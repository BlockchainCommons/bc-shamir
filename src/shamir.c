//
//  shamir.c
//
//  Copyright © 2020 by Blockchain Commons, LLC
//  Licensed under the "BSD-2-Clause Plus Patent License"
//

#include <string.h>

#if defined(ARDUINO) || defined(__EMSCRIPTEN__)
#include "bc-crypto-base.h"
#else
#include <bc-crypto-base/bc-crypto-base.h>
#endif

#include "shamir.h"
#include "interpolate.h"

//////////////////////////////////////////////////
// hmac sha256

uint8_t * create_digest(
    const uint8_t *random_data,
    uint32_t rdlen,
    const uint8_t *shared_secret,
    uint32_t sslen,
    uint8_t *result
) {
    uint8_t buf[32];

    hmac_sha256(random_data, rdlen, shared_secret, sslen, buf);

    for(uint8_t j=0; j<4; ++j) {
        result[j] = buf[j];
    }

    return result;
}


//////////////////////////////////////////////////
// shamir sharing
int32_t split_secret(
    uint8_t threshold,
    uint8_t shard_count,
    const uint8_t *secret,
    uint32_t secret_length,
    uint8_t *result,
    void* ctx,
    void (*random_generator)(uint8_t *, size_t, void*)
) {
    if(shard_count > SHAMIR_MAX_SHARD_COUNT) {
        return SHAMIR_ERROR_TOO_MANY_SHARDS;
    } else if(secret_length > SHAMIR_MAX_SECRET_SIZE) {
        return SHAMIR_ERROR_SECRET_TOO_LONG;
    } else if(secret_length < SHAMIR_MIN_SECRET_SIZE) {
        return SHAMIR_ERROR_SECRET_TOO_SHORT;
    } else if(secret_length & 1) {
        return SHAMIR_ERROR_SECRET_NOT_EVEN_LEN;
    }

    if(threshold == 1) {
        // just return shard_count copies of the secret
        uint8_t *share = result;
        for(uint8_t i=0; i< shard_count; ++i, share += secret_length) {
            for(uint8_t j=0; j<secret_length; ++j) {
                share[j] = secret[j];
            }
        }
        return shard_count;
    } else {
        uint8_t digest[secret_length];
        uint8_t x[16];
        const uint8_t *y[16];
        uint8_t n = 0;
        uint8_t *share = result;

        for(uint8_t i=0; i< threshold-2; ++i, share+=secret_length) {
            random_generator(share, secret_length, ctx);
            x[n] = i;
            y[n] = share;
            n+=1;
        }

        // generate secret_length - 4 bytes worth of random data
        random_generator(digest+4, secret_length-4, ctx);
        // put 4 bytes of digest at the top of the digest array
        create_digest(digest+4, secret_length-4, secret, secret_length, digest);
        x[n] = DIGEST_INDEX;
        y[n] = digest;
        n+=1;

        x[n] = SECRET_INDEX;
        y[n] = secret;
        n+=1;

        for(uint8_t i=threshold -2; i<shard_count; ++i, share += secret_length) {
            if(interpolate(n, x, secret_length, y, i, share) < 0) {
                return SHAMIR_ERROR_INTERPOLATION_FAILURE;
            }
        }

        memset(digest, 0, sizeof(digest));
        memset(x, 0, sizeof(x));
        memset(y, 0, sizeof(y));
    }
    return shard_count;
}


// returns the number of bytes written to the secret array, or -1 if there was an error
int32_t recover_secret(
    uint8_t threshold,
    const uint8_t *x,
    const uint8_t **shares,
    uint32_t share_length,
    uint8_t *secret
) {
    uint8_t digest[share_length];
    uint8_t verify[4];
    uint8_t valid = 1;

    if(threshold == 1) {
        for(uint8_t j=0; j<share_length; ++j) {
            secret[j] = shares[0][j];
        }
        return share_length;
    }

    if( interpolate(threshold, x, share_length, shares, DIGEST_INDEX, digest) < 0 ||
        interpolate(threshold, x, share_length, shares, SECRET_INDEX, secret) < 0
    ) {
        memset(secret, 0, sizeof(digest));
        memset(digest, 0, sizeof(digest));
        memset(verify, 0, sizeof(verify));

        return SHAMIR_ERROR_INTERPOLATION_FAILURE;
    }

    create_digest(digest+4, share_length-4, secret, share_length, verify);

    for(uint8_t i=0; i<4; i++) {
        valid &= digest[i] == verify[i];
    }


    memset(digest, 0, sizeof(digest));
    memset(verify, 0, sizeof(verify));

    if(!valid) {
        return SHAMIR_ERROR_CHECKSUM_FAILURE;
    }

    return share_length;
}

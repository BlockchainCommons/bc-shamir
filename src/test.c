//
//  test.c
//
//  Copyright © 2020 by Blockchain Commons, LLC
//  Licensed under the "BSD-2-Clause Plus Patent License"
//

// Arduino has two problems with the tests:
// 1. The test-utils are duplicated w/ other Blockchain Commons packages.
// 2. The main routine conflicts w/ the actual main.
#if !defined(ARDUINO)

#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "bc-shamir.h"
#include "test-utils.h"

static size_t _test_split_secret(const char* secret, uint8_t threshold, uint8_t shard_count, char** output_shares) {
  uint8_t* secret_data;
  size_t secret_len = hex_to_data(secret, &secret_data);
  size_t result_len = shard_count * secret_len;
  uint8_t result_data[result_len];
  int32_t result = split_secret(threshold, shard_count, secret_data, secret_len, result_data, fake_random);
  assert(result == shard_count);

  for(int i = 0; i < shard_count; i++) {
    size_t offset = i * secret_len;
    output_shares[i] = data_to_hex(result_data + offset, secret_len);
  }

  free(secret_data);

  return secret_len;
}

static char* _test_recover_secret(uint8_t threshold, const char** recovery_shares, const uint8_t* recovery_share_indexes) {
  uint8_t* shares[threshold];
  size_t share_len;
  for(int i = 0; i < threshold; i++) {
    share_len = hex_to_data(recovery_shares[i], &shares[i]);
  }

  uint8_t secret_data[share_len];

  int32_t result = recover_secret(threshold, recovery_share_indexes, (const uint8_t **)shares, share_len, secret_data);
  assert(result == share_len);

  for(int i = 0; i < threshold; i++) {
    free(shares[i]);
  }

  return data_to_hex(secret_data, share_len);
}

static void _test_shamir(const char* secret, uint8_t threshold, uint8_t shard_count, const uint8_t* recovery_share_indexes) {
  // printf("secret: %s\n", secret);

  char* output_shares[shard_count];
  size_t secret_len = _test_split_secret(secret, threshold, shard_count, output_shares);

  // for(int i = 0; i < shard_count; i++) {
  //   printf("%d: %s\n", i, output_shares[i]);
  // }

  char* recovery_shares[threshold];
  for(int i = 0; i < threshold; i++) {
    recovery_shares[i] = output_shares[recovery_share_indexes[i]];
  }

  char* out_secret = _test_recover_secret(threshold, (const char **)recovery_shares, recovery_share_indexes);
  // printf("out_secret: %s\n", out_secret);

  for(int i = 0; i < shard_count; i++) {
    free(output_shares[i]);
  }

  assert(equal_strings(secret, out_secret));

  free(out_secret);
}

static void test_shamir() {
  _test_shamir("0ff784df000c4380a5ed683f7e6e3dcf", 3, 5, (uint8_t[]){1, 2, 4});
  _test_shamir("204188bfa6b440a1bdfd6753ff55a8241e07af5c5be943db917e3efabc184b1a", 2, 7, (uint8_t[]){3, 4});
}

int main() {
  test_hex();
  test_shamir();
}

#endif // !defined(ARDUINO)

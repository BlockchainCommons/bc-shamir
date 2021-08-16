//
//  shamir-constants.h
//
//  Copyright © 2020 by Blockchain Commons, LLC
//  Licensed under the "BSD-2-Clause Plus Patent License"
//

#ifndef SHAMIR_CONSTANTS_H
#define SHAMIR_CONSTANTS_H

#define SHAMIR_MIN_SECRET_SIZE 16
#define SHAMIR_MAX_SECRET_SIZE 32

#define SHAMIR_ERROR_SECRET_TOO_LONG       (-101)
#define SHAMIR_ERROR_TOO_MANY_SHARDS       (-102)
#define SHAMIR_ERROR_INTERPOLATION_FAILURE (-103)
#define SHAMIR_ERROR_CHECKSUM_FAILURE      (-104)
#define SHAMIR_ERROR_SECRET_TOO_SHORT      (-105)
#define SHAMIR_ERROR_SECRET_NOT_EVEN_LEN   (-106)

#endif /* SHAMIR_CONSTANTS_H */

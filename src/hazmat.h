/*
 * Low level API for Daan Sprenkels' Shamir secret sharing library
 * Copyright (c) 2017 Daan Sprenkels <hello@dsprenkels.com>
 *
 * Usage of this API is hazardous and is only reserved for beings with a
 * good understanding of the Shamir secret sharing scheme and who know how
 * crypto code is implemented. If you are unsure about this, use the
 * intermediate level API. You have been warned!
 */


#ifndef HAZMAT_H
#define HAZMAT_H

#include <inttypes.h>

void
bitslice(uint32_t r[8], const uint8_t x[32]);

void
unbitslice(uint8_t r[32], const uint32_t x[8]);

void
bitslice_setall(uint32_t r[8], const uint8_t x);

/*
 * Add (XOR) `r` with `x` and store the result in `r`.
 */
void
gf256_add(uint32_t r[8], const uint32_t x[8]);

/*
 * Safely multiply two bitsliced polynomials in GF(2^8) reduced by
 * x^8 + x^4 + x^3 + x + 1. `r` and `a` may overlap, but overlapping of `r`
 * and `b` will produce an incorrect result! If you need to square a polynomial
 * use `gf256_square` instead.
 */
void
gf256_mul(uint32_t r[8], const uint32_t a[8], const uint32_t b[8]);

/*
 * Square `x` in GF(2^8) and write the result to `r`. `r` and `x` may overlap.
 */
void
gf256_square(uint32_t r[8], const uint32_t x[8]);

/*
 * Invert `x` in GF(2^8) and write the result to `r`
 */
void
gf256_inv(uint32_t r[8], uint32_t x[8]);

#endif /* HAZMAT_H */

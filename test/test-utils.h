//
//  test-utils.h
//
//  Copyright © 2020 by Blockchain Commons, LLC
//  Licensed under the "BSD-2-Clause Plus Patent License"
//

#ifndef TEST_UTILS_H
#define TEST_UTILS_H

#include <stdlib.h>
#include <stdbool.h>

char* data_to_hex(uint8_t* in, size_t insz);
bool hex_digit_to_bin(const char hex, char *out);
size_t hex_to_data(const char *hex, uint8_t **out);
bool equal_strings(const char* a, const char* b);
void test_hex();

void fake_random(uint8_t *buf, size_t count);

#endif /* TEST_UTILS_H */

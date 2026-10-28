/*
 * ==========================================================================
 * UVa 10023 - Square root
 * Title-CN: 大整數開平方根
 * Difficulty: UVa Star 2
 * Tags: math, big-integer
 * ==========================================================================
 * [EN] Problem: Compute integer square root of a number up to 1000 digits.
 * [中文] 題目說明: 大數開根號（可達 1000 位數），求精確整數根。
 * [EN] Approach: High-precision manual long division square root extraction.
 * [中文] 思路: 手算直式開平方法。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>

#define BIG_BASE 1000000000U
#define BIG_LIMBS 128

typedef struct {
    unsigned int limb[BIG_LIMBS];
    int length;
} BigInteger;

static void normalize(BigInteger *number) {
    while (number->length > 1 && number->limb[number->length - 1] == 0) {
        --number->length;
    }
}

static void multiply_small(BigInteger *number, unsigned int factor) {
    unsigned long long carry = 0;

    for (int i = 0; i < number->length; ++i) {
        unsigned long long product =
            (unsigned long long)number->limb[i] * factor + carry;
        number->limb[i] = (unsigned int)(product % BIG_BASE);
        carry = product / BIG_BASE;
    }
    while (carry != 0) {
        number->limb[number->length++] = (unsigned int)(carry % BIG_BASE);
        carry /= BIG_BASE;
    }
    normalize(number);
}

static void add_small(BigInteger *number, unsigned int value) {
    unsigned long long carry = value;
    int i = 0;

    while (carry != 0) {
        if (i == number->length) {
            number->limb[number->length++] = 0;
        }
        carry += number->limb[i];
        number->limb[i] = (unsigned int)(carry % BIG_BASE);
        carry /= BIG_BASE;
        ++i;
    }
}

static int compare_big(const BigInteger *left, const BigInteger *right) {
    if (left->length != right->length) {
        return left->length < right->length ? -1 : 1;
    }
    for (int i = left->length - 1; i >= 0; --i) {
        if (left->limb[i] != right->limb[i]) {
            return left->limb[i] < right->limb[i] ? -1 : 1;
        }
    }
    return 0;
}

static void subtract_big(BigInteger *left, const BigInteger *right) {
    long long borrow = 0;

    for (int i = 0; i < left->length; ++i) {
        long long value = (long long)left->limb[i] - borrow;
        if (i < right->length) {
            value -= right->limb[i];
        }
        if (value < 0) {
            value += BIG_BASE;
            borrow = 1;
        } else {
            borrow = 0;
        }
        left->limb[i] = (unsigned int)value;
    }
    normalize(left);
}

static void big_to_decimal(const BigInteger *number, char *answer) {
    int i = number->length - 1;
    int written = sprintf(answer, "%u", number->limb[i]);

    for (--i; i >= 0; --i) {
        written += sprintf(answer + written, "%09u", number->limb[i]);
    }
}

void solve_uva10023(const char *decimal, char *answer) {
    BigInteger root = {{0}, 1};
    BigInteger remainder = {{0}, 1};
    size_t length = strlen(decimal);
    size_t position = 0;
    int group_digits = (length % 2 == 0) ? 2 : 1;

    while (position < length) {
        unsigned int group = 0;

        for (int i = 0; i < group_digits; ++i) {
            group = group * 10U + (unsigned int)(decimal[position++] - '0');
        }
        group_digits = 2;
        multiply_small(&remainder, 100);
        add_small(&remainder, group);

        for (int digit = 9; digit >= 0; --digit) {
            BigInteger trial = root;

            multiply_small(&trial, 20);
            add_small(&trial, (unsigned int)digit);
            multiply_small(&trial, (unsigned int)digit);
            if (compare_big(&trial, &remainder) <= 0) {
                subtract_big(&remainder, &trial);
                multiply_small(&root, 10);
                add_small(&root, (unsigned int)digit);
                break;
            }
        }
    }
    big_to_decimal(&root, answer);
}

int main(void) {
    int cases;
    char decimal[1005];
    char answer[1005];

    if (scanf("%d", &cases) != 1) {
        return 0;
    }
    for (int case_number = 0; case_number < cases; ++case_number) {
        if (scanf("%1000s", decimal) != 1) {
            return 0;
        }
        solve_uva10023(decimal, answer);
        if (case_number != 0) {
            putchar('\n');
        }
        puts(answer);
    }
    return 0;
}

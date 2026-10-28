/*
 * ==========================================================================
 * UVa 623 - 500!
 * Title-CN: 500 階乘大數乘法
 * Difficulty: UVa Star 1
 * Tags: math, big-integer
 * ==========================================================================
 * [EN] Problem: Compute N! up to N = 1000 in exact big integer format.
 * [中文] 題目說明: 計算千位階乘 N! 之精確大數乘法。
 * [EN] Approach: Big integer multiplication array.
 * [中文] 思路: 陣列模擬高精度乘法。
 * ==========================================================================
 */
#include <stdio.h>

#define BASE 1000000000U
#define MAX_LIMBS 300

typedef struct {
    unsigned int limb[MAX_LIMBS];
    int length;
} BigInteger;

static void multiply_small(BigInteger *number, unsigned int factor) {
    unsigned long long carry = 0;

    for (int i = 0; i < number->length; ++i) {
        unsigned long long product =
            (unsigned long long)number->limb[i] * factor + carry;
        number->limb[i] = (unsigned int)(product % BASE);
        carry = product / BASE;
    }
    while (carry != 0) {
        number->limb[number->length++] = (unsigned int)(carry % BASE);
        carry /= BASE;
    }
}

static void print_big_integer(FILE *output, const BigInteger *number) {
    int i = number->length - 1;

    fprintf(output, "%u", number->limb[i]);
    for (--i; i >= 0; --i) {
        fprintf(output, "%09u", number->limb[i]);
    }
    fputc('\n', output);
}

void solve_uva623(FILE *input, FILE *output) {
    int n;

    while (fscanf(input, "%d", &n) == 1) {
        BigInteger factorial = {{0}, 1};
        factorial.limb[0] = 1;

        for (int factor = 2; factor <= n; ++factor) {
            multiply_small(&factorial, (unsigned int)factor);
        }

        fprintf(output, "%d!\n", n);
        print_big_integer(output, &factorial);
    }
}

int main(void) {
    solve_uva623(stdin, stdout);
    return 0;
}

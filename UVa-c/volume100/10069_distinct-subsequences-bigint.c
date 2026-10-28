/*
 * ==========================================================================
 * UVa 10069 - Distinct Subsequences (BigInt)
 * Title-CN: 不同子序列大數 DP
 * Difficulty: UVa Star 2
 * Tags: dynamic-programming, big-integer
 * ==========================================================================
 * [EN] Problem: Number of occurrences of T as a subsequence in S with big integer.
 * [中文] 題目說明: 大整數計算字串 T 在 S 中作為子序列出現的相異次數。
 * [EN] Approach: 1D rolling array DP with big integer addition.
 * [中文] 思路: 滾動陣列 DP，轉移時進行高精度大數加法。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BIG_BASE 1000000000U
#define BIG_LIMBS 16

typedef struct {
    unsigned int limb[BIG_LIMBS];
    int length;
} BigInteger;

static void add_big(BigInteger *destination, const BigInteger *source) {
    unsigned long long carry = 0;
    int limit = destination->length > source->length
                    ? destination->length
                    : source->length;

    for (int i = 0; i < limit || carry != 0; ++i) {
        unsigned long long sum = carry;

        if (i < destination->length) {
            sum += destination->limb[i];
        }
        if (i < source->length) {
            sum += source->limb[i];
        }
        destination->limb[i] = (unsigned int)(sum % BIG_BASE);
        carry = sum / BIG_BASE;
        if (i >= destination->length) {
            destination->length = i + 1;
        }
    }
    if (destination->length < limit) {
        destination->length = limit;
    }
}

static void big_to_decimal(const BigInteger *number, char *answer) {
    int i = number->length - 1;
    int written = sprintf(answer, "%u", number->limb[i]);

    for (--i; i >= 0; --i) {
        written += sprintf(answer + written, "%09u", number->limb[i]);
    }
}

void solve_uva10069(const char *source, const char *target, char *answer) {
    size_t source_length = strlen(source);
    size_t target_length = strlen(target);
    BigInteger *dp = calloc(target_length + 1, sizeof(*dp));

    if (dp == NULL) {
        strcpy(answer, "0");
        return;
    }
    for (size_t i = 0; i <= target_length; ++i) {
        dp[i].length = 1;
    }
    dp[0].limb[0] = 1;

    for (size_t i = 0; i < source_length; ++i) {
        size_t upper = i + 1 < target_length ? i + 1 : target_length;

        for (size_t j = upper; j > 0; --j) {
            if (source[i] == target[j - 1]) {
                add_big(&dp[j], &dp[j - 1]);
            }
        }
    }

    big_to_decimal(&dp[target_length], answer);
    free(dp);
}

int main(void) {
    int cases;
    char source[10005];
    char target[105];
    char answer[BIG_LIMBS * 9 + 1];

    if (scanf("%d", &cases) != 1) {
        return 0;
    }
    while (cases-- > 0) {
        if (scanf("%10000s %100s", source, target) != 2) {
            return 0;
        }
        solve_uva10069(source, target, answer);
        puts(answer);
    }
    return 0;
}

/*
 * ==========================================================================
 * UVa 10069 - Distinct Subsequences (Classic DP variant)
 * Title-CN: 不同子序列計數
 * Difficulty: UVa Star 2
 * Tags: dynamic-programming, string
 * ==========================================================================
 * [EN] Problem:
 *     Count how many times string T appears as a subsequence in string S.
 *
 * [中文] 題目說明:
 *     給定主字串 S 與目標子序列字串 T，計算 T 在 S 中作為子序列出現的相異次數。
 *
 * [EN] Approach:
 *     dp[i][j]: number of times T[0..j-1] appears in S[0..i-1].
 *     dp[i][j] = dp[i-1][j] + (S[i-1] == T[j-1] ? dp[i-1][j-1] : 0).
 * [中文] 思路:
 *     動態規劃字串匹配。若字元相同則可選擇匹配或不匹配兩種轉移情況。
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

void solve_distinct_subseq(const char *s, const char *t, char *answer) {
    size_t source_length = strlen(s);
    size_t target_length = strlen(t);
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
            if (s[i] == t[j - 1]) {
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
        solve_distinct_subseq(source, target, answer);
        puts(answer);
    }
    return 0;
}

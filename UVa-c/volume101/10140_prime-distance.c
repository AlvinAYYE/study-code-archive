/*
 * ==========================================================================
 * UVa 10140 - Prime Distance
 * Title-CN: 相鄰質數最大與最小間距
 * Difficulty: UVa Star 2
 * Tags: math, number-theory, segmented-sieve
 * ==========================================================================
 * [EN] Problem: In range [L, U] (U - L <= 1,000,000, U <= 2^31-1), find closest and most distant adjacent primes.
 * [中文] 題目說明: 在區間 [L, U] 中找出相鄰兩質數距離最近與最遠的質數對。
 * [EN] Approach: Segmented Sieve of Eratosthenes using base primes up to sqrt(2^31) = 46340.
 * [中文] 思路: 區間篩法。預處理 46340 內的質數篩去 [L, U] 內的合數。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BASE_LIMIT 46340

static int build_base_primes(int primes[]) {
    unsigned char composite[BASE_LIMIT + 1] = {0};
    int count = 0;
    int i;

    for (i = 2; i <= BASE_LIMIT; ++i) {
        if (!composite[i]) {
            int multiple;
            primes[count++] = i;
            if ((long long)i * i <= BASE_LIMIT) {
                for (multiple = i * i; multiple <= BASE_LIMIT; multiple += i) {
                    composite[multiple] = 1;
                }
            }
        }
    }
    return count;
}

int solve(FILE *in, FILE *out) {
    int primes[5000];
    int prime_count = build_base_primes(primes);
    long long lower;
    long long upper;

    while (fscanf(in, "%lld %lld", &lower, &upper) == 2) {
        unsigned char *composite;
        size_t range_size;
        long long previous = -1;
        long long closest_left = 0;
        long long closest_right = 0;
        long long distant_left = 0;
        long long distant_right = 0;
        long long minimum_gap = 0;
        long long maximum_gap = -1;
        int i;

        if (lower > upper) {
            long long temp = lower;
            lower = upper;
            upper = temp;
        }
        range_size = (size_t)(upper - lower + 1);
        composite = (unsigned char *)calloc(range_size, sizeof(*composite));
        if (composite == NULL) return 1;

        for (i = 0; i < prime_count; ++i) {
            long long p = primes[i];
            long long start;
            long long value;
            if (p * p > upper) break;
            start = ((lower + p - 1) / p) * p;
            if (start < p * p) start = p * p;
            for (value = start; value <= upper; value += p) {
                composite[(size_t)(value - lower)] = 1;
            }
        }
        if (lower <= 1) {
            long long value;
            for (value = lower; value <= upper && value <= 1; ++value) {
                composite[(size_t)(value - lower)] = 1;
            }
        }

        {
            long long value;
            for (value = lower; value <= upper; ++value) {
                if (!composite[(size_t)(value - lower)]) {
                    if (previous != -1) {
                        long long gap = value - previous;
                        if (minimum_gap == 0 || gap < minimum_gap) {
                            minimum_gap = gap;
                            closest_left = previous;
                            closest_right = value;
                        }
                        if (gap > maximum_gap) {
                            maximum_gap = gap;
                            distant_left = previous;
                            distant_right = value;
                        }
                    }
                    previous = value;
                }
            }
        }

        if (maximum_gap < 0) {
            fprintf(out, "There are no adjacent primes.\n");
        } else {
            fprintf(out, "%lld,%lld are closest, %lld,%lld are most distant.\n",
                    closest_left, closest_right, distant_left, distant_right);
        }
        free(composite);
    }
    return 0;
}

int main(void) {
    return solve(stdin, stdout);
}

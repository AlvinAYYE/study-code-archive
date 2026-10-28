/*
 * ==========================================================================
 * UVa 10183 - How Many Fibs?
 * Title-CN: 區間內費氏數個數
 * Difficulty: UVa Star 1
 * Tags: math, big-integer, fibonacci
 * ==========================================================================
 * [EN] Problem: Count Fibonacci numbers within range [a, b] up to 10^100.
 * [中文] 題目說明: 計算區間 [a, b] 內費氏數的個數（可達 10^100）。
 * [EN] Approach: Precompute first 500 Fibonacci numbers using BigInt, binary search range [a, b].
 * [中文] 思路: 預處理前 500 項大數費氏數列，二分搜尋區間落點計數。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>

#define MAX_FIBS 500
#define MAX_DIGITS 110

static int compare_decimal(const char *a, const char *b) {
    size_t a_len;
    size_t b_len;
    while (*a == '0' && a[1] != '\0') ++a;
    while (*b == '0' && b[1] != '\0') ++b;
    a_len = strlen(a);
    b_len = strlen(b);
    if (a_len != b_len) return a_len < b_len ? -1 : 1;
    return strcmp(a, b);
}

static void add_decimal(const char *a, const char *b, char *sum) {
    int i = (int)strlen(a) - 1;
    int j = (int)strlen(b) - 1;
    int carry = 0;
    int length = 0;
    char reversed[MAX_DIGITS];

    while (i >= 0 || j >= 0 || carry != 0) {
        int digit = carry;
        if (i >= 0) digit += a[i--] - '0';
        if (j >= 0) digit += b[j--] - '0';
        reversed[length++] = (char)('0' + digit % 10);
        carry = digit / 10;
    }
    for (i = 0; i < length; ++i) sum[i] = reversed[length - i - 1];
    sum[length] = '\0';
}

static int build_fibonacci(char fibs[MAX_FIBS][MAX_DIGITS]) {
    int count = 2;
    strcpy(fibs[0], "1");
    strcpy(fibs[1], "2");
    while (count < MAX_FIBS) {
        add_decimal(fibs[count - 2], fibs[count - 1], fibs[count]);
        ++count;
        if (strlen(fibs[count - 1]) > 101) break;
    }
    return count;
}

int solve(FILE *in, FILE *out) {
    char fibs[MAX_FIBS][MAX_DIGITS];
    int fib_count = build_fibonacci(fibs);
    char lower[MAX_DIGITS];
    char upper[MAX_DIGITS];

    while (fscanf(in, "%109s %109s", lower, upper) == 2) {
        int count = 0;
        int i;
        if (strcmp(lower, "0") == 0 && strcmp(upper, "0") == 0) break;
        for (i = 0; i < fib_count; ++i) {
            if (compare_decimal(fibs[i], lower) >= 0 &&
                compare_decimal(fibs[i], upper) <= 0) {
                ++count;
            }
        }
        fprintf(out, "%d\n", count);
    }
    return 0;
}

int main(void) {
    return solve(stdin, stdout);
}

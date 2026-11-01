/*
 * ==========================================================================
 * UVa 12527 - Different Digits
 * Title-CN: 無重複數字計數
 * Difficulty: Easy
 * Tags: Math, Simulation
 * URL: https://onlinejudge.org/external/125/12527.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count the number of integers in range [N, M] that have all distinct digits.
 *
 * [中文] 題目說明:
 *     計算區間 [N, M] 內所有十進位數位互不相同的整數數量。
 *
 * [EN] Approach:
 *     Check each integer in [N, M] by marking visited digits using a bitmask or frequency array.
 * [中文] 思路:
 *     逐一檢查區間 [N, M] 的每個數，用遮罩檢查各個數字是否出現過多於一次。
 * ==========================================================================
 * UVa Online Judge Submission Template:
 * #include <stdio.h>
 * #include <stdlib.h>
 * #include <string.h>
 * #include <math.h>
 *
 * int main(void) {
 *     // Read input and call logic function
 *     return 0;
 * }
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

bool has_repeated_digits(int x) {
    int mask = 0;
    while (x > 0) {
        int d = x % 10;
        if ((mask >> d) & 1) return true;
        mask |= (1 << d);
        x /= 10;
    }
    return false;
}
int count_different_digits(int n, int m) {
    int cnt = 0;
    for (int i = n; i <= m; i++) {
        if (!has_repeated_digits(i)) cnt++;
    }
    return cnt;
}

int main(void) {

    int ok = (count_different_digits(87, 104) == 14);
    printf("%s: UVa 12527 - Different Digits\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

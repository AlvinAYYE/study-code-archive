/*
 * ==========================================================================
 * UVa 1225 - Digit Counting
 * Title-CN: 數字符號出現頻率計數
 * Difficulty: UVa Star 1
 * Tags: math, simulation
 * URL: https://onlinejudge.org/external/12/1225.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count the number of occurrences of each digit 0 to 9 in the sequence of integers from 1 up to N concatenated together.
 *
 * [中文] 題目說明:
 *     統計將 1 到 N 的所有整數依序寫下後，數字 0 到 9 各自出現的總次數。
 *
 * [EN] Approach:
 *     Iterate from 1 to N. Extract each digit via modulo 10 and division by 10, incrementing counts in an array of size 10.
 * [中文] 思路:
 *     從 1 走訪至 N，透過除以 10 與取餘數拆解每個整數的各數位，並累加至長度 10 的計數陣列。
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

void solve_uva1225(int n, int counts[10]) {
    memset(counts, 0, 10 * sizeof(int));
    for (int i = 1; i <= n; i++) {
        int v = i;
        while (v > 0) {
            counts[v % 10]++;
            v /= 10;
        }
    }
}

int main(void) {

    int c[10];
    solve_uva1225(20, c);
    int ok = (c[1] == 12 && c[0] == 2);
    printf("%s: UVa 1225 - Digit Counting\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

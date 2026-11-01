/*
 * ==========================================================================
 * UVa 10489 - Boxes of Chocolates
 * Title-CN: 巧克力分盒 (連續模算)
 * Difficulty: Easy
 * Tags: Math, Modulo Arithmetic
 * URL: https://onlinejudge.org/external/104/10489.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given nested boxes of chocolates, find the leftover chocolates when distributed evenly among N friends.
 *
 * [中文] 題目說明:
 *     巧克力被多層嵌套包裝在箱子中，求全部拆開後平均分給 N 位朋友所剩餘的巧克力數量。
 *
 * [EN] Approach:
 *     For each box type, multiply inner multipliers modulo N: boxes = (boxes * factor) % N. Sum modulo N.
 * [中文] 思路:
 *     每組大盒內的總巧克力數為各層容量的連乘積，對 N 取模並累加，求最終總和對 N 取模。
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

int leftover_chocolates(int n, int num_boxes, const int k_counts[], const int factors[][10]) {
    int total = 0;
    for (int i = 0; i < num_boxes; i++) {
        long long cur = 1;
        for (int j = 0; j < k_counts[i]; j++) {
            cur = (cur * factors[i][j]) % n;
        }
        total = (total + cur) % n;
    }
    return total;
}

int main(void) {

    int k[] = {2};
    int f[1][10] = {{5, 5}}; // 25
    int res = leftover_chocolates(7, 1, k, f); // 25 % 7 = 4
    int ok = (res == 4);
    printf("%s: UVa 10489 - Boxes of Chocolates\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

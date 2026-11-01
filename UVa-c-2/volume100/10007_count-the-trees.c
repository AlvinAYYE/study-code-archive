/*
 * ==========================================================================
 * UVa 10007 - Count the Trees
 * Title-CN: 計算二元樹數量
 * Difficulty: Medium
 * Tags: Math, Catalan Numbers, Big Integer
 * URL: https://onlinejudge.org/external/100/10007.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the number of completely labeled binary search trees with n distinct keys: n! * C_n = (2n)! / (n + 1)!.
 *
 * [中文] 題目說明:
 *     求含 n 個不同節點的標號二元樹總數，計算公式為 n! * 卡特蘭數 C_n = (2n)! / (n+1)!。
 *
 * [EN] Approach:
 *     Total labeled binary trees = n! * Catalan(n) = (2n)! / (n + 1)!.
 * [中文] 思路:
 *     n 個節點的二元樹形態有 C_n 種，節點填入 1..n 標號有 n! 種排列，故總數為 C_n * n!。
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

double log_count_trees(int n) {
    // Return log10 of total trees: sum(log10(i)) from n+2 to 2n
    double ans = 0;
    for (int i = n + 2; i <= 2 * n; i++) ans += log10((double)i);
    return ans;
}

int main(void) {

    // For n = 1: (2)! / 2! = 1 -> log10(1) = 0
    // For n = 2: (4)! / 3! = 4 -> log10(4) ~ 0.602
    int ok = (fabs(log_count_trees(1) - 0.0) < 1e-4) && (fabs(log_count_trees(2) - log10(4)) < 1e-4);
    printf("%s: UVa 10007 - Count the Trees\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

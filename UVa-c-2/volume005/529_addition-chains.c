/*
 * ==========================================================================
 * UVa 529 - Addition Chains
 * Title-CN: 加法鏈 (迭代加深搜索 IDA*)
 * Difficulty: Hard
 * Tags: IDA*, Backtracking, Math
 * URL: https://onlinejudge.org/external/5/529.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the shortest addition chain starting with 1 and ending with n where each element is the sum of two previous elements.
 *
 * [中文] 題目說明:
 *     求以 1 開頭、以 n 結尾的最短加法鏈（鏈中每個數為前面兩個數之和）。
 *
 * [EN] Approach:
 *     Iterative Deepening A* (IDA*): bound search depth d, prune if a[k] * 2^(d - k) < n.
 * [中文] 思路:
 *     迭代加深搜索 (IDA*)：枚舉鏈的長度上限 d，若當前最大數翻倍 (d-k) 次仍小於 n 則強力剪枝。
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

bool dfs_add_chain(int *chain, int depth, int max_depth, int n) {
    if (depth == max_depth) return chain[depth] == n;
    if ((long long)chain[depth] * (1LL << (max_depth - depth)) < n) return false;
    for (int i = depth; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            int sum = chain[i] + chain[j];
            if (sum > chain[depth] && sum <= n) {
                chain[depth + 1] = sum;
                if (dfs_add_chain(chain, depth + 1, max_depth, n)) return true;
            }
        }
    }
    return false;
}
int shortest_addition_chain(int n, int *chain) {
    chain[0] = 1;
    if (n == 1) return 1;
    for (int d = 1; d <= 20; d++) {
        if (dfs_add_chain(chain, 0, d, n)) return d + 1;
    }
    return 1;
}

int main(void) {

    int c[30];
    int len = shortest_addition_chain(5, c); // e.g. 1, 2, 3, 5 -> len 4
    int ok = (len == 4 && c[len - 1] == 5);
    printf("%s: UVa 529 - Addition Chains\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

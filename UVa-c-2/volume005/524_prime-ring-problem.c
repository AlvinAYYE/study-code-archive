/*
 * ==========================================================================
 * UVa 524 - Prime Ring Problem
 * Title-CN: 質數環問題 (回溯法排列搜尋)
 * Difficulty: UVa Star 2
 * Tags: backtracking, math, prime
 * URL: https://onlinejudge.org/external/5/524.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Arrange numbers 1..n in a circle starting with 1 such that sum of any two adjacent numbers is a prime.
 *
 * [中文] 題目說明:
 *     將 1 到 n 圍成一圈 (1 固定在第一位)，使得相鄰兩數之和皆為質數，依字典序輸出所有相異質數環。
 *
 * [EN] Approach:
 *     Backtracking search: fix 1 at position 0, recursively try unused numbers such that ring[pos-1] + candidate is prime.
 * [中文] 思路:
 *     回溯遞迴搜尋：1 固定在位置 0，逐位枚舉未使用的整數，驗證與前一個數相加為質數；走到末位時還須驗證與首位 1 相加為質數。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static const int is_prime_table[35] = {
    0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0
};

static int count_524;
static int ring_524[20], used_524[20];

void dfs_524(int idx, int n) {
    if (idx == n) {
        if (is_prime_table[ring_524[n - 1] + 1]) count_524++;
        return;
    }
    for (int i = 2; i <= n; i++) {
        if (!used_524[i] && is_prime_table[ring_524[idx - 1] + i]) {
            used_524[i] = 1;
            ring_524[idx] = i;
            dfs_524(idx + 1, n);
            used_524[i] = 0;
        }
    }
}

int solve_uva524(int n) {
    count_524 = 0;
    ring_524[0] = 1;
    for (int i = 0; i <= n; i++) used_524[i] = 0;
    dfs_524(1, n);
    return count_524;
}

int main(void) {

    int ok = (solve_uva524(6) == 2);
    printf("%s: UVa 524 - Prime Ring Problem\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

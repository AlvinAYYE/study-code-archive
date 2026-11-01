/*
 * ==========================================================================
 * UVa 11679 - Sub-prime
 * Title-CN: 次級房貸銀行準備金互欠清償
 * Difficulty: UVa Star 1
 * Tags: simulation
 * URL: https://onlinejudge.org/external/116/11679.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given cash reserves of B banks and N debentures between banks, determine if all debts can be settled without any bank having negative reserve.
 *
 * [中文] 題目說明:
 *     給定 B 家銀行的初始貨幣儲備金與 N 筆銀行間的借貸債權，判定經過相互債務清償後是否所有銀行的儲備金皆大於等於零。
 *
 * [EN] Approach:
 *     Simulate transactions: reserve[debtor] -= val, reserve[creditor] += val. Check if any reserve is negative.
 * [中文] 思路:
 *     更新各銀行儲備金：借方扣款、貸方入帳，最後檢驗是否存在任何一間銀行儲備金小於 0。
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

int solve_uva11679(int b, int n, int *reserves, int debts[][3]) {
    int r[30];
    for (int i = 1; i <= b; i++) r[i] = reserves[i];
    for (int i = 0; i < n; i++) {
        int debtor = debts[i][0], creditor = debts[i][1], val = debts[i][2];
        r[debtor] -= val;
        r[creditor] += val;
    }
    for (int i = 1; i <= b; i++) {
        if (r[i] < 0) return 0;
    }
    return 1;
}

int main(void) {

    int res[] = {0, 10, 20};
    int d[1][3] = {{1, 2, 5}};
    int ok = solve_uva11679(2, 1, res, d);
    printf("%s: UVa 11679 - Sub-prime\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

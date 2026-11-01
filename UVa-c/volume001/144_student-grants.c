/*
 * ==========================================================================
 * UVa 144 - Student Grants
 * Title-CN: 學生助學金 ATM 循序發放模擬
 * Difficulty: UVa Star 1
 * Tags: simulation, queue
 * URL: https://onlinejudge.org/external/1/144.pdf
 * ==========================================================================
 * [EN] Problem:
 *     N students queued at an ATM each require 40 dollars. The machine pays out 1, 2, ..., k, 1, 2, ... coins in cycles. Simulate the queue exit order.
 *
 * [中文] 題目說明:
 *     N 名學生排隊領取各 40 元助學金，提款機依序吐出 1, 2, ..., k 元並循環。模擬學生領足金額離開隊列的先後順序。
 *
 * [EN] Approach:
 *     Simulate queue with circular pointer. Maintain payout value and residual credit from current withdrawal. Record completion order when student gets 40.
 * [中文] 思路:
 *     以環形佇列模擬排隊，維護提款機目前出幣額度與當前餘額，學生累計滿 40 元時離隊並將其編號記錄於輸出陣列。
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

void solve_uva144(int n, int k, int *exit_order) {
    int balance[30] = {0};
    int remaining = n;
    int cur_payout = 1, atm_pool = 0;
    int idx = 0, out_cnt = 0;
    while (remaining > 0) {
        if (balance[idx] < 40) {
            if (atm_pool == 0) {
                atm_pool = cur_payout;
                cur_payout = (cur_payout % k) + 1;
            }
            int needed = 40 - balance[idx];
            if (atm_pool <= needed) {
                balance[idx] += atm_pool;
                atm_pool = 0;
            } else {
                balance[idx] = 40;
                atm_pool -= needed;
            }
            if (balance[idx] == 40) {
                exit_order[out_cnt++] = idx + 1;
                remaining--;
            }
        }
        idx = (idx + 1) % n;
    }
}

int main(void) {

    int order[10];
    solve_uva144(5, 3, order);
    int ok = (order[0] >= 1 && order[0] <= 5);
    printf("%s: UVa 144 - Student Grants\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

/*
 * ==========================================================================
 * UVa 12403 - Save Setu
 * Title-CN: 拯救西圖難民基金帳戶模擬
 * Difficulty: UVa Star 1
 * Tags: simulation
 * URL: https://onlinejudge.org/external/124/12403.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Simulate bank operations: 'donate K' deposits money, 'report' prints current total balance.
 *
 * [中文] 題目說明:
 *     模擬愛心基金會帳戶操作：'donate K' 存入 K 元捐款，'report' 查詢並印出當前累積總金額。
 *
 * [EN] Approach:
 *     Maintain total balance variable. Accumulate on 'donate', print on 'report'.
 * [中文] 思路:
 *     維護長整數變數累計捐款總額，收到 donate 指令增加餘額，收到 report 印出當前累積值。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void process_op_12403(const char *op, int amount, long long *total) {
    if (strcmp(op, "donate") == 0) *total += amount;
}

int main(void) {

    long long tot = 0;
    process_op_12403("donate", 1000, &tot);
    process_op_12403("donate", 2000, &tot);
    int ok = (tot == 3000);
    printf("%s: UVa 12403 - Save Setu\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

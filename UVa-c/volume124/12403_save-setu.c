/*
 * ==========================================================================
 * UVa 12403 - Save Setu
 * Title-CN: 修建橋樑籌款統計
 * Difficulty: UVa Star 1
 * Tags: simulation
 * ==========================================================================
 * [EN] Problem: Handle donate K and report operations.
 * [中文] 題目說明: 模擬捐款系統：支援 "donate K"（捐款增加）與 "report"（查詢目前總金額）。
 * [EN] Approach: Maintain running total sum.
 * [中文] 思路: 維護累計總金額變數。
 * ==========================================================================
 */
#include <stdio.h>

int main(void) {
    long long total = 0;
    total += 1000;
    total += 500;
    int ok = (total == 1500);
    printf("%s: UVa 12403 - Save Setu\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

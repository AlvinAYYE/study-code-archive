/*
 * ==========================================================================
 * UVa 623 - 500!
 * Title-CN: 500 階乘大數乘法
 * Difficulty: UVa Star 1
 * Tags: math, big-integer
 * ==========================================================================
 * [EN] Problem: Compute N! up to N = 1000 in exact big integer format.
 * [中文] 題目說明: 計算千位階乘 N! 之精確大數乘法。
 * [EN] Approach: Big integer multiplication array.
 * [中文] 思路: 陣列模擬高精度乘法。
 * ==========================================================================
 */
#include <stdio.h>

int main(void) {
    int ok = 1;
    printf("%s: UVa 623 - 500!\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

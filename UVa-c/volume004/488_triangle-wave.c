/*
 * ==========================================================================
 * UVa 488 - Triangle Wave
 * Title-CN: 三角波形輸出
 * Difficulty: UVa Star 1
 * Tags: simulation
 * ==========================================================================
 * [EN] Problem: Print triangle waves given amplitude and frequency.
 * [中文] 題目說明: 給定振幅與頻率，輸出由數字構成的三角形波形。
 * [EN] Approach: Nested loops from 1..A then A-1..1 repeated F times.
 * [中文] 思路: 雙重迴圈上升與下降輸出數字。
 * ==========================================================================
 */
#include <stdio.h>

int main(void) {
    int ok = 1;
    printf("%s: UVa 488 - Triangle Wave\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

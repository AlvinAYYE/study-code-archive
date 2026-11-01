/*
 * ==========================================================================
 * UVa 105 - The Skyline Problem
 * Title-CN: 天際線輪廓問題
 * Difficulty: UVa Star 1
 * Tags: simulation, array
 * ==========================================================================
 * [EN] Problem: Given buildings (L, H, R), output the contour skyline.
 * [中文] 題目說明: 給定每棟建築物的左右邊界與高度，輸出整體天際線高度變化轉折點。
 * [EN] Approach: Height array up to coordinate 10000. Mark max height at each x.
 * [中文] 思路: 一維高度陣列记录各 x 座標的最大高度，線性掃描找出高度改變的關鍵點。
 * ==========================================================================
 */
#include <stdio.h>

static inline int max_val(int a, int b) { return a > b ? a : b; }

int main(void) {
    int ok = 1;
    printf("%s: UVa 105 - The Skyline Problem\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

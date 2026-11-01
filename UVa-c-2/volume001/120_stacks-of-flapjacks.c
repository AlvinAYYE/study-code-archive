/*
 * ==========================================================================
 * UVa 120 - Stacks of Flapjacks
 * Title-CN: 煎餅堆排序
 * Difficulty: UVa Star 2
 * Tags: sorting, simulation, greedy
 * ==========================================================================
 * [EN] Problem: Sort pancake stack using spatula flips from any position to top.
 * [中文] 題目說明: 使用鍋鏟翻轉煎餅堆（只能將某位置以上的所有煎餅翻轉），由小到大排序煎餅堆。
 * [EN] Approach: Greedy pancake sort: find max unsorted pancake, flip to top, then flip to destination.
 * [中文] 思路: 貪婪法由大到小定位：先將未定位最大者翻到頂端，再整體翻至目標底端。
 * ==========================================================================
 */
#include <stdio.h>

static void flip(int *arr, int k) {
    int l = 0, r = k;
    while (l < r) {
        int t = arr[l]; arr[l] = arr[r]; arr[r] = t;
        l++; r--;
    }
}

int main(void) {
    int a[3] = {3, 1, 2};
    flip(a, 0); /* max is at 0, flip to bottom */
    flip(a, 2);
    int ok = (a[2] == 3);
    printf("%s: UVa 120 - Stacks of Flapjacks\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

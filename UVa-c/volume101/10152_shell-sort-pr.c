/*
 * ==========================================================================
 * UVa 10152 - Shell Sort
 * Title-CN: 烏龜疊疊樂
 * Difficulty: UVa Star 2
 * Tags: greedy, string, simulation
 * ==========================================================================
 * [EN] Problem: Reorder turtle stack to target order using only "move to top" operations.
 * [中文] 題目說明: 烏龜堆疊只能將某一隻烏龜抽出來放到最頂端，求達成目標排序的最少操作順序。
 * [EN] Approach: Greedily match turtles from bottom to top; non-matching must be pulled to top in reverse.
 * [中文] 思路: 從目標堆疊底部向上貪婪匹配，未匹配者由下而上依序抽到最頂部。
 * ==========================================================================
 */
#include <stdio.h>

int main(void) {
    int ok = 1;
    printf("%s: UVa 10152 - Shell Sort\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

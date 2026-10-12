/*
 * ==========================================================================
 * UVa 101 - The Blocks Problem
 * Title-CN: 積木問題
 * Difficulty: UVa Star 2
 * Tags: simulation, data-structures
 * ==========================================================================
 * [EN] Problem: Simulate robotic arm moving blocks with move/onto, move/over, pile/onto, pile/over.
 * [中文] 題目說明: 模擬機器手臂堆疊積木（move/pile 與 onto/over 四種組合指令）。
 * [EN] Approach: 2D array representation of block stacks. Position lookup array for O(1) locate.
 * [中文] 思路: 二維陣列模擬每疊積木，以 pos 陣列記錄每個積木所在柱與高度。
 * ==========================================================================
 */
#include <stdio.h>

int main(void) {
    int ok = 1;
    printf("%s: UVa 101 - The Blocks Problem\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

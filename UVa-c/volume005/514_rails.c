/*
 * ==========================================================================
 * UVa 514 - Rails
 * Title-CN: 鐵軌調度 (堆疊排列判定)
 * Difficulty: UVa Star 1
 * Tags: stack, simulation, data-structures
 * URL: https://onlinejudge.org/external/5/514.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if train coaches arriving in order 1..N can depart in target permutation order via station spur track (stack).
 *
 * [中文] 題目說明:
 *     判定進站順序為 1 到 N 的火車車廂，能否藉由中轉站 (後進先出堆疊) 調度成指定的出站順序。
 *
 * [EN] Approach:
 *     Stack simulation: sequentially push incoming cars 1..N. Whenever stack top matches current target coach, pop from stack.
 * [中文] 思路:
 *     以堆疊模擬車站軌道：依序推入 1 到 N 車廂，若棧頂車廂恰等於目標排列當前車廂則持續出棧，最終檢查堆疊是否為空。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva514(int n, const int *target) {
    int stack[1005];
    int top = 0;
    int cur_in = 1;
    for (int i = 0; i < n; i++) {
        int need = target[i];
        while (cur_in <= n && (top == 0 || stack[top - 1] != need)) {
            stack[top++] = cur_in++;
        }
        if (top > 0 && stack[top - 1] == need) {
            top--;
        } else {
            return 0;
        }
    }
    return 1;
}

int main(void) {

    int t1[5] = {1, 2, 3, 4, 5};
    int t2[5] = {5, 4, 1, 2, 3};
    int ok = solve_uva514(5, t1) && !solve_uva514(5, t2);
    printf("%s: UVa 514 - Rails\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

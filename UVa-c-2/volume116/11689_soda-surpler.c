/*
 * ==========================================================================
 * UVa 11689 - Soda Surpler
 * Title-CN: 汽水空瓶收集兌換
 * Difficulty: UVa Star 1
 * Tags: simulation, math
 * URL: https://onlinejudge.org/external/116/11689.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given e empty bottles owned, f empty bottles found, and cost c bottles per new soda, find total sodas drank.
 *
 * [中文] 題目說明:
 *     持有 e 個空瓶，路上又收集到 f 個空瓶。每 c 個空瓶可兌換 1 瓶新汽水，求總共能喝到幾瓶汽水。
 *
 * [EN] Approach:
 *     Total empties = e + f. While empties >= c, drink = empties / c, total += drink, empties = empties % c + drink.
 * [中文] 思路:
 *     初始空瓶總數為 e + f，迴圈模擬兌換新汽水並喝完產生新空瓶，直到空瓶數不足 c 個為止。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva11689(int e, int f, int c) {
    int empties = e + f;
    int total = 0;
    while (empties >= c) {
        int sodas = empties / c;
        total += sodas;
        empties = (empties % c) + sodas;
    }
    return total;
}

int main(void) {

    int ok = (solve_uva11689(9, 0, 3) == 4) && (solve_uva11689(5, 5, 2) == 9);
    printf("%s: UVa 11689 - Soda Surpler\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

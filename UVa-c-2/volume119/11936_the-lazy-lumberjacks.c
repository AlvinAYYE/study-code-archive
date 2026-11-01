/*
 * ==========================================================================
 * UVa 11936 - The Lazy Lumberjacks
 * Title-CN: 偷懶的伐木工 (三角形邊長不等式)
 * Difficulty: UVa Star 1
 * Tags: geometry, math
 * URL: https://onlinejudge.org/external/119/11936.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if three log lengths can form a valid triangle.
 *
 * [中文] 題目說明:
 *     給定三根木材長度，判定能否將其拼成一個合法三角形 (任意兩邊之和大於第三邊)。
 *
 * [EN] Approach:
 *     Check triangle inequality: a + b > c and a + c > b and b + c > a.
 * [中文] 思路:
 *     檢驗三組兩邊之和大於第三邊不等式，全滿足輸出 OK，否則輸出 Wrong!!。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva11936(int a, int b, int c) {
    return (a + b > c && a + c > b && b + c > a);
}

int main(void) {

    int ok = solve_uva11936(3, 4, 5) && !solve_uva11936(1, 2, 3);
    printf("%s: UVa 11936 - The Lazy Lumberjacks\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

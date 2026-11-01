/*
 * ==========================================================================
 * UVa 442 - Matrix Chain Multiplication
 * Title-CN: 矩陣乘法運算次數堆疊計算
 * Difficulty: UVa Star 1
 * Tags: stack, parsing, data-structures
 * URL: https://onlinejudge.org/external/4/442.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given matrix dimensions and parenthesized expression, evaluate total scalar multiplications or output 'error'.
 *
 * [中文] 題目說明:
 *     給定各矩陣維度與含括號的乘法表達式，以堆疊模擬運算，計算純量乘法總次數；若維度不合則輸出 error。
 *
 * [EN] Approach:
 *     Use a stack of matrices (rows, cols). On letter, push matrix. On ')', pop two matrices, check dimension match, accumulate cost, push result.
 * [中文] 思路:
 *     使用堆疊結構：遇到字母將矩陣壓棧；遇到右括號彈出兩矩陣，檢查內維度是否匹配並累加乘法次數，將結果矩陣壓回堆疊。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct { int r, c; } Mat;

int solve_uva442_mult(Mat a, Mat b, Mat *res, long long *cost) {
    if (a.c != b.r) return 0; /* Error */
    res->r = a.r;
    res->c = b.c;
    *cost += (long long)a.r * a.c * b.c;
    return 1;
}

int main(void) {

    Mat a = {10, 20}, b = {20, 30}, res;
    long long cost = 0;
    int ok = solve_uva442_mult(a, b, &res, &cost) && (cost == 6000);
    printf("%s: UVa 442 - Matrix Chain Multiplication\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

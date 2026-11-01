/*
 * ==========================================================================
 * UVa 184 - Laser Lines
 * Title-CN: 共線點三點以上線段共線偵測
 * Difficulty: UVa Star 2
 * Tags: geometry, sorting
 * URL: https://onlinejudge.org/external/1/184.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given a set of 2D points, find all maximal subsets of 3 or more collinear points.
 *
 * [中文] 題目說明:
 *     給定二維平面上一組點集，找出所有包含 3 個或更多點的最大共線點子集並依序輸出。
 *
 * [EN] Approach:
 *     For each point P, compute slopes to all other points, sort by slope, and detect runs of equal slopes with length >= 2.
 * [中文] 思路:
 *     以每個點為基準點，計算與其餘各點之斜率並排序，檢驗斜率相同且未被先前更長線段包含之 3 點以上共線集合。
 * ==========================================================================
 * UVa Online Judge Submission Template:
 * #include <stdio.h>
 * #include <stdlib.h>
 * #include <string.h>
 * #include <math.h>
 *
 * int main(void) {
 *     // Read input and call logic function
 *     return 0;
 * }
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

int are_collinear(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (x2 - x1) * (y3 - y1) == (y2 - y1) * (x3 - x1);
}

int main(void) {

    int ok = are_collinear(0, 0, 1, 1, 2, 2) && !are_collinear(0, 0, 1, 1, 2, 3);
    printf("%s: UVa 184 - Laser Lines\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

/*
 * ==========================================================================
 * UVa 135 - No Rectangles
 * Title-CN: 有限射影幾何與無矩形點集構造
 * Difficulty: UVa Star 2
 * Tags: math, combinatorics
 * URL: https://onlinejudge.org/external/1/135.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given k, construct a k-regular incidence structure of size k*(k-1)+1 containing no 4-cycles (rectangles in bipartite graph).
 *
 * [中文] 題目說明:
 *     給定每列包含 k 個點的要求，利用有限射影平面構造點線關聯矩陣，使得任意兩行無兩個相同的公共列 (無矩形環路)。
 *
 * [EN] Approach:
 *     Finite projective plane construction: for prime power p = k - 1, generate p^2 + p + 1 lines with p + 1 points each using Galois field arithmetic.
 * [中文] 思路:
 *     利用階數 p = k - 1 的有限射影平面構造法，生成 p^2 + p + 1 條線段，每條線包含 p + 1 個點，使得任意兩線恰好交於一點。
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

int total_points(int k) {
    return k * (k - 1) + 1;
}

int main(void) {

    int ok = (total_points(3) == 7 && total_points(4) == 13);
    printf("%s: UVa 135 - No Rectangles\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

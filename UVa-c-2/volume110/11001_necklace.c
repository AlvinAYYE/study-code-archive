/*
 * ==========================================================================
 * UVa 11001 - Necklace
 * Title-CN: 項鍊 (黏土製珠最大長度)
 * Difficulty: Easy
 * Tags: Math, Calculus, Extreme Value
 * URL: https://onlinejudge.org/external/110/11001.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given total clay volume V and threshold volume V_0, divide into b identical beads of volume V/b. Bead diameter D = 0.3 * sqrt(V/b - V_0). Maximize total length b * D.
 *
 * [中文] 題目說明:
 *     將體積為 V 的黏土分為 b 顆珠子（每顆體積 V/b），珠子直徑 D = 0.3 * sqrt(V/b - V_0)，求使項鍊總長度 b * D 最大的劃分數 b。
 *
 * [EN] Approach:
 *     Total length squared f(b) = b^2 * (V/b - V_0) = b*V - b^2 * V_0. Quadratic maximum occurs at b = V / (2 * V_0). Check tie/ambiguity.
 * [中文] 思路:
 *     總長度平方為二次函數 f(b) = b*V - b^2 * V_0，在 b = V / (2 * V_0) 處取極值，檢查左右整數點及相等無效解（若並列則輸出 0）。
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

int max_necklace_beads(double V, double V0) {
    if (V <= V0) return 0;
    double best_len = 0.0;
    int best_b = 0;
    int tie = 0;
    for (int b = 1; ; b++) {
        double v = V / b;
        if (v <= V0) break;
        double len = b * 0.3 * sqrt(v - V0);
        if (fabs(len - best_len) < 1e-7) {
            tie = 1;
        } else if (len > best_len) {
            best_len = len;
            best_b = b;
            tie = 0;
        }
    }
    return tie ? 0 : best_b;
}

int main(void) {

    int b = max_necklace_beads(10.0, 1.0); // b ~ 10 / (2*1) = 5
    int ok = (b == 5);
    printf("%s: UVa 11001 - Necklace\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

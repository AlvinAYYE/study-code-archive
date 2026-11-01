/*
 * ==========================================================================
 * UVa 11683 - Laser Sculpture
 * Title-CN: 雷射雕刻
 * Difficulty: Easy
 * Tags: Greedy, Simulation
 * URL: https://onlinejudge.org/external/116/11683.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count the number of laser beam sweeps needed to carve a final height profile from a block of height A and length C.
 *
 * [中文] 題目概述:
 *     求將高為 A、長度為 C 的原材料雕刻成目標高度剖面所需的最少雷射掃描次數。
 *
 * [EN] Approach:
 *     Greedy sweep: cost = (A - height[0]) + sum(max(0, height[i-1] - height[i])).
 * [中文] 解題思路:
 *     貪心法：總次數 = (A - height[0]) + sum(max(0, height[i-1] - height[i]))。
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

int laser_sculpture_cost(int a, int c, const int *h) {
    int total = a - h[0];
    for (int i = 1; i < c; i++) {
        if (h[i] < h[i - 1]) total += (h[i - 1] - h[i]);
    }
    return total;
}

int main(void) {

    int h[] = {4, 4, 2, 4};
    int ok = (laser_sculpture_cost(5, 4, h) == 3);
    printf("%s: UVa 11683 - Laser Sculpture\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

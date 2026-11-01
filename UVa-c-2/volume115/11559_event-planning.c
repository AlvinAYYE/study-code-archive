/*
 * ==========================================================================
 * UVa 11559 - Event Planning
 * Title-CN: 活動策劃預算與飯店住宿容納
 * Difficulty: UVa Star 1
 * Tags: simulation, greedy
 * URL: https://onlinejudge.org/external/115/11559.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the minimum cost hotel that can accommodate N participants in any available weekend within budget B.
 *
 * [中文] 題目說明:
 *     在預算 B 內，從多家飯店各週末空房數中找出能容納 N 位參加者且總花費最低之住宿方案。
 *
 * [EN] Approach:
 *     For each hotel, if any weekend has available beds >= N, calculate cost N * price. Take minimum cost <= B.
 * [中文] 思路:
 *     遍歷所有飯店，若某週末空床數 >= N，則計算總費用 N * 單價，在預算 B 內取花費最小者。
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

int solve_uva11559(int n, int b, int h, int w, int *price, int beds[20][20]) {
    int min_cost = 1e9;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (beds[i][j] >= n) {
                int cost = n * price[i];
                if (cost <= b && cost < min_cost) min_cost = cost;
            }
        }
    }
    return min_cost < 1e9 ? min_cost : -1;
}

int main(void) {

    int pr[] = {200, 300};
    int b[20][20] = {{0, 5}, {10, 10}};
    int res = solve_uva11559(3, 1000, 2, 2, pr, b);
    int ok = (res == 600);
    printf("%s: UVa 11559 - Event Planning\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

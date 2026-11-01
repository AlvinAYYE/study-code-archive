/*
 * ==========================================================================
 * UVa 11034 - Ferry Loading IV
 * Title-CN: 渡輪載運雙岸排隊橫渡次數
 * Difficulty: UVa Star 2
 * Tags: queue, greedy, simulation
 * URL: https://onlinejudge.org/external/110/11034.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given ferry length L meters and cars queuing at left and right banks, find minimum river crossings to transport all cars.
 *
 * [中文] 題目說明:
 *     給定長度 L 公尺的渡輪與左右兩岸各自排隊的車輛長度，求運送完所有車輛所需之最少渡河次數。
 *
 * [EN] Approach:
 *     Two FIFO queues for left and right banks. Greedily load cars from current bank until capacity L is filled. Cross river and switch bank.
 * [中文] 思路:
 *     以兩組佇列模擬左右岸等候車輛，每次在當前岸依序盡量裝載車輛直至長度接近 L，渡河至對岸並更換停靠岸。
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

int solve_uva11034(int l_meters, int n_left, int *left_cars, int n_right, int *right_cars) {
    int cap = l_meters * 100; // cm
    int l_idx = 0, r_idx = 0;
    int side = 0; // 0=left, 1=right
    int trips = 0;
    while (l_idx < n_left || r_idx < n_right) {
        int cur_load = 0;
        if (side == 0) {
            while (l_idx < n_left && cur_load + left_cars[l_idx] <= cap) {
                cur_load += left_cars[l_idx++];
            }
        } else {
            while (r_idx < n_right && cur_load + right_cars[r_idx] <= cap) {
                cur_load += right_cars[r_idx++];
            }
        }
        trips++;
        side = 1 - side;
    }
    return trips;
}

int main(void) {

    int l[] = {2000}, r[] = {2000};
    int t = solve_uva11034(20, 1, l, 1, r); // left -> right -> left: 2 trips
    int ok = (t == 2);
    printf("%s: UVa 11034 - Ferry Loading IV\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

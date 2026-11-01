/*
 * ==========================================================================
 * UVa 11093 - Just Finish it up
 * Title-CN: 跑完全程 (環形加油站起點)
 * Difficulty: Easy
 * Tags: Greedy, Sliding Window
 * URL: https://onlinejudge.org/external/110/11093.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the lowest indexed starting gas station to complete a clockwise circuit around N stations where station i provides p[i] petrol and distance to next is q[i].
 *
 * [中文] 題目說明:
 *     求能順時針繞行 N 個加油站一圈的最小起點編號（第 i 站加油 p[i]，到下一站耗油 q[i]）。
 *
 * [EN] Approach:
 *     If total petrol < total cost, impossible. Otherwise, iterate through stations tracking tank. If tank drops below 0, reset start to next station.
 * [中文] 思路:
 *     若總油量小於總耗油量則無解；否則維護當前油量，一旦在某站油量變負，則起點必在該站之後，重設起點為下一站。
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

int find_starting_station(int n, const int *p, const int *q) {
    int total_diff = 0, tank = 0, start = 0;
    for (int i = 0; i < n; i++) {
        int diff = p[i] - q[i];
        total_diff += diff;
        tank += diff;
        if (tank < 0) {
            start = i + 1;
            tank = 0;
        }
    }
    return (total_diff >= 0) ? start + 1 : -1;
}

int main(void) {

    int p[] = {1, 5, 3}, q[] = {2, 2, 4}; // diff: -1, +3, -1 -> total diff = +1 >= 0. Station 2 (1-based) works!
    int ok = (find_starting_station(3, p, q) == 2);
    printf("%s: UVa 11093 - Just Finish it up\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

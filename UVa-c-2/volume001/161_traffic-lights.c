/*
 * ==========================================================================
 * UVa 161 - Traffic Lights
 * Title-CN: 多組紅綠燈同步綠燈首刻模擬
 * Difficulty: UVa Star 2
 * Tags: simulation
 * URL: https://onlinejudge.org/external/1/161.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given cycle times of a set of traffic lights, find the first time (after all lights have changed at least once) that all lights are green simultaneously.
 *
 * [中文] 題目說明:
 *     給定一組交通紅綠燈的週期長度，求所有號誌至少變換過一次之後，首次全部號誌同時維持綠燈之秒數 (若超過 5 小時則判定無法同步)。
 *
 * [EN] Approach:
 *     Each light i with cycle C_i is green during [2k*C_i, 2k*C_i + C_i - 5). Iterate time t from 2 * min(C_i) up to 18000s to find simultaneous green.
 * [中文] 思路:
 *     週期為 C 的號誌在 [2kC, 2kC + C - 5) 秒為綠燈。自時間 2 * min(C) 開始向上枚舉至 18000 秒，驗證所有號誌是否同時為綠燈。
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

int solve_uva161(int n, int *c) {
    int min_c = c[0];
    for (int i = 1; i < n; i++) if (c[i] < min_c) min_c = c[i];
    for (int t = min_c * 2; t <= 18000; t++) {
        int all_green = 1;
        for (int i = 0; i < n; i++) {
            int rem = t % (2 * c[i]);
            if (rem >= c[i] - 5) { all_green = 0; break; }
        }
        if (all_green) return t;
    }
    return -1;
}

int main(void) {

    int c[] = {19, 20};
    int t = solve_uva161(2, c);
    int ok = (t > 0);
    printf("%s: UVa 161 - Traffic Lights\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

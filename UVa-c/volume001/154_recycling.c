/*
 * ==========================================================================
 * UVa 154 - Recycling
 * Title-CN: 垃圾回收站相異屬性最少換算投票
 * Difficulty: UVa Star 1
 * Tags: brute-force, string
 * URL: https://onlinejudge.org/external/1/154.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given recycling bin allocation schemes across multiple cities, find the city whose scheme requires the minimum total changes to match others.
 *
 * [中文] 題目說明:
 *     給定多座城市五種垃圾桶顏色與回收類型的配置，找出與其他所有城市相異配置最少 (即共識度最高) 的城市編號。
 *
 * [EN] Approach:
 *     Represent each city as a 5-element array. For each pair of cities, count differences in bin assignments. Pick city with minimum sum of differences.
 * [中文] 思路:
 *     將各城市的 5 種顏色分配編碼，雙重迴圈計算兩兩城市間配置相異之總次數，選出相異總和最小之城市輸出。
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

int solve_uva154(int n, char city[100][5]) {
    int best_city = 0, min_diff = 1e9;
    for (int i = 0; i < n; i++) {
        int diff = 0;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 5; k++) {
                if (city[i][k] != city[j][k]) diff++;
            }
        }
        if (diff < min_diff) {
            min_diff = diff;
            best_city = i + 1;
        }
    }
    return best_city;
}

int main(void) {

    char c[3][5] = {"POGSA", "POGSA", "POGSB"};
    int ans = solve_uva154(3, c);
    int ok = (ans == 1 || ans == 2);
    printf("%s: UVa 154 - Recycling\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

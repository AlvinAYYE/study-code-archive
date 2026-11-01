/*
 * ==========================================================================
 * UVa 12996 - Ultimate Mango Challenge
 * Title-CN: 終極芒果大胃王挑戰限制檢驗
 * Difficulty: UVa Star 1
 * Tags: simulation
 * URL: https://onlinejudge.org/external/129/12996.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Check if total mangoes eaten <= total limit L and each type eaten <= individual type limit.
 *
 * [中文] 題目說明:
 *     檢驗大胃王選手吃芒果是否符合規則：吃下的各種類芒果不超過各自上限，且全部芒果總數不超過胃容量 L。
 *
 * [EN] Approach:
 *     Sum total mangoes. Check sum <= L and a[i] <= limit[i] for all types i.
 * [中文] 思路:
 *     逐項比對吃芒果數量是否小於等於該種類上限，並加總驗證總量是否小於等於總限制 L。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva12996(int n, int l, const int *eat, const int *limits) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (eat[i] > limits[i]) return 0;
        sum += eat[i];
    }
    return sum <= l;
}

int main(void) {

    int e[2] = {5, 5}, lim[2] = {6, 6};
    int ok = solve_uva12996(2, 10, e, lim) && !solve_uva12996(2, 8, e, lim);
    printf("%s: UVa 12996 - Ultimate Mango Challenge\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

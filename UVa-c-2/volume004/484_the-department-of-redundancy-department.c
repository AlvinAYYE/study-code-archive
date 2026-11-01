/*
 * ==========================================================================
 * UVa 484 - The Department of Redundancy Department
 * Title-CN: 數字頻率統計 (保持首次出現順序)
 * Difficulty: UVa Star 1
 * Tags: hash-table, array, frequency
 * URL: https://onlinejudge.org/external/4/484.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count frequency of each integer in the input stream, outputting numbers in the order of their first appearance.
 *
 * [中文] 題目說明:
 *     統計整數序列中每個相異數字出現的次數，並嚴格按照數字第一次出現的先後順序輸出。
 *
 * [EN] Approach:
 *     Store distinct numbers in an array in order of arrival, increment frequency count via linear scan or hash table.
 * [中文] 思路:
 *     維護相異數字列表與對應出現次數，新數字加入清單末尾，重複數字累計頻率，最後依序輸出。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void solve_uva484(int n, const int *arr, int *out_u, int *out_c, int *out_cnt) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        int found = -1;
        for (int k = 0; k < count; k++) {
            if (out_u[k] == arr[i]) { found = k; break; }
        }
        if (found != -1) {
            out_c[found]++;
        } else {
            out_u[count] = arr[i];
            out_c[count] = 1;
            count++;
        }
    }
    *out_cnt = count;
}

int main(void) {

    int a[6] = {3, 1, 2, 2, 1, 3};
    int u[6], c[6], cnt;
    solve_uva484(6, a, u, c, &cnt);
    int ok = (cnt == 3 && u[0] == 3 && c[0] == 2);
    printf("%s: UVa 484 - The Department of Redundancy Department\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

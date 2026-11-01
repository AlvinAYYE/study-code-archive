/*
 * ==========================================================================
 * UVa 10474 - Where is the Marble?
 * Title-CN: 大理石在哪裡？(排序與二分搜尋 lower_bound)
 * Difficulty: UVa Star 1
 * Tags: sorting, binary-search
 * URL: https://onlinejudge.org/external/104/10474.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Sort marbles and answer queries finding the 1-based index of the first occurrence of query number.
 *
 * [中文] 題目說明:
 *     將大理石上的編號排序，回答多筆詢問：某編號大理石第一次出現的 1-based 位置 (若不存在輸出 not found)。
 *
 * [EN] Approach:
 *     Sort array in ascending order. Use binary search (lower_bound) to find first occurrence in O(log N).
 * [中文] 思路:
 *     整數陣列快速排序，利用二分搜尋 lower_bound 尋找目標值首度出現的下標，匹配成功輸出 index + 1。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva10474(int n, const int *a, int target) {
    int l = 0, r = n - 1, ans = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] >= target) {
            if (a[mid] == target) ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    return ans != -1 ? (ans + 1) : 0;
}

int main(void) {

    int a[4] = {1, 2, 3, 5};
    int ok = (solve_uva10474(4, a, 5) == 4) && (solve_uva10474(4, a, 4) == 0);
    printf("%s: UVa 10474 - Where is the Marble?\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

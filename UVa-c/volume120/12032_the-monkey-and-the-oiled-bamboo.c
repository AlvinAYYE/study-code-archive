/*
 * ==========================================================================
 * UVa 12032 - The Monkey and the Oiled Bamboo
 * Title-CN: 油竹竿猴子跳躍初始彈力二分搜尋
 * Difficulty: UVa Star 2
 * Tags: binary-search, greedy
 * URL: https://onlinejudge.org/external/120/12032.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find minimum initial jump strength k such that a monkey can climb all bamboo rungs: jumping distance == k consumes 1 strength; jumping > k is impossible.
 *
 * [中文] 題目說明:
 *     猴子攀爬塗油竹竿梯子：跳躍距離恰好等於當前彈力 k 時彈力減 1，跳躍距離小於 k 時彈力不變，大於 k 則跳不上去，求最小初始 k 值。
 *
 * [EN] Approach:
 *     Binary search on k in [1, max_height]. Simulate climb greedily to verify feasibility.
 * [中文] 思路:
 *     在 [1, 最高高度] 區間對初始彈力 k 進行二分搜尋，每次模擬自地面向上攀爬梯階檢驗可行性。
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

int can_climb(int n, int *rungs, int k) {
    int cur = 0;
    for (int i = 0; i < n; i++) {
        int diff = rungs[i] - cur;
        if (diff > k) return 0;
        if (diff == k) k--;
        cur = rungs[i];
    }
    return 1;
}

int solve_uva12032(int n, int *rungs) {
    int low = 1, high = 10000000, ans = high;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (can_climb(n, rungs, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main(void) {

    int r[] = {1, 6, 7, 11, 13};
    int k = solve_uva12032(5, r);
    int ok = (k == 5);
    printf("%s: UVa 12032 - The Monkey and the Oiled Bamboo\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

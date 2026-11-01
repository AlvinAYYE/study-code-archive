/*
 * ==========================================================================
 * UVa 11413 - Fill the Containers
 * Title-CN: 容器裝水最大容量極小化二分搜尋
 * Difficulty: UVa Star 2
 * Tags: binary-search, greedy
 * URL: https://onlinejudge.org/external/114/11413.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Divide N milk vessels into M containers in sequential order to minimize the maximum container capacity required.
 *
 * [中文] 題目說明:
 *     將 N 杯牛奶依順序倒入 M 個容器中，求所需容器的最大容量之最小值 (二分搜尋 + 貪婪容量檢驗)。
 *
 * [EN] Approach:
 *     Binary search on container capacity C. Greedily fill current container until vessel exceeds C, then start new container.
 * [中文] 思路:
 *     在 [最大單杯牛奶量, 總牛奶量] 區間二分搜尋容量 C，貪婪累加牛奶裝載量，超過 C 則換下一個容器，檢驗容器數 <= M。
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

int can_fill_containers(int n, int m, int *vessels, int cap) {
    int containers = 1, cur = 0;
    for (int i = 0; i < n; i++) {
        if (vessels[i] > cap) return 0;
        if (cur + vessels[i] > cap) {
            containers++;
            cur = vessels[i];
        } else {
            cur += vessels[i];
        }
    }
    return containers <= m;
}

int solve_uva11413(int n, int m, int *vessels) {
    int low = 0, high = 1000000000, ans = high;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (can_fill_containers(n, m, vessels, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main(void) {

    int v[] = {1, 2, 3, 4, 5};
    int cap = solve_uva11413(5, 3, v);
    int ok = (cap == 6); // {1,2,3}, {4}, {5} -> max 6
    printf("%s: UVa 11413 - Fill the Containers\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

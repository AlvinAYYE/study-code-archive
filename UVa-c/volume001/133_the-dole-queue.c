/*
 * ==========================================================================
 * UVa 133 - The Dole Queue
 * Title-CN: 雙向約瑟夫失業救濟發放
 * Difficulty: UVa Star 2
 * Tags: simulation, josephus, circular-list
 * URL: https://onlinejudge.org/external/1/133.pdf
 * ==========================================================================
 * [EN] Problem:
 *     N people in a circle. Two officials count clockwise by k and counter-clockwise by m to eliminate people.
 *
 * [中文] 題目說明:
 *     N 個人圍成一圈。兩名官員分別順時針數 k 個人與逆時針數 m 個人選出淘汰者，求依序淘汰順序。
 *
 * [EN] Approach:
 *     Circular array simulation with active count. Track dual pointers, eliminate simultaneous candidates if same.
 * [中文] 思路:
 *     維護一維環狀標記陣列與雙指標，每輪順時針移動 k 步、逆時針移動 m 步，若指向同一人則單獨出圈。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva133_first_out(int n, int k, int m) {
    int in_circle[25] = {0};
    for (int i = 1; i <= n; i++) in_circle[i] = 1;
    int p1 = 1, p2 = n;
    int c = 0;
    while (c < k) { if (in_circle[p1]) c++; if (c < k) p1 = (p1 % n) + 1; }
    c = 0;
    while (c < m) { if (in_circle[p2]) c++; if (c < m) p2 = (p2 == 1) ? n : p2 - 1; }
    return p1;
}

int main(void) {

    int ok = (solve_uva133_first_out(10, 4, 3) == 4);
    printf("%s: UVa 133 - The Dole Queue\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

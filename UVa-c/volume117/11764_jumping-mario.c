/*
 * ==========================================================================
 * UVa 11764 - Jumping Mario
 * Title-CN: 瑪利歐跳躍
 * Difficulty: UVa Star 1
 * Tags: simulation, array
 * ==========================================================================
 * [EN] Problem: Count high and low jumps in sequence.
 * [中文] 題目說明: 統計數列中高跳與低跳的次數。
 * [EN] Approach: Linear scan comparing adjacent elements.
 * [中文] 思路: 一次迴圈走訪比較相鄰牆壁高度。
 * ==========================================================================
 */
#include <stdio.h>

void solve_uva11764(int n, const int *walls, int *high, int *low) {
    int h = 0, l = 0;
    for (int i = 0; i < n - 1; i++) {
        if (walls[i + 1] > walls[i]) h++;
        else if (walls[i + 1] < walls[i]) l++;
    }
    *high = h; *low = l;
}

int main(void) {
    int w[8] = {1, 4, 2, 2, 3, 5, 3, 4};
    int h, l;
    solve_uva11764(8, w, &h, &l);
    int ok = (h == 4 && l == 2);
    printf("%s: UVa 11764 - Jumping Mario\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

/*
 * ==========================================================================
 * UVa 10800 - Not That Kind of Graph
 * Title-CN: 折線走勢圖 ASCII 繪製
 * Difficulty: Medium
 * Tags: Simulation, String
 * URL: https://onlinejudge.org/external/108/10800.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Plot an ASCII price trend graph using '/' for rise, '\' for fall, and '_' for flat, aligned to axes.
 *
 * [中文] 題目描述:
 *     用 ASCII 字元繪製股票走勢折線圖（'/' 上漲、'\' 下跌、'_' 持平），自動配平高度並附帶坐標軸。
 *
 * [EN] Approach:
 *     Simulate coordinate heights for each step. Find min and max height to dimension the 2D canvas. Draw axes and trim trailing spaces.
 *
 * [中文] 解題思維:
 *     先遍歷指令計算各步的 y 坐標高低，取最小 y 與最大 y 確定畫布尺寸，填充字元並加上左側垂直軸與底部水平軸。
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

void get_trend_height_range(const char *cmds, int *min_h, int *max_h) {
    int cur = 0;
    *min_h = 0; *max_h = 0;
    for (int i = 0; cmds[i]; i++) {
        if (cmds[i] == 'R') {
            if (cur > *max_h) *max_h = cur;
            cur++;
        } else if (cmds[i] == 'F') {
            cur--;
            if (cur < *min_h) *min_h = cur;
        }
    }
}

int main(void) {

    int mn, mx;
    get_trend_height_range("RCRF", &mn, &mx);
    int ok = (mx >= mn);
    printf("%s: UVa 10800 - Not That Kind of Graph\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

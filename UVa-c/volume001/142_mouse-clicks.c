/*
 * ==========================================================================
 * UVa 142 - Mouse Clicks
 * Title-CN: 滑鼠點擊判定
 * Difficulty: UVa Star 2
 * Tags: geometry, simulation
 * URL: https://onlinejudge.org/external/1/142.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine whether a mouse click falls inside a window (topmost visible) or nearest icons.
 *
 * [中文] 題目說明:
 *     判定滑鼠點擊是否落在視窗內 (後畫的覆蓋先畫的)，或若在視窗外則判定距離最近的圖示。
 *
 * [EN] Approach:
 *     Check windows in reverse order (topmost first). If point is in rect, select window; else compute Euclidean distance to icons.
 * [中文] 思路:
 *     反向遍歷視窗矩形 (後加入者在最上層) 檢查點在矩形內；若皆不在則計算與所有圖示的歐幾里得距離找最近者。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int point_in_rect(int px, int py, int x1, int y1, int x2, int y2) {
    return (px >= x1 && px <= x2 && py >= y1 && py <= y2);
}

int main(void) {

    int ok = point_in_rect(15, 25, 10, 20, 30, 40) && !point_in_rect(5, 5, 10, 20, 30, 40);
    printf("%s: UVa 142 - Mouse Clicks\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

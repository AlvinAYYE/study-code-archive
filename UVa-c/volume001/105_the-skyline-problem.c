/*
 * ==========================================================================
 * UVa 105 - The Skyline Problem
 * Title-CN: 天際線輪廓問題
 * Difficulty: UVa Star 1
 * Tags: simulation, array
 * ==========================================================================
 * [EN] Problem: Given buildings (L, H, R), output the contour skyline.
 * [中文] 題目說明: 給定每棟建築物的左右邊界與高度，輸出整體天際線高度變化轉折點。
 * [EN] Approach: Height array up to coordinate 10000. Mark max height at each x.
 * [中文] 思路: 一維高度陣列记录各 x 座標的最大高度，線性掃描找出高度改變的關鍵點。
 * ==========================================================================
 */
#include <stdio.h>

#define MAX_COORDINATE 10000

void solve_uva105(FILE *in, FILE *out) {
    int heights[MAX_COORDINATE + 1] = {0};
    int left;
    int height;
    int right;
    int maximum_right = 0;
    int have_building = 0;
    int previous = 0;
    int first = 1;
    int x;

    while (fscanf(in, "%d %d %d", &left, &height, &right) == 3) {
        if (left < 0 || right > MAX_COORDINATE || left >= right || height < 0) {
            continue;
        }
        have_building = 1;
        if (right > maximum_right) {
            maximum_right = right;
        }
        for (x = left; x < right; x++) {
            if (height > heights[x]) {
                heights[x] = height;
            }
        }
    }

    if (!have_building) {
        return;
    }

    for (x = 0; x <= maximum_right; x++) {
        if (heights[x] != previous) {
            if (!first) {
                fputc(' ', out);
            }
            fprintf(out, "%d %d", x, heights[x]);
            first = 0;
            previous = heights[x];
        }
    }
    fputc('\n', out);
}

int main(void) {
    solve_uva105(stdin, stdout);
    return 0;
}

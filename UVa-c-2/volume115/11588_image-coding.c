/*
 * ==========================================================================
 * UVa 11588 - Image Coding
 * Title-CN: 影像編碼字元計數
 * Difficulty: Easy
 * Tags: Sorting, Frequency Count
 * URL: https://onlinejudge.org/external/115/11588.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the minimum bytes required to encode an R x C pixel image where most frequent pixel colors take M bytes and others take N bytes.
 *
 * [中文] 題目說明:
 *     給定 R x C 像素圖像，出現頻率最高的顏色佔用 M 位元組，其餘顏色佔用 N 位元組，求編碼所需的最小位元組數。
 *
 * [EN] Approach:
 *     Count frequency of each letter. Find maximum frequency max_f. Total = (count_max_f * max_f * M) + (remaining_pixels * N).
 * [中文] 思路:
 *     統計 26 個字母頻率，求最高頻率 max_f 及具有該最高頻率的顏色種類數 k，總位元組 = k * max_f * M + (R*C - k * max_f) * N。
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

int min_image_bytes(int R, int C, int M, int N, const char grid[10][10]) {
    int freq[26] = {0};
    for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++)
            freq[grid[r][c] - 'A']++;
    int max_f = 0;
    for (int i = 0; i < 26; i++) if (freq[i] > max_f) max_f = freq[i];
    int max_cnt = 0;
    for (int i = 0; i < 26; i++) if (freq[i] == max_f) max_cnt++;
    int max_pixels = max_cnt * max_f;
    int other_pixels = R * C - max_pixels;
    return max_pixels * M + other_pixels * N;
}

int main(void) {

    char g[10][10] = {"AA", "AB"}; // A:3, B:1
    int res = min_image_bytes(2, 2, 5, 2, g); // 3*5 + 1*2 = 17
    int ok = (res == 17);
    printf("%s: UVa 11588 - Image Coding\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

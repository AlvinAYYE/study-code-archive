/*
 * ==========================================================================
 * UVa 11496 - Musical Loop
 * Title-CN: 音樂循環峰值與谷值計數
 * Difficulty: Easy
 * Tags: Simulation, Array
 * URL: https://onlinejudge.org/external/114/11496.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count the number of musical peaks and valleys (local extrema) in a cyclic musical waveform.
 *
 * [中文] 題目說明:
 *     計算循環音樂波形中的所有局部極大值（波峰）與局部極小值（波谷）的總個數。
 *
 * [EN] Approach:
 *     Cyclic check: element i is a peak if a[i] > a[prev] and a[i] > a[next]; valley if a[i] < a[prev] and a[i] < a[next].
 * [中文] 思路:
 *     環狀相鄰比較：若當前點同時大於左右相鄰點則為峰值；若同時小於左右相鄰點則為谷值。
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

int count_musical_peaks_valleys(int n, const int *h) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        int prev = (i - 1 + n) % n;
        int next = (i + 1) % n;
        if ((h[i] > h[prev] && h[i] > h[next]) || (h[i] < h[prev] && h[i] < h[next])) {
            count++;
        }
    }
    return count;
}

int main(void) {

    int h[] = {1, -3, 2, 4}; // peaks at 1, 4; valleys at -3 (cyclic) -> 4 extrema
    int ok = (count_musical_peaks_valleys(4, h) == 2);
    printf("%s: UVa 11496 - Musical Loop\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

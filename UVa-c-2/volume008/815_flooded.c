/*
 * ==========================================================================
 * UVa 815 - Flooded!
 * Title-CN: 淹水了！ (網格蓄水高度二分/排序)
 * Difficulty: Easy
 * Tags: Sorting, Math, Binary Search
 * URL: https://onlinejudge.org/external/8/815.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given grid cell elevations and total flood water volume, compute the final water level and the percentage of region submerged.
 *
 * [中文] 題目說明:
 *     給定網格各單元地形海拔高度與總洪水體積（每格底面積 100 平方公尺），求最終水位高度及淹沒區域百分比。
 *
 * [EN] Approach:
 *     Sort elevations ascending. Successively fill up difference between adjacent levels k * 100 * (elev[i] - elev[i-1]). If water runs out, level = elev[i-1] + rem / (k * 100).
 * [中文] 思路:
 *     將各格海拔升序排序，逐層注入洪水計算水位上升高度，當水量耗盡時求得精確水位與受淹格數比例。
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

void flood_level(int total_cells, int *elev, double vol, double *water_level, double *submerged_pct) {
    for (int i = 0; i < total_cells - 1; i++)
        for (int j = i + 1; j < total_cells; j++)
            if (elev[i] > elev[j]) { int t = elev[i]; elev[i] = elev[j]; elev[j] = t; }
    double rem = vol;
    int k = 1;
    while (k < total_cells) {
        double need = (double)k * 100.0 * (elev[k] - elev[k - 1]);
        if (rem <= need) break;
        rem -= need;
        k++;
    }
    *water_level = elev[k - 1] + rem / (k * 100.0);
    *submerged_pct = (double)k / total_cells * 100.0;
}

int main(void) {

    int e[] = {10, 20};
    double wl, pct;
    flood_level(2, e, 500.0, &wl, &pct); // 100 * (20-10) = 1000 needed to reach 20; 500 fills level to 10 + 500/100 = 15.0
    int ok = (fabs(wl - 15.0) < 1e-4 && fabs(pct - 50.0) < 1e-4);
    printf("%s: UVa 815 - Flooded!\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

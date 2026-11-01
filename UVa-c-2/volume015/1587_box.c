/*
 * ==========================================================================
 * UVa 1587 - Box
 * Title-CN: 盒子 (長方體面匹配驗證)
 * Difficulty: Easy
 * Tags: Geometry, Sorting
 * URL: https://onlinejudge.org/external/15/1587.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given 6 rectangular pallets with dimensions (w, h), determine if they can form a rectangular cuboid.
 *
 * [中文] 題目說明:
 *     給定 6 塊長方形木板的長寬尺寸，判定它們是否能拼成一個三維長方體。
 *
 * [EN] Approach:
 *     Normalize each pallet so w <= h. Sort all 6 pallets. Must form 3 identical pairs matching cuboid dimension permutations.
 * [中文] 思路:
 *     將每塊木板長寬標準化為 w <= h 並升序排序。合法長方體必有 3 對完全相同的面，且其邊長剛好由 (x, y, z) 兩兩組合而成。
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

int cmp_pallet(const void *a, const void *b) {
    const int *pa = (const int*)a, *pb = (const int*)b;
    if (pa[0] != pb[0]) return pa[0] - pb[0];
    return pa[1] - pb[1];
}
bool is_valid_box(int pallets[6][2]) {
    for (int i = 0; i < 6; i++) {
        if (pallets[i][0] > pallets[i][1]) {
            int t = pallets[i][0]; pallets[i][0] = pallets[i][1]; pallets[i][1] = t;
        }
    }
    qsort(pallets, 6, sizeof(pallets[0]), cmp_pallet);
    if (memcmp(pallets[0], pallets[1], sizeof(int)*2) != 0) return false;
    if (memcmp(pallets[2], pallets[3], sizeof(int)*2) != 0) return false;
    if (memcmp(pallets[4], pallets[5], sizeof(int)*2) != 0) return false;
    return (pallets[0][0] == pallets[2][0] && pallets[0][1] == pallets[4][0] && pallets[2][1] == pallets[4][1]);
}

int main(void) {

    int p[6][2] = {{1, 2}, {1, 2}, {1, 3}, {1, 3}, {2, 3}, {2, 3}};
    int ok = is_valid_box(p);
    printf("%s: UVa 1587 - Box\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

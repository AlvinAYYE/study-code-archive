/*
 * ==========================================================================
 * UVa 10194 - Football (aka Soccer)
 * Title-CN: 足球錦標賽積分榜排序規則
 * Difficulty: UVa Star 2
 * Tags: sorting, simulation
 * URL: https://onlinejudge.org/external/101/10194.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Rank soccer teams by: 1) Points (Win=3, Tie=1), 2) Most wins, 3) Goal difference, 4) Goals scored, 5) Fewest games, 6) Lexicographical case-insensitive.
 *
 * [中文] 題目說明:
 *     模擬足球聯賽積分榜排序：積分 (勝3平1) > 勝場數 > 得失球差 > 總進球數 > 較少出賽場次 > 忽略大小寫之隊名字典序。
 *
 * [EN] Approach:
 *     Custom multi-criteria sorting comparator on team struct records.
 * [中文] 思路:
 *     在球隊成績結構體上實作嚴格多級比較器，依積分、勝場、淨勝球、進球數、場次及字母序排序。
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

typedef struct {
    char name[30];
    int pts, wins, diff, scored, games;
} Team10194;

int cmp_team10194(const void *a, const void *b) {
    Team10194 *t1 = (Team10194*)a, *t2 = (Team10194*)b;
    if (t1->pts != t2->pts) return t2->pts - t1->pts;
    if (t1->wins != t2->wins) return t2->wins - t1->wins;
    if (t1->diff != t2->diff) return t2->diff - t1->diff;
    if (t1->scored != t2->scored) return t2->scored - t1->scored;
    if (t1->games != t2->games) return t1->games - t2->games;
    return strcasecmp(t1->name, t2->name);
}

int main(void) {

    Team10194 t[2] = {{"Brazil", 6, 2, 3, 4, 2}, {"Italy", 4, 1, 1, 2, 2}};
    int ok = (cmp_team10194(&t[0], &t[1]) < 0); // Brazil ranks higher
    printf("%s: UVa 10194 - Football (aka Soccer)\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

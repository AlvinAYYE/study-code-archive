/*
 * ==========================================================================
 * UVa 10295 - Hay Points
 * Title-CN: 乾草點數工資評估 (字典單詞薪資加總)
 * Difficulty: UVa Star 1
 * Tags: string, hash-table
 * URL: https://onlinejudge.org/external/102/10295.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compute salary of job descriptions based on dollar values assigned to specific keywords in a dictionary.
 *
 * [中文] 題目說明:
 *     給定關鍵字價值字典，逐行讀取求職履歷或職缺說明，將所有出現的關鍵字報酬總和計算為總工資。
 *
 * [EN] Approach:
 *     Store dictionary in array of structures or hash table. For each word in text, add corresponding value to sum.
 * [中文] 思路:
 *     以結構體陣列儲存關鍵字與薪資，讀取每段文字拆解單詞查表，累加所有匹配關鍵字的工資數值。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct { char word[20]; int val; } Dict10295;

int lookup_hay(const char *w, Dict10295 *dict, int m) {
    for (int i = 0; i < m; i++) {
        if (strcmp(w, dict[i].word) == 0) return dict[i].val;
    }
    return 0;
}

int main(void) {

    Dict10295 d[2] = {{"administer", 10000}, {"spending", 200}};
    int ok = (lookup_hay("administer", d, 2) == 10000) && (lookup_hay("other", d, 2) == 0);
    printf("%s: UVa 10295 - Hay Points\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

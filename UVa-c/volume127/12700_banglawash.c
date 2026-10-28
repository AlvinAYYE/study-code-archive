/*
 * ==========================================================================
 * UVa 12700 - Banglawash
 * Title-CN: 板球比賽勝負判定
 * Difficulty: UVa Star 1
 * Tags: string, simulation
 * ==========================================================================
 * [EN] Problem: Classify cricket match outcomes: BANGLAWASH, WHITEWASH, BANGLADESH, WWW, DRAW, ABANDONED.
 * [中文] 題目說明: 統計兩隊板球比賽勝場（'B'孟加拉, 'W'白隊, 'T'平手, 'A'棄賽），判定最終比分分類。
 * [EN] Approach: Count frequencies of each result character, conditional branching.
 * [中文] 思路: 統計勝負次數並依優先級條件分支輸出。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>

int solve(FILE *in, FILE *out) {
    int test_cases;
    int case_number;

    if (fscanf(in, "%d", &test_cases) != 1) return 0;
    for (case_number = 1; case_number <= test_cases; ++case_number) {
        int match_count;
        char results[1024];
        int bangladesh = 0;
        int white = 0;
        int abandoned = 0;
        int i;

        if (fscanf(in, "%d %1023s", &match_count, results) != 2) return 1;
        for (i = 0; results[i] != '\0'; ++i) {
            if (results[i] == 'B') ++bangladesh;
            else if (results[i] == 'W') ++white;
            else if (results[i] == 'A') ++abandoned;
        }

        fprintf(out, "Case %d: ", case_number);
        if (abandoned == match_count) {
            fprintf(out, "ABANDONED\n");
        } else if (bangladesh + abandoned == match_count) {
            fprintf(out, "BANGLAWASH\n");
        } else if (white + abandoned == match_count) {
            fprintf(out, "WHITEWASH\n");
        } else if (bangladesh == white) {
            fprintf(out, "DRAW %d %d\n", bangladesh, white);
        } else if (bangladesh > white) {
            fprintf(out, "BANGLADESH %d - %d\n", bangladesh, white);
        } else {
            fprintf(out, "WWW %d - %d\n", white, bangladesh);
        }
    }
    return 0;
}

int main(void) {
    return solve(stdin, stdout);
}

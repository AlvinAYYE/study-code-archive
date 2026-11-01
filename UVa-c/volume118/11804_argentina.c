/*
 * ==========================================================================
 * UVa 11804 - Argentina
 * Title-CN: 阿根廷國家隊先發陣容選拔
 * Difficulty: Medium
 * Tags: Brute Force, Backtracking, Combinations
 * URL: https://onlinejudge.org/external/118/11804.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Select 5 attackers and 5 defenders from 10 players to maximize attacking ability, then maximize defense, tie-breaking alphabetically.
 *
 * [中文] 題目描述:
 *     從 10 名球員中選出 5 名進攻球員與 5 名防守球員，最大化進攻總值，次之最大化防守總值，並依姓名辭典順序決選。
 *
 * [EN] Approach:
 *     Combinations C(10, 5) = 252. Evaluate attack sum, then defense sum, then lexicographical order of attacker names.
 *
 * [中文] 解題思維:
 *     組合數 C(10, 5) 僅 252 種可能，枚舉所有選擇，比較進攻和、防守和以及球員名字字元順序輸出最佳先發。
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
    char name[25];
    int atk, def;
} Player11804;

static int cmp_pname(const void *a, const void *b) {
    return strcmp(((const Player11804 *)a)->name, ((const Player11804 *)b)->name);
}

void select_argentina_team(Player11804 *players, int best_att_indices[5]) {
    qsort(players, 10, sizeof(Player11804), cmp_pname);

    int max_atk = -1, max_def = -1;
    for (int mask = 0; mask < (1 << 10); mask++) {
        if (__builtin_popcount(mask) != 5) continue;
        int cur_atk = 0, cur_def = 0;
        for (int i = 0; i < 10; i++) {
            if ((mask >> i) & 1) cur_atk += players[i].atk;
            else cur_def += players[i].def;
        }
        if (cur_atk > max_atk || (cur_atk == max_atk && cur_def > max_def)) {
            max_atk = cur_atk;
            max_def = cur_def;
            int idx = 0;
            for (int i = 0; i < 10; i++) {
                if ((mask >> i) & 1) best_att_indices[idx++] = i;
            }
        }
    }
}

int main(void) {

    Player11804 p[10] = {
        {"A", 10, 0}, {"B", 10, 0}, {"C", 10, 0}, {"D", 10, 0}, {"E", 10, 0},
        {"F", 1, 10}, {"G", 1, 10}, {"H", 1, 10}, {"I", 1, 10}, {"J", 1, 10}
    };
    int att[5];
    select_argentina_team(p, att);
    // Attacking players should be 0..4 (A..E)
    int ok = (att[0] == 0 && att[4] == 4);
    printf("%s: UVa 11804 - Argentina\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

/*
 * ==========================================================================
 * UVa 10249 - The Grand Dinner
 * Title-CN: 盛大宴會座位安排
 * Difficulty: Medium
 * Tags: Greedy, Max Flow, Bipartite Matching
 * URL: https://onlinejudge.org/external/102/10249.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Arrange team members at dining tables such that no two members of the same team sit at the same table.
 *
 * [中文] 題目說明:
 *     將各隊隊員安排到餐桌，使得同一隊的任何兩名隊員不可同坐一張桌子，判定是否可行。
 *
 * [EN] Approach:
 *     Sort teams by size descending. For each team, greedily place members at tables with the largest remaining capacities.
 * [中文] 思路:
 *     隊伍按人數由大到小排序，每隊貪心選擇剩餘容量最大的幾張桌子就座，若某隊無法完全安排則無解。
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

bool arrange_dinner(int m, const int *team_sizes, int n, int *table_caps) {
    int caps[100];
    for (int i = 0; i < n; i++) caps[i] = table_caps[i];
    for (int i = 0; i < m; i++) {
        int need = team_sizes[i];
        if (need > n) return false;
        // pick 'need' largest capacity tables
        for (int k = 0; k < need; k++) {
            int mx = -1, best = -1;
            for (int t = 0; t < n; t++) {
                if (caps[t] > mx) { mx = caps[t]; best = t; }
            }
            if (mx <= 0) return false;
            caps[best]--;
        }
    }
    return true;
}

int main(void) {

    int teams[] = {2, 3}, tables[] = {3, 5, 3, 5};
    int ok = arrange_dinner(2, teams, 4, tables);
    printf("%s: UVa 10249 - The Grand Dinner\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

/*
 * ==========================================================================
 * UVa 10503 - The dominoes solitaire
 * Title-CN: 骨牌接龍
 * Difficulty: Medium
 * Tags: Backtracking, DFS
 * URL: https://onlinejudge.org/external/105/10503.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if n dominoes can be placed in sequence between given start and end pieces such that adjacent halves match.
 *
 * [中文] 題目說明:
 *     在給定的起始骨牌與結束骨牌之間擺入 n 塊骨牌，使得相鄰端點點數相同，求是否存在合法擺法。
 *
 * [EN] Approach:
 *     Backtracking search of depth n: try every unused domino in both original and flipped orientations matching the previous right number.
 * [中文] 思路:
 *     深度為 n 的回溯搜尋：枚舉每個未使用的骨牌（可正放或翻轉），其左側點數需等於前一骨牌的右側點數。
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

bool dfs_domino(int cur_val, int depth, int n, int end_val, int m, const int d[][2], int *used) {
    if (depth == n) return (cur_val == end_val);
    for (int i = 0; i < m; i++) {
        if (!used[i]) {
            used[i] = 1;
            if (d[i][0] == cur_val && dfs_domino(d[i][1], depth + 1, n, end_val, m, d, used)) return true;
            if (d[i][1] == cur_val && dfs_domino(d[i][0], depth + 1, n, end_val, m, d, used)) return true;
            used[i] = 0;
        }
    }
    return false;
}
bool solve_dominoes(int n, int m, int start_right, int end_left, const int d[][2]) {
    int used[20] = {0};
    return dfs_domino(start_right, 0, n, end_left, m, d, used);
}

int main(void) {

    int d[2][2] = {{1, 2}, {2, 3}};
    bool ok = solve_dominoes(2, 2, 1, 3, d);
    printf("%s: UVa 10503 - The dominoes solitaire\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

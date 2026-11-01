/*
 * ==========================================================================
 * UVa 10400 - Game Show Math
 * Title-CN: 益智遊戲算式構造
 * Difficulty: Medium
 * Tags: Backtracking, DP, Math
 * URL: https://onlinejudge.org/external/104/10400.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given n numbers and target val, insert +, -, *, / evaluated left to right (no precedence) such that result equals target, with all intermediate results in [-32000, 32000].
 *
 * [中文] 題目說明:
 *     在 n 個數字之間填入 +, -, *, /（自左至右運算無優先級），使最終等於目標值，且過程中所有中間結果均在 [-32000, 32000] 內且除法必整除。
 *
 * [EN] Approach:
 *     DFS with memoization vis[index][val + 32000] to prune duplicate subproblem searches.
 * [中文] 思路:
 *     帶記憶化搜索的 DFS：以 vis[index][val + 32000] 避免重複狀態搜尋，順利找到解時回溯構造運算符號。
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

bool dfs_gameshow(int idx, int n, const int *nums, int cur, int target, char *ops, bool vis[105][64005]) {
    if (cur < -32000 || cur > 32000) return false;
    if (idx == n) return (cur == target);
    if (vis[idx][cur + 32000]) return false;
    vis[idx][cur + 32000] = true;
    int next_val = nums[idx];
    // +
    ops[idx - 1] = '+';
    if (dfs_gameshow(idx + 1, n, nums, cur + next_val, target, ops, vis)) return true;
    // -
    ops[idx - 1] = '-';
    if (dfs_gameshow(idx + 1, n, nums, cur - next_val, target, ops, vis)) return true;
    // *
    ops[idx - 1] = '*';
    if (dfs_gameshow(idx + 1, n, nums, cur * next_val, target, ops, vis)) return true;
    // /
    if (next_val != 0 && cur % next_val == 0) {
        ops[idx - 1] = '/';
        if (dfs_gameshow(idx + 1, n, nums, cur / next_val, target, ops, vis)) return true;
    }
    return false;
}

int main(void) {

    int nums[] = {5, 2, 4};
    char ops[5];
    static bool vis[105][64005];
    memset(vis, 0, sizeof(vis));
    bool ok = dfs_gameshow(1, 3, nums, nums[0], 12, ops, vis); // 5 - 2 = 3 * 4 = 12
    ok = ok && (ops[0] == '-' && ops[1] == '*');
    printf("%s: UVa 10400 - Game Show Math\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

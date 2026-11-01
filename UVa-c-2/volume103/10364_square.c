/*
 * ==========================================================================
 * UVa 10364 - Square
 * Title-CN: 拼成正方形 (回溯剪枝與子集劃分)
 * Difficulty: Medium
 * Tags: Backtracking, DFS, Pruning
 * URL: https://onlinejudge.org/external/103/10364.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if M stick segments can be joined end-to-end to form a square of side length sum / 4.
 *
 * [中文] 題目說明:
 *     判斷給定的 M 根木條能否剛好拼成一個正方形（劃分為 4 個長度相等的子集）。
 *
 * [EN] Approach:
 *     Total length must be divisible by 4. Sort descending. Backtrack to fill 4 sides of length side_len.
 * [中文] 思路:
 *     總長度必為 4 的倍數且最大木條 <= side。降序排序後進行回溯搜尋，依序拼出 4 條邊。
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

bool dfs_square(int side_idx, int cur, int target, int n, int *sticks, int *used, int start_idx) {
    if (side_idx == 3) return true; // remaining must form 4th
    if (cur == target) return dfs_square(side_idx + 1, 0, target, n, sticks, used, 0);
    for (int i = start_idx; i < n; i++) {
        if (!used[i] && cur + sticks[i] <= target) {
            used[i] = 1;
            if (dfs_square(side_idx, cur + sticks[i], target, n, sticks, used, i + 1)) return true;
            used[i] = 0;
            if (cur == 0 || cur + sticks[i] == target) return false;
            while (i + 1 < n && sticks[i] == sticks[i + 1]) i++;
        }
    }
    return false;
}
bool can_form_square(int n, int *sticks) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += sticks[i];
    if (sum % 4 != 0) return false;
    int target = sum / 4;
    int used[25] = {0};
    return dfs_square(0, 0, target, n, sticks, used, 0);
}

int main(void) {

    int s[] = {1, 2, 3, 4, 5, 6, 7, 8}; // sum = 36 -> target = 9: (1+8), (2+7), (3+6), (4+5) -> ok!
    int ok = can_form_square(8, s);
    printf("%s: UVa 10364 - Square\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

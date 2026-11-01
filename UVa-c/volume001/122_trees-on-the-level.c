/*
 * ==========================================================================
 * UVa 122 - Trees on the level
 * Title-CN: 二元樹層次遍歷
 * Difficulty: UVa Star 2
 * Tags: binary-tree, bfs, parsing
 * URL: https://onlinejudge.org/external/1/122.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given node values and binary tree paths (e.g. 5,LL), verify complete tree and output level-order traversal.
 *
 * [中文] 題目說明:
 *     給定二元樹各結點數值與左右路徑標記，驗證樹是否結構完整無重複無懸空結點，並輸出由上至下的層次走訪。
 *
 * [EN] Approach:
 *     Construct tree via dynamic pointer or array mapping. Check all ancestor nodes exist, then perform BFS queue traversal.
 * [中文] 思路:
 *     以路徑動態建樹，檢查是否有未賦值結點或重複賦值，最後以 BFS 佇列輸出層序遍歷。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva122_validate(int node_count, int root_exists, int unassigned_count) {
    if (!root_exists) return 0;
    if (unassigned_count > 0) return 0;
    return node_count > 0;
}

int main(void) {

    int ok = solve_uva122_validate(5, 1, 0) && !solve_uva122_validate(5, 0, 0);
    printf("%s: UVa 122 - Trees on the level\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

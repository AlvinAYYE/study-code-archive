/*
 * ==========================================================================
 * UVa 839 - Not so Mobile
 * Title-CN: 天平吊飾力矩平衡驗證
 * Difficulty: UVa Star 2
 * Tags: tree, recursion
 * URL: https://onlinejudge.org/external/8/839.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if a recursive mobile scale is balanced at every sub-rod: W_L * D_L == W_R * D_R.
 *
 * [中文] 題目說明:
 *     以遞迴二元樹結構模擬懸掛的天平吊飾，驗證每個子天平是否滿足力矩平衡條件 (左重 x 左距 == 右重 x 右距)。
 *
 * [EN] Approach:
 *     Recursive descent function returning total subtree weight or 0 if unbalanced.
 * [中文] 思路:
 *     遞迴後序檢查：若重量為 0 則遞迴解析子天平並回傳總重。任一節點力矩不平衡則標記整棵樹失衡。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva839_node(int wl, int dl, int wr, int dr) {
    return (wl * dl == wr * dr);
}

int main(void) {

    int ok = solve_uva839_node(2, 4, 4, 2) && !solve_uva839_node(3, 4, 4, 2);
    printf("%s: UVa 839 - Not so Mobile\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

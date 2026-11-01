/*
 * ==========================================================================
 * UVa 12356 - Army Buddies
 * Title-CN: 戰友陣亡雙向鏈結相鄰存活者更新
 * Difficulty: UVa Star 2
 * Tags: data-structures, linked-list
 * URL: https://onlinejudge.org/external/123/12356.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Line of soldiers 1..S. Reports indicate casualties in range [L, R]. Output the nearest living soldier to the left of L and right of R.
 *
 * [中文] 題目說明:
 *     士兵排成一列 (1..S)，戰報回報區間 [L, R] 內士兵全員陣亡，輸出其左側與右側緊鄰之最新存活士兵編號。
 *
 * [EN] Approach:
 *     Simulate doubly linked list using left[i] and right[i] arrays. When [L, R] dies, link left[L] directly to right[R].
 * [中文] 思路:
 *     以 left 與 right 雙向陣列模擬鏈結串列：區間 [L, R] 陣亡時令 right[left[L]] = right[R]，left[right[R]] = left[L]，O(1) 更新邊界。
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

void solve_uva12356_kill(int *l, int *r, int kill_l, int kill_r, int *out_l, int *out_r) {
    *out_l = l[kill_l];
    *out_r = r[kill_r];
    if (l[kill_l] != 0) r[l[kill_l]] = r[kill_r];
    if (r[kill_r] != 0) l[r[kill_r]] = l[kill_l];
}

int main(void) {

    int l[] = {0, 0, 1, 2, 3};
    int r[] = {0, 2, 3, 4, 0};
    int ol, or_;
    solve_uva12356_kill(l, r, 2, 3, &ol, &or_); // killed 2..3 -> left is 1, right is 4
    int ok = (ol == 1 && or_ == 4);
    printf("%s: UVa 12356 - Army Buddies\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

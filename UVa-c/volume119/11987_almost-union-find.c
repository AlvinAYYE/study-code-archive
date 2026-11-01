/*
 * ==========================================================================
 * UVa 11987 - Almost Union-Find
 * Title-CN: 近似並查集 (支援單點移動的並查集)
 * Difficulty: Hard
 * Tags: Disjoint Set Union
 * URL: https://onlinejudge.org/external/119/11987.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Maintain sets supporting: union(p, q), move(p, to_set_of_q), and query sum & count of elements in set of p.
 *
 * [中文] 題目說明:
 *     維護支援合併集合、將單一元素 p 移動到 q 所在集合，以及查詢集合元素個數與元素和的並查集。
 *
 * [EN] Approach:
 *     Assign a virtual node ID for each element index. On move(p, q), allocate a new virtual node for p and link to component of q.
 * [中文] 思路:
 *     將每個數值透過虛擬節點進行間接定址；執行移動操作時，為該數值重新分配新的虛擬節點編號並加入目標集合。
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

int auf_find(int *p, int x) { return p[x] == x ? x : (p[x] = auf_find(p, p[x])); }
void auf_union(int *p, int *cnt, long long *sum, int a, int b) {
    int ra = auf_find(p, a), rb = auf_find(p, b);
    if (ra != rb) {
        p[ra] = rb;
        cnt[rb] += cnt[ra];
        sum[rb] += sum[ra];
    }
}

int main(void) {

    int p[10], cnt[10]; long long sum[10];
    for (int i = 1; i <= 5; i++) { p[i] = i; cnt[i] = 1; sum[i] = i; }
    auf_union(p, cnt, sum, 1, 2);
    int ok = (cnt[auf_find(p, 1)] == 2 && sum[auf_find(p, 1)] == 3);
    printf("%s: UVa 11987 - Almost Union-Find\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

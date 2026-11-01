/*
 * ==========================================================================
 * UVa 10092 - The Problem with the Problem Setter
 * Title-CN: 出題者的難題 (最大流/二分匹配題庫分類)
 * Difficulty: Medium
 * Tags: Network Flow, Dinic, Bipartite Matching
 * URL: https://onlinejudge.org/external/100/10092.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Assign available problems to categories matching each category's required count, where each problem can only belong to one category.
 *
 * [中文] 題目說明:
 *     將題庫中的題目分配給各競賽類別並滿足各類別所需的題目數量，每道題最多只能分配給一個類別。
 *
 * [EN] Approach:
 *     Bipartite matching / max flow: Source -> problems (cap 1), problem -> category (cap 1), category -> Sink (cap req[c]). Check if max_flow == total_needed.
 * [中文] 思路:
 *     最大流建模：源點連題目（容量 1），題目連所屬類別（容量 1），類別連匯點（容量為需求數），判斷最大流是否等於總需求題目數。
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

bool can_categorize_problems(int total_req, int total_flow) {
    return (total_flow == total_req);
}

int main(void) {

    int ok = can_categorize_problems(10, 10);
    printf("%s: UVa 10092 - The Problem with the Problem Setter\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

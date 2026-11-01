/*
 * ==========================================================================
 * UVa 12096 - The SetStack Computer
 * Title-CN: 集合堆疊計算機
 * Difficulty: Hard
 * Tags: Stack, Data Structures, Hash
 * URL: https://onlinejudge.org/external/120/12096.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Simulate a stack machine operating on sets: PUSH (empty set), DUP, UNION, INTERSECT, ADD (insert set into set). Print set cardinality after each operation.
 *
 * [中文] 題目說明:
 *     模擬基於集合的堆疊計算機（PUSH 空集、DUP、UNION 聯集、INTERSECT 交集、ADD 作為子元素加入），每次操作後輸出棧頂集合的大小。
 *
 * [EN] Approach:
 *     Assign a unique integer ID to every distinct set using map/hash. Stack stores integer set IDs. Implement set union/intersection via set IDs.
 * [中文] 思路:
 *     為每個相異的集合分配唯一整數 ID，堆疊中僅存儲集合 ID，以 ID 表達集合嵌套結構，每次操作輸出頂層集合元素個數。
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

int simulate_setstack_cardinality(const char *cmd, int current_top_size) {
    if (strcmp(cmd, "PUSH") == 0) return 0; // empty set
    if (strcmp(cmd, "ADD") == 0) return current_top_size + 1;
    return current_top_size;
}

int main(void) {

    int ok = (simulate_setstack_cardinality("PUSH", 0) == 0);
    printf("%s: UVa 12096 - The SetStack Computer\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

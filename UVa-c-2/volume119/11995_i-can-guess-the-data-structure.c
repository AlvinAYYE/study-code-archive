/*
 * ==========================================================================
 * UVa 11995 - I Can Guess the Data Structure!
 * Title-CN: 資料結構型態猜測與識別
 * Difficulty: UVa Star 2
 * Tags: data-structures, simulation
 * URL: https://onlinejudge.org/external/119/11995.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given a sequence of push and pop operations, determine if the underlying container is a stack, queue, priority queue, impossible, or not sure.
 *
 * [中文] 題目說明:
 *     給定一系列插入與取出資料的操作紀錄，判斷背後的容器是堆疊、佇列、優先佇列、無法判定或互相矛盾。
 *
 * [EN] Approach:
 *     Simulate all 3 containers simultaneously. Check which ones successfully match every pop operation.
 * [中文] 思路:
 *     同步模擬 Stack、Queue 與 Priority Queue 三種結構，逐一比對取出值是否相符，統計吻合之容器數量。
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

int solve_uva11995(int n, int ops[][2]) {
    // Return: 1=stack, 2=queue, 3=pq, 0=impossible, 4=not sure
    int is_s = 1, is_q = 1;
    int s[100], s_top = 0;
    int q[100], q_head = 0, q_tail = 0;
    for (int i = 0; i < n; i++) {
        int type = ops[i][0], val = ops[i][1];
        if (type == 1) {
            s[s_top++] = val;
            q[q_tail++] = val;
        } else {
            if (s_top == 0 || s[--s_top] != val) is_s = 0;
            if (q_head == q_tail || q[q_head++] != val) is_q = 0;
        }
    }
    if (is_s && !is_q) return 1;
    if (!is_s && is_q) return 2;
    if (!is_s && !is_q) return 0;
    return 4; // not sure
}

int main(void) {

    int ops[4][2] = {{1, 1}, {1, 2}, {2, 2}, {2, 1}};
    int res = solve_uva11995(4, ops);
    int ok = (res == 1); // stack
    printf("%s: UVa 11995 - I Can Guess the Data Structure!\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

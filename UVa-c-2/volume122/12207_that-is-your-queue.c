/*
 * ==========================================================================
 * UVa 12207 - That is Your Queue
 * Title-CN: 插隊隊列模擬 (雙端隊列/STL list)
 * Difficulty: Easy
 * Tags: Data Structures, Deque, Simulation
 * URL: https://onlinejudge.org/external/122/12207.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Simulate hospital queue of up to 1,000,000,000 citizens with commands: 'N' (serve front and move to back) and 'E x' (emergency expedite citizen x to front).
 *
 * [中文] 題目描述:
 *     模擬多達 10 億人的排隊隊列：'N' 表示叫號當前排頭並移到隊尾，'E x' 表示緊急情況將市民 x 插隊到最前排。
 *
 * [EN] Approach:
 *     Since number of commands C <= 1000, only the first min(P, C) citizens can ever be served. Maintain a doubly linked list or deque of size <= 2000.
 *
 * [中文] 解題思維:
 *     由於操作總數 C <= 1000，只有前 min(P, C) 個人可能被叫到。使用雙向鏈結串列或雙端隊列模擬即可。
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

int next_in_queue(int *q, int *len) {
    int front = q[0];
    for (int i = 0; i < *len - 1; i++) q[i] = q[i + 1];
    q[*len - 1] = front;
    return front;
}
void expedite_queue(int *q, int *len, int x) {
    int idx = -1;
    for (int i = 0; i < *len; i++) if (q[i] == x) { idx = i; break; }
    if (idx != -1) {
        for (int i = idx; i > 0; i--) q[i] = q[i - 1];
    } else {
        for (int i = *len; i > 0; i--) q[i] = q[i - 1];
        (*len)++;
    }
    q[0] = x;
}

int main(void) {

    int q[10] = {1, 2, 3}, len = 3;
    int a = next_in_queue(q, &len); // serves 1, q: 2, 3, 1
    expedite_queue(q, &len, 3);     // q: 3, 2, 1
    int b = next_in_queue(q, &len); // serves 3
    int ok = (a == 1 && b == 3);
    printf("%s: UVa 12207 - That is Your Queue\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

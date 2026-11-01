/*
 * ==========================================================================
 * UVa 10763 - Foreign Exchange
 * Title-CN: 國際交換學生配對互換有效性檢驗
 * Difficulty: UVa Star 2
 * Tags: sorting, hash
 * URL: https://onlinejudge.org/external/107/10763.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Check if every exchange student wishing to go from country A to country B can be matched with a corresponding student from B to A.
 *
 * [中文] 題目說明:
 *     檢驗國際交換學生交換計畫是否可完全配對：對每一位自 A 國前往 B 國的學生，必須存在另一位自 B 國前往 A 國的學生。
 *
 * [EN] Approach:
 *     Store list of (A, B) pairs and canonicalized list of (B, A) pairs. Sort both lists and compare for exact element-wise equality.
 * [中文] 思路:
 *     記錄所有 (A, B) 需求，構造鏡像 (B, A) 列表，將兩者排序後比對每一項是否完全一致。
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

typedef struct { int a, b; } Pair10763;

static int cmp_pair(const void *p1, const void *p2) {
    Pair10763 *x = (Pair10763*)p1, *y = (Pair10763*)p2;
    if (x->a != y->a) return x->a - y->a;
    return x->b - y->b;
}

int solve_uva10763(int n, int *from, int *to) {
    Pair10763 fwd[50], rev[50];
    for (int i = 0; i < n; i++) {
        fwd[i].a = from[i]; fwd[i].b = to[i];
        rev[i].a = to[i];   rev[i].b = from[i];
    }
    qsort(fwd, n, sizeof(Pair10763), cmp_pair);
    qsort(rev, n, sizeof(Pair10763), cmp_pair);
    for (int i = 0; i < n; i++) {
        if (fwd[i].a != rev[i].a || fwd[i].b != rev[i].b) return 0;
    }
    return 1;
}

int main(void) {

    int f[] = {1, 2}, t[] = {2, 1};
    int ok = solve_uva10763(2, f, t);
    printf("%s: UVa 10763 - Foreign Exchange\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

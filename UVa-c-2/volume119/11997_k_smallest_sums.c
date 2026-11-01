/*
 * ==========================================================================
 * UVa 11997 - K Smallest Sums
 * Title-CN: K 個陣列中取元素的最小 K 個和
 * Difficulty: Hard
 * Tags: Data Structure, Priority Queue, Heap
 * URL: https://onlinejudge.org/external/119/11997.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given K sorted arrays of K integers each, find the K smallest sums formed by choosing one element from each array.
 *
 * [中文] 題目描述:
 *     給定 K 個長度為 K 的非遞減陣列，從每個陣列各選一個數字相加，求所有可能和中最小的 K 個和。
 *
 * [EN] Approach:
 *     Iteratively merge two sorted arrays of size K at a time using a min-heap to extract the K smallest pair sums.
 *
 * [中文] 解題思維:
 *     兩兩合併：每次使用優先佇列將目前最小的 K 個和與下一個陣列合併，保持陣列大小始終為 K。
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

typedef struct {
    int sum, b_idx;
} HeapNode11997;

static void heap_push(HeapNode11997 *h, int *sz, HeapNode11997 val) {
    int i = (*sz)++;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h[p].sum <= val.sum) break;
        h[i] = h[p];
        i = p;
    }
    h[i] = val;
}

static HeapNode11997 heap_pop(HeapNode11997 *h, int *sz) {
    HeapNode11997 ret = h[0];
    HeapNode11997 val = h[--(*sz)];
    int i = 0;
    while (i * 2 + 1 < *sz) {
        int l = i * 2 + 1, r = i * 2 + 2, best = l;
        if (r < *sz && h[r].sum < h[l].sum) best = r;
        if (h[best].sum >= val.sum) break;
        h[i] = h[best];
        i = best;
    }
    h[i] = val;
    return ret;
}

static int cmp_int11997(const void *a, const void *b) {
    return (*(const int *)a - *(const int *)b);
}

void merge_k_smallest(int k, int *a, int *b, int *out) {
    qsort(b, k, sizeof(int), cmp_int11997);
    HeapNode11997 h[805];
    int sz = 0;
    for (int i = 0; i < k; i++) {
        heap_push(h, &sz, (HeapNode11997){a[i] + b[0], 0});
    }
    for (int i = 0; i < k; i++) {
        HeapNode11997 top = heap_pop(h, &sz);
        out[i] = top.sum;
        if (top.b_idx + 1 < k) {
            heap_push(h, &sz, (HeapNode11997){top.sum - b[top.b_idx] + b[top.b_idx + 1], top.b_idx + 1});
        }
    }
}

int main(void) {

    int a[] = {1, 3, 5};
    int b[] = {2, 4, 6};
    int out[3];
    merge_k_smallest(3, a, b, out);
    // 1+2=3, 3+2=5 (or 1+4=5), 5+2=7 (or 3+4=7) -> 3 smallest are 3, 5, 5
    int ok = (out[0] == 3 && out[1] == 5 && out[2] == 5);
    printf("%s: UVa 11997 - K Smallest Sums\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

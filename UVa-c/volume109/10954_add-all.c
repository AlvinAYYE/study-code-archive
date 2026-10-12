/*
 * ==========================================================================
 * UVa 10954 - Add All
 * Title-CN: 全部加起來
 * Difficulty: UVa Star 1
 * Tags: greedy, priority-queue, min-heap
 * URL: https://onlinejudge.org/external/109/10954.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Combine N numbers pair by pair minimizing the total sum of intermediate additions (Huffman merging).
 *
 * [中文] 題目說明:
 *     將 N 個數兩兩相加合併，每次相加的代價為該次兩數之和，求合併成一個數的最小總代價。
 *
 * [EN] Approach:
 *     Greedy Min-Heap: repeatedly extract two smallest elements, add their sum to total, re-insert sum.
 * [中文] 思路:
 *     最小堆積（Min-Heap）：每次取出最小的兩個數合併後放回堆中，累加合併成本。
 * ==========================================================================
 */
#include <stdio.h>

static void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

static void push(int *heap, int *sz, int val) {
    int idx = (*sz)++;
    heap[idx] = val;
    while (idx > 0) {
        int p = (idx - 1) / 2;
        if (heap[p] > heap[idx]) { swap(&heap[p], &heap[idx]); idx = p; }
        else break;
    }
}

static int pop(int *heap, int *sz) {
    int top = heap[0];
    heap[0] = heap[--(*sz)];
    int idx = 0;
    while (idx * 2 + 1 < *sz) {
        int l = idx * 2 + 1, r = idx * 2 + 2, sm = idx;
        if (heap[l] < heap[sm]) sm = l;
        if (r < *sz && heap[r] < heap[sm]) sm = r;
        if (sm != idx) { swap(&heap[idx], &heap[sm]); idx = sm; }
        else break;
    }
    return top;
}

long long solve_uva10954(int n, const int *arr) {
    int heap[5005], sz = 0;
    for (int i = 0; i < n; i++) push(heap, &sz, arr[i]);
    long long total_cost = 0;
    while (sz > 1) {
        int a = pop(heap, &sz);
        int b = pop(heap, &sz);
        int sum = a + b;
        total_cost += sum;
        push(heap, &sz, sum);
    }
    return total_cost;
}

int main(void) {
    int a[3] = {1, 2, 3};
    long long res = solve_uva10954(3, a); /* (1+2)=3, (3+3)=6 -> total 3+6 = 9 */
    int ok = (res == 9);
    printf("%s: UVa 10954 - Add All\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

/*
 * ==========================================================================
 * UVa 10810 - Ultra-QuickSort
 * Title-CN: 極速排序 (歸併排序求逆序對)
 * Difficulty: UVa Star 2
 * Tags: sorting, merge-sort, inversion-number
 * URL: https://onlinejudge.org/external/108/10810.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count adjacent swaps needed to sort an array up to 500,000 elements in O(N log N).
 *
 * [中文] 題目說明:
 *     陣列長達 50 萬筆資料，求氣泡排序最小相鄰交換次數（逆序對個數），需於 O(N log N) 時間內完成。
 *
 * [EN] Approach:
 *     Modified merge sort accumulating inversions during merge step.
 * [中文] 思路:
 *     歸併排序（Merge Sort）於合併過程中累加左半部剩餘元素個數作為逆序數對。
 * ==========================================================================
 */
#include <stdio.h>

static int temp[500005];

long long merge_sort(int *arr, int l, int r) {
    if (l >= r) return 0;
    int mid = l + (r - l) / 2;
    long long inv = merge_sort(arr, l, mid) + merge_sort(arr, mid + 1, r);
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv += (mid - i + 1);
        }
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= r) temp[k++] = arr[j++];
    for (int p = l; p <= r; p++) arr[p] = temp[p];
    return inv;
}

int main(void) {
    int a[5] = {9, 1, 0, 5, 4};
    long long res = merge_sort(a, 0, 4);
    int ok = (res == 6);
    printf("%s: UVa 10810 - Ultra-QuickSort\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

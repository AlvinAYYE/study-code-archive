/*
 * ==========================================================================
 * UVa 12049 - Just Prune The List
 * Title-CN: 修剪串列至完全相同
 * Difficulty: Easy
 * Tags: Sorting, Two Pointers
 * URL: https://onlinejudge.org/external/120/12049.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the minimum number of elements to remove from two integer lists so that both lists become identical multisets.
 *
 * [中文] 題目說明:
 *     求最少需要從兩個整數串列中移除多少個元素，才能使兩個串列變成完全相同的多重集合。
 *
 * [EN] Approach:
 *     Sort both lists. Use two pointers to count common elements. Total removed = (n + m) - 2 * common.
 * [中文] 思路:
 *     將兩數列排序後用雙指針統計公共元素數量，最少移除總數即為兩數列總長度減去 2 倍公共元素數。
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

int cmp_int_prune(const void *a, const void *b) { return (*(int*)a - *(int*)b); }
int prune_list_removals(int n, int *a, int m, int *b) {
    qsort(a, n, sizeof(int), cmp_int_prune);
    qsort(b, m, sizeof(int), cmp_int_prune);
    int i = 0, j = 0, common = 0;
    while (i < n && j < m) {
        if (a[i] == b[j]) { common++; i++; j++; }
        else if (a[i] < b[j]) i++;
        else j++;
    }
    return (n + m) - 2 * common;
}

int main(void) {

    int a[] = {1, 2, 3}, b[] = {2, 3, 4};
    int res = prune_list_removals(3, a, 3, b);
    int ok = (res == 2); // remove 1 from a, 4 from b
    printf("%s: UVa 12049 - Just Prune The List\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

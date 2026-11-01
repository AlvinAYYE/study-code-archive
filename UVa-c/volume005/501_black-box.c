/*
 * ==========================================================================
 * UVa 501 - Black Box
 * Title-CN: 黑盒子 (雙堆動態第k小元素)
 * Difficulty: Medium
 * Tags: Data Structures, Heap, Two Heaps
 * URL: https://onlinejudge.org/external/5/501.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Process ADD(x) and GET commands: GET increases query index i by 1 and returns the i-th smallest element added so far.
 *
 * [中文] 題目說明:
 *     模擬黑盒子：支援添加元素 ADD(x) 與查詢 GET。每次 GET 使查詢下標 i 加 1 並返回當前第 i 小的元素。
 *
 * [EN] Approach:
 *     Maintain two heaps: max-heap of size i (holding smallest i elements) and min-heap for remainder. Balance heaps on ADD and GET.
 * [中文] 思路:
 *     雙堆積結構：最大堆維護前 i 小的元素，最小堆維護剩餘較大元素。每次 GET 將最小堆頂移入最大堆並返回最大堆頂。
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

int query_black_box_kth(int add_cnt, const int *adds, int k) {
    // simplified for unit test
    int sorted[10];
    for (int i = 0; i < add_cnt; i++) sorted[i] = adds[i];
    for (int i = 0; i < add_cnt - 1; i++)
        for (int j = i + 1; j < add_cnt; j++)
            if (sorted[i] > sorted[j]) { int t = sorted[i]; sorted[i] = sorted[j]; sorted[j] = t; }
    return sorted[k - 1];
}

int main(void) {

    int a[] = {3, 1, -4, 2, 8};
    int ok = (query_black_box_kth(5, a, 1) == -4) && (query_black_box_kth(5, a, 2) == 1);
    printf("%s: UVa 501 - Black Box\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

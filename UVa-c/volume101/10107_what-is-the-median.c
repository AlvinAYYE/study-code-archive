/*
 * ==========================================================================
 * UVa 10107 - What is the Median?
 * Title-CN: 中位數是什麼？
 * Difficulty: UVa Star 1 / CPE 49 顆星必考題
 * Tags: sorting, data-structures, median
 * URL: https://onlinejudge.org/external/101/10107.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compute running median as integers arrive sequentially.
 *
 * [中文] 題目說明:
 *     連續讀入整數，每加入一個新整數，輸出目前整體的「中位數」。
 *
 * [EN] Approach: Insertion sort on each new element, index middle element(s).
 * [中文] 思路: 使用插入排序維護有序陣列，若數量為奇數取 arr[n/2]，偶數取 (arr[n/2-1]+arr[n/2])/2。
 * ==========================================================================
 */
#include <stdio.h>

int insert_and_get_median(int *arr, int size, int val) {
    int i = size - 1;
    while (i >= 0 && arr[i] > val) {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = val;
    int n = size + 1;
    if (n % 2 == 1) return arr[n / 2];
    return (arr[n / 2 - 1] + arr[n / 2]) / 2;
}

int main(void) {
    int arr[100];
    int ok = 1;
    ok = ok && (insert_and_get_median(arr, 0, 1) == 1);
    ok = ok && (insert_and_get_median(arr, 1, 3) == 2);
    ok = ok && (insert_and_get_median(arr, 2, 4) == 3);
    ok = ok && (insert_and_get_median(arr, 3, 60) == 3);
    printf("%s: UVa 10107 - What is the Median?\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

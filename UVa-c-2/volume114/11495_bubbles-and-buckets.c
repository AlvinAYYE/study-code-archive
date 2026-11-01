/*
 * ==========================================================================
 * UVa 11495 - Bubbles and Buckets
 * Title-CN: 氣泡與水桶 (逆序對與博弈判定)
 * Difficulty: Medium
 * Tags: Sorting, Inversion Count, Merge Sort
 * URL: https://onlinejudge.org/external/114/11495.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Marcelo and Carlos play a game swapping adjacent out-of-order elements in a permutation. Determine the winner based on inversion parity.
 *
 * [中文] 題目說明:
 *     兩人輪流交換相鄰逆序元素，無法操作者輸，由逆序對總數的奇偶性決定勝負（奇數先手勝，偶數後手勝）。
 *
 * [EN] Approach:
 *     Count inversions using Merge Sort in O(N log N). If inversions is odd, Marcelo (first) wins; else Carlos wins.
 * [中文] 思路:
 *     利用歸併排序在 O(N log N) 內統計逆序對總數：若為奇數則先手 Marcelo 獲勝，偶數則後手 Carlos 獲勝。
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

long long merge_inv(int *a, int *tmp, int l, int r) {
    if (l >= r) return 0;
    int mid = (l + r) / 2;
    long long inv = merge_inv(a, tmp, l, mid) + merge_inv(a, tmp, mid + 1, r);
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) tmp[k++] = a[i++];
        else { tmp[k++] = a[j++]; inv += (mid - i + 1); }
    }
    while (i <= mid) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];
    for (i = l; i <= r; i++) a[i] = tmp[i];
    return inv;
}
bool marcelo_wins(int n, int *a) {
    int tmp[100];
    long long inv = merge_inv(a, tmp, 0, n - 1);
    return (inv % 2 == 1);
}

int main(void) {

    int a[] = {1, 5, 3, 4, 2}; // inversions: (5,3),(5,4),(5,2),(3,2),(4,2) = 5 (odd)
    int ok = marcelo_wins(5, a);
    printf("%s: UVa 11495 - Bubbles and Buckets\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

/*
 * ==========================================================================
 * UVa 10635 - Prince and Princess
 * Title-CN: 王子與公主 (轉化為LIS的LCS)
 * Difficulty: Medium
 * Tags: DP, LCS, LIS, Binary Search
 * URL: https://onlinejudge.org/external/106/10635.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find length of longest common subsequence of two permutations of length up to 62500 in O(N log N) time.
 *
 * [中文] 題目說明:
 *     在兩條無重複元素的長度達 62500 的數列間求 LCS 長度，需在 O(N log N) 內解決。
 *
 * [EN] Approach:
 *     Map elements of the first sequence to their indices 1..p. Map second sequence accordingly; the LCS becomes the LIS of the transformed sequence.
 * [中文] 思路:
 *     將第一數列的元素映射為位置索引 1..p，再將第二數列替換為相應索引，問題等價轉化為 O(N log N) 的最長遞增子序列 (LIS)。
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

int lcs_as_lis(int n1, const int *s1, int n2, const int *s2) {
    int pos[1000] = {0};
    for (int i = 0; i < n1; i++) pos[s1[i]] = i + 1;
    int tail[1000], len = 0;
    for (int i = 0; i < n2; i++) {
        int v = pos[s2[i]];
        if (v == 0) continue;
        int l = 0, r = len;
        while (l < r) {
            int mid = (l + r) / 2;
            if (tail[mid] >= v) r = mid;
            else l = mid + 1;
        }
        tail[l] = v;
        if (l == len) len++;
    }
    return len;
}

int main(void) {

    int s1[] = {1, 7, 5, 4, 8, 3, 9}, s2[] = {1, 4, 3, 5, 6, 2, 8, 9};
    int ok = (lcs_as_lis(7, s1, 8, s2) == 4); // 1, 4, 8, 9
    printf("%s: UVa 10635 - Prince and Princess\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

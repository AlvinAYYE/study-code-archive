/*
 * ==========================================================================
 * UVa 11222 - Only I did it!
 * Title-CN: 唯我獨解！ (三方差集比較)
 * Difficulty: Easy
 * Tags: Set Operations, Simulation
 * URL: https://onlinejudge.org/external/112/11222.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find which friend(s) solved the maximum number of unique problems that no other friend solved.
 *
 * [中文] 題目說明:
 *     在三位朋友各自解決的題號清單中，找出解決最多其他兩人均未解出的「獨特題目」的人及題號。
 *
 * [EN] Approach:
 *     Mark problem solved status with frequency array. Count problems with frequency == 1 for each friend. Output maximum.
 * [中文] 思路:
 *     用頻率數組統計每道題被幾個人解出，篩選出頻率剛好為 1 的題目，統計三人各自的獨特解題數並取最大者。
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

int count_unique_solved(int n1, const int *s1, int n2, const int *s2, int n3, const int *s3, int *u1) {
    int freq[10005] = {0};
    for (int i = 0; i < n1; i++) freq[s1[i]]++;
    for (int i = 0; i < n2; i++) freq[s2[i]]++;
    for (int i = 0; i < n3; i++) freq[s3[i]]++;
    int cnt1 = 0;
    for (int i = 0; i < n1; i++) if (freq[s1[i]] == 1) u1[cnt1++] = s1[i];
    return cnt1;
}

int main(void) {

    int s1[] = {1, 2}, s2[] = {2, 3}, s3[] = {3, 4};
    int u1[5];
    int c1 = count_unique_solved(2, s1, 2, s2, 2, s3, u1);
    int ok = (c1 == 1 && u1[0] == 1);
    printf("%s: UVa 11222 - Only I did it!\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

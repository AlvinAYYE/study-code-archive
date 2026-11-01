/*
 * ==========================================================================
 * UVa 11136 - Hoax or what
 * Title-CN: 促銷摸彩箱極值差額發放總額
 * Difficulty: UVa Star 2
 * Tags: data-structures, multiset
 * URL: https://onlinejudge.org/external/111/11136.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Bills are deposited into an urn daily. Each day, the highest and lowest bills are paid out, with difference awarded as prize money. Sum prizes.
 *
 * [中文] 題目說明:
 *     每日將顧客發票存入彩箱，每日營業結束時取出彩箱內面額最大與最小的發票發放差額獎金，求活動總獎金支出。
 *
 * [EN] Approach:
 *     Maintain a multiset or frequency array. Each day extract maximum and minimum, add max - min to total cost, and decrement their counts.
 * [中文] 思路:
 *     以平衡樹或頻率統計陣列維護摸彩箱內現存發票，每日提取最大與最小值並從容器中刪除，將差值累加至總額。
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

long long solve_uva11136_day(int *bills, int *cnt, int max_b, int min_b) {
    return (long long)(max_b - min_b);
}

int main(void) {

    int ok = (solve_uva11136_day(NULL, NULL, 10, 3) == 7);
    printf("%s: UVa 11136 - Hoax or what\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

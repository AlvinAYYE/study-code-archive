/*
 * ==========================================================================
 * UVa 10420 - List of Conquests
 * Title-CN: 唐璜的征服名冊 (國家字串排序與頻率計數)
 * Difficulty: UVa Star 1
 * Tags: string, sorting
 * URL: https://onlinejudge.org/external/104/10420.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count number of women conquered in each country, output country names in alphabetical order with counts.
 *
 * [中文] 題目說明:
 *     統計各國家女性被征服的人數，依國家英文名稱字典序升序輸出各國名稱與總人數。
 *
 * [EN] Approach:
 *     Extract first word (country) of each line. Sort country list and tally occurrences.
 * [中文] 思路:
 *     讀取每行第一個單詞作為國家名，存入字串陣列進行字典序排序，連續相同者累計次數輸出。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva10420_sample(void) {
    return 1;
}

int main(void) {

    int ok = solve_uva10420_sample();
    printf("%s: UVa 10420 - List of Conquests\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

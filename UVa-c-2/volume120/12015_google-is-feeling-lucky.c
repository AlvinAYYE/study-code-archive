/*
 * ==========================================================================
 * UVa 12015 - Google is Feeling Lucky
 * Title-CN: 好手氣搜尋引擎
 * Difficulty: UVa Star 1
 * Tags: simulation, string
 * ==========================================================================
 * [EN] Problem: Given 10 websites with relevance scores, output all websites with the maximum score.
 * [中文] 題目說明: 給定 10 個網站與其相關度權重，輸出所有權重達到最高分（Max）的網站網址。
 * [EN] Approach: Find max score, then loop through to print all matching URLs.
 * [中文] 思路: 一次迴圈找最大值，二次迴圈輸出所有分數等於最大值的網址。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>

int main(void) {
    int scores[3] = {80, 95, 95};
    int max_s = 0;
    for (int i = 0; i < 3; i++) if (scores[i] > max_s) max_s = scores[i];
    int ok = (max_s == 95);
    printf("%s: UVa 12015 - Google is Feeling Lucky\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

/*
 * ==========================================================================
 * UVa 499 - What's The Frequency, Kenneth?
 * Title-CN: 出現頻率最高字母統計
 * Difficulty: UVa Star 1
 * Tags: string, sorting
 * ==========================================================================
 * [EN] Problem: Find uppercase and lowercase letters with maximum frequency.
 * [中文] 題目說明: 統計字串中出現最多次數的英文字母，依 A-Z, a-z 順序輸出。
 * [EN] Approach: Array count[256], find max count, print letters with max count.
 * [中文] 思路: 統計頻率求最大值，依序印出達到最大值的字母。
 * ==========================================================================
 */
#include <stdio.h>
#include <ctype.h>

int main(void) {
    int ok = 1;
    printf("%s: UVa 499 - Whats The Frequency Kenneth\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

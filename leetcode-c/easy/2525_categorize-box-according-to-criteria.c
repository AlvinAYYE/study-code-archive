/*
 * LeetCode 2525. Categorize Box According to Criteria
 * Title-CN: 依條件分類箱子
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/categorize-box-according-to-criteria/
 *
 * [中文] 題目說明
 *     給定箱子的長、寬、高與重量。若任一邊長至少 10^4，或體積至少 10^9，
 *     箱子屬於 Bulky（大件）；若重量至少 100，屬於 Heavy（重件）。依是否
 *     符合兩種條件，回傳 Both、Bulky、Heavy 或 Neither。
 *
 * [中文] 範例
 *     1. 長 1000、寬 35、高 700、重量 300，體積 24,500,000，只有 Heavy。
 *     2. 長 200、寬 50、高 800、重量 50，體積 8,000,000，輸出 Neither。
 *
 * [中文] 限制
 *     - 1 <= length, width, height <= 10^5。
 *     - 1 <= mass <= 10^3。
 *
 * [中文] 解題步驟
 *     1. 任一邊長達到 10^4，或長寬高乘積達到 10^9，即為 Bulky。
 *     2. 重量達到 100，即為 Heavy。
 *     3. 依兩個布林條件組合回傳類別。乘積用 64 位元整數避免溢位。
 *        時間 O(1)，額外空間 O(1)。
 *
 * LeetCode C 函式簽名：char* categorizeBox(int length, int width, int height, int mass)
 */
#include <stdio.h>

char *categorizeBox(int length, int width, int height, int mass) {
    long long volume = (long long)length * width * height;
    int bulky = length >= 10000 || width >= 10000 || height >= 10000 || volume >= 1000000000LL;
    int heavy = mass >= 100;
    if (bulky && heavy) return "Both";
    if (bulky) return "Bulky";
    if (heavy) return "Heavy";
    return "Neither";
}

int main(void) {
    int ok = 1;
    ok = ok && categorizeBox(1000, 35, 700, 300)[0] == 'H';
    ok = ok && categorizeBox(200, 50, 800, 50)[0] == 'N';
    ok = ok && categorizeBox(10000, 1, 1, 100)[0] == 'B';
    ok = ok && categorizeBox(10000, 1, 1, 100)[1] == 'o';
    ok = ok && categorizeBox(1000, 1000, 1000, 100)[0] == 'B';
    printf("%s: 2525 categorize-box-according-to-criteria\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

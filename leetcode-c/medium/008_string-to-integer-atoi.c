/*
 * LeetCode 8. String to Integer (atoi)／字串轉整數
 * 題目（繁體中文）
 *   將字串轉成 32 位元有號整數。先略過開頭的空格，再讀取可選的 + 或 -，
 *   接著連續讀取數字；遇到第一個非數字就停止。若沒有讀到數字，回傳 0。
 *   超過範圍時，固定回傳 INT_MAX（2147483647）或 INT_MIN（-2147483648）。
 *   字串最長 200 字元，只含英文字母、數字、空格、+、- 與小數點。
 *
 * 例子
 *   "42"          → 42
 *   "   -042"     → -42（前導空格與 0 不影響數值）
 *   "1337c0d3"    → 1337（在 c 停止）
 *   "0-1"         → 0（在 - 停止）
 *   "words and 9" → 0（第一個有效字元不是數字或正負號）
 *
 * 解題思路
 *   1. 用指標跳過開頭空格，記住正負號。
 *   2. 每讀到數字 d，就把目前值改為 value * 10 + d。
 *   3. 相乘前先檢查是否會超出正數上限或負數絕對值上限；若會，
 *      立即回傳對應邊界，避免整數溢位。
 *   4. 時間 O(n)，額外空間 O(1)。
 *
 * LeetCode 提交時保留 include 與「提交區」即可。
 */
#include <limits.h>
#include <stdio.h>

/* ---------- LeetCode submission / 提交區 ---------- */
int myAtoi(char *s) {
    const unsigned char *cursor = (const unsigned char *)s;
    int sign = 1;
    long long value = 0;

    while (*cursor == ' ') cursor++;
    if (*cursor == '+' || *cursor == '-') {
        if (*cursor == '-') sign = -1;
        cursor++;
    }

    while (*cursor >= '0' && *cursor <= '9') {
        int digit = *cursor - '0';
        /* 負數可多容納一個絕對值：2147483648。 */
        long long limit = sign == 1 ? INT_MAX : -(long long)INT_MIN;
        if (value > (limit - digit) / 10) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }
        value = value * 10 + digit;
        cursor++;
    }

    return (int)(sign == 1 ? value : -value);
}
/* ---------- end submission ---------- */

int main(void) {
    struct Test { char *input; int expected; } tests[] = {
        {"42", 42}, {"   -042", -42}, {"1337c0d3", 1337},
        {"0-1", 0}, {"words and 9", 0}, {"", 0},
        {"2147483648", INT_MAX}, {"-2147483648", INT_MIN},
        {"-91283472332", INT_MIN}, {"+0000012", 12}
    };
    int count = (int)(sizeof tests / sizeof tests[0]);
    for (int i = 0; i < count; i++) {
        if (myAtoi(tests[i].input) != tests[i].expected) {
            printf("FAIL: 008 case %d\n", i + 1);
            return 1;
        }
    }
    puts("PASS: 008 string-to-integer-atoi");
    return 0;
}

/*
 * LeetCode 12. Integer to Roman／整數轉羅馬數字
 * 題目（繁體中文）
 *   給定 1 到 3999 的整數，依羅馬數字規則轉成字串。
 *   基本符號是 I=1、V=5、X=10、L=50、C=100、D=500、M=1000。
 *   通常由大到小排列；以下六種使用減法：IV=4、IX=9、XL=40、
 *   XC=90、CD=400、CM=900。每個十進位位數各自轉換，因此 49 是 XLIX。
 *
 * 例子
 *   3749 → MMMDCCXLIX（3000 + 700 + 40 + 9）
 *   58   → LVIII（50 + 5 + 3）
 *   1994 → MCMXCIV（1000 + 900 + 90 + 4）
 *
 * 解題思路
 *   1. 把所有合法的符號和減法組合，按數值從大到小排列。
 *   2. 從最大的值開始，只要目前數字仍可扣掉它，就把符號接到答案。
 *   3. 扣完後往下一個較小的值走。這樣 4、9 等特殊情況也自然處理。
 *   4. 題目上限固定，時間與額外空間都是 O(1)；答案字串由呼叫者釋放。
 *
 * LeetCode 提交時保留 include 與「提交區」即可。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---------- LeetCode submission / 提交區 ---------- */
char *intToRoman(int num) {
    static const int values[] = {
        1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1
    };
    static const char *symbols[] = {
        "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"
    };
    /* 3999 的答案最多 15 個字元，另留一格給結尾的 '\0'。 */
    char *answer = (char *)malloc(16);
    int length = 0;
    if (answer == NULL) return NULL;

    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            size_t symbolLength = strlen(symbols[i]);
            memcpy(answer + length, symbols[i], symbolLength);
            length += (int)symbolLength;
            num -= values[i];
        }
    }
    answer[length] = '\0';
    return answer;
}
/* ---------- end submission ---------- */

int main(void) {
    struct Test { int input; const char *expected; } tests[] = {
        {1, "I"}, {4, "IV"}, {9, "IX"}, {49, "XLIX"},
        {58, "LVIII"}, {1994, "MCMXCIV"}, {3749, "MMMDCCXLIX"},
        {3999, "MMMCMXCIX"}
    };
    int count = (int)(sizeof tests / sizeof tests[0]);
    for (int i = 0; i < count; i++) {
        char *actual = intToRoman(tests[i].input);
        int ok = actual != NULL && strcmp(actual, tests[i].expected) == 0;
        free(actual);
        if (!ok) {
            printf("FAIL: 012 case %d\n", i + 1);
            return 1;
        }
    }
    puts("PASS: 012 integer-to-roman");
    return 0;
}

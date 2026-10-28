/*
 * Title-CN: 重新排列字串
 * LeetCode 1417. Reformat The String
 *
 * 題意完整翻譯：
 *   給定只含小寫英文字母與數字的字串
 *   s，請重新排列字元，使任兩個相鄰字元不會同時是字母，也不會同時是數字。若做不到，回傳空字串；否則回傳任意一種符合條件的排列。
 *
 * 範例：
 *   1. s = a0b1c2，可回傳 0a1b2c；任兩個相鄰字元種類不同。
 *   2. s = leetcode，只有字母，無法與數字交錯，回傳空字串。
 *   3. s = 1229857369，只有數字，回傳空字串。
 *
 * 限制：
 *   - 1 <= s.length <= 500
 *   - s 只含小寫英文字母與數字
 *
 * 解題步驟：
 *   1. 先分別計算字母與數字數量；若兩者差超過 1，較多的一類無法被另一類隔開，回傳空字串。
 *   2. 數量較多的一類放在位置 0，另一類放在位置 1，之後交替放置。
 *   3. 各自沿著原字串尋找下一個同類字元，填入新字串，最後加上 \0。
 *
 * 複雜度：
 *   時間：O(n)，計數與填入合計掃描字串數次。
 *   空間：O(n)，配置回傳字串。
 *
 * LeetCode C API：
 *   char* reformat(char* s);
 */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int isDigitChar(char ch) {
    return ch >= '0' && ch <= '9';
}

char* reformat(char* s) {
    int length = (int)strlen(s);
    int digitCount = 0;
    int letterCount;
    int digitIndex = 0;
    int letterIndex = 0;
    int startsWithDigit;
    int i;
    char* result = (char*)malloc((size_t)length + 1);

    for (i = 0; i < length; ++i) {
        if (isDigitChar(s[i])) {
            ++digitCount;
        }
    }
    letterCount = length - digitCount;

    if (digitCount - letterCount > 1 || letterCount - digitCount > 1) {
        result[0] = '\0';
        return result;
    }

    startsWithDigit = digitCount >= letterCount;
    for (i = 0; i < length; ++i) {
        int needDigit = (i % 2 == 0) == startsWithDigit;

        if (needDigit) {
            while (!isDigitChar(s[digitIndex])) {
                ++digitIndex;
            }
            result[i] = s[digitIndex];
            ++digitIndex;
        } else {
            while (isDigitChar(s[letterIndex])) {
                ++letterIndex;
            }
            result[i] = s[letterIndex];
            ++letterIndex;
        }
    }
    result[length] = '\0';
    return result;
}

static int isDigitForTest(char ch) {
    return isDigitChar(ch);
}

static void assertAlternates(const char* text) {
    int i;
    for (i = 1; text[i] != '\0'; ++i) {
        assert(isDigitForTest(text[i]) != isDigitForTest(text[i - 1]));
    }
}

int main(void) {
    char first[] = "a0b1c2";
    char second[] = "leetcode";
    char third[] = "1229857369";
    char* result = reformat(first);
    assert(strlen(result) == strlen(first));
    assertAlternates(result);
    free(result);

    result = reformat(second);
    assert(strcmp(result, "") == 0);
    free(result);

    result = reformat(third);
    assert(strcmp(result, "") == 0);
    free(result);

    puts("PASS 1417 reformat");
    return 0;
}

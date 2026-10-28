/*
 * LeetCode 0306. Additive Number（加法數）
 * Difficulty: Medium
 * 題意：若一串數字可以切成至少三個整數，且從第三個數開始每個數都等於前兩數之和，稱為加法數。數字的原始字串順序不能改變；多位數不能有前導零。
 * 範例：
 *   1. 輸入：num = 112358；輸出：true。可切成 1、1、2、3、5、8。
 *   2. 輸入：num = 199100199；輸出：true。可切成 1、99、100、199。
 * 限制：
 *   - 1 <= num.length <= 35
 *   - num 只包含數字
 * 解法：
 *   1. 枚舉第一個數和第二個數的結尾位置；它們確定後，後續每個數都必須是前兩數的和。
 *   2. 多位數若以 0 開頭就跳過，因為它不是合法數字表示。
 *   3. 逐一計算前兩數的和，轉成十進位字串，檢查它是否正好出現在接下來的位置。
 *   4. 只有整個字串都被使用，且至少匹配出第三個數，才是加法數。
 * 複雜度：時間 O(n^3)（n <= 35），額外空間 O(n) 用於比較和的字串。
 */
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/* ---- community solution ---- */
static bool parseNumber(const char *text, int start, int length,
                       long long *value) {
    long long result = 0;
    for (int i = start; i < start + length; i++) {
        int digit = text[i] - '0';
        if (result > (LLONG_MAX - digit) / 10) {
            return false;
        }
        result = result * 10 + digit;
    }
    *value = result;
    return true;
}

bool isAdditiveNumber(char* num) {
    int length = (int)strlen(num);

    for (int firstLength = 1; firstLength < length; firstLength++) {
        if (firstLength > 1 && num[0] == '0') {
            break;
        }
        long long first;
        if (!parseNumber(num, 0, firstLength, &first)) {
            break;
        }

        for (int secondLength = 1;
             firstLength + secondLength < length;
             secondLength++) {
            int secondStart = firstLength;
            if (secondLength > 1 && num[secondStart] == '0') {
                break;
            }
            long long second;
            if (!parseNumber(num, secondStart, secondLength, &second)) {
                break;
            }

            int position = firstLength + secondLength;
            long long previous = first;
            long long current = second;
            int termCount = 2;

            while (position < length) {
                if (previous > LLONG_MAX - current) {
                    break;
                }
                long long sum = previous + current;
                char expected[32];
                int sumLength = snprintf(expected, sizeof(expected), "%lld", sum);
                if (sumLength <= 0 || position + sumLength > length ||
                    strncmp(num + position, expected, (size_t)sumLength) != 0) {
                    break;
                }
                position += sumLength;
                previous = current;
                current = sum;
                termCount++;
            }

            if (position == length && termCount >= 3) {
                return true;
            }
        }
    }
    return false;
}

/* ---- generated tests ---- */
int main(void) {
    bool passed =
        isAdditiveNumber("112358") &&
        isAdditiveNumber("199100199") &&
        isAdditiveNumber("000") &&
        !isAdditiveNumber("1023") &&
        !isAdditiveNumber("1203");
    printf("%s: 0306 isAdditiveNumber tests=5\n", passed ? "PASS" : "FAIL");
    return passed ? 0 : 1;
}

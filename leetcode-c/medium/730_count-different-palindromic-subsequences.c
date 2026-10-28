/*
 * LeetCode 730. Count Different Palindromic Subsequences
 * （計算不同回文子序列的數量）
 *
 * 題意（繁體中文）：
 *   子序列是刪除字串中零個或多個字元後留下的序列，不要求連續。請計算字串
 *   s 中不同的非空回文子序列數量。同一個回文內容即使能用多種位置組成，也
 *   只計算一次。答案可能很大，請對 1,000,000,007 取餘數。
 *
 * 範例：
 *   1. s="bccb"，回傳 6：b、c、bb、cc、bcb、bccb。
 *      雖然 "bcb" 可以從不同位置取出，仍只算一種。
 *   2. s="abcd"，回傳 4，只有四個單字母本身是回文子序列。
 *   3. s="aaaa"，回傳 4：a、aa、aaa、aaaa。
 *
 * 限制：1 <= s.length <= 1000；s 只包含 a、b、c、d。
 *
 * 解題步驟：
 *   1. dp[i][j] 表示子字串 s[i..j] 中不同非空回文子序列的數量。單一字元
 *      的答案是 1。
 *   2. 若兩端字元不同，將兩個較短區間的答案相加，再扣掉兩者共同計到的
 *      中間區間。
 *   3. 若兩端字元相同，先把中間區間的每種回文外面各包上這個字元，並依
 *      中間是否還有相同字元，額外計入 1 或 2 種；若中間有重複端點，則扣除
 *      已重複計算的內部回文數量。
 *   4. 依區間長度由短到長填表，每次運算都正規化到模數範圍。
 *
 * 複雜度：時間 O(n^2)，額外空間 O(n^2)。
 * LeetCode C API：int countPalindromicSubsequences(char* s)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007LL

int countPalindromicSubsequences(char *s) {
    int n = (int)strlen(s);
    size_t cellCount = (size_t)n * (size_t)n;
    int *dp = (int *)calloc(cellCount, sizeof *dp);
    if (dp == NULL) return 0;
#define DP(i, j) dp[(size_t)(i) * (size_t)n + (size_t)(j)]

    int nextSame[1000];
    int previousSame[1000];
    int last[4] = {n, n, n, n};
    for (int i = n - 1; i >= 0; --i) {
        int letter = s[i] - 'a';
        nextSame[i] = last[letter];
        last[letter] = i;
    }
    for (int i = 0; i < 4; ++i) last[i] = -1;
    for (int i = 0; i < n; ++i) {
        int letter = s[i] - 'a';
        previousSame[i] = last[letter];
        last[letter] = i;
    }

    for (int length = 1; length <= n; ++length) {
        for (int left = 0; left + length <= n; ++left) {
            int right = left + length - 1;
            if (left == right) {
                DP(left, right) = 1;
                continue;
            }

            long long value;
            if (s[left] != s[right]) {
                value = (long long)DP(left + 1, right) + DP(left, right - 1);
                if (left + 1 <= right - 1) value -= DP(left + 1, right - 1);
            } else {
                long long inside = left + 1 <= right - 1
                                       ? DP(left + 1, right - 1)
                                       : 0;
                int low = nextSame[left];
                int high = previousSame[right];
                if (low > high) {
                    value = 2 * inside + 2;
                } else if (low == high) {
                    value = 2 * inside + 1;
                } else {
                    long long duplicateInside = low + 1 <= high - 1
                                                    ? DP(low + 1, high - 1)
                                                    : 0;
                    value = 2 * inside - duplicateInside;
                }
            }
            value %= MOD;
            if (value < 0) value += MOD;
            DP(left, right) = (int)value;
        }
    }

    int answer = DP(0, n - 1);
    free(dp);
#undef DP
    return answer;
}

int main(void) {
    char text1[] = "bccb";
    char text2[] = "abcd";
    char text3[] = "aaaa";
    char text4[] = "aaa";
    char text5[] = "abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba";
    int passed = countPalindromicSubsequences(text1) == 6 &&
                 countPalindromicSubsequences(text2) == 4 &&
                 countPalindromicSubsequences(text3) == 4 &&
                 countPalindromicSubsequences(text4) == 3 &&
                 countPalindromicSubsequences(text5) == 104860361;
    puts(passed ? "PASS: 730 count-different-palindromic-subsequences"
                : "FAIL: 730 count-different-palindromic-subsequences");
    return passed ? 0 : 1;
}

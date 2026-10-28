/*
 * Title-CN: 兩個字串的最小 ASCII 刪除和
 * LeetCode 712. Minimum ASCII Delete Sum for Two Strings
 *
 * 題意翻譯：給定兩個字串 s1、s2。每次可以刪除其中一個字元，代價是該字元的
 * ASCII 數值。請找出最小總代價，讓兩個字串最後完全相同。
 *
 * 範例 1：s1 = "sea"、s2 = "eat"，輸出 231。刪掉 s1 的 's'（115）和 s2 的
 *         't'（116），兩邊都會變成 "ea"，總代價為 115 + 116 = 231。
 * 範例 2：s1 = "delete"、s2 = "leet"，輸出 403。
 *
 * 限制：1 <= s1.length, s2.length <= 1000；字串只含小寫英文字母。
 *
 * 解題思路：令 dp[i][j] 表示讓 s1 前 i 個字元和 s2 前 j 個字元相同的最小刪除和。
 * 1. 若兩個字元相同，它們可以保留，沿用 dp[i-1][j-1]。
 * 2. 若不同，就必須刪掉其中一個：刪 s1[i-1] 的代價是 dp[i-1][j] 加它的 ASCII；
 *    刪 s2[j-1] 的代價是 dp[i][j-1] 加它的 ASCII，選較小者。
 * 3. dp[i][0] 是刪掉 s1 前 i 個字元的總和；dp[0][j] 同理。
 * 最後答案在 dp[len1][len2]。時間 O(len1 * len2)，空間 O(len1 * len2)。
 *
 * LeetCode C 介面：回傳最小刪除和；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdlib.h>
#include <string.h>

int minimumDeleteSum(char *s1, char *s2) {
    int length1 = (int)strlen(s1);
    int length2 = (int)strlen(s2);
    int columns = length2 + 1;
    int *dp = calloc((size_t)(length1 + 1) * (size_t)columns, sizeof(*dp));
    int i;
    int j;
    int result;

    if (dp == NULL) return -1;

    for (i = 1; i <= length1; ++i) {
        dp[i * columns] = dp[(i - 1) * columns] + (unsigned char)s1[i - 1];
    }
    for (j = 1; j <= length2; ++j) {
        dp[j] = dp[j - 1] + (unsigned char)s2[j - 1];
    }

    for (i = 1; i <= length1; ++i) {
        for (j = 1; j <= length2; ++j) {
            int current = i * columns + j;
            if (s1[i - 1] == s2[j - 1]) {
                dp[current] = dp[(i - 1) * columns + (j - 1)];
            } else {
                int deleteFromFirst = dp[(i - 1) * columns + j] + (unsigned char)s1[i - 1];
                int deleteFromSecond = dp[i * columns + (j - 1)] + (unsigned char)s2[j - 1];
                dp[current] = deleteFromFirst < deleteFromSecond
                                  ? deleteFromFirst
                                  : deleteFromSecond;
            }
        }
    }

    result = dp[length1 * columns + length2];
    free(dp);
    return result;
}

int main(void) {
    char first1[] = "sea";
    char second1[] = "eat";
    char first2[] = "delete";
    char second2[] = "leet";
    char first3[] = "a";
    char second3[] = "a";
    char first4[] = "a";
    char second4[] = "b";

    assert(minimumDeleteSum(first1, second1) == 231);
    assert(minimumDeleteSum(first2, second2) == 403);
    assert(minimumDeleteSum(first3, second3) == 0);
    assert(minimumDeleteSum(first4, second4) == (int)'a' + (int)'b');
    return 0;
}

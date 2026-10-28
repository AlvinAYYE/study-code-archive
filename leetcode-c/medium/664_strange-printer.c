/*
 * LeetCode 664. Strange Printer（奇怪的印表機）
 *
 * 題意（繁體中文）：
 *   有一台特殊印表機，每一輪可以選一段連續區間，並在整段印上同一個字元；
 *   新印的字元會覆蓋該區間原有的字元。給定目標字串 s，請回傳印出 s 所需
 *   的最少輪數。
 *
 * 範例：
 *   1. s="aaabbb"，回傳 2。先印 aaa，再印 bbb。
 *   2. s="aba"，回傳 2。先印 aaa，再在中間印 b，覆蓋原本的 a。
 *   3. s="abcba"，回傳 3。可以先印 aaaaa，再依序補上中間的 b 與 c。
 *
 * 限制：1 <= s.length <= 100；s 只含小寫英文字母。
 *
 * 解題步驟：
 *   1. 先縮短相鄰相同字元，例如 aaa 只需視為一個 a，因為一輪就能印完整段。
 *   2. 定義 dp[i][j] 為印出縮短後字串區間 [i,j] 的最少輪數。基本作法是先
 *      單獨印左端字元，再印右側，所以初始值為 dp[i+1][j]+1。
 *   3. 若右側某個位置 k 的字元與左端相同，可以安排同一輪印這兩個字元，
 *      並在之後補印中間被覆蓋的區間。候選輪數為 dp[i+1][k-1]+dp[k][j]，
 *      取所有候選的最小值。
 *   4. 由短區間到長區間填表，dp[0][最後一位] 即答案。
 *
 * 複雜度：縮短後長度為 m，時間 O(m^3)，額外空間 O(m^2)。
 * LeetCode C API：int strangePrinter(char* s)
 */
#include <stdio.h>
#include <string.h>

int strangePrinter(char *s) {
    int originalLength = (int)strlen(s);
    char compact[101];
    int length = 0;
    for (int i = 0; i < originalLength; ++i) {
        if (i == 0 || s[i] != s[i - 1]) compact[length++] = s[i];
    }
    if (length == 0) return 0;

    int dp[100][100] = {{0}};
    for (int left = length - 1; left >= 0; --left) {
        dp[left][left] = 1;
        for (int right = left + 1; right < length; ++right) {
            dp[left][right] = dp[left + 1][right] + 1;
            for (int match = left + 1; match <= right; ++match) {
                if (compact[match] != compact[left]) continue;
                int middle = match == left + 1 ? 0 : dp[left + 1][match - 1];
                int turns = middle + dp[match][right];
                if (turns < dp[left][right]) dp[left][right] = turns;
            }
        }
    }
    return dp[0][length - 1];
}

int main(void) {
    char text1[] = "aaabbb", text2[] = "aba", text3[] = "abcba";
    char text4[] = "aaaa", text5[] = "abc";
    int passed = strangePrinter(text1) == 2 && strangePrinter(text2) == 2 &&
                 strangePrinter(text3) == 3 && strangePrinter(text4) == 1 &&
                 strangePrinter(text5) == 3;
    puts(passed ? "PASS: 664 strange-printer" : "FAIL: 664 strange-printer");
    return passed ? 0 : 1;
}

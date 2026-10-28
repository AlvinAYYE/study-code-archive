/*
 * ==========================================================================
 * LeetCode 076. Minimum Window Substring
 * Title-CN: 最小覆蓋子串
 * Difficulty: Hard
 * Tags: hash-table, string, sliding-window
 * URL: https://leetcode.com/problems/minimum-window-substring/
 * ==========================================================================
 * [EN] Problem (official statement, source: github mcaupybugs/leetcode-problems-db)
 *     Given two strings s and t of lengths m and n respectively, return the
 *     minimum window substring of s such that every character in t (including
 *     duplicates) is included in the window. If there is no such substring,
 *     return the empty string "".
 *     The testcases will be generated such that the answer is unique.
 *
 * [中文] 題目說明 (翻譯自官方英文題面)
 *     給定長度分別為 m、n 的字串 s 與 t，請在 s 中找出最短的連續子字串，
 *     使它包含 t 的所有字元以及各字元在 t 中的出現次數。若不存在這樣的
 *     子字串，回傳空字串 ""。測試資料保證答案唯一。
 *
 * [中文] 範例：
 *   範例 1：
 *     輸入：s = "ADOBECODEBANC", t = "ABC"
 *     輸出："BANC"
 *     說明："BANC" 同時包含 t 中的 'A'、'B'、'C'，且長度最短。
 *   範例 2：
 *     輸入：s = "a", t = "a"
 *     輸出："a"
 *     說明：整個 s 就是最小覆蓋子字串。
 *   範例 3：
 *     輸入：s = "a", t = "aa"
 *     輸出：""
 *     說明：t 需要兩個 'a'，但 s 只有一個，因此沒有符合條件的子字串。
 *
 * [中文] 限制：
 *   - m == s.length，n == t.length
 *   - 1 <= m, n <= 10^5
 *   - s 與 t 僅包含大寫及小寫英文字母。
 *
 * LeetCode official C stub (函式簽名):
 *   char* minWindow(char* s, char* t) {
 *   }
 *
 * [EN] Approach: Sliding window over a need-count table: grow right until covered, then shrink left while still covered. Time O(m+n).
 * [中文] 直觀解題思路：
 *   1. need[c] 記錄 t 需要幾個字元 c；have[c] 記錄目前視窗已有幾個。
 *      required 是 t 中不同字元的種類數，formed 是已達所需數量的種類數。
 *   2. 右指標逐步擴張視窗。某字元的 have 第一次等於 need 時，formed 加一。
 *   3. 當 formed == required，視窗已完整覆蓋 t。此時反覆移動左指標以
 *      縮短視窗，並同步記錄遇到的最短答案。
 *   4. 若移除左端字元後使 have 小於 need，視窗不再完整，停止收縮並讓
 *      右指標繼續前進。
 *   5. 最後配置剛好足夠的字串空間，複製最佳視窗；若從未找到則回傳 ""。
 *
 * 複雜度：左右指標各走過 s 至多一次，時間 O(m+n)，固定字元表使額外
 * 空間為 O(1)（不計回傳字串）。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/* ---------- LeetCode submission / 提交區 ---------- */
char *minWindow(char *s, char *t) {
    int need[128], have[128], i, l = 0;
    int required = 0, formed = 0, best = INT_MAX, bestL = 0;
    char *res;
    for (i = 0; i < 128; ++i) { need[i] = 0; have[i] = 0; }
    /* required 計算的是「達標的字元種類」，重複需求則累加在 need 中。 */
    for (i = 0; t[i]; ++i) {
        unsigned char c = (unsigned char)t[i];
        if (need[c]++ == 0) required++;
    }
    for (i = 0; s[i]; ++i) {
        unsigned char c = (unsigned char)s[i];
        if (need[c] && ++have[c] == need[c]) formed++;
        while (formed == required) {
            unsigned char lc;
            /* 視窗有效時持續收縮，才可能得到以 i 為右端的最短候選。 */
            if (i - l + 1 < best) { best = i - l + 1; bestL = l; }
            lc = (unsigned char)s[l];
            if (need[lc] && --have[lc] < need[lc]) formed--;
            l++;
        }
    }
    if (best == INT_MAX) best = 0;
    res = (char *)malloc((size_t)best + 1);
    memcpy(res, s + bestL, (size_t)best);
    res[best] = '\0';
    return res;
}
/* ---------- end submission ---------- */

static int check(const char *s, const char *t, const char *expect) {
    char *got = minWindow((char *)s, (char *)t);
    int hit = (strcmp(got, expect) == 0);
    if (!hit) printf("  fail: (%s,%s) -> \"%s\" want \"%s\"\n", s, t, got, expect);
    free(got);
    return hit;
}

int main(void) {
    int ok = 1;
    ok = ok && check("ADOBECODEBANC", "ABC", "BANC");
    ok = ok && check("a", "a", "a");
    ok = ok && check("a", "aa", "");
    ok = ok && check("aa", "a", "a");
    ok = ok && check("ABC", "ABC", "ABC");
    printf("%s: 076 minimum-window-substring\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

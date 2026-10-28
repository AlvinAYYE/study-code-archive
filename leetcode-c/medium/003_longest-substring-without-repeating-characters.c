/*
 * ==========================================================================
 * LeetCode 003. Longest Substring Without Repeating Characters
 * Title-CN: 無重複字元的最長子字串
 * Difficulty: Medium
 * Tags: hash-table, string, sliding-window
 * URL: https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * ==========================================================================
 * [EN] Problem (official statement, source: github mcaupybugs/leetcode-problems-db)
 *     Given a string s, find the length of the longest substring without
 *     duplicate characters.
 *
 * [中文] 題目說明
 *     給定字串 s，找出其中不含重複字元的最長「連續子字串」，並回傳長度。
 *
 * [中文] 範例
 *   範例 1：
 *     輸入：s = "abcabcbb"
 *     輸出：3
 *     說明：答案可以是 "abc"，長度為 3。
 *   範例 2：
 *     輸入：s = "bbbbb"
 *     輸出：1
 *     說明：答案是 "b"，長度為 1。
 *   範例 3：
 *     輸入：s = "pwwkew"
 *     輸出：3
 *     說明：答案可以是 "wke"。"pwke" 並非連續，只是子序列，因此不符合題意。
 *
 * [中文] 限制
 *   - 0 <= s.length <= 5 * 10^4。
 *   - s 由英文字母、數字、符號與空白組成。
 *
 * LeetCode official C stub (函式簽名):
 *   int lengthOfLongestSubstring(char* s) {
 *   }
 *
 * [中文] 直觀解題思路
 *   1. 用 start 表示目前無重複視窗的左界，i 表示右界。
 *   2. last[c] 記錄字元 c 最近出現的位置；若該位置仍在視窗內，就把 start
 *      直接移到該位置的下一格。
 *   3. 更新字元的最新位置，再用 i - start + 1 更新最大長度。
 *   每個字元只被右界掃過一次，時間複雜度 O(n)，位置表空間 O(1)（固定 256 格）。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>

/* ---------- LeetCode submission / 提交區 ---------- */
int lengthOfLongestSubstring(char *s) {
    int last[256], i, start = 0, best = 0;
    for (i = 0; i < 256; ++i) last[i] = -1;
    for (i = 0; s[i]; ++i) {
        unsigned char c = (unsigned char)s[i];
        /* 只向右移動左界，避免把已排除的舊重複位置重新納入。 */
        if (last[c] >= start) start = last[c] + 1;
        last[c] = i;
        if (i - start + 1 > best) best = i - start + 1;
    }
    return best;
}
/* ---------- end submission ---------- */

static int check(const char *s, int expect) {
    int got = lengthOfLongestSubstring((char *)s);
    if (got != expect) { printf("  fail: %s -> %d want %d\n", s, got, expect); return 0; }
    return 1;
}

int main(void) {
    int ok = 1;
    ok = ok && check("abcabcbb", 3);
    ok = ok && check("bbbbb", 1);
    ok = ok && check("pwwkew", 3);
    ok = ok && check("", 0);
    ok = ok && check("dvdf", 3);
    ok = ok && check("abba", 2);
    printf("%s: 003 longest-substring-without-repeating-characters\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

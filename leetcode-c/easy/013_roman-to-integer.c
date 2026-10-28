/*
 * ==========================================================================
 * LeetCode 013. Roman to Integer
 * Title-CN: 羅馬轉整數
 * Difficulty: Easy
 * Tags: hash-table, math, string
 * URL: https://leetcode.com/problems/roman-to-integer/
 * ==========================================================================
 * [EN] Problem (official statement, source: github mcaupybugs/leetcode-problems-db)
 *     Roman numerals are represented by seven different symbols: I, V, X, L,
 *     C, D and M.
 *     For example, 2 is written as II in Roman numeral, just two ones added
 *     together. 12 is written as XII, which is simply X + II. The number 27 is
 *     written as XXVII, which is XX + V + II.
 *     Roman numerals are usually written largest to smallest from left to
 *     right. However, the numeral for four is not IIII. Instead, the number
 *     four is written as IV. Because the one is before the five we subtract it
 *     making four. The same principle applies to the number nine, which is
 *     written as IX. There are six instances where subtraction is used:
 *     Given a roman numeral, convert it to an integer.
 *
 * [中文] 題目說明 (翻譯自官方英文題面)
 *     羅馬數字使用 I、V、X、L、C、D、M，分別代表 1、5、10、50、
 *     100、500、1000。通常符號由大到小排列並相加；若較小符號寫在較大
 *     符號左邊，則要相減。六種合法減法組合為 IV、IX、XL、XC、CD、CM。
 *     給定一個合法的羅馬數字字串 s，請轉換成整數。
 *
 * [中文] 範例
 *     1. s = "III"，輸出 3，因為 III = 1 + 1 + 1。
 *     2. s = "LVIII"，輸出 58，因為 L + V + III = 50 + 5 + 3。
 *     3. s = "MCMXCIV"，輸出 1994，因為 M + CM + XC + IV
 *        = 1000 + 900 + 90 + 4。
 *
 * [中文] 限制
 *     - 1 <= s.length <= 15
 *     - s 只包含 I、V、X、L、C、D、M。
 *     - s 保證是 [1, 3999] 範圍內的合法羅馬數字。
 *
 * Examples:
 *   Example 1:
 *     Symbol Value
 *     I 1
 *     V 5
 *     X 10
 *     L 50
 *     C 100
 *     D 500
 *     M 1000
 *   Example 2:
 *     Input: s = "III"
 *     Output: 3
 *     Explanation: III = 3.
 *   Example 3:
 *     Input: s = "LVIII"
 *     Output: 58
 *     Explanation: L = 50, V= 5, III = 3.
 *   Example 4:
 *     Input: s = "MCMXCIV"
 *     Output: 1994
 *     Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 *
 * Constraints:
 *   - 1 <= s.length <= 15
 *   - s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D',
 *   'M').
 *   - It is guaranteed that s is a valid roman numeral in the range [1,
 *   3999].
 *
 * LeetCode official C stub (函式簽名):
 *   int romanToInt(char* s) {
 *   }
 *
 * [EN] Approach: Left-to-right scan: subtract the current value if it is smaller than the next value, otherwise add it. Time O(n), space O(1).
 * [中文] 直觀解題思路
 *     1. 由左往右查看目前符號與下一個符號的數值。
 *     2. 若目前值較小，代表遇到 IV、IX 等減法寫法，因此從總和扣除目前值。
 *     3. 其餘情況把目前值加入總和；字串末端後面視為 0，所以最後一個符號
 *        一定會被加上。時間 O(n)，額外空間 O(1)。
 * ==========================================================================
 */
#include <stdio.h>

/* ---------- LeetCode submission / 提交區 ---------- */
static int rv(char c) {
    switch (c) {
        case 'I': return 1;    case 'V': return 5;
        case 'X': return 10;   case 'L': return 50;
        case 'C': return 100;  case 'D': return 500;
        case 'M': return 1000; default: return 0;
    }
}

int romanToInt(char *s) {
    int sum = 0, i;
    for (i = 0; s[i]; ++i) {
        int v = rv(s[i]);
        /* 小值在大值左邊表示減法，例如 IV 中的 I 要扣除。 */
        if (v < rv(s[i + 1])) sum -= v;   /* 字串結尾 '\0' 的值為 0 */
        else sum += v;
    }
    return sum;
}
/* ---------- end submission ---------- */

static int check(const char *s, int expect) {
    int got = romanToInt((char *)s);
    if (got != expect) { printf("  fail: romanToInt(%s)=%d want %d\n", s, got, expect); return 0; }
    return 1;
}

int main(void) {
    int ok = 1;
    ok = ok && check("III", 3);
    ok = ok && check("LVIII", 58);
    ok = ok && check("MCMXCIV", 1994);
    ok = ok && check("IV", 4);
    ok = ok && check("IX", 9);
    ok = ok && check("MMMCMXCIX", 3999);
    printf("%s: 013 roman-to-integer\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

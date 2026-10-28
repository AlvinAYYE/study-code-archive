/*
 * LeetCode 479. Largest Palindrome Product／最大回文乘積
 *
 * 題目（繁體中文）
 *   給定 n，找出兩個 n 位數相乘可得到的最大回文整數。答案可能很大，
 *   請回傳它除以 1337 的餘數。
 *
 * 範例 1：n=2，99×91=9009 是最大回文乘積，9009 mod 1337=987，輸出 987。
 * 範例 2：n=1，最大回文乘積是 9，輸出 9。
 * 限制：1 <= n <= 8。
 *
 * 解題步驟：
 *   1. n=1 時直接回傳 9。
 *   2. n>=2 時，從最大的 n 位數開始向下列舉「回文左半部」，把它反向接到
 *      後面，組成 2n 位回文候選值。
 *   3. 由大到小檢查候選值是否能分解成兩個 n 位數：枚舉較大的因數，若整除
 *      且另一因數也在 n 位數範圍內，這就是最大答案。
 *   4. 使用 64 位元存放最多 16 位的候選乘積；找到答案後再取 1337 的餘數。
 *   搜尋時間取決於檢查的候選回文與因數範圍；額外空間 O(1)。n<=8 時可行。
 *
 * LeetCode C API：int largestPalindrome(int n)。
 */
#include <stdio.h>

#define PALINDROME_MODULUS 1337

/* ---------- LeetCode submission / 提交區 ---------- */
int largestPalindrome(int n) {
    if (n == 1) return 9;

    long long lower = 1;
    for (int i = 1; i < n; ++i) lower *= 10;
    long long upper = lower * 10 - 1;

    for (long long half = upper; half >= lower; --half) {
        long long palindrome = half;
        for (long long reversed = half; reversed > 0; reversed /= 10)
            palindrome = palindrome * 10 + reversed % 10;

        /* 因數從大到小試到平方根；第一組有效因數對即為最大回文。 */
        for (long long factor = upper; factor * factor >= palindrome; --factor) {
            if (palindrome % factor == 0) {
                long long other = palindrome / factor;
                if (other >= lower && other <= upper)
                    return (int)(palindrome % PALINDROME_MODULUS);
            }
        }
    }
    return 0; /* 題目範圍內必定會找到答案。 */
}
/* ---------- end submission ---------- */

int main(void) {
    int passed = largestPalindrome(1) == 9 &&
                 largestPalindrome(2) == 987 &&
                 largestPalindrome(3) == 123 &&
                 largestPalindrome(8) == 475;
    puts(passed ? "PASS: 479 largest-palindrome-product"
                : "FAIL: 479 largest-palindrome-product");
    return passed ? 0 : 1;
}

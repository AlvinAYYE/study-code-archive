/*
 * LeetCode 1837. Sum of Digits in Base K
 * Title-CN: K 進位數字總和
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/sum-of-digits-in-base-k/
 *
 * [中文] 題目說明
 *     給定十進位整數 n 和進位制 k，先把 n 轉成 k 進位，再把表示法中的
 *     每個數字視為一般整數相加，最後以十進位回傳總和。
 *
 * [中文] 範例
 *     1. n = 34、k = 6，34 的六進位是 54，5 + 4 = 9，輸出 9。
 *     2. n = 10、k = 10，數字為 1 和 0，總和為 1。
 *
 * [中文] 限制
 *     - 1 <= n <= 100。
 *     - 2 <= k <= 10。
 *
 * [中文] 解題步驟
 *     1. n 除以 k 的餘數就是最低位數字，將它加入總和。
 *     2. 將 n 整除 k，移除已處理的最低位，重複直到 n 變成 0。
 *     3. 回傳累加結果。時間 O(log_k n)，額外空間 O(1)。
 *
 * LeetCode C 函式簽名：int sumBase(int n, int k)
 */
#include <stdio.h>

int sumBase(int n, int k) {
    int sum = 0;
    while (n > 0) {
        sum += n % k;
        n /= k;
    }
    return sum;
}

int main(void) {
    int ok = sumBase(34, 6) == 9 && sumBase(10, 10) == 1 && sumBase(1, 2) == 1;
    printf("%s: 1837 sum-of-digits-in-base-k\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

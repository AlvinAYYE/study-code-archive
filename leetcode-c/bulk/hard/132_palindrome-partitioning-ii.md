# 0132. Palindrome Partitioning II《回文分割 II》

- **Difficulty**: Hard
- **Tags**: string, dynamic-programming
- **題目連結**: https://leetcode.com/problems/palindrome-partitioning-ii/
- **程式碼**: [`132_palindrome-partitioning-ii.c`](./132_palindrome-partitioning-ii.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

將字串 `s` 分割成多個子字串，使每個子字串都是回文。請回傳完成這種回文分割所需的最少切割次數。

## 解題思路

1. 定義 `dp[len]`：前 `len` 個字元分割成回文片段所需的最少切割次數。
2. 設 `dp[0] = -1`，讓整段前綴本身是回文時能自然得到 0 次切割；再以逐字切割初始化可行上界。
3. 依序把每個位置 `i` 當作回文中心，向外擴展奇數長度回文 `s[i-k..i+k]`，並用左側前綴答案更新右端前綴。
4. 再擴展中心位於 `i` 與 `i+1` 之間的偶數長度回文，使用相同方式更新。
5. 所有中心處理完後，`dp[n]` 即為完整字串的最少切割數。

最壞會從每個中心擴展 `O(n)`，時間複雜度為 `O(n^2)`，DP 陣列使用 `O(n)` 空間。

## Problem Statement (English)

Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例

```text
輸入：s = "aab"
輸出：1
說明：切成 ["aa","b"]，只需切一次且兩段都是回文。

輸入：s = "a"
輸出：0

輸入：s = "ab"
輸出：1
```

## 限制

- `1 <= s.length <= 2000`
- `s` 僅包含小寫英文字母。

## 官方 C 函式簽名 Signature

```c
int minCut(char* s) {
    
}
```

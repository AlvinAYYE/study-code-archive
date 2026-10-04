# 0646. Maximum Length of Pair Chain《最長數對鏈》

- **Difficulty**: Medium
- **Tags**: array, dynamic-programming, greedy, sorting
- **題目連結**: https://leetcode.com/problems/maximum-length-of-pair-chain/
- **程式碼**: [`646_maximum-length-of-pair-chain.c`](./646_maximum-length-of-pair-chain.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定多個數對 [left, right]，其中 left 小於 right；若前一對的右值小於下一對的左值，兩對便可相接。可任意選取與重排部分數對，求能形成的最長鏈長度。

**思路**：先以數對的左值排序，dp[i] 表示以第 i 個數對結尾的最長鏈。枚舉先前可銜接的數對並轉移，維護全域最大長度。

## Problem Statement (English)

You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.
A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.
Return the length longest chain which can be formed.
You do not need to use up all the given intervals. You can select pairs in any order.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: pairs = [[1,2],[2,3],[3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4].

Input: pairs = [[1,2],[7,8],[4,5]]
Output: 3
Explanation: The longest chain is [1,2] -> [4,5] -> [7,8].
```

## 限制 Constraints

n == pairs.length
1 <= n <= 1000
-1000 <= lefti < righti <= 1000

## 官方 C 函式簽名 Signature

```c
int findLongestChain(int** pairs, int pairsSize, int* pairsColSize) {
    
}
```

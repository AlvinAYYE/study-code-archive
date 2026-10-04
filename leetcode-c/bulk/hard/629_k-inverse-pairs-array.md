# 0629. K Inverse Pairs Array《K 個逆序對陣列》

- **Difficulty**: Hard
- **Tags**: dynamic-programming
- **題目連結**: https://leetcode.com/problems/k-inverse-pairs-array/
- **程式碼**: [`629_k-inverse-pairs-array.c`](./629_k-inverse-pairs-array.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

逆序對是滿足 i < j 且 nums[i] > nums[j] 的索引對。給定 n 與 k，計算由 1 到 n 各使用一次所形成、恰有 k 個逆序對的不同陣列數量。答案可能很大，需對 10^9 + 7 取模。

**思路**：使用動態規劃，dp[i][m] 表示由 1 到 i 組成且有 m 個逆序對的數量。加入數字 i 時枚舉其插入位置所新增的 0 到 i-1 個逆序對，累加前一列對應值。

## Problem Statement (English)

For an integer array nums, an inverse pair is a pair of integers [i, j] where 0  nums[j].
Given two integers n and k, return the number of different arrays consisting of numbers from 1 to n such that there are exactly k inverse pairs. Since the answer can be huge, return it modulo 109 + 7.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: n = 3, k = 0
Output: 1
Explanation: Only the array [1,2,3] which consists of numbers from 1 to 3 has exactly 0 inverse pairs.

Input: n = 3, k = 1
Output: 2
Explanation: The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.
```

## 限制 Constraints

1 <= n <= 1000
0 <= k <= 1000

## 官方 C 函式簽名 Signature

```c
int kInversePairs(int n, int k) {
    
}
```

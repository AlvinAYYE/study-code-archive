# 0060. Permutation Sequence《第 k 個排列》

- **Difficulty**: Hard
- **Tags**: math, recursion
- **題目連結**: https://leetcode.com/problems/permutation-sequence/
- **程式碼**: [`060_permutation-sequence.c`](./060_permutation-sequence.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

集合 [1, 2, 3, ..., n] 共有 n! 個不同排列，並依序編號。給定 n 與 k，回傳第 k 個排列所組成的字串。

**思路**：先將 k 轉為從零開始的索引，利用每一位固定後的階乘區塊大小選出對應數字。選取後從可用字元中移除該數字，最後兩位再依剩餘索引決定順序。

## Problem Statement (English)

The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
Given n and k, return the kth permutation sequence.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: n = 3, k = 3
Output: "213"

Input: n = 4, k = 9
Output: "2314"

Input: n = 3, k = 1
Output: "123"
```

## 限制 Constraints

1 <= n <= 9
1 <= k <= n!

## 官方 C 函式簽名 Signature

```c
char* getPermutation(int n, int k) {
    
}
```

# 0077. Combinations《組合》

- **Difficulty**: Medium
- **Tags**: backtracking
- **題目連結**: https://leetcode.com/problems/combinations/
- **程式碼**: [`077_combinations.c`](./077_combinations.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數 n 與 k，回傳從範圍 [1, n] 中選出 k 個數的所有組合。組合內元素順序不影響結果，答案可任意排列。保證 1 ≤ k ≤ n ≤ 20。

**思路**：以遞迴回溯逐一決定是否選取目前數字，選滿 k 個時複製到答案。剩餘數量不足以湊滿 k 時會提前剪枝。

## Problem Statement (English)

Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
You may return the answer in any order.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.

Input: n = 1, k = 1
Output: [[1]]
Explanation: There is 1 choose 1 = 1 total combination.
```

## 限制 Constraints

1 <= n <= 20
1 <= k <= n

## 官方 C 函式簽名 Signature

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {
    
}
```

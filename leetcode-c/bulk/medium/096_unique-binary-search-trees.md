# 0096. Unique Binary Search Trees《不同的二元搜尋樹》

- **Difficulty**: Medium
- **Tags**: math, dynamic-programming, tree, binary-search-tree, binary-tree
- **題目連結**: https://leetcode.com/problems/unique-binary-search-trees/
- **程式碼**: [`096_unique-binary-search-trees.c`](./096_unique-binary-search-trees.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數 n，求恰好使用 1 到 n 這 n 個互異值時，結構不同的二元搜尋樹數量。保證 1 ≤ n ≤ 19。

**思路**：以 DP 計算節點數為 i 的樹數量，依序枚舉每個值當根。根左、右的節點數固定後，方案數為兩側方案數的乘積並累加。

## Problem Statement (English)

Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: n = 3
Output: 5

Input: n = 1
Output: 1
```

## 限制 Constraints

1 <= n <= 19

## 官方 C 函式簽名 Signature

```c
int numTrees(int n) {
    
}
```

# 0040. Combination Sum II《組合總和 II》

- **Difficulty**: Medium
- **Tags**: array, backtracking
- **題目連結**: https://leetcode.com/problems/combination-sum-ii/
- **程式碼**: [`040_combination-sum-ii.c`](./040_combination-sum-ii.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定可能含重複值的 candidates 與 target，找出所有元素總和等於 target 的不重複組合。每個陣列元素在同一組合中至多使用一次，結果不得含重複組合。

**思路**：程式先排序，再由尾端回溯挑選更前面的元素，因而每個位置只會使用一次；同一層以已找到的索引略過相同數值來去重。

## Problem Statement (English)

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
```

## 限制 Constraints

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30

## 官方 C 函式簽名 Signature

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    
}
```

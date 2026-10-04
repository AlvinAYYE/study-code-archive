# 0039. Combination Sum《組合總和》

- **Difficulty**: Medium
- **Tags**: array, backtracking
- **題目連結**: https://leetcode.com/problems/combination-sum/
- **程式碼**: [`039_combination-sum.c`](./039_combination-sum.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定互異正整數 candidates 與 target，找出所有元素總和恰為 target 的不重複組合，輸出順序不限。每個候選數可重複選用，且測資保證符合條件的組合數少於 150 個。

**思路**：先排序候選數，再以回溯法從目前索引開始選數；遞迴時保留相同索引以允許重複使用，總和達標便記錄組合。

## Problem Statement (English)

Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

Input: candidates = [2], target = 1
Output: []
```

## 限制 Constraints

1 <= candidates.length <= 30
2 <= candidates[i] <= 40
All elements of candidates are distinct.
1 <= target <= 40

## 官方 C 函式簽名 Signature

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    
}
```

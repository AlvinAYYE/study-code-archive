# 0435. Non-overlapping Intervals《無重疊區間》

- **Difficulty**: Medium
- **Tags**: array, dynamic-programming, greedy, sorting
- **題目連結**: https://leetcode.com/problems/non-overlapping-intervals/
- **程式碼**: [`435_non-overlapping-intervals.c`](./435_non-overlapping-intervals.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定區間陣列 intervals，回傳至少要移除多少個區間，才能使剩餘區間互不重疊。僅在端點相接的區間不視為重疊，例如 [1,2] 與 [2,3] 可同時保留。

**思路**：先依起點、再依終點排序區間，維持目前保留區間的索引。遇到重疊時移除其中終點較晚的區間；不重疊則將目前區間更新為新保留區間。

## Problem Statement (English)

Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.

Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
```

## 限制 Constraints

1 <= intervals.length <= 105
intervals[i].length == 2
-5 * 104 <= starti < endi <= 5 * 104

## 官方 C 函式簽名 Signature

```c
int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    
}
```

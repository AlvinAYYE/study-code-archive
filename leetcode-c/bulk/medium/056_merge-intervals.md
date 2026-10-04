# 0056. Merge Intervals《合併區間》

- **Difficulty**: Medium
- **Tags**: array, sorting
- **題目連結**: https://leetcode.com/problems/merge-intervals/
- **程式碼**: [`056_merge-intervals.c`](./056_merge-intervals.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定一組區間 intervals，其中每個區間為 [start, end]，請合併所有重疊區間。回傳能覆蓋所有輸入區間且彼此不重疊的區間集合。

**思路**：先依區間起點排序，再依序比較目前區間與前一個合併區間。若有重疊便擴大終點，否則輸出前一段並開始新的區間。

## Problem Statement (English)

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
```

## 限制 Constraints

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104

## 官方 C 函式簽名 Signature

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    
}
```

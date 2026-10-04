# 0057. Insert Interval《插入區間》

- **Difficulty**: Medium
- **Tags**: array
- **題目連結**: https://leetcode.com/problems/insert-interval/
- **程式碼**: [`057_insert-interval.c`](./057_insert-interval.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定已依起點排序且互不重疊的區間陣列 intervals，以及一個 newInterval，插入後仍須保持排序與不重疊。若 newInterval 與既有區間重疊，必須合併後回傳結果；不要求原地修改。

**思路**：先複製完全位於新區間左側的區間，再找出所有重疊區間並更新新區間的兩端。加入合併後的新區間，最後接上右側其餘區間。

## Problem Statement (English)

You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
Return intervals after the insertion.
Note that you don't need to modify intervals in-place. You can make a new array and return it.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
```

## 限制 Constraints

0 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 105
intervals is sorted by starti in ascending order.
newInterval.length == 2
0 <= start <= end <= 105

## 官方 C 函式簽名 Signature

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes) {
    
}
```

# 0056. Merge Intervals｜合併區間

- **難度**：中等
- **標籤**：陣列、排序
- **題目連結**：[LeetCode 0056](https://leetcode.com/problems/merge-intervals/)
- **C 程式**：[056_merge-intervals.c](./056_merge-intervals.c)

## 題目說明

給定多個區間 `intervals[i] = [start, end]`，合併所有重疊區間，回傳彼此不重疊且能涵蓋原區間的結果。兩區間端點相接也算重疊，例如 `[1,4]` 和 `[4,5]` 要合併。

## 範例

```text
輸入：intervals = [[1,3],[2,6],[8,10],[15,18]]
輸出：[[1,6],[8,10],[15,18]]

輸入：intervals = [[1,4],[4,5]]
輸出：[[1,5]]
```

## 限制

- `1 <= intervals.length <= 10^4`。
- `intervals[i].length == 2`。
- `0 <= starti <= endi <= 10^4`。

## 解題步驟

1. 依區間起點由小到大排序。
2. `current` 指向目前合併中的區間。若下一區間的起點小於或等於 `current` 的終點，兩者重疊，把終點更新成兩者較大的終點。
3. 若下一區間起點大於目前終點，先將 `current` 複製到答案，再以新區間開始下一組合併。
4. 掃描結束後，記得把最後一個 `current` 加入答案。

## 複雜度

- 時間：`O(n log n)`，排序主導；合併掃描為 `O(n)`。
- 額外空間：`O(n)`，排序用的指標陣列與回傳區間。

## LeetCode C 函式簽名

```c
int** merge(int** intervals, int intervalsSize, int* intervalsColSize,
            int* returnSize, int** returnColumnSizes);
```

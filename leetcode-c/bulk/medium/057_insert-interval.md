# 0057. Insert Interval｜插入區間

- **難度**：中等
- **標籤**：陣列
- **題目連結**：[LeetCode 0057](https://leetcode.com/problems/insert-interval/)
- **C 程式**：[057_insert-interval.c](./057_insert-interval.c)

## 題目說明

給定依起點排序、彼此不重疊的區間陣列，以及一個 `newInterval`。將新區間插入後，合併所有與它重疊的區間，回傳仍按起點排序且彼此不重疊的結果。可以另外建立答案，不必原地修改輸入。

## 範例

```text
輸入：intervals = [[1,3],[6,9]], newInterval = [2,5]
輸出：[[1,5],[6,9]]

輸入：intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
輸出：[[1,2],[3,10],[12,16]]
說明：[4,8] 與 [3,5]、[6,7]、[8,10] 重疊，合併後為 [3,10]。
```

## 限制

- `0 <= intervals.length <= 10^4`。
- `intervals[i].length == 2`，區間依起點遞增且互不重疊。
- `0 <= starti <= endi <= 10^5`。
- `newInterval.length == 2`，`0 <= start <= end <= 10^5`。

## 解題步驟

1. 將所有終點早於新區間起點的區間直接複製到答案。
2. 逐一吸收起點不晚於新區間終點的區間，更新新區間起點為兩者較小值、終點為較大值。
3. 將合併完成的新區間加入答案。
4. 把剩餘區間直接複製到答案；它們都位於新區間右側。

## 複雜度

- 時間：`O(n)`，每個輸入區間只檢查一次。
- 額外空間：`O(n)`，回傳最多 `n + 1` 個區間。

## LeetCode C 函式簽名

```c
int** insert(int** intervals, int intervalsSize, int* intervalsColSize,
             int* newInterval, int newIntervalSize, int* returnSize,
             int** returnColumnSizes);
```

# 0040. Combination Sum II｜組合總和 II

- **難度**：中等
- **標籤**：陣列、回溯
- **題目連結**：[LeetCode 0040](https://leetcode.com/problems/combination-sum-ii/)
- **C 程式**：[040_combination-sum-ii.c](./040_combination-sum-ii.c)

## 題目說明

給定可能含有重複值的正整數陣列 `candidates` 和 `target`，找出所有總和等於目標的不同組合。每個陣列元素最多只能使用一次；答案不可有內容相同的組合。

## 範例

```text
輸入：candidates = [10,1,2,7,6,1,5], target = 8
輸出：[[1,1,6],[1,2,5],[1,7],[2,6]]

輸入：candidates = [2,5,2,1,2], target = 5
輸出：[[1,2,2],[5]]
```

## 限制

- `1 <= candidates.length <= 100`。
- `1 <= candidates[i] <= 50`。
- `1 <= target <= 30`。

## 解題步驟

1. 將候選數排序，讓重複值相鄰，也方便提早停止。
2. 回溯時用 `start` 限定可選範圍；選了索引 `i` 後，下一層從 `i + 1` 開始，因此同一個元素不會重複使用。
3. 在同一層遞迴中，若 `candidates[i]` 和前一個值相同就略過，避免從相同值開出重複組合。
4. `remaining == 0` 時將目前 `path` 加入答案；候選值大於 `remaining` 時，後面的值也更大，可以結束這層迴圈。

## 複雜度

- 時間：最壞情況為指數時間，需探索不同候選組合。
- 額外空間：`O(n)` 儲存遞迴路徑，不含回傳答案。

## LeetCode C 函式簽名

```c
int** combinationSum2(int* candidates, int candidatesSize, int target,
                      int* returnSize, int** returnColumnSizes);
```

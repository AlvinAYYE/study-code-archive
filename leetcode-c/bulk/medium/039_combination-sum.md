# 0039. Combination Sum｜組合總和

- **難度**：中等
- **標籤**：陣列、回溯
- **題目連結**：[LeetCode 0039](https://leetcode.com/problems/combination-sum/)
- **C 程式**：[039_combination-sum.c](./039_combination-sum.c)

## 題目說明

給定互不相同的正整數陣列 `candidates` 和目標值 `target`，找出所有總和等於 `target` 的組合。每個候選數可以重複使用；不同組合的順序不重要，例如 `[2,3,2]` 和 `[2,2,3]` 算同一種組合。

## 範例

```text
輸入：candidates = [2,3,6,7], target = 7
輸出：[[2,2,3],[7]]
說明：2 + 2 + 3 = 7；也可以直接選 7。

輸入：candidates = [2,3,5], target = 8
輸出：[[2,2,2,2],[2,3,3],[3,5]]

輸入：candidates = [2], target = 1
輸出：[]
```

## 限制

- `1 <= candidates.length <= 30`。
- `2 <= candidates[i] <= 40`，且候選值互不相同。
- `1 <= target <= 40`。
- 每筆測資的答案組數少於 150。

## 解題步驟

1. 先排序候選數，讓較大的數超過剩餘目標時可停止搜尋。
2. 回溯函式帶著 `start`、`remaining` 和 `path`：`path` 是目前選到的數，`remaining` 是還差多少。
3. 選到候選值 `candidates[i]` 後，遞迴仍從 `i` 開始，因為同一個數允許重複選。
4. `remaining == 0` 時，把 `path` 複製成一組答案；若候選值大於剩餘目標，就跳過後續更大的數。

## 複雜度

- 時間：與所有可探索的組合數及答案長度成正比；最壞情況為指數時間。
- 額外空間：`O(target / minCandidate)` 的遞迴路徑，不含回傳答案。

## LeetCode C 函式簽名

```c
int** combinationSum(int* candidates, int candidatesSize, int target,
                     int* returnSize, int** returnColumnSizes);
```

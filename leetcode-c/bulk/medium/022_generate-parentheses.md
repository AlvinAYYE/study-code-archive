# 0022. Generate Parentheses｜括號生成

- **難度**：中等
- **標籤**：字串、動態規劃、回溯
- **題目連結**：[LeetCode 0022](https://leetcode.com/problems/generate-parentheses/)
- **C 程式**：[022_generate-parentheses.c](./022_generate-parentheses.c)

## 題目說明

給定 `n` 對括號，產生所有格式正確的括號字串。格式正確代表每個左括號都能配對到後面的右括號，而且從左往右看時，右括號數量永遠不會多於左括號。

## 範例

```text
輸入：n = 3
輸出：["((()))","(()())","(())()","()(())","()()()"]
說明：共 5 種合法排法，每種都恰有 3 對括號。

輸入：n = 1
輸出：["()"]
```

## 限制

- `1 <= n <= 8`。

## 解題步驟

1. `openCount`、`closeCount` 分別記錄已放入的左、右括號數；`buffer` 暫存目前組合。
2. 若 `openCount < n`，可以再放一個 `(`，再遞迴嘗試後續位置。
3. 只有當 `closeCount < openCount`，才可以放 `)`；這能保證右括號不會先於可配對的左括號。
4. 當字串長度到 `2n`，目前組合就是一個完整答案，複製到答案陣列。

例如 `n = 3` 時，先沿著「可以放左括號」的分支往下；每次有未配對的左括號，才開出放右括號的分支。走到底的每條合法路徑就是一個輸出字串。

## 複雜度

令 `C_n` 為答案數量（第 `n` 個 Catalan 數）：

- 時間：`O(C_n × n)`，每個答案長度為 `2n`。
- 額外空間：遞迴深度 `O(n)`；答案占 `O(C_n × n)`。

## LeetCode C 函式簽名

```c
char** generateParenthesis(int n, int* returnSize);
```

回傳字串陣列，`returnSize` 是答案數量。

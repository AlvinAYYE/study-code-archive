# 0072. Edit Distance｜編輯距離

- **難度**：中等
- **標籤**：字串、動態規劃
- **題目連結**：[LeetCode 0072](https://leetcode.com/problems/edit-distance/)
- **C 程式**：[072_edit-distance.c](./072_edit-distance.c)

## 題目說明

給定兩個小寫英文字串 `word1` 和 `word2`，回傳把 `word1` 變成 `word2` 所需的最少操作次數。每次可以選一種操作：插入一個字元、刪除一個字元，或把一個字元替換成另一個字元。

## 範例

```text
輸入：word1 = "horse", word2 = "ros"
輸出：3
說明：horse → rorse（替換 h）、rorse → rose（刪除 r）、rose → ros（刪除 e）。

輸入：word1 = "intention", word2 = "execution"
輸出：5
```

## 限制

- `0 <= word1.length, word2.length <= 500`。
- 兩個字串只包含小寫英文字母。

## 解題步驟

1. `dp[j]` 表示已處理完 `word1` 目前前綴後，轉成 `word2` 前 `j` 個字元所需的最少操作數。
2. 空字串轉成長度 `j` 的字串需要插入 `j` 次，所以先令 `dp[j] = j`。
3. 每處理 `word1[i]`，空字串轉成目前長度 `i` 的前綴需要刪除 `i` 次，因此令 `dp[0] = i`。
4. 逐欄更新時，保存舊的 `dp[j]`（上方）和左上角舊值。字元相同就沿用左上角；不同則在「替換、刪除、插入」三種代價中取最小值再加一。
5. 最後一欄就是兩個完整字串之間的編輯距離。程式把較短字串放在欄方向，讓 DP 陣列更小。

## 複雜度

- 時間：`O(m × n)`，`m`、`n` 是兩個字串的長度。
- 額外空間：`O(min(m, n))`，只保留較短字串長度的一列。

## LeetCode C 函式簽名

```c
int minDistance(char* word1, char* word2);
```

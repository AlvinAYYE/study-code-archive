# 0097. Interleaving String｜交錯字串

- **難度**：中等
- **標籤**：字串、動態規劃
- **題目連結**：[LeetCode 0097](https://leetcode.com/problems/interleaving-string/)
- **C 程式**：[097_interleaving-string.c](./097_interleaving-string.c)

## 題目說明

給定字串 `s1`、`s2` 和 `s3`，判斷 `s3` 是否能由 `s1`、`s2` 交錯組成。交錯時要保留每個原字串中字元的先後順序；可以分成多段，但不能打亂字元。若 `s3` 長度不等於 `s1` 和 `s2` 長度總和，一定無法組成。

## 範例

```text
輸入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
輸出：true

輸入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
輸出：false

輸入：s1 = "", s2 = "", s3 = ""
輸出：true
```

## 限制

- `0 <= s1.length, s2.length <= 100`。
- `0 <= s3.length <= 200`。
- 三個字串只包含小寫英文字母。

## 解題步驟

1. `dp[j]` 表示已使用目前處理的 `s1` 前綴和 `s2` 前 `j` 個字元，是否能組成 `s3` 對應長度的前綴。
2. 若長度總和不相等，直接回傳 `false`。接著先用 `s2` 初始化 `s1` 尚未取字元時的狀態。
3. 每處理 `s1[i-1]`，更新 `dp[0]`，再從左到右更新各欄。
4. 新狀態可以由上方而來（下一個 `s3` 字元取自 `s1`），或由左方而來（取自 `s2`）；字元也必須與 `s3` 對應位置相同。
5. 逐列更新後，最後一格表示兩個完整來源字串是否能交錯成 `s3`。

## 複雜度

- 時間：`O(|s1| × |s2|)`。
- 額外空間：`O(min(|s1|, |s2|))`；實作將較短字串放在 DP 欄方向。

## LeetCode C 函式簽名

```c
bool isInterleave(char* s1, char* s2, char* s3);
```

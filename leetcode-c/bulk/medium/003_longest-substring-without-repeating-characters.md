# 0003. Longest Substring Without Repeating Characters｜無重複字元的最長子字串

- **難度**：中等
- **標籤**：雜湊表、字串、滑動視窗
- **題目連結**：[LeetCode 0003](https://leetcode.com/problems/longest-substring-without-repeating-characters/)
- **C 程式**：[003_longest-substring-without-repeating-characters.c](./003_longest-substring-without-repeating-characters.c)

## 題目說明

給定字串 `s`，找出其中**沒有任何重複字元**的最長連續片段，回傳該片段的長度。子字串必須連續，不能跳過中間字元。

## 範例

```text
輸入：s = "abcabcbb"
輸出：3
說明："abc" 沒有重複字元，長度是 3。

輸入：s = "bbbbb"
輸出：1
說明：最長片段是單一字元 "b"。

輸入：s = "pwwkew"
輸出：3
說明："wke" 是連續片段；"pwke" 雖然不重複，但不是子字串。
```

## 限制

- `0 <= s.length <= 5 * 10^4`。
- `s` 由英文字母、數字、符號與空白組成。

## 解題步驟

1. 用 `start` 表示目前有效視窗的左端，索引 `i` 當作右端。
2. `last[字元]` 記錄該字元最近一次出現的位置；初始化為 `-1`，表示尚未出現。
3. 若目前字元上次出現的位置仍在視窗內，就把 `start` 移到那個位置的下一格。左界只往右，不會倒退。
4. 更新字元的最後位置，再以 `i - start + 1` 更新最長長度。

例如讀到第二個 `a` 時，視窗左界會越過第一個 `a`，因此新視窗中不會有重複字元。

## 複雜度

- 時間：`O(n)`，每個字元只處理一次。
- 額外空間：`O(1)`，256 格表格涵蓋所有單位元組字元。

## LeetCode C 函式簽名

```c
int lengthOfLongestSubstring(char* s);
```

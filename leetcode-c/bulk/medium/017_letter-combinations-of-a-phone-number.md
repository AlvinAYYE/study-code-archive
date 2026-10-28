# 0017. Letter Combinations of a Phone Number｜電話號碼的字母組合

- **難度**：中等
- **標籤**：雜湊表、字串、回溯
- **題目連結**：[LeetCode 0017](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)
- **C 程式**：[017_letter-combinations-of-a-phone-number.c](./017_letter-combinations-of-a-phone-number.c)

## 題目說明

給定只含數字 `2` 到 `9` 的字串 `digits`，依照電話按鍵的字母對應，列出所有可能的字母組合，順序不限。空字串沒有組合，回傳空集合。

按鍵對應：`2 → abc`、`3 → def`、`4 → ghi`、`5 → jkl`、`6 → mno`、`7 → pqrs`、`8 → tuv`、`9 → wxyz`。

## 範例

```text
輸入：digits = "23"
輸出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
說明：第一個位置選 a/b/c，第二個位置選 d/e/f，兩組選擇交叉組合。

輸入：digits = ""
輸出：[]

輸入：digits = "2"
輸出：["a","b","c"]
```

## 限制

- `0 <= digits.length <= 4`。
- `digits[i]` 是 `'2'` 到 `'9'` 之間的數字。

## 解題步驟

1. `PHONE_LETTERS` 對照表保存每個數字的字母。
2. `position` 指向目前要處理的數字，`buffer[position]` 暫存這一層選到的字母。
3. 依序嘗試該按鍵的每個字母，遞迴填下一個位置；遞迴返回後就改試另一個字母。
4. 所有位置都填完時，把 `buffer` 複製成一個答案。

例如 `"23"` 先固定 `a`，依序接上 `d/e/f` 得到三個答案，再退回改選 `b`、`c`。

## 複雜度

若有 `M` 組答案、輸入長度為 `n`：

- 時間：`O(M × n)`，需複製每個完整答案。
- 額外空間：遞迴深度 `O(n)`；答案占 `O(M × n)`。

## LeetCode C 函式簽名

```c
char** letterCombinations(char* digits, int* returnSize);
```

回傳字串陣列，`returnSize` 是答案數量。

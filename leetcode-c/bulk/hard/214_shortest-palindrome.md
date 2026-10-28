# 0214. 最短回文串（Shortest Palindrome）

- **難度**：Hard
- **標籤**：字串、KMP、字串比對
- **題目連結**：[LeetCode 214](https://leetcode.com/problems/shortest-palindrome/)
- **解答檔案**：[214_shortest-palindrome.c](./214_shortest-palindrome.c)

## 題目完整翻譯

給定字串 `s`。你只能在 `s` 的前面加入字元，將它變成回文。請回傳能完成這件事的最短回文串。

## 範例

```text
輸入：s = "aacecaaa"
輸出："aaacecaaa"

輸入：s = "abcd"
輸出："dcbabcd"
```

## 限制

- `0 <= s.length <= 5 × 10^4`
- `s` 只包含小寫英文字母。

## 解題思路

1. 找出 `s` 開頭最長的回文前綴。這段前綴已經左右對稱，不必額外補字元。
2. 用 KMP 前綴表處理 `s + 分隔符 + reverse(s)`。最後一格的前綴長度，就是最長回文前綴的長度。
3. 把 `s` 中未被該回文前綴涵蓋的尾端反轉，接到 `s` 前面。

例如 `abcd` 的最長回文前綴只有 `a`；未涵蓋尾端 `bcd` 反轉成 `dcb`，加到前面後得到 `dcbabcd`。

## 複雜度

- 時間：`O(n)`。
- 額外空間：`O(n)`。

## C 函式介面

```c
char* shortestPalindrome(char* s);
```

回傳字串由解答配置，呼叫端需負責釋放。

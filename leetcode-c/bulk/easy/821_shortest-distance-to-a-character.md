# 0821. Shortest Distance to a Character《字元的最短距離》

- **Difficulty**: Easy
- **Tags**: array, two-pointers, string
- **題目連結**: https://leetcode.com/problems/shortest-distance-to-a-character/
- **程式碼**: [`821_shortest-distance-to-a-character.c`](./821_shortest-distance-to-a-character.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定字串 s 與保證至少出現一次的字元 c，回傳與 s 等長的陣列。答案第 i 項為索引 i 到任一最近 c 出現位置的絕對距離；s 長度最多為 10^4。

**思路**：由左至右將尚未配對下一個 c 的位置壓入堆疊；遇到 c 時反向彈出並以左右距離較小值更新，尾端剩餘位置則保留距離左側 c 的值。

## Problem Statement (English)

Given a string s and a character c that occurs in s, return an array of integers answer where answer.length == s.length and answer[i] is the distance from index i to the closest occurrence of character c in s.
The distance between two indices i and j is abs(i - j), where abs is the absolute value function.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: s = "loveleetcode", c = "e"
Output: [3,2,1,0,1,0,0,1,2,2,1,0]
Explanation: The character 'e' appears at indices 3, 5, 6, and 11 (0-indexed).
The closest occurrence of 'e' for index 0 is at index 3, so the distance is abs(0 - 3) = 3.
The closest occurrence of 'e' for index 1 is at index 3, so the distance is abs(1 - 3) = 2.
For index 4, there is a tie between the 'e' at index 3 and the 'e' at index 5, but the distance is still the same: abs(4 - 3) == abs(4 - 5) = 1.
The closest occurrence of 'e' for index 8 is at index 6, so the distance is abs(8 - 6) = 2.

Input: s = "aaab", c = "b"
Output: [3,2,1,0]
```

## 限制 Constraints

1 <= s.length <= 104
s[i] and c are lowercase English letters.
It is guaranteed that c occurs at least once in s.

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shortestToChar(char* s, char c, int* returnSize) {
    
}
```

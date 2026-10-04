# 0830. Positions of Large Groups《較大群組的位置》

- **Difficulty**: Easy
- **Tags**: string
- **題目連結**: https://leetcode.com/problems/positions-of-large-groups/
- **程式碼**: [`830_positions-of-large-groups.c`](./830_positions-of-large-groups.c) — 本專案自行撰寫並通過官方示例驗證

## 題目說明（中文）

小寫字串 s 中相同且連續的字元形成群組，群組以包含兩端的 [start, end] 表示。找出所有長度至少為 3 的群組區間，並依起始索引遞增回傳；s 長度最多為 1000。

**思路**：雙指針掃描每個相同字元的連續區段，若區段長度至少為 3，就記錄其起訖索引。

## Problem Statement (English)

In a string s of lowercase letters, these letters form consecutive groups of the same character.
For example, a string like s = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z", and "yy".
A group is identified by an interval [start, end], where start and end denote the start and end indices (inclusive) of the group. In the above example, "xxxx" has the interval [3,6].
A group is considered large if it has 3 or more characters.
Return the intervals of every large group sorted in increasing order by start index.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: s = "abbxxxxzzy"
Output: [[3,6]]
Explanation: "xxxx" is the only large group with start index 3 and end index 6.

Input: s = "abc"
Output: []
Explanation: We have groups "a", "b", and "c", none of which are large groups.

Input: s = "abcdddeeeeaabbbcd"
Output: [[3,5],[6,9],[12,14]]
Explanation: The large groups are "ddd", "eeee", and "bbb".
```

## 限制 Constraints

1 <= s.length <= 1000
s contains lowercase English letters only.

## 官方 C 函式簽名 Signature

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** largeGroupPositions(char* s, int* returnSize, int** returnColumnSizes) {
    
}
```

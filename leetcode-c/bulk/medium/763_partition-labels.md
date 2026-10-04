# 0763. Partition Labels《劃分字母區間》

- **Difficulty**: Medium
- **Tags**: hash-table, two-pointers, string, greedy
- **題目連結**: https://leetcode.com/problems/partition-labels/
- **程式碼**: [`763_partition-labels.c`](./763_partition-labels.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

將字串 s 劃分為盡可能多的片段，且每個字母至多出現在一個片段中；各片段依序串接後必須仍為原字串。回傳每個片段的長度。

**思路**：記錄每個字母的首次與最後出現位置，按首次位置排序後合併重疊的區間。每當下一個區間不再重疊時，就輸出目前合併區間的長度。

## Problem Statement (English)

You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part. For example, the string "ababcc" can be partitioned into ["abab", "cc"], but partitions such as ["aba", "bcc"] or ["ab", "ab", "cc"] are invalid.
Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.
Return a list of integers representing the size of these parts.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.

Input: s = "eccbbbbdec"
Output: [10]
```

## 限制 Constraints

1 <= s.length <= 500
s consists of lowercase English letters.

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* partitionLabels(char* s, int* returnSize) {
    
}
```

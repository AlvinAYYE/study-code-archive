# 0937. Reorder Data in Log Files《重新排列日誌檔案》

- **Difficulty**: Medium
- **Tags**: array, string, sorting
- **題目連結**: https://leetcode.com/problems/reorder-data-in-log-files/
- **程式碼**: [`937_reorder-data-in-log-files.c`](./937_reorder-data-in-log-files.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定日誌陣列，每筆日誌以識別字開頭，後面接以空格分隔的內容；內容全為字母者是字母日誌，內容全為數字者是數字日誌。重新排序時，所有字母日誌須在數字日誌之前，字母日誌依內容字典序排序、內容相同時依識別字排序，而數字日誌維持原相對順序。回傳排序後的日誌陣列。

**思路**：程式先依識別字後第一個字元把數字日誌與字母日誌分開，保存字母日誌內容和原索引後排序，最後將排序後字母日誌接在原順序的數字日誌之前。

## Problem Statement (English)

You are given an array of logs. Each log is a space-delimited string of words, where the first word is the identifier.
There are two types of logs:
Reorder these logs so that:
Return the final order of the logs.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]
Explanation:
The letter-log contents are all different, so their ordering is "art can", "art zero", "own kit dig".
The digit-logs have a relative order of "dig1 8 1 5 1", "dig2 3 6".

Input: logs = ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
Output: ["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]
```

## 限制 Constraints

1 <= logs.length <= 100
3 <= logs[i].length <= 100
All the tokens of logs[i] are separated by a single space.
logs[i] is guaranteed to have an identifier and at least one word after the identifier.

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** reorderLogFiles(char** logs, int logsSize, int* returnSize) {
    
}
```

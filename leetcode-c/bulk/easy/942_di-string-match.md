# 0942. DI String Match《DI 字串匹配》

- **Difficulty**: Easy
- **Tags**: array, two-pointers, string, greedy
- **題目連結**: https://leetcode.com/problems/di-string-match/
- **程式碼**: [`942_di-string-match.c`](./942_di-string-match.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

長度為 n 的字串 s 描述 0 到 n 的一個排列 perm：s[i] 為 I 時 perm[i] < perm[i+1]，為 D 時 perm[i] > perm[i+1]。請重建並回傳任一符合 s 的排列。

**思路**：維護尚可使用的最小值與最大值；遇到 I 放入最小值、遇到 D 放入最大值，最後把唯一剩下的值填入末端。

## Problem Statement (English)

A permutation perm of n + 1 integers of all the integers in the range [0, n] can be represented as a string s of length n where:
Given a string s, reconstruct the permutation perm and return it. If there are multiple valid permutations perm, return any of them.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: s = "IDID"
Output: [0,4,1,3,2]

Input: s = "III"
Output: [0,1,2,3]

Input: s = "DDI"
Output: [3,2,0,1]
```

## 限制 Constraints

1 <= s.length <= 105
s[i] is either 'I' or 'D'.

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* diStringMatch(char* s, int* returnSize) {
    
}
```

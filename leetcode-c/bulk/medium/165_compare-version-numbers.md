# 0165. Compare Version Numbers《比較版本號》

- **Difficulty**: Medium
- **Tags**: two-pointers, string
- **題目連結**: https://leetcode.com/problems/compare-version-numbers/
- **程式碼**: [`165_compare-version-numbers.c`](./165_compare-version-numbers.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定兩個以句點分隔修訂號的版本字串，需從左到右比較各段修訂號的整數值，並忽略前導零。若其中一個版本較短，缺少的修訂號視為 0。請依第一個版本較大、較小或相等，分別回傳 1、-1 或 0。

**思路**：逐段以句點切開兩個字串並轉為整數比較；任一字串已結束時，對應修訂號改視為 0。

## Problem Statement (English)

Given two version strings, version1 and version2, compare them. A version string consists of revisions separated by dots '.'. The value of the revision is its integer conversion ignoring leading zeros.
To compare version strings, compare their revision values in left-to-right order. If one of the version strings has fewer revisions, treat the missing revision values as 0.
Return the following:
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: version1 = "1.2", version2 = "1.10"
Output: -1
Explanation:
version1's second revision is "2" and version2's second revision is "10": 2 < 10, so version1 < version2.

Input: version1 = "1.01", version2 = "1.001"
Output: 0
Explanation:
Ignoring leading zeroes, both "01" and "001" represent the same integer "1".

Input: version1 = "1.0", version2 = "1.0.0.0"
Output: 0
Explanation:
version1 has less revisions, which means every missing revision are treated as "0".
```

## 限制 Constraints

1 <= version1.length, version2.length <= 500
version1 and version2 only contain digits and '.'.
version1 and version2 are valid version numbers.
All the given revisions in version1 and version2 can be stored in a 32-bit integer.

## 官方 C 函式簽名 Signature

```c
int compareVersion(char* version1, char* version2) {
    
}
```

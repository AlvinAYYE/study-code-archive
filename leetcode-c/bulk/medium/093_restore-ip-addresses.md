# 0093. Restore IP Addresses《復原 IP 位址》

- **Difficulty**: Medium
- **Tags**: string, backtracking
- **題目連結**: https://leetcode.com/problems/restore-ip-addresses/
- **程式碼**: [`093_restore-ip-addresses.c`](./093_restore-ip-addresses.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

有效 IP 位址由四個以單一點號分隔的整數組成，每段都必須介於 0 到 255，且不得有前導零。給定僅含數字的字串，插入點號後回傳所有可能的有效 IP 位址。不可重新排列或刪除任何數字，答案順序不限。

**思路**：回溯選擇每段 1 到 3 個字元，檢查是否無前導零且數值不超過 255。選滿四段且剛好用完整個字串時，將各段以點號組成答案。

## Problem Statement (English)

A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.
Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]

Input: s = "0000"
Output: ["0.0.0.0"]

Input: s = "101023"
Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
```

## 限制 Constraints

1 <= s.length <= 20
s consists of digits only.

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** restoreIpAddresses(char* s, int* returnSize) {
    
}
```

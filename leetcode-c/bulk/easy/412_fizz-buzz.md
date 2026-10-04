# 0412. Fizz Buzz《Fizz Buzz》

- **Difficulty**: Easy
- **Tags**: math, string, simulation
- **題目連結**: https://leetcode.com/problems/fizz-buzz/
- **程式碼**: [`412_fizz-buzz.c`](./412_fizz-buzz.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數 n，回傳從 1 到 n 的字串陣列。能被 3 整除的位置放入 "Fizz"，能被 5 整除的位置放入 "Buzz"，同時符合兩者則放入 "FizzBuzz"；其餘位置放入該數字的字串。

**思路**：依序處理 1 到 n，分別檢查是否可被 3 與 5 整除並串接對應字串。兩者皆不整除時，將目前數字格式化為字串。

## Problem Statement (English)

Given an integer n, return a string array answer (1-indexed) where:
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: n = 3
Output: ["1","2","Fizz"]

Input: n = 5
Output: ["1","2","Fizz","4","Buzz"]

Input: n = 15
Output: ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
```

## 限制 Constraints

1 <= n <= 104

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    
}
```

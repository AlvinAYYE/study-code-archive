# 0575. Distribute Candies《分發糖果》

- **Difficulty**: Easy
- **Tags**: array, hash-table
- **題目連結**: https://leetcode.com/problems/distribute-candies/
- **程式碼**: [`575_distribute-candies.c`](./575_distribute-candies.c) — 社群解答（repo akib-islam-coder_leetcodesolutions），已通過編譯+官方示例執行驗證

## 題目說明（中文）

Alice 有 n 顆糖果，n 為偶數，每顆糖果有一個類型。她只能吃 n/2 顆糖果，請回傳在此前提下最多可吃到多少種不同類型。

**思路**：程式以正數與負數兩個直接定址表記錄類型是否出現，再計算相異類型數，達到 n/2 時即可提前停止。

## Problem Statement (English)

Alice has n candies, where the ith candy is of type candyType[i]. Alice noticed that she started to gain weight, so she visited a doctor.
The doctor advised Alice to only eat n / 2 of the candies she has (n is always even). Alice likes her candies very much, and she wants to eat the maximum number of different types of candies while still following the doctor's advice.
Given the integer array candyType of length n, return the maximum number of different types of candies she can eat if she only eats n / 2 of them.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: candyType = [1,1,2,2,3,3]
Output: 3
Explanation: Alice can only eat 6 / 2 = 3 candies. Since there are only 3 types, she can eat one of each type.

Input: candyType = [1,1,2,3]
Output: 2
Explanation: Alice can only eat 4 / 2 = 2 candies. Whether she eats types [1,2], [1,3], or [2,3], she still can only eat 2 different types.

Input: candyType = [6,6,6,6]
Output: 1
Explanation: Alice can only eat 4 / 2 = 2 candies. Even though she can eat 2 candies, she only has 1 type.
```

## 限制 Constraints

n == candyType.length
2 <= n <= 104
n is even.
-105 <= candyType[i] <= 105

## 官方 C 函式簽名 Signature

```c
int distributeCandies(int* candyType, int candyTypeSize) {
    
}
```

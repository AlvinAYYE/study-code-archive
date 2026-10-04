# 0492. Construct the Rectangle《建構矩形》

- **Difficulty**: Easy
- **Tags**: math
- **題目連結**: https://leetcode.com/problems/construct-the-rectangle/
- **程式碼**: [`492_construct-the-rectangle.c`](./492_construct-the-rectangle.c) — 本專案自行撰寫並通過官方示例驗證

## 題目說明（中文）

給定網頁矩形的面積 area，找出長度 L 與寬度 W。兩者必須為正整數、L 不小於 W、乘積等於 area，且 L 與 W 的差要盡可能小。回傳 [L, W]。

**思路**：程式從 area 的平方根開始向下尋找第一個可整除的寬度 W。令 L = area / W，可保證 L ≥ W 且兩邊差距最小。

## Problem Statement (English)

A web developer needs to know how to design a web page's size. So, given a specific rectangular web page’s area, your job by now is to design a rectangular web page, whose length L and width W satisfy the following requirements:
Return an array [L, W] where L and W are the length and width of the web page you designed in sequence.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: area = 4
Output: [2,2]
Explanation: The target area is 4, and all the possible ways to construct it are [1,4], [2,2], [4,1]. 
But according to requirement 2, [1,4] is illegal; according to requirement 3,  [4,1] is not optimal compared to [2,2]. So the length L is 2, and the width W is 2.

Input: area = 37
Output: [37,1]

Input: area = 122122
Output: [427,286]
```

## 限制 Constraints

1 <= area <= 107

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructRectangle(int area, int* returnSize) {
    
}
```

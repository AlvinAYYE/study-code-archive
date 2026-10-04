# 0455. Assign Cookies《分配餅乾》

- **Difficulty**: Easy
- **Tags**: array, two-pointers, greedy, sorting
- **題目連結**: https://leetcode.com/problems/assign-cookies/
- **程式碼**: [`455_assign-cookies.c`](./455_assign-cookies.c) — 社群解答（repo lightmen_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

每個孩子有滿足所需的最小餅乾大小 g[i]，每塊餅乾有大小 s[j]，且每個孩子至多分配一塊餅乾。當 s[j] 不小於 g[i] 時孩子會滿足，請回傳可滿足孩子數目的最大值。

**思路**：將孩子需求與餅乾大小皆排序，從兩端最大的項目開始配對。若最大餅乾足以滿足目前最大需求便配對並兩者後移，否則只略過該孩子。

## Problem Statement (English)

Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.
Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.
Example 1:
Example 2:
Constraints:
Note: This question is the same as  2410: Maximum Matching of Players With Trainers.

## 範例 Examples

```text
Input: g = [1,2,3], s = [1,1]
Output: 1
Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
You need to output 1.

Input: g = [1,2], s = [1,2,3]
Output: 2
Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2. 
You have 3 cookies and their sizes are big enough to gratify all of the children, 
You need to output 2.
```

## 限制 Constraints

1 <= g.length <= 3 * 104
0 <= s.length <= 3 * 104
1 <= g[i], s[j] <= 231 - 1

## 官方 C 函式簽名 Signature

```c
int findContentChildren(int* g, int gSize, int* s, int sSize) {
    
}
```

# 0002. Add Two Numbers《两数相加》

- **Difficulty**: Medium
- **Tags**: linked-list, math, recursion
- **題目連結**: https://leetcode.com/problems/add-two-numbers/
- **程式碼**: [`002_add-two-numbers.c`](./002_add-two-numbers.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定兩個非空連結串列，各自以反向位數表示一個非負整數，每個節點只存一位數字。請將兩數相加，並以相同反向格式回傳和的連結串列；除數字 0 外，原數不會有前導零。

**思路**：程式先找出較長串列，直接在其節點上逐位加上另一串列與進位。走訪結束後若仍有進位，便在尾端新增值為 1 的節點。

## Problem Statement (English)

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Input: l1 = [0], l2 = [0]
Output: [0]

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
```

## 限制 Constraints

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.

## 官方 C 函式簽名 Signature

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
}
```

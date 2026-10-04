# 0445. Add Two Numbers II《兩數相加 II》

- **Difficulty**: Medium
- **Tags**: linked-list, math, stack
- **題目連結**: https://leetcode.com/problems/add-two-numbers-ii/
- **程式碼**: [`445_add-two-numbers-ii.c`](./445_add-two-numbers-ii.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定兩個非空鏈結串列，各自以最高位在前的方式表示非負整數，每個節點存一位數字。請回傳兩數和的鏈結串列；除數值 0 外，輸入沒有前導零，並要求可不反轉輸入串列。

**思路**：先取得兩串列長度，必要時交換以確保第一串列較長。遞迴先處理尾端並向前傳遞進位，直接覆寫較長串列的節點值；最前方仍有進位時再建立新頭節點。

## Problem Statement (English)

You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Example 1:
Example 2:
Example 3:
Constraints:
Follow up: Could you solve it without reversing the input lists?

## 範例 Examples

```text
Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]

Input: l1 = [0], l2 = [0]
Output: [0]
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

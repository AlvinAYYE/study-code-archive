# 0206. Reverse Linked List《反轉鏈結串列》

- **Difficulty**: Easy
- **Tags**: linked-list, recursion
- **題目連結**: https://leetcode.com/problems/reverse-linked-list/
- **程式碼**: [`206_reverse-linked-list.c`](./206_reverse-linked-list.c) — 本專案自行撰寫並通過官方示例驗證

## 題目說明（中文）

給定單向鏈結串列的頭節點，請將整個串列反轉並回傳反轉後的頭節點。串列節點數可為 0。

**思路**：迭代維護前一節點、目前節點與下一節點，逐一將目前節點的 next 指回前一節點，最後回傳前一節點。

## Problem Statement (English)

Given the head of a singly linked list, reverse the list, and return the reversed list.
Example 1:
Example 2:
Example 3:
Constraints:
Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?

## 範例 Examples

```text
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Input: head = [1,2]
Output: [2,1]

Input: head = []
Output: []
```

## 限制 Constraints

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000

## 官方 C 函式簽名 Signature

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    
}
```

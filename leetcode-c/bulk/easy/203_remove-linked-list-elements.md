# 0203. Remove Linked List Elements《移除鏈結串列元素》

- **Difficulty**: Easy
- **Tags**: linked-list, recursion
- **題目連結**: https://leetcode.com/problems/remove-linked-list-elements/
- **程式碼**: [`203_remove-linked-list-elements.c`](./203_remove-linked-list-elements.c) — 本專案自行撰寫並通過官方示例驗證

## 題目說明（中文）

給定單向鏈結串列的頭節點與整數 val，請移除所有節點值等於 val 的節點，並回傳新的頭節點。串列可以是空的。

**思路**：建立指向原頭節點的虛擬節點，從虛擬節點開始檢查下一個節點；命中 val 時直接跳過該節點，否則向前移動。

## Problem Statement (English)

Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]

Input: head = [], val = 1
Output: []

Input: head = [7,7,7,7], val = 7
Output: []
```

## 限制 Constraints

The number of nodes in the list is in the range [0, 104].
1 <= Node.val <= 50
0 <= val <= 50

## 官方 C 函式簽名 Signature

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    
}
```

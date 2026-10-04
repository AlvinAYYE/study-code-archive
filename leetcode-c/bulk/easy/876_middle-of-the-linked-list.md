# 0876. Middle of the Linked List《鏈結串列的中間節點》

- **Difficulty**: Easy
- **Tags**: linked-list, two-pointers
- **題目連結**: https://leetcode.com/problems/middle-of-the-linked-list/
- **程式碼**: [`876_middle-of-the-linked-list.c`](./876_middle-of-the-linked-list.c) — 本專案自行撰寫並通過官方示例驗證

## 題目說明（中文）

給定單向鏈結串列的頭節點，回傳其中間節點。若串列長度為偶數而有兩個中間節點，必須回傳第二個。

**思路**：程式使用快慢指標同時從頭出發，快指標每次走兩步、慢指標每次走一步。快指標抵達尾端時，慢指標正好位於所需的中間節點。

## Problem Statement (English)

Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.

Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
```

## 限制 Constraints

The number of nodes in the list is in the range [1, 100].
1 <= Node.val <= 100

## 官方 C 函式簽名 Signature

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    
}
```

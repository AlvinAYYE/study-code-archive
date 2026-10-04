# 0083. Remove Duplicates from Sorted List《刪除排序串列中的重複元素》

- **Difficulty**: Easy
- **Tags**: linked-list
- **題目連結**: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
- **程式碼**: [`083_remove-duplicates-from-sorted-list.c`](./083_remove-duplicates-from-sorted-list.c) — 本專案自行撰寫並通過官方示例驗證

## 題目說明（中文）

給定遞增排序的鏈結串列，刪除重複節點，讓每個值僅保留一個節點。回傳處理後仍為排序狀態的串列。串列節點數介於 0 到 300。

**思路**：以目前節點向後走訪，若下一節點與目前值相同便直接跨過下一節點；否則才將目前指針前進。

## Problem Statement (English)

Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: head = [1,1,2]
Output: [1,2]

Input: head = [1,1,2,3,3]
Output: [1,2,3]
```

## 限制 Constraints

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.

## 官方 C 函式簽名 Signature

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    
}
```

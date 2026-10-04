# 0082. Remove Duplicates from Sorted List II《刪除排序串列中的重複元素 II》

- **Difficulty**: Medium
- **Tags**: linked-list, two-pointers
- **題目連結**: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
- **程式碼**: [`082_remove-duplicates-from-sorted-list-ii.c`](./082_remove-duplicates-from-sorted-list-ii.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定遞增排序的鏈結串列，刪除所有出現過重複值的節點，只保留原串列中恰好出現一次的值。回傳處理後仍為排序狀態的串列。串列節點數介於 0 到 300。

**思路**：逐段檢查相同值的節點群組；若群組只有一個節點便接到結果串列，若重複則整段跳過。最後將結果尾端設為 NULL。

## Problem Statement (English)

Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]

Input: head = [1,1,1,2,3]
Output: [2,3]
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

# 0021. Merge Two Sorted Lists《合併兩個有序連結串列》

- **Difficulty**: Easy
- **Tags**: linked-list, recursion
- **題目連結**: https://leetcode.com/problems/merge-two-sorted-lists/
- **程式碼**: [`021_merge-two-sorted-lists.c`](./021_merge-two-sorted-lists.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定兩個已依非遞減順序排列的連結串列，將它們合併成一個有序串列。合併時應串接原本兩串列的節點，並回傳合併後的頭節點。

**思路**：程式以虛擬頭節點作為輸出尾端，比較兩串列目前節點後接上較小者。任一串列耗盡時，直接接上另一串列的剩餘部分。

## Problem Statement (English)

You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Input: list1 = [], list2 = []
Output: []

Input: list1 = [], list2 = [0]
Output: [0]
```

## 限制 Constraints

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.

## 官方 C 函式簽名 Signature

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    
}
```

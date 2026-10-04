# 0148. Sort List《排序鏈結串列》

- **Difficulty**: Medium
- **Tags**: linked-list, two-pointers, divide-and-conquer, sorting, merge-sort
- **題目連結**: https://leetcode.com/problems/sort-list/
- **程式碼**: [`148_sort-list.c`](./148_sort-list.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定鏈結串列頭節點，將串列依遞增順序排序後回傳頭節點。題目進一步要求可在 O(n log n) 時間與 O(1) 額外空間內完成。串列節點數介於 0 至 5×10^4，節點值介於 -10^5 至 10^5。

**思路**：以快慢指針將串列切成兩半，遞迴排序兩半後，再將兩個已排序串列合併，形成合併排序。

## Problem Statement (English)

Given the head of a linked list, return the list after sorting it in ascending order.
Example 1:
Example 2:
Example 3:
Constraints:
Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?

## 範例 Examples

```text
Input: head = [4,2,1,3]
Output: [1,2,3,4]

Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

Input: head = []
Output: []
```

## 限制 Constraints

The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105

## 官方 C 函式簽名 Signature

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* sortList(struct ListNode* head) {
    
}
```

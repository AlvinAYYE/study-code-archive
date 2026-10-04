# 0025. Reverse Nodes in k-Group《K 個一組反轉連結串列》

- **Difficulty**: Hard
- **Tags**: linked-list, recursion
- **題目連結**: https://leetcode.com/problems/reverse-nodes-in-k-group/
- **程式碼**: [`025_reverse-nodes-in-k-group.c`](./025_reverse-nodes-in-k-group.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定連結串列頭節點與正整數 k，將節點每 k 個一組反轉後回傳串列。末尾不足 k 個的節點必須維持原順序，且不得修改節點值。

**思路**：程式將每一組最多 k 個節點先放入指標堆疊，再以彈出順序重接，從而完成該組反轉。若最後一組不足 k 個，便不改動該組並直接回傳。

## Problem Statement (English)

Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
You may not alter the values in the list's nodes, only nodes themselves may be changed.
Example 1:
Example 2:
Constraints:
Follow-up: Can you solve the problem in O(1) extra memory space?

## 範例 Examples

```text
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
```

## 限制 Constraints

The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000

## 官方 C 函式簽名 Signature

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    
}
```

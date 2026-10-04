# 0019. Remove Nth Node From End of List《刪除連結串列的倒數第 N 個節點》

- **Difficulty**: Medium
- **Tags**: linked-list, two-pointers
- **題目連結**: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
- **程式碼**: [`019_remove-nth-node-from-end-of-list.c`](./019_remove-nth-node-from-end-of-list.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定連結串列頭節點 head，刪除倒數第 n 個節點後回傳新的頭節點。n 保證有效；題目進一步要求嘗試在一次走訪中完成。

**思路**：程式讓快指針先向前走 n 步，再讓快慢指針同步前進，使慢指針停在待刪節點。另以 prev 保留前一節點來重新連接串列，並特別處理刪除頭節點的情況。

## Problem Statement (English)

Given the head of a linked list, remove the nth node from the end of the list and return its head.
Example 1:
Example 2:
Example 3:
Constraints:
Follow up: Could you do this in one pass?

## 範例 Examples

```text
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Input: head = [1], n = 1
Output: []

Input: head = [1,2], n = 1
Output: [1]
```

## 限制 Constraints

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz

## 官方 C 函式簽名 Signature

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    
}
```

# 0092. Reverse Linked List II《反轉鏈結串列 II》

- **Difficulty**: Medium
- **Tags**: linked-list
- **題目連結**: https://leetcode.com/problems/reverse-linked-list-ii/
- **程式碼**: [`092_reverse-linked-list-ii.c`](./092_reverse-linked-list-ii.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定單向鏈結串列頭節點，以及 1 起算的 left、right 位置，反轉從 left 到 right（含）之間的節點。其餘節點順序維持不變，並回傳結果串列。保證 1 ≤ left ≤ right ≤ 串列長度。

**思路**：單次走訪到指定範圍時原地反轉節點指標，並記住反轉區段前的節點與原本區段首節點。反轉結束後把前段接到新首節點，再將原首節點接回後段。

## Problem Statement (English)

Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

Input: head = [5], left = 1, right = 1
Output: [5]
```

## 限制 Constraints

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n

## 官方 C 函式簽名 Signature

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    
}
```

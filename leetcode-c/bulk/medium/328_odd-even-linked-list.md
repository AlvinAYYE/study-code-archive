# 0328. Odd Even Linked List《奇偶連結串列》

- **Difficulty**: Medium
- **Tags**: linked-list
- **題目連結**: https://leetcode.com/problems/odd-even-linked-list/
- **程式碼**: [`328_odd-even-linked-list.c`](./328_odd-even-linked-list.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定單向連結串列頭節點，請先串接所有奇數索引的節點，再串接所有偶數索引的節點；第一個節點索引為奇數。奇數組與偶數組內部都必須維持輸入時的相對順序，且需在 O(n) 時間、O(1) 額外空間完成。

**思路**：保留偶數串列的頭節點，並在走訪時交替重接奇數與偶數節點的 next 指標。奇數串列處理完後，把其尾端接回保留的偶數串列頭。

## Problem Statement (English)

Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
The first node is considered odd, and the second node is even, and so on.
Note that the relative order inside both the even and odd groups should remain as it was in the input.
You must solve the problem in O(1) extra space complexity and O(n) time complexity.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]

Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
```

## 限制 Constraints

The number of nodes in the linked list is in the range [0, 104].
-106 <= Node.val <= 106

## 官方 C 函式簽名 Signature

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    
}
```

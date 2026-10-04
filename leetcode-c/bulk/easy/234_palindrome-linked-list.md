# 0234. Palindrome Linked List《迴文連結串列》

- **Difficulty**: Easy
- **Tags**: linked-list, two-pointers, stack, recursion
- **題目連結**: https://leetcode.com/problems/palindrome-linked-list/
- **程式碼**: [`234_palindrome-linked-list.c`](./234_palindrome-linked-list.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定單向連結串列的頭節點，判斷其節點值序列是否為迴文。若正讀與反讀一致回傳 true，否則回傳 false。

**思路**：以快慢指標找出後半段起點，原地反轉後半段連結串列。再從頭部與反轉後半段逐節點比較。

## Problem Statement (English)

Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: head = [1,2,2,1]
Output: true

Input: head = [1,2]
Output: false
```

## 限制 Constraints

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9

## 官方 C 函式簽名 Signature

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    
}
```

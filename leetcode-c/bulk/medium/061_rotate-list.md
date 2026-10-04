# 0061. Rotate List《旋轉串列》

- **Difficulty**: Medium
- **Tags**: linked-list, two-pointers
- **題目連結**: https://leetcode.com/problems/rotate-list/
- **程式碼**: [`061_rotate-list.c`](./061_rotate-list.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定單向串列的頭節點，將串列向右旋轉 k 個位置並回傳新頭節點。串列可能為空，且 k 可以很大。

**思路**：先計算串列長度並把尾節點連回頭節點形成環。以 k 對長度取模後走到新的尾節點，斷開環並回傳下一個節點作為新頭。

## Problem Statement (English)

Given the head of a linked list, rotate the list to the right by k places.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Input: head = [0,1,2], k = 4
Output: [2,0,1]
```

## 限制 Constraints

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109

## 官方 C 函式簽名 Signature

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    
}
```

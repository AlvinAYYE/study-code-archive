# 0024. Swap Nodes in Pairs《兩兩交換連結串列中的節點》

- **Difficulty**: Medium
- **Tags**: linked-list, recursion
- **題目連結**: https://leetcode.com/problems/swap-nodes-in-pairs/
- **程式碼**: [`024_swap-nodes-in-pairs.c`](./024_swap-nodes-in-pairs.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定連結串列，將每相鄰的兩個節點交換後回傳頭節點。不得修改節點中的值，只能調整節點本身的連結。

**思路**：程式以遞迴處理每一對節點：把第二個節點接到第一個之前，再將第一個節點連到後續子串列交換後的結果。剩下不足一對的節點直接保留。

## Problem Statement (English)

Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
Example 1:
Example 2:
Example 3:
Example 4:
Constraints:

## 範例 Examples

```text
Input: head = [1,2,3,4]
Output: [2,1,4,3]
Explanation:

Input: head = []
Output: []

Input: head = [1]
Output: [1]

Input: head = [1,2,3]
Output: [2,1,3]
```

## 限制 Constraints

The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100

## 官方 C 函式簽名 Signature

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    
}
```

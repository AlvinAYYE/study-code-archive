# 0086. Partition List《分隔串列》

- **Difficulty**: Medium
- **Tags**: linked-list, two-pointers
- **題目連結**: https://leetcode.com/problems/partition-list/
- **程式碼**: [`086_partition-list.c`](./086_partition-list.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定鏈結串列頭節點與整數 x，將所有小於 x 的節點放在所有大於或等於 x 的節點之前。兩個分區內都必須保持原本節點的相對順序。回傳分隔後的串列。

**思路**：建立小於 x 與大於等於 x 的兩條虛擬頭串列，走訪時將節點依值接到對應尾端。走訪完後串接兩串列並封住後段尾端。

## Problem Statement (English)

Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]

Input: head = [2,1], x = 2
Output: [1,2]
```

## 限制 Constraints

The number of nodes in the list is in the range [0, 200].
-100 <= Node.val <= 100
-200 <= x <= 200

## 官方 C 函式簽名 Signature

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    
}
```

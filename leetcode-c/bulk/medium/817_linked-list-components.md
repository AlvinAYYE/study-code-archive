# 0817. Linked List Components《連結串列元件》

- **Difficulty**: Medium
- **Tags**: array, hash-table, linked-list
- **題目連結**: https://leetcode.com/problems/linked-list-components/
- **程式碼**: [`817_linked-list-components.c`](./817_linked-list-components.c) — 社群解答（repo akib-islam-coder_leetcodesolutions），已通過編譯+官方示例執行驗證

## 題目說明（中文）

連結串列節點值互異，nums 是其中節點值的子集合；若 nums 中兩個值在串列中相鄰，便屬於同一連通元件。回傳元件數量；節點數最多為 10^4。

**思路**：先把 nums 放入雜湊表，接著走訪串列並追蹤是否位於連續的已選節點區段；每個區段結束時將元件數加一。

## Problem Statement (English)

You are given the head of a linked list containing unique integer values and an integer array nums that is a subset of the linked list values.
Return the number of connected components in nums where two values are connected if they appear consecutively in the linked list.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: head = [0,1,2,3], nums = [0,1,3]
Output: 2
Explanation: 0 and 1 are connected, so [0, 1] and [3] are the two connected components.

Input: head = [0,1,2,3,4], nums = [0,3,1,4]
Output: 2
Explanation: 0 and 1 are connected, 3 and 4 are connected, so [0, 1] and [3, 4] are the two connected components.
```

## 限制 Constraints

The number of nodes in the linked list is n.
1 <= n <= 104
0 <= Node.val < n
All the values Node.val are unique.
1 <= nums.length <= n
0 <= nums[i] < n
All the values of nums are unique.

## 官方 C 函式簽名 Signature

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int numComponents(struct ListNode* head, int* nums, int numsSize) {
    
}
```

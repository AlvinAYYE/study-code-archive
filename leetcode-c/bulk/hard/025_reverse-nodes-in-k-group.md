# 0025. Reverse Nodes in k-Group《K 個一組反轉連結串列》

- **Difficulty**: Hard
- **Tags**: linked-list, recursion
- **題目連結**: https://leetcode.com/problems/reverse-nodes-in-k-group/
- **程式碼**: [`025_reverse-nodes-in-k-group.c`](./025_reverse-nodes-in-k-group.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定連結串列頭節點 `head` 與正整數 `k`，請將節點每 `k` 個分成一組並反轉各組，最後回傳修改後的串列。若節點總數不是 `k` 的倍數，末尾不足 `k` 個的節點必須維持原順序。不得修改節點內的值，只能重新連接節點本身。

## 解題思路

1. 在串列前放一個 `dummy` 節點，`p` 永遠指向已完成部分的尾端，第一組與後續各組便能共用同一套接法。
2. 從待處理區段依序取最多 `k` 個節點，把節點指標壓入大小為 `k` 的堆疊。
3. 若這一組不足 `k` 個，題目要求保持原順序，因此直接回傳目前串列。
4. 若湊滿 `k` 個，依後進先出順序把節點接回，便能反轉這一組。
5. 將組尾接到下一個尚未處理的節點，再繼續處理下一組。

每個節點只進出堆疊一次，時間複雜度為 `O(n)`，額外空間為 `O(k)`。

## Problem Statement (English)

Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
You may not alter the values in the list's nodes, only nodes themselves may be changed.
Example 1:
Example 2:
Constraints:
Follow-up: Can you solve the problem in O(1) extra memory space?

## 範例

```text
輸入：head = [1,2,3,4,5], k = 2
輸出：[2,1,4,3,5]

輸入：head = [1,2,3,4,5], k = 3
輸出：[3,2,1,4,5]
```

## 限制

- 串列節點數為 `n`。
- `1 <= k <= n <= 5000`
- `0 <= Node.val <= 1000`

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

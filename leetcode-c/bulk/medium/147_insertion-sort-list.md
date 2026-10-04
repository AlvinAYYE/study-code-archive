# 0147. Insertion Sort List《對鏈結串列進行插入排序》

- **Difficulty**: Medium
- **Tags**: linked-list, sorting
- **題目連結**: https://leetcode.com/problems/insertion-sort-list/
- **程式碼**: [`147_insertion-sort-list.c`](./147_insertion-sort-list.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定單向鏈結串列的頭節點，使用插入排序將串列排序後回傳新頭節點。插入排序會維護已排序部分，並在每輪從未排序部分取出一個節點，原地插入其正確位置。串列節點數介於 1 至 5000，節點值介於 -5000 至 5000。

**思路**：逐一從輸入串列拆下節點，在已排序串列中線性尋找第一個不小於它的位置，再將該節點插入。

## Problem Statement (English)

Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.
The steps of the insertion sort algorithm:
The following is a graphical example of the insertion sort algorithm. The partially sorted list (black) initially contains only the first element in the list. One element (red) is removed from the input data and inserted in-place into the sorted list with each iteration.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: head = [4,2,1,3]
Output: [1,2,3,4]

Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
```

## 限制 Constraints

The number of nodes in the list is in the range [1, 5000].
-5000 <= Node.val <= 5000

## 官方 C 函式簽名 Signature

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    
}
```

# 0092. Reverse Linked List II｜反轉鏈結串列 II

- **難度**：中等
- **標籤**：鏈結串列
- **題目連結**：[LeetCode 0092](https://leetcode.com/problems/reverse-linked-list-ii/)
- **C 程式**：[092_reverse-linked-list-ii.c](./092_reverse-linked-list-ii.c)

## 題目說明

給定單向鏈結串列和位置 `left`、`right`（位置從 1 開始），反轉這兩個位置之間的節點，其他節點維持原位，回傳新串列的頭節點。只反轉指定區段，不需要建立新的節點。

## 範例

```text
輸入：head = [1,2,3,4,5], left = 2, right = 4
輸出：[1,4,3,2,5]

輸入：head = [5], left = 1, right = 1
輸出：[5]
```

## 限制

- 節點數 `n` 介於 `1` 到 `500`。
- `-500 <= Node.val <= 500`。
- `1 <= left <= right <= n`。

## 解題步驟

1. 在原頭節點前放一個虛擬節點，統一處理 `left == 1` 時頭節點也要改變的情況。
2. 讓 `before` 走到反轉區段前一個節點，`sublistHead` 指向區段目前的第一個節點。
3. 每次把 `sublistHead` 後面的節點取下，插到 `before` 後面。這樣區段會逐步反轉，而區段外的連結保持接好。
4. 重複 `right - left` 次，回傳虛擬節點的下一個節點。

## 複雜度

- 時間：`O(n)`，走到區段並逐個調整節點。
- 額外空間：`O(1)`，只重新連接既有節點。

## LeetCode C 函式簽名

```c
struct ListNode* reverseBetween(struct ListNode* head, int left, int right);
```

# 0021. Merge Two Sorted Lists《合併兩個有序鏈結串列》

- **難度**：Easy
- **標籤**：linked-list、recursion
- **題目連結**：https://leetcode.com/problems/merge-two-sorted-lists/
- **程式碼**：[`021_merge-two-sorted-lists.c`](./021_merge-two-sorted-lists.c)

## 題目說明

給定兩個按非遞減順序排列的單向鏈結串列 `list1` 與 `list2`。重新串接兩者原有的節點，合併成一個同樣按非遞減順序排列的串列，並回傳合併後的表頭。

## 範例

```text
輸入：list1 = [1,2,4], list2 = [1,3,4]
輸出：[1,1,2,3,4,4]

輸入：list1 = [], list2 = []
輸出：[]

輸入：list1 = [], list2 = [0]
輸出：[0]
```

## 限制

- 兩個串列的節點總數介於 0 到 50。
- `-100 <= Node.val <= 100`
- `list1` 與 `list2` 都按非遞減順序排列。

## 直觀解題思路

1. 建立不存答案資料的虛擬表頭 `head`，並以 `p` 指向目前結果尾端。
2. 當兩串列都有節點時，比較表頭值，把較小節點接到 `p` 後方。
3. 推進被取用串列的表頭與 `p`，重複比較。
4. 一條串列用完後，另一條剩餘部分本來就有序，可整段接上。

- 時間複雜度：`O(m+n)`
- 額外空間複雜度：`O(1)`

## 官方 C 函式簽名

```c
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2);
```

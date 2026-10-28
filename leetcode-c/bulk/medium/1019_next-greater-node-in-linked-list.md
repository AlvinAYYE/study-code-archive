# 1019. Next Greater Node In Linked List｜鏈結串列中的下一個較大節點

- **難度**：中等
- **標籤**：鏈結串列、堆疊、單調堆疊
- **題目連結**：[LeetCode 1019](https://leetcode.com/problems/next-greater-node-in-linked-list/)
- **C 程式**：[1019_next-greater-node-in-linked-list.c](./1019_next-greater-node-in-linked-list.c)

## 題目說明

給定有 `n` 個節點的鏈結串列，對每個節點找出它後方第一個值嚴格較大的節點值。回傳長度為 `n` 的陣列；若某節點後方沒有更大的值，該位置填 `0`。

## 範例

```text
輸入：head = [2,1,5]
輸出：[5,5,0]

輸入：head = [2,7,4,3,5]
輸出：[7,0,5,5,0]
```

## 限制

- 節點數 `1 <= n <= 10^4`。
- `1 <= Node.val <= 10^9`。

## 解題步驟

1. 先把鏈結串列的值依序複製到陣列，這樣就能用索引表示每個節點的位置。
2. `stack` 保存尚未找到下一個較大值的索引，並維持這些索引對應的值由大到小排列。
3. 掃描目前值時，只要它比堆疊頂端對應值大，就代表目前值是那些節點的第一個較大值，填入答案並彈出索引。
4. 將目前索引推入堆疊。掃描結束後仍留在堆疊中的節點沒有更大值，答案保持初始的 `0`。

## 複雜度

- 時間：`O(n)`，每個索引最多進出堆疊一次。
- 額外空間：`O(n)`，保存節點值、答案與單調堆疊。

## LeetCode C 函式簽名

```c
int* nextLargerNodes(struct ListNode* head, int* returnSize);
```

# 0019. Remove Nth Node From End of List｜刪除連結串列的倒數第 N 個節點

- **難度**：中等
- **標籤**：鏈結串列、雙指標
- **題目連結**：[LeetCode 0019](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)
- **C 程式**：[019_remove-nth-node-from-end-of-list.c](./019_remove-nth-node-from-end-of-list.c)

## 題目說明

給定單向鏈結串列 `head` 和整數 `n`，刪除從尾端往前數第 `n` 個節點，並回傳刪除後的頭節點。`n` 一定有效；進階要求是只走訪串列一次。

## 範例

```text
輸入：head = [1,2,3,4,5], n = 2
輸出：[1,2,3,5]
說明：倒數第二個節點是 4。

輸入：head = [1], n = 1
輸出：[]

輸入：head = [1,2], n = 1
輸出：[1]
```

## 限制

- 節點數 `sz`：`1 <= sz <= 30`。
- `0 <= Node.val <= 100`。
- `1 <= n <= sz`。

## 解題步驟

1. 在原頭節點前放一個虛擬節點 `dummy`，讓「刪除頭節點」也能用一般的前後連結處理。
2. `fast`、`slow` 起初都指向 `dummy`。先讓 `fast` 前進 `n` 步，兩者保持固定距離。
3. 同時移動兩個指標，直到 `fast` 到最後一個節點。此時 `slow->next` 正是要刪除的節點。
4. 把 `slow->next` 改接到待刪節點的下一個節點，回傳 `dummy.next`。

例如 `[1,2,3,4,5]`、`n = 2`：快指標先走兩步，再與慢指標一起走到尾端，慢指標停在 3，於是把 3 直接接到 5。

## 複雜度

- 時間：`O(sz)`，單次走訪。
- 額外空間：`O(1)`。

## LeetCode C 函式簽名

```c
struct ListNode* removeNthFromEnd(struct ListNode* head, int n);
```

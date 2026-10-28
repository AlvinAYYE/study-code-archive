# 0024. Swap Nodes in Pairs｜兩兩交換連結串列中的節點

- **難度**：中等
- **標籤**：鏈結串列、遞迴
- **題目連結**：[LeetCode 0024](https://leetcode.com/problems/swap-nodes-in-pairs/)
- **C 程式**：[024_swap-nodes-in-pairs.c](./024_swap-nodes-in-pairs.c)

## 題目說明

給定單向鏈結串列，將相鄰節點兩兩交換後回傳新的頭節點。只能改變節點的連結，不能修改節點值；使用常數額外空間。

## 範例

```text
輸入：head = [1,2,3,4]
輸出：[2,1,4,3]
說明：先交換 1 和 2，再交換 3 和 4。

輸入：head = []
輸出：[]

輸入：head = [1]
輸出：[1]

輸入：head = [1,2,3]
輸出：[2,1,3]
說明：最後的 3 沒有配對節點，因此留在原位。
```

## 限制

- 節點數介於 `0` 到 `100`。
- `0 <= Node.val <= 100`。

## 解題步驟

1. 用虛擬頭節點 `dummy` 指向原串列，`previous` 指向目前這一對之前的節點。
2. 若 `previous` 後面還有兩個節點，令 `first`、`second` 指向這一對。
3. 重新接線成 `previous → second → first → 原本第三個節點`。
4. 交換後令 `previous = first`，再處理下一對。若剩一個落單節點，迴圈會自然停止。
5. 回傳 `dummy.next`，它可能已經是新的頭節點。

## 複雜度

- 時間：`O(n)`，每一對節點只交換一次。
- 額外空間：`O(1)`，只使用固定數量的指標。

## LeetCode C 函式簽名

```c
struct ListNode* swapPairs(struct ListNode* head);
```

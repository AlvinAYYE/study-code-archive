# 0061. Rotate List｜旋轉連結串列

- **難度**：中等
- **標籤**：鏈結串列、雙指標
- **題目連結**：[LeetCode 0061](https://leetcode.com/problems/rotate-list/)
- **C 程式**：[061_rotate-list.c](./061_rotate-list.c)

## 題目說明

給定單向連結串列 `head`，將串列向右旋轉 `k` 個位置並回傳新頭節點。向右旋轉一次會把尾節點移到最前面。

## 範例

```text
輸入：head = [1,2,3,4,5], k = 2
輸出：[4,5,1,2,3]

輸入：head = [0,1,2], k = 4
輸出：[2,0,1]
說明：長度為 3，旋轉 4 次等同旋轉 1 次。
```

## 限制

- 節點數介於 `0` 到 `500`。
- `-100 <= Node.val <= 100`。
- `0 <= k <= 2 × 10^9`。

## 解題步驟

1. 走訪串列取得 `length` 和 `tail`；空串列直接回傳。
2. `shift = k % length`，因為每旋轉整整一圈，串列會回到原狀；若 `shift == 0` 也直接回傳。
3. 暫時把 `tail->next` 接到 `head`，形成環。
4. 新尾端在原串列索引 `length - shift - 1`；取它的下一個節點作為新頭，再把新尾端的 `next` 設為 `NULL`。

## 複雜度

- 時間：`O(n)`，走訪串列一次並定位新尾端。
- 額外空間：`O(1)`。

## LeetCode C 函式簽名

```c
struct ListNode* rotateRight(struct ListNode* head, int k);
```

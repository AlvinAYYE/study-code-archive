# 0083. Remove Duplicates from Sorted List《刪除排序串列中的重複元素》

- **難度**：Easy
- **標籤**：鏈結串列
- **題目連結**：https://leetcode.com/problems/remove-duplicates-from-sorted-list/

## 題目說明

給定一個已按遞增順序排序的鏈結串列，刪除重複節點，使每個不同的數值只出現一次。請回傳整理後的串列起點。因為串列已排序，相同數值一定相鄰。

## 範例

```text
輸入：head = [1,1,2]
輸出：[1,2]

輸入：head = [1,1,2,3,3]
輸出：[1,2,3]
```

## 限制

- 節點數介於 `0` 到 `300`。
- `-100 <= Node.val <= 100`。
- 串列保證依遞增順序排列。

## 解題思路

1. 用指標 `cur` 從串列開頭往後走。
2. 若 `cur` 和 `cur->next` 的值相同，就把 `cur->next` 改成它的下一個節點，等於跳過一個重複節點；此時先留在 `cur`，以便處理連續出現的多個重複值。
3. 若兩個值不同，才把 `cur` 移到下一個節點。走到尾端後，原串列起點就是答案。

**複雜度**：時間 `O(n)`，額外空間 `O(1)`。

## C 函式簽名

```c
struct ListNode* deleteDuplicates(struct ListNode* head);
```

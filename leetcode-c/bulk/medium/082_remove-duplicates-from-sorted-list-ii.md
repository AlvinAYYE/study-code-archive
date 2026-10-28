# 0082. Remove Duplicates from Sorted List II｜移除排序串列中的重複項 II

- **難度**：中等
- **標籤**：鏈結串列、雙指標
- **題目連結**：[LeetCode 0082](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/)
- **C 程式**：[082_remove-duplicates-from-sorted-list-ii.c](./082_remove-duplicates-from-sorted-list-ii.c)

## 題目說明

給定已遞增排序的單向鏈結串列，刪除所有值有重複的節點，只留下在原串列中只出現一次的值，並回傳新串列。若某個值出現兩次或更多次，該值的節點要全部移除。

## 範例

```text
輸入：head = [1,2,3,3,4,4,5]
輸出：[1,2,5]

輸入：head = [1,1,1,2,3]
輸出：[2,3]
```

## 限制

- 節點數介於 `0` 到 `300`。
- `-100 <= Node.val <= 100`。
- 串列依遞增順序排序。

## 解題步驟

1. 建立虛擬頭節點 `dummy`，讓原本頭節點也能用相同方式刪除；`previous` 指向最後一個已確認唯一的節點。
2. `current` 若和下一個節點值不同，表示它只出現一次，把它接到 `previous` 後面，再一起前進。
3. 若兩者相同，記下這個重複值，將 `current` 一路跳過直到遇到不同值；`previous` 不前進，因為被跳過的整組都不能留下。
4. 回傳 `dummy.next`。唯一節點只會依原順序接回，因此結果仍保持排序。

## 複雜度

- 時間：`O(n)`，每個節點最多走訪一次。
- 額外空間：`O(1)`。

## LeetCode C 函式簽名

```c
struct ListNode* deleteDuplicates(struct ListNode* head);
```

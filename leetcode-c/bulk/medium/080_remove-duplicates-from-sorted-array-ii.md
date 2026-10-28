# 0080. Remove Duplicates from Sorted Array II｜移除排序陣列中的重複項 II

- **難度**：中等
- **標籤**：陣列、雙指標
- **題目連結**：[LeetCode 0080](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/)
- **C 程式**：[080_remove-duplicates-from-sorted-array-ii.c](./080_remove-duplicates-from-sorted-array-ii.c)

## 題目說明

給定非遞減排序的整數陣列 `nums`，原地移除多餘重複值，使每個不同數字最多出現兩次。保留元素原本的相對順序，並回傳新長度 `k`；答案只需放在 `nums[0..k-1]`，後面的內容不重要。不能另建陣列，額外空間需為 `O(1)`。

## 範例

```text
輸入：nums = [1,1,1,2,2,3]
輸出：k = 5，nums 前 5 項為 [1,1,2,2,3]

輸入：nums = [0,0,1,1,1,1,2,3,3]
輸出：k = 7，nums 前 7 項為 [0,0,1,1,2,3,3]
```

## 限制

- `1 <= nums.length <= 3 × 10^4`。
- `-10^4 <= nums[i] <= 10^4`。
- `nums` 已依非遞減順序排序。

## 解題步驟

1. `write` 指向下一個可以寫入的位置。前兩個元素最多都能保留，因此先令 `write = 2`。
2. 從第三個元素開始讀取。若目前值不等於已保留區最後第二個值 `nums[write - 2]`，代表它最多只會是第三次以後的新重複值，不能放入；若不同，就把它寫到 `nums[write]` 並前進 `write`。
3. 掃描結束時，`write` 就是最多保留兩次後的長度。
4. 少於兩個元素時不需處理，直接回傳原長度。

## 複雜度

- 時間：`O(n)`，每個元素讀取一次。
- 額外空間：`O(1)`，直接覆寫輸入陣列。

## LeetCode C 函式簽名

```c
int removeDuplicates(int* nums, int numsSize);
```

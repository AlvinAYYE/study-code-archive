# 0027. Remove Element《移除元素》

- **難度**：Easy
- **標籤**：array、two-pointers
- **題目連結**：https://leetcode.com/problems/remove-element/
- **程式碼**：[`027_remove-element.c`](./027_remove-element.c)

## 題目說明

給定整數陣列 `nums` 與整數 `val`，原地移除所有等於 `val` 的元素，並回傳不等於 `val` 的元素數量 `k`。保留元素的順序可以改變，`nums` 前 `k` 個位置必須是保留元素；其後內容不列入答案。

## 範例

```text
輸入：nums = [3,2,2,3], val = 3
輸出：2, nums = [2,2,_,_]
說明：回傳 k = 2，前兩個元素都是 2。

輸入：nums = [0,1,2,2,3,0,4,2], val = 2
輸出：5, nums = [0,1,4,0,3,_,_,_]
說明：前五個元素包含 0、0、1、3、4，順序不限。
```

## 限制

- `0 <= nums.length <= 100`
- `0 <= nums[i] <= 50`
- `0 <= val <= 100`

## 直觀解題思路

1. `i` 先找到第一個等於 `val` 的位置；在它之前的元素可原樣保留。
2. `j` 從下一格往後掃描，每遇到不等於 `val` 的元素，就寫入 `nums[i]` 並推進 `i`。
3. 掃描結束後，索引 0 到 `i-1` 都是保留元素，所以 `i` 就是答案。

- 時間複雜度：`O(n)`
- 額外空間複雜度：`O(1)`

## 官方 C 函式簽名

```c
int removeElement(int* nums, int numsSize, int val);
```

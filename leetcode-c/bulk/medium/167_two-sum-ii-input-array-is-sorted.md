# 0167. Two Sum II - Input Array Is Sorted｜兩數之和 II：輸入陣列已排序

- **難度**：中等
- **標籤**：陣列、雙指標、二分搜尋
- **題目連結**：[LeetCode 0167](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)
- **C 程式**：[167_two-sum-ii-input-array-is-sorted.c](./167_two-sum-ii-input-array-is-sorted.c)

## 題目說明

給定已依非遞減順序排序的整數陣列 `numbers` 和目標值 `target`，找出兩個不同元素，使它們的和等於目標。回傳兩個索引，索引從 1 開始，且第一個索引小於第二個。題目保證恰有一組解，不能重複使用同一元素，並要求常數額外空間。

## 範例

```text
輸入：numbers = [2,7,11,15], target = 9
輸出：[1,2]

輸入：numbers = [2,3,4], target = 6
輸出：[1,3]

輸入：numbers = [-1,0], target = -1
輸出：[1,2]
```

## 限制

- `2 <= numbers.length <= 3 × 10^4`。
- `-1000 <= numbers[i], target <= 1000`。
- `numbers` 已依非遞減順序排序，且恰有一組解。

## 解題步驟

1. `left` 指向最小值，`right` 指向最大值，從陣列兩端往中間搜尋。
2. 若兩數總和等於 `target`，回傳它們的 1 起始索引。
3. 若總和太小，左端數字太小，將 `left` 右移；若總和太大，將 `right` 左移。
4. 因為陣列已排序，每次移動都能排除一端不可能的候選值。

## 複雜度

- 時間：`O(n)`，雙指標最多各移動 `n` 次。
- 額外空間：`O(1)`，不含題目要求的兩個回傳索引。

## LeetCode C 函式簽名

```c
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize);
```

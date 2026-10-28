# 0031. Next Permutation｜下一個排列

- **難度**：中等
- **標籤**：陣列、雙指標
- **題目連結**：[LeetCode 0031](https://leetcode.com/problems/next-permutation/)
- **C 程式**：[031_next-permutation.c](./031_next-permutation.c)

## 題目說明

給定整數陣列 `nums`，請把它原地改成字典順序中緊接在目前排列後面的排列。若目前排列已經是字典順序最大的排列，就改成最小排列（由小到大排序）。

必須直接修改 `nums`，只使用常數額外空間。

## 範例

```text
輸入：nums = [1,2,3]
輸出：[1,3,2]

輸入：nums = [3,2,1]
輸出：[1,2,3]
說明：原排列已是最大排列，因此回到最小排列。

輸入：nums = [1,1,5]
輸出：[1,5,1]
```

## 限制

- `1 <= nums.length <= 100`。
- `0 <= nums[i] <= 100`。

## 解題步驟

1. 從右往左找第一個滿足 `nums[pivot] < nums[pivot + 1]` 的位置。右側在此之前都已是遞減排列。
2. 若找到 `pivot`，從最右側往左找第一個比 `nums[pivot]` 大的數 `successor`，交換兩者。由右往左找會得到可替換的最小較大數。
3. 把 `pivot` 右側反轉成遞增順序，讓交換後的結果盡可能小。
4. 若找不到 `pivot`，代表整個陣列遞減，直接反轉整個陣列。

## 複雜度

- 時間：`O(n)`，尋找、交換與反轉最多各掃描一次。
- 額外空間：`O(1)`，所有操作都在原陣列完成。

## LeetCode C 函式簽名

```c
void nextPermutation(int* nums, int numsSize);
```

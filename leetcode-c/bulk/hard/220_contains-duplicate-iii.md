# 0220. 存在重複元素 III（Contains Duplicate III）

- **難度**：Hard
- **標籤**：陣列、滑動視窗、排序、桶排序
- **題目連結**：[LeetCode 220](https://leetcode.com/problems/contains-duplicate-iii/)
- **解答檔案**：[220_contains-duplicate-iii.c](./220_contains-duplicate-iii.c)

## 題目完整翻譯

給定整數陣列 `nums`，以及整數 `indexDiff`、`valueDiff`。請判斷是否存在兩個不同索引 `i`、`j`，同時滿足：

- `|i - j| <= indexDiff`
- `|nums[i] - nums[j]| <= valueDiff`

存在就回傳 `true`，否則回傳 `false`。

## 範例

```text
輸入：nums = [1,2,3,1], indexDiff = 3, valueDiff = 0
輸出：true
說明：選 i = 0、j = 3；索引差為 3，數值差為 0。

輸入：nums = [1,5,9,1,5,9], indexDiff = 2, valueDiff = 3
輸出：false
```

## 限制

- `2 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`
- `1 <= indexDiff <= nums.length`
- `0 <= valueDiff <= 10^9`

## 解題思路

1. 從左到右掃描，維持一個最多包含 `indexDiff` 個舊元素的滑動視窗；太舊的元素先移除。
2. 把數值分成寬度 `valueDiff + 1` 的桶。同一桶內任兩數的差一定不超過 `valueDiff`，因此桶已有人就找到答案。
3. 只要再檢查相鄰兩桶，並確認實際差值是否不超過 `valueDiff`。更遠的桶不可能符合條件。
4. 將目前數值放入桶，繼續掃描。

桶編號使用數學上的向下取整；C 的整數除法會朝 0 截斷，因此負數需要特別修正。

## 複雜度

- 時間：雜湊表平均 `O(n)`。
- 額外空間：`O(indexDiff)`，最多為 `O(n)`。

## C 函式介面

```c
bool containsNearbyAlmostDuplicate(int* nums, int numsSize, int indexDiff, int valueDiff);
```

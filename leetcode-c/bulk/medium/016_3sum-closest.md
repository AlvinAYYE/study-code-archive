# 0016. 3Sum Closest｜最接近的三數之和

- **難度**：中等
- **標籤**：陣列、雙指標、排序
- **題目連結**：[LeetCode 0016](https://leetcode.com/problems/3sum-closest/)
- **C 程式**：[016_3sum-closest.c](./016_3sum-closest.c)

## 題目說明

給定整數陣列 `nums` 和整數 `target`，從不同索引選三個數，使總和與 `target` 的差距最小，回傳這個總和。題目保證每筆輸入有唯一的最接近答案。

## 範例

```text
輸入：nums = [-1,2,1,-4], target = 1
輸出：2
說明：-1 + 2 + 1 = 2，和 target 的差距是 1。

輸入：nums = [0,0,0], target = 1
輸出：0
```

## 限制

- `3 <= nums.length <= 500`。
- `-1000 <= nums[i] <= 1000`。
- `-10^4 <= target <= 10^4`。

## 解題步驟

1. 排序陣列，方便判斷總和太小或太大。
2. 用 `i` 固定第一個數，再以 `left`、`right` 搜尋另外兩個數。
3. `sum` 是目前三數總和；若 `|sum - target|` 小於已知差距，就更新 `closest`。
4. `sum < target` 時增加 `left` 讓總和變大；`sum > target` 時減少 `right` 讓總和變小；相等時已找到最佳答案，可直接回傳。

## 複雜度

- 時間：`O(n^2)`。
- 額外空間：搜尋使用 `O(1)`；不含排序使用的空間。

## LeetCode C 函式簽名

```c
int threeSumClosest(int* nums, int numsSize, int target);
```

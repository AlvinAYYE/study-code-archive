# 1004. Max Consecutive Ones III｜最大連續 1 的數量 III

- **難度**：中等
- **標籤**：陣列、二分搜尋、滑動視窗
- **題目連結**：[LeetCode 1004](https://leetcode.com/problems/max-consecutive-ones-iii/)
- **C 程式**：[1004_max-consecutive-ones-iii.c](./1004_max-consecutive-ones-iii.c)

## 題目說明

給定只含 `0` 和 `1` 的陣列 `nums`，最多可以把 `k` 個 `0` 翻成 `1`。請找出翻轉後最長的連續 `1` 區段長度。等價地說，找出原陣列中最多包含 `k` 個零的最長連續子陣列。

## 範例

```text
輸入：nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
輸出：6
說明：翻轉一段中的兩個 0 後，可得到長度 6 的連續 1。

輸入：nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
輸出：10
```

## 限制

- `1 <= nums.length <= 10^5`。
- `nums[i]` 只會是 `0` 或 `1`。
- `0 <= k <= nums.length`。

## 解題步驟

1. 用 `left`、`right` 表示目前視窗左右界，`zeroCount` 記錄視窗內的零數量。
2. `right` 每次向右擴張；遇到 `0` 就增加 `zeroCount`。
3. 若視窗中的零超過 `k`，就反覆右移 `left`，並在移出的是 `0` 時減少計數，直到視窗重新合法。
4. 每次視窗合法時，用 `right - left + 1` 更新最長長度。

## 複雜度

- 時間：`O(n)`，左右指標都只向右移動。
- 額外空間：`O(1)`。

## LeetCode C 函式簽名

```c
int longestOnes(int* nums, int numsSize, int k);
```

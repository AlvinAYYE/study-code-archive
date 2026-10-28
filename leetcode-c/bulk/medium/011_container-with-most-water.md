# 0011. Container With Most Water｜盛最多水的容器

- **難度**：中等
- **標籤**：陣列、雙指標、貪心
- **題目連結**：[LeetCode 0011](https://leetcode.com/problems/container-with-most-water/)
- **C 程式**：[011_container-with-most-water.c](./011_container-with-most-water.c)

## 題目說明

給定陣列 `height`。索引 `i` 代表一條從 `(i, 0)` 延伸到 `(i, height[i])` 的直線。選兩條線與 x 軸形成不能傾斜的容器，回傳能裝水的最大面積。

面積 = 兩線距離 × 較矮那條線的高度。

## 範例

```text
輸入：height = [1,8,6,2,5,4,8,3,7]
輸出：49
說明：選索引 1 和 8；寬度為 7，較矮高度為 7，所以面積是 7 × 7 = 49。

輸入：height = [1,1]
輸出：1
```

## 限制

- `n == height.length`。
- `2 <= n <= 10^5`。
- `0 <= height[i] <= 10^4`。

## 解題步驟

1. `left`、`right` 從陣列兩端開始，代表目前考慮的兩條線。
2. 算出寬度 `right - left`，再乘上 `height[left]`、`height[right]` 中較小的值，更新 `bestArea`。
3. 移動較短的一端。水位受短線限制；若保留這條短線卻縮小寬度，面積不會變大。只有換掉短線才有機會提高水位。
4. 指標相遇時結束，回傳目前最大面積。

## 複雜度

- 時間：`O(n)`，每一步都讓一個指標往內移動。
- 額外空間：`O(1)`。

## LeetCode C 函式簽名

```c
int maxArea(int* height, int heightSize);
```

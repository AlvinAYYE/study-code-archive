# 0042. Trapping Rain Water《接雨水》

- **Difficulty**: Hard
- **Tags**: array, two-pointers, dynamic-programming, stack, monotonic-stack
- **題目連結**: https://leetcode.com/problems/trapping-rain-water/
- **程式碼**: [`042_trapping-rain-water.c`](./042_trapping-rain-water.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定 `n` 個非負整數 `height`，代表每根寬度皆為 1 的柱子高度。請計算下雨後，這張高度圖總共能接住多少單位的雨水。

## 解題思路

1. 某位置的水位由左右最高牆中較矮者決定。只要知道其中較矮的一端，就能確定該端目前位置的積水量。
2. 左右指標 `i`、`j` 從兩端往中央移動，每次取 `height[i]`、`height[j]` 中較小者 `h`；另一端至少有一根高度不低於 `h` 的牆，因此 `h` 這側可以安全結算。
3. `k` 記錄已結算路徑上的最高有效邊界。若 `h < k`，該格可接 `k-h` 單位的水；否則以 `h` 更新最高邊界。
4. 每根柱子只會處理一次，直到兩個指標交錯。

時間複雜度為 `O(n)`，額外空間為 `O(1)`。

## Problem Statement (English)

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
Example 1:
Example 2:
Constraints:

## 範例

```text
輸入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
輸出：6
說明：各凹槽累計可接住 6 單位的雨水。

輸入：height = [4,2,0,3,2,5]
輸出：9
```

## 限制

- `n == height.length`
- `1 <= n <= 2 * 10^4`
- `0 <= height[i] <= 10^5`

## 官方 C 函式簽名 Signature

```c
int trap(int* height, int heightSize) {
    
}
```

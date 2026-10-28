# 0053. Maximum Subarray｜最大子陣列和

- **難度**：中等
- **標籤**：陣列、動態規劃、分治
- **題目連結**：[LeetCode 0053](https://leetcode.com/problems/maximum-subarray/)
- **C 程式**：[053_maximum-subarray.c](./053_maximum-subarray.c)

## 題目說明

給定整數陣列 `nums`，找出總和最大的**連續子陣列**，回傳其總和。子陣列至少包含一個元素。

## 範例

```text
輸入：nums = [-2,1,-3,4,-1,2,1,-5,4]
輸出：6
說明：連續片段 [4,-1,2,1] 的總和最大，為 6。

輸入：nums = [1]
輸出：1

輸入：nums = [5,4,-1,7,8]
輸出：23
```

## 限制

- `1 <= nums.length <= 10^5`。
- `-10^4 <= nums[i] <= 10^4`。

## 解題步驟

1. `currentSum` 表示「必須以目前元素結尾」的最大子陣列和；`bestSum` 記錄掃描至今的最大值。
2. 對每個新元素，選擇接在舊片段後面，或從這個元素重新開始：`currentSum = max(nums[i], currentSum + nums[i])`。
3. 用新的 `currentSum` 更新 `bestSum`。
4. 從第一個元素初始化兩個總和，確保全負數陣列也會選到至少一個元素。

## 複雜度

- 時間：`O(n)`，每個元素處理一次。
- 額外空間：`O(1)`。

## LeetCode C 函式簽名

```c
int maxSubArray(int* nums, int numsSize);
```

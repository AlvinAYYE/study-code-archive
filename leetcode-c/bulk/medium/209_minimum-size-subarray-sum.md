# LeetCode 0209. Minimum Size Subarray Sum

Title-CN: 長度最短的連續子陣列

## 題目

給定正整數 target 和只含正整數的陣列 nums，找出總和至少為 target 的連續子陣列最短長度。若不存在符合條件的子陣列，回傳 0。

## 範例

1. 輸入：target = 7，nums = [2,3,1,2,4,3]；輸出：2。最短解是 [4,3]。
2. 輸入：target = 4，nums = [1,4,4]；輸出：1。
3. 輸入：target = 11，nums = [1,1,1,1,1,1,1,1]；輸出：0。

## 限制

- 1 <= target <= 10^9
- 1 <= nums.length <= 10^5
- 1 <= nums[i] <= 10^4

## 解題思路

1. 用左右邊界維護一個連續視窗，並用 windowSum 記錄視窗總和。
2. 右邊界每次向右擴張，加入一個數；當總和已達 target，就持續移除左端數字，縮到仍符合條件的最短視窗。
3. 每次符合條件時更新最短長度。正整數保證縮小視窗只會讓總和下降，因此兩個邊界都只前進、不回頭。
4. 若最短長度從未更新，代表沒有符合條件的子陣列。

## 複雜度

時間 O(n)，額外空間 O(1)。

## C 函式簽名

int minSubArrayLen(int target, int* nums, int numsSize)

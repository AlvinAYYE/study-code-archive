# LeetCode 0398. Random Pick Index

Title-CN: 隨機挑選索引

## 題目

給定整數陣列 nums，建立物件後，pick(target) 要在所有值等於 target 的索引中等機率隨機回傳一個。target 保證存在。

## 範例

1. 輸入：nums = [1,2,3,3,3]。pick(3) 可回傳 2、3 或 4，且三個索引機率相同；pick(1) 一定回傳 0。

## 限制

- 1 <= nums.length <= 2 * 10^4
- -2^31 <= nums[i] <= 2^31 - 1
- target 一定出現在 nums
- pick 呼叫不超過 10^4 次

## 解題思路

1. 掃描整個陣列，只處理值等於 target 的位置。
2. 用水塘抽樣：看到第 k 個符合位置時，以 1/k 的機率用它取代目前答案。
3. 掃描結束後，每個符合位置都有相同機率成為最後答案，且不需要預先保存所有索引。
4. 物件保存原陣列副本和自己的亂數狀態，避免依賴全域亂數狀態。

## 複雜度

建立時間 O(n)，每次 pick 時間 O(n)，額外空間 O(n) 保存輸入副本。

## C 函式簽名

Solution* solutionCreate(int* nums, int numsSize); int solutionPick(Solution* obj, int target); void solutionFree(Solution* obj)

# LeetCode 219. Contains Duplicate II

**難度：Easy**

## 題意完整翻譯

給定整數陣列 nums 和整數 k。判斷是否存在兩個不同索引 i、j，使 nums[i] == nums[j]，而且兩個索引距離 |i - j| 不超過 k。

## 範例

1. nums = [1,2,3,1], k = 3 → true
2. nums = [1,0,1,1], k = 1 → true
3. nums = [1,2,3,1,2,3], k = 2 → false

## 限制

- 1 <= nums.length <= 10⁵
- -10⁹ <= nums[i] <= 10⁹
- 0 <= k <= 10⁵

## 解題思路

1. 建立由 (數值, 原索引) 組成的副本，不修改輸入陣列。
2. 先依數值排序；數值相同時，再依原索引排序。
3. 檢查相鄰的相同數值配對；因索引已由小到大，相鄰配對中若有距離不超過 k 的，就回傳 true。
4. 若所有配對距離都太遠，回傳 false。

## 複雜度

- 時間：O(n log n)
- 空間：O(n)（索引副本與排序堆疊）

## C 函式簽名

~~~c
bool containsNearbyDuplicate(int* nums, int numsSize, int k);
~~~

## 程式如何運作

提交函式依照上述步驟完成計算；程式註解標出每個關鍵動作。本地測試 harness 保留在 .c 檔尾端。

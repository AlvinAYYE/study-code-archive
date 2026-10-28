# LeetCode 217. Contains Duplicate

**難度：Easy**

## 題意完整翻譯

給定整數陣列 nums。若有任何數值至少出現兩次，回傳 true；若所有元素都不相同，回傳 false。

## 範例

1. nums = [1,2,3,1] → true（1 出現在索引 0 與 3）
2. nums = [1,2,3,4] → false
3. nums = [1,1,1,3,3,4,3,2,4,2] → true

## 限制

- 1 <= nums.length <= 10⁵
- -10⁹ <= nums[i] <= 10⁹

## 解題思路

1. 將 nums 由小到大排序。
2. 排序後，相同數值會相鄰。
3. 掃描相鄰元素；只要有一對相同就回傳 true，否則全部看完後回傳 false。

## 複雜度

- 時間：O(n log n)
- 空間：O(log n) 排序堆疊，排序會改動輸入陣列

## C 函式簽名

~~~c
bool containsDuplicate(int* nums, int numsSize);
~~~

## 程式如何運作

提交函式依照上述步驟完成計算；程式註解標出每個關鍵動作。本地測試 harness 保留在 .c 檔尾端。

# LeetCode 1018. Binary Prefix Divisible by 5

**難度：Easy**

## 題意完整翻譯

給定只由 0 和 1 組成的陣列 nums。對每個索引 i，取 nums[0..i] 當成由最高位到最低位排列的二進位數。回傳布林陣列 answer，其中 answer[i] 表示這個二進位前綴能否被 5 整除。

## 範例

1. nums = [0,1,1] → [true,false,false]（前綴為 0₂、01₂、011₂，也就是 0、1、3）
2. nums = [1,1,1] → [false,false,false]（前綴值為 1、3、7）

## 限制

- 1 <= nums.length <= 10⁵
- nums[i] 為 0 或 1

## 解題思路

1. 從左到右讀取位元，維護目前前綴除以 5 的餘數 rem。
2. 加入新位元 b 後，新數值等於舊數值乘 2 再加 b，所以新餘數是 (rem × 2 + b) % 5。
3. 餘數為 0 時，把該位置的答案設為 true；每一步都只保存 0 到 4 的餘數，不會讓整個二進位數溢位。

## 複雜度

- 時間：O(n)
- 空間：O(n)（回傳陣列；額外狀態 O(1)）

## C 函式簽名

~~~c
bool* prefixesDivBy5(int* nums, int numsSize, int* returnSize);
~~~

## 程式如何運作

提交函式依照上述步驟完成計算；程式中的註解對應每個關鍵動作。本地測試 harness 保留在 .c 檔尾端。

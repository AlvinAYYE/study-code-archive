-- LeetCode 1757. Recyclable and Low Fat Products／找出低脂且可回收的產品
-- 題意（繁體中文）
-- Products(product_id, low_fats, recyclable)：產品資料，product_id 唯一。low_fats 與 recyclable 都是 Y/N；
-- Y 分別表示低脂、可回收。找出同時低脂且可回收的 product_id，順序不限。
-- 範例：產品 1、3 的兩個欄位都是 Y，因此回傳 1、3；產品 0 雖低脂但不可回收，不符合。
-- 解題思路：兩個條件都必須成立，因此以 AND 同時檢查兩欄等於 Y。
-- 步驟：1. 掃描產品。2. 保留 low_fats='Y' 且 recyclable='Y' 的列。3. 輸出 id。
-- 複雜度：令 N 為產品數，時間 O(N)，額外空間 O(1)。

SELECT product_id
FROM Products
WHERE low_fats = 'Y'
  AND recyclable = 'Y';

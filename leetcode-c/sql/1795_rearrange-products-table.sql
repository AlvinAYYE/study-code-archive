-- LeetCode 1795. Rearrange Products Table／將產品商店欄位整理成資料列
-- 題意（繁體中文）
-- Products(product_id, store1, store2, store3)：每個 product_id 唯一；三個 store 欄位分別記錄產品在該商店的
-- 價格，NULL 代表該產品沒有在該店販售。將寬表轉為 product_id、store、price 三欄的長表；遇到 NULL 不輸出該店列。
-- 結果順序不限。
-- 範例：產品 0 三家商店的價格為 95、100、105，因此輸出三列；產品 1 在 store2 是 NULL，只輸出 store1 和 store3。
-- 解題思路：每個商店欄位各自投影成三欄，再用 UNION ALL 合併；WHERE 排除不存在的價格。
-- 步驟：1. 讀取 store1 的非 NULL 價格。2. 同樣處理 store2、store3。3. 合併三組列。
-- 複雜度：令 N 為產品數，時間 O(N)，輸出空間 O(最多 3N 列)。

SELECT product_id, 'store1' AS store, store1 AS price
FROM Products
WHERE store1 IS NOT NULL
UNION ALL
SELECT product_id, 'store2' AS store, store2 AS price
FROM Products
WHERE store2 IS NOT NULL
UNION ALL
SELECT product_id, 'store3' AS store, store3 AS price
FROM Products
WHERE store3 IS NOT NULL;

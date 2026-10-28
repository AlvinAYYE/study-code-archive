-- Title-CN: 購買所有產品的顧客
-- LeetCode 1045. Customers Who Bought All Products
-- 題目：找出買過 Product 表中每一種產品的顧客，回傳 customer_id，順序不限。
-- 資料表：Customer(customer_id INT, product_key INT)，資料可能重複；customer_id 不為 NULL，
--       product_key 是 Product 的外鍵。Product(product_key INT 主鍵)，每種產品只出現一次。
-- 範例：Product 有產品 5、6；Customer 記錄 (1,5)、(2,6)、(3,5)、(3,6)、(1,6)。
--       顧客 1 和 3 都買齊產品 5、6，所以輸出 customer_id 為 1、3。
-- 解法：以顧客分組，計算買過的「不同產品」數量；數量等於 Product 的總產品數，代表已買齊。
--       使用 DISTINCT 避免 Customer 的重複資料把同一產品重複計算。
-- 複雜度：掃描 Customer 和 Product 各一次並分組；約 O(C + P)，實際成本由資料庫的分組策略決定。

SELECT
    c.customer_id
FROM Customer AS c
GROUP BY c.customer_id
HAVING COUNT(DISTINCT c.product_key) = (
    SELECT COUNT(*)
    FROM Product
);

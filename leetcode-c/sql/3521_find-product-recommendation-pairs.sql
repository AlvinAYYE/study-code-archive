-- Title-CN: 找出常被同一批顧客購買的商品組合
-- LeetCode 3521. Find Product Recommendation Pairs
-- 題意：找出被至少 3 位不同顧客一起購買的商品組合。每組只列一次，且 product1_id <
--      product2_id。輸出兩個商品 ID、各自類別及不同顧客數，依顧客數遞減、兩個 ID 遞增排列。
-- 資料表：ProductPurchases(user_id INT, product_id INT, quantity INT)，(user_id, product_id)
--        是主鍵；每列代表該顧客買過該商品。ProductInfo(product_id INT 主鍵, category VARCHAR,
--        price DECIMAL)，提供商品類別及價格。本題的「一起買」看是否買過，不以 quantity 加權。
-- 範例：若商品 101 與 102 被顧客 1、2、4 都買過，兩者有 3 位共同顧客；若商品 101 與 103
--      也有 3 位共同顧客，這兩組都符合門檻。輸出含 product1_id、product2_id、類別與 3。
-- 限制：只輸出不同商品組合；至少要有 3 位不同顧客。
-- 解法：1. 將購買表依顧客自我連接，保留較小 ID 在前的商品配對。2. 每組計算不同顧客數。
--      3. HAVING 篩掉少於 3 人的配對，再分別連接商品表取得類別。
-- 複雜度：若每位顧客買 k 件商品，配對數為 ΣO(k²)；其後按商品配對分組。

WITH pair_counts AS (
    SELECT p1.product_id AS product1_id,
           p2.product_id AS product2_id,
           COUNT(DISTINCT p1.user_id) AS customer_count
    FROM ProductPurchases AS p1
    JOIN ProductPurchases AS p2
      ON p1.user_id = p2.user_id
     AND p1.product_id < p2.product_id
    GROUP BY p1.product_id, p2.product_id
    HAVING COUNT(DISTINCT p1.user_id) >= 3
)
SELECT pc.product1_id,
       pc.product2_id,
       i1.category AS product1_category,
       i2.category AS product2_category,
       pc.customer_count
FROM pair_counts AS pc
JOIN ProductInfo AS i1 ON i1.product_id = pc.product1_id
JOIN ProductInfo AS i2 ON i2.product_id = pc.product2_id
ORDER BY pc.customer_count DESC, pc.product1_id ASC, pc.product2_id ASC;

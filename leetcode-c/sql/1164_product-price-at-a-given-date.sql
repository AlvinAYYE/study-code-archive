-- Title-CN: 指定日期的產品價格
-- LeetCode 1164. Product Price at a Given Date
-- 題目：找出 2019-08-16 當天所有產品的價格，輸出 product_id 和 price。
--       若某產品在該日或之前從未調價，價格沿用初始值 10。
-- 資料表：Products(product_id INT, new_price INT, change_date DATE)。
--       (product_id, change_date) 是複合主鍵；每列表示產品在該日調整為 new_price。
-- 範例：產品 1 在 8/14、8/15、8/16 調價，當日價格是 35；產品 2 最近一次在 8/14 調價，價格是 50；
--       產品 3 首次調價在 8/18，指定日期仍沿用初始價格 10。
-- 解法：先列出所有出現過的 product_id；對每個產品找 change_date 不晚於指定日的最近一筆價格。
--       找不到這種調價紀錄時以 COALESCE 回傳 10。用 LIMIT 1 取日期最新的一筆。
-- 複雜度：P 為產品數、M 為調價列數；有 (product_id, change_date) 索引時約 O(P log M)，否則相關查詢可能較慢。

SELECT
    products.product_id,
    COALESCE(
        (
            SELECT p2.new_price
            FROM Products AS p2
            WHERE p2.product_id = products.product_id
              AND p2.change_date <= '2019-08-16'
            ORDER BY p2.change_date DESC
            LIMIT 1
        ),
        10
    ) AS price
FROM (
    SELECT DISTINCT product_id
    FROM Products
) AS products;

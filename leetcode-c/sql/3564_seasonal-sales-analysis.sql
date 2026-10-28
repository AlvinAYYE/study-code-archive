-- Title-CN: 各季銷售最佳商品類別
-- LeetCode 3564. Seasonal Sales Analysis
-- 題意：依銷售日期將資料分季，對每季每個商品類別加總銷售數量與營收（quantity * price），
--      找出每季最佳類別。季節月份：Winter=12、1、2；Spring=3、4、5；Summer=6、7、8；
--      Fall=9、10、11。依總數量最多、總營收最高、類別名稱字典序最小依序決定勝者。
--      輸出 season、category、total_quantity、total_revenue，season 以字母順序排列。
-- 資料表：sales(sale_id INT 主鍵, product_id INT, sale_date DATE, quantity INT, price DECIMAL)；
--        products(product_id INT 主鍵, product_name VARCHAR, category VARCHAR)。
-- 範例：若春季 Kitchen 賣出 5 件、營收 50，而 Tech 賣出 4 件、營收 80，春季仍選 Kitchen；
--      數量先比較，只有數量相同才比較營收，兩者相同才比較類別名稱。
-- 限制：只會輸出有銷售紀錄的季節；每季至多一個類別。
-- 解法：1. 用 MONTH() 將銷售歸入季節，依季節及類別彙總數量、營收。2. 用 ROW_NUMBER() 在
--      每季內依三層規則排名。3. 取排名 1 的類別並排序。
-- 複雜度：N 筆銷售彙總與排序，時間約 O(N log N)，分組及排名空間 O(N)。

WITH seasonal_totals AS (
    SELECT CASE
               WHEN MONTH(s.sale_date) IN (12, 1, 2) THEN 'Winter'
               WHEN MONTH(s.sale_date) IN (3, 4, 5) THEN 'Spring'
               WHEN MONTH(s.sale_date) IN (6, 7, 8) THEN 'Summer'
               ELSE 'Fall'
           END AS season,
           p.category,
           SUM(s.quantity) AS total_quantity,
           SUM(s.quantity * s.price) AS total_revenue
    FROM sales AS s
    JOIN products AS p ON p.product_id = s.product_id
    GROUP BY season, p.category
), ranked AS (
    SELECT season, category, total_quantity, total_revenue,
           ROW_NUMBER() OVER (
               PARTITION BY season
               ORDER BY total_quantity DESC, total_revenue DESC, category ASC
           ) AS season_rank
    FROM seasonal_totals
)
SELECT season, category, total_quantity, total_revenue
FROM ranked
WHERE season_rank = 1
ORDER BY season ASC;

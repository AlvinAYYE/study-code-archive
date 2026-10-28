-- Title-CN: 產品銷售分析 III
-- LeetCode 1070. Product Sales Analysis III
-- 題目：找出每種產品在首次銷售年份發生的所有銷售紀錄，輸出 product_id、first_year、quantity、price，順序不限。
-- 資料表：Sales(sale_id INT, product_id INT, year INT, quantity INT, price INT)。
--       (sale_id, year) 是複合主鍵；product_id 參照產品。相同產品同一年可以有多筆銷售，price 是單件價格。
-- 範例：Sales 有 (100,2008,10,5000)、(100,2009,12,5000)、(200,2011,15,9000)
--       （此處括號內依序是 product_id、year、quantity、price），結果為
--       (100,2008,10,5000)、(200,2011,15,9000)。若產品首年有多筆，必須全部回傳。
-- 解法：先依 product_id 分組求 MIN(year)，再和 Sales 連接，保留年份等於首年年份的紀錄。
--       這樣能取回首年銷售的 quantity 與 price，也不會把同年其他銷售漏掉。
-- 複雜度：N 為銷售列數；聚合並連接各掃描一次，約 O(N)，額外工作空間由資料庫執行計畫決定。

SELECT
    s.product_id,
    first_sale.first_year,
    s.quantity,
    s.price
FROM Sales AS s
JOIN (
    SELECT product_id, MIN(year) AS first_year
    FROM Sales
    GROUP BY product_id
) AS first_sale
    ON first_sale.product_id = s.product_id
   AND first_sale.first_year = s.year;

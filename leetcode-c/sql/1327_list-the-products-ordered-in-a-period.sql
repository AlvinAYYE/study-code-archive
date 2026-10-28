-- LeetCode 1327. List the Products Ordered in a Period
-- Title-CN: 列出指定期間訂購的產品
--
-- 題目（繁體中文）
-- Products(product_id, product_name, product_category)：產品資料，product_id 是主鍵。
-- Orders(product_id, order_date, unit)：訂單明細，記錄產品於日期的訂購數量；
--   同一產品可能有多筆訂單。
-- 找出 2020 年 2 月訂購總數至少 100 件的產品，輸出 product_name 與總件數 unit，順序不限。
--
-- 範例：Leetcode Solutions 在 2 月訂購 60+70=130 件，列入結果；Leetcode Kit
--   訂購 50+50=100 件，也列入；Jewels of Stringology 只有 80 件，不列入。
--
-- 思路：先以日期範圍篩選二月訂單，按 product_id 加總 unit，再連接產品名稱，
--   以 HAVING 篩掉總數少於 100 的產品。
-- 複雜度：掃描訂單 O(O)，篩選、分組並連接產品；實際連接成本依索引與執行計畫而定。
-- 題目：https://leetcode.com/problems/list-the-products-ordered-in-a-period/

SELECT
    p.product_name,
    SUM(o.unit) AS unit
FROM Orders AS o
JOIN Products AS p ON p.product_id = o.product_id
WHERE o.order_date >= '2020-02-01'
  AND o.order_date < '2020-03-01'
GROUP BY p.product_id, p.product_name
HAVING SUM(o.unit) >= 100;

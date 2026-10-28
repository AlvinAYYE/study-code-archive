-- LeetCode 1251. Average Selling Price
-- Title-CN: 平均銷售價格
--
-- 題目（繁體中文）
-- Prices(product_id, start_date, end_date, price)：記錄產品在一段日期內的單價，
--   (product_id, start_date, end_date) 是複合主鍵；同一產品的價格期間不重疊。
-- UnitsSold(product_id, purchase_date, units)：記錄某日售出數量，資料列可能重複。
-- 對每個產品計算加權平均售價：各筆銷售的「單價 × 件數」總和除以售出件數，
-- 四捨五入到小數點後兩位。從未售出的產品平均價回傳 0。結果順序不限。
--
-- 範例：產品 1 在 2019-02-17 至 02-28 的價格是 5，03-01 至 03-22 是 20；
--   售出 100 件與 15 件，平均價 = (100×5 + 15×20) / 115 = 6.96。
--   產品 2 的兩筆價格分別是 15、30，售出 200、30 件，平均價是 16.96。
--
-- 思路：以 Prices 為主表，依產品及購買日期連接適用價格期間的銷售；
--   SUM(price * units) / SUM(units) 算加權平均，COALESCE 將沒有銷售的 NULL 改成 0。
-- 複雜度：概念上掃描價格與銷售資料各一次，連接及分組成本依索引與資料庫執行計畫而定。
-- 題目：https://leetcode.com/problems/average-selling-price/

SELECT
    p.product_id,
    COALESCE(
        ROUND(1.0 * SUM(p.price * u.units) / NULLIF(SUM(u.units), 0), 2),
        0
    ) AS average_price
FROM Prices AS p
LEFT JOIN UnitsSold AS u
    ON u.product_id = p.product_id
   AND u.purchase_date BETWEEN p.start_date AND p.end_date
GROUP BY p.product_id;

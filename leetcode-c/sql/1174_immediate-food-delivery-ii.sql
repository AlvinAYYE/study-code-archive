-- Title-CN: 立即送達 II
-- LeetCode 1174. Immediate Food Delivery II
-- 題目：對每位顧客只看最早下單的那筆訂單，計算其中「下單日等於顧客希望送達日」的比例，
--       並以百分比表示、四捨五入到小數點後兩位。每位顧客保證恰有一筆最早訂單。
-- 資料表：Delivery(delivery_id INT 主鍵, customer_id INT, order_date DATE,
--       customer_pref_delivery_date DATE)。希望送達日不早於下單日。
-- 範例：顧客 1 首單為預約配送；顧客 2 首單立即送達；顧客 3 首單為預約配送；顧客 4 首單立即送達。
--       4 位顧客中 2 位立即送達，因此輸出 50.00。
-- 解法：先依 customer_id 求最早 order_date，再連回 Delivery 找到每位顧客的首單；
--       對首單中立即送達的筆數除以首單總筆數，乘 100 並四捨五入至兩位小數。
-- 複雜度：D 為訂單數；分組與連接約 O(D)，資料庫可能需額外排序/暫存。

WITH first_orders AS (
    SELECT customer_id, MIN(order_date) AS first_order_date
    FROM Delivery
    GROUP BY customer_id
)
SELECT
    ROUND(
        100.0 * SUM(
            CASE
                WHEN d.order_date = d.customer_pref_delivery_date THEN 1
                ELSE 0
            END
        ) / COUNT(*),
        2
    ) AS immediate_percentage
FROM Delivery AS d
JOIN first_orders AS f
    ON f.customer_id = d.customer_id
   AND f.first_order_date = d.order_date;

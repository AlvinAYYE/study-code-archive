-- LeetCode 1321. Restaurant Growth
-- Title-CN: 餐廳營業額成長
--
-- 題目（繁體中文）
-- Customer(customer_id, name, visited_on, amount)：記錄顧客每日消費；
--   (customer_id, visited_on) 是主鍵，且資料涵蓋期間內每天至少有一筆消費。
-- 對每個可形成完整七日區間的日期，輸出該日往前含當日共七天的消費總額 amount，
-- 以及七日平均 average_amount（四捨五入至小數點後兩位）。依 visited_on 遞增排序。
--
-- 範例：2019-01-07 的七日總額為 100+110+120+130+110+140+150 = 860，
--   平均為 860/7 = 122.86；2019-01-08 的視窗往後移一天，總額是 840，平均 120。
--
-- 思路：先把同一天多位顧客的金額加總成每日一列，再用視窗函式計算當日與前六列的
--   七日總額和列數。只有列數達七的日期才輸出，表示已累積完整一週。
-- 複雜度：彙整 R 筆交易並按日期排序 D 個日期，概念成本 O(R + D log D)。
-- 題目：https://leetcode.com/problems/restaurant-growth/

WITH DailyAmount AS (
    SELECT visited_on, SUM(amount) AS amount
    FROM Customer
    GROUP BY visited_on
),
SevenDayWindow AS (
    SELECT
        visited_on,
        SUM(amount) OVER (
            ORDER BY visited_on
            ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
        ) AS amount,
        COUNT(*) OVER (
            ORDER BY visited_on
            ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
        ) AS days_in_window
    FROM DailyAmount
)
SELECT
    visited_on,
    amount,
    ROUND(amount / 7.0, 2) AS average_amount
FROM SevenDayWindow
WHERE days_in_window = 7
ORDER BY visited_on;

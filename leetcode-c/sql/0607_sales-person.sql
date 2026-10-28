-- LeetCode 607. Sales Person／銷售人員
-- 題目（繁體中文）
-- SalesPerson(sales_id, name, salary, commission_rate, hire_date) 記錄業務；
-- Company(com_id, name, city) 記錄公司；Orders(order_id, order_date, com_id,
-- sales_id, amount) 記錄訂單。三表各自的 id 是主鍵，Orders 的 com_id 與
-- sales_id 分別參照 Company 與 SalesPerson。
-- 找出從未有任何訂單與名稱為 "RED" 的公司相關的業務，輸出 name，順序不限。
--
-- 範例
-- John 與 Pam 都曾經接到 RED 的訂單，因此排除；Amy、Mark 沒有訂單，Alex
-- 只有 GREEN 的訂單，三人都沒有 RED 訂單，因此輸出 Amy、Mark、Alex。
--
-- 限制與輸出規則
-- 結果只輸出 name。判斷的是「是否曾有 RED 訂單」：業務即使也替其他公司
-- 成交，只要存在一筆 RED 訂單就必須排除；完全沒有訂單的業務應保留。
--
-- 分步思路
-- 1. 對每位業務，用相關子查詢連接 Orders 與 Company。
-- 2. 子查詢尋找 sales_id 相同且 Company.name = 'RED' 的任一訂單。
-- 3. NOT EXISTS 只保留找不到這類訂單的業務，也自然包含完全沒有訂單的人。
-- 題目：https://leetcode.com/problems/sales-person/

SELECT salesperson.name
FROM SalesPerson AS salesperson
WHERE NOT EXISTS (
    SELECT 1
    FROM Orders AS orders
    JOIN Company AS company
      ON company.com_id = orders.com_id
    WHERE orders.sales_id = salesperson.sales_id
      AND company.name = 'RED'
);

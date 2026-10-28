-- LeetCode 586. Customer Placing the Largest Number of Orders／訂單數最多的客戶
-- 題目：https://leetcode.com/problems/customer-placing-the-largest-number-of-orders/
--
-- 題目（繁體中文）
-- Orders 表：
--   order_number    INT  主鍵，訂單的唯一編號
--   customer_number INT  下單客戶的編號
--
-- 找出下單數量最多的客戶，輸出 customer_number。測試資料保證只有一名客戶
-- 的訂單數嚴格最多，因此結果只有一列。
--
-- 範例
-- 輸入：
--   order_number | customer_number
--              1 | 1
--              2 | 2
--              3 | 3
--              4 | 3
-- 客戶 3 有 2 筆訂單，客戶 1、2 各 1 筆，因此輸出 customer_number = 3。
--
-- 限制與資料規則
--   1. order_number 是主鍵，每筆訂單只出現一次。
--   2. 題目保證訂單數最多者唯一，不需處理並列第一。
--   3. 延伸問題若允許並列，則需改用排名或與最大計數比較，不能只用 LIMIT 1。
--
-- 直觀解題思路
--   1. 依 customer_number 分組，每組列數就是該客戶的訂單數。
--   2. 按 COUNT(*) 由大到小排序，最多訂單者會排在第一列。
--   3. 題目保證唯一最大值，因此 LIMIT 1 即可回傳唯一答案。

SELECT customer_number
FROM Orders
GROUP BY customer_number
ORDER BY COUNT(*) DESC
LIMIT 1;

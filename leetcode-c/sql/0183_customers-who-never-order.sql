-- LeetCode 183. Customers Who Never Order／從未下單的顧客
-- 題目（繁體中文）
-- Customers(id, name) 記錄顧客；Orders(id, customerId) 記錄訂單；
-- 兩表的 id 均為主鍵，Orders.customerId 指向 Customers.id。
-- 找出完全沒有下過訂單的顧客姓名，欄名 Customers，順序不限。
-- 例子：Joe(id=1)、Henry(id=2)、Sam(id=3)、Max(id=4)，訂單只屬於
-- id=1 與 id=3 → 輸出 Henry、Max。
-- 思路：以顧客為左表做 LEFT JOIN，保留所有顧客；沒有訂單的人在
-- 訂單欄位得到 NULL，因此以 o.id IS NULL 篩選。
-- 題目：https://leetcode.com/problems/customers-who-never-order/

SELECT c.name AS Customers
FROM Customers AS c
LEFT JOIN Orders AS o ON o.customerId = c.id
WHERE o.id IS NULL;

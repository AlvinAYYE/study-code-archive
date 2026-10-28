-- LeetCode 584. Find Customer Referee／尋找客戶推薦人
-- 題目（繁體中文）
-- Customer(id, name, referee_id) 記錄客戶及推薦人；id 是主鍵，referee_id 是
-- 推薦該客戶的另一位客戶 id，也可能是 NULL，表示沒有人推薦。
-- 找出推薦人不是 id=2，或沒有推薦人的客戶姓名，輸出欄名 name，順序不限。
--
-- 範例
-- Will(NULL)、Jane(NULL)、Alex(2)、Bill(NULL)、Zack(1)、Mark(2) 中，
-- Alex 與 Mark 由 id=2 推薦，必須排除；輸出 Will、Jane、Bill、Zack。
--
-- 限制與輸出規則
-- Customer.id 是主鍵。結果只輸出 name；referee_id = NULL 的客戶必須保留。
-- SQL 中 NULL 與 2 使用 <> 比較不會得到 TRUE，因此不能只寫 referee_id <> 2。
--
-- 分步思路
-- 1. referee_id <> 2 保留由其他客戶推薦的人。
-- 2. referee_id IS NULL 另外保留沒有推薦人的客戶。
-- 3. 兩個條件用 OR 合併，再只選取 name。
-- 題目：https://leetcode.com/problems/find-customer-referee/

SELECT name
FROM Customer
WHERE referee_id <> 2
   OR referee_id IS NULL;

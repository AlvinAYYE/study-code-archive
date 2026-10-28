-- LeetCode 1693. Daily Leads and Partners／每日線索與合作夥伴統計
-- 題意（繁體中文）
-- DailySales(date_id, make_name, lead_id, partner_id)：每天各品牌的銷售線索與合作夥伴紀錄。此表沒有唯一鍵，
-- 因此可能有重複資料。對每一個日期及品牌組合，分別計算不同 lead_id 數量與不同 partner_id 數量；輸出
-- date_id、make_name、unique_leads、unique_partners，順序不限。
-- 範例：2020-12-8 的 toyota 線索 id 為 0、1，合作夥伴 id 為 0、1、2，因此輸出 2 和 3；重複的 id 只算一次。
-- 解題思路：依 date_id 與 make_name 分組，兩個識別欄位分別使用 COUNT(DISTINCT ...) 去重計數。
-- 步驟：1. 把同一天同品牌的列放在一組。2. 分別統計不重複線索及合作夥伴。3. 輸出四個欄位。
-- 複雜度：令 N 為紀錄數、G 為日期品牌組合數，時間 O(N)，分組與去重空間 O(N)。

SELECT date_id,
       make_name,
       COUNT(DISTINCT lead_id) AS unique_leads,
       COUNT(DISTINCT partner_id) AS unique_partners
FROM DailySales
GROUP BY date_id, make_name;

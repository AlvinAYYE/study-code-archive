-- LeetCode 1484. Group Sold Products By The Date
-- Title-CN: 依日期彙整銷售產品
--
-- 題目（繁體中文）
-- Activities(sell_date, product)：每列記錄某日賣出一種產品；表中可能有重複列。
-- 對每個日期輸出不同產品數 num_sold，以及按字典序排列、用逗號連接的產品名稱 products。
-- 依 sell_date 遞增排序。
--
-- 範例：2020-05-30 賣出 Headphone、Basketball、T-shirt，結果為
--   num_sold=3、products="Basketball,Headphone,T-shirt"。同日重複賣出的 Mask 只算一種。
--
-- 思路：以 sell_date 分組，COUNT(DISTINCT product) 計算不同產品數；
--   GROUP_CONCAT(DISTINCT ... ORDER BY ... SEPARATOR ',') 去重、排序並連成字串。
-- 複雜度：掃描 A 筆活動資料，並在每個日期內去重及排序產品；排序成本依各日產品數而定。
-- 注意：SQLite 的 group_concat 語法不同，SQLite 等價測試請在分組前去重與排序。
-- 題目：https://leetcode.com/problems/group-sold-products-by-the-date/

SELECT
    sell_date,
    COUNT(DISTINCT product) AS num_sold,
    GROUP_CONCAT(DISTINCT product ORDER BY product SEPARATOR ',') AS products
FROM Activities
GROUP BY sell_date
ORDER BY sell_date;

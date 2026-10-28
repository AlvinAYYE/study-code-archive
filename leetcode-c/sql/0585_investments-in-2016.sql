-- LeetCode 585. Investments in 2016／2016 年的投資
-- 題目：https://leetcode.com/problems/investments-in-2016/
--
-- 題目（繁體中文）
-- Insurance 表：
--   pid      INT    主鍵，保單持有人的保單編號
--   tiv_2015 FLOAT  2015 年總投資額
--   tiv_2016 FLOAT  2016 年總投資額
--   lat      FLOAT  所在城市緯度，保證不為 NULL
--   lon      FLOAT  所在城市經度，保證不為 NULL
--
-- 加總同時符合以下兩項條件之保單持有人的 tiv_2016：
--   1. tiv_2015 與至少另一名保單持有人相同。
--   2. (lat, lon) 組合在全表唯一，也就是所在地沒有其他保單持有人。
-- 將總和四捨五入到小數點後兩位，輸出欄名 tiv_2016。
--
-- 範例
-- 輸入四列：
--   pid | tiv_2015 | tiv_2016 | lat | lon
--     1 |       10 |        5 |  10 |  10
--     2 |       20 |       20 |  20 |  20
--     3 |       10 |       30 |  20 |  20
--     4 |       10 |       40 |  40 |  40
-- pid 1、4 的 tiv_2015 都有重複且位置唯一，因此輸出 5 + 40 = 45.00。
-- pid 2 的 2015 投資額不重複；pid 2、3 又共用位置，兩者都不合格。
--
-- 限制與資料規則
--   1. pid 是主鍵。
--   2. lat、lon 都不為 NULL，城市必須以兩欄組合一起判斷。
--   3. 兩項條件必須同時成立，最後才加總 tiv_2016。
--
-- 直觀解題思路
--   1. 第一個子查詢按 tiv_2015 分組，留下出現至少兩次的投資額。
--   2. 第二個子查詢按 (lat, lon) 分組，只留下出現一次的位置。
--   3. 主查詢保留同時落在兩個集合的保單，再加總 tiv_2016 並取兩位小數。

SELECT ROUND(SUM(tiv_2016), 2) AS tiv_2016
FROM Insurance
WHERE tiv_2015 IN (
    SELECT tiv_2015
    FROM Insurance
    GROUP BY tiv_2015
    HAVING COUNT(*) >= 2
)
AND (lat, lon) IN (
    SELECT lat, lon
    FROM Insurance
    GROUP BY lat, lon
    HAVING COUNT(*) = 1
);

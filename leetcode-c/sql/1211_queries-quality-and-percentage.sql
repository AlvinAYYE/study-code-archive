-- Title-CN: 查詢品質與不良比例
-- LeetCode 1211. Queries Quality and Percentage
-- 題目：按 query_name 分組計算兩個指標，並都四捨五入至小數點後兩位：
--       quality = 每列 rating / position 的平均值；poor_query_percentage = rating 小於 3 的列數占該組總列數的百分比。
--       回傳 query_name、quality、poor_query_percentage，順序不限。
-- 資料表：Queries(query_name VARCHAR, result VARCHAR, position INT, rating INT)。可能有重複列；
--       position 介於 1 到 500，rating 介於 1 到 5；rating < 3 表示不良查詢。
-- 範例：Dog 的 (rating,position) 為 (5,1)、(5,2)、(1,200)，quality=(5/1+5/2+1/200)/3=2.50，
--       不良比例為 1/3*100=33.33。Cat 的 quality 為 0.66，不良比例同樣是 33.33。
-- 解法：先按 query_name 分組；AVG(1.0 * rating / position) 計算品質並保留小數除法，
--       CASE 將不良列標成 1，再用總和除以總筆數並乘 100 算百分比。
-- 複雜度：N 為 Queries 列數；掃描與分組一次，約 O(N)，分組成本依資料庫執行計畫而異。

SELECT
    query_name,
    ROUND(AVG(1.0 * rating / position), 2) AS quality,
    ROUND(
        100.0 * SUM(CASE WHEN rating < 3 THEN 1 ELSE 0 END) / COUNT(*),
        2
    ) AS poor_query_percentage
FROM Queries
GROUP BY query_name;

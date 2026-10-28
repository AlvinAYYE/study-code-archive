-- Title-CN: 每月交易 I
-- LeetCode 1193. Monthly Transactions I
-- 題目：依交易月份和國家分組，回傳交易總筆數、已核准筆數、交易總金額、已核准交易總金額。
--       月份輸出格式為 YYYY-MM；結果順序不限。
-- 資料表：Transactions(id INT 主鍵, country VARCHAR 可為 NULL, state ENUM('approved','declined'),
--       amount INT, trans_date DATE)。
-- 範例：2018-12 的 US 有一筆核准 1000 和一筆拒絕 2000，輸出筆數 2、核准筆數 1、
--       總額 3000、核准總額 1000。2019-01 的 US、DE 各有一筆核准 2000。
-- 解法：用 DATE_FORMAT 將日期轉成 YYYY-MM，再以月份和 country 分組；COUNT 統計全部交易，
--       CASE 條件加總核准筆數與金額。
-- 複雜度：N 為交易數；掃描並分組一次，約 O(N)，分組排序成本依資料庫執行計畫而異。
-- SQLite 測試備註：MySQL 的 DATE_FORMAT(trans_date, '%Y-%m') 在 SQLite 沒有同名函式；
--       可用 strftime('%Y-%m', trans_date) 做等價日期格式化，其餘查詢邏輯相同。

SELECT
    DATE_FORMAT(trans_date, '%Y-%m') AS month,
    country,
    COUNT(*) AS trans_count,
    SUM(CASE WHEN state = 'approved' THEN 1 ELSE 0 END) AS approved_count,
    SUM(amount) AS trans_total_amount,
    SUM(CASE WHEN state = 'approved' THEN amount ELSE 0 END) AS approved_total_amount
FROM Transactions
GROUP BY DATE_FORMAT(trans_date, '%Y-%m'), country;

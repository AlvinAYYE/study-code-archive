-- LeetCode 626. Exchange Seats／交換座位
-- 題目：https://leetcode.com/problems/exchange-seats/
--
-- 題目（繁體中文）
-- Seat 表：
--   id      INT      主鍵，座位編號
--   student VARCHAR  學生姓名
-- id 一定從 1 開始連續遞增。
--
-- 每兩名相鄰學生交換座位編號：1 與 2、3 與 4，依此類推。若學生總數為奇數，
-- 最後一名學生沒有配對，座位編號維持不變。輸出 id、student，並按 id 升冪排序。
--
-- 範例
-- 輸入座位依序為 1 Abbot、2 Doris、3 Emerson、4 Green、5 Jeames。
-- 交換後輸出 1 Doris、2 Abbot、3 Green、4 Emerson、5 Jeames；最後一人不變。
--
-- 限制與資料規則
--   1. id 是主鍵，且恰為從 1 開始的連續整數。
--   2. 奇數 id 一般換成 id + 1，偶數 id 換成 id - 1。
--   3. 若最大 id 為奇數，該列是未配對的最後一人，必須保留原 id。
--   4. 輸出必須依交換後的 id 升冪排序。
--
-- 直觀解題思路
--   1. CASE 先辨認「奇數且為最大 id」的尾列，讓它保持原位。
--   2. 其餘奇數 id 加 1，偶數 id 減 1，即完成每組相鄰交換。
--   3. 將新編號命名為 id，最後 ORDER BY id 依新座位順序輸出。

SELECT
    CASE
        WHEN MOD(id, 2) = 1 AND id = (SELECT MAX(id) FROM Seat) THEN id
        WHEN MOD(id, 2) = 1 THEN id + 1
        ELSE id - 1
    END AS id,
    student
FROM Seat
ORDER BY id;

-- LeetCode 601. Human Traffic of Stadium／體育館的人流量
-- 題目：https://leetcode.com/problems/human-traffic-of-stadium/
--
-- 題目（繁體中文）
-- Stadium 表：
--   id         INT   造訪編號
--   visit_date DATE  造訪日期，欄位值唯一
--   people     INT   當次造訪人數
-- 隨 id 增加，visit_date 也會增加。
--
-- 找出所有屬於「至少 3 個連續 id，且每列 people >= 100」區段的資料列，
-- 輸出 id、visit_date、people，並按 visit_date 升冪排序。
-- 連續條件看 id；日期中間即使跳日，只要 id 連續仍屬同一區段。
--
-- 範例
-- id 2、3 雖都至少 100 人，但只有兩個連續 id，所以不輸出。
-- id 5、6、7、8 連續且人數分別為 145、1455、199、188，全部輸出。
-- 即使 id 7 的日期是 2017-01-07、id 8 是 2017-01-09，仍因 id 連續而合格。
--
-- 限制與資料規則
--   1. visit_date 唯一，而且日期順序與 id 遞增方向一致。
--   2. 每列都必須 people >= 100；低於 100 的列會切斷連續區段。
--   3. 合格區段長度可以大於 3，區段中的每一列都要輸出一次。
--   4. 最終結果必須依 visit_date 升冪排序。
--
-- 直觀解題思路
--   1. HighTraffic 先移除 people < 100 的列。
--   2. 對剩餘列按 id 編號；連續 id 的 id - ROW_NUMBER() 會維持相同，
--      因而可把每段連續區間標成同一 island_key。
--   3. Qualified 找出列數至少為 3 的 island_key。
--   4. 回到 HighTraffic 取出所有合格區段資料，按 visit_date 排序。

WITH HighTraffic AS (
    SELECT
        id,
        visit_date,
        people,
        id - ROW_NUMBER() OVER (ORDER BY id) AS island_key
    FROM Stadium
    WHERE people >= 100
),
Qualified AS (
    SELECT island_key
    FROM HighTraffic
    GROUP BY island_key
    HAVING COUNT(*) >= 3
)
SELECT id, visit_date, people
FROM HighTraffic
WHERE island_key IN (SELECT island_key FROM Qualified)
ORDER BY visit_date;

-- LeetCode 550. Game Play Analysis IV／遊戲玩法分析 IV
-- 題目：https://leetcode.com/problems/game-play-analysis-iv/
--
-- 題目（繁體中文）
-- Activity 表：
--   player_id    INT   玩家 id
--   device_id    INT   使用的裝置 id
--   event_date   DATE  登入日期
--   games_played INT   該次登出前玩的局數，可能為 0
-- (player_id, event_date) 是複合主鍵。
--
-- 計算所有玩家中，有多少比例在「首次登入的隔天」再次登入。結果四捨五入到
-- 小數點後兩位，只輸出一列一欄，欄名為 fraction。
--
-- 範例
-- 玩家 1 首次於 2016-03-01 登入，且 2016-03-02 再次登入；玩家 2 與玩家 3
-- 都沒有在各自首次登入的隔天回來。符合者 1 人、總玩家 3 人，
-- fraction = ROUND(1 / 3, 2) = 0.33。
--
-- 限制與資料規則
--   1. (player_id, event_date) 為主鍵，同一玩家同一天最多一筆記錄。
--   2. 分母是不同玩家總數，每位玩家只計一次。
--   3. 必須檢查首次登入「恰好隔一天」，之後其他日期登入不算。
--   4. games_played 是否為 0 不影響登入紀錄的判定。
--
-- 直觀解題思路
--   1. FirstLogin 先按 player_id 分組，取得每位玩家的最早 event_date。
--   2. 左連接該玩家首次登入隔天的 Activity；有配對代表符合條件。
--   3. CASE 將符合者記為 1、其餘記為 0，AVG 就是符合玩家比例。
--   4. ROUND(..., 2) 產生題目要求的 fraction。

WITH FirstLogin AS (
    SELECT player_id, MIN(event_date) AS first_login
    FROM Activity
    GROUP BY player_id
)
SELECT ROUND(
           AVG(CASE WHEN next_day.player_id IS NOT NULL THEN 1 ELSE 0 END),
           2
       ) AS fraction
FROM FirstLogin AS first_day
LEFT JOIN Activity AS next_day
  ON next_day.player_id = first_day.player_id
 AND next_day.event_date = DATE_ADD(first_day.first_login, INTERVAL 1 DAY);

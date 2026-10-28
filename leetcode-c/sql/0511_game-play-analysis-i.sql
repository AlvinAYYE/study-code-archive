-- LeetCode 511. Game Play Analysis I／遊戲玩法分析 I
-- 題目：https://leetcode.com/problems/game-play-analysis-i/
--
-- 題目（繁體中文）
-- Activity 表：
--   player_id    INT   玩家 id
--   device_id    INT   使用的裝置 id
--   event_date   DATE  登入日期
--   games_played INT   該次登出前玩的局數，可能為 0
-- (player_id, event_date) 是複合主鍵，因此同一玩家同一天最多一筆記錄。
--
-- 找出每位玩家第一次登入的日期。輸出 player_id 與 first_login，順序不限。
--
-- 範例
-- 輸入 Activity 摘要：
--   玩家 1 在 2016-03-01、2016-05-02 登入；
--   玩家 2 在 2017-06-25 登入；
--   玩家 3 在 2016-03-02、2018-07-03 登入。
-- 輸出：
--   player_id | first_login
--           1 | 2016-03-01
--           2 | 2017-06-25
--           3 | 2016-03-02
--
-- 限制與資料規則
--   1. (player_id, event_date) 為主鍵，不會有重複的玩家日期組合。
--   2. games_played 可以是 0，但仍代表玩家當天曾登入，不影響首次登入判定。
--   3. 裝置可能更換；本題只比較同一玩家的日期。
--
-- 直觀解題思路
--   1. 依 player_id 將同一玩家的所有活動分成一組。
--   2. 每組最早的 event_date 就是首次登入日期，以 MIN 取得。
--   3. 將聚合欄位命名為題目要求的 first_login。

SELECT player_id, MIN(event_date) AS first_login
FROM Activity
GROUP BY player_id;

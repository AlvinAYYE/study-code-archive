-- LeetCode 602. Friend Requests II: Who Has the Most Friends／好友最多的人
-- 題目：https://leetcode.com/problems/friend-requests-ii-who-has-the-most-friends/
--
-- 題目（繁體中文）
-- RequestAccepted 表：
--   requester_id INT   發出好友邀請者的 id
--   accepter_id  INT   接受好友邀請者的 id
--   accept_date  DATE  接受日期
-- (requester_id, accepter_id) 是複合主鍵。每列代表一個已成立的好友關係。
--
-- 找出好友數最多的人與其好友數，輸出欄名 id、num。測試資料保證只有一人
-- 擁有最多好友，因此結果只有一列。
--
-- 範例
-- 已接受的關係為 (1,2)、(1,3)、(2,3)、(3,4)。使用者 3 分別與 1、2、4
-- 是好友，共有 3 名好友，為全表最多，因此輸出 id = 3、num = 3。
--
-- 限制與資料規則
--   1. (requester_id, accepter_id) 是主鍵，不會有相同方向的重複邀請紀錄。
--   2. 好友關係成立後是雙向的；提出者與接受者都要各增加一名好友。
--   3. 題目保證最大好友數只有一人；延伸問題才需要處理多人並列。
--
-- 直觀解題思路
--   1. Friends 用 UNION ALL 把 requester_id 與 accepter_id 疊成同一欄 id。
--   2. 每段好友關係會貢獻兩列，剛好讓雙方各被計數一次；不能用 UNION 去重。
--   3. 依 id 分組計數，按好友數由大到小排序，取唯一第一名。

WITH Friends AS (
    SELECT requester_id AS id
    FROM RequestAccepted
    UNION ALL
    SELECT accepter_id AS id
    FROM RequestAccepted
)
SELECT id, COUNT(*) AS num
FROM Friends
GROUP BY id
ORDER BY num DESC
LIMIT 1;

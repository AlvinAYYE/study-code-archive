-- Title-CN: 最後一位能上公車的人
-- LeetCode 1204. Last Person to Fit in the Bus
-- 題目：Queue 表列出依 turn 順序上車的人。公車總載重不能超過 1000 公斤，
--       找出依序上車後仍能在載重限制內的最後一位乘客姓名。題目保證第一位乘客可上車。
-- 資料表：Queue(person_id INT 唯一, person_name VARCHAR, weight INT, turn INT)。
--       turn 是 1 到 n 的連續順序；weight 是公斤。
-- 範例：依序 Alice 250、Alex 350、John Cena 400，累積剛好 1000；下一位 Marie 會使總重達 1200。
--       因此回傳 person_name = 'John Cena'。
-- 解法：用視窗函式依 turn 計算從第一位到目前為止的累積重量；只保留累積不超過 1000 的人，
--       再按 turn 由大到小取第一位。
-- 複雜度：N 為排隊人數；依 turn 排序約 O(N log N)，視窗計算線性 O(N)。

WITH weighted_queue AS (
    SELECT
        person_name,
        turn,
        SUM(weight) OVER (
            ORDER BY turn
            ROWS BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW
        ) AS total_weight
    FROM Queue
)
SELECT person_name
FROM weighted_queue
WHERE total_weight <= 1000
ORDER BY turn DESC
LIMIT 1;

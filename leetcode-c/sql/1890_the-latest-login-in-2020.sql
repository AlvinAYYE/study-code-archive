-- LeetCode 1890. The Latest Login in 2020／找出每位使用者在 2020 年的最後登入
-- 題意（繁體中文）
-- Logins(user_id, time_stamp)：使用者登入紀錄，(user_id, time_stamp) 組合唯一。找出每位曾在 2020 年登入的使用者，
-- 只回傳該使用者在 2020 年內最晚的登入時間；未在 2020 年登入的人不可出現在結果。輸出 user_id、last_stamp，順序不限。
-- 範例：使用者 6 在 2020 年只有 6 月 30 日登入；使用者 8 在 2 月與 12 月登入，因此取 12 月 30 日；使用者 14
-- 只有 2019、2021 的紀錄，排除。
-- 解題思路：先把登入時間限制在 2020 年，再按 user_id 分組取 MAX。
-- 步驟：1. 篩選時間 >= 2020-01-01 且 < 2021-01-01。2. 每位使用者取最大時間。3. 將結果欄命名為 last_stamp。
-- 複雜度：令 N 為登入紀錄數、U 為該年登入使用者數，時間 O(N)，分組空間 O(U)。

SELECT user_id,
       MAX(time_stamp) AS last_stamp
FROM Logins
WHERE time_stamp >= '2020-01-01 00:00:00'
  AND time_stamp < '2021-01-01 00:00:00'
GROUP BY user_id;

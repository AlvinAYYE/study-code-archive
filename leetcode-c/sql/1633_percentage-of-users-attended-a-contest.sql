-- LeetCode 1633. Percentage of Users Attended a Contest／各競賽的使用者報名百分比
-- 題意（繁體中文）
-- Users(user_id, user_name)：使用者資料，user_id 唯一。Register(contest_id, user_id)：使用者報名競賽紀錄，
-- (contest_id, user_id) 組合唯一。對每個至少有人報名的競賽，計算報名人數占全部使用者人數的百分比，四捨五入
-- 至小數點後兩位。輸出 contest_id、percentage；百分比由高到低排序，同百分比時 contest_id 由小到大。
-- 範例：共有 3 位使用者；競賽 208 有 3 人報名，為 100.00%；競賽 215 有 2 人報名，為 66.67%；競賽 207
-- 有 1 人報名，為 33.33%。
-- 解題思路：每個競賽的報名列數就是報名人數；除以 Users 總列數再乘 100，ROUND(..., 2) 保留兩位小數。
-- 步驟：1. 依 contest_id 分組。2. 計算該組人數及全體人數。3. 算百分比並四捨五入。4. 依題目規則排序。
-- 複雜度：令 R 為報名紀錄數、U 為使用者數，時間 O(R+U)，額外分組空間 O(競賽數)。

SELECT contest_id,
       ROUND(COUNT(*) * 100.0 / (SELECT COUNT(*) FROM Users), 2) AS percentage
FROM Register
GROUP BY contest_id
ORDER BY percentage DESC, contest_id ASC;

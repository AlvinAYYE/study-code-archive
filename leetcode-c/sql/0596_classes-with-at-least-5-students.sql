-- LeetCode 596. Classes With at Least 5 Students／至少有五名學生的課程
-- 題目（繁體中文）
-- Courses(student, class) 記錄學生修讀的課程；(student, class) 是複合主鍵，
-- 因此同一位學生不會在同一門課重複出現。找出至少有五名學生的所有課程，
-- 輸出欄名 class，順序不限。
--
-- 範例
-- Math 有 A、C、E、G、H、I 共六名學生，應輸出 Math；English、Biology、
-- Computer 各只有一名學生，因此不輸出。
--
-- 限制與輸出規則
-- (student, class) 組合唯一，所以每列可直接計為一名學生，不需額外去重。
-- 「至少五名」包含剛好五名，HAVING 條件必須使用 >= 5。
--
-- 分步思路
-- 1. 用 GROUP BY class 將同一門課的選課紀錄歸在一起。
-- 2. COUNT(*) 計算每門課的學生數。
-- 3. HAVING 在分組後只保留筆數至少為 5 的課程。
-- 題目：https://leetcode.com/problems/classes-with-at-least-5-students/

SELECT class
FROM Courses
GROUP BY class
HAVING COUNT(*) >= 5;

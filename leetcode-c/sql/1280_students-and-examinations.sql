-- LeetCode 1280. Students and Examinations
-- Title-CN: 學生與考試
--
-- 題目（繁體中文）
-- Students(student_id, student_name)：學生名單，student_id 是主鍵。
-- Subjects(subject_name)：學科名單，subject_name 是主鍵。
-- Examinations(student_id, subject_name)：每列表示該學生參加該科一次考試，
--   沒有主鍵，因此同一學生同一科可以出現多次。
-- 輸出每一位學生與每一科目的組合，以及該學生參加該科考試的次數；
-- 沒參加過的組合也要列出，次數為 0。依 student_id、subject_name 遞增排序。
--
-- 範例：Alice 參加 Math 三次、Physics 兩次、Programming 一次；Bob 沒考 Physics，
--   所以 Bob/Physics 仍要出現在結果中，attended_exams = 0。
--
-- 思路：Students CROSS JOIN Subjects 先產生完整的學生×科目組合，再左連接考試紀錄。
--   COUNT(e.student_id) 只數配對成功的考試列，因此沒有紀錄時會得到 0。
-- 複雜度：先產生 S×C 個組合，再連接及分組 E 筆考試紀錄；概念成本 O(S*C + E)。
-- 題目：https://leetcode.com/problems/students-and-examinations/

SELECT
    s.student_id,
    s.student_name,
    sub.subject_name,
    COUNT(e.student_id) AS attended_exams
FROM Students AS s
CROSS JOIN Subjects AS sub
LEFT JOIN Examinations AS e
    ON e.student_id = s.student_id
   AND e.subject_name = sub.subject_name
GROUP BY s.student_id, s.student_name, sub.subject_name
ORDER BY s.student_id, sub.subject_name;

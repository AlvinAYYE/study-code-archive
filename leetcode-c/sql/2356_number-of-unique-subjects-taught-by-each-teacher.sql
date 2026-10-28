-- Title-CN: 每位教師教授的不重複科目數
-- LeetCode 2356. Number of Unique Subjects Taught by Each Teacher
-- 題意：Teacher 每列代表一位教師在某系教授一門科目。統計每位教師教授過幾種不同科目；
--      同一科目即使在不同系出現，也只計一次。輸出 teacher_id 與 cnt，順序不限。
-- 資料表：Teacher(teacher_id INT, subject_id INT, dept_id INT)，(subject_id, dept_id) 是主鍵。
--        因此同一科目可在不同系重複出現；teacher_id 本身不是唯一值。
-- 範例：教師 1 的列為 (科目2,系3)、(科目2,系4)、(科目3,系3)，答案 cnt=2；
--      教師 2 教授科目 1、2、3、4，答案 cnt=4。
-- 限制：無額外限制；依主鍵保證相同科目與系的列不重複。
-- 解法：1. 依 teacher_id 分組。2. 用 COUNT(DISTINCT subject_id) 去除跨系重複科目。
-- 複雜度：掃描 N 列並分組，時間約 O(N log N)，分組空間 O(N)。

SELECT teacher_id, COUNT(DISTINCT subject_id) AS cnt
FROM Teacher
GROUP BY teacher_id;

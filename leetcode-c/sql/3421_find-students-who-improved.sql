-- 3421. 找出進步的學生（Find Students Who Improved）
-- 題目完整翻譯：找出同一學生在同一科目至少於兩個不同日期應考，且最近一次成績高於第一次成績的組合。回傳 student_id、subject、first_score、latest_score，依 student_id、subject 升冪排列。
-- 資料表與鍵：Scores(student_id INT, subject VARCHAR, score INT, exam_date VARCHAR)；(student_id, subject, exam_date) 是主鍵。每列記錄某學生某科某日期的成績，分數介於 0 到 100。
-- 範例輸入重點：101 的 Math 為 70 → 85、Physics 為 65 → 60；102 的 Math 為 80 → 85；103 只有一次 Math 考試；104 的 Physics 為 75 → 85。
-- 範例輸出：101 Math 70 85；102 Math 80 85；104 Physics 75 85。
-- 限制：題目沒有額外列出資料列數限制。
-- 解題步驟：在每位學生、每科的分組內按 exam_date 排序；ROW_NUMBER 標出最早與最晚考試，同時計算該組考試次數；彙總成首考與末考成績，最後只保留至少兩次且末考較高的分組。
-- 複雜度：N 筆成績需依學生、科目、日期排序，約 O(N log N)；中間結果空間 O(N)。

WITH ranked_scores AS (
    SELECT
        student_id,
        subject,
        score,
        ROW_NUMBER() OVER (
            PARTITION BY student_id, subject
            ORDER BY exam_date ASC
        ) AS first_rank,
        ROW_NUMBER() OVER (
            PARTITION BY student_id, subject
            ORDER BY exam_date DESC
        ) AS latest_rank,
        COUNT(*) OVER (
            PARTITION BY student_id, subject
        ) AS exam_count
    FROM Scores
),
subject_progress AS (
    SELECT
        student_id,
        subject,
        MAX(CASE WHEN first_rank = 1 THEN score END) AS first_score,
        MAX(CASE WHEN latest_rank = 1 THEN score END) AS latest_score,
        MAX(exam_count) AS exam_count
    FROM ranked_scores
    GROUP BY student_id, subject
)
SELECT
    student_id,
    subject,
    first_score,
    latest_score
FROM subject_progress
WHERE exam_count >= 2
  AND latest_score > first_score
ORDER BY student_id ASC, subject ASC;

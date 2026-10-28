-- Title-CN: 找出連續多週會議過多的員工
-- LeetCode 3611. Find Overbooked Employees
-- 題意：標準工作週為 40 小時。每位員工每週（週一至週日）會議總時數超過 20 小時，該週就算
--      meeting-heavy。統計各員工符合的週數，只輸出至少有 2 個這類週的員工，並帶出部門；
--      依 meeting_heavy_weeks 遞減、員工姓名遞增排序。
-- 資料表：employees(employee_id INT 主鍵, employee_name VARCHAR, department VARCHAR)；
--        meetings(meeting_id INT 主鍵, employee_id INT, meeting_date DATE, meeting_type VARCHAR,
--        duration_hours DECIMAL)。meeting_type 可為 Team、Client 或 Training。
-- 範例：Alice 在 6/5–6/11 開會 8+6+7=21 小時，6/12–6/18 開會 12+9=21 小時，符合 2 週，列出；
--      Bob 只有第一週超過 20 小時，雖然有 23 小時，但未達至少 2 週門檻，不列出。
-- 限制：每週門檻為嚴格大於 20 小時；員工需至少有 2 個 meeting-heavy 週。
-- 解法：1. 用 YEARWEEK(date, 3) 將日期歸到週一開始的週。2. 依員工與週加總時數，只留總時數 >20。
--      3. 再按員工計算符合週數，留下至少 2 週並連接員工姓名與部門。
-- 複雜度：M 筆會議先依員工與週分組再彙總，時間約 O(M log M)，分組空間 O(M)。

WITH weekly_meetings AS (
    SELECT employee_id,
           YEARWEEK(meeting_date, 3) AS meeting_week,
           SUM(duration_hours) AS weekly_hours
    FROM meetings
    GROUP BY employee_id, YEARWEEK(meeting_date, 3)
), heavy_weeks AS (
    SELECT employee_id, COUNT(*) AS meeting_heavy_weeks
    FROM weekly_meetings
    WHERE weekly_hours > 20
    GROUP BY employee_id
    HAVING COUNT(*) >= 2
)
SELECT e.employee_id,
       e.employee_name,
       e.department,
       h.meeting_heavy_weeks
FROM heavy_weeks AS h
JOIN employees AS e ON e.employee_id = h.employee_id
ORDER BY h.meeting_heavy_weeks DESC, e.employee_name ASC;

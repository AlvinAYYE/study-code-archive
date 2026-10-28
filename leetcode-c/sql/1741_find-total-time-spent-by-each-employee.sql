-- LeetCode 1741. Find Total Time Spent by Each Employee／統計員工每日在辦公室的總時間
-- 題意（繁體中文）
-- Employees(emp_id, event_day, in_time, out_time)：員工進出辦公室紀錄；(emp_id, event_day, in_time) 組合唯一。
-- in_time 與 out_time 是一天中的分鐘數，範圍 1 到 1440，且 in_time < out_time。同一員工同一天可能多次進出，
-- 但各時段不重疊。每次停留分鐘數 = out_time - in_time。請按員工和日期加總，輸出 day、emp_id、total_time，順序不限。
-- 範例：員工 1 在 2020-11-28 有兩段時間 4 到 32、55 到 200，總計 28+145=173 分鐘。
-- 解題思路：每列是一次辦公室停留，直接相減後依日期和員工分組加總。
-- 步驟：1. 計算每筆 out_time - in_time。2. 依 event_day、emp_id 分組。3. 加總並將日期欄命名為 day。
-- 複雜度：令 N 為進出紀錄數、G 為員工日期組合數，時間 O(N)，分組空間 O(G)。

SELECT event_day AS day,
       emp_id,
       SUM(out_time - in_time) AS total_time
FROM Employees
GROUP BY event_day, emp_id;

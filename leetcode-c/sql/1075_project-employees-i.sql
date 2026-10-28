-- LeetCode 1075. Project Employees I／專案員工 I
-- 題目（繁體中文）
-- Project(project_id, employee_id) 記錄員工參與的專案；兩欄組成主鍵，employee_id 參照 Employee。
-- Employee(employee_id, name, experience_years) 記錄員工年資，experience_years 不為 NULL。
-- 對每個專案計算參與員工的平均年資，四捨五入至小數點後兩位；欄位為 project_id、average_years。
-- 範例：年資 3、2、1 的員工參與專案 1，平均為 2.00；年資 3、2 的員工參與專案 2，平均為 2.50。
-- 解法：依 employee_id 連接兩表，再按 project_id 分組，以 AVG 算平均並用 ROUND 保留兩位小數。
-- 複雜度：概念上需處理每筆專案成員關係。

SELECT project.project_id,
       ROUND(AVG(employee.experience_years), 2) AS average_years
FROM Project AS project
JOIN Employee AS employee
  ON employee.employee_id = project.employee_id
GROUP BY project.project_id;

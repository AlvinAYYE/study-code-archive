-- LeetCode 1731. The Number of Employees Which Report to Each Employee／統計主管的直屬員工
-- 題意（繁體中文）
-- Employees(employee_id, name, reports_to, age)：員工資料，employee_id 唯一；reports_to 是其直屬主管的 id，
-- 沒有主管時為 NULL。至少有一位直屬部屬的員工才算主管。找出每位主管的 employee_id、name、直屬部屬人數
-- reports_count，以及直屬部屬平均年齡 average_age（四捨五入至最接近整數）；依主管 employee_id 遞增排序。
-- 範例：Hercy 的直屬部屬 Alice、Bob 年齡為 41、36，平均 38.5，四捨五入為 39；直屬人數為 2。
-- 解題思路：把員工表的部屬列接到主管列，以部屬的 reports_to 對上主管 employee_id，再按主管統計。
-- 步驟：1. 將報告者與主管自我連接。2. 依主管 id、姓名分組。3. COUNT 部屬、AVG 年齡並四捨五入。4. 排序。
-- 複雜度：令 E 為員工數、M 為有直屬部屬的主管數，時間 O(E)，分組空間 O(M)。

SELECT manager.employee_id,
       manager.name,
       COUNT(*) AS reports_count,
       ROUND(AVG(report.age)) AS average_age
FROM Employees AS report
JOIN Employees AS manager
  ON manager.employee_id = report.reports_to
GROUP BY manager.employee_id, manager.name
ORDER BY manager.employee_id;

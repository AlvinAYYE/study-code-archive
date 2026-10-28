-- LeetCode 577. Employee Bonus／員工獎金
-- 題目（繁體中文）
-- Employee(empId, name, supervisor, salary) 記錄員工資料；empId 是唯一值，
-- supervisor 是其主管的員工編號。Bonus(empId, bonus) 記錄員工獎金；empId
-- 是唯一值，並參照 Employee.empId。沒有 Bonus 資料列代表該員工沒有獎金。
-- 找出獎金少於 1000，或完全沒有獎金的員工，輸出 name、bonus，順序不限。
--
-- 範例
-- Employee 有 Brad、John、Dan、Thomas；Bonus 只有 Dan=500、Thomas=2000。
-- 輸出 Brad(NULL)、John(NULL)、Dan(500)；Thomas 的獎金並非少於 1000，
-- 因此不輸出。
--
-- 限制與輸出規則
-- Employee.empId 與 Bonus.empId 各自唯一；Bonus.empId 是外鍵。結果欄名必須
-- 是 name、bonus。條件是嚴格小於 1000，所以 bonus = 1000 不符合。
--
-- 分步思路
-- 1. 以 Employee 為左表 LEFT JOIN Bonus，保留所有員工。
-- 2. 沒有獎金資料的員工會得到 bonus = NULL。
-- 3. 篩選 bonus < 1000 或 bonus IS NULL，即得到兩類符合條件的員工。
-- 題目：https://leetcode.com/problems/employee-bonus/

SELECT employee.name,
       bonus.bonus
FROM Employee AS employee
LEFT JOIN Bonus AS bonus
  ON bonus.empId = employee.empId
WHERE bonus.bonus < 1000
   OR bonus.bonus IS NULL;

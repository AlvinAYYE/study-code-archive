-- LeetCode 184. Department Highest Salary／部門最高薪水
-- 題目（繁體中文）
-- Employee(id, name, salary, departmentId) 記錄員工；id 是主鍵，departmentId
-- 參照 Department.id。Department(id, name) 記錄部門，id 是主鍵且 name 不為 NULL。
-- 找出每個部門中薪水最高的所有員工；若多人並列最高薪，必須全部輸出。
-- 結果欄名依序為 Department、Employee、Salary，順序不限。
--
-- 範例
-- IT 的 Jim 與 Max 都是 90000，Sales 的 Henry 是 80000 → 輸出
-- (IT,Jim,90000)、(IT,Max,90000)、(Sales,Henry,80000)。
--
-- 分步思路
-- 1. grouped 子查詢依 departmentId 分組，求出每個部門的 MAX(salary)。
-- 2. 將 Employee 連到對應部門及該部門最高薪。
-- 3. 同時比對 departmentId 與 salary，因此所有並列最高薪員工都會保留。
-- 題目：https://leetcode.com/problems/department-highest-salary/

SELECT department.name AS Department,
       employee.name AS Employee,
       employee.salary AS Salary
FROM Employee AS employee
JOIN Department AS department
  ON department.id = employee.departmentId
JOIN (
    SELECT departmentId, MAX(salary) AS highest_salary
    FROM Employee
    GROUP BY departmentId
) AS grouped
  ON grouped.departmentId = employee.departmentId
 AND grouped.highest_salary = employee.salary;

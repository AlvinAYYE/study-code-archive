-- LeetCode 185. Department Top Three Salaries／部門前三高薪水
-- 題目（繁體中文）
-- Employee(id, name, salary, departmentId) 記錄員工，departmentId 參照
-- Department(id, name)。所謂部門高薪員工，是薪水落在該部門前三個「不同薪水」
-- 之內的員工。找出所有部門的高薪員工；同一薪水的員工必須全部保留。
-- 結果欄名依序為 Department、Employee、Salary，順序不限。
--
-- 範例
-- IT 的不同薪水為 90000、85000、70000、69000，因此輸出 Max(90000)、
-- Joe(85000)、Randy(85000)、Will(70000)；Sales 只有 80000、60000 兩種薪水，
-- 所以 Henry 與 Sam 都輸出，不要求一定湊滿三種。
--
-- 限制
-- Employee.id 與 Department.id 都是主鍵；同一部門中不會有姓名、薪水與部門
-- 三者完全相同的重複員工列。
--
-- 分步思路
-- 1. DENSE_RANK 在每個 departmentId 分區內按 salary 降序排名。
-- 2. 同薪員工得到相同名次，下一個不同薪水不跳號，正好對應前三種不同薪水。
-- 3. 保留 salary_rank <= 3，再連接 Department 取得部門名稱並輸出指定三欄。
-- 題目：https://leetcode.com/problems/department-top-three-salaries/

WITH RankedEmployees AS (
    SELECT name,
           salary,
           departmentId,
           DENSE_RANK() OVER (
               PARTITION BY departmentId
               ORDER BY salary DESC
           ) AS salary_rank
    FROM Employee
)
SELECT department.name AS Department,
       ranked.name AS Employee,
       ranked.salary AS Salary
FROM RankedEmployees AS ranked
JOIN Department AS department
  ON department.id = ranked.departmentId
WHERE ranked.salary_rank <= 3;

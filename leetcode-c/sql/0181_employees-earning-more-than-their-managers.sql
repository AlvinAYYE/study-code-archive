-- LeetCode 181. Employees Earning More Than Their Managers／薪水高於主管的員工
-- 題目（繁體中文）
-- Employee(id, name, salary, managerId) 記錄員工與主管的 id；id 是主鍵。
-- 找出薪水嚴格高於自己主管的員工姓名，結果欄名為 Employee，順序不限。
-- 沒有主管的員工不會入選。
-- 例子：Joe 薪水 70000、主管 Sam 薪水 60000 → 輸出 Joe；
-- Henry 薪水 80000、主管 Max 薪水 90000 → 不輸出 Henry。
-- 思路：同一張 Employee 表使用兩個別名，e 代表員工、m 代表主管。
-- 以 e.managerId = m.id 配對後，比較兩人的 salary。
-- 題目：https://leetcode.com/problems/employees-earning-more-than-their-managers/

SELECT e.name AS Employee
FROM Employee AS e
JOIN Employee AS m ON m.id = e.managerId
WHERE e.salary > m.salary;

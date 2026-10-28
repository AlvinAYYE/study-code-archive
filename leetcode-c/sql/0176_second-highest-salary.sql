-- LeetCode 176. Second Highest Salary／第二高的薪水
-- 題目（繁體中文）
-- Employee(id, salary) 中 id 是主鍵。找出第二高的「不同薪水」；
-- 若員工只有一種薪水，仍須輸出一列，欄名 SecondHighestSalary，值為 NULL。
-- 例子：[100, 200, 300] → 200；[100, 100] → NULL。
-- 思路：先用子查詢找最高薪水，再從低於最高薪水的值中取 MAX。
-- MAX 在沒有符合資料時回傳 NULL，恰好符合題目要求；重複薪水不影響結果。
-- 題目：https://leetcode.com/problems/second-highest-salary/

SELECT MAX(salary) AS SecondHighestSalary
FROM Employee
WHERE salary < (SELECT MAX(salary) FROM Employee);

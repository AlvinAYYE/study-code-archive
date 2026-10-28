-- LeetCode 177. Nth Highest Salary／第 N 高的薪水
-- 題目（繁體中文）
-- Employee(id, salary) 記錄員工薪水，id 是主鍵，每列代表一位員工。
-- 實作 MySQL 函式 getNthHighestSalary(N)，回傳第 N 高的「不同薪水」。
-- 重複薪水只算一個名次；若不同薪水不足 N 種，函式必須回傳 NULL。
--
-- 範例
-- Employee 的薪水為 [100, 200, 300]、N = 2 → 回傳 200。
-- Employee 的薪水只有 [100]、N = 2 → 回傳 NULL。
--
-- 限制與輸出規則
-- Employee.id 是唯一值；salary 為整數。輸出欄名由函式呼叫決定，例如
-- getNthHighestSalary(2)。N 代表從 1 開始計算的薪水名次。
--
-- 分步思路
-- 1. DENSE_RANK 依 salary 由高到低排名；相同薪水得到相同名次且不跳號。
-- 2. 外層只保留 salary_rank = N 的列。
-- 3. MAX 將可能因同薪而出現的多列合成單一值；沒有第 N 名時，MAX 對空集合
--    自然回傳 NULL，正好符合題目要求。
-- 題目：https://leetcode.com/problems/nth-highest-salary/

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    RETURN (
        SELECT MAX(ranked.salary)
        FROM (
            SELECT salary,
                   DENSE_RANK() OVER (ORDER BY salary DESC) AS salary_rank
            FROM Employee
        ) AS ranked
        WHERE ranked.salary_rank = N
    );
END;

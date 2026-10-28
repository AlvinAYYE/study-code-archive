-- LeetCode 627. Swap Salary（現名 Swap Sex of Employees）／交換員工性別
-- 題目：https://leetcode.com/problems/swap-sex-of-employees/
--
-- 題目（繁體中文）
-- Salary 表：
--   id     INT      主鍵，員工編號
--   name   VARCHAR  員工姓名
--   sex    ENUM     只可能是 'm' 或 'f'
--   salary INT      薪資
--
-- 使用「單一 UPDATE 陳述式」將所有 'm' 改成 'f'，同時將所有 'f' 改成 'm'。
-- 必須直接更新 Salary，不能建立暫存表，也不能用 SELECT 代替更新。
-- 評測器執行陳述式後會顯示完整 Salary 表。
--
-- 範例
-- 輸入：(1,A,m,2500)、(2,B,f,1500)、(3,C,m,5500)、(4,D,f,500)。
-- 更新後 sex 依序為 f、m、f、m；id、name、salary 均不改變。
--
-- 限制與資料規則
--   1. id 是主鍵。
--   2. sex 僅有 'm'、'f' 兩種 ENUM 值，因此 CASE 的兩個分支已涵蓋所有列。
--   3. 必須在一次 UPDATE 中完成；若分成兩次更新，第一次產生的新值可能在
--      第二次又被改回去。
--
-- 直觀解題思路
--   1. UPDATE 逐列改寫 sex。
--   2. CASE 在原值為 'm' 時回傳 'f'，否則回傳 'm'。
--   3. 單一陳述式會依每列更新前的值計算，因此能安全同步交換。

UPDATE Salary
SET sex = CASE
    WHEN sex = 'm' THEN 'f'
    ELSE 'm'
END;

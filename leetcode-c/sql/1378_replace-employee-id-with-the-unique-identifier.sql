-- LeetCode 1378. Replace Employee ID With The Unique Identifier
-- Title-CN: 以唯一識別碼取代員工編號
--
-- 題目（繁體中文）
-- Employees(id, name)：員工名單，id 是主鍵。
-- EmployeeUNI(id, unique_id)：員工與唯一識別碼的對照，(id, unique_id) 為複合主鍵。
-- 對每位員工輸出 unique_id 與 name；若沒有對照資料，unique_id 顯示 NULL。
-- 輸出順序不限。
--
-- 範例：Employees 有 Alice(id=1)、Meir(id=11)；EmployeeUNI 只有 id=11 對應 unique_id=2。
--   結果是 (NULL, Alice) 與 (2, Meir)。
--
-- 思路：員工名單必須完整保留，因此以 Employees 為左表 LEFT JOIN 對照表；
--   找不到員工編號時，資料庫會自動將 unique_id 填為 NULL。
-- 複雜度：連接兩表各掃描一次，概念成本 O(E + U)，實際依索引與執行計畫而定。
-- 題目：https://leetcode.com/problems/replace-employee-id-with-the-unique-identifier/

SELECT eu.unique_id, e.name
FROM Employees AS e
LEFT JOIN EmployeeUNI AS eu ON eu.id = e.id;

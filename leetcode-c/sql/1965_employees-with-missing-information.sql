-- LeetCode 1965. Employees With Missing Information／找出資料缺漏的員工
-- 題意（繁體中文）
-- Employees(employee_id, name) 與 Salaries(employee_id, salary) 各自記錄員工姓名及薪資；兩表中的 employee_id
-- 都唯一。若員工 id 只出現在其中一張表，代表缺少姓名或薪資資料。找出所有這種 employee_id，依 id 遞增排序。
-- 範例：員工 1 只有薪資、缺姓名；員工 2 只有姓名、缺薪資；員工 4、5 兩表都有，因此結果是 1、2。
-- 解題思路：分別找出只在 Employees、只在 Salaries 出現的 id，再用 UNION 合併並去除重複。
-- 步驟：1. Employees 中找不到薪資列的 id。2. Salaries 中找不到姓名列的 id。3. 合併兩組並排序。
-- 複雜度：令 E、S 為兩表列數，時間 O(E+S)，索引或集合空間 O(E+S)。

SELECT employee_id
FROM Employees
WHERE employee_id NOT IN (SELECT employee_id FROM Salaries)
UNION
SELECT employee_id
FROM Salaries
WHERE employee_id NOT IN (SELECT employee_id FROM Employees)
ORDER BY employee_id;

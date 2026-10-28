-- LeetCode 1978. Employees Whose Manager Left the Company／找出主管已離職的員工
-- 題意（繁體中文）
-- Employees(employee_id, name, manager_id, salary)：公司在職員工資料，employee_id 唯一；沒有主管時 manager_id 為 NULL。
-- 當主管離職，其資料列會從表中刪除，但仍可能有員工的 manager_id 指向該主管。找出薪水嚴格小於 30000、且其
-- manager_id 在 Employees 中找不到的員工 id。沒有主管的人不算「主管離職」。結果依 employee_id 遞增排序。
-- 範例：Kalel 薪水低於 30000，但主管 Joziah 仍在表中，不回傳；Joziah 薪水低於 30000，manager_id=6 卻找不到 id 6，
-- 所以回傳 11。
-- 解題思路：以員工表左連接主管資料；連不到主管但 manager_id 非 NULL，代表主管資料已刪除。再檢查薪水門檻。
-- 步驟：1. 員工列的 manager_id 連接主管 employee_id。2. 保留薪水 < 30000。3. 確認 manager_id 非 NULL 且主管列不存在。
-- 複雜度：令 N 為員工數，時間 O(N)，連接所需空間 O(N)。

SELECT employee.employee_id
FROM Employees AS employee
LEFT JOIN Employees AS manager
  ON manager.employee_id = employee.manager_id
WHERE employee.salary < 30000
  AND employee.manager_id IS NOT NULL
  AND manager.employee_id IS NULL
ORDER BY employee.employee_id;

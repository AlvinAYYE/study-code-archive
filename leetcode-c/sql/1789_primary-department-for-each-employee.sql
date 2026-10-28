-- LeetCode 1789. Primary Department for Each Employee／找出每位員工的主要部門
-- 題意（繁體中文）
-- Employee(employee_id, department_id, primary_flag)：員工所屬部門，(employee_id, department_id) 組合唯一。
-- 員工可屬於多個部門；primary_flag='Y' 的部門是其主要部門。若員工只屬於一個部門，該列的旗標會是 'N'，
-- 但仍須回傳這個唯一部門。找出每位員工的 employee_id 與主要 department_id，順序不限。
-- 範例：員工 2 有多個部門，選旗標 Y 的部門 1；員工 1 只有部門 1，即使旗標是 N 也回傳 1。
-- 解題思路：答案列有兩種情況：主要旗標為 Y，或該員工在表中只有一筆部門資料。
-- 步驟：1. 先找只有一筆部門的員工 id。2. 篩出旗標 Y 或上述單一部門員工的列。3. 輸出 id 與部門。
-- 複雜度：令 N 為員工部門列數、E 為員工數，時間 O(N)，分組空間 O(E)。

SELECT employee_id,
       department_id
FROM Employee
WHERE primary_flag = 'Y'
   OR employee_id IN (
       SELECT employee_id
       FROM Employee
       GROUP BY employee_id
       HAVING COUNT(*) = 1
   );

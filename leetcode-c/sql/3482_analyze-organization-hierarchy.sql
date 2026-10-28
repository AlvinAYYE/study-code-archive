-- 3482. 分析組織階層（Analyze Organization Hierarchy）
-- 題目完整翻譯：分析 Employees 組織圖，為每位員工算出層級（CEO 為 1，直接向 CEO 回報者為 2，依此類推）；計算其下屬總數（直接及間接）；計算其預算（本人薪資加所有直接及間接下屬薪資）。回傳 employee_id、employee_name、level、team_size、budget，依 level 升冪、budget 降冪、employee_name 升冪排序。
-- 資料表與鍵：Employees(employee_id INT, employee_name VARCHAR, manager_id INT, salary INT, department VARCHAR)；employee_id 為唯一鍵；CEO 的 manager_id 為 NULL。
-- 範例輸入重點：Alice 為 CEO；Bob、Charlie 向 Alice 回報；其餘員工依 Bob、Charlie、David、Frank 等管理鏈逐層回報。
-- 範例輸出重點：Alice level=1、team_size=9、budget=84500；Charlie level=2、team_size=4、budget=41500；Bob level=2、team_size=3、budget=31000；無下屬者 team_size=0 且 budget 等於本人薪資。
-- 限制：題目沒有額外列出員工數限制；資料代表一棵以 CEO 為根的組織樹。
-- 解題步驟：遞迴 CTE 以每位員工各自作為起點，沿回報關係列出自己及所有下屬，得到每個主管的完整團隊和薪資總額；同一張遞迴結果中，取 CEO 起點的距離加一作為每位員工層級；最後彙總團隊人數（扣除本人）與預算。
-- 複雜度：遞迴結果每個祖先與其後代會形成一列，最壞 O(N^2) 列；彙總與排序另需至多 O(N^2 log N)。

WITH RECURSIVE org_walk (ancestor_id, member_id, member_salary, distance) AS (
    SELECT
        employee_id,
        employee_id,
        salary,
        0
    FROM Employees

    UNION ALL

    SELECT
        org_walk.ancestor_id,
        employee.employee_id,
        employee.salary,
        org_walk.distance + 1
    FROM org_walk
    JOIN Employees AS employee
      ON employee.manager_id = org_walk.member_id
),
employee_levels AS (
    SELECT
        member_id AS employee_id,
        MAX(distance + 1) AS level
    FROM org_walk
    WHERE ancestor_id = (
        SELECT employee_id
        FROM Employees
        WHERE manager_id IS NULL
    )
    GROUP BY member_id
),
team_totals AS (
    SELECT
        ancestor_id AS employee_id,
        COUNT(*) - 1 AS team_size,
        SUM(member_salary) AS budget
    FROM org_walk
    GROUP BY ancestor_id
)
SELECT
    employee.employee_id,
    employee.employee_name,
    employee_levels.level,
    team_totals.team_size,
    team_totals.budget
FROM Employees AS employee
JOIN employee_levels
  ON employee_levels.employee_id = employee.employee_id
JOIN team_totals
  ON team_totals.employee_id = employee.employee_id
ORDER BY employee_levels.level ASC, team_totals.budget DESC, employee.employee_name ASC;

-- LeetCode 570. Managers with at Least 5 Direct Reports／至少有 5 名直屬部屬的主管
-- 題目：https://leetcode.com/problems/managers-with-at-least-5-direct-reports/
--
-- 題目（繁體中文）
-- Employee 表：
--   id         INT      主鍵，員工的唯一編號
--   name       VARCHAR  員工姓名
--   department VARCHAR  所屬部門
--   managerId  INT      直屬主管的 id；NULL 表示沒有主管
-- 每列描述一名員工、其部門與直屬主管，而且沒有人會是自己的主管。
--
-- 找出至少有 5 名「直屬」部屬的主管，輸出主管姓名，欄名為 name，順序不限。
-- 下屬的下屬不算在內。
--
-- 範例
-- Employee 中 John(id=101) 沒有主管；Dan、James、Amy、Anne、Ron 的
-- managerId 都是 101。John 恰有 5 名直屬部屬，因此輸出：
--   name
--   John
--
-- 限制與資料規則
--   1. id 是主鍵，每名員工只有一列。
--   2. managerId 為 NULL 時代表沒有主管。
--   3. 員工不會管理自己；只需計算 managerId 直接指向主管的資料列。
--
-- 直觀解題思路
--   1. 將 Employee 自我連接，manager 代表主管，report 代表直屬部屬。
--   2. 用 report.managerId = manager.id 配對直接管理關係。
--   3. 依主管分組後計算部屬列數，以 HAVING COUNT(*) >= 5 篩選。

SELECT manager.name
FROM Employee AS manager
JOIN Employee AS report
  ON report.managerId = manager.id
GROUP BY manager.id, manager.name
HAVING COUNT(*) >= 5;

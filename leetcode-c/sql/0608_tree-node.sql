-- Title-CN: 樹狀節點類型
-- LeetCode 0608. Tree Node
-- 題目：Tree 表記錄一棵合法樹中每個節點的 id 和父節點 p_id。請為每個節點標示類型：
--       沒有父節點的是 Root；有父節點且至少有一個子節點的是 Inner；有父節點且沒有子節點的是 Leaf。
--       回傳每個 id 及其 type，結果順序不限。
-- 資料表：Tree(id INT 唯一, p_id INT 可為 NULL)。id 唯一；整體結構保證為一棵合法樹。
-- 範例：Tree = [(1,NULL),(2,1),(3,1),(4,2),(5,2)]，結果為
--       [(1,'Root'),(2,'Inner'),(3,'Leaf'),(4,'Leaf'),(5,'Leaf')]
--       若只有 (1,NULL)，結果為 [(1,'Root')]。
-- 解法：先判斷 p_id 是否為 NULL；否則用 NOT EXISTS 查是否有任何列以目前 id 為父節點。
--       有子節點就是 Inner，沒有就是 Leaf。先判斷 Root 可正確處理單一節點樹。
-- 複雜度：N 為節點數；有 p_id 索引時約 O(N)，無索引時相關子查詢最壞 O(N^2)。

SELECT
    t.id,
    CASE
        WHEN t.p_id IS NULL THEN 'Root'
        WHEN NOT EXISTS (
            SELECT 1
            FROM Tree AS child
            WHERE child.p_id = t.id
        ) THEN 'Leaf'
        ELSE 'Inner'
    END AS type
FROM Tree AS t;

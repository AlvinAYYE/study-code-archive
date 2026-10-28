-- Title-CN: 重新整理部門營收表
-- LeetCode 1179. Reformat Department Table
-- 題目：將每個部門原本分列的月營收轉成寬表：每個部門一列，並提供 Jan_Revenue 到 Dec_Revenue 共 12 個月份欄位。
--       該部門沒有該月份資料時，欄位需為 NULL。
-- 資料表：Department(id INT, revenue INT, month VARCHAR)。 (id, month) 是主鍵；month 是 Jan 至 Dec 其中之一。
-- 範例：輸入 (1,8000,'Jan')、(1,7000,'Feb')、(1,6000,'Mar')、(2,9000,'Jan')、(3,10000,'Feb')；
--       輸出部門 1 的 Jan/Feb/Mar 為 8000/7000/6000，其餘月份 NULL；部門 2 只有 Jan=9000；部門 3 只有 Feb=10000。
-- 解法：以 id 分組，對每個月份用條件聚合取出該月 revenue。CASE 沒有符合資料時會產生 NULL，
--       MAX 便自然保留 NULL；(id, month) 唯一，所以每月最多一筆。
-- 複雜度：N 為 Department 列數；掃描並分組一次，約 O(N)，記憶體/排序成本視資料庫而定。

SELECT
    id,
    MAX(CASE WHEN month = 'Jan' THEN revenue END) AS Jan_Revenue,
    MAX(CASE WHEN month = 'Feb' THEN revenue END) AS Feb_Revenue,
    MAX(CASE WHEN month = 'Mar' THEN revenue END) AS Mar_Revenue,
    MAX(CASE WHEN month = 'Apr' THEN revenue END) AS Apr_Revenue,
    MAX(CASE WHEN month = 'May' THEN revenue END) AS May_Revenue,
    MAX(CASE WHEN month = 'Jun' THEN revenue END) AS Jun_Revenue,
    MAX(CASE WHEN month = 'Jul' THEN revenue END) AS Jul_Revenue,
    MAX(CASE WHEN month = 'Aug' THEN revenue END) AS Aug_Revenue,
    MAX(CASE WHEN month = 'Sep' THEN revenue END) AS Sep_Revenue,
    MAX(CASE WHEN month = 'Oct' THEN revenue END) AS Oct_Revenue,
    MAX(CASE WHEN month = 'Nov' THEN revenue END) AS Nov_Revenue,
    MAX(CASE WHEN month = 'Dec' THEN revenue END) AS Dec_Revenue
FROM Department
GROUP BY id;

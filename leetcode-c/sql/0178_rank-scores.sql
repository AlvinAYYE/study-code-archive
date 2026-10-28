-- LeetCode 178. Rank Scores／分數排名
-- 題目（繁體中文）
-- Scores(id, score) 記錄每場遊戲的分數；id 是主鍵，score 是保留兩位小數
-- 的 decimal。請替每列分數計算排名。
--
-- 排名與輸出規則
-- 分數由高到低排名；相同分數必須同名次，下一個不同分數接續下一個整數名次，
-- 不可因並列而跳號。輸出欄為 score、rank，結果必須按 score 降序排列。
--
-- 範例
-- 分數 [3.50, 3.65, 4.00, 3.85, 4.00, 3.65] 依序輸出：
-- (4.00,1)、(4.00,1)、(3.85,2)、(3.65,3)、(3.65,3)、(3.50,4)。
--
-- 分步思路
-- 1. DENSE_RANK 正是「同值同名次、下一名不跳號」的排名方式。
-- 2. 視窗依 score DESC 排名，但不會合併原始列，所以並列分數仍各輸出一列。
-- 3. 最後再以 ORDER BY score DESC 保證題目要求的輸出順序。
-- 題目：https://leetcode.com/problems/rank-scores/

SELECT score,
       DENSE_RANK() OVER (ORDER BY score DESC) AS `rank`
FROM Scores
ORDER BY score DESC;

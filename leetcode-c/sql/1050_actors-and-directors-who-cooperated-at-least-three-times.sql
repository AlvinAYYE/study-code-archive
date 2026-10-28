-- LeetCode 1050. Actors and Directors Who Cooperated at Least Three Times／合作至少三次的演員和導演
-- 題目（繁體中文）
-- ActorDirector(actor_id, director_id, timestamp) 記錄演員與導演合作的紀錄；timestamp 是唯一主鍵。
-- 找出合作次數至少三次的 (actor_id, director_id) 配對。結果可任意排序。
-- 範例：配對 (1,1) 出現三次，其他配對不足三次，因此只回傳 (1,1)。
-- 解法：依演員與導演分組，COUNT(*) 計算合作次數，再用 HAVING 篩出至少三次的群組。
-- 複雜度：資料庫依索引與執行計畫分組；概念上需檢查每筆合作紀錄。

SELECT actor_id, director_id
FROM ActorDirector
GROUP BY actor_id, director_id
HAVING COUNT(*) >= 3;

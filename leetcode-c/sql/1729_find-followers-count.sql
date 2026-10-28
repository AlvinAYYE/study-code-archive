-- LeetCode 1729. Find Followers Count／統計每位使用者的追蹤者數
-- 題意（繁體中文）
-- Followers(user_id, follower_id)：社群平台上的追蹤關係；(user_id, follower_id) 組合唯一。每列表示
-- follower_id 追蹤 user_id。對每位出現在此表的 user_id 計算追蹤者數，輸出 user_id、followers_count，依 user_id
-- 遞增排序。
-- 範例：user 0 有 follower 1，因此數量為 1；user 2 有 follower 0、1，因此數量為 2。
-- 解題思路：每一列代表一位追蹤者，依被追蹤的 user_id 分組並計算列數。
-- 步驟：1. 依 user_id 分組。2. 計算每組列數。3. 依 user_id 遞增輸出。
-- 複雜度：令 F 為追蹤關係數、U 為出現在表中的使用者數，時間 O(F)，分組空間 O(U)。

SELECT user_id,
       COUNT(*) AS followers_count
FROM Followers
GROUP BY user_id
ORDER BY user_id;

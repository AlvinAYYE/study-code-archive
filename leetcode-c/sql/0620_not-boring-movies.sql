-- LeetCode 620. Not Boring Movies／有趣的電影
-- 題目：https://leetcode.com/problems/not-boring-movies/
--
-- 題目（繁體中文）
-- Cinema 表：
--   id          INT      主鍵，電影編號
--   movie       VARCHAR  電影名稱
--   description VARCHAR  電影描述或類型
--   rating      FLOAT    評分，範圍 [0, 10]，保留兩位小數
--
-- 找出 id 為奇數且 description 不等於 'boring' 的電影，輸出 Cinema 的
-- 四個欄位，並按 rating 由高到低排序。
--
-- 範例
-- 奇數 id 為 1、3、5；其中 id=3 的 description 是 boring，所以排除。
-- 剩下 House card(id=5, rating=9.1) 與 War(id=1, rating=8.9)，依評分降冪
-- 輸出 5、1 兩列。
--
-- 限制與資料規則
--   1. id 是主鍵。
--   2. rating 是 0 到 10、最多兩位小數的浮點數。
--   3. 必須同時符合奇數 id 與 description <> 'boring'。
--   4. 最終排序必須是 rating 降冪。
--
-- 直觀解題思路
--   1. MOD(id, 2) = 1 篩出奇數編號。
--   2. description <> 'boring' 排除無聊電影。
--   3. 直接選取四個原欄位，再以 rating DESC 排序。

SELECT id, movie, description, rating
FROM Cinema
WHERE MOD(id, 2) = 1
  AND description <> 'boring'
ORDER BY rating DESC;

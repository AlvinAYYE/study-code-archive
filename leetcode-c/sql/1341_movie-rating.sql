-- LeetCode 1341. Movie Rating
-- Title-CN: 電影評分
--
-- 題目（繁體中文）
-- Movies(movie_id, title)：電影資料；movie_id 是主鍵，title 不重複。
-- Users(user_id, name)：使用者資料；user_id 是主鍵，name 不重複。
-- MovieRating(movie_id, user_id, rating, created_at)：使用者對電影的評分日期與分數，
--   (movie_id, user_id) 是主鍵。
-- 回傳單欄 results，包含兩筆答案：評分電影數最多的使用者姓名；以及 2020 年 2 月
--   平均評分最高的電影名稱。各自若同分，選字典序較小的名稱。
--
-- 範例：Daniel 與 Monica 都評過三部電影，Daniel 字典序較小；Frozen 2 與 Joker
--   在 2020 年 2 月平均分數同為 3.5，Frozen 2 字典序較小，因此輸出 Daniel、Frozen 2。
--
-- 思路：先各自統計每位使用者的評分筆數，以及每部電影二月評分平均；再用
--   ROW_NUMBER() 按題目規則排名，取第一名，最後 UNION ALL 合成 results 欄。
-- 複雜度：掃描評分資料進行兩次彙整，再排序彙整後的使用者與電影候選列；
--   成本約為 O(R + U log U + M log M)，R 為評分數、U/M 為使用者/電影數。
-- 題目：https://leetcode.com/problems/movie-rating/

WITH UserTotals AS (
    SELECT u.name, COUNT(*) AS rating_count
    FROM Users AS u
    JOIN MovieRating AS mr ON mr.user_id = u.user_id
    GROUP BY u.user_id, u.name
),
RankedUsers AS (
    SELECT
        name,
        ROW_NUMBER() OVER (ORDER BY rating_count DESC, name ASC) AS row_num
    FROM UserTotals
),
FebruaryAverages AS (
    SELECT m.title, AVG(mr.rating) AS average_rating
    FROM Movies AS m
    JOIN MovieRating AS mr ON mr.movie_id = m.movie_id
    WHERE mr.created_at >= '2020-02-01'
      AND mr.created_at < '2020-03-01'
    GROUP BY m.movie_id, m.title
),
RankedMovies AS (
    SELECT
        title,
        ROW_NUMBER() OVER (ORDER BY average_rating DESC, title ASC) AS row_num
    FROM FebruaryAverages
)
SELECT name AS results
FROM RankedUsers
WHERE row_num = 1
UNION ALL
SELECT title AS results
FROM RankedMovies
WHERE row_num = 1;

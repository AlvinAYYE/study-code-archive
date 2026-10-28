-- Title-CN: 文章瀏覽 I
-- LeetCode 1148. Article Views I
-- 題目：找出至少看過自己所寫文章一次的作者，回傳作者編號並命名為 id，依 id 遞增排序。
-- 資料表：Views(article_id INT, author_id INT, viewer_id INT, view_date DATE)。沒有主鍵，列可能重複；
--       每列表示某位 viewer 在某日看了某篇由 author 撰寫的文章。author_id = viewer_id 表示作者看自己的文章。
-- 範例：記錄中作者 7 看過自己的文章 2，作者 4 看過自己的文章 3（此列重複也只算作者一次）；
--       輸出 id 為 4、7。
-- 解法：篩出 author_id = viewer_id 的列，以 DISTINCT 去除同一作者的重複瀏覽，再按 id 排序。
-- 複雜度：N 為瀏覽記錄數；掃描 O(N)，去重及排序約 O(A log A)，A 為符合條件的作者數。

SELECT DISTINCT
    author_id AS id
FROM Views
WHERE author_id = viewer_id
ORDER BY id;

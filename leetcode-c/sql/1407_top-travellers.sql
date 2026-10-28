-- LeetCode 1407. Top Travellers
-- Title-CN: 最常旅行者
--
-- 題目（繁體中文）
-- Users(id, name)：使用者清單，id 唯一。
-- Rides(id, user_id, distance)：每趟旅程的距離，user_id 表示旅程屬於誰。
-- 輸出每位使用者的總旅程距離 travelled_distance；沒有旅程的人距離為 0。
-- 依 travelled_distance 由大到小排序，同距離時依 name 字典序由小到大排序。
--
-- 範例：Elvis 與 Lee 都走了 450，Elvis 名字較前所以排在 Lee 之前；Donald 沒有旅程，
--   仍要列出，距離為 0。
--
-- 思路：以 Users 左連接旅程，按使用者分組加總 distance；COALESCE 將無旅程的 NULL 改為 0，
--   最後依總距離及姓名排序。
-- 複雜度：連接與分組 R 筆旅程及 U 位使用者，最後排序 U 筆結果；概念成本 O(R + U log U)。
-- 題目：https://leetcode.com/problems/top-travellers/

SELECT
    u.name,
    COALESCE(SUM(r.distance), 0) AS travelled_distance
FROM Users AS u
LEFT JOIN Rides AS r ON r.user_id = u.id
GROUP BY u.id, u.name
ORDER BY travelled_distance DESC, u.name ASC;

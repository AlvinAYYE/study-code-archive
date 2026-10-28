-- Title-CN: 市場分析 I
-- LeetCode 1158. Market Analysis I
-- 題目：對 Users 的每位使用者，回傳 user_id 改名為 buyer_id、join_date，以及該使用者在 2019 年下單的筆數。
--       沒有在 2019 下單的使用者仍要列出，訂單數為 0；結果順序不限。
-- 資料表：Users(user_id INT 主鍵, join_date DATE, favorite_brand VARCHAR)。
--       Orders(order_id INT 主鍵, order_date DATE, item_id INT, buyer_id INT, seller_id INT)。
--       Items(item_id INT 主鍵, item_brand VARCHAR)；本題計數不需使用 Items。
-- 範例：使用者 1 在 2019 買過一次、使用者 2 買過兩次；使用者 3、4 沒有 2019 訂單。
--       對應輸出為 (1, 2018-01-01, 1)、(2, 2018-02-09, 2)、(3, 2018-01-19, 0)、(4, 2018-05-21, 0)。
-- 解法：從 Users 出發 LEFT JOIN 訂單，並把 2019 日期範圍條件放在 ON 子句，保留零訂單使用者；
--       再以 COUNT(order_id) 計數，避免 LEFT JOIN 補出的 NULL 被算成一筆。
-- 複雜度：U 為使用者數、O 為訂單數；掃描並連接約 O(U + O)，索引可改善 buyer_id/date 查找。

SELECT
    u.user_id AS buyer_id,
    u.join_date,
    COUNT(o.order_id) AS orders_in_2019
FROM Users AS u
LEFT JOIN Orders AS o
    ON o.buyer_id = u.user_id
   AND o.order_date >= '2019-01-01'
   AND o.order_date <  '2020-01-01'
GROUP BY u.user_id, u.join_date;

-- Title-CN: 找出常被同一批顧客購買的類別組合
-- LeetCode 3554. Find Category Recommendation Pairs
-- 題意：若某顧客買過某類別的任一商品，就算買過該類別。找出至少被 3 位不同顧客共同購買的
--      類別組合。每組只列一次，並要求 category1 < category2。依共同顧客數遞減、類別名稱遞增排序。
-- 資料表：ProductPurchases(user_id INT, product_id INT, quantity INT)，(user_id, product_id)
--        是主鍵。ProductInfo(product_id INT 主鍵, category VARCHAR, price DECIMAL)。
-- 範例：先將每位顧客買過的商品類別去重；若顧客 1、2、4 都買過 Books 與 Electronics，
--      輸出 Books / Electronics，customer_count=3（類別順序依字母比較）。
-- 限制：配對類別必須不同且按字典順序固定方向；至少 3 位不同顧客共同購買。
-- 解法：1. 連接兩表並去重成「顧客、類別」清單。2. 同一顧客的類別清單自我連接，僅保留
--      category1 < category2。3. 按類別配對計算顧客數，保留至少 3 人的配對。
-- 複雜度：令每位顧客買過 k 種類別，配對數為 ΣO(k²)；之後按類別配對分組。

WITH user_categories AS (
    SELECT DISTINCT pp.user_id, pi.category
    FROM ProductPurchases AS pp
    JOIN ProductInfo AS pi ON pi.product_id = pp.product_id
), category_pairs AS (
    SELECT a.category AS category1,
           b.category AS category2,
           COUNT(DISTINCT a.user_id) AS customer_count
    FROM user_categories AS a
    JOIN user_categories AS b
      ON a.user_id = b.user_id
     AND a.category < b.category
    GROUP BY a.category, b.category
    HAVING COUNT(DISTINCT a.user_id) >= 3
)
SELECT category1, category2, customer_count
FROM category_pairs
ORDER BY customer_count DESC, category1 ASC, category2 ASC;

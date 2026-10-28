-- LeetCode 1084. Sales Analysis III／銷售分析 III
-- 題目（繁體中文）
-- Product(product_id, product_name, unit_price) 保存商品資料；Sales(seller_id, product_id, buyer_id,
-- sale_date, quantity, price) 保存銷售紀錄，可能有重複列，product_id 參照 Product。
-- 找出在 2019 年第一季（2019-01-01 至 2019-03-31，含首尾）有銷售，且在此期間以外完全沒有銷售的商品。
-- 回傳 product_id、product_name，順序不限。沒有任何銷售的商品不算「只在第一季售出」。
-- 範例：商品 1 只在 2019-01-21 售出，應列出；商品 2 也在 2019 年 6 月售出，不能列出。
-- 解法：先確認商品至少有一筆第一季銷售，再排除任何日期落在第一季之外的商品。
-- 複雜度：概念上檢查商品及其銷售紀錄；product_id 可用索引加速。

SELECT product.product_id,
       product.product_name
FROM Product AS product
WHERE EXISTS (
    SELECT 1
    FROM Sales AS in_quarter
    WHERE in_quarter.product_id = product.product_id
      AND in_quarter.sale_date BETWEEN '2019-01-01' AND '2019-03-31'
)
AND NOT EXISTS (
    SELECT 1
    FROM Sales AS outside_quarter
    WHERE outside_quarter.product_id = product.product_id
      AND (outside_quarter.sale_date < '2019-01-01'
           OR outside_quarter.sale_date > '2019-03-31')
);

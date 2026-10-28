-- LeetCode 1068. Product Sales Analysis I／產品銷售分析 I
-- 題目（繁體中文）
-- Sales(sale_id, product_id, year, quantity, price) 記錄每筆銷售；(sale_id, year) 是複合主鍵，
-- price 是單件商品的價格，product_id 參照 Product。Product(product_id, product_name) 保存商品名稱。
-- 對 Sales 的每筆紀錄，回傳商品名稱、銷售年份與單價，欄位依序為 product_name、year、price。
-- 範例：商品 100（Nokia）在 2008 年售價 5000，輸出 (Nokia, 2008, 5000)。
-- 解法：用 product_id 將銷售表與商品表內連接，取所需欄位；每筆銷售都保留。
-- 複雜度：概念上需檢查每筆銷售紀錄，連接可使用 product_id 索引。

SELECT product.product_name,
       sales.year,
       sales.price
FROM Sales AS sales
JOIN Product AS product
  ON product.product_id = sales.product_id;

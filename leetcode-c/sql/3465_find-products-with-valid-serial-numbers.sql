-- 3465. 找出含有效序號的產品（Find Products with Valid Serial Numbers）
-- 題目完整翻譯：找出 description 中包含有效序號的所有產品。序號以大小寫相符的 SN 開頭，接著恰有 4 位數字、連字號及恰有 4 位數字；序號可出現在描述文字中任意位置。依 product_id 升冪回傳完整產品資料。
-- 資料表與鍵：products(product_id INT, product_name VARCHAR, description VARCHAR)；product_id 為唯一鍵。
-- 範例輸入重點：Widget A 含 SN1234-5678；Widget B 含 SN9876-1234；Widget C 的 SN1234-56789 尾段多一位數；Widget D 沒有序號；Widget E 含 SN4321-8765。
-- 範例輸出：Widget A、Widget B、Widget E。
-- 限制：題目沒有額外列出資料長度限制。
-- 解題步驟：用不加字串起始錨點的正規表示式搜尋描述任意位置；SN 後固定四位數及連字號，尾端四位之後不可再接數字，避免把五位數誤當成合法序號的一部分。
-- 複雜度：對 N 個描述逐筆搜尋，約 O(N × L)，L 為描述長度；額外空間 O(1)。

SELECT
    product_id,
    product_name,
    description
FROM products
WHERE REGEXP_LIKE(description, 'SN[0-9]{4}-[0-9]{4}([^0-9]|$)', 'c')
ORDER BY product_id ASC;

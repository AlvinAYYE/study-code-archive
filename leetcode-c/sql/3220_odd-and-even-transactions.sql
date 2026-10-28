-- 3220. 奇數與偶數交易（Odd and Even Transactions）
-- 題目完整翻譯：transactions 有交易編號、金額與交易日期。請按日期統計金額為奇數與偶數的交易金額總和，分別命名 odd_sum、even_sum；某一天沒有奇數或偶數金額時，該欄顯示 0。結果依日期升冪排列。
-- 資料表與鍵：transactions(transaction_id INT, amount INT, transaction_date DATE)；transaction_id 唯一識別每筆交易。
-- 範例輸入：2024-07-01 有 (1,150)、(2,200)、(3,75)；2024-07-02 有 (4,300)、(5,50)；2024-07-03 有 (6,120)。
-- 範例輸出：
-- transaction_date | odd_sum | even_sum
-- 2024-07-01       | 75      | 350
-- 2024-07-02       | 0       | 350
-- 2024-07-03       | 0       | 120
-- 限制：題目沒有額外列出資料範圍限制。
-- 解題步驟：以 transaction_date 分組；依 amount 的奇偶性做條件加總；CASE 的 ELSE 0 讓缺少的奇偶類別仍回傳 0。
-- 複雜度：讀取 N 筆交易一次，聚合約 O(N)；按日期排序最壞 O(D log D)，D 為不同日期數。

SELECT
    transaction_date,
    SUM(CASE WHEN MOD(amount, 2) <> 0 THEN amount ELSE 0 END) AS odd_sum,
    SUM(CASE WHEN MOD(amount, 2) = 0 THEN amount ELSE 0 END) AS even_sum
FROM transactions
GROUP BY transaction_date
ORDER BY transaction_date ASC;

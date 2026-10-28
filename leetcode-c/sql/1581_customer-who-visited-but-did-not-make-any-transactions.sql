-- LeetCode 1581. Customer Who Visited but Did Not Make Any Transactions／統計未消費的訪客
-- 題意（繁體中文）
-- Visits(visit_id, customer_id)：顧客到訪紀錄，visit_id 唯一。Transactions(transaction_id, visit_id, amount)：
-- 到訪期間完成的交易，transaction_id 唯一；一個到訪可以有零筆或多筆交易。找出每位至少有一次「到訪時
-- 完全沒有交易」的顧客，以及這類到訪的次數。輸出 customer_id、count_no_trans，順序不限。
-- 範例：顧客 54 到訪三次，其中 visit_id 6、7 沒有交易，visit_id 8 有交易，因此計數為 2；顧客 30 和 96
-- 各有一次無交易到訪，因此各計數為 1。visit_id 1、2、5 都有交易，不納入計數。
-- 解題思路：以 Visits 為主表 LEFT JOIN Transactions。沒有配對交易時，交易欄位為 NULL；篩掉有交易的到訪，
-- 再依 customer_id 分組並計算剩餘到訪筆數。
-- 步驟：1. 保留每一筆到訪。2. 接上該次到訪的交易。3. 篩出交易不存在的列。4. 依顧客計數。
-- 複雜度：令 V 為到訪數、T 為交易數，時間 O(V+T)，分組所需空間 O(顧客數)。

SELECT visits.customer_id,
       COUNT(*) AS count_no_trans
FROM Visits AS visits
LEFT JOIN Transactions AS transactions
  ON transactions.visit_id = visits.visit_id
WHERE transactions.transaction_id IS NULL
GROUP BY visits.customer_id;

-- LeetCode 1393. Capital Gain/Loss
-- Title-CN: 資本損益
--
-- 題目（繁體中文）
-- Stocks(stock_name, operation, operation_day, price)：記錄股票的買賣；
--   (stock_name, operation_day) 是主鍵，operation 為 Buy 或 Sell。
-- 每次買進後都有之後的賣出，每次賣出前也一定買過。對每支股票計算總損益，
--   一次交易的損益是賣出價減買進價；總損益可能為負數。輸出股票名稱與損益，順序不限。
--
-- 範例：Leetcode 以 1000 買入、9000 賣出，損益 8000；Handbags 以 30000 買入、
--   7000 賣出，損益 -23000。Corona Masks 多次買賣後合計損益為 9500。
--
-- 思路：對 Sell 價格加總、對 Buy 價格減總，依股票分組；每筆買賣差額相加後，
--   自然得到所有交易的總損益。
-- 複雜度：掃描並分組 S 筆操作，概念成本 O(S)。
-- 題目：https://leetcode.com/problems/capital-gainloss/

SELECT
    stock_name,
    SUM(CASE WHEN operation = 'Sell' THEN price ELSE -price END) AS capital_gain_loss
FROM Stocks
GROUP BY stock_name;

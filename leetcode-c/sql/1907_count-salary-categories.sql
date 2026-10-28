-- LeetCode 1907. Count Salary Categories／統計各薪資級距的帳戶數
-- 題意（繁體中文）
-- Accounts(account_id, income)：銀行帳戶資料，account_id 唯一，income 是每月收入。依下列互斥級距計算帳戶數：
-- Low Salary：收入嚴格小於 20000；Average Salary：收入介於 20000 到 50000（含）之間；High Salary：收入嚴格大於 50000。
-- 結果必須固定含有三個類別；沒有帳戶的類別也要回傳 0。輸出 category、accounts_count，順序不限。
-- 範例：收入 12747 屬 Low Salary；87709、91796、108939 屬 High Salary；Average Salary 為 0。
-- 解題思路：分別用條件式 COUNT 計算三個互斥範圍，再以 UNION ALL 固定輸出三列；COUNT 條件在沒有符合資料時仍回傳 0。
-- 步驟：1. 計算 income < 20000。2. 計算 20000 <= income <= 50000。3. 計算 income > 50000。4. 合併三類。
-- 複雜度：令 N 為帳戶數，掃描三次仍是 O(N)，額外空間 O(1)。

SELECT 'Low Salary' AS category,
       COUNT(CASE WHEN income < 20000 THEN 1 END) AS accounts_count
FROM Accounts
UNION ALL
SELECT 'Average Salary' AS category,
       COUNT(CASE WHEN income BETWEEN 20000 AND 50000 THEN 1 END) AS accounts_count
FROM Accounts
UNION ALL
SELECT 'High Salary' AS category,
       COUNT(CASE WHEN income > 50000 THEN 1 END) AS accounts_count
FROM Accounts;

-- LeetCode 1587. Bank Account Summary II／銀行帳戶餘額統計 II
-- 題意（繁體中文）
-- Users(account, name)：帳戶資料，account 唯一，且不同帳戶不會有相同姓名。Transactions(trans_id, account,
-- amount, transacted_on)：帳戶交易，trans_id 唯一；amount 為正表示入帳，為負表示轉出；所有帳戶起始餘額為 0。
-- 一個帳戶餘額是該帳戶所有交易金額的總和。只回傳餘額嚴格大於 10000 的使用者姓名及餘額，順序不限。
-- 範例：Alice 的交易是 7000、7000、-3000，餘額 11000，應列出；Bob 的 1000、Charlie 的 8000 不列出。
-- 解題思路：用帳戶連接交易，依帳戶分組後以 SUM 算出餘額，並用 HAVING 篩選總和大於 10000。
-- 步驟：1. 將每個使用者配對其交易。2. 加總交易金額。3. 只留下餘額大於門檻者。4. 輸出姓名與餘額。
-- 複雜度：令 U 為使用者數、T 為交易數，時間 O(U+T)，分組所需空間 O(有交易的帳戶數)。

SELECT users.name,
       SUM(transactions.amount) AS balance
FROM Users AS users
JOIN Transactions AS transactions
  ON transactions.account = users.account
GROUP BY users.account, users.name
HAVING SUM(transactions.amount) > 10000;

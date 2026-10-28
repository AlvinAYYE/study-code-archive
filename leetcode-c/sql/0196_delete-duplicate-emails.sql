-- LeetCode 196. Delete Duplicate Emails／刪除重複的電子郵件
-- 題目：https://leetcode.com/problems/delete-duplicate-emails/
--
-- 題目（繁體中文）
-- Person 表：
--   id    INT      主鍵，每列都有唯一 id
--   email VARCHAR  電子郵件地址，內容不含大寫字母
--
-- 刪除重複的電子郵件，使每個 email 最後只留下 id 最小的那一列。
-- 本題必須提交 DELETE，而不是用 SELECT 顯示結果。執行完畢後，評測器會顯示
-- Person 的 id、email 兩欄；資料列順序不限。
--
-- 範例
-- 輸入 Person：
--   id | email
--    1 | john@example.com
--    2 | bob@example.com
--    3 | john@example.com
-- 輸出 Person：
--   id | email
--    1 | john@example.com
--    2 | bob@example.com
-- 說明：john@example.com 出現兩次，只保留較小的 id = 1。
--
-- 限制與資料規則
--   1. id 是主鍵，因此任兩列的 id 不相同。
--   2. email 只含小寫字母格式，不需要做大小寫正規化。
--   3. 同一 email 可能出現兩次以上，仍只能留下全組最小 id。
--
-- 直觀解題思路
--   1. 將 Person 自我連接：later 代表候選刪除列，earlier 代表同 email 的較早列。
--   2. email 相同且 later.id > earlier.id 時，later 一定不是該組最小 id。
--   3. DELETE 只刪除符合條件的 later；最小 id 找不到更小配對，因此會留下。

DELETE later
FROM Person AS later
JOIN Person AS earlier
  ON earlier.email = later.email
 AND earlier.id < later.id;

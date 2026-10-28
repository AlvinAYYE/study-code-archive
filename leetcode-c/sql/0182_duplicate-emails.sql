-- LeetCode 182. Duplicate Emails／重複的電子郵件
-- 題目（繁體中文）
-- Person(id, email) 中 id 是主鍵，email 不為 NULL 且沒有大寫字母。
-- 找出至少出現兩次的 email，每個重複地址只輸出一次，欄名 Email，順序不限。
-- 例子：[a@b.com, c@d.com, a@b.com] → 只有 a@b.com。
-- 思路：用 GROUP BY 把相同 email 分成一組，再用 HAVING 篩出筆數超過 1 的組。
-- 題目：https://leetcode.com/problems/duplicate-emails/

SELECT email AS Email
FROM Person
GROUP BY email
HAVING COUNT(*) > 1;

-- LeetCode 1517. Find Users With Valid E-Mails
-- Title-CN: 找出有效電子郵件的使用者
--
-- 題目（繁體中文）
-- Users(user_id, name, mail)：網站使用者資料，user_id 是主鍵。
-- 找出有效電子郵件並回傳該列的 user_id、name、mail，順序不限。
-- 有效信箱由 prefix name 與網域組成：prefix 可含大小寫英文字母、數字、底線、句點、
--   連字號，且第一個字元必須是英文字母；網域必須精確為小寫的 @leetcode.com。
--
-- 範例：winston@leetcode.com、bella-@leetcode.com、sally.come@leetcode.com 有效；
--   jonathanisgreat 缺少網域，quarz#2020@leetcode.com 含不允許字元，
--   david69@gmail.com 網域錯誤，.shapo@leetcode.com 的 prefix 不是字母開頭。
--
-- 思路：用正規表示式一次檢查整個 mail：第一個字元限定為英文字母，後續 prefix
--   字元限定在允許集合，最後要求精確的小寫網域。'c' 旗標使網域比對區分大小寫。
-- 複雜度：逐列檢查信箱，概念成本 O(U * L)，U 是使用者數、L 是信箱長度。
-- 方言：REGEXP_LIKE(..., 'c') 是 MySQL 8.0 語法；SQLite 測試需註冊等價正規表示式函式。
-- 題目：https://leetcode.com/problems/find-users-with-valid-e-mails/

SELECT user_id, name, mail
FROM Users
WHERE REGEXP_LIKE(
    mail,
    '^[A-Za-z][A-Za-z0-9_.-]*@leetcode\\.com$',
    'c'
);

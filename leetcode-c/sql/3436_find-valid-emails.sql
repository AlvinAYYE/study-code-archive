-- 3436. 找出有效電子郵件（Find Valid Emails）
-- 題目完整翻譯：從 Users 找出所有符合格式的電子郵件，並依 user_id 升冪回傳 user_id、email。有效格式必須恰有一個 @、以小寫 .com 結尾；@ 前只能有英數字或底線，@ 與 .com 之間至少有一個英文字母且只能是英文字母。
-- 資料表與鍵：Users(user_id INT, email VARCHAR)；user_id 為唯一鍵，每列是一位使用者的電子郵件。
-- 範例輸入：alice@example.com、bob_at_example.com、charlie@example.net、david@domain.com、eve@invalid。
-- 範例輸出：user_id 1 的 alice@example.com，以及 user_id 4 的 david@domain.com。
-- 限制：題目沒有額外列出資料範圍限制。
-- 解題步驟：用錨點固定整個字串；local 部分使用英數字與底線字元集合，@ 後只允許英文字母，最後要求精確的小寫 .com。錨定整個字串也確保只有一個 @ 且沒有額外字元。
-- 複雜度：對 N 個郵件逐筆比對，時間 O(N × L)，L 為郵件長度；額外空間 O(1)。

SELECT
    user_id,
    email
FROM Users
WHERE REGEXP_LIKE(email, '^[A-Za-z0-9_]+@[A-Za-z]+[.]com$', 'c')
ORDER BY user_id ASC;

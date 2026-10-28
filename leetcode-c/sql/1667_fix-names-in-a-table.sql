-- LeetCode 1667. Fix Names in a Table／修正資料表中的姓名格式
-- 題意（繁體中文）
-- Users(user_id, name)：使用者資料，user_id 唯一；name 只含英文字母。把姓名轉成「第一個字母大寫、其餘字母小寫」，
-- 輸出 user_id、修正後的 name，依 user_id 由小到大排序。回傳結果即可，不需修改原表。
-- 範例：aLice 變成 Alice，bOB 變成 Bob，依 user_id 排列。
-- 解題思路：取出第一個字元轉大寫，再把第二個字元起的子字串轉小寫，最後串接兩部分。
-- 步驟：1. LEFT(name, 1) 取首字母並 UPPER。2. SUBSTRING(name, 2) 取其餘部分並 LOWER。3. CONCAT 組合及排序。
-- 複雜度：令 N 為使用者數、L 為姓名長度，時間 O(NL)，額外空間 O(1)（不計輸出）。

SELECT user_id,
       CONCAT(UPPER(LEFT(name, 1)), LOWER(SUBSTRING(name, 2))) AS name
FROM Users
ORDER BY user_id;

-- LeetCode 1141. User Activity for the Past 30 Days I／過去 30 天的使用者活動 I
-- 題目（繁體中文）
-- Activity(user_id, session_id, activity_date, activity_type) 記錄社群網站使用者活動，資料可能重複；
-- 每個 session 僅屬於一位使用者。activity_type 為 open_session、end_session、scroll_down 或 send_message。
-- 統計以 2019-07-27 為最後一天、往前含首尾共 30 天內，每一天的不重複活躍使用者數。
-- 使用者當天至少有一筆活動就算活躍；沒有活躍使用者的日期不輸出。結果欄位為 day、active_users。
-- 範例：2019-07-20 有兩位不同使用者活動，輸出 (2019-07-20, 2)。
-- 解法：只保留 2019-06-28 到 2019-07-27 的資料，按日期分組，再用 COUNT(DISTINCT user_id) 去重計數。
-- 複雜度：概念上掃描活動紀錄一次，日期分組時對使用者去重。

SELECT activity_date AS day,
       COUNT(DISTINCT user_id) AS active_users
FROM Activity
WHERE activity_date BETWEEN '2019-06-28' AND '2019-07-27'
GROUP BY activity_date;

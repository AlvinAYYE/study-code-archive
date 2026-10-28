-- 3497. 分析訂閱轉換（Analyze Subscription Conversion）
-- 題目完整翻譯：訂閱服務提供 7 天免費試用，之後使用者可轉為付費或取消。找出曾從 free_trial 轉成 paid 的使用者，並分別計算其免費試用期間及付費期間的每日平均使用分鐘數，四捨五入到小數點後兩位。取消的活動不納入兩種平均。依 user_id 升冪回傳。
-- 資料表與鍵：UserActivity(user_id INT, activity_date DATE, activity_type VARCHAR, activity_duration INT)；(user_id, activity_date, activity_type) 為唯一鍵；activity_type 為 free_trial、paid 或 cancelled。
-- 範例輸入重點：使用者 1、3、4 同時有 free_trial 與 paid；使用者 2 只有試用後取消。
-- 範例輸出：1 | 45.00 | 76.67；3 | 70.00 | 63.33；4 | 37.50 | 45.00。使用者 2 不列出。
-- 限制：題目沒有額外列出活動列數限制。
-- 解題步驟：按 user_id 分組；AVG 搭配 CASE 僅取 free_trial 或 paid 列的分鐘數，CASE 其他活動回傳 NULL，因此不會進入平均；HAVING 確認兩種活動都至少出現一次，即只保留完成轉換的人。
-- 複雜度：讀取 N 筆活動並分組，約 O(N)；若資料庫需要排序完成分組則最壞 O(N log N)，額外空間 O(U)，U 為使用者數。

SELECT
    user_id,
    ROUND(AVG(CASE WHEN activity_type = 'free_trial' THEN activity_duration END), 2)
        AS trial_avg_duration,
    ROUND(AVG(CASE WHEN activity_type = 'paid' THEN activity_duration END), 2)
        AS paid_avg_duration
FROM UserActivity
GROUP BY user_id
HAVING SUM(CASE WHEN activity_type = 'free_trial' THEN 1 ELSE 0 END) > 0
   AND SUM(CASE WHEN activity_type = 'paid' THEN 1 ELSE 0 END) > 0
ORDER BY user_id ASC;

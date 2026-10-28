-- LeetCode 1934. Confirmation Rate／計算使用者確認率
-- 題意（繁體中文）
-- Signups(user_id, time_stamp)：註冊資料，每位使用者一列。Confirmations(user_id, time_stamp, action)：使用者要求
-- 確認訊息的結果，action 為 confirmed 或 timeout，(user_id, time_stamp) 組合唯一。確認率 = confirmed 訊息數 /
-- 該使用者要求確認的訊息總數。沒有提出任何要求的使用者確認率為 0。四捨五入至小數點後兩位，輸出每位使用者的
-- user_id、confirmation_rate，順序不限。
-- 範例：使用者 6 沒有要求訊息，結果為 0.00；使用者 3 的 2 次皆逾時，為 0.00；使用者 7 的 3 次皆確認，為 1.00；
-- 使用者 2 有 1 次確認、1 次逾時，為 0.50。
-- 解題思路：從 Signups 左連接 Confirmations 以保留零次請求者；AVG(action='confirmed') 就是成功數除以總請求數。
-- 步驟：1. 保留全部註冊使用者。2. 對確認紀錄計算成功比例。3. 沒有紀錄時以 0 取代 NULL。4. 四捨五入兩位。
-- 複雜度：令 U 為使用者數、C 為確認請求數，時間 O(U+C)，分組空間 O(U)。

SELECT signups.user_id,
       COALESCE(ROUND(AVG(confirmations.action = 'confirmed'), 2), 0) AS confirmation_rate
FROM Signups AS signups
LEFT JOIN Confirmations AS confirmations
  ON confirmations.user_id = signups.user_id
GROUP BY signups.user_id;

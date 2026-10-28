-- LeetCode 1683. Invalid Tweets／找出無效推文
-- 題意（繁體中文）
-- Tweets(tweet_id, content)：社群平台的推文資料，tweet_id 唯一。content 只包含英文字母、數字、驚嘆號或空格。
-- 若 content 的字元數嚴格大於 15，該推文無效；找出所有無效推文的 tweet_id，順序不限。
-- 範例：`Let us Code` 長度為 11，是有效推文；`More than fifteen chars are here!` 長度為 33，應回傳其 id。
-- 解題思路：題目限制內容字元集合為 ASCII，因此 MySQL LENGTH 得到的位元組數等於字元數；直接比較是否大於 15。
-- 步驟：1. 逐筆讀取推文。2. 計算 content 長度。3. 只輸出長度大於 15 的 tweet_id。
-- 複雜度：令 N 為推文數、C 為內容總字元數，時間 O(C)，額外空間 O(1)。

SELECT tweet_id
FROM Tweets
WHERE LENGTH(content) > 15;

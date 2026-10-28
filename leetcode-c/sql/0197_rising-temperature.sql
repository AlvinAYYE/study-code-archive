-- LeetCode 197. Rising Temperature／上升的溫度
-- 題目：https://leetcode.com/problems/rising-temperature/
--
-- 題目（繁體中文）
-- Weather 表：
--   id          INT   唯一值
--   recordDate  DATE  記錄日期，表中不會有兩列使用同一天
--   temperature INT   當天溫度
--
-- 找出溫度比「前一天」嚴格更高的所有日期，輸出該日的 id，欄名為 id。
-- 結果順序不限。前一天指相差一個日曆日，不能用 id 大小或排序後的上一列代替。
--
-- 範例
-- 輸入 Weather：
--   id | recordDate | temperature
--    1 | 2015-01-01 | 10
--    2 | 2015-01-02 | 25
--    3 | 2015-01-03 | 20
--    4 | 2015-01-04 | 30
-- 輸出：id = 2、4。
-- 說明：1 月 2 日由 10 升至 25；1 月 4 日由 20 升至 30。
--
-- 限制與資料規則
--   1. id 在 Weather 中唯一。
--   2. recordDate 在 Weather 中唯一。
--   3. 日期可能不連續；缺少昨天資料時，該列不能入選。
--
-- 直觀解題思路
--   1. 將 Weather 自我連接，today 代表待判斷日期，yesterday 代表比較基準。
--   2. 用 DATEDIFF(today.recordDate, yesterday.recordDate) = 1 精確配對昨天。
--   3. 再篩選 today.temperature > yesterday.temperature，輸出 today.id。

SELECT today.id
FROM Weather AS today
JOIN Weather AS yesterday
  ON DATEDIFF(today.recordDate, yesterday.recordDate) = 1
WHERE today.temperature > yesterday.temperature;

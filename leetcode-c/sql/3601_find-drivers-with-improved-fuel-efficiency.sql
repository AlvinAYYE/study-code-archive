-- Title-CN: 找出下半年平均油耗效率提升的駕駛
-- LeetCode 3601. Find Drivers with Improved Fuel Efficiency
-- 題意：每趟效率為 distance_km / fuel_consumed。把 1 至 6 月視為上半年、7 至 12 月視為下半年，
--      分別計算駕駛每趟效率的平均值。只輸出兩個半年都有行程、且下半年平均更高的駕駛；
--      三個數值（上半年、下半年、提升量）都四捨五入至小數點後 2 位，依提升量遞減、姓名遞增排序。
-- 資料表：drivers(driver_id INT 主鍵, driver_name VARCHAR)；trips(trip_id INT 主鍵, driver_id INT,
--        trip_date DATE, distance_km DECIMAL, fuel_consumed DECIMAL)。
-- 範例：Bob 上半年兩趟效率為 100/9 與 250/22，平均約 11.24；下半年一趟為 200/15，約 13.33；
--      改善量以未四捨五入的平均數相減後再取 2 位，結果 2.10。
-- 限制：上半年為 1–6 月、下半年為 7–12 月；兩個期間都必須至少有一趟；效率改善必須大於 0。
-- 解法：1. 按駕駛彙總兩段期間內各趟 distance/fuel 的平均值。2. 篩除缺少任一期間或沒有進步者。
--      3. 對兩個平均值及其差值分別 ROUND 到 2 位並排序。
-- 複雜度：掃描 N 趟行程並按駕駛分組，時間約 O(N)，分組空間 O(D)。

WITH half_year_averages AS (
    SELECT driver_id,
           AVG(CASE WHEN MONTH(trip_date) BETWEEN 1 AND 6
                    THEN distance_km / fuel_consumed END) AS first_half_avg,
           AVG(CASE WHEN MONTH(trip_date) BETWEEN 7 AND 12
                    THEN distance_km / fuel_consumed END) AS second_half_avg
    FROM trips
    GROUP BY driver_id
)
SELECT d.driver_id,
       d.driver_name,
       ROUND(h.first_half_avg, 2) AS first_half_avg,
       ROUND(h.second_half_avg, 2) AS second_half_avg,
       ROUND(h.second_half_avg - h.first_half_avg, 2) AS efficiency_improvement
FROM half_year_averages AS h
JOIN drivers AS d ON d.driver_id = h.driver_id
WHERE h.first_half_avg IS NOT NULL
  AND h.second_half_avg IS NOT NULL
  AND h.second_half_avg > h.first_half_avg
ORDER BY efficiency_improvement DESC, d.driver_name ASC;

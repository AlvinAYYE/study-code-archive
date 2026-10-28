-- LeetCode 1661. Average Time of Process per Machine／每台機器的平均處理時間
-- 題意（繁體中文）
-- Activity(machine_id, process_id, activity_type, timestamp)：工廠網站的處理紀錄；activity_type 只有 start 或
-- end；(machine_id, process_id, activity_type) 是唯一鍵。每個機器上的每個程序恰有一筆 start 與一筆 end，且
-- start 時間早於 end 時間。程序耗時 = end timestamp - start timestamp。對每台機器計算所有程序耗時的平均，
-- 輸出 machine_id、processing_time，四捨五入至小數點後三位，順序不限。
-- 範例：機器 0 的兩個程序分別耗時 1.520-0.712=0.808 秒、4.120-3.140=0.980 秒，平均為 0.894 秒。
-- 解題思路：同一張表依 machine_id、process_id 自我連接，讓 start 列與對應 end 列放在同一列，再依機器取平均。
-- 步驟：1. 用兩欄識別同一程序。2. 篩出一列 start、一列 end。3. 相減並依 machine_id 平均。4. 四捨五入三位。
-- 複雜度：令 A 為活動紀錄數、M 為機器數，時間 O(A)，分組結果空間 O(M)。
-- 限制：題目保證每個程序的開始與結束紀錄都存在。

SELECT starts.machine_id,
       ROUND(AVG(ends.timestamp - starts.timestamp), 3) AS processing_time
FROM Activity AS starts
JOIN Activity AS ends
  ON ends.machine_id = starts.machine_id
 AND ends.process_id = starts.process_id
WHERE starts.activity_type = 'start'
  AND ends.activity_type = 'end'
GROUP BY starts.machine_id;

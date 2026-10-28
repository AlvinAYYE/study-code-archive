-- Title-CN: 找出新冠康復病患與康復天數
-- LeetCode 3586. Find COVID Recovery Patients
-- 題意：病患先在某日驗出 Positive，之後在更晚日期驗出 Negative，才算康復。康復天數是第一筆
--      Positive 到其後第一筆 Negative 的日期差。輸出病患 ID、姓名、年齡、天數，依天數遞增、姓名遞增。
-- 資料表：patients(patient_id INT 主鍵, patient_name VARCHAR, age INT)；covid_tests(test_id INT 主鍵,
--        patient_id INT, test_date DATE, result VARCHAR)，result 可為 Positive、Negative 或 Inconclusive。
-- 範例：Alice 於 2023-01-15 首次陽性，2023-01-25 首次後續陰性，康復 10 天；Carol 在陽性前曾陰性，
--      但 2023-02-10 陽性後於 2023-02-20 陰性，所以也列入，康復 10 天。
-- 限制：陰性必須發生在陽性之後；Inconclusive 不參與計算；只有陽性或只有陰性的病患不列入。
-- 解法：1. 對每位病患找最早陽性日期。2. 在該日期之後找最早陰性日期。3. 用 DATEDIFF 算天數，
--      連接病患資料並排序。
-- 複雜度：依病患與日期彙整測試紀錄，時間約 O(T log T)，分組空間 O(T)。

WITH first_positive AS (
    SELECT patient_id, MIN(test_date) AS positive_date
    FROM covid_tests
    WHERE result = 'Positive'
    GROUP BY patient_id
), recovery AS (
    SELECT fp.patient_id,
           fp.positive_date,
           MIN(ct.test_date) AS negative_date
    FROM first_positive AS fp
    JOIN covid_tests AS ct
      ON ct.patient_id = fp.patient_id
     AND ct.result = 'Negative'
     AND ct.test_date > fp.positive_date
    GROUP BY fp.patient_id, fp.positive_date
)
SELECT p.patient_id,
       p.patient_name,
       p.age,
       DATEDIFF(r.negative_date, r.positive_date) AS recovery_time
FROM recovery AS r
JOIN patients AS p ON p.patient_id = r.patient_id
ORDER BY recovery_time ASC, p.patient_name ASC;

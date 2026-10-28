-- LeetCode 1527. Patients With a Condition／找出患有指定疾病的病患
-- 題意（繁體中文）
-- Patients(patient_id, patient_name, conditions)：病患資料表，patient_id 為唯一識別碼；conditions
-- 以空格分隔零個或多個疾病代碼。找出患有第一型糖尿病的病患，並回傳 patient_id、patient_name、conditions。
-- 只要某一個疾病代碼以 DIAB1 開頭就符合；代碼可能出現在字串開頭，也可能出現在其他代碼之後。
-- 結果順序不限。題目未另外列出數值範圍限制。
-- 範例：Daniel 的 `YFEV COUGH` 不符合；Bob 的 `DIAB100 MYOP` 及 George 的 `ACNE DIAB100` 符合，
-- 因為兩人的其中一個完整代碼都以 DIAB1 開頭。像 `ACNE DIAB2` 則不符合。
-- 解題思路：用正規表示式尋找「字串開頭或空格」後緊接 DIAB1 的位置，避免把 DIAB1 誤認成其他代碼中間的子字串。
-- 步驟：1. 逐筆檢查 conditions。2. 保留符合代碼邊界及 DIAB1 前綴的病患。3. 輸出指定三欄。
-- 複雜度：掃描所有病患與疾病字串，時間 O(總字元數)，額外空間 O(1)。

SELECT patient_id, patient_name, conditions
FROM Patients
WHERE conditions REGEXP '(^| )DIAB1';

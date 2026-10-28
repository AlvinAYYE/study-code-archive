-- LeetCode 610. Triangle Judgement／判斷三角形
-- 題目：https://leetcode.com/problems/triangle-judgement/
--
-- 題目（繁體中文）
-- Triangle 表：
--   x INT  第一條線段長度
--   y INT  第二條線段長度
--   z INT  第三條線段長度
-- 在 SQL 題目中，(x, y, z) 是複合主鍵；每列代表三條線段的長度。
--
-- 對每一列判斷三條線段能否組成三角形，輸出原本的 x、y、z，並增加欄位
-- triangle。可以組成時輸出 'Yes'，否則輸出 'No'；結果順序不限。
--
-- 範例
-- 輸入：
--   x  | y  | z
--   13 | 15 | 30
--   10 | 20 | 15
-- 輸出：
--   x  | y  | z  | triangle
--   13 | 15 | 30 | No
--   10 | 20 | 15 | Yes
-- 說明：13 + 15 <= 30，無法閉合；10、20、15 則滿足三角形條件。
--
-- 限制與資料規則
--   1. (x, y, z) 是複合主鍵，不會有完全相同的三邊組合。
--   2. 任兩邊和必須「嚴格大於」第三邊；等於時三點共線，不是三角形。
--   3. 三個不等式都要成立，不能只檢查其中一組。
--
-- 直觀解題思路
--   1. 三角形成立條件為 x + y > z、x + z > y、y + z > x。
--   2. CASE 同時檢查三個條件；全部成立才回傳 'Yes'。
--   3. 保留三個原始欄位，將 CASE 結果命名為 triangle。

SELECT
    x,
    y,
    z,
    CASE
        WHEN x + y > z AND x + z > y AND y + z > x THEN 'Yes'
        ELSE 'No'
    END AS triangle
FROM Triangle;

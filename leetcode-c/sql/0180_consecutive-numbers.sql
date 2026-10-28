-- LeetCode 180. Consecutive Numbers／連續出現的數字
-- 題目（繁體中文）
-- Logs(id, num) 記錄依序產生的值；id 是從 1 開始自動遞增的主鍵，num 是字串。
-- 找出按 id 順序至少連續出現三次的所有 num。每個符合值只輸出一次，
-- 欄名必須是 ConsecutiveNums，結果順序不限。
--
-- 範例
-- Logs 依序為 [1,1,1,2,1,2,2] → 只有 1 連續出現至少三次，因此輸出 1。
--
-- 限制與規則
-- 「連續」是依 id 由小到大的相鄰資料列判斷；同一數字即使形成四列以上的
-- 連續區段，也只能在結果中出現一次。
--
-- 分步思路
-- 1. 用 LAG 取得目前列前一列與前兩列的 num，視窗順序指定為 id。
-- 2. 若目前 num 同時等於這兩個值，就代表已有至少三列連續相同。
-- 3. DISTINCT 去除長連續區段產生的重複答案。
-- 題目：https://leetcode.com/problems/consecutive-numbers/

SELECT DISTINCT num AS ConsecutiveNums
FROM (
    SELECT num,
           LAG(num, 1) OVER (ORDER BY id) AS previous_num,
           LAG(num, 2) OVER (ORDER BY id) AS two_rows_before
    FROM Logs
) AS compared
WHERE num = previous_num
  AND num = two_rows_before;

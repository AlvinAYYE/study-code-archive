-- LeetCode 619. Biggest Single Number／最大的唯一數字
-- 題目：https://leetcode.com/problems/biggest-single-number/
--
-- 題目（繁體中文）
-- MyNumbers 表只有一欄：
--   num INT  一個整數
-- 此表沒有主鍵，因此同一數字可能出現多次。
--
-- 「唯一數字」是全表恰好出現一次的數字。找出最大的唯一數字，輸出欄名 num；
-- 若沒有任何唯一數字，仍須輸出一列，其值為 NULL。
--
-- 範例 1
-- 輸入：[8, 8, 3, 3, 1, 4, 5, 6]。
-- 唯一數字是 1、4、5、6，其中最大為 6，因此輸出 num = 6。
--
-- 範例 2
-- 輸入：[8, 8, 7, 7, 3, 3, 3]。沒有唯一數字，因此輸出 num = NULL。
--
-- 限制與資料規則
--   1. MyNumbers 沒有主鍵，重複列是合法資料。
--   2. 只有 COUNT(*) = 1 的數字才算唯一，出現兩次以上都不合格。
--   3. 無符合資料時不能回傳空結果，必須回傳一列 NULL。
--
-- 直觀解題思路
--   1. 子查詢按 num 分組，以 HAVING COUNT(*) = 1 留下所有唯一數字。
--   2. 外層用 MAX 取得其中最大值。
--   3. MAX 對空集合會產生一列 NULL，恰好符合沒有唯一數字的要求。

SELECT MAX(num) AS num
FROM (
    SELECT num
    FROM MyNumbers
    GROUP BY num
    HAVING COUNT(*) = 1
) AS single_numbers;

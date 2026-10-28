-- LeetCode 175. Combine Two Tables／合併兩個表
-- 題目（繁體中文）
-- Person(personId, lastName, firstName) 記錄每個人的姓名；personId 是主鍵。
-- Address(addressId, personId, city, state) 記錄地址；addressId 是主鍵。
-- 對 Person 中的每個人，輸出 firstName、lastName、city、state。
-- 若此人在 Address 找不到地址，city 與 state 都輸出 NULL；順序不限。
-- 例子：Person 有 Allen Wang(id=1)、Bob Alice(id=2)，只有 id=2 有
-- New York City / New York 地址 → Allen 的地址欄為 NULL，Bob 的地址欄有值。
-- 思路：以 Person 為左表做 LEFT JOIN。它保留每位人士；沒配對的地址欄
-- 會自動成為 NULL。用 personId 連接，最後只選題目要求的四欄。
-- 題目：https://leetcode.com/problems/combine-two-tables/

SELECT p.firstName, p.lastName, a.city, a.state
FROM Person AS p
LEFT JOIN Address AS a ON a.personId = p.personId;

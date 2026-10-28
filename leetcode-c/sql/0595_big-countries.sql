-- LeetCode 595. Big Countries／大的國家
-- 題目（繁體中文）
-- World(name, continent, area, population, gdp) 記錄國家名稱、洲別、面積、
-- 人口與 GDP；name 是主鍵。
-- 若國家面積至少 3,000,000 平方公里，或人口至少 25,000,000，就屬於大國。
-- 找出所有大國，輸出 name、population、area，順序不限。
--
-- 範例
-- Afghanistan 面積 652230、人口 25500100，因人口達門檻而輸出；
-- Algeria 面積 2381741、人口 37100000，也因人口達門檻而輸出；
-- Albania、Andorra、Angola 的面積與人口都未達門檻，因此不輸出。
--
-- 限制與輸出規則
-- World.name 是唯一值。兩個門檻都是「至少」，所以必須使用 >=；符合面積或
-- 人口任一條件即可。結果欄名與順序依序為 name、population、area。
--
-- 分步思路
-- 1. 以 area >= 3000000 判斷面積條件。
-- 2. 以 population >= 25000000 判斷人口條件。
-- 3. 用 OR 合併兩條件，再投影題目指定的三欄。
-- 題目：https://leetcode.com/problems/big-countries/

SELECT name,
       population,
       area
FROM World
WHERE area >= 3000000
   OR population >= 25000000;

-- LeetCode 262. Trips and Users／行程和使用者
-- 題目：https://leetcode.com/problems/trips-and-users/
--
-- 題目（繁體中文）
-- Trips 表：
--   id INT 主鍵；client_id、driver_id 分別連到 Users.users_id；city_id INT；
--   status ENUM('completed', 'cancelled_by_driver', 'cancelled_by_client')；
--   request_at VARCHAR，表示叫車日期。
-- Users 表：
--   users_id INT 主鍵；banned ENUM('Yes', 'No')；
--   role ENUM('client', 'driver', 'partner')。
--
-- 對 2013-10-01 到 2013-10-03 的每一天，計算「客戶與司機都未被停權」之
-- 行程取消率。取消包含乘客取消與司機取消；取消率等於合格取消行程數除以
-- 合格總行程數，四捨五入到小數點後兩位。只輸出至少有一筆合格行程的日期。
-- 輸出欄名必須是 Day 與 Cancellation Rate，結果順序不限。
--
-- 範例摘要
--   2013-10-01：忽略被停權客戶的行程後共 3 筆，1 筆取消，輸出 0.33。
--   2013-10-02：合格行程共 2 筆，0 筆取消，輸出 0.00。
--   2013-10-03：合格行程共 2 筆，1 筆取消，輸出 0.50。
--
-- 限制與資料規則
--   1. Trips.id 與 Users.users_id 各自為主鍵。
--   2. Trips.client_id、Trips.driver_id 都參照 Users.users_id。
--   3. 客戶或司機任一方 banned = 'Yes'，整筆行程都不納入分子與分母。
--   4. completed 不算取消，兩種 cancelled 狀態都算取消。
--
-- 直觀解題思路
--   1. Trips 分別連接 Users 兩次，取得客戶與司機的停權狀態。
--   2. 先保留指定日期範圍，並要求兩方 banned 都是 'No'。
--   3. 按 request_at 分組；CASE 將取消記為 1、完成記為 0。
--   4. 取消旗標總和除以 COUNT(*)，再 ROUND(..., 2)。

SELECT
    t.request_at AS Day,
    ROUND(
        1.0 * SUM(CASE WHEN t.status <> 'completed' THEN 1 ELSE 0 END) / COUNT(*),
        2
    ) AS `Cancellation Rate`
FROM Trips AS t
JOIN Users AS client
  ON client.users_id = t.client_id
 AND client.banned = 'No'
JOIN Users AS driver
  ON driver.users_id = t.driver_id
 AND driver.banned = 'No'
WHERE t.request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY t.request_at;

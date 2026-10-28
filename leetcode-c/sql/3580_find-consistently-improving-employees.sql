-- Title-CN: 找出最近三次考核持續進步的員工
-- LeetCode 3580. Find Consistently Improving Employees
-- 題意：員工至少要有 3 次績效評核；只看依日期排序最新的 3 次，且評分必須嚴格逐次增加。
--      improvement_score = 最新一次評分 - 這三次中最早一次評分。依分數遞減、姓名遞增排序。
-- 資料表：employees(employee_id INT 主鍵, name VARCHAR)；performance_reviews(review_id INT 主鍵,
--        employee_id INT, review_date DATE, rating INT)。評分範圍 1 到 5。
-- 範例：Alice 的評分依日期為 2、3、4、5；只看最近三次 3、4、5，符合條件，分數為 5-3=2。
--      Bob 最近三次為 2、4、5，分數為 5-2=3；若最近三次中有相同或下降評分則不列入。
-- 限制：至少 3 次評核；只根據最近 3 次；相鄰兩次評分都必須嚴格增加。
-- 解法：1. 對每位員工按日期由新到舊編號。2. 只取編號 1、2、3，彙整出最新、中間、最早評分。
--      3. 檢查 latest > middle > earliest，計算差值後連接員工姓名。
-- 複雜度：R 筆評核依員工與日期排序，時間約 O(R log R)，視窗與彙整空間 O(R)。

WITH numbered_reviews AS (
    SELECT employee_id,
           rating,
           ROW_NUMBER() OVER (
               PARTITION BY employee_id
               ORDER BY review_date DESC, review_id DESC
           ) AS rn
    FROM performance_reviews
), last_three AS (
    SELECT employee_id,
           MAX(CASE WHEN rn = 1 THEN rating END) AS newest_rating,
           MAX(CASE WHEN rn = 2 THEN rating END) AS middle_rating,
           MAX(CASE WHEN rn = 3 THEN rating END) AS oldest_rating
    FROM numbered_reviews
    WHERE rn <= 3
    GROUP BY employee_id
    HAVING COUNT(*) = 3
)
SELECT e.employee_id,
       e.name,
       lt.newest_rating - lt.oldest_rating AS improvement_score
FROM last_three AS lt
JOIN employees AS e ON e.employee_id = lt.employee_id
WHERE lt.newest_rating > lt.middle_rating
  AND lt.middle_rating > lt.oldest_rating
ORDER BY improvement_score DESC, e.name ASC;

-- LeetCode 1873. Calculate Special Bonus／計算員工特別獎金
-- 題意（繁體中文）
-- Employees(employee_id, name, salary)：員工資料，employee_id 唯一。符合以下兩個條件時，bonus 等於 salary：
-- 員工編號是奇數，而且姓名不以大寫字母 M 開頭。其他員工的 bonus 為 0。輸出 employee_id、bonus，依編號遞增排序。
-- 範例：編號 7 的 Addilyn 與編號 9 的 Kannon 符合，獎金等於薪水；偶數編號 2、8，以及名字以 M 開頭的員工 3，獎金為 0。
-- 解題思路：用 CASE 一次判斷編號奇偶與姓名首字母，再選擇薪資或 0。
-- 步驟：1. MOD(employee_id, 2)=1 判斷奇數。2. LEFT(name,1) 不等於 M。3. 兩者皆成立取 salary，否則取 0。
-- 複雜度：令 N 為員工數，時間 O(N)，額外空間 O(1)。

SELECT employee_id,
       CASE
           WHEN MOD(employee_id, 2) = 1 AND LEFT(name, 1) <> 'M' THEN salary
           ELSE 0
       END AS bonus
FROM Employees
ORDER BY employee_id;

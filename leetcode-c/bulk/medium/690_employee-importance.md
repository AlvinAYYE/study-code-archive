# LeetCode 0690. Employee Importance

Title-CN: 員工重要性

## 題目

每位員工有唯一 id、importance 分數，以及直屬下屬 id 清單。給定所有員工和一個 id，回傳該員工與其所有下屬（包含間接下屬）的 importance 總和。

## 範例

1. 輸入：員工 1 的 importance 為 5、下屬為 2 和 3；員工 2、3 的 importance 都是 3；id = 1。輸出：11。
2. 輸入：員工 5 的 importance 為 -3、沒有下屬；id = 5。輸出：-3。

## 限制

- 1 <= employees.length <= 2000
- 員工 id 介於 1 和 2000，且彼此唯一
- -100 <= importance <= 100
- 每位員工最多只有一位直屬主管
- 下屬 id 都存在於 employees

## 解題思路

1. 先建立 id 到 Employee 指標的表，之後用下屬 id 就能直接找到員工資料。
2. 從指定員工開始做深度優先或廣度優先走訪，把每位可到達員工的 importance 加進總和。
3. 每個下屬 id 放入待處理堆疊；處理一位員工時，再把其下屬加入堆疊。
4. 回傳累加結果。題目保證組織階層有效，因此不會形成循環。

## 複雜度

時間 O(E + S)，額外空間 O(2000)；E 為員工數，S 為下屬關係數。

## C 函式簽名

int getImportance(struct Employee** employees, int employeesSize, int* employeesColSize, int id)

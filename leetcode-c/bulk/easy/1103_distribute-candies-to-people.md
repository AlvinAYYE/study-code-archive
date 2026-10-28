# LeetCode 1103. Distribute Candies to People

**難度：Easy**

## 題意完整翻譯

把 candies 顆糖果依序分給一排 num_people 個人：第一次給第 1 人 1 顆、第 2 人 2 顆，依序增加到最後一人；下一輪回到第 1 人，繼續每次多給 1 顆。若糖果不夠完成下一次分配，最後一位收到糖果的人拿走所有剩餘糖果。請回傳每個人最後拿到的糖果數。

## 範例

1. candies = 7, num_people = 4 → [1,2,3,1]
2. candies = 10, num_people = 3 → [5,2,3]

## 限制

- 1 <= candies <= 10⁹
- 1 <= num_people <= 1000

## 解題思路

1. 配置長度為 num_people 的零陣列，代表每個人的糖果數。
2. 從要發出的 1 顆開始，每次把 min(目前應給數量, 剩餘糖果) 加到輪到的人身上。
3. 扣掉已發出的數量，輪到下一個人並把下一份預定數量加一。
4. 糖果發完後回傳陣列。

## 複雜度

- 時間：O(發放次數 + num_people)，發放次數為 O(√candies)
- 空間：O(num_people)（回傳陣列）

## C 函式簽名

~~~c
int* distributeCandies(int candies, int num_people, int* returnSize);
~~~

## 程式如何運作

提交函式依照上述步驟完成計算；程式註解標出每個關鍵動作。本地測試 harness 保留在 .c 檔尾端。

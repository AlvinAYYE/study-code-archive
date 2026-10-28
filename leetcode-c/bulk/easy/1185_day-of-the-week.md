# LeetCode 1185. Day of the Week

**難度：Easy**

## 題意完整翻譯

給定有效的西曆日期 day、month、year，請回傳該日期是星期幾，英文名稱須為 Sunday、Monday、Tuesday、Wednesday、Thursday、Friday 或 Saturday。

## 範例

1. day = 31, month = 8, year = 2019 → Saturday
2. day = 18, month = 7, year = 1999 → Sunday
3. day = 15, month = 8, year = 1993 → Sunday

## 限制

- 輸入日期有效，年份介於 1971 和 2100 之間

## 解題思路

1. 以已知的 1971 年 1 月 1 日（星期五）作為基準日。
2. 加上基準日之後完整經過的年數；每年加 365 天，閏年再多加一天。
3. 再加上當年該月份之前各月的天數，以及當月日期減一。
4. 將總天數加到星期五的索引上並對 7 取餘數，找出星期名稱。閏年需符合西曆規則。

## 複雜度

- 時間：O(year - 1971 + month)，範圍內最多約 130 年
- 空間：O(1) 額外空間，另配置回傳字串

## C 函式簽名

~~~c
char* dayOfTheWeek(int day, int month, int year);
~~~

## 程式如何運作

提交函式依照上述步驟完成計算；程式註解標出每個關鍵動作。本地測試 harness 保留在 .c 檔尾端。

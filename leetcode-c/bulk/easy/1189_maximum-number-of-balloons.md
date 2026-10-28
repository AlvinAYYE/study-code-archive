# LeetCode 1189. Maximum Number of Balloons

**難度：Easy**

## 題意完整翻譯

給定只含小寫英文字母的字串 text，請找出最多可以從這些字母拼出幾個完整的 balloon。每個字母只能使用 text 中實際出現的次數；balloon 裡的 l 和 o 各需要兩個。

## 範例

1. text = "nlaebolko" → 1
2. text = "loonbalxballpoon" → 2
3. text = "leetcode" → 0

## 限制

- 1 <= text.length <= 10⁴
- text 只含小寫英文字母

## 解題思路

1. 統計 text 中 b、a、l、o、n 的出現次數。
2. 每個 balloon 需要 b、a、n 各 1 個，以及 l、o 各 2 個，所以先把 l 和 o 的次數除以 2。
3. 這五種可用數量的最小值，就是能拼出的 balloon 數量。

## 複雜度

- 時間：O(n)
- 空間：O(1)

## C 函式簽名

~~~c
int maxNumberOfBalloons(char* text);
~~~

## 程式如何運作

提交函式依照上述步驟完成計算；程式註解標出每個關鍵動作。本地測試 harness 保留在 .c 檔尾端。

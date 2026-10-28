# LeetCode 1221. Split a String in Balanced Strings

**難度：Easy**

## 題意完整翻譯

平衡字串是 L 與 R 數量相同的字串。給定一個平衡字串 s，請把它切成最多個非空的連續平衡子字串，並回傳切出的子字串數量。

## 範例

1. s = "RLRRLLRLRL" → 4（可切成 "RL"、"RRLL"、"RL"、"RL"）
2. s = "RLRRRLLRLL" → 2
3. s = "LLLLRRRR" → 1

## 限制

- 2 <= s.length <= 1000
- s[i] 是 'L' 或 'R'
- s 本身是平衡字串

## 解題思路

1. 由左至右掃描，用 balance 記錄目前片段中 R 的數量減去 L 的數量。
2. 遇到 R 就加一，遇到 L 就減一。
3. balance 回到 0 時，代表目前片段已平衡；切一段並把答案加一。貪心地在每次歸零時切開，可得到最多片段。

## 複雜度

- 時間：O(n)
- 空間：O(1)

## C 函式簽名

~~~c
int balancedStringSplit(char* s);
~~~

## 程式如何運作

提交函式依照上述步驟完成計算；程式註解標出每個關鍵動作。本地測試 harness 保留在 .c 檔尾端。

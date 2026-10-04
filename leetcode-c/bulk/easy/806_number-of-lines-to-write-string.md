# 0806. Number of Lines To Write String《寫字串所需的行數》

- **Difficulty**: Easy
- **Tags**: array, string
- **題目連結**: https://leetcode.com/problems/number-of-lines-to-write-string/
- **程式碼**: [`806_number-of-lines-to-write-string.c`](./806_number-of-lines-to-write-string.c) — 社群解答（repo akib-islam-coder_leetcodesolutions），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定小寫字母寬度表 widths 與字串 s，每一行最多可容納 100 像素，必須從左至右依序書寫字元。回傳長度為 2 的陣列，分別為使用行數與最後一行已使用的像素數；s 長度最多為 1000。

**思路**：依序累加每個字元寬度；若加入後超過 100，便換新行再處理該字元，最後回傳行數與當前行寬。

## Problem Statement (English)

You are given a string s of lowercase English letters and an array widths denoting how many pixels wide each lowercase English letter is. Specifically, widths[0] is the width of 'a', widths[1] is the width of 'b', and so on.
You are trying to write s across several lines, where each line is no longer than 100 pixels. Starting at the beginning of s, write as many letters on the first line such that the total width does not exceed 100 pixels. Then, from where you stopped in s, continue writing as many letters as you can on the second line. Continue this process until you have written all of s.
Return an array result of length 2 where:
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: widths = [10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10], s = "abcdefghijklmnopqrstuvwxyz"
Output: [3,60]
Explanation: You can write s as follows:
abcdefghij  // 100 pixels wide
klmnopqrst  // 100 pixels wide
uvwxyz      // 60 pixels wide
There are a total of 3 lines, and the last line is 60 pixels wide.

Input: widths = [4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10], s = "bbbcccdddaaa"
Output: [2,4]
Explanation: You can write s as follows:
bbbcccdddaa  // 98 pixels wide
a            // 4 pixels wide
There are a total of 2 lines, and the last line is 4 pixels wide.
```

## 限制 Constraints

widths.length == 26
2 <= widths[i] <= 10
1 <= s.length <= 1000
s contains only lowercase English letters.

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numberOfLines(int* widths, int widthsSize, char * s, int* returnSize){

}
```

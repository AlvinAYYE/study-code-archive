# 0824. Goat Latin《山羊拉丁文》

- **Difficulty**: Easy
- **Tags**: string
- **題目連結**: https://leetcode.com/problems/goat-latin/
- **程式碼**: [`824_goat-latin.c`](./824_goat-latin.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定以單一空格分隔、無前後空白的英文句子，依序將每個單字轉成 Goat Latin。母音開頭的單字直接加上 ma；子音開頭則把首字母移到尾端後加 ma，最後第 i 個單字再加 i 個 a。

**思路**：以空白切分單字，檢查首字母是否為母音後依規則串接，再附加 ma 與隨單字序號增加的 a，最後以空白合併。

## Problem Statement (English)

You are given a string sentence that consist of words separated by spaces. Each word consists of lowercase and uppercase letters only.
We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.) The rules of Goat Latin are as follows:
Return the final sentence representing the conversion from sentence to Goat Latin.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: sentence = "I speak Goat Latin"
Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"

Input: sentence = "The quick brown fox jumped over the lazy dog"
Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
```

## 限制 Constraints

1 <= sentence.length <= 150
sentence consists of English letters and spaces.
sentence has no leading or trailing spaces.
All the words in sentence are separated by a single space.

## 官方 C 函式簽名 Signature

```c
char* toGoatLatin(char* sentence) {
    
}
```

# 0599. Minimum Index Sum of Two Lists《兩個列表的最小索引總和》

- **Difficulty**: Easy
- **Tags**: array, hash-table, string
- **題目連結**: https://leetcode.com/problems/minimum-index-sum-of-two-lists/
- **程式碼**: [`599_minimum-index-sum-of-two-lists.c`](./599_minimum-index-sum-of-two-lists.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定兩個字串陣列，找出同時出現在兩個列表中的字串。對每個共同字串，將它在兩列表中的索引相加，回傳索引總和最小的所有字串；若有並列可任意順序回傳。保證至少存在一個共同字串，且各列表內的字串皆不重複。

**思路**：先以自製雜湊表記錄第一個列表中每個字串的索引，再走訪第二個列表查詢共同字串。持續維護最小索引和，遇到更小值便清空答案，遇到相同值則一併加入。

## Problem Statement (English)

Given two arrays of strings list1 and list2, find the common strings with the least index sum.
A common string is a string that appeared in both list1 and list2.
A common string with the least index sum is a common string such that if it appeared at list1[i] and list2[j] then i + j should be the minimum value among all the other common strings.
Return all the common strings with the least index sum. Return the answer in any order.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"]
Output: ["Shogun"]
Explanation: The only common string is "Shogun".

Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["KFC","Shogun","Burger King"]
Output: ["Shogun"]
Explanation: The common string with the least index sum is "Shogun" with index sum = (0 + 1) = 1.

Input: list1 = ["happy","sad","good"], list2 = ["sad","happy","good"]
Output: ["sad","happy"]
Explanation: There are three common strings:
"happy" with index sum = (0 + 1) = 1.
"sad" with index sum = (1 + 0) = 1.
"good" with index sum = (2 + 2) = 4.
The strings with the least index sum are "sad" and "happy".
```

## 限制 Constraints

1 <= list1.length, list2.length <= 1000
1 <= list1[i].length, list2[i].length <= 30
list1[i] and list2[i] consist of spaces ' ' and English letters.
All the strings of list1 are unique.
All the strings of list2 are unique.
There is at least a common string between list1 and list2.

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findRestaurant(char** list1, int list1Size, char** list2, int list2Size, int* returnSize) {
    
}
```

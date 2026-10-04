# 0692. Top K Frequent Words《前 K 個高頻單詞》

- **Difficulty**: Medium
- **Tags**: array, hash-table, string, trie, sorting, heap-(priority-queue, bucket-sort, counting
- **題目連結**: https://leetcode.com/problems/top-k-frequent-words/
- **程式碼**: [`692_top-k-frequent-words.c`](./692_top-k-frequent-words.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定單詞陣列 words 與整數 k，回傳出現頻率最高的 k 個單詞。結果須按頻率由高到低排列，頻率相同時按字典序排列。

**思路**：以 Trie 為每個不同單詞建立索引並累計出現次數。將單詞與頻率排序為頻率遞減、字典序遞增後，取前 k 個。

## Problem Statement (English)

Given an array of strings words and an integer k, return the k most frequent strings.
Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.
Example 1:
Example 2:
Constraints:
Follow-up: Could you solve it in O(n log(k)) time and O(n) extra space?

## 範例 Examples

```text
Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.

Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
Output: ["the","is","sunny","day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.
```

## 限制 Constraints

1 <= words.length <= 500
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
k is in the range [1, The number of unique words[i]]

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** topKFrequent(char** words, int wordsSize, int k, int* returnSize) {
    
}
```

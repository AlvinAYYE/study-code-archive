# LeetCode 0274. H-Index

Title-CN: H 指數

## 題目

給定研究者每篇論文的引用次數 citations，計算 H 指數 h：至少有 h 篇論文各自被引用至少 h 次，而且其餘論文各自被引用不超過 h 次。回傳最大的 h。

## 範例

1. 輸入：citations = [3,0,6,1,5]；輸出：3。至少 3 篇論文各有 3 次以上引用。
2. 輸入：citations = [1,3,1]；輸出：1。

## 限制

- 1 <= citations.length <= 5000
- 0 <= citations[i] <= 1000

## 解題思路

1. 建立 citations.length + 1 個桶。引用次數超過論文總數的值都放進最後一桶，因為 H 指數不可能大於論文數。
2. 從最大可能的 h 往下掃描，累加引用次數至少為 h 的論文數。
3. 第一個滿足「至少 h 篇論文有至少 h 次引用」的 h，就是最大的 H 指數。

## 複雜度

時間 O(n)，額外空間 O(n)。

## C 函式簽名

int hIndex(int* citations, int citationsSize)

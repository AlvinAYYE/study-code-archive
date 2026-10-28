# LeetCode 0275. H-Index II

Title-CN: H 指數 II

## 題目

給定已依遞增排序的引用次數陣列 citations，計算最大的 H 指數 h：至少 h 篇論文各自被引用至少 h 次。

## 範例

1. 輸入：citations = [0,1,3,5,6]；輸出：3。
2. 輸入：citations = [1,2,100]；輸出：2。

## 限制

- 1 <= citations.length <= 10^5
- 0 <= citations[i] <= 1000
- citations 已依遞增順序排序

## 解題思路

1. 若從索引 i 開始的論文共有 n-i 篇，這些論文的引用次數都至少是 citations[i]。
2. 要讓這 n-i 篇論文符合 H 指數，需滿足 citations[i] >= n-i。
3. 此條件在排序陣列上具有單調性，因此用二分搜尋找第一個符合的位置。
4. 回傳 n-i；若沒有符合位置，二分搜尋會停在 n，答案就是 0。

## 複雜度

時間 O(log n)，額外空間 O(1)。

## C 函式簽名

int hIndex(int* citations, int citationsSize)

# LeetCode 0528. Random Pick with Weight

Title-CN: 依權重隨機挑選

## 題目

給定正整數權重陣列 w。每次呼叫 pickIndex 時回傳一個索引 i，且被選中的機率為 w[i] 除以所有權重總和。

## 範例

1. 輸入：w = [1]；pickIndex 一定回傳 0。
2. 輸入：w = [1,3]；索引 0 的機率為 1/4，索引 1 的機率為 3/4。

## 限制

- 1 <= w.length <= 10^4
- 1 <= w[i] <= 10^5
- pickIndex 呼叫不超過 10^4 次

## 解題思路

1. 建立累積權重陣列。例如權重 [1,3,2] 對應前綴 [1,4,6]。
2. 在 1 到總權重之間等機率抽一個整數 ticket。
3. 用二分搜尋找第一個累積權重大於或等於 ticket 的索引。
4. 每個索引涵蓋的 ticket 數量恰好等於它的權重，因此選取機率符合題目要求。

## 複雜度

建立時間 O(n)，每次 pickIndex 時間 O(log n)，額外空間 O(n)。

## C 函式簽名

Solution* solutionCreate(int* w, int wSize); int solutionPickIndex(Solution* obj); void solutionFree(Solution* obj)

# LeetCode 0519. Random Flip Matrix

Title-CN: 隨機翻轉矩陣

## 題目

給定 m 列 n 欄的全零矩陣。flip 隨機挑一個尚未翻轉的格子，回傳其座標並將它設為 1；reset 將所有格子恢復成 0。flip 保證呼叫時至少還有一個零格。

## 範例

1. 建立 3x1 矩陣；連續 flip 會不重複地回傳 [0,0]、[1,0]、[2,0] 的某種順序。reset 後這些位置都可再次被選中。

## 限制

- 1 <= m, n <= 10^4
- 每次 flip 呼叫時至少有一個尚未翻轉的格子
- flip 和 reset 的呼叫總數不超過 1000

## 解題思路

1. 把矩陣攤平成 0 到 m*n-1 的索引，不實際配置整張矩陣。
2. 把目前剩餘索引看成一個從 0 到 remaining-1 的虛擬陣列；隨機選中一個索引後，將最後一個可用值搬到該位置。
3. 用稀疏映射只記錄被搬動過的位置，避免為最多 10^8 個格子配置記憶體。
4. 將選到的扁平索引換算成 row = index / n、column = index % n。reset 只需清空映射並還原 remaining。

## 複雜度

每次 flip 時間 O(q)，reset 時間 O(1)；額外空間 O(q)，q 是 reset 以來已翻轉的格數，至多 1000。

## C 函式簽名

Solution* solutionCreate(int m, int n); int* solutionFlip(Solution* obj, int* retSize); void solutionReset(Solution* obj); void solutionFree(Solution* obj)

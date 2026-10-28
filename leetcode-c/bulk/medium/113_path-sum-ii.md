# 0113. Path Sum II｜路徑總和 II

- **難度**：中等
- **標籤**：回溯、樹、深度優先搜尋、二元樹
- **題目連結**：[LeetCode 0113](https://leetcode.com/problems/path-sum-ii/)
- **C 程式**：[113_path-sum-ii.c](./113_path-sum-ii.c)

## 題目說明

給定二元樹根節點和目標總和 `targetSum`，回傳所有從根節點走到葉節點、且節點值總和等於目標的路徑。葉節點是沒有左右子節點的節點。每條路徑以節點值陣列表示。

## 範例

```text
輸入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
輸出：[[5,4,11,2],[5,8,4,5]]

輸入：root = [1,2,3], targetSum = 5
輸出：[]

輸入：root = [1,2], targetSum = 0
輸出：[]
```

## 限制

- 節點數介於 `0` 到 `5000`。
- `-1000 <= Node.val <= 1000`。
- `-1000 <= targetSum <= 1000`。

## 解題步驟

1. 深度優先走訪時，用 `path` 保存從根到目前節點的值，並用 `remaining` 記錄距離目標還差多少。
2. 進入節點時把它的值放入 `path`，並從 `remaining` 扣掉該值。
3. 只有走到葉節點且 `remaining` 剛好為 0，才把目前路徑複製到答案；中途和為目標不算，因為路徑必須到葉節點。
4. 分別遞迴左右子樹。共享同一個路徑陣列，回傳時不需要另外建立每層暫存陣列。

## 複雜度

- 時間：`O(n + 輸出元素數)`，每個節點走訪一次，符合的路徑需要複製。
- 額外空間：`O(h)` 遞迴與路徑空間，`h` 是樹高；不含回傳結果。

## LeetCode C 函式簽名

```c
int** pathSum(struct TreeNode* root, int targetSum,
              int* returnSize, int** returnColumnSizes);
```

# 0096. Unique Binary Search Trees｜不同的二元搜尋樹

- **難度**：中等
- **標籤**：數學、動態規劃、二元搜尋樹
- **題目連結**：[LeetCode 0096](https://leetcode.com/problems/unique-binary-search-trees/)
- **C 程式**：[096_unique-binary-search-trees.c](./096_unique-binary-search-trees.c)

## 題目說明

給定整數 `n`，使用值為 `1` 到 `n` 的 `n` 個不同數字建立二元搜尋樹。請回傳結構不同的二元搜尋樹總數。只比較樹的形狀與節點位置，不是比較節點值排列。

## 範例

```text
輸入：n = 3
輸出：5
說明：三個節點可形成五種不同的 BST 結構。

輸入：n = 1
輸出：1
```

## 限制

- `1 <= n <= 19`。

## 解題步驟

1. `dp[count]` 表示用 `count` 個連續值可形成的 BST 數量；空樹只有一種，所以 `dp[0] = 1`。
2. 對每個節點數 `count`，逐一假設其中一個值當根。
3. 若根左邊有 `leftCount` 個值，右邊就有 `count - 1 - leftCount` 個值；左右子樹可以各自獨立選形狀，因此這個根的組合數是兩者數量相乘。
4. 累加所有根的位置，就是 `dp[count]`；最後回傳 `dp[n]`。

## 複雜度

- 時間：`O(n²)`，每個節點數都嘗試所有根位置。
- 額外空間：`O(n)`，保存每種節點數的答案。

## LeetCode C 函式簽名

```c
int numTrees(int n);
```

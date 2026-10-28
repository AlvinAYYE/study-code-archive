# 0098. Validate Binary Search Tree｜驗證二元搜尋樹

- **難度**：中等
- **標籤**：樹、深度優先搜尋、二元搜尋樹
- **題目連結**：[LeetCode 0098](https://leetcode.com/problems/validate-binary-search-tree/)
- **C 程式**：[098_validate-binary-search-tree.c](./098_validate-binary-search-tree.c)

## 題目說明

給定二元樹根節點，判斷它是否為有效的二元搜尋樹（BST）。每個節點都必須滿足：左子樹中所有值嚴格小於該節點，右子樹中所有值嚴格大於該節點；左右子樹本身也都要符合這個規則。相同值不允許出現在同一棵 BST 中。

## 範例

```text
輸入：root = [2,1,3]
輸出：true

輸入：root = [5,1,4,null,null,3,6]
輸出：false
說明：根節點右子樹中的 4 小於根值 5，因此違反 BST 規則。
```

## 限制

- 節點數介於 `1` 到 `10^4`。
- `-2^31 <= Node.val <= 2^31 - 1`。

## 解題步驟

1. 使用中序走訪：有效 BST 的中序結果必須嚴格遞增。
2. 用堆疊模擬遞迴，先一路走到最左節點，再依序取出節點並記錄前一個值。
3. 若目前值小於或等於前一個值，代表順序不是嚴格遞增，立即回傳 `false`。
4. 否則走訪目前節點的右子樹；全部節點都通過後回傳 `true`。

## 複雜度

- 時間：`O(n)`，每個節點走訪一次。
- 額外空間：`O(h)`，堆疊最多保存樹高 `h` 個節點。

## LeetCode C 函式簽名

```c
bool isValidBST(struct TreeNode* root);
```

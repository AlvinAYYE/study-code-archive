# 0331. Verify Preorder Serialization of a Binary Tree《驗證二元樹的前序序列化》

- **Difficulty**: Medium
- **Tags**: string, stack, tree, binary-tree
- **題目連結**: https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/
- **程式碼**: [`331_verify-preorder-serialization-of-a-binary-tree.c`](./331_verify-preorder-serialization-of-a-binary-tree.c) — 社群解答（repo lightmen_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

二元樹以前序走訪序列化時，非空節點記錄其整數值，空節點以 # 表示，項目以逗號分隔。給定序列 preorder，判斷它是否可能是正確的二元樹前序序列化；不可重建樹。

**思路**：以待處理非空節點數量模擬讀取流程：每個非空節點依序讀取兩個子欄位，子欄位不是 # 時便新增一個待處理節點。處理完後再確認字串沒有多餘項目。

## Problem Statement (English)

One way to serialize a binary tree is to use preorder traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as '#'.
For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where '#' represents a null node.
Given a string of comma-separated values preorder, return true if it is a correct preorder traversal serialization of a binary tree.
It is guaranteed that each comma-separated value in the string must be either an integer or a character '#' representing null pointer.
You may assume that the input format is always valid.
Note: You are not allowed to reconstruct the tree.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#"
Output: true

Input: preorder = "1,#"
Output: false

Input: preorder = "9,#,#,1"
Output: false
```

## 限制 Constraints

1 <= preorder.length <= 104
preorder consist of integers in the range [0, 100] and '#' separated by commas ','.

## 官方 C 函式簽名 Signature

```c
bool isValidSerialization(char* preorder) {
    
}
```

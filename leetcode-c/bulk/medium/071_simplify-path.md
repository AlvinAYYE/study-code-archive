# 0071. Simplify Path《簡化路徑》

- **Difficulty**: Medium
- **Tags**: string, stack
- **題目連結**: https://leetcode.com/problems/simplify-path/
- **程式碼**: [`071_simplify-path.c`](./071_simplify-path.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定一個以「/」開頭的有效 Unix 絕對路徑，將它化為規範路徑。連續斜線視為一個，單一「.」表示目前目錄，雙點「..」回到上一層且不得越過根目錄；其他名稱皆視為一般目錄。結果必須以單一「/」開頭，根目錄外不可有結尾斜線。

**思路**：以斜線切分路徑並用堆疊保存目錄名稱，遇到「..」便彈出、遇到「.」略過。最後反轉堆疊並以斜線重新串成結果。

## Problem Statement (English)

You are given an absolute path for a Unix-style file system, which always begins with a slash '/'. Your task is to transform this absolute path into its simplified canonical path.
The rules of a Unix-style file system are as follows:
The simplified canonical path should follow these rules:
Return the simplified canonical path.
Example 1:
Example 2:
Example 3:
Example 4:
Example 5:
Constraints:

## 範例 Examples

```text
Input: path = "/home/"
Output: "/home"
Explanation:
The trailing slash should be removed.

Input: path = "/home//foo/"
Output: "/home/foo"
Explanation:
Multiple consecutive slashes are replaced by a single one.

Input: path = "/home/user/Documents/../Pictures"
Output: "/home/user/Pictures"
Explanation:
A double period ".." refers to the directory up a level (the parent directory).

Input: path = "/../"
Output: "/"
Explanation:
Going one level up from the root directory is not possible.
```

## 限制 Constraints

1 <= path.length <= 3000
path consists of English letters, digits, period '.', slash '/' or '_'.
path is a valid absolute Unix path.

## 官方 C 函式簽名 Signature

```c
char* simplifyPath(char* path) {
    
}
```

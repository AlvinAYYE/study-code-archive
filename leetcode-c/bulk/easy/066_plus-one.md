# 0066. Plus One《加一》

- **難度**：Easy
- **標籤**：array、math
- **題目連結**：https://leetcode.com/problems/plus-one/
- **程式碼**：[`066_plus-one.c`](./066_plus-one.c)

## 題目說明

整數陣列 `digits` 表示一個大整數，每個元素是一位數，並由最高位到最低位排列；除了數字 0 本身外，不含前導零。將此整數加一後，以相同形式回傳結果。

## 範例

```text
輸入：digits = [1,2,3]
輸出：[1,2,4]
說明：123 + 1 = 124。

輸入：digits = [4,3,2,1]
輸出：[4,3,2,2]
說明：4321 + 1 = 4322。

輸入：digits = [9]
輸出：[1,0]
說明：9 + 1 = 10。
```

## 限制

- `1 <= digits.length <= 100`
- `0 <= digits[i] <= 9`
- `digits` 不含前導零。

## 直觀解題思路

1. 配置 `digitsSize + 1` 格結果，令進位 `s = 1`，代表要對原數加一。
2. 從最低位往左計算：目前位存 `(digits[i] + s) % 10`，進位更新成 `(digits[i] + s) / 10`。
3. 若最高位處理完仍有進位，將既有結果右移一格並在最前方放 1。
4. 透過 `returnSize` 告訴呼叫端結果實際有幾位。

- 時間複雜度：`O(n)`
- 回傳陣列空間：`O(n)`；除此之外的額外空間為 `O(1)`

## 官方 C 函式簽名

```c
int* plusOne(int* digits, int digitsSize, int* returnSize);
```

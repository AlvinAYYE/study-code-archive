# 1007. Minimum Domino Rotations For Equal Row｜使兩列相等的最少多米諾旋轉

- **難度**：中等
- **標籤**：陣列、貪心
- **題目連結**：[LeetCode 1007](https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/)
- **C 程式**：[1007_minimum-domino-rotations-for-equal-row.c](./1007_minimum-domino-rotations-for-equal-row.c)

## 題目說明

第 `i` 張多米諾的上半是 `tops[i]`，下半是 `bottoms[i]`，每張都可以翻面交換上下數字。請回傳最少翻幾張，才能讓上排全部相同，或下排全部相同；若做不到回傳 `-1`。

## 範例

```text
輸入：tops = [2,1,2,4,2,2], bottoms = [5,2,6,2,3,2]
輸出：2
說明：翻轉第 2、4 張後，上排可以全部變成 2。

輸入：tops = [3,5,1,2,3], bottoms = [3,6,3,3,4]
輸出：-1
```

## 限制

- `2 <= tops.length <= 2 × 10^4`。
- `bottoms.length == tops.length`。
- `1 <= tops[i], bottoms[i] <= 6`。

## 解題步驟

1. 若某個數字能成為整排的目標，它一定出現在第一張多米諾的上半或下半；因此只需檢查這兩個候選值。
2. 對一個候選值逐張檢查：若某張的上、下兩面都不是候選值，就不可能完成，回傳失敗。
3. 否則分別計算要讓上排相同需要翻幾張、讓下排相同需要翻幾張，取較小值。
4. 兩個候選都失敗時回傳 `-1`。

## 複雜度

- 時間：`O(n)`，最多掃描兩次所有多米諾。
- 額外空間：`O(1)`。

## LeetCode C 函式簽名

```c
int minDominoRotations(int* tops, int topsSize, int* bottoms, int bottomsSize);
```

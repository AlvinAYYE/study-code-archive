# 1010. Pairs of Songs With Total Durations Divisible by 60｜總時長可被 60 整除的歌曲配對

- **難度**：中等
- **標籤**：陣列、雜湊表、計數
- **題目連結**：[LeetCode 1010](https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/)
- **C 程式**：[1010_pairs-of-songs-with-total-durations-divisible-by-60.c](./1010_pairs-of-songs-with-total-durations-divisible-by-60.c)

## 題目說明

給定每首歌的播放秒數 `time`，回傳有幾組不同歌曲配對，其播放時間總和能被 60 整除。每首歌最多使用一次，配對以索引 `i < j` 計算。

## 範例

```text
輸入：time = [30,20,150,100,40]
輸出：3
說明：有效配對的總秒數分別是 180、120、60。

輸入：time = [60,60,60]
輸出：3
說明：三首歌彼此配對，共有三組。
```

## 限制

- `1 <= time.length <= 6 × 10^4`。
- `1 <= time[i] <= 500`。

## 解題步驟

1. 兩個時間相加是否能被 60 整除，只取決於它們除以 60 的餘數。
2. 用 `remainderCount[r]` 記錄已看過、餘數為 `r` 的歌曲數量。
3. 對目前餘數 `r`，需要的配對餘數是 `(60 - r) % 60`；把已出現的這種歌曲數量加入答案。
4. 再將目前歌曲的餘數數量加一，讓後面的歌曲可以和它配對。

## 複雜度

- 時間：`O(n)`，每首歌處理一次。
- 額外空間：`O(1)`，餘數只有 60 種。

## LeetCode C 函式簽名

```c
int numPairsDivisibleBy60(int* time, int timeSize);
```

# 0920. Number of Music Playlists《音樂播放清單數量》

- **Difficulty**: Hard
- **Tags**: math, dynamic-programming, combinatorics
- **題目連結**: https://leetcode.com/problems/number-of-music-playlists/
- **程式碼**: [`920_number-of-music-playlists.c`](./920_number-of-music-playlists.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

有 n 首不同歌曲，請建立長度為 goal 的播放清單，且每一首歌至少要播放一次。某首歌若要再次播放，在此之前必須已播放過至少 k 首其他歌曲。回傳可建立的播放清單數量，結果對 10⁹ + 7 取模。

**思路**：動態規劃以 dp[i][j] 記錄長度 i 的清單使用 j 首不同歌曲的方案數；轉移分別加入一首未用歌曲，或從已可重播的 j-k 首歌曲中選一首。

## Problem Statement (English)

Your music player contains n different songs. You want to listen to goal songs (not necessarily different) during your trip. To avoid boredom, you will create a playlist so that:
Given n, goal, and k, return the number of possible playlists that you can create. Since the answer can be very large, return it modulo 109 + 7.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: n = 3, goal = 3, k = 1
Output: 6
Explanation: There are 6 possible playlists: [1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], and [3, 2, 1].

Input: n = 2, goal = 3, k = 0
Output: 6
Explanation: There are 6 possible playlists: [1, 1, 2], [1, 2, 1], [2, 1, 1], [2, 2, 1], [2, 1, 2], and [1, 2, 2].

Input: n = 2, goal = 3, k = 1
Output: 2
Explanation: There are 2 possible playlists: [1, 2, 1] and [2, 1, 2].
```

## 限制 Constraints

0 <= k < n <= goal <= 100

## 官方 C 函式簽名 Signature

```c
int numMusicPlaylists(int n, int goal, int k) {
    
}
```

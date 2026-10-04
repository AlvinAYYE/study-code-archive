# 0841. Keys and Rooms《鑰匙和房間》

- **Difficulty**: Medium
- **Tags**: depth-first-search, breadth-first-search, graph
- **題目連結**: https://leetcode.com/problems/keys-and-rooms/
- **程式碼**: [`841_keys-and-rooms.c`](./841_keys-and-rooms.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

共有編號 0 到 n−1 的房間，初始只有 0 號房間未上鎖；進入房間後可取得其中列出的房間鑰匙。給定 rooms，其中 rooms[i] 是造訪 i 號房間可取得的相異鑰匙，判斷能否造訪所有房間。

**思路**：程式以佇列從 0 號房間開始進行廣度優先搜尋，並用陣列記錄已造訪房間。每次取出新房間後將其持有、尚未造訪的鑰匙入列，最後比較造訪數量是否等於房間數。

## Problem Statement (English)

There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.
When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.
Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, return true if you can visit all the rooms, or false otherwise.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: rooms = [[1],[2],[3],[]]
Output: true
Explanation: 
We visit room 0 and pick up key 1.
We then visit room 1 and pick up key 2.
We then visit room 2 and pick up key 3.
We then visit room 3.
Since we were able to visit every room, we return true.

Input: rooms = [[1,3],[3,0,1],[2],[0]]
Output: false
Explanation: We can not enter room number 2 since the only key that unlocks it is in that room.
```

## 限制 Constraints

n == rooms.length
2 <= n <= 1000
0 <= rooms[i].length <= 1000
1 <= sum(rooms[i].length) <= 3000
0 <= rooms[i][j] < n
All the values of rooms[i] are unique.

## 官方 C 函式簽名 Signature

```c
bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    
}
```

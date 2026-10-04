# 0457. Circular Array Loop《環形陣列迴圈》

- **Difficulty**: Medium
- **Tags**: array, hash-table, two-pointers
- **題目連結**: https://leetcode.com/problems/circular-array-loop/
- **程式碼**: [`457_circular-array-loop.c`](./457_circular-array-loop.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定非零整數環形陣列，nums[i] 表示從索引 i 向前或向後跳躍的格數，越界時會環繞。判斷是否存在長度至少為 2 的循環，且循環內所有跳躍方向必須相同。存在則回傳 true，否則回傳 false。

**思路**：程式對每個起點以快慢指標追蹤跳躍位置，並確認快指標的每次跳躍都和起點同方向。相遇後排除自我迴圈，符合條件即回傳 true。

## Problem Statement (English)

You are playing a game involving a circular array of non-zero integers nums. Each nums[i] denotes the number of indices forward/backward you must move if you are located at index i:
Since the array is circular, you may assume that moving forward from the last element puts you on the first element, and moving backwards from the first element puts you on the last element.
A cycle in the array consists of a sequence of indices seq of length k where:
Return true if there is a cycle in nums, or false otherwise.
Example 1:
Example 2:
Example 3:
Constraints:
Follow up: Could you solve it in O(n) time complexity and O(1) extra space complexity?

## 範例 Examples

```text
Input: nums = [2,-1,1,2,2]
Output: true
Explanation: The graph shows how the indices are connected. White nodes are jumping forward, while red is jumping backward.
We can see the cycle 0 --> 2 --> 3 --> 0 --> ..., and all of its nodes are white (jumping in the same direction).

Input: nums = [-1,-2,-3,-4,-5,6]
Output: false
Explanation: The graph shows how the indices are connected. White nodes are jumping forward, while red is jumping backward.
The only cycle is of size 1, so we return false.

Input: nums = [1,-1,5,1,4]
Output: true
Explanation: The graph shows how the indices are connected. White nodes are jumping forward, while red is jumping backward.
We can see the cycle 0 --> 1 --> 0 --> ..., and while it is of size > 1, it has a node jumping forward and a node jumping backward, so it is not a cycle.
We can see the cycle 3 --> 4 --> 3 --> ..., and all of its nodes are white (jumping in the same direction).
```

## 限制 Constraints

1 <= nums.length <= 5000
-1000 <= nums[i] <= 1000
nums[i] != 0

## 官方 C 函式簽名 Signature

```c
bool circularArrayLoop(int* nums, int numsSize) {
    
}
```

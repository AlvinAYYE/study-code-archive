# 0735. Asteroid Collision《行星碰撞》

- **Difficulty**: Medium
- **Tags**: array, stack, simulation
- **題目連結**: https://leetcode.com/problems/asteroid-collision/
- **程式碼**: [`735_asteroid-collision.c`](./735_asteroid-collision.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定一列行星，絕對值代表大小，正負號分別代表向右與向左移動，且所有行星速度相同。相遇時較小者爆炸、大小相同者皆爆炸，請回傳所有碰撞結束後仍存在的行星。

**思路**：用堆疊保存尚未消失的行星；只有堆疊頂端向右且目前行星向左時才可能碰撞。反覆比較大小、彈出被摧毀者，直到目前行星被消滅或可安全入堆疊。

## Problem Statement (English)

We are given an array asteroids of integers representing asteroids in a row. The indices of the asteriod in the array represent their relative position in space.
For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.
Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.

Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
```

## 限制 Constraints

2 <= asteroids.length <= 104
-1000 <= asteroids[i] <= 1000
asteroids[i] != 0

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
    
}
```

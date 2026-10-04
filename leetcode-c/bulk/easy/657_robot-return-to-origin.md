# 0657. Robot Return to Origin《機器人能否返回原點》

- **Difficulty**: Easy
- **Tags**: string, simulation
- **題目連結**: https://leetcode.com/problems/robot-return-to-origin/
- **程式碼**: [`657_robot-return-to-origin.c`](./657_robot-return-to-origin.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

機器人從二維平面的原點 (0, 0) 出發，移動字串只包含上、下、左、右四種指令。判斷完成所有等距移動後是否回到原點；機器人的朝向不影響指令意義。

**思路**：掃描字串並分別累加垂直與水平位移。兩個位移最後都為 0 時便回傳 true。

## Problem Statement (English)

There is a robot starting at the position (0, 0), the origin, on a 2D plane. Given a sequence of its moves, judge if this robot ends up at (0, 0) after it completes its moves.
You are given a string moves that represents the move sequence of the robot where moves[i] represents its ith move. Valid moves are 'R' (right), 'L' (left), 'U' (up), and 'D' (down).
Return true if the robot returns to the origin after it finishes all of its moves, or false otherwise.
Note: The way that the robot is "facing" is irrelevant. 'R' will always make the robot move to the right once, 'L' will always make it move left, etc. Also, assume that the magnitude of the robot's movement is the same for each move.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: moves = "UD"
Output: true
Explanation: The robot moves up once, and then down once. All moves have the same magnitude, so it ended up at the origin where it started. Therefore, we return true.

Input: moves = "LL"
Output: false
Explanation: The robot moves left twice. It ends up two "moves" to the left of the origin. We return false because it is not at the origin at the end of its moves.
```

## 限制 Constraints

1 <= moves.length <= 2 * 104
moves only contains the characters 'U', 'D', 'L' and 'R'.

## 官方 C 函式簽名 Signature

```c
bool judgeCircle(char* moves) {
    
}
```

/*
 * LeetCode 390. Elimination Game
 * Title-CN: 消除遊戲
 *
 * 題目翻譯：一開始有遞增排列的整數 [1,2,...,n]。先從左往右，刪除第一個數及之後每隔一個數；
 * 再從右往左，刪除最右邊的數及之後每隔一個數。如此左右交替進行，直到只剩一個數，回傳它。
 *
 * 範例：n=9：
 * [1,2,3,4,5,6,7,8,9] -> [2,4,6,8] -> [2,6] -> [6]，因此回傳 6。
 * n=1 時只有 [1]，回傳 1。
 *
 * 限制：1 <= n <= 10^9。
 *
 * 解題思路：每一輪刪掉一半數字，剩下的數字仍是等距排列，因此只需記錄：
 * head（目前最小的剩餘值）、step（相鄰剩餘值的間距）、remaining（剩餘數量）與方向。
 * 1. 從左往右時，最小值一定被刪除，所以 head 增加 step。
 * 2. 從右往左時，若剩餘數量是奇數，最左端也會被刪除，head 增加 step；若是偶數則不變。
 * 3. 每輪 remaining 減半、step 加倍並切換方向。剩下一個時，head 就是答案。
 *
 * 複雜度：每輪將候選數量減半，時間 O(log n)；額外空間 O(1)。
 *
 * LeetCode C API：int lastRemaining(int n)
 */
#include <stdio.h>

int lastRemaining(int n) {
    long long head = 1;
    long long step = 1;
    long long remaining = n;
    int leftToRight = 1;

    while (remaining > 1) {
        if (leftToRight || (remaining & 1LL) != 0) {
            head += step;
        }
        remaining /= 2;
        step *= 2;
        leftToRight = !leftToRight;
    }
    return (int)head;
}

int main(void) {
    int passed = lastRemaining(9) == 6 &&
                 lastRemaining(1) == 1 &&
                 lastRemaining(2) == 2 &&
                 lastRemaining(3) == 2 &&
                 lastRemaining(4) == 2 &&
                 lastRemaining(8) == 6;

    puts(passed ? "PASS: 390 elimination-game" : "FAIL: 390 elimination-game");
    return passed ? 0 : 1;
}

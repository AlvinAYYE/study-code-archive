/*
 * LeetCode 464. Can I Win／我能贏嗎
 *
 * 題目（繁體中文）
 *   有一個可選數字池 1..maxChoosableInteger。兩位玩家輪流選一個尚未選過的
 *   數字並加到累計總和；第一個讓總和達到或超過 desiredTotal 的玩家獲勝。
 *   雙方都採取最佳策略時，判斷先手是否一定能贏。
 *
 * 範例 1：maxChoosableInteger=10、desiredTotal=11，輸出 false；先手無論
 *   選哪個數字，後手都能補到 11。
 * 範例 2：maxChoosableInteger=10、desiredTotal=0，輸出 true。
 * 範例 3：maxChoosableInteger=10、desiredTotal=1，先手直接選 1，輸出 true。
 * 限制：1 <= maxChoosableInteger <= 20；0 <= desiredTotal <= 300。
 *
 * 解題步驟：
 *   1. 若所有數字總和仍小於目標，任何人都不可能達標，先手必敗；目標小於等於
 *      0 時，先手已達成目標，回傳 true。
 *   2. 用位元遮罩記錄哪些數字已被拿走。例如第 i 位是 1，表示數字 i+1 已用。
 *   3. 對每個遮罩做記憶化搜尋：逐一嘗試未使用的數字；若選它就能直接達標，
 *      或能把局面留給必敗的對手，則目前玩家有必勝策略。
 *   4. 每種已選集合只計算一次。狀態數最多 2^20，每個狀態最多嘗試 20 個數字，
 *      時間 O(n·2^n)，記憶化表空間 O(2^n)，遞迴深度 O(n)。
 *
 * LeetCode C API：bool canIWin(int maxChoosableInteger, int desiredTotal)。
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static bool canWinFrom(int maximum, int remaining, unsigned int usedMask,
                       signed char *memo) {
    if (memo[usedMask] != -1) return memo[usedMask] != 0;

    for (int choice = 1; choice <= maximum; ++choice) {
        unsigned int bit = 1u << (choice - 1);
        if ((usedMask & bit) != 0) continue;

        /* 立即達標，或把必敗局面留給對手，都是當前玩家的勝法。 */
        if (choice >= remaining ||
            !canWinFrom(maximum, remaining - choice, usedMask | bit, memo)) {
            memo[usedMask] = 1;
            return true;
        }
    }
    memo[usedMask] = 0;
    return false;
}

/* ---------- LeetCode submission / 提交區 ---------- */
bool canIWin(int maxChoosableInteger, int desiredTotal) {
    if (desiredTotal <= 0) return true;
    int total = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
    if (total < desiredTotal) return false;

    size_t stateCount = (size_t)1u << maxChoosableInteger;
    signed char *memo = (signed char *)malloc(stateCount * sizeof *memo);
    if (memo == NULL) return false;
    for (size_t i = 0; i < stateCount; ++i) memo[i] = -1;

    bool result = canWinFrom(maxChoosableInteger, desiredTotal, 0, memo);
    free(memo);
    return result;
}
/* ---------- end submission ---------- */

int main(void) {
    int passed = !canIWin(10, 11) &&
                 canIWin(10, 0) &&
                 canIWin(10, 1) &&
                 !canIWin(5, 50) &&
                 canIWin(1, 1);

    puts(passed ? "PASS: 464 can-i-win" : "FAIL: 464 can-i-win");
    return passed ? 0 : 1;
}

/*
 * LeetCode 0754. Reach a Number（抵達目標數字）
 * 題意：從數線 0 出發，第 i 步恰好移動 i 格，可選向左或向右；求到 target 的最少步數。
 * 範例：target=2 -> 3 步（+1,-2,+3）；target=3 -> 2 步（+1,+2）。
 * 限制：-10^9 <= target <= 10^9，target != 0。
 * 解法：先令每步都向目標方向，累加 1+2+...+m 直到不少於 |target|。
 *       若超出的差為偶數，翻轉其中一個步長差值的一半所對應方向，即可抵達。
 * 複雜度：時間 O(sqrt(|target|))，空間 O(1)。
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* ---- community solution ---- */
int reachNumber(int target) {
    long long distance = llabs((long long)target);
    long long sum = 0;
    int moves = 0;
    while (sum < distance || (sum - distance) % 2 != 0) {
        moves++;
        sum += moves;
    }
    return moves;
}

/* ---- generated tests ---- */
int main(void) {
    bool passed = reachNumber(2) == 3 && reachNumber(3) == 2 &&
                  reachNumber(-2) == 3 && reachNumber(1) == 1 &&
                  reachNumber(1000000000) == 44723;
    printf("%s: 0754 reachNumber tests=5\n", passed ? "PASS" : "FAIL");
    return passed ? 0 : 1;
}

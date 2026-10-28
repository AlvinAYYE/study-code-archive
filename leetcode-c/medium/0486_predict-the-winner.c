/*
 * Title-CN: 預測勝者
 * LeetCode 486. Predict the Winner
 *
 * 題目翻譯：兩位玩家輪流從陣列左右兩端拿走一個數字，拿到的分數就是該數字。
 * 兩人都採取最佳策略。第一位玩家最後分數不低於第二位時，回傳 true，否則回傳 false。
 *
 * 例子：[1,5,2] 時第一位玩家無法避免落敗，回傳 false；[1,5,233,7] 時回傳 true。
 *
 * 限制：陣列長度最多 20；數字介於 0 到 10000000。
 *
 * 解題步驟：對每段連續區間，計算目前玩家相對於對手最多能領先多少分。
 * 若拿左端，領先值是 nums[left] 減去對手在剩餘區間能取得的最佳領先；
 * 若拿右端則同理。每個區間取兩者較大值。由短區間逐步擴大，最後答案非負代表先手不輸。
 *
 * 複雜度：區間數量 O(n^2)，每個區間 O(1)，時間 O(n^2)；用一維陣列保存結果，空間 O(n)。
 *
 * LeetCode 提交區：保留 predictTheWinner 函式；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdbool.h>

bool predictTheWinner(int *nums, int numsSize) {
    int bestDifference[20];
    for (int i = 0; i < numsSize; ++i) {
        bestDifference[i] = nums[i];
    }

    for (int length = 2; length <= numsSize; ++length) {
        for (int left = 0; left + length <= numsSize; ++left) {
            int right = left + length - 1;
            int takeLeft = nums[left] - bestDifference[left + 1];
            int takeRight = nums[right] - bestDifference[left];
            bestDifference[left] = takeLeft > takeRight ? takeLeft : takeRight;
        }
    }
    return bestDifference[0] >= 0;
}

int main(void) {
    int lose[] = {1, 5, 2};
    int win[] = {1, 5, 233, 7};
    int tie[] = {1, 1};
    assert(!predictTheWinner(lose, 3));
    assert(predictTheWinner(win, 4));
    assert(predictTheWinner(tie, 2));
    return 0;
}

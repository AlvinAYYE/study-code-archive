/*
 * Title-CN: 兩鍵鍵盤
 * LeetCode 650. 2 Keys Keyboard
 *
 * 題目翻譯：螢幕一開始只有一個字母 A。你只有「全選複製」與「貼上」兩種操作，
 * 請計算最少操作幾次才能讓螢幕上恰好有 n 個 A。
 *
 * 例子：n=3 時先複製一次，再貼上兩次，共 3 步；n=1 時不需操作，答案是 0。
 *
 * 限制：1 <= n <= 1000。
 *
 * 解題步驟：每一段操作都會把目前 A 的數量乘上一個整數因數。例如從 1 變成 9，
 * 可連續乘 3 兩次，代表做 3+3 步。把 n 分解成質因數後，每個質因數就是一段
 * 最省的「複製一次、貼上若干次」操作成本；把質因數相加即為最少步數。
 *
 * 複雜度：試除到平方根，時間 O(sqrt(n))，額外空間 O(1)。
 *
 * LeetCode 提交區：保留 minSteps 函式；main() 僅供本機測試。
 */

#include <assert.h>

int minSteps(int n) {
    int steps = 0;
    for (int factor = 2; factor * factor <= n; ++factor) {
        while (n % factor == 0) {
            steps += factor;
            n /= factor;
        }
    }
    if (n > 1) {
        steps += n;
    }
    return steps;
}

int main(void) {
    assert(minSteps(1) == 0);
    assert(minSteps(3) == 3);
    assert(minSteps(9) == 6);
    assert(minSteps(12) == 7);
    return 0;
}

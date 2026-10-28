/*
 * Title-CN: 燈泡開關 II
 * LeetCode 672. Bulb Switcher II
 *
 * 題意翻譯：有 n 顆一開始全亮的燈泡，以及 4 種按鈕：切換全部燈、切換奇數位置、
 * 切換偶數位置、切換位置為 1+3k 的燈。恰好按 m 次按鈕後，回傳可能出現的不同狀態數。
 *
 * 範例：n = 3、m = 1，回傳 4，因為四個按鈕各自會產生一種狀態。
 *
 * 限制：0 <= n,m <= 1000。
 *
 * 解題思路：每個按鈕按兩次會抵銷，所以只需記錄四個按鈕各按偶數或奇數次，
 * 一共最多 16 種組合。若某組合有 p 個按鈕按奇數次，只有當 p <= m 且 m-p 為偶數
 * 時才能恰好按 m 次（多出的次數可用重複按鈕兩次補齊）。四種燈泡規則每 6 格重複，
 * 因此只需模擬前 min(n,6) 顆，再把相同狀態去重。
 *
 * 複雜度：時間 O(16*6)，空間 O(2^6)。
 * LeetCode 介面：保留 flipLights；main() 僅供本機測試。
 */

#include <assert.h>

int flipLights(int n, int presses) {
    int bulbs = n < 6 ? n : 6;
    unsigned int initial = bulbs == 0 ? 0U : (1U << bulbs) - 1U;
    unsigned int patterns[4] = {0, 0, 0, 0};
    for (int position = 1; position <= bulbs; ++position) {
        unsigned int bit = 1U << (position - 1);
        patterns[0] |= bit;                 /* 全部位置 */
        if (position % 2 == 1) patterns[1] |= bit;
        else patterns[2] |= bit;
        if ((position - 1) % 3 == 0) patterns[3] |= bit;
    }

    int seen[64] = {0};
    int distinct = 0;
    for (int mask = 0; mask < 16; ++mask) {
        int oddPresses = 0;
        unsigned int state = initial;
        for (int button = 0; button < 4; ++button) {
            if ((mask & (1 << button)) != 0) {
                ++oddPresses;
                state ^= patterns[button];
            }
        }
        if (oddPresses <= presses && (presses - oddPresses) % 2 == 0
            && !seen[state]) {
            seen[state] = 1;
            ++distinct;
        }
    }
    return distinct;
}

int main(void) {
    assert(flipLights(1, 1) == 2);
    assert(flipLights(2, 1) == 3);
    assert(flipLights(3, 1) == 4);
    assert(flipLights(3, 2) == 7);
    assert(flipLights(3, 3) == 8);
    assert(flipLights(0, 5) == 1);
    return 0;
}

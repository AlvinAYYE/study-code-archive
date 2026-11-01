/*
 * ==========================================================================
 * UVa 10205 - Stack 'em Up
 * Title-CN: 紙牌洗牌排列置換複合模擬
 * Difficulty: UVa Star 1
 * Tags: simulation
 * URL: https://onlinejudge.org/external/102/10205.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given known 52-card shuffles (permutations) and a sequence of dealer shuffles, determine the final order of cards.
 *
 * [中文] 題目說明:
 *     給定若干套已知規則的 52 張撲克牌洗牌置換規則，依序模擬發牌員執行的洗牌動作，輸出最終牌組順序。
 *
 * [EN] Approach:
 *     Start with identity array cards[i] = i. For each shuffle index k, apply deck[i] = old_deck[shuffles[k][i] - 1].
 * [中文] 思路:
 *     以 1..52 代表初始牌組，每次選定指定洗牌規則進行置換映射：new_deck[i] = old_deck[perm[i] - 1]。
 * ==========================================================================
 * UVa Online Judge Submission Template:
 * #include <stdio.h>
 * #include <stdlib.h>
 * #include <string.h>
 * #include <math.h>
 *
 * int main(void) {
 *     // Read input and call logic function
 *     return 0;
 * }
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

void solve_uva10205(int n_moves, int moves[], int perm[52], int deck[52]) {
    for (int i = 0; i < 52; i++) deck[i] = i + 1;
    int temp[52];
    for (int m = 0; m < n_moves; m++) {
        for (int i = 0; i < 52; i++) temp[i] = deck[perm[i] - 1];
        memcpy(deck, temp, sizeof(temp));
    }
}

int main(void) {

    int p[52], d[52], m[] = {0};
    for (int i = 0; i < 52; i++) p[i] = (i + 1) % 52 + 1; // cyclic shift
    solve_uva10205(1, m, p, d);
    int ok = (d[0] == 2);
    printf("%s: UVa 10205 - Stack 'em Up\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

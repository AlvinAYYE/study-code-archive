/*
 * LeetCode 514. Freedom Trail（自由之路）
 *
 * 題意（繁體中文）：
 *   有一個環形字母盤 ring，以及要拼出的字串 key。起始時 ring[0] 位於
 *   指針位置。每次要拼一個字母，可以順時針或逆時針旋轉字母盤，讓該字母
 *   對準指針，再按下中央按鈕。旋轉一格與按按鈕都各算一步。請回傳拼完
 *   key 所需的最少步數。題目保證 key 中每個字母都能在 ring 找到。
 *
 * 範例：
 *   1. ring="godding", key="gd"，回傳 4。
 *      拼 g 不用轉，按一次；接著逆時針轉兩格對準 d，再按一次，共 4 步。
 *   2. ring="godding", key="godding"，回傳 13。
 *
 * 限制：ring 與 key 長度皆為 1..100；只含小寫英文字母；key 一定可拼出。
 *
 * 解題步驟：
 *   1. 用 dp[i] 記錄拼完目前前綴後，指針停在 ring[i] 時的最少步數。
 *      一開始只有位置 0 可達，成本是 0。
 *   2. 依序處理 key 的每個字母。對每個可能的目標位置，嘗試從所有上一輪
 *      的位置轉過來。環上的最短旋轉距離是兩方向距離的較小值。
 *   3. 每次轉到目標字母後還要按按鈕，所以轉動成本再加 1。更新下一輪 dp，
 *      最後取所有位置中的最小值。
 *
 * 複雜度：令 n=ring 長度、m=key 長度，時間 O(m*n^2)，額外空間 O(n)。
 * LeetCode C API：int findRotateSteps(char* ring, char* key)
 */
#include <limits.h>
#include <stdio.h>
#include <string.h>

int findRotateSteps(char *ring, char *key) {
    int ringLength = (int)strlen(ring);
    int keyLength = (int)strlen(key);
    int dp[101], next[101];
    const int infinity = INT_MAX / 4;

    for (int i = 0; i < ringLength; ++i) dp[i] = infinity;
    dp[0] = 0;

    for (int k = 0; k < keyLength; ++k) {
        for (int target = 0; target < ringLength; ++target) next[target] = infinity;

        for (int from = 0; from < ringLength; ++from) {
            if (dp[from] == infinity) continue;
            for (int target = 0; target < ringLength; ++target) {
                if (ring[target] != key[k]) continue;

                int clockwise = target - from;
                if (clockwise < 0) clockwise += ringLength;
                int counterclockwise = ringLength - clockwise;
                int rotation = clockwise < counterclockwise ? clockwise : counterclockwise;
                int cost = dp[from] + rotation + 1; /* 旋轉後按一次中央按鈕 */
                if (cost < next[target]) next[target] = cost;
            }
        }

        for (int i = 0; i < ringLength; ++i) dp[i] = next[i];
    }

    int answer = infinity;
    for (int i = 0; i < ringLength; ++i)
        if (dp[i] < answer) answer = dp[i];
    return answer;
}

int main(void) {
    char ring1[] = "godding", key1[] = "gd";
    char ring2[] = "godding", key2[] = "godding";
    char ring3[] = "abc", key3[] = "cba";
    int passed = findRotateSteps(ring1, key1) == 4 &&
                 findRotateSteps(ring2, key2) == 13 &&
                 findRotateSteps(ring3, key3) == 6;
    puts(passed ? "PASS: 514 freedom-trail" : "FAIL: 514 freedom-trail");
    return passed ? 0 : 1;
}

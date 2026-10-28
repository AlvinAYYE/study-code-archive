/*
 * LeetCode 691. Stickers to Spell Word（貼紙拼字）
 *
 * 題意（繁體中文）：
 *   有多種貼紙，每張貼紙上印著一個小寫英文字。你可以把貼紙上的單字剪成
 *   單個字母，再任意重新排列；每種貼紙都可以使用無限次。給定目標字串
 *   target，請回傳拼出它所需的最少貼紙張數；若無法拼出，回傳 -1。
 *
 * 範例：
 *   1. stickers=["with","example","science"], target="thehat"，回傳 3。
 *      使用兩張 "with" 和一張 "example" 可以湊出目標字母。
 *   2. stickers=["notice","possible"], target="basicbasic"，回傳 -1。
 *      貼紙中沒有字母 c，無法完成目標。
 *   3. stickers=["a","b","ab"], target="ab"，回傳 1。
 *
 * 限制：貼紙種類數 1..50；每張長度 1..10；target 長度 1..15；只含小寫字母。
 *
 * 解題步驟：
 *   1. 用位元遮罩表示 target 哪些位置已經被字母填滿。因為長度最多 15，
 *      總狀態數最多 2^15。
 *   2. dp[mask] 表示填好 mask 所代表位置所需的最少貼紙數。從每個可達狀態
 *      出發，試用一張貼紙；依序把它提供的字母填到尚未填好的相同目標字母。
 *   3. 新遮罩一定比舊遮罩大，因此依數值由小到大走訪狀態，就能在更新前先
 *      完成所有較小狀態。最後完整遮罩的答案若仍不可達，回傳 -1。
 *
 * 複雜度：目標長度為 m、貼紙種類數為 S，時間 O(2^m*S*(m+26))，額外空間
 *   O(2^m + 26*S)。字母表固定為 26 個小寫英文字母。
 * LeetCode C API：int minStickers(char** stickers, int stickersSize, char* target)
 */
#include <limits.h>
#include <stdio.h>
#include <string.h>

int minStickers(char **stickers, int stickersSize, char *target) {
    int targetLength = (int)strlen(target);
    int stateCount = 1 << targetLength;
    int fullMask = stateCount - 1;
    int stickerCounts[50][26] = {{0}};
    for (int i = 0; i < stickersSize; ++i) {
        for (const char *p = stickers[i]; *p != '\0'; ++p)
            ++stickerCounts[i][*p - 'a'];
    }

    int dp[1 << 15];
    for (int mask = 0; mask < stateCount; ++mask) dp[mask] = INT_MAX / 4;
    dp[0] = 0;

    for (int mask = 0; mask < stateCount; ++mask) {
        if (dp[mask] == INT_MAX / 4) continue;
        for (int sticker = 0; sticker < stickersSize; ++sticker) {
            int remaining[26];
            memcpy(remaining, stickerCounts[sticker], sizeof remaining);
            int nextMask = mask;
            for (int position = 0; position < targetLength; ++position) {
                int bit = 1 << position;
                int letter = target[position] - 'a';
                if ((nextMask & bit) == 0 && remaining[letter] > 0) {
                    nextMask |= bit;
                    --remaining[letter];
                }
            }
            if (nextMask != mask && dp[nextMask] > dp[mask] + 1)
                dp[nextMask] = dp[mask] + 1;
        }
    }

    return dp[fullMask] == INT_MAX / 4 ? -1 : dp[fullMask];
}

int main(void) {
    char *stickers1[] = {"with", "example", "science"};
    char target1[] = "thehat";
    char *stickers2[] = {"notice", "possible"};
    char target2[] = "basicbasic";
    char *stickers3[] = {"a", "b", "ab"};
    char target3[] = "ab";
    char *stickers4[] = {"a"};
    char target4[] = "aaa";
    int passed = minStickers(stickers1, 3, target1) == 3 &&
                 minStickers(stickers2, 2, target2) == -1 &&
                 minStickers(stickers3, 3, target3) == 1 &&
                 minStickers(stickers4, 1, target4) == 3;
    puts(passed ? "PASS: 691 stickers-to-spell-word"
                : "FAIL: 691 stickers-to-spell-word");
    return passed ? 0 : 1;
}

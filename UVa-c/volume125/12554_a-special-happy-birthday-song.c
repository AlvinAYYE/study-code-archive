/*
 * ==========================================================================
 * UVa 12554 - A Special Happy Birthday Song
 * Title-CN: 生日快樂歌歌詞輪唱循環指派
 * Difficulty: UVa Star 1
 * Tags: string, simulation
 * URL: https://onlinejudge.org/external/125/12554.pdf
 * ==========================================================================
 * [EN] Problem:
 *     N people sing the 16-word Happy Birthday song in turn. Ensure everyone sings at least once and the entire song is completed in whole rounds.
 *
 * [中文] 題目說明:
 *     N 個人輪流朗唱 16 個單詞的生日快樂歌歌詞，確保每個人至少唱過一次且最後一首歌必須完整唱完 16 句。
 *
 * [EN] Approach:
 *     Total words sung is the smallest multiple of 16 that is >= N. Print name[i % N] with song[i % 16].
 * [中文] 思路:
 *     總唱誦詞數為大於等於 N 之最小 16 的倍數，使用迴圈將 name[i % N] 與歌詞詞彙 song[i % 16] 配對印出。
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

int total_song_words(int n) {
    int rounds = (n + 15) / 16;
    return rounds * 16;
}

int main(void) {

    int ok = (total_song_words(3) == 16 && total_song_words(17) == 32);
    printf("%s: UVa 12554 - A Special Happy Birthday Song\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

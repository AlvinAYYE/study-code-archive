/*
 * LeetCode 466. Count The Repetitions／統計重複次數
 *
 * 題目（繁體中文）
 *   設 str=[s,n] 代表把 s 連接 n 次。若刪除 str1 的部分字元後，可以得到
 *   str2 重複 m 次的字串，請回傳最大的 m。這裡 str1=[s1,n1]、
 *   str2=[s2,n2]，所以答案要把可得到的完整 s2 個數再除以 n2。
 *
 * 範例 1：s1="acb"、n1=4、s2="ab"、n2=2。每份 "acb" 可抽出一個 "ab"，
 *   因此可抽出 4 個 "ab"，等於 ["ab",2]，輸出 2。
 * 範例 2：s1="acb"、n1=1、s2="acb"、n2=1，輸出 1。
 * 限制：s1、s2 長度 1..100，只含小寫英文字母；1 <= n1,n2 <= 10^6。
 *
 * 解題步驟：
 *   1. 依序掃描每份 s1，貪心匹配 s2 的下一個字元；每完成一整個 s2，就記錄一次。
 *   2. 每掃完一份 s1，記下目前已匹配到 s2 的位置，以及完成的 s2 份數。
 *   3. 若相同的 s2 位置再次出現，兩次之間就是可重複的循環：每循環消耗固定
 *      份數的 s1，也完成固定份數的 s2。
 *   4. 一次跳過剩餘可重複循環，只逐份處理循環後不足一輪的尾端。
 *   最多觀察 |s2|+1 個區塊狀態，因此時間 O(|s1|×|s2|+|s1|)，空間 O(|s2|)。
 *
 * LeetCode C API：int getMaxRepetitions(char* s1, int n1, char* s2, int n2)。
 */
#include <stdio.h>
#include <string.h>

#define MAX_S2_LENGTH 100

/* ---------- LeetCode submission / 提交區 ---------- */
int getMaxRepetitions(char *s1, int n1, char *s2, int n2) {
    if (s1 == NULL || s2 == NULL || n1 <= 0 || n2 <= 0) return 0;
    int length1 = (int)strlen(s1);
    int length2 = (int)strlen(s2);
    if (length1 == 0 || length2 == 0 || length2 > MAX_S2_LENGTH) return 0;

    int seenBlock[MAX_S2_LENGTH + 1];
    long long seenCompleted[MAX_S2_LENGTH + 1];
    for (int i = 0; i <= MAX_S2_LENGTH; ++i) {
        seenBlock[i] = -1;
        seenCompleted[i] = 0;
    }

    int nextS2 = 0;
    int blocksDone = 0;
    long long completedS2 = 0;
    int cycleSkipped = 0;
    seenBlock[0] = 0; /* 還沒讀 s1 時，尚未開始匹配 s2。 */

    while (blocksDone < n1) {
        for (int i = 0; i < length1; ++i) {
            if (s1[i] == s2[nextS2]) {
                ++nextS2;
                if (nextS2 == length2) {
                    nextS2 = 0;
                    ++completedS2;
                }
            }
        }
        ++blocksDone;

        if (cycleSkipped) continue;
        if (seenBlock[nextS2] >= 0) {
            int cycleBlocks = blocksDone - seenBlock[nextS2];
            long long cycleCompleted = completedS2 - seenCompleted[nextS2];
            int remainingBlocks = n1 - blocksDone;
            int wholeCycles = remainingBlocks / cycleBlocks;
            blocksDone += wholeCycles * cycleBlocks;
            completedS2 += (long long)wholeCycles * cycleCompleted;
            cycleSkipped = 1;
        } else {
            seenBlock[nextS2] = blocksDone;
            seenCompleted[nextS2] = completedS2;
        }
    }
    return (int)(completedS2 / n2);
}
/* ---------- end submission ---------- */

int main(void) {
    char s1a[] = "acb", s2a[] = "ab";
    char s1b[] = "acb", s2b[] = "acb";
    char s1c[] = "aaa", s2c[] = "aa";
    int passed = getMaxRepetitions(s1a, 4, s2a, 2) == 2 &&
                 getMaxRepetitions(s1b, 1, s2b, 1) == 1 &&
                 getMaxRepetitions(s1c, 3, s2c, 1) == 4;

    puts(passed ? "PASS: 466 count-the-repetitions"
                : "FAIL: 466 count-the-repetitions");
    return passed ? 0 : 1;
}

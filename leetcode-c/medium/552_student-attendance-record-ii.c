/*
 * LeetCode 552. Student Attendance Record II（學生出勤紀錄 II）
 *
 * 題意（繁體中文）：
 *   每天的出勤狀態只有三種：P 代表到課、A 代表缺席、L 代表遲到。長度為 n
 *   的紀錄符合獎勵資格，必須同時滿足：整份紀錄缺席少於兩次，而且不能有
 *   連續三天或更多天遲到。請計算符合資格的紀錄數，答案對 1,000,000,007
 *   取餘數。
 *
 * 範例：
 *   1. n=2，回傳 8。只有 "AA" 不合格，其餘 8 種紀錄都符合條件。
 *   2. n=1，回傳 3，P、A、L 三種單日紀錄都合格。
 *   3. n=10101，回傳 183236316。
 *
 * 限制：1 <= n <= 100000。
 *
 * 解題步驟：
 *   1. 狀態 dp[a][l] 表示目前用了 a 次缺席（a 只有 0 或 1），且結尾連續
 *      遲到 l 天（l 為 0、1、2）的紀錄數。
 *   2. 新增 P：缺席數不變，連續遲到歸零；新增 L：遲到數加一，但不能超過
 *      2；新增 A：只有尚未缺席過才能新增，且連續遲到歸零。
 *   3. 每天用一個新的 2x3 表累計下一輪狀態，所有加法都取模。只保留前後
 *      兩輪，因此不必保存全部 n 天的資料。
 *
 * 複雜度：時間 O(n)，額外空間 O(1)。
 * LeetCode C API：int checkRecord(int n)
 */
#include <stdio.h>

#define MODULO 1000000007

int checkRecord(int n) {
    long long dp[2][3] = {{0}};
    dp[0][0] = 1;

    for (int day = 0; day < n; ++day) {
        long long next[2][3] = {{0}};
        for (int absences = 0; absences <= 1; ++absences) {
            for (int lateRun = 0; lateRun <= 2; ++lateRun) {
                long long ways = dp[absences][lateRun];
                if (ways == 0) continue;

                /* 到課：連續遲到天數歸零。 */
                next[absences][0] = (next[absences][0] + ways) % MODULO;
                /* 遲到：最多只能連續兩天。 */
                if (lateRun < 2)
                    next[absences][lateRun + 1] =
                        (next[absences][lateRun + 1] + ways) % MODULO;
                /* 缺席：整份紀錄最多一次。 */
                if (absences == 0)
                    next[1][0] = (next[1][0] + ways) % MODULO;
            }
        }
        for (int a = 0; a <= 1; ++a)
            for (int l = 0; l <= 2; ++l) dp[a][l] = next[a][l];
    }

    long long answer = 0;
    for (int a = 0; a <= 1; ++a)
        for (int l = 0; l <= 2; ++l) answer += dp[a][l];
    return (int)(answer % MODULO);
}

int main(void) {
    int passed = checkRecord(2) == 8 && checkRecord(1) == 3 &&
                 checkRecord(3) == 19 && checkRecord(10101) == 183236316;
    puts(passed ? "PASS: 552 student-attendance-record-ii"
                : "FAIL: 552 student-attendance-record-ii");
    return passed ? 0 : 1;
}

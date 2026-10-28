/*
 * LeetCode 600. Non-negative Integers without Consecutive Ones
 * （不含連續 1 的非負整數）
 *
 * 題意（繁體中文）：
 *   給定正整數 n，請計算區間 [0,n] 中有多少個非負整數，其二進位表示不含
 *   連續的兩個 1。
 *
 * 範例：
 *   1. n=5，回傳 5。0、1、2、4、5 的二進位表示符合條件，只有 3 (11) 不符合。
 *   2. n=1，回傳 2，符合者為 0、1。
 *   3. n=2，回傳 3，符合者為 0、1、2。
 *
 * 限制：1 <= n <= 10^9。
 *
 * 解題步驟：
 *   1. 先計算長度為 i 的二進位字串中，不含連續 1 的數量 ways[i]。
 *      開頭若放 0，剩下 i-1 位；若放 1，下一位必須是 0，剩下 i-2 位，
 *      因此 ways[i]=ways[i-1]+ways[i-2]。
 *   2. 從 n 的最高位往最低位掃描。當 n 的某位是 1 時，先把該位改成 0，
 *      後面剩下的位數可任意組成合法字串，將 ways[剩餘位數] 加進答案。
 *   3. 若掃描到 n 本身出現連續 11，n 及其尚未分岔的前綴都不合法，已累加
 *      的數字就是答案；若掃描完沒有連續 1，再把 n 本身也算入答案。
 *
 * 複雜度：時間 O(log n)，額外空間 O(log n)。
 * LeetCode C API：int findIntegers(int n)
 */
#include <stdio.h>

int findIntegers(int n) {
    int ways[31];
    ways[0] = 1;
    ways[1] = 2;
    for (int bits = 2; bits <= 30; ++bits)
        ways[bits] = ways[bits - 1] + ways[bits - 2];

    int answer = 0;
    int previousWasOne = 0;
    for (int bit = 30; bit >= 0; --bit) {
        if ((n & (1 << bit)) == 0) {
            previousWasOne = 0;
            continue;
        }

        /* 此位改為 0 後，剩下 bit 位有 ways[bit] 種合法填法。 */
        answer += ways[bit];
        if (previousWasOne) return answer; /* n 的前綴已含連續 11。 */
        previousWasOne = 1;
    }
    return answer + 1; /* n 本身也沒有連續 1。 */
}

int main(void) {
    int passed = findIntegers(5) == 5 && findIntegers(1) == 2 &&
                 findIntegers(2) == 3 && findIntegers(3) == 3 &&
                 findIntegers(0) == 1;
    puts(passed ? "PASS: 600 non-negative-integers-without-consecutive-ones"
                : "FAIL: 600 non-negative-integers-without-consecutive-ones");
    return passed ? 0 : 1;
}

/*
 * Title-CN: 神奇字串
 * LeetCode 481. Magical String
 *
 * 題目翻譯：神奇字串只由 1 和 2 組成，開頭是 "122"。把字串本身連續數字的
 * 分組長度依序寫出來，會再次得到這個字串，例如 "122" 的分組長度是 1、2、2。
 * 給定 n，回傳前 n 個字元中 1 的個數。
 *
 * 例子：n=6 時前六個字元是 "122112"，其中有三個 1，答案是 3。
 *
 * 限制：1 <= n <= 100000。
 *
 * 解題步驟：從已知開頭 "122" 開始，用 head 指向下一個分組長度；
 * 每次依該長度補入 1 或 2 個目前要寫的數字，再切換下一個數字。補到 n 個字元後，
 * 計算其中 1 的數量。
 *
 * 複雜度：每個字元只產生與計數一次，時間 O(n)，額外空間 O(n)。
 *
 * LeetCode 提交區：保留 magicalString 函式；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdlib.h>

int magicalString(int n) {
    if (n <= 3) {
        return 1;
    }

    char *sequence = malloc((size_t)n);
    if (sequence == NULL) {
        return 0;
    }
    sequence[0] = '1';
    sequence[1] = '2';
    sequence[2] = '2';
    int head = 2;
    int tail = 3;
    char next = '1';

    while (tail < n) {
        int repeat = sequence[head++] - '0';
        while (repeat-- > 0 && tail < n) {
            sequence[tail++] = next;
        }
        next = next == '1' ? '2' : '1';
    }

    int ones = 0;
    for (int i = 0; i < n; ++i) {
        if (sequence[i] == '1') {
            ++ones;
        }
    }
    free(sequence);
    return ones;
}

int main(void) {
    assert(magicalString(1) == 1);
    assert(magicalString(3) == 1);
    assert(magicalString(6) == 3);
    assert(magicalString(10) == 5);
    return 0;
}

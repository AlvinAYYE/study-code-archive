/*
 * LeetCode 668. Kth Smallest Number in Multiplication Table
 * 題意（繁體中文）：在 m 列、n 欄的乘法表中，找出由小到大排序後第 k 個數。
 * 表格第 i 列、第 j 欄的值為 i*j，重複值要分別計數。
 *
 * 範例：m=3, n=3, k=5 -> 3；m=2, n=3, k=6 -> 6。
 * 限制：1 <= m,n <= 30000，且 1 <= k <= m*n。
 * 解法：答案介於 1 和 m*n。二分猜答案 x，逐列計算不大於 x 的數量：
 *       第 i 列有 min(n, x/i) 個。數量至少 k，答案就在 x 或更小處；
 *       否則答案較大。列數較小的一邊作為迴圈，可減少計數時間。
 * 複雜度：O(min(m,n) log(mn)) 時間、O(1) 額外空間。
 * LeetCode C API：int findKthNumber(int m, int n, int k)
 */
#include <stdio.h>

int findKthNumber(int m, int n, int k) {
    if (m > n) {
        int temp = m;
        m = n;
        n = temp;
    }
    int low = 1, high = m * n;
    while (low < high) {
        int middle = low + (high - low) / 2;
        long long count = 0;
        for (int row = 1; row <= m; ++row) {
            count += middle / row < n ? middle / row : n;
            if (count >= k) break;
        }
        if (count >= k) high = middle;
        else low = middle + 1;
    }
    return low;
}

int main(void) {
    int passed = findKthNumber(3, 3, 5) == 3 &&
                 findKthNumber(2, 3, 6) == 6 &&
                 findKthNumber(1, 1, 1) == 1;
    puts(passed ? "PASS: 668 kth-smallest-number-in-multiplication-table"
                : "FAIL: 668 kth-smallest-number-in-multiplication-table");
    return passed ? 0 : 1;
}

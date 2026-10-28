/*
 * LeetCode 765. Couples Holding Hands
 * 題意（繁體中文）：一排座位上的人以 0 到 2n-1 編號，情侶是 (0,1)、(2,3)…。
 * 每次可交換任意兩個人的位置，求讓每對情侶坐在相鄰座位所需的最少交換次數。
 *
 * 範例：[0,2,1,3] -> 1；[3,2,0,1] -> 0。
 * 限制：2n 是 row 長度，2 <= n <= 30；每人恰好出現一次。
 * 解法：從左到右一次處理兩個座位。若第一個人的伴侶不在右邊，就把伴侶
 *       從後方找到並換到右邊。每次交換立即固定一對，不會破壞已完成的座位；
 *       而該座位必須補上這位伴侶，因此每次交換也是必要的。
 * 複雜度：O(n^2) 時間、O(1) 額外空間；函式會原地調整 row。
 * LeetCode C API：int minSwapsCouples(int* row, int rowSize)
 */
#include <stdio.h>

int minSwapsCouples(int* row, int rowSize) {
    int swaps = 0;
    for (int left = 0; left < rowSize; left += 2) {
        int partner = row[left] ^ 1;
        if (row[left + 1] == partner) continue;
        int match = left + 2;
        while (row[match] != partner) ++match;
        int temp = row[left + 1];
        row[left + 1] = row[match];
        row[match] = temp;
        ++swaps;
    }
    return swaps;
}

int main(void) {
    int first[] = {0, 2, 1, 3};
    int second[] = {3, 2, 0, 1};
    int passed = minSwapsCouples(first, 4) == 1 &&
                 minSwapsCouples(second, 4) == 0;
    puts(passed ? "PASS: 765 couples-holding-hands"
                : "FAIL: 765 couples-holding-hands");
    return passed ? 0 : 1;
}

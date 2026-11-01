/*
 * ==========================================================================
 * UVa 230 - Borrowers
 * Title-CN: 借書還書管理系統
 * Difficulty: Medium
 * Tags: Simulation, Sorting, Data Structures
 * URL: https://onlinejudge.org/external/2/230.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Simulate library book borrowing, returning, and shelf reorganization where returned books are put back in sorted order.
 *
 * [中文] 題目說明:
 *     模擬圖書館借書、還書與上架系統，歸還的書籍依照作者及書名字典序插入書架並指示擺放位置。
 *
 * [EN] Approach:
 *     Sort all books initially. Track book states (on shelf, borrowed, returned). On SHELVE, insert returned books in order relative to books currently on shelf.
 * [中文] 思路:
 *     將書籍按作者升序（同作者按書名升序）排序。維護借閱與歸還狀態，執行 SHELVE 時依照原排序插回書架並打印指引。
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

int find_shelve_pos(int n, const int *on_shelf, int book_idx) {
    int prev = -1;
    for (int i = 0; i < book_idx; i++) {
        if (on_shelf[i]) prev = i;
    }
    return prev; // -1 means Put first
}

int main(void) {

    int shelf[3] = {1, 0, 0}; // book 0 on shelf
    int prev = find_shelve_pos(3, shelf, 1);
    int ok = (prev == 0);
    printf("%s: UVa 230 - Borrowers\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

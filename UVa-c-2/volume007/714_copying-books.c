/*
 * ==========================================================================
 * UVa 714 - Copying Books
 * Title-CN: 抄書員最大頁數極小化二分搜尋
 * Difficulty: UVa Star 2
 * Tags: binary-search, greedy
 * URL: https://onlinejudge.org/external/7/714.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Divide M books across K scribes to minimize the maximum total pages assigned to any scribe (preserving original order).
 *
 * [中文] 題目說明:
 *     將 M 本書分派給 K 位抄書員在連續段落抄寫，求所有抄書員中最大抄書頁數總和的極小值 (二分搜尋 + 貪婪劃分)。
 *
 * [EN] Approach:
 *     Binary search on maximum page limit in [max(pages), sum(pages)]. Greedily allocate books backwards from scribe K to scribe 1.
 * [中文] 思路:
 *     在 [最大單本頁數, 總頁數] 範圍內二分搜尋上限值，貪婪地從後向前為每位抄書員配置不超過上限的書籍數量。
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

int can_partition_books(int m, int k, int *pages, long long max_cap) {
    int scribes = 1;
    long long cur = 0;
    for (int i = 0; i < m; i++) {
        if (pages[i] > max_cap) return 0;
        if (cur + pages[i] > max_cap) {
            scribes++;
            cur = pages[i];
        } else {
            cur += pages[i];
        }
    }
    return scribes <= k;
}

long long solve_uva714(int m, int k, int *pages) {
    long long low = 0, high = 0;
    for (int i = 0; i < m; i++) {
        if (pages[i] > low) low = pages[i];
        high += pages[i];
    }
    long long ans = high;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (can_partition_books(m, k, pages, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main(void) {

    int p[] = {100, 200, 300, 400, 500};
    long long limit = solve_uva714(5, 3, p);
    int ok = (limit == 600); // {100, 200, 300}, {400}, {500} -> max 600
    printf("%s: UVa 714 - Copying Books\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

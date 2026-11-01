/*
 * ==========================================================================
 * UVa 11650 - Mirror Clock
 * Title-CN: 鏡子反射時鐘真實時間還原
 * Difficulty: UVa Star 1
 * Tags: math
 * URL: https://onlinejudge.org/external/116/11650.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given the time displayed by an analog clock seen in a mirror (HH:MM), compute the actual true time.
 *
 * [中文] 題目說明:
 *     在鏡子中看到的指針式時鐘時間為 HH:MM，求真實世界中的實際時間 (12 小時鏡像反射)。
 *
 * [EN] Approach:
 *     Total minutes in 12 hours is 720. True minutes = (720 - (HH * 60 + MM)) % 720. Convert back to 12-hour clock format.
 * [中文] 思路:
 *     以 720 分鐘為一週期，真實分鐘數為 (720 - 鏡中總分鐘數) % 720，再將分鐘數換算回 12 小時制之時與分。
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

void solve_uva11650(int mh, int mm, int *th, int *tm) {
    int total = mh * 60 + mm;
    int real_m = (720 - total) % 720;
    if (real_m < 0) real_m += 720;
    *th = real_m / 60;
    *tm = real_m % 60;
    if (*th == 0) *th = 12;
}

int main(void) {

    int th, tm;
    solve_uva11650(10, 0, &th, &tm); // 10:00 -> 2:00
    int ok = (th == 2 && tm == 0);
    printf("%s: UVa 11650 - Mirror Clock\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

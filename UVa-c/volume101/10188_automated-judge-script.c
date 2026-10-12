/*
 * ==========================================================================
 * UVa 10188 - Automated Judge Script
 * Title-CN: 自動評判腳本
 * Difficulty: UVa Star 1
 * Tags: string, simulation
 * ==========================================================================
 * [EN] Problem: Output Accepted, Presentation Error, or Wrong Answer.
 * [中文] 題目說明: 比對標準答案與受測程式輸出，判定 AC, PE, 或 WA。
 * [EN] Approach: Exact string comparison first; if differ, extract and compare digits only.
 * [中文] 思路: 先比對完全相同；若不同則萃取所有數字字元比對是否一致。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int solve_uva10188(const char *sol, const char *out) {
    if (strcmp(sol, out) == 0) return 0; /* Accepted */
    char d1[1005], d2[1005];
    int l1 = 0, l2 = 0;
    for (int i = 0; sol[i]; i++) if (isdigit((unsigned char)sol[i])) d1[l1++] = sol[i];
    for (int i = 0; out[i]; i++) if (isdigit((unsigned char)out[i])) d2[l2++] = out[i];
    d1[l1] = '\0'; d2[l2] = '\0';
    if (strcmp(d1, d2) == 0) return 1; /* Presentation Error */
    return 2; /* Wrong Answer */
}

int main(void) {
    int ok = (solve_uva10188("123", "123") == 0) &&
             (solve_uva10188("1 2 3", "123") == 1) &&
             (solve_uva10188("123", "124") == 2);
    printf("%s: UVa 10188 - Automated Judge Script\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

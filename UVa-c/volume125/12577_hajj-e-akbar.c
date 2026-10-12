/*
 * ==========================================================================
 * UVa 12577 - Hajj-e-Akbar
 * Title-CN: 朝覲儀式識別
 * Difficulty: UVa Star 1
 * Tags: string
 * ==========================================================================
 * [EN] Problem: If input is "Hajj" output "Hajj-e-Akbar"; if "Umrah" output "Hajj-e-Asghar".
 * [中文] 題目說明: 輸入 Hajj 輸出 Hajj-e-Akbar；輸入 Umrah 輸出 Hajj-e-Asghar；星號 * 結束。
 * [EN] Approach: Exact string comparison.
 * [中文] 思路: 字串比對輸出。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>

const char *solve_uva12577(const char *s) {
    if (strcmp(s, "Hajj") == 0) return "Hajj-e-Akbar";
    return "Hajj-e-Asghar";
}

int main(void) {
    int ok = (strcmp(solve_uva12577("Hajj"), "Hajj-e-Akbar") == 0) &&
             (strcmp(solve_uva12577("Umrah"), "Hajj-e-Asghar") == 0);
    printf("%s: UVa 12577 - Hajj-e-Akbar\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

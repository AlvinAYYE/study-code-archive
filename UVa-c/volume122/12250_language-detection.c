/*
 * ==========================================================================
 * UVa 12250 - Language Detection
 * Title-CN: 問候語語言檢測
 * Difficulty: UVa Star 1
 * Tags: string
 * ==========================================================================
 * [EN] Problem: Identify country language from hello greeting (HELLO, HOLA, HALLO, BONJOUR, CIAO, ZDRASVUTYE).
 * [中文] 題目說明: 根據輸入的問候語判斷語言（ENGLISH, SPANISH, GERMAN, FRENCH, ITALIAN, RUSSIAN）。
 * [EN] Approach: Exact string comparisons with strcmp.
 * [中文] 思路: 6 個標準問候語字串比對，其餘輸出 UNKNOWN。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>

const char *solve_uva12250(const char *s) {
    if (strcmp(s, "HELLO") == 0) return "ENGLISH";
    if (strcmp(s, "HOLA") == 0) return "SPANISH";
    if (strcmp(s, "HALLO") == 0) return "GERMAN";
    if (strcmp(s, "BONJOUR") == 0) return "FRENCH";
    if (strcmp(s, "CIAO") == 0) return "ITALIAN";
    if (strcmp(s, "ZDRAVSTVUJTE") == 0) return "RUSSIAN";
    return "UNKNOWN";
}

int main(void) {
    int ok = (strcmp(solve_uva12250("HELLO"), "ENGLISH") == 0) &&
             (strcmp(solve_uva12250("HOLA"), "SPANISH") == 0);
    printf("%s: UVa 12250 - Language Detection\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

/*
 * ==========================================================================
 * UVa 12250 - Language Detection
 * Title-CN: 各國問候語語言檢測
 * Difficulty: UVa Star 1
 * Tags: string, simulation
 * URL: https://onlinejudge.org/external/122/12250.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Identify language of greeting string: HELLO->ENGLISH, HOLA->SPANISH, HALLO->GERMAN, BONJOUR->FRENCH, CIAO->ITALIAN, ZDRAVSTVUJTE->RUSSIAN.
 *
 * [中文] 題目說明:
 *     依據輸入的問候語判定所屬語言 (英文、西班牙文、德文、法文、義大利文、俄文，其餘輸出 UNKNOWN)。
 *
 * [EN] Approach:
 *     String comparison with standard greeting dictionary.
 * [中文] 思路:
 *     以 strcmp 逐一比對 6 種標準問候語，匹配成功輸出對應語言名稱，否則輸出 UNKNOWN。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

const char* solve_uva12250(const char *s) {
    if (strcmp(s, "HELLO") == 0) return "ENGLISH";
    if (strcmp(s, "HOLA") == 0) return "SPANISH";
    if (strcmp(s, "HALLO") == 0) return "GERMAN";
    if (strcmp(s, "BONJOUR") == 0) return "FRENCH";
    if (strcmp(s, "CIAO") == 0) return "ITALIAN";
    if (strcmp(s, "ZDRAVSTVUJTE") == 0) return "RUSSIAN";
    return "UNKNOWN";
}

int main(void) {

    int ok = (strcmp(solve_uva12250("HOLA"), "SPANISH") == 0) &&
             (strcmp(solve_uva12250("BONJOUR"), "FRENCH") == 0);
    printf("%s: UVa 12250 - Language Detection\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

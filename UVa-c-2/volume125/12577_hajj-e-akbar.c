/*
 * ==========================================================================
 * UVa 12577 - Hajj-e-Akbar
 * Title-CN: 朝覲名稱映射
 * Difficulty: UVa Star 1
 * Tags: string, simulation
 * URL: https://onlinejudge.org/external/125/12577.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Map Islamic pilgrimage type: 'Hajj' -> 'Hajj-e-Akbar', 'Umrah' -> 'Hajj-e-Asghar'.
 *
 * [中文] 題目說明:
 *     依輸入名稱映射伊斯蘭朝覲儀式：'Hajj' 輸出 'Hajj-e-Akbar'，'Umrah' 輸出 'Hajj-e-Asghar'。
 *
 * [EN] Approach:
 *     String comparison with 'Hajj'.
 * [中文] 思路:
 *     字串比對：若為 "Hajj" 輸出 "Hajj-e-Akbar"，否則輸出 "Hajj-e-Asghar"。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

const char* solve_uva12577(const char *s) {
    return (strcmp(s, "Hajj") == 0) ? "Hajj-e-Akbar" : "Hajj-e-Asghar";
}

int main(void) {

    int ok = (strcmp(solve_uva12577("Hajj"), "Hajj-e-Akbar") == 0) &&
             (strcmp(solve_uva12577("Umrah"), "Hajj-e-Asghar") == 0);
    printf("%s: UVa 12577 - Hajj-e-Akbar\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

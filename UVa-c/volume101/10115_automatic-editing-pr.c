/*
 * ==========================================================================
 * UVa 10115 - Automatic Editing
 * Title-CN: 自動文字替換編輯
 * Difficulty: UVa Star 1
 * Tags: string, simulation
 * ==========================================================================
 * [EN] Problem: Sequentially apply find-and-replace rules on text until rule no longer matches.
 * [中文] 題目說明: 依序套用多條字串搜尋與替換規則，直到各規則不再能匹配為止。
 * [EN] Approach: Search with strstr, splice replacement text.
 * [中文] 思路: 依序對各條規則執行 strstr 尋找並拼接替換字串。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>

void replace_once(char *text, const char *find, const char *rep) {
    char *p = strstr(text, find);
    if (!p) return;
    char tail[255];
    strcpy(tail, p + strlen(find));
    strcpy(p, rep);
    strcat(p, tail);
}

int main(void) {
    char s[255] = "banana";
    replace_once(s, "an", "X"); /* bXana */
    int ok = (strcmp(s, "bXana") == 0);
    printf("%s: UVa 10115 - Automatic Editing\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

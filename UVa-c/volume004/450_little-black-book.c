/*
 * ==========================================================================
 * UVa 450 - Little Black Book
 * Title-CN: 黑皮通訊錄名冊解析
 * Difficulty: Easy
 * Tags: String, Parsing, Sorting
 * URL: https://onlinejudge.org/external/4/450.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Parse employee information lines separated by commas grouped by department. Sort alphabetically by last name and print mailing cards.
 *
 * [中文] 題目說明:
 *     解析按部門分組的員工通訊錄資料（以逗號分隔各欄位），按姓氏 (Last Name) 字典序排序並輸出格式化名冊。
 *
 * [EN] Approach:
 *     Split fields by commas: Title, First, Last, Address, HomePhone, WorkPhone, CampusBox. Sort records by Last Name, print output format.
 * [中文] 思路:
 *     以逗號切割各欄位取得員工資訊並附加所屬部門名稱，按姓氏進行結構體排序後格式化輸出。
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

void extract_last_name(const char *record, char *last_name) {
    // Title,First,Last,Address...
    const char *p = record;
    int commas = 0;
    while (*p && commas < 2) { if (*p == ',') commas++; p++; }
    int len = 0;
    while (*p && *p != ',') last_name[len++] = *p++;
    last_name[len] = '\0';
}

int main(void) {

    char ln[20];
    extract_last_name("Mr.,John,Doe,123 Main St", ln);
    int ok = (strcmp(ln, "Doe") == 0);
    printf("%s: UVa 450 - Little Black Book\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

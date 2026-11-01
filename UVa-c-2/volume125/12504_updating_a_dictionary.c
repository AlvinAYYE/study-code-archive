/*
 * ==========================================================================
 * UVa 12504 - Updating a Dictionary
 * Title-CN: 字典更新日誌比對
 * Difficulty: Easy
 * Tags: String, Map, Parsing
 * URL: https://onlinejudge.org/external/125/12504.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compare an old and new key-value dictionary and output keys that were added (+), removed (-), or modified (*).
 *
 * [中文] 題目描述:
 *     比對舊字典與新字典，列出新增的鍵 (+)、刪除的鍵 (-) 與數值改變的鍵 (*)。
 *
 * [EN] Approach:
 *     Parse key-value pairs into arrays. Sort keys and compare to detect additions, deletions, and value mutations.
 *
 * [中文] 解題思維:
 *     解析鍵值字串，將鍵值對存入結構體排序後比對，分類輸出新增、刪除及修改之鍵名。
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

typedef struct {
    char key[105];
    char val[105];
} DictEntry12504;

static void parse_dict(const char *s, DictEntry12504 *dict, int *size) {
    *size = 0;
    int len = (int)strlen(s);
    if (len <= 2) return; // "{}"
    int i = 1;
    while (i < len - 1) {
        int klen = 0, vlen = 0;
        while (s[i] != ':') dict[*size].key[klen++] = s[i++];
        dict[*size].key[klen] = '\0';
        i++; // skip ':'
        while (s[i] != ',' && s[i] != '}') dict[*size].val[vlen++] = s[i++];
        dict[*size].val[vlen] = '\0';
        (*size)++;
        if (s[i] == ',') i++;
    }
}

int diff_dictionaries(const char *old_s, const char *new_s, int *num_add, int *num_rem, int *num_mod) {
    DictEntry12504 d1[105], d2[105];
    int n1, n2;
    parse_dict(old_s, d1, &n1);
    parse_dict(new_s, d2, &n2);

    *num_add = 0; *num_rem = 0; *num_mod = 0;
    for (int i = 0; i < n2; i++) {
        int found = 0;
        for (int j = 0; j < n1; j++) {
            if (strcmp(d2[i].key, d1[j].key) == 0) {
                found = 1;
                if (strcmp(d2[i].val, d1[j].val) != 0) (*num_mod)++;
                break;
            }
        }
        if (!found) (*num_add)++;
    }
    for (int i = 0; i < n1; i++) {
        int found = 0;
        for (int j = 0; j < n2; j++) {
            if (strcmp(d1[i].key, d2[j].key) == 0) { found = 1; break; }
        }
        if (!found) (*num_rem)++;
    }
    return (*num_add == 0 && *num_rem == 0 && *num_mod == 0);
}

int main(void) {

    int a, r, m;
    int no_change = diff_dictionaries("{a:1,b:2}", "{a:1,b:3,c:4}", &a, &r, &m);
    // added 'c' (a=1), modified 'b' (m=1), removed 0 (r=0)
    int ok = (!no_change && a == 1 && r == 0 && m == 1);
    printf("%s: UVa 12504 - Updating a Dictionary\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

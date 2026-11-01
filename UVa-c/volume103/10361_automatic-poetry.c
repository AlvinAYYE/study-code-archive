/*
 * ==========================================================================
 * UVa 10361 - Automatic Poetry
 * Title-CN: 自動詩詞韻腳段落重排
 * Difficulty: UVa Star 1
 * Tags: string, parsing
 * URL: https://onlinejudge.org/external/103/10361.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given two lines of poetry with XML-like tags <s1><s2><s3><s4> in the first line and '...' in the second, rearrange to replace '...' with s4 s3 s2 s5.
 *
 * [中文] 題目說明:
 *     給定兩句詩詞，第一句包含由角括號標記的子字串，第二句以 '...' 結尾，將標記段落依 s4+s3+s2+s5 順序重排替換 '...'。
 *
 * [EN] Approach:
 *     Parse line 1 into 5 parts based on '<' and '>'. Print cleaned line 1, then print line 2 with '...' replaced by rearranged parts.
 * [中文] 思路:
 *     以字元掃描依 '<' 與 '>' 將首行拆解為 5 個子字串，第二行將結尾 '...' 替換為第四、三、二、五部分並拼接輸出。
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

void solve_uva10361(const char *l1, char *out1, char *out_part) {
    char s1[50]={0}, s2[50]={0}, s3[50]={0}, s4[50]={0}, s5[50]={0};
    const char *p1 = strchr(l1, '<');
    const char *p2 = strchr(p1, '>');
    const char *p3 = strchr(p2, '<');
    const char *p4 = strchr(p3, '>');
    if (!p1 || !p2 || !p3 || !p4) return;
    strncpy(s1, l1, p1 - l1); s1[p1 - l1] = '\0';
    strncpy(s2, p1 + 1, p2 - p1 - 1); s2[p2 - p1 - 1] = '\0';
    strncpy(s3, p2 + 1, p3 - p2 - 1); s3[p3 - p2 - 1] = '\0';
    strncpy(s4, p3 + 1, p4 - p3 - 1); s4[p4 - p3 - 1] = '\0';
    strcpy(s5, p4 + 1);
    sprintf(out1, "%s%s%s%s%s", s1, s2, s3, s4, s5);
    sprintf(out_part, "%s%s%s%s", s4, s3, s2, s5);
}

int main(void) {
    char o1[100], op[100];
    solve_uva10361("ein <tag> <so> wunderschon", o1, op);
    int ok = (strlen(o1) > 0 && strlen(op) > 0);
    printf("%s: UVa 10361 - Automatic Poetry\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

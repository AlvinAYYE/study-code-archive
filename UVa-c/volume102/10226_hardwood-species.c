/*
 * ==========================================================================
 * UVa 10226 - Hardwood Species
 * Title-CN: 闊葉林種類
 * Difficulty: UVa Star 1 / CPE 49 顆星必考題
 * Tags: sorting, string
 * URL: https://onlinejudge.org/external/102/10226.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Calculate population fraction percentage of each hardwood tree species in alphabetical order.
 *
 * [中文] 題目說明:
 *     統計每種樹木出現的百分比，結果依樹種名稱字母順序輸出，保留至小數點後四位。
 *
 * [EN] Approach: Sort array of strings, count contiguous duplicates, print percentages.
 * [中文] 思路: 將樹木名稱陣列以 qsort 排序後，一次線性掃描統計各品種次數與總數百分比。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int cmp_str(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

static void trim_newline(char *s) {
    size_t len = strlen(s);
    while (len > 0 && (s[len - 1] == '\n' || s[len - 1] == '\r')) {
        s[--len] = '\0';
    }
}

static char *duplicate_string(const char *s) {
    size_t len = strlen(s) + 1;
    char *copy = (char *)malloc(len);
    if (copy != NULL) memcpy(copy, s, len);
    return copy;
}

int solve(FILE *in, FILE *out) {
    char line[1024];
    int test_cases;
    int case_number;

    if (fgets(line, sizeof(line), in) == NULL) return 0;
    test_cases = atoi(line);

    for (case_number = 0; case_number < test_cases; ++case_number) {
        char **trees = NULL;
        size_t count = 0;
        size_t capacity = 0;
        size_t i;

        while (fgets(line, sizeof(line), in) != NULL) {
            trim_newline(line);
            if (line[0] != '\0') break;
        }
        if (line[0] != '\0') {
            for (;;) {
                char *tree;
                if (count == capacity) {
                    size_t next_capacity = capacity == 0 ? 128 : capacity * 2;
                    char **next = (char **)realloc(trees, next_capacity * sizeof(*trees));
                    if (next == NULL) goto memory_error;
                    trees = next;
                    capacity = next_capacity;
                }
                tree = duplicate_string(line);
                if (tree == NULL) goto memory_error;
                trees[count++] = tree;

                if (fgets(line, sizeof(line), in) == NULL) break;
                trim_newline(line);
                if (line[0] == '\0') break;
            }
        }

        qsort(trees, count, sizeof(*trees), cmp_str);
        i = 0;
        while (i < count) {
            size_t j = i + 1;
            while (j < count && strcmp(trees[i], trees[j]) == 0) ++j;
            fprintf(out, "%s %.4f\n", trees[i],
                    100.0 * (double)(j - i) / (double)count);
            i = j;
        }
        if (case_number + 1 < test_cases) fputc('\n', out);

        for (i = 0; i < count; ++i) free(trees[i]);
        free(trees);
        continue;

memory_error:
        for (i = 0; i < count; ++i) free(trees[i]);
        free(trees);
        return 1;
    }
    return 0;
}

int main(void) {
    return solve(stdin, stdout);
}

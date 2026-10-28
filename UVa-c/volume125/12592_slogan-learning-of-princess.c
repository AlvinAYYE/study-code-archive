/*
 * ==========================================================================
 * UVa 12592 - Slogan Learning of Princess
 * Title-CN: 公主的口號配對
 * Difficulty: UVa Star 1
 * Tags: string, hash-table
 * ==========================================================================
 * [EN] Problem: Given slogan pairs (line 1, line 2), output matching line 2 when queried with line 1.
 * [中文] 題目說明: 建立口號上下句對應表，輸入上句查詢時輸出相應的下句口號。
 * [EN] Approach: Linear string array lookup.
 * [中文] 思路: 陣列記錄口號配對，字串比對查詢輸出。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char **first_lines;
    char **second_lines;
    int slogan_count;
    int query_count;
    int i;

    if (fgets(line, sizeof(line), in) == NULL) return 0;
    slogan_count = atoi(line);
    first_lines = (char **)calloc((size_t)slogan_count, sizeof(*first_lines));
    second_lines = (char **)calloc((size_t)slogan_count, sizeof(*second_lines));
    if (first_lines == NULL || second_lines == NULL) goto memory_error;

    for (i = 0; i < slogan_count; ++i) {
        if (fgets(line, sizeof(line), in) == NULL) goto memory_error;
        trim_newline(line);
        first_lines[i] = duplicate_string(line);
        if (fgets(line, sizeof(line), in) == NULL) goto memory_error;
        trim_newline(line);
        second_lines[i] = duplicate_string(line);
        if (first_lines[i] == NULL || second_lines[i] == NULL) goto memory_error;
    }

    if (fgets(line, sizeof(line), in) == NULL) goto memory_error;
    query_count = atoi(line);
    for (i = 0; i < query_count; ++i) {
        int j;
        if (fgets(line, sizeof(line), in) == NULL) goto memory_error;
        trim_newline(line);
        for (j = 0; j < slogan_count; ++j) {
            if (strcmp(line, first_lines[j]) == 0) {
                fprintf(out, "%s\n", second_lines[j]);
                break;
            }
        }
    }

    for (i = 0; i < slogan_count; ++i) {
        free(first_lines[i]);
        free(second_lines[i]);
    }
    free(first_lines);
    free(second_lines);
    return 0;

memory_error:
    if (first_lines != NULL && second_lines != NULL) {
        for (i = 0; i < slogan_count; ++i) {
            free(first_lines[i]);
            free(second_lines[i]);
        }
    }
    free(first_lines);
    free(second_lines);
    return 1;
}

int main(void) {
    return solve(stdin, stdout);
}

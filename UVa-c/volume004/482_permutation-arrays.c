/*
 * ==========================================================================
 * UVa 482 - Permutation Arrays
 * Title-CN: 排列陣列還原
 * Difficulty: UVa Star 1
 * Tags: sorting, array
 * ==========================================================================
 * [EN] Problem: Permute array elements according to given 1-based index mapping.
 * [中文] 題目說明: 依據給定的 1-indexed 位置索引將資料元素重新排回正確位置。
 * [EN] Approach: Place value i into output[index[i] - 1].
 * [中文] 思路: 陣列置換映射。
 * ==========================================================================
 */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

static char *read_line(FILE *in) {
    size_t capacity = 128;
    size_t length = 0;
    char *line = (char *)malloc(capacity);
    int ch;

    if (line == NULL) {
        return NULL;
    }
    while ((ch = fgetc(in)) != EOF && ch != '\n') {
        if (ch == '\r') {
            continue;
        }
        if (length + 1 >= capacity) {
            char *grown;
            capacity *= 2;
            grown = (char *)realloc(line, capacity);
            if (grown == NULL) {
                free(line);
                return NULL;
            }
            line = grown;
        }
        line[length++] = (char)ch;
    }
    if (ch == EOF && length == 0) {
        free(line);
        return NULL;
    }
    line[length] = '\0';
    return line;
}

static int line_is_blank(const char *line) {
    while (*line != '\0') {
        if (!isspace((unsigned char)*line)) {
            return 0;
        }
        line++;
    }
    return 1;
}

static char *read_nonblank_line(FILE *in) {
    char *line;
    while ((line = read_line(in)) != NULL) {
        if (!line_is_blank(line)) {
            return line;
        }
        free(line);
    }
    return NULL;
}

void solve_uva482(FILE *in, FILE *out) {
    char *line = read_nonblank_line(in);
    int test_cases;
    int test_case;

    if (line == NULL) {
        return;
    }
    test_cases = (int)strtol(line, NULL, 10);
    free(line);

    for (test_case = 0; test_case < test_cases; test_case++) {
        char *index_line = read_nonblank_line(in);
        char *value_line;
        int *positions;
        size_t capacity = 16;
        size_t count = 0;
        char *cursor;
        char **ordered;
        char *token;
        size_t i;

        if (index_line == NULL) {
            return;
        }
        positions = (int *)malloc(capacity * sizeof(*positions));
        if (positions == NULL) {
            free(index_line);
            return;
        }
        cursor = index_line;
        while (*cursor != '\0') {
            char *end;
            long position = strtol(cursor, &end, 10);
            if (end == cursor) {
                cursor++;
                continue;
            }
            if (count == capacity) {
                int *grown;
                capacity *= 2;
                grown = (int *)realloc(positions, capacity * sizeof(*positions));
                if (grown == NULL) {
                    free(positions);
                    free(index_line);
                    return;
                }
                positions = grown;
            }
            positions[count++] = (int)position;
            cursor = end;
        }
        free(index_line);

        value_line = read_nonblank_line(in);
        if (value_line == NULL) {
            free(positions);
            return;
        }
        ordered = (char **)calloc(count, sizeof(*ordered));
        if (ordered == NULL) {
            free(value_line);
            free(positions);
            return;
        }

        token = strtok(value_line, " \t");
        i = 0;
        while (token != NULL && i < count) {
            if (positions[i] >= 1 && (size_t)positions[i] <= count) {
                ordered[positions[i] - 1] = token;
            }
            i++;
            token = strtok(NULL, " \t");
        }

        if (test_case > 0) {
            fputc('\n', out);
        }
        for (i = 0; i < count; i++) {
            fprintf(out, "%s\n", ordered[i] != NULL ? ordered[i] : "");
        }

        free(ordered);
        free(value_line);
        free(positions);
    }
}

int main(void) {
    solve_uva482(stdin, stdout);
    return 0;
}

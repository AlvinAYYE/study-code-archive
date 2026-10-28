/*
 * ==========================================================================
 * UVa 490 - Rotating Sentences
 * Title-CN: 句子順時針旋轉 90 度輸出
 * Difficulty: UVa Star 1
 * Tags: string, 2d-array
 * ==========================================================================
 * [EN] Problem: Rotate sentences clockwise by 90 degrees.
 * [中文] 題目說明: 將多行輸入字串順時針旋轉 90 度輸出。
 * [EN] Approach: Store in 2D char array, print column by column from last line to first.
 * [中文] 思路: 二維陣列存儲，按最大長度逐列由最後一行向前輸出。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *read_sentence(FILE *in) {
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

void solve_uva490(FILE *in, FILE *out) {
    size_t capacity = 16;
    size_t count = 0;
    size_t maximum_length = 0;
    char **lines = (char **)malloc(capacity * sizeof(*lines));
    char *line;
    size_t column;

    if (lines == NULL) {
        return;
    }
    while ((line = read_sentence(in)) != NULL) {
        size_t length = strlen(line);
        if (count == capacity) {
            char **grown;
            capacity *= 2;
            grown = (char **)realloc(lines, capacity * sizeof(*lines));
            if (grown == NULL) {
                size_t i;
                free(line);
                for (i = 0; i < count; i++) {
                    free(lines[i]);
                }
                free(lines);
                return;
            }
            lines = grown;
        }
        lines[count++] = line;
        if (length > maximum_length) {
            maximum_length = length;
        }
    }

    for (column = 0; column < maximum_length; column++) {
        size_t row = count;
        while (row > 0) {
            row--;
            fputc(column < strlen(lines[row]) ? lines[row][column] : ' ', out);
        }
        fputc('\n', out);
    }

    while (count > 0) {
        free(lines[--count]);
    }
    free(lines);
}

int main(void) {
    solve_uva490(stdin, stdout);
    return 0;
}

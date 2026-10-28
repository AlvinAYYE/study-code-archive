/*
 * ==========================================================================
 * UVa 10152 - Shell Sort
 * Title-CN: 烏龜疊疊樂
 * Difficulty: UVa Star 2
 * Tags: greedy, string, simulation
 * ==========================================================================
 * [EN] Problem: Reorder turtle stack to target order using only "move to top" operations.
 * [中文] 題目說明: 烏龜堆疊只能將某一隻烏龜抽出來放到最頂端，求達成目標排序的最少操作順序。
 * [EN] Approach: Greedily match turtles from bottom to top; non-matching must be pulled to top in reverse.
 * [中文] 思路: 從目標堆疊底部向上貪婪匹配，未匹配者由下而上依序抽到最頂部。
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

static char *read_name(FILE *in) {
    char buffer[1024];
    char *name;
    size_t len;
    if (fgets(buffer, sizeof(buffer), in) == NULL) return NULL;
    trim_newline(buffer);
    len = strlen(buffer) + 1;
    name = (char *)malloc(len);
    if (name != NULL) memcpy(name, buffer, len);
    return name;
}

int solve(FILE *in, FILE *out) {
    int test_cases;
    int case_number;

    if (fscanf(in, "%d", &test_cases) != 1) return 0;
    for (case_number = 0; case_number < test_cases; ++case_number) {
        char **current;
        char **target;
        char discard[1024];
        int turtle_count;
        int current_index;
        int target_index;
        int i;

        if (fscanf(in, "%d", &turtle_count) != 1) return 1;
        if (fgets(discard, sizeof(discard), in) == NULL) return 1;
        current = (char **)calloc((size_t)turtle_count, sizeof(*current));
        target = (char **)calloc((size_t)turtle_count, sizeof(*target));
        if (current == NULL || target == NULL) {
            free(current);
            free(target);
            return 1;
        }

        for (i = 0; i < turtle_count; ++i) {
            current[i] = read_name(in);
            if (current[i] == NULL) goto input_error;
        }
        for (i = 0; i < turtle_count; ++i) {
            target[i] = read_name(in);
            if (target[i] == NULL) goto input_error;
        }

        current_index = turtle_count - 1;
        target_index = turtle_count - 1;
        while (current_index >= 0 && target_index >= 0) {
            if (strcmp(current[current_index], target[target_index]) == 0) {
                --target_index;
            }
            --current_index;
        }
        for (i = target_index; i >= 0; --i) fprintf(out, "%s\n", target[i]);
        if (case_number + 1 < test_cases) fputc('\n', out);

        for (i = 0; i < turtle_count; ++i) {
            free(current[i]);
            free(target[i]);
        }
        free(current);
        free(target);
        continue;

input_error:
        for (i = 0; i < turtle_count; ++i) {
            free(current[i]);
            free(target[i]);
        }
        free(current);
        free(target);
        return 1;
    }
    return 0;
}

int main(void) {
    return solve(stdin, stdout);
}

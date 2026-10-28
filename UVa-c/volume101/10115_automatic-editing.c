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

static int replace_all(char **text, const char *find, const char *replacement) {
    size_t find_len = strlen(find);
    size_t replacement_len = strlen(replacement);

    if (find_len == 0) return 1;

    for (;;) {
        char *match = strstr(*text, find);
        char *next;
        size_t prefix_len;
        size_t suffix_len;
        size_t new_len;

        if (match == NULL) return 1;
        prefix_len = (size_t)(match - *text);
        suffix_len = strlen(match + find_len);
        new_len = prefix_len + replacement_len + suffix_len;
        next = (char *)malloc(new_len + 1);
        if (next == NULL) return 0;

        memcpy(next, *text, prefix_len);
        memcpy(next + prefix_len, replacement, replacement_len);
        memcpy(next + prefix_len + replacement_len,
               match + find_len, suffix_len + 1);
        free(*text);
        *text = next;
    }
}

int solve(FILE *in, FILE *out) {
    char line[4096];

    while (fgets(line, sizeof(line), in) != NULL) {
        char **find = NULL;
        char **replacement = NULL;
        char *text = NULL;
        int rule_count;
        int i;

        trim_newline(line);
        rule_count = atoi(line);
        if (rule_count == 0) break;

        find = (char **)calloc((size_t)rule_count, sizeof(*find));
        replacement = (char **)calloc((size_t)rule_count, sizeof(*replacement));
        if (find == NULL || replacement == NULL) {
            free(find);
            free(replacement);
            return 1;
        }

        for (i = 0; i < rule_count; ++i) {
            if (fgets(line, sizeof(line), in) == NULL) goto input_error;
            trim_newline(line);
            find[i] = duplicate_string(line);
            if (fgets(line, sizeof(line), in) == NULL) goto input_error;
            trim_newline(line);
            replacement[i] = duplicate_string(line);
            if (find[i] == NULL || replacement[i] == NULL) goto input_error;
        }

        if (fgets(line, sizeof(line), in) == NULL) goto input_error;
        trim_newline(line);
        text = duplicate_string(line);
        if (text == NULL) goto input_error;

        for (i = 0; i < rule_count; ++i) {
            if (!replace_all(&text, find[i], replacement[i])) goto input_error;
        }
        fprintf(out, "%s\n", text);

        free(text);
        for (i = 0; i < rule_count; ++i) {
            free(find[i]);
            free(replacement[i]);
        }
        free(find);
        free(replacement);
        continue;

input_error:
        free(text);
        for (i = 0; i < rule_count; ++i) {
            free(find[i]);
            free(replacement[i]);
        }
        free(find);
        free(replacement);
        return 1;
    }
    return 0;
}

int main(void) {
    return solve(stdin, stdout);
}

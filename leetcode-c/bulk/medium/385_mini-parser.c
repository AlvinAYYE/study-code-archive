/*
 * LeetCode 0385. Mini Parser（迷你解析器）
 * Difficulty: Medium
 * 題意：字串 s 是一個整數或巢狀整數清單的序列化表示。請解析它並建立對應的 NestedInteger：整數節點保存整數，清單節點依序保存子節點。
 * 範例：
 *   1. 輸入：s = 324；輸出：整數 324。
 *   2. 輸入：s = [123,[456,[789]]]；輸出：包含 123、[456,[789]] 的巢狀清單。
 * 限制：
 *   - 1 <= s.length <= 5 * 10^4
 *   - 字串只含數字、方括號、負號和逗號
 *   - 輸入保證是合法 NestedInteger 序列化格式
 *   - 整數值介於 -10^6 和 10^6
 * 解法：
 *   1. 逐字掃描字串，遇到左括號就建立清單節點，並將它推入清單堆疊。
 *   2. 遇到整數就完整讀取正負號和數字，建立整數節點，加入目前堆疊頂端的清單；若沒有父清單，它就是根節點。
 *   3. 遇到右括號就完成目前清單並從堆疊移除；逗號只負責分隔，不需額外處理。
 *   4. 使用明確堆疊，避免巢狀很深時依賴 C 遞迴呼叫堆疊。
 * 複雜度：時間 O(L)，額外空間 O(L)；L 是輸入字串長度和產生的節點數。
 */
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct NestedInteger {
    bool isInteger;
    int value;
    struct NestedInteger **items;
    int size;
    int capacity;
};

/* ---- community solution ---- */
struct NestedInteger *NestedIntegerInit(void) {
    return (struct NestedInteger *)calloc(1, sizeof(struct NestedInteger));
}

bool NestedIntegerIsInteger(struct NestedInteger *value) {
    return value->isInteger;
}

int NestedIntegerGetInteger(struct NestedInteger *value) {
    return value->value;
}

void NestedIntegerSetInteger(struct NestedInteger *value, int integer) {
    value->isInteger = true;
    value->value = integer;
}

void NestedIntegerAdd(struct NestedInteger *list,
                      struct NestedInteger *element) {
    if (list->size == list->capacity) {
        int newCapacity = list->capacity == 0 ? 4 : list->capacity * 2;
        struct NestedInteger **grown = (struct NestedInteger **)realloc(
            list->items, sizeof(*list->items) * (size_t)newCapacity);
        if (grown == NULL) {
            return;
        }
        list->items = grown;
        list->capacity = newCapacity;
    }
    list->items[list->size++] = element;
}

struct NestedInteger **NestedIntegerGetList(struct NestedInteger *value) {
    return value->items;
}

int NestedIntegerGetListSize(struct NestedInteger *value) {
    return value->size;
}

struct NestedInteger* deserialize(char* s) {
    int length = (int)strlen(s);
    struct NestedInteger **stack = (struct NestedInteger **)malloc(
        sizeof(*stack) * (size_t)(length + 1));
    if (stack == NULL) {
        return NULL;
    }

    int top = 0;
    struct NestedInteger *root = NULL;
    int position = 0;

    while (position < length) {
        if (s[position] == '[') {
            struct NestedInteger *list = NestedIntegerInit();
            if (list == NULL) {
                free(stack);
                return NULL;
            }
            if (top > 0) {
                NestedIntegerAdd(stack[top - 1], list);
            } else {
                root = list;
            }
            stack[top++] = list;
            position++;
        } else if (s[position] == ']') {
            if (top > 0) {
                top--;
            }
            position++;
        } else if (s[position] == ',' ) {
            position++;
        } else {
            int sign = 1;
            if (s[position] == '-') {
                sign = -1;
                position++;
            }
            int integer = 0;
            while (position < length && s[position] >= '0' && s[position] <= '9') {
                integer = integer * 10 + (s[position] - '0');
                position++;
            }

            struct NestedInteger *item = NestedIntegerInit();
            if (item == NULL) {
                free(stack);
                return NULL;
            }
            NestedIntegerSetInteger(item, sign * integer);
            if (top > 0) {
                NestedIntegerAdd(stack[top - 1], item);
            } else {
                root = item;
            }
        }
    }

    free(stack);
    return root;
}

/* ---- generated tests ---- */
static void freeNestedValue(struct NestedInteger *value) {
    if (!value->isInteger) {
        for (int i = 0; i < value->size; i++) {
            freeNestedValue(value->items[i]);
        }
    }
    free(value->items);
    free(value);
}

int main(void) {
    struct NestedInteger *number = deserialize("324");
    struct NestedInteger *nested = deserialize("[123,[456,[789]]]");
    struct NestedInteger *empty = deserialize("[]");

    bool passed = number != NULL && NestedIntegerIsInteger(number) &&
                  NestedIntegerGetInteger(number) == 324 &&
                  nested != NULL && !NestedIntegerIsInteger(nested) &&
                  NestedIntegerGetListSize(nested) == 2 &&
                  NestedIntegerGetInteger(NestedIntegerGetList(nested)[0]) == 123;
    if (passed) {
        struct NestedInteger *second = NestedIntegerGetList(nested)[1];
        struct NestedInteger *third = NestedIntegerGetList(second)[1];
        passed = NestedIntegerGetInteger(NestedIntegerGetList(second)[0]) == 456 &&
                 NestedIntegerGetInteger(NestedIntegerGetList(third)[0]) == 789 &&
                 empty != NULL && NestedIntegerGetListSize(empty) == 0;
    }

    freeNestedValue(number);
    freeNestedValue(nested);
    freeNestedValue(empty);
    printf("%s: 0385 deserialize tests=3\n", passed ? "PASS" : "FAIL");
    return passed ? 0 : 1;
}

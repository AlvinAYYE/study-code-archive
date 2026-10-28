/*
 * LeetCode 0341. Flatten Nested List Iterator（扁平化巢狀清單迭代器）
 * Difficulty: Medium
 * 題意：給定由整數和巢狀清單組成的資料，建立迭代器，讓 next 依原本由左至右、由外至內的順序逐一回傳所有整數；hasNext 判斷是否還有整數。
 * 範例：
 *   1. 輸入：nestedList = [[1,1],2,[1,1]]；依序 next 得到 [1,1,2,1,1]。
 *   2. 輸入：nestedList = [1,[4,[6]]]；依序 next 得到 [1,4,6]。
 * 限制：
 *   - 1 <= nestedList.length <= 500
 *   - 巢狀清單中的整數介於 -10^6 和 10^6
 * 解法：
 *   1. 建立迭代器時，使用深度優先走訪巢狀清單：遇到整數就放入一維陣列，遇到子清單就依序遞迴展開。
 *   2. 迭代器保存攤平後的陣列、元素數量和目前索引。
 *   3. hasNext 檢查索引是否小於元素數量；next 回傳目前元素後將索引加一。
 *   4. 把展開工作集中在建立階段，讓每次讀取都只需 O(1)。
 * 複雜度：建立時間 O(N)，每次 next/hasNext 為 O(1)，額外空間 O(N)；N 是巢狀結構中的整數數量。
 */
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/* Local test representation of the platform NestedInteger interface. */
struct NestedInteger {
    bool isInteger;
    int value;
    struct NestedInteger **items;
    int size;
    int capacity;
};

bool NestedIntegerIsInteger(struct NestedInteger *value);
int NestedIntegerGetInteger(struct NestedInteger *value);
struct NestedInteger **NestedIntegerGetList(struct NestedInteger *value);
int NestedIntegerGetListSize(struct NestedInteger *value);

struct NestedIterator {
    int *values;
    int size;
    int capacity;
    int nextIndex;
};

/* ---- community solution ---- */
static bool appendFlattenedValue(struct NestedIterator *iter, int value) {
    if (iter->size == iter->capacity) {
        int newCapacity = iter->capacity == 0 ? 16 : iter->capacity * 2;
        int *grown = (int *)realloc(iter->values,
                                    sizeof(int) * (size_t)newCapacity);
        if (grown == NULL) {
            return false;
        }
        iter->values = grown;
        iter->capacity = newCapacity;
    }
    iter->values[iter->size++] = value;
    return true;
}

static bool flattenNestedValue(struct NestedInteger *value,
                               struct NestedIterator *iter) {
    if (NestedIntegerIsInteger(value)) {
        return appendFlattenedValue(iter, NestedIntegerGetInteger(value));
    }

    int childCount = NestedIntegerGetListSize(value);
    struct NestedInteger **children = NestedIntegerGetList(value);
    for (int i = 0; i < childCount; i++) {
        if (!flattenNestedValue(children[i], iter)) {
            return false;
        }
    }
    return true;
}

struct NestedIterator *nestedIterCreate(struct NestedInteger** nestedList,
                                        int nestedListSize) {
    struct NestedIterator *iter =
        (struct NestedIterator *)calloc(1, sizeof(*iter));
    if (iter == NULL) {
        return NULL;
    }

    for (int i = 0; i < nestedListSize; i++) {
        if (!flattenNestedValue(nestedList[i], iter)) {
            free(iter->values);
            free(iter);
            return NULL;
        }
    }
    return iter;
}

bool nestedIterHasNext(struct NestedIterator *iter) {
    return iter->nextIndex < iter->size;
}

int nestedIterNext(struct NestedIterator *iter) {
    if (!nestedIterHasNext(iter)) {
        return 0;
    }
    return iter->values[iter->nextIndex++];
}

void nestedIterFree(struct NestedIterator *iter) {
    if (iter != NULL) {
        free(iter->values);
        free(iter);
    }
}

/* ---- generated tests ---- */
bool NestedIntegerIsInteger(struct NestedInteger *value) {
    return value->isInteger;
}

int NestedIntegerGetInteger(struct NestedInteger *value) {
    return value->value;
}

struct NestedInteger **NestedIntegerGetList(struct NestedInteger *value) {
    return value->items;
}

int NestedIntegerGetListSize(struct NestedInteger *value) {
    return value->size;
}

static struct NestedInteger *makeNestedInteger(int value) {
    struct NestedInteger *item =
        (struct NestedInteger *)calloc(1, sizeof(*item));
    item->isInteger = true;
    item->value = value;
    return item;
}

static struct NestedInteger *makeNestedList(void) {
    return (struct NestedInteger *)calloc(1, sizeof(struct NestedInteger));
}

static void appendNestedItem(struct NestedInteger *list,
                             struct NestedInteger *item) {
    if (list->size == list->capacity) {
        int newCapacity = list->capacity == 0 ? 4 : list->capacity * 2;
        list->items = (struct NestedInteger **)realloc(
            list->items, sizeof(*list->items) * (size_t)newCapacity);
        list->capacity = newCapacity;
    }
    list->items[list->size++] = item;
}

static void freeNestedValue(struct NestedInteger *value) {
    if (!value->isInteger) {
        for (int i = 0; i < value->size; i++) {
            freeNestedValue(value->items[i]);
        }
    }
    free(value->items);
    free(value);
}

static bool checkFlatten(struct NestedInteger **input, int inputSize,
                         const int *expected, int expectedSize) {
    struct NestedIterator *iter = nestedIterCreate(input, inputSize);
    if (iter == NULL) {
        return false;
    }
    int index = 0;
    bool passed = true;
    while (nestedIterHasNext(iter)) {
        if (index >= expectedSize || nestedIterNext(iter) != expected[index]) {
            passed = false;
            break;
        }
        index++;
    }
    passed = passed && index == expectedSize && !nestedIterHasNext(iter);
    nestedIterFree(iter);
    return passed;
}

int main(void) {
    struct NestedInteger *left = makeNestedList();
    appendNestedItem(left, makeNestedInteger(1));
    appendNestedItem(left, makeNestedInteger(1));
    struct NestedInteger *right = makeNestedList();
    appendNestedItem(right, makeNestedInteger(1));
    appendNestedItem(right, makeNestedInteger(1));
    struct NestedInteger *caseOne[] = {left, makeNestedInteger(2), right};
    const int expectedOne[] = {1, 1, 2, 1, 1};

    struct NestedInteger *deep = makeNestedList();
    struct NestedInteger *inner = makeNestedList();
    struct NestedInteger *innermost = makeNestedList();
    appendNestedItem(innermost, makeNestedInteger(6));
    appendNestedItem(inner, makeNestedInteger(4));
    appendNestedItem(inner, innermost);
    appendNestedItem(deep, makeNestedInteger(1));
    appendNestedItem(deep, inner);
    struct NestedInteger *caseTwo[] = {deep};
    const int expectedTwo[] = {1, 4, 6};

    bool passed = checkFlatten(caseOne, 3, expectedOne, 5) &&
                  checkFlatten(caseTwo, 1, expectedTwo, 3);
    for (int i = 0; i < 3; i++) {
        freeNestedValue(caseOne[i]);
    }
    freeNestedValue(deep);
    printf("%s: 0341 NestedIterator tests=2\n", passed ? "PASS" : "FAIL");
    return passed ? 0 : 1;
}

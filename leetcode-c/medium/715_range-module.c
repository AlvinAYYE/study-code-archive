/*
 * LeetCode 715. Range Module（區間模組）
 *
 * 題意（繁體中文）：
 *   設計一個資料結構，追蹤哪些實數區間已被加入。所有區間採半開形式
 *   [left,right)，包含 left 但不包含 right。需要支援三種操作：加入區間、
 *   移除區間，以及查詢某個區間中的每一個數是否都正在被追蹤。
 *
 * 範例：
 *   依序執行 addRange(10,20)、removeRange(14,16)，之後：
 *   queryRange(10,14) 回傳 true；queryRange(13,15) 回傳 false；
 *   queryRange(16,17) 回傳 true。移除 [14,16) 不會移除右端的 16。
 *
 * 限制：1 <= left < right <= 10^9；最多呼叫 add、query、remove 共 10^4 次。
 *
 * 解題步驟：
 *   1. 把每個整數座標 x 視為單位區間 [x,x+1)，因此整數端點的半開區間
 *      [left,right) 可轉成座標格 left 到 right-1。
 *   2. 建立動態線段樹，涵蓋座標格 0..999999999。每個節點記錄整段是全追蹤、
 *      全未追蹤，或兩者混合；混合時才建立左右子節點。
 *   3. 加入或移除是區間指定操作，把涵蓋的節點整段設為追蹤或未追蹤；查詢
 *      則確認目標區間落入的節點都為全追蹤。統一的子樹可以直接回答，不必展開。
 *
 * 複雜度：座標範圍長度 C=10^9，每次區間操作 O(log C)，動態節點空間
 *   O(Q log C)，Q 為更新次數。
 * LeetCode C API：rangeModuleCreate、rangeModuleAddRange、
 *                  rangeModuleQueryRange、rangeModuleRemoveRange、rangeModuleFree
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define COORDINATE_LEFT 0
#define COORDINATE_RIGHT 999999999
#define NODE_MIXED (-1)

typedef struct {
    int leftChild;
    int rightChild;
    signed char state; /* 0=全未追蹤，1=全追蹤，-1=混合 */
} RangeNode;

typedef struct {
    RangeNode *nodes;
    int nodeCount;
    int capacity;
} RangeModule;

static bool reserveNodes(RangeModule *obj, int extra) {
    int needed = obj->nodeCount + extra;
    if (needed <= obj->capacity) return true;
    int newCapacity = obj->capacity;
    while (newCapacity < needed) {
        if (newCapacity > 1073741823) return false;
        newCapacity *= 2;
    }
    RangeNode *grown = (RangeNode *)realloc(
        obj->nodes, (size_t)newCapacity * sizeof *obj->nodes);
    if (grown == NULL) return false;
    obj->nodes = grown;
    obj->capacity = newCapacity;
    return true;
}

static int createNodeReserved(RangeModule *obj, int state) {
    int index = obj->nodeCount++;
    obj->nodes[index].leftChild = -1;
    obj->nodes[index].rightChild = -1;
    obj->nodes[index].state = (signed char)state;
    return index;
}

/* 將均一節點展開成兩個同狀態子節點，供部分區間更新使用。 */
static bool pushChildren(RangeModule *obj, int index) {
    int state = obj->nodes[index].state;
    if (state == NODE_MIXED) return true;
    int left = obj->nodes[index].leftChild;
    int right = obj->nodes[index].rightChild;
    if (left == -1) {
        if (!reserveNodes(obj, 2)) return false;
        left = createNodeReserved(obj, state);
        right = createNodeReserved(obj, state);
        obj->nodes[index].leftChild = left;
        obj->nodes[index].rightChild = right;
    } else {
        /* 父節點曾經整段覆寫；舊子樹已過期，重設其根狀態即可。 */
        obj->nodes[left].state = (signed char)state;
        obj->nodes[right].state = (signed char)state;
    }
    obj->nodes[index].state = NODE_MIXED;
    return true;
}

static bool updateRange(RangeModule *obj, int index, int low, int high,
                        int queryLow, int queryHigh, int state) {
    if (queryLow <= low && high <= queryHigh) {
        obj->nodes[index].state = (signed char)state;
        return true;
    }
    if (low == high || !pushChildren(obj, index)) return false;

    int middle = low + (high - low) / 2;
    int left = obj->nodes[index].leftChild;
    int right = obj->nodes[index].rightChild;
    if (queryLow <= middle &&
        !updateRange(obj, left, low, middle, queryLow, queryHigh, state))
        return false;
    if (queryHigh > middle &&
        !updateRange(obj, right, middle + 1, high, queryLow, queryHigh, state))
        return false;

    int leftState = obj->nodes[left].state;
    int rightState = obj->nodes[right].state;
    obj->nodes[index].state =
        (leftState == rightState && leftState != NODE_MIXED)
            ? (signed char)leftState
            : NODE_MIXED;
    return true;
}

static bool queryRange(const RangeModule *obj, int index, int low, int high,
                       int queryLow, int queryHigh) {
    int state = obj->nodes[index].state;
    if (state == 0) return false;
    if (state == 1) return true;
    if (queryLow <= low && high <= queryHigh) return false;

    int middle = low + (high - low) / 2;
    int left = obj->nodes[index].leftChild;
    int right = obj->nodes[index].rightChild;
    if (queryHigh <= middle)
        return queryRange(obj, left, low, middle, queryLow, queryHigh);
    if (queryLow > middle)
        return queryRange(obj, right, middle + 1, high, queryLow, queryHigh);
    return queryRange(obj, left, low, middle, queryLow, queryHigh) &&
           queryRange(obj, right, middle + 1, high, queryLow, queryHigh);
}

RangeModule *rangeModuleCreate(void) {
    RangeModule *obj = (RangeModule *)malloc(sizeof *obj);
    if (obj == NULL) return NULL;
    obj->capacity = 16;
    obj->nodeCount = 1;
    obj->nodes = (RangeNode *)malloc((size_t)obj->capacity * sizeof *obj->nodes);
    if (obj->nodes == NULL) {
        free(obj);
        return NULL;
    }
    obj->nodes[0] = (RangeNode){-1, -1, 0};
    return obj;
}

void rangeModuleAddRange(RangeModule *obj, int left, int right) {
    if (obj == NULL || left >= right) return;
    (void)updateRange(obj, 0, COORDINATE_LEFT, COORDINATE_RIGHT,
                      left, right - 1, 1);
}

bool rangeModuleQueryRange(RangeModule *obj, int left, int right) {
    if (obj == NULL || left >= right) return false;
    return queryRange(obj, 0, COORDINATE_LEFT, COORDINATE_RIGHT,
                      left, right - 1);
}

void rangeModuleRemoveRange(RangeModule *obj, int left, int right) {
    if (obj == NULL || left >= right) return;
    (void)updateRange(obj, 0, COORDINATE_LEFT, COORDINATE_RIGHT,
                      left, right - 1, 0);
}

void rangeModuleFree(RangeModule *obj) {
    if (obj == NULL) return;
    free(obj->nodes);
    free(obj);
}

int main(void) {
    RangeModule *rangeModule = rangeModuleCreate();
    if (rangeModule == NULL) return 1;

    rangeModuleAddRange(rangeModule, 10, 20);
    rangeModuleRemoveRange(rangeModule, 14, 16);
    int passed = rangeModuleQueryRange(rangeModule, 10, 14) &&
                 !rangeModuleQueryRange(rangeModule, 13, 15) &&
                 rangeModuleQueryRange(rangeModule, 16, 17);
    rangeModuleAddRange(rangeModule, 14, 16);
    passed = passed && rangeModuleQueryRange(rangeModule, 10, 20);
    rangeModuleRemoveRange(rangeModule, 10, 20);
    passed = passed && !rangeModuleQueryRange(rangeModule, 10, 20);
    rangeModuleAddRange(rangeModule, 1, 1000000000);
    passed = passed && rangeModuleQueryRange(rangeModule, 1, 1000000000);
    rangeModuleFree(rangeModule);

    puts(passed ? "PASS: 715 range-module" : "FAIL: 715 range-module");
    return passed ? 0 : 1;
}

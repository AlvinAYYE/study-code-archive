/*
 * LeetCode 155. Min Stack
 * Title-CN: 最小堆疊
 *
 * 題目翻譯：設計一個堆疊，支援 push（加入）、pop（移除頂端）、top（讀取頂端）與 getMin
 * （讀取目前最小值）。每一種操作都必須在 O(1) 時間完成。
 *
 * 操作範例：
 * push(-2), push(0), push(-3), getMin() -> -3, pop(), top() -> 0, getMin() -> -2。
 * 每次 pop 只移除最上方元素；移除 -3 後，堆疊仍有 -2 與 0，最小值因此回到 -2。
 *
 * 限制：-2^31 <= val <= 2^31 - 1；pop、top、getMin 一定會在非空堆疊上呼叫；
 * push、pop、top、getMin 的總呼叫次數最多 3 * 10^4。
 *
 * 解題思路：每個堆疊節點除了自己的值，也記錄「從底部到此節點」的最小值。
 * 1. push 時，新節點的最小值取自身值與舊頂端最小值兩者較小者。
 * 2. pop 時刪除頂端節點；新的頂端節點已保存剩餘堆疊的最小值。
 * 3. top 讀頂端值，getMin 讀頂端記錄的最小值，因此都不必掃描整個堆疊。
 *
 * 複雜度：push、pop、top、getMin 各為 O(1)；空間 O(n)，n 為目前堆疊大小。
 *
 * LeetCode C API：
 * MinStack *minStackCreate(void);
 * void minStackPush(MinStack *obj, int val);
 * void minStackPop(MinStack *obj);
 * int minStackTop(MinStack *obj);
 * int minStackGetMin(MinStack *obj);
 * void minStackFree(MinStack *obj);
 */
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode {
    int value;
    int minimum;
    struct StackNode *next;
} StackNode;

typedef struct {
    StackNode *top;
} MinStack;

/* LeetCode 提交 API */
MinStack *minStackCreate(void) {
    return (MinStack *)calloc(1, sizeof(MinStack));
}

void minStackPush(MinStack *obj, int val) {
    if (obj == NULL) return;

    StackNode *node = (StackNode *)malloc(sizeof *node);
    if (node == NULL) return;

    node->value = val;
    node->minimum = (obj->top == NULL || val < obj->top->minimum)
                        ? val
                        : obj->top->minimum;
    node->next = obj->top;
    obj->top = node;
}

void minStackPop(MinStack *obj) {
    if (obj == NULL || obj->top == NULL) return;

    StackNode *oldTop = obj->top;
    obj->top = oldTop->next;
    free(oldTop);
}

int minStackTop(MinStack *obj) {
    return (obj == NULL || obj->top == NULL) ? 0 : obj->top->value;
}

int minStackGetMin(MinStack *obj) {
    return (obj == NULL || obj->top == NULL) ? 0 : obj->top->minimum;
}

void minStackFree(MinStack *obj) {
    if (obj == NULL) return;

    while (obj->top != NULL) {
        StackNode *oldTop = obj->top;
        obj->top = oldTop->next;
        free(oldTop);
    }
    free(obj);
}

int main(void) {
    MinStack *stack = minStackCreate();
    if (stack == NULL) return 1;

    minStackPush(stack, -2);
    minStackPush(stack, 0);
    minStackPush(stack, -3);
    int passed = minStackGetMin(stack) == -3;
    minStackPop(stack);
    passed = passed && minStackTop(stack) == 0 && minStackGetMin(stack) == -2;
    minStackPop(stack);
    minStackPush(stack, -2);
    minStackPush(stack, INT_MIN);
    minStackPush(stack, INT_MIN);
    passed = passed && minStackGetMin(stack) == INT_MIN;
    minStackPop(stack);
    passed = passed && minStackGetMin(stack) == INT_MIN;
    minStackPop(stack);
    passed = passed && minStackGetMin(stack) == -2;

    minStackFree(stack);
    puts(passed ? "PASS: 155 min-stack" : "FAIL: 155 min-stack");
    return passed ? 0 : 1;
}

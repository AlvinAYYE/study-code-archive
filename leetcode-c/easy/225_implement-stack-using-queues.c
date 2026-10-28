/*
 * LeetCode 225. Implement Stack using Queues
 * Title-CN: 用佇列實作堆疊
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/implement-stack-using-queues/
 *
 * [題目翻譯]
 * 只使用兩個佇列，實作後進先出（LIFO）的堆疊，支援 push、pop、top、empty。
 * pop 與 top 呼叫時一定有元素。進階：能否只用一個佇列完成？
 *
 * [範例]
 * 操作：push(1)、push(2)、top()、pop()、empty()
 * 回傳：  null、null、2、2、false
 *
 * [限制]
 * 1 <= x <= 9；push、pop、top、empty 總呼叫次數不超過 100；
 * pop 與 top 呼叫時堆疊不為空。
 *
 * [解題思路]
 * 佇列先進先出，堆疊後進先出。push(x) 時先把 x 放入輔助佇列，
 * 再把主佇列的舊元素依序接在 x 後面，最後交換兩個佇列的角色。
 * 如此主佇列的最前端永遠是最新加入的元素，pop/top 都能直接取得堆疊頂端。
 * push 為 O(n)，其餘操作為 O(1)，空間為 O(n)。
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int values[100];
    int front;
    int size;
} Queue;

typedef struct {
    Queue mainQueue;
    Queue helperQueue;
} MyStack;

static bool queueIsEmpty(const Queue* queue) {
    return queue->size == 0;
}

static void enqueue(Queue* queue, int value) {
    queue->values[queue->front + queue->size] = value;
    ++queue->size;
}

static int dequeue(Queue* queue) {
    int value = queue->values[queue->front++];
    --queue->size;
    if (queue->size == 0) {
        queue->front = 0;
    }
    return value;
}

/* ---------- LeetCode submission / 提交區 ---------- */
MyStack* myStackCreate(void) {
    return (MyStack*)calloc(1, sizeof(MyStack));
}

void myStackPush(MyStack* obj, int x) {
    enqueue(&obj->helperQueue, x);
    while (!queueIsEmpty(&obj->mainQueue)) {
        enqueue(&obj->helperQueue, dequeue(&obj->mainQueue));
    }

    /* 輔助佇列現在已按堆疊順序排好，交換兩個佇列。 */
    Queue temporary = obj->mainQueue;
    obj->mainQueue = obj->helperQueue;
    obj->helperQueue = temporary;
}

int myStackPop(MyStack* obj) {
    return dequeue(&obj->mainQueue);
}

int myStackTop(MyStack* obj) {
    return obj->mainQueue.values[obj->mainQueue.front];
}

bool myStackEmpty(MyStack* obj) {
    return queueIsEmpty(&obj->mainQueue);
}

void myStackFree(MyStack* obj) {
    free(obj);
}
/* ---------- end submission ---------- */

int main(void) {
    MyStack* stack = myStackCreate();
    int ok = stack != NULL;
    if (ok) {
        myStackPush(stack, 1);
        myStackPush(stack, 2);
        ok = myStackTop(stack) == 2 && myStackPop(stack) == 2 &&
             myStackTop(stack) == 1 && !myStackEmpty(stack) &&
             myStackPop(stack) == 1 && myStackEmpty(stack);
        myStackFree(stack);
    }
    printf("%s: 225 implement-stack-using-queues\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

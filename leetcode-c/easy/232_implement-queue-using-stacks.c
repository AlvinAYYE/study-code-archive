/*
 * LeetCode 232. Implement Queue using Stacks
 * Title-CN: 用堆疊實作佇列
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/implement-queue-using-stacks/
 *
 * [題目翻譯]
 * 只使用兩個堆疊，實作先進先出（FIFO）的佇列，支援 push、pop、peek、empty。
 * pop 與 peek 呼叫時一定有元素。進階：讓每個操作的攤銷時間為 O(1)。
 *
 * [範例]
 * 操作：push(1)、push(2)、peek()、pop()、empty()
 * 回傳：  null、null、1、1、false
 *
 * [限制]
 * 1 <= x <= 9；四種操作總呼叫次數不超過 100；pop 與 peek 呼叫時佇列不為空。
 *
 * [解題思路]
 * 新元素先放進輸入堆疊。需要查看或移除隊首時，若輸出堆疊為空，
 * 就把輸入堆疊全部倒入輸出堆疊；倒過來後，最早加入的元素會位於頂端。
 * 每個元素最多搬一次，因此 push、pop、peek 的攤銷時間都是 O(1)，空間 O(n)。
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int input[100];
    int inputSize;
    int output[100];
    int outputSize;
} MyQueue;

static void moveToOutput(MyQueue* obj) {
    if (obj->outputSize == 0) {
        while (obj->inputSize > 0) {
            obj->output[obj->outputSize++] = obj->input[--obj->inputSize];
        }
    }
}

/* ---------- LeetCode submission / 提交區 ---------- */
MyQueue* myQueueCreate(void) {
    return (MyQueue*)calloc(1, sizeof(MyQueue));
}

void myQueuePush(MyQueue* obj, int x) {
    obj->input[obj->inputSize++] = x;
}

int myQueuePop(MyQueue* obj) {
    moveToOutput(obj);
    return obj->output[--obj->outputSize];
}

int myQueuePeek(MyQueue* obj) {
    moveToOutput(obj);
    return obj->output[obj->outputSize - 1];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->inputSize == 0 && obj->outputSize == 0;
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}
/* ---------- end submission ---------- */

int main(void) {
    MyQueue* queue = myQueueCreate();
    int ok = queue != NULL;
    if (ok) {
        myQueuePush(queue, 1);
        myQueuePush(queue, 2);
        ok = myQueuePeek(queue) == 1 && myQueuePop(queue) == 1 &&
             myQueuePeek(queue) == 2 && !myQueueEmpty(queue) &&
             myQueuePop(queue) == 2 && myQueueEmpty(queue);
        myQueueFree(queue);
    }
    printf("%s: 232 implement-queue-using-stacks\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

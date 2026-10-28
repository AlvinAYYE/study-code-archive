/*
 * Title-CN: 設計循環佇列
 * LeetCode 622. Design Circular Queue
 *
 * 題意翻譯：設計固定容量的循環佇列，支援從尾端加入、從前端移除、查看隊首與隊尾，
 * 並判斷空或滿。滿時不能加入，空時不能移除或查看；失敗回傳 false 或 -1。
 *
 * 範例：容量 3，依序加入 1、2、3 後佇列已滿；移除 1 後可以再加入 4，
 * 此時隊尾為 4。
 *
 * 限制：0 <= k <= 1000；呼叫次數不超過 3000。
 *
 * 解題思路：用陣列保存資料，front 指向隊首，size 記錄目前元素數量。尾端位置為
 * (front+size) 對容量取餘數；移除隊首時只移動 front。取餘數讓索引走到陣列尾端後
 * 回到開頭，因此不用搬移其他元素。
 *
 * 複雜度：每個操作 O(1)，空間 O(k)。
 * LeetCode 介面：保留 MyCircularQueue 操作與 myCircularQueueFree；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int *values;
    int capacity;
    int front;
    int size;
} MyCircularQueue;

MyCircularQueue *myCircularQueueCreate(int k) {
    MyCircularQueue *queue = malloc(sizeof(*queue));
    if (queue == NULL) return NULL;
    queue->values = k > 0 ? malloc((size_t)k * sizeof(*queue->values)) : NULL;
    if (k > 0 && queue->values == NULL) {
        free(queue);
        return NULL;
    }
    queue->capacity = k;
    queue->front = 0;
    queue->size = 0;
    return queue;
}

bool myCircularQueueEnQueue(MyCircularQueue *obj, int value) {
    if (obj->size == obj->capacity) return false;
    int rear = (obj->front + obj->size) % obj->capacity;
    obj->values[rear] = value;
    ++obj->size;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue *obj) {
    if (obj->size == 0) return false;
    obj->front = (obj->front + 1) % obj->capacity;
    --obj->size;
    return true;
}

int myCircularQueueFront(MyCircularQueue *obj) {
    return obj->size == 0 ? -1 : obj->values[obj->front];
}

int myCircularQueueRear(MyCircularQueue *obj) {
    if (obj->size == 0) return -1;
    int rear = (obj->front + obj->size - 1) % obj->capacity;
    return obj->values[rear];
}

bool myCircularQueueIsEmpty(MyCircularQueue *obj) {
    return obj->size == 0;
}

bool myCircularQueueIsFull(MyCircularQueue *obj) {
    return obj->size == obj->capacity;
}

void myCircularQueueFree(MyCircularQueue *obj) {
    if (obj == NULL) return;
    free(obj->values);
    free(obj);
}

int main(void) {
    MyCircularQueue *queue = myCircularQueueCreate(3);
    assert(queue != NULL && myCircularQueueIsEmpty(queue));
    assert(myCircularQueueEnQueue(queue, 1));
    assert(myCircularQueueEnQueue(queue, 2));
    assert(myCircularQueueEnQueue(queue, 3));
    assert(!myCircularQueueEnQueue(queue, 4) && myCircularQueueIsFull(queue));
    assert(myCircularQueueRear(queue) == 3 && myCircularQueueFront(queue) == 1);
    assert(myCircularQueueDeQueue(queue));
    assert(myCircularQueueEnQueue(queue, 4));
    assert(myCircularQueueRear(queue) == 4 && myCircularQueueFront(queue) == 2);
    myCircularQueueFree(queue);
    return 0;
}

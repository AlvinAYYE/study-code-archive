/*
 * Title-CN: 設計循環雙端佇列
 * LeetCode 641. Design Circular Deque
 *
 * 題意翻譯：設計固定容量的雙端佇列，支援從前端或尾端插入、從兩端刪除、
 * 查看兩端元素，以及判斷空或滿。滿時插入失敗；空時刪除失敗或查詢回傳 -1。
 *
 * 範例：容量 3 時，可先從前端加入 2，再從尾端加入 3；前端為 2，尾端為 3。
 *
 * 限制：0 <= k <= 1000；呼叫次數不超過 2000。
 *
 * 解題思路：用陣列搭配 front（目前第一個元素的位置）和 size（元素數量）。
 * 前端插入時把 front 往回一格並環繞；尾端插入位置是 (front+size) 對容量取餘數。
 * 刪除只調整 front 或 size，不搬動其他資料。
 *
 * 複雜度：每個操作 O(1)，空間 O(k)。
 * LeetCode 介面：保留 MyCircularDeque 操作與 myCircularDequeFree；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int *values;
    int capacity;
    int front;
    int size;
} MyCircularDeque;

MyCircularDeque *myCircularDequeCreate(int k) {
    MyCircularDeque *deque = malloc(sizeof(*deque));
    if (deque == NULL) return NULL;
    deque->values = k > 0 ? malloc((size_t)k * sizeof(*deque->values)) : NULL;
    if (k > 0 && deque->values == NULL) {
        free(deque);
        return NULL;
    }
    deque->capacity = k;
    deque->front = 0;
    deque->size = 0;
    return deque;
}

bool myCircularDequeInsertFront(MyCircularDeque *obj, int value) {
    if (obj->size == obj->capacity) return false;
    obj->front = (obj->front - 1 + obj->capacity) % obj->capacity;
    obj->values[obj->front] = value;
    ++obj->size;
    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque *obj, int value) {
    if (obj->size == obj->capacity) return false;
    int rear = (obj->front + obj->size) % obj->capacity;
    obj->values[rear] = value;
    ++obj->size;
    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque *obj) {
    if (obj->size == 0) return false;
    obj->front = (obj->front + 1) % obj->capacity;
    --obj->size;
    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque *obj) {
    if (obj->size == 0) return false;
    --obj->size;
    return true;
}

int myCircularDequeGetFront(MyCircularDeque *obj) {
    return obj->size == 0 ? -1 : obj->values[obj->front];
}

int myCircularDequeGetRear(MyCircularDeque *obj) {
    if (obj->size == 0) return -1;
    int rear = (obj->front + obj->size - 1) % obj->capacity;
    return obj->values[rear];
}

bool myCircularDequeIsEmpty(MyCircularDeque *obj) {
    return obj->size == 0;
}

bool myCircularDequeIsFull(MyCircularDeque *obj) {
    return obj->size == obj->capacity;
}

void myCircularDequeFree(MyCircularDeque *obj) {
    if (obj == NULL) return;
    free(obj->values);
    free(obj);
}

int main(void) {
    MyCircularDeque *deque = myCircularDequeCreate(3);
    assert(deque != NULL);
    assert(myCircularDequeInsertLast(deque, 1));
    assert(myCircularDequeInsertLast(deque, 2));
    assert(myCircularDequeInsertFront(deque, 3));
    assert(!myCircularDequeInsertFront(deque, 4));
    assert(myCircularDequeGetFront(deque) == 3 && myCircularDequeGetRear(deque) == 2);
    assert(myCircularDequeDeleteLast(deque));
    assert(myCircularDequeInsertFront(deque, 4));
    assert(myCircularDequeGetFront(deque) == 4 && myCircularDequeGetRear(deque) == 1);
    myCircularDequeFree(deque);
    return 0;
}

/*
 * LeetCode 0707. Design Linked List（設計鏈結串列）
 * 題意：實作可依索引讀取、在頭尾或指定位置插入，以及依索引刪除節點的單向鏈結串列。
 * 範例：addAtHead(1), addAtTail(3), addAtIndex(1,2) 得到 1->2->3；
 *       get(1) 回傳 2，刪除索引 1 後 get(1) 回傳 3。
 * 限制：index、val 為 0 到 1000；操作呼叫總數不超過 2000；不可使用內建 LinkedList。
 * 解法：用 dummy 假頭節點簡化頭部插入與刪除；每次沿 next 指標走到目標前一格再操作。
 * 複雜度：每個操作最壞 O(n)，額外空間 O(n)。
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int value;
    struct ListNode *next;
} ListNode;

typedef struct {
    ListNode *dummy;
    int size;
} MyLinkedList;

/* ---- community solution ---- */
MyLinkedList* myLinkedListCreate(void) {
    MyLinkedList *list = (MyLinkedList *)malloc(sizeof(*list));
    ListNode *dummy = (ListNode *)malloc(sizeof(*dummy));
    if (list == NULL || dummy == NULL) {
        free(list);
        free(dummy);
        return NULL;
    }
    dummy->next = NULL;
    list->dummy = dummy;
    list->size = 0;
    return list;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if (obj == NULL || index < 0 || index >= obj->size) {
        return -1;
    }
    ListNode *node = obj->dummy->next;
    for (int i = 0; i < index; i++) {
        node = node->next;
    }
    return node->value;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (obj == NULL || index > obj->size) {
        return;
    }
    if (index < 0) {
        index = 0;
    }
    ListNode *previous = obj->dummy;
    for (int i = 0; i < index; i++) {
        previous = previous->next;
    }
    ListNode *node = (ListNode *)malloc(sizeof(*node));
    if (node == NULL) {
        return;
    }
    node->value = val;
    node->next = previous->next;
    previous->next = node;
    obj->size++;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    myLinkedListAddAtIndex(obj, 0, val);
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    if (obj != NULL) {
        myLinkedListAddAtIndex(obj, obj->size, val);
    }
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (obj == NULL || index < 0 || index >= obj->size) {
        return;
    }
    ListNode *previous = obj->dummy;
    for (int i = 0; i < index; i++) {
        previous = previous->next;
    }
    ListNode *removed = previous->next;
    previous->next = removed->next;
    free(removed);
    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    if (obj == NULL) {
        return;
    }
    ListNode *node = obj->dummy;
    while (node != NULL) {
        ListNode *next = node->next;
        free(node);
        node = next;
    }
    free(obj);
}

/* ---- generated tests ---- */
int main(void) {
    MyLinkedList *list = myLinkedListCreate();
    if (list == NULL) {
        return 1;
    }
    myLinkedListAddAtHead(list, 1);
    myLinkedListAddAtTail(list, 3);
    myLinkedListAddAtIndex(list, 1, 2);
    bool passed = myLinkedListGet(list, 1) == 2;
    myLinkedListDeleteAtIndex(list, 1);
    passed = passed && myLinkedListGet(list, 1) == 3 &&
             myLinkedListGet(list, 3) == -1;
    myLinkedListAddAtIndex(list, 1, 4);
    passed = passed && myLinkedListGet(list, 1) == 4;
    myLinkedListAddAtIndex(list, 99, 8);
    myLinkedListDeleteAtIndex(list, 99);
    passed = passed && myLinkedListGet(list, 3) == -1;
    myLinkedListFree(list);
    printf("%s: 0707 MyLinkedList tests=5\n", passed ? "PASS" : "FAIL");
    return passed ? 0 : 1;
}

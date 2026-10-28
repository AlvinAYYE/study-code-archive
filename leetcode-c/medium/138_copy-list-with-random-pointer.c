/*
 * LeetCode 138. Copy List with Random Pointer
 * Title-CN: 複製帶有隨機指標的鏈結串列
 *
 * 題目翻譯：每個節點除了 next，還有一個 random 指標；random 可以指向串列中的任一節點，
 * 也可以是 NULL。請建立一條全新的深層複本，讓複本節點的值與兩種指標關係都和原串列一致。
 * 複本中的 next、random 都只能指向複本節點，不能指回原串列，最後回傳複本的頭節點。
 * 輸入中的 random_index 代表 random 指向的節點索引，null 代表沒有指向任何節點。
 *
 * 範例：
 * 1. [[7,null],[13,0],[11,4],[10,2],[1,0]] -> [[7,null],[13,0],[11,4],[10,2],[1,0]]。
 * 2. [[1,1],[2,1]] -> [[1,1],[2,1]]。
 * 3. [[3,null],[3,0],[3,null]] -> [[3,null],[3,0],[3,null]]；節點值相同仍須複製成不同節點。
 *
 * 限制：節點數 0 到 1000；-10^4 <= Node.val <= 10^4；random 為 NULL 或指向原串列中的節點。
 *
 * 解題思路：把複製節點暫時插在對應原節點後方，讓原節點的 random->next 就是複本目標。
 * 1. 走訪原串列，在每個原節點後插入一個同值複製節點。
 * 2. 再走一次，設定複製節點的 random：原節點 random 為 NULL 就設 NULL，否則接到 random->next。
 * 3. 最後將交錯串列拆開，恢復原串列並串起複本串列。
 *
 * 複雜度：時間 O(n)，除新串列外額外空間 O(1)。
 *
 * LeetCode C API：struct Node *copyRandomList(struct Node *head)
 */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
    struct Node *random;
};

/* LeetCode 提交函式：交錯原節點與複製節點，避免使用雜湊表。 */
struct Node *copyRandomList(struct Node *head) {
    if (head == NULL) return NULL;

    /* 第一步：每個原節點後方插入一個複製節點。 */
    struct Node *current = head;
    while (current != NULL) {
        struct Node *copy = (struct Node *)malloc(sizeof *copy);
        if (copy == NULL) {
            /* 配置失敗時，把已插入的複製節點移除並還原原串列。 */
            struct Node *original = head;
            while (original != current) {
                struct Node *createdCopy = original->next;
                original->next = createdCopy->next;
                free(createdCopy);
                original = original->next;
            }
            return NULL;
        }
        copy->val = current->val;
        copy->random = NULL;
        copy->next = current->next;
        current->next = copy;
        current = copy->next;
    }

    /* 第二步：原節點 random 的下一個節點，就是對應的複製節點。 */
    for (current = head; current != NULL; current = current->next->next) {
        if (current->random != NULL) {
            current->next->random = current->random->next;
        }
    }

    /* 第三步：拆開交錯串列，同時把原串列接回原狀。 */
    struct Node *copyHead = head->next;
    current = head;
    while (current != NULL) {
        struct Node *copy = current->next;
        struct Node *nextOriginal = copy->next;
        current->next = nextOriginal;
        copy->next = (nextOriginal != NULL) ? nextOriginal->next : NULL;
        current = nextOriginal;
    }

    return copyHead;
}

static int checkCopy(struct Node *original, struct Node *copy,
                     const int *randomIndices, int count) {
    struct Node *copies[5];
    struct Node *cursor = copy;

    for (int i = 0; i < count; ++i) {
        if (cursor == NULL) return 0;
        copies[i] = cursor;
        cursor = cursor->next;
    }
    if (cursor != NULL) return 0;

    for (int i = 0; i < count; ++i) {
        if (copies[i] == &original[i] || copies[i]->val != original[i].val) return 0;
        if (i + 1 < count && copies[i]->next != copies[i + 1]) return 0;
        if (randomIndices[i] < 0) {
            if (copies[i]->random != NULL) return 0;
        } else if (copies[i]->random != copies[randomIndices[i]]) {
            return 0;
        }
    }
    return 1;
}

static int runExample(const int *values, const int *randomIndices, int count) {
    struct Node original[5];
    for (int i = 0; i < count; ++i) {
        original[i].val = values[i];
        original[i].next = (i + 1 < count) ? &original[i + 1] : NULL;
        original[i].random = (randomIndices[i] < 0) ? NULL : &original[randomIndices[i]];
    }

    struct Node *copy = copyRandomList(count == 0 ? NULL : &original[0]);
    int passed = (count == 0) ? copy == NULL : checkCopy(original, copy, randomIndices, count);

    struct Node *cursor = copy;
    while (cursor != NULL) {
        struct Node *next = cursor->next;
        free(cursor);
        cursor = next;
    }

    /* 深層複製也不能破壞原本的 next 串列。 */
    for (int i = 0; i < count; ++i) {
        struct Node *expectedNext = (i + 1 < count) ? &original[i + 1] : NULL;
        if (original[i].next != expectedNext) passed = 0;
    }
    return passed;
}

int main(void) {
    const int values1[] = {7, 13, 11, 10, 1};
    const int randoms1[] = {-1, 0, 4, 2, 0};
    const int values2[] = {1, 2};
    const int randoms2[] = {1, 1};
    const int values3[] = {3, 3, 3};
    const int randoms3[] = {-1, 0, -1};

    int passed = runExample(values1, randoms1, 5);
    passed = runExample(values2, randoms2, 2) && passed;
    passed = runExample(values3, randoms3, 3) && passed;
    passed = runExample(NULL, NULL, 0) && passed;

    puts(passed ? "PASS: 138 copy-list-with-random-pointer"
                : "FAIL: 138 copy-list-with-random-pointer");
    return passed ? 0 : 1;
}

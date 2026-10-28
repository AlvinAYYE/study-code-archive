/*
 * LeetCode 133. Clone Graph／克隆圖
 * 題目：給定一個連通無向圖的節點參考，建立整張圖的深層複製並回傳複本起點。
 *       每個節點含整數 val 與鄰居清單；節點值唯一，起點值為 1。
 *
 * 範例 1：鄰接表 [[2,4],[1,3],[2,4],[1,3]]，複本的鄰接表相同。
 * 範例 2：鄰接表 [[]]，代表只有一個節點且沒有鄰居，複本仍是單一節點。
 * 範例 3：鄰接表 []，空圖回傳 NULL。
 * 限制：節點數介於 0 到 100；1 <= Node.val <= 100；沒有重複邊或自環；
 *       從起點可以走到所有節點。
 *
 * 解題步驟：
 *   1. 用 val 對應複製節點的表格，先建立起點複本並放入佇列。
 *   2. 逐一取出原圖節點，檢查每個鄰居；尚未複製就建立新節點並排入佇列。
 *   3. 將目前複製節點的 neighbors 指到對應複本，而非原圖節點。
 *   4. 佇列清空時，整張可達圖都已複製完成。
 *   時間 O(V+E)，額外空間 O(V)（映射表與佇列），輸出圖另占 O(V+E)。
 *
 * LeetCode 提供 Node 型別；此檔案中的定義與 main 僅供本機測試。
 */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    int numNeighbors;
    struct Node **neighbors;
};

#define MAX_GRAPH_NODES 100

static struct Node *createNode(int value, int neighborCount) {
    struct Node *node = (struct Node *)malloc(sizeof *node);
    if (node == NULL) return NULL;
    node->val = value;
    node->numNeighbors = neighborCount;
    node->neighbors = NULL;
    if (neighborCount > 0) {
        node->neighbors = (struct Node **)malloc(
            (size_t)neighborCount * sizeof *node->neighbors);
        if (node->neighbors == NULL) {
            free(node);
            return NULL;
        }
    }
    return node;
}

static void freeClones(struct Node **copies) {
    for (int value = 1; value <= MAX_GRAPH_NODES; ++value) {
        if (copies[value] != NULL) {
            free(copies[value]->neighbors);
            free(copies[value]);
        }
    }
}

/* ---------- LeetCode submission / 提交區 ---------- */
struct Node *cloneGraph(struct Node *s) {
    struct Node *copies[MAX_GRAPH_NODES + 1] = {0};
    struct Node *queue[MAX_GRAPH_NODES];
    int head = 0, tail = 0;

    if (s == NULL) return NULL;

    copies[s->val] = createNode(s->val, s->numNeighbors);
    if (copies[s->val] == NULL) return NULL;
    queue[tail++] = s;

    while (head < tail) {
        struct Node *original = queue[head++];
        struct Node *copy = copies[original->val];

        for (int i = 0; i < original->numNeighbors; ++i) {
            struct Node *neighbor = original->neighbors[i];
            if (copies[neighbor->val] == NULL) {
                copies[neighbor->val] =
                    createNode(neighbor->val, neighbor->numNeighbors);
                if (copies[neighbor->val] == NULL) {
                    freeClones(copies);
                    return NULL;
                }
                queue[tail++] = neighbor;
            }
            /* 相鄰邊必須連到複本圖中的對應節點。 */
            copy->neighbors[i] = copies[neighbor->val];
        }
    }

    return copies[s->val];
}
/* ---------- end submission ---------- */

static struct Node *findNode(struct Node *start, int value) {
    struct Node *queue[MAX_GRAPH_NODES];
    int seen[MAX_GRAPH_NODES + 1] = {0};
    int head = 0, tail = 0;

    if (start == NULL) return NULL;
    queue[tail++] = start;
    seen[start->val] = 1;
    while (head < tail) {
        struct Node *node = queue[head++];
        if (node->val == value) return node;
        for (int i = 0; i < node->numNeighbors; ++i) {
            struct Node *neighbor = node->neighbors[i];
            if (!seen[neighbor->val]) {
                seen[neighbor->val] = 1;
                queue[tail++] = neighbor;
            }
        }
    }
    return NULL;
}

static void freeGraph(struct Node *start) {
    struct Node *nodes[MAX_GRAPH_NODES];
    int seen[MAX_GRAPH_NODES + 1] = {0};
    int head = 0, tail = 0;

    if (start == NULL) return;
    nodes[tail++] = start;
    seen[start->val] = 1;
    while (head < tail) {
        struct Node *node = nodes[head++];
        for (int i = 0; i < node->numNeighbors; ++i) {
            struct Node *neighbor = node->neighbors[i];
            if (!seen[neighbor->val]) {
                seen[neighbor->val] = 1;
                nodes[tail++] = neighbor;
            }
        }
    }
    for (int i = 0; i < tail; ++i) {
        free(nodes[i]->neighbors);
        free(nodes[i]);
    }
}

int main(void) {
    struct Node *n1Neighbors[2], *n2Neighbors[2];
    struct Node *n3Neighbors[2], *n4Neighbors[2];
    struct Node n1 = {1, 2, n1Neighbors};
    struct Node n2 = {2, 2, n2Neighbors};
    struct Node n3 = {3, 2, n3Neighbors};
    struct Node n4 = {4, 2, n4Neighbors};
    n1Neighbors[0] = &n2; n1Neighbors[1] = &n4;
    n2Neighbors[0] = &n1; n2Neighbors[1] = &n3;
    n3Neighbors[0] = &n2; n3Neighbors[1] = &n4;
    n4Neighbors[0] = &n1; n4Neighbors[1] = &n3;

    struct Node *copy = cloneGraph(&n1);
    struct Node *copy1 = findNode(copy, 1);
    struct Node *copy2 = findNode(copy, 2);
    struct Node *copy3 = findNode(copy, 3);
    struct Node *copy4 = findNode(copy, 4);
    int passed = copy != NULL && copy != &n1 && copy1 != &n1 &&
                 copy2 != NULL && copy3 != NULL && copy4 != NULL &&
                 copy1->numNeighbors == 2 && copy1->neighbors[0] == copy2 &&
                 copy1->neighbors[1] == copy4 &&
                 copy2->neighbors[0] == copy1 && copy2->neighbors[1] == copy3 &&
                 copy3->neighbors[0] == copy2 && copy3->neighbors[1] == copy4 &&
                 copy4->neighbors[0] == copy1 && copy4->neighbors[1] == copy3;
    freeGraph(copy);

    struct Node isolated = {1, 0, NULL};
    struct Node *singleCopy = cloneGraph(&isolated);
    passed = passed && singleCopy != NULL && singleCopy != &isolated &&
             singleCopy->val == 1 && singleCopy->numNeighbors == 0;
    freeGraph(singleCopy);
    passed = passed && cloneGraph(NULL) == NULL;

    puts(passed ? "PASS: 133 clone-graph" : "FAIL: 133 clone-graph");
    return passed ? 0 : 1;
}

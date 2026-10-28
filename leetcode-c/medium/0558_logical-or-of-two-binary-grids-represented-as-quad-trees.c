/*
 * Title-CN: 以四叉樹表示的兩個二元網格邏輯或
 * LeetCode 558. Logical OR of Two Binary Grids Represented as Quad-Trees
 *
 * 題意翻譯：給定兩棵四叉樹，各自代表一個由 0/1 組成的正方形網格，
 * 回傳代表兩個網格逐格做 OR（只要其中一格為 1，結果就是 1）的四叉樹。
 * 如果一個區域的結果全部相同，應合併成單一葉節點。
 *
 * 範例：一棵樹的根是值為 1 的葉節點，與任何網格做 OR 後，結果都是值為 1 的葉節點。
 *
 * 限制：兩個網格大小相同，邊長為 2 的冪且不超過 512；每個節點依四叉樹格式給定。
 *
 * 解題思路：若任一目前區域是值為 1 的葉節點，結果整區都是 1；若一邊是值為 0
 * 的葉節點，結果直接等於另一棵子樹的複製。否則四個象限分別遞迴做 OR。
 * 若四個結果都是相同值的葉節點，就把它們合併成一個葉節點，保持樹精簡。
 *
 * 複雜度：時間 O(n)，n 為輸入四叉樹節點數；遞迴與結果空間 O(n)。
 * LeetCode 介面：保留 intersect；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node {
    bool val;
    bool isLeaf;
    struct Node *topLeft;
    struct Node *topRight;
    struct Node *bottomLeft;
    struct Node *bottomRight;
};

static struct Node *newNode(bool value, bool isLeaf) {
    struct Node *node = malloc(sizeof(*node));
    if (node == NULL) return NULL;
    node->val = value;
    node->isLeaf = isLeaf;
    node->topLeft = node->topRight = NULL;
    node->bottomLeft = node->bottomRight = NULL;
    return node;
}

static void freeTree(struct Node *node) {
    if (node == NULL) return;
    freeTree(node->topLeft);
    freeTree(node->topRight);
    freeTree(node->bottomLeft);
    freeTree(node->bottomRight);
    free(node);
}

static struct Node *cloneTree(const struct Node *node) {
    if (node == NULL) return NULL;
    struct Node *copy = newNode(node->val, node->isLeaf);
    if (copy == NULL || node->isLeaf) return copy;
    copy->topLeft = cloneTree(node->topLeft);
    copy->topRight = cloneTree(node->topRight);
    copy->bottomLeft = cloneTree(node->bottomLeft);
    copy->bottomRight = cloneTree(node->bottomRight);
    if (copy->topLeft == NULL || copy->topRight == NULL
        || copy->bottomLeft == NULL || copy->bottomRight == NULL) {
        freeTree(copy);
        return NULL;
    }
    return copy;
}

struct Node *intersect(struct Node *quadTree1, struct Node *quadTree2) {
    if (quadTree1->isLeaf && quadTree1->val) return newNode(true, true);
    if (quadTree2->isLeaf && quadTree2->val) return newNode(true, true);
    if (quadTree1->isLeaf) return cloneTree(quadTree2);
    if (quadTree2->isLeaf) return cloneTree(quadTree1);

    struct Node *result = newNode(false, false);
    if (result == NULL) return NULL;
    result->topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
    result->topRight = intersect(quadTree1->topRight, quadTree2->topRight);
    result->bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
    result->bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
    if (result->topLeft == NULL || result->topRight == NULL
        || result->bottomLeft == NULL || result->bottomRight == NULL) {
        freeTree(result);
        return NULL;
    }

    struct Node *children[] = {result->topLeft, result->topRight,
                               result->bottomLeft, result->bottomRight};
    bool canMerge = true;
    bool value = children[0]->val;
    for (int i = 0; i < 4; ++i) {
        if (!children[i]->isLeaf || children[i]->val != value) canMerge = false;
    }
    if (canMerge) {
        freeTree(result->topLeft);
        freeTree(result->topRight);
        freeTree(result->bottomLeft);
        freeTree(result->bottomRight);
        result->topLeft = result->topRight = NULL;
        result->bottomLeft = result->bottomRight = NULL;
        result->val = value;
        result->isLeaf = true;
    }
    return result;
}

static struct Node *leaf(bool value) {
    return newNode(value, true);
}

int main(void) {
    struct Node *one = leaf(true);
    struct Node *zero = leaf(false);
    struct Node *result = intersect(one, zero);
    assert(result != NULL && result->isLeaf && result->val);
    freeTree(result);

    struct Node *a = newNode(false, false);
    struct Node *b = newNode(false, false);
    assert(a != NULL && b != NULL);
    a->topLeft = leaf(true);
    a->topRight = leaf(false);
    a->bottomLeft = leaf(false);
    a->bottomRight = leaf(true);
    b->topLeft = leaf(false);
    b->topRight = leaf(true);
    b->bottomLeft = leaf(true);
    b->bottomRight = leaf(true);
    result = intersect(a, b);
    assert(result != NULL && result->isLeaf && result->val);
    freeTree(result);
    freeTree(a);
    freeTree(b);
    freeTree(one);
    freeTree(zero);
    return 0;
}

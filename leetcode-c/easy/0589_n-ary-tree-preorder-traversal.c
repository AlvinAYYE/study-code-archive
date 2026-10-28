/*
 * LeetCode 0589. N-ary Tree Preorder Traversal《N 叉樹的前序走訪》
 * 難度：Easy；標籤：堆疊、樹、深度優先搜尋
 * 題目連結：https://leetcode.com/problems/n-ary-tree-preorder-traversal/
 *
 * 題目說明：
 * 給定 N 叉樹根節點，依前序順序回傳所有節點值。前序是先記錄目前節點，
 * 再由左到右依序走訪它的每個子樹。空樹回傳空陣列。輸入以層序表示，null
 * 用來分隔不同節點的子節點群組。
 *
 * 範例：
 * 1. root = [1,null,3,2,4,null,5,6]，回傳 [1,3,5,6,2,4]。
 * 2. root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,
 *    12,null,13,null,null,14]，回傳 [1,2,3,6,7,11,14,4,8,12,5,9,13,10]。
 *
 * 限制：節點數介於 0 到 10^4；0 <= Node.val <= 10^4；樹高不超過 1000。
 *
 * 解題思路：
 * 1. 用堆疊模擬深度優先的前序走訪。先將根節點放入堆疊。
 * 2. 每次取出一個節點，先將它的值寫入結果。
 * 3. 子節點要由左到右被取出；因為堆疊是後進先出，所以將子節點由右到左
 *    推入堆疊。這樣最左邊的子節點會先被處理。
 * 4. 堆疊清空時，結果陣列就是前序走訪順序。回傳陣列由 malloc 配置，呼叫端
 *    負責釋放。
 *
 * 複雜度：時間 O(n)；結果陣列 O(n)，堆疊最壞額外使用 O(n) 空間。
 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* LeetCode 提供的 N 叉樹節點定義。 */
struct Node {
    int val;
    int numChildren;
    struct Node** children;
};

int* preorder(struct Node* root, int* returnSize) {
    int *result = (int*)malloc(sizeof(int) * 10000);
    struct Node **stack = (struct Node**)malloc(sizeof(struct Node*) * 10000);
    int top = 0;
    int count = 0;

    if (!root) {
        *returnSize = 0;
        free(stack);
        return result;
    }

    stack[top++] = root;
    while (top > 0) {
        struct Node *node = stack[--top];
        int i;

        result[count++] = node->val;
        /* 反向入堆疊，取出時便會照原本的左到右順序走訪。 */
        for (i = node->numChildren - 1; i >= 0; --i) {
            if (node->children[i]) stack[top++] = node->children[i];
        }
    }

    free(stack);
    *returnSize = count;
    return result;
}

static void initNode(struct Node *node, int value) {
    node->val = value;
    node->numChildren = 0;
    node->children = NULL;
}

static void setChildren(struct Node *node, struct Node **children, int count) {
    node->numChildren = count;
    node->children = children;
}

static void checkTraversal(struct Node *root, const int *expected, int expectedSize) {
    int size = -1;
    int *actual = preorder(root, &size);
    int i;

    assert(size == expectedSize);
    for (i = 0; i < size; ++i) assert(actual[i] == expected[i]);
    free(actual);
}

int main(void) {
    struct Node a[14];
    struct Node *aRootChildren[] = {&a[2], &a[1], &a[3]};
    struct Node *aThreeChildren[] = {&a[4], &a[5]};
    struct Node *bRootChildren[] = {&a[1], &a[2], &a[3], &a[4]};
    struct Node *bThreeChildren[] = {&a[5], &a[6]};
    struct Node *bFourChildren[] = {&a[7]};
    struct Node *bFiveChildren[] = {&a[8], &a[9]};
    struct Node *bSevenChildren[] = {&a[10]};
    struct Node *bEightChildren[] = {&a[11]};
    struct Node *bNineChildren[] = {&a[12]};
    struct Node *bElevenChildren[] = {&a[13]};
    const int expectedA[] = {1, 3, 5, 6, 2, 4};
    const int expectedB[] = {1, 2, 3, 6, 7, 11, 14, 4, 8, 12, 5, 9, 13, 10};
    int i;

    for (i = 0; i < 14; ++i) initNode(&a[i], i + 1);

    /* 範例一。 */
    setChildren(&a[0], aRootChildren, 3);
    setChildren(&a[2], aThreeChildren, 2);
    checkTraversal(&a[0], expectedA, 6);

    /* 範例二。 */
    for (i = 0; i < 14; ++i) setChildren(&a[i], NULL, 0);
    setChildren(&a[0], bRootChildren, 4);
    setChildren(&a[2], bThreeChildren, 2);
    setChildren(&a[3], bFourChildren, 1);
    setChildren(&a[4], bFiveChildren, 2);
    setChildren(&a[6], bSevenChildren, 1);
    setChildren(&a[7], bEightChildren, 1);
    setChildren(&a[8], bNineChildren, 1);
    setChildren(&a[10], bElevenChildren, 1);
    checkTraversal(&a[0], expectedB, 14);
    checkTraversal(NULL, NULL, 0);

    puts("PASS 0589 preorder");
    return 0;
}

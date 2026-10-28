/*
 * LeetCode 0559. Maximum Depth of N-ary Tree《N 叉樹的最大深度》
 * 難度：Easy；標籤：樹、深度優先搜尋、廣度優先搜尋
 * 題目連結：https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
 *
 * 題目說明：
 * 給定一棵 N 叉樹，回傳從根節點到最遠葉節點的最長路徑所包含的節點數。
 * N 叉樹的節點可以有任意多個子節點；沒有子節點的節點就是葉節點。
 * 空樹的深度為 0。題目輸入以層序方式表示，null 用來分隔各節點的子節點群組。
 *
 * 範例：
 * 1. root = [1,null,3,2,4,null,5,6]，回傳 3。
 *    根節點 1 有子節點 3、2、4；節點 3 又有子節點 5、6，最長路徑含 3 個節點。
 * 2. root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,
 *    12,null,13,null,null,14]，回傳 5。
 *
 * 限制：節點總數介於 0 到 10^4；樹的深度不超過 1000。
 *
 * 解題思路：
 * 1. 空節點的深度是 0。
 * 2. 遞迴求出每個子節點的最大深度。
 * 3. 目前節點的深度等於最深子樹深度加 1；若沒有子節點，子樹深度就是 0。
 *
 * 複雜度：每個節點走訪一次，時間 O(n)；遞迴堆疊額外使用 O(h)，h 為樹高。
 */
#include <assert.h>
#include <stdio.h>

/* LeetCode 提供的 N 叉樹節點定義。 */
struct Node {
    int val;
    int numChildren;
    struct Node** children;
};

int maxDepth(struct Node* root) {
    int deepestChild = 0;
    int i;

    if (!root) return 0;
    for (i = 0; i < root->numChildren; ++i) {
        int childDepth = maxDepth(root->children[i]);
        if (childDepth > deepestChild) deepestChild = childDepth;
    }
    return deepestChild + 1;
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
    int i;

    for (i = 0; i < 14; ++i) initNode(&a[i], i + 1);

    /* 範例一：[1,null,3,2,4,null,5,6]。 */
    setChildren(&a[0], aRootChildren, 3);
    setChildren(&a[2], aThreeChildren, 2);
    assert(maxDepth(&a[0]) == 3);

    /* 範例二的最深路徑為 1 -> 3 -> 7 -> 11 -> 14。 */
    for (i = 0; i < 14; ++i) setChildren(&a[i], NULL, 0);
    setChildren(&a[0], bRootChildren, 4);
    setChildren(&a[2], bThreeChildren, 2);
    setChildren(&a[3], bFourChildren, 1);
    setChildren(&a[4], bFiveChildren, 2);
    setChildren(&a[6], bSevenChildren, 1);
    setChildren(&a[7], bEightChildren, 1);
    setChildren(&a[8], bNineChildren, 1);
    setChildren(&a[10], bElevenChildren, 1);
    assert(maxDepth(&a[0]) == 5);
    assert(maxDepth(NULL) == 0);

    puts("PASS 0559 maxDepth");
    return 0;
}

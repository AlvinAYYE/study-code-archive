/*
 * Title-CN: 二元樹的最近共同祖先
 * LeetCode 236. Lowest Common Ancestor of a Binary Tree
 *
 * 題目翻譯：給定一棵二元樹，以及樹中兩個不同節點 p、q，找出同時是
 * p 和 q 祖先的節點中，位置最低（離它們最近）的那一個。節點可以是自己的祖先。
 *
 * 例子：
 *   root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1，答案是 3。
 *   p = 5, q = 4，答案是 5，因為節點也算自己的祖先。
 *
 * 限制：樹有 2 到 100000 個節點，節點值不重複；p、q 都確定存在於樹中。
 *
 * 解題步驟：
 *   1. 從目前節點往左右子樹找 p 和 q。
 *   2. 若目前節點就是 p 或 q，直接回傳它；上層呼叫便知道這邊找到了目標。
 *   3. 若左右子樹各找到一個目標，目前節點就是兩者第一次會合的地方，也就是最近共同祖先。
 *   4. 若只有一邊找到目標，就把那一邊的結果往上回傳。
 *
 * 複雜度：每個節點最多走訪一次，時間 O(n)；遞迴呼叫堆疊最多 O(h)，h 是樹高。
 *
 * LeetCode 提交區：保留 TreeNode 定義與 lowestCommonAncestor 函式；main() 僅供本機測試。
 */

#include <assert.h>
#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *lowestCommonAncestor(struct TreeNode *root,
                                      struct TreeNode *p,
                                      struct TreeNode *q) {
    if (root == NULL || root == p || root == q) {
        return root;
    }

    struct TreeNode *left_result = lowestCommonAncestor(root->left, p, q);
    struct TreeNode *right_result = lowestCommonAncestor(root->right, p, q);

    if (left_result != NULL && right_result != NULL) {
        return root;
    }
    return left_result != NULL ? left_result : right_result;
}

int main(void) {
    struct TreeNode nodes[9] = {0};
    const int values[] = {3, 5, 1, 6, 2, 0, 8, 7, 4};
    for (int i = 0; i < 9; ++i) {
        nodes[i].val = values[i];
    }

    nodes[0].left = &nodes[1];
    nodes[0].right = &nodes[2];
    nodes[1].left = &nodes[3];
    nodes[1].right = &nodes[4];
    nodes[2].left = &nodes[5];
    nodes[2].right = &nodes[6];
    nodes[4].left = &nodes[7];
    nodes[4].right = &nodes[8];

    assert(lowestCommonAncestor(&nodes[0], &nodes[1], &nodes[2]) == &nodes[0]);
    assert(lowestCommonAncestor(&nodes[0], &nodes[1], &nodes[8]) == &nodes[1]);
    assert(lowestCommonAncestor(&nodes[0], &nodes[7], &nodes[8]) == &nodes[4]);
    return 0;
}

/*
 * LeetCode 105. Construct Binary Tree from Preorder and Inorder Traversal
 * 繁中題名：從前序與中序走訪序列建立二元樹
 * 題目：給定同一棵二元樹的前序與中序走訪結果，重建並回傳該樹。
 *
 * 範例 1：preorder=[3,9,20,15,7]，inorder=[9,3,15,20,7]
 *         建立出的樹以層序表示為 [3,9,20,null,null,15,7]。
 * 範例 2：preorder=[-1]，inorder=[-1]，回傳只有根節點 -1 的樹。
 * 限制：1 <= 節點數 <= 3000；節點值介於 -3000 到 3000；值互不相同；
 *       兩個陣列確實是同一棵樹的前序與中序走訪。
 *
 * 解題步驟：
 *   1. 前序走訪的第一個值一定是目前子樹的根。
 *   2. 在中序走訪找到根的位置；左側就是左子樹，右側就是右子樹。
 *   3. 依照左、右子樹在中序中的長度，遞迴重建兩側。
 *   4. 用值到中序索引的表格快速找根的位置，避免每層重新線性搜尋。
 *   每個節點處理一次，時間 O(n)；索引表與遞迴堆疊共 O(n) 空間。
 *
 * LeetCode 提供 TreeNode 型別；此檔案中的定義與 main 僅供本機測試。
 */
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define VALUE_OFFSET 3000
#define VALUE_RANGE 6001

static struct TreeNode *buildPreorderRange(const int *preorder,
                                           int *preorderIndex,
                                           int inorderLeft,
                                           int inorderRight,
                                           const int *inorderPosition) {
    struct TreeNode *root;
    int rootValue, rootIndex;

    if (inorderLeft > inorderRight) return NULL;

    /* 前序序列依序給出根、左子樹、右子樹。 */
    rootValue = preorder[(*preorderIndex)++];
    rootIndex = inorderPosition[rootValue + VALUE_OFFSET];

    root = (struct TreeNode *)malloc(sizeof *root);
    if (root == NULL) return NULL;
    root->val = rootValue;

    /* 中序序列中，根左邊的值全屬左子樹，右邊的值全屬右子樹。 */
    root->left = buildPreorderRange(preorder, preorderIndex,
                                    inorderLeft, rootIndex - 1,
                                    inorderPosition);
    root->right = buildPreorderRange(preorder, preorderIndex,
                                     rootIndex + 1, inorderRight,
                                     inorderPosition);
    return root;
}

/* ---------- LeetCode submission / 提交區 ---------- */
struct TreeNode *buildTree(int *preorder, int preorderSize,
                           int *inorder, int inorderSize) {
    int inorderPosition[VALUE_RANGE];
    int preorderIndex = 0;

    if (preorder == NULL || inorder == NULL || preorderSize == 0 ||
        preorderSize != inorderSize) {
        return NULL;
    }

    for (int i = 0; i < VALUE_RANGE; ++i) inorderPosition[i] = -1;
    for (int i = 0; i < inorderSize; ++i) {
        inorderPosition[inorder[i] + VALUE_OFFSET] = i;
    }

    return buildPreorderRange(preorder, &preorderIndex, 0, inorderSize - 1,
                              inorderPosition);
}
/* ---------- end submission ---------- */

static void collectPreorder(const struct TreeNode *root, int *values, int *size) {
    if (root == NULL) return;
    values[(*size)++] = root->val;
    collectPreorder(root->left, values, size);
    collectPreorder(root->right, values, size);
}

static void collectInorder(const struct TreeNode *root, int *values, int *size) {
    if (root == NULL) return;
    collectInorder(root->left, values, size);
    values[(*size)++] = root->val;
    collectInorder(root->right, values, size);
}

static void freeTree(struct TreeNode *root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

static int arraysEqual(const int *a, const int *b, int size) {
    for (int i = 0; i < size; ++i) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

static int checkExample(const int *preorder, const int *inorder, int size) {
    struct TreeNode *root = buildTree((int *)preorder, size,
                                      (int *)inorder, size);
    int actualPreorder[3000], actualInorder[3000];
    int preorderCount = 0, inorderCount = 0;
    int passed;

    collectPreorder(root, actualPreorder, &preorderCount);
    collectInorder(root, actualInorder, &inorderCount);
    passed = preorderCount == size && inorderCount == size &&
             arraysEqual(actualPreorder, preorder, size) &&
             arraysEqual(actualInorder, inorder, size);
    freeTree(root);
    return passed;
}

int main(void) {
    int preorder1[] = {3, 9, 20, 15, 7};
    int inorder1[] = {9, 3, 15, 20, 7};
    int preorder2[] = {-1};
    int inorder2[] = {-1};
    int preorder3[] = {1, 2, 3};
    int inorder3[] = {1, 2, 3};
    int passed = checkExample(preorder1, inorder1, 5) &&
                 checkExample(preorder2, inorder2, 1) &&
                 checkExample(preorder3, inorder3, 3);

    puts(passed ? "PASS: 105 construct-binary-tree-preorder-inorder"
                : "FAIL: 105 construct-binary-tree-preorder-inorder");
    return passed ? 0 : 1;
}

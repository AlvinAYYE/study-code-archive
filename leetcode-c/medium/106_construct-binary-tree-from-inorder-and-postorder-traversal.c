/*
 * LeetCode 106. Construct Binary Tree from Inorder and Postorder Traversal
 * 繁中題名：從中序與後序走訪序列建立二元樹
 * 題目：給定同一棵二元樹的中序與後序走訪結果，重建並回傳該樹。
 *
 * 範例 1：inorder=[9,3,15,20,7]，postorder=[9,15,7,20,3]
 *         建立出的樹以層序表示為 [3,9,20,null,null,15,7]。
 * 範例 2：inorder=[-1]，postorder=[-1]，回傳只有根節點 -1 的樹。
 * 限制：1 <= 節點數 <= 3000；節點值介於 -3000 到 3000；值互不相同；
 *       兩個陣列確實是同一棵樹的中序與後序走訪。
 *
 * 解題步驟：
 *   1. 後序走訪的最後一個值一定是目前子樹的根。
 *   2. 在中序走訪找到根的位置；左側是左子樹，右側是右子樹。
 *   3. 倒著讀後序時，根之後先遇到右子樹，所以必須先遞迴建立右子樹，
 *      再建立左子樹。
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

static struct TreeNode *buildPostorderRange(const int *postorder,
                                            int *postorderIndex,
                                            int inorderLeft,
                                            int inorderRight,
                                            const int *inorderPosition) {
    struct TreeNode *root;
    int rootValue, rootIndex;

    if (inorderLeft > inorderRight) return NULL;

    /* 從後往前讀後序序列，先讀到根，再讀右子樹、左子樹。 */
    rootValue = postorder[(*postorderIndex)--];
    rootIndex = inorderPosition[rootValue + VALUE_OFFSET];

    root = (struct TreeNode *)malloc(sizeof *root);
    if (root == NULL) return NULL;
    root->val = rootValue;

    /* 反向讀取時，先建立右子樹，才能與後序順序一致。 */
    root->right = buildPostorderRange(postorder, postorderIndex,
                                      rootIndex + 1, inorderRight,
                                      inorderPosition);
    root->left = buildPostorderRange(postorder, postorderIndex,
                                     inorderLeft, rootIndex - 1,
                                     inorderPosition);
    return root;
}

/* ---------- LeetCode submission / 提交區 ---------- */
struct TreeNode *buildTree(int *inorder, int inorderSize,
                           int *postorder, int postorderSize) {
    int inorderPosition[VALUE_RANGE];
    int postorderIndex = postorderSize - 1;

    if (inorder == NULL || postorder == NULL || inorderSize == 0 ||
        inorderSize != postorderSize) {
        return NULL;
    }

    for (int i = 0; i < VALUE_RANGE; ++i) inorderPosition[i] = -1;
    for (int i = 0; i < inorderSize; ++i) {
        inorderPosition[inorder[i] + VALUE_OFFSET] = i;
    }

    return buildPostorderRange(postorder, &postorderIndex, 0, inorderSize - 1,
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

static void collectPostorder(const struct TreeNode *root, int *values, int *size) {
    if (root == NULL) return;
    collectPostorder(root->left, values, size);
    collectPostorder(root->right, values, size);
    values[(*size)++] = root->val;
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

static int checkExample(const int *inorder, const int *postorder, int size) {
    struct TreeNode *root = buildTree((int *)inorder, size,
                                      (int *)postorder, size);
    int actualInorder[3000], actualPostorder[3000];
    int inorderCount = 0, postorderCount = 0;
    int passed;

    collectInorder(root, actualInorder, &inorderCount);
    collectPostorder(root, actualPostorder, &postorderCount);
    passed = inorderCount == size && postorderCount == size &&
             arraysEqual(actualInorder, inorder, size) &&
             arraysEqual(actualPostorder, postorder, size);
    freeTree(root);
    return passed;
}

int main(void) {
    int inorder1[] = {9, 3, 15, 20, 7};
    int postorder1[] = {9, 15, 7, 20, 3};
    int inorder2[] = {-1};
    int postorder2[] = {-1};
    int inorder3[] = {1, 2, 3};
    int postorder3[] = {3, 2, 1};
    int passed = checkExample(inorder1, postorder1, 5) &&
                 checkExample(inorder2, postorder2, 1) &&
                 checkExample(inorder3, postorder3, 3);

    puts(passed ? "PASS: 106 construct-binary-tree-inorder-postorder"
                : "FAIL: 106 construct-binary-tree-inorder-postorder");
    return passed ? 0 : 1;
}

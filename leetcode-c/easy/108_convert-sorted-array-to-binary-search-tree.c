/*
 * LeetCode 108. Convert Sorted Array to Binary Search Tree／有序陣列轉平衡搜尋樹
 * 題目（繁體中文）
 *   給定嚴格遞增的整數陣列，建立一棵高度平衡的二元搜尋樹並回傳根節點。
 *   搜尋樹的左子樹都比根小、右子樹都比根大；高度平衡表示每個節點的
 *   左右子樹高度差不超過 1。陣列長度 1～10000，數值範圍 -10000～10000。
 *
 * 例子
 *   [-10,-3,0,5,9] → 可選 0 為根，[-10,-3] 建左樹，[5,9] 建右樹。
 *   [1,3] → 根可為 1 或 3，只要仍是平衡搜尋樹即可。
 *
 * 解題思路
 *   1. 已排序的中間元素當根，兩側元素數量最接近。
 *   2. 左半段遞迴建左子樹，右半段遞迴建右子樹。
 *   3. 每個元素只建立一個節點，所以時間 O(n)；遞迴深度 O(log n)。
 *      新樹本身需 O(n) 空間，由呼叫者釋放。
 *
 * LeetCode 已提供 TreeNode 定義；提交時只複製 stdlib.h 與提交區。
 */
#include <stdio.h>
#include <stdlib.h>

struct TreeNode { int val; struct TreeNode *left; struct TreeNode *right; };

/* ---------- LeetCode submission / 提交區 ---------- */
static struct TreeNode *buildTree(int *nums, int left, int right) {
    if (left > right) return NULL;

    int middle = left + (right - left) / 2;
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof *root);
    if (root == NULL) return NULL;
    root->val = nums[middle];
    root->left = buildTree(nums, left, middle - 1);
    root->right = buildTree(nums, middle + 1, right);
    return root;
}

struct TreeNode *sortedArrayToBST(int *nums, int numsSize) {
    return buildTree(nums, 0, numsSize - 1);
}
/* ---------- end submission ---------- */

static int checkTree(struct TreeNode *root, int *nums, int *index) {
    if (root == NULL) return 0;
    int leftHeight = checkTree(root->left, nums, index);
    if (leftHeight < 0 || root->val != nums[(*index)++]) return -1;
    int rightHeight = checkTree(root->right, nums, index);
    if (rightHeight < 0 || abs(leftHeight - rightHeight) > 1) return -1;
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

static void freeTree(struct TreeNode *root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(void) {
    int nums[] = {-10, -3, 0, 5, 9};
    int index = 0;
    struct TreeNode *root = sortedArrayToBST(nums, 5);
    int height = checkTree(root, nums, &index);
    freeTree(root);
    if (height < 0 || index != 5) {
        puts("FAIL: 108 sorted-array-to-bst");
        return 1;
    }
    puts("PASS: 108 sorted-array-to-bst");
    return 0;
}

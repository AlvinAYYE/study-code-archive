/*
 * LeetCode 109. Convert Sorted List to Binary Search Tree
 * 繁中題名：將排序連結串列轉換成二元搜尋樹
 * 題目：給定一條由小到大排序的單向連結串列，將它轉成高度平衡的二元搜尋樹。
 *
 * 範例 1：head=[-10,-3,0,5,9]，其中一種答案是 [0,-3,9,-10,null,5]。
 * 範例 2：head=[]，輸出 []。
 * 限制：節點數介於 0 到 2 * 10^4；-10^5 <= Node.val <= 10^5。
 *
 * 解題步驟：
 *   1. 先把串列值依序複製到陣列，陣列仍是由小到大排列。
 *   2. 每次取目前區間的中間值作為子樹根，左半部遞迴建立左子樹，右半部建立右子樹。
 *   3. 區間不含元素時回傳空指標。
 *   因為每次都從中間切開，左右子樹高度差最多為 1。
 *   時間 O(n)，額外空間 O(n)（值陣列與遞迴堆疊，另有輸出樹）。
 *
 * LeetCode 提供 ListNode、TreeNode 型別；此檔案中的定義與 main 僅供本機測試。
 */
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static struct TreeNode *buildFromSortedValues(const int *values,
                                               int left, int right) {
    int middle;
    struct TreeNode *root;

    if (left > right) return NULL;

    middle = left + (right - left) / 2;
    root = (struct TreeNode *)malloc(sizeof *root);
    if (root == NULL) return NULL;

    root->val = values[middle];
    /* 中間值分別把較小與較大的區間留給左右子樹。 */
    root->left = buildFromSortedValues(values, left, middle - 1);
    root->right = buildFromSortedValues(values, middle + 1, right);
    return root;
}

/* ---------- LeetCode submission / 提交區 ---------- */
struct TreeNode *sortedListToBST(struct ListNode *head) {
    int size = 0, index = 0;
    struct ListNode *current;
    int *values;
    struct TreeNode *root;

    for (current = head; current != NULL; current = current->next) ++size;
    if (size == 0) return NULL;

    values = (int *)malloc((size_t)size * sizeof *values);
    if (values == NULL) return NULL;
    for (current = head; current != NULL; current = current->next) {
        values[index++] = current->val;
    }

    root = buildFromSortedValues(values, 0, size - 1);
    free(values);
    return root;
}
/* ---------- end submission ---------- */

static struct ListNode *makeList(const int *values, int size) {
    struct ListNode *head = NULL, *tail = NULL;
    for (int i = 0; i < size; ++i) {
        struct ListNode *node = (struct ListNode *)malloc(sizeof *node);
        if (node == NULL) return head;
        node->val = values[i];
        node->next = NULL;
        if (tail == NULL) head = node;
        else tail->next = node;
        tail = node;
    }
    return head;
}

static void freeList(struct ListNode *head) {
    while (head != NULL) {
        struct ListNode *next = head->next;
        free(head);
        head = next;
    }
}

static void freeTree(struct TreeNode *root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

static void collectInorder(const struct TreeNode *root, int *values, int *size) {
    if (root == NULL) return;
    collectInorder(root->left, values, size);
    values[(*size)++] = root->val;
    collectInorder(root->right, values, size);
}

/* 回傳子樹高度；若左右高度差超過 1，回傳 -1 表示不平衡。 */
static int balancedHeight(const struct TreeNode *root) {
    int leftHeight, rightHeight;
    if (root == NULL) return 0;
    leftHeight = balancedHeight(root->left);
    if (leftHeight < 0) return -1;
    rightHeight = balancedHeight(root->right);
    if (rightHeight < 0 || abs(leftHeight - rightHeight) > 1) return -1;
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

static int checkCase(const int *values, int size) {
    struct ListNode *list = makeList(values, size);
    struct TreeNode *tree = sortedListToBST(list);
    int actual[16], actualSize = 0, passed;

    collectInorder(tree, actual, &actualSize);
    passed = actualSize == size && balancedHeight(tree) >= 0;
    for (int i = 0; passed && i < size; ++i) {
        if (actual[i] != values[i]) passed = 0;
    }
    freeTree(tree);
    freeList(list);
    return passed;
}

int main(void) {
    int example1[] = {-10, -3, 0, 5, 9};
    int example2[] = {0};
    int passed = checkCase(example1, 5) && checkCase(NULL, 0) &&
                 checkCase(example2, 1);

    puts(passed ? "PASS: 109 convert-sorted-list-to-bst"
                : "FAIL: 109 convert-sorted-list-to-bst");
    return passed ? 0 : 1;
}

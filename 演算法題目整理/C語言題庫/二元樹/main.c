/*
 * 【初學者詳細導讀】
 * 【這題要做什麼】把輸入值建成二元搜尋樹，依使用者選擇輸出前序、中序或後序走訪。
 * 【輸入】n、n 個整數、走訪編號 1 前序／2 中序／3
 * 後序。【輸出】依走訪順序排列的值。 【閱讀順序】插入規則是較小值往左，其他值往右。walk
 * 遞迴走訪節點：前序先印根；中序先走左再印根；後序先走左右最後印根。mode 控制根值在哪個時機印出。
 * 【C 語法】Node 結構包含值 x 與左右指標 l、r；Node **p 可以改變 root
 * 或某個子節點欄位；calloc 建立節點並把指標初始化為 NULL。
 *
 * 【共通讀法】程式從 main 開始執行。scanf 依格式讀入資料，printf 將答案印到螢幕；for/while
 * 重複執行大括號中的步驟。C 陣列索引從 0 開始。遇到函式時，可把它當成一段有名字、可重複使用的工作。
 */
/* 輸入 n、n 個值插入 BST，再輸入 1 前序／2 中序／3 後序，輸出走訪序列。 */
#include <stdio.h>
#include <stdlib.h>
typedef struct BinaryTreeNode {
    int value;
    struct BinaryTreeNode *left_child, *right_child;
} BinaryTreeNode;
void traverse_tree(BinaryTreeNode *child_link, int mode) {
    if (!child_link)
        return;
    if (mode == 1)
        printf("%d ", child_link->value);
    traverse_tree(child_link->left_child, mode);
    if (mode == 2)
        printf("%d ", child_link->value);
    traverse_tree(child_link->right_child, mode);
    if (mode == 3)
        printf("%d ", child_link->value);
}
int main(void) {
    /* 先讀取並檢查輸入；接著依導讀中的演算法處理資料，最後輸出結果。 */
    int node_count, value, traversal_mode;
    if (scanf("%d", &node_count) != 1 || node_count < 0)
        return 1;
    BinaryTreeNode *root = NULL;
    for (int index = 0; index < node_count; index++) {
        if (scanf("%d", &value) != 1)
            return 1;
        BinaryTreeNode **child_link = &root;
        while (*child_link)
            child_link = value < (*child_link)->value ? &(*child_link)->left_child
                                                      : &(*child_link)->right_child;
        *child_link = calloc(1, sizeof(BinaryTreeNode));
        if (!*child_link)
            return 1;
        (*child_link)->value = value;
    }
    if (scanf("%d", &traversal_mode) != 1 || traversal_mode < 1 || traversal_mode > 3)
        return 1;
    traverse_tree(root, traversal_mode);
    putchar('\n');
    return 0;
}

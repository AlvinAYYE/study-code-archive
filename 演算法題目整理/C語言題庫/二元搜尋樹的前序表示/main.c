/*
 * 【初學者詳細導讀】
 * 【這題要做什麼】把輸入數字依序插入二元搜尋樹，再用前序走訪輸出：根、左子樹、右子樹。
 * 【輸入】節點數 n，接著 n 個整數。【輸出】前序順序的節點值。
 * 【閱讀順序】Node 結構各保存一個值和左右子節點指標。插入時用 Node **p
 * 找到空的子節點欄位，再配置新節點。pre 函式先印目前節點，再遞迴處理左、右子樹。 【C
 * 語法】struct Node 定義一種節點資料；Node * 是節點指標；Node ** 是「指標的指標」，用來修改 root
 * 或子節點欄位；calloc 配置並清成 0，故新節點的左右指標會是 NULL。
 *
 * 【共通讀法】程式從 main 開始執行。scanf 依格式讀入資料，printf 將答案印到螢幕；for/while
 * 重複執行大括號中的步驟。C 陣列索引從 0 開始。遇到函式時，可把它當成一段有名字、可重複使用的工作。
 */
/* 輸入 n 及 n 個值，依序插入 BST，輸出前序走訪。 */
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int value;
    struct Node *left_child, *right_child;
} Node;
void print_preorder(Node *child_link) {
    if (child_link) {
        printf("%d ", child_link->value);
        print_preorder(child_link->left_child);
        print_preorder(child_link->right_child);
    }
}
int main(void) {
    /* 先讀取並檢查輸入；接著依導讀中的演算法處理資料，最後輸出結果。 */
    int node_count, value;
    if (scanf("%d", &node_count) != 1 || node_count < 0)
        return 1;
    Node *root = NULL;
    for (int index = 0; index < node_count; index++) {
        if (scanf("%d", &value) != 1)
            return 1;
        Node **child_link = &root;
        while (*child_link)
            child_link = value < (*child_link)->value ? &(*child_link)->left_child
                                                      : &(*child_link)->right_child;
        *child_link = calloc(1, sizeof(Node));
        if (!*child_link)
            return 1;
        (*child_link)->value = value;
    }
    print_preorder(root);
    putchar('\n');
    return 0;
}

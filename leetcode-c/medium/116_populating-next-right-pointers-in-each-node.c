/*
 * LeetCode 116. Populating Next Right Pointers in Each Node
 * 繁中題名：填充每個節點的下一個右側節點指標
 * 題目：給定一棵完美二元樹（每個內部節點都有左右子節點，所有葉節點同層），
 *       將每個節點的 next 指向同層右側相鄰節點；每層最右側的 next 為 NULL。
 *       初始時所有 next 都是 NULL。
 *
 * 範例：root=[1,2,3,4,5,6,7]，連結後各層為 1→NULL、2→3→NULL、
 *       4→5→6→7→NULL。空樹輸出 []。
 * 限制：節點數介於 0 到 2^12 - 1；-1000 <= Node.val <= 1000。
 *
 * 解題步驟：
 *   1. 從目前層最左側節點開始，父節點間已由 next 串成一列。
 *   2. 對每個父節點，先連接左孩子的 next 到右孩子。
 *   3. 若父節點右邊還有鄰居，再把右孩子接到鄰居的左孩子。
 *   4. 移到下一層最左側，重複直到葉節點層。
 *   不需佇列，時間 O(n)、額外空間 O(1)。
 *
 * LeetCode 提供 Node 型別；此檔案中的定義與 main 僅供本機測試。
 */
#include <stdio.h>

struct Node {
    int val;
    struct Node *left;
    struct Node *right;
    struct Node *next;
};

/* ---------- LeetCode submission / 提交區 ---------- */
struct Node *connect(struct Node *root) {
    struct Node *levelStart = root;
    if (root == NULL) return NULL;

    /* 根節點是第一層唯一節點，最後一個 next 必須為空。 */
    root->next = NULL;
    while (levelStart->left != NULL) {
        struct Node *current = levelStart;
        while (current != NULL) {
            current->left->next = current->right;
            current->right->next =
                (current->next != NULL) ? current->next->left : NULL;
            current = current->next;
        }
        levelStart = levelStart->left;
    }
    return root;
}
/* ---------- end submission ---------- */

int main(void) {
    struct Node n4 = {4, NULL, NULL, NULL};
    struct Node n5 = {5, NULL, NULL, NULL};
    struct Node n6 = {6, NULL, NULL, NULL};
    struct Node n7 = {7, NULL, NULL, NULL};
    struct Node n2 = {2, &n4, &n5, NULL};
    struct Node n3 = {3, &n6, &n7, NULL};
    struct Node root = {1, &n2, &n3, NULL};
    struct Node single = {9, NULL, NULL, NULL};
    struct Node *result = connect(&root);
    int passed = result == &root && root.next == NULL &&
                 n2.next == &n3 && n3.next == NULL &&
                 n4.next == &n5 && n5.next == &n6 &&
                 n6.next == &n7 && n7.next == NULL;

    result = connect(&single);
    passed = passed && result == &single && single.next == NULL;
    passed = passed && connect(NULL) == NULL;

    puts(passed ? "PASS: 116 populating-next-right-pointers"
                : "FAIL: 116 populating-next-right-pointers");
    return passed ? 0 : 1;
}

/*
 * LeetCode 117. Populating Next Right Pointers in Each Node II
 * Title-CN: 填充每個節點的下一個右側節點指標 II
 *
 * 題目翻譯：給定一棵二元樹，替每個節點設定 next，讓它指向同一層右邊緊鄰的節點；
 * 若右邊沒有節點，next 就設為 NULL。題目保證輸入時所有 next 都是 NULL。
 *
 * 範例：
 * 1. [1,2,3,4,5,null,7] 的 next 連線為 1->NULL、2->3->NULL、4->5->7->NULL。
 *    序列化結果：[1,#,2,3,#,4,5,7,#]，# 表示該層結束。
 * 2. [] -> []。
 *
 * 限制：節點數 0 到 6000；-100 <= Node.val <= 100。進階要求只使用 O(1) 額外空間。
 *
 * 解題思路：用已建立好的 next 指標逐層走訪，並用一個虛擬頭節點串起下一層。
 * 1. level 指向目前層的最左節點；dummy 與 tail 負責建立下一層的 next 鏈。
 * 2. 沿目前層的 next 由左到右檢查每個節點，依序把左子節點、右子節點接到 tail 後面。
 * 3. 一層處理完後，將最後一個子節點的 next 設為 NULL，再從 dummy.next 開始處理下一層。
 * 這樣不需要佇列；每個節點只被拜訪一次。
 *
 * 複雜度：時間 O(n)，額外空間 O(1)。
 *
 * LeetCode C API：struct Node *connect(struct Node *root)
 */
#include <stdio.h>

struct Node {
    int val;
    struct Node *left;
    struct Node *right;
    struct Node *next;
};

/* LeetCode 提交函式：逐層用 next 串接下一層，不另配置佇列。 */
struct Node *connect(struct Node *root) {
    struct Node *level = root;

    while (level != NULL) {
        struct Node dummy = {0, NULL, NULL, NULL};
        struct Node *tail = &dummy;

        for (struct Node *current = level; current != NULL; current = current->next) {
            if (current->left != NULL) {
                tail->next = current->left;
                tail = tail->next;
            }
            if (current->right != NULL) {
                tail->next = current->right;
                tail = tail->next;
            }
        }

        /* 最後一個節點必須明確收尾，確保每層最後的 next 都是 NULL。 */
        tail->next = NULL;
        level = dummy.next;
    }

    return root;
}

static int exampleTreeIsConnected(void) {
    struct Node n4 = {4, NULL, NULL, NULL};
    struct Node n5 = {5, NULL, NULL, NULL};
    struct Node n7 = {7, NULL, NULL, NULL};
    struct Node n2 = {2, &n4, &n5, NULL};
    struct Node n3 = {3, NULL, &n7, NULL};
    struct Node root = {1, &n2, &n3, NULL};

    connect(&root);
    return root.next == NULL &&
           n2.next == &n3 && n3.next == NULL &&
           n4.next == &n5 && n5.next == &n7 && n7.next == NULL;
}

int main(void) {
    int passed = exampleTreeIsConnected();
    passed = passed && connect(NULL) == NULL;

    struct Node only = {42, NULL, NULL, NULL};
    passed = passed && connect(&only) == &only && only.next == NULL;

    puts(passed ? "PASS: 117 populating-next-right-pointers-in-each-node-ii"
                : "FAIL: 117 populating-next-right-pointers-in-each-node-ii");
    return passed ? 0 : 1;
}

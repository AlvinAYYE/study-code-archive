/*
 * LeetCode 199. Binary Tree Right Side View
 * Title-CN: 二元樹的右側視圖
 *
 * 題意：想像自己站在二元樹最右邊，從上到下回傳每一層最右側看得到的節點值。
 *
 * 範例：
 * 1. [1,2,3,null,5,null,4] -> [1,3,4]。
 * 2. [1,2,3,4,null,null,null,5] -> [1,3,4,5]。
 * 3. [1,null,3] -> [1,3]；空樹 -> []。
 *
 * 限制：節點數 0 到 100；-100 <= Node.val <= 100。
 *
 * 解題思路：用佇列做廣度優先搜尋。每次先記下佇列裡目前這一層有幾個節點；
 * 依左到右順序取出，該層最後取出的節點就是從右側看到的節點。
 *
 * 複雜度：時間 O(n)，佇列 O(n)，回傳陣列 O(h)，其中 h 是樹的高度。
 */
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/* LeetCode 提交函式：節點數上限為 100，因此佇列容量已足夠。 */
int *rightSideView(struct TreeNode *root, int *returnSize) {
    *returnSize = 0;
    if (root == NULL) return NULL;

    int *answer = (int *)malloc(100 * sizeof *answer);
    if (answer == NULL) return NULL;

    struct TreeNode *queue[100];
    int head = 0;
    int tail = 0;
    queue[tail++] = root;

    while (head < tail) {
        int levelSize = tail - head;
        for (int i = 0; i < levelSize; ++i) {
            struct TreeNode *node = queue[head++];
            if (i == levelSize - 1) answer[(*returnSize)++] = node->val;
            if (node->left != NULL) queue[tail++] = node->left;
            if (node->right != NULL) queue[tail++] = node->right;
        }
    }
    return answer;
}

static int arrayEquals(const int *actual, int actualSize,
                       const int *expected, int expectedSize) {
    if (actualSize != expectedSize) return 0;
    for (int i = 0; i < actualSize; ++i) {
        if (actual[i] != expected[i]) return 0;
    }
    return 1;
}

int main(void) {
    struct TreeNode n5 = {5, NULL, NULL};
    struct TreeNode n4 = {4, NULL, NULL};
    struct TreeNode n2 = {2, NULL, &n5};
    struct TreeNode n3 = {3, NULL, &n4};
    struct TreeNode root = {1, &n2, &n3};
    const int expected[] = {1, 3, 4};
    int count = 0;
    int *answer = rightSideView(&root, &count);
    int passed = arrayEquals(answer, count, expected, 3);
    free(answer);

    count = -1;
    answer = rightSideView(NULL, &count);
    passed = passed && answer == NULL && count == 0;
    free(answer);

    puts(passed ? "PASS: 199 binary-tree-right-side-view"
                : "FAIL: 199 binary-tree-right-side-view");
    return passed ? 0 : 1;
}

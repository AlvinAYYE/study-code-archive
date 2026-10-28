/*
 * LeetCode 590. N-ary Tree Postorder Traversal
 * Title-CN: N 叉樹的後序遍歷
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/n-ary-tree-postorder-traversal/
 *
 * [題目翻譯]
 * 給定 N 叉樹的根節點，回傳節點值的後序遍歷結果。後序遍歷會先依序
 * 遍歷每個孩子，再把目前節點放入結果。題目用層序資料表示樹，每組孩子
 * 以 null 分隔。
 *
 * [範例]
 * root = [1,null,3,2,4,null,5,6]，回傳 [5,6,3,2,4,1]。
 * root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,
 * null,13,null,null,14]，回傳 [2,6,14,11,7,3,12,8,4,13,9,10,5,1]。
 * 進階：遞迴解法很直觀，能否改成迭代解法？
 *
 * [限制]
 * 節點數量為 0 到 10^4；0 <= Node.val <= 10^4；樹高不超過 1000。
 *
 * [解題思路]
 * 遞迴處理每個孩子，等孩子都完成後才把根節點值寫入結果陣列。
 * 先數出節點數以配置剛好足夠的結果空間。每個節點走訪一次，時間 O(n)，
 * 輸出空間 O(n)，遞迴堆疊最深 O(h)。
 */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    int numChildren;
    struct Node** children;
};

static int countNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    int count = 1;
    for (int i = 0; i < root->numChildren; ++i) {
        count += countNodes(root->children[i]);
    }
    return count;
}

static void fillPostorder(struct Node* root, int* result, int* index) {
    if (root == NULL) {
        return;
    }
    for (int i = 0; i < root->numChildren; ++i) {
        fillPostorder(root->children[i], result, index);
    }
    result[(*index)++] = root->val;
}

/* ---------- LeetCode submission / 提交區 ---------- */
int* postorder(struct Node* root, int* returnSize) {
    int nodeCount = countNodes(root);
    *returnSize = nodeCount;
    if (nodeCount == 0) {
        return NULL;
    }

    int* result = (int*)malloc((size_t)nodeCount * sizeof(int));
    if (result == NULL) {
        *returnSize = 0;
        return NULL;
    }
    int index = 0;
    fillPostorder(root, result, &index);
    return result;
}
/* ---------- end submission ---------- */

int main(void) {
    struct Node five = {5, 0, NULL};
    struct Node six = {6, 0, NULL};
    struct Node* threeChildren[] = {&five, &six};
    struct Node three = {3, 2, threeChildren};
    struct Node two = {2, 0, NULL};
    struct Node four = {4, 0, NULL};
    struct Node* rootChildren[] = {&three, &two, &four};
    struct Node root = {1, 3, rootChildren};
    int expected[] = {5, 6, 3, 2, 4, 1};
    int returnSize = 0;
    int* actual = postorder(&root, &returnSize);
    int ok = returnSize == 6;
    for (int i = 0; ok && i < returnSize; ++i) {
        ok = actual[i] == expected[i];
    }
    free(actual);

    int emptySize = -1;
    ok = ok && postorder(NULL, &emptySize) == NULL && emptySize == 0;
    printf("%s: 590 n-ary-tree-postorder-traversal\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}

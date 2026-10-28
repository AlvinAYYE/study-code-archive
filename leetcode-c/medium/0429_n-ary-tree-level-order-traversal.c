/*
 * Title-CN: N 叉樹的層序遍歷
 * LeetCode 429. N-ary Tree Level Order Traversal
 *
 * 題意翻譯：給定一棵 N 叉樹的根節點，請由上而下、由左而右列出每一層
 * 的節點值。每一層放在一個陣列中；空樹回傳空結果。
 *
 * 範例：root = [1,null,3,2,4,null,5,6]，回傳 [[1],[3,2,4],[5,6]]。
 * 說明：先走訪根節點 1，再走訪它的孩子 3、2、4，最後走訪 3 的孩子 5、6。
 *
 * 限制：節點數為 0 到 5000；節點值為 -100000 到 100000；樹高不超過 1000。
 *
 * 解題思路：使用佇列做廣度優先搜尋。每一輪先記住目前佇列的長度，
 * 這個長度就是本層節點數；逐一取出它們並把孩子加入佇列，便能自然分層。
 *
 * 複雜度：時間 O(n)，每個節點只進出佇列一次；額外空間 O(n)。
 * LeetCode 介面：保留 levelOrder；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdlib.h>

struct Node {
    int val;
    int numChildren;
    struct Node **children;
};

int **levelOrder(struct Node *root, int *returnSize, int **returnColumnSizes) {
    *returnSize = 0;
    *returnColumnSizes = NULL;
    if (root == NULL) {
        return NULL;
    }

    int capacity = 16;
    int front = 0;
    int back = 0;
    struct Node **queue = malloc((size_t)capacity * sizeof(*queue));
    int **levels = NULL;
    int *columnSizes = NULL;
    if (queue == NULL) {
        return NULL;
    }
    queue[back++] = root;

    while (front < back) {
        int levelCount = back - front;
        int *values = malloc((size_t)levelCount * sizeof(*values));
        if (values == NULL) {
            free(queue);
            for (int i = 0; i < *returnSize; ++i) free(levels[i]);
            free(levels);
            free(columnSizes);
            *returnSize = 0;
            return NULL;
        }

        for (int i = 0; i < levelCount; ++i) {
            struct Node *node = queue[front++];
            values[i] = node->val;
            for (int child = 0; child < node->numChildren; ++child) {
                if (back == capacity) {
                    capacity *= 2;
                    struct Node **grown = realloc(queue, (size_t)capacity * sizeof(*queue));
                    if (grown == NULL) {
                        free(values);
                        free(queue);
                        for (int j = 0; j < *returnSize; ++j) free(levels[j]);
                        free(levels);
                        free(columnSizes);
                        *returnSize = 0;
                        return NULL;
                    }
                    queue = grown;
                }
                queue[back++] = node->children[child];
            }
        }

        int **grownLevels = realloc(levels, (size_t)(*returnSize + 1) * sizeof(*levels));
        int *grownSizes = realloc(columnSizes, (size_t)(*returnSize + 1) * sizeof(*columnSizes));
        if (grownLevels == NULL || grownSizes == NULL) {
            free(values);
            free(grownLevels != NULL ? grownLevels : levels);
            free(grownSizes != NULL ? grownSizes : columnSizes);
            free(queue);
            *returnSize = 0;
            return NULL;
        }
        levels = grownLevels;
        columnSizes = grownSizes;
        levels[*returnSize] = values;
        columnSizes[*returnSize] = levelCount;
        ++*returnSize;
    }

    free(queue);
    *returnColumnSizes = columnSizes;
    return levels;
}

static struct Node makeNode(int value, int childCount, struct Node **children) {
    struct Node node = {value, childCount, children};
    return node;
}

int main(void) {
    struct Node n5 = makeNode(5, 0, NULL);
    struct Node n6 = makeNode(6, 0, NULL);
    struct Node *children3[] = {&n5, &n6};
    struct Node n3 = makeNode(3, 2, children3);
    struct Node n2 = makeNode(2, 0, NULL);
    struct Node n4 = makeNode(4, 0, NULL);
    struct Node *rootChildren[] = {&n3, &n2, &n4};
    struct Node root = makeNode(1, 3, rootChildren);

    int rows = 0;
    int *columns = NULL;
    int **answer = levelOrder(&root, &rows, &columns);
    int expected[][3] = {{1, 0, 0}, {3, 2, 4}, {5, 6, 0}};
    int expectedSizes[] = {1, 3, 2};
    assert(rows == 3);
    for (int r = 0; r < rows; ++r) {
        assert(columns[r] == expectedSizes[r]);
        for (int c = 0; c < columns[r]; ++c) assert(answer[r][c] == expected[r][c]);
        free(answer[r]);
    }
    free(answer);
    free(columns);

    answer = levelOrder(NULL, &rows, &columns);
    assert(rows == 0 && answer == NULL && columns == NULL);
    return 0;
}

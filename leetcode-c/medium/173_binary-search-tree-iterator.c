/*
 * LeetCode 173. Binary Search Tree Iterator
 * Title-CN: 二元搜尋樹迭代器
 *
 * 題目翻譯：實作 BSTIterator(root)、next() 與 hasNext()。建立迭代器時，位置在樹中最小值
 * 之前；next() 向右移到下一個中序值並回傳它；hasNext() 則判斷是否還有下一個值。
 * 題目保證每次 next() 呼叫時都還有值可取。
 *
 * 範例：BST 為 [7,3,15,null,null,9,20] 時，中序順序為 3、7、9、15、20。
 * next() -> 3，next() -> 7，hasNext() -> true，接著 next() -> 9、15、20，最後 hasNext() -> false。
 *
 * 限制：節點數 1 到 10^5；0 <= Node.val <= 10^6；next 與 hasNext 最多呼叫 10^5 次。
 * 進階要求：next 平均 O(1) 時間，額外空間 O(h)，h 為樹高。
 *
 * 解題思路：用堆疊模擬遞迴中序走訪，但只先放入目前節點一路往左的路徑。
 * 1. 建立迭代器時，將 root 到最左節點的路徑壓入堆疊；最小值就在堆疊頂端。
 * 2. next() 取出堆疊頂端；若該節點有右子樹，就把右子樹一路向左的節點放入堆疊。
 * 3. hasNext() 只需檢查堆疊是否為空。每個樹節點只進出堆疊一次，所以 next 平均 O(1)。
 *
 * 複雜度：建立迭代器 O(h)；next 平均 O(1)，單次最壞 O(h)；hasNext O(1)；空間 O(h)。
 *
 * LeetCode C API：
 * BSTIterator *bSTIteratorCreate(struct TreeNode *root);
 * int bSTIteratorNext(BSTIterator *obj);
 * bool bSTIteratorHasNext(BSTIterator *obj);
 * void bSTIteratorFree(BSTIterator *obj);
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct {
    struct TreeNode **nodes;
    size_t size;
    size_t capacity;
} BSTIterator;

static int iteratorPush(BSTIterator *obj, struct TreeNode *node) {
    if (obj->size == obj->capacity) {
        size_t newCapacity = obj->capacity == 0 ? 16 : obj->capacity * 2;
        struct TreeNode **newNodes =
            (struct TreeNode **)realloc(obj->nodes, newCapacity * sizeof *newNodes);
        if (newNodes == NULL) return 0;
        obj->nodes = newNodes;
        obj->capacity = newCapacity;
    }
    obj->nodes[obj->size++] = node;
    return 1;
}

static int pushLeftPath(BSTIterator *obj, struct TreeNode *node) {
    while (node != NULL) {
        if (!iteratorPush(obj, node)) return 0;
        node = node->left;
    }
    return 1;
}

/* LeetCode 提交 API */
BSTIterator *bSTIteratorCreate(struct TreeNode *root) {
    BSTIterator *obj = (BSTIterator *)calloc(1, sizeof *obj);
    if (obj == NULL) return NULL;

    if (!pushLeftPath(obj, root)) {
        free(obj->nodes);
        free(obj);
        return NULL;
    }
    return obj;
}

int bSTIteratorNext(BSTIterator *obj) {
    if (obj == NULL || obj->size == 0) return 0;

    struct TreeNode *node = obj->nodes[--obj->size];
    int value = node->val;
    /* 右子樹中的最小值，是中序走訪的下一個值。 */
    (void)pushLeftPath(obj, node->right);
    return value;
}

bool bSTIteratorHasNext(BSTIterator *obj) {
    return obj != NULL && obj->size > 0;
}

void bSTIteratorFree(BSTIterator *obj) {
    if (obj == NULL) return;
    free(obj->nodes);
    free(obj);
}

int main(void) {
    struct TreeNode n3 = {3, NULL, NULL};
    struct TreeNode n9 = {9, NULL, NULL};
    struct TreeNode n20 = {20, NULL, NULL};
    struct TreeNode n15 = {15, &n9, &n20};
    struct TreeNode root = {7, &n3, &n15};
    const int expected[] = {3, 7, 9, 15, 20};

    BSTIterator *iterator = bSTIteratorCreate(&root);
    int passed = iterator != NULL && bSTIteratorHasNext(iterator);
    for (int i = 0; i < 5; ++i) {
        if (!bSTIteratorHasNext(iterator) || bSTIteratorNext(iterator) != expected[i]) {
            passed = 0;
        }
    }
    passed = passed && !bSTIteratorHasNext(iterator);
    bSTIteratorFree(iterator);

    struct TreeNode only = {42, NULL, NULL};
    iterator = bSTIteratorCreate(&only);
    passed = passed && bSTIteratorHasNext(iterator) &&
             bSTIteratorNext(iterator) == 42 && !bSTIteratorHasNext(iterator);
    bSTIteratorFree(iterator);

    puts(passed ? "PASS: 173 binary-search-tree-iterator"
                : "FAIL: 173 binary-search-tree-iterator");
    return passed ? 0 : 1;
}

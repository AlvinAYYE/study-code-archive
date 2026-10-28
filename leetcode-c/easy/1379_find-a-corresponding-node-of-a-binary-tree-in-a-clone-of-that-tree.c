/*
 * Title-CN: 在複製樹中找對應節點
 * LeetCode 1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree
 *
 * 題意完整翻譯：
 *   給定原始二元樹 original、它的完整複製 cloned，以及指向 original 某個節點的 target。回傳 cloned 中與
 *   target 位置相同的節點。不能修改兩棵樹或 target；回傳值必須是 cloned 中節點的指標。題目限制節點值唯一；即使值重複，仍可用
 *   target 的原始指標定位。
 *
 * 範例：
 *   1. original 和 cloned 都是 [7,4,3,null,null,6,19]，target 指向值 3 的節點，回傳 cloned 中值
 *      3 的對應節點。
 *   2. 樹只有根節點 7，target 指向根，回傳 cloned 的根節點。
 *   3. 在只有右子樹的鏈狀樹中，target 指向值 4 的節點，回傳複製樹中相同位置的節點。
 *
 * 限制：
 *   - 節點數介於 1 到 10^4
 *   - original 與 cloned 的形狀、節點值完全相同
 *   - 節點值唯一
 *   - target 是 original 中非空的節點
 *
 * 解題步驟：
 *   1. 同步走訪 original 和 cloned 中相同位置的節點。
 *   2. 若 original 目前節點指標就是 target，回傳 cloned 目前節點。
 *   3. 否則遞迴檢查左右子樹；兩棵樹形狀相同，因此位置會一一對應。
 *   4. 找到後直接回傳複製樹中的節點指標，不複製或修改任何節點。
 *
 * 複雜度：
 *   時間：O(n)，最壞需要走訪所有節點。
 *   空間：O(h) 遞迴堆疊；h 是樹高，最壞為 O(n)。
 *
 * LeetCode C API：
 *   struct TreeNode* getTargetCopy(struct TreeNode* original, struct TreeNode*
 *   cloned, struct TreeNode* target);
 */
#include <assert.h>
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* getTargetCopy(struct TreeNode* original,
                               struct TreeNode* cloned,
                               struct TreeNode* target) {
    struct TreeNode* found;

    if (original == NULL) {
        return NULL;
    }
    if (original == target) {
        return cloned;
    }

    found = getTargetCopy(original->left, cloned->left, target);
    if (found != NULL) {
        return found;
    }
    return getTargetCopy(original->right, cloned->right, target);
}

int main(void) {
    struct TreeNode originalLeft = {4, NULL, NULL};
    struct TreeNode originalSix = {6, NULL, NULL};
    struct TreeNode originalNineteen = {19, NULL, NULL};
    struct TreeNode originalRight = {3, &originalSix, &originalNineteen};
    struct TreeNode originalRoot = {7, &originalLeft, &originalRight};

    struct TreeNode clonedLeft = {4, NULL, NULL};
    struct TreeNode clonedSix = {6, NULL, NULL};
    struct TreeNode clonedNineteen = {19, NULL, NULL};
    struct TreeNode clonedRight = {3, &clonedSix, &clonedNineteen};
    struct TreeNode clonedRoot = {7, &clonedLeft, &clonedRight};

    assert(getTargetCopy(&originalRoot, &clonedRoot, &originalRight) == &clonedRight);
    assert(getTargetCopy(&originalRoot, &clonedRoot, &originalLeft) == &clonedLeft);
    puts("PASS 1379 getTargetCopy");
    return 0;
}

# 404 Sum of Left Leaves：左葉節點之和

**難度：** Easy

## 題意完整翻譯

給定二元樹的根節點 root，回傳所有左葉節點的值總和。葉節點是沒有左、右子節點的節點；左葉節點還必須是其父節點的左子節點。

## 範例

### 範例 1

- 輸入：root = [3,9,20,null,null,15,7]
- 輸出：24
- 說明：左葉節點是 9 與 15，總和為 24。

### 範例 2

- 輸入：root = [1]
- 輸出：0
- 說明：根節點不是任何節點的左子節點，因此沒有左葉。

## 限制

- 節點數量介於 1 到 1000
- -1000 <= Node.val <= 1000

## 解題思路

1. 遞迴走訪每個節點，並記住目前節點是父節點的左子節點還是右子節點。
2. 若目前節點沒有子節點，且它是左子節點，就回傳它的值；其他葉節點回傳 0。
3. 非葉節點回傳左子樹與右子樹的結果相加。根節點一開始標記為非左子節點。

## 複雜度

- 時間：O(n)，每個節點恰好走訪一次。
- 空間：O(h) 遞迴堆疊；h 是樹高，最壞為 O(n)。

## C 函式簽名

~~~c
int sumOfLeftLeaves(struct TreeNode* root);
~~~

## 程式如何運作

~~~c
static int sumLeftLeavesHelper(struct TreeNode* node, bool isLeftChild) {
    if (node == NULL) {
        return 0;
    }

    // 葉節點只有在是左子節點時才計入。
    if (node->left == NULL && node->right == NULL) {
        return isLeftChild ? node->val : 0;
    }

    return sumLeftLeavesHelper(node->left, true) +
           sumLeftLeavesHelper(node->right, false);
}

int sumOfLeftLeaves(struct TreeNode* root) {
    // 根節點沒有父節點，所以不算左子節點。
    return sumLeftLeavesHelper(root, false);
}
~~~

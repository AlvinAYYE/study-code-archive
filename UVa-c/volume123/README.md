# UVa Volume 123 題目索引

本卷收錄 4 份 C 解答，涵蓋 4 個 UVa 題號，以下依題號排序。

<a id="uva-12342_tax-calculator"></a>

### UVa 12342 — Tax Calculator／所得稅試算

- 原始碼：[12342_tax-calculator.c](12342_tax-calculator.c)
- 難度：Easy
- 演算法：simulation, math

**English description:** Calculate income tax using progressive brackets with a minimum tax rule (if tax > 0, tax = max(ceil(tax), 2000)).

**中文詳細描述：** 依據累進稅率計算個人所得稅，若需繳稅則最低稅額為 2000 元（不滿 2000 算 2000，取無條件進位）。

**English approach:** Apply tax brackets (first 180k exempt, next 300k at 10%, next 400k at 15%, next 300k at 20%, remainder at 25%). If tax > 0 and tax < 2000, tax = 2000.

**中文解題思路：** 依各級距累進課稅，計算總稅額並無條件進位；若有稅額且小於 2000 則一律以 2000 計。 ==========================================================================


<a id="uva-12347_binary_search_tree"></a>

### UVa 12347 — Binary Search Tree／二元搜尋樹前序轉後序

- 原始碼：[12347_binary_search_tree.c](12347_binary_search_tree.c)
- 難度：Medium
- 演算法：tree, bst, recursion

**English description:** Given the preorder traversal sequence of a Binary Search Tree, output its postorder traversal sequence.

**中文詳細描述：** 給定二元搜尋樹（BST）的前序遍歷序列，重建該樹並輸出後序遍歷序列。

**English approach:** First element is root. Find partition index where elements become greater than root (right subtree). Recursively convert left and right subtrees.

**中文解題思路：** 前序首位為根節點，找到首個大於根節點的位置劃分左右子樹，遞歸處理左子樹、右子樹後輸出根節點。 ==========================================================================


<a id="uva-12356_army-buddies"></a>

### UVa 12356 — Army Buddies／戰友陣亡雙向鏈結相鄰存活者更新

- 原始碼：[12356_army-buddies.c](12356_army-buddies.c)
- 難度：UVa Star 2
- 演算法：data-structures, linked-list

**English description:** Line of soldiers 1..S. Reports indicate casualties in range [L, R]. Output the nearest living soldier to the left of L and right of R.

**中文詳細描述：** 士兵排成一列 (1..S)，戰報回報區間 [L, R] 內士兵全員陣亡，輸出其左側與右側緊鄰之最新存活士兵編號。

**English approach:** Simulate doubly linked list using left[i] and right[i] arrays. When [L, R] dies, link left[L] directly to right[R].

**中文解題思路：** 以 left 與 right 雙向陣列模擬鏈結串列：區間 [L, R] 陣亡時令 right[left[L]] = right[R]，left[right[R]] = left[L]，O(1) 更新邊界。 ==========================================================================


<a id="uva-12372_packing-for-holiday"></a>

### UVa 12372 — Packing for Holiday／假日行李箱尺寸檢驗

- 原始碼：[12372_packing-for-holiday.c](12372_packing-for-holiday.c)
- 難度：UVa Star 1
- 演算法：basics, simulation

**English description:** Check if a suitcase with dimensions L, W, H fits within the maximum airline luggage limits of 20 x 20 x 20.

**中文詳細描述：** 給定行李箱長寬高 L, W, H，檢驗其是否各維度均不超過航空公司隨身行李限制 20 x 20 x 20。

**English approach:** Return 1 (good) if L <= 20 and W <= 20 and H <= 20, else 0 (bad).

**中文解題思路：** 單純比較 L <= 20 且 W <= 20 且 H <= 20 即可判定是否符合規格。 ==========================================================================

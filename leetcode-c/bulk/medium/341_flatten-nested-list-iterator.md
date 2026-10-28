# LeetCode 0341. Flatten Nested List Iterator

Title-CN: 扁平化巢狀清單迭代器

## 題目

給定由整數和巢狀清單組成的資料，建立迭代器，讓 next 依原本由左至右、由外至內的順序逐一回傳所有整數；hasNext 判斷是否還有整數。

## 範例

1. 輸入：nestedList = [[1,1],2,[1,1]]；依序 next 得到 [1,1,2,1,1]。
2. 輸入：nestedList = [1,[4,[6]]]；依序 next 得到 [1,4,6]。

## 限制

- 1 <= nestedList.length <= 500
- 巢狀清單中的整數介於 -10^6 和 10^6

## 解題思路

1. 建立迭代器時，使用深度優先走訪巢狀清單：遇到整數就放入一維陣列，遇到子清單就依序遞迴展開。
2. 迭代器保存攤平後的陣列、元素數量和目前索引。
3. hasNext 檢查索引是否小於元素數量；next 回傳目前元素後將索引加一。
4. 把展開工作集中在建立階段，讓每次讀取都只需 O(1)。

## 複雜度

建立時間 O(N)，每次 next/hasNext 為 O(1)，額外空間 O(N)；N 是巢狀結構中的整數數量。

## C 函式簽名

struct NestedIterator* nestedIterCreate(struct NestedInteger** nestedList, int nestedListSize); bool nestedIterHasNext(struct NestedIterator* iter); int nestedIterNext(struct NestedIterator* iter); void nestedIterFree(struct NestedIterator* iter)

# LeetCode 0707. Design Linked List

Title-CN: 設計鏈結串列

## 題目

請自行實作單向鏈結串列。每個節點保存一個整數和指向下一個節點的指標；索引從 0 開始。支援查詢指定索引、在開頭或末尾新增節點、在指定索引前新增節點，以及刪除指定索引的節點。索引不存在時，查詢回傳 `-1`，新增或刪除則不改變串列；若新增索引小於等於 0，視為加在開頭，若索引等於目前長度則加在末尾。

## 範例

1. 操作：建立串列，`addAtHead(1)`、`addAtTail(3)`、`addAtIndex(1,2)`。串列變成 `1 -> 2 -> 3`，`get(1)` 回傳 `2`；刪除索引 1 後串列為 `1 -> 3`，`get(1)` 回傳 `3`。

## 限制

- `0 <= index, val <= 1000`
- 不可使用內建 LinkedList
- `get`、新增與刪除操作總呼叫次數不超過 2000

## 解題思路

1. 建立一個永遠保留的 dummy 假頭節點。真正的第一個節點放在 `dummy->next`，因此處理索引 0 時也能沿用一般插入規則。
2. 另外保存 `size`，先用它判斷索引是否有效，也能快速知道尾端插入位置。
3. 插入或刪除索引 `i` 時，從 dummy 走到第 `i` 個節點的前一格，再重新接好 `next` 指標。
4. 查詢則從第一個實際節點走 `i` 步；銷毀串列時逐節點釋放記憶體。

## 複雜度

查詢、插入和刪除最壞時間皆為 `O(n)`；串列額外空間為 `O(n)`。

## C 函式簽名

`MyLinkedList* myLinkedListCreate(void)`、`int myLinkedListGet(MyLinkedList* obj, int index)`、`void myLinkedListAddAtHead(MyLinkedList* obj, int val)`、`void myLinkedListAddAtTail(MyLinkedList* obj, int val)`、`void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val)`、`void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index)`、`void myLinkedListFree(MyLinkedList* obj)`

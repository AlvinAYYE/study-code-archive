# LeetCode 206. Reverse Linked List

**難度：Easy**

## 題意完整翻譯

給定單向鏈結串列的頭節點 head，請將串列方向反轉，並回傳新的頭節點。反轉時應直接改變節點的 next 指標，不必建立新的節點。

## 範例

1. head = [1,2,3,4,5] → [5,4,3,2,1]
2. head = [1,2] → [2,1]
3. head = [] → []

## 限制

- 節點數介於 0 到 5000
- -5000 <= Node.val <= 5000

## 解題思路

1. 用 previous 記錄已反轉部分的頭，初始為空；current 從 head 開始。
2. 每次先暫存 current->next，再把 current->next 指向 previous。
3. previous 和 current 都往前移一格，直到 current 為空。
4. 此時 previous 就是反轉後的新頭節點。

## 複雜度

- 時間：O(n)
- 空間：O(1)

## C 函式簽名

~~~c
struct ListNode* reverseList(struct ListNode* head);
~~~

## 程式如何運作

提交函式依照上述步驟完成計算；程式註解標出每個關鍵動作。本地測試 harness 保留在 .c 檔尾端。

# 0203. Remove Linked List Elements《移除鏈結串列元素》

- 難度：Easy
- 題目連結：https://leetcode.com/problems/remove-linked-list-elements/

## 題目翻譯

給定單向鏈結串列的頭節點 head 和整數 val，移除所有節點值等於 val 的節點，並回傳移除後串列的新頭節點。

## 範例

~~~text
輸入：head = [1,2,6,3,4,5,6], val = 6
輸出：[1,2,3,4,5]

輸入：head = [], val = 1
輸出：[]

輸入：head = [7,7,7,7], val = 7
輸出：[]
~~~

## 限制

- 節點數介於 0 到 10^4。
- 1 <= Node.val <= 50
- 0 <= val <= 50

## 解題步驟

1. 在原本串列前放一個暫時的 dummy 節點，讓刪除頭節點也能使用相同流程。
2. current 指向目前保留的節點，檢查 current->next。
3. 若下一個節點的值等於 val，就把 current->next 改成再下一個節點。
4. 若不是目標值，就將 current 前進一格。
5. 回傳 dummy.next，這就是更新後的串列頭。

## 複雜度

- 時間：O(n)，每個節點最多檢查一次。
- 空間：O(1)，只使用虛擬節點與指標。

## C 函式簽名

~~~c
struct ListNode* removeElements(struct ListNode* head, int val);
~~~

LeetCode 已提供 struct ListNode 型別定義。
~~~

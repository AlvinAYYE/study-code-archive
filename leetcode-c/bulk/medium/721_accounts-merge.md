# LeetCode 0721. Accounts Merge

Title-CN: 合併帳戶

## 題目

每個帳戶是一串字串：第一個是姓名，後面都是該帳戶的 email。若兩個帳戶有任何一個相同 email，就確定屬於同一個人，必須合併；同一個人原本也可能有多個帳戶。姓名相同本身不代表是同一人。合併後每組第一項放姓名，其餘 email 依字典順序排列；不同組的輸出順序不限。

## 範例

1. 輸入有兩個 John 帳戶共用 `johnsmith@mail.com`，另有 Mary 與另一個 John 帳戶。輸出可包含：`[John, john00@mail.com, john_newyork@mail.com, johnsmith@mail.com]`、`[Mary, mary@mail.com]`、`[John, johnnybravo@mail.com]`。
2. 輸入中的五個帳戶都沒有共用 email，輸出就是五組各自排序後的帳戶。

## 限制

- `1 <= accounts.length <= 1000`
- `2 <= accounts[i].length <= 10`
- 每個字串長度介於 1 到 30；姓名只含英文字母，其他欄位是合法 email
- 同一人的所有帳戶姓名相同

## 解題思路

1. 把每個帳戶視為一個節點。第一次看到某個 email 時，記住它屬於哪個帳戶；之後再看到同一 email，就把兩個帳戶用並查集合併。
2. 所有帳戶處理完後，並查集根節點代表同一個人。雜湊表每個 email 只保存一次，所以自然完成 email 去重。
3. 依根節點計算每組有幾個 email，為每組配置輸出陣列，複製姓名與 email。
4. 對每組姓名以外的 email 執行字典排序，再回傳分組結果。

## 複雜度

令 `E` 為所有帳戶列出的 email 數量、`A` 為帳戶數。平均時間 `O(E α(A) + E log E)`，空間 `O(E + A)`。

## C 函式簽名

`char*** accountsMerge(char*** accounts, int accountsSize, int* accountsColSize, int* returnSize, int** returnColumnSizes)`

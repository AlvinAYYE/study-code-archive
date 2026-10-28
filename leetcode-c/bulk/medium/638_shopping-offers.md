# LeetCode 0638. Shopping Offers

Title-CN: 購物優惠

## 題目

有 n 種商品，price[i] 是單買第 i 種商品的價格。每個優惠 special[i] 列出各商品數量和優惠總價。給定 needs，請計算剛好買到需求數量的最低花費；優惠可以不使用，也不能買超過需求。

## 範例

1. 輸入：price = [2,5]，special = [[3,0,5],[1,2,10]]，needs = [3,2]；輸出：14。
2. 輸入：price = [2,3,4]，special = [[1,1,0,4],[2,2,1,9]]，needs = [1,2,1]；輸出：11。

## 限制

- 1 <= 商品種類數 n <= 6
- 0 <= price[i], needs[i] <= 10
- 1 <= special.length <= 100
- 每個優惠列含 n 種商品數量及 1 個總價
- 每個優惠至少包含一件商品

## 解題思路

1. 把目前剩餘需求向量當作一個狀態；先假設剩下商品全部單買，得到一個可行花費上限。
2. 逐一嘗試優惠。若優惠任一商品數量超過剩餘需求，就不能使用。
3. 可使用時，將優惠數量從需求扣除，遞迴計算剩餘需求的最低花費，再加上優惠價格。
4. 用需求向量的 base-11 編碼作為 memo 索引，記住每個狀態的最佳花費，避免重複計算。

## 複雜度

最多 O(11^n * S * n)，S 為優惠數量；額外空間 O(11^n)。

## C 函式簽名

int shoppingOffers(int* price, int priceSize, int** special, int specialSize, int* specialColSize, int* needs, int needsSize)

# LeetCode 0299. Bulls and Cows

Title-CN: 公牛與母牛

## 題目

給定等長數字字串 secret 和 guess。公牛（bull）代表數字和位置都正確；母牛（cow）代表數字正確但位置不同。回傳格式為 xAyB，其中 x 是公牛數、y 是母牛數。

## 範例

1. 輸入：secret = 1807，guess = 7810；輸出：1A3B。
2. 輸入：secret = 1123，guess = 0111；輸出：1A1B。不能把已配成公牛的數字再算成母牛。

## 限制

- 1 <= secret.length == guess.length <= 1000
- secret 和 guess 只包含數字

## 解題思路

1. 先逐位比較；同一位置數字相同就計為公牛。
2. 其餘位置才可能形成母牛，分別統計 secret 和 guess 中未配對的 0 到 9 數量。
3. 每個數字能配對的母牛數，是兩邊未配對數量的較小值；將十種數字的配對數加總。
4. 把公牛數和母牛數格式化成 xAyB 字串。

## 複雜度

時間 O(n)，額外空間 O(1)。

## C 函式簽名

char* getHint(char* secret, char* guess)

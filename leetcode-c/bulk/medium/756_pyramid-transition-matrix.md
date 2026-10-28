# LeetCode 0756. Pyramid Transition Matrix

Title-CN: 金字塔轉換矩陣

## 題目

每塊積木以 A 到 F 的一個字母代表顏色。每條規則 `XYZ` 表示：底層相鄰的左積木 `X`、右積木 `Y` 上方，可以放一塊 `Z`。給定底層字串 `bottom` 和所有允許規則 `allowed`，判斷是否有辦法逐層往上疊，最後只剩一塊積木。

## 範例

1. 輸入：`bottom = "BCD"`、`allowed = ["BCC","CDE","CEA","FFF"]`；輸出：`true`。底層相鄰的 `BC` 可疊成 `C`、`CD` 可疊成 `E`，因此第二層是 `CE`；`CEA` 再把它疊成 `A`。
2. 輸入：`bottom = "AAAA"`、`allowed = ["AAB","AAC","BCD","BBE","DEF"]`；輸出：`false`。嘗試所有第二層組合後，都會在抵達頂端前卡住。

## 限制

- `2 <= bottom.length <= 6`
- `0 <= allowed.length <= 216`
- 每條規則長度為 3，顏色只會是 A 到 F
- `allowed` 中的規則不重複

## 解題思路

1. 把每組底色 `(左色, 右色)` 對應到可選頂色的集合。顏色只有六種，所以用 6 個位元表示集合。
2. 依序為底層每一對相鄰積木選一個允許的頂色，組成短一格的新列。
3. 對新列重複相同程序；只要其中一種分支可以一路到長度 1，就回傳 `true`。
4. 用列字串編碼成整數並記憶化結果。同一列只需判斷一次，遇到無路可走的列便直接回傳 `false`。

## 複雜度

令 `L` 為底層長度，最壞約 `O(6^L)` 個不同列狀態；記憶化空間 `O(6^L)`。題目保證 `L <= 6`。

## C 函式簽名

`bool pyramidTransition(char* bottom, char** allowed, int allowedSize)`

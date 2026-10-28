# UVa Volume 004

本卷收錄 12 個 C 題目檔，依 UVa 題號排序。

<a id="uva-401_palindromes"></a>

### UVa 401 — Palindromes／回文與鏡像字串判定

- 原始碼：[401_palindromes.c](401_palindromes.c)
- 演算法：字串比對、鏡像映射（string, simulation）

**English description:** For every input string, independently test whether it reads the same backward and whether reversing it while replacing each character by its defined mirror yields the original. Print one of four classifications: regular palindrome, mirrored string, mirrored palindrome, or neither.

**中文詳細描述：** 每行輸入一個只含題目允許字元的字串。第一項檢查左右反讀是否相同，第二項利用字元鏡像對照表，判斷把字串反轉並逐字鏡射後是否仍相同。依兩項布林結果輸出普通回文、鏡像字串、鏡像回文或兩者皆非的指定句子。

<a id="uva-438_the-circumference-of-the-circle"></a>

### UVa 438 — The Circumference of the Circle／三角形外接圓周長

- 原始碼：[438_the-circumference-of-the-circle.c](438_the-circumference-of-the-circle.c)
- 演算法：平面幾何、海龍公式（geometry, circumcircle）

**English description:** Each case provides the Cartesian coordinates of three non-collinear points. Determine the circumference of the unique circle passing through all three points and print it to two decimal places.

**中文詳細描述：** 每筆輸入三個不共線平面點的座標，三點可形成唯一的外接圓。先由點距求三角形三邊，使用海龍公式求面積，再以 `R = abc/(4A)` 得到半徑並計算 `2πR`；每筆輸出圓周長至小數點後兩位。

<a id="uva-439_knight-moves"></a>

### UVa 439 — Knight Moves／西洋棋騎士最短步數

- 原始碼：[439_knight-moves.c](439_knight-moves.c)
- 演算法：廣度優先搜尋（graph, BFS, shortest path）

**English description:** Given two algebraic square names on a standard 8 × 8 chessboard, find the minimum number of legal knight moves from the first square to the second. Print the original square names and the distance in the required sentence.

**中文詳細描述：** 每筆輸入兩個棋盤位置，例如 `a1` 與 `h8`。把 8 × 8 棋盤視為無權圖，每格可連到騎士八種「日」字走法仍在棋盤內的位置，以 BFS 從起點找最短距離；輸出原起終點與最少移動步數。

<a id="uva-445_marvelous-mazes"></a>

### UVa 445 — Marvelous Mazes／奇妙的迷宮解碼繪圖

- 原始碼：[445_marvelous-mazes.c](445_marvelous-mazes.c)
- 演算法：游程解碼、字串模擬（string, run-length decoding）

**English description:** Decode a compact maze description. Consecutive digits contribute their values to a repetition count; the following character is printed that many times, with `b` representing a blank. An exclamation mark or an input newline starts a new output line.

**中文詳細描述：** 輸入以數字和字元壓縮表示迷宮。連續數字不是一個多位數，而是把每個數字值相加作為下一個圖形字元的重複次數；`b` 要畫成空白，`!` 與原輸入換行都表示另起一列。逐字解碼後輸出完整迷宮圖案。

<a id="uva-458_the-decoder"></a>

### UVa 458 — The Decoder／簡易解碼器

- 原始碼：[458_the-decoder.c](458_the-decoder.c)
- 演算法：逐字元轉換（string, basic I/O）

**English description:** Read the encoded text until end of file. Decode each non-newline character by subtracting 7 from its ASCII value, while preserving line boundaries, and print the resulting plaintext.

**中文詳細描述：** 輸入是持續到檔案結尾的加密文字，每個可見字元的編碼值都比原字元大 7。程式逐字讀取，將非換行字元的 ASCII 值減 7 後輸出，換行原樣保留，從而還原完整明文。

<a id="uva-476_points-in-figures"></a>

### UVa 476 — Points in Figures: Rectangles／點是否落在矩形內

- 原始碼：[476_points-in-figures.c](476_points-in-figures.c)
- 演算法：幾何、矩形內部判定（geometry, point containment）

**English description:** Read up to ten axis-aligned rectangles, then test each point until the sentinel point `(9999.9, 9999.9)`. Report every rectangle containing each point; points on rectangle borders are considered outside.

**中文詳細描述：** 先讀取至多十個矩形，每個矩形以左上角與右下角座標表示，直到 `*` 結束圖形輸入。接著逐點檢查，直到讀到 `(9999.9, 9999.9)`；若點嚴格位於某矩形內部，就輸出該點與矩形編號，邊界上的點不算包含。若沒有任何矩形包含該點，輸出題目指定的未包含訊息。

<a id="uva-482_permutation-arrays"></a>

### UVa 482 — Permutation Arrays／排列陣列還原

- 原始碼：[482_permutation-arrays.c](482_permutation-arrays.c)
- 演算法：索引映射、陣列置換（array, permutation）

**English description:** Each test case contains a line of one-based destination indices and a matching line of data strings. Place the i-th data item at the position specified by the i-th index, then print the reordered items one per line, separating test cases with a blank line.

**中文詳細描述：** 每組輸入有兩列等長資料：第一列是從 1 開始的位置索引，第二列是要排列的字串或數值文字。第 `i` 個資料應放到第 `index[i]` 個輸出位置，完成映射後依位置逐行輸出；不同測試案例之間依題意留空行。

<a id="uva-483_word-scramble"></a>

### UVa 483 — Word Scramble／單字字元原地反轉

- 原始碼：[483_word-scramble.c](483_word-scramble.c)
- 演算法：字串掃描、區間反轉（string, two pointers）

**English description:** Read text line by line and reverse the characters within each whitespace-delimited word. Keep the words in their original order and preserve the separating spaces and line breaks.

**中文詳細描述：** 輸入包含多行文字，以空白和換行作為單字邊界。對每個單字只反轉其內部字元，不改變單字順序，也不移動原本的分隔空白與換行；處理後逐行輸出轉換結果。

<a id="uva-488_triangle-wave"></a>

### UVa 488 — Triangle Wave／三角波形輸出

- 原始碼：[488_triangle-wave.c](488_triangle-wave.c)
- 演算法：巢狀迴圈輸出模擬（simulation, pattern printing）

**English description:** For each test case, an amplitude and a frequency describe a numeric wave. One wave rises from line 1 through the amplitude and then falls back to 1; line `i` consists of digit `i` repeated `i` times. Print the wave the requested number of times with the specified blank-line separation.

**中文詳細描述：** 每組輸入振幅 `A` 與頻率 `F`。單一波形從第 1 層上升到第 `A` 層，再下降回第 1 層；第 `i` 層輸出 `i` 共 `i` 次。將完整波形重複 `F` 次，並依題目格式在波形及測試案例之間加入空白行。

<a id="uva-490_rotating-sentences"></a>

### UVa 490 — Rotating Sentences／句子順時針旋轉 90 度輸出

- 原始碼：[490_rotating-sentences.c](490_rotating-sentences.c)
- 演算法：二維字元陣列（string, matrix rotation）

**English description:** Read all input lines as rows of a character grid, padding shorter lines conceptually with spaces. Rotate the complete collection 90 degrees clockwise and print it, so each output row is one original column read from the last input line upward.

**中文詳細描述：** 將直到檔案結尾的每一行文字存成二維字元陣列，各列長度可不同，缺少的位置視為空白。以最長輸入列為輸出行數，對每個欄位從最後一列往第一列讀取，即得到順時針旋轉 90 度的結果；必要空白也要保留。

<a id="uva-494_kindergarten-counting-game"></a>

### UVa 494 — Kindergarten Counting Game／幼稚園單字計數

- 原始碼：[494_kindergarten-counting-game.c](494_kindergarten-counting-game.c)
- 演算法：有限狀態掃描（string, state machine）

**English description:** For each input line, count words defined as maximal consecutive sequences of alphabetic letters. Digits, punctuation, and whitespace all separate words. Print one count per line.

**中文詳細描述：** 每行文字各自計算單字數；單字定義為一段最長的連續英文字母，數字、標點及空白都視為分隔符。掃描時在「非單字」轉入「字母中」的瞬間加一，最後每個輸入行輸出一個計數。

<a id="uva-499_whats-the-frequency-kenneth"></a>

### UVa 499 — What's The Frequency, Kenneth?／出現頻率最高字母統計

- 原始碼：[499_whats-the-frequency-kenneth.c](499_whats-the-frequency-kenneth.c)
- 演算法：字元頻率統計（string, counting）

**English description:** For each input line, count uppercase and lowercase English letters separately, ignoring all other characters. Print every letter tied for the highest positive frequency in ASCII order, followed by that frequency.

**中文詳細描述：** 對每一輸入行分別統計 `A`–`Z` 與 `a`–`z` 的出現次數，大小寫視為不同字元，其他內容不計。找出該行最高頻率，依大寫在前、小寫在後的字元順序輸出所有並列字母，再輸出最高次數。

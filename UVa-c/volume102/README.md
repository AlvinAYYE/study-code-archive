# UVa Volume 102 題目索引

本目錄收錄 14 支 C 題目檔，涵蓋 14 個題目。

<a id="uva-10200_prime-time"></a>
### UVa 10200 — Prime Time／質數時刻

- 原始碼：[10200_prime-time.c](10200_prime-time.c)
- 演算法：質數判定、前綴和（Prime, Prefix Sum）

**English description:** For every inclusive interval [a, b], evaluate n²+n+41 at each integer n and print the percentage of those values that are prime, rounded in the required format.

**中文詳細描述：** 每筆輸入區間端點 a、b；要對其中每個整數 n 計算 n²+n+41，統計結果為質數的比例並輸出百分比。完整作法可先預計算各 n 的質數性與前綴計數，使每個區間能快速取得質數個數

<a id="uva-10209_is-this-integration"></a>
### UVa 10209 — Is This Integration?／這是積分嗎？

- 原始碼：[10209_is-this-integration.c](10209_is-this-integration.c)
- 演算法：平面幾何、圓弧面積公式（Geometry）

**English description:** A square and four circular arcs divide the figure into three types of regions. Given the side length, compute and print the total area of each region type.

**中文詳細描述：** 每行輸入正方形邊長；圖中的四段圓弧把正方形分成三種對稱區域，任務是求三類區域各自的總面積。程式利用正方形、扇形與等邊三角形的精確面積關係推導公式，代入邊長平方後按指定順序與精度輸出三值。

<a id="uva-10215_the-largest-smallest-box"></a>
### UVa 10215 — The Largest/Smallest Box ...／最大與最小盒子

- 原始碼：[10215_the-largest-smallest-box.c](10215_the-largest-smallest-box.c)
- 演算法：微分極值、二次方程（Calculus, Math）

**English description:** Squares of side x are removed from the four corners of a W by L sheet and the sides are folded to form an open box. Print the x that maximizes volume and the boundary x values that minimize it.

**中文詳細描述：** 每行輸入矩形紙板的寬 W 與長 L；四角各剪去邊長 x 的正方形後折成立體，體積為 x(W-2x)(L-2x)。程式令導數為零並解二次方程取得合法的最大體積切割值；最小體積出現在可行區間兩端，輸出最大值位置與兩個最小值邊界。

<a id="uva-10219_find-the-ways-"></a>
### UVa 10219 — Find the Ways!／找出方法數

- 原始碼：[10219_find-the-ways-.c](10219_find-the-ways-.c)
- 演算法：組合數、對數累加（Combinatorics, Logarithm）

**English description:** Given n and k, determine how many decimal digits are needed to write the binomial coefficient C(n, k), without constructing the potentially enormous coefficient.

**中文詳細描述：** 每行輸入 n、k；任務是輸出組合數 C(n,k) 的十進位位數。程式利用對稱性取較小的 k，累加分子與分母的常用對數，最後以總和向下取整再加一得到位數，避免直接計算巨大整數。

<a id="uva-10221_satellites"></a>
### UVa 10221 — Satellites／人造衛星

- 原始碼：[10221_satellites.c](10221_satellites.c)
- 演算法：圓弧、弦長、角度轉換（Geometry, Trigonometry）

**English description:** Two satellites orbit at a given height and are separated by an angle expressed in degrees or minutes. Compute the shorter arc distance along the orbit and the straight chord distance between them.

**中文詳細描述：** 每行輸入衛星離地高度、夾角及角度單位；軌道半徑為地球半徑 6440 加高度。程式先把分轉成度，並把大於 180 度的角換成較短圓弧角，再轉弧度計算 `rθ` 的弧長與 `2r sin(θ/2)` 的弦長，輸出兩值。

<a id="uva-10222_decode-the-mad-man"></a>
### UVa 10222 — Decode the Mad Man／解碼瘋狂打字者

- 原始碼：[10222_decode-the-mad-man.c](10222_decode-the-mad-man.c)
- 演算法：鍵盤字元映射、字串模擬（Keyboard Mapping）

**English description:** Decode text typed with every intended key displaced two positions to the right on a QWERTY keyboard. Map each typed character two keys left, using lowercase output and preserving whitespace.

**中文詳細描述：** 輸入直到檔案結尾的加密文字；打字者的手在標準 QWERTY 鍵盤上向右偏了兩格，因此每個字元要映射到鍵盤序列左邊兩格。程式先轉成小寫並在固定鍵盤表中查找，空白與換行保留，逐字輸出解碼內容。

<a id="uva-10226_hardwood-species"></a>
### UVa 10226 — Hardwood Species／硬木樹種

- 原始碼：[10226_hardwood-species.c](10226_hardwood-species.c)
- 演算法：字串排序、次數統計（Sorting, Frequency Counting）

**English description:** For each forest survey, count every tree species and print the species names alphabetically with their percentages of the total population to four decimal places.

**中文詳細描述：** 每組測資由多行完整樹種名稱組成，空行分隔案例；需統計各樹種出現次數，以總棵數換算百分比，再按名稱字典序輸出至小數點後四位。可先排序讓同名項目連續後計數

<a id="uva-10235_simply-emirp"></a>
### UVa 10235 — Simply Emirp／反向質數

- 原始碼：[10235_simply-emirp.c](10235_simply-emirp.c)
- 演算法：質數判定、數字反轉（Prime, Number Theory）

**English description:** Classify each integer as non-prime, prime, or emirp. An emirp is prime and remains prime after its digits are reversed, with the reversed value different from the original.

**中文詳細描述：** 每行輸入一個整數；先判斷原數是否為質數，若不是就輸出非質數。若原數為質數，再反轉十進位數字並檢查反轉值；反轉值不同且也是質數時分類為 emirp，否則分類為一般質數。

<a id="uva-10242_fourth-point-"></a>
### UVa 10242 — Fourth Point!!／第四個點

- 原始碼：[10242_fourth-point-.c](10242_fourth-point-.c)
- 演算法：向量幾何、座標運算（Vector Geometry）

**English description:** Four input coordinate pairs describe two adjacent sides of a parallelogram, with their common endpoint repeated. Determine and print the missing fourth vertex.

**中文詳細描述：** 每筆輸入四個端點座標，其中有兩個座標相同，代表平行四邊形兩條相鄰邊的共同頂點。程式先辨認重複點 C 與另外兩點 A、B，再以向量關係 D=A+B-C 計算缺少的第四點，依指定精度輸出座標。

<a id="uva-10252_common-permutation"></a>
### UVa 10252 — Common Permutation／共同排列

- 原始碼：[10252_common-permutation.c](10252_common-permutation.c)
- 演算法：字元頻率交集（Frequency Counting）

**English description:** Given two lowercase strings, print the longest alphabetically sorted string whose letters can be selected from both inputs, respecting each letter's available multiplicity.

**中文詳細描述：** 每次輸入兩行小寫字串；要找可同時由兩字串各自選出並重新排列的最長字串。程式分別統計 a 到 z 的出現次數，每個字母取兩邊次數的較小值，再由 a 到 z 重複輸出，因此自然得到字典序結果。

<a id="uva-10258_contest-scoreboard"></a>
### UVa 10258 — Contest Scoreboard／競賽計分板

- 原始碼：[10258_contest-scoreboard.c](10258_contest-scoreboard.c)
- 演算法：事件模擬、多鍵排序（Simulation, Sorting）

**English description:** Process programming contest submissions and rank every participating team by problems solved descending, total penalty ascending, and team number ascending.

**中文詳細描述：** 輸入多組提交紀錄，每筆包含隊伍、題號、時間與結果代碼；只有首次正確提交計入解題，之前該題的錯誤提交各加固定罰時，其他結果仍使隊伍列入榜單但不影響分數。完成模擬後依解題數、罰時與隊號排序輸出

<a id="uva-10268_498-bis"></a>
### UVa 10268 — 498-bis／多項式導數求值

- 原始碼：[10268_498-bis.c](10268_498-bis.c)
- 演算法：霍納法則、多項式（Horner's Rule）

**English description:** Given x and the coefficients of a polynomial in descending degree order, evaluate the derivative P'(x) and print its value.

**中文詳細描述：** 每組輸入先給求值點 x，下一行給多項式由最高次到常數項的係數。任務是計算導函數在 x 的值；程式把每個係數乘上原次方後，以霍納法則在線性時間內累積，避免逐項計算冪次並輸出結果。

<a id="uva-10281_average-speed"></a>
### UVa 10281 — Average Speed／平均速度

- 原始碼：[10281_average-speed.c](10281_average-speed.c)
- 演算法：時間解析、分段等速累積（Simulation）

**English description:** Timestamped records either change the current speed or query the distance traveled so far. Update distance over each elapsed interval and print queried timestamps with accumulated kilometers.

**中文詳細描述：** 每行以 `hh:mm:ss` 開頭，後面可能附新速度；有速度時先把前一段經過時間乘目前速度加入里程，再更新速度，只有時間時則輸出截至該刻的總距離。需把時間轉為秒並保存上一筆時間與當前速度

<a id="uva-10282_babelfish"></a>
### UVa 10282 — Babelfish／巴別魚

- 原始碼：[10282_babelfish.c](10282_babelfish.c)
- 演算法：字典、排序與二分搜尋（Dictionary, Binary Search）

**English description:** Read English and foreign-word pairs into a dictionary, then translate each queried foreign word to English. Print "eh" when no dictionary entry exists.

**中文詳細描述：** 輸入前半段是「英文 外語」字典條目，以空行結束；後半段逐行給外語查詢。程式依外語欄位排序字典，對每次查詢做二分搜尋，找到便輸出對應英文，找不到則輸出 `eh`。

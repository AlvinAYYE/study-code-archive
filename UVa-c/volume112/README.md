# UVa Volume 112 題目索引

本卷收錄 17 份 C 解答，涵蓋 17 個 UVa 題號，以下依題號排序。

<a id="uva-11219_how-old-are-you"></a>

### UVa 11219 — How old are you?／精確年齡計算與異常檢測

- 原始碼：[11219_how-old-are-you.c](11219_how-old-are-you.c)
- 難度：UVa Star 1
- 演算法：simulation, date

**English description:** Given current date and birth date (DD/MM/YYYY), calculate age in years. Output 'Invalid birth date' or 'Check birth date' (> 130).

**中文詳細描述：** 給定當前日期與出生日期，計算實歲年齡。若尚未出生輸出 Invalid birth date，若年齡大於 130 歲輸出 Check birth date。

**English approach:** Compare dates: years diff = cur_y - birth_y. If cur_month < birth_month or (same month and cur_day < birth_day), decrement age.

**中文解題思路：** 實歲計算邏輯：年份相減，若當前月份未到生日月或同月但日期未達生日當天，則實歲減 1。檢測小於 0 與大於 130 歲邊界。 ==========================================================================


<a id="uva-11220_decoding-the-message"></a>

### UVa 11220 — Decoding the message.／破譯密碼訊息 (單字第k字母拼接)

- 原始碼：[11220_decoding-the-message.c](11220_decoding-the-message.c)
- 難度：Easy
- 演算法：string, parsing

**English description:** Decode hidden message from a sentence: the i-th word contributes its i-th character (1-based) if word is long enough.

**中文詳細描述：** 從句子中破譯隱藏文字：每句話中的第 i 個有效單字貢獻其第 i 個字母（下標從 1 起算），單字長度不足則跳過且下標不增加。

**English approach:** Tokenize sentence into words. Track target char index k (starts at 1). If word length >= k, append word[k-1] to decoded message and increment k.

**中文解題思路：** 將句子拆詞，維護當前字元下標 k=1，若當前單字長度 >= k，則提取第 k 個字母加入解碼結果並將 k 加 1。 ==========================================================================


<a id="uva-11221_magic-square-palindromes"></a>

### UVa 11221 — Magic square palindromes.／魔方回文

- 原始碼：[11221_magic-square-palindromes.c](11221_magic-square-palindromes.c)
- 難度：Easy
- 演算法：string, palindrome

**English description:** Determine if a cleaned sentence (letters only) forms an K x K magic square palindrome (reads same along rows and columns forward and backward).

**中文詳細描述：** 判斷去除標點符號後的純英文字串是否為 K x K 的魔方回文（水平與垂直正反讀皆完全一致）。

**English approach:** Filter out non-alpha chars. Check if length L is a perfect square K*K. If so, verify palindrome and symmetric grid transpose.

**中文解題思路：** 過濾純字母，檢查長度 L 是否為完全平方數 K*K，若是則驗證是否為回文且網格對稱。 ==========================================================================


<a id="uva-11222_only-i-did-it"></a>

### UVa 11222 — Only I did it!／唯我獨解！ (三方差集比較)

- 原始碼：[11222_only-i-did-it.c](11222_only-i-did-it.c)
- 難度：Easy
- 演算法：set-operations, simulation

**English description:** Find which friend(s) solved the maximum number of unique problems that no other friend solved.

**中文詳細描述：** 在三位朋友各自解決的題號清單中，找出解決最多其他兩人均未解出的「獨特題目」的人及題號。

**English approach:** Mark problem solved status with frequency array. Count problems with frequency == 1 for each friend. Output maximum.

**中文解題思路：** 用頻率數組統計每道題被幾個人解出，篩選出頻率剛好為 1 的題目，統計三人各自的獨特解題數並取最大者。 ==========================================================================


<a id="uva-11223_o-dah-dah-dah"></a>

### UVa 11223 — O: dah dah dah!／摩斯密碼解碼

- 原始碼：[11223_o-dah-dah-dah.c](11223_o-dah-dah-dah.c)
- 難度：Easy
- 演算法：string, morse-code

**English description:** Decode Morse code where '.' is dit, '-' is dah, single spaces separate letters, and double spaces separate words.

**中文詳細描述：** 解碼摩斯密碼：'.' 為短音，'-' 為長音，單一空格分隔字母，雙空格分隔單詞。

**English approach:** Split into words by double space. Split each word by single space into Morse tokens. Map Morse token to letter using lookup table.

**中文解題思路：** 依雙空格劃分單字，單空格劃分字母，以查表法將各摩斯編碼轉換為英文字母並輸出。 ==========================================================================


<a id="uva-11228_transportation-system"></a>

### UVa 11228 — Transportation system.／交通運輸系統

- 原始碼：[11228_transportation-system.c](11228_transportation-system.c)
- 難度：Medium
- 演算法：graph, mst, kruskal

**English description:** Given cities and distance threshold r, partition cities into states (components connected by dist <= r). Find number of states and road/railway lengths.

**中文詳細描述：** 給定城市座標與距離閥值 r，距離 <= r 的城市屬於同一個州。求州的數量以及鋪設公路與鐵路的總長度（最小生成樹）。

**English approach:** Build MST using Kruskal's algorithm. Edges with weight <= r are roads (and keep same state); edges > r are railways (connecting different states).

**中文解題思路：** 使用 Kruskal 演算法求最小生成樹：權重 <= r 的邊為公路，權重 > r 的邊為鐵路，大於 r 的邊數 + 1 即為州的數量。 ==========================================================================


<a id="uva-11231_black-and-white-painting"></a>

### UVa 11231 — Black and white painting／黑白棋盤格 8x8 棋盤子矩陣計數

- 原始碼：[11231_black-and-white-painting.c](11231_black-and-white-painting.c)
- 難度：UVa Star 1
- 演算法：math

**English description:** Count how many 8x8 standard chessboards (bottom-right square white) can be cut out of an n x m grid with top-left square colored c.

**中文詳細描述：** 在 n x m 的交錯黑白方格網中，計算有多少個 8x8 標準西洋棋盤 (右下角格子為白色) 可以被完整裁切出來。

**English approach:** Total 8x8 subgrids is (n - 7) * (m - 7). Exactly half of them end on white squares, plus c if the total product is odd.

**中文解題思路：** 總可裁切 8x8 區塊數為 (n - 7) * (m - 7)，其中剛好有一半右下角為白色，若乘積為奇數則加上底色偏移量 c。 ==========================================================================


<a id="uva-11233_deli-deli"></a>

### UVa 11233 — Deli Deli／外送菜單英語複數變形

- 原始碼：[11233_deli-deli.c](11233_deli-deli.c)
- 難度：Easy
- 演算法：string, rule-based-simulation

**English description:** Transform English nouns into their plural forms given an irregular dictionary and standard morphological rules.

**中文詳細描述：** 根據不規則名詞字典與標準英語複數形態規則，將單詞轉換為複數形。

**English approach:** Check irregular word dictionary first; else apply suffix rules: consonant+y -> ies, o/s/ch/sh/x -> es, otherwise append s.

**中文解題思路：** 先查不規則字典，若無則按字尾規則判定：子音+y 變 ies；o/s/ch/sh/x 結尾加 es；其餘加 s。 ==========================================================================


<a id="uva-11235_frequent-values"></a>

### UVa 11235 — Frequent values／區間最高頻率連續值統計

- 原始碼：[11235_frequent-values.c](11235_frequent-values.c)
- 難度：UVa Star 2
- 演算法：data-structures, rmq

**English description:** Given a non-decreasing sorted array, find the maximum frequency of any value in query range [L, R].

**中文詳細描述：** 給定一個非遞減排序整數陣列，求指定區間 [L, R] 內出現頻率最高之數值的出現次數。

**English approach:** Count frequencies of elements within the range [L, R] and return the maximum frequency.

**中文解題思路：** 在非遞減陣列中統計區間 [L, R] 內連續相同數值的最大連續長度並回傳。 ==========================================================================


<a id="uva-11236_grocery_store"></a>

### UVa 11236 — Grocery store／雜貨店四件商品總價與總乘積巧合

- 原始碼：[11236_grocery_store.c](11236_grocery_store.c)
- 難度：Medium
- 演算法：math, brute-force, pruning

**English description:** Find all combinations of 4 item prices a <= b <= c <= d in cents such that a+b+c+d == a*b*c*d / 10^6.

**中文詳細描述：** 求 4 個商品價格（分）使得四者之和等於四者相乘除以 10^6（即以元為單位的總和等於總乘積）。

**English approach:** Triple loop for a, b, c with strict bounds. Solve for d directly: d = (10^6 * S) / (P - 10^6). Verify d >= c and valid.

**中文解題思路：** 三重循環枚舉 a <= b <= c，由等式解出 d = (10^6 * S) / (P - 10^6)，檢查 d 是否整除且 d >= c 且總價 <= 2000。 ==========================================================================


<a id="uva-11239_open-source"></a>

### UVa 11239 — Open Source／開源專案選拔 (去重與跨專案除名)

- 原始碼：[11239_open-source.c](11239_open-source.c)
- 難度：Medium
- 演算法：string, sorting, hash

**English description:** Count registered students for open source projects. If a student signs up for multiple projects, disqualify that student from all projects.

**中文詳細描述：** 統計各開源專案的報名學生人數；若同一學生報名了超過一個專案，則該學生在所有專案中均被除名失效。

**English approach:** Maintain student map tracking which project(s) they registered for. Filter out students with > 1 project. Sort projects by count descending.

**中文解題思路：** 記錄每位學生報名的專案集合，標記多選學生為無效；統計各專案有效報名人數並按人數降序、專案名字典序排序。 ==========================================================================


<a id="uva-11242_tour-de-france"></a>

### UVa 11242 — Tour de France／環法自行車賽

- 原始碼：[11242_tour-de-france.c](11242_tour-de-france.c)
- 難度：Easy
- 演算法：sorting, simulation

**English description:** Given teeth count on front and rear sprockets of a bicycle, find the maximum ratio between adjacent drive ratios when sorted.

**中文詳細描述：** 給定自行車前齒輪與後齒輪的齒數，求所有齒輪比排序後，相鄰齒輪比之間的最大比值。

**English approach:** Generate all drive ratios r = rear / front. Sort them, and find max(r[i+1] / r[i]).

**中文解題思路：** 枚舉所有齒比 r = 後齒數 / 前齒數，排序後取相鄰兩齒比商的最大值。 ==========================================================================


<a id="uva-11244_counting-stars"></a>

### UVa 11244 — Counting Stars／夜空孤立星星計數

- 原始碼：[11244_counting-stars.c](11244_counting-stars.c)
- 難度：UVa Star 1
- 演算法：simulation, 2d-grid

**English description:** Count the number of lone stars ('*') in a sky grid that have no neighboring '*' in any of the 8 adjacent directions.

**中文詳細描述：** 在星空網格中統計孤立的星星 ('*') 數量：該星號周圍 8 個相鄰格子內均不得出現其他任何星號。

**English approach:** Scan each cell: if '*', inspect all 8 neighbors. If no neighbor is '*', increment lone star count.

**中文解題思路：** 雙重迴圈逐格檢查：遇到 '*' 則檢查周圍 8 個相鄰方向，若皆為 '.' 則此星星為孤立星，計數加一。 ==========================================================================


<a id="uva-11258_string_partition"></a>

### UVa 11258 — String Partition／字串分割求最大 32 位元整數總和

- 原始碼：[11258_string_partition.c](11258_string_partition.c)
- 難度：Medium
- 演算法：dynamic-programming, string

**English description:** Partition a digit string into integers each <= 2^31 - 1 (2147483647) such that their sum is maximized.

**中文詳細描述：** 將數字字串劃分成多個不超過 32 位元有號整數上限（2147483647）的整數，求劃分後整數總和的最大值。

**English approach:** 1D DP: dp[i] = max_{1 <= len <= 10}(dp[i - len] + val) where val <= 2147483647.

**中文解題思路：** 一維動態規劃：dp[i] 表示前 i 個數字的最大總和，枚舉最後一段長度 1~10，若其數值小於等於 2147483647 則進行轉移。 ==========================================================================


<a id="uva-11264_coin-collector"></a>

### UVa 11264 — Coin Collector／硬幣收藏家

- 原始碼：[11264_coin-collector.c](11264_coin-collector.c)
- 難度：Medium
- 演算法：greedy

**English description:** Find the maximum number of different coins that can be withdrawn from a bank given coins of strictly increasing denominations.

**中文詳細描述：** 給定嚴格遞增面額的硬幣，求最多可以同時取出多少種不同面額的硬幣。

**English approach:** Greedily take coin i if the current sum plus coin i is strictly less than coin i+1. Always take the last coin.

**中文解題思路：** 貪心法：若當前硬幣總和加上第 i 枚硬幣的面額嚴格小於第 i+1 枚硬幣面額，則選取第 i 枚；最後一枚必定選取。 ==========================================================================


<a id="uva-11286_conformity"></a>

### UVa 11286 — Conformity／選課組合人氣從眾指數統計

- 原始碼：[11286_conformity.c](11286_conformity.c)
- 難度：UVa Star 1
- 演算法：sorting, hash

**English description:** Given course combinations of 5 courses for N students, find the total number of students enrolled in the most popular combination(s).

**中文詳細描述：** 給定 N 名學生每人選修的 5 門課程編號，找出最受歡迎選課組合中的總修課學生人數。

**English approach:** Sort each student's 5 courses. Group identical sorted 5-tuples and count frequencies. Sum counts of combinations matching maximum frequency.

**中文解題思路：** 將每位學生的 5 門課排序，統計各組合出現之次數，找出最大頻率後，將所有達到此最大頻率的組合學生數加總。 ==========================================================================


<a id="uva-11292_dragon-of-loowater"></a>

### UVa 11292 — Dragon of Loowater／羅特瓦爾的巨龍與英勇騎士

- 原始碼：[11292_dragon-of-loowater.c](11292_dragon-of-loowater.c)
- 難度：UVa Star 1
- 演算法：greedy, sorting

**English description:** Each knight of height H can cut off a dragon head of diameter <= H and costs H gold. Find minimum gold to slay all heads or report doomed.

**中文詳細描述：** 身高為 H 的騎士能砍下直徑 <= H 的龍頭並索取 H 枚金幣。求砍下所有龍頭所需的最少金幣總額，若無法斬殺則輸出失敗。

**English approach:** Sort dragon heads and knight heights ascending. Greedily match each dragon head to the smallest knight whose height >= head diameter.

**中文解題思路：** 將龍頭直徑與騎士身高由小到大排序，貪婪地以可斬下龍頭之最小騎士依序迎戰，騎士用完仍有龍頭殘存則判為失敗。 ==========================================================================

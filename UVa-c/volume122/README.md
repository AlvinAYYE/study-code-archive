# UVa Volume 122

本卷收錄 9 份 C 解答，涵蓋 7 個 UVa 題號，以下依題號排序。

<a id="uva-12207_that-is-your-queue"></a>

### UVa 12207 — That is Your Queue／插隊隊列模擬 (雙端隊列/STL list)

- 原始碼：[12207_that-is-your-queue.c](12207_that-is-your-queue.c)
- 難度：Easy
- 演算法：data-structures, deque, simulation

**English description:** Simulate hospital queue of up to 1,000,000,000 citizens with commands: 'N' (serve front and move to back) and 'E x' (emergency expedite citizen x to front).

**中文詳細描述：** 模擬多達 10 億人的排隊隊列：'N' 表示叫號當前排頭並移到隊尾，'E x' 表示緊急情況將市民 x 插隊到最前排。

**English approach:** Since number of commands C <= 1000, only the first min(P, C) citizens can ever be served. Maintain a doubly linked list or deque of size <= 2000.

**中文解題思路：** 由於操作總數 C <= 1000，只有前 min(P, C) 個人可能被叫到。使用雙向鏈結串列或雙端隊列模擬即可。 ==========================================================================


<a id="uva-12210_a-match-making-problem"></a>

### UVa 12210 — A Match Making Problem／相親配對問題

- 原始碼：[12210_a-match-making-problem.c](12210_a-match-making-problem.c)
- 難度：Easy
- 演算法：greedy, sorting

**English description:** Given B bachelors and S spinsters with ages, match each bachelor with the spinster closest in age. If bachelors remain, report count and youngest age.

**中文詳細描述：** B 位單身漢與 S 位單身女子相親，每位單身漢配對年齡最相近的女性。若有單身漢剩餘，輸出剩餘人數與最年輕者的年齡。

**English approach:** If B <= S, all bachelors can be matched (0 left). If B > S, remaining count is B - S, and the youngest bachelor is always unmatched.

**中文解題思路：** 若 B <= S 則所有人皆可配對（剩餘 0 人）；若 B > S 則必定剩餘 B - S 人，且剩餘者中必包含最年輕的單身漢。 ==========================================================================


<a id="uva-12243_flowers-flourish-from-france"></a>

### UVa 12243 — Flowers Flourish from France／頭韻全字母吻合檢測

- 原始碼：[12243_flowers-flourish-from-france.c](12243_flowers-flourish-from-france.c)
- 難度：Easy
- 演算法：string

**English description:** Determine if a sentence is a tautogram (every word starts with the same letter, case-insensitive).

**中文詳細描述：** 判斷給定的句子是否為全頭韻句（每個單詞的首字母不分大小寫完全相同）。

**English approach:** Extract the first letter of each word and verify case-insensitively that all initial letters match.

**中文解題思路：** 提取每個單詞的第一個字母轉為小寫，檢查全句所有單詞首字母是否皆與第一個單詞一致。 ==========================================================================


<a id="uva-12247_jollo"></a>

### UVa 12247 — Jollo／紙牌博弈

- 原始碼：[12247_jollo.c](12247_jollo.c)
- 難度：Easy
- 演算法：game-theory, simulation, greedy

**English description:** Prince and Princess each hold 3 cards (1 to 52). Prince has 2 revealed. Find lowest card for Prince's 3rd card to guarantee victory.

**中文詳細描述：** 王子與公主各拿 3 張牌比大小，已知公主 3 張牌與王子 2 張牌，求王子第 3 張牌取何值時能確保 3 局 2 勝。

**English approach:** Princess's cards are known. Try each available card x from 1 to 52 for Prince's 3rd card. Simulate all 6 matchups to verify guaranteed win.

**中文解題思路：** 枚舉王子第 3 張牌的可能數值（1~52 中未出現者），模擬公主最優出牌情況下王子能否必勝，輸出最小值。 ==========================================================================


<a id="uva-12250_language-detection"></a>
### UVa 12250 — Language Detection／語言偵測

- 原始碼：[12250_language-detection.c](12250_language-detection.c)
- 演算法：字串比對（String Matching）

**English description:**

Read greeting words until `#`. Match each greeting against the known words for English, Spanish, German, French, Italian, and Russian, then output the detected language or `UNKNOWN` with its case number.

**中文詳細描述：**

逐行讀入問候語，遇到 `#` 結束。把字串與六種已知問候語精確比對，分別判定英文、西班牙文、德文、法文、義大利文或俄文；無法辨識時輸出 `UNKNOWN`，並附案例編號。

<a id="uva-12250_language-detection-pr"></a>

### UVa 12250 — Language Detection／各國問候語語言檢測

- 原始碼：[12250_language-detection-pr.c](12250_language-detection-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：string, simulation

**English description:** Identify language of greeting string: HELLO->ENGLISH, HOLA->SPANISH, HALLO->GERMAN, BONJOUR->FRENCH, CIAO->ITALIAN, ZDRAVSTVUJTE->RUSSIAN.

**中文詳細描述：** 依據輸入的問候語判定所屬語言 (英文、西班牙文、德文、法文、義大利文、俄文，其餘輸出 UNKNOWN)。

**English approach:** String comparison with standard greeting dictionary.

**中文解題思路：** 以 strcmp 逐一比對 6 種標準問候語，匹配成功輸出對應語言名稱，否則輸出 UNKNOWN。 ==========================================================================


<a id="uva-12279_emogle-balance"></a>
### UVa 12279 — EMOOGLE BALANCE／Emoogle 平衡值

- 原始碼：[12279_emogle-balance.c](12279_emogle-balance.c)
- 演算法：計數模擬（Simulation）

**English description:**

Each data set contains event values where zero denotes a treat and a positive value denotes a reason to give treats. Compute the balance as the number of positive values minus the number of zeros and output it for each case.

**中文詳細描述：**

每組輸入是一串事件值，其中 0 代表送出禮物的事件，正數代表收到理由或需求的事件。分別統計正數與 0 的個數，以前者減後者得到 Emoogle balance，最後依案例格式輸出。

<a id="uva-12289_one-two-three"></a>
### UVa 12289 — One-Two-Three／一二三

- 原始碼：[12289_one-two-three.c](12289_one-two-three.c)
- 演算法：字串長度、錯字比對（String）

**English description:**

Each input word represents `one`, `two`, or `three` with at most one incorrect character. Determine the intended word and output its numeric value 1, 2, or 3.

**中文詳細描述：**

每組輸入是一個英文數字單字，但最多可能有一個字元錯誤。長度為 5 時可判定為 `three`；長度為 3 時，比較它和 `one` 的相同位置，至多一處不同便輸出 1，否則輸出 2。

<a id="uva-12289_one-two-three-pr"></a>

### UVa 12289 — One-Two-Three／辨識被塗抹的數字單字 (one, two, three)

- 原始碼：[12289_one-two-three-pr.c](12289_one-two-three-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：string

**English description:** Identify number word (one, two, three) where at most one letter is incorrectly recognized.

**中文詳細描述：** 幼童寫下的數字英文單字 (one, two, three) 最多有一個字母被寫錯，辨識其原本所代表的數字 1, 2, 3。

**English approach:** If length is 5, it must be 'three' (3). If length is 3, count matching characters with 'one'; if >= 2 it's 1, else 2.

**中文解題思路：** 長度為 5 必為 3。長度為 3 則比對與 "one" 相同的字元數：若 >= 2 則為 1，否則為 2。 ==========================================================================

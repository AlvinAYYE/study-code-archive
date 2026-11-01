# UVa Volume 130

本卷收錄 6 份 C 解答，涵蓋 4 個 UVa 題號，以下依題號排序。

<a id="uva-13012_identifying-tea"></a>
### UVa 13012 — Identifying tea／辨識茶葉

- 原始碼：[13012_identifying-tea.c](13012_identifying-tea.c)
- 演算法：線性計數（Simulation）

**English description:**

The input gives the correct tea type followed by five contestants' guesses. Count how many guesses equal the correct type and output that count.

**中文詳細描述：**

每筆輸入先給正確的茶葉種類編號，再給五位參賽者各自的猜測。逐一比較猜測與正確編號，統計相同者的人數並輸出。

<a id="uva-13012_identifying-tea-pr"></a>

### UVa 13012 — Identifying tea／盲測盲品茶葉猜中人數統計

- 原始碼：[13012_identifying-tea-pr.c](13012_identifying-tea-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：simulation

**English description:** Given correct tea type T and 5 contestants' answers, count how many contestants guessed correctly.

**中文詳細描述：** 盲測品茶：已知正確茶葉編號 T，統計 5 位參賽選手中有多少人猜中了正確編號。

**English approach:** Count matching answers among 5 inputs equal to T.

**中文解題思路：** 遍歷 5 位選手的回答，每當數值等於正確編號 T 則計數加 1。 ==========================================================================


<a id="uva-13025_back-to-the-past"></a>

### UVa 13025 — Back to the Past／重返過去指定歷史星期日期輸出

- 原始碼：[13025_back-to-the-past.c](13025_back-to-the-past.c)
- 難度：UVa Star 1
- 演算法：basics

**English description:** Output the fixed date 'May 29, 2013 Wednesday' corresponding to the inaugural contest date.

**中文詳細描述：** 直接印出指定歷史日期 "May 29, 2013 Wednesday"。

**English approach:** Return constant formatted string directly.

**中文解題思路：** 依據題意回傳固定常數字串 "May 29, 2013 Wednesday"。 ==========================================================================


<a id="uva-13034_solve-everything"></a>
### UVa 13034 — Solve Everything :-)／解決所有問題

- 原始碼：[13034_solve-everything.c](13034_solve-everything.c)
- 演算法：全稱條件檢查（Simulation）

**English description:**

Read the solved-count values for all 13 contest problems. Output `Yes` only when every value is positive, indicating that every problem was solved at least once; otherwise output `No`.

**中文詳細描述：**

輸入 13 個整數，分別表示比賽中每題被解出的次數。只有當 13 個值全都大於 0，也就是每題至少有人解出時輸出 `Yes`；只要存在 0 就輸出 `No`。

<a id="uva-13034_solve-everything-pr"></a>

### UVa 13034 — Solve Everything?!／全部解出？！(各題解出數大於零判定)

- 原始碼：[13034_solve-everything-pr.c](13034_solve-everything-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：simulation

**English description:** Check if team solved at least one question in each of the 13 problem sets.

**中文詳細描述：** 評判隊伍是否在 13 道題目中每一題皆至少解出了一次 (即 13 個數值皆 > 0)。

**English approach:** Verify all 13 integers are strictly positive (> 0).

**中文解題思路：** 檢查輸入的 13 個整數：若全部皆大於 0 輸出 Yes，只要有任一題解出數為 0 則輸出 No。 ==========================================================================


<a id="uva-13059_tournament"></a>

### UVa 13059 — Tournament／單淘汰錦標賽總比賽場次

- 原始碼：[13059_tournament.c](13059_tournament.c)
- 難度：UVa Star 1
- 演算法：math

**English description:** Find total matches played in single-elimination tournament of N players until one champion remains.

**中文詳細描述：** N 名選手進行單淘汰錦標賽，每場比賽淘汰 1 人，直到決出唯一的冠軍，求總共需進行幾場比賽。

**English approach:** Each match eliminates exactly 1 player. To eliminate N - 1 players, exactly N - 1 matches are played.

**中文解題思路：** 每場淘汰賽必有且僅有 1 位淘汰者。要從 N 人決出 1 位冠軍需淘汰 N - 1 人，比賽總場次恆為 N - 1。 ==========================================================================

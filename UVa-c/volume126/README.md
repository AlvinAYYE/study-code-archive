# UVa Volume 126

本卷共收錄 3 題 C 題目檔，以下依題號排序。

<a id="uva-12602_nice-licence-plates"></a>
### UVa 12602 — Nice Licence Plates／漂亮車牌

- 原始碼：[12602_nice-licence-plates.c](12602_nice-licence-plates.c)
- 演算法：字串解析、26 進位（String, Math）

**English description:**

Each plate has the form `LLL-DDDD`. Interpret the three letters as a base-26 value with `A = 0`, compare it with the four-digit decimal value, and output `nice` when the absolute difference is at most 100; otherwise output `not nice`.

**中文詳細描述：**

每組輸入是一個 `LLL-DDDD` 格式的車牌。將前三個英文字母以 `A=0` 解讀成 26 進位數，再與後四位十進位數字比較；兩者差的絕對值不超過 100 時輸出 `nice`，否則輸出 `not nice`。

<a id="uva-12650_dangerous-dive"></a>
### UVa 12650 — Dangerous Dive／危險潛水

- 原始碼：[12650_dangerous-dive.c](12650_dangerous-dive.c)
- 演算法：布林標記、缺項搜尋（Array, Simulation）

**English description:**

The input gives `N` divers numbered from 1 to `N`, followed by the identifiers of the `R` divers who returned. Output all missing identifiers in increasing order, or `*` if everyone returned.

**中文詳細描述：**

每組輸入表示共有編號 1 到 `N` 的潛水員，接著列出已返回的 `R` 人編號。用布林陣列標記返回者，依編號遞增輸出所有未返回的人；若全部返回，則輸出 `*`。

<a id="uva-12696_cabin-baggage"></a>
### UVa 12696 — Cabin Baggage／隨身行李

- 原始碼：[12696_cabin-baggage.c](12696_cabin-baggage.c)
- 演算法：複合條件判斷（Simulation）

**English description:**

For each bag, determine acceptance from its length, width, depth, and weight. Weight must not exceed 7.0, and either all individual dimension limits must hold or the three dimensions must sum to at most 125; output each decision and the total accepted count.

**中文詳細描述：**

每件行李輸入長、寬、深與重量。重量必須不超過 7.0，尺寸則需同時符合長不超過 56、寬不超過 45、深不超過 25，或三邊總和不超過 125；逐件輸出是否合格，最後再輸出通過總數。

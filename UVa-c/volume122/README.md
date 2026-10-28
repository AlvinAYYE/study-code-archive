# UVa Volume 122

本卷共收錄 3 題 C 題目檔，以下依題號排序。

<a id="uva-12250_language-detection"></a>
### UVa 12250 — Language Detection／語言偵測

- 原始碼：[12250_language-detection.c](12250_language-detection.c)
- 演算法：字串比對（String Matching）

**English description:**

Read greeting words until `#`. Match each greeting against the known words for English, Spanish, German, French, Italian, and Russian, then output the detected language or `UNKNOWN` with its case number.

**中文詳細描述：**

逐行讀入問候語，遇到 `#` 結束。把字串與六種已知問候語精確比對，分別判定英文、西班牙文、德文、法文、義大利文或俄文；無法辨識時輸出 `UNKNOWN`，並附案例編號。

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

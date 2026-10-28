# UVa Volume 124

本卷共收錄 2 題 C 題目檔，以下依題號排序。

<a id="uva-12403_save-setu"></a>
### UVa 12403 — Save Setu／拯救 Setu

- 原始碼：[12403_save-setu.c](12403_save-setu.c)
- 演算法：累加模擬（Simulation）

**English description:**

Process a sequence of commands. A `donate K` command adds `K` to the current fund, while a `report` command asks for the current total; output the total for every report.

**中文詳細描述：**

輸入包含一連串指令，基金初始為 0。遇到 `donate K` 時把金額 `K` 加入累計總額；遇到 `report` 時輸出目前累積的捐款金額，依序處理所有指令。

<a id="uva-12468_zapping"></a>
### UVa 12468 — Zapping／轉台

- 原始碼：[12468_zapping.c](12468_zapping.c)
- 演算法：環狀距離（Math）

**English description:**

Television channels are numbered 0 through 99 in a cycle. For each starting and target channel until the terminating pair, output the minimum number of up or down button presses needed to reach the target.

**中文詳細描述：**

電視頻道編號為 0 到 99，按到端點後會環狀接回另一端。每筆輸入給目前頻道與目標頻道，直到終止資料；比較直接距離 `|a-b|` 與繞回距離 `100-|a-b|`，輸出較小的按鍵次數。

# UVa Volume 119

本卷共收錄 1 題 C 題目檔，以下依題號排序。

<a id="uva-11984_a-change-in-thermal-unit"></a>
### UVa 11984 — A Change in Thermal Unit／溫度單位變化

- 原始碼：[11984_a-change-in-thermal-unit.c](11984_a-change-in-thermal-unit.c)
- 演算法：單位換算（Math）

**English description:**

Each case gives an initial Celsius temperature `C` and an increase `d` measured in Fahrenheit degrees. Convert only the temperature difference to Celsius, add it to `C`, and output the final Celsius temperature.

**中文詳細描述：**

每組輸入給初始攝氏溫度 `C`，以及以華氏「溫差」表示的增加量 `d`。溫差換算不需加減 32，只要計算 `d × 5/9`，再加回 `C`，最後依指定精度輸出新的攝氏溫度。

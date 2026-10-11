# C 程式設計教材整理版

本文件由同資料夾中的三份 HTML 教材轉換而成，方便以 Markdown 閱讀與搜尋。程式碼以 fenced code block 呈現；原始 HTML 保持不變。

---

## 教材目錄

[完整主題目錄：依章節查閱所有範例、投影片講義與測試資料](教材目錄.md)

- [CH1–4：完整案例實作手冊](#toc-chapter-ch1)
- [CH5–7：完整案例實作手冊](#toc-chapter-ch5)
- [CH8、CH22、CH24：完整範例互動教材](#toc-chapter-ch8)

---


<a id="toc-chapter-ch1"></a>

# CH1–4：完整案例實作手冊

來源：`CH1-4_完整程式碼與解題說明.html`

C PROGRAMMING / CHAPTERS 1–4 HANDBOOK

# 從完整題目開始，把解題思路落實成可測試的程式。

保留第 1–4 章原稿的所有範例，依題目、解題說明、完整程式及測試資料分區閱讀；版型與操作方式統一為第 5–7 章手冊。

**53**完整原稿範例

**53**可獨立編譯的 C 程式

**133**完整輸入／輸出測試資料

**122**原稿標示的對照投影片頁數

**本次 Linux 原稿資料重跑**GCC 133/133Clang 133/133GCC + UBSan 133/133[判準與觀察值限制 →](#guide)

**01先看完整題目**保留原題情境、輸入與限制、輸出規格，並呈現原稿測試範例。

**02理解解題過程**沿用原稿三步思考與解題示例，可逐步標記重點。

**03編譯並核對測試**完整程式、原稿輸出與結束碼，可分別複製或下載。

**內容保留：**原有 53 題的題目、解法、程式與 133 組資料均保留；E01–E53 對應原稿閱讀順序，不重新編排檔名。五個主題群組只供介面篩選，不另推定原始章節邊界。
**適用範圍：**原稿的平台前提、刻意警告及「原稿與新增內容的界線」逐題保留。

## 全部實作主題

53 / 53 個主題

沒有符合條件的主題。

[E01原稿範例入門與基本元素

### 分辨三類錯誤並執行修正版

用漏分號、整數除法與格式型別不符三例，建立「先分類、再修正」流程。

16\_diagnostics\_safe.c

1 份完整程式 · 1 組原稿測試↗](#ex-16)[E02原稿範例入門與基本元素

### 建立並執行第一支 C 程式

將一個 .c 原始檔建置成執行檔，執行後輸出一行問候文字。

01\_hello.c

1 份完整程式 · 1 組原稿測試↗](#ex-1)[E03原稿範例入門與基本元素

### 以名稱與註解表達計算意圖

用合法識別字、巨集及註解完成31分鐘的單位數計算。

17\_naming.c

1 份完整程式 · 1 組原稿測試↗](#ex-17)[E04原稿範例入門與基本元素

### 觀察型別與實作範圍

建立int、float、double三種資料，並查看本機int上下界。

18\_basic\_types.c

1 份完整程式 · 1 組原稿測試↗](#ex-18)[E05原稿範例入門與基本元素

### 安全觀察初始化與賦值

依原例 int height, length, width=10，追蹤每個變數何時才可讀。

19\_initialization.c

1 份完整程式 · 1 組原稿測試↗](#ex-19)[E06原稿範例入門與基本元素

### 用中間值追蹤體積計算

計算12×10×8，再改高為9，觀察已存下的volume是否自動更新。

20\_volume\_flow.c

1 份完整程式 · 1 組原稿測試↗](#ex-20)[E07原稿範例入門與基本元素

### 計算包裹的材積重量

讀入長、寬、高，依教材係數將體積換算為向上取整的材積重量。

02\_dweight.c

1 份完整程式 · 7 組原稿測試↗](#ex-2)[E08原稿範例入門與基本元素

### 驗證整數向上取整的邊界

以固定除數166比較直接除法與向上取整公式。

21\_ceiling\_division.c

1 份完整程式 · 8 組原稿測試↗](#ex-21)[E09原稿範例入門與基本元素

### 比較巨集有無括號的結果

對照3乘BASE的兩種替換方式，並驗證具名材積常數。

22\_macro\_parentheses.c

1 份完整程式 · 1 組原稿測試↗](#ex-22)[E10原稿範例入門與基本元素

### 華氏溫度轉攝氏溫度

依 C = (F − 32) × (5/9) 計算攝氏；除法發生前必須使用浮點型別。

03\_celsius.c

1 份完整程式 · 9 組原稿測試↗](#ex-3)[E11原稿範例入門與基本元素

### 驗證基本元素的四題檢核

用可執行結果確認初始化、除法、巨集；建置流程以文字作答。

23\_quiz\_basics.c

1 份完整程式 · 1 組原稿測試↗](#ex-23)[E12原稿範例格式化輸入輸出

### 讓格式與數值一一配對

輸出quantity=3與temperature=26.75，依序使用整數及一位小數格式。

24\_printf\_contract.c

1 份完整程式 · 1 組原稿測試↗](#ex-24)[E13原稿範例格式化輸入輸出

### 依資料型別選擇 printf 規格

將原表中的int、unsigned、字元、浮點與字串各印一次。

25\_printf\_types.c

1 份完整程式 · 1 組原稿測試↗](#ex-25)[E14原稿範例格式化輸入輸出

### 比較欄寬、精度與浮點格式

對同一整數及同一浮點值，觀察不同格式如何改變顯示，而不改變儲存值。

04\_printf\_formats.c

1 份完整程式 · 1 組原稿測試↗](#ex-4)[E15原稿範例格式化輸入輸出

### 製作感測器數值報表

將兩筆假設量測值輸出成名稱、固定小數與科學記號三欄。

05\_sensor\_report.c

1 份完整程式 · 1 組原稿測試↗](#ex-5)[E16原稿範例格式化輸入輸出

### 控制字串截取與動態欄寬

分別顯示SENSOR前四個ASCII字元，以及由參數控制寬度與精度的3.5。

26\_dynamic\_format.c

1 份完整程式 · 1 組原稿測試↗](#ex-26)[E17原稿範例格式化輸入輸出

### 輸出引號、反斜線與換行

用跳脫序列印出原案例的引號文字與Windows風格路徑。

27\_escape\_sequences.c

1 份完整程式 · 1 組原稿測試↗](#ex-27)[E18診斷對照格式化輸入輸出

### 區分多給參數與危險格式錯誤

只執行原表中可定義的多餘參數例，再用不同變數觀察其求值。

28\_printf\_extra\_args.c

1 份完整程式 · 1 組原稿測試↗](#ex-28)[E19原稿範例格式化輸入輸出

### 正確讀取 float 與 double

各讀一個浮點數，配對目標物件型別，再以printf輸出。

29\_scan\_value\_address.c

1 份完整程式 · 4 組原稿測試↗](#ex-29)[E20原稿範例格式化輸入輸出

### 逐項解析沒有空白的數字串

使用 %d%d%f%f 讀四個數字，再觀察下一個未消耗的字元。

06\_scan\_stream.c

1 份完整程式 · 5 組原稿測試↗](#ex-6)[E21原稿範例格式化輸入輸出

### 觀察 scanf 部分成功後的狀態

讀取三個整數；故意讓第二項失敗，確認哪些變數已改、哪些仍保留初值。

07\_scan\_failure.c

1 份完整程式 · 4 組原稿測試↗](#ex-7)[E22原稿範例格式化輸入輸出

### 重現五組分隔符匹配實驗

用固定字串重現原表五組scanf格式的成功項數，避免互相消耗同一輸入。

30\_scan\_delimiters.c

1 份完整程式 · 1 組原稿測試↗](#ex-30)[E23原稿範例格式化輸入輸出

### 比較 %c 與前導空白的讀取

先讀一個整數，再讀一個原始字元與一個跳過空白的字元。

08\_scan\_char.c

1 份完整程式 · 4 組原稿測試↗](#ex-8)[E24原稿範例格式化輸入輸出

### 親自觀察尾端空白指令的等待

分兩階段讀取：第一個%d立即結束；第二個%d\n需繼續看到非空白或EOF。

31\_scan\_trailing\_space.c

1 份完整程式 · 3 組原稿測試↗](#ex-31)[E25原稿範例格式化輸入輸出

### 將兩個分數相加且不先約分

保留整數分子與分母，透過交叉相乘計算和；不先做整數除法。

09\_fractions.c

1 份完整程式 · 8 組原稿測試↗](#ex-9)[E26原稿範例格式化輸入輸出

### 用小實驗驗證四題格式化檢核

將欄寬、分隔符失敗、剩餘換行與double輸入分成四個互不干擾的測試。

32\_quiz\_io.c

1 份完整程式 · 1 組原稿測試↗](#ex-32)[E27原稿範例運算式與狀態

### 拆解一元與二元運算

為原式−a+b×2指定小整數，分別輸出子式與整體結果。

33\_unary\_binary.c

1 份完整程式 · 1 組原稿測試↗](#ex-33)[E28原稿範例運算式與狀態

### 比較兩筆量測值的平均

計算80與81的平均，對照整數除法及在除法前引入浮點數。

34\_average\_division.c

1 份完整程式 · 1 組原稿測試↗](#ex-34)[E29原稿範例運算式與狀態

### 驗證正負整數的商與餘數

列出17與3的四種正負組合，驗證a=(a/b)×b+a%b。

35\_quotient\_remainder.c

1 份完整程式 · 1 組原稿測試↗](#ex-35)[E30原稿範例運算式與狀態

### 把總秒數拆成時、分、秒

將非負持續秒數拆成完整小時、剩餘分鐘與秒數。

10\_duration.c

1 份完整程式 · 9 組原稿測試↗](#ex-10)[E31原稿範例運算式與狀態

### 比較括號改變前後的運算樹

對同一組a、b、c，計算a+b\*c與(a+b)\*c。

36\_precedence.c

1 份完整程式 · 1 組原稿測試↗](#ex-36)[E32原稿範例運算式與狀態

### 用括號驗證結合性

驗證連續減法、乘除以及連鎖賦值的語法分組。

37\_associativity.c

1 份完整程式 · 1 組原稿測試↗](#ex-37)[E33診斷對照運算式與狀態

### 追蹤連鎖賦值的型別轉換

執行f=i=33.3f，觀察內層賦值先轉int後提供什麼值。

38\_assignment\_value.c

1 份完整程式 · 1 組原稿測試↗](#ex-38)[E34原稿範例運算式與狀態

### 辨識可修改的賦值目標

只執行合法的i=3；將常數、運算結果及const目標反例作文字分類。

39\_lvalue\_safe.c

1 份完整程式 · 1 組原稿測試↗](#ex-39)[E35原稿範例運算式與狀態

### 追蹤庫存與複合賦值

先處理42件庫存的售出與補貨，再比較\*=分組、+=與=+。

40\_compound\_assignment.c

1 份完整程式 · 1 組原稿測試↗](#ex-40)[E36原稿範例運算式與狀態

### 分開觀察遞增的值與狀態

兩次都從i=1開始，分別執行x=++i與x=i++。

41\_pre\_post\_increment.c

1 份完整程式 · 1 組原稿測試↗](#ex-41)[E37原稿範例運算式與狀態

### 追蹤三組獨立的遞增運算式

對三組表格範例分別重設 i=1、j=2，再算 k 與最後狀態。

11\_expression\_trace.c

1 份完整程式 · 1 組原稿測試↗](#ex-11)[E38原稿範例運算式與狀態

### 逐層解出複合運算式

依原初值計算a=b+=c++−d+--e/−f，再列出六個變數。

53\_complex\_expression.c

1 份完整程式 · 1 組原稿測試↗](#ex-53)[E39原稿範例運算式與狀態

### 分開驗證分組與人為指定順序

對(a+b)\*(c-d)選定無衝突小整數，計算直接式及兩種明確分步版本。

42\_grouping\_order.c

1 份完整程式 · 1 組原稿測試↗](#ex-42)[E40原稿範例運算式與狀態

### 將四種語言行為分開說明

用實作範圍與無衝突運算實測，其他兩類只保留分類，不執行非法或未定義程式。

43\_behavior\_classes.c

1 份完整程式 · 1 組原稿測試↗](#ex-43)[E41原稿範例運算式與狀態

### 把衝突副作用改成明確步驟

依「先用舊a計算b，再改a」的新明確意圖，重寫原反例。

15\_safe\_rewrite.c

1 份完整程式 · 1 組原稿測試↗](#ex-15)[E42診斷對照運算式與狀態

### 正確檢查分數是否在範圍內

比較正確的0<=score && score<=100與原頁的連寫不等式。

44\_relational\_logical.c

1 份完整程式 · 6 組原稿測試↗](#ex-44)[E43原稿範例運算式與狀態

### 用短路規則保護除法

對原防護式測分母為0、商大於3及不大於3的三種情況。

45\_short\_circuit.c

1 份完整程式 · 1 組原稿測試↗](#ex-45)[E44原稿範例運算式與狀態

### 分辨逗號運算子與參數分隔符

執行j=(i++,i+10)，再於另一個printf使用正常參數分隔符。

46\_comma\_operator.c

1 份完整程式 · 1 組原稿測試↗](#ex-46)[E45診斷對照運算式與狀態

### 比較只計算與真的更新

從i=10開始，分別觀察i+1、i+=1、i=i+1是否改變物件。

47\_expression\_statement.c

1 份完整程式 · 1 組原稿測試↗](#ex-47)[E46原稿範例綜合實作與檢核

### 由 UPC 前十一位計算檢查碼

依原案例的奇偶位置加權規則，計算第十二位應補上的數字。

12\_upc.c

1 份完整程式 · 9 組原稿測試↗](#ex-12)[E47原稿範例綜合實作與檢核

### 用零加權和檢查 UPC 公式

分別對total=45、0、58比較原公式與投影片修正版。

48\_upc\_boundary.c

1 份完整程式 · 1 組原稿測試↗](#ex-48)[E48原稿範例綜合實作與檢核

### 修正平均值程式的三個問題

修正整數除法、printf格式與scanf目標型別配對，再執行驗證。

49\_debug\_io\_fixed.c

1 份完整程式 · 3 組原稿測試↗](#ex-49)[E49原稿範例綜合實作與檢核

### 計算以半小時為單位的停車費

每開始30分鐘收20元，0分鐘不收費；將規格轉為可測試公式。

13\_parking.c

1 份完整程式 · 12 組原稿測試↗](#ex-13)[E50診斷對照綜合實作與檢核

### 驗證可計算的總檢核答案

用固定測試核對停車費、double讀入及多餘參數；未定義反例只分類。

50\_quiz\_integrated.c

1 份完整程式 · 1 組原稿測試↗](#ex-50)[E51原稿範例附錄與延伸觀察

### 觀察 scanf 星號的抑制賦值

讀兩個整數但只保存第二個，對照printf星號的完全不同用途。

51\_scan\_suppression.c

1 份完整程式 · 4 組原稿測試↗](#ex-51)[E52原稿範例附錄與延伸觀察

### 觀察數值跳脫序列的邊界

在ASCII相容執行字元集上，輸出八進位A與明確截斷的十六進位AB。

52\_numeric\_escapes.c

1 份完整程式 · 1 組原稿測試↗](#ex-52)[E53原稿範例附錄與延伸觀察

### 用不同進位顯示同一個值

觀察十進位、十六進位、八進位與十六進位浮點輸出。

14\_format\_extras.c

1 份完整程式 · 1 組原稿測試↗](#ex-14)

### 帶走完整實作資源

含53份原始C程式、133組原稿測試、本次重跑工具與編譯紀錄。

E01原稿範例入門與基本元素CH1–4


<a id="toc-ch1-01"></a>

# 分辨三類錯誤並執行修正版

16\_diagnostics\_safe.c1 組原稿測試

**原稿索引：**16\_diagnostics\_safe.c　原檔：4　新版：題目 6 / 講解 7
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-16/problem)[02 解題說明](#ex-16/solution)[03 完整程式](#ex-16/code)[04 測試資料](#ex-16/tests)[05 來源與提醒](#ex-16/tips)

01

## 完整題目

先確認規格，再寫程式

用漏分號、整數除法與格式型別不符三例，建立「先分類、再修正」流程。

### 輸入與限制

固定 n=3；不需輸入；不可執行的反例只放註解。

### 應產生的輸出

n=3、兩種比例的差異、正確浮點输出。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 範例輸出

```
n=3
integer scale=0.000000
floating scale=0.555556
correct floating value=3.0
```

78 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

先補齊語法：宣告末尾加分號，讓程式能完成編譯。

**STEP 02**

保留合法但不合題意的 5/9，與 5.0/9.0 比較。

**STEP 03**

printf 的格式要配資料型別；錯誤 %f/int 反例不執行。

### 原稿解題示例

5/9 → 0.000000；5.0/9.0 → 0.555556

03

## 完整程式碼

每份程式均有獨立 main

16\_diagnostics\_safe.c

完整程式 · 20 行 · 內容與原稿逐字相同

```
/* 16_diagnostics_safe.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 4.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>

int main(void)
{
    /* Syntax counterexample: int n = 3   (missing semicolon) */
    int n = 3;
    double integer_scale = 5 / 9;
    double floating_scale = 5.0 / 9.0;
    printf("n=%d\n", n);
    printf("integer scale=%.6f\n", integer_scale);
    printf("floating scale=%.6f\n", floating_scale);
    /* Undefined counterexample: printf("%f", 3); */
    printf("correct floating value=%.1f\n", 3.0);
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/16_diagnostics_safe.c -o example`

04


## 測試資料

1 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E01-T01**1. 測試1**原稿測試 · 0 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿完整預期輸出

```
n=3
integer scale=0.000000
floating scale=0.555556
correct floating value=3.0
```

78 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

原第4頁是分類反例；本次新增完整安全對照程式。漏分號與不匹配格式僅留註解，不冒稱原樣可執行。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← 回到全部主題](#overview)[E02 建立並執行第一支 C 程式 →](#ex-1)

E02原稿範例入門與基本元素CH1–4


<a id="toc-ch1-02"></a>

# 建立並執行第一支 C 程式

01\_hello.c1 組原稿測試

**原稿索引：**01\_hello.c　原檔：5, 6　新版：題目 8 / 講解 9, 10
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-1/problem)[02 解題說明](#ex-1/solution)[03 完整程式](#ex-1/code)[04 測試資料](#ex-1/tests)[05 來源與提醒](#ex-1/tips)

01

## 完整題目

先確認規格，再寫程式

將一個 .c 原始檔建置成執行檔，執行後輸出一行問候文字。

### 輸入與限制

不需輸入；使用 hosted C 環境。

### 應產生的輸出

Hello, C!，接著換行。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 範例輸出

```
Hello, C!
```

10 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

先準備入口：加入 stdio.h，定義 int main(void)。

**STEP 02**

將輸出放在 main：printf 印字串，\n 結束該行。

**STEP 03**

分開檢查建置與執行：成功編譯後才執行產生的檔案。

### 原稿解題示例

執行 → Hello, C!

03

## 完整程式碼

每份程式均有獨立 main

01\_hello.c

完整程式 · 12 行 · 內容與原稿逐字相同

```
/* 01_hello.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 5, 6.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>

int main(void)
{
    printf("Hello, C!\n");
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/01_hello.c -o example`

04


## 測試資料

1 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E02-T01**1. 測試1**原稿測試 · 0 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿完整預期輸出

```
Hello, C!
```

10 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

原第5頁用 hello.c 示意工具鏈；本包統一實際檔名為 01\_hello.c。保留原第6頁程式本體。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E01 分辨三類錯誤並執行修正版](#ex-16)[E03 以名稱與註解表達計算意圖 →](#ex-17)

E03原稿範例入門與基本元素CH1–4


<a id="toc-ch1-03"></a>

# 以名稱與註解表達計算意圖

17\_naming.c1 組原稿測試

**原稿索引：**17\_naming.c　原檔：7　新版：題目 11 / 講解 12
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-17/problem)[02 解題說明](#ex-17/solution)[03 完整程式](#ex-17/code)[04 測試資料](#ex-17/tests)[05 來源與提醒](#ex-17/tips)

01

## 完整題目

先確認規格，再寫程式

用合法識別字、巨集及註解完成31分鐘的單位數計算。

### 輸入與限制

固定 n=31；新增 total\_count 初值0。

### 應產生的輸出

MAX\_COUNT=30、blocks=2、total\_count=2。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 範例輸出

```
MAX_COUNT=30 blocks=2 total_count=2
value=3.5
```

46 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

選能代表資料的名稱，避免把減號或空白塞入識別字。

**STEP 02**

用巨集命名30；以註解說明未滿一單位仍需進位。

**STEP 03**

保留完整 token，輸出中間結果以核對名稱與資料。

### 原稿解題示例

31 → (31+29)/30 → 2 blocks

03

## 完整程式碼

每份程式均有獨立 main

17\_naming.c

完整程式 · 21 行 · 內容與原稿逐字相同

```
/* 17_naming.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 7.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>
#define MAX_COUNT 30

int main(void)
{
    int total_count = 0;
    int n = 31;
    float value = 3.5f; /* The token float must not be split. */
    // Round up partial blocks.
    int blocks = (n + MAX_COUNT - 1) / MAX_COUNT;
    total_count += blocks;
    printf("MAX_COUNT=%d blocks=%d total_count=%d\n", MAX_COUNT, blocks, total_count);
    printf("value=%.1f\n", value);
    /* Invalid tokens are not executed: fl oat value; */
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/17_naming.c -o example`

04


## 測試資料

1 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E03-T01**1. 測試1**原稿測試 · 0 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿完整預期輸出

```
MAX_COUNT=30 blocks=2 total_count=2
value=3.5
```

46 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

原頁是分散片段；本次用固定n=31與value=3.5f接成微型實驗，這些固定值是新增。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E02 建立並執行第一支 C 程式](#ex-1)[E04 觀察型別與實作範圍 →](#ex-18)

E04原稿範例入門與基本元素CH1–4


<a id="toc-ch1-04"></a>

# 觀察型別與實作範圍

18\_basic\_types.c1 組原稿測試

**原稿索引：**18\_basic\_types.c　原檔：8　新版：題目 13 / 講解 14
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-18/problem)[02 解題說明](#ex-18/solution)[03 完整程式](#ex-18/code)[04 測試資料](#ex-18/tests)[05 來源與提醒](#ex-18/tips)

01

## 完整題目

先確認規格，再寫程式

建立int、float、double三種資料，並查看本機int上下界。

### 輸入與限制

固定3、26.75f、5.0/9.0；範圍由limits.h提供。

### 應產生的輸出

三種值與本機INT\_MIN、INT\_MAX。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿平台觀察值

```
count=3 temp=26.75 ratio=0.555556
INT_MIN=-2147483648 INT_MAX=2147483647
```

73 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

此例含平台觀察值，請依原題前提判讀，不將本機型別範圍或浮點字面表示當成跨平台固定答案。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

依資料性質選型別：數量、溫度、比例各自宣告。

**STEP 02**

用正確printf規格輸出，float作引數時提升為double。

**STEP 03**

從limits.h取得整數界線，不把本機結果當作所有平台規格。

### 原稿解題示例

count=3；temp=26.75；ratio≈0.555556

03

## 完整程式碼

每份程式均有獨立 main

18\_basic\_types.c

完整程式 · 17 行 · 內容與原稿逐字相同

```
/* 18_basic_types.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 8.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int count = 3;
    float temp = 26.75f;
    double ratio = 5.0 / 9.0;
    printf("count=%d temp=%.2f ratio=%.6f\n", count, temp, ratio);
    printf("INT_MIN=%d INT_MAX=%d\n", INT_MIN, INT_MAX);
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/18_basic_types.c -o example`

04


## 測試資料

1 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E04-T01**1. 測試1**原稿測試 · 0 input bytes · 平台觀察紀錄exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜依模式或數值核對；以下列出本次GCC環境觀察值

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿平台觀察值

```
count=3 temp=26.75 ratio=0.555556
INT_MIN=-2147483648 INT_MAX=2147483647
```

73 bytes · 保留原稿的空白、tab 與換行

上方是原 HTML 記錄的 GCC 觀察值，本次環境輸出與其一致；不是所有平台都必須逐字相同的答案。原稿未附具體模式／數值判準，本次未補寫該判準。

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

補入原備忘錄提及的limits.h實測，不固定假設int為32位元。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E03 以名稱與註解表達計算意圖](#ex-17)[E05 安全觀察初始化與賦值 →](#ex-19)

E05原稿範例入門與基本元素CH1–4


<a id="toc-ch1-05"></a>

# 安全觀察初始化與賦值

19\_initialization.c1 組原稿測試

**原稿索引：**19\_initialization.c　原檔：9　新版：題目 15 / 講解 16
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-19/problem)[02 解題說明](#ex-19/solution)[03 完整程式](#ex-19/code)[04 測試資料](#ex-19/tests)[05 來源與提醒](#ex-19/tips)

01

## 完整題目

先確認規格，再寫程式

依原例 int height, length, width=10，追蹤每個變數何時才可讀。

### 輸入與限制

初始只有width=10；依序指定height=8、length=12。

### 應產生的輸出

先只印width，再印已被賦值的變數。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 範例輸出

```
after declaration: width=10
after height assignment: height=8 width=10
final: height=8 length=12 width=10
```

106 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

看每個宣告子：=10只屬於width，不會初始化所有變數。

**STEP 02**

在height被賦值前不讀它；length亦同。

**STEP 03**

全部取得有效值後才同時輸出三個變數。

### 原稿解題示例

width=10 → height=8 → length=12

03

## 完整程式碼

每份程式均有獨立 main

19\_initialization.c

完整程式 · 17 行 · 內容與原稿逐字相同

```
/* 19_initialization.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 9.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>

int main(void)
{
    int height, length, width = 10;
    printf("after declaration: width=%d\n", width);
    height = 8;
    printf("after height assignment: height=%d width=%d\n", height, width);
    length = 12;
    printf("final: height=%d length=%d width=%d\n", height, length, width);
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/19_initialization.c -o example`

04


## 測試資料

1 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E05-T01**1. 測試1**原稿測試 · 0 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿完整預期輸出

```
after declaration: width=10
after height assignment: height=8 width=10
final: height=8 length=12 width=10
```

106 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

原表中的「未指定」不是可印出的數值；本程式刻意不讀尚未初始化的物件。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E04 觀察型別與實作範圍](#ex-18)[E06 用中間值追蹤體積計算 →](#ex-20)

E06原稿範例入門與基本元素CH1–4


<a id="toc-ch1-06"></a>

# 用中間值追蹤體積計算

20\_volume\_flow.c1 組原稿測試

**原稿索引：**20\_volume\_flow.c　原檔：10　新版：題目 17 / 講解 18
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-20/problem)[02 解題說明](#ex-20/solution)[03 完整程式](#ex-20/code)[04 測試資料](#ex-20/tests)[05 來源與提醒](#ex-20/tips)

01

## 完整題目

先確認規格，再寫程式

計算12×10×8，再改高為9，觀察已存下的volume是否自動更新。

### 輸入與限制

固定length=12、width=10、height=8；之後height=9。

### 應產生的輸出

原體積960、未重算仍960、重算後1080。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 範例輸出

```
initial volume=960
before recompute=960
after recompute=1080
```

61 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

先給三個維度有效值，乘法結果再指定给volume。

**STEP 02**

改height不等於重跑體積公式；先印舊volume確認。

**STEP 03**

再次執行賦值，才將1080寫入volume。

### 原稿解題示例

960 → 改height後仍960 → 重算1080

03

## 完整程式碼

每份程式均有獨立 main

20\_volume\_flow.c

完整程式 · 18 行 · 內容與原稿逐字相同

```
/* 20_volume_flow.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 10.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>

int main(void)
{
    int length = 12, width = 10, height = 8;
    int volume = length * width * height;
    printf("initial volume=%d\n", volume);
    height = 9;
    printf("before recompute=%d\n", volume);
    volume = length * width * height;
    printf("after recompute=%d\n", volume);
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/20_volume_flow.c -o example`

04


## 測試資料

1 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E06-T01**1. 測試1**原稿測試 · 0 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿完整預期輸出

```
initial volume=960
before recompute=960
after recompute=1080
```

61 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

後兩次觀察實作原備忘錄的height=9提問，不改變體積公式或單位。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E05 安全觀察初始化與賦值](#ex-19)[E07 計算包裹的材積重量 →](#ex-2)

E07原稿範例入門與基本元素CH1–4


<a id="toc-ch1-07"></a>

# 計算包裹的材積重量

02\_dweight.c7 組原稿測試

**原稿索引：**02\_dweight.c　原檔：11, 13　新版：題目 19 / 講解 20, 23
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-2/problem)[02 解題說明](#ex-2/solution)[03 完整程式](#ex-2/code)[04 測試資料](#ex-2/tests)[05 來源與提醒](#ex-2/tips)

01

## 完整題目

先確認規格，再寫程式

讀入長、寬、高，依教材係數將體積換算為向上取整的材積重量。

### 輸入與限制

三個整數，依序為長、寬、高；各 1..30 英吋。

### 應產生的輸出

Volume（in^3）與 Dimensional weight（lb）。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
12 10 8
```

8 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
Volume: 960 in^3
Dimensional weight: 6 lb
```

42 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

確認資料前提：三個整數都成功讀入，且各在 1..30。

**STEP 02**

先算體積：volume = length \* width \* height，保留可追蹤中間值。

**STEP 03**

最後進位：以 (volume + 165) / 166 計算整數磅數。

### 原稿解題示例

12 10 8 → 960 in^3 → 6 lb

03

## 完整程式碼

每份程式均有獨立 main

02\_dweight.c

完整程式 · 27 行 · 內容與原稿逐字相同

```
/* 02_dweight.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 11, 12, 13.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>
#define INCHES_PER_POUND 166

int main(void)
{
    int length, width, height;
    int volume, weight;
    if (scanf("%d%d%d", &length, &width, &height) != 3) {
        puts("Input error");
        return 1;
    }
    if (length < 1 || length > 30 || width < 1 || width > 30 ||
        height < 1 || height > 30) {
        puts("Range error");
        return 1;
    }
    volume = length * width * height;
    weight = (volume + INCHES_PER_POUND - 1) / INCHES_PER_POUND;
    printf("Volume: %d in^3\n", volume);
    printf("Dimensional weight: %d lb\n", weight);
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/02_dweight.c -o example`

04


## 測試資料

7 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E07-T01**1. 測試1**原稿測試 · 8 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
12 10 8
```

8 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Volume: 960 in^3
Dimensional weight: 6 lb
```

42 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E07-T02**2. 測試2**原稿測試 · 6 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
1 1 1
```

6 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Volume: 1 in^3
Dimensional weight: 1 lb
```

40 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E07-T03**3. 測試3**原稿測試 · 9 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
30 30 30
```

9 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Volume: 27000 in^3
Dimensional weight: 163 lb
```

46 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E07-T04**4. 測試4**原稿測試 · 7 input bytes · 完整字串核對exit 1 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 1

返回碼 1｜完整字串核對

STDIN · 完整輸入

```
0 10 8
```

7 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Range error
```

12 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E07-T05**5. 測試5**原稿測試 · 8 input bytes · 完整字串核對exit 1 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 1

返回碼 1｜完整字串核對

STDIN · 完整輸入

```
31 10 8
```

8 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Range error
```

12 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E07-T06**6. 測試6**原稿測試 · 7 input bytes · 完整字串核對exit 1 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 1

返回碼 1｜完整字串核對

STDIN · 完整輸入

```
a 10 8
```

7 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Input error
```

12 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E07-T07**7. 測試7**原稿測試 · 0 input bytes · 完整字串核對exit 1 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 1

返回碼 1｜完整字串核對

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿完整預期輸出

```
Input error
```

12 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

新增 main、標頭與原投影片已聲明的回傳值及範圍檢查；運算式、單位與係數不變。166 為教材係數，非現行物流費率。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E06 用中間值追蹤體積計算](#ex-20)[E08 驗證整數向上取整的邊界 →](#ex-21)

E08原稿範例入門與基本元素CH1–4


<a id="toc-ch1-08"></a>

# 驗證整數向上取整的邊界

21\_ceiling\_division.c8 組原稿測試

**原稿索引：**21\_ceiling\_division.c　原檔：12　新版：題目 21 / 講解 22
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-21/problem)[02 解題說明](#ex-21/solution)[03 完整程式](#ex-21/code)[04 測試資料](#ex-21/tests)[05 來源與提醒](#ex-21/tips)

01

## 完整題目

先確認規格，再寫程式

以固定除數166比較直接除法與向上取整公式。

### 輸入與限制

非負整數n，0..30000；166為固定正數。

### 應產生的輸出

n/166 與 (n+165)/166。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
0
```

2 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
floor=0 ceil=0
```

15 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

先限制n，使加165仍在保守int範圍內。

**STEP 02**

直接除法只留下整數商；加165將部分單位推到下一格。

**STEP 03**

測0、165、166、167、332，看整除點有無多算。

### 原稿解題示例

167 → floor=1；ceil=2

03

## 完整程式碼

每份程式均有獨立 main

21\_ceiling\_division.c

完整程式 · 21 行 · 內容與原稿逐字相同

```
/* 21_ceiling_division.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 12.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) {
        puts("Input error");
        return 1;
    }
    if (n < 0 || n > 30000) {
        puts("Range error");
        return 1;
    }
    printf("floor=%d ceil=%d\n", n / 166, (n + 165) / 166);
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/21_ceiling_division.c -o example`

04


## 測試資料

8 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E08-T01**1. 測試1**原稿測試 · 2 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
0
```

2 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
floor=0 ceil=0
```

15 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E08-T02**2. 測試2**原稿測試 · 4 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
165
```

4 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
floor=0 ceil=1
```

15 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E08-T03**3. 測試3**原稿測試 · 4 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
166
```

4 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
floor=1 ceil=1
```

15 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E08-T04**4. 測試4**原稿測試 · 4 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
167
```

4 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
floor=1 ceil=2
```

15 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E08-T05**5. 測試5**原稿測試 · 4 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
332
```

4 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
floor=2 ceil=2
```

15 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E08-T06**6. 測試6**原稿測試 · 6 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
30000
```

6 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
floor=180 ceil=181
```

19 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E08-T07**7. 測試7**原稿測試 · 3 input bytes · 完整字串核對exit 1 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 1

返回碼 1｜完整字串核對

STDIN · 完整輸入

```
-1
```

3 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Range error
```

12 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E08-T08**8. 測試8**原稿測試 · 4 input bytes · 完整字串核對exit 1 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 1

返回碼 1｜完整字串核對

STDIN · 完整輸入

```
abc
```

4 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Input error
```

12 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

把原表改成可自行輸入n的實驗；本次明示新增n≤30000界線，避免加165溢位。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E07 計算包裹的材積重量](#ex-2)[E09 比較巨集有無括號的結果 →](#ex-22)

E09原稿範例入門與基本元素CH1–4


<a id="toc-ch1-09"></a>

# 比較巨集有無括號的結果

22\_macro\_parentheses.c1 組原稿測試

**原稿索引：**22\_macro\_parentheses.c　原檔：14　新版：題目 24 / 講解 25
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-22/problem)[02 解題說明](#ex-22/solution)[03 完整程式](#ex-22/code)[04 測試資料](#ex-22/tests)[05 來源與提醒](#ex-22/tips)

01

## 完整題目

先確認規格，再寫程式

對照3乘BASE的兩種替換方式，並驗證具名材積常數。

### 輸入與限制

BASE\_BAD=10+2、BASE\_GOOD=(10+2)、volume=960。

### 應產生的輸出

未加括號32、加括號36、weight=6。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 範例輸出

```
bad=32 good=36 weight=6
```

24 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

先作文字替換：3\*BASE\_BAD變成3\*10+2。

**STEP 02**

再看括號保護：3\*(10+2)才是先加後乘。

**STEP 03**

用INCHES\_PER\_POUND命名166，讓進位公式可讀。

### 原稿解題示例

3\*BASE\_BAD=32；3\*BASE\_GOOD=36

03

## 完整程式碼

每份程式均有獨立 main

22\_macro\_parentheses.c

完整程式 · 19 行 · 內容與原稿逐字相同

```
/* 22_macro_parentheses.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 14.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>
#define BASE_BAD 10 + 2
#define BASE_GOOD (10 + 2)
#define INCHES_PER_POUND 166

int main(void)
{
    int bad = 3 * BASE_BAD;
    int good = 3 * BASE_GOOD;
    int volume = 960;
    int weight = (volume + INCHES_PER_POUND - 1) / INCHES_PER_POUND;
    printf("bad=%d good=%d weight=%d\n", bad, good, weight);
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/22_macro_parentheses.c -o example`

04


## 測試資料

1 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E09-T01**1. 測試1**原稿測試 · 0 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿完整預期輸出

```
bad=32 good=36 weight=6
```

24 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

為能在同檔比較，將原先兩段BASE分別命名BASE\_BAD/BASE\_GOOD；替換內容與數值不變。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E08 驗證整數向上取整的邊界](#ex-21)[E10 華氏溫度轉攝氏溫度 →](#ex-3)

E10原稿範例入門與基本元素CH1–4


<a id="toc-ch1-10"></a>

# 華氏溫度轉攝氏溫度

03\_celsius.c9 組原稿測試

**原稿索引：**03\_celsius.c　原檔：15, 16　新版：題目 26 / 講解 27, 28
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-3/problem)[02 解題說明](#ex-3/solution)[03 完整程式](#ex-3/code)[04 測試資料](#ex-3/tests)[05 來源與提醒](#ex-3/tips)

01

## 完整題目

先確認規格，再寫程式

依 C = (F − 32) × (5/9) 計算攝氏；除法發生前必須使用浮點型別。

### 輸入與限制

一個可表示的 double；本次新增教學範圍 −1000..10000，且須為有限值。

### 應產生的輸出

Celsius:，攝氏值顯示一位小數。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
212
```

4 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
Celsius: 100.0
```

15 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

以 %lf 讀入 double；先排除解析失敗、非有限值與超出範圍。

**STEP 02**

先減 32.0，再乘 (5.0 / 9.0)，避免整數 5 / 9 變成 0。

**STEP 03**

用 %.1f 顯示；以 32、98.6、212 三個已知答案核對。

### 原稿解題示例

212 → Celsius: 100.0

03

## 完整程式碼

每份程式均有獨立 main

03\_celsius.c

完整程式 · 25 行 · 內容與原稿逐字相同

```
/* 03_celsius.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 15, 16.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>
#include <math.h>
#define FREEZING_PT 32.0
#define SCALE_FACTOR (5.0 / 9.0)

int main(void)
{
    double fahrenheit, celsius;
    if (scanf("%lf", &fahrenheit) != 1) {
        puts("Input error");
        return 1;
    }
    if (!isfinite(fahrenheit) || fahrenheit < -1000.0 || fahrenheit > 10000.0) {
        puts("Range error");
        return 1;
    }
    celsius = (fahrenheit - FREEZING_PT) * SCALE_FACTOR;
    printf("Celsius: %.1f\n", celsius);
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/03_celsius.c -o example`

04


## 測試資料

9 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E10-T01**1. 測試1**原稿測試 · 4 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
212
```

4 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Celsius: 100.0
```

15 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E10-T02**2. 測試2**原稿測試 · 3 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
32
```

3 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Celsius: 0.0
```

13 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E10-T03**3. 測試3**原稿測試 · 5 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
98.6
```

5 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Celsius: 37.0
```

14 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E10-T04**4. 測試4**原稿測試 · 4 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
-40
```

4 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Celsius: -40.0
```

15 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E10-T05**5. 測試5**原稿測試 · 4 input bytes · 完整字串核對exit 1 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 1

返回碼 1｜完整字串核對

STDIN · 完整輸入

```
abc
```

4 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Input error
```

12 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E10-T06**6. 測試6**原稿測試 · 4 input bytes · 完整字串核對exit 1 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 1

返回碼 1｜完整字串核對

STDIN · 完整輸入

```
nan
```

4 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Range error
```

12 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E10-T07**7. 測試7**原稿測試 · 4 input bytes · 完整字串核對exit 1 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 1

返回碼 1｜完整字串核對

STDIN · 完整輸入

```
inf
```

4 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Range error
```

12 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E10-T08**8. 測試8**原稿測試 · 6 input bytes · 完整字串核對exit 1 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 1

返回碼 1｜完整字串核對

STDIN · 完整輸入

```
10001
```

6 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Range error
```

12 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E10-T09**9. 測試9**原稿測試 · 0 input bytes · 完整字串核對exit 1 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 1

返回碼 1｜完整字串核對

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿完整預期輸出

```
Input error
```

12 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

保留投影片的 double 版本。原檔只說有限範圍，未給數字；−1000..10000 是本次明示的測試界線，不是物理量測規格。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E09 比較巨集有無括號的結果](#ex-22)[E11 驗證基本元素的四題檢核 →](#ex-23)

E11原稿範例入門與基本元素CH1–4


<a id="toc-ch1-11"></a>

# 驗證基本元素的四題檢核

23\_quiz\_basics.c1 組原稿測試

**原稿索引：**23\_quiz\_basics.c　原檔：17　新版：題目 29 / 講解 30
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-23/problem)[02 解題說明](#ex-23/solution)[03 完整程式](#ex-23/code)[04 測試資料](#ex-23/tests)[05 來源與提醒](#ex-23/tips)

01

## 完整題目

先確認規格，再寫程式

用可執行結果確認初始化、除法、巨集；建置流程以文字作答。

### 輸入與限制

固定c=3；a、b未初始化時不讀取。

### 應產生的輸出

c、整數比例與巨集結果；列出#include的階段。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 範例輸出

```
c=3 x=0.0 macro=32
after assignments: a=0 b=0
#include is processed during preprocessing.
```

90 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

先判定哪些變數可讀，只印有初值的c。

**STEP 02**

保留5/9與未括號巨集，觀察合法但容易誤判的值。

**STEP 03**

#include的處理屬建置過程，不假裝它是main內的執行動作。

### 原稿解題示例

c=3；x=0.0；3\*BASE=32

03

## 完整程式碼

每份程式均有獨立 main

23\_quiz\_basics.c

完整程式 · 19 行 · 內容與原稿逐字相同

```
/* 23_quiz_basics.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 17.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>
#define BASE 10 + 2

int main(void)
{
    int a, b, c = 3;
    double x = 5 / 9;
    printf("c=%d x=%.1f macro=%d\n", c, x, 3 * BASE);
    /* Assign before observing a and b. */
    a = 0; b = 0;
    printf("after assignments: a=%d b=%d\n", a, b);
    puts("#include is processed during preprocessing.");
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/23_quiz_basics.c -o example`

04


## 測試資料

1 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E11-T01**1. 測試1**原稿測試 · 0 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿完整預期輸出

```
c=3 x=0.0 macro=32
after assignments: a=0 b=0
#include is processed during preprocessing.
```

90 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

新增a=b=0僅為示範使用前赋值，不改變原題「只有c已初始化」的答案。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E10 華氏溫度轉攝氏溫度](#ex-3)[E12 讓格式與數值一一配對 →](#ex-24)

E12原稿範例格式化輸入輸出CH1–4


<a id="toc-ch1-12"></a>

# 讓格式與數值一一配對

24\_printf\_contract.c1 組原稿測試

**原稿索引：**24\_printf\_contract.c　原檔：18　新版：題目 31 / 講解 32
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-24/problem)[02 解題說明](#ex-24/solution)[03 完整程式](#ex-24/code)[04 測試資料](#ex-24/tests)[05 來源與提醒](#ex-24/tips)

01

## 完整題目

先確認規格，再寫程式

輸出quantity=3與temperature=26.75，依序使用整數及一位小數格式。

### 輸入與限制

固定int quantity與double temperature。

### 應產生的輸出

Qty=3 Temp=26.8。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 範例輸出

```
Qty=3 Temp=26.8
```

16 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

先看%d要取int值，讓quantity放第一個位置。

**STEP 02**

再看%.1f要取double值，讓temperature放第二個位置。

**STEP 03**

一般文字與空白照印；最後由\n換行。

### 原稿解題示例

quantity=3、temperature=26.75 → Qty=3 Temp=26.8

03

## 完整程式碼

每份程式均有獨立 main

24\_printf\_contract.c

完整程式 · 14 行 · 內容與原稿逐字相同

```
/* 24_printf_contract.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 18.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>

int main(void)
{
    int quantity = 3;
    double temperature = 26.75;
    printf("Qty=%d Temp=%.1f\n", quantity, temperature);
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/24_printf_contract.c -o example`

04


## 測試資料

1 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E12-T01**1. 測試1**原稿測試 · 0 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿完整預期輸出

```
Qty=3 Temp=26.8
```

16 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

補齊原圖所列的變數宣告及main。顯示預期沿用一般最近捨入環境。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E11 驗證基本元素的四題檢核](#ex-23)[E13 依資料型別選擇 printf 規格 →](#ex-25)

E13原稿範例格式化輸入輸出CH1–4


<a id="toc-ch1-13"></a>

# 依資料型別選擇 printf 規格

25\_printf\_types.c1 組原稿測試

**原稿索引：**25\_printf\_types.c　原檔：19　新版：題目 33 / 講解 34
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-25/problem)[02 解題說明](#ex-25/solution)[03 完整程式](#ex-25/code)[04 測試資料](#ex-25/tests)[05 來源與提醒](#ex-25/tips)

01

## 完整題目

先確認規格，再寫程式

將原表中的int、unsigned、字元、浮點與字串各印一次。

### 輸入與限制

固定42、42u、A、3.5f、3.5、Hello。

### 應產生的輸出

使用各自匹配規格的六行輸出。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 範例輸出

```
int=42
unsigned=42
char=A
float=3.5
double=3.5
string=Hello
```

60 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

按C型別而非數值外觀選%d、%u或%f。

**STEP 02**

字元用%c、字串用%s；兩者不是同一種參數。

**STEP 03**

float傳入printf後提升為double，不要把讀入指標規則混入。

### 原稿解題示例

3.5f與3.5 → 都以printf的%f輸出

03

## 完整程式碼

每份程式均有獨立 main

25\_printf\_types.c

完整程式 · 22 行 · 內容與原稿逐字相同

```
/* 25_printf_types.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 19.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>

int main(void)
{
    int n = 42;
    unsigned int u = 42u;
    float f = 3.5f;
    double d = 3.5;
    printf("int=%d\n", n);
    printf("unsigned=%u\n", u);
    printf("char=%c\n", 'A');
    printf("float=%.1f\n", f);
    printf("double=%.1f\n", d);
    printf("string=%s\n", "Hello");
    /* Counterexample (not executed): printf("%d", 3.0); */
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/25_printf_types.c -o example`

04


## 測試資料

1 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E13-T01**1. 測試1**原稿測試 · 0 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿完整預期輸出

```
int=42
unsigned=42
char=A
float=3.5
double=3.5
string=Hello
```

60 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

表格具體化，型別不匹配的原反例只保留在註解。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E12 讓格式與數值一一配對](#ex-24)[E14 比較欄寬、精度與浮點格式 →](#ex-4)

E14原稿範例格式化輸入輸出CH1–4


<a id="toc-ch1-14"></a>

# 比較欄寬、精度與浮點格式

04\_printf\_formats.c1 組原稿測試

**原稿索引：**04\_printf\_formats.c　原檔：20, 21　新版：題目 35 / 講解 36, 37
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-4/problem)[02 解題說明](#ex-4/solution)[03 完整程式](#ex-4/code)[04 測試資料](#ex-4/tests)[05 來源與提醒](#ex-4/tips)

01

## 完整題目

先確認規格，再寫程式

對同一整數及同一浮點值，觀察不同格式如何改變顯示，而不改變儲存值。

### 輸入與限制

固定 i=40、x=839.21；不需輸入。

### 應產生的輸出

以 | 標記欄位邊界，並列出 %f、%e、%g。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 範例輸出

```
|   40|
|40   |
|  040|
|00040|
|123456|
839.210
8.392e+02
839.2
|   839.210|
```

78 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

先算整數位數：欄寬補空白，整數精度補前導零。

**STEP 02**

以同一浮點值比較固定小數、科學記號與有效位數。

**STEP 03**

測超出欄寬的 123456：最小欄寬不會截掉數字。

### 原稿解題示例

%5.3d、40 → | 040|

03

## 完整程式碼

每份程式均有獨立 main

04\_printf\_formats.c

完整程式 · 22 行 · 內容與原稿逐字相同

```
/* 04_printf_formats.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 20, 21.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>

int main(void)
{
    int i = 40;
    double x = 839.21;
    printf("|%5d|\n", i);
    printf("|%-5d|\n", i);
    printf("|%5.3d|\n", i);
    printf("|%05d|\n", i);
    printf("|%5d|\n", 123456);
    printf("%.3f\n", x);
    printf("%.3e\n", x);
    printf("%.4g\n", x);
    printf("|%10.3f|\n", x);
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/04_printf_formats.c -o example`

04


## 測試資料

1 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E14-T01**1. 測試1**原稿測試 · 0 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿完整預期輸出

```
|   40|
|40   |
|  040|
|00040|
|123456|
839.210
8.392e+02
839.2
|   839.210|
```

78 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

將原兩頁表格包成可執行實驗；新增 123456 作最小欄寬的反證。浮點字面測試採本次一般二進位浮點、C locale 環境。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E13 依資料型別選擇 printf 規格](#ex-25)[E15 製作感測器數值報表 →](#ex-5)

E15原稿範例格式化輸入輸出CH1–4


<a id="toc-ch1-15"></a>

# 製作感測器數值報表

05\_sensor\_report.c1 組原稿測試

**原稿索引：**05\_sensor\_report.c　原檔：22　新版：題目 38 / 講解 39
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-5/problem)[02 解題說明](#ex-5/solution)[03 完整程式](#ex-5/code)[04 測試資料](#ex-5/tests)[05 來源與提醒](#ex-5/tips)

01

## 完整題目

先確認規格，再寫程式

將兩筆假設量測值輸出成名稱、固定小數與科學記號三欄。

### 輸入與限制

固定 Temp=26.75、Volt=3.30；無外接感測器。

### 應產生的輸出

三欄標題與兩筆對齊資料。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 範例輸出

```
Item        Value   Scientific
Temp        26.75    2.675e+01
Volt         3.30    3.300e+00
```

93 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

為每欄決定規格：名稱靠左，數值欄靠右。

**STEP 02**

同一筆數值分別交給 %8.2f 與 %12.3e 顯示。

**STEP 03**

以標題與兩筆資料檢查對齊，不用手打空白湊位置。

### 原稿解題示例

Temp → 26.75 → 2.675e+01

03

## 完整程式碼

每份程式均有獨立 main

05\_sensor\_report.c

完整程式 · 16 行 · 內容與原稿逐字相同

```
/* 05_sensor_report.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 22.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>

int main(void)
{
    double temperature = 26.75;
    double voltage = 3.30;
    printf("%-8s %8s %12s\n", "Item", "Value", "Scientific");
    printf("%-8s %8.2f %12.3e\n", "Temp", temperature, temperature);
    printf("%-8s %8.2f %12.3e\n", "Volt", voltage, voltage);
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/05_sensor_report.c -o example`

04


## 測試資料

1 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E15-T01**1. 測試1**原稿測試 · 0 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿完整預期輸出

```
Item        Value   Scientific
Temp        26.75    2.675e+01
Volt         3.30    3.300e+00
```

93 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

沿用原第22頁完整程式，未新增外部資料來源。對齊以 ASCII 與等寬終端顯示為前提。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E14 比較欄寬、精度與浮點格式](#ex-4)[E16 控制字串截取與動態欄寬 →](#ex-26)

E16原稿範例格式化輸入輸出CH1–4


<a id="toc-ch1-16"></a>

# 控制字串截取與動態欄寬

26\_dynamic\_format.c1 組原稿測試

**原稿索引：**26\_dynamic\_format.c　原檔：23　新版：題目 40 / 講解 41
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-26/problem)[02 解題說明](#ex-26/solution)[03 完整程式](#ex-26/code)[04 測試資料](#ex-26/tests)[05 來源與提醒](#ex-26/tips)

01

## 完整題目

先確認規格，再寫程式

分別顯示SENSOR前四個ASCII字元，以及由參數控制寬度與精度的3.5。

### 輸入與限制

字串SENSOR；width=8、precision=2、value=3.5。

### 應產生的輸出

|SENS |、| 3.50|、單一百分號。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 範例輸出

```
|SENS    |
|    3.50|
%
```

24 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

%-8.4s先限制最多四個位元組，再靠左補滿八格。

**STEP 02**

%\*.\*f依序取width、precision、value，共三個參數。

**STEP 03**

%%直接產生百分號，不再拿取一個數值。

### 原稿解題示例

8, 2, 3.5 → | 3.50|

03

## 完整程式碼

每份程式均有獨立 main

26\_dynamic\_format.c

完整程式 · 14 行 · 內容與原稿逐字相同

```
/* 26_dynamic_format.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 23.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>

int main(void)
{
    printf("|%-8.4s|\n", "SENSOR");
    printf("|%*.*f|\n", 8, 2, 3.5);
    printf("%%\n");
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/26_dynamic_format.c -o example`

04


## 測試資料

1 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E16-T01**1. 測試1**原稿測試 · 0 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿完整預期輸出

```
|SENS    |
|    3.50|
%
```

24 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

保留原兩段printf；新增百分號示範。此ASCII資料不推廣為Unicode可見字數計算。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E15 製作感測器數值報表](#ex-5)[E17 輸出引號、反斜線與換行 →](#ex-27)

E17原稿範例格式化輸入輸出CH1–4


<a id="toc-ch1-17"></a>

# 輸出引號、反斜線與換行

27\_escape\_sequences.c1 組原稿測試

**原稿索引：**27\_escape\_sequences.c　原檔：24　新版：題目 42 / 講解 43
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-27/problem)[02 解題說明](#ex-27/solution)[03 完整程式](#ex-27/code)[04 測試資料](#ex-27/tests)[05 來源與提醒](#ex-27/tips)

01

## 完整題目

先確認規格，再寫程式

用跳脫序列印出原案例的引號文字與Windows風格路徑。

### 輸入與限制

不需輸入。

### 應產生的輸出

第一行為"C"\tmp，第二行為C:\temp。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 範例輸出

```
"C"\tmp
C:\temp
```

16 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

先分清字串界定引號與真正要輸出的雙引號。

**STEP 02**

用\\表示單一反斜線，避免\t被當成跳格。

**STEP 03**

用\n終止該行；來源寫法與顯示結果分兩層核對。

### 原稿解題示例

來源 \" 與 \\ → 顯示 " 與 \

03

## 完整程式碼

每份程式均有獨立 main

27\_escape\_sequences.c

完整程式 · 13 行 · 內容與原稿逐字相同

```
/* 27_escape_sequences.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 24.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>

int main(void)
{
    printf("\"C\"\\tmp\n");
    printf("C:\\temp\n");
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/27_escape_sequences.c -o example`

04


## 測試資料

1 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E17-T01**1. 測試1**原稿測試 · 0 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿完整預期輸出

```
"C"\tmp
C:\temp
```

16 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

第二行來自原備忘錄的路徑提問。沒有用system或作業系統專屬函式。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E16 控制字串截取與動態欄寬](#ex-26)[E18 區分多給參數與危險格式錯誤 →](#ex-28)

E18刻意保留診斷對照格式化輸入輸出CH1–4


<a id="toc-ch1-18"></a>

# 區分多給參數與危險格式錯誤

28\_printf\_extra\_args.c1 組原稿測試

**原稿索引：**28\_printf\_extra\_args.c　原檔：25　新版：題目 44 / 講解 45
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-28/problem)[02 解題說明](#ex-28/solution)[03 完整程式](#ex-28/code)[04 測試資料](#ex-28/tests)[05 來源與提醒](#ex-28/tips)

01

## 完整題目

先確認規格，再寫程式

只執行原表中可定義的多餘參數例，再用不同變數觀察其求值。

### 輸入與限制

固定i=10、j=20；不執行少參數或型別不匹配反例。

### 應產生的輸出

只印格式需要的i；多餘++j仍把j改成21。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 範例輸出

```
first=10
second=10
j=21
```

24 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

先排除不能給固定輸出的兩種反例，只留註解。

**STEP 02**

printf只消耗格式需要的參數；其餘參數仍會求值。

**STEP 03**

將j的結果在下一行印出，避免同次呼叫的衝突讀寫。

### 原稿解題示例

printf只印10；額外++j仍使j=21

03

## 完整程式碼

每份程式均有獨立 main

28\_printf\_extra\_args.c

完整程式 · 18 行 · 內容與原稿逐字相同

```
/* 28_printf_extra_args.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 25.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>

int main(void)
{
    int i = 10, j = 20;
    /* The next two calls intentionally trigger format-extra-args warnings. */
    printf("first=%d\n", i, j);
    printf("second=%d\n", i, ++j);
    printf("j=%d\n", j);
    /* DO NOT execute: printf("%d %d", i); */
    /* DO NOT execute: printf("%f", i); */
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/28_printf_extra_args.c -o example`

此範例原稿已標示「刻意保留診斷對照」。程式中的教學反例與警告沒有因格式轉換而刪除；詳細界線見本題第 05 區。

04


## 測試資料

1 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E18-T01**1. 測試1**原稿測試 · 0 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿完整預期輸出

```
first=10
second=10
j=21
```

24 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

原頁多餘參數例保留；新增++j讓「仍求值」可觀察。此檔刻意觸發format-extra-args警告，預期警告不是編譯失敗。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E17 輸出引號、反斜線與換行](#ex-27)[E19 正確讀取 float 與 double →](#ex-29)

E19原稿範例格式化輸入輸出CH1–4


<a id="toc-ch1-19"></a>

# 正確讀取 float 與 double

29\_scan\_value\_address.c4 組原稿測試

**原稿索引：**29\_scan\_value\_address.c　原檔：26　新版：題目 46 / 講解 47
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-29/problem)[02 解題說明](#ex-29/solution)[03 完整程式](#ex-29/code)[04 測試資料](#ex-29/tests)[05 來源與提醒](#ex-29/tips)

01

## 完整題目

先確認規格，再寫程式

各讀一個浮點數，配對目標物件型別，再以printf輸出。

### 輸入與限制

依序一個float與一個double；示例3.5 3.5。

### 應產生的輸出

f=3.500000 d=3.500000。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
3.5 3.5
```

8 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
f=3.500000 d=3.500000
```

22 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

兩個目標分別宣告float f與double d。

**STEP 02**

scanf用%f寫入&f、用%lf寫入&d；成功兩項才繼續。

**STEP 03**

輸出取的是值，兩者皆以printf的%f表示。

### 原稿解題示例

3.5 3.5 → f=3.500000 d=3.500000

03

## 完整程式碼

每份程式均有獨立 main

29\_scan\_value\_address.c

完整程式 · 18 行 · 內容與原稿逐字相同

```
/* 29_scan_value_address.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 26.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>

int main(void)
{
    float f;
    double d;
    if (scanf("%f%lf", &f, &d) != 2) {
        puts("Input error");
        return 1;
    }
    printf("f=%f d=%f\n", f, d);
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/29_scan_value_address.c -o example`

04


## 測試資料

4 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E19-T01**1. 測試1**原稿測試 · 8 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
3.5 3.5
```

8 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
f=3.500000 d=3.500000
```

22 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E19-T02**2. 測試2**原稿測試 · 7 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
-2.5 8
```

7 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
f=-2.500000 d=8.000000
```

23 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E19-T03**3. 測試3**原稿測試 · 6 input bytes · 完整字串核對exit 1 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 1

返回碼 1｜完整字串核對

STDIN · 完整輸入

```
3.5 x
```

6 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Input error
```

12 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E19-T04**4. 測試4**原稿測試 · 0 input bytes · 完整字串核對exit 1 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 1

返回碼 1｜完整字串核對

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿完整預期輸出

```
Input error
```

12 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

將原頁兩次scanf合併成一次兩項讀取，格式與物件配對不變；不將不同大小的指標互換。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E18 區分多給參數與危險格式錯誤](#ex-28)[E20 逐項解析沒有空白的數字串 →](#ex-6)

E20原稿範例格式化輸入輸出CH1–4


<a id="toc-ch1-20"></a>

# 逐項解析沒有空白的數字串

06\_scan\_stream.c5 組原稿測試

**原稿索引：**06\_scan\_stream.c　原檔：27, 28　新版：題目 48 / 講解 49, 50
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-6/problem)[02 解題說明](#ex-6/solution)[03 完整程式](#ex-6/code)[04 測試資料](#ex-6/tests)[05 來源與提醒](#ex-6/tips)

01

## 完整題目

先確認規格，再寫程式

使用 %d%d%f%f 讀四個數字，再觀察下一個未消耗的字元。

### 輸入與限制

例如 1-20.3-4.0e3，或以空白／換行分隔的同一組值。

### 應產生的輸出

成功項數、四個變數與下一個字元。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
1-20.3-4.0e3
```

13 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
count=4
i=1 j=-20 x=0.3 y=-4000.0
next=NEWLINE
```

47 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

依格式次序切割：第一個 %d 讀 1，第二個讀 −20。

**STEP 02**

兩個 %f 接著讀 .3 與 −4.0e3；四項都成功才印數值。

**STEP 03**

用 getchar 額外觀察剩餘字元；換行不是被 scanf 自動吃掉。

### 原稿解題示例

1-20.3-4.0e3 → 1, −20, 0.3, −4000.0

03

## 完整程式碼

每份程式均有獨立 main

06\_scan\_stream.c

完整程式 · 25 行 · 內容與原稿逐字相同

```
/* 06_scan_stream.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 27, 28.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>

int main(void)
{
    int i = 0, j = 0;
    float x = 0.0f, y = 0.0f;
    int count = scanf("%d%d%f%f", &i, &j, &x, &y);
    if (count == EOF) puts("count=EOF");
    else printf("count=%d\n", count);
    if (count != 4) {
        puts("Input error");
        return 1;
    }
    printf("i=%d j=%d x=%.1f y=%.1f\n", i, j, x, y);
    int next = getchar();
    if (next == EOF) puts("next=EOF");
    else if (next == '\n') puts("next=NEWLINE");
    else printf("next=%c\n", next);
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/06_scan_stream.c -o example`

04


## 測試資料

5 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E20-T01**1. 測試1**原稿測試 · 13 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
1-20.3-4.0e3
```

13 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
count=4
i=1 j=-20 x=0.3 y=-4000.0
next=NEWLINE
```

47 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E20-T02**2. 測試2**原稿測試 · 18 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
  1
-20 .3
-4.0e3
```

18 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
count=4
i=1 j=-20 x=0.3 y=-4000.0
next=NEWLINE
```

47 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E20-T03**3. 測試3**原稿測試 · 12 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
1-20.3-4.0e3
```

12 bytes · 最後沒有換行，直接 EOF

STDOUT · 原稿完整預期輸出

```
count=4
i=1 j=-20 x=0.3 y=-4000.0
next=EOF
```

43 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E20-T04**4. 測試4**原稿測試 · 5 input bytes · 完整字串核對exit 1 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 1

返回碼 1｜完整字串核對

STDIN · 完整輸入

```
12 x
```

5 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
count=1
Input error
```

20 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E20-T05**5. 測試5**原稿測試 · 0 input bytes · 完整字串核對exit 1 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 1

返回碼 1｜完整字串核對

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿完整預期輸出

```
count=EOF
Input error
```

22 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

新增宣告、初值、回傳值檢查及 getchar 觀察器。getchar 僅供看見剩餘輸入，不是清空輸入的操作。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E19 正確讀取 float 與 double](#ex-29)[E21 觀察 scanf 部分成功後的狀態 →](#ex-7)

E21原稿範例格式化輸入輸出CH1–4


<a id="toc-ch1-21"></a>

# 觀察 scanf 部分成功後的狀態

07\_scan\_failure.c4 組原稿測試

**原稿索引：**07\_scan\_failure.c　原檔：29　新版：題目 51 / 講解 52
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-7/problem)[02 解題說明](#ex-7/solution)[03 完整程式](#ex-7/code)[04 測試資料](#ex-7/tests)[05 來源與提醒](#ex-7/tips)

01

## 完整題目

先確認規格，再寫程式

讀取三個整數；故意讓第二項失敗，確認哪些變數已改、哪些仍保留初值。

### 輸入與限制

標準示例 12 x 3；另測完全成功、首項錯誤、EOF。

### 應產生的輸出

count、a/b/c 與 next；本程式是診斷實驗。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
12 x 3
```

7 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
count=1
a=12 b=-1 c=-1
next=x
```

30 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

先把三個變數都設為 −1，才能安全觀察未賦值項目。

**STEP 02**

執行一次 scanf，保留成功賦值數；不要失敗後繼續算總和。

**STEP 03**

用 getchar 看下一個字元；x 不會被下一次 %d 自動略過。

### 原稿解題示例

12 x 3 → count=1，a=12，b=c=−1，next=x

03

## 完整程式碼

每份程式均有獨立 main

07\_scan\_failure.c

完整程式 · 21 行 · 內容與原稿逐字相同

```
/* 07_scan_failure.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 29.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>

int main(void)
{
    int a = -1, b = -1, c = -1;
    int count = scanf("%d%d%d", &a, &b, &c);
    if (count == EOF) puts("count=EOF");
    else printf("count=%d\n", count);
    printf("a=%d b=%d c=%d\n", a, b, c);
    int next = getchar();
    if (next == EOF) puts("next=EOF");
    else if (next == '\n') puts("next=NEWLINE");
    else if (next == ' ') puts("next=SPACE");
    else printf("next=%c\n", next);
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/07_scan_failure.c -o example`

04


## 測試資料

4 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E21-T01**1. 測試1**原稿測試 · 7 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
12 x 3
```

7 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
count=1
a=12 b=-1 c=-1
next=x
```

30 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E21-T02**2. 測試2**原稿測試 · 6 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
1 2 3
```

6 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
count=3
a=1 b=2 c=3
next=NEWLINE
```

33 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E21-T03**3. 測試3**原稿測試 · 2 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
x
```

2 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
count=0
a=-1 b=-1 c=-1
next=x
```

30 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E21-T04**4. 測試4**原稿測試 · 0 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿完整預期輸出

```
count=EOF
a=-1 b=-1 c=-1
next=EOF
```

34 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

這是觀察 scanf 失敗的測試器，預期失敗仍回傳程序結束碼0，表示觀察流程正常完成；不將 count 與程序結束碼混為一談。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E20 逐項解析沒有空白的數字串](#ex-6)[E22 重現五組分隔符匹配實驗 →](#ex-30)

E22原稿範例格式化輸入輸出CH1–4


<a id="toc-ch1-22"></a>

# 重現五組分隔符匹配實驗

30\_scan\_delimiters.c1 組原稿測試

**原稿索引：**30\_scan\_delimiters.c　原檔：30　新版：題目 53 / 講解 54
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-30/problem)[02 解題說明](#ex-30/solution)[03 完整程式](#ex-30/code)[04 測試資料](#ex-30/tests)[05 來源與提醒](#ex-30/tips)

01

## 完整題目

先確認規格，再寫程式

用固定字串重現原表五組scanf格式的成功項數，避免互相消耗同一輸入。

### 輸入與限制

固定5/6、5 / 6與5 6；本次用sscanf作獨立測試器。

### 應產生的輸出

五次成功賦值數依序2、1、2、2、1。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 範例輸出

```
case1: count=2 a=5 b=6
case2: count=1 a=5 b=-1
case3: count=2 a=5 b=6
case4: count=2 a=5 b=6
case5: count=1 a=5 b=-1
```

117 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

普通/或,要直接匹配；格式空白可略過零個或多個空白。

**STEP 02**

每次重設a、b初值，失敗後仍可安全查看未改值。

**STEP 03**

用sscanf從不同字串開頭開始，保留相同轉換與匹配規則。

### 原稿解題示例

%d/%d讀5 / 6 → count=1，b仍−1

03

## 完整程式碼

每份程式均有獨立 main

30\_scan\_delimiters.c

完整程式 · 26 行 · 內容與原稿逐字相同

```
/* 30_scan_delimiters.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 30.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>

int main(void)
{
    int a = -1, b = -1, count;
    count = sscanf("5/6", "%d/%d", &a, &b);
    printf("case1: count=%d a=%d b=%d\n", count, a, b);
    a = -1; b = -1;
    count = sscanf("5 / 6", "%d/%d", &a, &b);
    printf("case2: count=%d a=%d b=%d\n", count, a, b);
    a = -1; b = -1;
    count = sscanf("5 / 6", "%d / %d", &a, &b);
    printf("case3: count=%d a=%d b=%d\n", count, a, b);
    a = -1; b = -1;
    count = sscanf("5/6", "%d / %d", &a, &b);
    printf("case4: count=%d a=%d b=%d\n", count, a, b);
    a = -1; b = -1;
    count = sscanf("5 6", "%d, %d", &a, &b);
    printf("case5: count=%d a=%d b=%d\n", count, a, b);
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/30_scan_delimiters.c -o example`

04


## 測試資料

1 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E22-T01**1. 測試1**原稿測試 · 0 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿完整預期輸出

```
case1: count=2 a=5 b=6
case2: count=1 a=5 b=-1
case3: count=2 a=5 b=6
case4: count=2 a=5 b=6
case5: count=1 a=5 b=-1
```

117 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

sscanf是本次新增的測試支援，並非原頁已使用。只把資料來源從stdin換成固定字串，不用它模擬終端等待。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E21 觀察 scanf 部分成功後的狀態](#ex-7)[E23 比較 %c 與前導空白的讀取 →](#ex-8)

E23原稿範例格式化輸入輸出CH1–4


<a id="toc-ch1-23"></a>

# 比較 %c 與前導空白的讀取

08\_scan\_char.c4 組原稿測試

**原稿索引：**08\_scan\_char.c　原檔：31　新版：題目 55 / 講解 56
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-8/problem)[02 解題說明](#ex-8/solution)[03 完整程式](#ex-8/code)[04 測試資料](#ex-8/tests)[05 來源與提醒](#ex-8/tips)

01

## 完整題目

先確認規格，再寫程式

先讀一個整數，再讀一個原始字元與一個跳過空白的字元。

### 輸入與限制

輸入 123、換行、A、換行。

### 應產生的輸出

整數、raw 是否為換行、最後讀到的字元。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
123
A
```

6 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
n=123
raw=NEWLINE
skipped=A
```

28 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

數值讀取只消耗數字；輸入中的換行仍留在串流。

**STEP 02**

用 %c 讀取 raw，直接觀察那個換行。

**STEP 03**

再用「空格＋%c」讀下一個非空白字元 A。

### 原稿解題示例

123↵A↵ → raw=NEWLINE；skipped=A

03

## 完整程式碼

每份程式均有獨立 main

08\_scan\_char.c

完整程式 · 26 行 · 內容與原稿逐字相同

```
/* 08_scan_char.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 31.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>

int main(void)
{
    int n;
    char raw, skipped;
    if (scanf("%d", &n) != 1) {
        puts("Input error");
        return 1;
    }
    if (scanf("%c", &raw) != 1 || scanf(" %c", &skipped) != 1) {
        puts("Input error");
        return 1;
    }
    printf("n=%d\n", n);
    if (raw == '\n') puts("raw=NEWLINE");
    else if (raw == ' ') puts("raw=SPACE");
    else printf("raw=%c\n", raw);
    printf("skipped=%c\n", skipped);
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/08_scan_char.c -o example`

04


## 測試資料

4 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E23-T01**1. 測試1**原稿測試 · 6 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
123
A
```

6 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
n=123
raw=NEWLINE
skipped=A
```

28 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E23-T02**2. 測試2**原稿測試 · 8 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
123   A
```

8 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
n=123
raw=SPACE
skipped=A
```

26 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E23-T03**3. 測試3**原稿測試 · 2 input bytes · 完整字串核對exit 1 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 1

返回碼 1｜完整字串核對

STDIN · 完整輸入

```
x
```

2 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Input error
```

12 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E23-T04**4. 測試4**原稿測試 · 3 input bytes · 完整字串核對exit 1 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 1

返回碼 1｜完整字串核對

STDIN · 完整輸入

```
123
```

3 bytes · 最後沒有換行，直接 EOF

STDOUT · 原稿完整預期輸出

```
Input error
```

12 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

原頁為兩個替代方案；本次將兩種讀取接在同一示範輸入上，讓它們依序消耗不同字元，並明確印出 raw 與 skipped。不是把同一串流倒回重讀。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E22 重現五組分隔符匹配實驗](#ex-30)[E24 親自觀察尾端空白指令的等待 →](#ex-31)

E24原稿範例格式化輸入輸出CH1–4


<a id="toc-ch1-24"></a>

# 親自觀察尾端空白指令的等待

31\_scan\_trailing\_space.c3 組原稿測試

**原稿索引：**31\_scan\_trailing\_space.c　原檔：32　新版：題目 57 / 講解 58
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-31/problem)[02 解題說明](#ex-31/solution)[03 完整程式](#ex-31/code)[04 測試資料](#ex-31/tests)[05 來源與提醒](#ex-31/tips)

01

## 完整題目

先確認規格，再寫程式

分兩階段讀取：第一個%d立即結束；第二個%d\n需繼續看到非空白或EOF。

### 輸入與限制

先輸入7↵；再輸入8↵，最後補X↵或送出EOF。

### 應產生的輸出

plain=7；trailing=8；下一個未消耗字元X。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
7
8
X
```

6 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
Stage 1: enter an integer (plain %d).
plain=7
Stage 2: enter another integer, then X or EOF (%d\n).
trailing=8
next=X
```

118 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

先執行不含尾端空白的%d，看到第一段完成。

**STEP 02**

再執行%d\n；只按Enter可能尚未滿足尾端空白指令。

**STEP 03**

輸入X讓讀取結束，getchar確認X未被空白指令消耗。

### 原稿解題示例

7↵8↵X↵ → plain=7，trailing=8，next=X

03

## 完整程式碼

每份程式均有獨立 main

31\_scan\_trailing\_space.c

完整程式 · 29 行 · 內容與原稿逐字相同

```
/* 31_scan_trailing_space.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 32.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>

int main(void)
{
    int plain, trailing;
    puts("Stage 1: enter an integer (plain %d).");
    fflush(stdout);
    if (scanf("%d", &plain) != 1) {
        puts("Input error");
        return 1;
    }
    printf("plain=%d\n", plain);
    puts("Stage 2: enter another integer, then X or EOF (%d\\n).");
    fflush(stdout);
    if (scanf("%d\n", &trailing) != 1) {
        puts("Input error");
        return 1;
    }
    printf("trailing=%d\n", trailing);
    int next = getchar();
    if (next == EOF) puts("next=EOF");
    else printf("next=%c\n", next);
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/31_scan_trailing_space.c -o example`

04


## 測試資料

3 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E24-T01**1. 測試1**原稿測試 · 6 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
7
8
X
```

6 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Stage 1: enter an integer (plain %d).
plain=7
Stage 2: enter another integer, then X or EOF (%d\n).
trailing=8
next=X
```

118 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E24-T02**2. 測試2**原稿測試 · 4 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
7
8
```

4 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Stage 1: enter an integer (plain %d).
plain=7
Stage 2: enter another integer, then X or EOF (%d\n).
trailing=8
next=EOF
```

120 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E24-T03**3. 測試3**原稿測試 · 4 input bytes · 完整字串核對exit 1 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 1

返回碼 1｜完整字串核對

STDIN · 完整輸入

```
abc
```

4 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Stage 1: enter an integer (plain %d).
Input error
```

50 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

這支程式刻意展示互動等待，不是推薦輸入模板。新增fflush(stdout)只確保提示顯示，從未使用fflush(stdin)。自動測試以完整重導輸入或EOF終止；另有互動等待驗證。

互動操作時第二階段只輸入8與Enter可能會等待；補X與Enter即可。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E23 比較 %c 與前導空白的讀取](#ex-8)[E25 將兩個分數相加且不先約分 →](#ex-9)

E25原稿範例格式化輸入輸出CH1–4


<a id="toc-ch1-25"></a>

# 將兩個分數相加且不先約分

09\_fractions.c8 組原稿測試

**原稿索引：**09\_fractions.c　原檔：33, 34　新版：題目 59 / 講解 60, 61
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-9/problem)[02 解題說明](#ex-9/solution)[03 完整程式](#ex-9/code)[04 測試資料](#ex-9/tests)[05 來源與提醒](#ex-9/tips)

01

## 完整題目

先確認規格，再寫程式

保留整數分子與分母，透過交叉相乘計算和；不先做整數除法。

### 輸入與限制

依序輸入 n1/d1 與 n2/d2；分子 −100..100，分母 1..100。

### 應產生的輸出

Sum: numerator/denominator；本章不約分。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
5/6
3/4
```

8 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
Sum: 38/24
```

11 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

先完成兩次 %d / %d 讀取；/ 是必須匹配的普通字元。

**STEP 02**

驗證分子、分母範圍，確保乘積與相加不超出保守 int 範圍。

**STEP 03**

分子交叉相乘後相加，分母相乘；最後輸出兩個整數。

### 原稿解題示例

5/6 + 3/4 → Sum: 38/24

03

## 完整程式碼

每份程式均有獨立 main

09\_fractions.c

完整程式 · 26 行 · 內容與原稿逐字相同

```
/* 09_fractions.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 33, 34.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>

int main(void)
{
    int n1, d1, n2, d2;
    int numerator, denominator;
    if (scanf("%d / %d", &n1, &d1) != 2 ||
        scanf("%d / %d", &n2, &d2) != 2) {
        puts("Input error");
        return 1;
    }
    if (n1 < -100 || n1 > 100 || n2 < -100 || n2 > 100 ||
        d1 < 1 || d1 > 100 || d2 < 1 || d2 > 100) {
        puts("Range error");
        return 1;
    }
    numerator = n1 * d2 + n2 * d1;
    denominator = d1 * d2;
    printf("Sum: %d/%d\n", numerator, denominator);
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/09_fractions.c -o example`

04


## 測試資料

8 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E25-T01**1. 測試1**原稿測試 · 8 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
5/6
3/4
```

8 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Sum: 38/24
```

11 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E25-T02**2. 測試2**原稿測試 · 12 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
5 / 6
3 / 4
```

12 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Sum: 38/24
```

11 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E25-T03**3. 測試3**原稿測試 · 9 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
-1/2
1/2
```

9 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Sum: 0/4
```

9 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E25-T04**4. 測試4**原稿測試 · 16 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
100/100
100/100
```

16 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Sum: 20000/10000
```

17 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E25-T05**5. 測試5**原稿測試 · 8 input bytes · 完整字串核對exit 1 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 1

返回碼 1｜完整字串核對

STDIN · 完整輸入

```
5/0
3/4
```

8 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Range error
```

12 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E25-T06**6. 測試6**原稿測試 · 10 input bytes · 完整字串核對exit 1 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 1

返回碼 1｜完整字串核對

STDIN · 完整輸入

```
101/2
1/2
```

10 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Range error
```

12 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E25-T07**7. 測試7**原稿測試 · 8 input bytes · 完整字串核對exit 1 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 1

返回碼 1｜完整字串核對

STDIN · 完整輸入

```
5,6
3/4
```

8 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Input error
```

12 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E25-T08**8. 測試8**原稿測試 · 0 input bytes · 完整字串核對exit 1 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 1

返回碼 1｜完整字串核對

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿完整預期輸出

```
Input error
```

12 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

保留原投影片的未約分語意、格式與範圍；補上標頭、main、宣告及完整防護。未加入最大公因數或迴圈。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E24 親自觀察尾端空白指令的等待](#ex-31)[E26 用小實驗驗證四題格式化檢核 →](#ex-32)

E26原稿範例格式化輸入輸出CH1–4


<a id="toc-ch1-26"></a>

# 用小實驗驗證四題格式化檢核

32\_quiz\_io.c1 組原稿測試

**原稿索引：**32\_quiz\_io.c　原檔：35　新版：題目 62 / 講解 63
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-32/problem)[02 解題說明](#ex-32/solution)[03 完整程式](#ex-32/code)[04 測試資料](#ex-32/tests)[05 來源與提醒](#ex-32/tips)

01

## 完整題目

先確認規格，再寫程式

將欄寬、分隔符失敗、剩餘換行與double輸入分成四個互不干擾的測試。

### 輸入與限制

皆為固定資料；sscanf是本次新增測試支援。

### 應產生的輸出

| 040|、count=1、raw為換行、x=3.5。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 範例輸出

```
|  040|
slash: count=1 a=5 b=-1
char: count=2 n=123 newline=1
double: count=1 x=3.5
```

84 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

先用直線框出五格，計算補零與補空白的不同。

**STEP 02**

以獨立字串驗證/匹配失敗與數字後的換行。

**STEP 03**

最後以%lf配double，避免前一組剩餘輸入干擾下一題。

### 原稿解題示例

四題結果：040前兩格空白、1、換行、%lf

03

## 完整程式碼

每份程式均有獨立 main

32\_quiz\_io.c

完整程式 · 22 行 · 內容與原稿逐字相同

```
/* 32_quiz_io.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 35.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>

int main(void)
{
    printf("|%5.3d|\n", 40);
    int a = -1, b = -1;
    int count = sscanf("5 / 6", "%d/%d", &a, &b);
    printf("slash: count=%d a=%d b=%d\n", count, a, b);
    int n = 0;
    char ch = '?';
    count = sscanf("123\nA\n", "%d%c", &n, &ch);
    printf("char: count=%d n=%d newline=%d\n", count, n, ch == '\n');
    double x = 0.0;
    count = sscanf("3.5", "%lf", &x);
    printf("double: count=%d x=%.1f\n", count, x);
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/32_quiz_io.c -o example`

04


## 測試資料

1 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E26-T01**1. 測試1**原稿測試 · 0 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿完整預期輸出

```
|  040|
slash: count=1 a=5 b=-1
char: count=2 n=123 newline=1
double: count=1 x=3.5
```

84 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

將備忘錄答案實作成固定輸入測試；未將本次sscanf測試支援說成原教材程式。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E25 將兩個分數相加且不先約分](#ex-9)[E27 拆解一元與二元運算 →](#ex-33)

E27原稿範例運算式與狀態CH1–4


<a id="toc-ch1-27"></a>

# 拆解一元與二元運算

33\_unary\_binary.c1 組原稿測試

**原稿索引：**33\_unary\_binary.c　原檔：36　新版：題目 64 / 講解 65
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-33/problem)[02 解題說明](#ex-33/solution)[03 完整程式](#ex-33/code)[04 測試資料](#ex-33/tests)[05 來源與提醒](#ex-33/tips)

01

## 完整題目

先確認規格，再寫程式

為原式−a+b×2指定小整數，分別輸出子式與整體結果。

### 輸入與限制

本次新增固定a=3、b=4。

### 應產生的輸出

−a=−3、b×2=8、result=5。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 範例輸出

```
-a=-3 b*2=8 result=5
```

21 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

一元−只取a，得到−3。

**STEP 02**

二元乘法取b與2，得到8。

**STEP 03**

加法組合兩個子結果；不把負號一律當成二元相減。

### 原稿解題示例

a=3，b=4 → −3+8=5

03

## 完整程式碼

每份程式均有獨立 main

33\_unary\_binary.c

完整程式 · 14 行 · 內容與原稿逐字相同

```
/* 33_unary_binary.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 36.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>

int main(void)
{
    int a = 3, b = 4;
    int result = -a + b * 2;
    printf("-a=%d b*2=%d result=%d\n", -a, b * 2, result);
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/33_unary_binary.c -o example`

04


## 測試資料

1 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E27-T01**1. 測試1**原稿測試 · 0 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿完整預期輸出

```
-a=-3 b*2=8 result=5
```

21 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

原頁只列符號a與b；3與4是本次明示加入的測试初值。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E26 用小實驗驗證四題格式化檢核](#ex-32)[E28 比較兩筆量測值的平均 →](#ex-34)

E28原稿範例運算式與狀態CH1–4


<a id="toc-ch1-28"></a>

# 比較兩筆量測值的平均

34\_average\_division.c1 組原稿測試

**原稿索引：**34\_average\_division.c　原檔：37　新版：題目 66 / 講解 67
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-34/problem)[02 解題說明](#ex-34/solution)[03 完整程式](#ex-34/code)[04 測試資料](#ex-34/tests)[05 來源與提醒](#ex-34/tips)

01

## 完整題目

先確認規格，再寫程式

計算80與81的平均，對照整數除法及在除法前引入浮點數。

### 輸入與限制

固定a=80、b=81。

### 應產生的輸出

integer division=80.0；floating division=80.5。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 範例輸出

```
integer division=80.0
floating division=80.5
```

45 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

先求a+b=161；若除以整數2，商先截為80。

**STEP 02**

改成2.0後，除法才會保留小數而得到80.5。

**STEP 03**

將兩式分別存入double再輸出，顯示左側型別不會補回小數。

### 原稿解題示例

(80+81)/2 → 80.0；/2.0 → 80.5

03

## 完整程式碼

每份程式均有獨立 main

34\_average\_division.c

完整程式 · 16 行 · 內容與原稿逐字相同

```
/* 34_average_division.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 37.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>

int main(void)
{
    int a = 80, b = 81;
    double truncated = (a + b) / 2;
    double fractional = (a + b) / 2.0;
    printf("integer division=%.1f\n", truncated);
    printf("floating division=%.1f\n", fractional);
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/34_average_division.c -o example`

04


## 測試資料

1 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E28-T01**1. 測試1**原稿測試 · 0 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿完整預期輸出

```
integer division=80.0
floating division=80.5
```

45 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

保留原值；原備忘錄16\_comma\_and\_average.c的提及更新為此檔與46\_comma\_operator.c，拆為兩個獨立範例。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E27 拆解一元與二元運算](#ex-33)[E29 驗證正負整數的商與餘數 →](#ex-35)

E29原稿範例運算式與狀態CH1–4


<a id="toc-ch1-29"></a>

# 驗證正負整數的商與餘數

35\_quotient\_remainder.c1 組原稿測試

**原稿索引：**35\_quotient\_remainder.c　原檔：38　新版：題目 68 / 講解 69
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-35/problem)[02 解題說明](#ex-35/solution)[03 完整程式](#ex-35/code)[04 測試資料](#ex-35/tests)[05 來源與提醒](#ex-35/tips)

01

## 完整題目

先確認規格，再寫程式

列出17與3的四種正負組合，驗證a=(a/b)×b+a%b。

### 輸入與限制

固定±17、±3；除數非零且商可表示。

### 應產生的輸出

每組a、b、q、r及還原值。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 範例輸出

```
17 3: q=5 r=2 rebuild=17
17 -3: q=-5 r=2 rebuild=17
-17 3: q=-5 r=-2 rebuild=-17
-17 -3: q=5 r=-2 rebuild=-17
```

110 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

依C99規則將整數商朝0截斷。

**STEP 02**

餘數配合商還原被除數；非零餘數與被除數同號。

**STEP 03**

用四次固定計算核對表格，不測除零或不可表示商。

### 原稿解題示例

−17/3=−5；−17%3=−2

03

## 完整程式碼

每份程式均有獨立 main

35\_quotient\_remainder.c

完整程式 · 19 行 · 內容與原稿逐字相同

```
/* 35_quotient_remainder.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 38.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>

int main(void)
{
    int a = 17, b = 3;
    printf("%d %d: q=%d r=%d rebuild=%d\n", a, b, a/b, a%b, (a/b)*b+a%b);
    a = 17; b = -3;
    printf("%d %d: q=%d r=%d rebuild=%d\n", a, b, a/b, a%b, (a/b)*b+a%b);
    a = -17; b = 3;
    printf("%d %d: q=%d r=%d rebuild=%d\n", a, b, a/b, a%b, (a/b)*b+a%b);
    a = -17; b = -3;
    printf("%d %d: q=%d r=%d rebuild=%d\n", a, b, a/b, a%b, (a/b)*b+a%b);
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/35_quotient_remainder.c -o example`

04


## 測試資料

1 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E29-T01**1. 測試1**原稿測試 · 0 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿完整預期輸出

```
17 3: q=5 r=2 rebuild=17
17 -3: q=-5 r=2 rebuild=17
-17 3: q=-5 r=-2 rebuild=-17
-17 -3: q=5 r=-2 rebuild=-17
```

110 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

以重複敘述而非迴圈呈現四列，避免提前要求後章語法；完全沿用原表數字。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E28 比較兩筆量測值的平均](#ex-34)[E30 把總秒數拆成時、分、秒 →](#ex-10)

E30原稿範例運算式與狀態CH1–4


<a id="toc-ch1-30"></a>

# 把總秒數拆成時、分、秒

10\_duration.c9 組原稿測試

**原稿索引：**10\_duration.c　原檔：39　新版：題目 70 / 講解 71
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-10/problem)[02 解題說明](#ex-10/solution)[03 完整程式](#ex-10/code)[04 測試資料](#ex-10/tests)[05 來源與提醒](#ex-10/tips)

01

## 完整題目

先確認規格，再寫程式

將非負持續秒數拆成完整小時、剩餘分鐘與秒數。

### 輸入與限制

一個整數秒數，0..30000。

### 應產生的輸出

hours:minutes:seconds；分、秒固定補到兩位。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
3671
```

5 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
1:01:11
```

8 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

先以 /3600 求完整小時，從總量中切出最大單位。

**STEP 02**

用 %3600 保留不足一小時的部分，再 /60 求分鐘。

**STEP 03**

秒數為 %60；以 %02d 只改顯示，不改值。

### 原稿解題示例

3671 → 1:01:11

03

## 完整程式碼

每份程式均有獨立 main

10\_duration.c

完整程式 · 24 行 · 內容與原稿逐字相同

```
/* 10_duration.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 39.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>

int main(void)
{
    int seconds, hours, minutes, remainder;
    if (scanf("%d", &seconds) != 1) {
        puts("Input error");
        return 1;
    }
    if (seconds < 0 || seconds > 30000) {
        puts("Range error");
        return 1;
    }
    hours = seconds / 3600;
    minutes = (seconds % 3600) / 60;
    remainder = seconds % 60;
    printf("%d:%02d:%02d\n", hours, minutes, remainder);
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/10_duration.c -o example`

04


## 測試資料

9 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E30-T01**1. 測試1**原稿測試 · 5 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
3671
```

5 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
1:01:11
```

8 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E30-T02**2. 測試2**原稿測試 · 2 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
0
```

2 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
0:00:00
```

8 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E30-T03**3. 測試3**原稿測試 · 3 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
59
```

3 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
0:00:59
```

8 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E30-T04**4. 測試4**原稿測試 · 3 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
60
```

3 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
0:01:00
```

8 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E30-T05**5. 測試5**原稿測試 · 5 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
3600
```

5 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
1:00:00
```

8 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E30-T06**6. 測試6**原稿測試 · 6 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
30000
```

6 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
8:20:00
```

8 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E30-T07**7. 測試7**原稿測試 · 3 input bytes · 完整字串核對exit 1 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 1

返回碼 1｜完整字串核對

STDIN · 完整輸入

```
-1
```

3 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Range error
```

12 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E30-T08**8. 測試8**原稿測試 · 6 input bytes · 完整字串核對exit 1 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 1

返回碼 1｜完整字串核對

STDIN · 完整輸入

```
30001
```

6 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Range error
```

12 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E30-T09**9. 測試9**原稿測試 · 4 input bytes · 完整字串核對exit 1 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 1

返回碼 1｜完整字串核對

STDIN · 完整輸入

```
abc
```

4 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Input error
```

12 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

保留原備忘錄給定的0..30000界線；此為持續時間，不加入日期、跨日與時區。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E29 驗證正負整數的商與餘數](#ex-35)[E31 比較括號改變前後的運算樹 →](#ex-36)

E31原稿範例運算式與狀態CH1–4


<a id="toc-ch1-31"></a>

# 比較括號改變前後的運算樹

36\_precedence.c1 組原稿測試

**原稿索引：**36\_precedence.c　原檔：40　新版：題目 72 / 講解 73
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-36/problem)[02 解題說明](#ex-36/solution)[03 完整程式](#ex-36/code)[04 測試資料](#ex-36/tests)[05 來源與提醒](#ex-36/tips)

01

## 完整題目

先確認規格，再寫程式

對同一組a、b、c，計算a+b\*c與(a+b)\*c。

### 輸入與限制

固定a=2、b=3、c=4。

### 應產生的輸出

無額外括號14；加括號20。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 範例輸出

```
a+b*c=14
(a+b)*c=20
```

20 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

先把a+b\*c分組為a+(b\*c)，乘法子樹先形成一個值。

**STEP 02**

括號把另一式改成(a+b)\*c，得到不同公式。

**STEP 03**

分別印兩個結果；不由分組推論所有求值時間順序。

### 原稿解題示例

2+3\*4=14；(2+3)\*4=20

03

## 完整程式碼

每份程式均有獨立 main

36\_precedence.c

完整程式 · 14 行 · 內容與原稿逐字相同

```
/* 36_precedence.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 40.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>

int main(void)
{
    int a = 2, b = 3, c = 4;
    printf("a+b*c=%d\n", a + b * c);
    printf("(a+b)*c=%d\n", (a + b) * c);
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/36_precedence.c -o example`

04


## 測試資料

1 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E31-T01**1. 測試1**原稿測試 · 0 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿完整預期輸出

```
a+b*c=14
(a+b)*c=20
```

20 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

沿用原圖的固定2、3、4與两種分組。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E30 把總秒數拆成時、分、秒](#ex-10)[E32 用括號驗證結合性 →](#ex-37)

E32原稿範例運算式與狀態CH1–4


<a id="toc-ch1-32"></a>

# 用括號驗證結合性

37\_associativity.c1 組原稿測試

**原稿索引：**37\_associativity.c　原檔：41　新版：題目 74 / 講解 75
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-37/problem)[02 解題說明](#ex-37/solution)[03 完整程式](#ex-37/code)[04 測試資料](#ex-37/tests)[05 來源與提醒](#ex-37/tips)

01

## 完整題目

先確認規格，再寫程式

驗證連續減法、乘除以及連鎖賦值的語法分組。

### 輸入與限制

固定20、5、3、2；i/j/k初始均有值。

### 應產生的輸出

20−5−3=12；20/5\*2=8；連鎖後i=j=k=0。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 範例輸出

```
20-5-3=12
20-(5-3)=18
20/5*2=8
i=0 j=0 k=0
```

43 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

連續減法補成(20−5)−3，不能補成20−(5−3)。

**STEP 02**

同級乘除由左分組，先取20/5的商再乘2。

**STEP 03**

賦值右結合，最內層k=0的值逐層寫到j及i。

### 原稿解題示例

20/5\*2 → (20/5)\*2 → 8

03

## 完整程式碼

每份程式均有獨立 main

37\_associativity.c

完整程式 · 17 行 · 內容與原稿逐字相同

```
/* 37_associativity.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 41.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>

int main(void)
{
    int i = 1, j = 2, k = 3;
    printf("20-5-3=%d\n", 20 - 5 - 3);
    printf("20-(5-3)=%d\n", 20 - (5 - 3));
    printf("20/5*2=%d\n", 20 / 5 * 2);
    i = j = k = 0;
    printf("i=%d j=%d k=%d\n", i, j, k);
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/37_associativity.c -o example`

04


## 測試資料

1 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E32-T01**1. 測試1**原稿測試 · 0 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿完整預期輸出

```
20-5-3=12
20-(5-3)=18
20/5*2=8
i=0 j=0 k=0
```

43 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

新增對照括號結果18與初始化1/2/3，使連鎖更新可觀察；原表結論不變。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E31 比較括號改變前後的運算樹](#ex-36)[E33 追蹤連鎖賦值的型別轉換 →](#ex-38)

E33刻意保留診斷對照運算式與狀態CH1–4


<a id="toc-ch1-33"></a>

# 追蹤連鎖賦值的型別轉換

38\_assignment\_value.c1 組原稿測試

**原稿索引：**38\_assignment\_value.c　原檔：42　新版：題目 76 / 講解 77
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-38/problem)[02 解題說明](#ex-38/solution)[03 完整程式](#ex-38/code)[04 測試資料](#ex-38/tests)[05 來源與提醒](#ex-38/tips)

01

## 完整題目

先確認規格，再寫程式

執行f=i=33.3f，觀察內層賦值先轉int後提供什麼值。

### 輸入與限制

int i、float f；常數33.3f。

### 應產生的輸出

i=33、f=33.0。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 範例輸出

```
i=33 f=33.0
```

12 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

先辨識右結合：f=(i=33.3f)。

**STEP 02**

33.3f寫入int時得到33；內層運算式提供int值33。

**STEP 03**

外層把33轉成float給f，因此不是原常數33.3。

### 原稿解題示例

33.3f → int 33 → float 33.0

03

## 完整程式碼

每份程式均有獨立 main

38\_assignment\_value.c

完整程式 · 15 行 · 內容與原稿逐字相同

```
/* 38_assignment_value.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 42.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>

int main(void)
{
    int i;
    float f;
    f = i = 33.3f;
    printf("i=%d f=%.1f\n", i, f);
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/38_assignment_value.c -o example`

此範例原稿已標示「刻意保留診斷對照」。程式中的教學反例與警告沒有因格式轉換而刪除；詳細界線見本題第 05 區。

04


## 測試資料

1 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E33-T01**1. 測試1**原稿測試 · 0 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿完整預期輸出

```
i=33 f=33.0
```

12 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

原式完整保留。Clang可能就常數33.3f到int的刻意截斷提出警告；此為本題要觀察的轉換。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E32 用括號驗證結合性](#ex-37)[E34 辨識可修改的賦值目標 →](#ex-39)

E34原稿範例運算式與狀態CH1–4


<a id="toc-ch1-34"></a>

# 辨識可修改的賦值目標

39\_lvalue\_safe.c1 組原稿測試

**原稿索引：**39\_lvalue\_safe.c　原檔：43　新版：題目 78 / 講解 79
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-39/problem)[02 解題說明](#ex-39/solution)[03 完整程式](#ex-39/code)[04 測試資料](#ex-39/tests)[05 來源與提醒](#ex-39/tips)

01

## 完整題目

先確認規格，再寫程式

只執行合法的i=3；將常數、運算結果及const目標反例作文字分類。

### 輸入與限制

固定const limit=10；不修改limit。

### 應產生的輸出

i=3、limit=10，以及反例分類文字。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 範例輸出

```
i=3 limit=10
12=i, i+j=0, -i=j: not modifiable lvalues.
limit=20: the const object cannot be modified.
```

103 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

先問左側是否代表一個物件，再問它能否被修改。

**STEP 02**

只對可修改的i做賦值，const物件保持原值。

**STEP 03**

不把12=i或i+j=0拿來執行，因為它們違反語言限制。

### 原稿解題示例

i=3可執行；12=i與limit=20只作反例

03

## 完整程式碼

每份程式均有獨立 main

39\_lvalue\_safe.c

完整程式 · 18 行 · 內容與原稿逐字相同

```
/* 39_lvalue_safe.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 43.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>

int main(void)
{
    int i = 0;
    const int limit = 10;
    i = 3;
    printf("i=%d limit=%d\n", i, limit);
    puts("12=i, i+j=0, -i=j: not modifiable lvalues.");
    puts("limit=20: the const object cannot be modified.");
    /* Invalid counterexamples are intentionally not executable statements. */
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/39_lvalue_safe.c -o example`

04


## 測試資料

1 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E34-T01**1. 測試1**原稿測試 · 0 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿完整預期輸出

```
i=3 limit=10
12=i, i+j=0, -i=j: not modifiable lvalues.
limit=20: the const object cannot be modified.
```

103 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

原頁以表格列不可編譯反例；本次提供分類器及合法側，不聲稱所有原反例可變成原樣可執行檔。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E33 追蹤連鎖賦值的型別轉換](#ex-38)[E35 追蹤庫存與複合賦值 →](#ex-40)

E35原稿範例運算式與狀態CH1–4


<a id="toc-ch1-35"></a>

# 追蹤庫存與複合賦值

40\_compound\_assignment.c1 組原稿測試

**原稿索引：**40\_compound\_assignment.c　原檔：44　新版：題目 80 / 講解 81
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-40/problem)[02 解題說明](#ex-40/solution)[03 完整程式](#ex-40/code)[04 測試資料](#ex-40/tests)[05 來源與提醒](#ex-40/tips)

01

## 完整題目

先確認規格，再寫程式

先處理42件庫存的售出與補貨，再比較\*=分組、+=與=+。

### 輸入與限制

stock=42；售7補5；另設i=2,j=3,k=4。

### 應產生的輸出

庫存42→35→40；i\*=j+k為14；+=得13、=+得3。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 範例輸出

```
start=42
after sale=35
after restock=40
i*=j+k: 14
i+=j: 13
i=+j: 3
```

68 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

對同一stock逐步更新，逐行印出新狀態。

**STEP 02**

\*=右側的j+k視為整組，不可展開成i\*j+k。

**STEP 03**

比較+=與=+前重設i=10，避免把兩個獨立實驗接續計算。

### 原稿解題示例

42 − 7 + 5 → stock=40

03

## 完整程式碼

每份程式均有獨立 main

40\_compound\_assignment.c

完整程式 · 24 行 · 內容與原稿逐字相同

```
/* 40_compound_assignment.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 44.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>

int main(void)
{
    int stock = 42;
    printf("start=%d\n", stock);
    stock -= 7;
    printf("after sale=%d\n", stock);
    stock += 5;
    printf("after restock=%d\n", stock);
    int i = 2, j = 3, k = 4;
    i *= j + k;
    printf("i*=j+k: %d\n", i);
    i = 10; i += j;
    printf("i+=j: %d\n", i);
    i = 10; i =+ j;
    printf("i=+j: %d\n", i);
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/40_compound_assignment.c -o example`

04


## 測試資料

1 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E35-T01**1. 測試1**原稿測試 · 0 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿完整預期輸出

```
start=42
after sale=35
after restock=40
i*=j+k: 14
i+=j: 13
i=+j: 3
```

68 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

庫存與+=例沿用原內容；為\*=j+k新增小整數初值2、3、4。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E34 辨識可修改的賦值目標](#ex-39)[E36 分開觀察遞增的值與狀態 →](#ex-41)

E36原稿範例運算式與狀態CH1–4


<a id="toc-ch1-36"></a>

# 分開觀察遞增的值與狀態

41\_pre\_post\_increment.c1 組原稿測試

**原稿索引：**41\_pre\_post\_increment.c　原檔：45　新版：題目 82 / 講解 83
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-41/problem)[02 解題說明](#ex-41/solution)[03 完整程式](#ex-41/code)[04 測試資料](#ex-41/tests)[05 來源與提醒](#ex-41/tips)

01

## 完整題目

先確認規格，再寫程式

兩次都從i=1開始，分別執行x=++i與x=i++。

### 輸入與限制

每次實驗重設i=1。

### 應產生的輸出

前置x=2,i=2；後置x=1,i=2。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 範例輸出

```
prefix: x=2 i=2
postfix: x=1 i=2
```

33 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

前置先更新物件，這個運算式提供新值。

**STEP 02**

後置提供原值，但完整敘述結束後i已增加。

**STEP 03**

在下一個printf才印狀態，不把遞增與讀同一i塞入不同參數。

### 原稿解題示例

++i → x=2；i++ → x=1；兩者最後i都2

03

## 完整程式碼

每份程式均有獨立 main

41\_pre\_post\_increment.c

完整程式 · 17 行 · 內容與原稿逐字相同

```
/* 41_pre_post_increment.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 45.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>

int main(void)
{
    int i = 1, x;
    x = ++i;
    printf("prefix: x=%d i=%d\n", x, i);
    i = 1;
    x = i++;
    printf("postfix: x=%d i=%d\n", x, i);
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/41_pre_post_increment.c -o example`

04


## 測試資料

1 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E36-T01**1. 測試1**原稿測試 · 0 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿完整預期輸出

```
prefix: x=2 i=2
postfix: x=1 i=2
```

33 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

原兩個獨立例直接補成main，保留每次重設i=1。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E35 追蹤庫存與複合賦值](#ex-40)[E37 追蹤三組獨立的遞增運算式 →](#ex-11)

E37原稿範例運算式與狀態CH1–4


<a id="toc-ch1-37"></a>

# 追蹤三組獨立的遞增運算式

11\_expression\_trace.c1 組原稿測試

**原稿索引：**11\_expression\_trace.c　原檔：46　新版：題目 84 / 講解 85
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-11/problem)[02 解題說明](#ex-11/solution)[03 完整程式](#ex-11/code)[04 測試資料](#ex-11/tests)[05 來源與提醒](#ex-11/tips)

01

## 完整題目

先確認規格，再寫程式

對三組表格範例分別重設 i=1、j=2，再算 k 與最後狀態。

### 輸入與限制

固定初值；每一組都是獨立實驗。

### 應產生的輸出

逐組列出 i、j、k。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 範例輸出

```
case1: i=2 j=3 k=4
case2: i=2 j=3 k=3
case3: i=0 j=1 k=2
```

57 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

先辨識每個 ++／-- 提供舊值或新值，而不是只看最後狀態。

**STEP 02**

左右更新不同物件，用各自提供的值計算 k。

**STEP 03**

下一组前重設 i、j，避免沿用上一組已修改的狀態。

### 原稿解題示例

++i + j++ → i=2，j=3，k=4

03

## 完整程式碼

每份程式均有獨立 main

11\_expression\_trace.c

完整程式 · 20 行 · 內容與原稿逐字相同

```
/* 11_expression_trace.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 46.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>

int main(void)
{
    int i = 1, j = 2, k;
    k = ++i + j++;
    printf("case1: i=%d j=%d k=%d\n", i, j, k);
    i = 1; j = 2;
    k = i++ + j++;
    printf("case2: i=%d j=%d k=%d\n", i, j, k);
    i = 1; j = 2;
    k = --i + j--;
    printf("case3: i=%d j=%d k=%d\n", i, j, k);
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/11_expression_trace.c -o example`

04


## 測試資料

1 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E37-T01**1. 測試1**原稿測試 · 0 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿完整預期輸出

```
case1: i=2 j=3 k=4
case2: i=2 j=3 k=3
case3: i=0 j=1 k=2
```

57 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

保留原第46頁三組運算；補上重設初值與輸出。此程式不示範同一變數未排序的衝突讀寫。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E36 分開觀察遞增的值與狀態](#ex-41)[E38 逐層解出複合運算式 →](#ex-53)

E38原稿範例運算式與狀態CH1–4


<a id="toc-ch1-38"></a>

# 逐層解出複合運算式

53\_complex\_expression.c1 組原稿測試

**原稿索引：**53\_complex\_expression.c　原檔：47　新版：題目 86 / 講解 87
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-53/problem)[02 解題說明](#ex-53/solution)[03 完整程式](#ex-53/code)[04 測試資料](#ex-53/tests)[05 來源與提醒](#ex-53/tips)

01

## 完整題目

先確認規格，再寫程式

依原初值計算a=b+=c++−d+--e/−f，再列出六個變數。

### 輸入與限制

b=1,c=10,d=10,e=10,f=3；a只在賦值後讀取。

### 應產生的輸出

a=−2,b=−2,c=11,d=10,e=9,f=3。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 範例輸出

```
a=-2 b=-2 c=11 d=10 e=9 f=3
```

28 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

先標註提供值：c++給10、--e給9、−f給−3。

**STEP 02**

算术部分10−10+9/(−3)=−3；b加上它後成−2。

**STEP 03**

內層賦值提供−2再給a；最後分開印所有狀態。

### 原稿解題示例

右側−3 → b=−2 → a=−2；c=11、e=9

03

## 完整程式碼

每份程式均有獨立 main

53\_complex\_expression.c

完整程式 · 14 行 · 內容與原稿逐字相同

```
/* 53_complex_expression.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 47.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>

int main(void)
{
    int a, b = 1, c = 10, d = 10, e = 10, f = 3;
    a = b += c++ - d + --e / -f;
    printf("a=%d b=%d c=%d d=%d e=%d f=%d\n", a, b, c, d, e, f);
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/53_complex_expression.c -o example`

04


## 測試資料

1 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E38-T01**1. 測試1**原稿測試 · 0 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿完整預期輸出

```
a=-2 b=-2 c=11 d=10 e=9 f=3
```

28 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

原複合式與所有初值均完整保留；不以手算步驟宣稱編譯器必依此順序求值。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E37 追蹤三組獨立的遞增運算式](#ex-11)[E39 分開驗證分組與人為指定順序 →](#ex-42)

E39原稿範例運算式與狀態CH1–4


<a id="toc-ch1-39"></a>

# 分開驗證分組與人為指定順序

42\_grouping\_order.c1 組原稿測試

**原稿索引：**42\_grouping\_order.c　原檔：48　新版：題目 88 / 講解 89
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-42/problem)[02 解題說明](#ex-42/solution)[03 完整程式](#ex-42/code)[04 測試資料](#ex-42/tests)[05 來源與提醒](#ex-42/tips)

01

## 完整題目

先確認規格，再寫程式

對(a+b)\*(c-d)選定無衝突小整數，計算直接式及兩種明確分步版本。

### 輸入與限制

本次新增a=2,b=3,c=10,d=4。

### 應產生的輸出

直接式、先算左式、先算右式皆為30。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 範例輸出

```
direct=30 left-first=30 right-first=30
```

39 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

括號固定乘法的兩個運算元；它們只讀不同已初始化資料。

**STEP 02**

用分行敘述明確寫出先左後右與先右後左。

**STEP 03**

結果相同只因本例沒有相依副作用，不表示編譯器承諾固定次序。

### 原稿解題示例

(2+3)\*(10−4)=30；兩種分步路徑也都是30

03

## 完整程式碼

每份程式均有獨立 main

42\_grouping\_order.c

完整程式 · 20 行 · 內容與原稿逐字相同

```
/* 42_grouping_order.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 48.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>

int main(void)
{
    int a = 2, b = 3, c = 10, d = 4;
    int direct = (a + b) * (c - d);
    int left = a + b;
    int right = c - d;
    int left_first = left * right;
    right = c - d;
    left = a + b;
    int right_first = left * right;
    printf("direct=%d left-first=%d right-first=%d\n", direct, left_first, right_first);
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/42_grouping_order.c -o example`

04


## 測試資料

1 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E39-T01**1. 測試1**原稿測試 · 0 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿完整預期輸出

```
direct=30 left-first=30 right-first=30
```

39 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

本次新增固定初值與兩條明確分行計算。沒有透過執行結果推斷原式編譯器的實際求值順序。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E38 逐層解出複合運算式](#ex-53)[E40 將四種語言行為分開說明 →](#ex-43)

E40原稿範例運算式與狀態CH1–4


<a id="toc-ch1-40"></a>

# 將四種語言行為分開說明

43\_behavior\_classes.c1 組原稿測試

**原稿索引：**43\_behavior\_classes.c　原檔：49　新版：題目 90 / 講解 91
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-43/problem)[02 解題說明](#ex-43/solution)[03 完整程式](#ex-43/code)[04 測試資料](#ex-43/tests)[05 來源與提醒](#ex-43/tips)

01

## 完整題目

先確認規格，再寫程式

用實作範圍與無衝突運算實測，其他兩類只保留分類，不執行非法或未定義程式。

### 輸入與限制

本機limits.h；固定(2+3)\*(10−4)。

### 應產生的輸出

int上下界、純運算值30及兩種不可執行的分類。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿平台觀察值

```
INT_MIN=-2147483648 INT_MAX=2147483647
pure expression=30
12=i: constraint violation; not executed.
i*i++: undefined behavior; not executed.
```

141 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

此例含平台觀察值，請依原題前提判讀，不將本機型別範圍或浮點字面表示當成跨平台固定答案。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

限制違反要先修正，不替12=i預測執行輸出。

**STEP 02**

實作特性查本機界限；未指定順序不等於所有結果都不確定。

**STEP 03**

i\*i++是反例，只記錄分類，不以某次結果當語言保證。

### 原稿解題示例

INT範圍看本機；純運算30；i\*i++不執行

03

## 完整程式碼

每份程式均有獨立 main

43\_behavior\_classes.c

完整程式 · 16 行 · 內容與原稿逐字相同

```
/* 43_behavior_classes.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 49.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>
#include <limits.h>

int main(void)
{
    printf("INT_MIN=%d INT_MAX=%d\n", INT_MIN, INT_MAX);
    printf("pure expression=%d\n", (2 + 3) * (10 - 4));
    puts("12=i: constraint violation; not executed.");
    puts("i*i++: undefined behavior; not executed.");
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/43_behavior_classes.c -o example`

04


## 測試資料

1 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E40-T01**1. 測試1**原稿測試 · 0 input bytes · 平台觀察紀錄exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜依模式或數值核對；以下列出本次GCC環境觀察值

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿平台觀察值

```
INT_MIN=-2147483648 INT_MAX=2147483647
pure expression=30
12=i: constraint violation; not executed.
i*i++: undefined behavior; not executed.
```

141 bytes · 保留原稿的空白、tab 與換行

上方是原 HTML 記錄的 GCC 觀察值，本次環境輸出與其一致；不是所有平台都必須逐字相同的答案。原稿未附具體模式／數值判準，本次未補寫該判準。

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

新增安全分類展示，不試圖將未定義行為列為有限結果集合。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E39 分開驗證分組與人為指定順序](#ex-42)[E41 把衝突副作用改成明確步驟 →](#ex-15)

E41原稿範例運算式與狀態CH1–4


<a id="toc-ch1-41"></a>

# 把衝突副作用改成明確步驟

15\_safe\_rewrite.c1 組原稿測試

**原稿索引：**15\_safe\_rewrite.c　原檔：50　新版：題目 92 / 講解 93
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-15/problem)[02 解題說明](#ex-15/solution)[03 完整程式](#ex-15/code)[04 測試資料](#ex-15/tests)[05 來源與提醒](#ex-15/tips)

01

## 完整題目

先確認規格，再寫程式

依「先用舊a計算b，再改a」的新明確意圖，重寫原反例。

### 輸入與限制

固定 a=5；另示範 i=2 時保存舊值後再遞增。

### 應產生的輸出

a=1、b=7、c=6；第二例 old\_i=2、i=3、j=4。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 範例輸出

```
a=1 b=7 c=6
old_i=2 i=3 j=4
```

28 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

先說明演算法意圖，而不是替未定義原式猜一個答案。

**STEP 02**

拆成 b=a+2、a=1、c=b-a 三個完整敘述。

**STEP 03**

需要舊值時先保存，再更新；每一步完成後才讀下一個狀態。

### 原稿解題示例

a=5 → b=7 → a=1 → c=6

03

## 完整程式碼

每份程式均有獨立 main

15\_safe\_rewrite.c

完整程式 · 23 行 · 內容與原稿逐字相同

```
/* 15_safe_rewrite.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 50.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>

int main(void)
{
    int a = 5, b, c;
    /* Original counterexample is intentionally NOT executed:
       c = (b = a + 2) - (a = 1); */
    b = a + 2;
    a = 1;
    c = b - a;
    printf("a=%d b=%d c=%d\n", a, b, c);
    int i = 2;
    int old_i = i;
    i++;
    int j = old_i * old_i;
    printf("old_i=%d i=%d j=%d\n", old_i, i, j);
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/15_safe_rewrite.c -o example`

04


## 測試資料

1 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E41-T01**1. 測試1**原稿測試 · 0 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿完整預期輸出

```
a=1 b=7 c=6
old_i=2 i=3 j=4
```

28 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

第一段沿用原頁右側明確重寫；第二段實作原備忘錄提到的old\_i策略。兩者都不是聲稱保有未定義原式的標準結果。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E40 將四種語言行為分開說明](#ex-43)[E42 正確檢查分數是否在範圍內 →](#ex-44)

E42刻意保留診斷對照運算式與狀態CH1–4


<a id="toc-ch1-42"></a>

# 正確檢查分數是否在範圍內

44\_relational\_logical.c6 組原稿測試

**原稿索引：**44\_relational\_logical.c　原檔：51　新版：題目 94 / 講解 95
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-44/problem)[02 解題說明](#ex-44/solution)[03 完整程式](#ex-44/code)[04 測試資料](#ex-44/tests)[05 來源與提醒](#ex-44/tips)

01

## 完整題目

先確認規格，再寫程式

比較正確的0<=score && score<=100與原頁的連寫不等式。

### 輸入與限制

可表示int；教學限制score在−1000..1000。

### 應產生的輸出

正確range判斷與錯誤連寫判斷，皆用0/1表示。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
-5
```

3 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
score=-5 correct=0 chained=1
```

29 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

把下界與上界各變成一個比較，再用&&合併。

**STEP 02**

保留原錯誤式觀察：第一個比較先產生0或1。

**STEP 03**

再和100比較時總成立，故不能代表原數值的範圍。

### 原稿解題示例

score=−5 → correct=0，chained=1

03

## 完整程式碼

每份程式均有獨立 main

44\_relational\_logical.c

完整程式 · 24 行 · 內容與原稿逐字相同

```
/* 44_relational_logical.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 51.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>

int main(void)
{
    int score;
    if (scanf("%d", &score) != 1) {
        puts("Input error");
        return 1;
    }
    if (score < -1000 || score > 1000) {
        puts("Range error");
        return 1;
    }
    int correct = 0 <= score && score <= 100;
    /* Intentional logical mistake: observe compiler diagnostics. */
    int chained = 0 <= score <= 100;
    printf("score=%d correct=%d chained=%d\n", score, correct, chained);
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/44_relational_logical.c -o example`

此範例原稿已標示「刻意保留診斷對照」。程式中的教學反例與警告沒有因格式轉換而刪除；詳細界線見本題第 05 區。

04


## 測試資料

6 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E42-T01**1. 測試1**原稿測試 · 3 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
-5
```

3 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
score=-5 correct=0 chained=1
```

29 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E42-T02**2. 測試2**原稿測試 · 2 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
0
```

2 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
score=0 correct=1 chained=1
```

28 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E42-T03**3. 測試3**原稿測試 · 4 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
100
```

4 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
score=100 correct=1 chained=1
```

30 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E42-T04**4. 測試4**原稿測試 · 4 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
101
```

4 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
score=101 correct=0 chained=1
```

30 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E42-T05**5. 測試5**原稿測試 · 4 input bytes · 完整字串核對exit 1 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 1

返回碼 1｜完整字串核對

STDIN · 完整輸入

```
abc
```

4 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Input error
```

12 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E42-T06**6. 測試6**原稿測試 · 5 input bytes · 完整字串核對exit 1 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 1

返回碼 1｜完整字串核對

STDIN · 完整輸入

```
1001
```

5 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Range error
```

12 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

保留原合法但邏輯錯誤的連寫式；編譯器可出現bool-compare等警告，正是教材要辨識的問題。新增−1000..1000輸入界線。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E41 把衝突副作用改成明確步驟](#ex-15)[E43 用短路規則保護除法 →](#ex-45)

E43原稿範例運算式與狀態CH1–4


<a id="toc-ch1-43"></a>

# 用短路規則保護除法

45\_short\_circuit.c1 組原稿測試

**原稿索引：**45\_short\_circuit.c　原檔：52　新版：題目 96 / 講解 97
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-45/problem)[02 解題說明](#ex-45/solution)[03 完整程式](#ex-45/code)[04 測試資料](#ex-45/tests)[05 來源與提醒](#ex-45/tips)

01

## 完整題目

先確認規格，再寫程式

對原防護式測分母為0、商大於3及不大於3的三種情況。

### 輸入與限制

固定numerator=20；denominator依序0、5、10。

### 應產生的輸出

三種&&結果為0、1、0；另驗證||跳過右式。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 範例輸出

```
d=0 result=0
d=5 result=1
d=10 result=0
or=1 right-evaluated=0
```

63 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

&&先檢查分母，不合法時不要執行右側除法。

**STEP 02**

分母為5時才計算20/5>3，得到1；分母10時得到0。

**STEP 03**

用不同觀察變數驗證||左側為真會跳過右側副作用。

### 原稿解題示例

d=0 → 不除法、0；d=5 → 20/5>3、1

03

## 完整程式碼

每份程式均有獨立 main

45\_short\_circuit.c

完整程式 · 23 行 · 內容與原稿逐字相同

```
/* 45_short_circuit.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 52.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>

int main(void)
{
    int numerator = 20, denominator = 0;
    int result = denominator != 0 && numerator / denominator > 3;
    printf("d=0 result=%d\n", result);
    denominator = 5;
    result = denominator != 0 && numerator / denominator > 3;
    printf("d=5 result=%d\n", result);
    denominator = 10;
    result = denominator != 0 && numerator / denominator > 3;
    printf("d=10 result=%d\n", result);
    int left_is_true = 1, evaluated = 0;
    int either = left_is_true || (evaluated = 1);
    printf("or=%d right-evaluated=%d\n", either, evaluated);
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/45_short_circuit.c -o example`

04


## 測試資料

1 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E43-T01**1. 測試1**原稿測試 · 0 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿完整預期輸出

```
d=0 result=0
d=5 result=1
d=10 result=0
or=1 right-evaluated=0
```

63 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

新增固定20與三個分母作可執行測試，並補上原頁提到的||。數值小且商可表示，不宣稱只檢查非零就涵蓋所有整數除法風險。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E42 正確檢查分數是否在範圍內](#ex-44)[E44 分辨逗號運算子與參數分隔符 →](#ex-46)

E44原稿範例運算式與狀態CH1–4


<a id="toc-ch1-44"></a>

# 分辨逗號運算子與參數分隔符

46\_comma\_operator.c1 組原稿測試

**原稿索引：**46\_comma\_operator.c　原檔：53　新版：題目 98 / 講解 99
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-46/problem)[02 解題說明](#ex-46/solution)[03 完整程式](#ex-46/code)[04 測試資料](#ex-46/tests)[05 來源與提醒](#ex-46/tips)

01

## 完整題目

先確認規格，再寫程式

執行j=(i++,i+10)，再於另一個printf使用正常參數分隔符。

### 輸入與限制

i=1；另設a=3,b=4。

### 應產生的輸出

i=2、j=12，後一行3 4。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 範例輸出

```
i=2 j=12
3 4
```

13 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

括號內的逗號先完成左式i++的副作用。

**STEP 02**

再算右式i+10=12，整個運算式以右式作值。

**STEP 03**

printf的逗號只分隔參數；用無副作用資料示範，不強加先後順序。

### 原稿解題示例

i=1 → i++完成 → i+10=12 → j=12

03

## 完整程式碼

每份程式均有獨立 main

46\_comma\_operator.c

完整程式 · 17 行 · 內容與原稿逐字相同

```
/* 46_comma_operator.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 53.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>

int main(void)
{
    int i = 1, j;
    j = (i++, i + 10);
    printf("i=%d j=%d\n", i, j);
    int a = 3, b = 4;
    printf("%d %d\n", a, b);
    /* Do not use printf("%d %d", i++, i) to teach ordering. */
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/46_comma_operator.c -o example`

04


## 測試資料

1 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E44-T01**1. 測試1**原稿測試 · 0 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿完整預期輸出

```
i=2 j=12
3 4
```

13 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

第一段沿用原例，a=3/b=4為本次新增初始化。反例只留註解。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E43 用短路規則保護除法](#ex-45)[E45 比較只計算與真的更新 →](#ex-47)

E45刻意保留診斷對照運算式與狀態CH1–4


<a id="toc-ch1-45"></a>

# 比較只計算與真的更新

47\_expression\_statement.c1 組原稿測試

**原稿索引：**47\_expression\_statement.c　原檔：54　新版：題目 100 / 講解 101
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-47/problem)[02 解題說明](#ex-47/solution)[03 完整程式](#ex-47/code)[04 測試資料](#ex-47/tests)[05 來源與提醒](#ex-47/tips)

01

## 完整題目

先確認規格，再寫程式

從i=10開始，分別觀察i+1、i+=1、i=i+1是否改變物件。

### 輸入與限制

固定i=10；各次更新與输出依序執行。

### 應產生的輸出

只算後10、+=後11、再赋值後12。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 範例輸出

```
discarded result: i=10
compound assignment: i=11
simple assignment: i=12
```

73 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

i+1只產生值，未存回，因此i仍為10。

**STEP 02**

i+=1將結果存回，狀態變成11。

**STEP 03**

再執行i=i+1會再加一次；不要把連續執行當獨立實驗。

### 原稿解題示例

i=10 → i+1仍10 → i+=1成11 → 再加成12

03

## 完整程式碼

每份程式均有獨立 main

47\_expression\_statement.c

完整程式 · 19 行 · 內容與原稿逐字相同

```
/* 47_expression_statement.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 54.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>

int main(void)
{
    int i = 10;
    /* Intentional unused-value warning: the result is discarded. */
    i + 1;
    printf("discarded result: i=%d\n", i);
    i += 1;
    printf("compound assignment: i=%d\n", i);
    i = i + 1;
    printf("simple assignment: i=%d\n", i);
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/47_expression_statement.c -o example`

此範例原稿已標示「刻意保留診斷對照」。程式中的教學反例與警告沒有因格式轉換而刪除；詳細界線見本題第 05 區。

04


## 測試資料

1 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E45-T01**1. 測試1**原稿測試 · 0 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿完整預期輸出

```
discarded result: i=10
compound assignment: i=11
simple assignment: i=12
```

73 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

原「無作用敘述」刻意保留並產生unused-value警告；此為合法可執行反例，非未定義行為。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E44 分辨逗號運算子與參數分隔符](#ex-46)[E46 由 UPC 前十一位計算檢查碼 →](#ex-12)

E46原稿範例綜合實作與檢核CH1–4


<a id="toc-ch1-46"></a>

# 由 UPC 前十一位計算檢查碼

12\_upc.c9 組原稿測試

**原稿索引：**12\_upc.c　原檔：55, 56　新版：題目 102 / 講解 103, 104
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-12/problem)[02 解題說明](#ex-12/solution)[03 完整程式](#ex-12/code)[04 測試資料](#ex-12/tests)[05 來源與提醒](#ex-12/tips)

01

## 完整題目

先確認規格，再寫程式

依原案例的奇偶位置加權規則，計算第十二位應補上的數字。

### 輸入與限制

前十一位數字；%1d 逐位讀取，允許前導空白，不嚴格驗證整行長度。

### 應產生的輸出

Check digit: 0..9。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
01380015173
```

12 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
Check digit: 5
```

15 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

以十一個 %1d 分別保存位置；全部讀成功才計算。

**STEP 02**

從左起奇數位置加總乘 3，偶數位置加總乘 1。

**STEP 03**

求 (10 − total % 10) % 10，讓整除10時得到0而非10。

### 原稿解題示例

01380015173 → total=45 → Check digit: 5

03

## 完整程式碼

每份程式均有獨立 main

12\_upc.c

完整程式 · 24 行 · 內容與原稿逐字相同

```
/* 12_upc.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 55, 56.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>

int main(void)
{
    int d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11;
    int odd, even, total, check;
    if (scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",
              &d1, &d2, &d3, &d4, &d5, &d6,
              &d7, &d8, &d9, &d10, &d11) != 11) {
        puts("Input error: enter eleven digits");
        return 1;
    }
    odd = d1 + d3 + d5 + d7 + d9 + d11;
    even = d2 + d4 + d6 + d8 + d10;
    total = 3 * odd + even;
    check = (10 - total % 10) % 10;
    printf("Check digit: %d\n", check);
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/12_upc.c -o example`

04


## 測試資料

9 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E46-T01**1. 測試1**原稿測試 · 12 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
01380015173
```

12 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Check digit: 5
```

15 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E46-T02**2. 測試2**原稿測試 · 12 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
00000000000
```

12 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Check digit: 0
```

15 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E46-T03**3. 測試3**原稿測試 · 12 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
03600029145
```

12 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Check digit: 2
```

15 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E46-T04**4. 測試4**原稿測試 · 14 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
0 13800 15173
```

14 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Check digit: 5
```

15 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E46-T05**5. 測試5**原稿測試 · 12 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
99999999999
```

12 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Check digit: 3
```

15 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E46-T06**6. 測試6**原稿測試 · 12 input bytes · 完整字串核對exit 1 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 1

返回碼 1｜完整字串核對

STDIN · 完整輸入

```
013x0015173
```

12 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Input error: enter eleven digits
```

33 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E46-T07**7. 測試7**原稿測試 · 4 input bytes · 完整字串核對exit 1 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 1

返回碼 1｜完整字串核對

STDIN · 完整輸入

```
0138
```

4 bytes · 最後沒有換行，直接 EOF

STDOUT · 原稿完整預期輸出

```
Input error: enter eleven digits
```

33 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E46-T08**8. documented-prefix-only**原稿測試 · 13 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
013800151735
```

13 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Check digit: 5
```

15 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E46-T09**9. 測試9**原稿測試 · 0 input bytes · 完整字串核對exit 1 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 1

返回碼 1｜完整字串核對

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿完整預期輸出

```
Input error: enter eleven digits
```

33 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

保留原頁的%1d教學解析：只消耗前十一個成功數字轉換，不宣稱是嚴格UPC字串驗證。尾端第十二位不檢查，此限制有測試。全零僅是公式邊界資料。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E45 比較只計算與真的更新](#ex-47)[E47 用零加權和檢查 UPC 公式 →](#ex-48)

E47原稿範例綜合實作與檢核CH1–4


<a id="toc-ch1-47"></a>

# 用零加權和檢查 UPC 公式

48\_upc\_boundary.c1 組原稿測試

**原稿索引：**48\_upc\_boundary.c　原檔：57　新版：題目 105 / 講解 106
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-48/problem)[02 解題說明](#ex-48/solution)[03 完整程式](#ex-48/code)[04 測試資料](#ex-48/tests)[05 來源與提醒](#ex-48/tips)

01

## 完整題目

先確認規格，再寫程式

分別對total=45、0、58比較原公式與投影片修正版。

### 輸入與限制

固定三個加權和；不涉及真實商品查詢。

### 應產生的輸出

一般值都相同；total=0時舊式10、新式0。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 範例輸出

```
total=45 old=5 revised=5
total=0 old=10 revised=0
total=58 old=2 revised=2
```

75 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

先讓兩個公式接受同一個total，排除輸入差異。

**STEP 02**

C99中−1%10為−1，因此舊式在total=0得到10。

**STEP 03**

修正式再取%10，讓檢查碼維持一位數範圍。

### 原稿解題示例

total=0 → old=10、revised=0

03

## 完整程式碼

每份程式均有獨立 main

48\_upc\_boundary.c

完整程式 · 17 行 · 內容與原稿逐字相同

```
/* 48_upc_boundary.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 57.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>

int main(void)
{
    int total = 45;
    printf("total=%d old=%d revised=%d\n", total, 9-((total-1)%10), (10-total%10)%10);
    total = 0;
    printf("total=%d old=%d revised=%d\n", total, 9-((total-1)%10), (10-total%10)%10);
    total = 58;
    printf("total=%d old=%d revised=%d\n", total, 9-((total-1)%10), (10-total%10)%10);
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/48_upc_boundary.c -o example`

04


## 測試資料

1 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E47-T01**1. 測試1**原稿測試 · 0 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿完整預期輸出

```
total=45 old=5 revised=5
total=0 old=10 revised=0
total=58 old=2 revised=2
```

75 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

原第57頁兩公式與三筆測試完整保留；舊式是結果不合規格的合法計算，可以安全比較。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E46 由 UPC 前十一位計算檢查碼](#ex-12)[E48 修正平均值程式的三個問題 →](#ex-49)

E48原稿範例綜合實作與檢核CH1–4


<a id="toc-ch1-48"></a>

# 修正平均值程式的三個問題

49\_debug\_io\_fixed.c3 組原稿測試

**原稿索引：**49\_debug\_io\_fixed.c　原檔：58　新版：題目 107 / 講解 108
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-49/problem)[02 解題說明](#ex-49/solution)[03 完整程式](#ex-49/code)[04 測試資料](#ex-49/tests)[05 來源與提醒](#ex-49/tips)

01

## 完整題目

先確認規格，再寫程式

修正整數除法、printf格式與scanf目標型別配對，再執行驗證。

### 輸入與限制

先算80與81平均；再讀一個double，例如82.5。

### 應產生的輸出

calculated=80.5；read=82.5。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
82.5
```

5 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
calculated=80.5
read=82.5
```

26 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

計算階段把/2改成/2.0，讓除法保留小數。

**STEP 02**

輸出階段用%.1f匹配double，不用%d。

**STEP 03**

讀入階段用%lf與&average，回傳值1才印新值。

### 原稿解題示例

先算80.5；再輸入82.5 → 新值82.5

03

## 完整程式碼

每份程式均有獨立 main

49\_debug\_io\_fixed.c

完整程式 · 24 行 · 內容與原稿逐字相同

```
/* 49_debug_io_fixed.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 58.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>
#include <math.h>

int main(void)
{
    double average = (80 + 81) / 2.0;
    printf("calculated=%.1f\n", average);
    if (scanf("%lf", &average) != 1) {
        puts("Input error");
        return 1;
    }
    if (!isfinite(average) || average < -10000.0 || average > 10000.0) {
        puts("Range error");
        return 1;
    }
    printf("read=%.1f\n", average);
    /* Original wrong-type calls remain in the teaching slide, not executed here. */
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/49_debug_io_fixed.c -o example`

04


## 測試資料

3 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E48-T01**1. 測試1**原稿測試 · 5 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
82.5
```

5 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
calculated=80.5
read=82.5
```

26 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E48-T02**2. 測試2**原稿測試 · 4 input bytes · 完整字串核對exit 1 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 1

返回碼 1｜完整字串核對

STDIN · 完整輸入

```
abc
```

4 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
calculated=80.5
Input error
```

28 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E48-T03**3. 測試3**原稿測試 · 4 input bytes · 完整字串核對exit 1 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 1

返回碼 1｜完整字串核對

STDIN · 完整輸入

```
nan
```

4 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
calculated=80.5
Range error
```

28 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

本次提供原除錯題的明確修正版，不執行原不匹配格式。讀入值±10000與有限值防護為新增教學範圍。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E47 用零加權和檢查 UPC 公式](#ex-48)[E49 計算以半小時為單位的停車費 →](#ex-13)

E49原稿範例綜合實作與檢核CH1–4


<a id="toc-ch1-49"></a>

# 計算以半小時為單位的停車費

13\_parking.c12 組原稿測試

**原稿索引：**13\_parking.c　原檔：59, 60, 61, 62　新版：題目 109 / 講解 110, 111, 112, 113
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-13/problem)[02 解題說明](#ex-13/solution)[03 完整程式](#ex-13/code)[04 測試資料](#ex-13/tests)[05 來源與提醒](#ex-13/tips)

01

## 完整題目

先確認規格，再寫程式

每開始30分鐘收20元，0分鐘不收費；將規格轉為可測試公式。

### 輸入與限制

一個整數分鐘數，0..1440；費率僅為教材假設。

### 應產生的輸出

Minutes、Blocks、Fee，各一行。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
0
```

2 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
Minutes: 0
Blocks: 0
Fee: 0
```

28 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

先分開處理讀取失敗與超出範圍，錯誤時不進入計算。

**STEP 02**

以 (minutes + 29) / 30 計算開始過的半小時單位。

**STEP 03**

單位數乘20得費用；先核對0、30、31三個邊界。

### 原稿解題示例

31 → Blocks: 2 → Fee: 40

03

## 完整程式碼

每份程式均有獨立 main

13\_parking.c

完整程式 · 25 行 · 內容與原稿逐字相同

```
/* 13_parking.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 59, 60, 61, 62.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>
#define BLOCK_MINUTES 30
#define PRICE_PER_BLOCK 20

int main(void)
{
    int minutes, blocks, fee;
    if (scanf("%d", &minutes) != 1) {
        puts("Input error");
        return 1;
    }
    if (minutes < 0 || minutes > 1440) {
        puts("Range error");
        return 1;
    }
    blocks = (minutes + BLOCK_MINUTES - 1) / BLOCK_MINUTES;
    fee = blocks * PRICE_PER_BLOCK;
    printf("Minutes: %d\nBlocks: %d\nFee: %d\n", minutes, blocks, fee);
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/13_parking.c -o example`

04


## 測試資料

12 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E49-T01**1. 測試1**原稿測試 · 2 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
0
```

2 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Minutes: 0
Blocks: 0
Fee: 0
```

28 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E49-T02**2. 測試2**原稿測試 · 2 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
1
```

2 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Minutes: 1
Blocks: 1
Fee: 20
```

29 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E49-T03**3. 測試3**原稿測試 · 3 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
29
```

3 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Minutes: 29
Blocks: 1
Fee: 20
```

30 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E49-T04**4. 測試4**原稿測試 · 3 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
30
```

3 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Minutes: 30
Blocks: 1
Fee: 20
```

30 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E49-T05**5. 測試5**原稿測試 · 3 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
31
```

3 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Minutes: 31
Blocks: 2
Fee: 40
```

30 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E49-T06**6. 測試6**原稿測試 · 3 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
90
```

3 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Minutes: 90
Blocks: 3
Fee: 60
```

30 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E49-T07**7. 測試7**原稿測試 · 5 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
1440
```

5 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Minutes: 1440
Blocks: 48
Fee: 960
```

34 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E49-T08**8. 測試8**原稿測試 · 3 input bytes · 完整字串核對exit 1 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 1

返回碼 1｜完整字串核對

STDIN · 完整輸入

```
-1
```

3 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Range error
```

12 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E49-T09**9. 測試9**原稿測試 · 5 input bytes · 完整字串核對exit 1 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 1

返回碼 1｜完整字串核對

STDIN · 完整輸入

```
1441
```

5 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Range error
```

12 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E49-T10**10. 測試10**原稿測試 · 4 input bytes · 完整字串核對exit 1 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 1

返回碼 1｜完整字串核對

STDIN · 完整輸入

```
abc
```

4 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Input error
```

12 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E49-T11**11. 測試11**原稿測試 · 0 input bytes · 完整字串核對exit 1 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 1

返回碼 1｜完整字串核對

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿完整預期輸出

```
Input error
```

12 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E49-T12**12. documented-prefix-only**原稿測試 · 5 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
31.5
```

5 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Minutes: 31
Blocks: 2
Fee: 40
```

30 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

保留原程式的scanf整數前綴解析。輸入31.5時%d讀到31，未驗證尾端，因此本版不宣稱會拒絕所有小數字串。這是原教學程式的範圍，不新增免費時段或每日封頂。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E48 修正平均值程式的三個問題](#ex-49)[E50 驗證可計算的總檢核答案 →](#ex-50)

E50刻意保留診斷對照綜合實作與檢核CH1–4


<a id="toc-ch1-50"></a>

# 驗證可計算的總檢核答案

50\_quiz\_integrated.c1 組原稿測試

**原稿索引：**50\_quiz\_integrated.c　原檔：63　新版：題目 114 / 講解 115
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-50/problem)[02 解題說明](#ex-50/solution)[03 完整程式](#ex-50/code)[04 測試資料](#ex-50/tests)[05 來源與提醒](#ex-50/tips)

01

## 完整題目

先確認規格，再寫程式

用固定測試核對停車費、double讀入及多餘參數；未定義反例只分類。

### 輸入與限制

31分鐘、固定字串3.5；i\*i++不執行。

### 應產生的輸出

blocks=2、fee=40、count=1、x=3.5、多餘參數只印10。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 範例輸出

```
blocks=2 fee=40
count=1 x=3.5
i*i++: undefined behavior; not executed.
extra argument example=10
```

97 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

先分類題目是否有可推導答案，避免對未定義式硬算。

**STEP 02**

可計算部分分別用固定資料驗證，避免互相干擾。

**STEP 03**

對多餘printf參數觀察警告與有效輸出，不與少參數混為一談。

### 原稿解題示例

31分鐘 → 2單位／40；i\*i++ → 不給固定輸出

03

## 完整程式碼

每份程式均有獨立 main

50\_quiz\_integrated.c

完整程式 · 19 行 · 內容與原稿逐字相同

```
/* 50_quiz_integrated.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 63.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>

int main(void)
{
    int blocks = (31 + 29) / 30;
    printf("blocks=%d fee=%d\n", blocks, blocks * 20);
    double x = 0.0;
    int count = sscanf("3.5", "%lf", &x);
    printf("count=%d x=%.1f\n", count, x);
    puts("i*i++: undefined behavior; not executed.");
    /* Intentional format-extra-args warning. */
    printf("extra argument example=%d\n", 10, 20);
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/50_quiz_integrated.c -o example`

此範例原稿已標示「刻意保留診斷對照」。程式中的教學反例與警告沒有因格式轉換而刪除；詳細界線見本題第 05 區。

04


## 測試資料

1 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E50-T01**1. 測試1**原稿測試 · 0 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿完整預期輸出

```
blocks=2 fee=40
count=1 x=3.5
i*i++: undefined behavior; not executed.
extra argument example=10
```

97 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

沿用原四題答案；sscanf與固定3.5是本次測試支援。多餘參數範例有預期警告。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E49 計算以半小時為單位的停車費](#ex-13)[E51 觀察 scanf 星號的抑制賦值 →](#ex-51)

E51原稿範例附錄與延伸觀察CH1–4


<a id="toc-ch1-51"></a>

# 觀察 scanf 星號的抑制賦值

51\_scan\_suppression.c4 組原稿測試

**原稿索引：**51\_scan\_suppression.c　原檔：64　新版：題目 116 / 講解 117
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-51/problem)[02 解題說明](#ex-51/solution)[03 完整程式](#ex-51/code)[04 測試資料](#ex-51/tests)[05 來源與提醒](#ex-51/tips)

01

## 完整題目

先確認規格，再寫程式

讀兩個整數但只保存第二個，對照printf星號的完全不同用途。

### 輸入與限制

輸入10 20；格式%\*d%d只提供&x。

### 應產生的輸出

count=1、x=20；動態輸出欄寬仍由另一個參數提供。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
10 20
```

6 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
count=1 x=20
|   20|
```

21 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

%\*d先讀第一個整數但不賦值，因此不提供第一個寫入位置。

**STEP 02**

第二個%d才寫入x，scanf成功賦值數是1而非2。

**STEP 03**

再以printf的%\*d示範動態欄寬，不把兩個星號混用。

### 原稿解題示例

10 20 → count=1、x=20 → | 20|

03

## 完整程式碼

每份程式均有獨立 main

51\_scan\_suppression.c

完整程式 · 19 行 · 內容與原稿逐字相同

```
/* 51_scan_suppression.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 64.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>

int main(void)
{
    int x = -1;
    int count = scanf("%*d%d", &x);
    if (count != 1) {
        puts("Input error");
        return 1;
    }
    printf("count=%d x=%d\n", count, x);
    printf("|%*d|\n", 5, x);
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/51_scan_suppression.c -o example`

04


## 測試資料

4 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E51-T01**1. 測試1**原稿測試 · 6 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
10 20
```

6 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
count=1 x=20
|   20|
```

21 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E51-T02**2. 測試2**原稿測試 · 6 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
10 -7
```

6 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
count=1 x=-7
|   -7|
```

21 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E51-T03**3. 測試3**原稿測試 · 5 input bytes · 完整字串核對exit 1 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 1

返回碼 1｜完整字串核對

STDIN · 完整輸入

```
10 x
```

5 bytes · 最後有 LF 換行

STDOUT · 原稿完整預期輸出

```
Input error
```

12 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

E51-T04**4. 測試4**原稿測試 · 0 input bytes · 完整字串核對exit 1 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 1

返回碼 1｜完整字串核對

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿完整預期輸出

```
Input error
```

12 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

將原附錄備忘錄的%\*d%d題實作；printf的動態欄寬是用來作跨函式對照的新增行。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E50 驗證可計算的總檢核答案](#ex-50)[E52 觀察數值跳脫序列的邊界 →](#ex-52)

E52原稿範例附錄與延伸觀察CH1–4


<a id="toc-ch1-52"></a>

# 觀察數值跳脫序列的邊界

52\_numeric\_escapes.c1 組原稿測試

**原稿索引：**52\_numeric\_escapes.c　原檔：65　新版：題目 118 / 講解 119
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-52/problem)[02 解題說明](#ex-52/solution)[03 完整程式](#ex-52/code)[04 測試資料](#ex-52/tests)[05 來源與提醒](#ex-52/tips)

01

## 完整題目

先確認規格，再寫程式

在ASCII相容執行字元集上，輸出八進位A與明確截斷的十六進位AB。

### 輸入與限制

無輸入；檢查A/B是否為ASCII對應值。

### 應產生的輸出

A、AB，另示範水平跳格。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 範例輸出

```
A
AB
tab:A	B
```

13 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

\101採最多三個八進位數字；此例值為65。

**STEP 02**

把\x41與後面的B分成相鄰字串，避免B被十六進位序列吸收。

**STEP 03**

輸出前先檢查字元集前提；控制字元的顯示仍由終端決定。

### 原稿解題示例

"\101" → A；"\x41" "B" → AB

03

## 完整程式碼

每份程式均有獨立 main

52\_numeric\_escapes.c

完整程式 · 19 行 · 內容與原稿逐字相同

```
/* 52_numeric_escapes.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 65.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>

int main(void)
{
    if ('A' != 65 || 'B' != 66) {
        puts("ASCII-compatible execution character set required for this demo.");
        return 0;
    }
    printf("%s\n", "\101");
    printf("%s\n", "\x41" "B");
    printf("tab:A\tB\n");
    /* '\a', '\b', and '\r' are listed in the guide, not used for visual assertions. */
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/52_numeric_escapes.c -o example`

04


## 測試資料

1 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E52-T01**1. 測試1**原稿測試 · 0 input bytes · 完整字串核對exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜完整字串核對

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿完整預期輸出

```
A
AB
tab:A	B
```

13 bytes · 保留原稿的空白、tab 與換行

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

數值序列沿用原附錄；新增執行字元集檢查與tab示範。ASCII以外環境會印前提訊息，而不是保證A/AB輸出。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E51 觀察 scanf 星號的抑制賦值](#ex-51)[E53 用不同進位顯示同一個值 →](#ex-14)

E53原稿範例附錄與延伸觀察CH1–4


<a id="toc-ch1-53"></a>

# 用不同進位顯示同一個值

14\_format\_extras.c1 組原稿測試

**原稿索引：**14\_format\_extras.c　原檔：66　新版：題目 120 / 講解 121
**格式轉換：**題目、三步解法、程式與測試資料均沿用上傳 HTML；原有順序與檔名不變。

[01 完整題目](#ex-14/problem)[02 解題說明](#ex-14/solution)[03 完整程式](#ex-14/code)[04 測試資料](#ex-14/tests)[05 來源與提醒](#ex-14/tips)

01

## 完整題目

先確認規格，再寫程式

觀察十進位、十六進位、八進位與十六進位浮點輸出。

### 輸入與限制

固定 unsigned int n=26u、double 1.5。

### 應產生的輸出

26 0x1a 032；%a 的等值表示；字元、字串與百分號。

### 輸入／輸出範例 沿用本題原稿第一組測試

STDIN · 範例輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿平台觀察值

```
26 0x1a 032
0x1.800p+0
A Hello %
```

33 bytes · 保留原稿的空白、tab 與換行

空輸入檔代表直接 EOF，不需輸入「EOF」文字；下載保留實際空白、tab 及有無末尾換行。

此例含平台觀察值，請依原題前提判讀，不將本機型別範圍或浮點字面表示當成跨平台固定答案。

目前隱藏解答：題目及題目範例仍可閱讀，解法、程式與完整測試答案暫時遮蔽。這是閱讀模式，不是考試保密機制。

02

## 解題說明

沿用原稿的核心思考

### 核心解法的思考邏輯

全部步驟

依原文逐步閱讀；按鈕只標記解題文字，不會執行 C 程式，也不額外指定運算式求值順序。

**STEP 01**

先確認型別：%u、%x、%o 都使用 unsigned int。

**STEP 02**

同一數值用不同格式顯示，不改變 n 本身。

**STEP 03**

辨識 %a 的 p 是以2為底的指數；%% 不消耗數值參數。

### 原稿解題示例

26u → 26、0x1a、032

03

## 完整程式碼

每份程式均有獨立 main

14\_format\_extras.c

完整程式 · 15 行 · 內容與原稿逐字相同

```
/* 14_format_extras.c
 * Source: C_Programming_Ch1-4.pptx, actual slide(s) 66.
 * This is a complete teaching edition; see the accompanying Chinese guide.
 * Build each .c file separately. No project-specific headers are required.
 */
#include <stdio.h>

int main(void)
{
    unsigned int n = 26u;
    printf("%u %#x %#o\n", n, n, n);
    printf("%.3a\n", 1.5);
    printf("%c %s %%\n", 'A', "Hello");
    return 0;
}
```

單題編譯指令（使用說明）`gcc -std=c11 -Wall -Wextra -Wpedantic code/14_format_extras.c -o example`

04


## 測試資料

1 組完整原稿資料

輸入、輸出與返回碼沿用原稿；來源觀察值另行標示。

列印版列出測試索引與結束碼；完整輸入、輸出及原稿核對說明請使用 HTML 或下載的測試檔。

E53-T01**1. 測試1**原稿測試 · 0 input bytes · 平台觀察紀錄exit 0 ✓

本次 GCC / Clang / UBSan 與原稿一致結束碼 0

返回碼 0｜依模式或數值核對；以下列出本次GCC環境觀察值

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 空輸入檔，直接 EOF

STDOUT · 原稿平台觀察值

```
26 0x1a 032
0x1.800p+0
A Hello %
```

33 bytes · 保留原稿的空白、tab 與換行

上方是原 HTML 記錄的 GCC 觀察值，本次環境輸出與其一致；不是所有平台都必須逐字相同的答案。原稿未附具體模式／數值判準，本次未補寫該判準。

原稿測試標記：PASS

05

## 來源與注意事項

保留原稿的適用範圍

### 原稿與新增內容的界線

保留原程式；%a測試接受實作所選等值十六進位表示，並另檢驗其數值為1.5，不以本機字面輸出限制所有C實作。

本區「本次／新增」等措辭來自原 HTML 的逐題說明，並非本次版型轉換新增題目或修改 C 程式的宣稱。

[← E52 觀察數值跳脫序列的邊界](#ex-52)[回到全部主題 →](#overview)

HOW TO USE / CONVERSION VALIDATION

# 使用與驗證說明

CH1–4 原有內容，套用 CH5–7 的閱讀與下載介面。

## 這份 HTML 保留了什麼？

**53 個範例、53 份完整 C 程式、133 組測試資料**，原有題目、輸入與輸出規格、三步解法、解題示例、逐題來源界線、原稿頁次及閱讀順序均保留。介面群組是檢索用的主題分類，未另行宣稱原始章節分界。

文字與程式碼並未轉為圖片。程式、輸入檔、輸出檔與 ZIP 都內嵌於同一 HTML；即使離線，也不必連到原稿相對路徑中的 `code/` 或 `README.md`。

**「隱藏解答」只是顯示模式**；題目範例仍屬題目的一部分，完整解答及下載資料也仍存放在檔案內。「下一步」只標記原稿三步解法，不在瀏覽器中執行 C，也不額外宣稱語言的求值次序。按 Esc 可關閉手機目錄，按 / 可聚焦搜尋。

### 內容來源與本次轉換界線

內容來自上傳的 `CH1-4_完整程式碼與解題說明.html`；視覺與互動介面沿用 `C_Programming_Ch5-7_Examples.html`。本次未補入新題目、新解法或原稿缺少的變數表，也未修正 C 演算法與輸入規則。

每題第 05 區保留原 HTML 的「原稿與新增內容的界線」。其中「本次／新增」沿用原稿的說明，不是這次版型轉換新增程式內容。原稿標示的 122 頁投影片及各頁索引照錄，本次未重新讀取 CH1–4 PPTX 核對頁次。

原 HTML 提及的 README 及原始測試器未包含在此次上傳檔案中。本頁、資源包 README 與 `tests/run_tests.py` 是本次另製的操作／轉換驗證支援，不冒充原有文件。

### 單題編譯與執行

下載頂部「程式與測試 ZIP」並完整解壓縮。每個檔案各有 `main`，請分開編譯，不要將53支程式連結成同一支執行檔。

#### Linux／macOS shell

```
gcc -std=c11 -Wall -Wextra -Wpedantic code/02_dweight.c -o example
./example < tests/data/E07/E07-T01.in.txt
echo $?
```

#### Windows 命令提示字元（cmd.exe）使用範例

```
gcc -std=c11 -Wall -Wextra -Wpedantic code/02_dweight.c -o example.exe
example.exe < tests/data/E07/E07-T01.in.txt
echo %ERRORLEVEL%
```

Windows 指令供操作參考，本次未在 Windows 實測。上列重導向寫法屬 cmd.exe，不是 PowerShell；需先具備編譯器，HTML 本身不會安裝或執行編譯器。

### 本次實際重跑的範圍

以原程式逐份編譯，再將原稿的133組輸入交給對應執行檔。本次 Linux 環境中，三輪結果如下。

| 實測工具 | 程式編譯 | 原稿資料核對 |
| --- | --- | --- |
| GCC 14.2 | 53 / 53 | 133 / 133 |
| Clang 17.0 | 53 / 53 | 133 / 133 |
| GCC 14.2 + UBSan | 53 / 53 | 133 / 133 |

核對完整標準輸出、程序結束碼及空的 stderr；只將 CRLF 正規化為 LF，不刪除其他空白。刻意產生的編譯警告保留於報告，未使用 `-Werror`，也沒有為消除警告而更改程式。完整編譯輸出與每組實測结果包含在資源 ZIP 的 `validation/`。

**3 組平台觀察值不是跨平台固定答案。**

`18_basic_types.c`、`43_behavior_classes.c`、`14_format_extras.c` 的原稿標示「依模式或數值核對」，但未附具體判準。本次只核對現有環境與原稿保存的完整觀察字串相同，沒有補寫未知判準。其他平台的型別範圍或等值十六進位浮點表示可能不同，應依原題前提判讀。

### 重跑測試

```
python tests/run_tests.py --compiler gcc --report local_gcc.json
python tests/run_tests.py --compiler clang --report local_clang.json
python tests/run_tests.py --compiler gcc --sanitize --report local_ubsan.json
```

本次新增測試工具使用 Python 標準函式庫，需 Python 3.9 以上及相應編譯器。它只比對所附原稿字串，不宣稱重建原先未附的模式／數值測試器。不同平台的觀察資料不一致時須另行判讀。

### 空檔、空白行與資料末尾

0 bytes 是直接 EOF；只有  的輸入是一個空白行。測試區可切換「顯示跳脫字元」，辨識 tab、空白及末尾換行；下載永遠使用原始資料，不是 JSON 跳脫後的顯示文字。

`31_scan_trailing_space.c` 是原稿刻意安排的互動等待實驗；人工操作前請閱讀其來源提醒。自動測試在送完輸入後關閉串流，與終端只按 Enter 仍持續開啟串流的情境不同。

### 原稿共通限制仍適用

數值須可由對應型別表示；scanf 前綴解析不等於嚴格整行驗證。原稿的安全改寫、ASCII及平台前提、教學費率與刻意診斷均不變。測試通過不是對任意輸入的形式證明，也不是 Windows、MSVC 或 Office 實測。

列印目前頁只印正在閱讀的範例；列印全冊包含所有53題。為控制篇幅，列印版的測試區列出索引及結束碼，完整輸入／輸出請使用 HTML 或下載檔案。

[查看來源索引 →](#sources)

SOURCE / CONTENT PRESERVATION

# 來源與案例索引

原稿順序、檔名、頁次與新增界線完整保留。

## 這次使用的兩份 HTML

### 內容來源

`CH1-4_完整程式碼與解題說明.html`
53題、53程式、133組原稿資料。

### 版型與操作來源

`C_Programming_Ch5-7_Examples.html`
側邊目錄、主題卡片、分區、配色與互動方式。

**保留比對：**原題文字、輸入／輸出規格、三步解法、解題示例、來源段落、程式碼及測試資料逐項核對。範例E01–E53只是沿用原稿閱讀序列的顯示標籤；不更名或重排任何C檔案。

### 原 HTML 的使用說明（保留原文）

下方「本次實測」等用语屬原稿文字。本次轉換的重跑方法及限制另列於「使用與驗證說明」。原稿中的 README 超連結未附文件，這裡以純文字保留。

### 使用前先確認

每個檔案各有 `main`，請分開編譯；完整限制與指令見 README。GCC、Clang、GCC＋UBSan 均通過 53 檔編譯及 133 組測試。下列結果以本次實測為依據；特定型別大小、字元編碼與浮點表示須依題目前提判讀。

原投影片的非法／未定義反例只作分析；程式包提供明確標示的安全改寫，並不宣稱與未定義原式等價。scanf 範例要求數值可由型別表示，不保證嚴格整行解析。

原 HTML 的來源宣告（照錄）：來源：本次上傳的 C\_Programming\_Ch1-4.pptx。新增程式與講解均逐題標記。

### 完整範例對照

| 序號 | 題目／原程式 | 原稿頁次記錄 | 資料 |
| --- | --- | --- | --- |
| [E01](#ex-16) | [分辨三類錯誤並執行修正版](#ex-16) `16_diagnostics_safe.c` | 16\_diagnostics\_safe.c　原檔：4　新版：題目 6 / 講解 7 | 1 組 |
| [E02](#ex-1) | [建立並執行第一支 C 程式](#ex-1) `01_hello.c` | 01\_hello.c　原檔：5, 6　新版：題目 8 / 講解 9, 10 | 1 組 |
| [E03](#ex-17) | [以名稱與註解表達計算意圖](#ex-17) `17_naming.c` | 17\_naming.c　原檔：7　新版：題目 11 / 講解 12 | 1 組 |
| [E04](#ex-18) | [觀察型別與實作範圍](#ex-18) `18_basic_types.c` | 18\_basic\_types.c　原檔：8　新版：題目 13 / 講解 14 | 1 組 |
| [E05](#ex-19) | [安全觀察初始化與賦值](#ex-19) `19_initialization.c` | 19\_initialization.c　原檔：9　新版：題目 15 / 講解 16 | 1 組 |
| [E06](#ex-20) | [用中間值追蹤體積計算](#ex-20) `20_volume_flow.c` | 20\_volume\_flow.c　原檔：10　新版：題目 17 / 講解 18 | 1 組 |
| [E07](#ex-2) | [計算包裹的材積重量](#ex-2) `02_dweight.c` | 02\_dweight.c　原檔：11, 13　新版：題目 19 / 講解 20, 23 | 7 組 |
| [E08](#ex-21) | [驗證整數向上取整的邊界](#ex-21) `21_ceiling_division.c` | 21\_ceiling\_division.c　原檔：12　新版：題目 21 / 講解 22 | 8 組 |
| [E09](#ex-22) | [比較巨集有無括號的結果](#ex-22) `22_macro_parentheses.c` | 22\_macro\_parentheses.c　原檔：14　新版：題目 24 / 講解 25 | 1 組 |
| [E10](#ex-3) | [華氏溫度轉攝氏溫度](#ex-3) `03_celsius.c` | 03\_celsius.c　原檔：15, 16　新版：題目 26 / 講解 27, 28 | 9 組 |
| [E11](#ex-23) | [驗證基本元素的四題檢核](#ex-23) `23_quiz_basics.c` | 23\_quiz\_basics.c　原檔：17　新版：題目 29 / 講解 30 | 1 組 |
| [E12](#ex-24) | [讓格式與數值一一配對](#ex-24) `24_printf_contract.c` | 24\_printf\_contract.c　原檔：18　新版：題目 31 / 講解 32 | 1 組 |
| [E13](#ex-25) | [依資料型別選擇 printf 規格](#ex-25) `25_printf_types.c` | 25\_printf\_types.c　原檔：19　新版：題目 33 / 講解 34 | 1 組 |
| [E14](#ex-4) | [比較欄寬、精度與浮點格式](#ex-4) `04_printf_formats.c` | 04\_printf\_formats.c　原檔：20, 21　新版：題目 35 / 講解 36, 37 | 1 組 |
| [E15](#ex-5) | [製作感測器數值報表](#ex-5) `05_sensor_report.c` | 05\_sensor\_report.c　原檔：22　新版：題目 38 / 講解 39 | 1 組 |
| [E16](#ex-26) | [控制字串截取與動態欄寬](#ex-26) `26_dynamic_format.c` | 26\_dynamic\_format.c　原檔：23　新版：題目 40 / 講解 41 | 1 組 |
| [E17](#ex-27) | [輸出引號、反斜線與換行](#ex-27) `27_escape_sequences.c` | 27\_escape\_sequences.c　原檔：24　新版：題目 42 / 講解 43 | 1 組 |
| [E18](#ex-28) | [區分多給參數與危險格式錯誤](#ex-28) `28_printf_extra_args.c` | 28\_printf\_extra\_args.c　原檔：25　新版：題目 44 / 講解 45 | 1 組 |
| [E19](#ex-29) | [正確讀取 float 與 double](#ex-29) `29_scan_value_address.c` | 29\_scan\_value\_address.c　原檔：26　新版：題目 46 / 講解 47 | 4 組 |
| [E20](#ex-6) | [逐項解析沒有空白的數字串](#ex-6) `06_scan_stream.c` | 06\_scan\_stream.c　原檔：27, 28　新版：題目 48 / 講解 49, 50 | 5 組 |
| [E21](#ex-7) | [觀察 scanf 部分成功後的狀態](#ex-7) `07_scan_failure.c` | 07\_scan\_failure.c　原檔：29　新版：題目 51 / 講解 52 | 4 組 |
| [E22](#ex-30) | [重現五組分隔符匹配實驗](#ex-30) `30_scan_delimiters.c` | 30\_scan\_delimiters.c　原檔：30　新版：題目 53 / 講解 54 | 1 組 |
| [E23](#ex-8) | [比較 %c 與前導空白的讀取](#ex-8) `08_scan_char.c` | 08\_scan\_char.c　原檔：31　新版：題目 55 / 講解 56 | 4 組 |
| [E24](#ex-31) | [親自觀察尾端空白指令的等待](#ex-31) `31_scan_trailing_space.c` | 31\_scan\_trailing\_space.c　原檔：32　新版：題目 57 / 講解 58 | 3 組 |
| [E25](#ex-9) | [將兩個分數相加且不先約分](#ex-9) `09_fractions.c` | 09\_fractions.c　原檔：33, 34　新版：題目 59 / 講解 60, 61 | 8 組 |
| [E26](#ex-32) | [用小實驗驗證四題格式化檢核](#ex-32) `32_quiz_io.c` | 32\_quiz\_io.c　原檔：35　新版：題目 62 / 講解 63 | 1 組 |
| [E27](#ex-33) | [拆解一元與二元運算](#ex-33) `33_unary_binary.c` | 33\_unary\_binary.c　原檔：36　新版：題目 64 / 講解 65 | 1 組 |
| [E28](#ex-34) | [比較兩筆量測值的平均](#ex-34) `34_average_division.c` | 34\_average\_division.c　原檔：37　新版：題目 66 / 講解 67 | 1 組 |
| [E29](#ex-35) | [驗證正負整數的商與餘數](#ex-35) `35_quotient_remainder.c` | 35\_quotient\_remainder.c　原檔：38　新版：題目 68 / 講解 69 | 1 組 |
| [E30](#ex-10) | [把總秒數拆成時、分、秒](#ex-10) `10_duration.c` | 10\_duration.c　原檔：39　新版：題目 70 / 講解 71 | 9 組 |
| [E31](#ex-36) | [比較括號改變前後的運算樹](#ex-36) `36_precedence.c` | 36\_precedence.c　原檔：40　新版：題目 72 / 講解 73 | 1 組 |
| [E32](#ex-37) | [用括號驗證結合性](#ex-37) `37_associativity.c` | 37\_associativity.c　原檔：41　新版：題目 74 / 講解 75 | 1 組 |
| [E33](#ex-38) | [追蹤連鎖賦值的型別轉換](#ex-38) `38_assignment_value.c` | 38\_assignment\_value.c　原檔：42　新版：題目 76 / 講解 77 | 1 組 |
| [E34](#ex-39) | [辨識可修改的賦值目標](#ex-39) `39_lvalue_safe.c` | 39\_lvalue\_safe.c　原檔：43　新版：題目 78 / 講解 79 | 1 組 |
| [E35](#ex-40) | [追蹤庫存與複合賦值](#ex-40) `40_compound_assignment.c` | 40\_compound\_assignment.c　原檔：44　新版：題目 80 / 講解 81 | 1 組 |
| [E36](#ex-41) | [分開觀察遞增的值與狀態](#ex-41) `41_pre_post_increment.c` | 41\_pre\_post\_increment.c　原檔：45　新版：題目 82 / 講解 83 | 1 組 |
| [E37](#ex-11) | [追蹤三組獨立的遞增運算式](#ex-11) `11_expression_trace.c` | 11\_expression\_trace.c　原檔：46　新版：題目 84 / 講解 85 | 1 組 |
| [E38](#ex-53) | [逐層解出複合運算式](#ex-53) `53_complex_expression.c` | 53\_complex\_expression.c　原檔：47　新版：題目 86 / 講解 87 | 1 組 |
| [E39](#ex-42) | [分開驗證分組與人為指定順序](#ex-42) `42_grouping_order.c` | 42\_grouping\_order.c　原檔：48　新版：題目 88 / 講解 89 | 1 組 |
| [E40](#ex-43) | [將四種語言行為分開說明](#ex-43) `43_behavior_classes.c` | 43\_behavior\_classes.c　原檔：49　新版：題目 90 / 講解 91 | 1 組 |
| [E41](#ex-15) | [把衝突副作用改成明確步驟](#ex-15) `15_safe_rewrite.c` | 15\_safe\_rewrite.c　原檔：50　新版：題目 92 / 講解 93 | 1 組 |
| [E42](#ex-44) | [正確檢查分數是否在範圍內](#ex-44) `44_relational_logical.c` | 44\_relational\_logical.c　原檔：51　新版：題目 94 / 講解 95 | 6 組 |
| [E43](#ex-45) | [用短路規則保護除法](#ex-45) `45_short_circuit.c` | 45\_short\_circuit.c　原檔：52　新版：題目 96 / 講解 97 | 1 組 |
| [E44](#ex-46) | [分辨逗號運算子與參數分隔符](#ex-46) `46_comma_operator.c` | 46\_comma\_operator.c　原檔：53　新版：題目 98 / 講解 99 | 1 組 |
| [E45](#ex-47) | [比較只計算與真的更新](#ex-47) `47_expression_statement.c` | 47\_expression\_statement.c　原檔：54　新版：題目 100 / 講解 101 | 1 組 |
| [E46](#ex-12) | [由 UPC 前十一位計算檢查碼](#ex-12) `12_upc.c` | 12\_upc.c　原檔：55, 56　新版：題目 102 / 講解 103, 104 | 9 組 |
| [E47](#ex-48) | [用零加權和檢查 UPC 公式](#ex-48) `48_upc_boundary.c` | 48\_upc\_boundary.c　原檔：57　新版：題目 105 / 講解 106 | 1 組 |
| [E48](#ex-49) | [修正平均值程式的三個問題](#ex-49) `49_debug_io_fixed.c` | 49\_debug\_io\_fixed.c　原檔：58　新版：題目 107 / 講解 108 | 3 組 |
| [E49](#ex-13) | [計算以半小時為單位的停車費](#ex-13) `13_parking.c` | 13\_parking.c　原檔：59, 60, 61, 62　新版：題目 109 / 講解 110, 111, 112, 113 | 12 組 |
| [E50](#ex-50) | [驗證可計算的總檢核答案](#ex-50) `50_quiz_integrated.c` | 50\_quiz\_integrated.c　原檔：63　新版：題目 114 / 講解 115 | 1 組 |
| [E51](#ex-51) | [觀察 scanf 星號的抑制賦值](#ex-51) `51_scan_suppression.c` | 51\_scan\_suppression.c　原檔：64　新版：題目 116 / 講解 117 | 4 組 |
| [E52](#ex-52) | [觀察數值跳脫序列的邊界](#ex-52) `52_numeric_escapes.c` | 52\_numeric\_escapes.c　原檔：65　新版：題目 118 / 講解 119 | 1 組 |
| [E53](#ex-14) | [用不同進位顯示同一個值](#ex-14) `14_format_extras.c` | 14\_format\_extras.c　原檔：66　新版：題目 120 / 講解 121 | 1 組 |

原稿頁次照錄，未將未附於本次任務的 CH1–4 投影片當成已重新核對的來源。

CH1–4 內容來源：上傳之完整程式碼與解題說明 HTML。版型來源：CH5–7 案例實作手冊。
保留原稿53題與133組資料 · 單一檔案離線閱讀 · 原始碼仍為可複製文字

---


<a id="toc-chapter-ch5"></a>

# CH5–7：完整案例實作手冊

來源：`CH5-7_完整程式碼與解題說明.html`

C PROGRAMMING / COMPLETE EXAMPLE HANDBOOK

# 從完整題目開始，把解題思路落實成可測試的程式。

整合選擇敘述、迴圈與基本型別。每題先定義輸入與輸出，再逐步拆解流程，提供完整 C 程式及一般、邊界、錯誤路徑的具體測試。

**16**正式實際案例

**20**明確標示的語法補充

**37**可獨立編譯的完整程式

**262**完整輸入／輸出測試資料

**本次 Linux 實測**GCC 269/269Clang 269/269GCC + UBSan 269/269[判準與教學警告 →](#guide)

**01先看完整題目**情境、輸入、輸出、限制與可直接使用的範例。

**02理解解題過程**流程、變數、固定範例追蹤及解法成立的理由。

**03編譯並核對測試**完整程式、預期輸出、結束碼與錯誤路徑。

**教材沿用與新增：**C01–C16 是整合版原有正式案例；S01–S20 是將語法片段／除錯練習補成可執行題目。原有17份程式完整保留。平台觀察值另行標示，不當成所有電腦的固定答案。

## 全部實作主題

36 / 36 個主題

沒有符合條件的主題。

[C01正式案例選擇敘述

### 成績等第判定

為課程成績系統撰寫單筆等第判定程式。讀入一個整數成績，先驗證範圍，再依規則只輸出一個等第。

ifelse if區間char

1 份完整程式 · 14 組測試資料↗](#C01)[C02正式案例選擇敘述

### 分段手續費計算

依原教材的假設費率，計算一筆交易的手續費。先找交易金額所屬區間，套用該區間公式，最後套用最低收費。這是教學假設，並非現行券商費率。

if費率double邊界值

1 份完整程式 · 19 組測試資料↗](#C02)[C03正式案例選擇敘述

### 四則計算器

讀入兩個整數與中間的運算符號，用 switch 完成 +、-、\*、/ 四則運算。除法必須得到小數結果，並處理除以零與未知符號。

switch除以零cast運算子

1 份完整程式 · 12 組測試資料↗](#C03)[C04正式案例選擇敘述

### 英文日期格式化

把月/日/年的數字日期轉成英文日期句子。輸出前須確認日期存在，包括大小月及西元閏年；日期的英文序數字尾也必須正確。

switch日期閏年序數

1 份完整程式 · 19 組測試資料↗](#C04)[C05正式案例迴圈

### 找出足夠大的 2 次方容量

某緩衝區只能選擇 1、2、4、8、16…等容量。輸入需求 n，找出不小於 n 的最小 2 次方容量 p。

while2次方不變數

1 份完整程式 · 9 組測試資料↗](#C05)[C06正式案例迴圈

### 平方表：while 與 for 雙版本

讀入表格長度 n，依序列印 1～n 的整數與平方。先完成 while 版本，再改寫為 for 版本，兩者輸出必須完全相同。

whilefor平方迴圈端點

2 份完整程式 · 7 組測試資料↗](#C06)[C07正式案例迴圈

### 以 0 結束的數列加總

連續讀入整數，累加所有非零資料，遇到 0 結束並輸出總和。也允許輸入檔在資料末尾直接結束。

whilesentinelEOF加總

1 份完整程式 · 12 組測試資料↗](#C07)[C08正式案例迴圈

### 計算十進位位數

輸入一個非負整數，以反覆整除 10 的方式計算其十進位位數；不得把數字轉成字串處理。

do while位數整除

1 份完整程式 · 9 組測試資料↗](#C08)[C09正式案例迴圈

### 質數判定與提早停止

判斷整數 n 是否為質數。若不是質數且 n≥2，找出最小的整除因子；找到第一個因子後立即停止搜尋。

forbreak質數平方根

1 份完整程式 · 11 組測試資料↗](#C09)[C10正式案例迴圈

### 座位編號產生器

為活動會場建立矩形座位表。輸入列數 rows 與每列座位數 cols，以「列-座號」格式逐列輸出。

巢狀for座位格式

1 份完整程式 · 8 組測試資料↗](#C10)[C11正式案例迴圈

### 距離感測資料清理

連續讀入距離感測值，忽略超出有效量測範圍的資料。收到停止記號後，輸出有效資料筆數及平均距離。此為教學模擬，不是設備規格。

continuebreak資料清理平均

1 份完整程式 · 11 組測試資料↗](#C11)[C12正式案例基本型別

### 量測目前環境的型別

不要背誦「64 位元電腦的 long 一定是 8 bytes」。撰寫不需輸入的實驗程式，查詢並輸出實際編譯環境的型別大小、整數範圍及浮點特性。

sizeoflimits.hfloat.h環境觀察

1 份完整程式 · 1 組測試資料↗](#C12)[C13正式案例基本型別

### RGB 影片的記憶體估算

影像系統要將多張 RGB 影格同時存入記憶體。每個像素固定佔 3 bytes，請計算所有未壓縮影格所需的 bytes 與 MiB。

castoverflowRGBMiB

1 份完整程式 · 8 組測試資料↗](#C13)[C14正式案例基本型別

### 一行文字的分類統計

讀取一行 ASCII 文字，統計總字元數、英文字母數、數字數及空白字元數。必須以 getchar 逐字讀取，不使用字串陣列。

getcharctypeEOFASCII

1 份完整程式 · 9 組測試資料↗](#C14)[C15正式案例綜合實作

### 互動式零用金帳本

建立可反覆輸入指令的教學帳本，支援清零、收入、支出、查詢與離開。餘額以最小單位「分」存成整數，拒絕非法交易且不改變原餘額。

switchfor狀態整數分

1 份完整程式 · 15 組測試資料↗](#C15)[C16正式案例綜合實作

### 班級成績統計器

輸入預計蒐集的合法成績筆數 n，逐筆處理成績。超出 0～100 的值略過並要求下一筆，蒐集滿 n 筆後輸出平均、最高、最低與及格人數。

whilecontinue統計有效筆數

1 份完整程式 · 11 組測試資料↗](#C16)[S01語法補充選擇敘述

### 比較、連鎖不等式與否定的解析

讀取一個整數 x，分別觀察正確區間判斷、錯誤連鎖比較的實際解析、否定括號，以及 == 與 = 的差異。最後印出 x 的副本被指派成 0 後的值。

比較區間指派

1 份完整程式 · 6 組測試資料↗](#S01)[S02語法補充選擇敘述

### 短路求值與被略過的自增

輸入 total、den、i、j。先用短路條件保護除法，再分別觀察 i>0 && ++j>0 及 i>0 || ++j>0。AND 與 OR 示範都從同一個原始 j 開始。

短路&&||

1 份完整程式 · 4 組測試資料↗](#S02)[S03語法補充選擇敘述

### 大括號與 else 配對

輸入 outer、inner，分別模擬「else 配對內層 if」與「else 配對外層 if」兩種結構，輸出各自是否執行 ACTION、FALLBACK 或沒有動作。

ifelse大括號

1 份完整程式 · 5 組測試資料↗](#S03)[S04語法補充選擇敘述

### bool、條件運算子與獨立 if

輸入 a、b 與 flag，將 flag 轉成 bool，找出 a、b 最大值，觀察 ?: 只自增被選中的變數，並比較兩個獨立 if 與 if/else if 命中的次數。

bool?:else if

1 份完整程式 · 4 組測試資料↗](#S04)[S05語法補充選擇敘述

### switch 分派、共用標籤與 fall-through

輸入 command 與 grade。第一段依command分派命令；第二段刻意不在各grade之間break，重現教材從入口一路向下執行的字串串接。

switchbreakfall-through

1 份完整程式 · 5 組測試資料↗](#S05)[S06語法補充選擇敘述

### 邏輯 AND 與低8位元運算

輸入0～255的兩個整數a、b，比較邏輯AND和位元AND，並列出OR、XOR、a的低8位反相及左右移2位結果。

位元unsigned&&

1 份完整程式 · 5 組測試資料↗](#S06)[S07語法補充迴圈

### 計數端點、逗號運算子與多變數更新

輸入n，列印0～n-1與1～n兩種計數，輸出外部宣告的迴圈變數終值，再觀察教材的逗號運算子與三變數for更新。

forcomma作用域

1 份完整程式 · 4 組測試資料↗](#S07)[S08語法補充迴圈

### 不用乘法的奇數累加平方表

沿用C06的平方表輸入輸出，但不可用乘法計算平方。利用相鄰平方差為3、5、7…，由1開始累加下一個奇數。此題補齊原Ch6 square3.c的另一種方法。

for平方差

1 份完整程式 · 5 組測試資料↗](#S08)[S09語法補充迴圈

### while、do、for 與 continue 的執行次數

輸入n，量測相同計數條件下while、do和for的本體次數，再用for跳過偶數，輸出0～n-1中的奇數。

whiledocontinue

1 份完整程式 · 4 組測試資料↗](#S09)[S10語法補充迴圈

### 有意的空本體與讀到行尾

先執行教材的有意空本體倒數，輸出最終i；接著略過輸入的第一行，再印下一個字元的數值，觀察空本體如何在條件內完成讀取。

空敘述EOFgetchar

1 份完整程式 · 4 組測試資料↗](#S10)[S11語法補充基本型別

### 整數常數進位與輸入輸出格式

觀察原始碼中10、010、0x10的差異，再分別以十進位、八進位、十六進位格式讀取三個unsigned值並全部用十進位印出。

八進位十六進位scanf

1 份完整程式 · 5 組測試資料↗](#S11)[S12語法補充基本型別

### unsigned 回繞、整數提升與混合比較

不讀取輸入，示範UINT\_MAX加1U回繞、int的-1與1U比較時的轉換，並在8-bit unsigned char環境中觀察250+10先得到260、轉回byte後得到4。

unsigned整數提升wrap

1 份完整程式 · 1 組測試資料↗](#S12)[S13語法補充基本型別

### 先轉型再除法：平均值與零筆資料

輸入sum、count，對比(double)(sum/count)與(double)sum/count；count=0時輸出NO\_DATA，不做除法。此題補成第93頁平均值除錯題的完整程式。

cast整數除法零分母

1 份完整程式 · 5 組測試資料↗](#S13)[S14語法補充基本型別

### float、double、long double 的 I/O 與精度觀察

分別讀入float、double與long double，使用正確格式輸出，再印出0.1+0.2的高精度觀察及只顯示兩位小數的結果。

float%lf精度

1 份完整程式 · 4 組測試資料↗](#S14)[S15語法補充基本型別

### 字元、跳脫字元與 toupper

讀入一個ASCII字元，印出其數值、大寫版本與數字值；最後示範八進位跳脫、分開十六進位跳脫與tab輸出。

charASCIItoupper

1 份完整程式 · 5 組測試資料↗](#S15)[S16語法補充基本型別

### scanf 後殘留的換行與下一個命令

先用scanf讀整數，再用getchar觀察下一個未消耗字元，最後用scanf(" %c")讀下一個非空白命令。

scanfgetchar輸入緩衝

1 份完整程式 · 5 組測試資料↗](#S16)[S17語法補充基本型別

### typedef、sizeof 與精確寬度型別

不讀取輸入，驗證Cents只是long long的別名、sizeof(char)=1，且固定型別的sizeof(i++)不會自增i；若環境提供uint32\_t，使用PRIu32印出42。

typedefsizeofstdint

1 份完整程式 · 1 組測試資料↗](#S17)[S18語法補充綜合實作

### 安全的 unsigned 倒數

輸入n，依序輸出n-1到0；n=0時不處理任何項目。修正原題unsigned i>=0永遠為真的問題。

unsigned倒數除錯

1 份完整程式 · 5 組測試資料↗](#S18)[S19語法補充綜合實作

### 修正空本體與閉區間接受條件

將第93頁兩個除錯片段補成完整程式：先判斷score是否落在0～100（含端點），再由i=0遞增到3並逐次印出。

除錯空本體閉區間

1 份完整程式 · 5 組測試資料↗](#S19)[S20語法補充基本型別

### 單行訊息長度：原 length.c 的完整化

只計算一行訊息長度，包含空白與標點，不包含結尾換行。此題將原Ch7 length.c / length2.c的核心功能獨立保留，與C14的分類統計區分。

getchar長度EOF

1 份完整程式 · 5 組測試資料↗](#S20)

### 帶走完整實作資源

含37份C程式、262組測試資料、Python測試器、實測報告與來源對照。

C01正式案例選擇敘述C11


<a id="toc-ch5-01"></a>

# 成績等第判定

ifelse if區間char

**對應整合版：**第 10–12 頁　·　1 份程式　·　14 組測試
**來源對照：**Ch5 pp.15–29：if / else if 與區間判斷
題目、規則與程式沿用既有資源包；本 HTML 另補變數表、追蹤、正確性說明與測試用途標籤。

[01 完整題目](#C01/problem)[02 解題說明](#C01/solution)[03 完整程式](#C01/code)[04 測試資料](#C01/tests)[05 易錯提醒](#C01/tips)

01

## 完整題目

先確認規格，再寫程式

為課程成績系統撰寫單筆等第判定程式。讀入一個整數成績，先驗證範圍，再依規則只輸出一個等第。

### 輸入規格

一個整數 score；合法範圍 0～100。

### 輸出規格

合法輸入輸出 A、B、C、D 或 F；超出範圍輸出 ERR\_RANGE；無法讀入整數輸出 ERR\_INPUT。

### 規則與限制

- 90～100：A；80～89：B；70～79：C。
- 60～69：D；0～59：F。
- 同一筆成績只能命中一個等第；上下界皆包含。

### 輸入／輸出範例

STDIN · 範例輸入

```
85
```

3 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
B
```

2 bytes · 包含程式實際輸出的換行與空白

輸入區不包含提示文字。下載後可直接作為標準輸入檔；檔案結束代表 EOF，不需輸入「EOF」三個字母。

目前為自學模式：完整題目與測試輸入仍可閱讀。按上方「顯示解答」即可查看解法、程式與預期輸出。這是閱讀遮蔽功能，不是考試保密機制。

02

## 解題說明

理解狀態如何改變

**STEP 01**讀取 score

**STEP 02**排除範圍錯誤

**STEP 03**由高到低測門檻

**STEP 04**印出唯一等第

### 核心思考與步驟

1. 先把不合法成績排除，後面的分支才共享 0≤score≤100 的前提。
2. 門檻由高到低測試；85 在 >=90 失敗後，於 >=80 命中。
3. else if 只執行第一個成立分支，避免多個獨立 if 覆寫結果。

### 重要變數與狀態

| 名稱 | 型別／形式 | 用途 |
| --- | --- | --- |
| score | int | 待判定成績 |
| grade | char | 最後選定的一個等第 |

### 固定範例追蹤

全表

這是依指定範例整理的狀態表；切換步驟只改變標記，不是在瀏覽器中編譯或執行 C。

| 檢查 | 代入 85 | 行為 |
| --- | --- | --- |
| 輸入範圍 | 0 ≤ 85 ≤ 100 | 通過 |
| score ≥ 90 | 假 | 繼續 |
| score ≥ 80 | 真 | grade = B |
| 其餘 else if | 不再測試 | 輸出 B |

### 為什麼這個解法成立？

有效輸入會落在互斥且完整的五個區間中。依序使用 else if，第一個成立分支決定等第，後面的門檻不再執行。

時間 O(1)；額外空間 O(1)。

03

## 完整程式碼

每一份都可獨立編譯

c01\_grade.c

完整程式 · 18 行 · 長行可橫向捲動

```
#include <stdio.h>
int main(void) {
    int score;
    char grade;
    if (scanf("%d", &score) != 1) {
        puts("ERR_INPUT"); return 1;
    }
    if (score < 0 || score > 100) {
        puts("ERR_RANGE"); return 1;
    }
    if (score >= 90) grade = 'A';
    else if (score >= 80) grade = 'B';
    else if (score >= 70) grade = 'C';
    else if (score >= 60) grade = 'D';
    else grade = 'F';
    printf("%c\n", grade);
    return 0;
}
```

單題編譯（在包含本檔的資料夾執行）：`gcc -std=c11 -Wall -Wextra -Wpedantic c01_grade.c -o c01_grade`

完整測試方式與 Windows cmd.exe 操作範例請見[使用與驗證說明](#guide)。此頁為離線教材，不提供任意 C 程式的網頁執行環境。

04


## 測試資料

14 組完整資料

核對輸出、結束碼與 stderr。全部輸入／輸出已內嵌，可個別下載。

列印版僅列測試目的與結束碼；完整輸入與輸出請使用 HTML 展開或下載檔案，避免上限測試產生數千行列印內容。

C01-T01**題目示範輸入／輸出**原資源包 · 3 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
85
```

3 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
B
```

2 bytes · 包含程式實際輸出的換行與空白

C01-T02**合法最小值0**原資源包 · 2 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
0
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
F
```

2 bytes · 包含程式實際輸出的換行與空白

C01-T03**F/D門檻前一分**原資源包 · 3 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
59
```

3 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
F
```

2 bytes · 包含程式實際輸出的換行與空白

C01-T04**剛好60分、由F進入D**原資源包 · 3 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
60
```

3 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
D
```

2 bytes · 包含程式實際輸出的換行與空白

C01-T05**D/C門檻前一分**原資源包 · 3 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
69
```

3 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
D
```

2 bytes · 包含程式實際輸出的換行與空白

C01-T06**剛好70分、由D進入C**原資源包 · 3 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
70
```

3 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
C
```

2 bytes · 包含程式實際輸出的換行與空白

C01-T07**C/B門檻前一分**原資源包 · 3 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
79
```

3 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
C
```

2 bytes · 包含程式實際輸出的換行與空白

C01-T08**剛好80分、由C進入B**原資源包 · 3 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
80
```

3 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
B
```

2 bytes · 包含程式實際輸出的換行與空白

C01-T09**B/A門檻前一分**原資源包 · 3 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
89
```

3 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
B
```

2 bytes · 包含程式實際輸出的換行與空白

C01-T10**剛好90分、由B進入A**原資源包 · 3 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
90
```

3 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
A
```

2 bytes · 包含程式實際輸出的換行與空白

C01-T11**合法最大值100**原資源包 · 4 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
100
```

4 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
A
```

2 bytes · 包含程式實際輸出的換行與空白

C01-T12**驗證 ERR\_RANGE**原資源包 · 3 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
-1
```

3 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_RANGE
```

10 bytes · 包含程式實際輸出的換行與空白

C01-T13**驗證 ERR\_RANGE**原資源包 · 4 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
101
```

4 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_RANGE
```

10 bytes · 包含程式實際輸出的換行與空白

C01-T14**驗證 ERR\_INPUT**原資源包 · 2 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
x
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_INPUT
```

10 bytes · 包含程式實際輸出的換行與空白

錯誤分支的非零結束碼也屬預期結果，不代表測試失敗。測試器僅正規化 CRLF 為 LF，其餘空白需保持一致。

05

## 易錯提醒與檢查重點

- 用 59/60、89/90 檢查邊界，而不只測 85。
- grade 用 char 儲存單一字元；字元常數用單引號。

教學輸入契約：數值 token 須可由程式的讀取型別表示；這些範例不是用來解析任意長數字或所有惡意輸入。詳細限制見[共通輸入與測試規則](#guide)。

[← 全部主題](#overview)[C02 分段手續費計算 →](#C02)

C02正式案例選擇敘述C11


<a id="toc-ch5-02"></a>

# 分段手續費計算

if費率double邊界值

**對應整合版：**第 13–16 頁　·　1 份程式　·　19 組測試
**來源對照：**Ch5 pp.30–32：broker.c
題目、規則與程式沿用既有資源包；本 HTML 另補變數表、追蹤、正確性說明與測試用途標籤。

[01 完整題目](#C02/problem)[02 解題說明](#C02/solution)[03 完整程式](#C02/code)[04 測試資料](#C02/tests)[05 易錯提醒](#C02/tips)

01

## 完整題目

先確認規格，再寫程式

依原教材的假設費率，計算一筆交易的手續費。先找交易金額所屬區間，套用該區間公式，最後套用最低收費。這是教學假設，並非現行券商費率。

### 輸入規格

一個有限實數 value，0 < value ≤ 1,000,000,000。

### 輸出規格

輸出 Commission: 金額，顯示到小數第 2 位；非法範圍輸出 ERR\_RANGE；讀取失敗輸出 ERR\_INPUT。

### 規則與限制

- [0,2500)：30 + 0.017v；[2500,6250)：56 + 0.0066v。
- [6250,20000)：76 + 0.0034v；[20000,50000)：100 + 0.0022v。
- [50000,500000)：155 + 0.0011v；[500000,∞)：255 + 0.0009v。
- 完成分段計算後，低於 39 一律改收 39；不採累進分段加總。

### 輸入／輸出範例

STDIN · 範例輸入

```
30000
```

6 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
Commission: 166.00
```

19 bytes · 包含程式實際輸出的換行與空白

輸入區不包含提示文字。下載後可直接作為標準輸入檔；檔案結束代表 EOF，不需輸入「EOF」三個字母。

目前為自學模式：完整題目與測試輸入仍可閱讀。按上方「顯示解答」即可查看解法、程式與預期輸出。這是閱讀遮蔽功能，不是考試保密機制。

02

## 解題說明

理解狀態如何改變

**STEP 01**驗證金額

**STEP 02**選一個費率區間

**STEP 03**套用最低 39

**STEP 04**顯示兩位小數

### 核心思考與步驟

1. 把區間視為左閉右開，直接沿用原程式的 < 上界規則。
2. 30000 命中 [20000,50000)，得到 100+0.0022×30000=166。
3. 最低收費是第二層規則，不是另一個金額區間。

### 重要變數與狀態

| 名稱 | 型別／形式 | 用途 |
| --- | --- | --- |
| value | double | 交易金額 |
| fee | double | 套用公式後的手續費 |

### 固定範例追蹤

全表

這是依指定範例整理的狀態表；切換步驟只改變標記，不是在瀏覽器中編譯或執行 C。

| 步驟 | 計算／判斷 | 結果 |
| --- | --- | --- |
| 選區間 | 20000 ≤ 30000 < 50000 | 使用 100 + 0.0022v |
| 代公式 | 100 + 0.0022 × 30000 | 166 |
| 最低收費 | 166 < 39 為假 | 保持 166 |
| 格式化 | %.2f | Commission: 166.00 |

### 為什麼這個解法成立？

所有通過驗證的金額只使用一個區間公式。最低收費在區間判斷完成後獨立套用，所以每筆正常輸出的金額不小於 39。表格描述費率區間；合法輸入仍受 0 < value ≤ 10^9 限制。

時間 O(1)；額外空間 O(1)。

03

## 完整程式碼

每一份都可獨立編譯

c02\_commission.c

完整程式 · 25 行 · 長行可橫向捲動

```
#include <stdio.h>
int main(void) {
    double value, fee;
    if (scanf("%lf", &value) != 1) {
        puts("ERR_INPUT"); return 1;
    }
    if (!(value > 0.0 && value <= 1.0e9)) {
        puts("ERR_RANGE"); return 1;
    }
    if (value < 2500.0)
        fee = 30.0 + 0.017 * value;
    else if (value < 6250.0)
        fee = 56.0 + 0.0066 * value;
    else if (value < 20000.0)
        fee = 76.0 + 0.0034 * value;
    else if (value < 50000.0)
        fee = 100.0 + 0.0022 * value;
    else if (value < 500000.0)
        fee = 155.0 + 0.0011 * value;
    else
        fee = 255.0 + 0.0009 * value;
    if (fee < 39.0) fee = 39.0;
    printf("Commission: %.2f\n", fee);
    return 0;
}
```

單題編譯（在包含本檔的資料夾執行）：`gcc -std=c11 -Wall -Wextra -Wpedantic c02_commission.c -o c02_commission`

完整測試方式與 Windows cmd.exe 操作範例請見[使用與驗證說明](#guide)。此頁為離線教材，不提供任意 C 程式的網頁執行環境。

04


## 測試資料

19 組完整資料

核對輸出、結束碼與 stderr。全部輸入／輸出已內嵌，可個別下載。

列印版僅列測試目的與結束碼；完整輸入與輸出請使用 HTML 展開或下載檔案，避免上限測試產生數千行列印內容。

C02-T01**題目示範輸入／輸出**原資源包 · 6 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
30000
```

6 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Commission: 166.00
```

19 bytes · 包含程式實際輸出的換行與空白

C02-T02**計算值低於39，套用最低收費**原資源包 · 4 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
100
```

4 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Commission: 39.00
```

18 bytes · 包含程式實際輸出的換行與空白

C02-T03**2500屬第二區間的下界**原資源包 · 5 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
2500
```

5 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Commission: 72.50
```

18 bytes · 包含程式實際輸出的換行與空白

C02-T04**6250屬第三區間的下界**原資源包 · 5 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
6250
```

5 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Commission: 97.25
```

18 bytes · 包含程式實際輸出的換行與空白

C02-T05**20000屬第四區間的下界**原資源包 · 6 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
20000
```

6 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Commission: 144.00
```

19 bytes · 包含程式實際輸出的換行與空白

C02-T06**50000屬第五區間的下界**原資源包 · 6 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
50000
```

6 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Commission: 210.00
```

19 bytes · 包含程式實際輸出的換行與空白

C02-T07**500000屬最後區間的下界**原資源包 · 7 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
500000
```

7 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Commission: 705.00
```

19 bytes · 包含程式實際輸出的換行與空白

C02-T08**驗證 ERR\_RANGE**原資源包 · 2 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
0
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_RANGE
```

10 bytes · 包含程式實際輸出的換行與空白

C02-T09**驗證 ERR\_RANGE**原資源包 · 4 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
-10
```

4 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_RANGE
```

10 bytes · 包含程式實際輸出的換行與空白

C02-T10**驗證 ERR\_RANGE**原資源包 · 4 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
nan
```

4 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_RANGE
```

10 bytes · 包含程式實際輸出的換行與空白

C02-T11**非數字 token：scanf 讀取失敗**本 HTML 新增測試 · 2 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
x
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_INPUT
```

10 bytes · 包含程式實際輸出的換行與空白

C02-T12**最大合法交易金額**本 HTML 新增測試 · 11 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
1000000000
```

11 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Commission: 900255.00
```

22 bytes · 包含程式實際輸出的換行與空白

C02-T13**交易金額超出上限**本 HTML 新增測試 · 11 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
1000000001
```

11 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_RANGE
```

10 bytes · 包含程式實際輸出的換行與空白

C02-T14**2500 門檻前一個整數**本 HTML 新增測試 · 5 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
2499
```

5 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Commission: 72.48
```

18 bytes · 包含程式實際輸出的換行與空白

C02-T15**6250 門檻前一個整數**本 HTML 新增測試 · 5 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
6249
```

5 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Commission: 97.24
```

18 bytes · 包含程式實際輸出的換行與空白

C02-T16**20000 門檻前一個整數**本 HTML 新增測試 · 6 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
19999
```

6 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Commission: 144.00
```

19 bytes · 包含程式實際輸出的換行與空白

C02-T17**50000 門檻前一個整數**本 HTML 新增測試 · 6 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
49999
```

6 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Commission: 210.00
```

19 bytes · 包含程式實際輸出的換行與空白

C02-T18**500000 門檻前一個整數**本 HTML 新增測試 · 7 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
499999
```

7 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Commission: 705.00
```

19 bytes · 包含程式實際輸出的換行與空白

C02-T19**正無窮值不屬於合法有限範圍**本 HTML 新增測試 · 4 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
inf
```

4 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_RANGE
```

10 bytes · 包含程式實際輸出的換行與空白

錯誤分支的非零結束碼也屬預期結果，不代表測試失敗。測試器僅正規化 CRLF 為 LF，其餘空白需保持一致。

05

## 易錯提醒與檢查重點

- 原表格端點較含糊，本版以原始程式的比較式界定邊界。
- 使用 double 與 %.2f 只是本題顯示方式，不保證十進位金額完全精確。

教學輸入契約：數值 token 須可由程式的讀取型別表示；這些範例不是用來解析任意長數字或所有惡意輸入。詳細限制見[共通輸入與測試規則](#guide)。

[← C01 成績等第判定](#C01)[C03 四則計算器 →](#C03)

C03正式案例選擇敘述C11


<a id="toc-ch5-03"></a>

# 四則計算器

switch除以零cast運算子

**對應整合版：**第 20–22 頁　·　1 份程式　·　12 組測試
**來源對照：**Ch5 pp.75–76：計算器；pp.58–68：switch
題目、規則與程式沿用既有資源包；本 HTML 另補變數表、追蹤、正確性說明與測試用途標籤。

[01 完整題目](#C03/problem)[02 解題說明](#C03/solution)[03 完整程式](#C03/code)[04 測試資料](#C03/tests)[05 易錯提醒](#C03/tips)

01

## 完整題目

先確認規格，再寫程式

讀入兩個整數與中間的運算符號，用 switch 完成 +、-、\*、/ 四則運算。除法必須得到小數結果，並處理除以零與未知符號。

### 輸入規格

格式為 a op b；a、b 為 -10000～10000 的整數，op 為單一字元。

### 輸出規格

正常輸出 Result: 數值（小數 2 位）；其他輸出 ERR\_INPUT、ERR\_RANGE、ERR\_ZERO 或 ERR\_OP。

### 規則與限制

- 只接受 +、-、\*、/。
- 除法先檢查 b 是否為 0；其他三種運算允許 b=0。
- 先將 a 轉成 double，使計算不依賴 int 乘積能否容納結果。

### 輸入／輸出範例

STDIN · 範例輸入

```
7 / 2
```

6 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
Result: 3.50
```

13 bytes · 包含程式實際輸出的換行與空白

輸入區不包含提示文字。下載後可直接作為標準輸入檔；檔案結束代表 EOF，不需輸入「EOF」三個字母。

目前為自學模式：完整題目與測試輸入仍可閱讀。按上方「顯示解答」即可查看解法、程式與預期輸出。這是閱讀遮蔽功能，不是考試保密機制。

02

## 解題說明

理解狀態如何改變

**STEP 01**讀取 a op b

**STEP 02**共同範圍驗證

**STEP 03**switch 選運算

**STEP 04**成功輸出或回報錯誤

### 核心思考與步驟

1. 輸入成功後先驗證共同範圍，再依 op 分派。
2. 除以零隻屬於 / 分支；不要讓合法的 7+0 被拒絕。
3. 每個成功 case 都設定 result；錯誤路徑 return，避免讀未初始化值。

### 重要變數與狀態

| 名稱 | 型別／形式 | 用途 |
| --- | --- | --- |
| a / b | int | 左右運算元 |
| op | char | 單一運算符號 |
| result | double | 成功運算的結果 |

### 固定範例追蹤

全表

這是依指定範例整理的狀態表；切換步驟只改變標記，不是在瀏覽器中編譯或執行 C。

| 步驟 | 7 / 2 | 說明 |
| --- | --- | --- |
| 選擇分支 | case '/' | 只做除法 |
| 檢查分母 | 2 != 0 | 可進行 |
| 先轉型 | (double)7 / 2 | 以浮點除法計算 |
| 結果 | 3.5 | 輸出 Result: 3.50 |

### 為什麼這個解法成立？

每個正常 case 都會設定 result；非法符號與零分母會先 return，不會使用尚未初始化的結果。共同範圍檢查先於運算符號檢查。

時間 O(1)；額外空間 O(1)。

03

## 完整程式碼

每一份都可獨立編譯

c03\_calculator.c

完整程式 · 24 行 · 長行可橫向捲動

```
#include <stdio.h>
int main(void) {
    int a, b;
    char op;
    double result;
    if (scanf("%d %c %d", &a, &op, &b) != 3) {
        puts("ERR_INPUT"); return 1;
    }
    if (a < -10000 || a > 10000 ||
        b < -10000 || b > 10000) {
        puts("ERR_RANGE"); return 1;
    }
    switch (op) {
    case '+': result = (double)a + b; break;
    case '-': result = (double)a - b; break;
    case '*': result = (double)a * b; break;
    case '/':
        if (b == 0) { puts("ERR_ZERO"); return 1; }
        result = (double)a / b; break;
    default: puts("ERR_OP"); return 1;
    }
    printf("Result: %.2f\n", result);
    return 0;
}
```

單題編譯（在包含本檔的資料夾執行）：`gcc -std=c11 -Wall -Wextra -Wpedantic c03_calculator.c -o c03_calculator`

完整測試方式與 Windows cmd.exe 操作範例請見[使用與驗證說明](#guide)。此頁為離線教材，不提供任意 C 程式的網頁執行環境。

04


## 測試資料

12 組完整資料

核對輸出、結束碼與 stderr。全部輸入／輸出已內嵌，可個別下載。

列印版僅列測試目的與結束碼；完整輸入與輸出請使用 HTML 展開或下載檔案，避免上限測試產生數千行列印內容。

C03-T01**題目示範輸入／輸出**原資源包 · 6 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
7 / 2
```

6 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Result: 3.50
```

13 bytes · 包含程式實際輸出的換行與空白

C03-T02**加法分支**原資源包 · 6 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
4 + 5
```

6 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Result: 9.00
```

13 bytes · 包含程式實際輸出的換行與空白

C03-T03**減法結果為負數**原資源包 · 6 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
4 - 5
```

6 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Result: -1.00
```

14 bytes · 包含程式實際輸出的換行與空白

C03-T04**最大運算元相乘，避免先做int乘法**原資源包 · 14 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
10000 * 10000
```

14 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Result: 100000000.00
```

21 bytes · 包含程式實際輸出的換行與空白

C03-T05**驗證 ERR\_ZERO**原資源包 · 6 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
7 / 0
```

6 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_ZERO
```

9 bytes · 包含程式實際輸出的換行與空白

C03-T06**驗證 ERR\_OP**原資源包 · 6 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
7 % 2
```

6 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_OP
```

7 bytes · 包含程式實際輸出的換行與空白

C03-T07**加法允許第二運算元為0**原資源包 · 6 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
7 + 0
```

6 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Result: 7.00
```

13 bytes · 包含程式實際輸出的換行與空白

C03-T08**驗證 ERR\_INPUT**原資源包 · 2 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
x
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_INPUT
```

10 bytes · 包含程式實際輸出的換行與空白

C03-T09**第一個運算元超出範圍**本 HTML 新增測試 · 10 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
10001 + 1
```

10 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_RANGE
```

10 bytes · 包含程式實際輸出的換行與空白

C03-T10**第二個運算元超出範圍**本 HTML 新增測試 · 11 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
1 + -10001
```

11 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_RANGE
```

10 bytes · 包含程式實際輸出的換行與空白

C03-T11**負數浮點除法**本 HTML 新增測試 · 7 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
-7 / 2
```

7 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Result: -3.50
```

14 bytes · 包含程式實際輸出的換行與空白

C03-T12**缺少第二個運算元**本 HTML 新增測試 · 4 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
1 +
```

4 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_INPUT
```

10 bytes · 包含程式實際輸出的換行與空白

錯誤分支的非零結束碼也屬預期結果，不代表測試失敗。測試器僅正規化 CRLF 為 LF，其餘空白需保持一致。

05

## 易錯提醒與檢查重點

- 原例以 if 串接；本版改用 switch，新增錯誤路徑。
- (double)a / b 是「先轉型再運算」，第 7 章會再次剖析。

教學輸入契約：數值 token 須可由程式的讀取型別表示；這些範例不是用來解析任意長數字或所有惡意輸入。詳細限制見[共通輸入與測試規則](#guide)。

[← C02 分段手續費計算](#C02)[C04 英文日期格式化 →](#C04)

C04正式案例選擇敘述C11


<a id="toc-ch5-04"></a>

# 英文日期格式化

switch日期閏年序數

**對應整合版：**第 23–26 頁　·　1 份程式　·　19 組測試
**來源對照：**Ch5 pp.69–71：date.c
題目、規則與程式沿用既有資源包；本 HTML 另補變數表、追蹤、正確性說明與測試用途標籤。

[01 完整題目](#C04/problem)[02 解題說明](#C04/solution)[03 完整程式](#C04/code)[04 測試資料](#C04/tests)[05 易錯提醒](#C04/tips)

01

## 完整題目

先確認規格，再寫程式

把月/日/年的數字日期轉成英文日期句子。輸出前須確認日期存在，包括大小月及西元閏年；日期的英文序數字尾也必須正確。

### 輸入規格

格式 mm/dd/yyyy；year 範圍 1900～9999。月份與日期為整數。

### 輸出規格

合法時輸出 Dated this 日序數 day of 英文月份, 年.；格式錯誤輸出 ERR\_INPUT；不存在的日期輸出 ERR\_DATE。

### 規則與限制

- 閏年：能被 400 整除，或能被 4 整除且不能被 100 整除。
- 1、21、31 用 st；2、22 用 nd；3、23 用 rd；其餘用 th。
- 用完整四位數年份；1900 非閏年，2000 為閏年。

### 輸入／輸出範例

STDIN · 範例輸入

```
7/19/2026
```

10 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
Dated this 19th day of July, 2026.
```

35 bytes · 包含程式實際輸出的換行與空白

輸入區不包含提示文字。下載後可直接作為標準輸入檔；檔案結束代表 EOF，不需輸入「EOF」三個字母。

目前為自學模式：完整題目與測試輸入仍可閱讀。按上方「顯示解答」即可查看解法、程式與預期輸出。這是閱讀遮蔽功能，不是考試保密機制。

02

## 解題說明

理解狀態如何改變

**STEP 01**讀取日期

**STEP 02**查該月天數

**STEP 03**驗證日期存在

**STEP 04**輸出日字尾與月份

### 核心思考與步驟

1. 日期驗證和文字輸出分開，避免先印出半句才發現無效日期。
2. 先找該月天數；二月再套閏年條件。
3. 合法日數僅 1～31，直接列 st/nd/rd 的 case，可自然排除 11、12、13。

### 重要變數與狀態

| 名稱 | 型別／形式 | 用途 |
| --- | --- | --- |
| m / d / y | int | 月份、日、年 |
| days | int | 該月允許的最大日數 |

### 固定範例追蹤

全表

這是依指定範例整理的狀態表；切換步驟只改變標記，不是在瀏覽器中編譯或執行 C。

| 步驟 | 7/19/2026 | 結果 |
| --- | --- | --- |
| 年月範圍 | 1900≤2026≤9999；m=7 | 通過 |
| 本月天數 | 七月不是 30 天月，也不是二月 | days=31 |
| 日數範圍 | 1≤19≤31 | 通過 |
| 文字輸出 | 19 對應 th；7 對應 July | Dated this 19th day of July, 2026. |

### 為什麼這個解法成立？

先驗證年月、再求正確天數、再驗證日，避免輸出不存在的日期。因合法日僅 1～31，列舉 1/21/31 等 case 能直接處理序數例外。

時間 O(1)；額外空間 O(1)。

03

## 完整程式碼

每一份都可獨立編譯

c04\_date.c

完整程式 · 45 行 · 長行可橫向捲動

```
#include <stdio.h>
int main(void) {
    int m, d, y, days = 31;
    if (scanf("%d /%d /%d", &m, &d, &y) != 3) {
        puts("ERR_INPUT"); return 1;
    }
    if (y < 1900 || y > 9999 || m < 1 || m > 12) {
        puts("ERR_DATE"); return 1;
    }
    switch (m) {
    case 4: case 6: case 9: case 11:
        days = 30; break;
    case 2:
        days = (y % 400 == 0 ||
                (y % 4 == 0 && y % 100 != 0)) ? 29 : 28;
        break;
    }
    if (d < 1 || d > days) {
        puts("ERR_DATE"); return 1;
    }
    printf("Dated this %d", d);
    switch (d) {
    case 1: case 21: case 31: printf("st"); break;
    case 2: case 22: printf("nd"); break;
    case 3: case 23: printf("rd"); break;
    default: printf("th"); break;
    }
    printf(" day of ");
    switch (m) {
    case 1: printf("January"); break;
    case 2: printf("February"); break;
    case 3: printf("March"); break;
    case 4: printf("April"); break;
    case 5: printf("May"); break;
    case 6: printf("June"); break;
    case 7: printf("July"); break;
    case 8: printf("August"); break;
    case 9: printf("September"); break;
    case 10: printf("October"); break;
    case 11: printf("November"); break;
    case 12: printf("December"); break;
    }
    printf(", %d.\n", y);
    return 0;
}
```

單題編譯（在包含本檔的資料夾執行）：`gcc -std=c11 -Wall -Wextra -Wpedantic c04_date.c -o c04_date`

完整測試方式與 Windows cmd.exe 操作範例請見[使用與驗證說明](#guide)。此頁為離線教材，不提供任意 C 程式的網頁執行環境。

04


## 測試資料

19 組完整資料

核對輸出、結束碼與 stderr。全部輸入／輸出已內嵌，可個別下載。

列印版僅列測試目的與結束碼；完整輸入與輸出請使用 HTML 展開或下載檔案，避免上限測試產生數千行列印內容。

C04-T01**題目示範輸入／輸出**原資源包 · 10 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
7/19/2026
```

10 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Dated this 19th day of July, 2026.
```

35 bytes · 包含程式實際輸出的換行與空白

C04-T02**2000可被400整除，是世紀閏年**原資源包 · 10 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
2/29/2000
```

10 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Dated this 29th day of February, 2000.
```

39 bytes · 包含程式實際輸出的換行與空白

C04-T03**驗證 ERR\_DATE**原資源包 · 10 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
2/29/1900
```

10 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_DATE
```

9 bytes · 包含程式實際輸出的換行與空白

C04-T04**驗證 ERR\_DATE**原資源包 · 10 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
4/31/2026
```

10 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_DATE
```

9 bytes · 包含程式實際輸出的換行與空白

C04-T05**11使用th，不是st**原資源包 · 10 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
1/11/2026
```

10 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Dated this 11th day of January, 2026.
```

38 bytes · 包含程式實際輸出的換行與空白

C04-T06**21使用st**原資源包 · 10 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
1/21/2026
```

10 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Dated this 21st day of January, 2026.
```

38 bytes · 包含程式實際輸出的換行與空白

C04-T07**22使用nd**原資源包 · 10 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
1/22/2026
```

10 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Dated this 22nd day of January, 2026.
```

38 bytes · 包含程式實際輸出的換行與空白

C04-T08**23使用rd**原資源包 · 10 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
1/23/2026
```

10 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Dated this 23rd day of January, 2026.
```

38 bytes · 包含程式實際輸出的換行與空白

C04-T09**驗證 ERR\_DATE**原資源包 · 10 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
13/1/2026
```

10 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_DATE
```

9 bytes · 包含程式實際輸出的換行與空白

C04-T10**驗證 ERR\_DATE**原資源包 · 9 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
0/1/2026
```

9 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_DATE
```

9 bytes · 包含程式實際輸出的換行與空白

C04-T11**驗證 ERR\_INPUT**原資源包 · 10 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
7-19-2026
```

10 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_INPUT
```

10 bytes · 包含程式實際輸出的換行與空白

C04-T12**非數字 token：scanf 讀取失敗**本 HTML 新增測試 · 2 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
x
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_INPUT
```

10 bytes · 包含程式實際輸出的換行與空白

C04-T13**一般閏年**本 HTML 新增測試 · 10 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
2/29/2024
```

10 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Dated this 29th day of February, 2024.
```

39 bytes · 包含程式實際輸出的換行與空白

C04-T14**非閏年的二月 29 日**本 HTML 新增測試 · 10 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
2/29/2026
```

10 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_DATE
```

9 bytes · 包含程式實際輸出的換行與空白

C04-T15**12th 例外**本 HTML 新增測試 · 10 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
1/12/2026
```

10 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Dated this 12th day of January, 2026.
```

38 bytes · 包含程式實際輸出的換行與空白

C04-T16**13th 例外**本 HTML 新增測試 · 10 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
1/13/2026
```

10 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Dated this 13th day of January, 2026.
```

38 bytes · 包含程式實際輸出的換行與空白

C04-T17**最大合法年份與月末**本 HTML 新增測試 · 11 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
12/31/9999
```

11 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Dated this 31st day of December, 9999.
```

39 bytes · 包含程式實際輸出的換行與空白

C04-T18**年份低於下限**本 HTML 新增測試 · 9 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
1/1/1899
```

9 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_DATE
```

9 bytes · 包含程式實際輸出的換行與空白

C04-T19**不存在的第 0 日**本 HTML 新增測試 · 9 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
1/0/2026
```

9 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_DATE
```

9 bytes · 包含程式實際輸出的換行與空白

錯誤分支的非零結束碼也屬預期結果，不代表測試失敗。測試器僅正規化 CRLF 為 LF，其餘空白需保持一致。

05

## 易錯提醒與檢查重點

- 原例只示範格式化；本版新增日期驗證並改用四位年份。
- 12、13 分別是 12th、13th，不可只看個位數。

教學輸入契約：數值 token 須可由程式的讀取型別表示；這些範例不是用來解析任意長數字或所有惡意輸入。詳細限制見[共通輸入與測試規則](#guide)。

[← C03 四則計算器](#C03)[C05 找出足夠大的 2 次方容量 →](#C05)

C05正式案例迴圈C11


<a id="toc-ch5-05"></a>

# 找出足夠大的 2 次方容量

while2次方不變數

**對應整合版：**第 30–32 頁　·　1 份程式　·　9 組測試
**來源對照：**Ch6 p.8：最小的 2 次方
題目、規則與程式沿用既有資源包；本 HTML 另補變數表、追蹤、正確性說明與測試用途標籤。

[01 完整題目](#C05/problem)[02 解題說明](#C05/solution)[03 完整程式](#C05/code)[04 測試資料](#C05/tests)[05 易錯提醒](#C05/tips)

01

## 完整題目

先確認規格，再寫程式

某緩衝區只能選擇 1、2、4、8、16…等容量。輸入需求 n，找出不小於 n 的最小 2 次方容量 p。

### 輸入規格

一個整數 n，1～1,000,000,000。

### 輸出規格

輸出 Capacity: p；讀取或範圍錯誤分別輸出 ERR\_INPUT / ERR\_RANGE。

### 規則與限制

- 初始容量為 1；不足時每次乘以 2。
- 需求剛好是 2 次方時，不再擴大。
- n 的上限使結果最大為 1,073,741,824；以 long long 計算。

### 輸入／輸出範例

STDIN · 範例輸入

```
10
```

3 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
Capacity: 16
```

13 bytes · 包含程式實際輸出的換行與空白

輸入區不包含提示文字。下載後可直接作為標準輸入檔；檔案結束代表 EOF，不需輸入「EOF」三個字母。

目前為自學模式：完整題目與測試輸入仍可閱讀。按上方「顯示解答」即可查看解法、程式與預期輸出。這是閱讀遮蔽功能，不是考試保密機制。

02

## 解題說明

理解狀態如何改變

**STEP 01**p = 1

**STEP 02**檢查 p < n

**STEP 03**不足就 p × 2

**STEP 04**達標後印出 p

### 核心思考與步驟

1. 狀態只需 n 與 p；每回合都保持 p 是 2 次方。
2. while 在執行本體之前判斷，n=1 時不必倍增。
3. 停止時 p≥n；若 p>1，前一個容量 p/2<n，因此答案最小。

### 重要變數與狀態

| 名稱 | 型別／形式 | 用途 |
| --- | --- | --- |
| n | long long | 容量需求 |
| p | long long | 目前候選容量，初值 1 |

### 固定範例追蹤

全表

這是依指定範例整理的狀態表；切換步驟只改變標記，不是在瀏覽器中編譯或執行 C。

| 檢查前 p | p < 10？ | 下一個狀態 |
| --- | --- | --- |
| 1 | 是 | p=2 |
| 2 | 是 | p=4 |
| 4 | 是 | p=8 |
| 8 | 是 | p=16 |
| 16 | 否 | 停止；Capacity: 16 |

### 為什麼這個解法成立？

p 從 1 出發且只倍增，永遠是 2 的次方。停止時 p≥n；若 p>1，上一次 p/2<n，所以不可能存在更小且足夠的 2 次方容量。

時間 O(log n)；額外空間 O(1)。

03

## 完整程式碼

每一份都可獨立編譯

c05\_power2.c

完整程式 · 15 行 · 長行可橫向捲動

```
#include <stdio.h>
int main(void) {
    long long n, p = 1;
    if (scanf("%lld", &n) != 1) {
        puts("ERR_INPUT"); return 1;
    }
    if (n < 1 || n > 1000000000LL) {
        puts("ERR_RANGE"); return 1;
    }
    while (p < n) {
        p *= 2;
    }
    printf("Capacity: %lld\n", p);
    return 0;
}
```

單題編譯（在包含本檔的資料夾執行）：`gcc -std=c11 -Wall -Wextra -Wpedantic c05_power2.c -o c05_power2`

完整測試方式與 Windows cmd.exe 操作範例請見[使用與驗證說明](#guide)。此頁為離線教材，不提供任意 C 程式的網頁執行環境。

04


## 測試資料

9 組完整資料

核對輸出、結束碼與 stderr。全部輸入／輸出已內嵌，可個別下載。

列印版僅列測試目的與結束碼；完整輸入與輸出請使用 HTML 展開或下載檔案，避免上限測試產生數千行列印內容。

C05-T01**題目示範輸入／輸出**原資源包 · 3 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
10
```

3 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Capacity: 16
```

13 bytes · 包含程式實際輸出的換行與空白

C05-T02**n=1時，while本體不執行**原資源包 · 2 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
1
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Capacity: 1
```

12 bytes · 包含程式實際輸出的換行與空白

C05-T03**需求已是2次方，不再倍增**原資源包 · 3 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
16
```

3 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Capacity: 16
```

13 bytes · 包含程式實際輸出的換行與空白

C05-T04**剛超過16，容量須升至32**原資源包 · 3 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
17
```

3 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Capacity: 32
```

13 bytes · 包含程式實際輸出的換行與空白

C05-T05**最大需求值與停止條件**原資源包 · 11 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
1000000000
```

11 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Capacity: 1073741824
```

21 bytes · 包含程式實際輸出的換行與空白

C05-T06**驗證 ERR\_RANGE**原資源包 · 2 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
0
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_RANGE
```

10 bytes · 包含程式實際輸出的換行與空白

C05-T07**非數字 token：scanf 讀取失敗**本 HTML 新增測試 · 2 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
x
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_INPUT
```

10 bytes · 包含程式實際輸出的換行與空白

C05-T08**剛好達到第一次倍增值**本 HTML 新增測試 · 2 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
2
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Capacity: 2
```

12 bytes · 包含程式實際輸出的換行與空白

C05-T09**需求超出上限**本 HTML 新增測試 · 11 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
1000000001
```

11 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_RANGE
```

10 bytes · 包含程式實際輸出的換行與空白

錯誤分支的非零結束碼也屬預期結果，不代表測試失敗。測試器僅正規化 CRLF 為 LF，其餘空白需保持一致。

05

## 易錯提醒與檢查重點

- 本體改成 p+=2 會破壞「2 次方」不變數。
- 刪掉更新 p\*=2，n>1 時將無法停止。

教學輸入契約：數值 token 須可由程式的讀取型別表示；這些範例不是用來解析任意長數字或所有惡意輸入。詳細限制見[共通輸入與測試規則](#guide)。

[← C04 英文日期格式化](#C04)[C06 平方表：while 與 for 雙版本 →](#C06)

C06正式案例迴圈C11


<a id="toc-ch5-06"></a>

# 平方表：while 與 for 雙版本

whilefor平方迴圈端點

**對應整合版：**第 33–36 頁　·　2 份程式　·　7 組測試
**來源對照：**Ch6 pp.13–14、43–46：square.c / square2.c / square3.c
題目、規則與程式沿用既有資源包；本 HTML 另補變數表、追蹤、正確性說明與測試用途標籤。

[01 完整題目](#C06/problem)[02 解題說明](#C06/solution)[03 完整程式](#C06/code)[04 測試資料](#C06/tests)[05 易錯提醒](#C06/tips)

01

## 完整題目

先確認規格，再寫程式

讀入表格長度 n，依序列印 1～n 的整數與平方。先完成 while 版本，再改寫為 for 版本，兩者輸出必須完全相同。

### 輸入規格

一個整數 n，1～20。

### 輸出規格

每列輸出 i 與 i 的平方，中間一個空白，共 n 列；錯誤輸出 ERR\_INPUT / ERR\_RANGE。

### 規則與限制

- 包含 i=1 與 i=n；不能多印第 0 列或第 n+1 列。
- 平方使用 1LL\*i\*i，把乘法運算型別先提升。
- 兩個程式各有自己的 main，可分別編譯執行。

### 輸入／輸出範例

STDIN · 範例輸入

```
5
```

2 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
1 1
2 4
3 9
4 16
5 25
```

22 bytes · 包含程式實際輸出的換行與空白

輸入區不包含提示文字。下載後可直接作為標準輸入檔；檔案結束代表 EOF，不需輸入「EOF」三個字母。

目前為自學模式：完整題目與測試輸入仍可閱讀。按上方「顯示解答」即可查看解法、程式與預期輸出。這是閱讀遮蔽功能，不是考試保密機制。

02

## 解題說明

理解狀態如何改變

**STEP 01**i = 1

**STEP 02**檢查 i ≤ n

**STEP 03**印出 i 與平方

**STEP 04**i++ 後回到檢查

### 核心思考與步驟

1. 初始化 i=1；判斷 i<=n；印出 i 和平方；最後 i++。
2. n=5 時本體執行 5 次，條件測試 6 次。
3. 改成 for 時，將初始化、條件、更新搬入表頭，本體不再重複 i++。

### 重要變數與狀態

| 名稱 | 型別／形式 | 用途 |
| --- | --- | --- |
| n | int | 要印出的列數 |
| i | int | 目前列編號 |
| 1LL\*i\*i | long long 運算式 | 本列平方 |

### 固定範例追蹤

全表

這是依指定範例整理的狀態表；切換步驟只改變標記，不是在瀏覽器中編譯或執行 C。

| i | i ≤ 5？ | 輸出 |
| --- | --- | --- |
| 1 | 是 | 1 1 |
| 2 | 是 | 2 4 |
| 3 | 是 | 3 9 |
| 4 | 是 | 4 16 |
| 5 | 是 | 5 25 |
| 6 | 否 | 不輸出，結束 |

### 為什麼這個解法成立？

每次印出一列之後 i 恰好增加 1，因此合法 n 會依序產生 1～n、共 n 列。while 與 for 版本的初始化、條件、本體、更新相同；本例沒有 continue。

時間 O(n)；額外空間 O(1)，不含輸出。

03

## 完整程式碼

每一份都可獨立編譯

本題同時提供 while 與 for 兩個**完整程式**，各有自己的 main。請分開編譯；兩版使用同一組題目與測試資料。

c06\_squares\_while.c

while 版本 · 15 行 · 長行可橫向捲動

```
#include <stdio.h>
int main(void) {
    int n, i = 1;
    if (scanf("%d", &n) != 1) {
        puts("ERR_INPUT"); return 1;
    }
    if (n < 1 || n > 20) {
        puts("ERR_RANGE"); return 1;
    }
    while (i <= n) {
        printf("%d %lld\n", i, 1LL * i * i);
        i++;
    }
    return 0;
}
```

單題編譯（在包含本檔的資料夾執行）：`gcc -std=c11 -Wall -Wextra -Wpedantic c06_squares_while.c -o c06_squares_while`

c06\_squares\_for.c

for 版本 · 14 行 · 長行可橫向捲動

```
#include <stdio.h>
int main(void) {
    int n;
    if (scanf("%d", &n) != 1) {
        puts("ERR_INPUT"); return 1;
    }
    if (n < 1 || n > 20) {
        puts("ERR_RANGE"); return 1;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d %lld\n", i, 1LL * i * i);
    }
    return 0;
}
```

單題編譯（在包含本檔的資料夾執行）：`gcc -std=c11 -Wall -Wextra -Wpedantic c06_squares_for.c -o c06_squares_for`

完整測試方式與 Windows cmd.exe 操作範例請見[使用與驗證說明](#guide)。此頁為離線教材，不提供任意 C 程式的網頁執行環境。

04


## 測試資料

7 組完整資料

核對輸出、結束碼與 stderr。全部輸入／輸出已內嵌，可個別下載。

列印版僅列測試目的與結束碼；完整輸入與輸出請使用 HTML 展開或下載檔案，避免上限測試產生數千行列印內容。

C06-T01**題目示範輸入／輸出**原資源包 · 2 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
5
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
1 1
2 4
3 9
4 16
5 25
```

22 bytes · 包含程式實際輸出的換行與空白

C06-T02**最小列數，恰好印一列**原資源包 · 2 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
1
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
1 1
```

4 bytes · 包含程式實際輸出的換行與空白

C06-T03**連續三列，不多一列也不少一列**原資源包 · 2 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
3
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
1 1
2 4
3 9
```

12 bytes · 包含程式實際輸出的換行與空白

C06-T04**驗證 ERR\_RANGE**原資源包 · 2 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
0
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_RANGE
```

10 bytes · 包含程式實際輸出的換行與空白

C06-T05**驗證 ERR\_RANGE**原資源包 · 3 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
21
```

3 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_RANGE
```

10 bytes · 包含程式實際輸出的換行與空白

C06-T06**非數字 token：scanf 讀取失敗**本 HTML 新增測試 · 2 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
x
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_INPUT
```

10 bytes · 包含程式實際輸出的換行與空白

C06-T07**最大合法列數，兩版本同測**本 HTML 新增測試 · 3 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
20
```

3 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
1 1
2 4
3 9
4 16
5 25
6 36
7 49
8 64
9 81
10 100
11 121
12 144
13 169
14 196
15 225
16 256
17 289
18 324
19 361
20 400
```

119 bytes · 包含程式實際輸出的換行與空白

錯誤分支的非零結束碼也屬預期結果，不代表測試失敗。測試器僅正規化 CRLF 為 LF，其餘空白需保持一致。

05

## 易錯提醒與檢查重點

- while 與 for 的對照以本體不含 continue 為前提；continue 的更新位置另行比較。
- 平方差依序為 3、5、7…，可理解原教材 square3.c 的奇數累加法。

教學輸入契約：數值 token 須可由程式的讀取型別表示；這些範例不是用來解析任意長數字或所有惡意輸入。詳細限制見[共通輸入與測試規則](#guide)。

[← C05 找出足夠大的 2 次方容量](#C05)[C07 以 0 結束的數列加總 →](#C07)

C07正式案例迴圈C11


<a id="toc-ch5-07"></a>

# 以 0 結束的數列加總

whilesentinelEOF加總

**對應整合版：**第 38–40 頁　·　1 份程式　·　12 組測試
**來源對照：**Ch6 pp.15–16：sum.c；Ch7 pp.29–31：sum2.c
題目、規則與程式沿用既有資源包；本 HTML 另補變數表、追蹤、正確性說明與測試用途標籤。

[01 完整題目](#C07/problem)[02 解題說明](#C07/solution)[03 完整程式](#C07/code)[04 測試資料](#C07/tests)[05 易錯提醒](#C07/tips)

01

## 完整題目

先確認規格，再寫程式

連續讀入整數，累加所有非零資料，遇到 0 結束並輸出總和。也允許輸入檔在資料末尾直接結束。

### 輸入規格

最多 1000 筆非零整數，每筆 -1,000,000～1,000,000；以 0 或 EOF 結束。

### 輸出規格

正常輸出 Sum: 總和；讀取失敗、超出範圍或超過筆數時輸出 ERR\_INPUT / ERR\_RANGE。

### 規則與限制

- 0 是結束記號，不計入筆數；正負資料都可累加。
- 完全沒有資料時總和為 0。
- 總和絕對值最多 10^9，使用 long long 儲存。

### 輸入／輸出範例

STDIN · 範例輸入

```
8 23 71 5 0
```

12 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
Sum: 107
```

9 bytes · 包含程式實際輸出的換行與空白

輸入區不包含提示文字。下載後可直接作為標準輸入檔；檔案結束代表 EOF，不需輸入「EOF」三個字母。

目前為自學模式：完整題目與測試輸入仍可閱讀。按上方「顯示解答」即可查看解法、程式與預期輸出。這是閱讀遮蔽功能，不是考試保密機制。

02

## 解題說明

理解狀態如何改變

**STEP 01**讀一筆整數

**STEP 02**處理 0／EOF

**STEP 03**檢查筆數與範圍

**STEP 04**加總後讀下一筆

### 核心思考與步驟

1. 每次先讀資料，再分辨 sentinel、合法資料與錯誤。
2. 迴圈內累加前驗證範圍，總和不含 0 終止記號。
3. status=1、0、EOF 是三種不同結果，不把讀取失敗當成正常資料。

### 重要變數與狀態

| 名稱 | 型別／形式 | 用途 |
| --- | --- | --- |
| n / sum | long long | 本筆整數／累計總和 |
| count | int | 已接受的非零整數筆數 |
| status | int | scanf 回傳狀態 |

### 固定範例追蹤

全表

這是依指定範例整理的狀態表；切換步驟只改變標記，不是在瀏覽器中編譯或執行 C。

| 讀入 | count | sum | 行為 |
| --- | --- | --- | --- |
| 8 | 1 | 8 | 接受 |
| 23 | 2 | 31 | 接受 |
| 71 | 3 | 102 | 接受 |
| 5 | 4 | 107 | 接受 |
| 0 | 4 | 107 | 停止；0 不計入 |

### 為什麼這個解法成立？

每次成功接受資料後，sum 等於目前已接受資料的總和，count 等於非零合法資料筆數。0 不加入總和；正常 EOF 也保留之前的總和。

k 為非零資料筆數：時間 O(k)；額外空間 O(1)。

03

## 完整程式碼

每一份都可獨立編譯

c07\_sum.c

完整程式 · 19 行 · 長行可橫向捲動

```
#include <stdio.h>
int main(void) {
    long long n, sum = 0;
    int count = 0, status;
    while ((status = scanf("%lld", &n)) == 1) {
        if (n == 0) break;
        if (n < -1000000LL || n > 1000000LL ||
            count == 1000) {
            puts("ERR_RANGE"); return 1;
        }
        sum += n;
        count++;
    }
    if (status == 0 || ferror(stdin)) {
        puts("ERR_INPUT"); return 1;
    }
    printf("Sum: %lld\n", sum);
    return 0;
}
```

單題編譯（在包含本檔的資料夾執行）：`gcc -std=c11 -Wall -Wextra -Wpedantic c07_sum.c -o c07_sum`

完整測試方式與 Windows cmd.exe 操作範例請見[使用與驗證說明](#guide)。此頁為離線教材，不提供任意 C 程式的網頁執行環境。

04


## 測試資料

12 組完整資料

核對輸出、結束碼與 stderr。全部輸入／輸出已內嵌，可個別下載。

列印版僅列測試目的與結束碼；完整輸入與輸出請使用 HTML 展開或下載檔案，避免上限測試產生數千行列印內容。

C07-T01**題目示範輸入／輸出**原資源包 · 12 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
8 23 71 5 0
```

12 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Sum: 107
```

9 bytes · 包含程式實際輸出的換行與空白

C07-T02**第一筆就是停止記號**原資源包 · 2 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
0
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Sum: 0
```

7 bytes · 包含程式實際輸出的換行與空白

C07-T03**正負互相抵消**原資源包 · 7 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
5 -5 0
```

7 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Sum: 0
```

7 bytes · 包含程式實際輸出的換行與空白

C07-T04**無結尾換行，以 EOF 結束**原資源包 · 5 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
1 2 3
```

5 bytes · 最後沒有換行，檔案直接結束

STDOUT · 完整預期輸出

```
Sum: 6
```

7 bytes · 包含程式實際輸出的換行與空白

C07-T05**空輸入檔：立即 EOF**原資源包 · 0 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 0 bytes，不是空白行

STDOUT · 完整預期輸出

```
Sum: 0
```

7 bytes · 包含程式實際輸出的換行與空白

C07-T06**驗證 ERR\_INPUT**原資源包 · 4 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
1 x
```

4 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_INPUT
```

10 bytes · 包含程式實際輸出的換行與空白

C07-T07**驗證 ERR\_RANGE**原資源包 · 10 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
1000001 0
```

10 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_RANGE
```

10 bytes · 包含程式實際輸出的換行與空白

C07-T08**1001 筆非零值：超過 1000 筆上限**原資源包上限測試 · 2,004 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0
```

2,004 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_RANGE
```

10 bytes · 包含程式實際輸出的換行與空白

C07-T09**非數字 token：scanf 讀取失敗**本 HTML 新增測試 · 2 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
x
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_INPUT
```

10 bytes · 包含程式實際輸出的換行與空白

C07-T10**1000 筆最大值，總和為 10^9**本 HTML 新增測試 · 8,002 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 0
```

8,002 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Sum: 1000000000
```

16 bytes · 包含程式實際輸出的換行與空白

C07-T11**低於最小合法值**本 HTML 新增測試 · 9 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
-1000001
```

9 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_RANGE
```

10 bytes · 包含程式實際輸出的換行與空白

C07-T12**停止記號後的資料不再讀取**本 HTML 新增測試 · 8 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
1 0 999
```

8 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Sum: 1
```

7 bytes · 包含程式實際輸出的換行與空白

錯誤分支的非零結束碼也屬預期結果，不代表測試失敗。測試器僅正規化 CRLF 為 LF，其餘空白需保持一致。

05

## 易錯提醒與檢查重點

- sum 必須初始化為 0，scanf 的型別必須與 long long 對應。
- 本版修正原教材 for 改寫中格式不一致及未檢查輸入的問題。

教學輸入契約：數值 token 須可由程式的讀取型別表示；這些範例不是用來解析任意長數字或所有惡意輸入。詳細限制見[共通輸入與測試規則](#guide)。

[← C06 平方表：while 與 for 雙版本](#C06)[C08 計算十進位位數 →](#C08)

C08正式案例迴圈C11


<a id="toc-ch5-08"></a>

# 計算十進位位數

do while位數整除

**對應整合版：**第 41–43 頁　·　1 份程式　·　9 組測試
**來源對照：**Ch6 pp.21–22：numdigits.c
題目、規則與程式沿用既有資源包；本 HTML 另補變數表、追蹤、正確性說明與測試用途標籤。

[01 完整題目](#C08/problem)[02 解題說明](#C08/solution)[03 完整程式](#C08/code)[04 測試資料](#C08/tests)[05 易錯提醒](#C08/tips)

01

## 完整題目

先確認規格，再寫程式

輸入一個非負整數，以反覆整除 10 的方式計算其十進位位數；不得把數字轉成字串處理。

### 輸入規格

一個整數 n，0～1,000,000,000。

### 輸出規格

輸出 Digits: 位數；錯誤輸出 ERR\_INPUT / ERR\_RANGE。

### 規則與限制

- 0 的位數定義為 1。
- 輸入解讀為數值：例如 00060 與 60 都是 2 位數。
- 每次 n/=10 去除最低一位，至少執行一次。

### 輸入／輸出範例

STDIN · 範例輸入

```
60
```

3 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
Digits: 2
```

10 bytes · 包含程式實際輸出的換行與空白

輸入區不包含提示文字。下載後可直接作為標準輸入檔；檔案結束代表 EOF，不需輸入「EOF」三個字母。

目前為自學模式：完整題目與測試輸入仍可閱讀。按上方「顯示解答」即可查看解法、程式與預期輸出。這是閱讀遮蔽功能，不是考試保密機制。

02

## 解題說明

理解狀態如何改變

**STEP 01**digits = 0

**STEP 02**n /= 10

**STEP 03**digits++

**STEP 04**n > 0 就再做一次

### 核心思考與步驟

1. do 的本體先執行，因此 n=0 仍可讓 digits 加 1。
2. 以 60 追蹤：60→6→0，共兩次整除。
3. 程式會改變 n；若還要印出原輸入，需先另存副本。

### 重要變數與狀態

| 名稱 | 型別／形式 | 用途 |
| --- | --- | --- |
| n | long long | 尚未移除的數位部分 |
| digits | int | 已完成的整除次數 |

### 固定範例追蹤

全表

這是依指定範例整理的狀態表；切換步驟只改變標記，不是在瀏覽器中編譯或執行 C。

| 回合 | 除法前 n | 除法後 n | digits |
| --- | --- | --- | --- |
| 1 | 60 | 6 | 1 |
| 2 | 6 | 0 | 2 |
| 終止 | 0 | 不再執行 | Digits: 2 |

### 為什麼這個解法成立？

每次整除 10 去除一個十進位數位。do...while 保證至少執行一次，故 0 也會得到 1 位。輸入的前導 0 不屬於數值本身。

d 為十進位位數：時間 O(d)；額外空間 O(1)。

03

## 完整程式碼

每一份都可獨立編譯

c08\_digits.c

完整程式 · 17 行 · 長行可橫向捲動

```
#include <stdio.h>
int main(void) {
    long long n;
    int digits = 0;
    if (scanf("%lld", &n) != 1) {
        puts("ERR_INPUT"); return 1;
    }
    if (n < 0 || n > 1000000000LL) {
        puts("ERR_RANGE"); return 1;
    }
    do {
        n /= 10;
        digits++;
    } while (n > 0);
    printf("Digits: %d\n", digits);
    return 0;
}
```

單題編譯（在包含本檔的資料夾執行）：`gcc -std=c11 -Wall -Wextra -Wpedantic c08_digits.c -o c08_digits`

完整測試方式與 Windows cmd.exe 操作範例請見[使用與驗證說明](#guide)。此頁為離線教材，不提供任意 C 程式的網頁執行環境。

04


## 測試資料

9 組完整資料

核對輸出、結束碼與 stderr。全部輸入／輸出已內嵌，可個別下載。

列印版僅列測試目的與結束碼；完整輸入與輸出請使用 HTML 展開或下載檔案，避免上限測試產生數千行列印內容。

C08-T01**題目示範輸入／輸出**原資源包 · 3 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
60
```

3 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Digits: 2
```

10 bytes · 包含程式實際輸出的換行與空白

C08-T02**0仍有一位，須至少執行一次**原資源包 · 2 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
0
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Digits: 1
```

10 bytes · 包含程式實際輸出的換行與空白

C08-T03**個位數上界**原資源包 · 2 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
9
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Digits: 1
```

10 bytes · 包含程式實際輸出的換行與空白

C08-T04**跨過10的位數門檻**原資源包 · 3 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
10
```

3 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Digits: 2
```

10 bytes · 包含程式實際輸出的換行與空白

C08-T05**最大值有10位**原資源包 · 11 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
1000000000
```

11 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Digits: 10
```

11 bytes · 包含程式實際輸出的換行與空白

C08-T06**驗證 ERR\_RANGE**原資源包 · 3 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
-1
```

3 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_RANGE
```

10 bytes · 包含程式實際輸出的換行與空白

C08-T07**非數字 token：scanf 讀取失敗**本 HTML 新增測試 · 2 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
x
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_INPUT
```

10 bytes · 包含程式實際輸出的換行與空白

C08-T08**前導 0 不增加數值的位數**本 HTML 新增測試 · 6 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
00060
```

6 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Digits: 2
```

10 bytes · 包含程式實際輸出的換行與空白

C08-T09**數值超出上限**本 HTML 新增測試 · 11 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
1000000001
```

11 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_RANGE
```

10 bytes · 包含程式實際輸出的換行與空白

錯誤分支的非零結束碼也屬預期結果，不代表測試失敗。測試器僅正規化 CRLF 為 LF，其餘空白需保持一致。

05

## 易錯提醒與檢查重點

- 不要把 while(n>0) 原封不動換進來，否則 0 會得到 0 位數。
- do...while 結尾必須有分號，和一般 while 本體前的多餘分號不同。

教學輸入契約：數值 token 須可由程式的讀取型別表示；這些範例不是用來解析任意長數字或所有惡意輸入。詳細限制見[共通輸入與測試規則](#guide)。

[← C07 以 0 結束的數列加總](#C07)[C09 質數判定與提早停止 →](#C09)

C09正式案例迴圈C11


<a id="toc-ch5-09"></a>

# 質數判定與提早停止

forbreak質數平方根

**對應整合版：**第 45–47 頁　·　1 份程式　·　11 組測試
**來源對照：**Ch6 pp.48–49：prime / break
題目、規則與程式沿用既有資源包；本 HTML 另補變數表、追蹤、正確性說明與測試用途標籤。

[01 完整題目](#C09/problem)[02 解題說明](#C09/solution)[03 完整程式](#C09/code)[04 測試資料](#C09/tests)[05 易錯提醒](#C09/tips)

01

## 完整題目

先確認規格，再寫程式

判斷整數 n 是否為質數。若不是質數且 n≥2，找出最小的整除因子；找到第一個因子後立即停止搜尋。

### 輸入規格

一個整數 n，0～1,000,000,000。

### 輸出規格

質數輸出 PRIME；n<2 輸出 NOT\_PRIME；其他合數輸出 DIVISOR: 最小因子。

### 規則與限制

- 質數必須大於或等於 2。
- 從 d=2 依序測試；只需測到平方根附近。
- 以 d<=n/d 取代 d\*d<=n，避免乘積中途超出型別範圍。

### 輸入／輸出範例

STDIN · 範例輸入

```
91
```

3 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
DIVISOR: 7
```

11 bytes · 包含程式實際輸出的換行與空白

輸入區不包含提示文字。下載後可直接作為標準輸入檔；檔案結束代表 EOF，不需輸入「EOF」三個字母。

目前為自學模式：完整題目與測試輸入仍可閱讀。按上方「顯示解答」即可查看解法、程式與預期輸出。這是閱讀遮蔽功能，不是考試保密機制。

02

## 解題說明

理解狀態如何改變

**STEP 01**排除 n < 2

**STEP 02**d 從 2 出發

**STEP 03**測試 n % d

**STEP 04**找到就 break，否則續查

### 核心思考與步驟

1. 若 n=a×b 且兩個因子都大於 sqrt(n)，乘積會大於 n，矛盾。
2. 由小到大測試，所以第一個找到的因子必然最小。
3. divisor=0 表示尚未找到；break 只離開 for，不是整個 main。

### 重要變數與狀態

| 名稱 | 型別／形式 | 用途 |
| --- | --- | --- |
| n | long long | 待判定數 |
| d | long long | 目前測試的除數 |
| divisor | long long | 0 代表尚未找到因子 |

### 固定範例追蹤

全表

這是依指定範例整理的狀態表；切換步驟只改變標記，不是在瀏覽器中編譯或執行 C。

| d | d ≤ 91/d？ | 91 % d | 行為 |
| --- | --- | --- | --- |
| 2 | 是 | 1 | 續查 |
| 3 | 是 | 1 | 續查 |
| 4 | 是 | 3 | 續查 |
| 5 | 是 | 1 | 續查 |
| 6 | 是 | 1 | 續查 |
| 7 | 是 | 0 | divisor=7；break |

### 為什麼這個解法成立？

若合數 n 的兩個因子都大於 √n，其乘積會大於 n，矛盾。由 2 遞增測試至 √n 的整數因子，第一個找到的必為最小因子；沒有找到則為質數。

最壞時間 O(√n)；額外空間 O(1)。

03

## 完整程式碼

每一份都可獨立編譯

c09\_prime.c

完整程式 · 20 行 · 長行可橫向捲動

```
#include <stdio.h>
int main(void) {
    long long n, divisor = 0;
    if (scanf("%lld", &n) != 1) {
        puts("ERR_INPUT"); return 1;
    }
    if (n < 0 || n > 1000000000LL) {
        puts("ERR_RANGE"); return 1;
    }
    if (n < 2) { puts("NOT_PRIME"); return 0; }
    for (long long d = 2; d <= n / d; d++) {
        if (n % d == 0) {
            divisor = d;
            break;
        }
    }
    if (divisor == 0) puts("PRIME");
    else printf("DIVISOR: %lld\n", divisor);
    return 0;
}
```

單題編譯（在包含本檔的資料夾執行）：`gcc -std=c11 -Wall -Wextra -Wpedantic c09_prime.c -o c09_prime`

完整測試方式與 Windows cmd.exe 操作範例請見[使用與驗證說明](#guide)。此頁為離線教材，不提供任意 C 程式的網頁執行環境。

04


## 測試資料

11 組完整資料

核對輸出、結束碼與 stderr。全部輸入／輸出已內嵌，可個別下載。

列印版僅列測試目的與結束碼；完整輸入與輸出請使用 HTML 展開或下載檔案，避免上限測試產生數千行列印內容。

C09-T01**題目示範輸入／輸出**原資源包 · 3 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
91
```

3 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
DIVISOR: 7
```

11 bytes · 包含程式實際輸出的換行與空白

C09-T02**0不是質數**原資源包 · 2 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
0
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
NOT_PRIME
```

10 bytes · 包含程式實際輸出的換行與空白

C09-T03**1不是質數**原資源包 · 2 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
1
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
NOT_PRIME
```

10 bytes · 包含程式實際輸出的換行與空白

C09-T04**最小質數2**原資源包 · 2 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
2
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
PRIME
```

6 bytes · 包含程式實際輸出的換行與空白

C09-T05**平方數49，因子7在搜尋上界**原資源包 · 3 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
49
```

3 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
DIVISOR: 7
```

11 bytes · 包含程式實際輸出的換行與空白

C09-T06**非平方質數97**原資源包 · 3 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
97
```

3 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
PRIME
```

6 bytes · 包含程式實際輸出的換行與空白

C09-T07**找到最小因子2後提早停止**原資源包 · 4 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
100
```

4 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
DIVISOR: 2
```

11 bytes · 包含程式實際輸出的換行與空白

C09-T08**非數字 token：scanf 讀取失敗**本 HTML 新增測試 · 2 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
x
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_INPUT
```

10 bytes · 包含程式實際輸出的換行與空白

C09-T09**最大合法 n，第一輪即找到因子**本 HTML 新增測試 · 11 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
1000000000
```

11 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
DIVISOR: 2
```

11 bytes · 包含程式實際輸出的換行與空白

C09-T10**大質數：需走完平方根範圍**本 HTML 新增測試 · 10 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
999999937
```

10 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
PRIME
```

6 bytes · 包含程式實際輸出的換行與空白

C09-T11**負值不符合題目範圍**本 HTML 新增測試 · 3 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
-1
```

3 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_RANGE
```

10 bytes · 包含程式實際輸出的換行與空白

錯誤分支的非零結束碼也屬預期結果，不代表測試失敗。測試器僅正規化 CRLF 為 LF，其餘空白需保持一致。

05

## 易錯提醒與檢查重點

- n=2 是測試重點：迴圈可以 0 次，答案仍為 PRIME。
- 原教材逐一試到 n−1；本版增加平方根上界並處理 n<2。

教學輸入契約：數值 token 須可由程式的讀取型別表示；這些範例不是用來解析任意長數字或所有惡意輸入。詳細限制見[共通輸入與測試規則](#guide)。

[← C08 計算十進位位數](#C08)[C10 座位編號產生器 →](#C10)

C10正式案例迴圈C11


<a id="toc-ch5-10"></a>

# 座位編號產生器

巢狀for座位格式

**對應整合版：**第 48–50 頁　·　1 份程式　·　8 組測試
**來源對照：**延伸 Ch6 的 for 與巢狀控制結構
題目、規則與程式沿用既有資源包；本 HTML 另補變數表、追蹤、正確性說明與測試用途標籤。

[01 完整題目](#C10/problem)[02 解題說明](#C10/solution)[03 完整程式](#C10/code)[04 測試資料](#C10/tests)[05 易錯提醒](#C10/tips)

01

## 完整題目

先確認規格，再寫程式

為活動會場建立矩形座位表。輸入列數 rows 與每列座位數 cols，以「列-座號」格式逐列輸出。

### 輸入規格

兩個整數 rows、cols，均為 1～10。

### 輸出規格

每個座位格式 r-c；同列相鄰座位間一個空白，每列結尾換行，行尾沒有多餘空白。

### 規則與限制

- 列、座號都從 1 開始。
- 外層控制列，內層控制該列各座位。
- 無效輸入輸出 ERR\_INPUT 或 ERR\_RANGE。

### 輸入／輸出範例

STDIN · 範例輸入

```
2 3
```

4 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
1-1 1-2 1-3
2-1 2-2 2-3
```

24 bytes · 包含程式實際輸出的換行與空白

輸入區不包含提示文字。下載後可直接作為標準輸入檔；檔案結束代表 EOF，不需輸入「EOF」三個字母。

目前為自學模式：完整題目與測試輸入仍可閱讀。按上方「顯示解答」即可查看解法、程式與預期輸出。這是閱讀遮蔽功能，不是考試保密機制。

02

## 解題說明

理解狀態如何改變

**STEP 01**r 從 1 到 rows

**STEP 02**c 從 1 到 cols

**STEP 03**輸出 r-c 與間隔

**STEP 04**整列完成才換行

### 核心思考與步驟

1. 固定 r，讓 c 由 1 跑到 cols；完成整列才換行。
2. 每次進入新的一列，都由內層 for 重新初始化 c=1。
3. 2×3 的座位列印動作共 6 次，換行 2 次。

### 重要變數與狀態

| 名稱 | 型別／形式 | 用途 |
| --- | --- | --- |
| rows / cols | int | 總列數／每列座位數 |
| r / c | int | 目前列／座位 |

### 固定範例追蹤

全表

這是依指定範例整理的狀態表；切換步驟只改變標記，不是在瀏覽器中編譯或執行 C。

| r | c | 輸出片段 | 行尾處理 |
| --- | --- | --- | --- |
| 1 | 1 | 1-1 | 加空白 |
| 1 | 2 | 1-2 | 加空白 |
| 1 | 3 | 1-3 | 換行 |
| 2 | 1 | 2-1 | 加空白 |
| 2 | 2 | 2-2 | 加空白 |
| 2 | 3 | 2-3 | 換行 |

### 為什麼這個解法成立？

外層對每一列執行一次，內層每次重新由 1 開始，產生所有 rows×cols 個座位。只有 c<cols 才印空白，因此沒有尾隨空白。

時間 O(rows×cols)；額外空間 O(1)，不含輸出。

03

## 完整程式碼

每一份都可獨立編譯

c10\_seats.c

完整程式 · 19 行 · 長行可橫向捲動

```
#include <stdio.h>
int main(void) {
    int rows, cols;
    if (scanf("%d %d", &rows, &cols) != 2) {
        puts("ERR_INPUT"); return 1;
    }
    if (rows < 1 || rows > 10 ||
        cols < 1 || cols > 10) {
        puts("ERR_RANGE"); return 1;
    }
    for (int r = 1; r <= rows; r++) {
        for (int c = 1; c <= cols; c++) {
            printf("%d-%d", r, c);
            if (c < cols) putchar(' ');
        }
        putchar('\n');
    }
    return 0;
}
```

單題編譯（在包含本檔的資料夾執行）：`gcc -std=c11 -Wall -Wextra -Wpedantic c10_seats.c -o c10_seats`

完整測試方式與 Windows cmd.exe 操作範例請見[使用與驗證說明](#guide)。此頁為離線教材，不提供任意 C 程式的網頁執行環境。

04


## 測試資料

8 組完整資料

核對輸出、結束碼與 stderr。全部輸入／輸出已內嵌，可個別下載。

列印版僅列測試目的與結束碼；完整輸入與輸出請使用 HTML 展開或下載檔案，避免上限測試產生數千行列印內容。

C10-T01**題目示範輸入／輸出**原資源包 · 4 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
2 3
```

4 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
1-1 1-2 1-3
2-1 2-2 2-3
```

24 bytes · 包含程式實際輸出的換行與空白

C10-T02**只有一席，不印多餘空白**原資源包 · 4 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
1 1
```

4 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
1-1
```

4 bytes · 包含程式實際輸出的換行與空白

C10-T03**多列單欄，每列均重新開始**原資源包 · 4 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
3 1
```

4 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
1-1
2-1
3-1
```

12 bytes · 包含程式實際輸出的換行與空白

C10-T04**驗證 ERR\_RANGE**原資源包 · 4 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
0 3
```

4 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_RANGE
```

10 bytes · 包含程式實際輸出的換行與空白

C10-T05**驗證 ERR\_RANGE**原資源包 · 5 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
11 3
```

5 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_RANGE
```

10 bytes · 包含程式實際輸出的換行與空白

C10-T06**非數字 token：scanf 讀取失敗**本 HTML 新增測試 · 2 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
x
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_INPUT
```

10 bytes · 包含程式實際輸出的換行與空白

C10-T07**座位數不得為 0**本 HTML 新增測試 · 4 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
2 0
```

4 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_RANGE
```

10 bytes · 包含程式實際輸出的換行與空白

C10-T08**最大 10×10 座位表及空白格式**本 HTML 新增測試 · 6 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
10 10
```

6 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
1-1 1-2 1-3 1-4 1-5 1-6 1-7 1-8 1-9 1-10
2-1 2-2 2-3 2-4 2-5 2-6 2-7 2-8 2-9 2-10
3-1 3-2 3-3 3-4 3-5 3-6 3-7 3-8 3-9 3-10
4-1 4-2 4-3 4-4 4-5 4-6 4-7 4-8 4-9 4-10
5-1 5-2 5-3 5-4 5-5 5-6 5-7 5-8 5-9 5-10
6-1 6-2 6-3 6-4 6-5 6-6 6-7 6-8 6-9 6-10
7-1 7-2 7-3 7-4 7-5 7-6 7-7 7-8 7-9 7-10
8-1 8-2 8-3 8-4 8-5 8-6 8-7 8-8 8-9 8-10
9-1 9-2 9-3 9-4 9-5 9-6 9-7 9-8 9-9 9-10
10-1 10-2 10-3 10-4 10-5 10-6 10-7 10-8 10-9 10-10
```

420 bytes · 包含程式實際輸出的換行與空白

錯誤分支的非零結束碼也屬預期結果，不代表測試失敗。測試器僅正規化 CRLF 為 LF，其餘空白需保持一致。

05

## 易錯提醒與檢查重點

- 把換行放進內層，會讓每個座位各佔一行。
- 把 c 的初始化放到外層之外，第二列可能完全不執行。

教學輸入契約：數值 token 須可由程式的讀取型別表示；這些範例不是用來解析任意長數字或所有惡意輸入。詳細限制見[共通輸入與測試規則](#guide)。

[← C09 質數判定與提早停止](#C09)[C11 距離感測資料清理 →](#C11)

C11正式案例迴圈C11


<a id="toc-ch5-11"></a>

# 距離感測資料清理

continuebreak資料清理平均

**對應整合版：**第 51–53 頁　·　1 份程式　·　11 組測試
**來源對照：**Ch6 pp.50–54：break / continue；Ch7 pp.92–95：cast
題目、規則與程式沿用既有資源包；本 HTML 另補變數表、追蹤、正確性說明與測試用途標籤。

[01 完整題目](#C11/problem)[02 解題說明](#C11/solution)[03 完整程式](#C11/code)[04 測試資料](#C11/tests)[05 易錯提醒](#C11/tips)

01

## 完整題目

先確認規格，再寫程式

連續讀入距離感測值，忽略超出有效量測範圍的資料。收到停止記號後，輸出有效資料筆數及平均距離。此為教學模擬，不是設備規格。

### 輸入規格

整數串流，以 -999 或 EOF 結束；最多處理 1000 筆非停止記號資料。

### 輸出規格

有有效值輸出 Count: 筆數與 Mean: 平均（2 位小數）；沒有有效值輸出 NO\_DATA。

### 規則與限制

- 0～10000（毫米）為有效值；其他值略過但仍算已處理一筆。
- -999 是停止記號，需在範圍篩選前檢查。
- 超過 1000 筆輸出 ERR\_LIMIT；非整數資料輸出 ERR\_INPUT。

### 輸入／輸出範例

STDIN · 範例輸入

```
100 120 -5 140 -999
```

20 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
Count: 3
Mean: 120.00
```

22 bytes · 包含程式實際輸出的換行與空白

輸入區不包含提示文字。下載後可直接作為標準輸入檔；檔案結束代表 EOF，不需輸入「EOF」三個字母。

目前為自學模式：完整題目與測試輸入仍可閱讀。按上方「顯示解答」即可查看解法、程式與預期輸出。這是閱讀遮蔽功能，不是考試保密機制。

02

## 解題說明

理解狀態如何改變

**STEP 01**先查 -999／EOF

**STEP 02**計入 seen 並查上限

**STEP 03**無效值 continue

**STEP 04**有效值更新 sum/count

### 核心思考與步驟

1. 停止、總筆數限制、有效性篩選必須依序處理。
2. continue 略過 sum/count 更新，但下一輪仍會讀取新資料。
3. count=0 時不能算平均；平均須先將 sum 轉成 double。

### 重要變數與狀態

| 名稱 | 型別／形式 | 用途 |
| --- | --- | --- |
| x / sum | long long | 本筆讀值／有效總和 |
| seen | int | 非停止記號總筆數 |
| count | int | 有效讀值筆數 |
| status | int | 讀取狀態 |

### 固定範例追蹤

全表

這是依指定範例整理的狀態表；切換步驟只改變標記，不是在瀏覽器中編譯或執行 C。

| 讀值 | seen | count | sum | 行為 |
| --- | --- | --- | --- | --- |
| 100 | 1 | 1 | 100 | 接受 |
| 120 | 2 | 2 | 220 | 接受 |
| -5 | 3 | 2 | 220 | continue |
| 140 | 4 | 3 | 360 | 接受 |
| -999 | 4 | 3 | 360 | break；Mean=120.00 |

### 為什麼這個解法成立？

seen 包含無效讀值，count 與 sum 只反映合法距離資料。停止記號先判斷，否則它會被當成普通無效值而無法停止。count=0 時不做除法。

k 為處理筆數：時間 O(k)；額外空間 O(1)。

03

## 完整程式碼

每一份都可獨立編譯

c11\_sensor.c

完整程式 · 22 行 · 長行可橫向捲動

```
#include <stdio.h>
int main(void) {
    long long x, sum = 0;
    int count = 0, seen = 0, status;
    while ((status = scanf("%lld", &x)) == 1) {
        if (x == -999) break;
        if (seen == 1000) {
            puts("ERR_LIMIT"); return 1;
        }
        seen++;
        if (x < 0 || x > 10000) continue;
        sum += x;
        count++;
    }
    if (status == 0 || ferror(stdin)) {
        puts("ERR_INPUT"); return 1;
    }
    if (count == 0) { puts("NO_DATA"); return 0; }
    printf("Count: %d\n", count);
    printf("Mean: %.2f\n", (double)sum / count);
    return 0;
}
```

單題編譯（在包含本檔的資料夾執行）：`gcc -std=c11 -Wall -Wextra -Wpedantic c11_sensor.c -o c11_sensor`

完整測試方式與 Windows cmd.exe 操作範例請見[使用與驗證說明](#guide)。此頁為離線教材，不提供任意 C 程式的網頁執行環境。

04


## 測試資料

11 組完整資料

核對輸出、結束碼與 stderr。全部輸入／輸出已內嵌，可個別下載。

列印版僅列測試目的與結束碼；完整輸入與輸出請使用 HTML 展開或下載檔案，避免上限測試產生數千行列印內容。

C11-T01**題目示範輸入／輸出**原資源包 · 20 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
100 120 -5 140 -999
```

20 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Count: 3
Mean: 120.00
```

22 bytes · 包含程式實際輸出的換行與空白

C11-T02**停止記號前沒有有效資料**原資源包 · 5 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
-999
```

5 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
NO_DATA
```

8 bytes · 包含程式實際輸出的換行與空白

C11-T03**所有讀值都無效**原資源包 · 14 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
-5 10001 -999
```

14 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
NO_DATA
```

8 bytes · 包含程式實際輸出的換行與空白

C11-T04**有效範圍的下界0及上界10000**原資源包 · 13 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
0 10000 -999
```

13 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Count: 2
Mean: 5000.00
```

23 bytes · 包含程式實際輸出的換行與空白

C11-T05**平均值應保留小數**原資源包 · 9 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
1 2 -999
```

9 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Count: 2
Mean: 1.50
```

20 bytes · 包含程式實際輸出的換行與空白

C11-T06**驗證 ERR\_INPUT**原資源包 · 4 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
1 x
```

4 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_INPUT
```

10 bytes · 包含程式實際輸出的換行與空白

C11-T07**1001 筆無效值仍須計入 seen 上限**原資源包上限測試 · 3,008 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -999
```

3,008 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_LIMIT
```

10 bytes · 包含程式實際輸出的換行與空白

C11-T08**非數字 token：scanf 讀取失敗**本 HTML 新增測試 · 2 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
x
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_INPUT
```

10 bytes · 包含程式實際輸出的換行與空白

C11-T09**空檔立即 EOF**本 HTML 新增測試 · 0 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 0 bytes，不是空白行

STDOUT · 完整預期輸出

```
NO_DATA
```

8 bytes · 包含程式實際輸出的換行與空白

C11-T10**無 sentinel，直接以 EOF 結束**本 HTML 新增測試 · 7 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
100 200
```

7 bytes · 最後沒有換行，檔案直接結束

STDOUT · 完整預期輸出

```
Count: 2
Mean: 150.00
```

22 bytes · 包含程式實際輸出的換行與空白

C11-T11**1000 筆有效值：合法筆數上限**本 HTML 新增測試 · 2,005 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 -999
```

2,005 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Count: 1000
Mean: 0.00
```

23 bytes · 包含程式實際輸出的換行與空白

錯誤分支的非零結束碼也屬預期結果，不代表測試失敗。測試器僅正規化 CRLF 為 LF，其餘空白需保持一致。

05

## 易錯提醒與檢查重點

- seen 與 count 不同：前者包含無效讀值，後者只含有效讀值。
- 在 while 中把讀取放在 continue 之後，容易重複處理同一筆而無法前進。

教學輸入契約：數值 token 須可由程式的讀取型別表示；這些範例不是用來解析任意長數字或所有惡意輸入。詳細限制見[共通輸入與測試規則](#guide)。

[← C10 座位編號產生器](#C10)[C12 量測目前環境的型別 →](#C12)

C12正式案例基本型別C11


<a id="toc-ch5-12"></a>

# 量測目前環境的型別

sizeoflimits.hfloat.h環境觀察

**對應整合版：**第 63–65 頁　·　1 份程式　·　1 組測試
**來源對照：**Ch7 pp.6–15、39、103–106：limits / float.h / sizeof
題目、規則與程式沿用既有資源包；本 HTML 另補變數表、追蹤、正確性說明與測試用途標籤。

[01 完整題目](#C12/problem)[02 解題說明](#C12/solution)[03 完整程式](#C12/code)[04 測試資料](#C12/tests)[05 易錯提醒](#C12/tips)

01

## 完整題目

先確認規格，再寫程式

不要背誦「64 位元電腦的 long 一定是 8 bytes」。撰寫不需輸入的實驗程式，查詢並輸出實際編譯環境的型別大小、整數範圍及浮點特性。

### 輸入規格

不需輸入；在目前的 C11 編譯環境直接執行。

### 輸出規格

依程式標籤列印 CHAR\_BIT、四種型別大小、int/long 範圍、FLT\_DIG、DBL\_DIG、FLT\_MIN 與 FLT\_TRUE\_MIN。

### 規則與限制

- 大小單位是 C byte；一個 byte 有 CHAR\_BIT bits。
- 使用標頭提供的巨集，不能硬寫平台數值。
- 輸出可因平台而異；右側只提供本次測試環境的觀察，不是標準保證。

### 輸入／輸出範例

以下輸出為本次 Linux／GCC 的**完整觀察值**，不是所有電腦都必須相同的固定答案。本題由 <limits.h>、<float.h> 與 sizeof 取得環境值。驗證欄位齊全、數值可解析、大小／範圍基本關係合理；不要求其他平台和這裡的 Linux 輸出相同。

STDIN · 範例輸入

```
（無輸入）
```

15 bytes · 最後沒有換行，檔案直接結束

STDOUT · 本次觀察

```
CHAR_BIT=8
sizeof(int)=4
sizeof(long)=8
sizeof(long long)=8
sizeof(double)=8
INT_MIN=-2147483648 INT_MAX=2147483647
LONG_MIN=-9223372036854775808 LONG_MAX=9223372036854775807
FLT_DIG=6 DBL_DIG=15
FLT_MIN=1.175494e-38
FLT_TRUE_MIN=1.401298e-45
```

243 bytes · 包含程式實際輸出的換行與空白

輸入區不包含提示文字。下載後可直接作為標準輸入檔；檔案結束代表 EOF，不需輸入「EOF」三個字母。

目前為自學模式：完整題目與測試輸入仍可閱讀。按上方「顯示解答」即可查看解法、程式與預期輸出。這是閱讀遮蔽功能，不是考試保密機制。

02

## 解題說明

理解狀態如何改變

**STEP 01**引入標準標頭

**STEP 02**查詢 sizeof

**STEP 03**查詢 limits 巨集

**STEP 04**輸出 float 特性

### 核心思考與步驟

1. sizeof 告訴你儲存空間，limits.h 告訴你可表示範圍，兩者不要混為一談。
2. 用 %zu 輸出 sizeof 的結果；用正確格式輸出其他巨集。
3. 比較兩台電腦的結果，觀察 long 及浮點參數，不以 CPU 位元數直接推測。

### 重要變數與狀態

| 名稱 | 型別／形式 | 用途 |
| --- | --- | --- |
| CHAR\_BIT | 標頭巨集 | 每個 C byte 的位元數 |
| sizeof(...) | size\_t 結果 | 型別佔用的 C bytes |
| INT\_MIN / LONG\_MAX 等 | 標頭巨集 | 目前環境實際範圍 |

### 固定範例追蹤

全表

這是依指定範例整理的狀態表；切換步驟只改變標記，不是在瀏覽器中編譯或執行 C。

| 查詢類型 | 程式使用方式 | 解讀 |
| --- | --- | --- |
| 大小 | sizeof(long) | 不要由 CPU 位元數推測 |
| 整數範圍 | LONG\_MIN / LONG\_MAX | 由實作提供 |
| 十進位精度 | FLT\_DIG / DBL\_DIG | 不是小數點後位數 |
| 最小正數 | FLT\_MIN / FLT\_TRUE\_MIN | 正常數與所有正數下界不同 |

### 為什麼這個解法成立？

程式沒有把平台值寫死，而是從編譯器與標頭取得。測試核對必要欄位與成功執行，不把本次觀察值當成所有平台必須符合的固定答案。

固定數量的查詢：時間 O(1)；額外空間 O(1)。

03

## 完整程式碼

每一份都可獨立編譯

c12\_type\_lab.c

完整程式 · 16 行 · 長行可橫向捲動

```
#include <stdio.h>
#include <limits.h>
#include <float.h>
int main(void) {
    printf("CHAR_BIT=%d\n", CHAR_BIT);
    printf("sizeof(int)=%zu\n", sizeof(int));
    printf("sizeof(long)=%zu\n", sizeof(long));
    printf("sizeof(long long)=%zu\n", sizeof(long long));
    printf("sizeof(double)=%zu\n", sizeof(double));
    printf("INT_MIN=%d INT_MAX=%d\n", INT_MIN, INT_MAX);
    printf("LONG_MIN=%ld LONG_MAX=%ld\n", LONG_MIN, LONG_MAX);
    printf("FLT_DIG=%d DBL_DIG=%d\n", FLT_DIG, DBL_DIG);
    printf("FLT_MIN=%e\n", (double)FLT_MIN);
    printf("FLT_TRUE_MIN=%e\n", (double)FLT_TRUE_MIN);
    return 0;
}
```

單題編譯（在包含本檔的資料夾執行）：`gcc -std=c11 -Wall -Wextra -Wpedantic c12_type_lab.c -o c12_type_lab`

完整測試方式與 Windows cmd.exe 操作範例請見[使用與驗證說明](#guide)。此頁為離線教材，不提供任意 C 程式的網頁執行環境。

04


## 測試資料

1 組完整資料

核對輸出、結束碼與 stderr。全部輸入／輸出已內嵌，可個別下載。

本題由 <limits.h>、<float.h> 與 sizeof 取得環境值。驗證欄位齊全、數值可解析、大小／範圍基本關係合理；不要求其他平台和這裡的 Linux 輸出相同。

列印版僅列測試目的與結束碼；完整輸入與輸出請使用 HTML 展開或下載檔案，避免上限測試產生數千行列印內容。

C12-T01**無輸入：量測編譯環境（欄位檢查）**原資源包 · 0 input bytes · 平台判準exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 0 bytes，不是空白行

STDOUT · 本次觀察（非跨平台固定答案）

```
CHAR_BIT=8
sizeof(int)=4
sizeof(long)=8
sizeof(long long)=8
sizeof(double)=8
INT_MIN=-2147483648 INT_MAX=2147483647
LONG_MIN=-9223372036854775808 LONG_MAX=9223372036854775807
FLT_DIG=6 DBL_DIG=15
FLT_MIN=1.175494e-38
FLT_TRUE_MIN=1.401298e-45
```

243 bytes · 包含程式實際輸出的換行與空白

錯誤分支的非零結束碼也屬預期結果，不代表測試失敗。測試器僅正規化 CRLF 為 LF，其餘空白需保持一致。

05

## 易錯提醒與檢查重點

- FLT\_TRUE\_MIN 是 C11 巨集；因此本份實作統一以 -std=c11 編譯。
- 實驗不量測指標與複合型別，以免超出本章核心。

教學輸入契約：數值 token 須可由程式的讀取型別表示；這些範例不是用來解析任意長數字或所有惡意輸入。詳細限制見[共通輸入與測試規則](#guide)。

[← C11 距離感測資料清理](#C11)[C13 RGB 影片的記憶體估算 →](#C13)

C13正式案例基本型別C11


<a id="toc-ch5-13"></a>

# RGB 影片的記憶體估算

castoverflowRGBMiB

**對應整合版：**第 71–73 頁　·　1 份程式　·　8 組測試
**來源對照：**Ch7 pp.25–26、92–96：overflow / cast
題目、規則與程式沿用既有資源包；本 HTML 另補變數表、追蹤、正確性說明與測試用途標籤。

[01 完整題目](#C13/problem)[02 解題說明](#C13/solution)[03 完整程式](#C13/code)[04 測試資料](#C13/tests)[05 易錯提醒](#C13/tips)

01

## 完整題目

先確認規格，再寫程式

影像系統要將多張 RGB 影格同時存入記憶體。每個像素固定佔 3 bytes，請計算所有未壓縮影格所需的 bytes 與 MiB。

### 輸入規格

整數 width、height、frames；寬高各 1～20000，影格數 1～3600。

### 輸出規格

輸出 Bytes: 整數容量，以及 MiB: 容量（2 位小數）；錯誤輸出 ERR\_INPUT / ERR\_RANGE。

### 規則與限制

- bytes = width × height × 3 × frames。
- 1 MiB = 1024×1024 bytes；不含列對齊、metadata、壓縮或額外副本。
- 使用 long long 進行乘法；最大 4.32×10^12，可由至少 64 位的 long long 容納。

### 輸入／輸出範例

STDIN · 範例輸入

```
1920 1080 600
```

14 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
Bytes: 3732480000
MiB: 3559.57
```

31 bytes · 包含程式實際輸出的換行與空白

輸入區不包含提示文字。下載後可直接作為標準輸入檔；檔案結束代表 EOF，不需輸入「EOF」三個字母。

目前為自學模式：完整題目與測試輸入仍可閱讀。按上方「顯示解答」即可查看解法、程式與預期輸出。這是閱讀遮蔽功能，不是考試保密機制。

02

## 解題說明

理解狀態如何改變

**STEP 01**驗證三個維度

**STEP 02**先轉 long long

**STEP 03**乘出總 bytes

**STEP 04**以浮點除法算 MiB

### 核心思考與步驟

1. 先推導最大結果，再選型別；不要等溢位後才補救。
2. 第一個乘法前就把 width 轉成 long long，後續整數乘法沿用較寬型別。
3. bytes / 1048576 若都是整數會先截斷；轉成 double 後再除。

### 重要變數與狀態

| 名稱 | 型別／形式 | 用途 |
| --- | --- | --- |
| width / height / frames | int | 寬、高與影格數 |
| bytes | long long | 全部像素資料 bytes |
| mib | double | 換算後的 MiB |

### 固定範例追蹤

全表

這是依指定範例整理的狀態表；切換步驟只改變標記，不是在瀏覽器中編譯或執行 C。

| 階段 | 運算 | 結果 |
| --- | --- | --- |
| 像素／張 | 1920 × 1080 | 2,073,600 |
| bytes／張 | 2,073,600 × 3 | 6,220,800 |
| 全部影格 | 6,220,800 × 600 | 3,732,480,000 |
| MiB | 3,732,480,000 ÷ 1,048,576 | 3559.57（顯示到 2 位） |

### 為什麼這個解法成立？

合法輸入的最大乘積是 20000×20000×3×3600 = 4.32×10^12。第一個運算元已轉成 long long，避免先在 int 中溢位；換算 MiB 前再轉成 double，保留小數部分。

時間 O(1)；額外空間 O(1)。

03

## 完整程式碼

每一份都可獨立編譯

c13\_rgb\_memory.c

完整程式 · 17 行 · 長行可橫向捲動

```
#include <stdio.h>
int main(void) {
    int width, height, frames;
    if (scanf("%d %d %d", &width, &height, &frames) != 3) {
        puts("ERR_INPUT"); return 1;
    }
    if (width < 1 || width > 20000 ||
        height < 1 || height > 20000 ||
        frames < 1 || frames > 3600) {
        puts("ERR_RANGE"); return 1;
    }
    long long bytes = (long long)width * height * 3 * frames;
    double mib = (double)bytes / (1024.0 * 1024.0);
    printf("Bytes: %lld\n", bytes);
    printf("MiB: %.2f\n", mib);
    return 0;
}
```

單題編譯（在包含本檔的資料夾執行）：`gcc -std=c11 -Wall -Wextra -Wpedantic c13_rgb_memory.c -o c13_rgb_memory`

完整測試方式與 Windows cmd.exe 操作範例請見[使用與驗證說明](#guide)。此頁為離線教材，不提供任意 C 程式的網頁執行環境。

04


## 測試資料

8 組完整資料

核對輸出、結束碼與 stderr。全部輸入／輸出已內嵌，可個別下載。

列印版僅列測試目的與結束碼；完整輸入與輸出請使用 HTML 展開或下載檔案，避免上限測試產生數千行列印內容。

C13-T01**題目示範輸入／輸出**原資源包 · 14 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
1920 1080 600
```

14 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Bytes: 3732480000
MiB: 3559.57
```

31 bytes · 包含程式實際輸出的換行與空白

C13-T02**最小影格共3bytes，MiB四捨五入顯示0.00**原資源包 · 6 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
1 1 1
```

6 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Bytes: 3
MiB: 0.00
```

19 bytes · 包含程式實際輸出的換行與空白

C13-T03**三個維度均在上限，驗證大乘積**原資源包 · 17 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
20000 20000 3600
```

17 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Bytes: 4320000000000
MiB: 4119873.05
```

37 bytes · 包含程式實際輸出的換行與空白

C13-T04**驗證 ERR\_RANGE**原資源包 · 11 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
0 1080 600
```

11 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_RANGE
```

10 bytes · 包含程式實際輸出的換行與空白

C13-T05**非數字 token：scanf 讀取失敗**本 HTML 新增測試 · 2 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
x
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_INPUT
```

10 bytes · 包含程式實際輸出的換行與空白

C13-T06**寬度超限**本 HTML 新增測試 · 10 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
20001 1 1
```

10 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_RANGE
```

10 bytes · 包含程式實際輸出的換行與空白

C13-T07**高度超限**本 HTML 新增測試 · 10 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
1 20001 1
```

10 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_RANGE
```

10 bytes · 包含程式實際輸出的換行與空白

C13-T08**影格數超限**本 HTML 新增測試 · 9 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
1 1 3601
```

9 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_RANGE
```

10 bytes · 包含程式實際輸出的換行與空白

錯誤分支的非零結束碼也屬預期結果，不代表測試失敗。測試器僅正規化 CRLF 為 LF，其餘空白需保持一致。

05

## 易錯提醒與檢查重點

- (long long)(width\*height\*3\*frames) 轉型太晚；指定結果變數型別也不會改變右側的中途型別。
- 這是原始像素資料量，不是影片檔案大小或 GPU 可用容量估計。

教學輸入契約：數值 token 須可由程式的讀取型別表示；這些範例不是用來解析任意長數字或所有惡意輸入。詳細限制見[共通輸入與測試規則](#guide)。

[← C12 量測目前環境的型別](#C12)[C14 一行文字的分類統計 →](#C14)

C14正式案例基本型別C11


<a id="toc-ch5-14"></a>

# 一行文字的分類統計

getcharctypeEOFASCII

**對應整合版：**第 76–79 頁　·　1 份程式　·　9 組測試
**來源對照：**Ch7 pp.60–73：ctype / getchar / length.c
題目、規則與程式沿用既有資源包；本 HTML 另補變數表、追蹤、正確性說明與測試用途標籤。

[01 完整題目](#C14/problem)[02 解題說明](#C14/solution)[03 完整程式](#C14/code)[04 測試資料](#C14/tests)[05 易錯提醒](#C14/tips)

01

## 完整題目

先確認規格，再寫程式

讀取一行 ASCII 文字，統計總字元數、英文字母數、數字數及空白字元數。必須以 getchar 逐字讀取，不使用字串陣列。

### 輸入規格

一行 ASCII 文字，最多 4096 bytes；遇換行或 EOF 結束。

### 輸出規格

輸出 Length、Letters、Digits、Spaces 四個計數；超長輸出 ERR\_LIMIT；串流讀取錯誤輸出 ERR\_INPUT。

### 規則與限制

- 總長度包含標點與空白，不包含結尾的換行。
- 空白類別使用 isspace，包含空白與 tab；分類以預設 C locale 為準。
- 題目限定 ASCII；本程式不把 UTF-8 中文的多個 bytes 合併成一個字。

### 輸入／輸出範例

STDIN · 範例輸入

```
Ab 12!
```

7 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
Length: 6
Letters: 2
Digits: 2
Spaces: 1
```

41 bytes · 包含程式實際輸出的換行與空白

輸入區不包含提示文字。下載後可直接作為標準輸入檔；檔案結束代表 EOF，不需輸入「EOF」三個字母。

目前為自學模式：完整題目與測試輸入仍可閱讀。按上方「顯示解答」即可查看解法、程式與預期輸出。這是閱讀遮蔽功能，不是考試保密機制。

02

## 解題說明

理解狀態如何改變

**STEP 01**getchar 讀一個 byte

**STEP 02**EOF／換行就停

**STEP 03**檢查長度並 len++

**STEP 04**分類並繼續讀取

### 核心思考與步驟

1. 用 int 接收 getchar，先排除 EOF 與換行，再更新計數。
2. 每個有效讀入 byte 都增加 len，標點即使不屬於三種類別仍計入總長度。
3. getchar 成功值可直接交給 ctype；若原值來自 char 變數，先轉 unsigned char。

### 重要變數與狀態

| 名稱 | 型別／形式 | 用途 |
| --- | --- | --- |
| ch | int | 目前 byte 或 EOF |
| len | size\_t | 總 byte 數 |
| letters / digits / spaces | size\_t | 各分類計數 |

### 固定範例追蹤

全表

這是依指定範例整理的狀態表；切換步驟只改變標記，不是在瀏覽器中編譯或執行 C。

| 字元 | len | letters | digits | spaces |
| --- | --- | --- | --- | --- |
| A | 1 | 1 | 0 | 0 |
| b | 2 | 2 | 0 | 0 |
| 空白 | 3 | 2 | 0 | 1 |
| 1 | 4 | 2 | 1 | 1 |
| 2 | 5 | 2 | 2 | 1 |
| ! | 6 | 2 | 2 | 1 |
| 換行 | 6 | 2 | 2 | 1 |

### 為什麼這個解法成立？

所有非換行的成功讀值都恰好增加 len 一次；分類只增加相應計數，標點仍計入總長度。先排除 EOF，再使用 ctype。題目限定 ASCII byte 統計，不是 Unicode 字數統計。

L 為該行 byte 數：時間 O(L)；額外空間 O(1)。

03

## 完整程式碼

每一份都可獨立編譯

c14\_text\_stats.c

完整程式 · 19 行 · 長行可橫向捲動

```
#include <stdio.h>
#include <ctype.h>
int main(void) {
    int ch;
    size_t len = 0, letters = 0, digits = 0, spaces = 0;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (len == 4096) { puts("ERR_LIMIT"); return 1; }
        len++;
        if (isalpha(ch)) letters++;
        else if (isdigit(ch)) digits++;
        else if (isspace(ch)) spaces++;
    }
    if (ferror(stdin)) { puts("ERR_INPUT"); return 1; }
    printf("Length: %zu\n", len);
    printf("Letters: %zu\n", letters);
    printf("Digits: %zu\n", digits);
    printf("Spaces: %zu\n", spaces);
    return 0;
}
```

單題編譯（在包含本檔的資料夾執行）：`gcc -std=c11 -Wall -Wextra -Wpedantic c14_text_stats.c -o c14_text_stats`

完整測試方式與 Windows cmd.exe 操作範例請見[使用與驗證說明](#guide)。此頁為離線教材，不提供任意 C 程式的網頁執行環境。

04


## 測試資料

9 組完整資料

核對輸出、結束碼與 stderr。全部輸入／輸出已內嵌，可個別下載。

列印版僅列測試目的與結束碼；完整輸入與輸出請使用 HTML 展開或下載檔案，避免上限測試產生數千行列印內容。

C14-T01**題目示範輸入／輸出**原資源包 · 7 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
Ab 12!
```

7 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Length: 6
Letters: 2
Digits: 2
Spaces: 1
```

41 bytes · 包含程式實際輸出的換行與空白

C14-T02**只含換行的空行**原資源包 · 1 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```

```

1 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Length: 0
Letters: 0
Digits: 0
Spaces: 0
```

41 bytes · 包含程式實際輸出的換行與空白

C14-T03**空輸入檔：立即 EOF**原資源包 · 0 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 0 bytes，不是空白行

STDOUT · 完整預期輸出

```
Length: 0
Letters: 0
Digits: 0
Spaces: 0
```

41 bytes · 包含程式實際輸出的換行與空白

C14-T04**包含 tab 的空白分類**原資源包 · 4 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
a	9
```

4 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Length: 3
Letters: 1
Digits: 1
Spaces: 1
```

41 bytes · 包含程式實際輸出的換行與空白

C14-T05**無結尾換行，以 EOF 結束**原資源包 · 3 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
Hi!
```

3 bytes · 最後沒有換行，檔案直接結束

STDOUT · 完整預期輸出

```
Length: 3
Letters: 2
Digits: 0
Spaces: 0
```

41 bytes · 包含程式實際輸出的換行與空白

C14-T06**4096 bytes：合法長度上限**原資源包上限測試 · 4,097 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
```

4,097 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Length: 4096
Letters: 4096
Digits: 0
Spaces: 0
```

47 bytes · 包含程式實際輸出的換行與空白

C14-T07**4097 bytes：超過長度上限**原資源包上限測試 · 4,098 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
```

4,098 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_LIMIT
```

10 bytes · 包含程式實際輸出的換行與空白

C14-T08**只統計第一行**本 HTML 新增測試 · 9 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
Hi!
NEXT
```

9 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Length: 3
Letters: 2
Digits: 0
Spaces: 0
```

41 bytes · 包含程式實際輸出的換行與空白

C14-T09**標點與多種空白**本 HTML 新增測試 · 6 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
  	!?
```

6 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Length: 5
Letters: 0
Digits: 0
Spaces: 3
```

41 bytes · 包含程式實際輸出的換行與空白

錯誤分支的非零結束碼也屬預期結果，不代表測試失敗。測試器僅正規化 CRLF 為 LF，其餘空白需保持一致。

05

## 易錯提醒與檢查重點

- 原始 length.c 未處理 EOF；本版補上 EOF 與型別問題。
- 空白和標點也佔長度；letters+digits+spaces 不必等於 len。

教學輸入契約：數值 token 須可由程式的讀取型別表示；這些範例不是用來解析任意長數字或所有惡意輸入。詳細限制見[共通輸入與測試規則](#guide)。

[← C13 RGB 影片的記憶體估算](#C13)[C15 互動式零用金帳本 →](#C15)

C15正式案例綜合實作C11


<a id="toc-ch5-15"></a>

# 互動式零用金帳本

switchfor狀態整數分

**對應整合版：**第 83–87 頁　·　1 份程式　·　15 組測試
**來源對照：**Ch6 pp.59–64：checking.c；Ch7：型別與溢位
題目、規則與程式沿用既有資源包；本 HTML 另補變數表、追蹤、正確性說明與測試用途標籤。

[01 完整題目](#C15/problem)[02 解題說明](#C15/solution)[03 完整程式](#C15/code)[04 測試資料](#C15/tests)[05 易錯提醒](#C15/tips)

01

## 完整題目

先確認規格，再寫程式

建立可反覆輸入指令的教學帳本，支援清零、收入、支出、查詢與離開。餘額以最小單位「分」存成整數，拒絕非法交易且不改變原餘額。

### 輸入規格

整數指令：0 清零、1 收入、2 支出、3 查詢、4 離開。1/2 後另讀入正整數金額（分）。

### 輸出規格

查詢輸出 Balance: 元.分；錯誤指令 ERR\_CMD；非法金額 ERR\_AMOUNT；收入超限 ERR\_LIMIT；餘額不足 ERR\_FUNDS。

### 規則與限制

- 初始餘額為 0；餘額上限 1,000,000,000,000 分。
- 0 清零後輸出 CLEARED；1/2 成功輸出 OK；4 輸出 BYE。
- EOF（在指令位置）正常離開；讀取錯誤或缺少金額輸出 ERR\_INPUT 並結束。
- 拒絕交易後繼續接收指令；所有金額輸入都是整數「分」，不接受小數「元」。

### 輸入／輸出範例

STDIN · 範例輸入

```
1 104256
2 13379
3
4
```

21 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
OK
OK
Balance: 908.77
BYE
```

26 bytes · 包含程式實際輸出的換行與空白

輸入區不包含提示文字。下載後可直接作為標準輸入檔；檔案結束代表 EOF，不需輸入「EOF」三個字母。

目前為自學模式：完整題目與測試輸入仍可閱讀。按上方「顯示解答」即可查看解法、程式與預期輸出。這是閱讀遮蔽功能，不是考試保密機制。

02

## 解題說明

理解狀態如何改變

**STEP 01**讀取指令

**STEP 02**驗證交易條件

**STEP 03**成功才更新餘額

**STEP 04**break 回到下次指令

### 核心思考與步驟

1. 外層 for(;;) 管理互動生命週期；switch 只管理單次指令。
2. 收入先檢查剩餘容量；支出先檢查餘額。通過檢查才更新 balance。
3. case 內的 break 只離開 switch；4 用 return 直接結束 main。
4. 整數分除以 100 取得元，餘數以 %02lld 顯示兩位數。

### 重要變數與狀態

| 名稱 | 型別／形式 | 用途 |
| --- | --- | --- |
| balance / amount | long long | 餘額／交易金額，單位分 |
| LIMIT | const long long | 餘額上限 |
| cmd / status | int | 指令／讀取狀態 |

### 固定範例追蹤

全表

這是依指定範例整理的狀態表；切換步驟只改變標記，不是在瀏覽器中編譯或執行 C。

| 指令 | 操作前餘額（分） | 操作後餘額（分） | 輸出 |
| --- | --- | --- | --- |
| 1 104256 | 0 | 104256 | OK |
| 2 13379 | 104256 | 90877 | OK |
| 3 | 90877 | 90877 | Balance: 908.77 |
| 4 | 90877 | 90877 | BYE；結束 |

### 為什麼這個解法成立？

初始 0≤balance≤LIMIT。收入先檢查 amount≤LIMIT−balance，支出先檢查 amount≤balance，因此接受交易後仍保持此範圍。拒絕路徑不更新 balance。

k 為指令數：時間 O(k)；額外空間 O(1)。

03

## 完整程式碼

每一份都可獨立編譯

c15\_ledger.c

完整程式 · 43 行 · 長行可橫向捲動

```
#include <stdio.h>
int main(void) {
    const long long LIMIT = 1000000000000LL;
    long long balance = 0, amount;
    int cmd, status;
    for (;;) {
        status = scanf("%d", &cmd);
        if (status == EOF && !ferror(stdin)) break;
        if (status != 1) { puts("ERR_INPUT"); return 1; }
        switch (cmd) {
        case 0:
            balance = 0; puts("CLEARED"); break;
        case 1: case 2:
            if (scanf("%lld", &amount) != 1) {
                puts("ERR_INPUT"); return 1;
            }
            if (amount <= 0 || amount > LIMIT) {
                puts("ERR_AMOUNT"); break;
            }
            if (cmd == 1) {
                if (amount > LIMIT - balance) {
                    puts("ERR_LIMIT"); break;
                }
                balance += amount;
            } else {
                if (amount > balance) {
                    puts("ERR_FUNDS"); break;
                }
                balance -= amount;
            }
            puts("OK"); break;
        case 3:
            printf("Balance: %lld.%02lld\n",
                   balance / 100, balance % 100);
            break;
        case 4:
            puts("BYE"); return 0;
        default:
            puts("ERR_CMD"); break;
        }
    }
    return 0;
}
```

單題編譯（在包含本檔的資料夾執行）：`gcc -std=c11 -Wall -Wextra -Wpedantic c15_ledger.c -o c15_ledger`

完整測試方式與 Windows cmd.exe 操作範例請見[使用與驗證說明](#guide)。此頁為離線教材，不提供任意 C 程式的網頁執行環境。

04


## 測試資料

15 組完整資料

核對輸出、結束碼與 stderr。全部輸入／輸出已內嵌，可個別下載。

列印版僅列測試目的與結束碼；完整輸入與輸出請使用 HTML 展開或下載檔案，避免上限測試產生數千行列印內容。

C15-T01**題目示範輸入／輸出**原資源包 · 21 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
1 104256
2 13379
3
4
```

21 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
OK
OK
Balance: 908.77
BYE
```

26 bytes · 包含程式實際輸出的換行與空白

C15-T02**初始餘額為0**原資源包 · 4 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
3
4
```

4 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Balance: 0.00
BYE
```

18 bytes · 包含程式實際輸出的換行與空白

C15-T03**驗證 ERR\_FUNDS**原資源包 · 8 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
2 1
3
4
```

8 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_FUNDS
Balance: 0.00
BYE
```

28 bytes · 包含程式實際輸出的換行與空白

C15-T04**一分要印成0.01元**原資源包 · 8 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
1 1
3
4
```

8 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
OK
Balance: 0.01
BYE
```

21 bytes · 包含程式實際輸出的換行與空白

C15-T05**驗證 ERR\_AMOUNT**原資源包 · 9 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
1 -1
3
4
```

9 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_AMOUNT
Balance: 0.00
BYE
```

29 bytes · 包含程式實際輸出的換行與空白

C15-T06**驗證 ERR\_CMD**原資源包 · 4 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
8
4
```

4 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_CMD
BYE
```

12 bytes · 包含程式實際輸出的換行與空白

C15-T07**收入達上限後再收入，拒絕且餘額不變**原資源包 · 24 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
1 1000000000000
1 1
3
4
```

24 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
OK
ERR_LIMIT
Balance: 10000000000.00
BYE
```

41 bytes · 包含程式實際輸出的換行與空白

C15-T08**清除帳本後餘額歸0**原資源包 · 12 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
1 123
0
3
4
```

12 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
OK
CLEARED
Balance: 0.00
BYE
```

29 bytes · 包含程式實際輸出的換行與空白

C15-T09**驗證 ERR\_INPUT**原資源包 · 1 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
1
```

1 bytes · 最後沒有換行，檔案直接結束

STDOUT · 完整預期輸出

```
ERR_INPUT
```

10 bytes · 包含程式實際輸出的換行與空白

C15-T10**空輸入檔：立即 EOF**原資源包 · 0 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 0 bytes，不是空白行

STDOUT · 完整預期輸出

```
（空輸出）
```

0 bytes · 包含程式實際輸出的換行與空白

C15-T11**非數字 token：scanf 讀取失敗**本 HTML 新增測試 · 2 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
x
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_INPUT
```

10 bytes · 包含程式實際輸出的換行與空白

C15-T12**支出剛好用完餘額**本 HTML 新增測試 · 16 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
1 100
2 100
3
4
```

16 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
OK
OK
Balance: 0.00
BYE
```

24 bytes · 包含程式實際輸出的換行與空白

C15-T13**零金額被拒絕，但可繼續接收指令**本 HTML 新增測試 · 6 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
1 0
4
```

6 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_AMOUNT
BYE
```

15 bytes · 包含程式實際輸出的換行與空白

C15-T14**單筆金額超限**本 HTML 新增測試 · 18 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
1 1000000000001
4
```

18 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_AMOUNT
BYE
```

15 bytes · 包含程式實際輸出的換行與空白

C15-T15**拒絕支出後餘額保持不變**本 HTML 新增測試 · 16 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
1 100
2 101
3
4
```

16 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
OK
ERR_FUNDS
Balance: 1.00
BYE
```

31 bytes · 包含程式實際輸出的換行與空白

錯誤分支的非零結束碼也屬預期結果，不代表測試失敗。測試器僅正規化 CRLF 為 LF，其餘空白需保持一致。

05

## 易錯提醒與檢查重點

- 原教材採 float 餘額；本版新增「整數分」表示及交易防護。
- 本案例僅是狀態與控制流程練習，不是可直接部署的金融系統。

教學輸入契約：數值 token 須可由程式的讀取型別表示；這些範例不是用來解析任意長數字或所有惡意輸入。詳細限制見[共通輸入與測試規則](#guide)。

[← C14 一行文字的分類統計](#C14)[C16 班級成績統計器 →](#C16)

C16正式案例綜合實作C11


<a id="toc-ch5-16"></a>

# 班級成績統計器

whilecontinue統計有效筆數

**對應整合版：**第 88–92 頁　·　1 份程式　·　11 組測試
**來源對照：**整合 Ch5 分支、Ch6 迴圈、Ch7 型別與轉換
題目、規則與程式沿用既有資源包；本 HTML 另補變數表、追蹤、正確性說明與測試用途標籤。

[01 完整題目](#C16/problem)[02 解題說明](#C16/solution)[03 完整程式](#C16/code)[04 測試資料](#C16/tests)[05 易錯提醒](#C16/tips)

01

## 完整題目

先確認規格，再寫程式

輸入預計蒐集的合法成績筆數 n，逐筆處理成績。超出 0～100 的值略過並要求下一筆，蒐集滿 n 筆後輸出平均、最高、最低與及格人數。

### 輸入規格

第一個整數 n 為 1～1000；後續為成績整數。最多處理 10000 筆成績輸入。

### 輸出規格

無效成績輸出 IGNORED；蒐集完成輸出 Count、Mean（2 位）、Min、Max、Pass；輸入中斷 ERR\_INPUT；超過嘗試上限 ERR\_LIMIT。

### 規則與限制

- 及格定義 score≥60；無效成績不計入 n、總和或極值。
- 要累積「n 筆有效值」，不是只讀 n 次。
- n 非法輸出 ERR\_RANGE；最多 10000 次嘗試防止無限制重試。

### 輸入／輸出範例

STDIN · 範例輸入

```
4
90 101 59 60 100
```

19 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
IGNORED
Count: 4
Mean: 77.25
Min: 59
Max: 100
Pass: 3
```

54 bytes · 包含程式實際輸出的換行與空白

輸入區不包含提示文字。下載後可直接作為標準輸入檔；檔案結束代表 EOF，不需輸入「EOF」三個字母。

目前為自學模式：完整題目與測試輸入仍可閱讀。按上方「顯示解答」即可查看解法、程式與預期輸出。這是閱讀遮蔽功能，不是考試保密機制。

02

## 解題說明

理解狀態如何改變

**STEP 01**讀取需求 n

**STEP 02**嘗試讀一筆分數

**STEP 03**無效值略過不增 count

**STEP 04**接受滿 n 筆後統計

### 核心思考與步驟

1. 以 count<n 作為條件，count 只在接受合法資料後增加。
2. 四項更新 sum、min、max、pass 都只能處理合法成績。
3. 已保證 n≥1，完成後 count>0，可安全計算平均。

### 重要變數與狀態

| 名稱 | 型別／形式 | 用途 |
| --- | --- | --- |
| n / count / tries | int | 需求有效筆數／已接受／嘗試次數 |
| score / min / max / pass | int | 本筆分數／極值／及格人數 |
| sum | long long | 合法分數總和 |

### 固定範例追蹤

全表

這是依指定範例整理的狀態表；切換步驟只改變標記，不是在瀏覽器中編譯或執行 C。

| 輸入 | tries | count | sum | min / max | pass |
| --- | --- | --- | --- | --- | --- |
| 90 | 1 | 1 | 90 | 90 / 90 | 1 |
| 101 | 2 | 1 | 90 | 90 / 90 | 1 |
| 59 | 3 | 2 | 149 | 59 / 90 | 1 |
| 60 | 4 | 3 | 209 | 59 / 90 | 2 |
| 100 | 5 | 4 | 309 | 59 / 100 | 3 |

### 為什麼這個解法成立？

count 只在接受合法值後增加。sum、極值與 pass 同時只處理合法資料，因此完成時恰好統計 n 筆；tries 額外限制反覆輸入無效值。完成後 count≥1，平均除法有非零分母。

t 為嘗試讀取筆數：時間 O(t)，t≤10000；額外空間 O(1)。

03

## 完整程式碼

每一份都可獨立編譯

c16\_score\_stats.c

完整程式 · 30 行 · 長行可橫向捲動

```
#include <stdio.h>
int main(void) {
    int n, score, count = 0, tries = 0, pass = 0;
    int min = 100, max = 0;
    long long sum = 0;
    if (scanf("%d", &n) != 1) {
        puts("ERR_INPUT"); return 1;
    }
    if (n < 1 || n > 1000) {
        puts("ERR_RANGE"); return 1;
    }
    while (count < n) {
        if (tries == 10000) { puts("ERR_LIMIT"); return 1; }
        if (scanf("%d", &score) != 1) {
            puts("ERR_INPUT"); return 1;
        }
        tries++;
        if (score < 0 || score > 100) {
            puts("IGNORED"); continue;
        }
        sum += score;
        count++;
        if (score < min) min = score;
        if (score > max) max = score;
        if (score >= 60) pass++;
    }
    printf("Count: %d\nMean: %.2f\n", count, (double)sum / count);
    printf("Min: %d\nMax: %d\nPass: %d\n", min, max, pass);
    return 0;
}
```

單題編譯（在包含本檔的資料夾執行）：`gcc -std=c11 -Wall -Wextra -Wpedantic c16_score_stats.c -o c16_score_stats`

完整測試方式與 Windows cmd.exe 操作範例請見[使用與驗證說明](#guide)。此頁為離線教材，不提供任意 C 程式的網頁執行環境。

04


## 測試資料

11 組完整資料

核對輸出、結束碼與 stderr。全部輸入／輸出已內嵌，可個別下載。

列印版僅列測試目的與結束碼；完整輸入與輸出請使用 HTML 展開或下載檔案，避免上限測試產生數千行列印內容。

C16-T01**題目示範輸入／輸出**原資源包 · 19 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
4
90 101 59 60 100
```

19 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
IGNORED
Count: 4
Mean: 77.25
Min: 59
Max: 100
Pass: 3
```

54 bytes · 包含程式實際輸出的換行與空白

C16-T02**單筆0分，最低最高均為0**原資源包 · 4 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
1 0
```

4 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Count: 1
Mean: 0.00
Min: 0
Max: 0
Pass: 0
```

42 bytes · 包含程式實際輸出的換行與空白

C16-T03**單筆100分，最低最高均為100**原資源包 · 6 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
1 100
```

6 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Count: 1
Mean: 100.00
Min: 100
Max: 100
Pass: 1
```

48 bytes · 包含程式實際輸出的換行與空白

C16-T04**59/60分的及格界線與非整數平均**原資源包 · 8 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
2 59 60
```

8 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Count: 2
Mean: 59.50
Min: 59
Max: 60
Pass: 1
```

45 bytes · 包含程式實際輸出的換行與空白

C16-T05**驗證 ERR\_INPUT**原資源包 · 4 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
2 80
```

4 bytes · 最後沒有換行，檔案直接結束

STDOUT · 完整預期輸出

```
ERR_INPUT
```

10 bytes · 包含程式實際輸出的換行與空白

C16-T06**驗證 ERR\_RANGE**原資源包 · 2 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
0
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_RANGE
```

10 bytes · 包含程式實際輸出的換行與空白

C16-T07**10000 次無效嘗試後仍未蒐集完成**原資源包上限測試 · 40,002 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
1
101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101 101
```

40,002 bytes · 最後沒有換行，檔案直接結束

STDOUT · 完整預期輸出

```
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
IGNORED
ERR_LIMIT
```

80,010 bytes · 包含程式實際輸出的換行與空白

C16-T08**非數字 token：scanf 讀取失敗**本 HTML 新增測試 · 2 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
x
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_INPUT
```

10 bytes · 包含程式實際輸出的換行與空白

C16-T09**需求筆數超出上限**本 HTML 新增測試 · 5 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
1001
```

5 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_RANGE
```

10 bytes · 包含程式實際輸出的換行與空白

C16-T10**無效值不汙染極值與平均**本 HTML 新增測試 · 15 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
2 -1 0 101 100
```

15 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
IGNORED
IGNORED
Count: 2
Mean: 50.00
Min: 0
Max: 100
Pass: 1
```

61 bytes · 包含程式實際輸出的換行與空白

C16-T11**需求筆數最大值，全部剛好及格**本 HTML 新增測試 · 3,005 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
1000
60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60 60
```

3,005 bytes · 最後沒有換行，檔案直接結束

STDOUT · 完整預期輸出

```
Count: 1000
Mean: 60.00
Min: 60
Max: 60
Pass: 1000
```

51 bytes · 包含程式實際輸出的換行與空白

錯誤分支的非零結束碼也屬預期結果，不代表測試失敗。測試器僅正規化 CRLF 為 LF，其餘空白需保持一致。

05

## 易錯提醒與檢查重點

- min=100、max=0 依賴本題已知成績範圍；一般資料可用第一筆合法值初始化。
- for(i=0;i<n;i++) 若遇無效成績仍 i++，會提早停止。

教學輸入契約：數值 token 須可由程式的讀取型別表示；這些範例不是用來解析任意長數字或所有惡意輸入。詳細限制見[共通輸入與測試規則](#guide)。

[← C15 互動式零用金帳本](#C15)[S01 比較、連鎖不等式與否定的解析 →](#S01)

S01語法補充完整化選擇敘述C11


<a id="toc-ch5-17"></a>

# 比較、連鎖不等式與否定的解析

比較區間指派

**對應整合版：**第 6、9、28、93 頁　·　1 份程式　·　6 組測試
**來源對照：**整合版 p.6,9,28,93（原題／語意依投影片及備忘錄）
原投影片主要是語法片段／觀念示例；本 HTML 新增明確輸入輸出、main、必要標頭與測試。刻意保留錯誤行為的地方均另行說明，不把可能無限迴圈或未定義行為當成固定輸出。

[01 完整題目](#S01/problem)[02 解題說明](#S01/solution)[03 完整程式](#S01/code)[04 測試資料](#S01/tests)[05 易錯提醒](#S01/tips)

01

## 完整題目

先確認規格，再寫程式

讀取一個整數 x，分別觀察正確區間判斷、錯誤連鎖比較的實際解析、否定括號，以及 == 與 = 的差異。最後印出 x 的副本被指派成 0 後的值。

### 輸入規格

一個整數 x，-1000～1000。

### 輸出規格

依序輸出 Compare、Nonzero、WrongRange、CorrectRange、WrongNot、CorrectNot、EqualZero、AssignValue、AfterAssign。

### 規則與限制

- WrongRange 以 first=(0<=x)，再計算 first<10，明示原式 0<=x<10 的實際順序。
- CorrectRange 是 0<=x && x<10；本題半開區間與第93頁的0～100閉區間題不同。
- 範圍或讀取錯誤印 ERR\_RANGE 或 ERR\_INPUT，結束碼為1。
- Compare 輸出 3<5；Nonzero 輸出 !!(-7)，兩者皆以0或1表示。
- WrongNot 為 (!x)==2；CorrectNot 為 !(x==2)。先令copy=x，EqualZero輸出copy==0，再執行copy=0；AssignValue與AfterAssign分別輸出指派式的值與copy最後的值。
- 共同錯誤處理：讀取數值失敗印ERR\_INPUT；數值可讀取但超出本題輸入範圍印ERR\_RANGE，皆以結束碼1停止。正常完成以0結束；每一行輸出均以換行結尾。

### 輸入／輸出範例

STDIN · 範例輸入

```
50
```

3 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
Compare: 1
Nonzero: 1
WrongRange: 1
CorrectRange: 0
WrongNot: 0
CorrectNot: 1
EqualZero: 0
AssignValue: 0
AfterAssign: 0
```

121 bytes · 包含程式實際輸出的換行與空白

輸入區不包含提示文字。下載後可直接作為標準輸入檔；檔案結束代表 EOF，不需輸入「EOF」三個字母。

目前為自學模式：完整題目與測試輸入仍可閱讀。按上方「顯示解答」即可查看解法、程式與預期輸出。這是閱讀遮蔽功能，不是考試保密機制。

02

## 解題說明

理解狀態如何改變

**STEP 01**將連鎖比較拆成兩次比較。

**STEP 02**正確區間使用 &&。

**STEP 03**先分清否定的是 x 還是整個比較。

**STEP 04**指派式的值為被指定的值。

### 核心思考與步驟

1. 將連鎖比較拆成兩次比較。
2. 正確區間使用 &&。
3. 先分清否定的是 x 還是整個比較。
4. 指派式的值為被指定的值。

### 固定範例追蹤

全表

這是依指定範例整理的狀態表；切換步驟只改變標記，不是在瀏覽器中編譯或執行 C。

| 觀察項目 | x=50 的結果 |
| --- | --- |
| 0<=50 | 1 |
| 1<10 | 1（錯誤區間也成立） |
| 0<=50 && 50<10 | 0 |
| copy=0 | 修改 copy，表達式也得到0 |

### 為什麼這個解法成立？

拆開的運算保留了原連鎖比較的語意，並直接與正確區間式比對。

本題資料規模已限制；重點為所示控制流程與型別行為。

03

## 完整程式碼

每一份都可獨立編譯

s01\_comparison.c

補齊後的完整程式 · 20 行 · 長行可橫向捲動

```
#include <stdio.h>
int main(void) {
    int x;
    if (scanf("%d", &x) != 1) { puts("ERR_INPUT"); return 1; }
    if (x < -1000 || x > 1000) { puts("ERR_RANGE"); return 1; }
    int first = (0 <= x);
    int negated = !x;
    int copy = x;
    int equal_zero = (copy == 0);
    int assigned = (copy = 0);
    printf("Compare: %d\n", 3 < 5);
    printf("Nonzero: %d\n", !!(-7));
    printf("WrongRange: %d\n", first < 10);
    printf("CorrectRange: %d\n", 0 <= x && x < 10);
    printf("WrongNot: %d\n", negated == 2);
    printf("CorrectNot: %d\n", !(x == 2));
    printf("EqualZero: %d\n", equal_zero);
    printf("AssignValue: %d\nAfterAssign: %d\n", assigned, copy);
    return 0;
}
```

單題編譯（在包含本檔的資料夾執行）：`gcc -std=c11 -Wall -Wextra -Wpedantic s01_comparison.c -o s01_comparison`

完整測試方式與 Windows cmd.exe 操作範例請見[使用與驗證說明](#guide)。此頁為離線教材，不提供任意 C 程式的網頁執行環境。

04


## 測試資料

6 組完整資料

核對輸出、結束碼與 stderr。全部輸入／輸出已內嵌，可個別下載。

列印版僅列測試目的與結束碼；完整輸入與輸出請使用 HTML 展開或下載檔案，避免上限測試產生數千行列印內容。

S01-T01**x=50：錯誤區間仍成立**本 HTML 新增測試 · 3 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
50
```

3 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Compare: 1
Nonzero: 1
WrongRange: 1
CorrectRange: 0
WrongNot: 0
CorrectNot: 1
EqualZero: 0
AssignValue: 0
AfterAssign: 0
```

121 bytes · 包含程式實際輸出的換行與空白

S01-T02**包含的下界**本 HTML 新增測試 · 2 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
0
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Compare: 1
Nonzero: 1
WrongRange: 1
CorrectRange: 1
WrongNot: 0
CorrectNot: 1
EqualZero: 1
AssignValue: 0
AfterAssign: 0
```

121 bytes · 包含程式實際輸出的換行與空白

S01-T03**不包含的上界**本 HTML 新增測試 · 3 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
10
```

3 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Compare: 1
Nonzero: 1
WrongRange: 1
CorrectRange: 0
WrongNot: 0
CorrectNot: 1
EqualZero: 0
AssignValue: 0
AfterAssign: 0
```

121 bytes · 包含程式實際輸出的換行與空白

S01-T04**否定 x==2**本 HTML 新增測試 · 2 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
2
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Compare: 1
Nonzero: 1
WrongRange: 1
CorrectRange: 1
WrongNot: 0
CorrectNot: 0
EqualZero: 0
AssignValue: 0
AfterAssign: 0
```

121 bytes · 包含程式實際輸出的換行與空白

S01-T05**負數不在區間**本 HTML 新增測試 · 3 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
-1
```

3 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Compare: 1
Nonzero: 1
WrongRange: 1
CorrectRange: 0
WrongNot: 0
CorrectNot: 1
EqualZero: 0
AssignValue: 0
AfterAssign: 0
```

121 bytes · 包含程式實際輸出的換行與空白

S01-T06**讀取失敗**本 HTML 新增測試 · 2 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
x
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_INPUT
```

10 bytes · 包含程式實際輸出的換行與空白

錯誤分支的非零結束碼也屬預期結果，不代表測試失敗。測試器僅正規化 CRLF 為 LF，其餘空白需保持一致。

05

## 易錯提醒與檢查重點

- 程式刻意展示錯誤條件，但用暫存變數呈現解析順序，避免把錯誤寫法當成推薦用法。
- 非零條件為真，不代表每個真值本來都是1。

教學輸入契約：數值 token 須可由程式的讀取型別表示；這些範例不是用來解析任意長數字或所有惡意輸入。詳細限制見[共通輸入與測試規則](#guide)。

[← C16 班級成績統計器](#C16)[S02 短路求值與被略過的自增 →](#S02)

S02語法補充完整化選擇敘述C11


<a id="toc-ch5-18"></a>

# 短路求值與被略過的自增

短路&&||

**對應整合版：**第 7、28 頁　·　1 份程式　·　4 組測試
**來源對照：**整合版 p.7,28（原題／語意依投影片及備忘錄）
原投影片主要是語法片段／觀念示例；本 HTML 新增明確輸入輸出、main、必要標頭與測試。刻意保留錯誤行為的地方均另行說明，不把可能無限迴圈或未定義行為當成固定輸出。

[01 完整題目](#S02/problem)[02 解題說明](#S02/solution)[03 完整程式](#S02/code)[04 測試資料](#S02/tests)[05 易錯提醒](#S02/tips)

01

## 完整題目

先確認規格，再寫程式

輸入 total、den、i、j。先用短路條件保護除法，再分別觀察 i>0 && ++j>0 及 i>0 || ++j>0。AND 與 OR 示範都從同一個原始 j 開始。

### 輸入規格

四個整數 total den i j，各為 -10000～10000。

### 輸出規格

印 Guard、And、AfterAnd、Or、AfterOr。

### 規則與限制

- Guard 使用 den!=0 && total/den>2，這裡是整數除法。
- 在兩個自增示範之間將 j 還原，不能讓第一個示範影響第二個。
- 範圍有限，避免除法與自增超出型別範圍。
- And、Or是兩個邏輯式的0/1結果；AfterAnd、AfterOr是各自運算後的j，不是邏輯值。輸出順序固定為Guard、And、AfterAnd、Or、AfterOr。
- 共同錯誤處理：讀取數值失敗印ERR\_INPUT；數值可讀取但超出本題輸入範圍印ERR\_RANGE，皆以結束碼1停止。正常完成以0結束；每一行輸出均以換行結尾。

### 輸入／輸出範例

STDIN · 範例輸入

```
100 0 0 5
```

10 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
Guard: 0
And: 0
AfterAnd: 5
Or: 1
AfterOr: 6
```

45 bytes · 包含程式實際輸出的換行與空白

輸入區不包含提示文字。下載後可直接作為標準輸入檔；檔案結束代表 EOF，不需輸入「EOF」三個字母。

目前為自學模式：完整題目與測試輸入仍可閱讀。按上方「顯示解答」即可查看解法、程式與預期輸出。這是閱讀遮蔽功能，不是考試保密機制。

02

## 解題說明

理解狀態如何改變

**STEP 01**先確認分母再做除法。

**STEP 02**AND 左側假，右側不做。

**STEP 03**OR 左側真，右側不做。

**STEP 04**分別列出自增後狀態。

### 核心思考與步驟

1. 先確認分母再做除法。
2. AND 左側假，右側不做。
3. OR 左側真，右側不做。
4. 分別列出自增後狀態。

### 固定範例追蹤

全表

這是依指定範例整理的狀態表；切換步驟只改變標記，不是在瀏覽器中編譯或執行 C。

| 路徑 | i=0、j=5 |
| --- | --- |
| AND 左側 | 假；++j不執行 |
| AfterAnd | 5 |
| OR 左側 | 假；須評估++j |
| AfterOr | 6 |

### 為什麼這個解法成立？

是否執行右側取決於左側是否足以決定整個邏輯式。

本題資料規模已限制；重點為所示控制流程與型別行為。

03

## 完整程式碼

每一份都可獨立編譯

s02\_short\_circuit.c

補齊後的完整程式 · 19 行 · 長行可橫向捲動

```
#include <stdio.h>
int main(void) {
    int total, den, i, j;
    if (scanf("%d %d %d %d", &total, &den, &i, &j) != 4) {
        puts("ERR_INPUT"); return 1;
    }
    if (total < -10000 || total > 10000 || den < -10000 || den > 10000 ||
        i < -10000 || i > 10000 || j < -10000 || j > 10000) {
        puts("ERR_RANGE"); return 1;
    }
    int original = j;
    int guard = den != 0 && total / den > 2;
    int and_result = i > 0 && ++j > 0;
    printf("Guard: %d\nAnd: %d\nAfterAnd: %d\n", guard, and_result, j);
    j = original;
    int or_result = i > 0 || ++j > 0;
    printf("Or: %d\nAfterOr: %d\n", or_result, j);
    return 0;
}
```

單題編譯（在包含本檔的資料夾執行）：`gcc -std=c11 -Wall -Wextra -Wpedantic s02_short_circuit.c -o s02_short_circuit`

完整測試方式與 Windows cmd.exe 操作範例請見[使用與驗證說明](#guide)。此頁為離線教材，不提供任意 C 程式的網頁執行環境。

04


## 測試資料

4 組完整資料

核對輸出、結束碼與 stderr。全部輸入／輸出已內嵌，可個別下載。

列印版僅列測試目的與結束碼；完整輸入與輸出請使用 HTML 展開或下載檔案，避免上限測試產生數千行列印內容。

S02-T01**零分母與 AND 短路**本 HTML 新增測試 · 10 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
100 0 0 5
```

10 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Guard: 0
And: 0
AfterAnd: 5
Or: 1
AfterOr: 6
```

45 bytes · 包含程式實際輸出的換行與空白

S02-T02**OR 短路**本 HTML 新增測試 · 11 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
100 10 1 5
```

11 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Guard: 1
And: 1
AfterAnd: 6
Or: 1
AfterOr: 5
```

45 bytes · 包含程式實際輸出的換行與空白

S02-T03**自增成0仍為假**本 HTML 新增測試 · 9 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
1 2 0 -1
```

9 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Guard: 0
And: 0
AfterAnd: -1
Or: 0
AfterOr: 0
```

46 bytes · 包含程式實際輸出的換行與空白

S02-T04**讀取失敗**本 HTML 新增測試 · 2 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
x
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_INPUT
```

10 bytes · 包含程式實際輸出的換行與空白

錯誤分支的非零結束碼也屬預期結果，不代表測試失敗。測試器僅正規化 CRLF 為 LF，其餘空白需保持一致。

05

## 易錯提醒與檢查重點

- 不要把有必要發生的更新藏在可能被短路的分支裡。

教學輸入契約：數值 token 須可由程式的讀取型別表示；這些範例不是用來解析任意長數字或所有惡意輸入。詳細限制見[共通輸入與測試規則](#guide)。

[← S01 比較、連鎖不等式與否定的解析](#S01)[S03 大括號與 else 配對 →](#S03)

S03語法補充完整化選擇敘述C11


<a id="toc-ch5-19"></a>

# 大括號與 else 配對

ifelse大括號

**對應整合版：**第 8–9 頁　·　1 份程式　·　5 組測試
**來源對照：**整合版 p.8,9（原題／語意依投影片及備忘錄）
原投影片主要是語法片段／觀念示例；本 HTML 新增明確輸入輸出、main、必要標頭與測試。刻意保留錯誤行為的地方均另行說明，不把可能無限迴圈或未定義行為當成固定輸出。

[01 完整題目](#S03/problem)[02 解題說明](#S03/solution)[03 完整程式](#S03/code)[04 測試資料](#S03/tests)[05 易錯提醒](#S03/tips)

01

## 完整題目

先確認規格，再寫程式

輸入 outer、inner，分別模擬「else 配對內層 if」與「else 配對外層 if」兩種結構，輸出各自是否執行 ACTION、FALLBACK 或沒有動作。

### 輸入規格

兩個整數 outer inner，只能是0或1。

### 輸出規格

印 InnerElse: 動作及 OuterElse: 動作。

### 規則與限制

- 用大括號將兩段的語法結構明示，行為對應第8頁左右兩種配對。
- 每段都必須輸出一個結果；NONE 表示原片段不執行任何動作。
- 內層配對：outer=0時NONE；outer=1且inner=1時ACTION；outer=1且inner=0時FALLBACK。
- 外層配對：outer=0時FALLBACK；outer=1且inner=1時ACTION；outer=1且inner=0時NONE。
- 共同錯誤處理：讀取數值失敗印ERR\_INPUT；數值可讀取但超出本題輸入範圍印ERR\_RANGE，皆以結束碼1停止。正常完成以0結束；每一行輸出均以換行結尾。

### 輸入／輸出範例

STDIN · 範例輸入

```
1 0
```

4 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
InnerElse: FALLBACK
OuterElse: NONE
```

36 bytes · 包含程式實際輸出的換行與空白

輸入區不包含提示文字。下載後可直接作為標準輸入檔；檔案結束代表 EOF，不需輸入「EOF」三個字母。

目前為自學模式：完整題目與測試輸入仍可閱讀。按上方「顯示解答」即可查看解法、程式與預期輸出。這是閱讀遮蔽功能，不是考試保密機制。

02

## 解題說明

理解狀態如何改變

**STEP 01**先判斷 outer。

**STEP 02**內層配對只在 outer 真時運作。

**STEP 03**外層配對在 outer 假時執行 fallback。

### 核心思考與步驟

1. 先判斷 outer。
2. 內層配對只在 outer 真時運作。
3. 外層配對在 outer 假時執行 fallback。

### 固定範例追蹤

全表

這是依指定範例整理的狀態表；切換步驟只改變標記，不是在瀏覽器中編譯或執行 C。

| outer / inner | 內層else | 外層else |
| --- | --- | --- |
| 1 / 0 | FALLBACK | NONE |
| 0 / 1 | NONE | FALLBACK |

### 為什麼這個解法成立？

兩段具有不同語法結構，因此不能因縮排看起來相近就認為等價。

本題資料規模已限制；重點為所示控制流程與型別行為。

03

## 完整程式碼

每一份都可獨立編譯

s03\_dangling\_else.c

補齊後的完整程式 · 20 行 · 長行可橫向捲動

```
#include <stdio.h>
int main(void) {
    int outer, inner;
    if (scanf("%d %d", &outer, &inner) != 2) { puts("ERR_INPUT"); return 1; }
    if ((outer != 0 && outer != 1) || (inner != 0 && inner != 1)) {
        puts("ERR_RANGE"); return 1;
    }
    const char *a = "NONE", *b = "NONE";
    if (outer) {
        if (inner) a = "ACTION";
        else a = "FALLBACK";
    }
    if (outer) {
        if (inner) b = "ACTION";
    } else {
        b = "FALLBACK";
    }
    printf("InnerElse: %s\nOuterElse: %s\n", a, b);
    return 0;
}
```

單題編譯（在包含本檔的資料夾執行）：`gcc -std=c11 -Wall -Wextra -Wpedantic s03_dangling_else.c -o s03_dangling_else`

完整測試方式與 Windows cmd.exe 操作範例請見[使用與驗證說明](#guide)。此頁為離線教材，不提供任意 C 程式的網頁執行環境。

04


## 測試資料

5 組完整資料

核對輸出、結束碼與 stderr。全部輸入／輸出已內嵌，可個別下載。

列印版僅列測試目的與結束碼；完整輸入與輸出請使用 HTML 展開或下載檔案，避免上限測試產生數千行列印內容。

S03-T01**外真、內假**本 HTML 新增測試 · 4 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
1 0
```

4 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
InnerElse: FALLBACK
OuterElse: NONE
```

36 bytes · 包含程式實際輸出的換行與空白

S03-T02**外假，內層不執行**本 HTML 新增測試 · 4 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
0 1
```

4 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
InnerElse: NONE
OuterElse: FALLBACK
```

36 bytes · 包含程式實際輸出的換行與空白

S03-T03**兩條件皆真**本 HTML 新增測試 · 4 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
1 1
```

4 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
InnerElse: ACTION
OuterElse: ACTION
```

36 bytes · 包含程式實際輸出的換行與空白

S03-T04**兩條件皆假**本 HTML 新增測試 · 4 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
0 0
```

4 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
InnerElse: NONE
OuterElse: FALLBACK
```

36 bytes · 包含程式實際輸出的換行與空白

S03-T05**非法旗標**本 HTML 新增測試 · 4 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
2 0
```

4 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_RANGE
```

10 bytes · 包含程式實際輸出的換行與空白

錯誤分支的非零結束碼也屬預期結果，不代表測試失敗。測試器僅正規化 CRLF 為 LF，其餘空白需保持一致。

05

## 易錯提醒與檢查重點

- const char \* 在此僅用來保存輸出標籤；屬本 HTML 為補齊輸出新增的簡單用法。
- 更改縮排不會改變 else 配對。

教學輸入契約：數值 token 須可由程式的讀取型別表示；這些範例不是用來解析任意長數字或所有惡意輸入。詳細限制見[共通輸入與測試規則](#guide)。

[← S02 短路求值與被略過的自增](#S02)[S04 bool、條件運算子與獨立 if →](#S04)

S04語法補充完整化選擇敘述C11


<a id="toc-ch5-20"></a>

# bool、條件運算子與獨立 if

bool?:else if

**對應整合版：**第 9、17、28 頁　·　1 份程式　·　4 組測試
**來源對照：**整合版 p.9,17,28（原題／語意依投影片及備忘錄）
原投影片主要是語法片段／觀念示例；本 HTML 新增明確輸入輸出、main、必要標頭與測試。刻意保留錯誤行為的地方均另行說明，不把可能無限迴圈或未定義行為當成固定輸出。

[01 完整題目](#S04/problem)[02 解題說明](#S04/solution)[03 完整程式](#S04/code)[04 測試資料](#S04/tests)[05 易錯提醒](#S04/tips)

01

## 完整題目

先確認規格，再寫程式

輸入 a、b 與 flag，將 flag 轉成 bool，找出 a、b 最大值，觀察 ?: 只自增被選中的變數，並比較兩個獨立 if 與 if/else if 命中的次數。

### 輸入規格

三個整數 a b flag，各在 -10000～10000。

### 輸出規格

印 Ready、Max、Left、Right、Independent、Chained。

### 規則與限制

- flag=0代表false；其他值轉成true。
- left與right從0開始；ready為真時只增加left。
- 獨立判斷為 a>=0 與 a>=10；串接版本只計第一個成立分支。
- Ready以0/1輸出轉成bool後的flag；Max為a、b最大值。Ready為假時只將right由0增為1；Left與Right輸出各自最後的值。
- Independent分別計數a>=0、a>=10兩個成立條件；Chained依if(a>=0)、else if(a>=10)的順序只計第一個成立者。本題刻意比較兩種結構。
- 共同錯誤處理：讀取數值失敗印ERR\_INPUT；數值可讀取但超出本題輸入範圍印ERR\_RANGE，皆以結束碼1停止。正常完成以0結束；每一行輸出均以換行結尾。

### 輸入／輸出範例

STDIN · 範例輸入

```
10 2 5
```

7 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
Ready: 1
Max: 10
Left: 1
Right: 0
Independent: 2
Chained: 1
```

60 bytes · 包含程式實際輸出的換行與空白

輸入區不包含提示文字。下載後可直接作為標準輸入檔；檔案結束代表 EOF，不需輸入「EOF」三個字母。

目前為自學模式：完整題目與測試輸入仍可閱讀。按上方「顯示解答」即可查看解法、程式與預期輸出。這是閱讀遮蔽功能，不是考試保密機制。

02

## 解題說明

理解狀態如何改變

**STEP 01**將旗標轉成 bool。

**STEP 02**用 ?: 選值及單一分支。

**STEP 03**獨立 if 可各自成立。

**STEP 04**else if 只取第一個成立分支。

### 核心思考與步驟

1. 將旗標轉成 bool。
2. 用 ?: 選值及單一分支。
3. 獨立 if 可各自成立。
4. else if 只取第一個成立分支。

### 固定範例追蹤

全表

這是依指定範例整理的狀態表；切換步驟只改變標記，不是在瀏覽器中編譯或執行 C。

| 步驟 | 輸入10 2 5 |
| --- | --- |
| ready | 1 |
| maximum | 10 |
| ?: | left=1，right=0 |
| 命中數 | Independent=2，Chained=1 |

### 為什麼這個解法成立？

bool非零正規化、條件分支單選與if串接互斥，可分別由列印出的狀態核對。

本題資料規模已限制；重點為所示控制流程與型別行為。

03

## 完整程式碼

每一份都可獨立編譯

s04\_bool\_ternary.c

補齊後的完整程式 · 21 行 · 長行可橫向捲動

```
#include <stdio.h>
#include <stdbool.h>
int main(void) {
    int a, b, flag;
    if (scanf("%d %d %d", &a, &b, &flag) != 3) { puts("ERR_INPUT"); return 1; }
    if (a < -10000 || a > 10000 || b < -10000 || b > 10000 ||
        flag < -10000 || flag > 10000) { puts("ERR_RANGE"); return 1; }
    bool ready = flag;
    int maximum = a > b ? a : b;
    int left = 0, right = 0;
    int chosen = ready ? ++left : ++right;
    (void)chosen;
    int independent = 0, chained = 0;
    if (a >= 0) independent++;
    if (a >= 10) independent++;
    if (a >= 0) chained++;
    else if (a >= 10) chained++;
    printf("Ready: %d\nMax: %d\nLeft: %d\nRight: %d\n", ready, maximum, left, right);
    printf("Independent: %d\nChained: %d\n", independent, chained);
    return 0;
}
```

單題編譯（在包含本檔的資料夾執行）：`gcc -std=c11 -Wall -Wextra -Wpedantic s04_bool_ternary.c -o s04_bool_ternary`

完整測試方式與 Windows cmd.exe 操作範例請見[使用與驗證說明](#guide)。此頁為離線教材，不提供任意 C 程式的網頁執行環境。

04


## 測試資料

4 組完整資料

核對輸出、結束碼與 stderr。全部輸入／輸出已內嵌，可個別下載。

列印版僅列測試目的與結束碼；完整輸入與輸出請使用 HTML 展開或下載檔案，避免上限測試產生數千行列印內容。

S04-T01**非零正規化與兩個if命中**本 HTML 新增測試 · 7 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
10 2 5
```

7 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Ready: 1
Max: 10
Left: 1
Right: 0
Independent: 2
Chained: 1
```

60 bytes · 包含程式實際輸出的換行與空白

S04-T02**false選右分支**本 HTML 新增測試 · 8 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
-3 -1 0
```

8 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Ready: 0
Max: -1
Left: 0
Right: 1
Independent: 0
Chained: 0
```

60 bytes · 包含程式實際輸出的換行與空白

S04-T03**相等值與負的非零旗標**本 HTML 新增測試 · 7 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
2 2 -7
```

7 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Ready: 1
Max: 2
Left: 1
Right: 0
Independent: 1
Chained: 1
```

59 bytes · 包含程式實際輸出的換行與空白

S04-T04**a=0門檻**本 HTML 新增測試 · 6 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
0 1 0
```

6 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Ready: 0
Max: 1
Left: 0
Right: 1
Independent: 1
Chained: 1
```

59 bytes · 包含程式實際輸出的換行與空白

錯誤分支的非零結束碼也屬預期結果，不代表測試失敗。測試器僅正規化 CRLF 為 LF，其餘空白需保持一致。

05

## 易錯提醒與檢查重點

- 此處自增只是觀察求值行為；一般流程仍宜保留清楚的if區塊。
- 串接範例的第二個條件刻意無法命中，用來對比獨立if。

教學輸入契約：數值 token 須可由程式的讀取型別表示；這些範例不是用來解析任意長數字或所有惡意輸入。詳細限制見[共通輸入與測試規則](#guide)。

[← S03 大括號與 else 配對](#S03)[S05 switch 分派、共用標籤與 fall-through →](#S05)

S05語法補充完整化選擇敘述C11


<a id="toc-ch5-21"></a>

# switch 分派、共用標籤與 fall-through

switchbreakfall-through

**對應整合版：**第 18–19 頁　·　1 份程式　·　5 組測試
**來源對照：**整合版 p.18,19（原題／語意依投影片及備忘錄）
原投影片主要是語法片段／觀念示例；本 HTML 新增明確輸入輸出、main、必要標頭與測試。刻意保留錯誤行為的地方均另行說明，不把可能無限迴圈或未定義行為當成固定輸出。

[01 完整題目](#S05/problem)[02 解題說明](#S05/solution)[03 完整程式](#S05/code)[04 測試資料](#S05/tests)[05 易錯提醒](#S05/tips)

01

## 完整題目

先確認規格，再寫程式

輸入 command 與 grade。第一段依command分派命令；第二段刻意不在各grade之間break，重現教材從入口一路向下執行的字串串接。

### 輸入規格

兩個整數 command grade，各在-10～10。

### 輸出規格

第一行為命令文字；第二行為從grade入口開始串接的文字。

### 規則與限制

- command=1輸出START、2輸出STOP、3或4輸出REPORT，其餘輸出ERR\_CMD。
- grade=4/3/2/1/0分別從Excellent/Good/Average/Poor/Failing開始，最後流入Illegal grade。
- 這是刻意的fall-through示範，並非一般成績分類程式。
- grade=4時第二行完整字串為ExcellentGoodAveragePoorFailingIllegal grade；其他合法grade值由對應字串起印，之間不另加空白。grade不為0～4時只印Illegal grade。
- ERR\_CMD是command未匹配的正常輸出，仍需印grade結果；只要兩個輸入均在-10～10，程式結束碼仍為0。
- 共同錯誤處理：讀取數值失敗印ERR\_INPUT；數值可讀取但超出本題輸入範圍印ERR\_RANGE，皆以結束碼1停止。正常完成以0結束；每一行輸出均以換行結尾。

### 輸入／輸出範例

STDIN · 範例輸入

```
3 3
```

4 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
REPORT
GoodAveragePoorFailingIllegal grade
```

43 bytes · 包含程式實際輸出的換行與空白

輸入區不包含提示文字。下載後可直接作為標準輸入檔；檔案結束代表 EOF，不需輸入「EOF」三個字母。

目前為自學模式：完整題目與測試輸入仍可閱讀。按上方「顯示解答」即可查看解法、程式與預期輸出。這是閱讀遮蔽功能，不是考試保密機制。

02

## 解題說明

理解狀態如何改變

**STEP 01**command先選入口。

**STEP 02**break終止單次switch。

**STEP 03**共用標籤共用實作。

**STEP 04**grade段刻意向下流動。

### 核心思考與步驟

1. command先選入口。
2. break終止單次switch。
3. 共用標籤共用實作。
4. grade段刻意向下流動。

### 固定範例追蹤

全表

這是依指定範例整理的狀態表；切換步驟只改變標記，不是在瀏覽器中編譯或執行 C。

| 路徑 | grade=3 |
| --- | --- |
| 入口 | Good |
| 接續 | Average → Poor → Failing |
| 最後 | Illegal grade |

### 為什麼這個解法成立？

沒有break時，後續case與default不會重新測試grade，而是依程式順序執行。

本題資料規模已限制；重點為所示控制流程與型別行為。

03

## 完整程式碼

每一份都可獨立編譯

s05\_switch\_paths.c

補齊後的完整程式 · 24 行 · 長行可橫向捲動

```
#include <stdio.h>
int main(void) {
    int command, grade;
    if (scanf("%d %d", &command, &grade) != 2) { puts("ERR_INPUT"); return 1; }
    if (command < -10 || command > 10 || grade < -10 || grade > 10) {
        puts("ERR_RANGE"); return 1;
    }
    switch (command) {
    case 1: puts("START"); break;
    case 2: puts("STOP"); break;
    case 3: case 4: puts("REPORT"); break;
    default: puts("ERR_CMD"); break;
    }
    switch (grade) {
    case 4: printf("Excellent"); /* fall through */
    case 3: printf("Good"); /* fall through */
    case 2: printf("Average"); /* fall through */
    case 1: printf("Poor"); /* fall through */
    case 0: printf("Failing"); /* fall through */
    default: printf("Illegal grade"); break;
    }
    putchar('\n');
    return 0;
}
```

單題編譯（在包含本檔的資料夾執行）：`gcc -std=c11 -Wall -Wextra -Wpedantic s05_switch_paths.c -o s05_switch_paths`

完整測試方式與 Windows cmd.exe 操作範例請見[使用與驗證說明](#guide)。此頁為離線教材，不提供任意 C 程式的網頁執行環境。

04


## 測試資料

5 組完整資料

核對輸出、結束碼與 stderr。全部輸入／輸出已內嵌，可個別下載。

列印版僅列測試目的與結束碼；完整輸入與輸出請使用 HTML 展開或下載檔案，避免上限測試產生數千行列印內容。

S05-T01**共用標籤與grade=3串接**本 HTML 新增測試 · 4 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
3 3
```

4 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
REPORT
GoodAveragePoorFailingIllegal grade
```

43 bytes · 包含程式實際輸出的換行與空白

S05-T02**從第一標籤開始**本 HTML 新增測試 · 4 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
4 4
```

4 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
REPORT
ExcellentGoodAveragePoorFailingIllegal grade
```

52 bytes · 包含程式實際輸出的換行與空白

S05-T03**grade=0仍流入default**本 HTML 新增測試 · 4 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
1 0
```

4 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
START
FailingIllegal grade
```

27 bytes · 包含程式實際輸出的換行與空白

S05-T04**沒有符合標籤**本 HTML 新增測試 · 5 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
2 -1
```

5 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
STOP
Illegal grade
```

19 bytes · 包含程式實際輸出的換行與空白

S05-T05**default命令但程式仍繼續**本 HTML 新增測試 · 4 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
8 2
```

4 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_CMD
AveragePoorFailingIllegal grade
```

40 bytes · 包含程式實際輸出的換行與空白

錯誤分支的非零結束碼也屬預期結果，不代表測試失敗。測試器僅正規化 CRLF 為 LF，其餘空白需保持一致。

05

## 易錯提醒與檢查重點

- ERR\_CMD在本示範只代表未知命令，程式仍完成grade示範，結束碼為0。
- 不要把標籤當成自動隔離的分支區塊。

教學輸入契約：數值 token 須可由程式的讀取型別表示；這些範例不是用來解析任意長數字或所有惡意輸入。詳細限制見[共通輸入與測試規則](#guide)。

[← S04 bool、條件運算子與獨立 if](#S04)[S06 邏輯 AND 與低8位元運算 →](#S06)

S06語法補充完整化選擇敘述C11


<a id="toc-ch5-22"></a>

# 邏輯 AND 與低8位元運算

位元unsigned&&

**對應整合版：**第 27 頁　·　1 份程式　·　5 組測試
**來源對照：**整合版 p.27（原題／語意依投影片及備忘錄）
原投影片主要是語法片段／觀念示例；本 HTML 新增明確輸入輸出、main、必要標頭與測試。刻意保留錯誤行為的地方均另行說明，不把可能無限迴圈或未定義行為當成固定輸出。

[01 完整題目](#S06/problem)[02 解題說明](#S06/solution)[03 完整程式](#S06/code)[04 測試資料](#S06/tests)[05 易錯提醒](#S06/tips)

01

## 完整題目

先確認規格，再寫程式

輸入0～255的兩個整數a、b，比較邏輯AND和位元AND，並列出OR、XOR、a的低8位反相及左右移2位結果。

### 輸入規格

兩個整數a b，各在0～255。

### 輸出規格

印 LogicalAND、AND、OR、XOR、NOT\_low8、Left2、Right2。

### 規則與限制

- 先驗證範圍，再轉為unsigned int進行位元操作。
- ~a反轉整個unsigned int；本題以&0xFFU只保留低8位。
- Left2輸出整個unsigned結果，不截成8位。
- LogicalAND為(a&&b)的0/1結果；AND、OR、XOR分別為a&b、a|b、a^b。NOT\_low8為(~a)&0xFFU，Left2為a<<2，Right2為a>>2；全部以十進位顯示。
- 共同錯誤處理：讀取數值失敗印ERR\_INPUT；數值可讀取但超出本題輸入範圍印ERR\_RANGE，皆以結束碼1停止。正常完成以0結束；每一行輸出均以換行結尾。

### 輸入／輸出範例

STDIN · 範例輸入

```
60 13
```

6 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
LogicalAND: 1
AND: 12
OR: 61
XOR: 49
NOT_low8: 195
Left2: 240
Right2: 15
```

73 bytes · 包含程式實際輸出的換行與空白

輸入區不包含提示文字。下載後可直接作為標準輸入檔；檔案結束代表 EOF，不需輸入「EOF」三個字母。

目前為自學模式：完整題目與測試輸入仍可閱讀。按上方「顯示解答」即可查看解法、程式與預期輸出。這是閱讀遮蔽功能，不是考試保密機制。

02

## 解題說明

理解狀態如何改變

**STEP 01**把a、b視為二進位數。

**STEP 02**&&先視為真假。

**STEP 03**&、|、^逐bit運算。

**STEP 04**反相後套低8位遮罩。

### 核心思考與步驟

1. 把a、b視為二進位數。
2. &&先視為真假。
3. &、|、^逐bit運算。
4. 反相後套低8位遮罩。

### 固定範例追蹤

全表

這是依指定範例整理的狀態表；切換步驟只改變標記，不是在瀏覽器中編譯或執行 C。

| 運算 | 60與13結果 |
| --- | --- |
| 60 && 13 | 1 |
| 60 & 13 | 12 |
| 60 | 13 | 61 |
| 60 ^ 13 | 49 |
| (~60U)&255U | 195 |

### 為什麼這個解法成立？

邏輯運算結果僅為0或1；位元運算結果則保存各bit位置的計算結果。

本題資料規模已限制；重點為所示控制流程與型別行為。

03

## 完整程式碼

每一份都可獨立編譯

s06\_bitwise.c

補齊後的完整程式 · 12 行 · 長行可橫向捲動

```
#include <stdio.h>
int main(void) {
    int ia, ib;
    if (scanf("%d %d", &ia, &ib) != 2) { puts("ERR_INPUT"); return 1; }
    if (ia < 0 || ia > 255 || ib < 0 || ib > 255) { puts("ERR_RANGE"); return 1; }
    unsigned int a = (unsigned int)ia, b = (unsigned int)ib;
    printf("LogicalAND: %d\n", a && b);
    printf("AND: %u\nOR: %u\nXOR: %u\n", a & b, a | b, a ^ b);
    printf("NOT_low8: %u\n", (~a) & 0xFFU);
    printf("Left2: %u\nRight2: %u\n", a << 2, a >> 2);
    return 0;
}
```

單題編譯（在包含本檔的資料夾執行）：`gcc -std=c11 -Wall -Wextra -Wpedantic s06_bitwise.c -o s06_bitwise`

完整測試方式與 Windows cmd.exe 操作範例請見[使用與驗證說明](#guide)。此頁為離線教材，不提供任意 C 程式的網頁執行環境。

04


## 測試資料

5 組完整資料

核對輸出、結束碼與 stderr。全部輸入／輸出已內嵌，可個別下載。

列印版僅列測試目的與結束碼；完整輸入與輸出請使用 HTML 展開或下載檔案，避免上限測試產生數千行列印內容。

S06-T01**教材60與13**本 HTML 新增測試 · 6 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
60 13
```

6 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
LogicalAND: 1
AND: 12
OR: 61
XOR: 49
NOT_low8: 195
Left2: 240
Right2: 15
```

73 bytes · 包含程式實際輸出的換行與空白

S06-T02**含零與全1低8位**本 HTML 新增測試 · 6 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
0 255
```

6 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
LogicalAND: 0
AND: 0
OR: 255
XOR: 255
NOT_low8: 255
Left2: 0
Right2: 0
```

71 bytes · 包含程式實際輸出的換行與空白

S06-T03**最大合法值**本 HTML 新增測試 · 8 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
255 255
```

8 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
LogicalAND: 1
AND: 255
OR: 255
XOR: 0
NOT_low8: 0
Left2: 1020
Right2: 63
```

73 bytes · 包含程式實際輸出的換行與空白

S06-T04**真假相同但共同bit為0**本 HTML 新增測試 · 4 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
1 2
```

4 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
LogicalAND: 1
AND: 0
OR: 3
XOR: 3
NOT_low8: 254
Left2: 4
Right2: 0
```

67 bytes · 包含程式實際輸出的換行與空白

S06-T05**負值拒絕**本 HTML 新增測試 · 5 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
-1 0
```

5 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_RANGE
```

10 bytes · 包含程式實際輸出的換行與空白

錯誤分支的非零結束碼也屬預期結果，不代表測試失敗。測試器僅正規化 CRLF 為 LF，其餘空白需保持一致。

05

## 易錯提醒與檢查重點

- 圖中的8格不代表unsigned int只有8位。

教學輸入契約：數值 token 須可由程式的讀取型別表示；這些範例不是用來解析任意長數字或所有惡意輸入。詳細限制見[共通輸入與測試規則](#guide)。

[← S05 switch 分派、共用標籤與 fall-through](#S05)[S07 計數端點、逗號運算子與多變數更新 →](#S07)

S07語法補充完整化迴圈C11


<a id="toc-ch5-23"></a>

# 計數端點、逗號運算子與多變數更新

forcomma作用域

**對應整合版：**第 37 頁　·　1 份程式　·　4 組測試
**來源對照：**整合版 p.37（原題／語意依投影片及備忘錄）
原投影片主要是語法片段／觀念示例；本 HTML 新增明確輸入輸出、main、必要標頭與測試。刻意保留錯誤行為的地方均另行說明，不把可能無限迴圈或未定義行為當成固定輸出。

[01 完整題目](#S07/problem)[02 解題說明](#S07/solution)[03 完整程式](#S07/code)[04 測試資料](#S07/tests)[05 易錯提醒](#S07/tips)

01

## 完整題目

先確認規格，再寫程式

輸入n，列印0～n-1與1～n兩種計數，輸出外部宣告的迴圈變數終值，再觀察教材的逗號運算子與三變數for更新。

### 輸入規格

一個整數n，0～9。

### 輸出規格

印Zero、One、After及Comma；接著逐列印a,b,c三個狀態。

### 規則與限制

- n=0時前兩個序列皆為空，三變數迴圈也不執行。
- 逗號運算使用j=10，計算(j++, (void)(j+100), 999+j)；void明示丟棄中間值。
- 三變數初值a=1,b=10,c=1，每回合a+1、b-1、c×2。
- Zero:與One:後的每個數字前面各有一個空白；空序列只印標籤及換行。After印第一個for結束時i的值，Comma印逗號式最後得到的i與j，中間一個空白。
- 最後三變數迴圈的條件為a<=n，每一輪先印出a b c（三者以空白分隔）再更新，總共n列；不輸出欄名。
- 共同錯誤處理：讀取數值失敗印ERR\_INPUT；數值可讀取但超出本題輸入範圍印ERR\_RANGE，皆以結束碼1停止。正常完成以0結束；每一行輸出均以換行結尾。

### 輸入／輸出範例

STDIN · 範例輸入

```
3
```

2 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
Zero: 0 1 2
One: 1 2 3
After: 3
Comma: 1010 11
1 10 1
2 9 2
3 8 4
```

66 bytes · 包含程式實際輸出的換行與空白

輸入區不包含提示文字。下載後可直接作為標準輸入檔；檔案結束代表 EOF，不需輸入「EOF」三個字母。

目前為自學模式：完整題目與測試輸入仍可閱讀。按上方「顯示解答」即可查看解法、程式與預期輸出。這是閱讀遮蔽功能，不是考試保密機制。

02

## 解題說明

理解狀態如何改變

**STEP 01**列出兩種端點區間。

**STEP 02**外部i可在迴圈後讀取。

**STEP 03**逗號先左後右，值取最後。

**STEP 04**每回合同步更新a,b,c。

### 核心思考與步驟

1. 列出兩種端點區間。
2. 外部i可在迴圈後讀取。
3. 逗號先左後右，值取最後。
4. 每回合同步更新a,b,c。

### 固定範例追蹤

全表

這是依指定範例整理的狀態表；切換步驟只改變標記，不是在瀏覽器中編譯或執行 C。

| 步驟 | j與i |
| --- | --- |
| j初值 | 10 |
| j++ | j=11 |
| j+100 | 111被丟棄 |
| 999+j | i=1010 |

### 為什麼這個解法成立？

0～n-1與1～n皆有n個元素；三個更新式由逗號順序執行，印出的是每回合更新前的狀態。

本題資料規模已限制；重點為所示控制流程與型別行為。

03

## 完整程式碼

每一份都可獨立編譯

s07\_count\_comma.c

補齊後的完整程式 · 18 行 · 長行可橫向捲動

```
#include <stdio.h>
int main(void) {
    int n, i;
    if (scanf("%d", &n) != 1) { puts("ERR_INPUT"); return 1; }
    if (n < 0 || n > 9) { puts("ERR_RANGE"); return 1; }
    printf("Zero:");
    for (i = 0; i < n; i++) printf(" %d", i);
    printf("\nOne:");
    for (int k = 1; k <= n; k++) printf(" %d", k);
    printf("\nAfter: %d\n", i);
    int j = 10;
    i = (j++, (void)(j + 100), 999 + j);
    printf("Comma: %d %d\n", i, j);
    for (int a = 1, b = 10, c = 1; a <= n; a++, b--, c *= 2) {
        printf("%d %d %d\n", a, b, c);
    }
    return 0;
}
```

單題編譯（在包含本檔的資料夾執行）：`gcc -std=c11 -Wall -Wextra -Wpedantic s07_count_comma.c -o s07_count_comma`

完整測試方式與 Windows cmd.exe 操作範例請見[使用與驗證說明](#guide)。此頁為離線教材，不提供任意 C 程式的網頁執行環境。

04


## 測試資料

4 組完整資料

核對輸出、結束碼與 stderr。全部輸入／輸出已內嵌，可個別下載。

列印版僅列測試目的與結束碼；完整輸入與輸出請使用 HTML 展開或下載檔案，避免上限測試產生數千行列印內容。

S07-T01**n=3兩種區間**本 HTML 新增測試 · 2 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
3
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Zero: 0 1 2
One: 1 2 3
After: 3
Comma: 1010 11
1 10 1
2 9 2
3 8 4
```

66 bytes · 包含程式實際輸出的換行與空白

S07-T02**零次迴圈**本 HTML 新增測試 · 2 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
0
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Zero:
One:
After: 0
Comma: 1010 11
```

35 bytes · 包含程式實際輸出的換行與空白

S07-T03**最大合法次數**本 HTML 新增測試 · 2 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
9
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Zero: 0 1 2 3 4 5 6 7 8
One: 1 2 3 4 5 6 7 8 9
After: 9
Comma: 1010 11
1 10 1
2 9 2
3 8 4
4 7 8
5 6 16
6 5 32
7 4 64
8 3 128
9 2 256
```

133 bytes · 包含程式實際輸出的換行與空白

S07-T04**超出上限**本 HTML 新增測試 · 3 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
10
```

3 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_RANGE
```

10 bytes · 包含程式實際輸出的換行與空白

錯誤分支的非零結束碼也屬預期結果，不代表測試失敗。測試器僅正規化 CRLF 為 LF，其餘空白需保持一致。

05

## 易錯提醒與檢查重點

- printf引數間的逗號不是逗號運算子，不保證引數由左到右求值。
- (void)是本HTML新增的明示丟棄，保持中間計算對最終結果的影響不變。

教學輸入契約：數值 token 須可由程式的讀取型別表示；這些範例不是用來解析任意長數字或所有惡意輸入。詳細限制見[共通輸入與測試規則](#guide)。

[← S06 邏輯 AND 與低8位元運算](#S06)[S08 不用乘法的奇數累加平方表 →](#S08)

S08語法補充完整化迴圈C11


<a id="toc-ch5-24"></a>

# 不用乘法的奇數累加平方表

for平方差

**對應整合版：**第 33、34、37 頁　·　1 份程式　·　5 組測試
**來源對照：**整合版 p.33,34,37（原題／語意依投影片及備忘錄）；另參照原 Chapter 6 Loops.pptx 第45–46頁的 square3.c。
原投影片主要是語法片段／觀念示例；本 HTML 新增明確輸入輸出、main、必要標頭與測試。刻意保留錯誤行為的地方均另行說明，不把可能無限迴圈或未定義行為當成固定輸出。

[01 完整題目](#S08/problem)[02 解題說明](#S08/solution)[03 完整程式](#S08/code)[04 測試資料](#S08/tests)[05 易錯提醒](#S08/tips)

01

## 完整題目

先確認規格，再寫程式

沿用C06的平方表輸入輸出，但不可用乘法計算平方。利用相鄰平方差為3、5、7…，由1開始累加下一個奇數。此題補齊原Ch6 square3.c的另一種方法。

### 輸入規格

一個整數n，1～20。

### 輸出規格

每列輸出i及i²，中間一個空白，共n列。

### 規則與限制

- 初值i=1、square=1、odd=3。
- 印完目前平方後，square+=odd，再讓odd+=2。
- 輸出必須與C06的while/for版本一致；不得在此法中使用i\*i。
- 共同錯誤處理：讀取數值失敗印ERR\_INPUT；數值可讀取但超出本題輸入範圍印ERR\_RANGE，皆以結束碼1停止。正常完成以0結束；每一行輸出均以換行結尾。

### 輸入／輸出範例

STDIN · 範例輸入

```
5
```

2 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
1 1
2 4
3 9
4 16
5 25
```

22 bytes · 包含程式實際輸出的換行與空白

輸入區不包含提示文字。下載後可直接作為標準輸入檔；檔案結束代表 EOF，不需輸入「EOF」三個字母。

目前為自學模式：完整題目與測試輸入仍可閱讀。按上方「顯示解答」即可查看解法、程式與預期輸出。這是閱讀遮蔽功能，不是考試保密機制。

02

## 解題說明

理解狀態如何改變

**STEP 01**從square=1開始。

**STEP 02**每次先印目前平方。

**STEP 03**把下一個奇數加進square。

**STEP 04**奇數每次增加2。

### 核心思考與步驟

1. 從square=1開始。
2. 每次先印目前平方。
3. 把下一個奇數加進square。
4. 奇數每次增加2。

### 固定範例追蹤

全表

這是依指定範例整理的狀態表；切換步驟只改變標記，不是在瀏覽器中編譯或執行 C。

| 目前i | square | 下一個差值 |
| --- | --- | --- |
| 1 | 1 | 3 |
| 2 | 4 | 5 |
| 3 | 9 | 7 |
| 4 | 16 | 9 |
| 5 | 25 | 11 |

### 為什麼這個解法成立？

(i+1)²−i²=2i+1，奇數差每回合增加2，因此累加後仍保持square=i²。

本題資料規模已限制；重點為所示控制流程與型別行為。

03

## 完整程式碼

每一份都可獨立編譯

s08\_square\_odd.c

補齊後的完整程式 · 13 行 · 長行可橫向捲動

```
#include <stdio.h>
int main(void) {
    int n, i = 1;
    long long square = 1, odd = 3;
    if (scanf("%d", &n) != 1) { puts("ERR_INPUT"); return 1; }
    if (n < 1 || n > 20) { puts("ERR_RANGE"); return 1; }
    for (; i <= n; odd += 2) {
        printf("%d %lld\n", i, square);
        i++;
        square += odd;
    }
    return 0;
}
```

單題編譯（在包含本檔的資料夾執行）：`gcc -std=c11 -Wall -Wextra -Wpedantic s08_square_odd.c -o s08_square_odd`

完整測試方式與 Windows cmd.exe 操作範例請見[使用與驗證說明](#guide)。此頁為離線教材，不提供任意 C 程式的網頁執行環境。

04


## 測試資料

5 組完整資料

核對輸出、結束碼與 stderr。全部輸入／輸出已內嵌，可個別下載。

列印版僅列測試目的與結束碼；完整輸入與輸出請使用 HTML 展開或下載檔案，避免上限測試產生數千行列印內容。

S08-T01**1～5平方**本 HTML 新增測試 · 2 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
5
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
1 1
2 4
3 9
4 16
5 25
```

22 bytes · 包含程式實際輸出的換行與空白

S08-T02**單列**本 HTML 新增測試 · 2 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
1
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
1 1
```

4 bytes · 包含程式實際輸出的換行與空白

S08-T03**最大合法列數**本 HTML 新增測試 · 3 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
20
```

3 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
1 1
2 4
3 9
4 16
5 25
6 36
7 49
8 64
9 81
10 100
11 121
12 144
13 169
14 196
15 225
16 256
17 289
18 324
19 361
20 400
```

119 bytes · 包含程式實際輸出的換行與空白

S08-T04**拒絕零列**本 HTML 新增測試 · 2 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
0
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_RANGE
```

10 bytes · 包含程式實際輸出的換行與空白

S08-T05**讀取失敗**本 HTML 新增測試 · 2 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
x
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_INPUT
```

10 bytes · 包含程式實際輸出的換行與空白

錯誤分支的非零結束碼也屬預期結果，不代表測試失敗。測試器僅正規化 CRLF 為 LF，其餘空白需保持一致。

05

## 易錯提醒與檢查重點

- 本HTML以long long保存累加狀態，輸出格式沿用C06而非原教材固定欄寬。
- 原Ch6 pp.45–46提供square3.c；整合版C06易錯提醒提及此方法。

教學輸入契約：數值 token 須可由程式的讀取型別表示；這些範例不是用來解析任意長數字或所有惡意輸入。詳細限制見[共通輸入與測試規則](#guide)。

[← S07 計數端點、逗號運算子與多變數更新](#S07)[S09 while、do、for 與 continue 的執行次數 →](#S09)

S09語法補充完整化迴圈C11


<a id="toc-ch5-25"></a>

# while、do、for 與 continue 的執行次數

whiledocontinue

**對應整合版：**第 29、44、55 頁　·　1 份程式　·　4 組測試
**來源對照：**整合版 p.29,44,55（原題／語意依投影片及備忘錄）
原投影片主要是語法片段／觀念示例；本 HTML 新增明確輸入輸出、main、必要標頭與測試。刻意保留錯誤行為的地方均另行說明，不把可能無限迴圈或未定義行為當成固定輸出。

[01 完整題目](#S09/problem)[02 解題說明](#S09/solution)[03 完整程式](#S09/code)[04 測試資料](#S09/tests)[05 易錯提醒](#S09/tips)

01

## 完整題目

先確認規格，再寫程式

輸入n，量測相同計數條件下while、do和for的本體次數，再用for跳過偶數，輸出0～n-1中的奇數。

### 輸入規格

一個整數n，0～20。

### 輸出規格

印While、Do、For的次數，接著印Odd序列。

### 規則與限制

- 三種迴圈各自從i=0、count=0開始。
- do先執行i++與count++，再檢查i<n，所以n=0時仍做一次。
- continue遇到偶數時直接到for更新式，不在本體額外增加i。
- While、Do、For各使用「標籤: 次數」獨立一行；Odd:後每個奇數前加一個空白，最後換行。三種計数互不共用累計結果。
- 共同錯誤處理：讀取數值失敗印ERR\_INPUT；數值可讀取但超出本題輸入範圍印ERR\_RANGE，皆以結束碼1停止。正常完成以0結束；每一行輸出均以換行結尾。

### 輸入／輸出範例

STDIN · 範例輸入

```
0
```

2 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
While: 0
Do: 1
For: 0
Odd:
```

27 bytes · 包含程式實際輸出的換行與空白

輸入區不包含提示文字。下載後可直接作為標準輸入檔；檔案結束代表 EOF，不需輸入「EOF」三個字母。

目前為自學模式：完整題目與測試輸入仍可閱讀。按上方「顯示解答」即可查看解法、程式與預期輸出。這是閱讀遮蔽功能，不是考試保密機制。

02

## 解題說明

理解狀態如何改變

**STEP 01**前測可執行0次。

**STEP 02**do後測至少做1次。

**STEP 03**for的continue先走更新。

**STEP 04**列出奇數確認進度。

### 核心思考與步驟

1. 前測可執行0次。
2. do後測至少做1次。
3. for的continue先走更新。
4. 列出奇數確認進度。

### 固定範例追蹤

全表

這是依指定範例整理的狀態表；切換步驟只改變標記，不是在瀏覽器中編譯或執行 C。

| i | continue? | 輸出 |
| --- | --- | --- |
| 0 | 是 | 無 |
| 1 | 否 | 1 |
| 2 | 是 | 無 |
| 3 | 否 | 3 |
| 4 | 是 | 無 |

### 為什麼這個解法成立？

三個次數由是否在第一輪之前檢查條件決定；for更新不因continue被跳過。

本題資料規模已限制；重點為所示控制流程與型別行為。

03

## 完整程式碼

每一份都可獨立編譯

s09\_loop\_counts.c

補齊後的完整程式 · 20 行 · 長行可橫向捲動

```
#include <stdio.h>
int main(void) {
    int n, i = 0, count = 0;
    if (scanf("%d", &n) != 1) { puts("ERR_INPUT"); return 1; }
    if (n < 0 || n > 20) { puts("ERR_RANGE"); return 1; }
    while (i < n) { count++; i++; }
    printf("While: %d\n", count);
    i = 0; count = 0;
    do { count++; i++; } while (i < n);
    printf("Do: %d\n", count);
    count = 0;
    for (i = 0; i < n; i++) count++;
    printf("For: %d\nOdd:", count);
    for (i = 0; i < n; i++) {
        if (i % 2 == 0) continue;
        printf(" %d", i);
    }
    putchar('\n');
    return 0;
}
```

單題編譯（在包含本檔的資料夾執行）：`gcc -std=c11 -Wall -Wextra -Wpedantic s09_loop_counts.c -o s09_loop_counts`

完整測試方式與 Windows cmd.exe 操作範例請見[使用與驗證說明](#guide)。此頁為離線教材，不提供任意 C 程式的網頁執行環境。

04


## 測試資料

4 組完整資料

核對輸出、結束碼與 stderr。全部輸入／輸出已內嵌，可個別下載。

列印版僅列測試目的與結束碼；完整輸入與輸出請使用 HTML 展開或下載檔案，避免上限測試產生數千行列印內容。

S09-T01**前測與後測的差異**本 HTML 新增測試 · 2 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
0
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
While: 0
Do: 1
For: 0
Odd:
```

27 bytes · 包含程式實際輸出的換行與空白

S09-T02**continue跳過偶數**本 HTML 新增測試 · 2 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
5
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
While: 5
Do: 5
For: 5
Odd: 1 3
```

31 bytes · 包含程式實際輸出的換行與空白

S09-T03**僅有i=0，奇數序列空**本 HTML 新增測試 · 2 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
1
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
While: 1
Do: 1
For: 1
Odd:
```

27 bytes · 包含程式實際輸出的換行與空白

S09-T04**最大合法n**本 HTML 新增測試 · 3 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
20
```

3 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
While: 20
Do: 20
For: 20
Odd: 1 3 5 7 9 11 13 15 17 19
```

55 bytes · 包含程式實際輸出的換行與空白

錯誤分支的非零結束碼也屬預期結果，不代表測試失敗。測試器僅正規化 CRLF 為 LF，其餘空白需保持一致。

05

## 易錯提醒與檢查重點

- 把for直接搬成while且把i++留在continue之後，可能不再前進；這裡不執行該錯誤版本。

教學輸入契約：數值 token 須可由程式的讀取型別表示；這些範例不是用來解析任意長數字或所有惡意輸入。詳細限制見[共通輸入與測試規則](#guide)。

[← S08 不用乘法的奇數累加平方表](#S08)[S10 有意的空本體與讀到行尾 →](#S10)

S10語法補充完整化迴圈C11


<a id="toc-ch5-26"></a>

# 有意的空本體與讀到行尾

空敘述EOFgetchar

**對應整合版：**第 54 頁　·　1 份程式　·　4 組測試
**來源對照：**整合版 p.54（原題／語意依投影片及備忘錄）
原投影片主要是語法片段／觀念示例；本 HTML 新增明確輸入輸出、main、必要標頭與測試。刻意保留錯誤行為的地方均另行說明，不把可能無限迴圈或未定義行為當成固定輸出。

[01 完整題目](#S10/problem)[02 解題說明](#S10/solution)[03 完整程式](#S10/code)[04 測試資料](#S10/tests)[05 易錯提醒](#S10/tips)

01

## 完整題目

先確認規格，再寫程式

先執行教材的有意空本體倒數，輸出最終i；接著略過輸入的第一行，再印下一個字元的數值，觀察空本體如何在條件內完成讀取。

### 輸入規格

任意ASCII文字；最多讀到第一個換行，接著再讀一個byte。

### 輸出規格

印AfterEmpty: 3；再印NextCode: 數值或Next: EOF。

### 規則與限制

- for(i=10;i>3;i--)本體使用空區塊。
- 略過行尾必須同時檢查EOF，避免空檔無法終止。
- 此題不執行while(i>0);而沒有更新的無限迴圈。
- 若第一行以換行結束，該換行會被消耗，NextCode觀察的是其後第一個byte；若已無資料則印Next: EOF。串流讀取錯誤印ERR\_INPUT，結束碼1；正常EOF結束碼0。

### 輸入／輸出範例

STDIN · 範例輸入

```
abc
Q
```

6 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
AfterEmpty: 3
NextCode: 81
```

27 bytes · 包含程式實際輸出的換行與空白

輸入區不包含提示文字。下載後可直接作為標準輸入檔；檔案結束代表 EOF，不需輸入「EOF」三個字母。

目前為自學模式：完整題目與測試輸入仍可閱讀。按上方「顯示解答」即可查看解法、程式與預期輸出。這是閱讀遮蔽功能，不是考試保密機制。

02

## 解題說明

理解狀態如何改變

**STEP 01**空for在更新式中前進。

**STEP 02**getchar在while條件內讀取。

**STEP 03**換行或EOF停止略過。

**STEP 04**再讀下一個byte。

### 核心思考與步驟

1. 空for在更新式中前進。
2. getchar在while條件內讀取。
3. 換行或EOF停止略過。
4. 再讀下一個byte。

### 固定範例追蹤

全表

這是依指定範例整理的狀態表；切換步驟只改變標記，不是在瀏覽器中編譯或執行 C。

| 輸入區段 | 處理 |
| --- | --- |
| a b c | 被條件中的getchar消耗 |
| 換行 | 終止略過 |
| Q | 下一次getchar取得81 |

### 為什麼這個解法成立？

空本體仍可正確工作，只要前進動作與停止條件放在條件／更新式內。

本題資料規模已限制；重點為所示控制流程與型別行為。

03

## 完整程式碼

每一份都可獨立編譯

s10\_empty\_loop.c

補齊後的完整程式 · 16 行 · 長行可橫向捲動

```
#include <stdio.h>
int main(void) {
    int i, ch;
    for (i = 10; i > 3; i--) { }
    printf("AfterEmpty: %d\n", i);
    while ((ch = getchar()) != EOF && ch != '\n') { }
    if (ferror(stdin)) { puts("ERR_INPUT"); return 1; }
    ch = getchar();
    if (ch == EOF) {
        if (ferror(stdin)) { puts("ERR_INPUT"); return 1; }
        puts("Next: EOF");
    } else {
        printf("NextCode: %d\n", ch);
    }
    return 0;
}
```

單題編譯（在包含本檔的資料夾執行）：`gcc -std=c11 -Wall -Wextra -Wpedantic s10_empty_loop.c -o s10_empty_loop`

完整測試方式與 Windows cmd.exe 操作範例請見[使用與驗證說明](#guide)。此頁為離線教材，不提供任意 C 程式的網頁執行環境。

04


## 測試資料

4 組完整資料

核對輸出、結束碼與 stderr。全部輸入／輸出已內嵌，可個別下載。

列印版僅列測試目的與結束碼；完整輸入與輸出請使用 HTML 展開或下載檔案，避免上限測試產生數千行列印內容。

S10-T01**略過第一行後讀到Q，ASCII=81**本 HTML 新增測試 · 6 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
abc
Q
```

6 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
AfterEmpty: 3
NextCode: 81
```

27 bytes · 包含程式實際輸出的換行與空白

S10-T02**空檔**本 HTML 新增測試 · 0 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 0 bytes，不是空白行

STDOUT · 完整預期輸出

```
AfterEmpty: 3
Next: EOF
```

24 bytes · 包含程式實際輸出的換行與空白

S10-T03**未換行即EOF**本 HTML 新增測試 · 3 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
abc
```

3 bytes · 最後沒有換行，檔案直接結束

STDOUT · 完整預期輸出

```
AfterEmpty: 3
Next: EOF
```

24 bytes · 包含程式實際輸出的換行與空白

S10-T04**第一行為空行**本 HTML 新增測試 · 2 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
Z
```

2 bytes · 最後沒有換行，檔案直接結束

STDOUT · 完整預期輸出

```
AfterEmpty: 3
NextCode: 90
```

27 bytes · 包含程式實際輸出的換行與空白

錯誤分支的非零結束碼也屬預期結果，不代表測試失敗。測試器僅正規化 CRLF 為 LF，其餘空白需保持一致。

05

## 易錯提醒與檢查重點

- 字元數值測試限定ASCII相容環境；若不是ASCII，數值觀察可能不同。

教學輸入契約：數值 token 須可由程式的讀取型別表示；這些範例不是用來解析任意長數字或所有惡意輸入。詳細限制見[共通輸入與測試規則](#guide)。

[← S09 while、do、for 與 continue 的執行次數](#S09)[S11 整數常數進位與輸入輸出格式 →](#S11)

S11語法補充完整化基本型別C11


<a id="toc-ch5-27"></a>

# 整數常數進位與輸入輸出格式

八進位十六進位scanf

**對應整合版：**第 59、62 頁　·　1 份程式　·　5 組測試
**來源對照：**整合版 p.59,62（原題／語意依投影片及備忘錄）
原投影片主要是語法片段／觀念示例；本 HTML 新增明確輸入輸出、main、必要標頭與測試。刻意保留錯誤行為的地方均另行說明，不把可能無限迴圈或未定義行為當成固定輸出。

[01 完整題目](#S11/problem)[02 解題說明](#S11/solution)[03 完整程式](#S11/code)[04 測試資料](#S11/tests)[05 易錯提醒](#S11/tips)

01

## 完整題目

先確認規格，再寫程式

觀察原始碼中10、010、0x10的差異，再分別以十進位、八進位、十六進位格式讀取三個unsigned值並全部用十進位印出。

### 輸入規格

依序三個token：十進位、八進位、十六進位；每個解讀後的值限0～10000。

### 輸出規格

印Literals: 10 8 16，及Read: 三個十進位數值。

### 規則與限制

- 第二個token使用%o、第三個使用%x；輸入須符合各自的合法進位文字。
- 仍沿用教學scanf輸入契約，不是拒絕所有尾隨垃圾的完整剖析器。
- 第二行使用Read: d o h，其中三個值都是解讀後的十進位值，值之間以單一空白分隔；範例16 20 10會讀出16 16 16。
- 共同錯誤處理：讀取數值失敗印ERR\_INPUT；數值可讀取但超出本題輸入範圍印ERR\_RANGE，皆以結束碼1停止。正常完成以0結束；每一行輸出均以換行結尾。

### 輸入／輸出範例

STDIN · 範例輸入

```
10 10 10
```

9 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
Literals: 10 8 16
Read: 10 8 16
```

32 bytes · 包含程式實際輸出的換行與空白

輸入區不包含提示文字。下載後可直接作為標準輸入檔；檔案結束代表 EOF，不需輸入「EOF」三個字母。

目前為自學模式：完整題目與測試輸入仍可閱讀。按上方「顯示解答」即可查看解法、程式與預期輸出。這是閱讀遮蔽功能，不是考試保密機制。

02

## 解題說明

理解狀態如何改變

**STEP 01**先分清原始碼常數前綴。

**STEP 02**scanf格式決定讀取進位。

**STEP 03**最後統一用%u印出。

### 核心思考與步驟

1. 先分清原始碼常數前綴。
2. scanf格式決定讀取進位。
3. 最後統一用%u印出。

### 固定範例追蹤

全表

這是依指定範例整理的狀態表；切換步驟只改變標記，不是在瀏覽器中編譯或執行 C。

| 文字10 | 規則 | 數值 |
| --- | --- | --- |
| 原始碼10 | 十進位 | 10 |
| 原始碼010 | 八進位 | 8 |
| 原始碼0x10 | 十六進位 | 16 |

### 為什麼這個解法成立？

相同文字形狀不一定代表相同值；程式直接指定每個欄位的進位解讀。

本題資料規模已限制；重點為所示控制流程與型別行為。

03

## 完整程式碼

每一份都可獨立編譯

s11\_integer\_io.c

補齊後的完整程式 · 13 行 · 長行可橫向捲動

```
#include <stdio.h>
int main(void) {
    unsigned int decimal, octal, hexadecimal;
    if (scanf("%u %o %x", &decimal, &octal, &hexadecimal) != 3) {
        puts("ERR_INPUT"); return 1;
    }
    if (decimal > 10000U || octal > 10000U || hexadecimal > 10000U) {
        puts("ERR_RANGE"); return 1;
    }
    printf("Literals: %d %d %d\n", 10, 010, 0x10);
    printf("Read: %u %u %u\n", decimal, octal, hexadecimal);
    return 0;
}
```

單題編譯（在包含本檔的資料夾執行）：`gcc -std=c11 -Wall -Wextra -Wpedantic s11_integer_io.c -o s11_integer_io`

完整測試方式與 Windows cmd.exe 操作範例請見[使用與驗證說明](#guide)。此頁為離線教材，不提供任意 C 程式的網頁執行環境。

04


## 測試資料

5 組完整資料

核對輸出、結束碼與 stderr。全部輸入／輸出已內嵌，可個別下載。

列印版僅列測試目的與結束碼；完整輸入與輸出請使用 HTML 展開或下載檔案，避免上限測試產生數千行列印內容。

S11-T01**相同字面字串使用不同進位讀取**本 HTML 新增測試 · 9 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
10 10 10
```

9 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Literals: 10 8 16
Read: 10 8 16
```

32 bytes · 包含程式實際輸出的換行與空白

S11-T02**相同數值使用三種進位**本 HTML 新增測試 · 11 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
255 377 ff
```

11 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Literals: 10 8 16
Read: 255 255 255
```

36 bytes · 包含程式實際輸出的換行與空白

S11-T03**零**本 HTML 新增測試 · 6 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
0 0 0
```

6 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Literals: 10 8 16
Read: 0 0 0
```

30 bytes · 包含程式實際輸出的換行與空白

S11-T04**十進位讀取失敗**本 HTML 新增測試 · 2 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
x
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_INPUT
```

10 bytes · 包含程式實際輸出的換行與空白

S11-T05**超出題目數值上限**本 HTML 新增測試 · 10 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
10001 0 0
```

10 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_RANGE
```

10 bytes · 包含程式實際輸出的換行與空白

錯誤分支的非零結束碼也屬預期結果，不代表測試失敗。測試器僅正規化 CRLF 為 LF，其餘空白需保持一致。

05

## 易錯提醒與檢查重點

- 原始碼的08不是合法八進位常數，沒有把它放進可編譯程式中。
- 這裡沒有使用%i自動判斷進位。

教學輸入契約：數值 token 須可由程式的讀取型別表示；這些範例不是用來解析任意長數字或所有惡意輸入。詳細限制見[共通輸入與測試規則](#guide)。

[← S10 有意的空本體與讀到行尾](#S10)[S12 unsigned 回繞、整數提升與混合比較 →](#S12)

S12語法補充完整化基本型別C11


<a id="toc-ch5-28"></a>

# unsigned 回繞、整數提升與混合比較

unsigned整數提升wrap

**對應整合版：**第 60、69 頁　·　1 份程式　·　1 組測試
**來源對照：**整合版 p.60,69（原題／語意依投影片及備忘錄）
原投影片主要是語法片段／觀念示例；本 HTML 新增明確輸入輸出、main、必要標頭與測試。刻意保留錯誤行為的地方均另行說明，不把可能無限迴圈或未定義行為當成固定輸出。

[01 完整題目](#S12/problem)[02 解題說明](#S12/solution)[03 完整程式](#S12/code)[04 測試資料](#S12/tests)[05 易錯提醒](#S12/tips)

01

## 完整題目

先確認規格，再寫程式

不讀取輸入，示範UINT\_MAX加1U回繞、int的-1與1U比較時的轉換，並在8-bit unsigned char環境中觀察250+10先得到260、轉回byte後得到4。

### 輸入規格

不需輸入；CHAR\_BIT等實作條件由編譯環境決定。

### 輸出規格

印Wrap、MixedLess；支援指定byte條件時印PromotedSum與Narrowed，否則印ByteDemo: SKIPPED。

### 規則與限制

- 不得實際執行INT\_MAX+1的有號溢位。
- 混合比較明示轉換後的unsigned值，重現原式-1<1U的語意。
- 小型整數示例用編譯期條件限制為UCHAR\_MAX=255且int可容納260。
- Wrap輸出UINT\_MAX+1U的結果；MixedLess輸出(unsigned int)(-1)<1U的0/1結果。指定byte條件成立時，PromotedSum印提升後的250+10，Narrowed印再轉成unsigned char的結果。

### 輸入／輸出範例

以下輸出為本次 Linux／GCC 的**完整觀察值**，不是所有電腦都必須相同的固定答案。Wrap 與 MixedLess 必須為0；若編譯條件成立，應印260與4，否則允許 ByteDemo: SKIPPED。兩條輸出路徑都由程式的條件編譯明示。

STDIN · 範例輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 0 bytes，不是空白行

STDOUT · 本次觀察

```
Wrap: 0
MixedLess: 0
PromotedSum: 260
Narrowed: 4
```

50 bytes · 包含程式實際輸出的換行與空白

輸入區不包含提示文字。下載後可直接作為標準輸入檔；檔案結束代表 EOF，不需輸入「EOF」三個字母。

目前為自學模式：完整題目與測試輸入仍可閱讀。按上方「顯示解答」即可查看解法、程式與預期輸出。這是閱讀遮蔽功能，不是考試保密機制。

02

## 解題說明

理解狀態如何改變

**STEP 01**在unsigned中相加。

**STEP 02**按规則明示mixed比較轉換。

**STEP 03**先加法再轉回unsigned char。

### 核心思考與步驟

1. 在unsigned中相加。
2. 按规則明示mixed比較轉換。
3. 先加法再轉回unsigned char。

### 固定範例追蹤

全表

這是依指定範例整理的狀態表；切換步驟只改變標記，不是在瀏覽器中編譯或執行 C。

| 階段 | 常見8-bit byte環境 |
| --- | --- |
| UINT\_MAX+1U | 0 |
| -1轉unsigned再比1U | 假 |
| a+b | int 260 |
| 轉成unsigned char | 4 |

### 為什麼這個解法成立？

原投影片的各種超界現象由不同規則導致；本程式不執行沒有固定輸出的有號溢位。

本題資料規模已限制；重點為所示控制流程與型別行為。

03

## 完整程式碼

每一份都可獨立編譯

s12\_unsigned\_rules.c

補齊後的完整程式 · 19 行 · 長行可橫向捲動

```
#include <stdio.h>
#include <limits.h>
int main(void) {
    unsigned int u = UINT_MAX;
    u = u + 1U;
    int s = -1;
    unsigned int converted = (unsigned int)s;
    printf("Wrap: %u\n", u);
    printf("MixedLess: %d\n", converted < 1U);
#if UCHAR_MAX == 255 && INT_MAX >= 260
    unsigned char a = 250, b = 10;
    int sum = a + b;
    unsigned char narrowed = (unsigned char)sum;
    printf("PromotedSum: %d\nNarrowed: %u\n", sum, (unsigned int)narrowed);
#else
    puts("ByteDemo: SKIPPED");
#endif
    return 0;
}
```

單題編譯（在包含本檔的資料夾執行）：`gcc -std=c11 -Wall -Wextra -Wpedantic s12_unsigned_rules.c -o s12_unsigned_rules`

完整測試方式與 Windows cmd.exe 操作範例請見[使用與驗證說明](#guide)。此頁為離線教材，不提供任意 C 程式的網頁執行環境。

04


## 測試資料

1 組完整資料

核對輸出、結束碼與 stderr。全部輸入／輸出已內嵌，可個別下載。

Wrap 與 MixedLess 必須為0；若編譯條件成立，應印260與4，否則允許 ByteDemo: SKIPPED。兩條輸出路徑都由程式的條件編譯明示。

列印版僅列測試目的與結束碼；完整輸入與輸出請使用 HTML 展開或下載檔案，避免上限測試產生數千行列印內容。

S12-T01**平台分支檢查：不將byte假設強加到其他實作**本 HTML 新增測試 · 0 input bytes · 平台判準exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 0 bytes，不是空白行

STDOUT · 本次觀察（非跨平台固定答案）

```
Wrap: 0
MixedLess: 0
PromotedSum: 260
Narrowed: 4
```

50 bytes · 包含程式實際輸出的換行與空白

錯誤分支的非零結束碼也屬預期結果，不代表測試失敗。測試器僅正規化 CRLF 為 LF，其餘空白需保持一致。

05

## 易錯提醒與檢查重點

- 本題不是把所有型別超界都統稱溢位；無號算術、提升與縮窄轉換分開。

教學輸入契約：數值 token 須可由程式的讀取型別表示；這些範例不是用來解析任意長數字或所有惡意輸入。詳細限制見[共通輸入與測試規則](#guide)。

[← S11 整數常數進位與輸入輸出格式](#S11)[S13 先轉型再除法：平均值與零筆資料 →](#S13)

S13語法補充完整化基本型別C11


<a id="toc-ch5-29"></a>

# 先轉型再除法：平均值與零筆資料

cast整數除法零分母

**對應整合版：**第 70、81、93 頁　·　1 份程式　·　5 組測試
**來源對照：**整合版 p.70,81,93（原題／語意依投影片及備忘錄）
原投影片主要是語法片段／觀念示例；本 HTML 新增明確輸入輸出、main、必要標頭與測試。刻意保留錯誤行為的地方均另行說明，不把可能無限迴圈或未定義行為當成固定輸出。

[01 完整題目](#S13/problem)[02 解題說明](#S13/solution)[03 完整程式](#S13/code)[04 測試資料](#S13/tests)[05 易錯提醒](#S13/tips)

01

## 完整題目

先確認規格，再寫程式

輸入sum、count，對比(double)(sum/count)與(double)sum/count；count=0時輸出NO\_DATA，不做除法。此題補成第93頁平均值除錯題的完整程式。

### 輸入規格

sum為-10000～10000的整數；count為0～1000。

### 輸出規格

正常印AfterDivision與BeforeDivision（2位小數）；count=0印NO\_DATA。

### 規則與限制

- 只比較轉型時機，不把sum重新由資料串流算出。
- 讀取或範圍錯誤印ERR\_INPUT或ERR\_RANGE，結束碼1。
- AfterDivision先做整數sum/count，再將結果轉成double；BeforeDivision在除法之前將sum轉成double。正常兩行皆顯示兩位小數；NO\_DATA為正常的0結束碼。
- 共同錯誤處理：讀取數值失敗印ERR\_INPUT；數值可讀取但超出本題輸入範圍印ERR\_RANGE，皆以結束碼1停止。正常完成以0結束；每一行輸出均以換行結尾。

### 輸入／輸出範例

STDIN · 範例輸入

```
3 2
```

4 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
AfterDivision: 1.00
BeforeDivision: 1.50
```

41 bytes · 包含程式實際輸出的換行與空白

輸入區不包含提示文字。下載後可直接作為標準輸入檔；檔案結束代表 EOF，不需輸入「EOF」三個字母。

目前為自學模式：完整題目與測試輸入仍可閱讀。按上方「顯示解答」即可查看解法、程式與預期輸出。這是閱讀遮蔽功能，不是考試保密機制。

02

## 解題說明

理解狀態如何改變

**STEP 01**先判定count是否為0。

**STEP 02**先除法会先截斷小數。

**STEP 03**先轉型才以浮點相除。

### 核心思考與步驟

1. 先判定count是否為0。
2. 先除法会先截斷小數。
3. 先轉型才以浮點相除。

### 固定範例追蹤

全表

這是依指定範例整理的狀態表；切換步驟只改變標記，不是在瀏覽器中編譯或執行 C。

| 運算 | 3/2中間值 | 最後結果 |
| --- | --- | --- |
| 先整數除法 | 1 | 1.00 |
| 先轉double | 3.0/2.0 | 1.50 |

### 為什麼這個解法成立？

浮點型別不能復原之前整數除法已捨棄的小數部分。

本題資料規模已限制；重點為所示控制流程與型別行為。

03

## 完整程式碼

每一份都可獨立編譯

s13\_cast\_mean.c

補齊後的完整程式 · 13 行 · 長行可橫向捲動

```
#include <stdio.h>
int main(void) {
    int sum, count;
    if (scanf("%d %d", &sum, &count) != 2) { puts("ERR_INPUT"); return 1; }
    if (sum < -10000 || sum > 10000 || count < 0 || count > 1000) {
        puts("ERR_RANGE"); return 1;
    }
    if (count == 0) { puts("NO_DATA"); return 0; }
    double after = (double)(sum / count);
    double before = (double)sum / count;
    printf("AfterDivision: %.2f\nBeforeDivision: %.2f\n", after, before);
    return 0;
}
```

單題編譯（在包含本檔的資料夾執行）：`gcc -std=c11 -Wall -Wextra -Wpedantic s13_cast_mean.c -o s13_cast_mean`

完整測試方式與 Windows cmd.exe 操作範例請見[使用與驗證說明](#guide)。此頁為離線教材，不提供任意 C 程式的網頁執行環境。

04


## 測試資料

5 組完整資料

核對輸出、結束碼與 stderr。全部輸入／輸出已內嵌，可個別下載。

列印版僅列測試目的與結束碼；完整輸入與輸出請使用 HTML 展開或下載檔案，避免上限測試產生數千行列印內容。

S13-T01**第93頁的3/2**本 HTML 新增測試 · 4 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
3 2
```

4 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
AfterDivision: 1.00
BeforeDivision: 1.50
```

41 bytes · 包含程式實際輸出的換行與空白

S13-T02**第70頁的7/2**本 HTML 新增測試 · 4 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
7 2
```

4 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
AfterDivision: 3.00
BeforeDivision: 3.50
```

41 bytes · 包含程式實際輸出的換行與空白

S13-T03**負整數除法向零截斷**本 HTML 新增測試 · 5 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
-7 2
```

5 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
AfterDivision: -3.00
BeforeDivision: -3.50
```

43 bytes · 包含程式實際輸出的換行與空白

S13-T04**零分母不運算**本 HTML 新增測試 · 4 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
0 0
```

4 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
NO_DATA
```

8 bytes · 包含程式實際輸出的換行與空白

S13-T05**非法count**本 HTML 新增測試 · 5 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
1 -1
```

5 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_RANGE
```

10 bytes · 包含程式實際輸出的換行與空白

錯誤分支的非零結束碼也屬預期結果，不代表測試失敗。測試器僅正規化 CRLF 為 LF，其餘空白需保持一致。

05

## 易錯提醒與檢查重點

- 這是轉型順序問題，不是float或double精度不足。

教學輸入契約：數值 token 須可由程式的讀取型別表示；這些範例不是用來解析任意長數字或所有惡意輸入。詳細限制見[共通輸入與測試規則](#guide)。

[← S12 unsigned 回繞、整數提升與混合比較](#S12)[S14 float、double、long double 的 I/O 與精度觀察 →](#S14)

S14語法補充完整化基本型別C11


<a id="toc-ch5-30"></a>

# float、double、long double 的 I/O 與精度觀察

float%lf精度

**對應整合版：**第 66–68 頁　·　1 份程式　·　4 組測試
**來源對照：**整合版 p.66,67,68（原題／語意依投影片及備忘錄）
原投影片主要是語法片段／觀念示例；本 HTML 新增明確輸入輸出、main、必要標頭與測試。刻意保留錯誤行為的地方均另行說明，不把可能無限迴圈或未定義行為當成固定輸出。

[01 完整題目](#S14/problem)[02 解題說明](#S14/solution)[03 完整程式](#S14/code)[04 測試資料](#S14/tests)[05 易錯提醒](#S14/tips)

01

## 完整題目

先確認規格，再寫程式

分別讀入float、double與long double，使用正確格式輸出，再印出0.1+0.2的高精度觀察及只顯示兩位小數的結果。

### 輸入規格

三個有限實數f d ld，各在-10000～10000。

### 輸出規格

印Float、Double、LongDouble（6位小數）、Sum17（17位有效數字）與Sum2（2位小數）。

### 規則與限制

- scanf使用%f、%lf、%Lf；printf的float/double用%f，long double用%Lf。
- Sum17是本環境觀察，不預設所有C實作都印出相同末位。
- 輸入錯誤或不在有限範圍內印ERR\_INPUT或ERR\_RANGE。
- 五個欄位各自一行，格式皆為「標籤: 值」。Sum17與Sum2都觀察double sum=0.1+0.2，不是輸入f、d、ld的加總。正常結束碼0，輸入或範圍錯誤結束碼1。
- 共同錯誤處理：讀取數值失敗印ERR\_INPUT；數值可讀取但超出本題輸入範圍印ERR\_RANGE，皆以結束碼1停止。正常完成以0結束；每一行輸出均以換行結尾。

### 輸入／輸出範例

以下輸出為本次 Linux／GCC 的**完整觀察值**，不是所有電腦都必須相同的固定答案。本組測試使用可精確表示的1.25及0，前三行對照六位小數；Sum2 必須為0.30。Sum17 須為有限數且與0.3的差小於10^-12，不將某一平台的最後一位寫成普遍答案。此誤差門檻是本測試所選，而非語言對所有浮點實作的保證。

STDIN · 範例輸入

```
1.25 1.25 1.25
```

15 bytes · 最後有 LF 換行

STDOUT · 本次觀察

```
Float: 1.250000
Double: 1.250000
LongDouble: 1.250000
Sum17: 0.30000000000000004
Sum2: 0.30
```

92 bytes · 包含程式實際輸出的換行與空白

輸入區不包含提示文字。下載後可直接作為標準輸入檔；檔案結束代表 EOF，不需輸入「EOF」三個字母。

目前為自學模式：完整題目與測試輸入仍可閱讀。按上方「顯示解答」即可查看解法、程式與預期輸出。這是閱讀遮蔽功能，不是考試保密機制。

02

## 解題說明

理解狀態如何改變

**STEP 01**按照目標物件選讀取格式。

**STEP 02**確認三個值都是合法範圍。

**STEP 03**區分儲存值與輸出格式。

### 核心思考與步驟

1. 按照目標物件選讀取格式。
2. 確認三個值都是合法範圍。
3. 區分儲存值與輸出格式。

### 固定範例追蹤

全表

這是依指定範例整理的狀態表；切換步驟只改變標記，不是在瀏覽器中編譯或執行 C。

| 輸出 | 常見binary64環境 |
| --- | --- |
| Sum17 | 0.30000000000000004 |
| Sum2 | 0.30 |
| 結論 | 格式化不改變內部儲存 |

### 為什麼這個解法成立？

讀取契約與輸出參數提升不同；以適合每個物件的格式才能可靠讀取。

本題資料規模已限制；重點為所示控制流程與型別行為。

03

## 完整程式碼

每一份都可獨立編譯

s14\_floating\_io.c

補齊後的完整程式 · 16 行 · 長行可橫向捲動

```
#include <stdio.h>
int main(void) {
    float f;
    double d;
    long double ld;
    if (scanf("%f %lf %Lf", &f, &d, &ld) != 3) { puts("ERR_INPUT"); return 1; }
    if (!(f >= -10000.0f && f <= 10000.0f) ||
        !(d >= -10000.0 && d <= 10000.0) ||
        !(ld >= -10000.0L && ld <= 10000.0L)) {
        puts("ERR_RANGE"); return 1;
    }
    double sum = 0.1 + 0.2;
    printf("Float: %.6f\nDouble: %.6f\nLongDouble: %.6Lf\n", f, d, ld);
    printf("Sum17: %.17g\nSum2: %.2f\n", sum, sum);
    return 0;
}
```

單題編譯（在包含本檔的資料夾執行）：`gcc -std=c11 -Wall -Wextra -Wpedantic s14_floating_io.c -o s14_floating_io`

完整測試方式與 Windows cmd.exe 操作範例請見[使用與驗證說明](#guide)。此頁為離線教材，不提供任意 C 程式的網頁執行環境。

04


## 測試資料

4 組完整資料

核對輸出、結束碼與 stderr。全部輸入／輸出已內嵌，可個別下載。

本組測試使用可精確表示的1.25及0，前三行對照六位小數；Sum2 必須為0.30。Sum17 須為有限數且與0.3的差小於10^-12，不將某一平台的最後一位寫成普遍答案。此誤差門檻是本測試所選，而非語言對所有浮點實作的保證。

列印版僅列測試目的與結束碼；完整輸入與輸出請使用 HTML 展開或下載檔案，避免上限測試產生數千行列印內容。

S14-T01**精確二進位輸入與環境浮點觀察**本 HTML 新增測試 · 15 input bytes · 平台判準exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
1.25 1.25 1.25
```

15 bytes · 最後有 LF 換行

STDOUT · 本次觀察（非跨平台固定答案）

```
Float: 1.250000
Double: 1.250000
LongDouble: 1.250000
Sum17: 0.30000000000000004
Sum2: 0.30
```

92 bytes · 包含程式實際輸出的換行與空白

S14-T02**零輸入與固定觀察**本 HTML 新增測試 · 6 input bytes · 平台判準exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
0 0 0
```

6 bytes · 最後有 LF 換行

STDOUT · 本次觀察（非跨平台固定答案）

```
Float: 0.000000
Double: 0.000000
LongDouble: 0.000000
Sum17: 0.30000000000000004
Sum2: 0.30
```

92 bytes · 包含程式實際輸出的換行與空白

S14-T03**拒絕NaN**本 HTML 新增測試 · 8 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
nan 1 1
```

8 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_RANGE
```

10 bytes · 包含程式實際輸出的換行與空白

S14-T04**讀取失敗**本 HTML 新增測試 · 2 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
x
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_INPUT
```

10 bytes · 包含程式實際輸出的換行與空白

錯誤分支的非零結束碼也屬預期結果，不代表測試失敗。測試器僅正規化 CRLF 為 LF，其餘空白需保持一致。

05

## 易錯提醒與檢查重點

- 以%.2f印成0.30不代表內部精確儲存十進位0.3。
- 本示例不執行scanf格式不匹配的錯誤版本。

教學輸入契約：數值 token 須可由程式的讀取型別表示；這些範例不是用來解析任意長數字或所有惡意輸入。詳細限制見[共通輸入與測試規則](#guide)。

[← S13 先轉型再除法：平均值與零筆資料](#S13)[S15 字元、跳脫字元與 toupper →](#S15)

S15語法補充完整化基本型別C11


<a id="toc-ch5-31"></a>

# 字元、跳脫字元與 toupper

charASCIItoupper

**對應整合版：**第 74、76、77 頁　·　1 份程式　·　5 組測試
**來源對照：**整合版 p.74,76,77（原題／語意依投影片及備忘錄）
原投影片主要是語法片段／觀念示例；本 HTML 新增明確輸入輸出、main、必要標頭與測試。刻意保留錯誤行為的地方均另行說明，不把可能無限迴圈或未定義行為當成固定輸出。

[01 完整題目](#S15/problem)[02 解題說明](#S15/solution)[03 完整程式](#S15/code)[04 測試資料](#S15/tests)[05 易錯提醒](#S15/tips)

01

## 完整題目

先確認規格，再寫程式

讀入一個ASCII字元，印出其數值、大寫版本與數字值；最後示範八進位跳脫、分開十六進位跳脫與tab輸出。

### 輸入規格

一個ASCII字元（空白也可）；立即EOF視為ERR\_INPUT。

### 輸出規格

印Code、Upper、Digit；以及HexJoin: AB、Octal: S、Tab: A與B中間一個tab。

### 規則與限制

- getchar用int接收；先排除EOF再交給toupper或isdigit。
- 不是數字時Digit印-1；數字用ch-'0'轉數值。
- 字元數值與跳脫觀察限定ASCII相容環境。
- Upper使用toupper的結果；Code為原輸入byte的十進位值。只讀第一個byte，不消耗或解讀整行。正常結束碼0；輸入EOF或byte值大於127時分別印ERR\_INPUT、ERR\_RANGE並以1結束。
- HexJoin與Octal為固定示範文字；Tab一行的實際輸出為Tab: A\tB\n，其中\t和\n分別代表一個tab與換行，不是反斜線字母。

### 輸入／輸出範例

STDIN · 範例輸入

```
a
```

2 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
Code: 97
Upper: A
Digit: -1
HexJoin: AB
Octal: S
Tab: A	B
```

58 bytes · 包含程式實際輸出的換行與空白

輸入區不包含提示文字。下載後可直接作為標準輸入檔；檔案結束代表 EOF，不需輸入「EOF」三個字母。

目前為自學模式：完整題目與測試輸入仍可閱讀。按上方「顯示解答」即可查看解法、程式與預期輸出。這是閱讀遮蔽功能，不是考試保密機制。

02

## 解題說明

理解狀態如何改變

**STEP 01**以int保存讀取結果。

**STEP 02**使用ctype分類與轉大寫。

**STEP 03**分開字串常值終止hex跳脫。

### 核心思考與步驟

1. 以int保存讀取結果。
2. 使用ctype分類與轉大寫。
3. 分開字串常值終止hex跳脫。

### 固定範例追蹤

全表

這是依指定範例整理的狀態表；切換步驟只改變標記，不是在瀏覽器中編譯或執行 C。

| 項目 | 輸入a |
| --- | --- |
| getchar | 97 |
| toupper | A |
| Digit | -1 |
| "\x41" "B" | AB |

### 為什麼這個解法成立？

字元編碼、字串拼接與ctype使用契約各自明確，不依不安全的char型別保存EOF。

本題資料規模已限制；重點為所示控制流程與型別行為。

03

## 完整程式碼

每一份都可獨立編譯

s15\_char\_escape.c

補齊後的完整程式 · 13 行 · 長行可橫向捲動

```
#include <stdio.h>
#include <ctype.h>
int main(void) {
    int ch = getchar();
    if (ch == EOF) { puts("ERR_INPUT"); return 1; }
    if (ch > 127) { puts("ERR_RANGE"); return 1; }
    printf("Code: %d\nUpper: %c\n", ch, toupper(ch));
    printf("Digit: %d\n", isdigit(ch) ? ch - '0' : -1);
    puts("HexJoin: " "\x41" "B");
    printf("Octal: %c\n", '\123');
    printf("Tab: A\tB\n");
    return 0;
}
```

單題編譯（在包含本檔的資料夾執行）：`gcc -std=c11 -Wall -Wextra -Wpedantic s15_char_escape.c -o s15_char_escape`

完整測試方式與 Windows cmd.exe 操作範例請見[使用與驗證說明](#guide)。此頁為離線教材，不提供任意 C 程式的網頁執行環境。

04


## 測試資料

5 組完整資料

核對輸出、結束碼與 stderr。全部輸入／輸出已內嵌，可個別下載。

列印版僅列測試目的與結束碼；完整輸入與輸出請使用 HTML 展開或下載檔案，避免上限測試產生數千行列印內容。

S15-T01**小寫轉大寫**本 HTML 新增測試 · 2 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
a
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Code: 97
Upper: A
Digit: -1
HexJoin: AB
Octal: S
Tab: A	B
```

58 bytes · 包含程式實際輸出的換行與空白

S15-T02**數字轉數值**本 HTML 新增測試 · 2 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
7
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Code: 55
Upper: 7
Digit: 7
HexJoin: AB
Octal: S
Tab: A	B
```

57 bytes · 包含程式實際輸出的換行與空白

S15-T03**空白不被略過**本 HTML 新增測試 · 2 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```

```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Code: 32
Upper:
Digit: -1
HexJoin: AB
Octal: S
Tab: A	B
```

58 bytes · 包含程式實際輸出的換行與空白

S15-T04**大寫保持不變**本 HTML 新增測試 · 2 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
A
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Code: 65
Upper: A
Digit: -1
HexJoin: AB
Octal: S
Tab: A	B
```

58 bytes · 包含程式實際輸出的換行與空白

S15-T05**立即EOF**本 HTML 新增測試 · 0 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 0 bytes，不是空白行

STDOUT · 完整預期輸出

```
ERR_INPUT
```

10 bytes · 包含程式實際輸出的換行與空白

錯誤分支的非零結束碼也屬預期結果，不代表測試失敗。測試器僅正規化 CRLF 為 LF，其餘空白需保持一致。

05

## 易錯提醒與檢查重點

- "\x41B"不是字母A接B，因為B也屬十六進位數字；本程式使用相鄰字串拼接。

教學輸入契約：數值 token 須可由程式的讀取型別表示；這些範例不是用來解析任意長數字或所有惡意輸入。詳細限制見[共通輸入與測試規則](#guide)。

[← S14 float、double、long double 的 I/O 與精度觀察](#S14)[S16 scanf 後殘留的換行與下一個命令 →](#S16)

S16語法補充完整化基本型別C11


<a id="toc-ch5-32"></a>

# scanf 後殘留的換行與下一個命令

scanfgetchar輸入緩衝

**對應整合版：**第 75 頁　·　1 份程式　·　5 組測試
**來源對照：**整合版 p.75（原題／語意依投影片及備忘錄）
原投影片主要是語法片段／觀念示例；本 HTML 新增明確輸入輸出、main、必要標頭與測試。刻意保留錯誤行為的地方均另行說明，不把可能無限迴圈或未定義行為當成固定輸出。

[01 完整題目](#S16/problem)[02 解題說明](#S16/solution)[03 完整程式](#S16/code)[04 測試資料](#S16/tests)[05 易錯提醒](#S16/tips)

01

## 完整題目

先確認規格，再寫程式

先用scanf讀整數，再用getchar觀察下一個未消耗字元，最後用scanf(" %c")讀下一個非空白命令。

### 輸入規格

一個-10000～10000的整數、至少一個後續ASCII字元，以及一個仍可供讀取的非空白ASCII命令。

### 輸出規格

印Number、Next（LF/SPACE/TAB/EOF或Code）、Command。

### 規則與限制

- getchar不略過空白，讀到的字元會被消耗。
- " %c"前的空白會略過連續空白，可能跨行。
- 缺少命令時在已印出的觀察之後印ERR\_INPUT並結束。
- Next觀察到換行、空白、tab或EOF時分別印Next: LF、Next: SPACE、Next: TAB、Next: EOF；其他值印Next: Code N，N為byte十進位值。最後成功讀到命令才印Command: X。
- 共同錯誤處理：讀取數值失敗印ERR\_INPUT；數值可讀取但超出本題輸入範圍印ERR\_RANGE，皆以結束碼1停止。正常完成以0結束；每一行輸出均以換行結尾。

### 輸入／輸出範例

STDIN · 範例輸入

```
123
Q
```

6 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
Number: 123
Next: LF
Command: Q
```

32 bytes · 包含程式實際輸出的換行與空白

輸入區不包含提示文字。下載後可直接作為標準輸入檔；檔案結束代表 EOF，不需輸入「EOF」三個字母。

目前為自學模式：完整題目與測試輸入仍可閱讀。按上方「顯示解答」即可查看解法、程式與預期輸出。這是閱讀遮蔽功能，不是考試保密機制。

02

## 解題說明

理解狀態如何改變

**STEP 01**scanf取走整數文字。

**STEP 02**getchar讀第一個剩餘字元。

**STEP 03**帶空白%c找下一個非空白命令。

### 核心思考與步驟

1. scanf取走整數文字。
2. getchar讀第一個剩餘字元。
3. 帶空白%c找下一個非空白命令。

### 固定範例追蹤

全表

這是依指定範例整理的狀態表；切換步驟只改變標記，不是在瀏覽器中編譯或執行 C。

| 串流 | 動作 |
| --- | --- |
| 123\nQ\n | scanf讀走123 |
| \nQ\n | getchar得到換行 |
| Q\n | scanf(" %c")得到Q |

### 為什麼這個解法成立？

分別觀察每次呼叫前的剩餘串流，可以預測下一次讀取會拿到什麼。

本題資料規模已限制；重點為所示控制流程與型別行為。

03

## 完整程式碼

每一份都可獨立編譯

s16\_input\_buffer.c

補齊後的完整程式 · 17 行 · 長行可橫向捲動

```
#include <stdio.h>
int main(void) {
    int number, ch;
    char command;
    if (scanf("%d", &number) != 1) { puts("ERR_INPUT"); return 1; }
    if (number < -10000 || number > 10000) { puts("ERR_RANGE"); return 1; }
    printf("Number: %d\n", number);
    ch = getchar();
    if (ch == '\n') puts("Next: LF");
    else if (ch == ' ') puts("Next: SPACE");
    else if (ch == '\t') puts("Next: TAB");
    else if (ch == EOF) puts("Next: EOF");
    else printf("Next: Code %d\n", ch);
    if (scanf(" %c", &command) != 1) { puts("ERR_INPUT"); return 1; }
    printf("Command: %c\n", command);
    return 0;
}
```

單題編譯（在包含本檔的資料夾執行）：`gcc -std=c11 -Wall -Wextra -Wpedantic s16_input_buffer.c -o s16_input_buffer`

完整測試方式與 Windows cmd.exe 操作範例請見[使用與驗證說明](#guide)。此頁為離線教材，不提供任意 C 程式的網頁執行環境。

04


## 測試資料

5 組完整資料

核對輸出、結束碼與 stderr。全部輸入／輸出已內嵌，可個別下載。

列印版僅列測試目的與結束碼；完整輸入與輸出請使用 HTML 展開或下載檔案，避免上限測試產生數千行列印內容。

S16-T01**教材殘留換行**本 HTML 新增測試 · 6 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
123
Q
```

6 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Number: 123
Next: LF
Command: Q
```

32 bytes · 包含程式實際輸出的換行與空白

S16-T02**多個空白**本 HTML 新增測試 · 8 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
123   Q
```

8 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Number: 123
Next: SPACE
Command: Q
```

35 bytes · 包含程式實際輸出的換行與空白

S16-T03**getchar先消耗Q**本 HTML 新增測試 · 7 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
123Q R
```

7 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Number: 123
Next: Code 81
Command: R
```

37 bytes · 包含程式實際輸出的換行與空白

S16-T04**缺少後續命令**本 HTML 新增測試 · 3 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
123
```

3 bytes · 最後沒有換行，檔案直接結束

STDOUT · 完整預期輸出

```
Number: 123
Next: EOF
ERR_INPUT
```

32 bytes · 包含程式實際輸出的換行與空白

S16-T05**首筆讀取失敗**本 HTML 新增測試 · 2 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
x
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_INPUT
```

10 bytes · 包含程式實際輸出的換行與空白

錯誤分支的非零結束碼也屬預期結果，不代表測試失敗。測試器僅正規化 CRLF 為 LF，其餘空白需保持一致。

05

## 易錯提醒與檢查重點

- 本題是刻意觀察「先消耗一個字元」；一般讀命令不一定需要中間那次getchar。
- 不使用fflush(stdin)處理殘留輸入。

教學輸入契約：數值 token 須可由程式的讀取型別表示；這些範例不是用來解析任意長數字或所有惡意輸入。詳細限制見[共通輸入與測試規則](#guide)。

[← S15 字元、跳脫字元與 toupper](#S15)[S17 typedef、sizeof 與精確寬度型別 →](#S17)

S17語法補充完整化基本型別C11


<a id="toc-ch5-33"></a>

# typedef、sizeof 與精確寬度型別

typedefsizeofstdint

**對應整合版：**第 80 頁　·　1 份程式　·　1 組測試
**來源對照：**整合版 p.80（原題／語意依投影片及備忘錄）
原投影片主要是語法片段／觀念示例；本 HTML 新增明確輸入輸出、main、必要標頭與測試。刻意保留錯誤行為的地方均另行說明，不把可能無限迴圈或未定義行為當成固定輸出。

[01 完整題目](#S17/problem)[02 解題說明](#S17/solution)[03 完整程式](#S17/code)[04 測試資料](#S17/tests)[05 易錯提醒](#S17/tips)

01

## 完整題目

先確認規格，再寫程式

不讀取輸入，驗證Cents只是long long的別名、sizeof(char)=1，且固定型別的sizeof(i++)不會自增i；若環境提供uint32\_t，使用PRIu32印出42。

### 輸入規格

不需輸入。

### 輸出規格

印AliasSameSize、NegativeAllowed、CharSize、AfterSizeof與U32。

### 規則與限制

- Cents先存-1，說明typedef沒有自動加入非負限制。
- sizeof的值先存成size\_t但不把平台int大小當成固定答案。
- uint32\_t以UINT32\_MAX條件檢查是否存在，不假定所有實作都有。
- AliasSameSize為sizeof(Cents)==sizeof(long long)的0/1值；NegativeAllowed為balance=-1之後balance<0的0/1值；CharSize印sizeof(char)。
- i初值為7；先取得sizeof(i++)但不使用其數值，再印AfterSizeof: i。若UINT32\_MAX有定義則印U32: 42，否則印U32: UNAVAILABLE；正常結束碼0。

### 輸入／輸出範例

以下輸出為本次 Linux／GCC 的**完整觀察值**，不是所有電腦都必須相同的固定答案。別名大小相同、仍可為負、sizeof(char)=1及未執行i++是固定判準；精確32位元型別存在時印42，否則允許 UNAVAILABLE。

STDIN · 範例輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 0 bytes，不是空白行

STDOUT · 本次觀察

```
AliasSameSize: 1
NegativeAllowed: 1
CharSize: 1
AfterSizeof: 7
U32: 42
```

71 bytes · 包含程式實際輸出的換行與空白

輸入區不包含提示文字。下載後可直接作為標準輸入檔；檔案結束代表 EOF，不需輸入「EOF」三個字母。

目前為自學模式：完整題目與測試輸入仍可閱讀。按上方「顯示解答」即可查看解法、程式與預期輸出。這是閱讀遮蔽功能，不是考試保密機制。

02

## 解題說明

理解狀態如何改變

**STEP 01**typedef建立型別別名。

**STEP 02**sizeof固定型別不求值。

**STEP 03**平台支援才使用uint32\_t。

### 核心思考與步驟

1. typedef建立型別別名。
2. sizeof固定型別不求值。
3. 平台支援才使用uint32\_t。

### 固定範例追蹤

全表

這是依指定範例整理的狀態表；切換步驟只改變標記，不是在瀏覽器中編譯或執行 C。

| 表達式 | 結果 |
| --- | --- |
| sizeof(Cents)==sizeof(long long) | 1 |
| balance=-1 | 允許 |
| sizeof(i++)後 | i仍為7 |
| uint32\_t | 視環境提供情形 |

### 為什麼這個解法成立？

型別別名不改變底層值域；sizeof的固定型別操作不執行i++。

本題資料規模已限制；重點為所示控制流程與型別行為。

03

## 完整程式碼

每一份都可獨立編譯

s17\_typedef\_sizeof.c

補齊後的完整程式 · 21 行 · 長行可橫向捲動

```
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
typedef long long Cents;
int main(void) {
    Cents balance = -1;
    int i = 7;
    size_t size = sizeof(i++);
    (void)size;
    printf("AliasSameSize: %d\n", sizeof(Cents) == sizeof(long long));
    printf("NegativeAllowed: %d\n", balance < 0);
    printf("CharSize: %zu\n", sizeof(char));
    printf("AfterSizeof: %d\n", i);
#ifdef UINT32_MAX
    uint32_t value = 42;
    printf("U32: %" PRIu32 "\n", value);
#else
    puts("U32: UNAVAILABLE");
#endif
    return 0;
}
```

單題編譯（在包含本檔的資料夾執行）：`gcc -std=c11 -Wall -Wextra -Wpedantic s17_typedef_sizeof.c -o s17_typedef_sizeof`

**刻意保留的教學警告：**Clang 會對 sizeof(i++) 發出未求值運算式警告。自動測試只對本題使用 `-Wno-error=unevaluated-expression`，保留警告而不將其升級成錯誤；沒有關閉其他警告。一般程式不應在 sizeof 中放無作用的自增。

完整測試方式與 Windows cmd.exe 操作範例請見[使用與驗證說明](#guide)。此頁為離線教材，不提供任意 C 程式的網頁執行環境。

04


## 測試資料

1 組完整資料

核對輸出、結束碼與 stderr。全部輸入／輸出已內嵌，可個別下載。

別名大小相同、仍可為負、sizeof(char)=1及未執行i++是固定判準；精確32位元型別存在時印42，否則允許 UNAVAILABLE。

列印版僅列測試目的與結束碼；完整輸入與輸出請使用 HTML 展開或下載檔案，避免上限測試產生數千行列印內容。

S17-T01**固定不變數與精確寬度型別條件檢查**本 HTML 新增測試 · 0 input bytes · 平台判準exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 0 bytes，不是空白行

STDOUT · 本次觀察（非跨平台固定答案）

```
AliasSameSize: 1
NegativeAllowed: 1
CharSize: 1
AfterSizeof: 7
U32: 42
```

71 bytes · 包含程式實際輸出的換行與空白

錯誤分支的非零結束碼也屬預期結果，不代表測試失敗。測試器僅正規化 CRLF 為 LF，其餘空白需保持一致。

05

## 易錯提醒與檢查重點

- 本题沒有VLA；不能將sizeof(i++)不自增的結論無條件推廣至所有變動長度陣列運算。
- 負數是否允許需要額外驗證，不是typedef會替你處理。
- 本題的 sizeof(i++) 刻意展示未求值運算式。Clang 會發出 unevaluated-expression 警告；自動測試只對本題把這個警告從錯誤降級，仍保留警告紀錄。一般程式請避免在 sizeof 中寫無作用的自增。

教學輸入契約：數值 token 須可由程式的讀取型別表示；這些範例不是用來解析任意長數字或所有惡意輸入。詳細限制見[共通輸入與測試規則](#guide)。

[← S16 scanf 後殘留的換行與下一個命令](#S16)[S18 安全的 unsigned 倒數 →](#S18)

S18語法補充完整化綜合實作C11


<a id="toc-ch5-34"></a>

# 安全的 unsigned 倒數

unsigned倒數除錯

**對應整合版：**第 93 頁　·　1 份程式　·　5 組測試
**來源對照：**整合版 p.93（原題／語意依投影片及備忘錄）
原投影片主要是語法片段／觀念示例；本 HTML 新增明確輸入輸出、main、必要標頭與測試。刻意保留錯誤行為的地方均另行說明，不把可能無限迴圈或未定義行為當成固定輸出。

[01 完整題目](#S18/problem)[02 解題說明](#S18/solution)[03 完整程式](#S18/code)[04 測試資料](#S18/tests)[05 易錯提醒](#S18/tips)

01

## 完整題目

先確認規格，再寫程式

輸入n，依序輸出n-1到0；n=0時不處理任何項目。修正原題unsigned i>=0永遠為真的問題。

### 輸入規格

一個整數n，0～20。

### 輸出規格

輸出Reverse:後接倒數項目，各相隔一個空白；n=0只印Reverse:及換行。

### 規則與限制

- 先讀成int以驗證非負，再轉unsigned。
- 迴圈狀態從n開始，只在i>0時印i-1，因此不會先算n-1造成n=0下溢。
- 每個倒數項目前都有一個空白，不在行尾另加空白；最後一定換行。
- 共同錯誤處理：讀取數值失敗印ERR\_INPUT；數值可讀取但超出本題輸入範圍印ERR\_RANGE，皆以結束碼1停止。正常完成以0結束；每一行輸出均以換行結尾。

### 輸入／輸出範例

STDIN · 範例輸入

```
3
```

2 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
Reverse: 2 1 0
```

15 bytes · 包含程式實際輸出的換行與空白

輸入區不包含提示文字。下載後可直接作為標準輸入檔；檔案結束代表 EOF，不需輸入「EOF」三個字母。

目前為自學模式：完整題目與測試輸入仍可閱讀。按上方「顯示解答」即可查看解法、程式與預期輸出。這是閱讀遮蔽功能，不是考試保密機制。

02

## 解題說明

理解狀態如何改變

**STEP 01**由n而非n-1初始化。

**STEP 02**只在i>0時進本體。

**STEP 03**處理i-1後再遞減。

### 核心思考與步驟

1. 由n而非n-1初始化。
2. 只在i>0時進本體。
3. 處理i-1後再遞減。

### 固定範例追蹤

全表

這是依指定範例整理的狀態表；切換步驟只改變標記，不是在瀏覽器中編譯或執行 C。

| i | 輸出 | 下一個i |
| --- | --- | --- |
| 3 | 2 | 2 |
| 2 | 1 | 1 |
| 1 | 0 | 0 |
| 0 | 不進本體 | 停止 |

### 為什麼這個解法成立？

本體只在i為正時運作，i-1合法；遞減到0後條件失敗。

本題資料規模已限制；重點為所示控制流程與型別行為。

03

## 完整程式碼

每一份都可獨立編譯

s18\_reverse\_unsigned.c

補齊後的完整程式 · 13 行 · 長行可橫向捲動

```
#include <stdio.h>
int main(void) {
    int input;
    if (scanf("%d", &input) != 1) { puts("ERR_INPUT"); return 1; }
    if (input < 0 || input > 20) { puts("ERR_RANGE"); return 1; }
    unsigned int n = (unsigned int)input;
    printf("Reverse:");
    for (unsigned int i = n; i > 0; --i) {
        printf(" %u", i - 1U);
    }
    putchar('\n');
    return 0;
}
```

單題編譯（在包含本檔的資料夾執行）：`gcc -std=c11 -Wall -Wextra -Wpedantic s18_reverse_unsigned.c -o s18_reverse_unsigned`

完整測試方式與 Windows cmd.exe 操作範例請見[使用與驗證說明](#guide)。此頁為離線教材，不提供任意 C 程式的網頁執行環境。

04


## 測試資料

5 組完整資料

核對輸出、結束碼與 stderr。全部輸入／輸出已內嵌，可個別下載。

列印版僅列測試目的與結束碼；完整輸入與輸出請使用 HTML 展開或下載檔案，避免上限測試產生數千行列印內容。

S18-T01**3個項目**本 HTML 新增測試 · 2 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
3
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Reverse: 2 1 0
```

15 bytes · 包含程式實際輸出的換行與空白

S18-T02**空序列不得下溢**本 HTML 新增測試 · 2 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
0
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Reverse:
```

9 bytes · 包含程式實際輸出的換行與空白

S18-T03**單一0**本 HTML 新增測試 · 2 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
1
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Reverse: 0
```

11 bytes · 包含程式實際輸出的換行與空白

S18-T04**上界**本 HTML 新增測試 · 3 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
20
```

3 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Reverse: 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0
```

59 bytes · 包含程式實際輸出的換行與空白

S18-T05**拒絕負n**本 HTML 新增測試 · 3 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
-1
```

3 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_RANGE
```

10 bytes · 包含程式實際輸出的換行與空白

錯誤分支的非零結束碼也屬預期結果，不代表測試失敗。測試器僅正規化 CRLF 為 LF，其餘空白需保持一致。

05

## 易錯提醒與檢查重點

- 沒有執行原本可能不停止的unsigned i>=0迴圈。

教學輸入契約：數值 token 須可由程式的讀取型別表示；這些範例不是用來解析任意長數字或所有惡意輸入。詳細限制見[共通輸入與測試規則](#guide)。

[← S17 typedef、sizeof 與精確寬度型別](#S17)[S19 修正空本體與閉區間接受條件 →](#S19)

S19語法補充完整化綜合實作C11


<a id="toc-ch5-35"></a>

# 修正空本體與閉區間接受條件

除錯空本體閉區間

**對應整合版：**第 93 頁　·　1 份程式　·　5 組測試
**來源對照：**整合版 p.93（原題／語意依投影片及備忘錄）
原投影片主要是語法片段／觀念示例；本 HTML 新增明確輸入輸出、main、必要標頭與測試。刻意保留錯誤行為的地方均另行說明，不把可能無限迴圈或未定義行為當成固定輸出。

[01 完整題目](#S19/problem)[02 解題說明](#S19/solution)[03 完整程式](#S19/code)[04 測試資料](#S19/tests)[05 易錯提醒](#S19/tips)

01

## 完整題目

先確認規格，再寫程式

將第93頁兩個除錯片段補成完整程式：先判斷score是否落在0～100（含端點），再由i=0遞增到3並逐次印出。

### 輸入規格

一個整數score，-1000～1000；其中只有0～100屬可接受成績。

### 輸出規格

印ACCEPT或REJECT；再印Step: 1、Step: 2、Step: 3與Final: 3。

### 規則與限制

- 接受判斷使用score>=0 && score<=100。
- 移除while後多餘分號，i++確實位於迴圈本體。
- 拒絕成績REJECT為正常分類，不是程式錯誤，仍執行迴圈。
- 第一行分類與其後四行迴圈輸出分開；score在允許輸入範圍內但不屬0～100時，輸出REJECT仍正常結束。
- 共同錯誤處理：讀取數值失敗印ERR\_INPUT；數值可讀取但超出本題輸入範圍印ERR\_RANGE，皆以結束碼1停止。正常完成以0結束；每一行輸出均以換行結尾。

### 輸入／輸出範例

STDIN · 範例輸入

```
150
```

4 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
REJECT
Step: 1
Step: 2
Step: 3
Final: 3
```

40 bytes · 包含程式實際輸出的換行與空白

輸入區不包含提示文字。下載後可直接作為標準輸入檔；檔案結束代表 EOF，不需輸入「EOF」三個字母。

目前為自學模式：完整題目與測試輸入仍可閱讀。按上方「顯示解答」即可查看解法、程式與預期輸出。這是閱讀遮蔽功能，不是考試保密機制。

02

## 解題說明

理解狀態如何改變

**STEP 01**用兩個比較合併閉區間。

**STEP 02**刪除while後的空敘述。

**STEP 03**本體每次確實增加i。

### 核心思考與步驟

1. 用兩個比較合併閉區間。
2. 刪除while後的空敘述。
3. 本體每次確實增加i。

### 固定範例追蹤

全表

這是依指定範例整理的狀態表；切換步驟只改變標記，不是在瀏覽器中編譯或執行 C。

| i初值 | 本體後i | 是否續做 |
| --- | --- | --- |
| 0 | 1 | 是 |
| 1 | 2 | 是 |
| 2 | 3 | 否 |

### 為什麼這個解法成立？

迴圈每次減少距離終止條件的差距1；三次後i=3，條件為假。

本題資料規模已限制；重點為所示控制流程與型別行為。

03

## 完整程式碼

每一份都可獨立編譯

s19\_repair\_basics.c

補齊後的完整程式 · 14 行 · 長行可橫向捲動

```
#include <stdio.h>
int main(void) {
    int score, i = 0;
    if (scanf("%d", &score) != 1) { puts("ERR_INPUT"); return 1; }
    if (score < -1000 || score > 1000) { puts("ERR_RANGE"); return 1; }
    if (score >= 0 && score <= 100) puts("ACCEPT");
    else puts("REJECT");
    while (i < 3) {
        i++;
        printf("Step: %d\n", i);
    }
    printf("Final: %d\n", i);
    return 0;
}
```

單題編譯（在包含本檔的資料夾執行）：`gcc -std=c11 -Wall -Wextra -Wpedantic s19_repair_basics.c -o s19_repair_basics`

完整測試方式與 Windows cmd.exe 操作範例請見[使用與驗證說明](#guide)。此頁為離線教材，不提供任意 C 程式的網頁執行環境。

04


## 測試資料

5 組完整資料

核對輸出、結束碼與 stderr。全部輸入／輸出已內嵌，可個別下載。

列印版僅列測試目的與結束碼；完整輸入與輸出請使用 HTML 展開或下載檔案，避免上限測試產生數千行列印內容。

S19-T01**原題要求的score=150**本 HTML 新增測試 · 4 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
150
```

4 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
REJECT
Step: 1
Step: 2
Step: 3
Final: 3
```

40 bytes · 包含程式實際輸出的換行與空白

S19-T02**含下界**本 HTML 新增測試 · 2 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
0
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ACCEPT
Step: 1
Step: 2
Step: 3
Final: 3
```

40 bytes · 包含程式實際輸出的換行與空白

S19-T03**含上界**本 HTML 新增測試 · 4 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
100
```

4 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ACCEPT
Step: 1
Step: 2
Step: 3
Final: 3
```

40 bytes · 包含程式實際輸出的換行與空白

S19-T04**界外**本 HTML 新增測試 · 3 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
-1
```

3 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
REJECT
Step: 1
Step: 2
Step: 3
Final: 3
```

40 bytes · 包含程式實際輸出的換行與空白

S19-T05**讀取失敗**本 HTML 新增測試 · 2 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
x
```

2 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_INPUT
```

10 bytes · 包含程式實際輸出的換行與空白

錯誤分支的非零結束碼也屬預期結果，不代表測試失敗。測試器僅正規化 CRLF 為 LF，其餘空白需保持一致。

05

## 易錯提醒與檢查重點

- 原始錯誤片段保留在解題描述中，不放進可執行路徑。

教學輸入契約：數值 token 須可由程式的讀取型別表示；這些範例不是用來解析任意長數字或所有惡意輸入。詳細限制見[共通輸入與測試規則](#guide)。

[← S18 安全的 unsigned 倒數](#S18)[S20 單行訊息長度：原 length.c 的完整化 →](#S20)

S20語法補充完整化基本型別C11


<a id="toc-ch5-36"></a>

# 單行訊息長度：原 length.c 的完整化

getchar長度EOF

**對應整合版：**第 74、76、77 頁　·　1 份程式　·　5 組測試
**來源對照：**整合版 p.74,76,77（原題／語意依投影片及備忘錄）；另參照原 Chapter 7 Basic Types.pptx 第71–73頁的 length.c。
原投影片主要是語法片段／觀念示例；本 HTML 新增明確輸入輸出、main、必要標頭與測試。刻意保留錯誤行為的地方均另行說明，不把可能無限迴圈或未定義行為當成固定輸出。

[01 完整題目](#S20/problem)[02 解題說明](#S20/solution)[03 完整程式](#S20/code)[04 測試資料](#S20/tests)[05 易錯提醒](#S20/tips)

01

## 完整題目

先確認規格，再寫程式

只計算一行訊息長度，包含空白與標點，不包含結尾換行。此題將原Ch7 length.c / length2.c的核心功能獨立保留，與C14的分類統計區分。

### 輸入規格

一行ASCII文字，最多4096 bytes；換行或EOF結束。

### 輸出規格

輸出Your message was N character(s) long.；超長印ERR\_LIMIT。

### 規則與限制

- 使用int接getchar，加入原片段未完整處理的EOF與串流錯誤分支。
- 不加入互動提示，讓標準輸入輸出可用檔案直接測試。
- 不使用字串陣列，且本題不是UTF-8字數統計。
- 長度0的空行或空檔都正常輸出0並以0結束；一旦讀到第4097個非換行byte就只印ERR\_LIMIT並以1結束。串流讀取失敗則印ERR\_INPUT並以1結束。

### 輸入／輸出範例

STDIN · 範例輸入

```
Brevity is the soul of wit.
```

28 bytes · 最後有 LF 換行

STDOUT · 範例輸出

```
Your message was 27 character(s) long.
```

39 bytes · 包含程式實際輸出的換行與空白

輸入區不包含提示文字。下載後可直接作為標準輸入檔；檔案結束代表 EOF，不需輸入「EOF」三個字母。

目前為自學模式：完整題目與測試輸入仍可閱讀。按上方「顯示解答」即可查看解法、程式與預期輸出。這是閱讀遮蔽功能，不是考試保密機制。

02

## 解題說明

理解狀態如何改變

**STEP 01**逐byte讀入。

**STEP 02**在換行或EOF時停止。

**STEP 03**成功讀入非換行值才累加。

### 核心思考與步驟

1. 逐byte讀入。
2. 在換行或EOF時停止。
3. 成功讀入非換行值才累加。

### 固定範例追蹤

全表

這是依指定範例整理的狀態表；切換步驟只改變標記，不是在瀏覽器中編譯或執行 C。

| 輸入 | 累計長度 |
| --- | --- |
| H | 1 |
| i | 2 |
| ! | 3 |
| EOF | 不再增加 |

### 為什麼這個解法成立？

讀取一次只增加一次計數，且停止記號不計入長度。

本題資料規模已限制；重點為所示控制流程與型別行為。

03

## 完整程式碼

每一份都可獨立編譯

s20\_message\_length.c

補齊後的完整程式 · 12 行 · 長行可橫向捲動

```
#include <stdio.h>
int main(void) {
    int ch;
    size_t len = 0;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (len == 4096) { puts("ERR_LIMIT"); return 1; }
        len++;
    }
    if (ferror(stdin)) { puts("ERR_INPUT"); return 1; }
    printf("Your message was %zu character(s) long.\n", len);
    return 0;
}
```

單題編譯（在包含本檔的資料夾執行）：`gcc -std=c11 -Wall -Wextra -Wpedantic s20_message_length.c -o s20_message_length`

完整測試方式與 Windows cmd.exe 操作範例請見[使用與驗證說明](#guide)。此頁為離線教材，不提供任意 C 程式的網頁執行環境。

04


## 測試資料

5 組完整資料

核對輸出、結束碼與 stderr。全部輸入／輸出已內嵌，可個別下載。

列印版僅列測試目的與結束碼；完整輸入與輸出請使用 HTML 展開或下載檔案，避免上限測試產生數千行列印內容。

S20-T01**原教材示範句**本 HTML 新增測試 · 28 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
Brevity is the soul of wit.
```

28 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Your message was 27 character(s) long.
```

39 bytes · 包含程式實際輸出的換行與空白

S20-T02**空行**本 HTML 新增測試 · 1 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```

```

1 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
Your message was 0 character(s) long.
```

38 bytes · 包含程式實際輸出的換行與空白

S20-T03**空檔EOF**本 HTML 新增測試 · 0 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
（空輸入檔，直接 EOF）
```

0 bytes · 0 bytes，不是空白行

STDOUT · 完整預期輸出

```
Your message was 0 character(s) long.
```

38 bytes · 包含程式實際輸出的換行與空白

S20-T04**沒有結尾換行**本 HTML 新增測試 · 3 input bytes · 完整比對exit 0 ✓

GCC / Clang / UBSan 通過結束碼 0；stderr 應為空

STDIN · 完整輸入

```
Hi!
```

3 bytes · 最後沒有換行，檔案直接結束

STDOUT · 完整預期輸出

```
Your message was 3 character(s) long.
```

38 bytes · 包含程式實際輸出的換行與空白

S20-T05**超過長度上限**本 HTML 新增測試 · 4,098 input bytes · 完整比對exit 1 ✓

GCC / Clang / UBSan 通過結束碼 1；stderr 應為空

STDIN · 完整輸入

```
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
```

4,098 bytes · 最後有 LF 換行

STDOUT · 完整預期輸出

```
ERR_LIMIT
```

10 bytes · 包含程式實際輸出的換行與空白

錯誤分支的非零結束碼也屬預期結果，不代表測試失敗。測試器僅正規化 CRLF 為 LF，其餘空白需保持一致。

05

## 易錯提醒與檢查重點

- 本HTML將原題的char接getchar改成int並補EOF防護，屬明示補強；不是逐字照抄原碼。

教學輸入契約：數值 token 須可由程式的讀取型別表示；這些範例不是用來解析任意長數字或所有惡意輸入。詳細限制見[共通輸入與測試規則](#guide)。

[← S19 修正空本體與閉區間接受條件](#S19)[回到全部主題 →](#overview)

HOW TO USE / VALIDATION

# 使用與驗證說明

先閱讀題目，再編譯單一程式，最後以同一份測試輸入核對結果。

## 這份 HTML 包含什麼？

共有 **16 個正式案例 + 20 個語法補充**，共 36 個主題、37 份可獨立執行的 C 程式，以及 262 組具體測試資料。C06 的 7 組資料分別測試 while 與 for，因此每輪執行 269 項「程式 × 資料」測試。

左側目錄與關鍵字搜尋可直接查找題目、語法、變數或程式片段。**「隱藏解答」只提供自學遮蔽**；完整解答仍在 HTML 中，不是保密考試頁面。即使完全離線，程式、輸入檔、預期輸出與整包 ZIP 均可下載。

頁面的「下一步」是固定範例追蹤表的逐列標記，不會執行 C 程式。真正的編譯與執行須在有 GCC／Clang 的電腦完成。

### 資料來源與新增範圍

C01–C16 沿用原教學資源包的完整題目與 17 份程式，已逐位元組比對相同；另外補充變數表、逐步追蹤、解題理由與測試。S01–S20 將投影片的語法片段／除錯練習補成明確題目及完整 main，均標為「語法補充」，不冒充原投影片本來就有的完整案例。

對應來源為 `C_Programming_Ch5-7_M365_Compatible.pptx`（101頁）及原資源包。S08 另參照原 Chapter 6 的 square3.c，S20 另參照原 Chapter 7 的 length.c。完整對照見[來源索引](#sources)。

## 單題編譯與執行

下載整包並解壓縮。每個 `.c` 都含自己的 main；**不可將全部程式一起連結成一個可執行檔**。以下假設目前位置為解壓縮後的資料夾。

### Linux／macOS shell

```
gcc -std=c11 -Wall -Wextra -Wpedantic examples/c01_grade.c -o grade
./grade < tests/data/C01/C01-T01.in.txt
echo $?
```

### Windows 命令提示字元（cmd.exe）

```
gcc -std=c11 -Wall -Wextra -Wpedantic examples/c01_grade.c -o grade.exe
grade.exe < tests/data/C01/C01-T01.in.txt
echo %ERRORLEVEL%
```

Windows 命令供使用參考，本次未在 Windows 實測；上列 < 重導向寫法是 cmd.exe，不是 PowerShell 命令。需先具備編譯器；HTML 本身不會安裝工具。

### 使用自動測試器

```
python tests/run_tests.py --compiler gcc --report tests/local_gcc_report.json
python tests/run_tests.py --compiler clang --report tests/local_clang_report.json
python tests/run_tests.py --compiler gcc --sanitize --report tests/local_ubsan_report.json
```

測試器使用 Python 3.9 以上標準函式庫，不需額外 Python 套件。以暫存資料夾放編譯結果；不覆蓋教材程式或既有報告。`--sanitize` 需要編譯器提供對應支援。

S17 刻意使用 `sizeof(i++)` 展示未求值運算式，Clang 會發出教學上預期的警告。僅在該題加上 `-Wno-error=unevaluated-expression`，其餘警告仍依 `-Werror` 視為錯誤；完整警告保留於報告。

## 完整測試結果與判準

| 實測工具 | 程式編譯 | 程式×資料測試 | 說明 |
| --- | --- | --- | --- |
| gcc | 37 / 37 | 269 / 269 | 本輪未發現測試失敗 |
| Clang 17.0.0 | 37 / 37 | 269 / 269 | S17保留1項教學警告 |
| GCC 14.2 + UBSan | 37 / 37 | 269 / 269 | 本輪未發現測試失敗 |

三輪合計 807 次成功執行。以上是在本次 Linux x86-64 環境實際執行的結果；不是對所有輸入的形式證明，也不是 Windows、MSVC 或 Microsoft Office 相容性實測。

### 一般題目：精確比對

核對 **stdout 完整內容、結束碼及空 stderr**。只將 CRLF 正規化成 LF，其餘空白、換行與標點都保留。遇到 ERR\_\* 的題目，只要輸出和指定的結束碼相符，仍是成功通過錯誤分支測試。

### 平台觀察：不把某台電腦的數字當作唯一答案

C12、S12、S14、S17 的部分測試採明確的欄位／關係判準。HTML 仍提供本次**完整觀察輸出**，資料檔名使用 `.observed-linux-gcc.out.txt`，不冒充跨平台固定預期輸出。S14 的浮點容許差是本測試選擇的門檻，並非語言對所有浮點實作的普遍保證。

### 空檔、空行、EOF 不一樣

0 bytes 的輸入檔會直接遇到 EOF。只含 `\n` 的檔案是一個空白行。EOF 是串流結束狀態，不是輸入字串「EOF」。「顯示跳脫字元」可辨認空白、tab 與最後的換行；下載保留的是原始資料，不是畫面上顯示的 JSON 跳脫寫法。

### 大型上限資料

1000筆、10000次等上限測試均提供**完整檔案內容**，沒有以省略符取代資料。HTML 中可在資料框內捲動或直接下載。列印時僅列出各測試目的與結束碼，完整輸入輸出以 HTML／下載檔案為準。

## 共通輸入契約與限制

以 C11 模式編譯，教學主題主要對應第5–7章的 C99 內容。數值 token 假定可以由 scanf 對應的型別表示；範圍檢查不等於任意長數字的安全解析。程式也未一律拒絕已讀取數值後的所有額外字元；各題的停止條件與輸出規則以題目為準。

文字題以 **ASCII byte** 為規格，不是 UTF-8 中文字數計算。測試採預設 C locale，平台型別大小與浮點末位可能不同。手續費為教材假設，整數分帳本為教學實作，不是實際金融服務。

錯誤片段可能造成無限迴圈或未定義行為時，不直接把它當成可重現固定輸出的程式來執行；補充題會明示改寫方式，保留需要理解的語意差異。

SOURCE MAP / CONTENT INTEGRITY

# 來源與案例索引

頁碼指最新可編輯整合版，不是原始三份 PPTX 的頁碼。

主來源：`C_Programming_Ch5-7_M365_Compatible.pptx`；案例題目與17份原程式來自 `C_Programming_Ch5-7_Resources.zip`。本 HTML 以這些教材為依據整理，沒有將外部網路查詢混入來源內容。

**保留與補充分開呈現。** C01–C16 的原程式逐位元組相同。新增的20題、解題追蹤及測試均清楚標示。平台量測題補上本次完整觀察值，而不是將省略號當成可執行答案。

| 編號 | 題目 | 整合版頁次 | 內容定位 | 程式檔名 |
| --- | --- | --- | --- | --- |
| C01 | 成績等第判定 | 10–12 | 正式案例／原程式保留 | c01\_grade.c |
| C02 | 分段手續費計算 | 13–16 | 正式案例／原程式保留 | c02\_commission.c |
| C03 | 四則計算器 | 20–22 | 正式案例／原程式保留 | c03\_calculator.c |
| C04 | 英文日期格式化 | 23–26 | 正式案例／原程式保留 | c04\_date.c |
| C05 | 找出足夠大的 2 次方容量 | 30–32 | 正式案例／原程式保留 | c05\_power2.c |
| C06 | 平方表：while 與 for 雙版本 | 33–36 | 正式案例／原程式保留 | c06\_squares\_while.c, c06\_squares\_for.c |
| C07 | 以 0 結束的數列加總 | 38–40 | 正式案例／原程式保留 | c07\_sum.c |
| C08 | 計算十進位位數 | 41–43 | 正式案例／原程式保留 | c08\_digits.c |
| C09 | 質數判定與提早停止 | 45–47 | 正式案例／原程式保留 | c09\_prime.c |
| C10 | 座位編號產生器 | 48–50 | 正式案例／原程式保留 | c10\_seats.c |
| C11 | 距離感測資料清理 | 51–53 | 正式案例／原程式保留 | c11\_sensor.c |
| C12 | 量測目前環境的型別 | 63–65 | 正式案例／原程式保留 | c12\_type\_lab.c |
| C13 | RGB 影片的記憶體估算 | 71–73 | 正式案例／原程式保留 | c13\_rgb\_memory.c |
| C14 | 一行文字的分類統計 | 76–79 | 正式案例／原程式保留 | c14\_text\_stats.c |
| C15 | 互動式零用金帳本 | 83–87 | 正式案例／原程式保留 | c15\_ledger.c |
| C16 | 班級成績統計器 | 88–92 | 正式案例／原程式保留 | c16\_score\_stats.c |
| S01 | 比較、連鎖不等式與否定的解析 | 6、9、28、93 | 語法片段／HTML補齊 | s01\_comparison.c |
| S02 | 短路求值與被略過的自增 | 7、28 | 語法片段／HTML補齊 | s02\_short\_circuit.c |
| S03 | 大括號與 else 配對 | 8–9 | 語法片段／HTML補齊 | s03\_dangling\_else.c |
| S04 | bool、條件運算子與獨立 if | 9、17、28 | 語法片段／HTML補齊 | s04\_bool\_ternary.c |
| S05 | switch 分派、共用標籤與 fall-through | 18–19 | 語法片段／HTML補齊 | s05\_switch\_paths.c |
| S06 | 邏輯 AND 與低8位元運算 | 27 | 語法片段／HTML補齊 | s06\_bitwise.c |
| S07 | 計數端點、逗號運算子與多變數更新 | 37 | 語法片段／HTML補齊 | s07\_count\_comma.c |
| S08 | 不用乘法的奇數累加平方表 | 33、34、37 | 語法片段／HTML補齊 | s08\_square\_odd.c |
| S09 | while、do、for 與 continue 的執行次數 | 29、44、55 | 語法片段／HTML補齊 | s09\_loop\_counts.c |
| S10 | 有意的空本體與讀到行尾 | 54 | 語法片段／HTML補齊 | s10\_empty\_loop.c |
| S11 | 整數常數進位與輸入輸出格式 | 59、62 | 語法片段／HTML補齊 | s11\_integer\_io.c |
| S12 | unsigned 回繞、整數提升與混合比較 | 60、69 | 語法片段／HTML補齊 | s12\_unsigned\_rules.c |
| S13 | 先轉型再除法：平均值與零筆資料 | 70、81、93 | 語法片段／HTML補齊 | s13\_cast\_mean.c |
| S14 | float、double、long double 的 I/O 與精度觀察 | 66–68 | 語法片段／HTML補齊 | s14\_floating\_io.c |
| S15 | 字元、跳脫字元與 toupper | 74、76、77 | 語法片段／HTML補齊 | s15\_char\_escape.c |
| S16 | scanf 後殘留的換行與下一個命令 | 75 | 語法片段／HTML補齊 | s16\_input\_buffer.c |
| S17 | typedef、sizeof 與精確寬度型別 | 80 | 語法片段／HTML補齊 | s17\_typedef\_sizeof.c |
| S18 | 安全的 unsigned 倒數 | 93 | 語法片段／HTML補齊 | s18\_reverse\_unsigned.c |
| S19 | 修正空本體與閉區間接受條件 | 93 | 語法片段／HTML補齊 | s19\_repair\_basics.c |
| S20 | 單行訊息長度：原 length.c 的完整化 | 74、76、77 | 語法片段／HTML補齊 | s20\_message\_length.c |

S08：原 Chapter 6 Loops.pptx 第45–46頁，奇數累加平方表。S20：原 Chapter 7 Basic Types.pptx 第71–73頁，訊息長度。各題另列其完整化時新增的輸入限制或 EOF 處理。

### 原17份程式的內容比對

已將原資源包 examples/ 內17個檔案，與本次提供的C01–C16所有程式逐位元組比對，結果全部一致。詳細 SHA-256 與結果列在 ZIP 的 `source_integrity.json`。

[閱讀使用說明 →](#guide)

C Programming · Chapters 5–7　｜　離線HTML案例手冊　｜　來源：整合版投影片與既有教學資源包
完整題目優先；新補充與原教材分開標示。測試通過不代表已證明所有可能輸入均正確。

---


<a id="toc-chapter-ch8"></a>

# CH8、CH22、CH24：完整範例互動教材

來源：`CH8_22_24_完整程式碼與解題說明.html`

內嵌資料：138 頁投影片講義、15 個案例、154 組測試。

本節由 HTML 內嵌教材資料整理，保留投影片講義、案例說明、完整程式與測試資料。

---


<a id="toc-slides"></a>

## 教學講義（依原投影片頁序）

---

### 投影片第 1 頁｜陣列、檔案 I/O 與錯誤處理

【本頁目標】
陣列、檔案 I/O 與錯誤處理
把三章串成一條可執行、可測試的資料處理流程

【教師講解】
本教材以三份原稿共 245 頁為基礎，重排成陣列、檔案輸入輸出、錯誤處理與整合專題。保留原稿概念與主要案例；新增的規格、測試、圖解及勘誤均有標籤。先用四筆成績的資料流說明：輸入要驗證，陣列要有邊界，統計要符合題意，報表要確認寫入成功。

【課堂提問】
一個程式印出正確平均值，是否就代表整個系統正確？

【參考答案】
未必。還需要確認輸入是否合法、陣列未越界、報表確實寫入且失敗時不毀損既有資料。

【來源與增補】
A 64頁 + B 172頁 + C 9頁
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 2 頁｜課程地圖｜從儲存資料到可靠輸出

【本頁目標】
課程地圖｜從儲存資料到可靠輸出
15 個完整案例，16 支獨立 C 程式；每題先規格、後解法。

【教師講解】
依陣列、I/O、錯誤處理、整合專題順序授課。每個單元以一個具體能力作結，而不是要求學生背函式名稱。案例 10 提供同一題目的逐字元版與區塊版，因此程式檔比題目多一支。可依課程進度拆成多次授課，但完整題目頁應保留在解答之前。

【課堂提問】
案例 10 為何需要兩個版本？

【參考答案】
在同一輸入、輸出和錯誤處理契約下，比較資料搬移單位的差異，避免把最佳化誤當成變更題意。

【來源與增補】
A+B+C
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 3 頁｜導讀｜先分清楚三種教材內容

【本頁目標】
導讀｜先分清楚三種教材內容
主案例採 C17；原稿中的 C99 特性會另外指出。

【教師講解】
提醒學生：檢查 scanf 的回傳值是必要條件，卻不能把不受信任的任意長數字安全轉成 int。為降低初學陣列時的負擔，前七題把「可由型別表示」寫成測試資料前提；到了錯誤處理單元再解除這個限制，改用 fgets 加 strtol。程式碼小片段只用於解釋語法，完整案例另有獨立 .c 檔。

【本頁收斂】
案例固定順序：完整題目 → 核心解法／圖解 → 完整程式 → 測試。

【課堂提問】
為何看到 scanf 回傳 1 仍不應宣稱能處理任意外部輸入？

【參考答案】
數值轉換是否可由目標型別表示也是問題；需要可控錯誤回報時，應使用整行讀取加 strtol 與完整驗證。

【來源與增補】
A+B+C｜新增導讀
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 4 頁｜01｜陣列：同型別、多筆值、連續元素

【本頁目標】
01｜陣列：同型別、多筆值、連續元素
一個陣列名稱管理多筆資料；索引決定要存取哪一筆。

【教師講解】
從單一 scalar 變數與 aggregate 變數的差異切入。陣列元素型別相同，元素之間依序配置；圖上的位址假設每個 int 為 4 bytes，只是用來解釋位移，不是所有平台保證。元素 a[i] 本身可作為左值讀寫，但整個陣列不是可直接互相指定的普通 scalar。

【本頁收斂】
元素位置：base + i × sizeof(a[0])；型別大小以實作為準。

【課堂提問】
int a[5] 的最後一個元素是哪個？

【參考答案】
a[4]。長度是 5，但合法索引從 0 到 4。

【來源與增補】
A pp.2–7
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 5 頁｜索引與走訪｜邊界是程式的責任

【本頁目標】
索引與走訪｜邊界是程式的責任
C 不保證替你檢查陣列索引；越界存取是未定義行為。

【教師講解】
對照 i<N 與 i<=N。示意圖把 a[N] 畫在陣列之外，強調不是某個可依賴的額外元素。越界可能看似正常、破壞其他資料或中止，不應用某次編譯結果當成標準答案。讀入資料前先確認有效筆數，走訪時再維持索引範圍。

【本頁收斂】
合法範圍永遠是 0 ≤ i < N；先驗證，再索引。

【課堂提問】
為何不能把越界程式執行一次後，記住得到的輸出？

【參考答案】
因為未定義行為沒有可攜的結果保證；編譯最佳化、資料配置或平台不同都可能改變行為。

【來源與增補】
A pp.8–11
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 6 頁｜初始化｜省略的元素補零，不等於所有陣列自動歸零

【本頁目標】
初始化｜省略的元素補零，不等於所有陣列自動歸零
區分「有初始列」、「沒有初始列」與儲存期。

【教師講解】
原稿 p.16 提到空初始列合法，與本教材 C17 基準不合；明確標示修正而非悄悄更換。把有初始列但長度不足的零填補，和沒有初始列的區域陣列區分開。不同儲存期有不同規則，所以不要讓學生形成「大括號可有可無」的錯覺。

【表格帶讀】
宣告／片段｜有效內容或意義｜要注意什麼
int a[6] = {1, 2};｜1 2 0 0 0 0｜有初始列但未指定的元素補零
int a[6] = {0};｜全部元素為 0｜C17 可攜的全零寫法
int a[] = {1, 2, 3};｜長度由初始列推得為 3｜宣告時可省略第一維長度
區域 int a[6];｜未初始化；不可假設全為 0｜使用前逐項賦值
static int a[6];｜靜態儲存期，初值全為 0｜規則來自儲存期
int a[6] = {};｜本教材 C17 不採用｜原稿 p.16 的空初始列敘述需勘誤

【課堂提問】
int a[6]={1,2} 中，a[5] 是不確定值嗎？

【參考答案】
不是，因為有初始列；未指定的其餘元素初始化為零。

【來源與增補】
A pp.14–17｜W1 §6.7.9
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。
【外部校核來源】
W1 — https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf （C11 委員會草案，引用與 C17 共通的核心條款）
W2 — https://learn.microsoft.com/en-us/cpp/overview/install-c17-support?view=msvc-170
W3 — https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/fopen-wfopen?view=msvc-170
W4 — https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/strtol-wcstol-strtol-l-wcstol-l?view=msvc-170

---

### 投影片第 7 頁｜指定初始化｜直接指定索引，建立稀疏表

【本頁目標】
指定初始化｜直接指定索引，建立稀疏表
C99 designated initializer：位置清楚，比長串 0 更容易維護。

【教師講解】
先展示 a[15] 中只有三個位置非零的例子，再展開混合初始化 c[10]。學生最常忽略指定索引後，一般值會接續從下一個位置開始。索引必須是整數常數運算式；const 查表則用於提醒此資料在程式中不應被修改。

【本頁收斂】
不要用大量看不出位置的 0；在語意重要的位置標明索引。

【課堂提問】
int c[10]={5,1,9,[4]=3,7,2,[8]=6}; 的 c[5] 是多少？

【參考答案】
7。指定 [4]=3 後，接著的一般初始值從索引 5 開始。

【來源與增補】
A pp.18–22,46–48
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 8 頁｜sizeof 與 size_t｜知道容量，也要知道適用範圍

【本頁目標】
sizeof 與 size_t｜知道容量，也要知道適用範圍
sizeof 陣列 / sizeof 元素，必須在「真正的陣列」上使用。

【教師講解】
以五元素 int 陣列示範 20/4=5，但數字 4 是圖解假設。C 使用 size_t，不是原稿截圖中的 C++ std::size_t。陣列作為函式參數時會調整成指標，此時 sizeof a 是指標大小；介面應另外傳入有效長度。size_t 是無號型別，倒數迴圈要避免 i>=0 永遠成立。

【本頁收斂】
用 size_t 搭配 %zu；長度與容量應成為函式契約的一部分。

【課堂提問】
void f(int a[]) 裡可以用 sizeof a/sizeof a[0] 算出呼叫端長度嗎？

【參考答案】
不行。參數 a 已是指標；必須由呼叫端另外傳入長度。

【來源與增補】
A pp.26–30｜W1 §6.5.3.4
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。
【外部校核來源】
W1 — https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf （C11 委員會草案，引用與 C17 共通的核心條款）
W2 — https://learn.microsoft.com/en-us/cpp/overview/install-c17-support?view=msvc-170
W3 — https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/fopen-wfopen?view=msvc-170
W4 — https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/strtol-wcstol-strtol-l-wcstol-l?view=msvc-170

---

### 投影片第 9 頁｜副作用｜把索引更新與資料存取拆開

【本頁目標】
副作用｜把索引更新與資料存取拆開
a[i++] = 0 與 a[i] = b[i++] 不是同一種風險。

【教師講解】
前一式只在該位置使用舊 i，之後更新 i，適當邊界下可使用。後一式同時讀 i 作左側索引又在右側修改 i，C17 下沒有需要的定序，屬未定義行為。不要引導學生猜左邊或右邊先算；用分開敘述或 for 迴圈明確安排順序。

【本頁收斂】
可讀的寫法也比較容易驗證：a[i] = b[i]; 然後再 ++i。

【課堂提問】
能不能用「賦值由右向左」證明 a[i]=b[i++] 正確？

【參考答案】
不能。運算子結合性不等於運算元求值順序；該式在 C17 下不具所需定序。

【來源與增補】
A pp.10–11｜W1 §6.5
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。
【外部校核來源】
W1 — https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf （C11 委員會草案，引用與 C17 共通的核心條款）
W2 — https://learn.microsoft.com/en-us/cpp/overview/install-c17-support?view=msvc-170
W3 — https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/fopen-wfopen?view=msvc-170
W4 — https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/strtol-wcstol-strtol-l-wcstol-l?view=msvc-170

---

### 投影片第 10 頁｜案例 01｜反向輸出 10 筆量測值

【本頁目標】
案例 01｜反向輸出 10 筆量測值
完整題目：先確認任務、輸入、輸出與限制

【教師講解】
先不要展示解答。請學生用自己的話重述任務，再指出輸入格式、輸出格式與無效資料的處理。依序讀入 10 筆整數量測值，保留原本儲存順序，再由最後一筆往前輸出。不得把題目改成排序。 每筆介於 −10000～10000；缺項、非數字或超出範圍即失敗。入門數值文字約定見導讀頁。

【完整規格】
任務：依序讀入 10 筆整數量測值，保留原本儲存順序，再由最後一筆往前輸出。不得把題目改成排序。
輸入：標準輸入：恰好 10 個整數，以空白或換行分隔。
輸出：由第 10 筆到第 1 筆輸出；數字間一個空白，最後換行。
限制：每筆介於 −10000～10000；缺項、非數字或超出範圍即失敗。入門數值文字約定見導讀頁。
範例輸入：
34 82 49 102 7 94 23 11 50 31
範例輸出：
31 50 11 23 94 7 102 49 82 34

【課堂提問】
為何輸出迴圈讀 a[i−1]，而不是 a[i]？

【參考答案】
i 由元素數量 10 開始；先減 1 才對應最後有效索引 9。i>0 也避免 unsigned 倒數下溢。

【來源與增補】
A pp.12–13
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 11 頁｜案例 01｜核心解法與圖解

【本頁目標】
案例 01｜核心解法與圖解
反向輸出 10 筆量測值

【教師講解】
依下列順序帶讀圖解：1. 先以正向迴圈填入 a[0]～a[9]。 2. 第二個迴圈從 i=10 遞減，讀取 a[i−1]。 3. 只改變輸出順序，不交換陣列元素。 錯誤的起點 a[10] 已越界；最後有效索引是 9。此題不是就地反轉。

【課堂提問】
為何輸出迴圈讀 a[i−1]，而不是 a[i]？

【參考答案】
i 由元素數量 10 開始；先減 1 才對應最後有效索引 9。i>0 也避免 unsigned 倒數下溢。

【來源與增補】
A pp.12–13
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 12 頁｜案例 01｜完整程式 1/1

【本頁目標】
案例 01｜完整程式 1/1
01_reverse.c

【教師講解】
本頁為 01_reverse.c 的第 1/1 段，對應原始檔第 1～17 行。所有程式頁依序接續，沒有省略程式碼。建立固定長度陣列，逐筆檢查 scanf 回傳值及範圍。讀入全部成功後才由 i=N 向下讀 a[i-1]；這只是反向輸出，沒有修改原陣列次序。

【程式帶讀】
對應 01_reverse.c，原始碼第 1～17 行。這是完整檔案第 1/1 段，依頁序合併即可，不需補寫省略片段。提醒學生先讀題目頁的輸入資料前提；程式使用的語法片段與整體錯誤契約應一起理解。

#include <stdio.h>
#include <stdlib.h>
#define N 10

int main(void) {
    int a[N];
    for (int i = 0; i < N; ++i) {
        if (scanf("%d", &a[i]) != 1 ||
            a[i] < -10000 || a[i] > 10000) {
            fputs("Invalid integer input\n", stderr);
            return EXIT_FAILURE;
        }
    }
    for (int i = N; i > 0; --i)
        printf("%d%c", a[i - 1], i == 1 ? '\n' : ' ');
    return EXIT_SUCCESS;
}

【課堂提問】
為何輸出迴圈讀 a[i−1]，而不是 a[i]？

【參考答案】
i 由元素數量 10 開始；先減 1 才對應最後有效索引 9。i>0 也避免 unsigned 倒數下溢。

【來源與增補】
A pp.12–13
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 13 頁｜案例 01｜測試與常見錯誤

【本頁目標】
案例 01｜測試與常見錯誤
先預測結果，再執行；不只測一般資料。

【教師講解】
依表格逐組測試，確認返回狀態、stdout、stderr 與檔案內容。錯誤的起點 a[10] 已越界；最後有效索引是 9。此題不是就地反轉。 對隨機或平台相依輸出，應測試性質，而不是把單一次執行結果當成唯一答案。

【測試判讀】
正常｜10 筆題目資料｜31 50 … 82 34｜確認前後次序
邊界｜含負值與 0｜全部正確反向｜不是數值排序
缺項｜1 2 後結束輸入｜失敗；stderr 訊息｜不可讀未初始化值
格式錯誤｜1 2 x｜失敗；stderr 訊息｜檢查 scanf 回傳
本頁列出教學代表測試。附件測試器另外包含一般值、邊界與錯誤路徑；未模擬磁碟滿載、斷電、併發或所有作業系統。

【課堂提問】
為何輸出迴圈讀 a[i−1]，而不是 a[i]？

【參考答案】
i 由元素數量 10 開始；先減 1 才對應最後有效索引 9。i>0 也避免 unsigned 倒數下溢。

【來源與增補】
A pp.12–13
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 14 頁｜案例 02｜用布林陣列偵測重複數字

【本頁目標】
案例 02｜用布林陣列偵測重複數字
完整題目：先確認任務、輸入、輸出與限制

【教師講解】
先不要展示解答。請學生用自己的話重述任務，再指出輸入格式、輸出格式與無效資料的處理。讀入一個非負整數，從個位數往高位數檢查，找出第一個「再次出現」的數字；完全沒有重複則明確回報。 0 ≤ n ≤ 2147483647。n=0 視為一個數字 0；不保留前導零，負數與錯誤輸入拒絕。

【完整規格】
任務：讀入一個非負整數，從個位數往高位數檢查，找出第一個「再次出現」的數字；完全沒有重複則明確回報。
輸入：標準輸入：一個十進位整數 n。
輸出：輸出 Repeated digit: d；若無重複，輸出 No repeated digit。
限制：0 ≤ n ≤ 2147483647。n=0 視為一個數字 0；不保留前導零，負數與錯誤輸入拒絕。
範例輸入：
28212
範例輸出：
Repeated digit: 2

【課堂提問】
為何 n=0 不使用 while(n>0) 就結束？

【參考答案】
題目把 0 視為具有一位數的有效輸入；do…while 至少執行一次，與題意一致。

【來源與增補】
A pp.23–25
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 15 頁｜案例 02｜核心解法與圖解

【本頁目標】
案例 02｜核心解法與圖解
用布林陣列偵測重複數字

【教師講解】
依下列順序帶讀圖解：1. seen[10] 初值全 false；索引就是數字 0～9。 2. digit=n%10 取得個位數，先檢查 seen[digit]。 3. 未出現則設 true、n/=10；do…while 讓 0 也被處理一次。 不能先把 seen[digit] 設為 true 再判斷，否則每個數字都會被誤判為重複。

【課堂提問】
為何 n=0 不使用 while(n>0) 就結束？

【參考答案】
題目把 0 視為具有一位數的有效輸入；do…while 至少執行一次，與題意一致。

【來源與增補】
A pp.23–25
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 16 頁｜案例 02｜完整程式 1/2

【本頁目標】
案例 02｜完整程式 1/2
02_repeated_digits.c

【教師講解】
本頁為 02_repeated_digits.c 的第 1/2 段，對應原始檔第 1～14 行。所有程式頁依序接續，沒有省略程式碼。建立長度 10 的 seen 表並全設 false。先驗證非負整數範圍，準備以十進位數字當成狀態表索引。

【程式帶讀】
對應 02_repeated_digits.c，原始碼第 1～14 行。這是完整檔案第 1/2 段，依頁序合併即可，不需補寫省略片段。提醒學生先讀題目頁的輸入資料前提；程式使用的語法片段與整體錯誤契約應一起理解。

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    bool seen[10] = {false};
    long n;
    int repeated = -1;
    if (scanf("%ld", &n) != 1 ||
        n < 0 || n > 2147483647L) {
        fputs("Expected 0..2147483647\n", stderr);
        return EXIT_FAILURE;
    }
    do {

【課堂提問】
為何 n=0 不使用 while(n>0) 就結束？

【參考答案】
題目把 0 視為具有一位數的有效輸入；do…while 至少執行一次，與題意一致。

【來源與增補】
A pp.23–25
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 17 頁｜案例 02｜完整程式 2/2

【本頁目標】
案例 02｜完整程式 2/2
02_repeated_digits.c

【教師講解】
本頁為 02_repeated_digits.c 的第 2/2 段，對應原始檔第 15～28 行。所有程式頁依序接續，沒有省略程式碼。用 do-while 讓 0 也能被處理。每次以 %10 取數字，先查表再標记；再次遇見 true 即可回報重複，最後用 /=10 移除末位。

【程式帶讀】
對應 02_repeated_digits.c，原始碼第 15～28 行。這是完整檔案第 2/2 段，依頁序合併即可，不需補寫省略片段。提醒學生先讀題目頁的輸入資料前提；程式使用的語法片段與整體錯誤契約應一起理解。

        int digit = (int)(n % 10);
        if (seen[digit]) {
            repeated = digit;
            break;
        }
        seen[digit] = true;
        n /= 10;
    } while (n > 0);
    if (repeated >= 0)
        printf("Repeated digit: %d\n", repeated);
    else
        puts("No repeated digit");
    return EXIT_SUCCESS;
}

【課堂提問】
為何 n=0 不使用 while(n>0) 就結束？

【參考答案】
題目把 0 視為具有一位數的有效輸入；do…while 至少執行一次，與題意一致。

【來源與增補】
A pp.23–25
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 18 頁｜案例 02｜測試與常見錯誤

【本頁目標】
案例 02｜測試與常見錯誤
先預測結果，再執行；不只測一般資料。

【教師講解】
依表格逐組測試，確認返回狀態、stdout、stderr 與檔案內容。不能先把 seen[digit] 設為 true 再判斷，否則每個數字都會被誤判為重複。 對隨機或平台相依輸出，應測試性質，而不是把單一次執行結果當成唯一答案。

【測試判讀】
有重複｜28212｜Repeated digit: 2｜第 3 次取出的 2 已看過
無重複｜9357｜No repeated digit｜各索引只設一次
零｜0｜No repeated digit｜仍應處理一次
零重複｜100｜Repeated digit: 0｜兩個 0 需要被辨認
不合法｜−1｜失敗｜不可讓 digit 成負索引
本頁列出教學代表測試。附件測試器另外包含一般值、邊界與錯誤路徑；未模擬磁碟滿載、斷電、併發或所有作業系統。

【課堂提問】
為何 n=0 不使用 while(n>0) 就結束？

【參考答案】
題目把 0 視為具有一位數的有效輸入；do…while 至少執行一次，與題意一致。

【來源與增補】
A pp.23–25
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 19 頁｜案例 03｜班級成績統計與分布

【本頁目標】
案例 03｜班級成績統計與分布
完整題目：先確認任務、輸入、輸出與限制

【教師講解】
先不要展示解答。請學生用自己的話重述任務，再指出輸入格式、輸出格式與無效資料的處理。讀入全班成績，計算總分、平均、最高分、最低分、及格人數，並統計五個成績區間。 1 ≤ n ≤ 100；0 ≤ 成績 ≤ 100；及格為 ≥60。分組：0–59、60–69、70–79、80–89、90–100。

【完整規格】
任務：讀入全班成績，計算總分、平均、最高分、最低分、及格人數，並統計五個成績區間。
輸入：先輸入人數 n，再輸入 n 個整數成績。
輸出：輸出 count、sum、min、max、average（小數 2 位）、pass 與五個 bins。
限制：1 ≤ n ≤ 100；0 ≤ 成績 ≤ 100；及格為 ≥60。分組：0–59、60–69、70–79、80–89、90–100。
範例輸入：
5
59 60 75 90 100
範例輸出：
count=5 sum=384 min=59 max=100
average=76.80 pass=4
bins=1 1 1 0 2

【課堂提問】
為何 bins[score/10] 不能直接用在長度 10 的陣列？

【參考答案】
100/10=10，會存取第 11 格而越界。本題採明確的五區間映射，把 90～100 合併。

【來源與增補】
A pp.8,26–30｜新增
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 20 頁｜案例 03｜核心解法與圖解

【本頁目標】
案例 03｜核心解法與圖解
班級成績統計與分布

【教師講解】
依下列順序帶讀圖解：1. 先驗證人數與每筆成績，再開始統計。 2. 以第一筆初始化 min/max；用同一趟掃描累加。 3. 100 分併入最後一組；平均前轉為 double。 sum/n 若先做整數除法再指定給 double，小數已經遺失；需用 (double)sum/n。

【課堂提問】
為何 bins[score/10] 不能直接用在長度 10 的陣列？

【參考答案】
100/10=10，會存取第 11 格而越界。本題採明確的五區間映射，把 90～100 合併。

【來源與增補】
A pp.8,26–30｜新增
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 21 頁｜案例 03｜完整程式 1/2

【本頁目標】
案例 03｜完整程式 1/2
03_score_stats.c

【教師講解】
本頁為 03_score_stats.c 的第 1/2 段，對應原始檔第 1～18 行。所有程式頁依序接續，沒有省略程式碼。配置固定容量 100 的資料陣列與五格 bins。先確認有效筆數與每筆 0～100 分的範圍；失敗時不讓未完成資料進入統計。

【程式帶讀】
對應 03_score_stats.c，原始碼第 1～18 行。這是完整檔案第 1/2 段，依頁序合併即可，不需補寫省略片段。提醒學生先讀題目頁的輸入資料前提；程式使用的語法片段與整體錯誤契約應一起理解。

#include <stdio.h>
#include <stdlib.h>
#define CAP 100

int main(void) {
    int score[CAP], bins[5] = {0};
    int n, sum = 0, pass = 0;
    if (scanf("%d", &n) != 1 || n < 1 || n > CAP) {
        fputs("Expected count 1..100\n", stderr);
        return EXIT_FAILURE;
    }
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &score[i]) != 1 ||
            score[i] < 0 || score[i] > 100) {
            fputs("Invalid score\n", stderr);
            return EXIT_FAILURE;
        }
    }

【課堂提問】
為何 bins[score/10] 不能直接用在長度 10 的陣列？

【參考答案】
100/10=10，會存取第 11 格而越界。本題採明確的五區間映射，把 90～100 合併。

【來源與增補】
A pp.8,26–30｜新增
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 22 頁｜案例 03｜完整程式 2/2

【本頁目標】
案例 03｜完整程式 2/2
03_score_stats.c

【教師講解】
本頁為 03_score_stats.c 的第 2/2 段，對應原始檔第 19～35 行。所有程式頁依序接續，沒有省略程式碼。從第一筆設定最小值與最大值，走訪 n 筆更新總分、及格數與區間。90～100 共用最後一格，避免把 100 分當成索引 5。平均值先轉 double，輸出保留兩位小數。

【程式帶讀】
對應 03_score_stats.c，原始碼第 19～35 行。這是完整檔案第 2/2 段，依頁序合併即可，不需補寫省略片段。提醒學生先讀題目頁的輸入資料前提；程式使用的語法片段與整體錯誤契約應一起理解。

    int low = score[0], high = score[0];
    for (int i = 0; i < n; ++i) {
        int s = score[i];
        sum += s;
        if (s < low) low = s;
        if (s > high) high = s;
        if (s >= 60) ++pass;
        int b = s < 60 ? 0 : (s >= 90 ? 4 : s / 10 - 5);
        ++bins[b];
    }
    printf("count=%d sum=%d min=%d max=%d\n",
           n, sum, low, high);
    printf("average=%.2f pass=%d\n", (double)sum / n, pass);
    printf("bins=%d %d %d %d %d\n",
           bins[0], bins[1], bins[2], bins[3], bins[4]);
    return EXIT_SUCCESS;
}

【課堂提問】
為何 bins[score/10] 不能直接用在長度 10 的陣列？

【參考答案】
100/10=10，會存取第 11 格而越界。本題採明確的五區間映射，把 90～100 合併。

【來源與增補】
A pp.8,26–30｜新增
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 23 頁｜案例 03｜測試與常見錯誤

【本頁目標】
案例 03｜測試與常見錯誤
先預測結果，再執行；不只測一般資料。

【教師講解】
依表格逐組測試，確認返回狀態、stdout、stderr 與檔案內容。sum/n 若先做整數除法再指定給 double，小數已經遺失；需用 (double)sum/n。 對隨機或平台相依輸出，應測試性質，而不是把單一次執行結果當成唯一答案。

【測試判讀】
一般｜59 60 75 90 100｜平均 76.80；及格 4｜驗證各組與平均
單筆｜n=1，score=100｜min=max=100｜初始化不可假設 0
分界｜0,59,60,69,70,89,100｜bins=2 2 1 1 1｜確認閉區間
容量｜n=0 或 101｜失敗｜先驗證才寫陣列
範圍｜score=101｜失敗｜不能當成新分組
本頁列出教學代表測試。附件測試器另外包含一般值、邊界與錯誤路徑；未模擬磁碟滿載、斷電、併發或所有作業系統。

【課堂提問】
為何 bins[score/10] 不能直接用在長度 10 的陣列？

【參考答案】
100/10=10，會存取第 11 格而越界。本題採明確的五區間映射，把 90～100 合併。

【來源與增補】
A pp.8,26–30｜新增
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 24 頁｜案例 04｜有先後順序的最大增幅

【本頁目標】
案例 04｜有先後順序的最大增幅
完整題目：先確認任務、輸入、輸出與限制

【教師講解】
先不要展示解答。請學生用自己的話重述任務，再指出輸入格式、輸出格式與無效資料的處理。量測陣列中的位置代表時間。找出 max(a[j]−a[i])，且必須滿足 i<j；比較雙迴圈與單次掃描兩種解法。 2 ≤ n ≤ 100；數值介於 −10000～10000。必須選兩個不同時刻；全程下降時答案可能為負。

【完整規格】
任務：量測陣列中的位置代表時間。找出 max(a[j]−a[i])，且必須滿足 i<j；比較雙迴圈與單次掃描兩種解法。
輸入：先輸入 n，再輸入 n 個整數量測值。
輸出：同一行輸出 brute 與 linear 的結果，兩者必須相同。
限制：2 ≤ n ≤ 100；數值介於 −10000～10000。必須選兩個不同時刻；全程下降時答案可能為負。
範例輸入：
5
10 15 90 200 110
範例輸出：
brute=190 linear=190

【課堂提問】
為何要先算差值，再更新 min_before？

【參考答案】
計算時 min_before 只能來自更早的位置，才能保證 i<j；先更新會把當前元素當成自己的前值。

【來源與增補】
A pp.59–60｜新增線性解法
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 25 頁｜案例 04｜核心解法與圖解

【本頁目標】
案例 04｜核心解法與圖解
有先後順序的最大增幅

【教師講解】
依下列順序帶讀圖解：1. 暴力法枚舉所有 i<j，時間 O(n²)。 2. 線性法在處理 j 前，保存 a[0..j−1] 的最小值。 3. 先用當前值計算增幅，再更新最小值；時間 O(n)、額外空間 O(1)。 不加順序限制的 max−min 是另一道題。best=0 會把全下降資料錯答成 0。

【課堂提問】
為何要先算差值，再更新 min_before？

【參考答案】
計算時 min_before 只能來自更早的位置，才能保證 i<j；先更新會把當前元素當成自己的前值。

【來源與增補】
A pp.59–60｜新增線性解法
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 26 頁｜案例 04｜完整程式 1/3

【本頁目標】
案例 04｜完整程式 1/3
04_ordered_difference.c

【教師講解】
本頁為 04_ordered_difference.c 的第 1/3 段，對應原始檔第 1～14 行。所有程式頁依序接續，沒有省略程式碼。暴力版只枚舉 j>i 的配對。以第一組合法配對初始化 best，而不是以 0 初始化；全部遞減時答案仍可能為負。

【程式帶讀】
對應 04_ordered_difference.c，原始碼第 1～14 行。這是完整檔案第 1/3 段，依頁序合併即可，不需補寫省略片段。提醒學生先讀題目頁的輸入資料前提；程式使用的語法片段與整體錯誤契約應一起理解。

#include <stdio.h>
#include <stdlib.h>
#define CAP 100

static long long brute(const int a[], int n) {
    long long best = (long long)a[1] - a[0];
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j) {
            long long d = (long long)a[j] - a[i];
            if (d > best) best = d;
        }
    return best;
}

【課堂提問】
為何要先算差值，再更新 min_before？

【參考答案】
計算時 min_before 只能來自更早的位置，才能保證 i<j；先更新會把當前元素當成自己的前值。

【來源與增補】
A pp.59–60｜新增線性解法
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 27 頁｜案例 04｜完整程式 2/3

【本頁目標】
案例 04｜完整程式 2/3
04_ordered_difference.c

【教師講解】
本頁為 04_ordered_difference.c 的第 2/3 段，對應原始檔第 15～28 行。所有程式頁依序接續，沒有省略程式碼。線性版維持處理位置之前的最小值。先計算目前元素可形成的差，再更新前綴最小值。long long 的轉型在相減之前完成。

【程式帶讀】
對應 04_ordered_difference.c，原始碼第 15～28 行。這是完整檔案第 2/3 段，依頁序合併即可，不需補寫省略片段。提醒學生先讀題目頁的輸入資料前提；程式使用的語法片段與整體錯誤契約應一起理解。

static long long linear(const int a[], int n) {
    int min_before = a[0];
    long long best = (long long)a[1] - a[0];
    for (int j = 1; j < n; ++j) {
        long long d = (long long)a[j] - min_before;
        if (d > best) best = d;
        if (a[j] < min_before) min_before = a[j];
    }
    return best;
}

int main(void) {
    int a[CAP], n;
    if (scanf("%d", &n) != 1 || n < 2 || n > CAP) {

【課堂提問】
為何要先算差值，再更新 min_before？

【參考答案】
計算時 min_before 只能來自更早的位置，才能保證 i<j；先更新會把當前元素當成自己的前值。

【來源與增補】
A pp.59–60｜新增線性解法
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 28 頁｜案例 04｜完整程式 3/3

【本頁目標】
案例 04｜完整程式 3/3
04_ordered_difference.c

【教師講解】
本頁為 04_ordered_difference.c 的第 3/3 段，對應原始檔第 29～41 行。所有程式頁依序接續，沒有省略程式碼。主程式檢查 n>=2 與每筆範圍，再對相同輸入同時呼叫暴力版和線性版。相同答案是基本測試，但還要涵蓋全遞減、相等及邊界案例。

【程式帶讀】
對應 04_ordered_difference.c，原始碼第 29～41 行。這是完整檔案第 3/3 段，依頁序合併即可，不需補寫省略片段。提醒學生先讀題目頁的輸入資料前提；程式使用的語法片段與整體錯誤契約應一起理解。

        fputs("Expected count 2..100\n", stderr);
        return EXIT_FAILURE;
    }
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &a[i]) != 1 ||
            a[i] < -10000 || a[i] > 10000) {
            fputs("Invalid sample\n", stderr);
            return EXIT_FAILURE;
        }
    }
    printf("brute=%lld linear=%lld\n", brute(a, n), linear(a, n));
    return EXIT_SUCCESS;
}

【課堂提問】
為何要先算差值，再更新 min_before？

【參考答案】
計算時 min_before 只能來自更早的位置，才能保證 i<j；先更新會把當前元素當成自己的前值。

【來源與增補】
A pp.59–60｜新增線性解法
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 29 頁｜案例 04｜測試與常見錯誤

【本頁目標】
案例 04｜測試與常見錯誤
先預測結果，再執行；不只測一般資料。

【教師講解】
依表格逐組測試，確認返回狀態、stdout、stderr 與檔案內容。不加順序限制的 max−min 是另一道題。best=0 會把全下降資料錯答成 0。 對隨機或平台相依輸出，應測試性質，而不是把單一次執行結果當成唯一答案。

【測試判讀】
一般｜10 15 90 200 110｜190｜200−10
全下降｜9 7 3｜−2｜不能錯設 best=0
相同值｜4 4 4｜0｜仍須兩個位置
兩筆邊界｜−10000 10000｜20000｜先轉 long long 再相減
資料不足｜n=1｜失敗｜不能讀 a[1]
本頁列出教學代表測試。附件測試器另外包含一般值、邊界與錯誤路徑；未模擬磁碟滿載、斷電、併發或所有作業系統。

【課堂提問】
為何要先算差值，再更新 min_before？

【參考答案】
計算時 min_before 只能來自更早的位置，才能保證 i<j；先更新會把當前元素當成自己的前值。

【來源與增補】
A pp.59–60｜新增線性解法
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 30 頁｜二維陣列｜表格視覺，row-major 儲存

【本頁目標】
二維陣列｜表格視覺，row-major 儲存
a[r][c]：先選第 r 列，再選該列的第 c 欄。

【教師講解】
先用 3×4 表格定位一格，再把整個表格依列攤平成記憶體。C 的最右側索引變化最快；每一列有 COLS 個元素，所以 [r][c] 的元素偏移為 r*COLS+c。此為儲存布局說明，不鼓勵用越過子陣列邊界的指標操作來取代合法索引。

【本頁收斂】
二維索引必須寫 a[r][c]；a[r,c] 會使用逗號運算子。

【課堂提問】
3×4 陣列的 a[1][2] 距陣列開頭有幾個元素的位置？

【參考答案】
1×4+2=6；若圖解假設每個元素 4 bytes，位元組偏移是 24。

【來源與增補】
A pp.36–42
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 31 頁｜二維初始化與 const 查表

【本頁目標】
二維初始化與 const 查表
保留內層大括號，讓每列長度與用途都看得見。

【教師講解】
將不完整的內層初始列補零與整列省略補零分開示範。單位矩陣以 r==c 決定 1 或 0，也可用指定初始化只填對角線。const 陣列如十六進位或牌碼對照表，文件化不變資料並讓編譯器協助阻止意外修改。

【本頁收斂】
目標：3×3 單位矩陣；核心條件是 row == col，不是 row + col。

【課堂提問】
int m[2][3]={{1},{2,3}} 的第二列是什麼？

【參考答案】
2、3、0。內層初始列不足時，該列剩餘元素補零。

【來源與增補】
A pp.39–48
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 32 頁｜案例 05｜三台設備 × 四時段產量表

【本頁目標】
案例 05｜三台設備 × 四時段產量表
完整題目：先確認任務、輸入、輸出與限制

【教師講解】
先不要展示解答。請學生用自己的話重述任務，再指出輸入格式、輸出格式與無效資料的處理。用二維陣列保存三台設備在四個時段的產量，計算每台設備總產量、每時段總產量與全部總量。 固定 3 列 × 4 欄；每格 0～10000。列代表設備，欄代表時段；不可交換索引意義。

【完整規格】
任務：用二維陣列保存三台設備在四個時段的產量，計算每台設備總產量、每時段總產量與全部總量。
輸入：依列輸入 12 個整數：先輸入設備 0 的四時段，再設備 1、設備 2。
輸出：輸出 rows 三筆、cols 四筆，以及 total。
限制：固定 3 列 × 4 欄；每格 0～10000。列代表設備，欄代表時段；不可交換索引意義。
範例輸入：
10 20 30 40
5 15 25 35
8 12 16 24
範例輸出：
rows=100 80 60
cols=23 47 71 99
total=240

【課堂提問】
為何 rows 和 cols 的陣列長度不同？

【參考答案】
rows 為每台設備保存一個結果，共 3 筆；cols 為每個時段保存一個結果，共 4 筆。

【來源與增補】
A pp.36–46｜新增
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 33 頁｜案例 05｜核心解法與圖解

【本頁目標】
案例 05｜核心解法與圖解
三台設備 × 四時段產量表

【教師講解】
依下列順序帶讀圖解：1. 以 qty[r][c] 同時表達設備與時段。 2. 外層走設備 r，內層走時段 c。 3. 每讀取一格，加入 rows[r]、cols[c] 與 total。 qty[r,c] 使用的是逗號運算子，不是二維索引；正確寫法必須是 qty[r][c]。

【課堂提問】
為何 rows 和 cols 的陣列長度不同？

【參考答案】
rows 為每台設備保存一個結果，共 3 筆；cols 為每個時段保存一個結果，共 4 筆。

【來源與增補】
A pp.36–46｜新增
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 34 頁｜案例 05｜完整程式 1/2

【本頁目標】
案例 05｜完整程式 1/2
05_matrix_report.c

【教師講解】
本頁為 05_matrix_report.c 的第 1/2 段，對應原始檔第 1～14 行。所有程式頁依序接續，沒有省略程式碼。以 ROWS、COLS 表達資料語意，準備三列四欄資料、三個列總和、四個欄總和。巢狀迴圈讀入每個合法值。

【程式帶讀】
對應 05_matrix_report.c，原始碼第 1～14 行。這是完整檔案第 1/2 段，依頁序合併即可，不需補寫省略片段。提醒學生先讀題目頁的輸入資料前提；程式使用的語法片段與整體錯誤契約應一起理解。

#include <stdio.h>
#include <stdlib.h>
#define ROWS 3
#define COLS 4

int main(void) {
    int qty[ROWS][COLS];
    long rows[ROWS] = {0}, cols[COLS] = {0}, total = 0;
    for (int r = 0; r < ROWS; ++r)
        for (int c = 0; c < COLS; ++c) {
            if (scanf("%d", &qty[r][c]) != 1 ||
                qty[r][c] < 0 || qty[r][c] > 10000) {
                fputs("Invalid quantity\n", stderr);
                return EXIT_FAILURE;

【課堂提問】
為何 rows 和 cols 的陣列長度不同？

【參考答案】
rows 為每台設備保存一個結果，共 3 筆；cols 為每個時段保存一個結果，共 4 筆。

【來源與增補】
A pp.36–46｜新增
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 35 頁｜案例 05｜完整程式 2/2

【本頁目標】
案例 05｜完整程式 2/2
05_matrix_report.c

【教師講解】
本頁為 05_matrix_report.c 的第 2/2 段，對應原始檔第 15～28 行。所有程式頁依序接續，沒有省略程式碼。每讀入一個 qty[r][c]，同步更新 rows[r]、cols[c] 及 total。觀察索引的位置和目標總和所代表的維度一致，最後分別輸出。

【程式帶讀】
對應 05_matrix_report.c，原始碼第 15～28 行。這是完整檔案第 2/2 段，依頁序合併即可，不需補寫省略片段。提醒學生先讀題目頁的輸入資料前提；程式使用的語法片段與整體錯誤契約應一起理解。

            }
        }
    for (int r = 0; r < ROWS; ++r)
        for (int c = 0; c < COLS; ++c) {
            rows[r] += qty[r][c];
            cols[c] += qty[r][c];
            total += qty[r][c];
        }
    printf("rows=%ld %ld %ld\n", rows[0], rows[1], rows[2]);
    printf("cols=%ld %ld %ld %ld\n",
           cols[0], cols[1], cols[2], cols[3]);
    printf("total=%ld\n", total);
    return EXIT_SUCCESS;
}

【課堂提問】
為何 rows 和 cols 的陣列長度不同？

【參考答案】
rows 為每台設備保存一個結果，共 3 筆；cols 為每個時段保存一個結果，共 4 筆。

【來源與增補】
A pp.36–46｜新增
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 36 頁｜案例 05｜測試與常見錯誤

【本頁目標】
案例 05｜測試與常見錯誤
先預測結果，再執行；不只測一般資料。

【教師講解】
依表格逐組測試，確認返回狀態、stdout、stderr 與檔案內容。qty[r,c] 使用的是逗號運算子，不是二維索引；正確寫法必須是 qty[r][c]。 對隨機或平台相依輸出，應測試性質，而不是把單一次執行結果當成唯一答案。

【測試判讀】
一般｜題目 3×4 資料｜列 100/80/60；總量 240｜行列語意正確
全部為零｜12 個 0｜所有統計皆為 0｜初值與空產能
單格非零｜qty[1][2]=5，其餘 0｜rows[1]=cols[2]=5｜定位特定座標
超出限制｜−1 或 10001｜失敗｜不能接受非法產量
本頁列出教學代表測試。附件測試器另外包含一般值、邊界與錯誤路徑；未模擬磁碟滿載、斷電、併發或所有作業系統。

【課堂提問】
為何 rows 和 cols 的陣列長度不同？

【參考答案】
rows 為每台設備保存一個結果，共 3 筆；cols 為每個時段保存一個結果，共 4 筆。

【來源與增補】
A pp.36–46｜新增
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 37 頁｜案例 06｜五種利率的逐年複利表

【本頁目標】
案例 06｜五種利率的逐年複利表
完整題目：先確認任務、輸入、輸出與限制

【教師講解】
先不要展示解答。請學生用自己的話重述任務，再指出輸入格式、輸出格式與無效資料的處理。以本金 100 作為數值運算練習，比較起始利率及其後四個整數百分比利率，列出逐年複利後的金額。 0 ≤ rate ≤ 20；1 ≤ years ≤ 30。每年複利一次；本金固定 100。不涉及費用、稅務或投資建議。

【完整規格】
任務：以本金 100 作為數值運算練習，比較起始利率及其後四個整數百分比利率，列出逐年複利後的金額。
輸入：標準輸入：起始年利率 rate（整數百分比）與年數 years。
輸出：輸出 5 個利率欄，每年一列，金額顯示小數 2 位。
限制：0 ≤ rate ≤ 20；1 ≤ years ≤ 30。每年複利一次；本金固定 100。不涉及費用、稅務或投資建議。
範例輸入：
6 5
範例輸出：
第 5 年：
133.82 140.26 146.93 153.86 161.05

【課堂提問】
為何不需要保存 years×5 的整張表？

【參考答案】
下一年只依賴上一年的餘額，已經輸出的歷史資料不再參與計算，因此五個狀態值就足夠。

【來源與增補】
A pp.31–35
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 38 頁｜案例 06｜核心解法與圖解

【本頁目標】
案例 06｜核心解法與圖解
五種利率的逐年複利表

【教師講解】
依下列順序帶讀圖解：1. value[5] 分別保存五種情境的「當年餘額」。 2. 外層迴圈推進年份；內層更新每個利率。 3. value[i] *= 1.0 + (rate+i)/100.0；只保存最近一年的狀態。 除以 100 會做整數除法；此題必須除以 100.0。顯示四捨五入不代表中間值已被截斷。

【課堂提問】
為何不需要保存 years×5 的整張表？

【參考答案】
下一年只依賴上一年的餘額，已經輸出的歷史資料不再參與計算，因此五個狀態值就足夠。

【來源與增補】
A pp.31–35
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 39 頁｜案例 06｜完整程式 1/2

【本頁目標】
案例 06｜完整程式 1/2
06_interest_table.c

【教師講解】
本頁為 06_interest_table.c 的第 1/2 段，對應原始檔第 1～14 行。所有程式頁依序接續，沒有省略程式碼。確認利率與年數的限制，建立五個初始值同為 100 的 double 元素。先印出五個不同利率的欄位標題。

【程式帶讀】
對應 06_interest_table.c，原始碼第 1～14 行。這是完整檔案第 1/2 段，依頁序合併即可，不需補寫省略片段。提醒學生先讀題目頁的輸入資料前提；程式使用的語法片段與整體錯誤契約應一起理解。

#include <stdio.h>
#include <stdlib.h>
#define RATES 5

int main(void) {
    int rate, years;
    double value[RATES];
    if (scanf("%d%d", &rate, &years) != 2 ||
        rate < 0 || rate > 20 || years < 1 || years > 30) {
        fputs("Expected rate 0..20 and years 1..30\n", stderr);
        return EXIT_FAILURE;
    }
    printf("Year");
    for (int i = 0; i < RATES; ++i) {

【課堂提問】
為何不需要保存 years×5 的整張表？

【參考答案】
下一年只依賴上一年的餘額，已經輸出的歷史資料不再參與計算，因此五個狀態值就足夠。

【來源與增補】
A pp.31–35
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 40 頁｜案例 06｜完整程式 2/2

【本頁目標】
案例 06｜完整程式 2/2
06_interest_table.c

【教師講解】
本頁為 06_interest_table.c 的第 2/2 段，對應原始檔第 15～28 行。所有程式頁依序接續，沒有省略程式碼。外層迴圈是年度，內層迴圈是利率欄位。每格使用前一年度同一格的值更新；100.0 確保除法是浮點運算。這是數值迭代教學，不是金融預測。

【程式帶讀】
對應 06_interest_table.c，原始碼第 15～28 行。這是完整檔案第 2/2 段，依頁序合併即可，不需補寫省略片段。提醒學生先讀題目頁的輸入資料前提；程式使用的語法片段與整體錯誤契約應一起理解。

        value[i] = 100.0;
        printf(" %7d%%", rate + i);
    }
    putchar('\n');
    for (int year = 1; year <= years; ++year) {
        printf("%4d", year);
        for (int i = 0; i < RATES; ++i) {
            value[i] *= 1.0 + (rate + i) / 100.0;
            printf(" %8.2f", value[i]);
        }
        putchar('\n');
    }
    return EXIT_SUCCESS;
}

【課堂提問】
為何不需要保存 years×5 的整張表？

【參考答案】
下一年只依賴上一年的餘額，已經輸出的歷史資料不再參與計算，因此五個狀態值就足夠。

【來源與增補】
A pp.31–35
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 41 頁｜案例 06｜測試與常見錯誤

【本頁目標】
案例 06｜測試與常見錯誤
先預測結果，再執行；不只測一般資料。

【教師講解】
依表格逐組測試，確認返回狀態、stdout、stderr 與檔案內容。除以 100 會做整數除法；此題必須除以 100.0。顯示四捨五入不代表中間值已被截斷。 對隨機或平台相依輸出，應測試性質，而不是把單一次執行結果當成唯一答案。

【測試判讀】
原稿數值｜rate=6，years=5｜第 5 年如右側範例｜確認遞推
零利率｜rate=0，years=1｜第一欄 100.00｜0% 不增加
最短期間｜years=1｜只有一列資料｜迴圈起訖
錯誤年數｜years=0｜失敗｜避免無意義輸出
本頁列出教學代表測試。附件測試器另外包含一般值、邊界與錯誤路徑；未模擬磁碟滿載、斷電、併發或所有作業系統。

【課堂提問】
為何不需要保存 years×5 的整張表？

【參考答案】
下一年只依賴上一年的餘額，已經輸出的歷史資料不再參與計算，因此五個狀態值就足夠。

【來源與增補】
A pp.31–35
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 42 頁｜案例 07｜不重複發牌與狀態表

【本頁目標】
案例 07｜不重複發牌與狀態表
完整題目：先確認任務、輸入、輸出與限制

【教師講解】
先不要展示解答。請學生用自己的話重述任務，再指出輸入格式、輸出格式與無效資料的處理。從 4 種花色、13 種點數的牌組發出 n 張不重複的牌，用二維布林表記錄已發出的牌。 0 ≤ n ≤ 52。點數 23456789tjqka；花色 cdhs。同一實作／種子可重現；跨編譯器不保證相同牌序。

【完整規格】
任務：從 4 種花色、13 種點數的牌組發出 n 張不重複的牌，用二維布林表記錄已發出的牌。
輸入：標準輸入：張數 n 與 unsigned 整數亂數種子 seed。
輸出：輸出 n 個二字元牌碼，例如 7c；牌碼間以空白分隔。n=0 只輸出換行。
限制：0 ≤ n ≤ 52。點數 23456789tjqka；花色 cdhs。同一實作／種子可重現；跨編譯器不保證相同牌序。
範例輸入：
5 1
範例輸出：
5 張合法、互不重複的牌
（精確序列依 C 函式庫而異）

【課堂提問】
發到重複牌時，能否把 dealt 加一？

【參考答案】
不可以。dealt 代表成功輸出的不同牌張數，而不是抽樣嘗試次數。只有確認新牌後才增加。

【來源與增補】
A pp.49–55
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 43 頁｜案例 07｜核心解法與圖解

【本頁目標】
案例 07｜核心解法與圖解
不重複發牌與狀態表

【教師講解】
依下列順序帶讀圖解：1. rand()%4 與 rand()%13 取得花色、點數。 2. in_hand[suit][rank] 已為 true 就重新抽。 3. 新牌才標記、輸出並增加 dealt；查表轉成牌碼。 rand()%n 可能有模數偏差；這是陣列與狀態管理練習，不是公平抽獎或密碼用途的亂數設計。

【課堂提問】
發到重複牌時，能否把 dealt 加一？

【參考答案】
不可以。dealt 代表成功輸出的不同牌張數，而不是抽樣嘗試次數。只有確認新牌後才增加。

【來源與增補】
A pp.49–55
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 44 頁｜案例 07｜完整程式 1/2

【本頁目標】
案例 07｜完整程式 1/2
07_deal_cards.c

【教師講解】
本頁為 07_deal_cards.c 的第 1/2 段，對應原始檔第 1～15 行。所有程式頁依序接續，沒有省略程式碼。以 4×13 的布林表追蹤每張牌，const 字元表用於把索引轉成點數和花色。輸入張數上限 52，避免要求不可能的手牌。

【程式帶讀】
對應 07_deal_cards.c，原始碼第 1～15 行。這是完整檔案第 1/2 段，依頁序合併即可，不需補寫省略片段。提醒學生先讀題目頁的輸入資料前提；程式使用的語法片段與整體錯誤契約應一起理解。

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define SUITS 4
#define RANKS 13

int main(void) {
    const char ranks[] = "23456789tjqka";
    const char suits[] = "cdhs";
    bool in_hand[SUITS][RANKS] = {{false}};
    int n;
    unsigned seed;
    if (scanf("%d%u", &n, &seed) != 2 || n < 0 || n > 52) {
        fputs("Expected count 0..52 and unsigned seed\n", stderr);
        return EXIT_FAILURE;

【課堂提問】
發到重複牌時，能否把 dealt 加一？

【參考答案】
不可以。dealt 代表成功輸出的不同牌張數，而不是抽樣嘗試次數。只有確認新牌後才增加。

【來源與增補】
A pp.49–55
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 45 頁｜案例 07｜完整程式 2/2

【本頁目標】
案例 07｜完整程式 2/2
07_deal_cards.c

【教師講解】
本頁為 07_deal_cards.c 的第 2/2 段，對應原始檔第 16～30 行。所有程式頁依序接續，沒有省略程式碼。初始化亂數種子後反覆挑選 suit 與 rank。只有未出現的牌才標記、輸出並增加已發張數。測試重點是不重複與有效牌值，不是跨平台固定的亂數輸出。

【程式帶讀】
對應 07_deal_cards.c，原始碼第 16～30 行。這是完整檔案第 2/2 段，依頁序合併即可，不需補寫省略片段。提醒學生先讀題目頁的輸入資料前提；程式使用的語法片段與整體錯誤契約應一起理解。

    }
    srand(seed);
    int dealt = 0;
    while (dealt < n) {
        int suit = rand() % SUITS;
        int rank = rand() % RANKS;
        if (in_hand[suit][rank]) continue;
        in_hand[suit][rank] = true;
        printf("%c%c%s", ranks[rank], suits[suit],
               dealt + 1 == n ? "" : " ");
        ++dealt;
    }
    putchar('\n');
    return EXIT_SUCCESS;
}

【課堂提問】
發到重複牌時，能否把 dealt 加一？

【參考答案】
不可以。dealt 代表成功輸出的不同牌張數，而不是抽樣嘗試次數。只有確認新牌後才增加。

【來源與增補】
A pp.49–55
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 46 頁｜案例 07｜測試與常見錯誤

【本頁目標】
案例 07｜測試與常見錯誤
先預測結果，再執行；不只測一般資料。

【教師講解】
依表格逐組測試，確認返回狀態、stdout、stderr 與檔案內容。rand()%n 可能有模數偏差；這是陣列與狀態管理練習，不是公平抽獎或密碼用途的亂數設計。 對隨機或平台相依輸出，應測試性質，而不是把單一次執行結果當成唯一答案。

【測試判讀】
不發牌｜n=0｜空行｜不進入發牌迴圈
一般｜n=5，seed=1｜5 張且不重複｜驗證性質，不鎖定跨平台牌序
整副牌｜n=52｜52 個互異合法牌碼｜狀態表覆蓋完整牌組
超量｜n=53｜立即失敗｜避免永遠等不到新牌
可重現｜同一執行檔，同 seed｜兩次牌序相同｜可重現實驗
本頁列出教學代表測試。附件測試器另外包含一般值、邊界與錯誤路徑；未模擬磁碟滿載、斷電、併發或所有作業系統。

【課堂提問】
發到重複牌時，能否把 dealt 加一？

【參考答案】
不可以。dealt 代表成功輸出的不同牌張數，而不是抽樣嘗試次數。只有確認新牌後才增加。

【來源與增補】
A pp.49–55
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 47 頁｜VLA｜執行時決定長度，不是自動成長的容器

【本頁目標】
VLA｜執行時決定長度，不是自動成長的容器
C99 引入；C11／C17 的支援可依實作而不同。

【教師講解】
保留原教材 VLA 主題，但不把所有 Windows 或所有 C 編譯器都支援當成前提。以固定容量 cap 和有效筆數 n 說明容量管理是另一個獨立觀念。n 驗證需要包含正值和上限；可宣告成功也不等於適合任意大資料。

【課堂提問】
宣告 int a[n] 後，執行 n=1000，陣列會變成 1000 格嗎？

【參考答案】
不會。該陣列的大小在宣告執行時已決定，不會跟著 n 之後的指定而改變。

【來源與增補】
A pp.61–64｜W1 §6.7.6.2
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。
【外部校核來源】
W1 — https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf （C11 委員會草案，引用與 C17 共通的核心條款）
W2 — https://learn.microsoft.com/en-us/cpp/overview/install-c17-support?view=msvc-170
W3 — https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/fopen-wfopen?view=msvc-170
W4 — https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/strtol-wcstol-strtol-l-wcstol-l?view=msvc-170

---

### 投影片第 48 頁｜陣列單元收斂｜先問資料，再選狀態

【本頁目標】
陣列單元收斂｜先問資料，再選狀態
把每個案例用到的「最小必要狀態」寫清楚。

【教師講解】
這一頁不是再列一次語法，而是讓學生比較不同問題究竟需要保存什麼。布林陣列記錄集合成員；一般陣列保存值；前綴最小值則是對歷史資料的摘要。請學生從任務需求說出資料模型，而不是先問要宣告幾維陣列。

【表格帶讀】
任務｜保存什麼｜關鍵不變量
反向輸出｜完整的一維資料｜讀入 n 筆後才輸出
重複數字／發牌｜是否出現的布林表｜true 代表已接受或已觀察
最大有序增幅｜前綴最小值與最佳答案｜當前候選只能搭配更早位置
產量表｜二維原始資料＋行列統計｜r/c 的語意不交換
複利表｜每種情境的最近狀態｜下一年只依賴上一年

【課堂提問】
為何最大增幅的線性演算法不必保存每一組差值？

【參考答案】
因為對固定的 j，最佳前值必定是之前的最小值；可以用狀態摘要代替所有配對。

【來源與增補】
A pp.1–64｜重整小結
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 49 頁｜02｜輸入／輸出：把資料流接到陣列

【本頁目標】
02｜輸入／輸出：把資料流接到陣列
FILE* 是串流介面；陣列是記憶體中的資料模型。

【教師講解】
先把來源、暫存、解析、計算與目的地分開。stdin、檔案與字串可能提供同樣的文字，但需要不同介面接收。成功讀到字元不等於成功解析數值，成功計算也不等於成功寫檔；本節逐一補上這些轉換與回傳值。

【課堂提問】
fgets 成功之後，就能把 line 當成合法整數嗎？

【參考答案】
不能。它只表示讀到字串；還需要解析格式與驗證數值範圍。

【來源與增補】
B pp.5–8｜新增串接
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 50 頁｜stdin、stdout、stderr｜資料與診斷分流

【本頁目標】
stdin、stdout、stderr｜資料與診斷分流
重導向改變串流的連接，不必改寫程式的計算邏輯。

【教師講解】
沿圖示解釋標準輸入、一般結果與錯誤診斷。指令中的 <、> 和 2> 是 shell 的工作，不是 C 語法。原稿提到 stderr 一定顯示在螢幕，需限縮為「只重導向 stdout 時不受影響」；stderr 本身仍然可以被重導向。範例指令以常見 shell 或 Windows cmd 語法示意。

【本頁收斂】
資料寫 stdout；錯誤寫 stderr；兩者都可能被呼叫環境重導向。

【課堂提問】
prog < in.txt > out.txt 2> err.txt 的錯誤訊息會去哪裡？

【參考答案】
若程式寫到 stderr，診斷會進入 err.txt，而不是螢幕或 out.txt。

【來源與增補】
B pp.3,9–13
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 51 頁｜跨章橋接｜FILE*、字串與命令列陣列

【本頁目標】
跨章橋接｜FILE*、字串與命令列陣列
只補上本節會用到的介面，不把指標章節整章插進來。

【教師講解】
本節由第 8 章跳到第 22 章，學生可能尚未熟悉字串與指標，因此以三個最小介面建立橋接。清楚區分 FILE*、char[] 與 char*argv[] 的用途。用 argv[1] 指向檔名文字作例，不要求學生自行操作 FILE 內部結構。

【課堂提問】
檔案內容有 1 GB，就需要宣告一個 1 GB 的 FILE 物件嗎？

【參考答案】
不需要。FILE* 管理串流狀態，資料可透過固定大小的緩衝區逐塊處理。

【來源與增補】
B pp.8,38–40,129–135
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 52 頁｜文字檔與二進位檔｜相同數值，不同表示法

【本頁目標】
文字檔與二進位檔｜相同數值，不同表示法
文字保存字元；原生二進位保存實作相關的物件表示。

【教師講解】
以 32767 對照五個十進位字元與二進位表示。圖中位元組順序及大小都明確標示為假設，不能從檔案副檔名判定。文字模式可能處理換行；通用複製工具使用二進位模式，避免內容在讀写轉換中改變。原生 int 或 struct 的二進位資料跨平台可能有大小、位元組順序與填補差異。

【本頁收斂】
通用位元組搬移用二進位模式；跨平台交換另定明確檔案格式。

【課堂提問】
副檔名是 .txt，就能在通用複製器中使用 r/w 模式嗎？

【參考答案】
不能只依副檔名假設內容；要保留任意檔案的原始位元組，使用 rb/wb 或建立保護版 wbx。

【來源與增補】
B pp.14–20
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 53 頁｜fopen 模式｜最重要的是「是否破壞既有資料」

【本頁目標】
fopen 模式｜最重要的是「是否破壞既有資料」
開啟模式是資料安全的決策，不只是可讀或可寫。

【教師講解】
讓學生先回答資料可不可以被覆寫，再選模式。w 的破壞發生在開檔成功時，不是第一次 fwrite。b 指定二進位模式；x 是排他建立，與 w 搭配使用。程式以相對路徑執行時，位置由目前工作目錄決定；Windows 字串內反斜線需要跳脫。

【表格帶讀】
模式｜要求檔案存在？｜允許操作｜既有內容
r｜是｜讀｜保留；位置從開頭
w｜否｜寫｜開啟成功時即截斷
a｜否｜寫（追加）｜保留；寫入追加在尾端
r+｜是｜讀＋寫｜保留；可定位更新
w+｜否｜讀＋寫｜開啟成功時即截斷
a+｜否｜讀＋追加寫｜寫仍追加，初始讀位置依實作
wbx / wx｜必須不存在｜建立新檔再寫｜拒絕既有檔案（C11 起）

【課堂提問】
檔案已存在時，fopen(name,"w") 成功但什麼都不寫，原內容還在嗎？

【參考答案】
不在；w 模式成功開啟既有檔案時就會將其截斷。

【來源與增補】
B pp.23–31｜W1 §7.21.5.3；W3
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。
【外部校核來源】
W1 — https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf （C11 委員會草案，引用與 C17 共通的核心條款）
W2 — https://learn.microsoft.com/en-us/cpp/overview/install-c17-support?view=msvc-170
W3 — https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/fopen-wfopen?view=msvc-170
W4 — https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/strtol-wcstol-strtol-l-wcstol-l?view=msvc-170

---

### 投影片第 54 頁｜更新串流｜讀寫切換需要同步點

【本頁目標】
更新串流｜讀寫切換需要同步點
r+、w+、a+ 不是「任何時候隨意混合讀寫」。

【教師講解】
分別画出寫到讀、讀到寫兩個方向。寫到讀可用 fflush 或定位函式；讀到寫一般要先定位，只有前次讀取遭遇 EOF 時例外。fseek 同時決定接下來要讀寫的實際位置。不要把 fflush(stdin) 當作讀到寫的通用解法。

【本頁收斂】
先確定方向，再選同步操作；位置與緩衝區狀態是兩件相關但不同的事。

【課堂提問】
剛 fscanf 完資料，直接 fflush(fp) 再 fprintf 就一定可攜嗎？

【參考答案】
不是。對讀到寫的切換一般需要檔案定位函式；fflush 對最近操作為輸入的更新串流不是 ISO C 的可攜解法。

【來源與增補】
B p.31｜W1 §7.21.5.3
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。
【外部校核來源】
W1 — https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf （C11 委員會草案，引用與 C17 共通的核心條款）
W2 — https://learn.microsoft.com/en-us/cpp/overview/install-c17-support?view=msvc-170
W3 — https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/fopen-wfopen?view=msvc-170
W4 — https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/strtol-wcstol-strtol-l-wcstol-l?view=msvc-170

---

### 投影片第 55 頁｜案例 08｜命令列檔案開啟檢查器

【本頁目標】
案例 08｜命令列檔案開啟檢查器
完整題目：先確認任務、輸入、輸出與限制

【教師講解】
先不要展示解答。請學生用自己的話重述任務，再指出輸入格式、輸出格式與無效資料的處理。寫一個命令列工具，接收一個檔名，檢查本次是否能以讀取模式成功開啟並關閉。 argc 必須為 2；以本次 fopen 的結果為準。可開啟不代表內容正確，也不保證未來仍可開啟。

【完整規格】
任務：寫一個命令列工具，接收一個檔名，檢查本次是否能以讀取模式成功開啟並關閉。
輸入：命令列：canopen filename；不從鍵盤另外讀取檔名。
輸出：成功：stdout 顯示檔案可開啟。失敗：stderr 顯示原因，回傳 EXIT_FAILURE。
限制：argc 必須為 2；以本次 fopen 的結果為準。可開啟不代表內容正確，也不保證未來仍可開啟。
範例輸入：
canopen sample.txt
範例輸出：
sample.txt can be opened

【課堂提問】
argc 為 2 時，argv[0] 與 argv[1] 分別是什麼？

【參考答案】
argv[0] 是程式名稱字串，argv[1] 是使用者傳入的檔名；argv[argc] 是空指標。

【來源與增補】
B pp.38–42｜C pp.6–9
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 56 頁｜案例 08｜核心解法與圖解

【本頁目標】
案例 08｜核心解法與圖解
命令列檔案開啟檢查器

【教師講解】
依下列順序帶讀圖解：1. 先驗證 argc，再使用 argv[1]。 2. fopen 回傳 NULL 就停止；保存 errno 後才輸出訊息。 3. 成功開啟也要檢查 fclose；不要把錯誤訊息寫入 stdout。 先用「檔案是否存在」判斷再 fopen 仍可能失敗；權限與狀態可能改變，應檢查真正要做的操作。

【課堂提問】
argc 為 2 時，argv[0] 與 argv[1] 分別是什麼？

【參考答案】
argv[0] 是程式名稱字串，argv[1] 是使用者傳入的檔名；argv[argc] 是空指標。

【來源與增補】
B pp.38–42｜C pp.6–9
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 57 頁｜案例 08｜完整程式 1/2

【本頁目標】
案例 08｜完整程式 1/2
08_canopen.c

【教師講解】
本頁為 08_canopen.c 的第 1/2 段，對應原始檔第 1～14 行。所有程式頁依序接續，沒有省略程式碼。先檢查 argc 才能使用 argv[1]；把 errno 清零後呼叫 fopen，成功與否由 fp 是否為 NULL 決定。

【程式帶讀】
對應 08_canopen.c，原始碼第 1～14 行。這是完整檔案第 1/2 段，依頁序合併即可，不需補寫省略片段。提醒學生先讀題目頁的輸入資料前提；程式使用的語法片段與整體錯誤契約應一起理解。

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fputs("usage: canopen filename\n", stderr);
        return EXIT_FAILURE;
    }
    errno = 0;
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        int saved_errno = errno;
        fprintf(stderr, "Cannot open: %s\n", argv[1]);

【課堂提問】
argc 為 2 時，argv[0] 與 argv[1] 分別是什麼？

【參考答案】
argv[0] 是程式名稱字串，argv[1] 是使用者傳入的檔名；argv[argc] 是空指標。

【來源與增補】
B pp.38–42｜C pp.6–9
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 58 頁｜案例 08｜完整程式 2/2

【本頁目標】
案例 08｜完整程式 2/2
08_canopen.c

【教師講解】
本頁為 08_canopen.c 的第 2/2 段，對應原始檔第 15～27 行。所有程式頁依序接續，沒有省略程式碼。失敗時先保存 errno，避免診斷輸出改變它，再視情況以 perror 補充原因。成功路徑仍檢查 fclose，不把開檔成功當成整段流程已成功。

【程式帶讀】
對應 08_canopen.c，原始碼第 15～27 行。這是完整檔案第 2/2 段，依頁序合併即可，不需補寫省略片段。提醒學生先讀題目頁的輸入資料前提；程式使用的語法片段與整體錯誤契約應一起理解。

        if (saved_errno != 0) {
            errno = saved_errno;
            perror("fopen");
        }
        return EXIT_FAILURE;
    }
    if (fclose(fp) != 0) {
        fputs("Close failed\n", stderr);
        return EXIT_FAILURE;
    }
    printf("%s can be opened\n", argv[1]);
    return EXIT_SUCCESS;
}

【課堂提問】
argc 為 2 時，argv[0] 與 argv[1] 分別是什麼？

【參考答案】
argv[0] 是程式名稱字串，argv[1] 是使用者傳入的檔名；argv[argc] 是空指標。

【來源與增補】
B pp.38–42｜C pp.6–9
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 59 頁｜案例 08｜測試與常見錯誤

【本頁目標】
案例 08｜測試與常見錯誤
先預測結果，再執行；不只測一般資料。

【教師講解】
依表格逐組測試，確認返回狀態、stdout、stderr 與檔案內容。先用「檔案是否存在」判斷再 fopen 仍可能失敗；權限與狀態可能改變，應檢查真正要做的操作。 對隨機或平台相依輸出，應測試性質，而不是把單一次執行結果當成唯一答案。

【測試判讀】
檔案存在｜sample.txt｜成功並關閉｜正常流程
不存在｜absent.txt｜失敗；stderr｜不能使用 NULL 串流
漏參數｜canopen｜usage 訊息；失敗｜先驗證 argc
多參數｜canopen a b｜usage 訊息；失敗｜介面規格固定
本頁列出教學代表測試。附件測試器另外包含一般值、邊界與錯誤路徑；未模擬磁碟滿載、斷電、併發或所有作業系統。

【課堂提問】
argc 為 2 時，argv[0] 與 argv[1] 分別是什麼？

【參考答案】
argv[0] 是程式名稱字串，argv[1] 是使用者傳入的檔名；argv[argc] 是空指標。

【來源與增補】
B pp.38–42｜C pp.6–9
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 60 頁｜printf 格式｜把一個規格拆成五個欄位

【本頁目標】
printf 格式｜把一個規格拆成五個欄位
% [flags] [width] [.precision] [length] conversion

【教師講解】
用原稿的格式文法拆解觀念，再以較容易閱讀的 %+08.2f 示範旗標、寬度和精度。field width 是最小欄寬，不會截斷過長數值；precision 的意義依轉換類型而異。完整規格表移到附錄，主課程先掌握型別匹配與輸出對齊。

【本頁收斂】
格式字串是型別契約；使用者資料要當引數，不要直接當格式字串。

【課堂提問】
printf("%3d",12345) 會只印出 123 嗎？

【參考答案】
不會；欄寬是最小值，完整的 12345 仍會被輸出。

【來源與增補】
B pp.61–85
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 61 頁｜printf 與 scanf｜相似符號，不同參數型別

【本頁目標】
printf 與 scanf｜相似符號，不同參數型別
輸出傳值；輸入多數時候傳入「要被寫入的物件位址」。

【教師講解】
重點對照 double 的輸入 %lf 與輸出 %f。printf 是可變參數函式，float 在傳遞時提升為 double；scanf 寫入物件，float* 和 double* 絕不能互換。陣列名稱用於 %s 時已提供首元素位址，不需要多加不合適的 &。

【表格帶讀】
資料｜printf 片段｜scanf 片段｜關鍵差異
int｜printf("%d", n)｜scanf("%d", &n)｜scanf 需要 int*
double｜printf("%f", x)｜scanf("%lf", &x)｜輸入要用 %lf
float｜printf("%f", f)｜scanf("%f", &f)｜輸出時 float 會提升
size_t｜printf("%zu", n)｜scanf("%zu", &n)｜不要硬套 %d
字元陣列｜printf("%s", s)｜scanf("%15s", s)｜s[16] 要保留結尾 \0
物件位址｜printf("%p", (void*)p)｜一般不拿來讀業務資料｜%p 的表示法依實作

【課堂提問】
double x; scanf("%f",&x) 是精度比較少但仍合法嗎？

【參考答案】
不合法；%f 要求 float*，給 double* 是型別不匹配，不能當作正常轉換使用。

【來源與增補】
B pp.71–76,84,86–100
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 62 頁｜欄寬與精度｜直接看相同輸入的輸出差異

【本頁目標】
欄寬與精度｜直接看相同輸入的輸出差異
下表以 · 表示空白；實際輸出沒有圓點。

【教師講解】
用最小欄寬、浮點小數位、有效數字、字串最大長度四組概念避免混淆。原稿 p.81 的 1234.56 用 %.4g 結果有誤，本教材修正為 1235。字串精度以 bytes 計算，不能視為中文字數；多位元組編碼下要特別注意。

【表格帶讀】
格式片段｜輸入值｜可見輸出｜解讀
%8d｜123｜·····123｜右靠齊，最小 8 欄
%-8d｜123｜123·····｜左靠齊
%08d｜−123｜-0000123｜符號後補零
%8.2f｜12.3｜···12.30｜小數點後 2 位
%6.4s｜"buzzword"｜··buzz｜最多輸出 4 bytes
%.4g｜1234.56｜1235｜4 位有效數字；修正原稿 p.81
%*.*f｜8, 2, 12.3｜···12.30｜* 先取寬度，再取精度

【課堂提問】
%.4f 和 %.4g 都是小數點後四位嗎？

【參考答案】
不是。%.4f 是小數點後四位；%.4g 是四位有效數字，並可能採科學記號。

【來源與增補】
B pp.68–83｜p.81 勘誤
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 63 頁｜scanf 配對｜輸入游標停在哪裡，決定下一次讀到什麼

【本頁目標】
scanf 配對｜輸入游標停在哪裡，決定下一次讀到什麼
用同一份輸入 12 , 34，看空白與常值逗號如何配對。

【教師講解】
先畫出 1、2、空白、逗號、空白、3、4 的位置，再比較四個格式。%d 會略過前導空白，但格式中的逗號不會自動略過空白。配對失敗時不相符字元留給後續讀取；若迴圈不消耗它，下一次可能在同處再次失敗。

【本頁收斂】
格式中的空白可匹配零個以上輸入空白；%c、%[、%n 不自動略過前導空白。

【課堂提問】
輸入是 12 , 34，scanf("%d,%d",&a,&b) 回傳多少？

【參考答案】
回傳 1。第一個整數成功後停在空白，格式下一個常值逗號無法立刻配對。

【來源與增補】
B pp.88–109
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 64 頁｜scanf 進階｜欄寬、抑制指定、scanset 與 %n

【本頁目標】
scanf 進階｜欄寬、抑制指定、scanset 與 %n
看的是「成功指定幾個物件」，不是消耗了幾段文字。

【教師講解】
先辨識 %s 和 %[ 會加終止字元、%c 不會。欄寬是輸入項目的最大字元數，不是整行合法性保證。%* 抑制指定，不計入回傳；%n 不消耗輸入，也不計入回傳。避免在格式尾端加不必要的換行，互動輸入可能等待下一個非空白字元。

【表格帶讀】
語法片段｜輸入／容量前提｜作用與結果
%15s｜char s[16]｜最多 15 個非空白字元，再補 \0
%15[^,]｜char s[16]｜讀取逗號前內容；至少匹配一個字元
%c / " %c"｜char ch｜前者讀下一字元；後者先略過空白
%*d%d｜輸入 12 34｜略過 12，只指定 34；回傳 1
%*d%d%n｜輸入 10 20 30｜指定 20；%n 記錄 5；回傳仍 1
%3d｜輸入 12345｜最多讀 3 字元；不代表完整數字已驗證

【課堂提問】
為何 char s[16] 應使用 %15s 而不是 %16s？

【參考答案】
還需要一格保存字串結尾的空字元；%16s 可能寫入 17 個字元。

【來源與增補】
B pp.95–109
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 65 頁｜讀取的成功、EOF、錯誤：三種狀態不能混在一起

【本頁目標】
讀取的成功、EOF、錯誤：三種狀態不能混在一起
先嘗試讀取，再依回傳值與串流指標解釋結果。

【教師講解】
強調 feof 是之前讀取是否遇到結尾的記錄，不是預測下一次讀取能否成功。fscanf 返回成功指定數；若已指定一部分才遇到 EOF，會回傳該數量而不一定是 EOF。ferror 與 feof 用於解釋串流狀態；配對失敗不一定會設定任何一個指標。

【本頁收斂】
不要把 EOF 當檔案中的某個特定 byte，也不要用它預測下一次讀取。

【課堂提問】
為何 while(!feof(fp)) 不是正確的讀取迴圈條件？

【參考答案】
因為 EOF 通常要在嘗試讀取之後才被設定；應用讀取函式回傳值控制迴圈，結束後檢查 ferror。

【來源與增補】
B pp.88–89,110–116
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 66 頁｜fgets｜容量、換行與字串結尾，都要看得見

【本頁目標】
fgets｜容量、換行與字串結尾，都要看得見
fgets(buf,n,fp) 最多保存 n−1 個讀入字元，並補上 \0。

【教師講解】
以容量 8 的陣列逐格示範讀入 ABCDE 和換行。讀到的換行會保留，puts 又自動加換行，因此直接 puts 原始 line 可能產生多一個空行。長行可能分多次讀到，不是每次成功就代表整行完整。原稿的 gets 是歷史內容；C11 起已移除，本教材不使用。

【本頁收斂】
gets 不列入 C17 解法；puts 自動加換行，fputs 則不會。

【課堂提問】
fgets 成功而字串中沒有換行，一定是完整的一行嗎？

【參考答案】
不一定，可能是最後一行沒有換行，也可能是緩衝區已滿造成截斷；需要依題目長度策略進一步判斷。

【來源與增補】
B pp.129–137｜W1 §7.21.7
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。
【外部校核來源】
W1 — https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf （C11 委員會草案，引用與 C17 共通的核心條款）
W2 — https://learn.microsoft.com/en-us/cpp/overview/install-c17-support?view=msvc-170
W3 — https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/fopen-wfopen?view=msvc-170
W4 — https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/strtol-wcstol-strtol-l-wcstol-l?view=msvc-170

---

### 投影片第 67 頁｜字串 I/O｜先接住整行，再解析與格式化

【本頁目標】
字串 I/O｜先接住整行，再解析與格式化
sscanf 解析字串；snprintf 將格式化結果寫進有容量上限的陣列。

【教師講解】
讓學生比較 scanf 直接從串流取資料與 fgets 後再 sscanf 的差別：整行字串可重複檢查，有利錯誤定位。snprintf 的回傳值是沒有長度限制时本来需要写出的字元數，不包含結束字元；负值代表错误，回傳值≥容量表示截斷。成功解析欄位不代表整行與語意都合法，日期案例會補上這一層。

【本頁收斂】
判斷 snprintf：先 n<0，再 (size_t)n >= sizeof buffer。

【課堂提問】
char out[8]; int n=snprintf(out,8,"%s","ABCDEFGHI"); n 是 7 嗎？

【參考答案】
不是，n 是原本需要的 9；out 只能保存前 7 個字元加 \0，因此 n≥8 表示截斷。

【來源與增補】
B pp.161–171
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 68 頁｜案例 09｜日期字串：格式合法不等於日期存在

【本頁目標】
案例 09｜日期字串：格式合法不等於日期存在
完整題目：先確認任務、輸入、輸出與限制

【教師講解】
先不要展示解答。請學生用自己的話重述任務，再指出輸入格式、輸出格式與無效資料的處理。讀入一行日期，接受 YYYY-MM-DD 或 YYYY/MM/DD，驗證實際日曆日期後，統一輸出 YYYY-MM-DD。 1900～2099 年；年月日必須分別為 4/2/2 位數；兩個分隔符須相同。不能有多餘字元或空白。輸入為無 NUL 的文字。

【完整規格】
任務：讀入一行日期，接受 YYYY-MM-DD 或 YYYY/MM/DD，驗證實際日曆日期後，統一輸出 YYYY-MM-DD。
輸入：一行 10 個字元的日期；允許行尾 LF、CRLF 或最後一行無換行。
輸出：有效日期：輸出正規化結果；無效：stderr 訊息並失敗。
限制：1900～2099 年；年月日必須分別為 4/2/2 位數；兩個分隔符須相同。不能有多餘字元或空白。輸入為無 NUL 的文字。
範例輸入：
2024/02/29
範例輸出：
2024-02-29

【課堂提問】
為何本題先檢查數字位置，再呼叫 sscanf？

【參考答案】
先確定欄位恰好是 4/2/2 位數，避免寬度只是上限而非固定長度的誤解，也讓數值一定在可表示範圍內。

【來源與增補】
B pp.132–135,161–171｜新增
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 69 頁｜案例 09｜核心解法與圖解

【本頁目標】
案例 09｜核心解法與圖解
日期字串：格式合法不等於日期存在

【教師講解】
依下列順序帶讀圖解：1. fgets 取得一整行，只移除行尾 CR/LF。 2. 先驗證長度與數字位置，再以 sscanf 拆欄位。 3. 檢查月份、閏年與當月天數，最後 snprintf 並檢查截斷。 只檢查 sscanf 回傳 3 或 5，只能證明欄位解析成功，不能證明日期在日曆中存在。

【課堂提問】
為何本題先檢查數字位置，再呼叫 sscanf？

【參考答案】
先確定欄位恰好是 4/2/2 位數，避免寬度只是上限而非固定長度的誤解，也讓數值一定在可表示範圍內。

【來源與增補】
B pp.132–135,161–171｜新增
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 70 頁｜案例 09｜完整程式 1/3

【本頁目標】
案例 09｜完整程式 1/3
09_date_parser.c

【教師講解】
本頁為 09_date_parser.c 的第 1/3 段，對應原始檔第 1～17 行。所有程式頁依序接續，沒有省略程式碼。以 fgets 取得有限長度文字，僅去掉末端 LF 與 CR；要求日期本體恰為 10 字元，不接受尾端雜字。

【程式帶讀】
對應 09_date_parser.c，原始碼第 1～17 行。這是完整檔案第 1/3 段，依頁序合併即可，不需補寫省略片段。提醒學生先讀題目頁的輸入資料前提；程式使用的語法片段與整體錯誤契約應一起理解。

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char line[64], sep1, sep2, extra;
    int y, m, d;
    if (fgets(line, sizeof line, stdin) == NULL) {
        fputs("Missing date\n", stderr);
        return EXIT_FAILURE;
    }
    size_t len = strlen(line);
    if (len > 0 && line[len - 1] == '\n') --len;
    if (len > 0 && line[len - 1] == '\r') --len;
    if (len != 10) {
        fputs("Expected YYYY-MM-DD or YYYY/MM/DD\n", stderr);

【課堂提問】
為何本題先檢查數字位置，再呼叫 sscanf？

【參考答案】
先確定欄位恰好是 4/2/2 位數，避免寬度只是上限而非固定長度的誤解，也讓數值一定在可表示範圍內。

【來源與增補】
B pp.132–135,161–171｜新增
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 71 頁｜案例 09｜完整程式 2/3

【本頁目標】
案例 09｜完整程式 2/3
09_date_parser.c

【教師講解】
本頁為 09_date_parser.c 的第 2/3 段，對應原始檔第 18～34 行。所有程式頁依序接續，沒有省略程式碼。先驗證數字位置及分隔符，再使用有欄寬的 sscanf 取得年月日。年份限制 1900～2099，兩個分隔符必須相同。

【程式帶讀】
對應 09_date_parser.c，原始碼第 18～34 行。這是完整檔案第 2/3 段，依頁序合併即可，不需補寫省略片段。提醒學生先讀題目頁的輸入資料前提；程式使用的語法片段與整體錯誤契約應一起理解。

        return EXIT_FAILURE;
    }
    line[len] = '\0';
    for (size_t i = 0; i < len; ++i) {
        if (i != 4 && i != 7 &&
            !isdigit((unsigned char)line[i])) {
            fputs("Invalid date digits\n", stderr);
            return EXIT_FAILURE;
        }
    }
    if (sscanf(line, "%4d%c%2d%c%2d%c",
               &y, &sep1, &m, &sep2, &d, &extra) != 5 ||
        sep1 != sep2 || (sep1 != '-' && sep1 != '/') ||
        y < 1900 || y > 2099 || m < 1 || m > 12) {
        fputs("Invalid date format/range\n", stderr);
        return EXIT_FAILURE;
    }

【課堂提問】
為何本題先檢查數字位置，再呼叫 sscanf？

【參考答案】
先確定欄位恰好是 4/2/2 位數，避免寬度只是上限而非固定長度的誤解，也讓數值一定在可表示範圍內。

【來源與增補】
B pp.132–135,161–171｜新增
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 72 頁｜案例 09｜完整程式 3/3

【本頁目標】
案例 09｜完整程式 3/3
09_date_parser.c

【教師講解】
本頁為 09_date_parser.c 的第 3/3 段，對應原始檔第 35～50 行。所有程式頁依序接續，沒有省略程式碼。依月份及閏年規則驗證日期範圍，最後以 snprintf 建立 YYYY-MM-DD。檢查回傳長度，完整輸出才回報成功。

【程式帶讀】
對應 09_date_parser.c，原始碼第 35～50 行。這是完整檔案第 3/3 段，依頁序合併即可，不需補寫省略片段。提醒學生先讀題目頁的輸入資料前提；程式使用的語法片段與整體錯誤契約應一起理解。

    const int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int leap = y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
    int limit = days[m - 1] + (m == 2 && leap);
    if (d < 1 || d > limit) {
        fputs("Invalid day\n", stderr);
        return EXIT_FAILURE;
    }
    char out[11];
    int written = snprintf(out, sizeof out, "%04d-%02d-%02d", y, m, d);
    if (written < 0 || (size_t)written >= sizeof out) {
        fputs("Formatting failed\n", stderr);
        return EXIT_FAILURE;
    }
    puts(out);
    return EXIT_SUCCESS;
}

【課堂提問】
為何本題先檢查數字位置，再呼叫 sscanf？

【參考答案】
先確定欄位恰好是 4/2/2 位數，避免寬度只是上限而非固定長度的誤解，也讓數值一定在可表示範圍內。

【來源與增補】
B pp.132–135,161–171｜新增
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 73 頁｜案例 09｜測試與常見錯誤

【本頁目標】
案例 09｜測試與常見錯誤
先預測結果，再執行；不只測一般資料。

【教師講解】
依表格逐組測試，確認返回狀態、stdout、stderr 與檔案內容。只檢查 sscanf 回傳 3 或 5，只能證明欄位解析成功，不能證明日期在日曆中存在。 對隨機或平台相依輸出，應測試性質，而不是把單一次執行結果當成唯一答案。

【測試判讀】
閏年｜2024/02/29｜2024-02-29｜可被 4 整除且非百年例外
平年｜2025-02-29｜失敗｜成功解析不代表日期存在
百年例外｜1900-02-29｜失敗｜1900 不是閏年
分隔符混用｜2024-02/29｜失敗｜兩個分隔符需一致
尾端垃圾｜2024-02-29x｜失敗｜不可只接受合法前綴
本頁列出教學代表測試。附件測試器另外包含一般值、邊界與錯誤路徑；未模擬磁碟滿載、斷電、併發或所有作業系統。

【課堂提問】
為何本題先檢查數字位置，再呼叫 sscanf？

【參考答案】
先確定欄位恰好是 4/2/2 位數，避免寬度只是上限而非固定長度的誤解，也讓數值一定在可表示範圍內。

【來源與增補】
B pp.132–135,161–171｜新增
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 74 頁｜逐字元 I/O｜用 int 保住 EOF 的區別

【本頁目標】
逐字元 I/O｜用 int 保住 EOF 的區別
fgetc / getchar 回傳值必須先由 int 接收，不要急著縮成 char。

【教師講解】
畫出合法字元值與 EOF 的不同區域。EOF 是負整數常數，不保證是 −1；若先存到 char 可能失去區分能力。fgetc 和 getc 的差異可涉及宏實作，不應直接宣稱其中一個一定比較快；需要效能時量測。ungetc 可退回字元，但不要把 EOF 推回，也不要假設能退回任意多個字元。

【本頁收斂】
正確骨架：while ((ch=fgetc(fp)) != EOF)；離開迴圈後檢查 ferror。

【課堂提問】
二進位檔中遇到 0xFF，可以當成讀到 EOF 嗎？

【參考答案】
不可以。0xFF 是合法檔案 byte；應以 fgetc 的 int 回傳值與 EOF 比較。

【來源與增補】
B pp.117–125
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 75 頁｜fread / fwrite｜「元素數」與「位元組數」要分清楚

【本頁目標】
fread / fwrite｜「元素數」與「位元組數」要分清楚
有效長度 n 是資料的一部分；最後一塊通常沒有填滿緩衝區。

【教師講解】
先介紹參數 ptr、size、count、stream，再以 size=1 的 4097-byte 複製作圖：先讀 4096、再讀 1。回傳是完整元素數；如果 size 不是 1，不能直接當 bytes。二進位 buffer 不必加 \0，不能用 printf("%s") 檢查任意二進位內容。原稿 while(!feof) 的範例在本教材明確改為依 fread 回傳控制。

【本頁收斂】
短讀：再分 EOF／錯誤；短寫：視為輸出失敗。

【課堂提問】
fread(a,sizeof a[0],10,fp) 回傳 3，代表讀了 3 bytes 嗎？

【參考答案】
不一定；代表成功讀到 3 個完整元素。只有 size=1 時，元素數才等於位元組數。

【來源與增補】
B pp.138–146
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 76 頁｜案例 10｜安全複製：逐字元版與區塊版

【本頁目標】
案例 10｜安全複製：逐字元版與區塊版
完整題目：先確認任務、輸入、輸出與限制

【教師講解】
先不要展示解答。請學生用自己的話重述任務，再指出輸入格式、輸出格式與無效資料的處理。複製任意文字或二進位檔案，保留所有位元組。實作逐字元與區塊兩版，且不得覆寫任何既有目的檔。 目的檔必須不存在；使用 C17 的 wbx 建立。檢查讀、寫、關閉錯誤；失敗時嘗試刪除本次建立的不完整檔。

【完整規格】
任務：複製任意文字或二進位檔案，保留所有位元組。實作逐字元與區塊兩版，且不得覆寫任何既有目的檔。
輸入：命令列：copy_character source new_destination，或 copy_block source new_destination。
輸出：成功：目的檔每個位元組與來源一致，stdout 顯示 Copy complete。
限制：目的檔必須不存在；使用 C17 的 wbx 建立。檢查讀、寫、關閉錯誤；失敗時嘗試刪除本次建立的不完整檔。
範例輸入：
copy_block input.bin copy.bin
範例輸出：
Copy complete
copy.bin 與 input.bin 位元組完全一致

【課堂提問】
區塊版的 fread(buffer,1,sizeof buffer,in) 回傳的是什麼？

【參考答案】
回傳完整元素數；因每個元素大小設成 1 byte，所以這個案例的回傳值也就是有效位元組數。

【來源與增補】
B pp.117–128,138–146｜新增防護
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 77 頁｜案例 10｜核心解法與圖解

【本頁目標】
案例 10｜核心解法與圖解
安全複製：逐字元版與區塊版

【教師講解】
依下列順序帶讀圖解：1. 來源用 rb；目的用 wbx，避免既有檔案被截斷。 2. 逐字元版：int 接 fgetc；區塊版：以 n 傳遞有效長度。 3. 結束後查 ferror 與 fclose；任何失敗都不能宣稱複製完成。 若使用 wb，開檔當下就可能毀掉原內容。fwrite 必須寫本次 fread 回傳的 n，而不是固定 4096。

【課堂提問】
區塊版的 fread(buffer,1,sizeof buffer,in) 回傳的是什麼？

【參考答案】
回傳完整元素數；因每個元素大小設成 1 byte，所以這個案例的回傳值也就是有效位元組數。

【來源與增補】
B pp.117–128,138–146｜新增防護
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 78 頁｜案例 10｜完整程式 1/3

【本頁目標】
案例 10｜完整程式 1/3
10a_copy_character.c

【教師講解】
本頁為 10a_copy_character.c 的第 1/3 段，對應原始檔第 1～13 行。所有程式頁依序接續，沒有省略程式碼。驗證來源與目的路徑參數；來源以 rb 開啟，目的以 wbx 建立，已存在的目的檔必須保留不動。

【程式帶讀】
對應 10a_copy_character.c，原始碼第 1～13 行。這是完整檔案第 1/3 段，依頁序合併即可，不需補寫省略片段。提醒學生先讀題目頁的輸入資料前提；程式使用的語法片段與整體錯誤契約應一起理解。

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fputs("usage: copy_character source new_destination\n", stderr);
        return EXIT_FAILURE;
    }
    FILE *in = fopen(argv[1], "rb");
    if (in == NULL) {
        fputs("Cannot open source\n", stderr);
        return EXIT_FAILURE;
    }

【課堂提問】
區塊版的 fread(buffer,1,sizeof buffer,in) 回傳的是什麼？

【參考答案】
回傳完整元素數；因每個元素大小設成 1 byte，所以這個案例的回傳值也就是有效位元組數。

【來源與增補】
B pp.117–128,138–146｜新增防護
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 79 頁｜案例 10｜完整程式 2/3

【本頁目標】
案例 10｜完整程式 2/3
10a_copy_character.c

【教師講解】
本頁為 10a_copy_character.c 的第 2/3 段，對應原始檔第 14～26 行。所有程式頁依序接續，沒有省略程式碼。目的建立失敗就關閉已取得的來源；成功後用 int 接收 fgetc，以 EOF 作讀取結束訊號，逐字元檢查 fputc。

【程式帶讀】
對應 10a_copy_character.c，原始碼第 14～26 行。這是完整檔案第 2/3 段，依頁序合併即可，不需補寫省略片段。提醒學生先讀題目頁的輸入資料前提；程式使用的語法片段與整體錯誤契約應一起理解。

    FILE *out = fopen(argv[2], "wbx");
    if (out == NULL) {
        fputs("Destination exists or cannot be created\n", stderr);
        fclose(in);
        return EXIT_FAILURE;
    }
    int ch, failed = 0;
    while ((ch = fgetc(in)) != EOF) {
        if (fputc(ch, out) == EOF) {
            failed = 1;
            break;
        }
    }

【課堂提問】
區塊版的 fread(buffer,1,sizeof buffer,in) 回傳的是什麼？

【參考答案】
回傳完整元素數；因每個元素大小設成 1 byte，所以這個案例的回傳值也就是有效位元組數。

【來源與增補】
B pp.117–128,138–146｜新增防護
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 80 頁｜案例 10｜完整程式 3/3

【本頁目標】
案例 10｜完整程式 3/3
10a_copy_character.c

【教師講解】
本頁為 10a_copy_character.c 的第 3/3 段，對應原始檔第 27～38 行。所有程式頁依序接續，沒有省略程式碼。迴圈結束不立即宣告成功；檢查 ferror 及兩次 fclose。任何失敗只移除本次新建的部分目的檔，並回傳失敗。

【程式帶讀】
對應 10a_copy_character.c，原始碼第 27～38 行。這是完整檔案第 3/3 段，依頁序合併即可，不需補寫省略片段。提醒學生先讀題目頁的輸入資料前提；程式使用的語法片段與整體錯誤契約應一起理解。

    if (ferror(in)) failed = 1;
    if (fclose(in) != 0) failed = 1;
    if (fclose(out) != 0) failed = 1;
    if (failed) {
        fputs("Copy failed; removing partial output\n", stderr);
        if (remove(argv[2]) != 0)
            fputs("Warning: partial output remains\n", stderr);
        return EXIT_FAILURE;
    }
    puts("Copy complete");
    return EXIT_SUCCESS;
}

【課堂提問】
區塊版的 fread(buffer,1,sizeof buffer,in) 回傳的是什麼？

【參考答案】
回傳完整元素數；因每個元素大小設成 1 byte，所以這個案例的回傳值也就是有效位元組數。

【來源與增補】
B pp.117–128,138–146｜新增防護
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 81 頁｜案例 10｜完整程式 1/3

【本頁目標】
案例 10｜完整程式 1/3
10b_copy_block.c

【教師講解】
本頁為 10b_copy_block.c 的第 1/3 段，對應原始檔第 1～14 行。所有程式頁依序接續，沒有省略程式碼。建立與逐字元版相同的命令列與開檔契約。先 rb 開來源，再以 wbx 拒絕覆寫目的檔。

【程式帶讀】
對應 10b_copy_block.c，原始碼第 1～14 行。這是完整檔案第 1/3 段，依頁序合併即可，不需補寫省略片段。提醒學生先讀題目頁的輸入資料前提；程式使用的語法片段與整體錯誤契約應一起理解。

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fputs("usage: copy_block source new_destination\n", stderr);
        return EXIT_FAILURE;
    }
    FILE *in = fopen(argv[1], "rb");
    if (in == NULL) {
        fputs("Cannot open source\n", stderr);
        return EXIT_FAILURE;
    }
    FILE *out = fopen(argv[2], "wbx");

【課堂提問】
區塊版的 fread(buffer,1,sizeof buffer,in) 回傳的是什麼？

【參考答案】
回傳完整元素數；因每個元素大小設成 1 byte，所以這個案例的回傳值也就是有效位元組數。

【來源與增補】
B pp.117–128,138–146｜新增防護
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 82 頁｜案例 10｜完整程式 2/3

【本頁目標】
案例 10｜完整程式 2/3
10b_copy_block.c

【教師講解】
本頁為 10b_copy_block.c 的第 2/3 段，對應原始檔第 15～27 行。所有程式頁依序接續，沒有省略程式碼。使用 unsigned char buffer[4096] 搬移原始 bytes。fread 的 size 為 1，回傳值因此直接是有效 byte 數 n；fwrite 必須使用 n。

【程式帶讀】
對應 10b_copy_block.c，原始碼第 15～27 行。這是完整檔案第 2/3 段，依頁序合併即可，不需補寫省略片段。提醒學生先讀題目頁的輸入資料前提；程式使用的語法片段與整體錯誤契約應一起理解。

    if (out == NULL) {
        fputs("Destination exists or cannot be created\n", stderr);
        fclose(in);
        return EXIT_FAILURE;
    }
    unsigned char buffer[4096];
    size_t n;
    int failed = 0;
    while ((n = fread(buffer, 1, sizeof buffer, in)) > 0) {
        if (fwrite(buffer, 1, n, out) != n) {
            failed = 1;
            break;
        }

【課堂提問】
區塊版的 fread(buffer,1,sizeof buffer,in) 回傳的是什麼？

【參考答案】
回傳完整元素數；因每個元素大小設成 1 byte，所以這個案例的回傳值也就是有效位元組數。

【來源與增補】
B pp.117–128,138–146｜新增防護
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 83 頁｜案例 10｜完整程式 3/3

【本頁目標】
案例 10｜完整程式 3/3
10b_copy_block.c

【教師講解】
本頁為 10b_copy_block.c 的第 3/3 段，對應原始檔第 28～40 行。所有程式頁依序接續，沒有省略程式碼。短讀後檢查來源錯誤，並檢查輸入與輸出的關閉結果。失敗時清理本次新建的部分檔案；成功才印出 Copy complete。

【程式帶讀】
對應 10b_copy_block.c，原始碼第 28～40 行。這是完整檔案第 3/3 段，依頁序合併即可，不需補寫省略片段。提醒學生先讀題目頁的輸入資料前提；程式使用的語法片段與整體錯誤契約應一起理解。

    }
    if (ferror(in)) failed = 1;
    if (fclose(in) != 0) failed = 1;
    if (fclose(out) != 0) failed = 1;
    if (failed) {
        fputs("Copy failed; removing partial output\n", stderr);
        if (remove(argv[2]) != 0)
            fputs("Warning: partial output remains\n", stderr);
        return EXIT_FAILURE;
    }
    puts("Copy complete");
    return EXIT_SUCCESS;
}

【課堂提問】
區塊版的 fread(buffer,1,sizeof buffer,in) 回傳的是什麼？

【參考答案】
回傳完整元素數；因每個元素大小設成 1 byte，所以這個案例的回傳值也就是有效位元組數。

【來源與增補】
B pp.117–128,138–146｜新增防護
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 84 頁｜案例 10｜測試與常見錯誤

【本頁目標】
案例 10｜測試與常見錯誤
先預測結果，再執行；不只測一般資料。

【教師講解】
依表格逐組測試，確認返回狀態、stdout、stderr 與檔案內容。若使用 wb，開檔當下就可能毀掉原內容。fwrite 必須寫本次 fread 回傳的 n，而不是固定 4096。 對隨機或平台相依輸出，應測試性質，而不是把單一次執行結果當成唯一答案。

【測試判讀】
二進位｜含 00、1A、FF 的檔案｜位元組完全一致｜不能當成 C 字串
空檔｜0 bytes｜建立 0-byte 目的檔｜EOF 不是錯誤
區塊邊界｜4096 / 4097 bytes｜無遺失、無額外資料｜最後一塊只寫 n bytes
目的已存在｜既有檔內容 KEEP｜失敗；KEEP 不變｜x 模式拒絕覆寫
同一路徑｜來源=目的｜失敗；來源不變｜避免先截斷來源
本頁列出教學代表測試。附件測試器另外包含一般值、邊界與錯誤路徑；未模擬磁碟滿載、斷電、併發或所有作業系統。

【課堂提問】
區塊版的 fread(buffer,1,sizeof buffer,in) 回傳的是什麼？

【參考答案】
回傳完整元素數；因每個元素大小設成 1 byte，所以這個案例的回傳值也就是有效位元組數。

【來源與增補】
B pp.117–128,138–146｜新增防護
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 85 頁｜緩衝區｜函式返回，不代表資料已永久存入磁碟

【本頁目標】
緩衝區｜函式返回，不代表資料已永久存入磁碟
程式 → stdio buffer → 主機環境／作業系統 → 儲存裝置

【教師講解】
沿四層流程說明 buffering 減少細碎的資料搬移。fflush 把 stdio 緩衝區送到主機環境，不是斷電持久化保證。fclose 也會處理尚未寫出的資料，錯誤可能到此時才被發現。將性能與可靠性分開說明，不能因每個 printf 看似成功就省略關閉檢查。

【課堂提問】
fflush(fp)==0 是否保證突然斷電後檔案仍完整？

【參考答案】
不是。它是標準 I/O 層的刷新成功，不是所有儲存層的持久化或交易保證。

【來源與增補】
B pp.49–57
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 86 頁｜setvbuf 與 fflush｜時間點與生命週期比呼叫名稱重要

【本頁目標】
setvbuf 與 fflush｜時間點與生命週期比呼叫名稱重要
先設緩衝，再做其他串流操作；使用者提供的 buffer 不能提早失效。

【教師講解】
原稿 p.57 在已經輸出後才 setvbuf，與前頁規則矛盾，本教材明確修正。若 buffer 是區域陣列，其生命週期必須涵蓋串流使用期間。setbuf 沒有回傳狀態，不代表 C17 已移除它。清掉不合法輸入應讀走剩餘字元或採整行解析，不使用 fflush(stdin)。

【表格帶讀】
工具／模式｜用途｜使用條件與注意
_IOFBF｜全緩衝｜適合區塊搬移；由大小等條件觸發刷新
_IOLBF｜行緩衝｜與換行及互動輸入等條件相關
_IONBF｜無緩衝｜不是所有輸出都需要如此設定
setvbuf(fp,buf,mode,n)｜設定模式／大小／buffer｜開啟後、其他 I/O 前呼叫；檢查非零失敗
fflush(fp)｜刷新適用的輸出串流｜成功 0；失敗 EOF；不是清除輸入
setbuf / fflush(stdin)｜舊介面／常見誤用｜setbuf 仍在 C17；fflush(stdin) 不可攜

【課堂提問】
可以先 printf 提示，再 setvbuf(stdout,...) 嗎？

【參考答案】
可攜寫法應先設定緩衝，再對該串流進行其他 I/O；不要照抄原稿順序錯誤的示例。

【來源與增補】
B pp.51–57｜W1 §7.21.5
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。
【外部校核來源】
W1 — https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf （C11 委員會草案，引用與 C17 共通的核心條款）
W2 — https://learn.microsoft.com/en-us/cpp/overview/install-c17-support?view=msvc-170
W3 — https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/fopen-wfopen?view=msvc-170
W4 — https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/strtol-wcstol-strtol-l-wcstol-l?view=msvc-170

---

### 投影片第 87 頁｜檔案定位｜把記錄索引換成 byte offset

【本頁目標】
檔案定位｜把記錄索引換成 byte offset
固定長度二進位記錄：offset = index × record_size。

【教師講解】
以五筆 int 記錄示範索引 2 的位置，但數字 4 bytes 只作圖解假設。fseek 傳入 long 偏移及 SEEK_SET/CUR/END 原點，回傳 0 代表定位操作成功；定位到某處不代表那裡有完整記錄，仍要檢查 fread。ftell 失敗可回傳 −1L。更新串流還須符合讀寫切換規則。

【本頁收斂】
位置是下一次讀寫的起點；讀完一筆後，位置已前進。

【課堂提問】
fseek 成功能證明第 100 筆記錄存在嗎？

【參考答案】
不能。可能只是成功調整位置；要讀到指定數量的完整記錄，仍需檢查 fread 的回傳值。

【來源與增補】
B pp.148–156
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 88 頁｜定位的邊界｜文字串流不適合任意 byte 算術

【本頁目標】
定位的邊界｜文字串流不適合任意 byte 算術
把「回到曾經的位置」與「計算位元組偏移」分開。

【教師講解】
保留原稿的五個定位函式，但修正容易被理解成「fpos_t 永遠支援任意大檔」的說法。文字模式可能存在編碼與換行轉換，ftell 值適合當作可恢復的位置標記，不一定是可自行運算的檔案 byte 數。clearerr 只清狀態，不能被當作任何錯誤的修復。

【表格帶讀】
介面／情境｜可用方式｜不可過度推論
二進位 fseek / ftell｜以 byte 計數，注意 long 可表示範圍｜SEEK_END 並非每個二進位串流都必須支援
文字 fseek｜offset=0，或用先前 ftell 值配 SEEK_SET｜不要對文字 ftell 結果任意加減
rewind(fp)｜回到開頭並清除 EOF／錯誤指標｜無回傳值，難以直接檢查定位失敗
fgetpos / fsetpos｜以 fpos_t 保存與還原位置｜fpos_t 未必是整數，也非無限檔案大小保證
clearerr(fp)｜清除 EOF 與 error 指標｜不移動位置，也不修復故障原因

【課堂提問】
clearerr(fp) 後，檔案位置會回到開頭嗎？

【參考答案】
不會。它只清除 EOF 和錯誤指標；位置需要 rewind、fseek 或其他定位函式處理。

【來源與增補】
B pp.112–114,152–159｜勘誤／補充
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 89 頁｜案例 11｜直接更新庫存檔的第 3 筆

【本頁目標】
案例 11｜直接更新庫存檔的第 3 筆
完整題目：先確認任務、輸入、輸出與限制

【教師講解】
先不要展示解答。請學生用自己的話重述任務，再指出輸入格式、輸出格式與無效資料的處理。建立五筆整數庫存的二進位檔，讀出索引 2 的舊值，再直接改成 99，最後重讀整個檔案確認結果。 目的檔必須不存在；第 3 筆＝索引 2。原生 int 格式僅限相同實作讀寫；這是定位練習，不提供交易式還原。

【完整規格】
任務：建立五筆整數庫存的二進位檔，讀出索引 2 的舊值，再直接改成 99，最後重讀整個檔案確認結果。
輸入：命令列：stock_update new_binary_file。初始資料固定為 10、20、35、40、50。
輸出：顯示 old=35 new=99，及更新後的五筆整數。
限制：目的檔必須不存在；第 3 筆＝索引 2。原生 int 格式僅限相同實作讀寫；這是定位練習，不提供交易式還原。
範例輸入：
stock_update stock.bin
範例輸出：
old=35 new=99
10 20 99 40 50

【課堂提問】
讀完索引 2 後，為什麼不能直接 fwrite 覆寫該筆？

【參考答案】
讀取後檔案位置已前進到下一筆，且更新串流的讀→寫需要定位；必須重新 fseek 回索引 2 的起點。

【來源與增補】
B pp.138–160｜原庫存案例改編
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 90 頁｜案例 11｜核心解法與圖解

【本頁目標】
案例 11｜核心解法與圖解
直接更新庫存檔的第 3 筆

【教師講解】
依下列順序帶讀圖解：1. 先 wbx 寫入初始陣列，關閉後以 rb+ 重開。 2. 位置 = 2×sizeof(int)；先 fseek 再讀出舊值。 3. 讀→寫前重新定位；寫→讀前再定位到檔首。 第 k 筆以 0-based 索引 k 計算 offset；更換平台不能假設 int 永遠是 4 bytes，也不能忽略位元組順序。

【課堂提問】
讀完索引 2 後，為什麼不能直接 fwrite 覆寫該筆？

【參考答案】
讀取後檔案位置已前進到下一筆，且更新串流的讀→寫需要定位；必須重新 fseek 回索引 2 的起點。

【來源與增補】
B pp.138–160｜原庫存案例改編
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 91 頁｜案例 11｜完整程式 1/3

【本頁目標】
案例 11｜完整程式 1/3
11_stock_update.c

【教師講解】
本頁為 11_stock_update.c 的第 1/3 段，對應原始檔第 1～15 行。所有程式頁依序接續，沒有省略程式碼。建立含五筆原生 int 的新二進位檔。使用 wbx 確保不覆寫既有檔案，並檢查最初 fwrite 與 fclose。

【程式帶讀】
對應 11_stock_update.c，原始碼第 1～15 行。這是完整檔案第 1/3 段，依頁序合併即可，不需補寫省略片段。提醒學生先讀題目頁的輸入資料前提；程式使用的語法片段與整體錯誤契約應一起理解。

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int stock[5] = {10, 20, 35, 40, 50};
    int updated = 99, previous;
    int failed = 0;
    if (argc != 2) {
        fputs("usage: stock_update new_binary_file\n", stderr);
        return EXIT_FAILURE;
    }
    FILE *fp = fopen(argv[1], "wbx");
    if (fp == NULL) {
        fputs("Cannot create new stock file\n", stderr);
        return EXIT_FAILURE;

【課堂提問】
讀完索引 2 後，為什麼不能直接 fwrite 覆寫該筆？

【參考答案】
讀取後檔案位置已前進到下一筆，且更新串流的讀→寫需要定位；必須重新 fseek 回索引 2 的起點。

【來源與增補】
B pp.138–160｜原庫存案例改編
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 92 頁｜案例 11｜完整程式 2/3

【本頁目標】
案例 11｜完整程式 2/3
11_stock_update.c

【教師講解】
本頁為 11_stock_update.c 的第 2/3 段，對應原始檔第 16～30 行。所有程式頁依序接續，沒有省略程式碼。以 rb+ 重新開啟，計算索引 2 的 byte 位移。先定位再讀舊值；讀取會前進，因此改寫前必須再次定位。

【程式帶讀】
對應 11_stock_update.c，原始碼第 16～30 行。這是完整檔案第 2/3 段，依頁序合併即可，不需補寫省略片段。提醒學生先讀題目頁的輸入資料前提；程式使用的語法片段與整體錯誤契約應一起理解。

    }
    if (fwrite(stock, sizeof stock[0], 5, fp) != 5) failed = 1;
    if (fclose(fp) != 0) failed = 1;
    if (failed) {
        fputs("Initial write failed\n", stderr);
        return EXIT_FAILURE;
    }
    fp = fopen(argv[1], "rb+");
    if (fp == NULL) {
        fputs("Cannot reopen stock file\n", stderr);
        return EXIT_FAILURE;
    }
    long offset = 2L * (long)sizeof stock[0];
    if (fseek(fp, offset, SEEK_SET) != 0 ||
        fread(&previous, sizeof previous, 1, fp) != 1 ||

【課堂提問】
讀完索引 2 後，為什麼不能直接 fwrite 覆寫該筆？

【參考答案】
讀取後檔案位置已前進到下一筆，且更新串流的讀→寫需要定位；必須重新 fseek 回索引 2 的起點。

【來源與增補】
B pp.138–160｜原庫存案例改編
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 93 頁｜案例 11｜完整程式 3/3

【本頁目標】
案例 11｜完整程式 3/3
11_stock_update.c

【教師講解】
本頁為 11_stock_update.c 的第 3/3 段，對應原始檔第 31～44 行。所有程式頁依序接續，沒有省略程式碼。寫入新值後定位回開頭以便重新讀取。檢查讀寫與關閉結果，列出舊值、新值與完整陣列。此格式只適用同一實作，不提供跨平台或交易保證。

【程式帶讀】
對應 11_stock_update.c，原始碼第 31～44 行。這是完整檔案第 3/3 段，依頁序合併即可，不需補寫省略片段。提醒學生先讀題目頁的輸入資料前提；程式使用的語法片段與整體錯誤契約應一起理解。

        fseek(fp, offset, SEEK_SET) != 0 ||
        fwrite(&updated, sizeof updated, 1, fp) != 1 ||
        fseek(fp, 0L, SEEK_SET) != 0 ||
        fread(stock, sizeof stock[0], 5, fp) != 5) {
        fputs("Record update/read failed\n", stderr);
        failed = 1;
    }
    if (fclose(fp) != 0) failed = 1;
    if (failed) return EXIT_FAILURE;
    printf("old=%d new=%d\n", previous, stock[2]);
    for (int i = 0; i < 5; ++i)
        printf("%d%c", stock[i], i == 4 ? '\n' : ' ');
    return EXIT_SUCCESS;
}

【課堂提問】
讀完索引 2 後，為什麼不能直接 fwrite 覆寫該筆？

【參考答案】
讀取後檔案位置已前進到下一筆，且更新串流的讀→寫需要定位；必須重新 fseek 回索引 2 的起點。

【來源與增補】
B pp.138–160｜原庫存案例改編
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 94 頁｜案例 11｜測試與常見錯誤

【本頁目標】
案例 11｜測試與常見錯誤
先預測結果，再執行；不只測一般資料。

【教師講解】
依表格逐組測試，確認返回狀態、stdout、stderr 與檔案內容。第 k 筆以 0-based 索引 k 計算 offset；更換平台不能假設 int 永遠是 4 bytes，也不能忽略位元組順序。 對隨機或平台相依輸出，應測試性質，而不是把單一次執行結果當成唯一答案。

【測試判讀】
一般｜新檔 stock.bin｜35→99，其餘不變｜精準更新一筆
檔案內容｜5 個原生 int｜10 20 99 40 50｜整檔驗證
既有檔案｜再次執行同檔名｜失敗；不重建｜避免覆寫
漏參數｜stock_update｜usage；失敗｜命令列契約
本頁列出教學代表測試。附件測試器另外包含一般值、邊界與錯誤路徑；未模擬磁碟滿載、斷電、併發或所有作業系統。

【課堂提問】
讀完索引 2 後，為什麼不能直接 fwrite 覆寫該筆？

【參考答案】
讀取後檔案位置已前進到下一筆，且更新串流的讀→寫需要定位；必須重新 fseek 回索引 2 的起點。

【來源與增補】
B pp.138–160｜原庫存案例改編
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 95 頁｜其他檔案工具｜名稱、串流與暫存資料各有介面

【本頁目標】
其他檔案工具｜名稱、串流與暫存資料各有介面
保留原稿工具，但把限制與風險一起教。

【教師講解】
這些工具容易因為函式名稱直觀就被誤用。tmpnam 並沒有保留那個名稱，取得名字到開檔之間可能改變；因此不可教成已保證安全建立。remove 和 rename 的成功與否仍依回傳值確認。寬字元與可變參數的延伸保留索引，不在此處跳過必要前置概念。

【表格帶讀】
介面｜處理對象｜正確期待
freopen｜既有串流｜可重新關聯 stdin/stdout；仍需檢查 NULL
tmpfile｜暫存串流｜以更新二進位模式建立；關閉或正常結束時移除
tmpnam｜候選檔名｜只產生名稱、不建立檔案；有先後競爭風險
remove｜檔名｜成功 0；失敗非零；不保證可移除使用中的檔
rename｜舊檔名與新檔名｜成功 0；新名稱已存在時效果依實作
v*printf / 寬字元 I/O｜va_list / wchar_t｜延伸介面；與本教材 byte I/O 核心分層學習

【課堂提問】
tmpnam 回傳一個名字，代表檔案已建立好了嗎？

【參考答案】
沒有。它只產生名稱；需要另行建立，而兩個動作之間存在狀態改變的可能。

【來源與增補】
B pp.35–37,43–48,58–60,65,162
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 96 頁｜I/O 選擇表｜依資料單位選函式，再檢查回傳

【本頁目標】
I/O 選擇表｜依資料單位選函式，再檢查回傳
同一問題可用不同 I/O 單位，但成功條件不能含糊。

【教師講解】
讓學生從要處理的是欄位、字元、行還是區塊開始選擇，而不是慣性使用 scanf。最後一列是本教材新增的強健輸入流程，將輸入取得與數字轉換分離。任何一欄都應列出失敗時如何停止或恢復，下一單元會把這些策略統一。

【表格帶讀】
需要處理的單位｜讀取｜輸出｜成功判斷重點
格式化欄位｜scanf / fscanf｜printf / fprintf｜指定數是否足夠；輸出是否負值
單一字元｜getchar / fgetc｜putchar / fputc｜int 與 EOF；錯誤指標
文字行／字串｜fgets｜puts / fputs｜NULL、截斷、換行、終止字元
二進位區塊｜fread｜fwrite｜完整元素數；最後一塊長度
記憶體中的字串｜sscanf｜snprintf｜完整解析；輸出截斷
任意數字文字｜fgets + strtol｜驗證後再格式化｜end、ERANGE、業務範圍

【課堂提問】
大量二進位資料要用 fgets 配 printf("%s") 嗎？

【參考答案】
不應；二進位可能包含零 byte，也不具字串結尾保證。應使用 fread/fwrite 和有效長度。

【來源與增補】
B pp.61–172｜新增彙整
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 97 頁｜03｜錯誤處理：分辨錯誤來源，才能選對處置

【本頁目標】
03｜錯誤處理：分辨錯誤來源，才能選對處置
輸入錯誤、外部資源失敗、內部邏輯違反，是不同問題。

【教師講解】
以三類錯誤建立分類。使用者輸入不合法應能用一般控制流程拒絕；檔案失敗需要診斷並清理；內部不變量違反可由 assert 協助找出開發缺陷。不是所有錯誤都應重試，也不是全部都應 abort。成功訊息與返回狀態要和真正完成的副作用一致。

【課堂提問】
使用者輸入 101 分，適合用 assert 中止程式嗎？

【參考答案】
不適合以 assert 作主要輸入驗證。這是可預期的外部資料錯誤，應回報原因並以正常流程處理。

【來源與增補】
C pp.1–9｜B pp.110–116
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 98 頁｜回傳值、ferror、errno｜三個不同層次的訊息

【本頁目標】
回傳值、ferror、errno｜三個不同層次的訊息
先看函式的成功／失敗契約，再決定還要查看哪個診斷來源。

【教師講解】
errno 並不是每次呼叫都會自動清除的萬用旗標。先用 fopen 是否 NULL、fread 是否足量等回傳值判定發生什麼事，再依該函式規格查診斷。數字轉換與數學函式的 errno 檢查方式也不完全相同；保存後才做其他操作，避免覆寫。

【本頁收斂】
先判斷操作結果；需要診斷時，立即保存 errno。

【課堂提問】
errno!=0 可以單獨證明剛才的 fopen 失敗嗎？

【參考答案】
不可以；可能是先前留下的值。fopen 成功與否看回傳指標，errno 只依平台與函式規格補充診斷。

【來源與增補】
C pp.6–9｜B pp.110–114
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 99 頁｜perror 與 strerror｜回報原因，不是自動恢復

【本頁目標】
perror 與 strerror｜回報原因，不是自動恢復
錯誤描述要包含操作、檔名或行號，不能只丟一句 Error。

【教師講解】
指出原稿 POSIX 標示的意義，不把平台擴充碼一律當成 ISO C 規定。perror 直接輸出，strerror 提供文字給呼叫者自行組合；兩者都不會修正檔案或重新執行操作。最好同时提供程式自己的上下文，而不是只依賴系統字串。

【表格帶讀】
工具／資訊｜來源與結果｜使用提醒
perror("open")｜依目前 errno 寫入 stderr｜先確認 errno 是相關失敗的診斷
strerror(saved_errno)｜回傳對應的說明文字｜文字與語言依實作，不做固定字串比對
EDOM / ERANGE / EILSEQ｜ISO C 提供的錯誤巨集｜定義域、範圍／極點、非法位元組序列
ENOENT / EACCES 等｜POSIX／平台常見錯誤碼｜不可當成所有 ISO C 實作必備
檔名／行號／操作｜程式自己掌握的上下文｜讓使用者能找到哪個資料或步驟失敗

【課堂提問】
把 strerror 的英文句子寫死在跨平台測試裡，穩定嗎？

【參考答案】
不穩定。應檢查回傳狀態或錯誤碼的意義，說明文字可能因平台或語系而不同。

【來源與增補】
C pp.2,6–9｜W1 §7.5,7.21.10,7.24.6
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。
【外部校核來源】
W1 — https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf （C11 委員會草案，引用與 C17 共通的核心條款）
W2 — https://learn.microsoft.com/en-us/cpp/overview/install-c17-support?view=msvc-170
W3 — https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/fopen-wfopen?view=msvc-170
W4 — https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/strtol-wcstol-strtol-l-wcstol-l?view=msvc-170

---

### 投影片第 100 頁｜案例 12｜嚴格讀取一個 0～100 分的整數

【本頁目標】
案例 12｜嚴格讀取一個 0～100 分的整數
完整題目：先確認任務、輸入、輸出與限制

【教師講解】
先不要展示解答。請學生用自己的話重述任務，再指出輸入格式、輸出格式與無效資料的處理。讀入一行成績，不只判斷是否以數字開頭，還要拒絕超大整數、尾端垃圾、空白行與超長輸入。 數值 0～100；單行最多 126 bytes（不含 LF）；不接受小數或第二個值。最末行可不含換行。

【完整規格】
任務：讀入一行成績，不只判斷是否以數字開頭，還要拒絕超大整數、尾端垃圾、空白行與超長輸入。
輸入：標準輸入的一行無 NUL 文字；允許數字前後空白及正號。
輸出：有效：score=value。無效：stderr 回報 No number、Trailing text、Out of range 等。
限制：數值 0～100；單行最多 126 bytes（不含 LF）；不接受小數或第二個值。最末行可不含換行。
範例輸入：
  +86
範例輸出：
score=86

【課堂提問】
為何 *out=(int)value 要放在所有檢查之後？

【參考答案】
只有值已落在 0～100，且沒有尾端垃圾時才承諾成功；如此失敗不會把半合法結果交給呼叫端。

【來源與增補】
B pp.103–104,132–135｜C pp.6–9｜新增
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 101 頁｜案例 12｜核心解法與圖解

【本頁目標】
案例 12｜核心解法與圖解
嚴格讀取一個 0～100 分的整數

【教師講解】
依下列順序帶讀圖解：1. fgets 限制讀取容量；過長輸入整行拒絕。 2. errno=0 後 strtol，保留 end 指標。 3. 依序檢查沒讀到數字、ERANGE／範圍、尾端非空白；成功才設定輸出值。 atoi 無法清楚區分「合法 0」與轉換失敗；只看 errno 也無法偵測 86abc。

【課堂提問】
為何 *out=(int)value 要放在所有檢查之後？

【參考答案】
只有值已落在 0～100，且沒有尾端垃圾時才承諾成功；如此失敗不會把半合法結果交給呼叫端。

【來源與增補】
B pp.103–104,132–135｜C pp.6–9｜新增
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 102 頁｜案例 12｜完整程式 1/3

【本頁目標】
案例 12｜完整程式 1/3
12_strict_score.c

【教師講解】
本頁為 12_strict_score.c 的第 1/3 段，對應原始檔第 1～15 行。所有程式頁依序接續，沒有省略程式碼。狀態 enum 把成功、缺少數字、尾端雜字及範圍錯誤分開。strtol 前將 errno 清零，轉換後用 end 與 ERANGE 判斷。

【程式帶讀】
對應 12_strict_score.c，原始碼第 1～15 行。這是完整檔案第 1/3 段，依頁序合併即可，不需補寫省略片段。提醒學生先讀題目頁的輸入資料前提；程式使用的語法片段與整體錯誤契約應一起理解。

#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Status { OK, NO_NUMBER, TRAILING, OUT_OF_RANGE };

static enum Status parse_score(const char *text, int *out) {
    char *end;
    errno = 0;
    long value = strtol(text, &end, 10);
    if (end == text) return NO_NUMBER;
    if (errno == ERANGE || value < 0 || value > 100)
        return OUT_OF_RANGE;

【課堂提問】
為何 *out=(int)value 要放在所有檢查之後？

【參考答案】
只有值已落在 0～100，且沒有尾端垃圾時才承諾成功；如此失敗不會把半合法結果交給呼叫端。

【來源與增補】
B pp.103–104,132–135｜C pp.6–9｜新增
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 103 頁｜案例 12｜完整程式 2/3

【本頁目標】
案例 12｜完整程式 2/3
12_strict_score.c

【教師講解】
本頁為 12_strict_score.c 的第 2/3 段，對應原始檔第 16～29 行。所有程式頁依序接續，沒有省略程式碼。略過尾端空白時把字元轉成 unsigned char 再交給 isspace。全部合法才寫入 *out。主程式以 fgets 控制輸入長度。

【程式帶讀】
對應 12_strict_score.c，原始碼第 16～29 行。這是完整檔案第 2/3 段，依頁序合併即可，不需補寫省略片段。提醒學生先讀題目頁的輸入資料前提；程式使用的語法片段與整體錯誤契約應一起理解。

    while (isspace((unsigned char)*end)) ++end;
    if (*end != '\0') return TRAILING;
    *out = (int)value;
    return OK;
}

int main(void) {
    char line[128];
    int score;
    if (fgets(line, sizeof line, stdin) == NULL) {
        fputs(ferror(stdin) ? "Read error\n" : "No input\n", stderr);
        return EXIT_FAILURE;
    }
    if (strchr(line, '\n') == NULL && !feof(stdin)) {

【課堂提問】
為何 *out=(int)value 要放在所有檢查之後？

【參考答案】
只有值已落在 0～100，且沒有尾端垃圾時才承諾成功；如此失敗不會把半合法結果交給呼叫端。

【來源與增補】
B pp.103–104,132–135｜C pp.6–9｜新增
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 104 頁｜案例 12｜完整程式 3/3

【本頁目標】
案例 12｜完整程式 3/3
12_strict_score.c

【教師講解】
本頁為 12_strict_score.c 的第 3/3 段，對應原始檔第 30～43 行。所有程式頁依序接續，沒有省略程式碼。主程式拒絕過長或讀取失敗的資料，依狀態回報可理解的錯誤文字。只有 OK 才使用 score；不要把有效輸出值和錯誤碼混用。

【程式帶讀】
對應 12_strict_score.c，原始碼第 30～43 行。這是完整檔案第 3/3 段，依頁序合併即可，不需補寫省略片段。提醒學生先讀題目頁的輸入資料前提；程式使用的語法片段與整體錯誤契約應一起理解。

        fputs("Line too long (max 126 bytes)\n", stderr);
        return EXIT_FAILURE;
    }
    enum Status status = parse_score(line, &score);
    if (status != OK) {
        const char *message[] = {
            "OK", "No number", "Trailing text", "Out of range"
        };
        fprintf(stderr, "%s\n", message[status]);
        return EXIT_FAILURE;
    }
    printf("score=%d\n", score);
    return EXIT_SUCCESS;
}

【課堂提問】
為何 *out=(int)value 要放在所有檢查之後？

【參考答案】
只有值已落在 0～100，且沒有尾端垃圾時才承諾成功；如此失敗不會把半合法結果交給呼叫端。

【來源與增補】
B pp.103–104,132–135｜C pp.6–9｜新增
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 105 頁｜案例 12｜測試與常見錯誤

【本頁目標】
案例 12｜測試與常見錯誤
先預測結果，再執行；不只測一般資料。

【教師講解】
依表格逐組測試，確認返回狀態、stdout、stderr 與檔案內容。atoi 無法清楚區分「合法 0」與轉換失敗；只看 errno 也無法偵測 86abc。 對隨機或平台相依輸出，應測試性質，而不是把單一次執行結果當成唯一答案。

【測試判讀】
一般｜  +86  ｜score=86｜允許前後空白
尾端垃圾｜86abc｜Trailing text｜不能只接受數字前綴
超大整數｜60 個 9｜Out of range｜使用 ERANGE
空白行｜只有空白／換行｜No number｜end==text
超長一行｜200 個字元｜Line too long｜不可默默截斷
本頁列出教學代表測試。附件測試器另外包含一般值、邊界與錯誤路徑；未模擬磁碟滿載、斷電、併發或所有作業系統。

【課堂提問】
為何 *out=(int)value 要放在所有檢查之後？

【參考答案】
只有值已落在 0～100，且沒有尾端垃圾時才承諾成功；如此失敗不會把半合法結果交給呼叫端。

【來源與增補】
B pp.103–104,132–135｜C pp.6–9｜新增
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 106 頁｜assert｜記錄內部不變量，不替代外部驗證

【本頁目標】
assert｜記錄內部不變量，不替代外部驗證
NDEBUG 會讓 assert 的運算式不被執行；裡面不能放必要副作用。

【教師講解】
將輸入邊界 if 與內部檢查 assert 並列。原稿建議完成後關閉 assert，本教材不把它當作一律適用的規則；是否停用應依專案需求與測試政策。核心要求是即使 assert 被停用，必要的輸入、I/O 與資源處理仍存在。assert 失敗通常會輸出診斷並呼叫 abort，不適合期待程式正常恢復。

【本頁收斂】
assert(expr) 中的 expr 應是無必要副作用的檢查；發布政策不等於輸入驗證政策。

【課堂提問】
assert(fclose(fp)==0) 為何危險？

【參考答案】
因為定義 NDEBUG 時，fclose 可能根本不會執行。必要的資源釋放不能放在 assert 裡。

【來源與增補】
C pp.3–5
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 107 頁｜案例 13｜外部驗證與 assert 的分工

【本頁目標】
案例 13｜外部驗證與 assert 的分工
完整題目：先確認任務、輸入、輸出與限制

【教師講解】
先不要展示解答。請學生用自己的話重述任務，再指出輸入格式、輸出格式與無效資料的處理。讀入數值後計算平方根。外部不合法輸入必須以正常錯誤路徑拒絕；assert 僅記錄驗證後的內部不變量。 只接受有限且非負的值；NaN、正負無窮大與負數拒絕。定義 NDEBUG 後，外部驗證仍須有效。

【完整規格】
任務：讀入數值後計算平方根。外部不合法輸入必須以正常錯誤路徑拒絕；assert 僅記錄驗證後的內部不變量。
輸入：標準輸入：一個可由 double 表示的數值文字。
輸出：有效：輸出 sqrt=結果（小數 6 位）；無效：stderr 訊息並失敗。
限制：只接受有限且非負的值；NaN、正負無窮大與負數拒絕。定義 NDEBUG 後，外部驗證仍須有效。
範例輸入：
4
範例輸出：
sqrt=2.000000

【課堂提問】
assert 關閉之後，這個程式會接受負數嗎？

【參考答案】
不會。外部驗證在 if 中，與 assert 是否啟用無關；assert 只是協助檢查內部邏輯。

【來源與增補】
C pp.3–5｜新增防護
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 108 頁｜案例 13｜核心解法與圖解

【本頁目標】
案例 13｜核心解法與圖解
外部驗證與 assert 的分工

【教師講解】
依下列順序帶讀圖解：1. if 檢查轉換結果、isfinite(x) 與 x≥0。 2. assert(x≥0) 說明程式到這裡應滿足的條件。 3. 用一般版與 -DNDEBUG 版跑同一批測試。 不可寫 assert(scanf(...)==1)；NDEBUG 啟用時，連讀取輸入的副作用都可能消失。

【課堂提問】
assert 關閉之後，這個程式會接受負數嗎？

【參考答案】
不會。外部驗證在 if 中，與 assert 是否啟用無關；assert 只是協助檢查內部邏輯。

【來源與增補】
C pp.3–5｜新增防護
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 109 頁｜案例 13｜完整程式 1/1

【本頁目標】
案例 13｜完整程式 1/1
13_assert_sqrt.c

【教師講解】
本頁為 13_assert_sqrt.c 的第 1/1 段，對應原始檔第 1～15 行。所有程式頁依序接續，沒有省略程式碼。先用 if 檢查轉換成功、有限值與非負條件，再以無副作用的 assert 驗證內部不變條件，最後計算 sqrt。加入 -DNDEBUG 之後，外部驗證仍然執行。

【程式帶讀】
對應 13_assert_sqrt.c，原始碼第 1～15 行。這是完整檔案第 1/1 段，依頁序合併即可，不需補寫省略片段。提醒學生先讀題目頁的輸入資料前提；程式使用的語法片段與整體錯誤契約應一起理解。

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    double x;
    if (scanf("%lf", &x) != 1 || !isfinite(x) || x < 0.0) {
        fputs("Expected a finite, nonnegative value\n", stderr);
        return EXIT_FAILURE;
    }
    assert(x >= 0.0);  /* Internal invariant; no side effects. */
    printf("sqrt=%.6f\n", sqrt(x));
    return EXIT_SUCCESS;
}

【課堂提問】
assert 關閉之後，這個程式會接受負數嗎？

【參考答案】
不會。外部驗證在 if 中，與 assert 是否啟用無關；assert 只是協助檢查內部邏輯。

【來源與增補】
C pp.3–5｜新增防護
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 110 頁｜案例 13｜測試與常見錯誤

【本頁目標】
案例 13｜測試與常見錯誤
先預測結果，再執行；不只測一般資料。

【教師講解】
依表格逐組測試，確認返回狀態、stdout、stderr 與檔案內容。不可寫 assert(scanf(...)==1)；NDEBUG 啟用時，連讀取輸入的副作用都可能消失。 對隨機或平台相依輸出，應測試性質，而不是把單一次執行結果當成唯一答案。

【測試判讀】
有效｜4｜sqrt=2.000000｜正常路徑
邊界｜0｜sqrt=0.000000｜合法輸入
負數｜−1｜一般錯誤返回｜不依賴 abort
特殊值｜nan / inf｜失敗｜有限性檢查
移除 assert｜-DNDEBUG 後輸入 −1｜仍失敗｜輸入驗證不可消失
本頁列出教學代表測試。附件測試器另外包含一般值、邊界與錯誤路徑；未模擬磁碟滿載、斷電、併發或所有作業系統。

【課堂提問】
assert 關閉之後，這個程式會接受負數嗎？

【參考答案】
不會。外部驗證在 if 中，與 assert 是否啟用無關；assert 只是協助檢查內部邏輯。

【來源與增補】
C pp.3–5｜新增防護
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 111 頁｜數學錯誤｜先確認回報機制，再解釋結果

【本頁目標】
數學錯誤｜先確認回報機制，再解釋結果
函式庫診斷、浮點特殊值與一般運算子，不能全部混成 errno。

【教師講解】
原稿把 1.0/0.0 與數學函式列在同一 errno 測試中，這不構成可攜的錯誤碼示範。改用 log 的文檔化行為，並依 math_errhandling 確認 errno 機制。NaN/無窮大表示也有實作相關條件；本教材只對平台承諾的分類做測試。

【課堂提問】
看到 errno=0，能推論任何浮點計算都成功嗎？

【參考答案】
不行。一般運算子不會保證設定 errno，數學函式也可能採浮點例外旗標等機制。

【來源與增補】
C pp.7–9｜W1 §7.12.1
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。
【外部校核來源】
W1 — https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf （C11 委員會草案，引用與 C17 共通的核心條款）
W2 — https://learn.microsoft.com/en-us/cpp/overview/install-c17-support?view=msvc-170
W3 — https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/fopen-wfopen?view=msvc-170
W4 — https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/strtol-wcstol-strtol-l-wcstol-l?view=msvc-170

---

### 投影片第 112 頁｜案例 14｜觀察 log 的 errno 診斷

【本頁目標】
案例 14｜觀察 log 的 errno 診斷
完整題目：先確認任務、輸入、輸出與限制

【教師講解】
先不要展示解答。請學生用自己的話重述任務，再指出輸入格式、輸出格式與無效資料的處理。依序計算 log(−1)、log(0)、log(1)，觀察數學函式的結果與錯誤分類，不把平台輸出字串當成固定答案。 只有 math_errhandling 含 MATH_ERRNO 時，才以 errno 驗證錯誤分類。NaN/inf 文字與 strerror 訊息依實作。

【完整規格】
任務：依序計算 log(−1)、log(0)、log(1)，觀察數學函式的結果與錯誤分類，不把平台輸出字串當成固定答案。
輸入：無外部輸入；程式內的 input 陣列固定為 −1、0、1。
輸出：先印 MATH_ERRNO 是否支援；逐筆印結果與 EDOM、ERANGE、none，或不支援 errno 檢查。
限制：只有 math_errhandling 含 MATH_ERRNO 時，才以 errno 驗證錯誤分類。NaN/inf 文字與 strerror 訊息依實作。
範例輸入：
直接執行 math_errno
範例輸出：
支援 MATH_ERRNO 時：
−1 → EDOM；0 → ERANGE；1 → none

【課堂提問】
如果不在每次 log 前清除 errno，會發生什麼誤判？

【參考答案】
先前失敗留下的非零值可能仍存在，後續成功呼叫就會被誤認為失敗；仍須遵守特定函式的規格。

【來源與增補】
C pp.6–9｜勘誤／補充
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 113 頁｜案例 14｜核心解法與圖解

【本頁目標】
案例 14｜核心解法與圖解
觀察 log 的 errno 診斷

【教師講解】
依下列順序帶讀圖解：1. 先確認數學函式的錯誤回報機制。 2. 每次呼叫 log 前把 errno 設為 0。 3. log 後立即保存 errno，再交給 printf／strerror 產生說明。 原稿的 1.0/0.0 不是會替你設定 errno 的函式呼叫；不能把它當作可攜的 ERANGE 示範。

【課堂提問】
如果不在每次 log 前清除 errno，會發生什麼誤判？

【參考答案】
先前失敗留下的非零值可能仍存在，後續成功呼叫就會被誤認為失敗；仍須遵守特定函式的規格。

【來源與增補】
C pp.6–9｜勘誤／補充
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 114 頁｜案例 14｜完整程式 1/2

【本頁目標】
案例 14｜完整程式 1/2
14_math_errno.c

【教師講解】
本頁為 14_math_errno.c 的第 1/2 段，對應原始檔第 1～13 行。所有程式頁依序接續，沒有省略程式碼。先查詢 math_errhandling 是否支援 MATH_ERRNO，再逐項測試 -1、0、1。每次呼叫 log 之前都清零 errno。

【程式帶讀】
對應 14_math_errno.c，原始碼第 1～13 行。這是完整檔案第 1/2 段，依頁序合併即可，不需補寫省略片段。提醒學生先讀題目頁的輸入資料前提；程式使用的語法片段與整體錯誤契約應一起理解。

#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    const double input[] = {-1.0, 0.0, 1.0};
    int has_errno = (math_errhandling & MATH_ERRNO) != 0;
    printf("MATH_ERRNO=%d\n", has_errno);
    for (size_t i = 0; i < sizeof input / sizeof input[0]; ++i) {
        errno = 0;
        double result = log(input[i]);
        int saved_errno = errno;

【課堂提問】
如果不在每次 log 前清除 errno，會發生什麼誤判？

【參考答案】
先前失敗留下的非零值可能仍存在，後續成功呼叫就會被誤認為失敗；仍須遵守特定函式的規格。

【來源與增補】
C pp.6–9｜勘誤／補充
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 115 頁｜案例 14｜完整程式 2/2

【本頁目標】
案例 14｜完整程式 2/2
14_math_errno.c

【教師講解】
本頁為 14_math_errno.c 的第 2/2 段，對應原始檔第 14～26 行。所有程式頁依序接續，沒有省略程式碼。立即保存 log 呼叫之後的 errno，再輸出結果與診斷。未支援時明確說明不能用 errno 檢查；診斷字串和 NaN／無限大顯示方式不作跨平台固定答案。

【程式帶讀】
對應 14_math_errno.c，原始碼第 14～26 行。這是完整檔案第 2/2 段，依頁序合併即可，不需補寫省略片段。提醒學生先讀題目頁的輸入資料前提；程式使用的語法片段與整體錯誤契約應一起理解。

        printf("x=%.0f result=%g ", input[i], result);
        if (!has_errno)
            puts("errno checking not supported");
        else if (saved_errno == 0)
            puts("error=none");
        else {
            const char *name = saved_errno == EDOM ? "EDOM" :
                               saved_errno == ERANGE ? "ERANGE" : "OTHER";
            printf("error=%s (%s)\n", name, strerror(saved_errno));
        }
    }
    return 0;
}

【課堂提問】
如果不在每次 log 前清除 errno，會發生什麼誤判？

【參考答案】
先前失敗留下的非零值可能仍存在，後續成功呼叫就會被誤認為失敗；仍須遵守特定函式的規格。

【來源與增補】
C pp.6–9｜勘誤／補充
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 116 頁｜案例 14｜測試與常見錯誤

【本頁目標】
案例 14｜測試與常見錯誤
先預測結果，再執行；不只測一般資料。

【教師講解】
依表格逐組測試，確認返回狀態、stdout、stderr 與檔案內容。原稿的 1.0/0.0 不是會替你設定 errno 的函式呼叫；不能把它當作可攜的 ERANGE 示範。 對隨機或平台相依輸出，應測試性質，而不是把單一次執行結果當成唯一答案。

【測試判讀】
定義域錯誤｜log(−1)｜EDOM（支援時）｜參數超出實數定義域
極點錯誤｜log(0)｜ERANGE（支援時）｜零點的發散
正常｜log(1)｜結果 0；none｜清除先前殘留值
平台差異｜MATH_ERRNO 未設｜明確標示不支援｜不可宣稱 errno=0 即安全
本頁列出教學代表測試。附件測試器另外包含一般值、邊界與錯誤路徑；未模擬磁碟滿載、斷電、併發或所有作業系統。

【課堂提問】
如果不在每次 log 前清除 errno，會發生什麼誤判？

【參考答案】
先前失敗留下的非零值可能仍存在，後續成功呼叫就會被誤認為失敗；仍須遵守特定函式的規格。

【來源與增補】
C pp.6–9｜勘誤／補充
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 117 頁｜清理流程｜失敗可以提早發生，資源仍要正確歸還

【本頁目標】
清理流程｜失敗可以提早發生，資源仍要正確歸還
把「拿到了哪些資源」當成狀態，而不是到處複製 fclose。

【教師講解】
對照來源未開啟、來源已開啟、兩檔已開啟、已完成寫入四種狀態。每個失敗分支只清理自己真正取得的資源。對新建檔案可以設計移除不完整結果，但 remove 可能失敗，原地更新也不等於交易式還原。關閉後不再使用 FILE*，避免重複關閉或使用失效串流。

【本頁收斂】
每個成功取得的資源，在每條離開路徑上都應被處理一次。

【課堂提問】
目的檔開啟失敗時，要不要刪除同名目的檔？

【參考答案】
不要；它可能是原本就存在的重要資料。只有確認是本次成功建立的檔案，才可依契約清理。

【來源與增補】
B pp.32–34,126–128｜C 綜合
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 118 頁｜介面設計｜把狀態碼與資料值分開

【本頁目標】
介面設計｜把狀態碼與資料值分開
原稿 find_int 回傳 −1/−2/−3 作錯誤碼，可能和合法負數資料混淆。

【教師講解】
保留原稿 find_int 的動機，但指出其回傳碼設計的前提。若檔案中的整數允許為負值，−1 到 −3 就可能是合法資料，呼叫端無法分辨。可改用 enum 狀態搭配 int* 輸出參數；案例 12 的 parse_score 就使用同樣模式。此頁為介面設計片段，不是新增未提供程式的實作題。

【課堂提問】
資料本身可能是 −1，還能用 return −1 表示開檔失敗嗎？

【參考答案】
除非契約明確排除資料值 −1，否則應把成功／失敗狀態和資料通道分開。

【來源與增補】
B pp.115–116｜新增介面補強
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 119 頁｜案例 15｜整合專題：成績檔驗證與報表

【本頁目標】
案例 15｜整合專題：成績檔驗證與報表
完整題目：先確認任務、輸入、輸出與限制

【教師講解】
先不要展示解答。請學生用自己的話重述任務，再指出輸入格式、輸出格式與無效資料的處理。從成績文字檔載入資料，全部驗證通過後才建立統計報表；任一筆不合法就停止，不產生看似成功的部分報表。 1～100 筆；ID 為 S000～S999 且不可重複；成績 0～100。無 BOM/NUL 的文字檔；禁止空白行；目的報表必須不存在。

【完整規格】
任務：從成績文字檔載入資料，全部驗證通過後才建立統計報表；任一筆不合法就停止，不產生看似成功的部分報表。
輸入：命令列：grade_file input_csv new_report。每行 Sddd,score，沒有標題列。
輸出：報表第一行列出 count、average、min、max、pass；後續保留輸入順序，逐列輸出 ID、成績、PASS/FAIL。
限制：1～100 筆；ID 為 S000～S999 且不可重複；成績 0～100。無 BOM/NUL 的文字檔；禁止空白行；目的報表必須不存在。
範例輸入：
S001,86
S002,100
S003,59
S004,75
範例輸出：
count=4 average=80.00 min=59 max=100 pass=3
S001,86,PASS
S002,100,PASS
S003,59,FAIL
S004,75,PASS

【課堂提問】
這個專題在哪三個位置直接使用陣列？

【參考答案】
ids/scores 保存最多 100 筆資料；seen[1000] 記錄 ID 是否出現；line[128] 承接每一行文字。

【來源與增補】
A+B+C｜新增整合實作
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 120 頁｜專題契約｜先說清楚哪些資料要拒絕

【本頁目標】
專題契約｜先說清楚哪些資料要拒絕
每一條驗證規則，都應對應一個可重現的測試。

【教師講解】
讓學生區分語法規則、數值規則、容量規則與副作用規則。本題不是一般 CSV 解析器；不支援引號、欄位內逗號或標題列。這些限制明確寫出後，才有一致的驗收標準。

【表格帶讀】
項目｜接受條件｜失敗政策
來源格式｜無標題列；Sddd,score；ID 前不可加空白｜空白行、BOM、錯誤欄位立即失敗
分數文字｜允許前後空白與正號；完整整數 0～100｜86abc、小數、超大整數均拒絕
記錄數量｜1～100 筆；ID 不得重複｜第 101 筆或重複 ID，指出行號
單行長度｜最多 126 bytes；來源為無 NUL 文字｜拒絕被緩衝區截斷的一行
報表建立｜全部輸入驗證、讀取與關閉成功之後｜使用 wx；不得覆寫既有報表

【課堂提問】
檔案裡已有 99 筆，下一筆 ID 重複，應先存入再標示錯誤嗎？

【參考答案】
不應。先驗證 ID 和容量，成功才寫入 ids[n]/scores[n] 並增加 n。

【來源與增補】
A+B+C｜新增整合實作
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 121 頁｜案例 15｜核心解法與圖解

【本頁目標】
案例 15｜核心解法與圖解
整合專題：成績檔驗證與報表

【教師講解】
依下列順序帶讀圖解：1. 載入：fgets 逐行取得資料，紀錄實際行號。 2. 驗證：格式、strtol、範圍、ID 去重與容量全部通過才存入。 3. 輸出：先完成所有驗證，再以 wx 建立報表；逐筆檢查寫入與關閉。 先輸出報表再驗證剩餘輸入，會留下半份結果。本題先完整載入與驗證，再建立目的檔。

【課堂提問】
這個專題在哪三個位置直接使用陣列？

【參考答案】
ids/scores 保存最多 100 筆資料；seen[1000] 記錄 ID 是否出現；line[128] 承接每一行文字。

【來源與增補】
A+B+C｜新增整合實作
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 122 頁｜專題資料模型｜三個陣列，三種責任

【本頁目標】
專題資料模型｜三個陣列，三種責任
儲存資料、記錄狀態、承接輸入，不要混成同一件事。

【教師講解】
對照四筆範例，ids 與 scores 以相同索引表示同一筆資料；seen 的索引卻是數值化 ID，長度因此為 1000。line 僅是可重複使用的暫存緩衝區，不是所有資料的永久存放處。

【課堂提問】
seen[86] 代表成績 86 分已經出現過嗎？

【參考答案】
不是；seen 的索引是 ID，seen[86] 代表 S086 已經被接受。

【來源與增補】
A+B+C｜新增整合實作
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 123 頁｜案例 15｜完整程式 1/6

【本頁目標】
案例 15｜完整程式 1/6
15_grade_file.c

【教師講解】
本頁為 15_grade_file.c 的第 1/6 段，對應原始檔第 1～18 行。所有程式頁依序接續，沒有省略程式碼。匯入必要標頭與容量定義。parse_record 先檢查長度、S 前綴與逗號位置，再驗證三位 ID 數字，避免在未驗證前就使用索引。

【程式帶讀】
對應 15_grade_file.c，原始碼第 1～18 行。這是完整檔案第 1/6 段，依頁序合併即可，不需補寫省略片段。提醒學生先讀題目頁的輸入資料前提；程式使用的語法片段與整體錯誤契約應一起理解。

#include <ctype.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CAP 100

static int parse_record(const char *line, int *id, int *score) {
    if (strlen(line) < 6 || line[0] != 'S' || line[4] != ',')
        return 0;
    for (int i = 1; i <= 3; ++i)
        if (!isdigit((unsigned char)line[i])) return 0;
    int number = (line[1] - '0') * 100 +
                 (line[2] - '0') * 10 + line[3] - '0';
    char *end;
    errno = 0;
    long value = strtol(line + 5, &end, 10);

【課堂提問】
這個專題在哪三個位置直接使用陣列？

【參考答案】
ids/scores 保存最多 100 筆資料；seen[1000] 記錄 ID 是否出現；line[128] 承接每一行文字。

【來源與增補】
A+B+C｜新增整合實作
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 124 頁｜案例 15｜完整程式 2/6

【本頁目標】
案例 15｜完整程式 2/6
15_grade_file.c

【教師講解】
本頁為 15_grade_file.c 的第 2/6 段，對應原始檔第 19～36 行。所有程式頁依序接續，沒有省略程式碼。strtol 解析分數，檢查沒有數字、ERANGE、0～100 及尾端雜字；全部合法才把 ID 和分數交給呼叫端。主程式另驗證命令列。

【程式帶讀】
對應 15_grade_file.c，原始碼第 19～36 行。這是完整檔案第 2/6 段，依頁序合併即可，不需補寫省略片段。提醒學生先讀題目頁的輸入資料前提；程式使用的語法片段與整體錯誤契約應一起理解。

    if (end == line + 5 || errno == ERANGE || value < 0 || value > 100)
        return 0;
    while (isspace((unsigned char)*end)) ++end;
    if (*end != '\0') return 0;
    *id = number;
    *score = (int)value;
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fputs("usage: grade_file input_csv new_report\n", stderr);
        return EXIT_FAILURE;
    }
    FILE *in = fopen(argv[1], "r");
    if (in == NULL) {
        fputs("Cannot open input\n", stderr);
        return EXIT_FAILURE;

【課堂提問】
這個專題在哪三個位置直接使用陣列？

【參考答案】
ids/scores 保存最多 100 筆資料；seen[1000] 記錄 ID 是否出現；line[128] 承接每一行文字。

【來源與增補】
A+B+C｜新增整合實作
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 125 頁｜案例 15｜完整程式 3/6

【本頁目標】
案例 15｜完整程式 3/6
15_grade_file.c

【教師講解】
本頁為 15_grade_file.c 的第 3/6 段，對應原始檔第 37～53 行。所有程式頁依序接續，沒有省略程式碼。開啟輸入後逐行讀取，維護行號。長行或 parse_record 失敗立即標記錯誤；只有完整解析的值才進入容量與重複檢查。

【程式帶讀】
對應 15_grade_file.c，原始碼第 37～53 行。這是完整檔案第 3/6 段，依頁序合併即可，不需補寫省略片段。提醒學生先讀題目頁的輸入資料前提；程式使用的語法片段與整體錯誤契約應一起理解。

    }
    int ids[CAP], scores[CAP], n = 0, failed = 0;
    bool seen[1000] = {false};
    char line[128];
    size_t line_no = 0;
    while (fgets(line, sizeof line, in) != NULL) {
        ++line_no;
        int id, score;
        if (strchr(line, '\n') == NULL && !feof(in)) {
            fprintf(stderr, "Line %zu: too long\n", line_no);
            failed = 1;
            break;
        }
        if (!parse_record(line, &id, &score)) {
            fprintf(stderr, "Line %zu: invalid record\n", line_no);
            failed = 1;
            break;

【課堂提問】
這個專題在哪三個位置直接使用陣列？

【參考答案】
ids/scores 保存最多 100 筆資料；seen[1000] 記錄 ID 是否出現；line[128] 承接每一行文字。

【來源與增補】
A+B+C｜新增整合實作
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 126 頁｜案例 15｜完整程式 4/6

【本頁目標】
案例 15｜完整程式 4/6
15_grade_file.c

【教師講解】
本頁為 15_grade_file.c 的第 4/6 段，對應原始檔第 54～70 行。所有程式頁依序接續，沒有省略程式碼。透過 seen[id] 偵測重複 ID，在寫入 ids[n] 和 scores[n] 之前檢查容量。讀取結束後檢查 ferror 和 fclose；輸入失敗時仍不建立報表。

【程式帶讀】
對應 15_grade_file.c，原始碼第 54～70 行。這是完整檔案第 4/6 段，依頁序合併即可，不需補寫省略片段。提醒學生先讀題目頁的輸入資料前提；程式使用的語法片段與整體錯誤契約應一起理解。

        }
        if (seen[id] || n == CAP) {
            fprintf(stderr, "Line %zu: duplicate ID or capacity exceeded\n",
                    line_no);
            failed = 1;
            break;
        }
        seen[id] = true;
        ids[n] = id;
        scores[n] = score;
        ++n;
    }
    if (ferror(in)) {
        fputs("Input read error\n", stderr);
        failed = 1;
    }
    if (fclose(in) != 0) failed = 1;

【課堂提問】
這個專題在哪三個位置直接使用陣列？

【參考答案】
ids/scores 保存最多 100 筆資料；seen[1000] 記錄 ID 是否出現；line[128] 承接每一行文字。

【來源與增補】
A+B+C｜新增整合實作
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 127 頁｜案例 15｜完整程式 5/6

【本頁目標】
案例 15｜完整程式 5/6
15_grade_file.c

【教師講解】
本頁為 15_grade_file.c 的第 5/6 段，對應原始檔第 71～87 行。所有程式頁依序接續，沒有省略程式碼。確認至少一筆資料，再走訪有效陣列計算總和、極值與及格數。以 wx 建立全新的輸出檔；既有檔案保持不變。

【程式帶讀】
對應 15_grade_file.c，原始碼第 71～87 行。這是完整檔案第 5/6 段，依頁序合併即可，不需補寫省略片段。提醒學生先讀題目頁的輸入資料前提；程式使用的語法片段與整體錯誤契約應一起理解。

    if (failed) return EXIT_FAILURE;
    if (n == 0) {
        fputs("Empty input\n", stderr);
        return EXIT_FAILURE;
    }
    int sum = 0, pass = 0, low = scores[0], high = scores[0];
    for (int i = 0; i < n; ++i) {
        sum += scores[i];
        if (scores[i] >= 60) ++pass;
        if (scores[i] < low) low = scores[i];
        if (scores[i] > high) high = scores[i];
    }
    FILE *out = fopen(argv[2], "wx");
    if (out == NULL) {
        fputs("Report exists or cannot be created\n", stderr);
        return EXIT_FAILURE;
    }

【課堂提問】
這個專題在哪三個位置直接使用陣列？

【參考答案】
ids/scores 保存最多 100 筆資料；seen[1000] 記錄 ID 是否出現；line[128] 承接每一行文字。

【來源與增補】
A+B+C｜新增整合實作
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 128 頁｜案例 15｜完整程式 6/6

【本頁目標】
案例 15｜完整程式 6/6
15_grade_file.c

【教師講解】
本頁為 15_grade_file.c 的第 6/6 段，對應原始檔第 88～104 行。所有程式頁依序接續，沒有省略程式碼。檢查統計與逐筆 fprintf，也檢查 fclose。任何輸出失敗嘗試移除本次建立的部分報表；成功才回傳成功狀態。這不提供所有檔案系統的原子交易保證。

【程式帶讀】
對應 15_grade_file.c，原始碼第 88～104 行。這是完整檔案第 6/6 段，依頁序合併即可，不需補寫省略片段。提醒學生先讀題目頁的輸入資料前提；程式使用的語法片段與整體錯誤契約應一起理解。

    if (fprintf(out, "count=%d average=%.2f min=%d max=%d pass=%d\n",
                n, (double)sum / n, low, high, pass) < 0)
        failed = 1;
    for (int i = 0; i < n && !failed; ++i)
        if (fprintf(out, "S%03d,%d,%s\n", ids[i], scores[i],
                    scores[i] >= 60 ? "PASS" : "FAIL") < 0)
            failed = 1;
    if (fclose(out) != 0) failed = 1;
    if (failed) {
        fputs("Report write failed\n", stderr);
        if (remove(argv[2]) != 0)
            fputs("Warning: partial report remains\n", stderr);
        return EXIT_FAILURE;
    }
    puts("Report created");
    return EXIT_SUCCESS;
}

【課堂提問】
這個專題在哪三個位置直接使用陣列？

【參考答案】
ids/scores 保存最多 100 筆資料；seen[1000] 記錄 ID 是否出現；line[128] 承接每一行文字。

【來源與增補】
A+B+C｜新增整合實作
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 129 頁｜案例 15｜測試與常見錯誤

【本頁目標】
案例 15｜測試與常見錯誤
先預測結果，再執行；不只測一般資料。

【教師講解】
依表格逐組測試，確認返回狀態、stdout、stderr 與檔案內容。先輸出報表再驗證剩餘輸入，會留下半份結果。本題先完整載入與驗證，再建立目的檔。 對隨機或平台相依輸出，應測試性質，而不是把單一次執行結果當成唯一答案。

【測試判讀】
正常｜題目四筆資料｜平均 80.00；及格 3｜檔案→陣列→報表
重複 ID｜S001 出現兩次｜失敗；不產生報表｜seen[1000] 去重
格式／數值｜86abc、101、超大整數｜失敗並指出行號｜拒絕不完整解析
空檔／超量｜0 筆或 101 筆｜失敗；不產生報表｜有效範圍 1～100
目的已存在｜已存在的報表｜失敗；原檔不變｜建立模式保護資料
本頁列出教學代表測試。附件測試器另外包含一般值、邊界與錯誤路徑；未模擬磁碟滿載、斷電、併發或所有作業系統。

【課堂提問】
這個專題在哪三個位置直接使用陣列？

【參考答案】
ids/scores 保存最多 100 筆資料；seen[1000] 記錄 ID 是否出現；line[128] 承接每一行文字。

【來源與增補】
A+B+C｜新增整合實作
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 130 頁｜專題結果｜正常輸出與失敗時的檔案狀態

【本頁目標】
專題結果｜正常輸出與失敗時的檔案狀態
同樣重要的兩個答案：算出什麼，以及哪些檔案不該被改動。

【教師講解】
用四筆樣本逐筆重算總分 320、平均 80、及格 3。接著示範在第二行加入非法分數時，報表不應被建立；如果目的報表早已存在，內容應維持不變。這比只看終端機印出成功更能驗證整合行為。

【課堂提問】
輸入驗證全部通過，就可以在寫入前印出 Report created 嗎？

【參考答案】
不能。fprintf 或 fclose 仍可能失敗；完成訊息必須放在所有必要輸出成功之後。

【來源與增補】
A+B+C｜新增整合實作
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 131 頁｜課堂檢核｜先判斷問題，再提出最小修正

【本頁目標】
課堂檢核｜先判斷問題，再提出最小修正
請先說明理由；教師備忘錄附參考答案。

【教師講解】
本頁可以作為分組討論或隨堂短答。第一題 i=N 越界，改 i<N。第二題以 fread 回傳控制，再檢查 ferror。第三題輸入副作用可能消失，應改 if 再視需要 assert。第四題改用本次有效長度 n。第五題回傳值是主要契約，errno 可能是殘留值。請學生先提出原因，再寫修正，避免只背「標準答案」。

【表格帶讀】
片段／說法｜要回答的問題｜討論方向
for(i=0; i<=N; ++i) a[i]=0;｜哪一次迭代越界？｜索引與長度
while(!feof(fp)) fread(...);｜為何不能預測下一次讀取？｜回傳值與狀態
assert(scanf("%d",&n)==1);｜NDEBUG 後有何差異？｜副作用與外部驗證
fwrite(buf,1,sizeof buf,out);｜最後一塊只有 1 byte 時如何？｜容量與有效長度
errno != 0 就宣告任務失敗｜為何可能誤判？｜診斷與實際結果

【課堂提問】
這五個問題的共同根源是什麼？

【參考答案】
把不同概念當成同一件事：長度與索引、預測與狀態、檢查與副作用、容量與有效長度、診斷與成功契約。

【來源與增補】
A+B+C｜新增檢核
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 132 頁｜交作業前｜讓「可執行」升級為「可驗證」

【本頁目標】
交作業前｜讓「可執行」升級為「可驗證」
把程式、測試與說明當成同一份交付內容。

【教師講解】
使用這一頁做作業驗收，不只看能不能編譯。特別要求同一份資料的人工預期結果，和失敗情況下的檔案狀態。程式需要清楚標示受支援的輸入範圍與平台限制；沒有進行的故障測試也應坦白列出，不能把正常執行當成所有錯誤都已驗證。

【課堂提問】
安全複製器除了比對輸出檔，還應測什麼？

【參考答案】
至少測目的檔已存在、來源與目的相同、空檔、區塊邊界及來源不存在；並確認失敗時原檔沒有被改動。

【來源與增補】
A+B+C｜新增驗收表
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 133 頁｜附錄 A｜printf 常用轉換與長度修飾子

【本頁目標】
附錄 A｜printf 常用轉換與長度修飾子
需要細節時回查；不必把所有規格放在主講解頁。

【教師講解】
附錄保留原稿完整規格查詢功能，而不是逐頁列一兩個項目。整數長度與有號性要一起看；對 z/t 修飾子的有號對應型別，不能簡化成所有轉換都直接要求同一個型別。%n 屬特殊用途，必須傳入正確指標，且不應使用外部輸入作格式字串。

【表格帶讀】
格式類別｜對應型別／意義｜注意
d/i；o/u/x/X｜int；unsigned int｜進位表示與符號規則不同
f/e/g/a｜double；小數／科學／有效數字／十六進位浮點｜float 透過可變參數時提升為 double
hh/h/l/ll｜char/short 經提升；long；long long｜配 d/u/x 等選擇相應整數長度
j / z / t｜intmax_t；size_t；ptrdiff_t 相關｜修飾子需配合實際 signed/unsigned 轉換
L + 浮點轉換｜long double｜例如 %Lf
c / s / p / n / %｜字元／字串／位址／記錄已輸出數／百分號｜%n 寫入物件，不輸出字元

【課堂提問】
printf("%n", &n) 會輸出 n 的值嗎？

【參考答案】
不會。它把本次呼叫到此為止已輸出的字元數寫進 n。

【來源與增補】
B pp.67–85
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 134 頁｜附錄 B｜scanf 的型別與格式語意

【本頁目標】
附錄 B｜scanf 的型別與格式語意
輸入函式操作物件位址，格式不匹配可能造成未定義行為。

【教師講解】
用作課後索引表。原稿完整枚舉的 j/z/t 等修飾子，主教材已說明型別匹配原則；實際使用時仍應按函式規格查對有號性。特別提醒 %u 不等於「拒絕負號」，輸入合法性要由規格另外保證或以 strtol 解析後檢查。

【表格帶讀】
格式／修飾子｜接收物件｜提醒
%d / %i｜int*｜%i 依前綴辨別進位；%d 固定十進位
%u / %o / %x｜unsigned int*｜仍可能接受符號，不能代替非負驗證
%f / %lf / %Lf｜float* / double* / long double*｜與 printf 的參數提升不同
%hhd / %hd / %ld / %lld｜signed char* / short* / long* / long long*｜目標值必須可由接收型別表示
%s / %[ / %c｜char 陣列／字元物件｜%s 與 %[ 補 \0；%c 不補
%* / %n｜抑制指定／int* 計數｜兩者都不增加回傳的指定數

【課堂提問】
使用 %u 就可以保證使用者沒有輸入負數嗎？

【參考答案】
不能。格式可能接受符號並依無號轉換規則處理；要拒絕負數必須另外驗證。

【來源與增補】
B pp.95–109
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---

### 投影片第 135 頁｜附錄 C｜明確標示原稿勘誤與安全補強（1/2）

【本頁目標】
附錄 C｜明確標示原稿勘誤與安全補強（1/2）
以本教材的 C17 基準解讀；不是把平台實驗結果當成語言保證。

【教師講解】
此頁集中保留修正紀錄，讓授課者可追溯到原始投影片，避免學生回去對照原稿時困惑。修正的基準是本教材採用的 C17 與實際可驗證格式輸出，不把差異悄悄隱藏在重排內容中。

【表格帶讀】
原稿位置｜需要釐清的內容｜本教材處理
A p.16｜空初始列的合法性敘述｜C17 使用 {0}，不採 {}
A p.27｜C++ 的 std::size_t 圖片｜C 語言改說 size_t，輸出用 %zu
B p.13 / p.64｜stderr 一定顯示螢幕｜限定為只重導向 stdout 的情境
B p.57｜輸出後才 setvbuf｜先設定緩衝，再對該串流 I/O
B p.81｜%.4g 的 1234.56 結果｜修正為 1235

【課堂提問】
為何要把原稿頁碼保留下來？

【參考答案】
方便追溯、比較和備課，能清楚區分原始概念、新增案例與勘誤。

【來源與增補】
A+B｜勘誤清單；W1
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。
【外部校核來源】
W1 — https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf （C11 委員會草案，引用與 C17 共通的核心條款）
W2 — https://learn.microsoft.com/en-us/cpp/overview/install-c17-support?view=msvc-170
W3 — https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/fopen-wfopen?view=msvc-170
W4 — https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/strtol-wcstol-strtol-l-wcstol-l?view=msvc-170

---

### 投影片第 136 頁｜附錄 C｜明確標示原稿勘誤與安全補強（2/2）

【本頁目標】
附錄 C｜明確標示原稿勘誤與安全補強（2/2）
保留原意，但不沿用會誤導學生的測試與安全假設。

【教師講解】
指出「補強」不一定表示原教材主題錯誤，而是教材示例缺少實務條件。例如原始 fcopy 說明主要資料移動，但未檢查所有輸出失敗；本教材以新的題目契約补上目的檔保护與不完整檔案處理。對於移植性限制，保留不同實作可能有不同結果的說明。

【表格帶讀】
原稿位置｜需要釐清的內容｜本教材處理
B pp.132–135｜gets 的歷史敘述｜C17 不使用；改 fgets 並檢查長行
B pp.128,143–146｜漏檢查 I/O、未初始化欄位、!feof 迴圈｜完整案例驗證有效長度與讀寫／關閉結果
B pp.115–116｜find_int 的負數錯誤碼｜示範狀態與資料分離的介面
B pp.152–159｜文字位移與 fpos_t 大檔推論｜依串流類型與實作說明限制
C p.7｜1.0/0.0 與 errno 的關聯｜改用 log 並檢查 math_errhandling
C p.5｜完成後一律停用 assert｜依專案策略；外部驗證不能依賴 assert

【課堂提問】
補上錯誤檢查之後，是否就能宣稱檔案寫入具備斷電交易安全？

【參考答案】
不能。這些檢查處理標準 I/O 回報的失敗，不等於作業系統與儲存裝置層的交易或持久化保證。

【來源與增補】
B+C｜勘誤／補強清單；W1
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。
【外部校核來源】
W1 — https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf （C11 委員會草案，引用與 C17 共通的核心條款）
W2 — https://learn.microsoft.com/en-us/cpp/overview/install-c17-support?view=msvc-170
W3 — https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/fopen-wfopen?view=msvc-170
W4 — https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/strtol-wcstol-strtol-l-wcstol-l?view=msvc-170

---

### 投影片第 137 頁｜來源與教材邊界

【本頁目標】
來源與教材邊界
原稿為內容主幹；新增示例與勘誤在各頁標示，備忘錄保留來源。

【教師講解】
三份使用者提供的原稿分別為 Chapter 8 Arrays(1).pptx（64 頁）、Chapter 22 InputOutput(1).pptx（172 頁）、Chapter 24 Error Handling(1).pptx（9 頁）。外部參考僅用於確認 C 語意與平台介面：W1 WG14 N1570 公開委員會草案、W2 Microsoft Learn C11/C17 支援說明、W3 Microsoft fopen 文件、W4 Microsoft strtol 文件。N1570 是公開 C11 委員會草案，本文引用的是與本教材 C17 共同的核心規則，不宣稱它是 ISO C17 正式版。

【課堂提問】
新增案例是否是原稿作者原有的題目？

【參考答案】
不是。新增案例、規格、圖解與測試為本次重整時補充；以標籤和來源頁碼區分。

【來源與增補】
A+B+C；W1–W4
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。
【外部校核來源】
W1 — https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf （C11 委員會草案，引用與 C17 共通的核心條款）
W2 — https://learn.microsoft.com/en-us/cpp/overview/install-c17-support?view=msvc-170
W3 — https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/fopen-wfopen?view=msvc-170
W4 — https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/strtol-wcstol-strtol-l-wcstol-l?view=msvc-170

---

### 投影片第 138 頁｜案例索引｜題目、解法、程式與測試都在一起

【本頁目標】
案例索引｜題目、解法、程式與測試都在一起
點選案例可跳回完整題目頁；附件提供同名獨立 .c 檔。

【教師講解】
本頁可用於課堂快速跳題。請始終先回到完整題目頁，避免只給學生看解答程式。附件有 16 支可獨立編譯的程式、測試資料、測試執行器與逐頁備忘錄；案例 10 的兩個版本接受同一個複製題目契約。

【課堂提問】
複習一題時應先看哪一頁？

【參考答案】
先看題目規格和輸入限制，再自行預測核心解法與測試，最後比對程式。

【來源與增補】
A+B+C｜新增索引
A：Chapter 8 Arrays(1).pptx；B：Chapter 22 InputOutput(1).pptx；C：Chapter 24 Error Handling(1).pptx。頁碼指原始投影片。標記「新增」的題目規格、圖解、案例及測試是整合教學增補；標記「勘誤」處與原稿文字有明確差異。

---


<a id="toc-cases"></a>

## 完整案例

---

<a id="toc-ch8-01"></a>

### 案例 01｜反向輸出 10 筆量測值

---

- 章節：CH8
- 類別：原稿案例補強
- 來源：A pp.12–13
- 原稿頁碼：10、13

---

**題目**

依序讀入 10 筆整數量測值，保留原本儲存順序，再由最後一筆往前輸出。不得把題目改成排序。

---

**輸入格式**

標準輸入：恰好 10 個整數，以空白或換行分隔。

---

**輸出要求**

由第 10 筆到第 1 筆輸出；數字間一個空白，最後換行。

---

**限制**

每筆介於 −10000～10000；缺項、非數字或超出範圍即失敗。入門數值文字約定見導讀頁。

---

**範例輸入**

```text
34 82 49 102 7 94 23 11 50 31
```

---

**範例輸出**

```text
31 50 11 23 94 7 102 49 82 34
```

---

**解題步驟**

- 先以正向迴圈填入 a[0]～a[9]。
- 第二個迴圈從 i=10 遞減，讀取 a[i−1]。
- 只改變輸出順序，不交換陣列元素。

---

**常見錯誤**

錯誤的起點 a[10] 已越界；最後有效索引是 9。此題不是就地反轉。

---

**課堂提問**

為何輸出迴圈讀 a[i−1]，而不是 a[i]？

---

**參考答案**

i 由元素數量 10 開始；先減 1 才對應最後有效索引 9。i>0 也避免 unsigned 倒數下溢。

---

**原稿測試／補充資料**

- 正常｜10 筆題目資料｜31 50 … 82 34｜確認前後次序
- 邊界｜含負值與 0｜全部正確反向｜不是數值排序
- 缺項｜1 2 後結束輸入｜失敗；stderr 訊息｜不可讀未初始化值
- 格式錯誤｜1 2 x｜失敗；stderr 訊息｜檢查 scanf 回傳

---

**編註**

- **lines**：`[[6, 12, "先讀入並驗證全部 10 筆", "輸入尚未完整前不輸出反向結果；每次 scanf 都檢查成功賦值數及本題數值範圍。"], [14, 15, "以 i > 0 保護 i−1", "i 依序為 10 到 1，實際存取索引為 9 到 0；陣列本身沒有交換元素。"]]`
- **boundary**：`"題目要求恰好 10 筆；這份入門程式只讀取前 10 筆，不會額外檢查尾端是否還有第 11 筆。互動保留此行為，不把它改稱為嚴格整行解析。"`

---

#### 程式：`01_reverse.c`

---

原稿頁碼：12

---

```c
#include <stdio.h>
#include <stdlib.h>
#define N 10

int main(void) {
    int a[N];
    for (int i = 0; i < N; ++i) {
        if (scanf("%d", &a[i]) != 1 ||
            a[i] < -10000 || a[i] > 10000) {
            fputs("Invalid integer input\n", stderr);
            return EXIT_FAILURE;
        }
    }
    for (int i = N; i > 0; --i)
        printf("%d%c", a[i - 1], i == 1 ? '\n' : ' ');
    return EXIT_SUCCESS;
}
```

---

<a id="toc-ch8-02"></a>

### 案例 02｜用布林陣列偵測重複數字

---

- 章節：CH8
- 類別：原稿案例補強
- 來源：A pp.23–25
- 原稿頁碼：14、18

---

**題目**

讀入一個非負整數，從個位數往高位數檢查，找出第一個「再次出現」的數字；完全沒有重複則明確回報。

---

**輸入格式**

標準輸入：一個十進位整數 n。

---

**輸出要求**

輸出 Repeated digit: d；若無重複，輸出 No repeated digit。

---

**限制**

0 ≤ n ≤ 2147483647。n=0 視為一個數字 0；不保留前導零，負數與錯誤輸入拒絕。

---

**範例輸入**

```text
28212
```

---

**範例輸出**

```text
Repeated digit: 2
```

---

**解題步驟**

- seen[10] 初值全 false；索引就是數字 0～9。
- digit=n%10 取得個位數，先檢查 seen[digit]。
- 未出現則設 true、n/=10；do…while 讓 0 也被處理一次。

---

**常見錯誤**

不能先把 seen[digit] 設為 true 再判斷，否則每個數字都會被誤判為重複。

---

**課堂提問**

為何 n=0 不使用 while(n>0) 就結束？

---

**參考答案**

題目把 0 視為具有一位數的有效輸入；do…while 至少執行一次，與題意一致。

---

**原稿測試／補充資料**

- 有重複｜28212｜Repeated digit: 2｜第 3 次取出的 2 已看過
- 無重複｜9357｜No repeated digit｜各索引只設一次
- 零｜0｜No repeated digit｜仍應處理一次
- 零重複｜100｜Repeated digit: 0｜兩個 0 需要被辨認
- 不合法｜−1｜失敗｜不可讓 digit 成負索引

---

**編註**

- **lines**：`[[6, 8, "資料值直接當作索引", "seen[digit] 表示數字 digit 是否已經出現；repeated=-1 代表尚未找到重複。"], [14, 22, "先檢查，再標記", "do…while 讓輸入 0 也檢查一次；由右至左第一次碰到已標記位置便停止。"], [23, 26, "輸出明確的兩種結果", "找到重複時輸出數字，否則輸出 No repeated digit；前導零不屬於整數值的一部分。"]]`
- **boundary**：`"互動陣列中的 T/F 是布林狀態的顯示方式，不是對 C bool 物件位元組表示的宣稱。"`

---

#### 程式：`02_repeated_digits.c`

---

原稿頁碼：16、17

---

```c
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    bool seen[10] = {false};
    long n;
    int repeated = -1;
    if (scanf("%ld", &n) != 1 ||
        n < 0 || n > 2147483647L) {
        fputs("Expected 0..2147483647\n", stderr);
        return EXIT_FAILURE;
    }
    do {
        int digit = (int)(n % 10);
        if (seen[digit]) {
            repeated = digit;
            break;
        }
        seen[digit] = true;
        n /= 10;
    } while (n > 0);
    if (repeated >= 0)
        printf("Repeated digit: %d\n", repeated);
    else
        puts("No repeated digit");
    return EXIT_SUCCESS;
}
```

---

<a id="toc-ch8-03"></a>

### 案例 03｜班級成績統計與分布

---

- 章節：CH8
- 類別：新增案例
- 來源：A pp.8,26–30｜新增
- 原稿頁碼：19、23

---

**題目**

讀入全班成績，計算總分、平均、最高分、最低分、及格人數，並統計五個成績區間。

---

**輸入格式**

先輸入人數 n，再輸入 n 個整數成績。

---

**輸出要求**

輸出 count、sum、min、max、average（小數 2 位）、pass 與五個 bins。

---

**限制**

1 ≤ n ≤ 100；0 ≤ 成績 ≤ 100；及格為 ≥60。分組：0–59、60–69、70–79、80–89、90–100。

---

**範例輸入**

```text
5
59 60 75 90 100
```

---

**範例輸出**

```text
count=5 sum=384 min=59 max=100
average=76.80 pass=4
bins=1 1 1 0 2
```

---

**解題步驟**

- 先驗證人數與每筆成績，再開始統計。
- 以第一筆初始化 min/max；用同一趟掃描累加。
- 100 分併入最後一組；平均前轉為 double。

---

**常見錯誤**

sum/n 若先做整數除法再指定給 double，小數已經遺失；需用 (double)sum/n。

---

**課堂提問**

為何 bins[score/10] 不能直接用在長度 10 的陣列？

---

**參考答案**

100/10=10，會存取第 11 格而越界。本題採明確的五區間映射，把 90～100 合併。

---

**原稿測試／補充資料**

- 一般｜59 60 75 90 100｜平均 76.80；及格 4｜驗證各組與平均
- 單筆｜n=1，score=100｜min=max=100｜初始化不可假設 0
- 分界｜0,59,60,69,70,89,100｜bins=2 2 1 1 1｜確認閉區間
- 容量｜n=0 或 101｜失敗｜先驗證才寫陣列
- 範圍｜score=101｜失敗｜不能當成新分組

---

**編註**

- **lines**：`[[10, 18, "驗證後才進行統計", "先檢查人數及全部成績，避免資料讀到一半便使用未初始化元素。"], [19, 27, "一次掃描維護多個統計值", "用第一筆初始化上下界；分組判斷讓 100 分仍落在 bins[4]，不會存取 bins[5]。"], [28, 34, "平均不是整數除法", "sum 轉成 double 後再除以 n；輸出固定兩位小數，分布順序與題目一致。"]]`
- **boundary**：`"互動直條圖與逐步累加是本次 HTML 的教學呈現；五個區間及計算規則沿用投影片與完整 C 程式。"`

---

#### 程式：`03_score_stats.c`

---

原稿頁碼：21、22

---

```c
#include <stdio.h>
#include <stdlib.h>
#define CAP 100

int main(void) {
    int score[CAP], bins[5] = {0};
    int n, sum = 0, pass = 0;
    if (scanf("%d", &n) != 1 || n < 1 || n > CAP) {
        fputs("Expected count 1..100\n", stderr);
        return EXIT_FAILURE;
    }
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &score[i]) != 1 ||
            score[i] < 0 || score[i] > 100) {
            fputs("Invalid score\n", stderr);
            return EXIT_FAILURE;
        }
    }
    int low = score[0], high = score[0];
    for (int i = 0; i < n; ++i) {
        int s = score[i];
        sum += s;
        if (s < low) low = s;
        if (s > high) high = s;
        if (s >= 60) ++pass;
        int b = s < 60 ? 0 : (s >= 90 ? 4 : s / 10 - 5);
        ++bins[b];
    }
    printf("count=%d sum=%d min=%d max=%d\n",
           n, sum, low, high);
    printf("average=%.2f pass=%d\n", (double)sum / n, pass);
    printf("bins=%d %d %d %d %d\n",
           bins[0], bins[1], bins[2], bins[3], bins[4]);
    return EXIT_SUCCESS;
}
```

---

<a id="toc-ch8-04"></a>

### 案例 04｜有先後順序的最大增幅

---

- 章節：CH8
- 類別：原稿案例補強
- 來源：A pp.59–60｜新增線性解法
- 原稿頁碼：24、29

---

**題目**

量測陣列中的位置代表時間。找出 max(a[j]−a[i])，且必須滿足 i<j；比較雙迴圈與單次掃描兩種解法。

---

**輸入格式**

先輸入 n，再輸入 n 個整數量測值。

---

**輸出要求**

同一行輸出 brute 與 linear 的結果，兩者必須相同。

---

**限制**

2 ≤ n ≤ 100；數值介於 −10000～10000。必須選兩個不同時刻；全程下降時答案可能為負。

---

**範例輸入**

```text
5
10 15 90 200 110
```

---

**範例輸出**

```text
brute=190 linear=190
```

---

**解題步驟**

- 暴力法枚舉所有 i<j，時間 O(n²)。
- 線性法在處理 j 前，保存 a[0..j−1] 的最小值。
- 先用當前值計算增幅，再更新最小值；時間 O(n)、額外空間 O(1)。

---

**常見錯誤**

不加順序限制的 max−min 是另一道題。best=0 會把全下降資料錯答成 0。

---

**課堂提問**

為何要先算差值，再更新 min_before？

---

**參考答案**

計算時 min_before 只能來自更早的位置，才能保證 i<j；先更新會把當前元素當成自己的前值。

---

**原稿測試／補充資料**

- 一般｜10 15 90 200 110｜190｜200−10
- 全下降｜9 7 3｜−2｜不能錯設 best=0
- 相同值｜4 4 4｜0｜仍須兩個位置
- 兩筆邊界｜−10000 10000｜20000｜先轉 long long 再相減
- 資料不足｜n=1｜失敗｜不能讀 a[1]

---

**編註**

- **lines**：`[[5, 13, "暴力解法作為對照", "枚舉所有 i<j；初值使用 a[1]−a[0]，保留全下降資料的負答案。"], [15, 24, "先比較差值，再更新最小值", "處理 j 時 min_before 只包含較早位置；若先把 a[j] 放進最小值，便可能把同一時刻配對而錯得 0。"], [38, 40, "同一輸入交給兩種解法", "輸出 brute 與 linear 便於交叉驗證；不以無序的全域最大值減最小值取代題目。"]]`
- **boundary**：`"互動主要逐步呈現線性解法，最後另以暴力枚舉核對；完整 C 原始碼仍保留兩個函式。"`

---

#### 程式：`04_ordered_difference.c`

---

原稿頁碼：26、27、28

---

```c
#include <stdio.h>
#include <stdlib.h>
#define CAP 100

static long long brute(const int a[], int n) {
    long long best = (long long)a[1] - a[0];
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j) {
            long long d = (long long)a[j] - a[i];
            if (d > best) best = d;
        }
    return best;
}

static long long linear(const int a[], int n) {
    int min_before = a[0];
    long long best = (long long)a[1] - a[0];
    for (int j = 1; j < n; ++j) {
        long long d = (long long)a[j] - min_before;
        if (d > best) best = d;
        if (a[j] < min_before) min_before = a[j];
    }
    return best;
}

int main(void) {
    int a[CAP], n;
    if (scanf("%d", &n) != 1 || n < 2 || n > CAP) {
        fputs("Expected count 2..100\n", stderr);
        return EXIT_FAILURE;
    }
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &a[i]) != 1 ||
            a[i] < -10000 || a[i] > 10000) {
            fputs("Invalid sample\n", stderr);
            return EXIT_FAILURE;
        }
    }
    printf("brute=%lld linear=%lld\n", brute(a, n), linear(a, n));
    return EXIT_SUCCESS;
}
```

---

<a id="toc-ch8-05"></a>

### 案例 05｜三台設備 × 四時段產量表

---

- 章節：CH8
- 類別：新增案例
- 來源：A pp.36–46｜新增
- 原稿頁碼：32、36

---

**題目**

用二維陣列保存三台設備在四個時段的產量，計算每台設備總產量、每時段總產量與全部總量。

---

**輸入格式**

依列輸入 12 個整數：先輸入設備 0 的四時段，再設備 1、設備 2。

---

**輸出要求**

輸出 rows 三筆、cols 四筆，以及 total。

---

**限制**

固定 3 列 × 4 欄；每格 0～10000。列代表設備，欄代表時段；不可交換索引意義。

---

**範例輸入**

```text
10 20 30 40
5 15 25 35
8 12 16 24
```

---

**範例輸出**

```text
rows=100 80 60
cols=23 47 71 99
total=240
```

---

**解題步驟**

- 以 qty[r][c] 同時表達設備與時段。
- 外層走設備 r，內層走時段 c。
- 每讀取一格，加入 rows[r]、cols[c] 與 total。

---

**常見錯誤**

qty[r,c] 使用的是逗號運算子，不是二維索引；正確寫法必須是 qty[r][c]。

---

**課堂提問**

為何 rows 和 cols 的陣列長度不同？

---

**參考答案**

rows 為每台設備保存一個結果，共 3 筆；cols 為每個時段保存一個結果，共 4 筆。

---

**原稿測試／補充資料**

- 一般｜題目 3×4 資料｜列 100/80/60；總量 240｜行列語意正確
- 全部為零｜12 個 0｜所有統計皆為 0｜初值與空產能
- 單格非零｜qty[1][2]=5，其餘 0｜rows[1]=cols[2]=5｜定位特定座標
- 超出限制｜−1 或 10001｜失敗｜不能接受非法產量

---

**編註**

- **lines**：`[[7, 16, "第一組巢狀迴圈只負責讀取", "r 對應設備、c 對應時段；12 格全部通過範圍檢查後才統計。"], [17, 22, "第二組迴圈同時更新三個總量", "每格加進 rows[r]、cols[c]、total；列和與欄和都應等於 total。"], [23, 27, "輸出有清楚的維度意義", "rows 有三筆、cols 有四筆；不能把欄總和當成設備總產量。"]]`
- **boundary**：`"投影片解法摘要寫「每讀取一格，加入總量」；完整 C 程式實際分成「先讀完」與「再統計」兩組迴圈。本 HTML 保留摘要原文，逐步圖解則依完整程式的實際順序。"`

---

#### 程式：`05_matrix_report.c`

---

原稿頁碼：34、35

---

```c
#include <stdio.h>
#include <stdlib.h>
#define ROWS 3
#define COLS 4

int main(void) {
    int qty[ROWS][COLS];
    long rows[ROWS] = {0}, cols[COLS] = {0}, total = 0;
    for (int r = 0; r < ROWS; ++r)
        for (int c = 0; c < COLS; ++c) {
            if (scanf("%d", &qty[r][c]) != 1 ||
                qty[r][c] < 0 || qty[r][c] > 10000) {
                fputs("Invalid quantity\n", stderr);
                return EXIT_FAILURE;
            }
        }
    for (int r = 0; r < ROWS; ++r)
        for (int c = 0; c < COLS; ++c) {
            rows[r] += qty[r][c];
            cols[c] += qty[r][c];
            total += qty[r][c];
        }
    printf("rows=%ld %ld %ld\n", rows[0], rows[1], rows[2]);
    printf("cols=%ld %ld %ld %ld\n",
           cols[0], cols[1], cols[2], cols[3]);
    printf("total=%ld\n", total);
    return EXIT_SUCCESS;
}
```

---

<a id="toc-ch8-06"></a>

### 案例 06｜五種利率的逐年複利表

---

- 章節：CH8
- 類別：原稿案例補強
- 來源：A pp.31–35
- 原稿頁碼：37、41

---

**題目**

以本金 100 作為數值運算練習，比較起始利率及其後四個整數百分比利率，列出逐年複利後的金額。

---

**輸入格式**

標準輸入：起始年利率 rate（整數百分比）與年數 years。

---

**輸出要求**

輸出 5 個利率欄，每年一列，金額顯示小數 2 位。

---

**限制**

0 ≤ rate ≤ 20；1 ≤ years ≤ 30。每年複利一次；本金固定 100。不涉及費用、稅務或投資建議。

---

**範例輸入**

```text
6 5
```

---

**範例輸出**

```text
第 5 年：
133.82 140.26 146.93 153.86 161.05
```

---

**解題步驟**

- value[5] 分別保存五種情境的「當年餘額」。
- 外層迴圈推進年份；內層更新每個利率。
- value[i] *= 1.0 + (rate+i)/100.0；只保存最近一年的狀態。

---

**常見錯誤**

除以 100 會做整數除法；此題必須除以 100.0。顯示四捨五入不代表中間值已被截斷。

---

**課堂提問**

為何不需要保存 years×5 的整張表？

---

**參考答案**

下一年只依賴上一年的餘額，已經輸出的歷史資料不再參與計算，因此五個狀態值就足夠。

---

**原稿測試／補充資料**

- 原稿數值｜rate=6，years=5｜第 5 年如右側範例｜確認遞推
- 零利率｜rate=0，years=1｜第一欄 100.00｜0% 不增加
- 最短期間｜years=1｜只有一列資料｜迴圈起訖
- 錯誤年數｜years=0｜失敗｜避免無意義輸出

---

**編註**

- **lines**：`[[8, 12, "限制練習規模", "先檢查利率與年數，避免超出題目規定後仍產生表格。"], [13, 18, "五個情境共用一維陣列", "每格起始為 100，索引 i 對應 rate+i 個百分點。"], [19, 25, "逐年覆寫最新狀態", "乘數使用 100.0 形成浮點除法；只保存上一年的餘額便能算出下一年。"]]`
- **boundary**：`"這是陣列與巢狀迴圈的數值題，不是金融試算建議。互動以 JavaScript 浮點推演；下方 C 實測保留真正 printf 的字距及小數格式。"`

---

#### 程式：`06_interest_table.c`

---

原稿頁碼：39、40

---

```c
#include <stdio.h>
#include <stdlib.h>
#define RATES 5

int main(void) {
    int rate, years;
    double value[RATES];
    if (scanf("%d%d", &rate, &years) != 2 ||
        rate < 0 || rate > 20 || years < 1 || years > 30) {
        fputs("Expected rate 0..20 and years 1..30\n", stderr);
        return EXIT_FAILURE;
    }
    printf("Year");
    for (int i = 0; i < RATES; ++i) {
        value[i] = 100.0;
        printf(" %7d%%", rate + i);
    }
    putchar('\n');
    for (int year = 1; year <= years; ++year) {
        printf("%4d", year);
        for (int i = 0; i < RATES; ++i) {
            value[i] *= 1.0 + (rate + i) / 100.0;
            printf(" %8.2f", value[i]);
        }
        putchar('\n');
    }
    return EXIT_SUCCESS;
}
```

---

<a id="toc-ch8-07"></a>

### 案例 07｜不重複發牌與狀態表

---

- 章節：CH8
- 類別：原稿案例補強
- 來源：A pp.49–55
- 原稿頁碼：42、46

---

**題目**

從 4 種花色、13 種點數的牌組發出 n 張不重複的牌，用二維布林表記錄已發出的牌。

---

**輸入格式**

標準輸入：張數 n 與 unsigned 整數亂數種子 seed。

---

**輸出要求**

輸出 n 個二字元牌碼，例如 7c；牌碼間以空白分隔。n=0 只輸出換行。

---

**限制**

0 ≤ n ≤ 52。點數 23456789tjqka；花色 cdhs。同一實作／種子可重現；跨編譯器不保證相同牌序。

---

**範例輸入**

```text
5 1
```

---

**範例輸出**

```text
5 張合法、互不重複的牌
（精確序列依 C 函式庫而異）
```

---

**解題步驟**

- rand()%4 與 rand()%13 取得花色、點數。
- in_hand[suit][rank] 已為 true 就重新抽。
- 新牌才標記、輸出並增加 dealt；查表轉成牌碼。

---

**常見錯誤**

rand()%n 可能有模數偏差；這是陣列與狀態管理練習，不是公平抽獎或密碼用途的亂數設計。

---

**課堂提問**

發到重複牌時，能否把 dealt 加一？

---

**參考答案**

不可以。dealt 代表成功輸出的不同牌張數，而不是抽樣嘗試次數。只有確認新牌後才增加。

---

**原稿測試／補充資料**

- 不發牌｜n=0｜空行｜不進入發牌迴圈
- 一般｜n=5，seed=1｜5 張且不重複｜驗證性質，不鎖定跨平台牌序
- 整副牌｜n=52｜52 個互異合法牌碼｜狀態表覆蓋完整牌組
- 超量｜n=53｜立即失敗｜避免永遠等不到新牌
- 可重現｜同一執行檔，同 seed｜兩次牌序相同｜可重現實驗

---

**編註**

- **lines**：`[[8, 17, "設定狀態與種子", "四種花色、十三種點數組成 52 個布林格；n=0 仍合法。"], [19, 26, "只有新牌才推進 dealt", "重複牌走 continue，不消耗名額；查表轉成二字元牌碼。"], [28, 29, "結束條件依已發張數", "不以抽樣次數作為發牌數；重抽也是程式流程的一部分。"]]`
- **boundary**：`"HTML 使用 xorshift32 產生可觀察的教學牌序，不模仿 C 函式庫 rand。C 測試驗證張數、牌碼合法與不重複，不固定跨平台的精確牌序。"`

---

#### 程式：`07_deal_cards.c`

---

原稿頁碼：44、45

---

```c
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define SUITS 4
#define RANKS 13

int main(void) {
    const char ranks[] = "23456789tjqka";
    const char suits[] = "cdhs";
    bool in_hand[SUITS][RANKS] = {{false}};
    int n;
    unsigned seed;
    if (scanf("%d%u", &n, &seed) != 2 || n < 0 || n > 52) {
        fputs("Expected count 0..52 and unsigned seed\n", stderr);
        return EXIT_FAILURE;
    }
    srand(seed);
    int dealt = 0;
    while (dealt < n) {
        int suit = rand() % SUITS;
        int rank = rand() % RANKS;
        if (in_hand[suit][rank]) continue;
        in_hand[suit][rank] = true;
        printf("%c%c%s", ranks[rank], suits[suit],
               dealt + 1 == n ? "" : " ");
        ++dealt;
    }
    putchar('\n');
    return EXIT_SUCCESS;
}
```

---

<a id="toc-ch8-08"></a>

### 案例 08｜命令列檔案開啟檢查器

---

- 章節：CH22
- 類別：原稿案例補強
- 來源：B pp.38–42｜C pp.6–9
- 原稿頁碼：55、59

---

**題目**

寫一個命令列工具，接收一個檔名，檢查本次是否能以讀取模式成功開啟並關閉。

---

**輸入格式**

命令列：canopen filename；不從鍵盤另外讀取檔名。

---

**輸出要求**

成功：stdout 顯示檔案可開啟。失敗：stderr 顯示原因，回傳 EXIT_FAILURE。

---

**限制**

argc 必須為 2；以本次 fopen 的結果為準。可開啟不代表內容正確，也不保證未來仍可開啟。

---

**範例輸入**

```text
canopen sample.txt
```

---

**範例輸出**

```text
sample.txt can be opened
```

---

**解題步驟**

- 先驗證 argc，再使用 argv[1]。
- fopen 回傳 NULL 就停止；保存 errno 後才輸出訊息。
- 成功開啟也要檢查 fclose；不要把錯誤訊息寫入 stdout。

---

**常見錯誤**

先用「檔案是否存在」判斷再 fopen 仍可能失敗；權限與狀態可能改變，應檢查真正要做的操作。

---

**課堂提問**

argc 為 2 時，argv[0] 與 argv[1] 分別是什麼？

---

**參考答案**

argv[0] 是程式名稱字串，argv[1] 是使用者傳入的檔名；argv[argc] 是空指標。

---

**原稿測試／補充資料**

- 檔案存在｜sample.txt｜成功並關閉｜正常流程
- 不存在｜absent.txt｜失敗；stderr｜不能使用 NULL 串流
- 漏參數｜canopen｜usage 訊息；失敗｜先驗證 argc
- 多參數｜canopen a b｜usage 訊息；失敗｜介面規格固定

---

**編註**

- **lines**：`[[5, 8, "先檢查 argc", "argv[1] 是命令列引數，不是以 scanf 讀取；參數不足時不得直接解參考。"], [10, 20, "保存失敗當下的診斷", "fopen 回傳 NULL 是主要失敗訊號；先保存 errno，避免後續輸出擾動診斷狀態。"], [21, 26, "關閉成功才回報成功", "開啟成功不代表關閉必然成功；診斷寫到 stderr，正常結果寫到 stdout。"]]`
- **boundary**：`"互動的「檔案存在／缺少／關閉失敗」是虛擬情境，不會存取電腦路徑。作業系統的 perror 字串不被當作固定答案。"`

---

#### 程式：`08_canopen.c`

---

原稿頁碼：57、58

---

```c
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fputs("usage: canopen filename\n", stderr);
        return EXIT_FAILURE;
    }
    errno = 0;
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        int saved_errno = errno;
        fprintf(stderr, "Cannot open: %s\n", argv[1]);
        if (saved_errno != 0) {
            errno = saved_errno;
            perror("fopen");
        }
        return EXIT_FAILURE;
    }
    if (fclose(fp) != 0) {
        fputs("Close failed\n", stderr);
        return EXIT_FAILURE;
    }
    printf("%s can be opened\n", argv[1]);
    return EXIT_SUCCESS;
}
```

---

<a id="toc-ch8-09"></a>

### 案例 09｜日期字串：格式合法不等於日期存在

---

- 章節：CH22
- 類別：新增案例
- 來源：B pp.132–135,161–171｜新增
- 原稿頁碼：68、73

---

**題目**

讀入一行日期，接受 YYYY-MM-DD 或 YYYY/MM/DD，驗證實際日曆日期後，統一輸出 YYYY-MM-DD。

---

**輸入格式**

一行 10 個字元的日期；允許行尾 LF、CRLF 或最後一行無換行。

---

**輸出要求**

有效日期：輸出正規化結果；無效：stderr 訊息並失敗。

---

**限制**

1900～2099 年；年月日必須分別為 4/2/2 位數；兩個分隔符須相同。不能有多餘字元或空白。輸入為無 NUL 的文字。

---

**範例輸入**

```text
2024/02/29
```

---

**範例輸出**

```text
2024-02-29
```

---

**解題步驟**

- fgets 取得一整行，只移除行尾 CR/LF。
- 先驗證長度與數字位置，再以 sscanf 拆欄位。
- 檢查月份、閏年與當月天數，最後 snprintf 並檢查截斷。

---

**常見錯誤**

只檢查 sscanf 回傳 3 或 5，只能證明欄位解析成功，不能證明日期在日曆中存在。

---

**課堂提問**

為何本題先檢查數字位置，再呼叫 sscanf？

---

**參考答案**

先確定欄位恰好是 4/2/2 位數，避免寬度只是上限而非固定長度的誤解，也讓數值一定在可表示範圍內。

---

**原稿測試／補充資料**

- 閏年｜2024/02/29｜2024-02-29｜可被 4 整除且非百年例外
- 平年｜2025-02-29｜失敗｜成功解析不代表日期存在
- 百年例外｜1900-02-29｜失敗｜1900 不是閏年
- 分隔符混用｜2024-02/29｜失敗｜兩個分隔符需一致
- 尾端垃圾｜2024-02-29x｜失敗｜不可只接受合法前綴

---

**編註**

- **lines**：`[[9, 20, "限制輸入的外觀", "讀取後僅移除尾端 LF／CR，長度必須是 10；不會任意 trim 掉前後空白。"], [21, 34, "分開檢查字元與欄位", "先確認數字所在位置，再檢查 sscanf 的成功數、兩個分隔符及年月範圍。"], [35, 48, "判斷日曆，再格式化", "天數表搭配閏年規則，最後以 11 格陣列容納 10 字元與 NUL，並檢查 snprintf 結果。"]]`
- **boundary**：`"日期圖解沿用 1900～2099 年及固定 4/2/2 位格式，不擴充成任意地區的日期解析器。"`

---

#### 程式：`09_date_parser.c`

---

原稿頁碼：70、71、72

---

```c
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char line[64], sep1, sep2, extra;
    int y, m, d;
    if (fgets(line, sizeof line, stdin) == NULL) {
        fputs("Missing date\n", stderr);
        return EXIT_FAILURE;
    }
    size_t len = strlen(line);
    if (len > 0 && line[len - 1] == '\n') --len;
    if (len > 0 && line[len - 1] == '\r') --len;
    if (len != 10) {
        fputs("Expected YYYY-MM-DD or YYYY/MM/DD\n", stderr);
        return EXIT_FAILURE;
    }
    line[len] = '\0';
    for (size_t i = 0; i < len; ++i) {
        if (i != 4 && i != 7 &&
            !isdigit((unsigned char)line[i])) {
            fputs("Invalid date digits\n", stderr);
            return EXIT_FAILURE;
        }
    }
    if (sscanf(line, "%4d%c%2d%c%2d%c",
               &y, &sep1, &m, &sep2, &d, &extra) != 5 ||
        sep1 != sep2 || (sep1 != '-' && sep1 != '/') ||
        y < 1900 || y > 2099 || m < 1 || m > 12) {
        fputs("Invalid date format/range\n", stderr);
        return EXIT_FAILURE;
    }
    const int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int leap = y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
    int limit = days[m - 1] + (m == 2 && leap);
    if (d < 1 || d > limit) {
        fputs("Invalid day\n", stderr);
        return EXIT_FAILURE;
    }
    char out[11];
    int written = snprintf(out, sizeof out, "%04d-%02d-%02d", y, m, d);
    if (written < 0 || (size_t)written >= sizeof out) {
        fputs("Formatting failed\n", stderr);
        return EXIT_FAILURE;
    }
    puts(out);
    return EXIT_SUCCESS;
}
```

---

<a id="toc-ch8-10"></a>

### 案例 10｜安全複製：逐字元版與區塊版

---

- 章節：CH22
- 類別：原稿案例補強
- 來源：B pp.117–128,138–146｜新增防護
- 原稿頁碼：76、84

---

**題目**

複製任意文字或二進位檔案，保留所有位元組。實作逐字元與區塊兩版，且不得覆寫任何既有目的檔。

---

**輸入格式**

命令列：copy_character source new_destination，或 copy_block source new_destination。

---

**輸出要求**

成功：目的檔每個位元組與來源一致，stdout 顯示 Copy complete。

---

**限制**

目的檔必須不存在；使用 C17 的 wbx 建立。檢查讀、寫、關閉錯誤；失敗時嘗試刪除本次建立的不完整檔。

---

**範例輸入**

```text
copy_block input.bin copy.bin
```

---

**範例輸出**

```text
Copy complete
copy.bin 與 input.bin 位元組完全一致
```

---

**解題步驟**

- 來源用 rb；目的用 wbx，避免既有檔案被截斷。
- 逐字元版：int 接 fgetc；區塊版：以 n 傳遞有效長度。
- 結束後查 ferror 與 fclose；任何失敗都不能宣稱複製完成。

---

**常見錯誤**

若使用 wb，開檔當下就可能毀掉原內容。fwrite 必須寫本次 fread 回傳的 n，而不是固定 4096。

---

**課堂提問**

區塊版的 fread(buffer,1,sizeof buffer,in) 回傳的是什麼？

---

**參考答案**

回傳完整元素數；因每個元素大小設成 1 byte，所以這個案例的回傳值也就是有效位元組數。

---

**原稿測試／補充資料**

- 二進位｜含 00、1A、FF 的檔案｜位元組完全一致｜不能當成 C 字串
- 空檔｜0 bytes｜建立 0-byte 目的檔｜EOF 不是錯誤
- 區塊邊界｜4096 / 4097 bytes｜無遺失、無額外資料｜最後一塊只寫 n bytes
- 目的已存在｜既有檔內容 KEEP｜失敗；KEEP 不變｜x 模式拒絕覆寫
- 同一路徑｜來源=目的｜失敗；來源不變｜避免先截斷來源

---

**編註**

- **lines**：`[[9, 19, "先開來源，再新建目的檔", "rb 保留所有 byte；wbx 要求目的檔不存在。已有目的檔時直接失敗，不截斷舊資料。"], [21, 28, "兩種複製粒度", "逐字元版用 int 保存 fgetc 回傳值；區塊版用 n 表示本次 fread 真正讀到的 byte 數，最後一塊不能仍寫滿 4096。"], [29, 39, "完成條件包含關閉", "檢查讀取錯誤及關閉結果；任一失敗只嘗試清理本次產物，不宣稱已完成可靠磁碟交易。"]]`
- **boundary**：`"本區行號解說主要對應 10b 區塊版；兩份完整程式都可切換查看。互動故障注入為教學模型，與測試紀錄中的實際檔案操作分開列示。"`

---

#### 程式：`10a_copy_character.c`

---

原稿頁碼：78、79、80

---

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fputs("usage: copy_character source new_destination\n", stderr);
        return EXIT_FAILURE;
    }
    FILE *in = fopen(argv[1], "rb");
    if (in == NULL) {
        fputs("Cannot open source\n", stderr);
        return EXIT_FAILURE;
    }
    FILE *out = fopen(argv[2], "wbx");
    if (out == NULL) {
        fputs("Destination exists or cannot be created\n", stderr);
        fclose(in);
        return EXIT_FAILURE;
    }
    int ch, failed = 0;
    while ((ch = fgetc(in)) != EOF) {
        if (fputc(ch, out) == EOF) {
            failed = 1;
            break;
        }
    }
    if (ferror(in)) failed = 1;
    if (fclose(in) != 0) failed = 1;
    if (fclose(out) != 0) failed = 1;
    if (failed) {
        fputs("Copy failed; removing partial output\n", stderr);
        if (remove(argv[2]) != 0)
            fputs("Warning: partial output remains\n", stderr);
        return EXIT_FAILURE;
    }
    puts("Copy complete");
    return EXIT_SUCCESS;
}
```

---

#### 程式：`10b_copy_block.c`

---

原稿頁碼：81、82、83

---

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fputs("usage: copy_block source new_destination\n", stderr);
        return EXIT_FAILURE;
    }
    FILE *in = fopen(argv[1], "rb");
    if (in == NULL) {
        fputs("Cannot open source\n", stderr);
        return EXIT_FAILURE;
    }
    FILE *out = fopen(argv[2], "wbx");
    if (out == NULL) {
        fputs("Destination exists or cannot be created\n", stderr);
        fclose(in);
        return EXIT_FAILURE;
    }
    unsigned char buffer[4096];
    size_t n;
    int failed = 0;
    while ((n = fread(buffer, 1, sizeof buffer, in)) > 0) {
        if (fwrite(buffer, 1, n, out) != n) {
            failed = 1;
            break;
        }
    }
    if (ferror(in)) failed = 1;
    if (fclose(in) != 0) failed = 1;
    if (fclose(out) != 0) failed = 1;
    if (failed) {
        fputs("Copy failed; removing partial output\n", stderr);
        if (remove(argv[2]) != 0)
            fputs("Warning: partial output remains\n", stderr);
        return EXIT_FAILURE;
    }
    puts("Copy complete");
    return EXIT_SUCCESS;
}
```

---

<a id="toc-ch8-11"></a>

### 案例 11｜直接更新庫存檔的第 3 筆

---

- 章節：CH22
- 類別：新增案例
- 來源：B pp.138–160｜原庫存案例改編
- 原稿頁碼：89、94

---

**題目**

建立五筆整數庫存的二進位檔，讀出索引 2 的舊值，再直接改成 99，最後重讀整個檔案確認結果。

---

**輸入格式**

命令列：stock_update new_binary_file。初始資料固定為 10、20、35、40、50。

---

**輸出要求**

顯示 old=35 new=99，及更新後的五筆整數。

---

**限制**

目的檔必須不存在；第 3 筆＝索引 2。原生 int 格式僅限相同實作讀寫；這是定位練習，不提供交易式還原。

---

**範例輸入**

```text
stock_update stock.bin
```

---

**範例輸出**

```text
old=35 new=99
10 20 99 40 50
```

---

**解題步驟**

- 先 wbx 寫入初始陣列，關閉後以 rb+ 重開。
- 位置 = 2×sizeof(int)；先 fseek 再讀出舊值。
- 讀→寫前重新定位；寫→讀前再定位到檔首。

---

**常見錯誤**

第 k 筆以 0-based 索引 k 計算 offset；更換平台不能假設 int 永遠是 4 bytes，也不能忽略位元組順序。

---

**課堂提問**

讀完索引 2 後，為什麼不能直接 fwrite 覆寫該筆？

---

**參考答案**

讀取後檔案位置已前進到下一筆，且更新串流的讀→寫需要定位；必須重新 fseek 回索引 2 的起點。

---

**原稿測試／補充資料**

- 一般｜新檔 stock.bin｜35→99，其餘不變｜精準更新一筆
- 檔案內容｜5 個原生 int｜10 20 99 40 50｜整檔驗證
- 既有檔案｜再次執行同檔名｜失敗；不重建｜避免覆寫
- 漏參數｜stock_update｜usage；失敗｜命令列契約

---

**編註**

- **lines**：`[[5, 18, "先建立可重現的五筆資料", "初始值固定 10、20、35、40、50；用 wbx 防止覆寫既有檔案。"], [28, 34, "更新必須重新定位", "先讀出索引 2 的舊值，再 fseek 到同一位置寫入 99；寫後回到檔首重新讀取。"], [35, 43, "失敗不能偽裝成功", "檢查定位、讀寫與關閉；原生 int 檔只用於相同實作的定位練習。"]]`
- **boundary**：`"sizeof(int) 的切換只改變圖解的位移假設，不改動固定 C 程式，更不宣稱原生 int 二進位資料可跨平台交換。"`

---

#### 程式：`11_stock_update.c`

---

原稿頁碼：91、92、93

---

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int stock[5] = {10, 20, 35, 40, 50};
    int updated = 99, previous;
    int failed = 0;
    if (argc != 2) {
        fputs("usage: stock_update new_binary_file\n", stderr);
        return EXIT_FAILURE;
    }
    FILE *fp = fopen(argv[1], "wbx");
    if (fp == NULL) {
        fputs("Cannot create new stock file\n", stderr);
        return EXIT_FAILURE;
    }
    if (fwrite(stock, sizeof stock[0], 5, fp) != 5) failed = 1;
    if (fclose(fp) != 0) failed = 1;
    if (failed) {
        fputs("Initial write failed\n", stderr);
        return EXIT_FAILURE;
    }
    fp = fopen(argv[1], "rb+");
    if (fp == NULL) {
        fputs("Cannot reopen stock file\n", stderr);
        return EXIT_FAILURE;
    }
    long offset = 2L * (long)sizeof stock[0];
    if (fseek(fp, offset, SEEK_SET) != 0 ||
        fread(&previous, sizeof previous, 1, fp) != 1 ||
        fseek(fp, offset, SEEK_SET) != 0 ||
        fwrite(&updated, sizeof updated, 1, fp) != 1 ||
        fseek(fp, 0L, SEEK_SET) != 0 ||
        fread(stock, sizeof stock[0], 5, fp) != 5) {
        fputs("Record update/read failed\n", stderr);
        failed = 1;
    }
    if (fclose(fp) != 0) failed = 1;
    if (failed) return EXIT_FAILURE;
    printf("old=%d new=%d\n", previous, stock[2]);
    for (int i = 0; i < 5; ++i)
        printf("%d%c", stock[i], i == 4 ? '\n' : ' ');
    return EXIT_SUCCESS;
}
```

---

<a id="toc-ch8-12"></a>

### 案例 12｜嚴格讀取一個 0～100 分的整數

---

- 章節：CH24
- 類別：新增案例
- 來源：B pp.103–104,132–135｜C pp.6–9｜新增
- 原稿頁碼：100、105

---

**題目**

讀入一行成績，不只判斷是否以數字開頭，還要拒絕超大整數、尾端垃圾、空白行與超長輸入。

---

**輸入格式**

標準輸入的一行無 NUL 文字；允許數字前後空白及正號。

---

**輸出要求**

有效：score=value。無效：stderr 回報 No number、Trailing text、Out of range 等。

---

**限制**

數值 0～100；單行最多 126 bytes（不含 LF）；不接受小數或第二個值。最末行可不含換行。

---

**範例輸入**

```text
  +86
```

---

**範例輸出**

```text
score=86
```

---

**解題步驟**

- fgets 限制讀取容量；過長輸入整行拒絕。
- errno=0 後 strtol，保留 end 指標。
- 依序檢查沒讀到數字、ERANGE／範圍、尾端非空白；成功才設定輸出值。

---

**常見錯誤**

atoi 無法清楚區分「合法 0」與轉換失敗；只看 errno 也無法偵測 86abc。

---

**課堂提問**

為何 *out=(int)value 要放在所有檢查之後？

---

**參考答案**

只有值已落在 0～100，且沒有尾端垃圾時才承諾成功；如此失敗不會把半合法結果交給呼叫端。

---

**原稿測試／補充資料**

- 一般｜  +86  ｜score=86｜允許前後空白
- 尾端垃圾｜86abc｜Trailing text｜不能只接受數字前綴
- 超大整數｜60 個 9｜Out of range｜使用 ERANGE
- 空白行｜只有空白／換行｜No number｜end==text
- 超長一行｜200 個字元｜Line too long｜不可默默截斷

---

**編註**

- **lines**：`[[10, 15, "數字開頭不代表整行合法", "strtol 前 errno=0；先檢查沒有數字，再檢查 ERANGE 與題目範圍。"], [16, 19, "尾端只能有空白", "跳過空白後仍有字元便是 TRAILING；所有檢查通過才設定 *out，保留呼叫端舊值。"], [24, 42, "讀取策略與解析策略分工", "fgets 限制容量，長行拒絕；主程式依狀態輸出易讀訊息，不用 assert 驗證外部輸入。"]]`
- **boundary**：`"來源以一行無 NUL 文字為約定，最多 126 bytes 不含 LF。互動使用 BigInt 判斷巨大整數；不把 JavaScript 數值範圍當成 C long 的範圍。"`

---

#### 程式：`12_strict_score.c`

---

原稿頁碼：102、103、104

---

```c
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Status { OK, NO_NUMBER, TRAILING, OUT_OF_RANGE };

static enum Status parse_score(const char *text, int *out) {
    char *end;
    errno = 0;
    long value = strtol(text, &end, 10);
    if (end == text) return NO_NUMBER;
    if (errno == ERANGE || value < 0 || value > 100)
        return OUT_OF_RANGE;
    while (isspace((unsigned char)*end)) ++end;
    if (*end != '\0') return TRAILING;
    *out = (int)value;
    return OK;
}

int main(void) {
    char line[128];
    int score;
    if (fgets(line, sizeof line, stdin) == NULL) {
        fputs(ferror(stdin) ? "Read error\n" : "No input\n", stderr);
        return EXIT_FAILURE;
    }
    if (strchr(line, '\n') == NULL && !feof(stdin)) {
        fputs("Line too long (max 126 bytes)\n", stderr);
        return EXIT_FAILURE;
    }
    enum Status status = parse_score(line, &score);
    if (status != OK) {
        const char *message[] = {
            "OK", "No number", "Trailing text", "Out of range"
        };
        fprintf(stderr, "%s\n", message[status]);
        return EXIT_FAILURE;
    }
    printf("score=%d\n", score);
    return EXIT_SUCCESS;
}
```

---

<a id="toc-ch8-13"></a>

### 案例 13｜外部驗證與 assert 的分工

---

- 章節：CH24
- 類別：原稿案例補強
- 來源：C pp.3–5｜新增防護
- 原稿頁碼：107、110

---

**題目**

讀入數值後計算平方根。外部不合法輸入必須以正常錯誤路徑拒絕；assert 僅記錄驗證後的內部不變量。

---

**輸入格式**

標準輸入：一個可由 double 表示的數值文字。

---

**輸出要求**

有效：輸出 sqrt=結果（小數 6 位）；無效：stderr 訊息並失敗。

---

**限制**

只接受有限且非負的值；NaN、正負無窮大與負數拒絕。定義 NDEBUG 後，外部驗證仍須有效。

---

**範例輸入**

```text
4
```

---

**範例輸出**

```text
sqrt=2.000000
```

---

**解題步驟**

- if 檢查轉換結果、isfinite(x) 與 x≥0。
- assert(x≥0) 說明程式到這裡應滿足的條件。
- 用一般版與 -DNDEBUG 版跑同一批測試。

---

**常見錯誤**

不可寫 assert(scanf(...)==1)；NDEBUG 啟用時，連讀取輸入的副作用都可能消失。

---

**課堂提問**

assert 關閉之後，這個程式會接受負數嗎？

---

**參考答案**

不會。外部驗證在 if 中，與 assert 是否啟用無關；assert 只是協助檢查內部邏輯。

---

**原稿測試／補充資料**

- 有效｜4｜sqrt=2.000000｜正常路徑
- 邊界｜0｜sqrt=0.000000｜合法輸入
- 負數｜−1｜一般錯誤返回｜不依賴 abort
- 特殊值｜nan / inf｜失敗｜有限性檢查
- 移除 assert｜-DNDEBUG 後輸入 −1｜仍失敗｜輸入驗證不可消失

---

**編註**

- **lines**：`[[7, 11, "可恢復的外部錯誤用 if", "先檢查 scanf、isfinite 與非負條件，因此 NaN、無窮與負數在到達 assert 前就被拒絕。"], [12, 14, "assert 描述已成立的不變量", "assert 不執行輸入或其他必要副作用；NDEBUG 只移除斷言，不移除前面的外部驗證。"]]`
- **boundary**：`"NDEBUG 開關是圖解；測試區另附真正以 -DNDEBUG 編譯後的 10 組結果。互動平方根只示範十進位格式與有限顯示範圍，完整 C 程式以來源規格為準。"`

---

#### 程式：`13_assert_sqrt.c`

---

原稿頁碼：109

---

```c
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    double x;
    if (scanf("%lf", &x) != 1 || !isfinite(x) || x < 0.0) {
        fputs("Expected a finite, nonnegative value\n", stderr);
        return EXIT_FAILURE;
    }
    assert(x >= 0.0);  /* Internal invariant; no side effects. */
    printf("sqrt=%.6f\n", sqrt(x));
    return EXIT_SUCCESS;
}
```

---

<a id="toc-ch8-14"></a>

### 案例 14｜觀察 log 的 errno 診斷

---

- 章節：CH24
- 類別：原稿案例補強
- 來源：C pp.6–9｜勘誤／補充
- 原稿頁碼：112、116

---

**題目**

依序計算 log(−1)、log(0)、log(1)，觀察數學函式的結果與錯誤分類，不把平台輸出字串當成固定答案。

---

**輸入格式**

無外部輸入；程式內的 input 陣列固定為 −1、0、1。

---

**輸出要求**

先印 MATH_ERRNO 是否支援；逐筆印結果與 EDOM、ERANGE、none，或不支援 errno 檢查。

---

**限制**

只有 math_errhandling 含 MATH_ERRNO 時，才以 errno 驗證錯誤分類。NaN/inf 文字與 strerror 訊息依實作。

---

**範例輸入**

```text
直接執行 math_errno
```

---

**範例輸出**

```text
支援 MATH_ERRNO 時：
−1 → EDOM；0 → ERANGE；1 → none
```

---

**解題步驟**

- 先確認數學函式的錯誤回報機制。
- 每次呼叫 log 前把 errno 設為 0。
- log 後立即保存 errno，再交給 printf／strerror 產生說明。

---

**常見錯誤**

原稿的 1.0/0.0 不是會替你設定 errno 的函式呼叫；不能把它當作可攜的 ERANGE 示範。

---

**課堂提問**

如果不在每次 log 前清除 errno，會發生什麼誤判？

---

**參考答案**

先前失敗留下的非零值可能仍存在，後續成功呼叫就會被誤認為失敗；仍須遵守特定函式的規格。

---

**原稿測試／補充資料**

- 定義域錯誤｜log(−1)｜EDOM（支援時）｜參數超出實數定義域
- 極點錯誤｜log(0)｜ERANGE（支援時）｜零點的發散
- 正常｜log(1)｜結果 0；none｜清除先前殘留值
- 平台差異｜MATH_ERRNO 未設｜明確標示不支援｜不可宣稱 errno=0 即安全

---

**編註**

- **lines**：`[[7, 9, "先確認 errno 回報機制", "math_errhandling 不含 MATH_ERRNO 時，不可以「errno 沒變」宣稱沒有數學錯誤。"], [10, 13, "每次呼叫都獨立觀察", "每次 log 前清零，呼叫後立刻保存 errno；這與直接使用除法運算子不是同一件事。"], [14, 24, "分類與顯示分離", "用符號 EDOM／ERANGE 判斷，strerror 的字句僅作平台診斷資訊。"]]`
- **boundary**：`"HTML 的 NaN、−inf 是語意圖解。真正 C 輸出的大小寫、負號、錯誤碼數值與語系，以各次實測紀錄為準。"`

---

#### 程式：`14_math_errno.c`

---

原稿頁碼：114、115

---

```c
#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    const double input[] = {-1.0, 0.0, 1.0};
    int has_errno = (math_errhandling & MATH_ERRNO) != 0;
    printf("MATH_ERRNO=%d\n", has_errno);
    for (size_t i = 0; i < sizeof input / sizeof input[0]; ++i) {
        errno = 0;
        double result = log(input[i]);
        int saved_errno = errno;
        printf("x=%.0f result=%g ", input[i], result);
        if (!has_errno)
            puts("errno checking not supported");
        else if (saved_errno == 0)
            puts("error=none");
        else {
            const char *name = saved_errno == EDOM ? "EDOM" :
                               saved_errno == ERANGE ? "ERANGE" : "OTHER";
            printf("error=%s (%s)\n", name, strerror(saved_errno));
        }
    }
    return 0;
}
```

---

<a id="toc-ch8-15"></a>

### 案例 15｜整合專題：成績檔驗證與報表

---

- 章節：CHproject
- 類別：新增整合案例
- 來源：A+B+C｜新增整合實作
- 原稿頁碼：119、130

---

**題目**

從成績文字檔載入資料，全部驗證通過後才建立統計報表；任一筆不合法就停止，不產生看似成功的部分報表。

---

**輸入格式**

命令列：grade_file input_csv new_report。每行 Sddd,score，沒有標題列。

---

**輸出要求**

報表第一行列出 count、average、min、max、pass；後續保留輸入順序，逐列輸出 ID、成績、PASS/FAIL。

---

**限制**

1～100 筆；ID 為 S000～S999 且不可重複；成績 0～100。無 BOM/NUL 的文字檔；禁止空白行；目的報表必須不存在。

---

**範例輸入**

```text
S001,86
S002,100
S003,59
S004,75
```

---

**範例輸出**

```text
count=4 average=80.00 min=59 max=100 pass=3
S001,86,PASS
S002,100,PASS
S003,59,FAIL
S004,75,PASS
```

---

**解題步驟**

- 載入：fgets 逐行取得資料，紀錄實際行號。
- 驗證：格式、strtol、範圍、ID 去重與容量全部通過才存入。
- 輸出：先完成所有驗證，再以 wx 建立報表；逐筆檢查寫入與關閉。

---

**常見錯誤**

先輸出報表再驗證剩餘輸入，會留下半份結果。本題先完整載入與驗證，再建立目的檔。

---

**課堂提問**

這個專題在哪三個位置直接使用陣列？

---

**參考答案**

ids/scores 保存最多 100 筆資料；seen[1000] 記錄 ID 是否出現；line[128] 承接每一行文字。

---

**原稿測試／補充資料**

- 正常｜題目四筆資料｜平均 80.00；及格 3｜檔案→陣列→報表
- 重複 ID｜S001 出現兩次｜失敗；不產生報表｜seen[1000] 去重
- 格式／數值｜86abc、101、超大整數｜失敗並指出行號｜拒絕不完整解析
- 空檔／超量｜0 筆或 101 筆｜失敗；不產生報表｜有效範圍 1～100
- 目的已存在｜已存在的報表｜失敗；原檔不變｜建立模式保護資料

---

**編註**

- **lines**：`[[8, 23, "parse_record 專責單筆解析", "確認 Sddd, 前綴，再用 strtol 檢查成績與尾端；成功才把 ID 與 score 交給呼叫端。"], [42, 64, "逐筆驗證才存入陣列", "保持實際行號，先檢查長度及格式，再檢查 ID 重複與 100 筆容量。"], [66, 87, "來源完全通過才建立報表", "先確認讀取、關閉及非空資料，再統計；以 wx 新建報表，避免覆寫既有檔。"], [88, 103, "每一步輸出都要有成功證據", "檢查 fprintf、逐筆寫入與 fclose；失敗時嘗試移除不完整報表，成功才輸出 Report created。"]]`
- **boundary**：`"本次補充測試具體化了正常、空檔、空白行、ID 重複、超長行與容量超限等情境。所有測試遵守原題無 BOM／NUL 的來源約定；不把範圍外的資料當成已經安全驗證。"`

---

#### 程式：`15_grade_file.c`

---

原稿頁碼：123、124、125、126、127、128

---

```c
#include <ctype.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CAP 100

static int parse_record(const char *line, int *id, int *score) {
    if (strlen(line) < 6 || line[0] != 'S' || line[4] != ',')
        return 0;
    for (int i = 1; i <= 3; ++i)
        if (!isdigit((unsigned char)line[i])) return 0;
    int number = (line[1] - '0') * 100 +
                 (line[2] - '0') * 10 + line[3] - '0';
    char *end;
    errno = 0;
    long value = strtol(line + 5, &end, 10);
    if (end == line + 5 || errno == ERANGE || value < 0 || value > 100)
        return 0;
    while (isspace((unsigned char)*end)) ++end;
    if (*end != '\0') return 0;
    *id = number;
    *score = (int)value;
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fputs("usage: grade_file input_csv new_report\n", stderr);
        return EXIT_FAILURE;
    }
    FILE *in = fopen(argv[1], "r");
    if (in == NULL) {
        fputs("Cannot open input\n", stderr);
        return EXIT_FAILURE;
    }
    int ids[CAP], scores[CAP], n = 0, failed = 0;
    bool seen[1000] = {false};
    char line[128];
    size_t line_no = 0;
    while (fgets(line, sizeof line, in) != NULL) {
        ++line_no;
        int id, score;
        if (strchr(line, '\n') == NULL && !feof(in)) {
            fprintf(stderr, "Line %zu: too long\n", line_no);
            failed = 1;
            break;
        }
        if (!parse_record(line, &id, &score)) {
            fprintf(stderr, "Line %zu: invalid record\n", line_no);
            failed = 1;
            break;
        }
        if (seen[id] || n == CAP) {
            fprintf(stderr, "Line %zu: duplicate ID or capacity exceeded\n",
                    line_no);
            failed = 1;
            break;
        }
        seen[id] = true;
        ids[n] = id;
        scores[n] = score;
        ++n;
    }
    if (ferror(in)) {
        fputs("Input read error\n", stderr);
        failed = 1;
    }
    if (fclose(in) != 0) failed = 1;
    if (failed) return EXIT_FAILURE;
    if (n == 0) {
        fputs("Empty input\n", stderr);
        return EXIT_FAILURE;
    }
    int sum = 0, pass = 0, low = scores[0], high = scores[0];
    for (int i = 0; i < n; ++i) {
        sum += scores[i];
        if (scores[i] >= 60) ++pass;
        if (scores[i] < low) low = scores[i];
        if (scores[i] > high) high = scores[i];
    }
    FILE *out = fopen(argv[2], "wx");
    if (out == NULL) {
        fputs("Report exists or cannot be created\n", stderr);
        return EXIT_FAILURE;
    }
    if (fprintf(out, "count=%d average=%.2f min=%d max=%d pass=%d\n",
                n, (double)sum / n, low, high, pass) < 0)
        failed = 1;
    for (int i = 0; i < n && !failed; ++i)
        if (fprintf(out, "S%03d,%d,%s\n", ids[i], scores[i],
                    scores[i] >= 60 ? "PASS" : "FAIL") < 0)
            failed = 1;
    if (fclose(out) != 0) failed = 1;
    if (failed) {
        fputs("Report write failed\n", stderr);
        if (remove(argv[2]) != 0)
            fputs("Warning: partial report remains\n", stderr);
        return EXIT_FAILURE;
    }
    puts("Report created");
    return EXIT_SUCCESS;
}
```

---

## 全部投影片講義索引已依頁碼列於前段

---


<a id="toc-tests"></a>

## 測試資料

---

### 案例 01

---

#### 01-01｜題目資料

---

程式：`01_reverse.c`

---

測試來源：投影片代表情境具體化

---

**標準輸入**

```text
34 82 49 102 7 94 23 11 50 31
```

---

**預期標準輸出**

```text
31 50 11 23 94 7 102 49 82 34
```

---

預期結束碼：`0`

---

#### 01-02｜含負數與零

---

程式：`01_reverse.c`

---

測試來源：投影片代表情境具體化

---

**標準輸入**

```text
-3 0 5 1 -2 100 3 7 9 -1
```

---

**預期標準輸出**

```text
-1 9 7 3 100 -2 1 5 0 -3
```

---

預期結束碼：`0`

---

#### 01-03｜上下界

---

程式：`01_reverse.c`

---

測試來源：投影片代表情境具體化

---

**標準輸入**

```text
-10000 10000 -10000 10000 -10000 10000 -10000 10000 -10000 10000
```

---

**預期標準輸出**

```text
10000 -10000 10000 -10000 10000 -10000 10000 -10000 10000 -10000
```

---

預期結束碼：`0`

---

#### 01-04｜相同值

---

程式：`01_reverse.c`

---

測試來源：投影片代表情境具體化

---

**標準輸入**

```text
7 7 7 7 7 7 7 7 7 7
```

---

**預期標準輸出**

```text
7 7 7 7 7 7 7 7 7 7
```

---

預期結束碼：`0`

---

#### 01-05｜缺少8筆

---

程式：`01_reverse.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
1 2
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Invalid integer input
```

---

預期結束碼：`1`

---

#### 01-06｜非數字

---

程式：`01_reverse.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
1 2 x
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Invalid integer input
```

---

預期結束碼：`1`

---

#### 01-07｜超出範圍

---

程式：`01_reverse.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
10001
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Invalid integer input
```

---

預期結束碼：`1`

---

#### 01-08｜空輸入

---

程式：`01_reverse.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Invalid integer input
```

---

預期結束碼：`1`

---

### 案例 02

---

#### 02-01｜題目資料

---

程式：`02_repeated_digits.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
28212
```

---

**預期標準輸出**

```text
Repeated digit: 2
```

---

預期結束碼：`0`

---

#### 02-02｜無重複

---

程式：`02_repeated_digits.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
9357
```

---

**預期標準輸出**

```text
No repeated digit
```

---

預期結束碼：`0`

---

#### 02-03｜單一零

---

程式：`02_repeated_digits.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
0
```

---

**預期標準輸出**

```text
No repeated digit
```

---

預期結束碼：`0`

---

#### 02-04｜零重複

---

程式：`02_repeated_digits.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
100
```

---

**預期標準輸出**

```text
Repeated digit: 0
```

---

預期結束碼：`0`

---

#### 02-05｜前導零不保留

---

程式：`02_repeated_digits.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
0012
```

---

**預期標準輸出**

```text
No repeated digit
```

---

預期結束碼：`0`

---

#### 02-06｜最大允許值

---

程式：`02_repeated_digits.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
2147483647
```

---

**預期標準輸出**

```text
Repeated digit: 4
```

---

預期結束碼：`0`

---

#### 02-07｜負數

---

程式：`02_repeated_digits.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
-1
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Expected 0..2147483647
```

---

預期結束碼：`1`

---

#### 02-08｜非數字

---

程式：`02_repeated_digits.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
abc
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Expected 0..2147483647
```

---

預期結束碼：`1`

---

#### 02-09｜無輸入

---

程式：`02_repeated_digits.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Expected 0..2147483647
```

---

預期結束碼：`1`

---

### 案例 03

---

#### 03-01｜題目資料

---

程式：`03_score_stats.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
5
59 60 75 90 100
```

---

**預期標準輸出**

```text
count=5 sum=384 min=59 max=100
average=76.80 pass=4
bins=1 1 1 0 2
```

---

預期結束碼：`0`

---

#### 03-02｜單筆100

---

程式：`03_score_stats.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
1
100
```

---

**預期標準輸出**

```text
count=1 sum=100 min=100 max=100
average=100.00 pass=1
bins=0 0 0 0 1
```

---

預期結束碼：`0`

---

#### 03-03｜全部分界

---

程式：`03_score_stats.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
7
0 59 60 69 70 89 100
```

---

**預期標準輸出**

```text
count=7 sum=447 min=0 max=100
average=63.86 pass=5
bins=2 2 1 1 1
```

---

預期結束碼：`0`

---

#### 03-04｜容量上限100筆

---

程式：`03_score_stats.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
100
0 100 0 100 0 100 0 100 0 100 0 100 0 100 0 100 0 100 0 100 0 100 0 100 0 100 0 100 0 100 0 100 0 100 0 100 0 100 0 100 0 100 0 100 0 100 0 100 0 100 0 100 0 100 0 100 0 100 0 100 0 100 0 100 0 100 0 100 0 100 0 100 0 100 0 100 0 100 0 100 0 100 0 100 0 100 0 100 0 100 0 100 0 100 0 100 0 100 0 100
```

---

**預期標準輸出**

```text
count=100 sum=5000 min=0 max=100
average=50.00 pass=50
bins=50 0 0 0 50
```

---

預期結束碼：`0`

---

#### 03-05｜全不及格

---

程式：`03_score_stats.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
3
0 20 59
```

---

**預期標準輸出**

```text
count=3 sum=79 min=0 max=59
average=26.33 pass=0
bins=3 0 0 0 0
```

---

預期結束碼：`0`

---

#### 03-06｜0人

---

程式：`03_score_stats.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
0
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Expected count 1..100
```

---

預期結束碼：`1`

---

#### 03-07｜超過容量

---

程式：`03_score_stats.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
101
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Expected count 1..100
```

---

預期結束碼：`1`

---

#### 03-08｜分數101

---

程式：`03_score_stats.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
1
101
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Invalid score
```

---

預期結束碼：`1`

---

#### 03-09｜非數字分數

---

程式：`03_score_stats.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
2
60 x
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Invalid score
```

---

預期結束碼：`1`

---

#### 03-10｜缺一筆

---

程式：`03_score_stats.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
2
60
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Invalid score
```

---

預期結束碼：`1`

---

### 案例 04

---

#### 04-01｜題目資料

---

程式：`04_ordered_difference.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
5
10 15 90 200 110
```

---

**預期標準輸出**

```text
brute=190 linear=190
```

---

預期結束碼：`0`

---

#### 04-02｜全程下降

---

程式：`04_ordered_difference.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
3
9 7 4
```

---

**預期標準輸出**

```text
brute=-2 linear=-2
```

---

預期結束碼：`0`

---

#### 04-03｜最低值在最高值之後

---

程式：`04_ordered_difference.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
3
100 1 2
```

---

**預期標準輸出**

```text
brute=1 linear=1
```

---

預期結束碼：`0`

---

#### 04-04｜兩個時刻

---

程式：`04_ordered_difference.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
2
-10000 10000
```

---

**預期標準輸出**

```text
brute=20000 linear=20000
```

---

預期結束碼：`0`

---

#### 04-05｜全部相同

---

程式：`04_ordered_difference.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
3
5 5 5
```

---

**預期標準輸出**

```text
brute=0 linear=0
```

---

預期結束碼：`0`

---

#### 04-06｜交錯正負

---

程式：`04_ordered_difference.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
5
-8 2 -10 3 -1
```

---

**預期標準輸出**

```text
brute=13 linear=13
```

---

預期結束碼：`0`

---

#### 04-07｜人數不足

---

程式：`04_ordered_difference.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
1
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Expected count 2..100
```

---

預期結束碼：`1`

---

#### 04-08｜容量超界

---

程式：`04_ordered_difference.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
101
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Expected count 2..100
```

---

預期結束碼：`1`

---

#### 04-09｜值超界

---

程式：`04_ordered_difference.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
2
0 10001
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Invalid sample
```

---

預期結束碼：`1`

---

#### 04-10｜缺值

---

程式：`04_ordered_difference.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
2
9
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Invalid sample
```

---

預期結束碼：`1`

---

### 案例 05

---

#### 05-01｜題目資料

---

程式：`05_matrix_report.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
10 20 30 40 5 15 25 35 8 12 16 24
```

---

**預期標準輸出**

```text
rows=100 80 60
cols=23 47 71 99
total=240
```

---

預期結束碼：`0`

---

#### 05-02｜全零

---

程式：`05_matrix_report.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
0 0 0 0 0 0 0 0 0 0 0 0
```

---

**預期標準輸出**

```text
rows=0 0 0
cols=0 0 0 0
total=0
```

---

預期結束碼：`0`

---

#### 05-03｜每格10000

---

程式：`05_matrix_report.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
10000 10000 10000 10000 10000 10000 10000 10000 10000 10000 10000 10000
```

---

**預期標準輸出**

```text
rows=40000 40000 40000
cols=30000 30000 30000 30000
total=120000
```

---

預期結束碼：`0`

---

#### 05-04｜row-major順序

---

程式：`05_matrix_report.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
1 2 3 4 5 6 7 8 9 10 11 12
```

---

**預期標準輸出**

```text
rows=10 26 42
cols=15 18 21 24
total=78
```

---

預期結束碼：`0`

---

#### 05-05｜負產量

---

程式：`05_matrix_report.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
-1
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Invalid quantity
```

---

預期結束碼：`1`

---

#### 05-06｜超範圍

---

程式：`05_matrix_report.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
10001
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Invalid quantity
```

---

預期結束碼：`1`

---

#### 05-07｜缺11筆

---

程式：`05_matrix_report.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
5
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Invalid quantity
```

---

預期結束碼：`1`

---

#### 05-08｜非數字

---

程式：`05_matrix_report.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
x
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Invalid quantity
```

---

預期結束碼：`1`

---

### 案例 06

---

#### 06-01｜題目利率

---

程式：`06_interest_table.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
6 5
```

---

**預期標準輸出**

```text
Year       6%       7%       8%       9%      10%
   1   106.00   107.00   108.00   109.00   110.00
   2   112.36   114.49   116.64   118.81   121.00
   3   119.10   122.50   125.97   129.50   133.10
   4   126.25   131.08   136.05   141.16   146.41
   5   133.82   140.26   146.93   153.86   161.05
```

---

預期結束碼：`0`

---

#### 06-02｜零起始利率

---

程式：`06_interest_table.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
0 1
```

---

**預期標準輸出**

```text
Year       0%       1%       2%       3%       4%
   1   100.00   101.00   102.00   103.00   104.00
```

---

預期結束碼：`0`

---

#### 06-03｜上限情境

---

程式：`06_interest_table.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
20 30
```

---

**預期標準輸出**

```text
Year      20%      21%      22%      23%      24%
   1   120.00   121.00   122.00   123.00   124.00
   2   144.00   146.41   148.84   151.29   153.76
   3   172.80   177.16   181.58   186.09   190.66
   4   207.36   214.36   221.53   228.89   236.42
   5   248.83   259.37   270.27   281.53   293.16
   6   298.60   313.84   329.73   346.28   363.52
   7   358.32   379.75   402.27   425.93   450.77
   8   429.98   459.50   490.77   523.89   558.95
   9   515.98   555.99   598.74   644.39   693.10
  10   619.17   672.75   730.46   792.59   859.44
  11   743.01   814.03   891.17   974.89  1065.71
  12   891.61   984.97  1087.22  1199.12  1321.48
  13  1069.93  1191.82  1326.41  1474.91  1638.63
  14  1283.92  1442.10  1618.22  1814.14  2031.91
  15  1540.70  1744.94  1974.23  2231.40  2519.56
  16  1848.84  2111.38  2408.56  2744.62  3124.26
  17  2218.61  2554.77  2938.44  3375.88  3874.08
  18  2662.33  3091.27  3584.90  4152.33  4803.86
  19  3194.80  3740.43  4373.58  5107.37  5956.79
  20  3833.76  4525.93  5335.76  6282.06  7386.41
  21  4600.51  5476.37  6509.63  7726.94  9159.15
  22  5520.61  6626.41  7941.75  9504.13 11357.35
  23  6624.74  8017.95  9688.94 11690.08 14083.12
  24  7949.68  9701.72 11820.50 14378.80 17463.06
  25  9539.62 11739.09 14421.01 17685.93 21654.20
  26 11447.55 14204.29 17593.64 21753.69 26851.21
  27 13737.06 17187.19 21464.24 26757.04 33295.50
  28 16484.47 20796.51 26186.37 32911.15 41286.42
  29 19781.36 25163.77 31947.37 40480.72 51195.16
  30 23737.63 30448.16 38975.79 49791.29 63481.99
```

---

預期結束碼：`0`

---

#### 06-04｜負利率

---

程式：`06_interest_table.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
-1 5
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Expected rate 0..20 and years 1..30
```

---

預期結束碼：`1`

---

#### 06-05｜超過利率

---

程式：`06_interest_table.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
21 1
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Expected rate 0..20 and years 1..30
```

---

預期結束碼：`1`

---

#### 06-06｜零年

---

程式：`06_interest_table.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
6 0
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Expected rate 0..20 and years 1..30
```

---

預期結束碼：`1`

---

#### 06-07｜超過年數

---

程式：`06_interest_table.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
6 31
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Expected rate 0..20 and years 1..30
```

---

預期結束碼：`1`

---

#### 06-08｜缺少年數

---

程式：`06_interest_table.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
6
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Expected rate 0..20 and years 1..30
```

---

預期結束碼：`1`

---

### 案例 07

---

#### 07-01｜零張

---

程式：`07_deal_cards.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
0 42
```

---

**預期標準輸出**

```text

```

---

預期結束碼：`0`

---

#### 07-02｜題目五張種子1

---

程式：`07_deal_cards.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
5 1
```

---

**預期標準輸出**

```text

```

---

預期結束碼：`0`

---

#### 07-03｜五張種子42

---

程式：`07_deal_cards.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
5 42
```

---

**預期標準輸出**

```text

```

---

預期結束碼：`0`

---

#### 07-04｜全副52張

---

程式：`07_deal_cards.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
52 42
```

---

**預期標準輸出**

```text

```

---

預期結束碼：`0`

---

#### 07-05｜單張

---

程式：`07_deal_cards.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
1 0
```

---

**預期標準輸出**

```text

```

---

預期結束碼：`0`

---

#### 07-06｜另一種子

---

程式：`07_deal_cards.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
10 123
```

---

**預期標準輸出**

```text

```

---

預期結束碼：`0`

---

#### 07-07｜超過52張

---

程式：`07_deal_cards.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
53 42
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Expected count 0..52 and unsigned seed
```

---

預期結束碼：`1`

---

#### 07-08｜負張數

---

程式：`07_deal_cards.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
-1 42
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Expected count 0..52 and unsigned seed
```

---

預期結束碼：`1`

---

#### 07-09｜缺少種子

---

程式：`07_deal_cards.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
5
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Expected count 0..52 and unsigned seed
```

---

預期結束碼：`1`

---

#### 07-10｜非數字

---

程式：`07_deal_cards.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
x 42
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Expected count 0..52 and unsigned seed
```

---

預期結束碼：`1`

---

### 案例 08

---

#### 08-01｜文字檔可開啟

---

程式：`08_canopen.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text
sample.txt can be opened
```

---

預期結束碼：`0`

---

**命令列參數**

- sample.txt

---

**檔案資料**

- **sample.txt**

```text
Hello
```

---

#### 08-02｜空檔也可開啟

---

程式：`08_canopen.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text
empty.txt can be opened
```

---

預期結束碼：`0`

---

**命令列參數**

- empty.txt

---

**檔案資料**

- **empty.txt**

```text

```

---

#### 08-03｜檔案不存在

---

程式：`08_canopen.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text

```

---

預期結束碼：`1`

---

**命令列參數**

- missing.txt

---

#### 08-04｜缺少檔名

---

程式：`08_canopen.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
usage: canopen filename
```

---

預期結束碼：`1`

---

#### 08-05｜多一個參數

---

程式：`08_canopen.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
usage: canopen filename
```

---

預期結束碼：`1`

---

**命令列參數**

- a
- b

---

### 案例 09

---

#### 09-01｜閏年斜線

---

程式：`09_date_parser.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
2024/02/29
```

---

**預期標準輸出**

```text
2024-02-29
```

---

預期結束碼：`0`

---

#### 09-02｜400年規則

---

程式：`09_date_parser.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
2000-02-29
```

---

**預期標準輸出**

```text
2000-02-29
```

---

預期結束碼：`0`

---

#### 09-03｜年份上界

---

程式：`09_date_parser.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
2099-12-31
```

---

**預期標準輸出**

```text
2099-12-31
```

---

預期結束碼：`0`

---

#### 09-04｜沒有末尾換行

---

程式：`09_date_parser.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
2024-01-01
```

---

**預期標準輸出**

```text
2024-01-01
```

---

預期結束碼：`0`

---

#### 09-05｜CRLF結尾

---

程式：`09_date_parser.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
2024/02/29
```

---

**預期標準輸出**

```text
2024-02-29
```

---

預期結束碼：`0`

---

#### 09-06｜平年2月29

---

程式：`09_date_parser.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
2025-02-29
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Invalid day
```

---

預期結束碼：`1`

---

#### 09-07｜1900不是閏年

---

程式：`09_date_parser.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
1900-02-29
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Invalid day
```

---

預期結束碼：`1`

---

#### 09-08｜4月31日

---

程式：`09_date_parser.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
2024-04-31
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Invalid day
```

---

預期結束碼：`1`

---

#### 09-09｜分隔符混用

---

程式：`09_date_parser.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
2024-02/29
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Invalid date format/range
```

---

預期結束碼：`1`

---

#### 09-10｜年份越界

---

程式：`09_date_parser.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
2100-01-01
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Invalid date format/range
```

---

預期結束碼：`1`

---

#### 09-11｜月份13

---

程式：`09_date_parser.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
2024-13-01
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Invalid date format/range
```

---

預期結束碼：`1`

---

#### 09-12｜尾端垃圾

---

程式：`09_date_parser.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
2024-02-29x
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Expected YYYY-MM-DD or YYYY/MM/DD
```

---

預期結束碼：`1`

---

#### 09-13｜非數字日期

---

程式：`09_date_parser.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
20x4-02-29
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Invalid date digits
```

---

預期結束碼：`1`

---

#### 09-14｜空輸入

---

程式：`09_date_parser.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Missing date
```

---

預期結束碼：`1`

---

### 案例 10

---

#### 10-01｜a版：含00/1A/FF

---

程式：`10a_copy_character.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text
Copy complete
```

---

預期結束碼：`0`

---

**命令列參數**

- source.bin
- copy.bin

---

**檔案資料**

- **source.bin**：`{"hex": "001aff410a"}`

---

**額外檢查**

- **source.bin**：`{"hex": "001aff410a"}`
- **copy.bin**：`{"hex": "001aff410a"}`

---

#### 10-02｜a版：空檔

---

程式：`10a_copy_character.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text
Copy complete
```

---

預期結束碼：`0`

---

**命令列參數**

- source.bin
- copy.bin

---

**檔案資料**

- **source.bin**：`{"hex": ""}`

---

**額外檢查**

- **source.bin**：`{"hex": ""}`
- **copy.bin**：`{"hex": ""}`

---

#### 10-03｜a版：ASCII文字

---

程式：`10a_copy_character.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text
Copy complete
```

---

預期結束碼：`0`

---

**命令列參數**

- source.bin
- copy.bin

---

**檔案資料**

- **source.bin**：`{"hex": "432061727261790a66696c6520492f4f0a"}`

---

**額外檢查**

- **source.bin**：`{"hex": "432061727261790a66696c6520492f4f0a"}`
- **copy.bin**：`{"hex": "432061727261790a66696c6520492f4f0a"}`

---

#### 10-04｜a版：跨越4096邊界

---

程式：`10a_copy_character.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text
Copy complete
```

---

預期結束碼：`0`

---

**命令列參數**

- source.bin
- copy.bin

---

**檔案資料**

- **source.bin**：`{"hex": "000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff61626364"}`

---

**額外檢查**

- **source.bin**：`{"hex": "000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff61626364"}`
- **copy.bin**：`{"hex": "000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff61626364"}`

---

#### 10-05｜a版：目的已存在

---

程式：`10a_copy_character.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Destination exists or cannot be created
```

---

預期結束碼：`1`

---

**命令列參數**

- source.bin
- copy.bin

---

**檔案資料**

- **source.bin**

```text
source
```
- **copy.bin**

```text
KEEP
```

---

**額外檢查**

- **copy.bin**

```text
KEEP
```

---

#### 10-06｜a版：來源不存在

---

程式：`10a_copy_character.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Cannot open source
```

---

預期結束碼：`1`

---

**命令列參數**

- none.bin
- copy.bin

---

**額外檢查**

- **copy.bin**：檔案不存在

---

#### 10-07｜a版：來源目的相同

---

程式：`10a_copy_character.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Destination exists or cannot be created
```

---

預期結束碼：`1`

---

**命令列參數**

- source.bin
- source.bin

---

**檔案資料**

- **source.bin**

```text
KEEP
```

---

**額外檢查**

- **source.bin**

```text
KEEP
```

---

#### 10-08｜a版：缺少參數

---

程式：`10a_copy_character.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
usage: copy_character source new_destination
```

---

預期結束碼：`1`

---

#### 10-09｜b版：含00/1A/FF

---

程式：`10b_copy_block.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text
Copy complete
```

---

預期結束碼：`0`

---

**命令列參數**

- source.bin
- copy.bin

---

**檔案資料**

- **source.bin**：`{"hex": "001aff410a"}`

---

**額外檢查**

- **source.bin**：`{"hex": "001aff410a"}`
- **copy.bin**：`{"hex": "001aff410a"}`

---

#### 10-10｜b版：空檔

---

程式：`10b_copy_block.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text
Copy complete
```

---

預期結束碼：`0`

---

**命令列參數**

- source.bin
- copy.bin

---

**檔案資料**

- **source.bin**：`{"hex": ""}`

---

**額外檢查**

- **source.bin**：`{"hex": ""}`
- **copy.bin**：`{"hex": ""}`

---

#### 10-11｜b版：ASCII文字

---

程式：`10b_copy_block.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text
Copy complete
```

---

預期結束碼：`0`

---

**命令列參數**

- source.bin
- copy.bin

---

**檔案資料**

- **source.bin**：`{"hex": "432061727261790a66696c6520492f4f0a"}`

---

**額外檢查**

- **source.bin**：`{"hex": "432061727261790a66696c6520492f4f0a"}`
- **copy.bin**：`{"hex": "432061727261790a66696c6520492f4f0a"}`

---

#### 10-12｜b版：跨越4096邊界

---

程式：`10b_copy_block.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text
Copy complete
```

---

預期結束碼：`0`

---

**命令列參數**

- source.bin
- copy.bin

---

**檔案資料**

- **source.bin**：`{"hex": "000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff61626364"}`

---

**額外檢查**

- **source.bin**：`{"hex": "000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff61626364"}`
- **copy.bin**：`{"hex": "000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fafbfcfdfeff61626364"}`

---

#### 10-13｜b版：目的已存在

---

程式：`10b_copy_block.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Destination exists or cannot be created
```

---

預期結束碼：`1`

---

**命令列參數**

- source.bin
- copy.bin

---

**檔案資料**

- **source.bin**

```text
source
```
- **copy.bin**

```text
KEEP
```

---

**額外檢查**

- **copy.bin**

```text
KEEP
```

---

#### 10-14｜b版：來源不存在

---

程式：`10b_copy_block.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Cannot open source
```

---

預期結束碼：`1`

---

**命令列參數**

- none.bin
- copy.bin

---

**額外檢查**

- **copy.bin**：檔案不存在

---

#### 10-15｜b版：來源目的相同

---

程式：`10b_copy_block.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Destination exists or cannot be created
```

---

預期結束碼：`1`

---

**命令列參數**

- source.bin
- source.bin

---

**檔案資料**

- **source.bin**

```text
KEEP
```

---

**額外檢查**

- **source.bin**

```text
KEEP
```

---

#### 10-16｜b版：缺少參數

---

程式：`10b_copy_block.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
usage: copy_block source new_destination
```

---

預期結束碼：`1`

---

### 案例 11

---

#### 11-01｜建立與定位更新

---

程式：`11_stock_update.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text
old=35 new=99
10 20 99 40 50
```

---

預期結束碼：`0`

---

**命令列參數**

- stock.bin

---

**額外檢查**

- **stock.bin**：`{"native_ints": [10, 20, 99, 40, 50]}`

---

#### 11-02｜拒絕既有檔案

---

程式：`11_stock_update.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Cannot create new stock file
```

---

預期結束碼：`1`

---

**命令列參數**

- stock.bin

---

**檔案資料**

- **stock.bin**

```text
KEEP
```

---

**額外檢查**

- **stock.bin**

```text
KEEP
```

---

#### 11-03｜父目錄不存在

---

程式：`11_stock_update.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Cannot create new stock file
```

---

預期結束碼：`1`

---

**命令列參數**

- not_here/stock.bin

---

#### 11-04｜缺少檔名

---

程式：`11_stock_update.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
usage: stock_update new_binary_file
```

---

預期結束碼：`1`

---

### 案例 12

---

#### 12-01｜題目空白正號

---

程式：`12_strict_score.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
  +86
```

---

**預期標準輸出**

```text
score=86
```

---

預期結束碼：`0`

---

#### 12-02｜零分

---

程式：`12_strict_score.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
0
```

---

**預期標準輸出**

```text
score=0
```

---

預期結束碼：`0`

---

#### 12-03｜一百分

---

程式：`12_strict_score.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
100
```

---

**預期標準輸出**

```text
score=100
```

---

預期結束碼：`0`

---

#### 12-04｜無末尾換行

---

程式：`12_strict_score.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
86
```

---

**預期標準輸出**

```text
score=86
```

---

預期結束碼：`0`

---

#### 12-05｜126bytes合法行

---

程式：`12_strict_score.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
86
```

---

**預期標準輸出**

```text
score=86
```

---

預期結束碼：`0`

---

#### 12-06｜126bytes無換行

---

程式：`12_strict_score.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
86
```

---

**預期標準輸出**

```text
score=86
```

---

預期結束碼：`0`

---

#### 12-07｜尾端文字

---

程式：`12_strict_score.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
86abc
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Trailing text
```

---

預期結束碼：`1`

---

#### 12-08｜兩個值

---

程式：`12_strict_score.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
86 90
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Trailing text
```

---

預期結束碼：`1`

---

#### 12-09｜小數

---

程式：`12_strict_score.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
86.5
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Trailing text
```

---

預期結束碼：`1`

---

#### 12-10｜負數

---

程式：`12_strict_score.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
-1
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Out of range
```

---

預期結束碼：`1`

---

#### 12-11｜大於100

---

程式：`12_strict_score.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
101
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Out of range
```

---

預期結束碼：`1`

---

#### 12-12｜60位大整數

---

程式：`12_strict_score.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
999999999999999999999999999999999999999999999999999999999999
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Out of range
```

---

預期結束碼：`1`

---

#### 12-13｜空白行

---

程式：`12_strict_score.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
No number
```

---

預期結束碼：`1`

---

#### 12-14｜只有正號

---

程式：`12_strict_score.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
+
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
No number
```

---

預期結束碼：`1`

---

#### 12-15｜127bytes行

---

程式：`12_strict_score.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
86
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Line too long (max 126 bytes)
```

---

預期結束碼：`1`

---

#### 12-16｜127bytes無換行

---

程式：`12_strict_score.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
86
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Line too long (max 126 bytes)
```

---

預期結束碼：`1`

---

#### 12-17｜空輸入

---

程式：`12_strict_score.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
No input
```

---

預期結束碼：`1`

---

### 案例 13

---

#### 13-01｜四的平方根

---

程式：`13_assert_sqrt.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
4
```

---

**預期標準輸出**

```text
sqrt=2.000000
```

---

預期結束碼：`0`

---

#### 13-02｜零

---

程式：`13_assert_sqrt.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
0
```

---

**預期標準輸出**

```text
sqrt=0.000000
```

---

預期結束碼：`0`

---

#### 13-03｜非整數平方根

---

程式：`13_assert_sqrt.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
2
```

---

**預期標準輸出**

```text
sqrt=1.414214
```

---

預期結束碼：`0`

---

#### 13-04｜小數

---

程式：`13_assert_sqrt.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
0.25
```

---

**預期標準輸出**

```text
sqrt=0.500000
```

---

預期結束碼：`0`

---

#### 13-05｜負數

---

程式：`13_assert_sqrt.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
-1
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Expected a finite, nonnegative value
```

---

預期結束碼：`1`

---

#### 13-06｜NaN

---

程式：`13_assert_sqrt.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
nan
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Expected a finite, nonnegative value
```

---

預期結束碼：`1`

---

#### 13-07｜正無窮

---

程式：`13_assert_sqrt.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
inf
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Expected a finite, nonnegative value
```

---

預期結束碼：`1`

---

#### 13-08｜負無窮

---

程式：`13_assert_sqrt.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
-inf
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Expected a finite, nonnegative value
```

---

預期結束碼：`1`

---

#### 13-09｜非數字

---

程式：`13_assert_sqrt.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text
abc
```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Expected a finite, nonnegative value
```

---

預期結束碼：`1`

---

#### 13-10｜空輸入

---

程式：`13_assert_sqrt.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Expected a finite, nonnegative value
```

---

預期結束碼：`1`

---

### 案例 14

---

#### 14-01｜三個log結果與errno分類

---

程式：`14_math_errno.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text

```

---

預期結束碼：`0`

---

### 案例 15

---

#### 15-01｜題目四筆資料

---

程式：`15_grade_file.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text
Report created
```

---

預期結束碼：`0`

---

**命令列參數**

- grades.txt
- report.txt

---

**檔案資料**

- **grades.txt**

```text
S001,86
S002,100
S003,59
S004,75
```

---

**額外檢查**

- **grades.txt**

```text
S001,86
S002,100
S003,59
S004,75
```
- **report.txt**

```text
count=4 average=80.00 min=59 max=100 pass=3
S001,86,PASS
S002,100,PASS
S003,59,FAIL
S004,75,PASS
```

---

#### 15-02｜最低最高ID

---

程式：`15_grade_file.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text
Report created
```

---

預期結束碼：`0`

---

**命令列參數**

- grades.txt
- report.txt

---

**檔案資料**

- **grades.txt**

```text
S000,0
S999,100
```

---

**額外檢查**

- **grades.txt**

```text
S000,0
S999,100
```
- **report.txt**

```text
count=2 average=50.00 min=0 max=100 pass=1
S000,0,FAIL
S999,100,PASS
```

---

#### 15-03｜分數前後空白與正號

---

程式：`15_grade_file.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text
Report created
```

---

預期結束碼：`0`

---

**命令列參數**

- grades.txt
- report.txt

---

**檔案資料**

- **grades.txt**

```text
S001,  +86
```

---

**額外檢查**

- **grades.txt**

```text
S001,  +86
```
- **report.txt**

```text
count=1 average=86.00 min=86 max=86 pass=1
S001,86,PASS
```

---

#### 15-04｜末尾不含換行

---

程式：`15_grade_file.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text
Report created
```

---

預期結束碼：`0`

---

**命令列參數**

- grades.txt
- report.txt

---

**檔案資料**

- **grades.txt**

```text
S001,86
```

---

**額外檢查**

- **grades.txt**

```text
S001,86
```
- **report.txt**

```text
count=1 average=86.00 min=86 max=86 pass=1
S001,86,PASS
```

---

#### 15-05｜CRLF

---

程式：`15_grade_file.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text
Report created
```

---

預期結束碼：`0`

---

**命令列參數**

- grades.txt
- report.txt

---

**檔案資料**

- **grades.txt**

```text
S001,60
S002,59
```

---

**額外檢查**

- **grades.txt**

```text
S001,60
S002,59
```
- **report.txt**

```text
count=2 average=59.50 min=59 max=60 pass=1
S001,60,PASS
S002,59,FAIL
```

---

#### 15-06｜100筆容量上限

---

程式：`15_grade_file.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text
Report created
```

---

預期結束碼：`0`

---

**命令列參數**

- grades.txt
- report.txt

---

**檔案資料**

- **grades.txt**

```text
S000,0
S001,1
S002,2
S003,3
S004,4
S005,5
S006,6
S007,7
S008,8
S009,9
S010,10
S011,11
S012,12
S013,13
S014,14
S015,15
S016,16
S017,17
S018,18
S019,19
S020,20
S021,21
S022,22
S023,23
S024,24
S025,25
S026,26
S027,27
S028,28
S029,29
S030,30
S031,31
S032,32
S033,33
S034,34
S035,35
S036,36
S037,37
S038,38
S039,39
S040,40
S041,41
S042,42
S043,43
S044,44
S045,45
S046,46
S047,47
S048,48
S049,49
S050,50
S051,51
S052,52
S053,53
S054,54
S055,55
S056,56
S057,57
S058,58
S059,59
S060,60
S061,61
S062,62
S063,63
S064,64
S065,65
S066,66
S067,67
S068,68
S069,69
S070,70
S071,71
S072,72
S073,73
S074,74
S075,75
S076,76
S077,77
S078,78
S079,79
S080,80
S081,81
S082,82
S083,83
S084,84
S085,85
S086,86
S087,87
S088,88
S089,89
S090,90
S091,91
S092,92
S093,93
S094,94
S095,95
S096,96
S097,97
S098,98
S099,99
```

---

**額外檢查**

- **grades.txt**

```text
S000,0
S001,1
S002,2
S003,3
S004,4
S005,5
S006,6
S007,7
S008,8
S009,9
S010,10
S011,11
S012,12
S013,13
S014,14
S015,15
S016,16
S017,17
S018,18
S019,19
S020,20
S021,21
S022,22
S023,23
S024,24
S025,25
S026,26
S027,27
S028,28
S029,29
S030,30
S031,31
S032,32
S033,33
S034,34
S035,35
S036,36
S037,37
S038,38
S039,39
S040,40
S041,41
S042,42
S043,43
S044,44
S045,45
S046,46
S047,47
S048,48
S049,49
S050,50
S051,51
S052,52
S053,53
S054,54
S055,55
S056,56
S057,57
S058,58
S059,59
S060,60
S061,61
S062,62
S063,63
S064,64
S065,65
S066,66
S067,67
S068,68
S069,69
S070,70
S071,71
S072,72
S073,73
S074,74
S075,75
S076,76
S077,77
S078,78
S079,79
S080,80
S081,81
S082,82
S083,83
S084,84
S085,85
S086,86
S087,87
S088,88
S089,89
S090,90
S091,91
S092,92
S093,93
S094,94
S095,95
S096,96
S097,97
S098,98
S099,99
```
- **report.txt**

```text
count=100 average=49.50 min=0 max=99 pass=40
S000,0,FAIL
S001,1,FAIL
S002,2,FAIL
S003,3,FAIL
S004,4,FAIL
S005,5,FAIL
S006,6,FAIL
S007,7,FAIL
S008,8,FAIL
S009,9,FAIL
S010,10,FAIL
S011,11,FAIL
S012,12,FAIL
S013,13,FAIL
S014,14,FAIL
S015,15,FAIL
S016,16,FAIL
S017,17,FAIL
S018,18,FAIL
S019,19,FAIL
S020,20,FAIL
S021,21,FAIL
S022,22,FAIL
S023,23,FAIL
S024,24,FAIL
S025,25,FAIL
S026,26,FAIL
S027,27,FAIL
S028,28,FAIL
S029,29,FAIL
S030,30,FAIL
S031,31,FAIL
S032,32,FAIL
S033,33,FAIL
S034,34,FAIL
S035,35,FAIL
S036,36,FAIL
S037,37,FAIL
S038,38,FAIL
S039,39,FAIL
S040,40,FAIL
S041,41,FAIL
S042,42,FAIL
S043,43,FAIL
S044,44,FAIL
S045,45,FAIL
S046,46,FAIL
S047,47,FAIL
S048,48,FAIL
S049,49,FAIL
S050,50,FAIL
S051,51,FAIL
S052,52,FAIL
S053,53,FAIL
S054,54,FAIL
S055,55,FAIL
S056,56,FAIL
S057,57,FAIL
S058,58,FAIL
S059,59,FAIL
S060,60,PASS
S061,61,PASS
S062,62,PASS
S063,63,PASS
S064,64,PASS
S065,65,PASS
S066,66,PASS
S067,67,PASS
S068,68,PASS
S069,69,PASS
S070,70,PASS
S071,71,PASS
S072,72,PASS
S073,73,PASS
S074,74,PASS
S075,75,PASS
S076,76,PASS
S077,77,PASS
S078,78,PASS
S079,79,PASS
S080,80,PASS
S081,81,PASS
S082,82,PASS
S083,83,PASS
S084,84,PASS
S085,85,PASS
S086,86,PASS
S087,87,PASS
S088,88,PASS
S089,89,PASS
S090,90,PASS
S091,91,PASS
S092,92,PASS
S093,93,PASS
S094,94,PASS
S095,95,PASS
S096,96,PASS
S097,97,PASS
S098,98,PASS
S099,99,PASS
```

---

#### 15-07｜126bytes合法列

---

程式：`15_grade_file.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text
Report created
```

---

預期結束碼：`0`

---

**命令列參數**

- grades.txt
- report.txt

---

**檔案資料**

- **grades.txt**

```text
S001,86
```

---

**額外檢查**

- **grades.txt**

```text
S001,86
```
- **report.txt**

```text
count=1 average=86.00 min=86 max=86 pass=1
S001,86,PASS
```

---

#### 15-08｜空檔

---

程式：`15_grade_file.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Empty input
```

---

預期結束碼：`1`

---

**命令列參數**

- grades.txt
- report.txt

---

**檔案資料**

- **grades.txt**

```text

```

---

**額外檢查**

- **report.txt**：檔案不存在

---

#### 15-09｜重複ID

---

程式：`15_grade_file.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Line 2: duplicate ID or capacity exceeded
```

---

預期結束碼：`1`

---

**命令列參數**

- grades.txt
- report.txt

---

**檔案資料**

- **grades.txt**

```text
S001,86
S001,75
```

---

**額外檢查**

- **report.txt**：檔案不存在

---

#### 15-10｜尾端垃圾

---

程式：`15_grade_file.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Line 1: invalid record
```

---

預期結束碼：`1`

---

**命令列參數**

- grades.txt
- report.txt

---

**檔案資料**

- **grades.txt**

```text
S001,86abc
```

---

**額外檢查**

- **report.txt**：檔案不存在

---

#### 15-11｜大於100

---

程式：`15_grade_file.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Line 1: invalid record
```

---

預期結束碼：`1`

---

**命令列參數**

- grades.txt
- report.txt

---

**檔案資料**

- **grades.txt**

```text
S001,101
```

---

**額外檢查**

- **report.txt**：檔案不存在

---

#### 15-12｜負分數

---

程式：`15_grade_file.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Line 1: invalid record
```

---

預期結束碼：`1`

---

**命令列參數**

- grades.txt
- report.txt

---

**檔案資料**

- **grades.txt**

```text
S001,-1
```

---

**額外檢查**

- **report.txt**：檔案不存在

---

#### 15-13｜缺少分數

---

程式：`15_grade_file.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Line 1: invalid record
```

---

預期結束碼：`1`

---

**命令列參數**

- grades.txt
- report.txt

---

**檔案資料**

- **grades.txt**

```text
S001,
```

---

**額外檢查**

- **report.txt**：檔案不存在

---

#### 15-14｜60位數整數

---

程式：`15_grade_file.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Line 1: invalid record
```

---

預期結束碼：`1`

---

**命令列參數**

- grades.txt
- report.txt

---

**檔案資料**

- **grades.txt**

```text
S001,999999999999999999999999999999999999999999999999999999999999
```

---

**額外檢查**

- **report.txt**：檔案不存在

---

#### 15-15｜空白列

---

程式：`15_grade_file.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Line 2: invalid record
```

---

預期結束碼：`1`

---

**命令列參數**

- grades.txt
- report.txt

---

**檔案資料**

- **grades.txt**

```text
S001,86
```

---

**額外檢查**

- **report.txt**：檔案不存在

---

#### 15-16｜ID前空白

---

程式：`15_grade_file.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Line 1: invalid record
```

---

預期結束碼：`1`

---

**命令列參數**

- grades.txt
- report.txt

---

**檔案資料**

- **grades.txt**

```text
 S001,86
```

---

**額外檢查**

- **report.txt**：檔案不存在

---

#### 15-17｜不接受標題列

---

程式：`15_grade_file.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Line 1: invalid record
```

---

預期結束碼：`1`

---

**命令列參數**

- grades.txt
- report.txt

---

**檔案資料**

- **grades.txt**

```text
id,score
```

---

**額外檢查**

- **report.txt**：檔案不存在

---

#### 15-18｜BOM前綴

---

程式：`15_grade_file.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Line 1: invalid record
```

---

預期結束碼：`1`

---

**命令列參數**

- grades.txt
- report.txt

---

**檔案資料**

- **grades.txt**

```text
﻿S001,86
```

---

**額外檢查**

- **report.txt**：檔案不存在

---

#### 15-19｜ID不是三位數

---

程式：`15_grade_file.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Line 1: invalid record
```

---

預期結束碼：`1`

---

**命令列參數**

- grades.txt
- report.txt

---

**檔案資料**

- **grades.txt**

```text
S01,86
```

---

**額外檢查**

- **report.txt**：檔案不存在

---

#### 15-20｜127bytes列

---

程式：`15_grade_file.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Line 1: too long
```

---

預期結束碼：`1`

---

**命令列參數**

- grades.txt
- report.txt

---

**檔案資料**

- **grades.txt**

```text
S001,86
```

---

**額外檢查**

- **report.txt**：檔案不存在

---

#### 15-21｜101筆

---

程式：`15_grade_file.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Line 101: duplicate ID or capacity exceeded
```

---

預期結束碼：`1`

---

**命令列參數**

- grades.txt
- report.txt

---

**檔案資料**

- **grades.txt**

```text
S000,60
S001,60
S002,60
S003,60
S004,60
S005,60
S006,60
S007,60
S008,60
S009,60
S010,60
S011,60
S012,60
S013,60
S014,60
S015,60
S016,60
S017,60
S018,60
S019,60
S020,60
S021,60
S022,60
S023,60
S024,60
S025,60
S026,60
S027,60
S028,60
S029,60
S030,60
S031,60
S032,60
S033,60
S034,60
S035,60
S036,60
S037,60
S038,60
S039,60
S040,60
S041,60
S042,60
S043,60
S044,60
S045,60
S046,60
S047,60
S048,60
S049,60
S050,60
S051,60
S052,60
S053,60
S054,60
S055,60
S056,60
S057,60
S058,60
S059,60
S060,60
S061,60
S062,60
S063,60
S064,60
S065,60
S066,60
S067,60
S068,60
S069,60
S070,60
S071,60
S072,60
S073,60
S074,60
S075,60
S076,60
S077,60
S078,60
S079,60
S080,60
S081,60
S082,60
S083,60
S084,60
S085,60
S086,60
S087,60
S088,60
S089,60
S090,60
S091,60
S092,60
S093,60
S094,60
S095,60
S096,60
S097,60
S098,60
S099,60
S100,60
```

---

**額外檢查**

- **report.txt**：檔案不存在

---

#### 15-22｜保護既有報表

---

程式：`15_grade_file.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Report exists or cannot be created
```

---

預期結束碼：`1`

---

**命令列參數**

- grades.txt
- report.txt

---

**檔案資料**

- **grades.txt**

```text
S001,86
```
- **report.txt**

```text
KEEP
```

---

**額外檢查**

- **report.txt**

```text
KEEP
```

---

#### 15-23｜來源不存在

---

程式：`15_grade_file.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
Cannot open input
```

---

預期結束碼：`1`

---

**命令列參數**

- missing.txt
- report.txt

---

**額外檢查**

- **report.txt**：檔案不存在

---

#### 15-24｜缺少參數

---

程式：`15_grade_file.c`

---

測試來源：本次補充測試

---

**標準輸入**

```text

```

---

**預期標準輸出**

```text

```

---

**預期錯誤輸出**

```text
usage: grade_file input_csv new_report
```

---

預期結束碼：`1`

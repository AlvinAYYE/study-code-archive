# History of C

> 來源：cppreference C 語言參考文件（離線轉換版）。

## Early C

- 1969: B created, based on BCPL, to replace PDP-7 assembler as the system programming language for Unix
1969：基於 BCPL 建立 B，以取代 PDP-7 組合語言作為 Unix 的系統程式語言

- added operators `++`, `--`, compound assignment, remained a typeless language like BCPL
新增了運運算元 ++ 、 -- 、複合賦值，仍然是像 BCPL 一樣的無型別語言
新增了運運算元 ++ 、 -- 、複合賦值，仍然是像 BCPL 一樣的無型別語言

- 1971: NB ("new B") created when porting B to PDP-11
1971：將 B 移植到 PDP-11 時建立了 NB（"new B"）

- types (`int`, `char`, arrays and pointers), array-to-pointer conversion, compilation to machine code
型別（ int 、 char 、陣列和指標）、陣列到指標轉換、編譯為機器碼
型別（ int 、 char 、陣列和指標）、陣列到指標轉換、編譯為機器碼

- 1972: Language renamed to C
1972：語言更名為 C

- `struct`, operators `&&` and `||`, preprocessor, portable I/O
struct 、運運算元 && 和 || 、前處理器、可移植 I/O
struct 、運運算元 && 和 || 、前處理器、可移植 I/O

- 1973: Unix re-written in C
1973：Unix 用 C 重寫

- `unsigned`, `long`, `union`, enumerations, increased type safety
unsigned、long、union、列舉、增強的型別安全
unsigned、long、union、列舉、增強的型別安全

- 1978: The C Programming Language, 1st edition
1978：《C程式設計語言》第1版

## Standard C

- 1983: ANSI established X3J11 committee
1983：ANSI 成立 X3J11 委員會

- 1988: The C Programming Language, 2nd edition
1988：《C程式設計語言》第2版

- 1989: **C89**, the ANSI C standard published
1989：C89，ANSI C 標準釋出

- codified existing practices
將現有實踐編纂成規範

- new features: `volatile`, `enum`, `signed`, `void`, locales
新特性：volatile、enum、signed、void、locale

- From C++: `const`, function prototypes
來自 C++：const、函式原型

- 1990: **C90**, the ANSI C standard accepted as ISO/IEC 9899:1990
1990：C90，ANSI C 標準被接受為 ISO/IEC 9899:1990

- 1994: Technical corrigendum 1 (ISO/IEC 9899:1990/Cor.1:1994)
1994：技術勘誤表 1（ISO/IEC 9899:1990/Cor.1:1994）

- 44 small changes
44 處小修改
44 處小修改

- 1995: **C95** (ISO/IEC 9899:1990/Amd.1:1995) (online store)
1995：C95（ISO/IEC 9899:1990/Amd.1:1995）（線上商店）

- greatly expanded wide and multibyte character support (<wctype.h>, <wchar.h>, additions and changes to stream I/O, etc)
大幅擴充套件寬字元與多位元組字元支援（<wctype.h>、<wchar.h>、流 I/O 的增補與修改等）

- digraphs, <iso646.h>,
digraph（二字圖形符）、<iso646.h>，

- 1996: Technical corrigendum 2 (ISO/IEC 9899:1990/Cor.2:1996)
1996：技術勘誤表 2（ISO/IEC 9899:1990/Cor.2:1996）

- 24 small changes
24 處小修改
24 處小修改

- 1999: **C99** (ISO/IEC 9899:1999)
1999：C99（ISO/IEC 9899:1999）

- new features: `bool`, `long long`, <stdint.h>, <inttypes.h>, `restrict`, compound literals, variable length arrays, flexible array members, designated initializers, <fenv.h>, variadic macros, complex numbers, `__func__`, hexadecimal floating-point format (`%a`), monetary formatting in lconv, isblank, concatenation of narrow and wide string literals, trailing comma in enumerations, empty arguments in function-like macros, `STDC_*` pragmas, va_copy, null return of tmpnam, null pointer in setvbuf, `hh` and `ll` length-specifiers in printf, snprintf, _Exit, <tgmath.h>, POSIX-like strftime specifiers
新特性：bool、long long、<stdint.h>、<inttypes.h>、restrict、複合字面量、變長陣列、靈活陣列成員、指定初始化器、<fenv.h>、可變參數宏、複數、__func__、十六進位制浮點格式（%a）、lconv 中的貨幣格式化、isblank、窄字串字面量與寬字串字面量的拼接、列舉中的尾隨逗號、類函式宏中的空參數、STDC_* pragma、va_copy、tmpnam 的空傳回值、setvbuf 中的空指標、printf 中的 hh 和 ll 長度說明符、snprintf、_Exit、<tgmath.h>、類 POSIX 的 strftime 格式說明符

- from C++: `inline`, mix declarations and code, declarations in the init-clause of the for loop, `//` comments, universal character names in source code
來自 C++：inline、混合宣告與程式碼、for 迴圈 init 子句中的宣告、// 註釋、原始碼中的通用字元名

- removed implicit functions and implicit `int`
移除了隱式函式和隱式 int

- 2001: Technical corrigendum 1 (ISO/IEC 9899:1999/Cor.1:2001)
2001：技術勘誤表 1（ISO/IEC 9899:1999/Cor.1:2001）

- 11 defects fixed
修復 11 處缺陷
修復 11 處缺陷

- 2004: Technical corrigendum 2 (ISO/IEC 9899:1999/Cor.2:2004)
2004：技術勘誤表 2（ISO/IEC 9899:1999/Cor.2:2004）

- 2004: Unicode TR (ISO/IEC TR 19769:2004) (ISO store) (N1040 November 7, 2003 draft)
2004：Unicode TR（ISO/IEC TR 19769:2004）（ISO 商店）（N1040，2003 年 11 月 7 日草案）

- 2007: Technical corrigendum 3 (ISO/IEC 9899:1999/Cor.3:2007) (N1256 September 7, 2007 draft)
2007：技術勘誤表 3（ISO/IEC 9899:1999/Cor.3:2007）（N1256，2007 年 9 月 7 日草案）

- deprecated gets
棄用 gets
棄用 gets

- 2007: Bounds-checking interfaces TR (ISO/IEC TR 24731-1:2007) (ISO store) (N1225 March 28, 2007 draft)
2007：邊界檢查介面 TR（ISO/IEC TR 24731-1:2007）（ISO 商店）（N1225，2007 年 3 月 28 日草案）

- 2008: Embedded TR (ISO/IEC TR 18037:2008) (ISO store) (N1021 September 24, 2003 draft)
2008：嵌入式 TR（ISO/IEC TR 18037:2008）（ISO 商店）（N1021，2003 年 9 月 24 日草案）

- 2009: Decimal floating-point TR (ISO/IEC TR 24732:2009) (ISO store) (N1241 July 5, 2007 draft)
2009：十進位制浮點 TR（ISO/IEC TR 24732:2009）（ISO 商店）（N1241，2007 年 7 月 5 日草案）

- 2009: Mathematical special functions TR (ISO/IEC TR 24747:2009) (ISO store) (N1182 August 2, 2006 draft)
2009：數學特殊函式 TR（ISO/IEC TR 24747:2009）（ISO 商店）（N1182，2006 年 8 月 2 日草案）

- 2010: Dynamic allocations functions TR (ISO/IEC TR 24731-2:2010) (ISO store) (N1388 June 1, 2009 draft)
2010：動態分配函式 TR（ISO/IEC TR 24731-2:2010）（ISO 商店）（N1388，2009 年 6 月 1 日草案）

- 2011: **C11** (ISO/IEC 9899:2011) (ISO store) (ANSI store) (N1570 April 12, 2011 draft)
2011：C11（ISO/IEC 9899:2011）（ISO 商店）（ANSI 商店）（N1570，2011 年 4 月 12 日草案）

- thread-aware memory model, <stdatomic.h>, <threads.h>, type-generic functions, `alignas`/`alignof`, `noreturn`, `static_assert`, analyzability extensions, extensions to complex and imaginary types, anonymous structures and unions, exclusive file open mode, quick_exit
執行緒感知記憶體模型、<stdatomic.h>、<threads.h>、泛型別函式、alignas/alignof、noreturn、static_assert、可分析性擴充套件、複數與虛數型別的擴充套件、匿名結構體與聯合、排他檔案開啟模式、quick_exit

- removed gets

- from Bounds-checking interfaces TR: bounds-checking interfaces,
來自邊界檢查介面 TR：邊界檢查介面，

- from Unicode TR: `char16_t`, `char32_t`, and <uchar.h>
來自 Unicode TR：char16_t、char32_t 和 <uchar.h>

- 2012: Technical corrigendum 1 (ISO/IEC 9899:2011/Cor 1:2012) (ISO store)
2012：技術勘誤表 1（ISO/IEC 9899:2011/Cor 1:2012）（ISO 商店）

- Fixes DR 411

- 2013: Secure Coding Rules TS (ISO/IEC TS 17961:2013) (ISO store) (N1718 May 30, 2013)
2013：安全編碼規則 TS（ISO/IEC TS 17961:2013）（ISO 商店）（N1718，2013 年 5 月 30 日）

- 2014: FP TS part 1: Binary floating-point arithmetic (ISO/IEC TS 18661-1:2014) (ISO store) (N1778 2013 draft)
2014：FP TS 第 1 部分：二進位制浮點算術（ISO/IEC TS 18661-1:2014）（ISO 商店）（N1778，2013 草案）

- provides changes to C11 (mostly to Annex F) that cover all basic requirements and some recommendations of IEC 60559:2011 (C11 was built on IEC 60559:1989)
提供對 C11 的修改（主要針對附錄 F），涵蓋 IEC 60559:2011 的所有基本要求和部分建議（C11 基於 IEC 60559:1989）

- 2015: FP TS part 2: Decimal floating-point arithmetic (ISO/IEC TS 18661-2:2015) (ISO store) (N1912 2015 draft)
2015：FP TS 第 2 部分：十進位制浮點算術（ISO/IEC TS 18661-2:2015）（ISO 商店）（N1912，2015 草案）

- provides changes to C11 to support all the requirements, plus some basic recommendations, of IEC 60559:2011 for decimal floating-point arithmetic. This supersedes ISO/IEC TR 24732:2009.
提供對 C11 的修改以支援 IEC 60559:2011 十進位制浮點算術的所有要求以及部分基本建議。本檔案取代 ISO/IEC TR 24732:2009。

- 2015: FP TS part 3: Interchange and extended types (ISO/IEC TS 18661-3:2015) (ISO store) (N1945 2015 draft)
2015：FP TS 第 3 部分：交換格式與擴充套件型別（ISO/IEC TS 18661-3:2015）（ISO 商店）（N1945，2015 草案）

- provides changes to C11 to support the recommendations of IEC 60559:2011 for extended floating‐point formats and the interchange formats, both arithmetic and non-arithmetic.
提供對 C11 的修改以支援 IEC 60559:2011 關於擴充套件浮點格式以及交換格式（算術與非算術）的建議。

- 2015: FP TS part 4: Supplementary functions (ISO/IEC TS 18661-4:2015) (ISO store) (N1950 2015 draft)
2015：FP TS 第 4 部分：補充函式（ISO/IEC TS 18661-4:2015）（ISO 商店）（N1950，2015 草案）

- provides changes to C11 to support all mathematical operations recommended by IEC 60559:2011, including trigonometry in π units, inverse square root, compounded interest, etc.
提供對 C11 的修改以支援 IEC 60559:2011 推薦的所有數學運算，包括以 π 為單位的三角運算、平方根倒數、複利等。

- 2016: FP TS part 5: Supplementary attributes (ISO/IEC TS 18661-5:2016) (ISO store) (N2004 2016 draft)
2016：FP TS 第 5 部分：補充屬性（ISO/IEC TS 18661-5:2016）（ISO 商店）（N2004，2016 草案）

- provides changes to C11 to support all supplementary attributes (evaluation model, exception handling, reproducibility, etc) recommended by IEC 60559:2011
提供對 C11 的修改以支援 IEC 60559:2011 推薦的所有補充屬性（求值模型、異常處理、可復現性等）

- 2018: **C17** (ISO/IEC 9899:2018) (ISO Store) (Final draft)
2018：C17（ISO/IEC 9899:2018）（ISO 商店）（最終草案）

Main Article: C17
主條目：C17

| Defect Reports fixed in C17 (54 defects)  |

- DR 400

- DR 401

- DR 402

- DR 403

- DR 404

- DR 405

- DR 406

- DR 407

- DR 410

- DR 412

- DR 414

- DR 415

- DR 416

- DR 417

- DR 419

- DR 423

- DR 426

- DR 428

- DR 429

- DR 430

- DR 431

- DR 433

- DR 434

- DR 436

- DR 437

- DR 438

- DR 439

- DR 441

- DR 444

- DR 445

- DR 447

- DR 448

- DR 450

- DR 452

- DR 453

- DR 457

- DR 458

- DR 459

- DR 460

- DR 462

- DR 464

- DR 465

- DR 468

- DR 470

- DR 471

- DR 472

- DR 473

- DR 475

- DR 477

- DR 480

- DR 481

- DR 485

- DR 487

- DR 491

- 2023 **C23** (ISO/IEC 9899:2024). C23 is the current revision of the C standard.
2023：C23（ISO/IEC 9899:2024）。C23 是 C 標準的目前修訂版。

Main Article: C23
主條目：C23

| Defect Reports fixed in C23 (? defects)  |

- DR 440

- DR 432

- DR 467

- DR 476

- DR 482

- DR 488

- DR 489

- DR 494

- DR 496

- DR 497

- DR 499

- DR 500

- DR 501

### Future development
未來發展

- Parallelism TS (Draft N2017 2016-03-10)
並行 TS（草案 N2017，2016-03-10）

- Transactional Memory TS (Draft N1961 2015-09-23)
事務記憶體 TS（草案 N1961，2015-09-23）

- **C** (Latest draft n3886 2026-05-24)
C（最新草案 n3886，2026-05-24）

- List of issues that were not granted DR status: (N2556 2020-08-02)
未被授予 DR 狀態的問題列表：（N2556，2020-08-02）

Main Article: C29 ?
主條目：C29？
Next major C language standard revision
C 語言的下一個主要標準修訂

### See also

C++ documentation for History of C++

### External links

| 1.  |   | The Development of the C Language by Dennis M. Ritchie  |

| 2.  |   | Rationale for the C99 standard  |

---
來源頁路徑：`en.cppreference.com/c/language/history.html`

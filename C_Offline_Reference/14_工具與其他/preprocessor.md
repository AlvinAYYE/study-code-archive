# Preprocessor

> 來源：cppreference C 語言參考文件（離線轉換版）。

The preprocessor is executed at translation phase 4, before the compilation. The result of preprocessing is a single file which is then passed to the actual compiler.
前處理器在翻譯階段 4 執行，位於編譯之前。預處理的結果是一個單獨的檔案，隨後被傳遞給真正的編譯器。

### Directives

The preprocessing directives control the behavior of the preprocessor. Each directive occupies one line and has the following format:
預處理指令控制前處理器的行為。每條指令佔據一行，並具有以下格式：

- `#` character

- preprocessing instruction (one of `define`, `undef`, `include`, `if`, `ifdef`, `ifndef`, `else`, `elif`, `elifdef`, `elifndef`(since C23), `endif`, `line`, `embed`(since C23), `error`, `warning`(since C23), `pragma`)
預處理指令（ define 、 undef 、 include 、 if 、 ifdef 、 ifndef 、 else 、 elif 、 elifdef 、 elifndef （自 C23 起）、 endif 、 line 、 embed （自 C23 起）、 error 、 warning （自 C23 起）、 pragma 之一） [ 1 ]

- arguments (depends on the instruction)
參數（取決於該指令）

- line break.

The null directive (`#` followed by a line break) is allowed and has no effect.
空指令（ # 後跟換行）是允許的，並且沒有任何作用。

### Capabilities

The preprocessor has the source file translation capabilities:
前處理器具有原始檔翻譯能力：

- **conditionally** compile of parts of source file (controlled by directive `#if`, `#ifdef`, `#ifndef`, `#else`, `#elif`, `#elifdef`, `#elifndef`(since C23) and `#endif`).
條件編譯原始檔的部分（由指令 #if 、 #ifdef 、 #ifndef 、 #else 、 #elif 、 #elifdef 、 #elifndef （自 C23 起）和 #endif 控制）。

- **replace** text macros while possibly concatenating or quoting identifiers (controlled by directives `#define` and `#undef`, and operators `#` and `##`)
替換文字宏，同時可能拼接或引用識別符號（由指令 #define 和 #undef 以及運運算元 # 和 ## 控制）

- **include** other files (controlled by directive `#include` and checked with `__has_include`(since C23))
包含其他檔案（由指令 #include 控制，並以 __has_include 檢查（自 C23 起））

- cause an **error** or **warning**(since C23) (controlled by directive `#error` or `#warning` respectively(since C23))
引起錯誤或警告（自 C23 起）（分別由指令 #error 或 #warning 控制（自 C23 起））

The following aspects of the preprocessor can be controlled:
前處理器的以下方面可以被控制：

- **implementation defined** behavior (controlled by directive `#pragma` and operator `_Pragma`(since C99))
實現定義的行為（由指令 #pragma 和運運算元 _Pragma 控制（自 C99 起））

- **file name and line information** available to the preprocessor (controlled by directives `#line`)
前處理器可用的檔名和行資訊（由指令 #line 控制）

### Footnotes

- ↑ These are the directives defined by the standard. The standard does not define behavior for other directives: they might be ignored, have some useful meaning, or make the program ill-formed. Even if otherwise ignored, they are removed from the source code when the preprocessor is done. A common non-standard extension is the directive #warning which emits a user-defined message during compilation.(until C23)
↑ 這些是標準所定義的指令。標準沒有為其他指令定義行為：它們可能被忽略、具有某些有用含義，或使程式為非良構。即使在其他情況下被忽略，它們也會在前處理器完成時從原始碼中移除。一種常見的非標準擴充套件是指令 #warning ，它在編譯期間發出使用者定義的訊息。（C23 之前）

### Example

|  | This section is incomplete
Reason: no example  |

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 6.10 Preprocessing directives (p: TBD)
6.10 預處理指令 (p: TBD)
6.10 預處理指令 (p: TBD)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.10 Preprocessing directives (p: 117-129)
6.10 預處理指令 (p: 117-129)
6.10 預處理指令 (p: 117-129)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.10 Preprocessing directives (p: 160-178)
6.10 預處理指令 (p: 160-178)
6.10 預處理指令 (p: 160-178)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.10 Preprocessing directives (p: 145-162)
6.10 預處理指令 (p: 145-162)
6.10 預處理指令 (p: 145-162)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.8 Preprocessing directives
3.8 預處理指令
3.8 預處理指令

### See also

C documentation for Predefined Macro Symbols

C documentation for Macro Symbol Index

C++ documentation for Preprocessor

---
來源頁路徑：`en.cppreference.com/c/preprocessor.html`

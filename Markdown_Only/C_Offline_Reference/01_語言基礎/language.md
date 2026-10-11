# C language

> 來源：cppreference C 語言參考文件（離線轉換版）。

This is a reference of the core C language constructs.
本頁是 C 語言核心語法與功能的索引，可從下列主題進入各項說明。

** Basic concepts（基本概念）**

Comments（註解）
ASCII chart（ASCII 字元表）
Character sets and encodings（字元集與編碼）
Translation phases（翻譯階段）
Punctuation（標點符號）
Identifier - Scope - Lifetime（識別字、作用域與生命期）
Lookup and Name Spaces（名稱查找與名稱空間）
Type - Arithmetic types（型別與算術型別）
Objects and Alignment（物件與對齊）
The `main` function（`main` 函式）
As-if rule（彷彿規則）
Undefined behavior（未定義行為）
Memory model and Data races（記憶體模型與資料競爭）

** Keywords（關鍵字）**

** Preprocessor（前處理器）**

`#if` - `#ifdef` - `#ifndef` - `#elif`
`#elifdef` - `#elifndef` (C23)
`#define` - `#` - `##`
#include - #pragma
#line - #error
#warning (C23) - #embed (C23)

** Statements（陳述式）**

`if` - `switch`
`for`
`while` - `do`-`while`
`continue` - `break`
`goto` - `return`

|   |
** Expressions（運算式）**

Value categories（值類別）
Evaluation order and sequencing（求值順序與定序）
Constants and literals（常數與字面值）
  Integer constants（整數常數）
  Floating constants（浮點常數）
  Character constants（字元常數）
  `true`/`false` (C23，布林常數)
  `nullptr` (C23，空指標常數)
  String literals（字串字面值）
  Compound literals (C99，複合字面值)
Constant expressions（常數運算式）
Implicit conversions（隱式轉換）
Operators（運算子）
  Member access and indirection（成員存取與間接存取）
  Logical - Comparison（邏輯運算與比較）
  Arithmetic - Assignment（算術運算與指定）
  Increment and Decrement（遞增與遞減）
  Call, Comma, Ternary（函式呼叫、逗號與條件運算子）
  `sizeof` - `alignof` (C11，大小與對齊需求)
  Cast operators（轉型運算子）
Operator precedence（運算子優先順序）
Generic selection (C11，泛型選擇)

** Initialization（初始化）**

Scalar（純量）
Array（陣列）
Structure/Union（結構與聯合）

|   |
** Declarations（宣告）**

Pointers - Arrays（指標與陣列）
Enumerations（列舉）
Storage duration and Linkage（儲存期與連結）
`const` - `volatile` - `restrict` (C99，型別限定詞)
`struct` - `union` - Bit-fields（結構、聯合與位元欄位）
`alignas` (C11，指定對齊) - `typedef`（型別別名）
`static_assert` (C11，編譯期斷言)
Atomic types (C11，原子型別)
External and tentative definitions（外部定義與暫定定義）
Attributes (C23，屬性)

** Functions（函式）**

Function declaration（函式宣告）
Function definition（函式定義）
`inline` (C99，內嵌函式)
`_Noreturn` (C11，不會正常返回；C23 起已淘汰)
Variadic arguments（可變數量的引數）

**Miscellaneous（其他主題）**

History of C（C 語言沿革）
Conformance（標準符合性）
Inline assembly（內嵌組合語言）
Signal handling（訊號處理）
Analyzability (C11，可分析性)

### See also

C++ documentation for C++ language constructs

---
來源頁路徑：`en.cppreference.com/c/language.html`

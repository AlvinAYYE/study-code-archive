# Identifier

> 來源：cppreference C 語言參考文件（離線轉換版）。

An *identifier* is an arbitrarily long sequence of digits, underscores, lowercase and uppercase Latin letters, and Unicode characters specified using `\u` and `\U` escape notation(since C99), of class XID_Continue(since C23). A valid identifier must begin with a non-digit character (Latin letter, underscore, or Unicode non-digit character(since C99)(until C23), or Unicode character of class XID_Start)(since C23)). Identifiers are case-sensitive (lowercase and uppercase letters are distinct). Every identifier must conform to Normalization Form C.(since C23)
識別符號是任意長的數字、下劃線、小寫和大寫拉丁字母以及使用 \u 和 \U 轉義表示法（C99 起）指定的 Unicode 字元的序列，屬於 XID_Continue 類（C23 起）。有效識別符號必須以非數字字元（拉丁字母、下劃線或 Unicode 非數字字元（C99 起）（C23 之前）或 XID_Start 類的 Unicode 字元）（C23 起））開頭。識別符號是區分大小寫的（小寫和大寫字母是不同的）。每個識別符號必須符合 Normalization Form C（C23 起）。

It is implementation-defined if raw (not escaped) Unicode characters are allowed in identifiers:
```c
char *\U0001f431 = "cat"; // supported char *🐱 = "cat"; // implementation-defined  // (e.g. works with Clang, but not GCC prior to version 10)  // both are ill formed in C23. Emoji are not XID_Start characters
```
|   | (since C99)
(until C23) |

Implementation-defined characters whose corresponding code points in ISO/IEC 10646 (Unicode) have the XID_Start or XID_Continue property can appear in the beginning or after the first character of an identifier respectively. |   | (since C23) |

Identifiers can denote the following types of entities:
識別符號可以表示以下型別的實體：

- objects

- functions

- tags (struct, union, or enumerations)
標籤（struct、union 或列舉）

- structure or union members
結構體或聯合體成員

- enumeration constants
列舉常量

- typedef names

- label names

- macro names

- macro parameter names
宏參數名

Every identifier other than macro names or macro parameter names has scope, belongs to a name space, and may have linkage. The same identifier can denote different entities at different points in the program, or may denote different entities at the same point if the entities are in different name spaces.
除宏名或宏參數名之外的每個識別符號都有作用域，屬於一個名稱空間，並且可以有連結。同一識別符號可以在程式的不同位置表示不同的實體，如果實體處於不同的名稱空間，也可以在同一位置表示不同的實體。

### Reserved identifiers
保留識別符號

The following identifiers are *reserved* and may not be declared in a program (doing so invokes undefined behavior):
以下識別符號是保留的，不得在程式中宣告（這樣做會引發未定義行為）：

- The identifiers that are keywords cannot be used for other purposes. In particular #define or #undef of an identifier that is identical to a keyword is not allowed.
作為關鍵字的識別符號不能用於其他目的。特別是不允許對與關鍵字相同的識別符號使用 #define 或 #undef。

- All external identifiers that begin with an underscore.
所有以下劃線開頭的外部識別符號。

- All identifiers that begin with an underscore followed by a capital letter or by another underscore (these reserved identifiers allow the library to use numerous behind-the-scenes non-external macros and functions).
所有以下劃線後跟大寫字母或另一個下劃線開頭的識別符號（這些保留識別符號允許庫使用眾多幕後非外部宏和函式）。

- All external identifiers defined by the standard library (in hosted environment). This means that no user-supplied external names are allowed to match any library names, not even if declaring a function that is identical to a library function.
標準函式庫（在宿主環境中）定義的所有外部識別符號。這意味著不允許使用者提供的任何外部名稱與任何庫名稱匹配，即使宣告的函式與庫函式完全相同。

- Identifiers declared as reserved for the implementation or future use by the standard library (see below).
被宣告為實現保留或標準函式庫未來使用的識別符號（見下文）。

- Identifiers declared as potentially reserved and provided by the implementation (see below). (since C23)
被宣告為潛在保留並由實現提供的識別符號（見下文）。（C23 起）

All other identifiers are available. Identifiers that are not reserved or potentially reserved(since C23) can be used with no fear of unexpected collisions when moving programs from one compiler and library to another.
所有其他識別符號都是可用的。非保留或潛在保留（C23 起）的識別符號在將程式從一個編譯器和庫遷移到另一個編譯器和庫時，可以不必擔心意外的衝突。
Note: in C++, identifiers with a double underscore anywhere are reserved everywhere; in C, only the ones that begin with a double underscore are reserved.
注意：在 C++ 中，任何位置帶有雙下劃線的識別符號在任何地方都是保留的；在 C 中，只有以雙下劃線開頭的識別符號是保留的。

#### Reserved and potentially reserved identifiers in the library

The standard library reserves every identifier it provides. Reserved identifiers that have external linkage (e.g. name of every standard function) are reserved regardless which header is included. Other reserved identifiers are reserved when any of its associated headers is included.
標準函式庫保留它提供的每個識別符號。具有外部連結的保留識別符號（例如每個標準函式的名稱）無論包含哪個標頭檔都是保留的。其他保留識別符號在其任何關聯標頭檔被包含時是保留的。

Potentially reserved identifiers are intended to be used by the implementation and future revision of standard. If a potentially reserved identifier is provided by the implementation, it becomes reserved.
Implementations are only allowed to provide external definitions of potentially reserved identifiers that are reserved as function names.
Potentially reserved identifiers that are not provided by the implementation are not reserved. They can be declared or defined by the user without undefined behavior. However, such usage is not portable.
|   | (since C23) |

Following identifiers are reserved or potentially reserved(since C23) for the implementation or future use by the standard library.
以下識別符號為實現或標準函式庫未來使用而保留或潛在保留（C23 起）。

- *function names*, all of which are potentially reserved(since C23)

- `cerf`, `cerfc`, `cexp2`, `cexpm1`, `clog10`, `clog1p`, `clog2`, `clgamma`, `ctgamma`, `csinpi`, `ccospi`, `ctanpi`, `casinpi`, `cacospi`, `catanpi`, `ccompoundn`, `cpown`, `cpowr`, `crootn`, `crsqrt`, `cexp10m1`, `cexp10`, `cexp2m1`, `clog10p1`, `clog2p1`, `clogp1`(since C23) and their -f and -l suffixed variants, in <complex.h> (since C99)
cerf、cerfc、cexp2、cexpm1、clog10、clog1p、clog2、clgamma、ctgamma、csinpi、ccospi、ctanpi、casinpi、cacospi、catanpi、ccompoundn、cpown、cpowr、crootn、crsqrt、cexp10m1、cexp10、cexp2m1、clog10p1、clog2p1、clogp1（C23 起）及其 -f 和 -l 字尾變體，在 <complex.h> 中（C99 起）

- beginning with `is` or `to` followed by a lowercase letter, in <ctype.h> and <wctype.h>(since C95)
以 is 或 to 後跟一個小寫字母開頭，在 <ctype.h> 和 <wctype.h> 中（C95 起）

- beginning with `str` or `wcs`(since C23) followed by a lowercase letter, in <stdlib.h> and <inttypes.h>(since C23)
以 str 或 wcs（C23 起）後跟一個小寫字母開頭，在 <stdlib.h> 和 <inttypes.h> 中（C23 起）

- beginning with `cr_`, in <math.h> (since C23)
以 cr_ 開頭，在 <math.h> 中（C23 起）

- beginning with `wcs` followed by a lowercase letter, in <wchar.h> (since C95)
以 wcs 後跟一個小寫字母開頭，在 <wchar.h> 中（C95 起）

- beginning with `atomic_` followed by a lowercase letter, in <stdatomic.h> (since C11)
以 atomic_ 後跟一個小寫字母開頭，在 <stdatomic.h> 中（C11 起）

- beginning with `cnd_`, `mtx_`, `thrd_` or `tss_` followed by a lowercase letter, in <threads.h> (since C11)
以 cnd_、mtx_、thrd_ 或 tss_ 後跟一個小寫字母開頭，在 <threads.h> 中（C11 起）

函式名，全部為潛在保留（C23 起）cerf、cerfc、cexp2、cexpm1、clog10、clog1p、clog2、clgamma、ctgamma、csinpi、ccospi、ctanpi、casinpi、cacospi、catanpi、ccompoundn、cpown、cpowr、crootn、crsqrt、cexp10m1、cexp10、cexp2m1、clog10p1、clog2p1、clogp1（C23 起）及其 -f 和 -l 字尾變體，在 <complex.h> 中（C99 起）以 is 或 to 後跟一個小寫字母開頭，在 <ctype.h> 和 <wctype.h> 中（C95 起）以 str 或 wcs（C23 起）後跟一個小寫字母開頭，在 <stdlib.h> 和 <inttypes.h> 中（C23 起）以 cr_ 開頭，在 <math.h> 中（C23 起）以 wcs 後跟一個小寫字母開頭，在 <wchar.h> 中（C95 起）以 atomic_ 後跟一個小寫字母開頭，在 <stdatomic.h> 中（C11 起）以 cnd_、mtx_、thrd_ 或 tss_ 後跟一個小寫字母開頭，在 <threads.h> 中（C11 起）

- *typedef names*, all of which are potentially reserved(since C23)

- beginning with `int` or `uint` and ending with `_t`, in <stdint.h> (since C99)
以 int 或 uint 開頭並以 _t 結尾，在 <stdint.h> 中（C99 起）

- beginning with `atomic_` or `memory_` followed by a lowercase letter, in <stdatomic.h> (since C11)
以 atomic_ 或 memory_ 後跟一個小寫字母開頭，在 <stdatomic.h> 中（C11 起）

- beginning with `cnd_`, `mtx_`, `thrd_` or `tss_` followed by a lowercase letter, in <threads.h> (since C11)
以 cnd_、mtx_、thrd_ 或 tss_ 後跟一個小寫字母開頭，在 <threads.h> 中（C11 起）

typedef 名稱，全部為潛在保留（C23 起）以 int 或 uint 開頭並以 _t 結尾，在 <stdint.h> 中（C99 起）以 atomic_ 或 memory_ 後跟一個小寫字母開頭，在 <stdatomic.h> 中（C11 起）以 cnd_、mtx_、thrd_ 或 tss_ 後跟一個小寫字母開頭，在 <threads.h> 中（C11 起）

- *macro names*

- beginning with `E` followed by a digit or an uppercase letter, in <errno.h>
以 E 後跟一個數字或大寫字母開頭，在 <errno.h> 中

- beginning with `FE_` followed by an uppercase letter, in <fenv.h> (since C99)
以 FE_ 後跟一個大寫字母開頭，在 <fenv.h> 中（C99 起）

- beginning with `DBL_`, `DEC32_`, `DEC64_`, `DEC128_`, `DEC_`, `FLT_`, or `LDBL_` followed by an uppercase letter, in <float.h>; these identifiers are potentially reserved (since C23)
以 DBL_、DEC32_、DEC64_、DEC128_、DEC_、FLT_ 或 LDBL_ 後跟一個大寫字母開頭，在 <float.h> 中；這些識別符號是潛在保留的（C23 起）

- beginning with `INT` or `UINT` and ending with `_MAX`, `_MIN`, `_WIDTH`(since C23), or `_C`, in <stdint.h>; these identifiers are potentially reserved(since C23) (since C99)
以 INT 或 UINT 開頭並以 _MAX、_MIN、_WIDTH（C23 起）或 _C 結尾，在 <stdint.h> 中；這些識別符號是潛在保留的（C23 起）（C99 起）

- beginning with `PRI` or `SCN` followed by lowercase letter or the letter `X`, in <inttypes.h>; these identifiers are potentially reserved(since C23) (since C99)
以 PRI 或 SCN 後跟一個小寫字母或字母 X 開頭，在 <inttypes.h> 中；這些識別符號是潛在保留的（C23 起）（C99 起）

- beginning with `LC_` followed by an uppercase letter, in <locale.h>
以 LC_ 後跟一個大寫字母開頭，在 <locale.h> 中

- beginning with `FP_` followed by an uppercase letter, in <math.h> (since C23)
以 FP_ 後跟一個大寫字母開頭，在 <math.h> 中（C23 起）

- beginning with `MATH_` followed by an uppercase letter, in <math.h>; these identifiers are potentially reserved (since C23)
以 MATH_ 後跟一個大寫字母開頭，在 <math.h> 中；這些識別符號是潛在保留的（C23 起）

- beginning with `SIG` or `SIG_` followed by an uppercase letter, in <signal.h>
以 SIG 或 SIG_ 後跟一個大寫字母開頭，在 <signal.h> 中

- beginning with `TIME_` followed by an uppercase letter, in <time.h> (since C11)
以 TIME_ 後跟一個大寫字母開頭，在 <time.h> 中（C11 起）

- beginning with `ATOMIC_` followed by an uppercase letter, in <stdatomic.h>; these identifiers are potentially reserved(since C23) (since C11)
以 ATOMIC_ 後跟一個大寫字母開頭，在 <stdatomic.h> 中；這些識別符號是潛在保留的（C23 起）（C11 起）

宏名以 E 後跟一個數字或大寫字母開頭，在 <errno.h> 中以 FE_ 後跟一個大寫字母開頭，在 <fenv.h> 中（C99 起）以 DBL_、DEC32_、DEC64_、DEC128_、DEC_、FLT_ 或 LDBL_ 後跟一個大寫字母開頭，在 <float.h> 中；這些識別符號是潛在保留的（C23 起）以 INT 或 UINT 開頭並以 _MAX、_MIN、_WIDTH（C23 起）或 _C 結尾，在 <stdint.h> 中；這些識別符號是潛在保留的（C23 起）（C99 起）以 PRI 或 SCN 後跟一個小寫字母或字母 X 開頭，在 <inttypes.h> 中；這些識別符號是潛在保留的（C23 起）（C99 起）以 LC_ 後跟一個大寫字母開頭，在 <locale.h> 中以 FP_ 後跟一個大寫字母開頭，在 <math.h> 中（C23 起）以 MATH_ 後跟一個大寫字母開頭，在 <math.h> 中；這些識別符號是潛在保留的（C23 起）以 SIG 或 SIG_ 後跟一個大寫字母開頭，在 <signal.h> 中以 TIME_ 後跟一個大寫字母開頭，在 <time.h> 中（C11 起）以 ATOMIC_ 後跟一個大寫字母開頭，在 <stdatomic.h> 中；這些識別符號是潛在保留的（C23 起）（C11 起）

- *enumeration constants*, all of which are potentially reserved(since C23)

- beginning with `memory_order_` followed by a lowercase letter, in <stdatomic.h> (since C11)
以 memory_order_ 後跟一個小寫字母開頭，在 <stdatomic.h> 中（C11 起）

- beginning with `cnd_`, `mtx_`, `thrd_` or `tss_` followed by a lowercase letter, in <threads.h> (since C11)
以 cnd_、mtx_、thrd_ 或 tss_ 後跟一個小寫字母開頭，在 <threads.h> 中（C11 起）

列舉常量，全部為潛在保留（C23 起）以 memory_order_ 後跟一個小寫字母開頭，在 <stdatomic.h> 中（C11 起）以 cnd_、mtx_、thrd_ 或 tss_ 後跟一個小寫字母開頭，在 <threads.h> 中（C11 起）

Implementations are recommended to warn when on declaration or definition of potentially reserved identifiers, except when

- the declaration is a non-definition declaration of an identifier with external linkage provided by the implementation, and

- the type used in the declaration is compatible with that used in the definition.
|   | (since C23) |

### Translation limits
翻譯限制

Even though there is no specific limit on the length of identifiers, early compilers had limits on the number of significant initial characters in identifiers and the linkers imposed stricter limits on the names with external linkage. C requires that at least the following limits are supported by any standard-compliant implementation:
儘管對識別符號的長度沒有具體限制，但早期編譯器對識別符號中有效首字元的數量有限制，連結器對具有外部連結的名稱施加了更嚴格的限制。C 要求任何符合標準的實現至少支援以下限制：

- 31 significant initial characters in an internal identifier or a macro name

- 6 significant initial characters in an external identifier

- 511 external identifiers in one translation unit

- 127 identifiers with block scope declared in one block

- 1024 macro identifiers simultaneously defined in one preprocessing translation unit
|   | (until C99) |

- 63 significant initial characters in an internal identifier or a macro name

- 31 significant initial characters in an external identifier

- 4095 external identifiers in one translation unit

- 511 identifiers with block scope declared in one block

- 4095 macro identifiers simultaneously defined in one preprocessing translation unit
|   | (since C99) |

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 5.2.5.2 Translation limits (p: TBD)
5.2.5.2 翻譯限制 (p: TBD)
5.2.5.2 翻譯限制 (p: TBD)

- 6.4.2 Identifiers (p: TBD)
6.4.2 識別符號 (p: TBD)
6.4.2 識別符號 (p: TBD)

- 6.10.10 Predefined macro names (p: TBD)
6.10.10 預定義宏名 (p: TBD)
6.10.10 預定義宏名 (p: TBD)

- 6.11.7 Predefined macro names (p: TBD)
6.11.7 預定義宏名 (p: TBD)
6.11.7 預定義宏名 (p: TBD)

- 7.33 Future library directions (p: TBD)
7.33 庫未來發展方向 (p: TBD)
7.33 庫未來發展方向 (p: TBD)

- K.3.1.2 Reserved identifiers (p: TBD)
K.3.1.2 保留識別符號 (p: TBD)
K.3.1.2 保留識別符號 (p: TBD)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 5.2.4.1 Translation limits (p: 19-20)
5.2.4.1 翻譯限制 (p: 19-20)
5.2.4.1 翻譯限制 (p: 19-20)

- 6.4.2 Identifiers (p: 43)
6.4.2 識別符號 (p: 43)
6.4.2 識別符號 (p: 43)

- 6.10.8 Predefined macro names (p: 127-129)
6.10.8 預定義宏名 (p: 127-129)
6.10.8 預定義宏名 (p: 127-129)

- 6.11.9 Predefined macro names (p: 130)
6.11.9 預定義宏名 (p: 130)
6.11.9 預定義宏名 (p: 130)

- 7.31 Future library directions (p: 332-333)
7.31 庫未來發展方向 (p: 332-333)
7.31 庫未來發展方向 (p: 332-333)

- K.3.1.2 Reserved identifiers (p: 425)
K.3.1.2 保留識別符號 (p: 425)
K.3.1.2 保留識別符號 (p: 425)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 5.2.4.1 Translation limits (p: 25-26)
5.2.4.1 翻譯限制 (p: 25-26)
5.2.4.1 翻譯限制 (p: 25-26)

- 6.4.2 Identifiers (p: 59-60)
6.4.2 識別符號 (p: 59-60)
6.4.2 識別符號 (p: 59-60)

- 6.10.8 Predefined macro names (p: 175-176)
6.10.8 預定義宏名 (p: 175-176)
6.10.8 預定義宏名 (p: 175-176)

- 6.11.9 Predefined macro names (p: 179)
6.11.9 預定義宏名 (p: 179)
6.11.9 預定義宏名 (p: 179)

- 7.31 Future library directions (p: 455-457)
7.31 庫未來發展方向 (p: 455-457)
7.31 庫未來發展方向 (p: 455-457)

- K.3.1.2 Reserved identifiers (p: 584)
K.3.1.2 保留識別符號 (p: 584)
K.3.1.2 保留識別符號 (p: 584)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 5.2.4.1 Translation limits (p: 20-21)
5.2.4.1 翻譯限制 (p: 20-21)
5.2.4.1 翻譯限制 (p: 20-21)

- 6.4.2 Identifiers (p: 51-52)
6.4.2 識別符號 (p: 51-52)
6.4.2 識別符號 (p: 51-52)

- 6.10.8 Predefined macro names (p: 160-161)
6.10.8 預定義宏名 (p: 160-161)
6.10.8 預定義宏名 (p: 160-161)

- 6.11.9 Predefined macro names (p: 163)
6.11.9 預定義宏名 (p: 163)
6.11.9 預定義宏名 (p: 163)

- 7.26 Future library directions (p: 401-402)
7.26 未來庫發展方向 (p: 401-402)
7.26 未來庫發展方向 (p: 401-402)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 2.2.4.1 Translation limits
2.2.4.1 翻譯限制
2.2.4.1 翻譯限制

- 3.1.2 Identifiers
3.1.2 識別符號
3.1.2 識別符號

- 3.8.8 Predefined macro names
3.8.8 預定義宏名
3.8.8 預定義宏名

### See also

C++ documentation for Identifiers

---
來源頁路徑：`en.cppreference.com/c/language/identifier.html`

# Implementation defined behavior control

> 來源：cppreference C 語言參考文件（離線轉換版）。

Implementation defined behavior is controlled by `#pragma` directive.
實作定義的行為由 #pragma 指令控制。

### Syntax

|   |

| `**#pragma**` pragma_params  |   | (1)  |   |   |

|   |

| `**_Pragma**` `**(**` string-literal `**)**`  |   | (2)  |   | (since C99)  |

|   |

1) Behaves in an implementation-defined manner (unless pragma_params is one of the standard pragmas shown below).

2) Removes the encoding prefix (if any), the outer quotes, and leading/trailing whitespace from string-literal, replaces each `\"` with `"` and each `\\` with `\`, then tokenizes the result (as in translation stage 3), and then uses the result as if the input to `#pragma` in (1).

### Explanation

The pragma directive controls implementation-specific behavior of the compiler, such as disabling compiler warnings or changing alignment requirements. Any pragma that is not recognized is ignored.
pragma 指令用來控制編譯器特有的行為，例如停用警告或變更對齊要求。編譯器會忽略不認得的 pragma。

### Standard pragmas
標準 pragma

The following three pragmas are defined by the language standard:
語言標準定義了以下三種 pragma：

|   |

| `**#pragma STDC FENV_ACCESS **`arg  |   | (1)  |   | (since C99)  |

|   |

| `**#pragma STDC FP_CONTRACT **`arg  |   | (2)  |   | (since C99)  |

|   |

| `**#pragma STDC CX_LIMITED_RANGE **`arg  |   | (3)  |   | (since C99)  |

|   |

where arg is either `**ON**` or `**OFF**` or `**DEFAULT**`.
其中 arg 為 ON 、 OFF 或 DEFAULT 。

1) If set to `**ON**`, informs the compiler that the program will access or modify floating-point environment, which means that optimizations that could subvert flag tests and mode changes (e.g., global common subexpression elimination, code motion, and constant folding) are prohibited. The default value is implementation-defined, usually `**OFF**`.

2) Allows *contracting* of floating-point expressions, that is optimizations that omit rounding errors and floating-point exceptions that would be observed if the expression was evaluated exactly as written. For example, allows the implementation of `(x * y) + z` with a single fused multiply-add CPU instruction. The default value is implementation-defined, usually `**ON**`.

3) Informs the compiler that multiplication, division, and absolute value of complex numbers may use simplified mathematical formulas (x+iy)×(u+iv) = (xu-yv)+i(yu+xv), (x+iy)/(u+iv) = [(xu+yv)+i(yu-xv)]/(u2
+v2
), and |x+iy| = √x2
+y2
, despite the possibility of intermediate overflow. In other words, the programmer guarantees that the range of the values that will be passed to those function is limited. The default value is `**OFF**`
Note: compilers that do not support these pragmas may provide equivalent compile-time options, such as gcc's `-fcx-limited-range` and `-ffp-contract`.
注意：不支援這些 pragma 的編譯器，可能會提供效果相同的編譯器選項，例如 gcc 的 -fcx-limited-range 和 -ffp-contract。

### Non-standard pragmas
非標準 pragma

#### `#pragma once`

`#pragma once` is a non-standard pragma that is supported by the vast majority of modern compilers. If it appears in a header file, it indicates that it is only to be parsed once, even if it is (directly or indirectly) included multiple times in the same source file.
#pragma once 是非標準 pragma，但絕大多數現代編譯器都支援。在標頭檔中使用它，表示該檔只應解析一次；即使同一原始碼檔案直接或間接納入它多次也一樣。
Standard approach to preventing multiple inclusion of the same header is by using include guards:
避免同一標頭檔被重複納入的標準作法，是使用標頭檔保護巨集：

```c
#ifndef LIBRARY_FILENAME_H #define LIBRARY_FILENAME_H // contents of the header #endif /* LIBRARY_FILENAME_H */
```

So that all but the first inclusion of the header in any translation unit are excluded from compilation. All modern compilers record the fact that a header file uses an include guard and do not re-parse the file if it is encountered again, as long as the guard is still defined (see e.g. gcc).
如此一來，每個翻譯單元只會編譯第一次納入的標頭檔。現代編譯器都會記住標頭檔使用了保護巨集；只要該巨集仍有定義，再次遇到同一檔案時就不會重新解析（例如參見 gcc）。
With `#pragma once`, the same header appears as
使用 #pragma once 時，同一標頭檔表現為

```c
#pragma once // contents of the header
```

Unlike header guards, this pragma makes it impossible to erroneously use the same macro name in more than one file. On the other hand, since with `#pragma once` files are excluded based on their filesystem-level identity, this can't protect against including a header twice if it exists in more than one location in a project.
相較於標頭檔保護巨集，這個 pragma 不會發生多個檔案誤用相同巨集名稱的問題。不過，#pragma once 是根據檔案系統判定檔案是否相同；若同一標頭檔在專案中有多個路徑，就無法避免它被納入兩次。

#### `#pragma pack`

This family of pragmas control the maximum alignment for subsequently defined structure and union members.
這組 pragma 會控制後續定義的結構與聯合體成員所允許的最大對齊值。

|   |

| `**#pragma pack(arg) **`  |   | (1)  |   |   |

|   |

| `**#pragma pack() **`  |   | (2)  |   |   |

|   |

| `**#pragma pack(push) **`  |   | (3)  |   |   |

|   |

| `**#pragma pack(push, arg) **`  |   | (4)  |   |   |

|   |

| `**#pragma pack(pop) **`  |   | (5)  |   |   |

|   |

where arg is a small power of two and specifies the new alignment in bytes.
其中 arg 是 2 的小次冪，以位元組為單位指定新的對齊。

1) Sets the current alignment to value arg.

2) Sets the current alignment to the default value (specified by a command-line option).

3) Pushes the value of the current alignment on an internal stack.

4) Pushes the value of the current alignment on the internal stack and then sets the current alignment to value arg.

5) Pops the top entry from the internal stack and then sets (restores) the current alignment to that value.

`#pragma pack` may decrease the alignment of a structure, however, it cannot make a structure overaligned.
#pragma pack 可以降低結構的對齊值，但不能讓結構過度對齊。
See also specific details for GCC and MSVC.
各編譯器的細節請參閱 GCC 與 MSVC 檔案。

|  | This section is incomplete
Reason: Explain the effects of this pragmas on data members and also the pros and cons of using them. Sources for reference:
- Stack Overflow

|  | This section is incomplete
Reason: no example  |

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.10.6 Pragma directive (p: 127)
6.10.6 Pragma 指令 (p: 127)
6.10.6 Pragma 指令 (p: 127)

- 6.10.9 Pragma operator (p: 129)
6.10.9 Pragma 運運算元 (p: 129)
6.10.9 Pragma 運運算元 (p: 129)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.10.6 Pragma directive (p: 174)
6.10.6 Pragma 指令 (p: 174)
6.10.6 Pragma 指令 (p: 174)

- 6.10.9 Pragma operator (p: 178)
6.10.9 Pragma 運運算元 (p: 178)
6.10.9 Pragma 運運算元 (p: 178)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.10.6 Pragma directive (p: 159)
6.10.6 Pragma 指令 (p: 159)
6.10.6 Pragma 指令 (p: 159)

- 6.10.9 Pragma operator (p: 161-162)
6.10.9 Pragma 運運算元 (p: 161-162)
6.10.9 Pragma 運運算元 (p: 161-162)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.8.6 Pragma directive
3.8.6 Pragma 指令
3.8.6 Pragma 指令

### See also

C++ documentation for Implementation defined behavior control

### External links

| 1.  |   | C++ pragmas in Visual Studio 2019  |

| 2.  |   | Pragmas accepted by GCC  |

| 3.  |   | Individual pragma descriptions and Standard pragmas in IBM AIX XL C 16.1  |

| 4.  |   | Appendix B. Pragmas in Sun Studio 11 C++ User's Guide  |

| 5.  |   | Intel C++ compiler pragmas  |

| 6.  |   | HP aCC compiler pragmas  |

---
來源頁路徑：`en.cppreference.com/c/preprocessor/impl.html`

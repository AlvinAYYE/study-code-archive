# C keywords

> 來源：cppreference C 語言參考文件（離線轉換版）。

This is a list of reserved keywords in C. Since they are used by the language, these keywords are not available for re-definition. As an exception, they are not considered reserved in attribute-tokens(since C23)
以下列出 C 語言的保留關鍵字。這些字由語言本身使用，不能重新定義。例外是 attribute-token：其中的關鍵字不視為保留字（C23 起）。

`alignas` (C23)
`alignof` (C23)
`auto`
`bool` (C23)
`break`
`case`
`char`
`const`
`constexpr` (C23)
`continue`
`default`
`do`
`double`
`else`
`enum`

|   |
`extern`
`false` (C23)
`float`
`for`
`goto`
`if`
`inline` (C99)
`int`
`long`
`nullptr` (C23)
`register`
`restrict` (C99)
`return`
`short`
`signed`

|   |
`sizeof`
`static`
`static_assert` (C23)
`struct`
`switch`
`thread_local` (C23)
`true` (C23)
`typedef`
`typeof` (C23)
`typeof_unqual` (C23)
`union`
`unsigned`
`void`
`volatile`
`while`

|   |
`_Alignas` (C11)(deprecated in C23)
`_Alignof` (C11)(deprecated in C23)
`_Atomic` (C11)
`_BitInt` (C23)
`_Bool` (C99)(deprecated in C23)
`_Complex` (C99)
`_Decimal128` (C23)
`_Decimal32` (C23)
`_Decimal64` (C23)
`_Generic` (C11)
`_Imaginary` (C99)
`_Noreturn` (C11)(deprecated in C23)
`_Static_assert` (C11)(deprecated in C23)
`_Thread_local` (C11)(deprecated in C23)

The most common keywords that begin with an underscore are generally used through their convenience macros:
以下列出以底線開頭、通常透過較方便的巨集使用的關鍵字：

| Keyword  |   | Used as  |   | Defined in  |

| `_Alignas` (C11)(deprecated in C23)  |   | alignas (removed in C23)  |   | `stdalign.h`  |

| `_Alignof` (C11)(deprecated in C23)  |   | alignof (removed in C23)  |   | `stdalign.h`  |

| `_Atomic` (C11)  |   | atomic_bool, atomic_int, ...  |   | `stdatomic.h`  |

| `_BitInt` (C23)  |   | (no macro)  |   |   |

| `_Bool` (C99)(deprecated in C23)  |   | bool (removed in C23)  |   | `stdbool.h`  |

| `_Complex` (C99)  |   | complex  |   | `complex.h`  |

| `_Decimal128` (C23)  |   | (no macro)  |   |   |

| `_Decimal32` (C23)  |   | (no macro)  |   |   |

| `_Decimal64` (C23)  |   | (no macro)  |   |   |

| `_Generic` (C11)  |   | (no macro)  |   |   |

| `_Imaginary` (C99)  |   | imaginary  |   | `complex.h`  |

| `_Noreturn` (C11)(deprecated in C23)  |   | noreturn  |   | `stdnoreturn.h`  |

| `_Static_assert` (C11)(deprecated in C23)  |   | static_assert (removed in C23)  |   | `assert.h`  |

| `_Thread_local` (C11)(deprecated in C23)  |   | thread_local (removed in C23)  |   | `threads.h`  |

Some keywords are deprecated and retained as alternative spellings for compatibility purposes. These can be used wherever the keyword can.
部分關鍵字已淘汰，但為了相容性仍保留替代拼法。只要原關鍵字可用，就能在相同位置使用這些替代拼法。

| Keyword  |   | Alternative spelling  |

| `alignas` (C23)  |   | `_Alignas` (C11)(deprecated in C23)  |

| `alignof` (C23)  |   | `_Alignof` (C11)(deprecated in C23)  |

| `bool` (C23)  |   | `_Bool` (C99)(deprecated in C23)  |

| `static_assert` (C23)  |   | `_Static_assert` (C11)(deprecated in C23)  |

| `thread_local` (C23)  |   | `_Thread_local` (C11)(deprecated in C23)  |

It is unspecified whether any of the spellings of these keywords, their alternate forms, or `true` and `false` is implemented as a predefined macro.
這些關鍵字及其替代拼法各自採用哪種拼寫，以及實作是否將 true 和 false 定義為預先定義的巨集，均未指定。
Each name that begins with a double underscore `**__**` or an underscore `**_**` followed by an uppercase letter is reserved: see identifier for details.
所有以雙底線 __ 開頭，或以底線 _ 接大寫字母開頭的名稱都保留不用；詳情請參閱識別字。
Note that digraphs `<%`, `%>`, `<:`, `:>`, `%:`, and `%:%:` provide an alternative way to represent standard tokens.
請注意，雙字元符號 <%、%>、<:、:>、%: 和 %:%: 都是標準記號的替代寫法。
The following tokens are recognized by the preprocessor when they are used *within* the context of a preprocessor directive:
當在預處理指令的上下文中使用時，前處理器會識別以下記號：

if
elif
else
endif

|   |
ifdef
ifndef
elifdef (C23)
elifndef (C23)
define
undef

|   |
include
embed (C23)
line
error
warning (C23)
pragma

|   |
defined
__has_include (C23)
__has_embed (C23)
__has_c_attribute (C23)

The following tokens are recognized by the preprocessor when they are used *outside* the context of a preprocessor directive:
當在預處理指令的上下文之外使用時，前處理器會識別以下記號：

_Pragma (C99)

The following additional keywords are classified as extensions and conditionally-supported:
以下額外關鍵字屬於擴充功能，實作可選擇是否支援：

asm
`fortran`

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 6.4.1 Keywords (p: 53)
6.4.1 關鍵字 (p: 53)
6.4.1 關鍵字 (p: 53)

- J.5.9 The fortran keyword (p: 601)
J.5.9 fortran 關鍵字 (p: 601)
J.5.9 fortran 關鍵字 (p: 601)

- J.5.10 The asm keyword (p: 601)
J.5.10 asm 關鍵字 (p: 601)
J.5.10 asm 關鍵字 (p: 601)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.4.1 Keywords (p: 42-43)
6.4.1 關鍵字 (p: 42-43)
6.4.1 關鍵字 (p: 42-43)

- J.5.9 The fortran keyword (p: 422)
J.5.9 fortran 關鍵字 (p: 422)
J.5.9 fortran 關鍵字 (p: 422)

- J.5.10 The asm keyword (p: 422)
J.5.10 asm 關鍵字 (p: 422)
J.5.10 asm 關鍵字 (p: 422)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.4.1 Keywords (p: 58-59)
6.4.1 關鍵字 (p: 58-59)
6.4.1 關鍵字 (p: 58-59)

- J.5.9 The fortran keyword (p: 580)
J.5.9 fortran 關鍵字 (p: 580)
J.5.9 fortran 關鍵字 (p: 580)

- J.5.10 The asm keyword (p: 580)
J.5.10 asm 關鍵字 (p: 580)
J.5.10 asm 關鍵字 (p: 580)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.4.1 Keywords (p: 50)
6.4.1 關鍵字 (p: 50)
6.4.1 關鍵字 (p: 50)

- J.5.9 The fortran keyword (p: 514)
J.5.9 fortran 關鍵字 (p: 514)
J.5.9 fortran 關鍵字 (p: 514)

- J.5.10 The asm keyword (p: 514)
J.5.10 asm 關鍵字 (p: 514)
J.5.10 asm 關鍵字 (p: 514)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.1.1 Keywords

- G.5.9 The fortran keyword
G.5.9 fortran 關鍵字
G.5.9 fortran 關鍵字

- G.5.10 The asm keyword
G.5.10 asm 關鍵字
G.5.10 asm 關鍵字

### See also

C++ documentation for C++ keywords

---
來源頁路徑：`en.cppreference.com/c/keyword.html`

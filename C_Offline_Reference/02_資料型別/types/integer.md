# Fixed width integer types (since C99)

> 來源：cppreference C 語言參考文件（離線轉換版）。

### Types

For each of the following typedef names marked (optional), an implementation defines it if and only if the implementation provides a corresponding type.
以下標示為「可選」的 typedef 名稱，只有在實作提供對應型別時才會定義。

Defined in header `<stdint.h>`

int8_tint16_tint32_tint64_tint*N*_t
(optional)(optional)(optional)(optional)(optional)
|   | signed integer type with width of exactly *N* (typically 8, 16, 32 or 64) bits and no padding bits
(typedef)   |

int_fast8_tint_fast16_tint_fast32_tint_fast64_tint_fast*N*_t
(optional)
|   | fastest signed integer type with width of at least *N* (typically 8, 16, 32 or 64) bits
(typedef)   |

int_least8_tint_least16_tint_least32_tint_least64_tint_least*N*_t
(optional)
|   | smallest signed integer type with width of at least *N* (typically 8, 16, 32 or 64) bits
(if `int*N*_t` is defined, `int_least*N*_t` designates the same type)
(typedef)   |

intmax_t
|   | maximum-width signed integer type other than a bit-precise integer type(since C23)
(typedef)   |

intptr_t
(optional)
|   | signed integer type other than a bit-precise integer type(since C23) capable of holding a pointer to `void`
(typedef)   |

uint8_tuint16_tuint32_tuint64_tuint*N*_t
(optional)(optional)(optional)(optional)(optional)
|   | unsigned integer type with width of exactly *N* (typically 8, 16, 32 or 64) bits and no padding bits
(typedef)   |

uint_fast8_tuint_fast16_tuint_fast32_tuint_fast64_tuint_fast*N*_t
(optional)
|   | fastest unsigned integer type with width of at least *N* (typically 8, 16, 32 or 64) bits
(typedef)   |

uint_least8_tuint_least16_tuint_least32_tuint_least64_tuint_least*N*_t
(optional)
|   | smallest unsigned integer type with width of at least *N* (typically 8, 16, 32 or 64) bits
(if `uint*N*_t` is defined, `uint_least*N*_t` designates the same type)
(typedef)   |

uintmax_t
|   | maximum-width unsigned integer type other than a bit-precise integer type(since C23)
(typedef)   |

uintptr_t
(optional)
|   | unsigned integer type other than a bit-precise integer type(since C23) capable of holding a pointer to `void`
(typedef)   |

### Macro constants
宏常量

For each of the following macros marked (conditionally present), an implementation defines it if and only if the implementation defines the corresponding typedef name.
以下標示為「有條件存在」的巨集，只有在實作定義了對應 typedef 名稱時才會定義。

Defined in header `<stdint.h>`

#####  Signed integers : bit width

INT*N*_WIDTH
(C23)(conditionally present)
|   | bit width of `int*N*_t` (*N* is typically 8, 16, 32 or 64)
(macro constant)   |

INT_FAST*N*_WIDTH
(C23)(conditionally present)
|   | bit width of `int_fast*N*_t` (*N* is typically 8, 16, 32 or 64)
(macro constant)   |

INT_LEAST*N*_WIDTH
(C23)(conditionally present)
|   | bit width of `int_least*N*_t` (*N* is typically 8, 16, 32 or 64)
(macro constant)   |

INTMAX_WIDTH
(C23)
|   | bit width of `intmax_t`
(macro constant)   |

INTPTR_WIDTH
(C23)(conditionally present)
|   | bit width of `intptr_t`
(macro constant)   |

#####  Signed integers : minimum value

INT*N*_MIN
(conditionally present)
|   | minimum value of `int*N*_t` (*N* is typically 8, 16, 32 or 64)
(macro constant)   |

INT_FAST*N*_MIN
(conditionally present)
|   | minimum value of `int_fast*N*_t` (*N* is typically 8, 16, 32 or 64)
(macro constant)   |

INT_LEAST*N*_MIN
(conditionally present)
|   | minimum value of `int_least*N*_t` (*N* is typically 8, 16, 32 or 64)
(macro constant)   |

INTMAX_MIN
|   | minimum value of `intmax_t`
(macro constant)   |

INTPTR_MIN
(conditionally present)
|   | minimum value of `intptr_t`
(macro constant)   |

#####  Signed integers : maximum value

INT*N*_MAX
(conditionally present)
|   | maximum value of `int*N*_t` (*N* is typically 8, 16, 32 or 64)
(macro constant)   |

INT_FAST*N*_MAX
(conditionally present)
|   | maximum value of `int_fast*N*_t` (*N* is typically 8, 16, 32 or 64)
(macro constant)   |

INT_LEAST*N*_MAX
(conditionally present)
|   | maximum value of `int_least*N*_t` (*N* is typically 8, 16, 32 or 64)
(macro constant)   |

INTMAX_MAX
|   | maximum value of `intmax_t`
(macro constant)   |

INTPTR_MAX
(conditionally present)
|   | maximum value of `intptr_t`
(macro constant)   |

#####  Unsigned integers : bit width

UINT*N*_WIDTH
(C23)(conditionally present)
|   | bit width of `uint*N*_t` (*N* is typically 8, 16, 32 or 64)
(macro constant)   |

UINT_FAST*N*_WIDTH
(C23)(conditionally present)
|   | bit width of `uint_fast*N*_t` (*N* is typically 8, 16, 32 or 64)
(macro constant)   |

UINT_LEAST*N*_WIDTH
(C23)(conditionally present)
|   | bit width of `uint_least*N*_t` (*N* is typically 8, 16, 32 or 64)
(macro constant)   |

UINTMAX_WIDTH
(C23)
|   | bit width of `uintmax_t`
(macro constant)   |

UINTPTR_WIDTH
(C23)(conditionally present)
|   | bit width of `uintptr_t`
(macro constant)   |

#####  Unsigned integers : maximum value

UINT*N*_MAX
(conditionally present)
|   | maximum value of `uint*N*_t` (*N* is typically 8, 16, 32 or 64)
(macro constant)   |

UINT_FAST*N*_MAX
(conditionally present)
|   | maximum value of `uint_fast*N*_t` (*N* is typically 8, 16, 32 or 64)
(macro constant)   |

UINT_LEAST*N*_MAX
(conditionally present)
|   | maximum value of `uint_least*N*_t` (*N* is typically 8, 16, 32 or 64)
(macro constant)   |

UINTMAX_MAX
|   | maximum value of `uintmax_t`
(macro constant)   |

UINTPTR_MAX
(conditionally present)
|   | maximum value of `uintptr_t`
(macro constant)   |

### Function macros
函式宏

For each of the following macros marked (conditionally present), an implementation defines it if and only if the implementation defines the corresponding typedef name.
以下標示為「有條件存在」的巨集，只有在實作定義了對應 typedef 名稱時才會定義。

INT*N*_C
(conditionally present)
|   | expands to an integer constant expression of type `int_least*N*_t`, its value is specified by the argument
(function macro)   |

INTMAX_C
|   | expands to an integer constant expression of type `intmax_t`, its value is specified by the argument
(function macro)   |

UINT*N*_C
(conditionally present)
|   | expands to an integer constant expression of type `uint_least*N*_t`, its value is specified by the argument
(function macro)   |

UINTMAX_C
|   | expands to an integer constant expression of type `uintmax_t`, its value is specified by the argument
(function macro)   |

```c
#include <stdint.h> UINT64_C(0x123) // might expand to 0x123ULL or 0x123UL
```

### Format macro constants
格式宏常量

Defined in header `<inttypes.h>`

#### Format constants for the fprintf family of functions

Each of the `PRI` macros listed here is defined if and only if the implementation defines the corresponding typedef name.
只有在實作定義了相應的 typedef 名稱時，才會定義此處列出的 PRI 巨集。

| Equivalent
for `int` or
`unsigned int`  |   | Description  |   | Macros for data types  |

`[u]int**x**_t`
|   |
`[u]int_least**x**_t`
|   |
`[u]int_fast**x**_t`
|   |
`[u]intmax_t`
|   |
`[u]intptr_t`

| `d`  |   | output of a signed decimal integer value  |   | PRId**x**  |   | PRIdLEAST**x**  |   | PRIdFAST**x**  |   | PRIdMAX  |   | PRIdPTR  |

| `i`  |   | PRIi**x**  |   | PRIiLEAST**x**  |   | PRIiFAST**x**  |   | PRIiMAX  |   | PRIiPTR  |

| `u`  |   | output of an unsigned decimal integer value  |   | PRIu**x**  |   | PRIuLEAST**x**  |   | PRIuFAST**x**  |   | PRIuMAX  |   | PRIuPTR  |

| `o`  |   | output of an unsigned octal integer value  |   | PRIo**x**  |   | PRIoLEAST**x**  |   | PRIoFAST**x**  |   | PRIoMAX  |   | PRIoPTR  |

| `x`  |   | output of an unsigned lowercase hexadecimal integer value  |   | PRIx**x**  |   | PRIxLEAST**x**  |   | PRIxFAST**x**  |   | PRIxMAX  |   | PRIxPTR  |

| `X`  |   | output of an unsigned uppercase hexadecimal integer value  |   | PRIX**x**  |   | PRIXLEAST**x**  |   | PRIXFAST**x**  |   | PRIXMAX  |   | PRIXPTR  |

#### Format constants for the fscanf family of functions

Each of the `SCN` macros listed in here is defined if and only if the implementation defines the corresponding typedef name and has a suitable fscanf length modifier for the type.
只有在實作定義了相應的 typedef 名稱，且 fscanf 有適用於該型別的長度修飾符時，才會定義此處列出的 SCN 巨集。

| Equivalent
for `int` or
`unsigned int`  |   | Description  |   | Macros for data types  |

`[u]int**x**_t`
|   |
`[u]int_least**x**_t`
|   |
`[u]int_fast**x**_t`
|   |
`[u]intmax_t`
|   |
`[u]intptr_t`

| `d`  |   | input of a signed decimal integer value  |   | SCNd**x**  |   | SCNdLEAST**x**  |   | SCNdFAST**x**  |   | SCNdMAX  |   | SCNdPTR  |

| `i`  |   | input of a signed integer value (base is determined by the first characters parsed)  |   | SCNi**x**  |   | SCNiLEAST**x**  |   | SCNiFAST**x**  |   | SCNiMAX  |   | SCNiPTR  |

| `u`  |   | input of an unsigned decimal integer value  |   | SCNu**x**  |   | SCNuLEAST**x**  |   | SCNuFAST**x**  |   | SCNuMAX  |   | SCNuPTR  |

| `o`  |   | input of an unsigned octal integer value  |   | SCNo**x**  |   | SCNoLEAST**x**  |   | SCNoFAST**x**  |   | SCNoMAX  |   | SCNoPTR  |

| `x`  |   | input of an unsigned hexadecimal integer value  |   | SCNx**x**  |   | SCNxLEAST**x**  |   | SCNxFAST**x**  |   | SCNxMAX  |   | SCNxPTR  |

### Example

See also C++ compatibility note regarding spaces before format macros used in this example.
另請參閱說明：本例中格式巨集前的空格與 C++ 相容性有關。
Run this code

```c
#include <inttypes.h> #include <stdio.h> int main(void) {  printf("%zu\n", sizeof(int64_t));  printf("%s\n", PRId64);  printf("%+" PRId64 "\n", INT64_MIN);  printf("%+" PRId64 "\n", INT64_MAX);    int64_t n = 7;  printf("%+" PRId64 "\n", n); }
```

Possible output:
可能的輸出：

```c
8 lld -9223372036854775808 +9223372036854775807 +7
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.8.1 Macros for format specifiers (p: TBD)
7.8.1 格式說明符宏（頁碼：待定）
7.8.1 格式說明符宏（頁碼：待定）

- 7.18 Integer types <stdint.h> (p: TBD)
7.18 整數型別 <stdint.h>（頁碼：待定）
7.18 整數型別 <stdint.h>（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.8.1 Macros for format specifiers (p: 158-159)
7.8.1 格式說明符宏（頁碼：158-159）
7.8.1 格式說明符宏（頁碼：158-159）

- 7.18 Integer types <stdint.h> (p: 212-216)
7.18 整數型別 <stdint.h>（頁碼：212-216）
7.18 整數型別 <stdint.h>（頁碼：212-216）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.8.1 Macros for format specifiers (p: 217-218)
7.8.1 格式說明符宏（頁碼：217-218）
7.8.1 格式說明符宏（頁碼：217-218）

- 7.18 Integer types <stdint.h> (p: 289-295)
7.18 整數型別 <stdint.h>（頁碼：289-295）
7.18 整數型別 <stdint.h>（頁碼：289-295）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.8.1 Macros for format specifiers (p: 198-199)
7.8.1 格式說明符宏（頁碼：198-199）
7.8.1 格式說明符宏（頁碼：198-199）

- 7.18 Integer types <stdint.h> (p: 255-261)
7.18 整數型別 <stdint.h>（頁碼：255-261）
7.18 整數型別 <stdint.h>（頁碼：255-261）

### See also

- Arithmetic types
算術型別

C++ documentation for Fixed width integer types

C++ documentation for User-defined literals (formatting macros note)

---
來源頁路徑：`en.cppreference.com/c/types/integer.html`

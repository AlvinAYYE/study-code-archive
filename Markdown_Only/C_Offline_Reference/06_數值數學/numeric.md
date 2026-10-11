# Numerics

> 來源：cppreference C 語言參考文件（離線轉換版）。

The C numerics library includes common mathematical functions and types, as well as support for random number generation.
C 數值函式庫提供常用的數學函式與型別，也支援亂數產生。

### Common mathematical functions
常用數學函式

The header <math.h> provides standard C library mathematical functions such as fabs, sqrt, and sin.
標頭檔 `<math.h>` 提供 C 標準函式庫常用的數學函式，例如 `fabs`、`sqrt` 和 `sin`。

### Floating-point environment
浮點環境

The header <fenv.h> defines flags and functions related to exceptional floating-point state, such as overflow and division by zero.
標頭檔 `<fenv.h>` 提供浮點環境相關的旗標與函式，用來檢查或控制溢位、除以零等浮點例外狀態。

### Pseudo-random number generation
偽隨機數產生

The header <stdlib.h> also includes C-style random number generation via srand and rand.
標頭檔 `<stdlib.h>` 也提供 `rand` 與 `srand`，可產生偽隨機數並設定其種子。

### Complex number arithmetic
複數運算

The header <complex.h> provides types and functions to work with complex numbers.
標頭檔 `<complex.h>` 提供複數型別及相關運算函式。

### Type-generic math
型別通用數學

The header <tgmath.h> provides some macros for a function which names XXX:
標頭檔 `<tgmath.h>` 提供型別通用巨集：呼叫時會依引數型別選用相應精度的函式。以下以 `XXX` 表示函式名稱：

- real function:

- `float` variant `XXXf`
float 版本 XXXf

- `double` variant `XXX`
double 版本 XXX

- `long double` variant `XXXl`
long double 版本 XXXl
float 版本 XXXf、double 版本 XXX、long double 版本 XXXl

- complex function:
複數函式：

- `float` variant `cXXXf`
float 複數版本 cXXXf

- `double` variant `cXXX`
double 複數版本 cXXX

- `long double` variant `cXXXl`
long double 複數版本 cXXXl
float 複數版本 cXXXf、double 複數版本 cXXX、long double 複數版本 cXXXl

### Bit manipulation (since C23)
位元操作（C23 起）

The header <stdbit.h> provides macros and functions to work with the byte ordering and byte and bit representation of C objects.
標頭檔 `<stdbit.h>` 提供巨集與函式，可檢查 C 物件的位元組順序，並操作其位元組與位元表示。

### Checked integer arithmetic (since C23)
檢查整數運算（C23 起）

Provides some type-generic macros for checked integer arithmetic:
`<stdckdint.h>` 提供型別通用巨集，執行整數加、減、乘法並回報結果是否溢位：

Defined in header `<stdckdint.h>`

ckd_add
(C23)
|   | checked addition operation on two integers
(type-generic function macro)  |

ckd_sub
(C23)
|   | checked subtraction operation on two integers
(type-generic function macro)  |

ckd_mul
(C23)
|   | checked multiplication operation on two integers
(type-generic function macro)  |

### See also

C++ documentation for Numerics library

---
來源頁路徑：`en.cppreference.com/c/numeric.html`

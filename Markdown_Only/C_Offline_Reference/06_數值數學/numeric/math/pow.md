# pow, powf, powl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
float powf( float base, float exponent );
```
|   |  (1)  |   |  (since C99)  |

```c
double pow( double base, double exponent );
```
|   |  (2)  |   |   |

```c
long double powl( long double base, long double exponent );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define pow( base, exponent )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Computes the value of `base` raised to the power `exponent`.

4) Type-generic macro: If any argument has type `long double`, `powl` is called. Otherwise, if any argument has integer type or has type `double`, `pow` is called. Otherwise, `powf` is called. If at least one argument is complex or imaginary, then the macro invokes the corresponding complex function (`cpowf`, `cpow`, `cpowl`).

### Parameters

| base  |   | -  |   | base as floating-point value  |

| exponent  |   | -  |   | exponent as floating-point value  |

### Return value

If no errors occur, `base` raised to the power of `exponent` (baseexponent
) is returned.
若沒有發生錯誤，回傳 base 的 exponent 次方。
If a domain error occurs, an implementation-defined value is returned (NaN where supported).
若發生定義域錯誤，回傳由實作定義的值（若支援則回傳 NaN）。
If a pole error or a range error due to overflow occurs, `±HUGE_VAL`, `±HUGE_VALF`, or `±HUGE_VALL` is returned.
若發生極點錯誤，或因浮點溢位而發生值域錯誤，回傳 ±HUGE_VAL、±HUGE_VALF 或 ±HUGE_VALL。
If a range error occurs due to underflow, the correct result (after rounding) is returned.
若因浮點下溢而發生值域錯誤，回傳正確結果（經捨入後）。

### Error handling

Errors are reported as specified in math_errhandling.
錯誤會依照 math_errhandling 的規定回報。
If `base` is finite and negative and `exponent` is finite and non-integer, a domain error occurs and a range error may occur.
若 base 是有限負數，而 exponent 是有限的非整數，會發生定義域錯誤，也可能發生值域錯誤。
If `base` is zero and `exponent` is zero, a domain error may occur.
若 base 和 exponent 都是零，可能會發生定義域錯誤。
If `base` is zero and `exponent` is negative, a domain error or a pole error may occur.
若 base 為零而 exponent 為負數，可能會發生定義域錯誤或極點錯誤。
If the implementation supports IEEE floating-point arithmetic (IEC 60559),
若實作支援 IEEE 浮點運算（IEC 60559）：

- `pow(+0, exponent)`, where `exponent` is a negative odd integer, returns `+∞` and raises FE_DIVBYZERO
pow ( + 0 , exponent ) （其中 exponent 為負奇數）傳回 +∞ 並引發 FE_DIVBYZERO

- `pow(-0, exponent)`, where `exponent` is a negative odd integer, returns `-∞` and raises FE_DIVBYZERO
pow ( -0 , exponent ) （其中 exponent 為負奇數）傳回 -∞ 並引發 FE_DIVBYZERO

- `pow(±0, exponent)`, where `exponent` is negative, finite, and is an even integer or a non-integer, returns +∞ and raises FE_DIVBYZERO
pow ( ± 0 , exponent ) （其中 exponent 為有限的負偶數或負非整數）傳回 +∞ 並引發 FE_DIVBYZERO

- `pow(±0, -∞)` returns +∞ and may raise FE_DIVBYZERO(until C23)
pow ( ± 0 , - ∞ ) 傳回 +∞ 並可能引發 FE_DIVBYZERO （C23 之前）

- `pow(+0, exponent)`, where `exponent` is a positive odd integer, returns +0
pow ( + 0 , exponent ) （其中 exponent 為正奇數）傳回 +0

- `pow(-0, exponent)`, where `exponent` is a positive odd integer, returns -0
pow ( -0 , exponent ) （其中 exponent 為正奇數）傳回 -0

- `pow(±0, exponent)`, where `exponent` is positive non-integer or a positive even integer, returns +0
pow ( ± 0 , exponent ) （其中 exponent 為正非整數或正偶數）傳回 +0

- `pow(-1, ±∞)` returns `1`
pow ( -1 , ±∞ ) 傳回 1

- `pow(+1, exponent)` returns `1` for any `exponent`, even when `exponent` is `NaN`
對任意 exponent ，pow ( + 1 , exponent ) 傳回 1，即使 exponent 為 NaN

- `pow(base, ±0)` returns `1` for any `base`, even when `base` is `NaN`
對任意 base ，pow ( base , ± 0 ) 傳回 1，即使 base 為 NaN

- `pow(base, exponent)` returns `NaN` and raises FE_INVALID if `base` is finite and negative and `exponent` is finite and non-integer.
如果 base 為有限負數且 exponent 為有限非整數，則 pow ( base , exponent ) 傳回 NaN 並引發 FE_INVALID。

- `pow(base, -∞)` returns +∞ for any `|base|<1`
對任意 |base|<1 ，pow ( base , - ∞ ) 傳回 +∞

- `pow(base, -∞)` returns +0 for any `|base|>1`
對任意 |base|>1 ，pow ( base , - ∞ ) 傳回 +0

- `pow(base, +∞)` returns +0 for any `|base|<1`
對任意 |base|<1 ，pow ( base , + ∞ ) 傳回 +0

- `pow(base, +∞)` returns +∞ for any `|base|>1`
對任意 |base|>1 ，pow ( base , + ∞ ) 傳回 +∞

- `pow(-∞, exponent)` returns -0 if `exponent` is a negative odd integer
若 exponent 為負奇數，pow ( - ∞ , exponent ) 傳回 -0

- `pow(-∞, exponent)` returns +0 if `exponent` is a negative non-integer or negative even integer
若 exponent 為負非整數或負偶數，pow ( - ∞ , exponent ) 傳回 +0

- `pow(-∞, exponent)` returns -∞ if `exponent` is a positive odd integer
若 exponent 為正奇數，pow ( - ∞ , exponent ) 傳回 -∞

- `pow(-∞, exponent)` returns +∞ if `exponent` is a positive non-integer or positive even integer
若 exponent 為正非整數或正偶數，pow ( - ∞ , exponent ) 傳回 +∞

- `pow(+∞, exponent)` returns +0 for any negative `exponent`
對任意負 exponent ，pow ( + ∞ , exponent ) 傳回 +0

- `pow(+∞, exponent)` returns +∞ for any positive `exponent`
對任意正 exponent ，pow ( + ∞ , exponent ) 傳回 +∞

- except where specified above, if any argument is NaN, NaN is returned.
除上述情況外，只要任一參數是 NaN，就回傳 NaN。

### Notes

Although `pow` cannot be used to obtain a root of a negative number, cbrt is provided for the common case where `exponent` is `1 / 3`.
pow 無法用來計算負數的根；若要處理常見的 exponent = 1 / 3 情況，可使用 cbrt。

### Example

Run this code

```c
#include <errno.h> #include <fenv.h> #include <math.h> #include <stdio.h> // #pragma STDC FENV_ACCESS ON int main(void) {  // typical usage  printf("pow(2, 10) = %f\n", pow(2, 10));  printf("pow(2, 0.5) = %f\n", pow(2, 0.5));  printf("pow(-2, -3) = %f\n", pow(-2, -3));  // special values  printf("pow(-1, NAN) = %f\n", pow(-1, NAN));  printf("pow(+1, NAN) = %f\n", pow(+1, NAN));  printf("pow(INFINITY, 2) = %f\n", pow(INFINITY, 2));  printf("pow(INFINITY, -1) = %f\n", pow(INFINITY, -1));  // error handling  errno = 0; feclearexcept(FE_ALL_EXCEPT);  printf("pow(-1, 1/3) = %f\n", pow(-1, 1.0 / 3));  if (errno == EDOM)  perror(" errno == EDOM");  if (fetestexcept(FE_INVALID))  puts(" FE_INVALID raised");  feclearexcept(FE_ALL_EXCEPT);  printf("pow(-0, -3) = %f\n", pow(-0.0, -3));  if (fetestexcept(FE_DIVBYZERO))  puts(" FE_DIVBYZERO raised"); }
```

Possible output:
可能的輸出：

```c
pow(2, 10) = 1024.000000 pow(2, 0.5) = 1.414214 pow(-2, -3) = -0.125000 pow(-1, NAN) = nan pow(+1, NAN) = 1.000000 pow(INFINITY, 2) = inf pow(INFINITY, -1) = 0.000000 pow(-1, 1/3) = -nan errno == EDOM: Numerical argument out of domain FE_INVALID raised pow(-0, -3) = -inf FE_DIVBYZERO raised
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.7.5 The pow functions
7.12.7.5 pow 函式
7.12.7.5 pow 函式

- 7.27 Type-generic math <tgmath.h>
7.27 型別泛型數學 <tgmath.h>
7.27 型別泛型數學 <tgmath.h>

- F.10.4.5 The pow functions (p: 524-525)
F.10.4.5 pow 函式（p: 524-525）
F.10.4.5 pow 函式（p: 524-525）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.7.4 The pow functions (p: 248-249)
7.12.7.4 pow 函式（p: 248-249）
7.12.7.4 pow 函式（p: 248-249）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.4.4 The pow functions (p: 524-525)
F.10.4.4 pow 函式（p: 524-525）
F.10.4.4 pow 函式（p: 524-525）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.7.4 The pow functions (p: 248-249)
7.12.7.4 pow 函式（p: 248-249）
7.12.7.4 pow 函式（p: 248-249）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.4.4 The pow functions (p: 524-525)
F.10.4.4 pow 函式（p: 524-525）
F.10.4.4 pow 函式（p: 524-525）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.7.4 The pow functions (p: 229)
7.12.7.4 pow 函式（p: 229）
7.12.7.4 pow 函式（p: 229）

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- F.9.4.4 The pow functions (p: 461)
F.9.4.4 pow 函式（p: 461）
F.9.4.4 pow 函式（p: 461）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.5.5.1 The pow function
4.5.5.1 pow 函式
4.5.5.1 pow 函式

### See also

sqrtsqrtfsqrtl
(C99)(C99)
|   | computes square root (√xx√x)
(function)   |

cbrtcbrtfcbrtl
(C99)(C99)(C99)
|   | computes cube root (3√xx33√x)
(function)   |

hypothypotfhypotl
(C99)(C99)(C99)
|   | computes square root of the sum of the squares of two given numbers (√x2+y2x2+y2√x2
+y2
)
(function)   |

cpowcpowfcpowl
(C99)(C99)(C99)
|   | computes the complex power function
(function)   |

C++ documentation for pow

---
來源頁路徑：`en.cppreference.com/c/numeric/math/pow.html`

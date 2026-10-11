# sqrt, sqrtf, sqrtl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
float sqrtf( float arg );
```
|   |  (1)  |   |  (since C99)  |

```c
double sqrt( double arg );
```
|   |  (2)  |   |   |

```c
long double sqrtl( long double arg );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define sqrt( arg )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Computes square root of `arg`.

4) Type-generic macro: If `arg` has type `long double`, `sqrtl` is called. Otherwise, if `arg` has integer type or the type `double`, `sqrt` is called. Otherwise, `sqrtf` is called. If `arg` is complex or imaginary, then the macro invokes the corresponding complex function (`csqrtf`, `csqrt`, `csqrtl`).

### Parameters

| arg  |   | -  |   | floating-point value  |

### Return value

If no errors occur, square root of `arg` (√argarg√arg), is returned.
若沒有發生錯誤，回傳 arg 的平方根（√arg）。
If a domain error occurs, an implementation-defined value is returned (NaN where supported).
若發生定義域錯誤，回傳由實作定義的值（若支援則回傳 NaN）。
If a range error occurs due to underflow, the correct result (after rounding) is returned.
若因浮點下溢而發生值域錯誤，回傳正確結果（經捨入後）。

### Error handling

Errors are reported as specified in math_errhandling.
錯誤會依照 math_errhandling 的規定回報。
Domain error occurs if `arg` is less than zero.
若 arg 小於零，會發生定義域錯誤。
If the implementation supports IEEE floating-point arithmetic (IEC 60559),
若實作支援 IEEE 浮點運算（IEC 60559）：

- If the argument is less than -0, FE_INVALID is raised and NaN is returned.
若參數小於 -0，會引發 FE_INVALID 並回傳 NaN。

- If the argument is +∞ or ±0, it is returned, unmodified.
若參數為 +∞ 或 ±0，則原樣回傳。

- If the argument is NaN, NaN is returned.
若參數為 NaN，回傳 NaN。

### Notes

`sqrt` is required by the IEEE standard to be correctly rounded from the infinitely precise result. In particular, the exact result is produced if it can be represented in the floating-point type. The only other operations which require this are the arithmetic operators and the function fma. Other functions, including pow, are not so constrained.
IEEE 標準要求 sqrt 對精確結果進行正確捨入。尤其是，若精確結果可由浮點型別表示，就必須回傳該精確值。除了算術運運算元和函式 fma 之外，其他函式都沒有這項要求，pow 也不例外。

### Example

Run this code

```c
#include <errno.h> #include <fenv.h> #include <math.h> #include <stdio.h> // #pragma STDC FENV_ACCESS ON int main(void) {  // normal use  printf("sqrt(100) = %f\n", sqrt(100));  printf("sqrt(2) = %f\n", sqrt(2));  printf("golden ratio = %f\n", (1 + sqrt(5)) / 2);  // special values  printf("sqrt(-0) = %f\n", sqrt(-0.0));  // error handling  errno = 0; feclearexcept(FE_ALL_EXCEPT);  printf("sqrt(-1.0) = %f\n", sqrt(-1));  if (errno == EDOM)  perror(" errno == EDOM");  if (fetestexcept(FE_INVALID))  puts(" FE_INVALID was raised"); }
```

Possible output:
可能的輸出：

```c
sqrt(100) = 10.000000 sqrt(2) = 1.414214 golden ratio = 1.618034 sqrt(-0) = -0.000000 sqrt(-1.0) = -nan errno = EDOM: Numerical argument out of domain FE_INVALID was raised
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.7.5 The sqrt functions (p: TBD)
7.12.7.5 sqrt 函式（p: TBD）
7.12.7.5 sqrt 函式（p: TBD）

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.4.5 The sqrt functions (p: TBD)
F.10.4.5 sqrt 函式（p: TBD）
F.10.4.5 sqrt 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.7.5 The sqrt functions (p: TBD)
7.12.7.5 sqrt 函式（p: TBD）
7.12.7.5 sqrt 函式（p: TBD）

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.4.5 The sqrt functions (p: TBD)
F.10.4.5 sqrt 函式（p: TBD）
F.10.4.5 sqrt 函式（p: TBD）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.7.5 The sqrt functions (p: 249)
7.12.7.5 sqrt 函式（p: 249）
7.12.7.5 sqrt 函式（p: 249）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.4.5 The sqrt functions (p: 525)
F.10.4.5 sqrt 函式（p: 525）
F.10.4.5 sqrt 函式（p: 525）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.7.5 The sqrt functions (p: 229-230)
7.12.7.5 sqrt 函式（p: 229-230）
7.12.7.5 sqrt 函式（p: 229-230）

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- F.9.4.5 The sqrt functions (p: 462)
F.9.4.5 sqrt 函式（p: 462）
F.9.4.5 sqrt 函式（p: 462）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.5.5.2 The sqrt function
4.5.5.2 sqrt 函式
4.5.5.2 sqrt 函式

### See also

powpowfpowl
(C99)(C99)
|   | computes a number raised to the given power (xyxyx)
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

csqrtcsqrtfcsqrtl
(C99)(C99)(C99)
|   | computes the complex square root
(function)   |

C++ documentation for sqrt

---
來源頁路徑：`en.cppreference.com/c/numeric/math/sqrt.html`

# fabs, fabsf, fabsl, fabsd32, fabsd64, fabsd128

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
float fabsf( float arg );
```
|   |  (1)  |   |  (since C99)  |

```c
double fabs( double arg );
```
|   |  (2)  |   |   |

```c
long double fabsl( long double arg );
```
|   |  (3)  |   |  (since C99)  |

```c
_Decimal32 fabsd32( _Decimal32 arg );
```
|   |  (4)  |   |  (since C23)  |

```c
_Decimal64 fabsd64( _Decimal64 arg );
```
|   |  (5)  |   |  (since C23)  |

```c
_Decimal128 fabsd128( _Decimal128 arg );
```
|   |  (6)  |   |  (since C23)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define fabs( arith )
```
|   |  (7)  |   |  (since C99)  |

|  |  |  |  |

1-6) Computes the absolute value of a floating-point value `arg`.

The functions with decimal floating-point parameters are declared if and only if the implementation predefines `__STDC_IEC_60559_DFP__` (i.e. the implementation supports decimal floating-point numbers).
|   | (since C23) |

7) Type-generic macro: If the argument has type `_Decimal128`, `_Decimal64`, `_Decimal32`,(since C23)`long double`, `double`, or `float`, `fabsd128`, `fabsd64`, `fabsd32`,(since C23)`fabsl`, `fabs`, or `fabsf` is called, respectively. Otherwise, if the argument has integer type, `fabs` is called. Otherwise, if the argument is complex, then the macro invokes the corresponding complex function (cabsf, cabs, cabsl). Otherwise, the behavior is undefined.

### Parameters

| arg  |   | -  |   | floating-point value  |

| arith  |   | -  |   | floating-point or integer value  |

### Return value

If successful, returns the absolute value of `arg` (|arg||arg||arg|). The value returned is exact and does not depend on any rounding modes.
成功時回傳 arg 的絕對值 |arg|。回傳值是精確值，不受捨入模式影響。

### Error handling

This function is not subject to any of the error conditions specified in math_errhandling.
此函式不受 math_errhandling 所列任何錯誤狀況影響。
If the implementation supports IEEE floating-point arithmetic (IEC 60559),
若實作支援 IEEE 浮點運算（IEC 60559）：

- If the argument is ±0, +0 is returned.
若參數為 ±0，回傳 +0。

- If the argument is ±∞, +∞ is returned.
若參數為 ±∞，回傳 +∞。

- If the argument is NaN, NaN is returned.
若參數為 NaN，回傳 NaN。

### Example

Run this code

```c
#include <math.h> #include <stdio.h> #define PI 3.14159 // This numerical integration assumes all area is positive. double integrate(double f(double),  double a, double b, // assume a < b  unsigned steps) // assume steps > 0 {  const double dx = (b - a) / steps;  double sum = 0.0;  for (double x = a; x < b; x += dx)  sum += fabs(f(x));  return dx * sum; } int main(void) {  printf("fabs(+3) = %f\n", fabs(+3.0));  printf("fabs(-3) = %f\n", fabs(-3.0));  // special values  printf("fabs(-0) = %f\n", fabs(-0.0));  printf("fabs(-Inf) = %f\n", fabs(-INFINITY));  printf("Area under sin(x) in [-PI, PI] = %f\n", integrate(sin, -PI, PI, 5101)); }
```

Output:

```c
fabs(+3) = 3.000000 fabs(-3) = 3.000000 fabs(-0) = 0.000000 fabs(-Inf) = inf Area under sin(x) in [-PI, PI] = 4.000000
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.7.2 The fabs functions (p: TBD)
7.12.7.2 fabs 函式（p: TBD）
7.12.7.2 fabs 函式（p: TBD）

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.4.2 The fabs functions (p: TBD)
F.10.4.2 fabs 函式（p: TBD）
F.10.4.2 fabs 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.7.2 The fabs functions (p: 181)
7.12.7.2 fabs 函式（p: 181）
7.12.7.2 fabs 函式（p: 181）

- 7.25 Type-generic math <tgmath.h> (p: 272-273)
7.25 型別通用數學 <tgmath.h> (p: 272-273)
7.25 型別通用數學 <tgmath.h> (p: 272-273)

- F.10.4.2 The fabs functions (p: 382)
F.10.4.2 fabs 函式（p: 382）
F.10.4.2 fabs 函式（p: 382）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.7.2 The fabs functions (p: 248)
7.12.7.2 fabs 函式（p: 248）
7.12.7.2 fabs 函式（p: 248）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.4.2 The fabs functions (p: 524)
F.10.4.2 fabs 函式（p: 524）
F.10.4.2 fabs 函式（p: 524）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.7.2 The fabs functions (p: 228-229)
7.12.7.2 fabs 函式（p: 228-229）
7.12.7.2 fabs 函式（p: 228-229）

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- F.9.4.2 The fabs functions (p: 460)
F.9.4.2 fabs 函式（p: 460）
F.9.4.2 fabs 函式（p: 460）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.5.6.2 The fabs function
4.5.6.2 fabs 函式
4.5.6.2 fabs 函式

### See also

abslabsllabs
(C99)
|   | computes absolute value of an integral value (|x||x||x|)
(function)   |

copysigncopysignfcopysignl
(C99)(C99)(C99)
|   | produces a value with the magnitude of a given value and the sign of another given value
(function)   |

signbit
(C99)
|   | checks if the given number is negative
(function macro)   |

cabscabsfcabsl
(C99)(C99)(C99)
|   | computes the magnitude of a complex number
(function)   |

C++ documentation for fabs

---
來源頁路徑：`en.cppreference.com/c/numeric/math/fabs.html`

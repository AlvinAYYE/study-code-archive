# nearbyint, nearbyintf, nearbyintl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
float nearbyintf( float arg );
```
|   |  (1)  |   |  (since C99)  |

```c
double nearbyint( double arg );
```
|   |  (2)  |   |  (since C99)  |

```c
long double nearbyintl( long double arg );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define nearbyint( arg )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Rounds the floating-point argument `arg` to an integer value in floating-point format, using the current rounding mode.

4) Type-generic macro: If `arg` has type `long double`, `nearbyintl` is called. Otherwise, if `arg` has integer type or the type `double`, `nearbyint` is called. Otherwise, `nearbyintf` is called, respectively.

### Parameters

| arg  |   | -  |   | floating-point value  |

### Return value

The nearest integer value to `arg`, according to the current rounding mode, is returned.
按照目前舍入模式，傳回最接近 arg 的整數值。

### Error handling

This function is not subject to any of the errors specified in math_errhandling.
此函式不受 math_errhandling 中規定的任何錯誤影響。
If the implementation supports IEEE floating-point arithmetic (IEC 60559),
若實作支援 IEEE 浮點運算（IEC 60559）：

- FE_INEXACT is never raised.
從不引發 FE_INEXACT 。

- If `arg` is ±∞, it is returned, unmodified.
若 arg 為 ±∞，則原樣回傳。

- If `arg` is ±0, it is returned, unmodified.
若 arg 為 ±0，則原樣回傳。

- If `arg` is NaN, NaN is returned.
如果 arg 為 NaN，則傳回 NaN。

### Notes

The only difference between `nearbyint` and rint is that `nearbyint` never raises FE_INEXACT.
nearbyint 與 rint 的唯一區別在於 nearbyint 從不引發 FE_INEXACT 。
The largest representable floating-point values are exact integers in all standard floating-point formats, so `nearbyint` never overflows on its own; however the result may overflow any integer type (including intmax_t), when stored in an integer variable.
在所有標準浮點格式中，可表示的最大浮點值都是精確整數，因此 nearbyint 本身絕不會上溢；但當結果存入整數變數時，可能會超出任何整數型別（包括 intmax_t ）的範圍。
If the current rounding mode is FE_TONEAREST, this function rounds to even in halfway cases (like rint, but unlike round).
如果目前舍入模式為 FE_TONEAREST ，此函式在恰好居中的情況下舍入到偶數（與 rint 相同，但與 round 不同）。

### Example

Run this code

```c
#include <fenv.h> #include <math.h> #include <stdio.h> int main(void) { // #pragma STDC FENV_ACCESS ON  fesetround(FE_TONEAREST);  printf("rounding to nearest:\nnearbyint(+2.3) = %+.1f ", nearbyint(2.3));  printf("nearbyint(+2.5) = %+.1f ", nearbyint(2.5));  printf("nearbyint(+3.5) = %+.1f\n", nearbyint(3.5));  printf("nearbyint(-2.3) = %+.1f ", nearbyint(-2.3));  printf("nearbyint(-2.5) = %+.1f ", nearbyint(-2.5));  printf("nearbyint(-3.5) = %+.1f\n", nearbyint(-3.5));  fesetround(FE_DOWNWARD);  printf("rounding down: \nnearbyint(+2.3) = %+.1f ", nearbyint(2.3));  printf("nearbyint(+2.5) = %+.1f ", nearbyint(2.5));  printf("nearbyint(+3.5) = %+.1f\n", nearbyint(3.5));  printf("nearbyint(-2.3) = %+.1f ", nearbyint(-2.3));  printf("nearbyint(-2.5) = %+.1f ", nearbyint(-2.5));  printf("nearbyint(-3.5) = %+.1f\n", nearbyint(-3.5));  printf("nearbyint(-0.0) = %+.1f\n", nearbyint(-0.0));  printf("nearbyint(-Inf) = %+.1f\n", nearbyint(-INFINITY)); }
```

Output:

```c
rounding to nearest: nearbyint(+2.3) = +2.0 nearbyint(+2.5) = +2.0 nearbyint(+3.5) = +4.0 nearbyint(-2.3) = -2.0 nearbyint(-2.5) = -2.0 nearbyint(-3.5) = -4.0 rounding down: nearbyint(+2.3) = +2.0 nearbyint(+2.5) = +2.0 nearbyint(+3.5) = +3.0 nearbyint(-2.3) = -3.0 nearbyint(-2.5) = -3.0 nearbyint(-3.5) = -4.0 nearbyint(-0.0) = -0.0 nearbyint(-Inf) = -inf
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.9.3 The nearbyint functions (p: TBD)
7.12.9.3 nearbyint 函式（p: TBD）
7.12.9.3 nearbyint 函式（p: TBD）

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.6.3 The nearbyint functions (p: TBD)
F.10.6.3 nearbyint 函式（p: TBD）
F.10.6.3 nearbyint 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.9.3 The nearbyint functions (p: TBD)
7.12.9.3 nearbyint 函式（p: TBD）
7.12.9.3 nearbyint 函式（p: TBD）

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.6.3 The nearbyint functions (p: TBD)
F.10.6.3 nearbyint 函式（p: TBD）
F.10.6.3 nearbyint 函式（p: TBD）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.9.3 The nearbyint functions (p: 251-252)
7.12.9.3 nearbyint 函式（p: 251-252）
7.12.9.3 nearbyint 函式（p: 251-252）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.6.3 The nearbyint functions (p: 526)
F.10.6.3 nearbyint 函式（p: 526）
F.10.6.3 nearbyint 函式（p: 526）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.9.3 The nearbyint functions (p: 232)
7.12.9.3 nearbyint 函式（p: 232）
7.12.9.3 nearbyint 函式（p: 232）

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- F.9.6.3 The nearbyint functions (p: 463)
F.9.6.3 nearbyint 函式（p: 463）
F.9.6.3 nearbyint 函式（p: 463）

### See also

rintrintfrintllrintlrintflrintlllrintllrintfllrintl
(C99)(C99)(C99)(C99)(C99)(C99)(C99)(C99)(C99)
|   | rounds to an integer using current rounding mode with
exception if the result differs
(function)   |

roundroundfroundllroundlroundflroundlllroundllroundfllroundl
(C99)(C99)(C99)(C99)(C99)(C99)(C99)(C99)(C99)
|   | rounds to nearest integer, rounding away from zero in halfway cases
(function)   |

fegetroundfesetround
(C99)(C99)
|   | gets or sets rounding direction
(function)   |

C++ documentation for nearbyint

---
來源頁路徑：`en.cppreference.com/c/numeric/math/nearbyint.html`

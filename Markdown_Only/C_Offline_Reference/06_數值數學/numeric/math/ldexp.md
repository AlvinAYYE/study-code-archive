# ldexp, ldexpf, ldexpl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
float ldexpf( float arg, int exp );
```
|   |  (1)  |   |  (since C99)  |

```c
double ldexp( double arg, int exp );
```
|   |  (2)  |   |   |

```c
long double ldexpl( long double arg, int exp );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define ldexp( arg, exp )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Multiplies a floating-point value `arg` by the number `2` raised to the `exp` power.

4) Type-generic macro: If `arg` has type `long double`, `ldexpl` is called. Otherwise, if `arg` has integer type or the type `double`, `ldexp` is called. Otherwise, `ldexpf` is called, respectively.

### Parameters

| arg  |   | -  |   | floating-point value  |

| exp  |   | -  |   | integer value  |

### Return value

If no errors occur, `arg` multiplied by 2 to the power of `exp` (arg×2exp
) is returned.
若沒有發生錯誤，回傳 arg × 2^exp。
If a range error due to overflow occurs, ±HUGE_VAL, `±HUGE_VALF`, or `±HUGE_VALL` is returned.
若因浮點溢位而發生值域錯誤，回傳 ±HUGE_VAL、±HUGE_VALF 或 ±HUGE_VALL。
If a range error due to underflow occurs, the correct result (after rounding) is returned.
若因浮點下溢而發生值域錯誤，回傳正確結果（經捨入後）。

### Error handling

Errors are reported as specified in math_errhandling.
錯誤會依照 math_errhandling 的規定回報。
If the implementation supports IEEE floating-point arithmetic (IEC 60559),
若實作支援 IEEE 浮點運算（IEC 60559）：

- Unless a range error occurs, FE_INEXACT is never raised (the result is exact)
除非發生值域錯誤，否則結果都是精確值，不會引發 FE_INEXACT。

- Unless a range error occurs, the current rounding mode is ignored
除非發生值域錯誤，否則結果不受目前捨入模式影響。

- If `arg` is ±0, it is returned, unmodified
若 arg 為 ±0，則原樣回傳。

- If `arg` is ±∞, it is returned, unmodified
若 arg 為 ±∞，則原樣回傳。

- If `exp` is 0, then `arg` is returned, unmodified
若 exp 為 0，則原樣回傳 arg。

- If `arg` is NaN, NaN is returned.
若 arg 為 NaN，回傳 NaN。

### Notes

On binary systems (where FLT_RADIX is `2`), `ldexp` is equivalent to scalbn.
在二進位系統（FLT_RADIX 為 2）中，ldexp 等同於 scalbn。
The function `ldexp` ("load exponent"), together with its dual, frexp, can be used to manipulate the representation of a floating-point number without direct bit manipulations.
ldexp（意為「載入指數」）和與它互補的 frexp 可用來操作浮點數表示法，不必直接處理位元。
On many implementations, `ldexp` is less efficient than multiplication or division by a power of two using arithmetic operators.
在許多實作中，使用算術運運算元乘除 2 的冪次，比呼叫 ldexp 更有效率。

### Example

Run this code

```c
#include <errno.h> #include <fenv.h> #include <float.h> #include <math.h> #include <stdio.h> // #pragma STDC FENV_ACCESS ON int main(void) {  printf("ldexp(7, -4) = %f\n", ldexp(7, -4));  printf("ldexp(1, -1074) = %g (minimum positive subnormal double)\n",  ldexp(1, -1074));  printf("ldexp(nextafter(1,0), 1024) = %g (largest finite double)\n",  ldexp(nextafter(1,0), 1024));    // special values  printf("ldexp(-0, 10) = %f\n", ldexp(-0.0, 10));  printf("ldexp(-Inf, -1) = %f\n", ldexp(-INFINITY, -1));    // error handling  errno = 0; feclearexcept(FE_ALL_EXCEPT);  printf("ldexp(1, 1024) = %f\n", ldexp(1, 1024));  if (errno == ERANGE)  perror(" errno == ERANGE");  if (fetestexcept(FE_OVERFLOW))  puts(" FE_OVERFLOW raised"); }
```

Possible output:
可能的輸出：

```c
ldexp(7, -4) = 0.437500 ldexp(1, -1074) = 4.94066e-324 (minimum positive subnormal double) ldexp(nextafter(1,0), 1024) = 1.79769e+308 (largest finite double) ldexp(-0, 10) = -0.000000 ldexp(-Inf, -1) = -inf ldexp(1, 1024) = inf errno == ERANGE: Numerical result out of range FE_OVERFLOW raised
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.6.6 The ldexp functions (p: TBD)
7.12.6.6 ldexp 函式（p: TBD）
7.12.6.6 ldexp 函式（p: TBD）

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.3.6 The ldexp functions (p: TBD)
F.10.3.6 ldexp 函式（p: TBD）
F.10.3.6 ldexp 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.6.6 The ldexp functions (p: TBD)
7.12.6.6 ldexp 函式（p: TBD）
7.12.6.6 ldexp 函式（p: TBD）

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.3.6 The ldexp functions (p: TBD)
F.10.3.6 ldexp 函式（p: TBD）
F.10.3.6 ldexp 函式（p: TBD）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.6.6 The ldexp functions (p: 244)
7.12.6.6 ldexp 函式（p: 244）
7.12.6.6 ldexp 函式（p: 244）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.3.6 The ldexp functions (p: 522)
F.10.3.6 ldexp 函式（p: 522）
F.10.3.6 ldexp 函式（p: 522）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.6.6 The ldexp functions (p: 225)
7.12.6.6 ldexp 函式（p: 225）
7.12.6.6 ldexp 函式（p: 225）

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- F.9.3.6 The ldexp functions (p: 459)
F.9.3.6 ldexp 函式（p: 459）
F.9.3.6 ldexp 函式（p: 459）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.5.4.3 The ldexp function
4.5.4.3 ldexp 函式
4.5.4.3 ldexp 函式

### See also

frexpfrexpffrexpl
(C99)(C99)
|   | breaks a number into significand and a power of 2
(function)   |

scalbnscalbnfscalbnlscalblnscalblnfscalblnl
(C99)(C99)(C99)(C99)(C99)(C99)
|   | computes efficiently a number times FLT_RADIX raised to a power
(function)   |

C++ documentation for ldexp

---
來源頁路徑：`en.cppreference.com/c/numeric/math/ldexp.html`

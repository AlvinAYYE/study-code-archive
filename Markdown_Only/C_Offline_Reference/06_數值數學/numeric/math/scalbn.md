# scalbn, scalbnf, scalbnl, scalbln, scalblnf, scalblnl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
float scalbnf( float arg, int exp );
```
|   |  (1)  |   |  (since C99)  |

```c
double scalbn( double arg, int exp );
```
|   |  (2)  |   |  (since C99)  |

```c
long double scalbnl( long double arg, int exp );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define scalbn( arg, exp )
```
|   |  (4)  |   |  (since C99)  |

Defined in header `<math.h>`
|   |  |   |  |

```c
float scalblnf( float arg, long exp );
```
|   |  (5)  |   |  (since C99)  |

```c
double scalbln( double arg, long exp );
```
|   |  (6)  |   |  (since C99)  |

```c
long double scalblnl( long double arg, long exp );
```
|   |  (7)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define scalbln( arg, exp )
```
|   |  (8)  |   |  (since C99)  |

|  |  |  |  |

1-3,5-7) Multiplies a floating-point value `arg` by FLT_RADIX raised to power `exp`.

4,8) Type-generic macros: If `arg` has type `long double`, `scalbnl` or `scalblnl` is called. Otherwise, if `arg` has integer type or the type `double`, `scalbn` or `scalbln` is called. Otherwise, `scalbnf` or `scalblnf` is called, respectively.

### Parameters

| arg  |   | -  |   | floating-point value  |

| exp  |   | -  |   | integer value  |

### Return value

If no errors occur, `arg` multiplied by FLT_RADIX to the power of `exp` (arg×FLT_RADIXexp
) is returned.
若沒有發生錯誤，回傳 arg × FLT_RADIX^exp。
If a range error due to overflow occurs, `±HUGE_VAL`, `±HUGE_VALF`, or `±HUGE_VALL` is returned.
若因浮點溢位而發生值域錯誤，回傳 ±HUGE_VAL、±HUGE_VALF 或 ±HUGE_VALL。
If a range error due to underflow occurs, the correct result (after rounding) is returned.
若因浮點下溢而發生值域錯誤，回傳正確結果（經捨入後）。

### Error handling

Errors are reported as specified in math_errhandling.
錯誤會依照 math_errhandling 的規定回報。
If the implementation supports IEEE floating-point arithmetic (IEC 60559),
若實作支援 IEEE 浮點運算（IEC 60559）：

- Unless a range error occurs, FE_INEXACT is never raised (the result is exact).
除非發生值域錯誤，否則結果都是精確值，不會引發 FE_INEXACT。

- Unless a range error occurs, the current rounding mode is ignored.
除非發生值域錯誤，否則結果不受目前捨入模式影響。

- If `arg` is ±0, it is returned, unmodified.
若 arg 為 ±0，則原樣回傳。

- If `arg` is ±∞, it is returned, unmodified.
若 arg 為 ±∞，則原樣回傳。

- If `exp` is 0, then `arg` is returned, unmodified.
若 exp 為 0，則原樣回傳 arg。

- If `arg` is NaN, NaN is returned.
若 arg 為 NaN，回傳 NaN。

### Notes

On binary systems (where FLT_RADIX is `2`), `scalbn` is equivalent to ldexp.
在二進位系統（FLT_RADIX 為 2）中，scalbn 等同於 ldexp。
Although `scalbn` and `scalbln` are specified to perform the operation efficiently, on many implementations they are less efficient than multiplication or division by a power of two using arithmetic operators.
雖然標準要求 scalbn 和 scalbln 能有效率地執行這項運算，但在許多實作中，使用算術運運算元乘除 2 的冪次反而更有效率。
The `scalbln` function is provided because the factor required to scale from the smallest positive floating-point value to the largest finite one may be greater than `32767`, the standard-guaranteed INT_MAX. In particular, for the 80-bit `long double`, the factor is `32828`.
提供 scalbln 的原因是，將最小正浮點值放大至最大有限值所需的指數可能大於標準保證的 INT_MAX 最小值 32767。以 80 位元 long double 為例，所需指數為 32828。

### Example

Run this code

```c
#include <errno.h> #include <fenv.h> #include <float.h> #include <math.h> #include <stdio.h> // #pragma STDC FENV_ACCESS ON int main(void) {  printf("scalbn(7, -4) = %f\n", scalbn(7, -4));  printf("scalbn(1, -1074) = %g (minimum positive subnormal double)\n",  scalbn(1, -1074));  printf("scalbn(nextafter(1,0), 1024) = %g (largest finite double)\n",  scalbn(nextafter(1,0), 1024));  // special values  printf("scalbn(-0, 10) = %f\n", scalbn(-0.0, 10));  printf("scalbn(-Inf, -1) = %f\n", scalbn(-INFINITY, -1));  // error handling  errno = 0; feclearexcept(FE_ALL_EXCEPT);  printf("scalbn(1, 1024) = %f\n", scalbn(1, 1024));  if (errno == ERANGE)  perror(" errno == ERANGE");  if (fetestexcept(FE_OVERFLOW))  puts(" FE_OVERFLOW raised"); }
```

Possible output:
可能的輸出：

```c
scalbn(7, -4) = 0.437500 scalbn(1, -1074) = 4.94066e-324 (minimum positive subnormal double) scalbn(nextafter(1,0), 1024) = 1.79769e+308 (largest finite double) scalbn(-0, 10) = -0.000000 scalbn(-Inf, -1) = -inf scalbn(1, 1024) = inf errno == ERANGE: Numerical result out of range FE_OVERFLOW raised
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.6.13 The scalbn functions (p: TBD)
7.12.6.13 scalbn 函式（p: TBD）
7.12.6.13 scalbn 函式（p: TBD）

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.3.13 The scalbn functions (p: TBD)
F.10.3.13 scalbn 函式（p: TBD）
F.10.3.13 scalbn 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.6.13 The scalbn functions (p: TBD)
7.12.6.13 scalbn 函式（p: TBD）
7.12.6.13 scalbn 函式（p: TBD）

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.3.13 The scalbn functions (p: TBD)
F.10.3.13 scalbn 函式（p: TBD）
F.10.3.13 scalbn 函式（p: TBD）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.6.13 The scalbn functions (p: 247)
7.12.6.13 scalbn 函式（p: 247）
7.12.6.13 scalbn 函式（p: 247）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.3.13 The scalbn functions (p: 523)
F.10.3.13 scalbn 函式（p: 523）
F.10.3.13 scalbn 函式（p: 523）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.6.13 The scalbn functions (p: 228)
7.12.6.13 scalbn 函式（p: 228）
7.12.6.13 scalbn 函式（p: 228）

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- F.9.3.13 The scalbn functions (p: 460)
F.9.3.13 scalbn 函式（p: 460）
F.9.3.13 scalbn 函式（p: 460）

### See also

frexpfrexpffrexpl
(C99)(C99)
|   | breaks a number into significand and a power of 2
(function)   |

ldexpldexpfldexpl
(C99)(C99)
|   | multiplies a number by 2 raised to a power
(function)   |

C++ documentation for scalbn

---
來源頁路徑：`en.cppreference.com/c/numeric/math/scalbn.html`

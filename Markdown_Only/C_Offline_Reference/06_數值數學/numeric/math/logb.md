# logb, logbf, logbl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
float logbf( float arg );
```
|   |  (1)  |   |  (since C99)  |

```c
double logb( double arg );
```
|   |  (2)  |   |  (since C99)  |

```c
long double logbl( long double arg );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define logb( arg )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Extracts the value of the unbiased radix-independent exponent from the floating-point argument `arg`, and returns it as a floating-point value.

4) Type-generic macros: If `arg` has type `long double`, `logbl` is called. Otherwise, if `arg` has integer type or the type `double`, `logb` is called. Otherwise, `logbf` is called.

Formally, the unbiased exponent is the signed integral part of logr|arg| (returned by this function as a floating-point value), for non-zero `arg`, where `r` is FLT_RADIX. If `arg` is subnormal, it is treated as though it was normalized.
正式定義中，對非零 arg ，無偏指數是 log r |arg| 的有符號整數部分（本函式將其作為浮點值傳回），其中 r 為 FLT_RADIX 。如果 arg 是非規格化的，則將其視為已規格化。

### Parameters

| arg  |   | -  |   | floating-point value  |

### Return value

If no errors occur, the unbiased exponent of `arg` is returned as a signed floating-point value.
如果未發生錯誤，則以有符號浮點值的形式傳回 arg 的無偏指數。
If a domain error occurs, an implementation-defined value is returned.
若發生定義域錯誤，回傳由實作定義的值。
If a pole error occurs, -HUGE_VAL, `-HUGE_VALF`, or `-HUGE_VALL` is returned.
若發生極點錯誤，回傳 -HUGE_VAL、-HUGE_VALF 或 -HUGE_VALL。

### Error handling

Errors are reported as specified in math_errhandling.
錯誤會依照 math_errhandling 的規定回報。
Domain or range error may occur if `arg` is zero.
如果 arg 為零，可能發生定義域錯誤或值域錯誤。
If the implementation supports IEEE floating-point arithmetic (IEC 60559),
若實作支援 IEEE 浮點運算（IEC 60559）：

- If `arg` is ±0, -∞ is returned and FE_DIVBYZERO is raised.
如果 arg 為 ±0，則傳回 -∞ 並引發 FE_DIVBYZERO。

- If `arg` is ±∞, +∞ is returned.
如果 arg 為 ±∞，則傳回 +∞。

- If `arg` is NaN, NaN is returned.
如果 arg 為 NaN，則傳回 NaN。

- In all other cases, the result is exact (FE_INEXACT is never raised) and the current rounding mode is ignored.
在所有其他情況下，結果都是精確的（絕不會引發 FE_INEXACT ），且目前舍入模式被忽略。

### Notes

POSIX requires that a pole error occurs if `arg` is ±0.
POSIX 要求當 arg 為 ±0 時發生極點錯誤。
The value of the exponent returned by `logb` is always `1` less than the exponent returned by frexp because of the different normalization requirements: for the exponent `e` returned by `logb`, |arg*r-e
| is between `1` and `r` (typically between `1` and `2`), but for the exponent `e` returned by frexp, |arg*2-e
| is between `0.5` and `1`.
由於規範化要求不同，logb 傳回的指數總是比 frexp 傳回的指數小 1：對 logb 傳回的指數 e ，|arg*r -e | 介於 1 和 r 之間（通常介於 1 和 2 之間）；而對 frexp 傳回的指數 e ，|arg*2 -e | 介於 0.5 和 1 之間。

### Example

Compares different floating-point decomposition functions.
比較不同的浮點分解函式。
Run this code

```c
#include <fenv.h> #include <float.h> #include <math.h> #include <stdio.h> // #pragma STDC FENV_ACCESS ON int main(void) {  double f = 123.45;  printf("Given the number %.2f or %a in hex,\n", f, f);  double f3;  double f2 = modf(f, &f3);  printf("modf() makes %.0f + %.2f\n", f3, f2);  int i;  f2 = frexp(f, &i);  printf("frexp() makes %f * 2^%d\n", f2, i);  i = logb(f);  printf("logb()/logb() make %f * %d^%d\n", f/scalbn(1.0, i), FLT_RADIX, i);  // error handling  feclearexcept(FE_ALL_EXCEPT);  printf("logb(0) = %f\n", logb(0));  if (fetestexcept(FE_DIVBYZERO))  puts(" FE_DIVBYZERO raised"); }
```

Possible output:
可能的輸出：

```c
Given the number 123.45 or 0x1.edccccccccccdp+6 in hex, modf() makes 123 + 0.45 frexp() makes 0.964453 * 2^7 logb()/logb() make 1.928906 * 2^6 logb(0) = -Inf FE_DIVBYZERO raised
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.6.11 The logb functions (p: TBD)
7.12.6.11 logb 函式（p: TBD）
7.12.6.11 logb 函式（p: TBD）

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.3.11 The logb functions (p: TBD)
F.10.3.11 logb 函式（p: TBD）
F.10.3.11 logb 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.6.11 The logb functions (p: 179-180)
7.12.6.11 logb 函式（p: 179-180）
7.12.6.11 logb 函式（p: 179-180）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.3.11 The logb functions (p: 381)
F.10.3.11 logb 函式（p: 381）
F.10.3.11 logb 函式（p: 381）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.6.11 The logb functions (p: 246)
7.12.6.11 logb 函式（p: 246）
7.12.6.11 logb 函式（p: 246）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.3.11 The logb functions (p: 522)
F.10.3.11 logb 函式（p: 522）
F.10.3.11 logb 函式（p: 522）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.6.11 The logb functions (p: 227)
7.12.6.11 logb 函式（p: 227）
7.12.6.11 logb 函式（p: 227）

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- F.9.3.11 The logb functions (p: 459)
F.9.3.11 logb 函式（p: 459）
F.9.3.11 logb 函式（p: 459）

### See also

frexpfrexpffrexpl
(C99)(C99)
|   | breaks a number into significand and a power of 2
(function)   |

ilogbilogbfilogbl
(C99)(C99)(C99)
|   | extracts exponent of the given number
(function)   |

scalbnscalbnfscalbnlscalblnscalblnfscalblnl
(C99)(C99)(C99)(C99)(C99)(C99)
|   | computes efficiently a number times FLT_RADIX raised to a power
(function)   |

C++ documentation for logb

---
來源頁路徑：`en.cppreference.com/c/numeric/math/logb.html`

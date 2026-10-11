# log1p, log1pf, log1pl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
float log1pf( float arg );
```
|   |  (1)  |   |  (since C99)  |

```c
double log1p( double arg );
```
|   |  (2)  |   |  (since C99)  |

```c
long double log1pl( long double arg );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define log1p( arg )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Computes the natural (base `e`) logarithm of `1 + arg`. This function is more precise than the expression `log(1 + arg)` if `arg` is close to zero.

4) Type-generic macro: If `arg` has type `long double`, `log1pl` is called. Otherwise, if `arg` has integer type or the type `double`, `log1p` is called. Otherwise, `log1pf` is called.

### Parameters

| arg  |   | -  |   | floating-point value  |

### Return value

If no errors occur ln(1 + arg) is returned.
如果未發生錯誤，則傳回 ln(1 + arg)。
If a domain error occurs, an implementation-defined value is returned (NaN where supported).
若發生定義域錯誤，回傳由實作定義的值（若支援則回傳 NaN）。
If a pole error occurs, `-HUGE_VAL`, `-HUGE_VALF`, or `-HUGE_VALL` is returned.
如果發生極點錯誤，則傳回 - HUGE_VAL 、-HUGE_VALF 或 -HUGE_VALL。
If a range error occurs due to underflow, the correct result (after rounding) is returned.
若因浮點下溢而發生值域錯誤，回傳正確結果（經捨入後）。

### Error handling

Errors are reported as specified in math_errhandling.
錯誤會依照 math_errhandling 的規定回報。
Domain error occurs if `arg` is less than -1.
如果 arg 小於 -1 ，則發生定義域錯誤。
Pole error may occur if `arg` is -1.
如果 arg 為 -1 ，可能發生極點錯誤。
If the implementation supports IEEE floating-point arithmetic (IEC 60559),
若實作支援 IEEE 浮點運算（IEC 60559）：

- If the argument is ±0, it is returned unmodified.
如果參數為 ±0，則原樣傳回。

- If the argument is -1, -∞ is returned and FE_DIVBYZERO is raised.
如果參數為 -1，則傳回 -∞ 並引發 FE_DIVBYZERO。

- If the argument is less than -1, NaN is returned and FE_INVALID is raised.
如果參數小於 -1，則傳回 NaN 並引發 FE_INVALID。

- If the argument is +∞, +∞ is returned.
如果參數為 +∞，則傳回 +∞。

- If the argument is NaN, NaN is returned.
若參數為 NaN，回傳 NaN。

### Notes

The functions expm1 and `log1p` are useful for financial calculations, for example, when calculating small daily interest rates: (1+x)n
-1 can be expressed as `expm1(n * log1p(x))`. These functions also simplify writing accurate inverse hyperbolic functions.
函式 expm1 和 log1p 對財務計算很有用，例如在計算微小的日利率時：(1+x) n -1 可以表示為 expm1 ( n * log1p ( x )) 。這些函式還簡化了精確反雙曲函式的編寫。

### Example

Run this code

```c
#include <errno.h> #include <fenv.h> #include <float.h> #include <math.h> #include <stdio.h> // #pragma STDC FENV_ACCESS ON int main(void) {  printf("log1p(0) = %f\n", log1p(0));  printf("Interest earned in 2 days on $100, compounded daily at 1%%\n"  " on a 30/360 calendar = %f\n",  100*expm1(2*log1p(0.01/360)));  printf("log(1+1e-16) = %g, but log1p(1e-16) = %g\n",  log(1+1e-16), log1p(1e-16));  // special values  printf("log1p(-0) = %f\n", log1p(-0.0));  printf("log1p(+Inf) = %f\n", log1p(INFINITY));  // error handling  errno = 0; feclearexcept(FE_ALL_EXCEPT);  printf("log1p(-1) = %f\n", log1p(-1));  if (errno == ERANGE)  perror(" errno == ERANGE");  if (fetestexcept(FE_DIVBYZERO))  puts(" FE_DIVBYZERO raised"); }
```

Possible output:
可能的輸出：

```c
log1p(0) = 0.000000 Interest earned in 2 days on $100, compounded daily at 1% on a 30/360 calendar = 0.005556 log(1+1e-16) = 0, but log1p(1e-16) = 1e-16 log1p(-0) = -0.000000 log1p(+Inf) = Inf log1p(-1) = -Inf errno == ERANGE: Result too large FE_DIVBYZERO raised
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.6.9 The log1p functions (p: TBD)
7.12.6.9 log1p 函式（p: TBD）
7.12.6.9 log1p 函式（p: TBD）

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.3.9 The log1p functions (p: TBD)
F.10.3.9 log1p 函式（p: TBD）
F.10.3.9 log1p 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.6.9 The log1p functions (p: TBD)
7.12.6.9 log1p 函式（p: TBD）
7.12.6.9 log1p 函式（p: TBD）

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.3.9 The log1p functions (p: TBD)
F.10.3.9 log1p 函式（p: TBD）
F.10.3.9 log1p 函式（p: TBD）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.6.9 The log1p functions (p: 245)
7.12.6.9 log1p 函式（p: 245）
7.12.6.9 log1p 函式（p: 245）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.3.9 The log1p functions (p: 522)
F.10.3.9 log1p 函式（p: 522）
F.10.3.9 log1p 函式（p: 522）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.6.9 The log1p functions (p: 226)
7.12.6.9 log1p 函式（p: 226）
7.12.6.9 log1p 函式（p: 226）

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- F.9.3.9 The log1p functions (p: 459)
F.9.3.9 log1p 函式（p: 459）
F.9.3.9 log1p 函式（p: 459）

### See also

loglogflogl
(C99)(C99)
|   | computes natural (base-*e*) logarithm (lnxln⁡xln(x))
(function)   |

log10log10flog10l
(C99)(C99)
|   | computes common (base-*10*) logarithm (log10xlog10⁡xlog10(x))
(function)   |

log2log2flog2l
(C99)(C99)(C99)
|   | computes base-2 logarithm (log2xlog2⁡xlog2(x))
(function)   |

expm1expm1fexpm1l
(C99)(C99)(C99)
|   | computes *e* raised to the given power, minus one (ex−1ex−1e-1)
(function)   |

C++ documentation for log1p

---
來源頁路徑：`en.cppreference.com/c/numeric/math/log1p.html`

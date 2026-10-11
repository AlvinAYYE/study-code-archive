# exp, expf, expl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
float expf( float arg );
```
|   |  (1)  |   |  (since C99)  |

```c
double exp( double arg );
```
|   |  (2)  |   |   |

```c
long double expl( long double arg );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define exp( arg )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Computes e (Euler's number, `2.7182818...`) raised to the given power `arg`.

4) Type-generic macro: If `arg` has type `long double`, `expl` is called. Otherwise, if `arg` has integer type or the type `double`, `exp` is called. Otherwise, `expf` is called. If `arg` is complex or imaginary, then the macro invokes the corresponding complex function (`cexpf`, `cexp`, `cexpl`).

### Parameters

| arg  |   | -  |   | floating-point value  |

### Return value

If no errors occur, the base-*e* exponential of `arg` (earg
) is returned.
若沒有發生錯誤，回傳 e 的 arg 次方（e^arg）。
If a range error occurs due to overflow, +HUGE_VAL, `+HUGE_VALF`, or `+HUGE_VALL` is returned.
若因浮點溢位而發生值域錯誤，回傳 +HUGE_VAL、+HUGE_VALF 或 +HUGE_VALL。
If a range error occurs due to underflow, the correct result (after rounding) is returned.
若因浮點下溢而發生值域錯誤，回傳正確結果（經捨入後）。

### Error handling

Errors are reported as specified in math_errhandling.
錯誤會依照 math_errhandling 的規定回報。
If the implementation supports IEEE floating-point arithmetic (IEC 60559),
若實作支援 IEEE 浮點運算（IEC 60559）：

- If the argument is ±0, 1 is returned
若參數為 ±0，回傳 1。

- If the argument is -∞, +0 is returned
若參數為 -∞，回傳 +0。

- If the argument is +∞, +∞ is returned
若參數為 +∞，回傳 +∞。

- If the argument is NaN, NaN is returned
若參數為 NaN，回傳 NaN。

### Notes

For IEEE-compatible type `double`, overflow is guaranteed if 709.8 < arg, and underflow is guaranteed if arg < -708.4.
對符合 IEEE 標準的 double 型別而言，arg 大於 709.8 時一定會溢位；arg 小於 -708.4 時則一定會下溢。

### Example

Run this code

```c
#include <errno.h> #include <fenv.h> #include <float.h> #include <math.h> #include <stdio.h> // #pragma STDC FENV_ACCESS ON int main(void) {  printf("exp(1) = %f\n", exp(1));  printf("FV of $100, continuously compounded at 3%% for 1 year = %f\n",  100*exp(0.03));  // special values  printf("exp(-0) = %f\n", exp(-0.0));  printf("exp(-Inf) = %f\n", exp(-INFINITY));  //error handling  errno = 0; feclearexcept(FE_ALL_EXCEPT);  printf("exp(710) = %f\n", exp(710));  if (errno == ERANGE)  perror(" errno == ERANGE");  if (fetestexcept(FE_OVERFLOW))  puts(" FE_OVERFLOW raised"); }
```

Possible output:
可能的輸出：

```c
exp(1) = 2.718282 FV of $100, continuously compounded at 3% for 1 year = 103.045453 exp(-0) = 1.000000 exp(-Inf) = 0.000000 exp(710) = inf errno == ERANGE: Numerical result out of range FE_OVERFLOW raised
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.6.1 The exp functions (p: TBD)
7.12.6.1 exp 函式（p: TBD）
7.12.6.1 exp 函式（p: TBD）

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.3.1 The exp functions (p: TBD)
F.10.3.1 exp 函式（p: TBD）
F.10.3.1 exp 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.6.1 The exp functions (p: 175)
7.12.6.1 exp 函式（p: 175）
7.12.6.1 exp 函式（p: 175）

- 7.25 Type-generic math <tgmath.h> (p: 272-273)
7.25 型別通用數學 <tgmath.h> (p: 272-273)
7.25 型別通用數學 <tgmath.h> (p: 272-273)

- F.10.3.1 The exp functions (p: 379)
F.10.3.1 exp 函式（p: 379）
F.10.3.1 exp 函式（p: 379）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.6.1 The exp functions (p: 242)
7.12.6.1 exp 函式（p: 242）
7.12.6.1 exp 函式（p: 242）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.3.1 The exp functions (p: 520)
F.10.3.1 exp 函式（p: 520）
F.10.3.1 exp 函式（p: 520）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.6.1 The exp functions (p: 223)
7.12.6.1 exp 函式（p: 223）
7.12.6.1 exp 函式（p: 223）

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- F.9.3.1 The exp functions (p: 458)
F.9.3.1 exp 函式（p: 458）
F.9.3.1 exp 函式（p: 458）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.5.4.1 The exp function
4.5.4.1 exp 函式
4.5.4.1 exp 函式

### See also

exp2exp2fexp2l
(C99)(C99)(C99)
|   | computes *2* raised to the given power (2x2x2)
(function)   |

expm1expm1fexpm1l
(C99)(C99)(C99)
|   | computes *e* raised to the given power, minus one (ex−1ex−1e-1)
(function)   |

loglogflogl
(C99)(C99)
|   | computes natural (base-*e*) logarithm (lnxln⁡xln(x))
(function)   |

cexpcexpfcexpl
(C99)(C99)(C99)
|   | computes the complex base-e exponential
(function)   |

C++ documentation for exp

---
來源頁路徑：`en.cppreference.com/c/numeric/math/exp.html`

# expm1, expm1f, expm1l

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
float expm1f( float arg );
```
|   |  (1)  |   |  (since C99)  |

```c
double expm1( double arg );
```
|   |  (2)  |   |  (since C99)  |

```c
long double expm1l( long double arg );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define expm1( arg )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Computes the *e* (Euler's number, `2.7182818`) raised to the given power `arg`, minus `1.0`. This function is more accurate than the expression `exp(arg)-1.0` if `arg` is close to zero.

4) Type-generic macro: If `arg` has type `long double`, `expm1l` is called. Otherwise, if `arg` has integer type or the type `double`, `expm1` is called. Otherwise, `expm1f` is called.

### Parameters

| arg  |   | -  |   | floating-point value  |

### Return value

If no errors occur earg
-1 is returned.
若未發生錯誤，則傳回 e arg -1。
If a range error due to overflow occurs, +HUGE_VAL, `+HUGE_VALF`, or `+HUGE_VALL` is returned.
如果因上溢發生值域錯誤，則傳回 +HUGE_VAL 、 +HUGE_VALF 或 +HUGE_VALL 。
If a range error occurs due to underflow, the correct result (after rounding) is returned.
若因浮點下溢而發生值域錯誤，回傳正確結果（經捨入後）。

### Error handling

Errors are reported as specified in math_errhandling.
錯誤會依照 math_errhandling 的規定回報。
If the implementation supports IEEE floating-point arithmetic (IEC 60559),
若實作支援 IEEE 浮點運算（IEC 60559）：

- If the argument is ±0, it is returned, unmodified
如果參數為 ±0，則原樣傳回

- If the argument is -∞, -1 is returned
如果參數為 -∞，則傳回 -1

- If the argument is +∞, +∞ is returned
如果參數為 +∞，則傳回 +∞

- If the argument is NaN, NaN is returned
如果參數為 NaN，則傳回 NaN

### Notes

The functions `expm1` and log1p are useful for financial calculations, for example, when calculating small daily interest rates: (1+x)n
-1 can be expressed as `expm1(n * log1p(x))`. These functions also simplify writing accurate inverse hyperbolic functions.
函式 expm1 和 log1p 對財務計算很有用，例如在計算微小的日利率時：(1+x) n -1 可以表示為 expm1 ( n * log1p ( x )) 。這些函式還簡化了精確反雙曲函式的編寫。
For IEEE-compatible type `double`, overflow is guaranteed if 709.8 < arg.
對於相容 IEEE 的型別 double，若 709.8 < arg 則必然發生溢位。

### Example

Run this code

```c
#include <errno.h> #include <fenv.h> #include <float.h> #include <math.h> #include <stdio.h> // #pragma STDC FENV_ACCESS ON int main(void) {  printf("expm1(1) = %f\n", expm1(1));  printf("Interest earned in 2 days on $100, compounded daily at 1%%\n"  " on a 30/360 calendar = %f\n",  100*expm1(2*log1p(0.01/360)));  printf("exp(1e-16)-1 = %g, but expm1(1e-16) = %g\n",  exp(1e-16)-1, expm1(1e-16));  // special values  printf("expm1(-0) = %f\n", expm1(-0.0));  printf("expm1(-Inf) = %f\n", expm1(-INFINITY));  //error handling  errno = 0; feclearexcept(FE_ALL_EXCEPT);  printf("expm1(710) = %f\n", expm1(710));  if (errno == ERANGE)  perror(" errno == ERANGE");  if (fetestexcept(FE_OVERFLOW))  puts(" FE_OVERFLOW raised"); }
```

Possible output:
可能的輸出：

```c
expm1(1) = 1.718282 Interest earned in 2 days on $100, compounded daily at 1% on a 30/360 calendar = 0.005556 exp(1e-16)-1 = 0, but expm1(1e-16) = 1e-16 expm1(-0) = -0.000000 expm1(-Inf) = -1.000000 expm1(710) = inf errno == ERANGE: Result too large FE_OVERFLOW raised
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.6.3 The expm1 functions (p: TBD)
7.12.6.3 expm1 函式 (p: TBD)
7.12.6.3 expm1 函式 (p: TBD)

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.3.3 The expm1 functions (p: TBD)
F.10.3.3 expm1 函式 (p: TBD)
F.10.3.3 expm1 函式 (p: TBD)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.6.3 The expm1 functions (p: 177)
7.12.6.3 expm1 函式 (p: 177)
7.12.6.3 expm1 函式 (p: 177)

- 7.25 Type-generic math <tgmath.h> (p: 272-273)
7.25 型別通用數學 <tgmath.h> (p: 272-273)
7.25 型別通用數學 <tgmath.h> (p: 272-273)

- F.10.3.3 The expm1 functions (p: 379)
F.10.3.3 expm1 函式 (p: 379)
F.10.3.3 expm1 函式 (p: 379)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.6.3 The expm1 functions (p: 243)
7.12.6.3 expm1 函式 (p: 243)
7.12.6.3 expm1 函式 (p: 243)

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.3.3 The expm1 functions (p: 521)
F.10.3.3 expm1 函式 (p: 521)
F.10.3.3 expm1 函式 (p: 521)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.6.3 The expm1 functions (p: 223-224)
7.12.6.3 expm1 函式 (p: 223-224)
7.12.6.3 expm1 函式 (p: 223-224)

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- F.9.3.3 The expm1 functions (p: 458)
F.9.3.3 expm1 函式 (p: 458)
F.9.3.3 expm1 函式 (p: 458)

### See also

expexpfexpl
(C99)(C99)
|   | computes *e* raised to the given power (exexe)
(function)   |

exp2exp2fexp2l
(C99)(C99)(C99)
|   | computes *2* raised to the given power (2x2x2)
(function)   |

log1plog1pflog1pl
(C99)(C99)(C99)
|   | computes natural (base-*e*) logarithm of 1 plus the given number (ln(1+x)ln⁡(1+x)ln(1+x))
(function)   |

C++ documentation for expm1

---
來源頁路徑：`en.cppreference.com/c/numeric/math/expm1.html`

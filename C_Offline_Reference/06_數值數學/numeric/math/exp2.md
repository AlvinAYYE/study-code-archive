# exp2, exp2f, exp2l

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
float exp2f( float n );
```
|   |  (1)  |   |  (since C99)  |

```c
double exp2( double n );
```
|   |  (2)  |   |  (since C99)  |

```c
long double exp2l( long double n );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define exp2( n )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Computes 2 raised to the given power `n`.

4) Type-generic macro: If `n` has type `long double`, `exp2l` is called. Otherwise, if `n` has integer type or the type `double`, `exp2` is called. Otherwise, `exp2f` is called.

### Parameters

| n  |   | -  |   | floating-point value  |

### Return value

If no errors occur, the base-*2* exponential of `n` (2n
) is returned.
如果未發生錯誤，則傳回 n 的以 2 為底的指數（ 2 n ）。
If a range error due to overflow occurs, +HUGE_VAL, `+HUGE_VALF`, or `+HUGE_VALL` is returned.
如果因上溢發生值域錯誤，則傳回 +HUGE_VAL 、 +HUGE_VALF 或 +HUGE_VALL 。
If a range error occurs due to underflow, the correct result (after rounding) is returned.
若因浮點下溢而發生值域錯誤，回傳正確結果（經捨入後）。

### Error handling

Errors are reported as specified in math_errhandling.
錯誤會依照 math_errhandling 的規定回報。
If the implementation supports IEEE floating-point arithmetic (IEC 60559),
若實作支援 IEEE 浮點運算（IEC 60559）：

- If the argument is ±0, 1 is returned
如果參數為 ±0，則傳回 1

- If the argument is -∞, +0 is returned
如果參數為 -∞，則傳回 +0

- If the argument is +∞, +∞ is returned
如果參數為 +∞，則傳回 +∞

- If the argument is NaN, NaN is returned
如果參數為 NaN，則傳回 NaN

### Example

Run this code

```c
#include <errno.h> #include <fenv.h> #include <float.h> #include <math.h> #include <stdio.h> // #pragma STDC FENV_ACCESS ON int main(void) {  printf("exp2(5) = %f\n", exp2(5));  printf("exp2(0.5) = %f\n", exp2(0.5));  printf("exp2(-4) = %f\n", exp2(-4));  // special values  printf("exp2(-0.9) = %f\n", exp2(-0.9));  printf("exp2(-Inf) = %f\n", exp2(-INFINITY));  //error handling  errno = 0; feclearexcept(FE_ALL_EXCEPT);  printf("exp2(1024) = %f\n", exp2(1024));  if (errno == ERANGE)  perror(" errno == ERANGE");  if (fetestexcept(FE_OVERFLOW))  puts(" FE_OVERFLOW raised"); }
```

Possible output:
可能的輸出：

```c
exp2(5) = 32.000000 exp2(0.5) = 1.414214 exp2(-4) = 0.062500 exp2(-0.9) = 0.535887 exp2(-Inf) = 0.000000 exp2(1024) = Inf errno == ERANGE: Result too large FE_OVERFLOW raised
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.6.2 The exp2 functions (p: TBD)
7.12.6.2 exp2 函式（p: TBD）
7.12.6.2 exp2 函式（p: TBD）

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.3.2 The exp2 functions (p: TBD)
F.10.3.2 exp2 函式（p: TBD）
F.10.3.2 exp2 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.6.2 The exp2 functions (p: 177)
7.12.6.2 exp2 函式（p: 177）
7.12.6.2 exp2 函式（p: 177）

- 7.25 Type-generic math <tgmath.h> (p: 272-273)
7.25 型別通用數學 <tgmath.h> (p: 272-273)
7.25 型別通用數學 <tgmath.h> (p: 272-273)

- F.10.3.2 The exp2 functions (p: 379)
F.10.3.2 exp2 函式（p: 379）
F.10.3.2 exp2 函式（p: 379）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.6.2 The exp2 functions (p: 242-243)
7.12.6.2 exp2 函式（p: 242-243）
7.12.6.2 exp2 函式（p: 242-243）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.3.2 The exp2 functions (p: 521)
F.10.3.2 exp2 函式（p: 521）
F.10.3.2 exp2 函式（p: 521）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.6.2 The exp2 functions (p: 223)
7.12.6.2 exp2 函式（p: 223）
7.12.6.2 exp2 函式（p: 223）

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- F.9.3.2 The exp2 functions (p: 458)
F.9.3.2 exp2 函式（p: 458）
F.9.3.2 exp2 函式（p: 458）

### See also

expexpfexpl
(C99)(C99)
|   | computes *e* raised to the given power (exexe)
(function)   |

expm1expm1fexpm1l
(C99)(C99)(C99)
|   | computes *e* raised to the given power, minus one (ex−1ex−1e-1)
(function)   |

log2log2flog2l
(C99)(C99)(C99)
|   | computes base-2 logarithm (log2xlog2⁡xlog2(x))
(function)   |

C++ documentation for exp2

---
來源頁路徑：`en.cppreference.com/c/numeric/math/exp2.html`

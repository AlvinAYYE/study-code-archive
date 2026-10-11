# cosh, coshf, coshl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
float coshf( float arg );
```
|   |  (1)  |   |  (since C99)  |

```c
double cosh( double arg );
```
|   |  (2)  |   |   |

```c
long double coshl( long double arg );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define cosh( arg )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Computes the hyperbolic cosine of `arg`.

4) Type-generic macro: If the argument has type `long double`, `coshl` is called. Otherwise, if the argument has integer type or the type `double`, `cosh` is called. Otherwise, `coshf` is called. If the argument is complex, then the macro invokes the corresponding complex function (`ccoshf`, `ccosh`, `ccoshl`).

### Parameters

| arg  |   | -  |   | floating-point value representing a hyperbolic angle  |

### Return value
If no errors occur, the hyperbolic cosine of `arg` (cosh(arg), or
如果未發生錯誤，則傳回 arg 的雙曲餘弦（ cosh(arg) ，或
earg
+e-arg

2 |
) is returned.
If a range error due to overflow occurs, +HUGE_VAL, `+HUGE_VALF`, or `+HUGE_VALL` is returned.
如果因上溢發生值域錯誤，則傳回 +HUGE_VAL 、 +HUGE_VALF 或 +HUGE_VALL 。

### Error handling

Errors are reported as specified in math_errhandling.
錯誤會依照 math_errhandling 的規定回報。
If the implementation supports IEEE floating-point arithmetic (IEC 60559),
若實作支援 IEEE 浮點運算（IEC 60559）：

- if the argument is ±0, 1 is returned
如果參數為 ±0，則傳回 1

- If the argument is ±∞, +∞ is returned
如果參數為 ±∞，則傳回 +∞

- if the argument is NaN, NaN is returned
如果參數為 NaN，則傳回 NaN

### Notes

For the IEEE-compatible type `double`, if |arg| > 710.5, then `cosh(arg)` overflows.
對於與 IEEE 相容的型別 double ，如果 |arg| > 710.5，則 cosh(arg) 會發生上溢。

### Example

Run this code

```c
#include <errno.h> #include <fenv.h> #include <math.h> #include <stdio.h> // #pragma STDC FENV_ACCESS ON int main(void) {  printf("cosh(1) = %f\ncosh(-1)= %f\n", cosh(1), cosh(-1));  printf("log(sinh(1) + cosh(1))=%f\n", log(sinh(1) + cosh(1)));  // special values  printf("cosh(+0) = %f\ncosh(-0) = %f\n", cosh(0.0), cosh(-0.0));  // error handling  errno = 0;  feclearexcept(FE_ALL_EXCEPT);  printf("cosh(710.5) = %f\n", cosh(710.5));  if (errno == ERANGE)  perror(" errno == ERANGE");  if (fetestexcept(FE_OVERFLOW))  puts(" FE_OVERFLOW raised"); }
```

Possible output:
可能的輸出：

```c
cosh(1) = 1.543081 cosh(-1)= 1.543081 log(sinh(1) + cosh(1))=1.000000 cosh(+0) = 1.000000 cosh(-0) = 1.000000 cosh(710.5) = inf errno == ERANGE: Numerical result out of range FE_OVERFLOW raised
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.5.4 The cosh functions (p: TBD)
7.12.5.4 cosh 函式（p: TBD）
7.12.5.4 cosh 函式（p: TBD）

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.2.4 The cosh functions (p: TBD)
F.10.2.4 cosh 函式（p: TBD）
F.10.2.4 cosh 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.5.4 The cosh functions (p: 176)
7.12.5.4 cosh 函式（p: 176）
7.12.5.4 cosh 函式（p: 176）

- 7.25 Type-generic math <tgmath.h> (p: 272-273)
7.25 型別通用數學 <tgmath.h> (p: 272-273)
7.25 型別通用數學 <tgmath.h> (p: 272-273)

- F.10.2.4 The cosh functions (p: 379)
F.10.2.4 cosh 函式（p: 379）
F.10.2.4 cosh 函式（p: 379）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.5.4 The cosh functions (p: 241)
7.12.5.4 cosh 函式（p: 241）
7.12.5.4 cosh 函式（p: 241）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.2.4 The cosh functions (p: 520)
F.10.2.4 cosh 函式（p: 520）
F.10.2.4 cosh 函式（p: 520）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.5.4 The cosh functions (p: 222)
7.12.5.4 cosh 函式（p: 222）
7.12.5.4 cosh 函式（p: 222）

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- F.9.2.4 The cosh functions (p: 457)
F.9.2.4 cosh 函式（p: 457）
F.9.2.4 cosh 函式（p: 457）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.5.3.1 The cosh function
4.5.3.1 cosh 函式
4.5.3.1 cosh 函式

### See also

sinhsinhfsinhl
(C99)(C99)
|   | computes hyperbolic sine (sinhxsinh⁡xsinh(x))
(function)   |

tanhtanhftanhl
(C99)(C99)
|   | computes hyperbolic tangent (tanhxtanh⁡xtanh(x))
(function)   |

acoshacoshfacoshl
(C99)(C99)(C99)
|   | computes inverse hyperbolic cosine (arcoshxarcosh⁡xarcosh(x))
(function)   |

ccoshccoshfccoshl
(C99)(C99)(C99)
|   | computes the complex hyperbolic cosine
(function)   |

C++ documentation for cosh

---
來源頁路徑：`en.cppreference.com/c/numeric/math/cosh.html`

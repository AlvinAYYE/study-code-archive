# log, logf, logl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
float logf( float arg );
```
|   |  (1)  |   |  (since C99)  |

```c
double log( double arg );
```
|   |  (2)  |   |   |

```c
long double logl( long double arg );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define log( arg )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Computes the natural (base *e*) logarithm of `arg`.

4) Type-generic macro: If `arg` has type `long double`, `logl` is called. Otherwise, if `arg` has integer type or the type `double`, `log` is called. Otherwise, `logf` is called. If `arg` is complex or imaginary, then the macro invokes the corresponding complex function (`clogf`, `clog`, `clogl`).

### Parameters

| arg  |   | -  |   | floating-point value  |

### Return value

If no errors occur, the natural (base-*e*) logarithm of `arg` (ln(arg) or loge(arg)) is returned.
若沒有發生錯誤，回傳 arg 的自然對數（以 e 為底），也就是 ln(arg) 或 logₑ(arg)。
If a domain error occurs, an implementation-defined value is returned (NaN where supported).
若發生定義域錯誤，回傳由實作定義的值（若支援則回傳 NaN）。
If a pole error occurs, -HUGE_VAL, `-HUGE_VALF`, or `-HUGE_VALL` is returned.
若發生極點錯誤，回傳 -HUGE_VAL、-HUGE_VALF 或 -HUGE_VALL。

### Error handling

Errors are reported as specified in math_errhandling.
錯誤會依照 math_errhandling 的規定回報。
Domain error occurs if `arg` is less than zero.
若 arg 小於零，會發生定義域錯誤。
Pole error may occur if `arg` is zero.
若 arg 為零，可能會發生極點錯誤。
If the implementation supports IEEE floating-point arithmetic (IEC 60559),
若實作支援 IEEE 浮點運算（IEC 60559）：

- If the argument is ±0, -∞ is returned and FE_DIVBYZERO is raised.
若參數為 ±0，回傳 -∞ 並引發 FE_DIVBYZERO。

- If the argument is 1, +0 is returned
若參數為 1，回傳 +0。

- If the argument is negative, NaN is returned and FE_INVALID is raised.
若參數為負數，回傳 NaN 並引發 FE_INVALID。

- If the argument is +∞, +∞ is returned
若參數為 +∞，回傳 +∞。

- If the argument is NaN, NaN is returned.
若參數為 NaN，回傳 NaN。

### Example

Run this code

```c
#include <errno.h> #include <fenv.h> #include <float.h> #include <math.h> #include <stdio.h> // #pragma STDC FENV_ACCESS ON int main(void) {  printf("log(1) = %f\n", log(1));  printf("base-5 logarithm of 125 = %f\n", log(125) / log(5));    // special values  printf("log(1) = %f\n", log(1));  printf("log(+Inf) = %f\n", log(INFINITY));    // error handling  errno = 0; feclearexcept(FE_ALL_EXCEPT);  printf("log(0) = %f\n", log(0));  if (errno == ERANGE)  perror(" errno == ERANGE");  if (fetestexcept(FE_DIVBYZERO))  puts(" FE_DIVBYZERO raised"); }
```

Output:

```c
log(1) = 0.000000 base-5 logarithm of 125 = 3.000000 log(1) = 0.000000 log(+Inf) = inf log(0) = -inf errno == ERANGE: Numerical result out of range FE_DIVBYZERO raised
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.6.7 The log functions (p: TBD)
7.12.6.7 log 函式 (p: TBD)
7.12.6.7 log 函式 (p: TBD)

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.3.7 The log functions (p: TBD)
F.10.3.7 log 函式 (p: TBD)
F.10.3.7 log 函式 (p: TBD)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.6.7 The log functions (p: 178-179)
7.12.6.7 log 函式 (p: 178-179)
7.12.6.7 log 函式 (p: 178-179)

- 7.25 Type-generic math <tgmath.h> (p: 272-273)
7.25 型別通用數學 <tgmath.h> (p: 272-273)
7.25 型別通用數學 <tgmath.h> (p: 272-273)

- F.10.3.7 The log functions (p: 380)
F.10.3.7 log 函式 (p: 380)
F.10.3.7 log 函式 (p: 380)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.6.7 The log functions (p: 244-245)
7.12.6.7 log 函式 (p: 244-245)
7.12.6.7 log 函式 (p: 244-245)

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.3.7 The log functions (p: 522)
F.10.3.7 log 函式 (p: 522)
F.10.3.7 log 函式 (p: 522)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.6.7 The log functions (p: 225)
7.12.6.7 log 函式 (p: 225)
7.12.6.7 log 函式 (p: 225)

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- F.9.3.7 The log functions (p: 459)
F.9.3.7 log 函式 (p: 459)
F.9.3.7 log 函式 (p: 459)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.5.4.4 The log function
4.5.4.4 log 函式
4.5.4.4 log 函式

### See also

log10log10flog10l
(C99)(C99)
|   | computes common (base-*10*) logarithm (log10xlog10⁡xlog10(x))
(function)   |

log2log2flog2l
(C99)(C99)(C99)
|   | computes base-2 logarithm (log2xlog2⁡xlog2(x))
(function)   |

log1plog1pflog1pl
(C99)(C99)(C99)
|   | computes natural (base-*e*) logarithm of 1 plus the given number (ln(1+x)ln⁡(1+x)ln(1+x))
(function)   |

expexpfexpl
(C99)(C99)
|   | computes *e* raised to the given power (exexe)
(function)   |

clogclogfclogl
(C99)(C99)(C99)
|   | computes the complex natural logarithm
(function)   |

C++ documentation for log

---
來源頁路徑：`en.cppreference.com/c/numeric/math/log.html`

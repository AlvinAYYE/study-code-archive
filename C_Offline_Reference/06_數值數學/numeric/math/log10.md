# log10, log10f, log10l

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
float log10f( float arg );
```
|   |  (1)  |   |  (since C99)  |

```c
double log10( double arg );
```
|   |  (2)  |   |   |

```c
long double log10l( long double arg );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define log10( arg )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Computes the common (base-*10*) logarithm of `arg`.

4) Type-generic macro: If `arg` has type `long double`, `log10l` is called. Otherwise, if `arg` has integer type or the type `double`, `log10` is called. Otherwise, `log10f` is called.

### Parameters

| arg  |   | -  |   | floating-point value  |

### Return value

If no errors occur, the common (base-*10*) logarithm of `arg` (log10(arg) or lg(arg)) is returned.
若沒有發生錯誤，回傳 arg 的常用對數（以 10 為底），也就是 log₁₀(arg) 或 lg(arg)。
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
如果參數為 ±0，則傳回 -∞ 並引發 FE_DIVBYZERO 。

- If the argument is 1, +0 is returned
如果參數為 1，則傳回 +0

- If the argument is negative, NaN is returned and FE_INVALID is raised.
如果參數為負數，則傳回 NaN 並引發 FE_INVALID 。

- If the argument is +∞, +∞ is returned
如果參數為 +∞，則傳回 +∞

- If the argument is NaN, NaN is returned.
若參數為 NaN，回傳 NaN。

### Example

Run this code

```c
#include <errno.h> #include <fenv.h> #include <float.h> #include <math.h> #include <stdio.h> // #pragma STDC FENV_ACCESS ON int main(void) {  printf("log10(1000) = %f\n", log10(1000));  printf("log10(0.001) = %f\n", log10(0.001));  printf("base-5 logarithm of 125 = %f\n", log10(125) / log10(5));  // special values  printf("log10(1) = %f\n", log10(1));  printf("log10(+Inf) = %f\n", log10(INFINITY));  // error handling  errno = 0; feclearexcept(FE_ALL_EXCEPT);  printf("log10(0) = %f\n", log10(0));  if (errno == ERANGE)  perror(" errno == ERANGE");  if (fetestexcept(FE_DIVBYZERO))  puts(" FE_DIVBYZERO raised"); }
```

Possible output:
可能的輸出：

```c
log10(1000) = 3.000000 log10(0.001) = -3.000000 base-5 logarithm of 125 = 3.000000 log10(1) = 0.000000 log10(+Inf) = inf log10(0) = -inf errno == ERANGE: Numerical result out of range FE_DIVBYZERO raised
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.6.8 The log10 functions (p: TBD)
7.12.6.8 log10 函式 (p: TBD)
7.12.6.8 log10 函式 (p: TBD)

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.3.8 The log10 functions (p: TBD)
F.10.3.8 log10 函式 (p: TBD)
F.10.3.8 log10 函式 (p: TBD)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.6.8 The log10 functions (p: 179)
7.12.6.8 log10 函式 (p: 179)
7.12.6.8 log10 函式 (p: 179)

- 7.25 Type-generic math <tgmath.h> (p: 272-273)
7.25 型別通用數學 <tgmath.h> (p: 272-273)
7.25 型別通用數學 <tgmath.h> (p: 272-273)

- F.10.3.8 The log10 functions (p: 380)
F.10.3.8 log10 函式 (p: 380)
F.10.3.8 log10 函式 (p: 380)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.6.8 The log10 functions (p: 245)
7.12.6.8 log10 函式 (p: 245)
7.12.6.8 log10 函式 (p: 245)

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.3.8 The log10 functions (p: 522)
F.10.3.8 log10 函式 (p: 522)
F.10.3.8 log10 函式 (p: 522)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.6.8 The log10 functions (p: 225-226)
7.12.6.8 log10 函式 (p: 225-226)
7.12.6.8 log10 函式 (p: 225-226)

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- F.9.3.8 The log10 functions (p: 459)
F.9.3.8 log10 函式 (p: 459)
F.9.3.8 log10 函式 (p: 459)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.5.4.5 The log10 function
4.5.4.5 log10 函式
4.5.4.5 log10 函式

### See also

loglogflogl
(C99)(C99)
|   | computes natural (base-*e*) logarithm (lnxln⁡xln(x))
(function)   |

log2log2flog2l
(C99)(C99)(C99)
|   | computes base-2 logarithm (log2xlog2⁡xlog2(x))
(function)   |

log1plog1pflog1pl
(C99)(C99)(C99)
|   | computes natural (base-*e*) logarithm of 1 plus the given number (ln(1+x)ln⁡(1+x)ln(1+x))
(function)   |

C++ documentation for log10

---
來源頁路徑：`en.cppreference.com/c/numeric/math/log10.html`

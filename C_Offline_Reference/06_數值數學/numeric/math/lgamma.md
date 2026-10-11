# lgamma, lgammaf, lgammal

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
float lgammaf( float arg );
```
|   |  (1)  |   |  (since C99)  |

```c
double lgamma( double arg );
```
|   |  (2)  |   |  (since C99)  |

```c
long double lgammal( long double arg );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define lgamma( arg )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Computes the natural logarithm of the absolute value of the gamma function of `arg`.

4) Type-generic macro: If `arg` has type `long double`, `lgammal` is called. Otherwise, if `arg` has integer type or the type `double`, `lgamma` is called. Otherwise, `lgammaf` is called.

### Parameters

| arg  |   | -  |   | floating-point value  |

### Return value

If no errors occur, the value of the logarithm of the gamma function of `arg`, that is loge|∫∞0targ−1e−tdt|loge⁡|∫0∞targ−1e−tdt|loge|∫∞
0*t*arg-1
*e* d*t*|, is returned.
若未發生錯誤，則傳回 arg 的 gamma 函式的對數值，即 log e | ∫ ∞ 0 t a r g − 1 e − t d t | log e ⁡ | ∫ 0 ∞ t a r g − 1 e − t d t | log e | ∫ ∞ 0 t arg-1 e -t d t |。
If a pole error occurs, +HUGE_VAL, `+HUGE_VALF`, or `+HUGE_VALL` is returned.
如果發生極點錯誤，則傳回 +HUGE_VAL、+HUGE_VALF 或 +HUGE_VALL。
If a range error due to overflow occurs, ±HUGE_VAL, `±HUGE_VALF`, or `±HUGE_VALL` is returned.
如果因溢位而發生值域錯誤，則傳回 ±HUGE_VAL 、±HUGE_VALF 或 ±HUGE_VALL。

### Error handling

Errors are reported as specified in math_errhandling.
錯誤會依照 math_errhandling 的規定回報。
If `arg` is zero or is an integer less than zero, a pole error may occur.
如果 arg 為零或為小於零的整數，可能會發生極點錯誤。
If the implementation supports IEEE floating-point arithmetic (IEC 60559),
若實作支援 IEEE 浮點運算（IEC 60559）：

- If the argument is 1, +0 is returned.
如果參數為 1，則傳回 +0。

- If the argument is 2, +0 is returned.
如果參數為 2，則傳回 +0。

- If the argument is ±0, +∞ is returned and FE_DIVBYZERO is raised.
如果參數為 ±0，則傳回 +∞ 並引發 FE_DIVBYZERO。

- If the argument is a negative integer, +∞ is returned and FE_DIVBYZERO is raised.
如果參數為負整數，則傳回 +∞ 並引發 FE_DIVBYZERO。

- If the argument is ±∞, +∞ is returned.
若參數為 ±∞，回傳 +∞。

- If the argument is NaN, NaN is returned.
若參數為 NaN，回傳 NaN。

### Notes

If `arg` is a natural number, `lgamma(arg)` is the logarithm of the factorial of `arg - 1`.
如果 arg 是自然數，則 lgamma ( arg ) 是 arg - 1 的階乘的對數。
The POSIX version of `lgamma` is not thread-safe: each execution of the function stores the sign of the gamma function of `arg` in the static external variable `signgam`. Some implementations provide `lgamma_r`, which takes a pointer to user-provided storage for singgam as the second parameter, and is thread-safe.
lgamma 的 POSIX 版本不是執行緒安全的：每次執行該函式都會將 arg 的 gamma 函式的符號儲存到靜態外部變數 signgam 中。某些實現提供 lgamma_r，它以指向使用者提供的用於儲存 singgam 的儲存區的指標作為第二個參數，並且是執行緒安全的。
There is a non-standard function named `gamma` in various implementations, but its definition is inconsistent. For example, glibc and 4.2BSD version of `gamma` executes `lgamma`, but 4.4BSD version of `gamma` executes `tgamma`.
各實現中存在一個名為 gamma 的非標準函式，但其定義並不一致。例如，glibc 和 4.2BSD 版本的 gamma 執行 lgamma ，而 4.4BSD 版本的 gamma 執行 tgamma 。

### Example

Run this code

```c
#include <errno.h> #include <fenv.h> #include <float.h> #include <math.h> #include <stdio.h> // #pragma STDC FENV_ACCESS ON int main(void) {  printf("lgamma(10) = %f, log(9!) = %f\n", lgamma(10),  log(2 * 3 * 4 * 5 * 6 * 7 * 8 * 9));  const double pi = acos(-1);  printf("lgamma(0.5) = %f, log(sqrt(pi)) = %f\n", log(sqrt(pi)), lgamma(0.5));  // special values  printf("lgamma(1) = %f\n", lgamma(1));  printf("lgamma(+Inf) = %f\n", lgamma(INFINITY));  // error handling  errno = 0; feclearexcept(FE_ALL_EXCEPT);  printf("lgamma(0) = %f\n", lgamma(0));  if (errno == ERANGE)  perror(" errno == ERANGE");  if (fetestexcept(FE_DIVBYZERO))  puts(" FE_DIVBYZERO raised"); }
```

Possible output:
可能的輸出：

```c
lgamma(10) = 12.801827, log(9!) = 12.801827 lgamma(0.5) = 0.572365, log(sqrt(pi)) = 0.572365 lgamma(1) = 0.000000 lgamma(+Inf) = inf lgamma(0) = inf errno == ERANGE: Numerical result out of range FE_DIVBYZERO raised
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.8.3 The lgamma functions (p: TBD)
7.12.8.3 lgamma 函式 (p: TBD)
7.12.8.3 lgamma 函式 (p: TBD)

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.5.3 The lgamma functions (p: TBD)
F.10.5.3 lgamma 函式 (p: TBD)
F.10.5.3 lgamma 函式 (p: TBD)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.8.3 The lgamma functions (p: 182)
7.12.8.3 lgamma 函式 (p: 182)
7.12.8.3 lgamma 函式 (p: 182)

- 7.25 Type-generic math <tgmath.h> (p: 272-273)
7.25 型別通用數學 <tgmath.h> (p: 272-273)
7.25 型別通用數學 <tgmath.h> (p: 272-273)

- F.10.5.3 The lgamma functions (p: 383)
F.10.5.3 lgamma 函式 (p: 383)
F.10.5.3 lgamma 函式 (p: 383)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.8.3 The lgamma functions (p: 250)
7.12.8.3 lgamma 函式 (p: 250)
7.12.8.3 lgamma 函式 (p: 250)

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.5.3 The lgamma functions (p: 525)
F.10.5.3 lgamma 函式 (p: 525)
F.10.5.3 lgamma 函式 (p: 525)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.8.3 The lgamma functions (p: 231)
7.12.8.3 lgamma 函式 (p: 231)
7.12.8.3 lgamma 函式 (p: 231)

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- F.9.5.3 The lgamma functions (p: 462)
F.9.5.3 lgamma 函式 (p: 462)
F.9.5.3 lgamma 函式 (p: 462)

### See also

tgammatgammaftgammal
(C99)(C99)(C99)
|   | computes gamma function
(function)   |

C++ documentation for lgamma

### External links

| Weisstein, Eric W. "Log Gamma Function." From MathWorld — A Wolfram Web Resource.  |

---
來源頁路徑：`en.cppreference.com/c/numeric/math/lgamma.html`

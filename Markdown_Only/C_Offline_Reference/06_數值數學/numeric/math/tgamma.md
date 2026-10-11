# tgamma, tgammaf, tgammal

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
float tgammaf( float arg );
```
|   |  (1)  |   |  (since C99)  |

```c
double tgamma( double arg );
```
|   |  (2)  |   |  (since C99)  |

```c
long double tgammal( long double arg );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define tgamma( arg )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Computes the gamma function of `arg`.

4) Type-generic macro: If `arg` has type `long double`, `tgammal` is called. Otherwise, if `arg` has integer type or the type `double`, `tgamma` is called. Otherwise, `tgammaf` is called.

### Parameters

| arg  |   | -  |   | floating-point value  |

### Return value

If no errors occur, the value of the gamma function of `arg`, that is Γ(arg)=∫∞0targ−1e−tdtΓ(arg)=∫0∞targ−1e−tdt∫∞
0*t*arg-1
*e* d*t*, is returned.
若沒有發生錯誤，回傳 arg 的伽瑪函式值 Γ(arg) = ∫₀^∞ t^(arg-1)e^(-t) dt。
If a domain error occurs, an implementation-defined value (NaN where supported) is returned.
若發生定義域錯誤，回傳由實作定義的值（若支援則回傳 NaN）。
If a pole error occurs, `±HUGE_VAL`, `±HUGE_VALF`, or `±HUGE_VALL` is returned.
若發生極點錯誤，回傳 ±HUGE_VAL、±HUGE_VALF 或 ±HUGE_VALL。
If a range error due to overflow occurs, ±HUGE_VAL, `±HUGE_VALF`, or `±HUGE_VALL` is returned.
若因浮點溢位而發生值域錯誤，回傳 ±HUGE_VAL、±HUGE_VALF 或 ±HUGE_VALL。
If a range error due to underflow occurs, the correct value (after rounding) is returned.
若因浮點下溢而發生值域錯誤，回傳正確結果（經捨入後）。

### Error handling

Errors are reported as specified in math_errhandling.
錯誤會依照 math_errhandling 的規定回報。
If `arg` is zero or is an integer less than zero, a pole error or a domain error may occur.
若 arg 為零或負整數，可能會發生極點錯誤或定義域錯誤。
If the implementation supports IEEE floating-point arithmetic (IEC 60559):
若實作支援 IEEE 浮點運算（IEC 60559）：

- If the argument is ±0, ±∞ is returned and FE_DIVBYZERO is raised.
若參數為 ±0，回傳 ±∞ 並引發 FE_DIVBYZERO。

- If the argument is a negative integer, NaN is returned and FE_INVALID is raised.
若參數為負整數，回傳 NaN 並引發 FE_INVALID。

- If the argument is -∞, NaN is returned and FE_INVALID is raised.
若參數為 -∞，回傳 NaN 並引發 FE_INVALID。

- If the argument is +∞, +∞ is returned.
若參數為 +∞，回傳 +∞。

- If the argument is NaN, NaN is returned.
若參數為 NaN，回傳 NaN。

### Notes

If `arg` is a natural number, `tgamma(arg)` is the factorial of `arg - 1`. Many implementations calculate the exact integer-domain factorial if the argument is a sufficiently small integer.
若 arg 是正整數，tgamma(arg) 就是 (arg - 1) 的階乘。許多實作在整數參數夠小時，會在整數範圍內精確計算階乘。
For IEEE-compatible type `double`, overflow happens if `0 < x < 1/DBL_MAX` or if `x > 171.7`.
對符合 IEEE 標準的 double 型別而言，0 < x < 1 / DBL_MAX 或 x > 171.7 時會發生溢位。
POSIX requires that a pole error occurs if the argument is zero, but a domain error occurs when the argument is a negative integer. It also specifies that in future, domain errors may be replaced by pole errors for negative integer arguments (in which case the return value in those cases would change from NaN to ±∞).
POSIX 規定，參數為零時會發生極點錯誤，參數為負整數時會發生定義域錯誤。POSIX 也指出，未來可能會將負整數參數的定義域錯誤改為極點錯誤；若如此，這些情況的回傳值也會從 NaN 改為 ±∞。
There is a non-standard function named `gamma` in various implementations, but its definition is inconsistent. For example, glibc and 4.2BSD version of `gamma` executes `lgamma`, but 4.4BSD version of `gamma` executes `tgamma`.
部分實作提供非標準函式 gamma，但其定義不一致。例如，glibc 和 4.2BSD 的 gamma 等同於 lgamma；4.4BSD 的 gamma 則等同於 tgamma。

### Example

Run this code

```c
#include <errno.h> #include <fenv.h> #include <float.h> #include <math.h> #include <stdio.h> // #pragma STDC FENV_ACCESS ON int main(void) {  printf("tgamma(10) = %f, 9!=%f\n", tgamma(10), 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9.0);  printf("tgamma(0.5) = %f, sqrt(pi) = %f\n", tgamma(0.5), sqrt(acos(-1)));  // special values  printf("tgamma(+Inf) = %f\n", tgamma(INFINITY));  // error handling  errno = 0; feclearexcept(FE_ALL_EXCEPT);  printf("tgamma(-1) = %f\n", tgamma(-1));  if (errno == ERANGE)  perror(" errno == ERANGE");  else  if (errno == EDOM) perror(" errno == EDOM");  if (fetestexcept(FE_DIVBYZERO))  puts(" FE_DIVBYZERO raised");  else if (fetestexcept(FE_INVALID))  puts(" FE_INVALID raised"); }
```

Possible output:
可能的輸出：

```c
tgamma(10) = 362880.000000, 9!=362880.000000 tgamma(0.5) = 1.772454, sqrt(pi) = 1.772454 tgamma(+Inf) = inf tgamma(-1) = nan errno == EDOM: Numerical argument out of domain FE_INVALID raised
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.8.4 The tgamma functions (p: 250)
7.12.8.4 tgamma 函式（p: 250）
7.12.8.4 tgamma 函式（p: 250）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.5.4 The tgamma functions (p: 525)
F.10.5.4 tgamma 函式（p: 525）
F.10.5.4 tgamma 函式（p: 525）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.8.4 The tgamma functions (p: 250)
7.12.8.4 tgamma 函式（p: 250）
7.12.8.4 tgamma 函式（p: 250）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.5.4 The tgamma functions (p: 525)
F.10.5.4 tgamma 函式（p: 525）
F.10.5.4 tgamma 函式（p: 525）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.8.4 The tgamma functions (p: 250)
7.12.8.4 tgamma 函式（p: 250）
7.12.8.4 tgamma 函式（p: 250）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.5.4 The tgamma functions (p: 525)
F.10.5.4 tgamma 函式（p: 525）
F.10.5.4 tgamma 函式（p: 525）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.8.4 The tgamma functions (p: 231)
7.12.8.4 tgamma 函式（p: 231）
7.12.8.4 tgamma 函式（p: 231）

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- F.9.5.4 The tgamma functions (p: 462)
F.9.5.4 tgamma 函式（p: 462）
F.9.5.4 tgamma 函式（p: 462）

### See also

lgammalgammaflgammal
(C99)(C99)(C99)
|   | computes natural (base-*e*) logarithm of the gamma function
(function)   |

C++ documentation for tgamma

### External links

| Weisstein, Eric W. "Gamma Function." From MathWorld — A Wolfram Web Resource.  |

---
來源頁路徑：`en.cppreference.com/c/numeric/math/tgamma.html`

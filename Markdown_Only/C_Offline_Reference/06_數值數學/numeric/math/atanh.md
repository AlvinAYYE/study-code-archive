# atanh, atanhf, atanhl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
float atanhf( float arg );
```
|   |  (1)  |   |  (since C99)  |

```c
double atanh( double arg );
```
|   |  (2)  |   |  (since C99)  |

```c
long double atanhl( long double arg );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define atanh( arg )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Computes the inverse hyperbolic tangent of `arg`.

4) Type-generic macro: If the argument has type `long double`, `atanhl` is called. Otherwise, if the argument has integer type or the type `double`, `atanh` is called. Otherwise, `atanhf` is called. If the argument is complex, then the macro invokes the corresponding complex function (catanhf, catanh, catanhl).

### Parameters

| arg  |   | -  |   | floating_point value representing the area of a hyperbolic sector  |

### Return value

If no errors occur, the inverse hyperbolic tangent of `arg` (tanh-1
(arg), or artanh(arg)), is returned.
若未發生錯誤，則傳回 arg 的反雙曲正切（ tanh -1 (arg) ，或 artanh(arg) ）。
If a domain error occurs, an implementation-defined value is returned (NaN where supported).
若發生定義域錯誤，回傳由實作定義的值（若支援則回傳 NaN）。
If a pole error occurs, `±HUGE_VAL`, `±HUGE_VALF`, or `±HUGE_VALL` is returned (with the correct sign).
若發生極點錯誤，則傳回 ± HUGE_VAL 、 ±HUGE_VALF 或 ±HUGE_VALL （符號正確）。
If a range error occurs due to underflow, the correct result (after rounding) is returned.
若因浮點下溢而發生值域錯誤，回傳正確結果（經捨入後）。

### Error handling

Errors are reported as specified in math_errhandling.
錯誤會依照 math_errhandling 的規定回報。
If the argument is not on the interval `[``-1``, ``+1``]`, a range error occurs.
若參數不在區間 [ -1 , + 1 ] 上，則發生值域錯誤。
If the argument is ±1, a pole error occurs.
若參數為 ±1，則發生極點錯誤。
If the implementation supports IEEE floating-point arithmetic (IEC 60559),
若實作支援 IEEE 浮點運算（IEC 60559）：

- If the argument is ±0, it is returned unmodified.
如果參數為 ±0，則原樣傳回。

- If the argument is ±1, ±∞ is returned and FE_DIVBYZERO is raised.
若參數為 ±1，則傳回 ±∞ 並引發 FE_DIVBYZERO 。

- If |arg|>1, NaN is returned and FE_INVALID is raised.
若 |arg|>1，則傳回 NaN 並引發 FE_INVALID 。

- If the argument is NaN, NaN is returned.
若參數為 NaN，回傳 NaN。

### Notes

Although the C standard names this function "arc hyperbolic tangent", the inverse functions of the hyperbolic functions are the area functions. Their argument is the area of a hyperbolic sector, not an arc. The correct name is "inverse hyperbolic tangent" (used by POSIX) or "area hyperbolic tangent".
儘管 C 標準將該函式命名為“arc hyperbolic tangent”，但雙曲函式的逆函式其實是反雙曲函式（area functions）。它們的參數是雙曲扇形的面積，而不是弧。正確的名稱是“inverse hyperbolic tangent”（POSIX 採用）或“area hyperbolic tangent”。
POSIX specifies that in case of underflow, `arg` is returned unmodified, and if that is not supported, an implementation-defined value no greater than DBL_MIN, FLT_MIN, and LDBL_MIN is returned.
POSIX 規定，在發生下溢的情況下原樣傳回 arg ；如果不支援此行為，則傳回一個不大於 DBL_MIN 、 FLT_MIN 和 LDBL_MIN 的由實現定義的值。

### Example

Run this code

```c
#include <errno.h> #include <fenv.h> #include <float.h> #include <math.h> #include <stdio.h> // #pragma STDC FENV_ACCESS ON int main(void) {  printf("atanh(0) = %f\natanh(-0) = %f\n", atanh(0), atanh(-0.0));  printf("atanh(0.9) = %f\n", atanh(0.9));  // error handling  errno = 0; feclearexcept(FE_ALL_EXCEPT);  printf("atanh(-1) = %f\n", atanh(-1));  if (errno == ERANGE)  perror(" errno == ERANGE");  if (fetestexcept(FE_DIVBYZERO))  puts(" FE_DIVBYZERO raised"); }
```

Possible output:
可能的輸出：

```c
atanh(0) = 0.000000 atanh(-0) = -0.000000 atanh(0.9) = 1.472219 atanh(-1) = -inf errno == ERANGE: Numerical result out of range FE_DIVBYZERO raised
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.5.3 The atanh functions (p: 241)
7.12.5.3 atanh 函式（p: 241）
7.12.5.3 atanh 函式（p: 241）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.2.3 The atanh functions (p: 520)
F.10.2.3 atanh 函式（p: 520）
F.10.2.3 atanh 函式（p: 520）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.5.3 The atanh functions (p: TBD)
7.12.5.3 atanh 函式（p: TBD）
7.12.5.3 atanh 函式（p: TBD）

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.2.3 The atanh functions (p: TBD)
F.10.2.3 atanh 函式（p: TBD）
F.10.2.3 atanh 函式（p: TBD）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.5.3 The atanh functions (p: 241)
7.12.5.3 atanh 函式（p: 241）
7.12.5.3 atanh 函式（p: 241）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.2.3 The atanh functions (p: 520)
F.10.2.3 atanh 函式（p: 520）
F.10.2.3 atanh 函式（p: 520）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.5.3 The atanh functions (p: 221-222)
7.12.5.3 atanh 函式（p: 221-222）
7.12.5.3 atanh 函式（p: 221-222）

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- F.9.2.3 The atanh functions (p: 457)
F.9.2.3 atanh 函式（p: 457）
F.9.2.3 atanh 函式（p: 457）

### See also

asinhasinhfasinhl
(C99)(C99)(C99)
|   | computes inverse hyperbolic sine (arsinhxarsinh⁡xarsinh(x))
(function)   |

acoshacoshfacoshl
(C99)(C99)(C99)
|   | computes inverse hyperbolic cosine (arcoshxarcosh⁡xarcosh(x))
(function)   |

tanhtanhftanhl
(C99)(C99)
|   | computes hyperbolic tangent (tanhxtanh⁡xtanh(x))
(function)   |

catanhcatanhfcatanhl
(C99)(C99)(C99)
|   | computes the complex arc hyperbolic tangent
(function)   |

C++ documentation for atanh

### External links

| Weisstein, Eric W. "Inverse Hyperbolic Tangent." From MathWorld — A Wolfram Web Resource.  |

---
來源頁路徑：`en.cppreference.com/c/numeric/math/atanh.html`

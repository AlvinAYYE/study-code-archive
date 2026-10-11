# acosh, acoshf, acoshl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
float acoshf( float arg );
```
|   |  (1)  |   |  (since C99)  |

```c
double acosh( double arg );
```
|   |  (2)  |   |  (since C99)  |

```c
long double acoshl( long double arg );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define acosh( arg )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Computes the inverse hyperbolic cosine of `arg`.

4) Type-generic macro: If the argument has type `long double`, `acoshl` is called. Otherwise, if the argument has integer type or the type `double`, `acosh` is called. Otherwise, `acoshf` is called. If the argument is complex, then the macro invokes the corresponding complex function (`cacoshf`, `cacosh`, `cacoshl`).

### Parameters

| arg  |   | -  |   | floating-point value representing the area of a hyperbolic sector  |

### Return value

If no errors occur, the inverse hyperbolic cosine of `arg` (cosh-1
(arg), or arcosh(arg)) on the interval [0, +∞], is returned.
若未發生錯誤，則傳回 arg 在區間 [0, +∞] 上的反雙曲餘弦（cosh -1 (arg) 或 arcosh(arg)）。
If a domain error occurs, an implementation-defined value is returned (NaN where supported).
若發生定義域錯誤，回傳由實作定義的值（若支援則回傳 NaN）。

### Error handling

Errors are reported as specified in math_errhandling.
錯誤會依照 math_errhandling 的規定回報。
If the argument is less than `1`, a domain error occurs.
如果參數小於 1，則發生定義域錯誤。
If the implementation supports IEEE floating-point arithmetic (IEC 60559),
若實作支援 IEEE 浮點運算（IEC 60559）：

- If the argument is less than 1, FE_INVALID is raised an NaN is returned.
如果參數小於 1，則引發 FE_INVALID 並傳回 NaN。

- If the argument is 1, +0 is returned.
如果參數為 1，則傳回 +0。

- If the argument is +∞, +∞ is returned.
如果參數為 +∞，則傳回 +∞。

- If the argument is NaN, NaN is returned.
若參數為 NaN，回傳 NaN。

### Notes

Although the C standard names this function "arc hyperbolic cosine", the inverse functions of the hyperbolic functions are the area functions. Their argument is the area of a hyperbolic sector, not an arc. The correct name is "inverse hyperbolic cosine" (used by POSIX) or "area hyperbolic cosine".
儘管 C 標準將該函式命名為“arc hyperbolic cosine”，但雙曲函式的反函式是 area 函式。它們的參數是雙曲扇形的面積，而不是弧。正確的名稱是“反雙曲餘弦”（POSIX 使用）或“area hyperbolic cosine”。

### Example

Run this code

```c
#include <errno.h> #include <fenv.h> #include <float.h> #include <math.h> #include <stdio.h> // #pragma STDC FENV_ACCESS ON int main(void) {  printf("acosh(1) = %f\nacosh(10) = %f\n", acosh(1), acosh(10));  printf("acosh(DBL_MAX) = %f\nacosh(Inf) = %f\n", acosh(DBL_MAX), acosh(INFINITY));  // error handling  errno = 0; feclearexcept(FE_ALL_EXCEPT);  printf("acosh(0.5) = %f\n", acosh(0.5));  if (errno == EDOM)  perror(" errno == EDOM");  if (fetestexcept(FE_INVALID))  puts(" FE_INVALID raised"); }
```

Possible output:
可能的輸出：

```c
acosh(1) = 0.000000 acosh(10) = 2.993223 acosh(DBL_MAX) = 710.475860 acosh(Inf) = inf acosh(0.5) = -nan errno == EDOM: Numerical argument out of domain FE_INVALID raised
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.5.1 The acosh functions (p: TBD)
7.12.5.1 acosh 函式 (p: TBD)
7.12.5.1 acosh 函式 (p: TBD)

- 7.27 Type-generic math <tgmath.h> (p: TBD)
7.27 型別通用數學 <tgmath.h> (p: TBD)
7.27 型別通用數學 <tgmath.h> (p: TBD)

- F.10.2.1 The acosh functions (p: TBD)
F.10.2.1 acosh 函式 (p: TBD)
F.10.2.1 acosh 函式 (p: TBD)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.5.1 The acosh functions (p: 175)
7.12.5.1 acosh 函式 (p: 175)
7.12.5.1 acosh 函式 (p: 175)

- 7.25 Type-generic math <tgmath.h> (p: 272-273)
7.25 型別通用數學 <tgmath.h> (p: 272-273)
7.25 型別通用數學 <tgmath.h> (p: 272-273)

- F.10.2.1 The acosh functions (p: 379)
F.10.2.1 acosh 函式 (p: 379)
F.10.2.1 acosh 函式 (p: 379)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.5.1 The acosh functions (p: 240)
7.12.5.1 acosh 函式 (p: 240)
7.12.5.1 acosh 函式 (p: 240)

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.2.1 The acosh functions (p: 520)
F.10.2.1 acosh 函式 (p: 520)
F.10.2.1 acosh 函式 (p: 520)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.5.1 The acosh functions (p: 221)
7.12.5.1 acosh 函式 (p: 221)
7.12.5.1 acosh 函式 (p: 221)

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- F.9.2.1 The acosh functions (p: 457)
F.9.2.1 acosh 函式 (p: 457)
F.9.2.1 acosh 函式 (p: 457)

### See also

asinhasinhfasinhl
(C99)(C99)(C99)
|   | computes inverse hyperbolic sine (arsinhxarsinh⁡xarsinh(x))
(function)   |

atanhatanhfatanhl
(C99)(C99)(C99)
|   | computes inverse hyperbolic tangent (artanhxartanh⁡xartanh(x))
(function)   |

coshcoshfcoshl
(C99)(C99)
|   | computes hyperbolic cosine (coshxcosh⁡xcosh(x))
(function)   |

cacoshcacoshfcacoshl
(C99)(C99)(C99)
|   | computes the complex arc hyperbolic cosine
(function)   |

C++ documentation for acosh

### External links

| Weisstein, Eric W. "Inverse Hyperbolic Cosine." From MathWorld — A Wolfram Web Resource.  |

---
來源頁路徑：`en.cppreference.com/c/numeric/math/acosh.html`

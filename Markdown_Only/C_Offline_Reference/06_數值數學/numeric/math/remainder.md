# remainder, remainderf, remainderl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
float remainderf( float x, float y );
```
|   |  (1)  |   |  (since C99)  |

```c
double remainder( double x, double y );
```
|   |  (2)  |   |  (since C99)  |

```c
long double remainderl( long double x, long double y );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define remainder( x, y )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Computes the IEEE remainder of the floating-point division operation `x/y`.

4) Type-generic macro: If any argument has type `long double`, `remainderl` is called. Otherwise, if any argument has integer type or has type `double`, `remainder` is called. Otherwise, `remainderf` is called.

The IEEE floating-point remainder of the division operation `x/y` calculated by this function is exactly the value `x - n * y`, where the value `n` is the integral value nearest the exact value `x/y`. When |n-x/y| = ½, the value `n` is chosen to be even.
此函式計算 x / y 的 IEEE 浮點餘數，結果恰為 x - n * y，其中 n 是最接近精確值 x / y 的整數；若 |n - x/y| = ½，則取偶數 n。
In contrast to fmod(), the returned value is not guaranteed to have the same sign as `x`.
與 fmod() 不同，remainder() 的回傳值不一定與 x 同號。
If the returned value is `0`, it will have the same sign as `x`.
若回傳值為 0，其正負號會與 x 相同。

### Parameters

| x, y  |   | -  |   | floating-point values  |

### Return value

If successful, returns the IEEE floating-point remainder of the division `x/y` as defined above.
成功時，回傳前述定義的 x / y IEEE 浮點餘數。
If a domain error occurs, an implementation-defined value is returned (NaN where supported).
若發生定義域錯誤，回傳由實作定義的值（若支援則回傳 NaN）。
If a range error occurs due to underflow, the correct result is returned.
若因浮點下溢而發生值域錯誤，回傳正確結果。
If `y` is zero, but the domain error does not occur, zero is returned.
若 y 為零但沒有發生定義域錯誤，則回傳零。

### Error handling

Errors are reported as specified in math_errhandling.
錯誤會依照 math_errhandling 的規定回報。
Domain error may occur if `y` is zero.
若 y 為零，可能會發生定義域錯誤。
If the implementation supports IEEE floating-point arithmetic (IEC 60559),
若實作支援 IEEE 浮點運算（IEC 60559）：

- The current rounding mode has no effect.
目前的捨入模式不會影響結果。

- FE_INEXACT is never raised, the result is always exact.
結果永遠精確，不會引發 FE_INEXACT。

- If `x` is ±∞ and `y` is not NaN, NaN is returned and FE_INVALID is raised.
若 x 為 ±∞ 且 y 不是 NaN，回傳 NaN 並引發 FE_INVALID。

- If `y` is ±0 and `x` is not NaN, NaN is returned and FE_INVALID is raised.
若 y 為 ±0 且 x 不是 NaN，回傳 NaN 並引發 FE_INVALID。

- If either argument is NaN, NaN is returned.
若任一參數是 NaN，回傳 NaN。

### Notes

POSIX requires that a domain error occurs if `x` is infinite or `y` is zero.
POSIX 規定，x 為無窮大或 y 為零時會發生定義域錯誤。
fmod, but not `remainder` is useful for doing silent wrapping of floating-point types to unsigned integer types: `(0.0 <= (y = fmod(rint(x), 65536.0)) ? y : 65536.0 + y)` is in the range `[``-0.0``, ``65535.0``]`, which corresponds to `unsigned short`, but `remainder(rint(x), 65536.0)` is in the range `[``-32767.0``, ``+32768.0``]`, which is outside of the range of `signed short`.
fmod（而非 remainder）可用來將浮點值靜默環繞至無號整數型別的範圍。例如，(0.0 <= (y = fmod(rint(x), 65536.0)) ? y : 65536.0 + y) 的結果介於 [-0.0, 65535.0]，可對應 unsigned short；remainder(rint(x), 65536.0) 的結果則介於 [-32767.0, +32768.0]，超出 signed short 的範圍。

### Example

Run this code

```c
#include <fenv.h> #include <math.h> #include <stdio.h> // #pragma STDC FENV_ACCESS ON int main(void) {  printf("remainder(+5.1, +3.0) = %.1f\n", remainder(5.1, 3));  printf("remainder(-5.1, +3.0) = %.1f\n", remainder(-5.1, 3));  printf("remainder(+5.1, -3.0) = %.1f\n", remainder(5.1, -3));  printf("remainder(-5.1, -3.0) = %.1f\n", remainder(-5.1, -3));  // special values  printf("remainder(-0.0, 1.0) = %.1f\n", remainder(-0.0, 1));  printf("remainder(+5.1, Inf) = %.1f\n", remainder(5.1, INFINITY));  // error handling  feclearexcept(FE_ALL_EXCEPT);  printf("remainder(+5.1, 0) = %.1f\n", remainder(5.1, 0));  if (fetestexcept(FE_INVALID))  puts(" FE_INVALID raised"); }
```

Output:

```c
remainder(+5.1, +3.0) = -0.9 remainder(-5.1, +3.0) = 0.9 remainder(+5.1, -3.0) = -0.9 remainder(-5.1, -3.0) = 0.9 remainder(+0.0, 1.0) = 0.0 remainder(-0.0, 1.0) = -0.0 remainder(+5.1, Inf) = 5.1 remainder(+5.1, 0) = -nan FE_INVALID raised
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.10.2 The remainder functions (p: TBD)
7.12.10.2 remainder 函式（p: TBD）
7.12.10.2 remainder 函式（p: TBD）

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.7.2 The remainder functions (p: TBD)
F.10.7.2 remainder 函式（p: TBD）
F.10.7.2 remainder 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.10.2 The remainder functions (p: 185-186)
7.12.10.2 remainder 函式（p: 185-186）
7.12.10.2 remainder 函式（p: 185-186）

- 7.25 Type-generic math <tgmath.h> (p: 272-273)
7.25 型別通用數學 <tgmath.h> (p: 272-273)
7.25 型別通用數學 <tgmath.h> (p: 272-273)

- F.10.7.2 The remainder functions (p: 385)
F.10.7.2 remainder 函式（p: 385）
F.10.7.2 remainder 函式（p: 385）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.10.2 The remainder functions (p: 254-255)
7.12.10.2 remainder 函式（p: 254-255）
7.12.10.2 remainder 函式（p: 254-255）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.7.2 The remainder functions (p: 529)
F.10.7.2 remainder 函式（p: 529）
F.10.7.2 remainder 函式（p: 529）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.10.2 The remainder functions (p: 235)
7.12.10.2 remainder 函式（p: 235）
7.12.10.2 remainder 函式（p: 235）

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- F.9.7.2 The remainder functions (p: 465)
F.9.7.2 remainder 函式（p: 465）
F.9.7.2 remainder 函式（p: 465）

### See also

divldivlldiv
(C99)
|   | computes quotient and remainder of integer division
(function)   |

fmodfmodffmodl
(C99)(C99)
|   | computes remainder of the floating-point division operation
(function)   |

remquoremquofremquol
(C99)(C99)(C99)
|   | computes signed remainder as well as the three last bits of the division operation
(function)   |

C++ documentation for remainder

---
來源頁路徑：`en.cppreference.com/c/numeric/math/remainder.html`

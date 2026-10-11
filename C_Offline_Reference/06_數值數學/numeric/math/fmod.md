# fmod, fmodf, fmodl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
float fmodf( float x, float y );
```
|   |  (1)  |   |  (since C99)  |

```c
double fmod( double x, double y );
```
|   |  (2)  |   |   |

```c
long double fmodl( long double x, long double y );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define fmod( x, y )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Computes the floating-point remainder of the division operation `x / y`.

4) Type-generic macro: If any argument has type `long double`, `fmodl` is called. Otherwise, if any argument has integer type or has type `double`, `fmod` is called. Otherwise, `fmodf` is called.

The floating-point remainder of the division operation `x / y` calculated by this function is exactly the value `x - n * y`, where `n` is `x / y` with its fractional part truncated.
本函式計算的除法操作 x / y 的浮點餘數恰好是值 x - n * y，其中 n 是截去小數部分後的 x / y。
The returned value has the same sign as `x` and is less or equal to `y` in magnitude.
回傳值的符號與 x 相同，且絕對值小於 |y|。

### Parameters

| x, y  |   | -  |   | floating-point values  |

### Return value

If successful, returns the floating-point remainder of the division `x / y` as defined above.
成功時，回傳上述定義的 x / y 浮點餘數。
If a domain error occurs, an implementation-defined value is returned (NaN where supported).
若發生定義域錯誤，回傳由實作定義的值（若支援則回傳 NaN）。
If a range error occurs due to underflow, the correct result (after rounding) is returned.
若因浮點下溢而發生值域錯誤，回傳正確結果（經捨入後）。

### Error handling

Errors are reported as specified in math_errhandling.
錯誤會依照 math_errhandling 的規定回報。
Domain error may occur if `y` is zero.
若 y 為零，可能會發生定義域錯誤。
If the implementation supports IEEE floating-point arithmetic (IEC 60559):
若實作支援 IEEE 浮點運算（IEC 60559）：

- If `x` is ±0 and `y` is not zero, ±0 is returned.
若 x 為 ±0 且 y 不為零，回傳 ±0。

- If `x` is ±∞ and `y` is not NaN, NaN is returned and FE_INVALID is raised.
若 x 為 ±∞ 且 y 不是 NaN，回傳 NaN 並引發 FE_INVALID。

- If `y` is ±0 and `x` is not NaN, NaN is returned and FE_INVALID is raised.
若 y 為 ±0 且 x 不是 NaN，回傳 NaN 並引發 FE_INVALID。

- If `y` is ±∞ and `x` is finite, `x` is returned.
若 y 為 ±∞ 且 x 是有限值，回傳 x。

- If either argument is NaN, NaN is returned.
若任一參數是 NaN，回傳 NaN。

### Notes

POSIX requires that a domain error occurs if `x` is infinite or `y` is zero.
POSIX 規定，x 為無窮大或 y 為零時會發生定義域錯誤。
`fmod`, but not remainder is useful for doing silent wrapping of floating-point types to unsigned integer types: `(0.0 <= (y = fmod(rint(x), 65536.0 )) ? y : 65536.0 + y)` is in the range `[``-0.0``, ``65535.0``]`, which corresponds to `unsigned short`, but `remainder(rint(x), 65536.0)` is in the range `[``-32767.0``, ``+32768.0``]`, which is outside of the range of `signed short`.
fmod（而非 remainder）可用來將浮點值靜默環繞至無號整數型別的範圍。例如，(0.0 <= (y = fmod(rint(x), 65536.0)) ? y : 65536.0 + y) 的結果介於 [-0.0, 65535.0]，可對應 unsigned short；remainder(rint(x), 65536.0) 的結果則介於 [-32767.0, +32768.0]，超出 signed short 的範圍。
The `double` version of `fmod` behaves as if implemented as follows:
fmod 的 double 版本行為等同於以下實作方式：

```c
double fmod(double x, double y) { #pragma STDC FENV_ACCESS ON  double result = remainder(fabs(x), (y = fabs(y)));  if (signbit(result))  result += y;  return copysign(result, x); }
```

### Example

Run this code

```c
#include <fenv.h> #include <math.h> #include <stdio.h> // #pragma STDC FENV_ACCESS ON int main(void) {  printf("fmod(+5.1, +3.0) = %.1f\n", fmod(5.1, 3));  printf("fmod(-5.1, +3.0) = %.1f\n", fmod(-5.1, 3));  printf("fmod(+5.1, -3.0) = %.1f\n", fmod(5.1, -3));  printf("fmod(-5.1, -3.0) = %.1f\n", fmod(-5.1, -3));  // special values  printf("fmod(+0.0, 1.0) = %.1f\n", fmod(0, 1));  printf("fmod(-0.0, 1.0) = %.1f\n", fmod(-0.0, 1));  printf("fmod(+5.1, Inf) = %.1f\n", fmod(5.1, INFINITY));  // error handling  feclearexcept(FE_ALL_EXCEPT);  printf("fmod(+5.1, 0) = %.1f\n", fmod(5.1, 0));  if (fetestexcept(FE_INVALID))  puts(" FE_INVALID raised"); }
```

Possible output:
可能的輸出：

```c
fmod(+5.1, +3.0) = 2.1 fmod(-5.1, +3.0) = -2.1 fmod(+5.1, -3.0) = 2.1 fmod(-5.1, -3.0) = -2.1 fmod(+0.0, 1.0) = 0.0 fmod(-0.0, 1.0) = -0.0 fmod(+5.1, Inf) = 5.1 fmod(+5.1, 0) = nan FE_INVALID raised
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.10.1 The fmod functions (p: TBD)
7.12.10.1 fmod 函式 (p: TBD)
7.12.10.1 fmod 函式 (p: TBD)

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.7.1 The fmod functions (p: TBD)
F.10.7.1 fmod 函式 (p: TBD)
F.10.7.1 fmod 函式 (p: TBD)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.10.1 The fmod functions (p: 185)
7.12.10.1 fmod 函式 (p: 185)
7.12.10.1 fmod 函式 (p: 185)

- 7.25 Type-generic math <tgmath.h> (p: 274-275)
7.25 型別通用數學 <tgmath.h> (p: 274-275)
7.25 型別通用數學 <tgmath.h> (p: 274-275)

- F.10.7.1 The fmod functions (p: 385)
F.10.7.1 fmod 函式 (p: 385)
F.10.7.1 fmod 函式 (p: 385)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.10.1 The fmod functions (p: 254)
7.12.10.1 fmod 函式 (p: 254)
7.12.10.1 fmod 函式 (p: 254)

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.7.1 The fmod functions (p: 528)
F.10.7.1 fmod 函式 (p: 528)
F.10.7.1 fmod 函式 (p: 528)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.10.1 The fmod functions (p: 235)
7.12.10.1 fmod 函式 (p: 235)
7.12.10.1 fmod 函式 (p: 235)

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- F.9.7.1 The fmod functions (p: 465)
F.9.7.1 fmod 函式 (p: 465)
F.9.7.1 fmod 函式 (p: 465)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.5.6.4 The fmod function
4.5.6.4 fmod 函式
4.5.6.4 fmod 函式

### See also

divldivlldiv
(C99)
|   | computes quotient and remainder of integer division
(function)   |

remainderremainderfremainderl
(C99)(C99)(C99)
|   | computes signed remainder of the floating-point division operation
(function)   |

remquoremquofremquol
(C99)(C99)(C99)
|   | computes signed remainder as well as the three last bits of the division operation
(function)   |

C++ documentation for fmod

---
來源頁路徑：`en.cppreference.com/c/numeric/math/fmod.html`

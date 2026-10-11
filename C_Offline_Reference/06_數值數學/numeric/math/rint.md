# rint, rintf, rintl, lrint, lrintf, lrintl, llrint, llrintf, llrintl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
float rintf( float arg );
```
|   |  (1)  |   |  (since C99)  |

```c
double rint( double arg );
```
|   |  (2)  |   |  (since C99)  |

```c
long double rintl( long double arg );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define rint( arg )
```
|   |  (4)  |   |  (since C99)  |

Defined in header `<math.h>`
|   |  |   |  |

```c
long lrintf( float arg );
```
|   |  (5)  |   |  (since C99)  |

```c
long lrint( double arg );
```
|   |  (6)  |   |  (since C99)  |

```c
long lrintl( long double arg );
```
|   |  (7)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define lrint( arg )
```
|   |  (8)  |   |  (since C99)  |

Defined in header `<math.h>`
|   |  |   |  |

```c
long long llrintf( float arg );
```
|   |  (9)  |   |  (since C99)  |

```c
long long llrint( double arg );
```
|   |  (10)  |   |  (since C99)  |

```c
long long llrintl( long double arg );
```
|   |  (11)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define llrint( arg )
```
|   |  (12)  |   |  (since C99)  |

|  |  |  |  |

1-3) Rounds the floating-point argument `arg` to an integer value in floating-point format, using the current rounding mode.

5-7, 9-11) Rounds the floating-point argument `arg` to an integer value in integer format, using the current rounding mode.

4,8,12) Type-generic macros: If `arg` has type `long double`, `rintl`, `lrintl`, `llrintl` is called. Otherwise, if `arg` has integer type or the type `double`, `rint`, `lrint`, `llrint` is called. Otherwise, `rintf`, `lrintf`, `llrintf` is called, respectively.

### Parameters

| arg  |   | -  |   | floating-point value  |

### Return value

If no errors occur, the nearest integer value to `arg`, according to the current rounding mode, is returned.
如果未發生錯誤，則按照目前舍入模式傳回最接近 arg 的整數值。

### Error handling

Errors are reported as specified in math_errhandling.
錯誤會依照 math_errhandling 的規定回報。
If the result of `lrint` or `llrint` is outside the range representable by the return type, a domain error or a range error may occur.
如果 lrint 或 llrint 的結果超出傳回型別可表示的範圍，則可能發生定義域錯誤或值域錯誤。
If the implementation supports IEEE floating-point arithmetic (IEC 60559),
若實作支援 IEEE 浮點運算（IEC 60559）：

For the `rint` function:
對於 rint 函式：

- If `arg` is ±∞, it is returned, unmodified.
若 arg 為 ±∞，則原樣回傳。

- If `arg` is ±0, it is returned, unmodified.
若 arg 為 ±0，則原樣回傳。

- If `arg` is NaN, NaN is returned.
如果 arg 為 NaN，則傳回 NaN。

For `lrint` and `llrint` functions:
對於 lrint 和 llrint 函式：

- If `arg` is ±∞, FE_INVALID is raised and an implementation-defined value is returned.
如果 arg 為 ±∞，則引發 FE_INVALID 並傳回由實現定義的值。

- If the result of the rounding is outside the range of the return type, FE_INVALID is raised and an implementation-defined value is returned.
如果舍入結果超出傳回型別的範圍，則引發 FE_INVALID 並傳回由實現定義的值。

- If `arg` is NaN, FE_INVALID is raised and an implementation-defined value is returned.
如果 arg 為 NaN，則引發 FE_INVALID 並傳回由實現定義的值。

### Notes

POSIX specifies that all cases where `lrint` or `llrint` raise FE_INEXACT are domain errors.
POSIX 規定，lrint 或 llrint 引發 FE_INEXACT 的所有情況均為定義域錯誤。
As specified in math_errhandling, FE_INEXACT may be (but isn't required to be on non-IEEE floating-point platforms) raised by `rint` when rounding a non-integer finite value.
如 math_errhandling 中所規定，rint 在對非整數有限值進行舍入時可能會引發 FE_INEXACT（但在非 IEEE 浮點平臺上不要求如此）。
The only difference between `rint` and nearbyint is that nearbyint never raises FE_INEXACT.
rint 與 nearbyint 的唯一區別在於 nearbyint 從不引發 FE_INEXACT 。
The largest representable floating-point values are exact integers in all standard floating-point formats, so `rint` never overflows on its own; however the result may overflow any integer type (including intmax_t), when stored in an integer variable.
在所有標準浮點格式中，可表示的最大浮點值都是精確整數，因此 rint 本身絕不會上溢；但當結果存入整數變數時，可能會超出任何整數型別（包括 intmax_t ）的範圍。
If the current rounding mode is...
如果目前舍入模式為……

- FE_DOWNWARD, then `rint` is equivalent to floor.
FE_DOWNWARD ，則 rint 等價於 floor 。

- FE_UPWARD, then `rint` is equivalent to ceil.
FE_UPWARD ，則 rint 等價於 ceil 。

- FE_TOWARDZERO, then `rint` is equivalent to trunc
FE_TOWARDZERO ，則 rint 等價於 trunc

- FE_TONEAREST, then `rint` differs from round in that halfway cases are rounded to even rather than away from zero.
FE_TONEAREST ，則 rint 與 round 的區別在於：對恰好居中的情況，rint 舍入到最接近的偶數，而不是遠離零。

### Example

Run this code

```c
#include <fenv.h> #include <limits.h> #include <math.h> #include <stdio.h> int main(void) { #pragma STDC FENV_ACCESS ON  fesetround(FE_TONEAREST);  printf("rounding to nearest (halfway cases to even):\n"  "rint(+2.3) = %+.1f ", rint(2.3));  printf("rint(+2.5) = %+.1f ", rint(2.5));  printf("rint(+3.5) = %+.1f\n", rint(3.5));  printf("rint(-2.3) = %+.1f ", rint(-2.3));  printf("rint(-2.5) = %+.1f ", rint(-2.5));  printf("rint(-3.5) = %+.1f\n", rint(-3.5));  fesetround(FE_DOWNWARD);  printf("rounding down: \nrint(+2.3) = %+.1f ", rint(2.3));  printf("rint(+2.5) = %+.1f ", rint(2.5));  printf("rint(+3.5) = %+.1f\n", rint(3.5));  printf("rint(-2.3) = %+.1f ", rint(-2.3));  printf("rint(-2.5) = %+.1f ", rint(-2.5));  printf("rint(-3.5) = %+.1f\n", rint(-3.5));  printf("rounding down with lrint: \nlrint(+2.3) = %ld ", lrint(2.3));  printf("lrint(+2.5) = %ld ", lrint(2.5));  printf("lrint(+3.5) = %ld\n", lrint(3.5));  printf("lrint(-2.3) = %ld ", lrint(-2.3));  printf("lrint(-2.5) = %ld ", lrint(-2.5));  printf("lrint(-3.5) = %ld\n", lrint(-3.5));  printf("lrint(-0.0) = %ld\n", lrint(-0.0));  printf("lrint(-Inf) = %ld\n", lrint(-INFINITY)); // FE_INVALID raised  // error handling  feclearexcept(FE_ALL_EXCEPT);  printf("rint(1.1) = %.1f\n", rint(1.1));  if (fetestexcept(FE_INEXACT))  puts(" FE_INEXACT was raised");  feclearexcept(FE_ALL_EXCEPT);  printf("lrint(LONG_MIN-2048.0) = %ld\n", lrint(LONG_MIN-2048.0));  if (fetestexcept(FE_INVALID))  puts(" FE_INVALID was raised"); }
```

Possible output:
可能的輸出：

```c
rounding to nearest (halfway cases to even): rint(+2.3) = +2.0 rint(+2.5) = +2.0 rint(+3.5) = +4.0 rint(-2.3) = -2.0 rint(-2.5) = -2.0 rint(-3.5) = -4.0 rounding down: rint(+2.3) = +2.0 rint(+2.5) = +2.0 rint(+3.5) = +3.0 rint(-2.3) = -3.0 rint(-2.5) = -3.0 rint(-3.5) = -4.0 rounding down with lrint: lrint(+2.3) = 2 lrint(+2.5) = 2 lrint(+3.5) = 3 lrint(-2.3) = -3 lrint(-2.5) = -3 lrint(-3.5) = -4 lrint(-0.0) = 0 lrint(-Inf) = -9223372036854775808 rint(1.1) = 1.0 FE_INEXACT was raised lrint(LONG_MIN-2048.0) = -9223372036854775808 FE_INVALID was raised
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.9.4 The rint functions (p: TBD)
7.12.9.4 rint 函式（p: TBD）
7.12.9.4 rint 函式（p: TBD）

- 7.12.9.5 The lrint and llrint functions (p: TBD)
7.12.9.5 lrint 和 llrint 函式（p: TBD）
7.12.9.5 lrint 和 llrint 函式（p: TBD）

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.6.4 The rint functions (p: TBD)
F.10.6.4 rint 函式（p: TBD）
F.10.6.4 rint 函式（p: TBD）

- F.10.6.5 The lrint and llrint functions (p: TBD)
F.10.6.5 lrint 和 llrint 函式（p: TBD）
F.10.6.5 lrint 和 llrint 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.9.4 The rint functions (p: 184)
7.12.9.4 rint 函式（p: 184）
7.12.9.4 rint 函式（p: 184）

- 7.12.9.5 The lrint and llrint functions (p: 184)
7.12.9.5 lrint 和 llrint 函式（p: 184）
7.12.9.5 lrint 和 llrint 函式（p: 184）

- 7.25 Type-generic math <tgmath.h> (p: 272-273)
7.25 型別通用數學 <tgmath.h> (p: 272-273)
7.25 型別通用數學 <tgmath.h> (p: 272-273)

- F.10.6.4 The rint functions (p: 384)
F.10.6.4 rint 函式（p: 384）
F.10.6.4 rint 函式（p: 384）

- F.10.6.5 The lrint and llrint functions (p: 384)
F.10.6.5 lrint 和 llrint 函式（p: 384）
F.10.6.5 lrint 和 llrint 函式（p: 384）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.9.4 The rint functions (p: 252)
7.12.9.4 rint 函式（p: 252）
7.12.9.4 rint 函式（p: 252）

- 7.12.9.5 The lrint and llrint functions (p: 252)
7.12.9.5 lrint 和 llrint 函式（p: 252）
7.12.9.5 lrint 和 llrint 函式（p: 252）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.6.4 The rint functions (p: 527)
F.10.6.4 rint 函式（p: 527）
F.10.6.4 rint 函式（p: 527）

- F.10.6.5 The lrint and llrint functions (p: 527)
F.10.6.5 lrint 和 llrint 函式（p: 527）
F.10.6.5 lrint 和 llrint 函式（p: 527）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.9.4 The rint functions (p: 232-233)
7.12.9.4 rint 函式（p: 232-233）
7.12.9.4 rint 函式（p: 232-233）

- 7.12.9.5 The lrint and llrint functions (p: 233)
7.12.9.5 lrint 和 llrint 函式（p: 233）
7.12.9.5 lrint 和 llrint 函式（p: 233）

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- F.9.6.4 The rint functions (p: 463)
F.9.6.4 rint 函式（p: 463）
F.9.6.4 rint 函式（p: 463）

- F.9.6.5 The lrint and llrint functions (p: 463)
F.9.6.5 lrint 和 llrint 函式（p: 463）
F.9.6.5 lrint 和 llrint 函式（p: 463）

### See also

trunctruncftruncl
(C99)(C99)(C99)
|   | rounds to nearest integer not greater in magnitude than the given value
(function)   |

nearbyintnearbyintfnearbyintl
(C99)(C99)(C99)
|   | rounds to an integer using current rounding mode
(function)   |

fegetroundfesetround
(C99)(C99)
|   | gets or sets rounding direction
(function)   |

C++ documentation for rint

---
來源頁路徑：`en.cppreference.com/c/numeric/math/rint.html`

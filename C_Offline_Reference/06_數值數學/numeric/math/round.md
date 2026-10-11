# round, roundf, roundl, lround, lroundf, lroundl, llround, llroundf, llroundl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
float roundf( float arg );
```
|   |  (1)  |   |  (since C99)  |

```c
double round( double arg );
```
|   |  (2)  |   |  (since C99)  |

```c
long double roundl( long double arg );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define round( arg )
```
|   |  (4)  |   |  (since C99)  |

Defined in header `<math.h>`
|   |  |   |  |

```c
long lroundf( float arg );
```
|   |  (5)  |   |  (since C99)  |

```c
long lround( double arg );
```
|   |  (6)  |   |  (since C99)  |

```c
long lroundl( long double arg );
```
|   |  (7)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define lround( arg )
```
|   |  (8)  |   |  (since C99)  |

Defined in header `<math.h>`
|   |  |   |  |

```c
long long llroundf( float arg );
```
|   |  (9)  |   |  (since C99)  |

```c
long long llround( double arg );
```
|   |  (10)  |   |  (since C99)  |

```c
long long llroundl( long double arg );
```
|   |  (11)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define llround( arg )
```
|   |  (12)  |   |  (since C99)  |

|  |  |  |  |

1-3) Computes the nearest integer value to `arg` (in floating-point format), rounding halfway cases away from zero, regardless of the current rounding mode.

5-7, 9-11) Computes the nearest integer value to `arg` (in integer format), rounding halfway cases away from zero, regardless of the current rounding mode.

4,8,12) Type-generic macros: If `arg` has type `long double`, `roundl`, `lroundl`, `llroundl` is called. Otherwise, if `arg` has integer type or the type `double`, `round`, `lround`, `llround` is called. Otherwise, `roundf`, `lroundf`, `llroundf` is called, respectively.

### Parameters

| arg  |   | -  |   | floating-point value  |

### Return value

If no errors occur, the nearest integer value to `arg`, rounding halfway cases away from zero, is returned.
若沒有發生錯誤，回傳最接近 arg 的整數；若剛好在兩個整數中間，則朝遠離零的方向捨入。

Return value

Argument

If a domain error occurs, an implementation-defined value is returned.
若發生定義域錯誤，回傳由實作定義的值。

### Error handling

Errors are reported as specified in math_errhandling.
錯誤會依照 math_errhandling 的規定回報。
If the result of `lround` or `llround` is outside the range representable by the return type, a domain error or a range error may occur.
若 lround 或 llround 的結果超出回傳型別可表示的範圍，可能會發生定義域錯誤或值域錯誤。
If the implementation supports IEEE floating-point arithmetic (IEC 60559):
若實作支援 IEEE 浮點運算（IEC 60559）：

For the `round`, `roundf`, and `roundl` function:
- The current rounding mode has no effect.
目前的捨入模式不會影響結果。

- If `arg` is ±∞, it is returned, unmodified.
若 arg 為 ±∞，則原樣回傳。

- If `arg` is ±0, it is returned, unmodified.
若 arg 為 ±0，則原樣回傳。

- If `arg` is NaN, NaN is returned.
若 arg 為 NaN，回傳 NaN。
對 round、roundf 和 roundl 而言，目前的捨入模式不影響結果。若 arg 為 ±∞ 或 ±0，則原樣回傳；若 arg 是 NaN，則回傳 NaN。
For `lround` and `llround` families of functions:
- FE_INEXACT is never raised.
永遠不會引發 FE_INEXACT。

- The current rounding mode has no effect.
目前的捨入模式不會影響結果。

- If `arg` is ±∞, FE_INVALID is raised and an implementation-defined value is returned
若 arg 為 ±∞，會引發 FE_INVALID，並回傳由實作定義的值。

- If the result of the rounding is outside the range of the return type, FE_INVALID is raised and an implementation-defined value is returned.
若捨入後的結果超出回傳型別的範圍，會引發 FE_INVALID，並回傳由實作定義的值。

- If `arg` is NaN, FE_INVALID is raised and an implementation-defined value is returned.
若 arg 是 NaN，會引發 FE_INVALID，並回傳由實作定義的值。
對 lround 和 llround 系列函式而言，永遠不會引發 FE_INEXACT，且目前的捨入模式不影響結果。若 arg 為 ±∞、捨入結果超出回傳型別範圍，或 arg 是 NaN，則會引發 FE_INVALID，並回傳由實作定義的值。

### Notes

FE_INEXACT may be (but isn't required to be) raised by `round` when rounding a non-integer finite value.
round 將有限的非整數捨入時，可能會引發 FE_INEXACT，但標準不要求一定引發。
The largest representable floating-point values are exact integers in all standard floating-point formats, so `round` never overflows on its own; however the result may overflow any integer type (including intmax_t), when stored in an integer variable.
在所有標準浮點格式中，可表示的最大浮點值都是精確整數，因此 round 本身不會溢位；但若將結果存入整數變數，仍可能超出任何整數型別（包括 intmax_t）的範圍。
POSIX specifies that all cases where `lround` or `llround` raise FE_INVALID are domain errors.
POSIX 規定，lround 或 llround 只要引發 FE_INVALID，就屬於定義域錯誤。
The `double` version of `round` behaves as if implemented as follows:
round 的 double 版本行為等同於以下實作方式：

```c
#include <math.h> #pragma STDC FENV_ACCESS ON double round(double x) {  return signbit(x) ? ceil(x - 0.5) : floor(x + 0.5); }
```

### Example

Run this code

```c
#include <assert.h> #include <fenv.h> #include <float.h> #include <limits.h> #include <math.h> #include <stdio.h> // #pragma STDC FENV_ACCESS ON double custom_round(double x) {  return signbit(x) ? ceil(x - 0.5) : floor(x + 0.5); } void test_custom_round() {  const double sample[] =  {  0.0, 2.3, 2.5 - DBL_EPSILON, 2.5, 2.5 + DBL_EPSILON, 2.7, INFINITY  };  for (size_t t = 0; t < sizeof sample / sizeof(double); ++t)  assert(round(+sample[t]) == custom_round(+sample[t]) &&  round(-sample[t]) == custom_round(-sample[t])); } int main(void) {  // round  printf("round(+2.3) = %+.1f ", round(2.3));  printf("round(+2.5) = %+.1f ", round(2.5));  printf("round(+2.7) = %+.1f\n", round(2.7));  printf("round(-2.3) = %+.1f ", round(-2.3));  printf("round(-2.5) = %+.1f ", round(-2.5));  printf("round(-2.7) = %+.1f\n", round(-2.7));  printf("round(-0.0) = %+.1f\n", round(-0.0));  printf("round(-Inf) = %+f\n", round(-INFINITY));  test_custom_round();  // lround  printf("lround(+2.3) = %+ld ", lround(2.3));  printf("lround(+2.5) = %+ld ", lround(2.5));  printf("lround(+2.7) = %+ld\n", lround(2.7));  printf("lround(-2.3) = %+ld ", lround(-2.3));  printf("lround(-2.5) = %+ld ", lround(-2.5));  printf("lround(-2.7) = %+ld\n", lround(-2.7));  printf("lround(-0.0) = %+ld\n", lround(-0.0));  printf("lround(-Inf) = %+ld\n", lround(-INFINITY)); // FE_INVALID raised  // error handling  feclearexcept(FE_ALL_EXCEPT);  printf("lround(LONG_MAX+1.5) = %ld\n", lround(LONG_MAX + 1.5));  if (fetestexcept(FE_INVALID))  puts(" FE_INVALID was raised"); }
```

Possible output:
可能的輸出：

```c
round(+2.3) = +2.0 round(+2.5) = +3.0 round(+2.7) = +3.0 round(-2.3) = -2.0 round(-2.5) = -3.0 round(-2.7) = -3.0 round(-0.0) = -0.0 round(-Inf) = -inf lround(+2.3) = +2 lround(+2.5) = +3 lround(+2.7) = +3 lround(-2.3) = -2 lround(-2.5) = -3 lround(-2.7) = -3 lround(-0.0) = +0 lround(-Inf) = -9223372036854775808 lround(LONG_MAX+1.5) = -9223372036854775808 FE_INVALID was raised
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.9.6 The round functions (p: TBD)
7.12.9.6 round 函式（p: TBD）
7.12.9.6 round 函式（p: TBD）

- 7.12.9.7 The lround and llround functions (p: TBD)
7.12.9.7 lround 和 llround 函式（p: TBD）
7.12.9.7 lround 和 llround 函式（p: TBD）

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.6.6 The round functions (p: TBD)
F.10.6.6 round 函式（p: TBD）
F.10.6.6 round 函式（p: TBD）

- F.10.6.7 The lround and llround functions (p: TBD)
F.10.6.7 lround 和 llround 函式（p: TBD）
F.10.6.7 lround 和 llround 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.9.6 The round functions (p: 184)
7.12.9.6 round 函式（p: 184）
7.12.9.6 round 函式（p: 184）

- 7.12.9.7 The lround and llround functions (p: 184-185)
7.12.9.7 lround 和 llround 函式（p: 184-185）
7.12.9.7 lround 和 llround 函式（p: 184-185）

- 7.25 Type-generic math <tgmath.h> (p: 272-273)
7.25 型別通用數學 <tgmath.h> (p: 272-273)
7.25 型別通用數學 <tgmath.h> (p: 272-273)

- F.10.6.6 The round functions (p: 384)
F.10.6.6 round 函式（p: 384）
F.10.6.6 round 函式（p: 384）

- F.10.6.7 The lround and llround functions (p: 385)
F.10.6.7 lround 和 llround 函式（p: 385）
F.10.6.7 lround 和 llround 函式（p: 385）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.9.6 The round functions (p: 253)
7.12.9.6 round 函式（p: 253）
7.12.9.6 round 函式（p: 253）

- 7.12.9.7 The lround and llround functions (p: 253)
7.12.9.7 lround 和 llround 函式（p: 253）
7.12.9.7 lround 和 llround 函式（p: 253）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.6.6 The round functions (p: 527)
F.10.6.6 round 函式（p: 527）
F.10.6.6 round 函式（p: 527）

- F.10.6.7 The lround and llround functions (p: 528)
F.10.6.7 lround 和 llround 函式（p: 528）
F.10.6.7 lround 和 llround 函式（p: 528）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.9.6 The round functions (p: 233)
7.12.9.6 round 函式（p: 233）
7.12.9.6 round 函式（p: 233）

- 7.12.9.7 The lround and llround functions (p: 234)
7.12.9.7 lround 和 llround 函式（p: 234）
7.12.9.7 lround 和 llround 函式（p: 234）

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- F.9.6.6 The round functions (p: 464)
F.9.6.6 round 函式（p: 464）
F.9.6.6 round 函式（p: 464）

- F.9.6.7 The lround and llround functions (p: 464)
F.9.6.7 lround 和 llround 函式（p: 464）
F.9.6.7 lround 和 llround 函式（p: 464）

### See also

floorfloorffloorl
(C99)(C99)
|   | computes largest integer not greater than the given value
(function)   |

ceilceilfceill
(C99)(C99)
|   | computes smallest integer not less than the given value
(function)   |

trunctruncftruncl
(C99)(C99)(C99)
|   | rounds to nearest integer not greater in magnitude than the given value
(function)   |

C++ documentation for round

---
來源頁路徑：`en.cppreference.com/c/numeric/math/round.html`

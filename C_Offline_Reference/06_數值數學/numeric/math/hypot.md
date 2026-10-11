# hypot, hypotf, hypotl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
float hypotf( float x, float y );
```
|   |  (1)  |   |  (since C99)  |

```c
double hypot( double x, double y );
```
|   |  (2)  |   |  (since C99)  |

```c
long double hypotl( long double x, long double y );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define hypot( x, y )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Computes the square root of the sum of the squares of `x` and `y`, without undue overflow or underflow at intermediate stages of the computation.

4) Type-generic macro: If any argument has type `long double`, the long double version of the function is called. Otherwise, if any argument has integer type or has type `double`, the double version of the function is called. Otherwise, the `float` version of the function is called.

The value computed by this function is the length of the hypotenuse of a right-angled triangle with sides of length `x` and `y`, or the distance of the point `(x, y)` from the origin `(0, 0)`, or the magnitude of a complex number `x+*i*y`.
本函式計算直角邊長分別為 x 和 y 的直角三角形之斜邊長，也就是點 (x, y) 到原點 (0, 0) 的距離，或複數 x + iy 的模。

### Parameters

| x  |   | -  |   | floating-point value  |

| y  |   | -  |   | floating-point value  |

### Return value

If no errors occur, the hypotenuse of a right-angled triangle, √x2+y2x2+y2√x2
+y2
, is returned.
若沒有發生錯誤，回傳直角三角形的斜邊長 √(x² + y²)。
If a range error due to overflow occurs, +HUGE_VAL, `+HUGE_VALF`, or `+HUGE_VALL` is returned.
若因浮點溢位而發生值域錯誤，回傳 +HUGE_VAL、+HUGE_VALF 或 +HUGE_VALL。
If a range error due to underflow occurs, the correct result (after rounding) is returned.
若因浮點下溢而發生值域錯誤，回傳正確結果（經捨入後）。

### Error handling

Errors are reported as specified in math_errhandling.
錯誤會依照 math_errhandling 的規定回報。
If the implementation supports IEEE floating-point arithmetic (IEC 60559),
若實作支援 IEEE 浮點運算（IEC 60559）：

- `hypot(x, y)`, `hypot(y, x)`, and `hypot(x, -y)` are equivalent
hypot(x, y)、hypot(y, x) 和 hypot(x, -y) 的結果相同。

- if one of the arguments is ±0, `hypot` is equivalent to `fabs` called with the non-zero argument
若其中一個參數為 ±0，hypot 的結果等同於對另一個參數呼叫 fabs。

- if one of the arguments is ±∞, `hypot` returns +∞ even if the other argument is NaN
若其中一個參數為 ±∞，即使另一個參數是 NaN，hypot 仍會回傳 +∞。

- otherwise, if any of the arguments is NaN, NaN is returned.
否則，只要任一參數是 NaN，就回傳 NaN。

### Notes

Implementations usually guarantee precision of less than 1 ulp (units in the last place): GNU, BSD.
部分實作（例如 GNU 和 BSD）通常保證精度優於 1 ulp（最後一位的單位）。
`hypot(x, y)` is equivalent to `cabs(x + I*y)`.
hypot(x, y) 等同於 cabs(x + I * y)。
POSIX specifies that underflow may only occur when both arguments are subnormal and the correct result is also subnormal (this forbids naive implementations).
POSIX 規定，只有當兩個參數和正確結果都是非正規數時才可能發生下溢；這項要求排除了過於簡單的實作方式。
`hypot(INFINITY, NAN)` returns +∞, but `sqrt(INFINITY * INFINITY + NAN * NAN)` returns NaN.
hypot(INFINITY, NAN) 會回傳 +∞；但 sqrt(INFINITY * INFINITY + NAN * NAN) 會回傳 NaN。

### Example

Run this code

```c
#include <errno.h> #include <fenv.h> #include <float.h> #include <math.h> #include <stdio.h> // #pragma STDC FENV_ACCESS ON int main(void) {  // typical usage  printf("(1,1) cartesian is (%f,%f) polar\n", hypot(1,1), atan2(1, 1));    // special values  printf("hypot(NAN,INFINITY) = %f\n", hypot(NAN, INFINITY));    // error handling  errno = 0;  feclearexcept(FE_ALL_EXCEPT);  printf("hypot(DBL_MAX,DBL_MAX) = %f\n", hypot(DBL_MAX, DBL_MAX));  if (errno == ERANGE)  perror(" errno == ERANGE");  if (fetestexcept(FE_OVERFLOW))  puts(" FE_OVERFLOW raised"); }
```

Possible output:
可能的輸出：

```c
(1,1) cartesian is (1.414214,0.785398) polar hypot(NAN,INFINITY) = inf hypot(DBL_MAX,DBL_MAX) = inf errno == ERANGE: Numerical result out of range FE_OVERFLOW raised
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.7.3 The hypot functions (p: TBD)
7.12.7.3 hypot 函式（p: TBD）
7.12.7.3 hypot 函式（p: TBD）

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.4.3 The hypot functions (p: TBD)
F.10.4.3 hypot 函式（p: TBD）
F.10.4.3 hypot 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.7.3 The hypot functions (p: 181)
7.12.7.3 hypot 函式（p: 181）
7.12.7.3 hypot 函式（p: 181）

- 7.25 Type-generic math <tgmath.h> (p: 272-273)
7.25 型別通用數學 <tgmath.h> (p: 272-273)
7.25 型別通用數學 <tgmath.h> (p: 272-273)

- F.10.4.3 The hypot functions (p: 382)
F.10.4.3 hypot 函式（p: 382）
F.10.4.3 hypot 函式（p: 382）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.7.3 The hypot functions (p: 248)
7.12.7.3 hypot 函式（p: 248）
7.12.7.3 hypot 函式（p: 248）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.4.3 The hypot functions (p: 524)
F.10.4.3 hypot 函式（p: 524）
F.10.4.3 hypot 函式（p: 524）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.7.3 The hypot functions (p: 229)
7.12.7.3 hypot 函式（p: 229）
7.12.7.3 hypot 函式（p: 229）

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- F.9.4.3 The hypot functions (p: 461)
F.9.4.3 hypot 函式（p: 461）
F.9.4.3 hypot 函式（p: 461）

### See also

powpowfpowl
(C99)(C99)
|   | computes a number raised to the given power (xyxyx)
(function)   |

sqrtsqrtfsqrtl
(C99)(C99)
|   | computes square root (√xx√x)
(function)   |

cbrtcbrtfcbrtl
(C99)(C99)(C99)
|   | computes cube root (3√xx33√x)
(function)   |

cabscabsfcabsl
(C99)(C99)(C99)
|   | computes the magnitude of a complex number
(function)   |

C++ documentation for hypot

---
來源頁路徑：`en.cppreference.com/c/numeric/math/hypot.html`

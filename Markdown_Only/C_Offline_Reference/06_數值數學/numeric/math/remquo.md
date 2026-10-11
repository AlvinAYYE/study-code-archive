# remquo, remquof, remquol

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
float remquof( float x, float y, int *quo );
```
|   |  (1)  |   |  (since C99)  |

```c
double remquo( double x, double y, int *quo );
```
|   |  (2)  |   |  (since C99)  |

```c
long double remquol( long double x, long double y, int *quo );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define remquo( x, y, quo )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Computes the floating-point remainder of the division operation `x/y` as the remainder() function does. Additionally, the sign and at least the three of the last bits of `x/y` will be stored in `quo`, sufficient to determine the octant of the result within a period.

4) Type-generic macro: If any non-pointer argument has type `long double`, `remquol` is called. Otherwise, if any non-pointer argument has integer type or has type `double`, `remquo` is called. Otherwise, `remquof` is called.

### Parameters

| x, y  |   | -  |   | floating-point values  |

| quo  |   | -  |   | pointer to an integer value to store the sign and some bits of `x/y`  |

### Return value

If successful, returns the floating-point remainder of the division `x/y` as defined in remainder, and stores, in `*quo`, the sign and at least three of the least significant bits of `x/y` (formally, stores a value whose sign is the sign of `x/y` and whose magnitude is congruent modulo 2n
to the magnitude of the integral quotient of `x/y`, where n is an implementation-defined integer greater than or equal to 3).
成功時，回傳 remainder 所定義的 x / y 浮點餘數，並將 x / y 的商之符號和至少三個最低有效位元存入 *quo。更精確地說，存入的值與 x / y 同號，其絕對值對 2ⁿ 取模後，等於整數商絕對值對 2ⁿ 取模的結果；n 由實作定義，且至少為 3。
If `y` is zero, the value stored in `*quo` is unspecified.
若 y 為零，*quo 中的值未指定。
If a domain error occurs, an implementation-defined value is returned (NaN where supported).
若發生定義域錯誤，回傳由實作定義的值（若支援則回傳 NaN）。
If a range error occurs due to underflow, the correct result is returned if subnormals are supported.
若因下溢而發生值域錯誤，且實作支援非正規數，則回傳正確結果。
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

- FE_INEXACT is never raised
永遠不會引發 FE_INEXACT。

- If `x` is ±∞ and `y` is not NaN, NaN is returned and FE_INVALID is raised
若 x 為 ±∞ 且 y 不是 NaN，回傳 NaN 並引發 FE_INVALID。

- If `y` is ±0 and `x` is not NaN, NaN is returned and FE_INVALID is raised
若 y 為 ±0 且 x 不是 NaN，回傳 NaN 並引發 FE_INVALID。

- If either `x` or `y` is NaN, NaN is returned
若 x 或 y 任一個是 NaN，回傳 NaN。

### Notes

POSIX requires that a domain error occurs if `x` is infinite or `y` is zero.
POSIX 規定，x 為無窮大或 y 為零時會發生定義域錯誤。
This function is useful when implementing periodic functions with the period exactly representable as a floating-point value: when calculating sin(πx) for a very large `x`, calling sin directly may result in a large error, but if the function argument is first reduced with `remquo`, the low-order bits of the quotient may be used to determine the sign and the octant of the result within the period, while the remainder may be used to calculate the value with high precision.
若週期函式的週期可用浮點值精確表示，remquo 就很有用。例如，計算很大的 x 所對應的 sin(πx) 時，直接呼叫 sin 可能產生較大誤差；先用 remquo 將參數約化，便可利用商的低位元判斷結果在週期中的符號與區段，再用餘數精確計算函式值。
On some platforms this operation is supported by hardware (and, for example, on Intel CPU, `FPREM1` leaves exactly 3 bits of precision in the quotient).
某些平臺有硬體支援這項運算，例如 Intel CPU 的 FPREM1 會在商中保留恰好 3 位精度。

### Example

Run this code

```c
#include <fenv.h> #include <math.h> #include <stdio.h> #ifndef __GNUC__ #pragma STDC FENV_ACCESS ON #endif double cos_pi_x_naive(double x) {  const double pi = acos(-1);  return cos(pi * x); } // the period is 2, values are (0;0.5) positive, (0.5;1.5) negative, (1.5,2) positive double cos_pi_x_smart(double x) {  const double pi = acos(-1);  int extremum;  double rem = remquo(x, 1, &extremum);  extremum = (unsigned)extremum % 2; // keep 1 bit to determine nearest extremum  return extremum ? -cos(pi * rem) : cos(pi * rem); } int main(void) {  printf("cos(pi * 0.25) = %f\n", cos_pi_x_naive(0.25));  printf("cos(pi * 1.25) = %f\n", cos_pi_x_naive(1.25));  printf("cos(pi * 1000000000000.25) = %f\n", cos_pi_x_naive(1000000000000.25));  printf("cos(pi * 1000000000001.25) = %f\n", cos_pi_x_naive(1000000000001.25));  printf("cos(pi * 1000000000000.25) = %f\n", cos_pi_x_smart(1000000000000.25));  printf("cos(pi * 1000000000001.25) = %f\n", cos_pi_x_smart(1000000000001.25));  // error handling  feclearexcept(FE_ALL_EXCEPT);  int quo;  printf("remquo(+Inf, 1) = %.1f\n", remquo(INFINITY, 1, &quo));  if (fetestexcept(FE_INVALID))  puts(" FE_INVALID raised"); }
```

Possible output:
可能的輸出：

```c
cos(pi * 0.25) = 0.707107 cos(pi * 1.25) = -0.707107 cos(pi * 1000000000000.25) = 0.707123 cos(pi * 1000000000001.25) = -0.707117 cos(pi * 1000000000000.25) = 0.707107 cos(pi * 1000000000001.25) = -0.707107 remquo(+Inf, 1) = -nan FE_INVALID raised
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.10.3 The remquo functions (p: TBD)
7.12.10.3 remquo 函式（p: TBD）
7.12.10.3 remquo 函式（p: TBD）

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.7.3 The remquo functions (p: TBD)
F.10.7.3 remquo 函式（p: TBD）
F.10.7.3 remquo 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.10.3 The remquo functions (p: 186)
7.12.10.3 remquo 函式（p: 186）
7.12.10.3 remquo 函式（p: 186）

- 7.25 Type-generic math <tgmath.h> (p: 272-273)
7.25 型別通用數學 <tgmath.h> (p: 272-273)
7.25 型別通用數學 <tgmath.h> (p: 272-273)

- F.10.7.3 The remquo functions (p: 385)
F.10.7.3 remquo 函式（p: 385）
F.10.7.3 remquo 函式（p: 385）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.10.3 The remquo functions (p: 255)
7.12.10.3 remquo 函式（p: 255）
7.12.10.3 remquo 函式（p: 255）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.7.3 The remquo functions (p: 529)
F.10.7.3 remquo 函式（p: 529）
F.10.7.3 remquo 函式（p: 529）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.10.3 The remquo functions (p: 236)
7.12.10.3 remquo 函式（p: 236）
7.12.10.3 remquo 函式（p: 236）

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- F.9.7.3 The remquo functions (p: 465)
F.9.7.3 remquo 函式（p: 465）
F.9.7.3 remquo 函式（p: 465）

### See also

divldivlldiv
(C99)
|   | computes quotient and remainder of integer division
(function)   |

fmodfmodffmodl
(C99)(C99)
|   | computes remainder of the floating-point division operation
(function)   |

remainderremainderfremainderl
(C99)(C99)(C99)
|   | computes signed remainder of the floating-point division operation
(function)   |

C++ documentation for remquo

---
來源頁路徑：`en.cppreference.com/c/numeric/math/remquo.html`

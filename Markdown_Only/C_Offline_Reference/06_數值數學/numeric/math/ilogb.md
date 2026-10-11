# ilogb, ilogbf, ilogbl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
int ilogbf( float arg );
```
|   |  (1)  |   |  (since C99)  |

```c
int ilogb( double arg );
```
|   |  (2)  |   |  (since C99)  |

```c
int ilogbl( long double arg );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define ilogb( arg )
```
|   |  (4)  |   |  (since C99)  |

Defined in header `<math.h>`
|   |  |   |  |

```c
#define FP_ILOGB0 /* implementation-defined */
```
|   |  (5)  |   |  (since C99)  |

```c
#define FP_ILOGBNAN /* implementation-defined */
```
|   |  (6)  |   |  (since C99)  |

|  |  |  |  |

1-3) Extracts the value of the unbiased exponent from the floating-point argument `arg`, and returns it as a signed integer value.

4) Type-generic macros: If `arg` has type `long double`, `ilogbl` is called. Otherwise, if `arg` has integer type or the type `double`, `ilogb` is called. Otherwise, `ilogbf` is called.

5) Expands to integer constant expression whose value is either INT_MIN or `-INT_MAX`.

6) Expands to integer constant expression whose value is either INT_MIN or `+INT_MAX`.

Formally, the unbiased exponent is the integral part of logr|arg| as a signed integral value, for non-zero `arg`, where `r` is FLT_RADIX.
正式定義中，非零 arg 的無偏指數是 log₍FLT_RADIX₎|arg| 的整數部分，以有號整數表示。

### Parameters

| arg  |   | -  |   | floating-point value  |

### Return value

If no errors occur, the unbiased exponent of `arg` is returned as a signed int value.
若沒有發生錯誤，以有號 int 回傳 arg 的無偏指數。
If `arg` is zero, FP_ILOGB0 is returned.
若 arg 為零，回傳 FP_ILOGB0。
If `arg` is infinite, INT_MAX is returned.
若 arg 為無窮大，回傳 INT_MAX。
If `arg` is a NaN, FP_ILOGBNAN is returned.
若 arg 為 NaN，回傳 FP_ILOGBNAN。
If the correct result is greater than INT_MAX or smaller than INT_MIN, the return value is unspecified and a domain error or range error may occur.
若正確結果大於 INT_MAX 或小於 INT_MIN，回傳值未指定，也可能發生定義域錯誤或值域錯誤。

### Error handling

Errors are reported as specified in math_errhandling.
錯誤會依照 math_errhandling 的規定回報。
A domain error or range error may occur if `arg` is zero, infinite, or NaN.
若 arg 為零、無窮大或 NaN，可能會發生定義域錯誤或值域錯誤。
If the correct result is greater than INT_MAX or smaller than INT_MIN, a domain error or a range error may occur
若正確結果大於 INT_MAX 或小於 INT_MIN，可能會發生定義域錯誤或值域錯誤。
If the implementation supports IEEE floating-point arithmetic (IEC 60559),
若實作支援 IEEE 浮點運算（IEC 60559）：

- If the correct result is greater than INT_MAX or smaller than INT_MIN, FE_INVALID is raised.
若正確結果大於 INT_MAX 或小於 INT_MIN，會引發 FE_INVALID。

- If `arg` is ±0, ±∞, or NaN, FE_INVALID is raised.
若 arg 為 ±0、±∞ 或 NaN，會引發 FE_INVALID。

- In all other cases, the result is exact (FE_INEXACT is never raised) and the current rounding mode is ignored.
其他情況下，結果都是精確值（不會引發 FE_INEXACT），且不受目前捨入模式影響。

### Notes

If `arg` is not zero, infinite, or NaN, the value returned is exactly equivalent to `(int)logb(arg)`.
若 arg 不是零、無窮大或 NaN，回傳值等同於 (int)logb(arg)。
POSIX requires that a domain error occurs if `arg` is zero, infinite, NaN, or if the correct result is outside of the range of `int`.
POSIX 規定，arg 為零、無窮大或 NaN，或正確結果超出 int 範圍時，會發生定義域錯誤。
POSIX also requires that, on XSI-conformant systems, the value returned when the correct result is greater than INT_MAX is INT_MAX and the value returned when the correct result is less than INT_MIN is INT_MIN.
POSIX 另規定，在符合 XSI 的系統上，正確結果大於 INT_MAX 時回傳 INT_MAX；小於 INT_MIN 時則回傳 INT_MIN。
The correct result can be represented as `int` on all known implementations. For overflow to occur, INT_MAX must be less than `LDBL_MAX_EXP * log2(FLT_RADIX)` or INT_MIN must be greater than `LDBL_MIN_EXP - LDBL_MANT_DIG) * log2(FLT_RADIX)`.
目前已知的實作都能以 int 表示正確結果。若要發生溢位，INT_MAX 必須小於 LDBL_MAX_EXP * log2(FLT_RADIX)，或 INT_MIN 必須大於 (LDBL_MIN_EXP - LDBL_MANT_DIG) * log2(FLT_RADIX)。
The value of the exponent returned by `ilogb` is always 1 less than the exponent retuned by frexp because of the different normalization requirements: for the exponent `e` returned by `ilogb`, |arg*r-e
| is between 1 and `r` (typically between `1` and `2`), but for the exponent `e` returned by frexp, |arg*2-e
| is between `0.5` and `1`.
由於正規化方式不同，ilogb 回傳的指數總是比 frexp 小 1。若 ilogb 回傳 e，|arg × r⁻ᵉ| 介於 1 和 r 之間（通常介於 1 和 2）；若 frexp 回傳 e，|arg × 2⁻ᵉ| 則介於 0.5 和 1 之間。

### Example

Run this code

```c
#include <fenv.h> #include <float.h> #include <math.h> #include <stdio.h> // #pragma STDC FENV_ACCESS ON int main(void) {  double f = 123.45;  printf("Given the number %.2f or %a in hex,\n", f, f);  double f3;  double f2 = modf(f, &f3);  printf("modf() makes %.0f + %.2f\n", f3, f2);  int i;  f2 = frexp(f, &i);  printf("frexp() makes %f * 2^%d\n", f2, i);  i = ilogb(f);  printf("logb()/ilogb() make %f * %d^%d\n", f/scalbn(1.0, i), FLT_RADIX, i);  // error handling  feclearexcept(FE_ALL_EXCEPT);  printf("ilogb(0) = %d\n", ilogb(0));  if (fetestexcept(FE_INVALID))  puts(" FE_INVALID raised"); }
```

Possible output:
可能的輸出：

```c
Given the number 123.45 or 0x1.edccccccccccdp+6 in hex, modf() makes 123 + 0.45 frexp() makes 0.964453 * 2^7 logb()/ilogb() make 1.92891 * 2^6 ilogb(0) = -2147483648 FE_INVALID raised
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12/8 Mathematics <math.h> (p: TBD)
7.12/8 數學 <math.h> （p: TBD）
7.12/8 數學 <math.h> （p: TBD）

- 7.12.6.5 The ilogb functions (p: TBD)
7.12.6.5 ilogb 函式（p: TBD）
7.12.6.5 ilogb 函式（p: TBD）

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.3.5 The ilogb functions (p: TBD)
F.10.3.5 ilogb 函式（p: TBD）
F.10.3.5 ilogb 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12/8 Mathematics <math.h> (p: TBD)
7.12/8 數學 <math.h> （p: TBD）
7.12/8 數學 <math.h> （p: TBD）

- 7.12.6.5 The ilogb functions (p: TBD)
7.12.6.5 ilogb 函式（p: TBD）
7.12.6.5 ilogb 函式（p: TBD）

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.3.5 The ilogb functions (p: TBD)
F.10.3.5 ilogb 函式（p: TBD）
F.10.3.5 ilogb 函式（p: TBD）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12/8 Mathematics <math.h> (p: 232)
7.12/8 數學 <math.h> （p: 232）
7.12/8 數學 <math.h> （p: 232）

- 7.12.6.5 The ilogb functions (p: 244)
7.12.6.5 ilogb 函式（p: 244）
7.12.6.5 ilogb 函式（p: 244）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.3.5 The ilogb functions (p: 521)
F.10.3.5 ilogb 函式（p: 521）
F.10.3.5 ilogb 函式（p: 521）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12/8 Mathematics <math.h> (p: 213)
7.12/8 數學 <math.h> （p: 213）
7.12/8 數學 <math.h> （p: 213）

- 7.12.6.5 The ilogb functions (p: 224-225)
7.12.6.5 ilogb 函式（p: 224-225）
7.12.6.5 ilogb 函式（p: 224-225）

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- F.9.3.5 The ilogb functions (p: 458)
F.9.3.5 ilogb 函式（p: 458）
F.9.3.5 ilogb 函式（p: 458）

### See also

frexpfrexpffrexpl
(C99)(C99)
|   | breaks a number into significand and a power of 2
(function)   |

logblogbflogbl
(C99)(C99)(C99)
|   | extracts exponent of the given number
(function)   |

scalbnscalbnfscalbnlscalblnscalblnfscalblnl
(C99)(C99)(C99)(C99)(C99)(C99)
|   | computes efficiently a number times FLT_RADIX raised to a power
(function)   |

C++ documentation for ilogb

---
來源頁路徑：`en.cppreference.com/c/numeric/math/ilogb.html`

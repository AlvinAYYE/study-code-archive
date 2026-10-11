# cbrt, cbrtf, cbrtl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
float cbrtf( float arg );
```
|   |  (1)  |   |  (since C99)  |

```c
double cbrt( double arg );
```
|   |  (2)  |   |  (since C99)  |

```c
long double cbrtl( long double arg );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define cbrt( arg )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Computes the cube root of `arg`.

4) Type-generic macro: If `arg` has type `long double`, `cbrtl` is called. Otherwise, if `arg` has integer type or the type `double`, `cbrt` is called. Otherwise, `cbrtf` is called.

### Parameters

| arg  |   | -  |   | floating-point value  |

### Return value

If no errors occur, the cube root of `arg` (3√argarg33√arg), is returned.
若沒有發生錯誤，回傳 arg 的立方根 ∛arg。
If a range error occurs due to underflow, the correct result (after rounding) is returned.
若因浮點下溢而發生值域錯誤，回傳正確結果（經捨入後）。

### Error handling

Errors are reported as specified in math_errhandling.
錯誤會依照 math_errhandling 的規定回報。
If the implementation supports IEEE floating-point arithmetic (IEC 60559),
若實作支援 IEEE 浮點運算（IEC 60559）：

- if the argument is ±0 or ±∞, it is returned, unchanged
若參數為 ±0 或 ±∞，則原樣回傳。

- if the argument is NaN, NaN is returned.
若參數為 NaN，回傳 NaN。

### Notes

`cbrt(arg)` is not equivalent to `pow(arg, 1.0/3)` because the rational number 1313
cbrt ( arg ) 不等價於 pow ( arg , 1.0 / 3 ) ，因為有理數 1 3 1 3
1 |
3 |
is typically not equal to `1.0/3` and std::pow cannot raise a negative base to a fractional exponent. Moreover, `cbrt(arg)` usually gives more accurate results than `pow(arg, 1.0/3)` (see example).
通常不等於 1.0 / 3 ，且 std::pow 無法將負底數提升到分數指數。此外，cbrt ( arg ) 通常比 pow ( arg , 1.0 / 3 ) 給出更精確的結果（見示例）。
### Example

Run this code

```c
#include <float.h> #include <math.h> #include <stdio.h> int main(void) {  printf("Normal use:\n"  "cbrt(729) = %f\n", cbrt(729));  printf("cbrt(-0.125) = %f\n", cbrt(-0.125));  printf("Special values:\n"  "cbrt(-0) = %f\n", cbrt(-0.0));  printf("cbrt(+inf) = %f\n", cbrt(INFINITY));  printf("Accuracy:\n"  "cbrt(343) = %.*f\n", DBL_DECIMAL_DIG, cbrt(343));  printf("pow(343,1.0/3) = %.*f\n", DBL_DECIMAL_DIG, pow(343, 1.0/3)); }
```

Possible output:
可能的輸出：

```c
Normal use: cbrt(729) = 9.000000 cbrt(-0.125) = -0.500000 Special values: cbrt(-0) = -0.000000 cbrt(+inf) = inf Accuracy: cbrt(343) = 7.00000000000000000 pow(343,1.0/3) = 6.99999999999999911
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.7.1 The cbrt functions (p: TBD)
7.12.7.1 cbrt 函式（p: TBD）
7.12.7.1 cbrt 函式（p: TBD）

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.4.1 The cbrt functions (p: TBD)
F.10.4.1 cbrt 函式（p: TBD）
F.10.4.1 cbrt 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.7.1 The cbrt functions (p: 180-181)
7.12.7.1 cbrt 函式（p: 180-181）
7.12.7.1 cbrt 函式（p: 180-181）

- 7.25 Type-generic math <tgmath.h> (p: 272-273)
7.25 型別通用數學 <tgmath.h> (p: 272-273)
7.25 型別通用數學 <tgmath.h> (p: 272-273)

- F.10.4.1 The cbrt functions (p: 381-)
F.10.4.1 cbrt 函式（p: 381-）
F.10.4.1 cbrt 函式（p: 381-）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.7.1 The cbrt functions (p: 247)
7.12.7.1 cbrt 函式（p: 247）
7.12.7.1 cbrt 函式（p: 247）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.4.1 The cbrt functions (p: 524)
F.10.4.1 cbrt 函式（p: 524）
F.10.4.1 cbrt 函式（p: 524）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.7.1 The cbrt functions (p: 228)
7.12.7.1 cbrt 函式（p: 228）
7.12.7.1 cbrt 函式（p: 228）

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- F.9.4.1 The cbrt functions (p: 460)
F.9.4.1 cbrt 函式（p: 460）
F.9.4.1 cbrt 函式（p: 460）

### See also

powpowfpowl
(C99)(C99)
|   | computes a number raised to the given power (xyxyx)
(function)   |

sqrtsqrtfsqrtl
(C99)(C99)
|   | computes square root (√xx√x)
(function)   |

hypothypotfhypotl
(C99)(C99)(C99)
|   | computes square root of the sum of the squares of two given numbers (√x2+y2x2+y2√x2
+y2
)
(function)   |

C++ documentation for cbrt

---
來源頁路徑：`en.cppreference.com/c/numeric/math/cbrt.html`

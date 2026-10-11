# cos, cosf, cosl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
float cosf( float arg );
```
|   |  (1)  |   |  (since C99)  |

```c
double cos( double arg );
```
|   |  (2)  |   |   |

```c
long double cosl( long double arg );
```
|   |  (3)  |   |  (since C99)  |

```c
_Decimal32 cosd32( _Decimal32 arg );
```
|   |  (4)  |   |  (since C23)  |

```c
_Decimal64 cosd64( _Decimal64 arg );
```
|   |  (5)  |   |  (since C23)  |

```c
_Decimal128 cosd128( _Decimal128 arg );
```
|   |  (6)  |   |  (since C23)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define cos( arg )
```
|   |  (7)  |   |  (since C99)  |

|  |  |  |  |

1-6) Computes the cosine of `arg` (measured in radians).

7) Type-generic macro: If the argument has type `long double`, (3) (`cosl`) is called. Otherwise, if the argument has integer type or the type `double`, (2) (`cos`) is called. Otherwise, (1) (`cosf`) is called. If the argument is complex, then the macro invokes the corresponding complex function (ccosf, ccos, ccosl).

The functions (4-6) are declared if and only if the implementation predefines `__STDC_IEC_60559_DFP__` (i.e. the implementation supports decimal floating-point numbers).
|   | (since C23) |

### Parameters

| arg  |   | -  |   | floating-point value representing angle in radians  |

### Return value

If no errors occur, the cosine of `arg` (cos(arg)) in the range [-1 ; +1], is returned.
若沒有發生錯誤，回傳 arg 的餘弦 cos(arg)，其值介於 [-1, +1]。

The result may have little or no significance if the magnitude of `arg` is large.
|   | (until C99) |

If a domain error occurs, an implementation-defined value is returned (NaN where supported).
若發生定義域錯誤，回傳由實作定義的值（若支援則回傳 NaN）。
If a range error occurs due to underflow, the correct result (after rounding) is returned.
若因浮點下溢而發生值域錯誤，回傳正確結果（經捨入後）。

### Error handling

Errors are reported as specified in math_errhandling.
錯誤會依照 math_errhandling 的規定回報。
If the implementation supports IEEE floating-point arithmetic (IEC 60559):
若實作支援 IEEE 浮點運算（IEC 60559）：

- if the argument is ±0, the result is `1.0`;
若參數為 ±0，結果為 1.0。

- if the argument is ±∞, NaN is returned and FE_INVALID is raised;
若參數為 ±∞，回傳 NaN 並引發 FE_INVALID。

- if the argument is NaN, NaN is returned.
若參數為 NaN，回傳 NaN。

### Notes

The case where the argument is infinite is not specified to be a domain error in C, but it is defined as a domain error in POSIX.
在 C 標準中，參數為無窮大的情況不屬於定義域錯誤；POSIX 則將它定義為定義域錯誤。

### Example

Run this code

```c
#include <errno.h> #include <fenv.h> #include <math.h> #include <stdio.h> #ifndef __GNUC__ #pragma STDC FENV_ACCESS ON #endif int main(void) {  const double pi = acos(-1);  // typical usage  printf("cos(pi/3) = %f\n", cos(pi / 3));  printf("cos(pi/2) = %f\n", cos(pi / 2));  printf("cos(-3*pi/4) = %f\n", cos(-3 * pi / 4));  // special values  printf("cos(+0) = %f\n", cos(0.0));  printf("cos(-0) = %f\n", cos(-0.0));  // error handling  feclearexcept(FE_ALL_EXCEPT);  printf("cos(INFINITY) = %f\n", cos(INFINITY));  if (fetestexcept(FE_INVALID))  puts(" FE_INVALID raised"); }
```

Possible output:
可能的輸出：

```c
cos(pi/3) = 0.500000 cos(pi/2) = 0.000000 cos(-3*pi/4) = -0.707107 cos(+0) = 1.000000 cos(-0) = 1.000000 cos(INFINITY) = -nan FE_INVALID raised
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.4.5 The cos functions (p: TBD)
7.12.4.5 cos 函式（p: TBD）
7.12.4.5 cos 函式（p: TBD）

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.1.5 The cos functions (p: TBD)
F.10.1.5 cos 函式（p: TBD）
F.10.1.5 cos 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.4.5 The cos functions (p: 174)
7.12.4.5 cos 函式（p: 174）
7.12.4.5 cos 函式（p: 174）

- 7.25 Type-generic math <tgmath.h> (p: 272-273)
7.25 型別通用數學 <tgmath.h> (p: 272-273)
7.25 型別通用數學 <tgmath.h> (p: 272-273)

- F.10.1.5 The cos functions (p: 378)
F.10.1.5 cos 函式（p: 378）
F.10.1.5 cos 函式（p: 378）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.4.5 The cos functions (p: 239)
7.12.4.5 cos 函式（p: 239）
7.12.4.5 cos 函式（p: 239）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.1.5 The cos functions (p: 519)
F.10.1.5 cos 函式（p: 519）
F.10.1.5 cos 函式（p: 519）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.4.5 The cos functions (p: 220)
7.12.4.5 cos 函式（p: 220）
7.12.4.5 cos 函式（p: 220）

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- F.9.1.5 The cos functions (p: 456)
F.9.1.5 cos 函式（p: 456）
F.9.1.5 cos 函式（p: 456）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.5.2.5 The cos function
4.5.2.5 cos 函式
4.5.2.5 cos 函式

### See also

sinsinfsinl
(C99)(C99)
|   | computes sine (sinxsin⁡xsin(x))
(function)   |

tantanftanl
(C99)(C99)
|   | computes tangent (tanxtan⁡xtan(x))
(function)   |

acosacosfacosl
(C99)(C99)
|   | computes arc cosine (arccosxarccos⁡xarccos(x))
(function)   |

ccosccosfccosl
(C99)(C99)(C99)
|   | computes the complex cosine
(function)   |

C++ documentation for cos

---
來源頁路徑：`en.cppreference.com/c/numeric/math/cos.html`

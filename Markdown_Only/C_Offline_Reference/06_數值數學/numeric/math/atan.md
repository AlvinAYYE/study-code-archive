# atan, atanf, atanl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
float atanf( float arg );
```
|   |  (1)  |   |  (since C99)  |

```c
double atan( double arg );
```
|   |  (2)  |   |   |

```c
long double atanl( long double arg );
```
|   |  (3)  |   |  (since C99)  |

```c
_Decimal32 atand32( _Decimal32 arg );
```
|   |  (4)  |   |  (since C23)  |

```c
_Decimal64 atand64( _Decimal64 arg );
```
|   |  (5)  |   |  (since C23)  |

```c
_Decimal128 atand128( _Decimal128 arg );
```
|   |  (6)  |   |  (since C23)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define atan( arg )
```
|   |  (7)  |   |  (since C99)  |

|  |  |  |  |

1-6) Computes the principal value of the arc tangent of `arg`.

7) Type-generic macro: If the argument has type `long double`, (3) (`atanl`) is called. Otherwise, if the argument has integer type or the type `double`, (2) (`atan`) is called. Otherwise, (1) (`atanf`) is called. If the argument is complex, then the macro invokes the corresponding complex function (catanf, catan, catanl).

The functions (4-6) are declared if and only if the implementation predefines `__STDC_IEC_60559_DFP__` (i.e. the implementation supports decimal floating-point numbers).
|   | (since C23) |

### Parameters

| arg  |   | -  |   | floating-point value  |

### Return value
If no errors occur, the arc tangent of `arg` (arctan(arg)) in the range
如果未發生錯誤，則傳回 arg 的反正切值（ arctan(arg) ），其範圍為
[-
π |
2 |
 ; +
π |
2 |
]
radians, is returned.
以弧度表示，予以傳回。
If a range error occurs due to underflow, the correct result (after rounding) is returned.
若因浮點下溢而發生值域錯誤，回傳正確結果（經捨入後）。

### Error handling

Errors are reported as specified in math_errhandling.
錯誤會依照 math_errhandling 的規定回報。
If the implementation supports IEEE floating-point arithmetic (IEC 60559):
若實作支援 IEEE 浮點運算（IEC 60559）：

- if the argument is ±0, it is returned unmodified;
若參數為 ±0，則原樣回傳。

- if the argument is +∞, +π/2 is returned;
如果參數為 +∞，則傳回 +π/2；

- if the argument is -∞, -π/2 is returned;
如果參數為 -∞，則傳回 -π/2；

- if the argument is NaN, NaN is returned.
若參數為 NaN，回傳 NaN。

### Notes

POSIX specifies that in case of underflow, `arg` is returned unmodified, and if that is not supported, an implementation-defined value no greater than DBL_MIN, FLT_MIN, and LDBL_MIN is returned.
POSIX 規定，在發生下溢的情況下原樣傳回 arg ；如果不支援此行為，則傳回一個不大於 DBL_MIN 、 FLT_MIN 和 LDBL_MIN 的由實現定義的值。

### Example

Run this code

```c
#include <math.h> #include <stdio.h> int main(void) {  printf("atan(1) = %f, 4*atan(1)=%f\n", atan(1), 4 * atan(1));  // special values  printf("atan(Inf) = %f, 2*atan(Inf) = %f\n", atan(INFINITY), 2 * atan(INFINITY));  printf("atan(-0.0) = %+f, atan(+0.0) = %+f\n", atan(-0.0), atan(0)); }
```

Output:

```c
atan(1) = 0.785398, 4*atan(1)=3.141593 atan(Inf) = 1.570796, 2*atan(Inf) = 3.141593 atan(-0.0) = -0.000000, atan(+0.0) = +0.000000
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.4.3 The atan functions (p: TBD)
7.12.4.3 atan 函式（p: TBD）
7.12.4.3 atan 函式（p: TBD）

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.1.3 The atan functions (p: TBD)
F.10.1.3 atan 函式（p: TBD）
F.10.1.3 atan 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.4.3 The atan functions (p: 174)
7.12.4.3 atan 函式（p: 174）
7.12.4.3 atan 函式（p: 174）

- 7.25 Type-generic math <tgmath.h> (p: 272-273)
7.25 型別通用數學 <tgmath.h> (p: 272-273)
7.25 型別通用數學 <tgmath.h> (p: 272-273)

- F.10.1.3 The atan functions (p: 378)
F.10.1.3 atan 函式（p: 378）
F.10.1.3 atan 函式（p: 378）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.4.3 The atan functions (p: 238-239)
7.12.4.3 atan 函式（p: 238-239）
7.12.4.3 atan 函式（p: 238-239）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.1.3 The atan functions (p: 519)
F.10.1.3 atan 函式（p: 519）
F.10.1.3 atan 函式（p: 519）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.4.3 The atan functions (p: 219)
7.12.4.3 atan 函式（p: 219）
7.12.4.3 atan 函式（p: 219）

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- F.9.1.3 The atan functions (p: 456)
F.9.1.3 atan 函式（p: 456）
F.9.1.3 atan 函式（p: 456）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.5.2.3 The atan function
4.5.2.3 atan 函式
4.5.2.3 atan 函式

### See also

atan2atan2fatan2l
(C99)(C99)
|   | computes arc tangent, using signs to determine quadrants
(function)   |

asinasinfasinl
(C99)(C99)
|   | computes arc sine (arcsinxarcsin⁡xarcsin(x))
(function)   |

acosacosfacosl
(C99)(C99)
|   | computes arc cosine (arccosxarccos⁡xarccos(x))
(function)   |

tantanftanl
(C99)(C99)
|   | computes tangent (tanxtan⁡xtan(x))
(function)   |

catancatanfcatanl
(C99)(C99)(C99)
|   | computes the complex arc tangent
(function)   |

C++ documentation for atan

---
來源頁路徑：`en.cppreference.com/c/numeric/math/atan.html`

# atan2, atan2f, atan2l

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
float atan2f( float y, float x );
```
|   |  (1)  |   |  (since C99)  |

```c
double atan2( double y, double x );
```
|   |  (2)  |   |   |

```c
long double atan2l( long double y, long double x );
```
|   |  (3)  |   |  (since C99)  |

```c
_Decimal32 atan2d32( _Decimal32 y, _Decimal32 x );
```
|   |  (4)  |   |  (since C23)  |

```c
_Decimal64 atan2d64( _Decimal64 y, _Decimal64 x );
```
|   |  (5)  |   |  (since C23)  |

```c
_Decimal128 atan2d128( _Decimal128 y, _Decimal128 x );
```
|   |  (6)  |   |  (since C23)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define atan2( y, x )
```
|   |  (7)  |   |  (since C99)  |

|  |  |  |  |

1-6) Computes the arc tangent of `y / x` using the signs of arguments to determine the correct quadrant.

7) Type-generic macro: If any argument has type `long double`, (3) (`atan2l`) is called. Otherwise, if any argument has integer type or has type `double`, (2) (`atan2`) is called. Otherwise, (1) (`atan2f`) is called.

The functions (4-6) are declared if and only if the implementation predefines `__STDC_IEC_60559_DFP__` (i.e. the implementation supports decimal floating-point numbers).
|   | (since C23) |

### Parameters

| x, y  |   | -  |   | floating-point value  |

### Return value
If no errors occur, the arc tangent of `y / x` (
若未發生錯誤，則傳回 y / x 的反正切（
arctan(
y |
x |
)
) in the range [-π ; +π] radians, is returned.
），其取值範圍為 [-π ; +π] 弧度。

Y argument

Return value

X argument

If a domain error occurs, an implementation-defined value is returned.
若發生定義域錯誤，回傳由實作定義的值。
If a range error occurs due to underflow, the correct result (after rounding) is returned.
若因浮點下溢而發生值域錯誤，回傳正確結果（經捨入後）。

### Error handling

Errors are reported as specified in math_errhandling.
錯誤會依照 math_errhandling 的規定回報。
Domain error may occur if `x` and `y` are both zero.
若 x 和 y 都是零，可能會發生定義域錯誤。
If the implementation supports IEEE floating-point arithmetic (IEC 60559):
若實作支援 IEEE 浮點運算（IEC 60559）：

- If `x` and `y` are both zero, domain error *does not* occur;
若 x 和 y 均為零，則不會發生定義域錯誤；

- If `x` and `y` are both zero, range error does not occur either;
若 x 和 y 均為零，也不會發生值域錯誤；

- If `y` is zero, pole error does not occur;
若 y 為零，則不會發生極點錯誤；

- If `y` is `±0` and `x` is negative or `-0`, `±π` is returned;
若 y 為 ±0 且 x 為負數或 -0，則傳回 ±π；

- If `y` is `±0` and `x` is positive or `+0`, `±0` is returned;
若 y 為 ±0 且 x 為正數或 +0，則傳回 ±0；

- If `y` is `±∞` and `x` is finite, `±π/2` is returned;
若 y 為 ±∞ 且 x 為有限值，則傳回 ±π/2；

- If `y` is `±∞` and `x` is `-∞`, `±3π/4` is returned;
若 y 為 ±∞ 且 x 為 -∞，則傳回 ±3π/4；

- If `y` is `±∞` and `x` is `+∞`, `±π/4` is returned;
若 y 為 ±∞ 且 x 為 +∞，則傳回 ±π/4；

- If `x` is `±0` and `y` is negative, `-π/2` is returned;
若 x 為 ±0 且 y 為負數，則傳回 -π/2；

- If `x` is `±0` and `y` is positive, `+π/2` is returned;
若 x 為 ±0 且 y 為正數，則傳回 +π/2；

- If `x` is `-∞` and `y` is finite and positive, `+π` is returned;
若 x 為 -∞ 且 y 為有限正數，則傳回 +π；

- If `x` is `-∞` and `y` is finite and negative, `-π` is returned;
若 x 為 -∞ 且 y 為有限負數，則傳回 -π；

- If `x` is `+∞` and `y` is finite and positive, `+0` is returned;
若 x 為 +∞ 且 y 為有限正數，則傳回 +0；

- If `x` is `+∞` and `y` is finite and negative, `-0` is returned;
若 x 為 +∞ 且 y 為有限負數，則傳回 -0；

- If either `x` is NaN or `y` is NaN, NaN is returned.
若 x 或 y 中有一個為 NaN，則傳回 NaN。

### Notes

`atan2(y, x)` is equivalent to `carg(x + I*y)`.
atan2 ( y , x ) 等價於 carg ( x + I * y ) 。
POSIX specifies that in case of underflow, `y / x` is the value returned, and if that is not supported, an implementation-defined value no greater than DBL_MIN, FLT_MIN, and LDBL_MIN is returned.
POSIX 規定，在發生下溢時傳回 y / x 作為結果；若不支援該做法，則傳回一個由實現定義的、不大於 DBL_MIN 、 FLT_MIN 和 LDBL_MIN 的值。

### Example

Run this code

```c
#include <math.h> #include <stdio.h> int main(void) {  // normal usage: the signs of the two arguments determine the quadrant  // atan2(1,1) = +pi/4, Quad I  printf("(+1,+1) cartesian is (%f,%f) polar\n", hypot( 1, 1), atan2( 1, 1));  // atan2(1, -1) = +3pi/4, Quad II  printf("(+1,-1) cartesian is (%f,%f) polar\n", hypot( 1,-1), atan2( 1,-1));  // atan2(-1,-1) = -3pi/4, Quad III  printf("(-1,-1) cartesian is (%f,%f) polar\n", hypot(-1,-1), atan2(-1,-1));  // atan2(-1,-1) = -pi/4, Quad IV  printf("(-1,+1) cartesian is (%f,%f) polar\n", hypot(-1, 1), atan2(-1, 1));  // special values  printf("atan2(0, 0) = %f atan2(0, -0)=%f\n", atan2(0,0), atan2(0,-0.0));  printf("atan2(7, 0) = %f atan2(7, -0)=%f\n", atan2(7,0), atan2(7,-0.0)); }
```

Output:

```c
(+1,+1) cartesian is (1.414214,0.785398) polar (+1,-1) cartesian is (1.414214,2.356194) polar (-1,-1) cartesian is (1.414214,-2.356194) polar (-1,+1) cartesian is (1.414214,-0.785398) polar atan2(0, 0) = 0.000000 atan2(0, -0)=3.141593 atan2(7, 0) = 1.570796 atan2(7, -0)=1.570796
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.4.4 The atan2 functions (p: TBD)
7.12.4.4 atan2 函式（p: TBD）
7.12.4.4 atan2 函式（p: TBD）

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.1.4 The atan2 functions (p: TBD)
F.10.1.4 atan2 函式（p: TBD）
F.10.1.4 atan2 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.4.4 The atan2 functions (p: 174)
7.12.4.4 atan2 函式（p: 174）
7.12.4.4 atan2 函式（p: 174）

- 7.25 Type-generic math <tgmath.h> (p: 272-273)
7.25 型別通用數學 <tgmath.h> (p: 272-273)
7.25 型別通用數學 <tgmath.h> (p: 272-273)

- F.10.1.4 The atan2 functions (p: 378)
F.10.1.4 atan2 函式（p: 378）
F.10.1.4 atan2 函式（p: 378）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.4.4 The atan2 functions (p: 239)
7.12.4.4 atan2 函式（p: 239）
7.12.4.4 atan2 函式（p: 239）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.1.4 The atan2 functions (p: 519)
F.10.1.4 atan2 函式（p: 519）
F.10.1.4 atan2 函式（p: 519）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.4.4 The atan2 functions (p: 219)
7.12.4.4 atan2 函式（p: 219）
7.12.4.4 atan2 函式（p: 219）

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- F.9.1.4 The atan2 functions (p: 456)
F.9.1.4 atan2 函式（p: 456）
F.9.1.4 atan2 函式（p: 456）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.5.2.4 The atan2 function
4.5.2.4 atan2 函式
4.5.2.4 atan2 函式

### See also

asinasinfasinl
(C99)(C99)
|   | computes arc sine (arcsinxarcsin⁡xarcsin(x))
(function)   |

acosacosfacosl
(C99)(C99)
|   | computes arc cosine (arccosxarccos⁡xarccos(x))
(function)   |

atanatanfatanl
(C99)(C99)
|   | computes arc tangent (arctanxarctan⁡xarctan(x))
(function)   |

cargcargfcargl
(C99)(C99)(C99)
|   | computes the phase angle of a complex number
(function)   |

C++ documentation for atan2

---
來源頁路徑：`en.cppreference.com/c/numeric/math/atan2.html`

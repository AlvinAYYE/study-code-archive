# nextafter, nextafterf, nextafterl, nexttoward, nexttowardf, nexttowardl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
float nextafterf( float from, float to );
```
|   |  (1)  |   |  (since C99)  |

```c
double nextafter( double from, double to );
```
|   |  (2)  |   |  (since C99)  |

```c
long double nextafterl( long double from, long double to );
```
|   |  (3)  |   |  (since C99)  |

```c
float nexttowardf( float from, long double to );
```
|   |  (4)  |   |  (since C99)  |

```c
double nexttoward( double from, long double to );
```
|   |  (5)  |   |  (since C99)  |

```c
long double nexttowardl( long double from, long double to );
```
|   |  (6)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define nextafter(from, to)
```
|   |  (7)  |   |  (since C99)  |

```c
#define nexttoward(from, to)
```
|   |  (8)  |   |  (since C99)  |

|  |  |  |  |

1-3) First, converts both arguments to the type of the function, then returns the next representable value of `from` in the direction of `to`. If `from` equals to `to`, `to` is returned.

4-6) First, converts the first argument to the type of the function, then returns the next representable value of `from` in the direction of `to`. If `from` equals to `to`, `to` is returned, converted from `long double` to the return type of the function without loss of range or precision.

7) Type-generic macro: If any argument has type `long double`, `nextafterl` is called. Otherwise, if any argument has integer type or has type `double`, `nextafter` is called. Otherwise, `nextafterf` is called.

8) Type-generic macro: If the argument `from` has type `long double`, `nexttowardl` is called. Otherwise, if `from` has integer type or the type `double`, `nexttoward` is called. Otherwise, `nexttowardf` is called.

### Parameters

| from, to  |   | -  |   | floating-point values  |

### Return value

If no errors occur, the next representable value of `from` in the direction of `to`. is returned. If `from` equals `to`, then `to` is returned, converted to the type of the function.
若沒有發生錯誤，回傳從 from 朝 to 方向的下一個可表示值。若 from 等於 to，則將 to 轉換成此函式的型別後回傳。
If a range error due to overflow occurs, `±HUGE_VAL`, `±HUGE_VALF`, or `±HUGE_VALL` is returned (with the same sign as `from`).
若因浮點溢位而發生範圍錯誤，回傳與 from 同號的 ±HUGE_VAL、±HUGE_VALF 或 ±HUGE_VALL。
If a range error occurs due to underflow, the correct result is returned.
若因浮點下溢而發生值域錯誤，回傳正確結果。

### Error handling

Errors are reported as specified in math_errhandling.
錯誤會依照 math_errhandling 的規定回報。
If the implementation supports IEEE floating-point arithmetic (IEC 60559),
若實作支援 IEEE 浮點運算（IEC 60559）：

- if `from` is finite, but the expected result is an infinity, raises FE_INEXACT and FE_OVERFLOW.
若 from 是有限值，但預期結果為無窮大，會引發 FE_INEXACT 和 FE_OVERFLOW。

- if `from` does not equal `to` and the result is subnormal or zero, raises FE_INEXACT and FE_UNDERFLOW.
若 from 不等於 to，且結果是非正規數或零，會引發 FE_INEXACT 和 FE_UNDERFLOW。

- in any case, the returned value is independent of the current rounding mode
無論如何，回傳值都不受目前捨入模式影響。

- if either `from` or `to` is NaN, NaN is returned.
若 from 或 to 任一個是 NaN，回傳 NaN。

### Notes

POSIX specifies that the overflow and the underflow conditions are range errors (errno may be set).
POSIX 規定，溢位和下溢都屬於範圍錯誤（可能會設定 errno）。
IEC 60559 recommends that `from` is returned whenever `from == to`. These functions return `to` instead, which makes the behavior around zero consistent: `nextafter(-0.0, +0.0)` returns `+0.0` and `nextafter(+0.0, -0.0)` returns `-0.0`.
IEC 60559 建議 from == to 時回傳 from。不過，這些函式會回傳 to，讓零附近的行為一致：nextafter(-0.0, +0.0) 回傳 +0.0，而 nextafter(+0.0, -0.0) 回傳 -0.0。
`nextafter` is typically implemented by manipulation of IEEE representation (glibc musl).
nextafter 通常直接操作 IEEE 浮點表示來實作（例如 glibc 和 musl）。

### Example

Run this code

```c
#include <fenv.h> #include <float.h> #include <math.h> #include <stdio.h> int main(void) {  float from1 = 0, to1 = nextafterf(from1, 1);  printf("The next representable float after %.2f is %.20g (%a)\n", from1, to1, to1);  float from2 = 1, to2 = nextafterf(from2, 2);  printf("The next representable float after %.2f is %.20f (%a)\n", from2, to2, to2);  double from3 = nextafter(0.1, 0), to3 = 0.1;  printf("The number 0.1 lies between two valid doubles:\n"  "  %.56f (%a)\nand %.55f (%a)\n", from3, from3, to3, to3);  // difference between nextafter and nexttoward:  long double dir = nextafterl(from1, 1); // first subnormal long double  float x = nextafterf(from1, dir); // first converts dir to float, giving 0  printf("Using nextafter, next float after %.2f (%a) is %.20g (%a)\n",  from1, from1, x, x);  x = nexttowardf(from1, dir);  printf("Using nexttoward, next float after %.2f (%a) is %.20g (%a)\n",  from1, from1, x, x);  // special values  {  #pragma STDC FENV_ACCESS ON  feclearexcept(FE_ALL_EXCEPT);  double from4 = DBL_MAX, to4 = nextafter(from4, INFINITY);  printf("The next representable double after %.2g (%a) is %.23f (%a)\n",  from4, from4, to4, to4);  if(fetestexcept(FE_OVERFLOW)) puts(" raised FE_OVERFLOW");  if(fetestexcept(FE_INEXACT)) puts(" raised FE_INEXACT");  } // end FENV_ACCESS block  float from5 = 0.0, to5 = nextafter(from5, -0.0);  printf("nextafter(+0.0, -0.0) gives %.2g (%a)\n", to5, to5); }
```

Output:

```c
The next representable float after 0.00 is 1.4012984643248170709e-45 (0x1p-149) The next representable float after 1.00 is 1.00000011920928955078 (0x1.000002p+0) The number 0.1 lies between two valid doubles: 0.09999999999999999167332731531132594682276248931884765625 (0x1.9999999999999p-4) and 0.1000000000000000055511151231257827021181583404541015625 (0x1.999999999999ap-4) Using nextafter, next float after 0.00 (0x0p+0) is 0 (0x0p+0) Using nexttoward, next float after 0.00 (0x0p+0) is 1.4012984643248170709e-45 (0x1p-149) The next representable double after 1.8e+308 (0x1.fffffffffffffp+1023) is inf (inf) raised FE_OVERFLOW raised FE_INEXACT nextafter(+0.0, -0.0) gives -0 (-0x0p+0)
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.11.3 The nextafter functions (p: TBD)
7.12.11.3 nextafter 函式 (p: TBD)
7.12.11.3 nextafter 函式 (p: TBD)

- 7.12.11.4 The nexttoward functions (p: TBD)
7.12.11.4 nexttoward 函式 (p: TBD)
7.12.11.4 nexttoward 函式 (p: TBD)

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.8.3 The nextafter functions (p: TBD)
F.10.8.3 nextafter 函式 (p: TBD)
F.10.8.3 nextafter 函式 (p: TBD)

- F.10.8.4 The nexttoward functions (p: TBD)
F.10.8.4 nexttoward 函式 (p: TBD)
F.10.8.4 nexttoward 函式 (p: TBD)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.11.3 The nextafter functions (p: 187)
7.12.11.3 nextafter 函式 (p: 187)
7.12.11.3 nextafter 函式 (p: 187)

- 7.12.11.4 The nexttoward functions (p: 187)
7.12.11.4 nexttoward 函式 (p: 187)
7.12.11.4 nexttoward 函式 (p: 187)

- 7.25 Type-generic math <tgmath.h> (p: 272-273)
7.25 型別通用數學 <tgmath.h> (p: 272-273)
7.25 型別通用數學 <tgmath.h> (p: 272-273)

- F.10.8.3 The nextafter functions (p: 386)
F.10.8.3 nextafter 函式 (p: 386)
F.10.8.3 nextafter 函式 (p: 386)

- F.10.8.4 The nexttoward functions (p: 386)
F.10.8.4 nexttoward 函式 (p: 386)
F.10.8.4 nexttoward 函式 (p: 386)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.11.3 The nextafter functions (p: 256)
7.12.11.3 nextafter 函式 (p: 256)
7.12.11.3 nextafter 函式 (p: 256)

- 7.12.11.4 The nexttoward functions (p: 257)
7.12.11.4 nexttoward 函式 (p: 257)
7.12.11.4 nexttoward 函式 (p: 257)

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.8.3 The nextafter functions (p: 529)
F.10.8.3 nextafter 函式 (p: 529)
F.10.8.3 nextafter 函式 (p: 529)

- F.10.8.4 The nexttoward functions (p: 529)
F.10.8.4 nexttoward 函式 (p: 529)
F.10.8.4 nexttoward 函式 (p: 529)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.11.3 The nextafter functions (p: 237)
7.12.11.3 nextafter 函式 (p: 237)
7.12.11.3 nextafter 函式 (p: 237)

- 7.12.11.4 The nexttoward functions (p: 238)
7.12.11.4 nexttoward 函式 (p: 238)
7.12.11.4 nexttoward 函式 (p: 238)

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- F.9.8.3 The nextafter functions (p: 466)
F.9.8.3 nextafter 函式 (p: 466)
F.9.8.3 nextafter 函式 (p: 466)

- F.9.8.4 The nexttoward functions (p: 466)
F.9.8.4 nexttoward 函式 (p: 466)
F.9.8.4 nexttoward 函式 (p: 466)

### See also

C++ documentation for nextafter

---
來源頁路徑：`en.cppreference.com/c/numeric/math/nextafter.html`

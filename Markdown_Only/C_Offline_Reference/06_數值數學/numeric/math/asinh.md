# asinh, asinhf, asinhl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
float asinhf( float arg );
```
|   |  (1)  |   |  (since C99)  |

```c
double asinh( double arg );
```
|   |  (2)  |   |  (since C99)  |

```c
long double asinhl( long double arg );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define asinh( arg )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Computes the inverse hyperbolic sine of `arg`.

4) Type-generic macro: If the argument has type `long double`, `asinhl` is called. Otherwise, if the argument has integer type or the type `double`, `asinh` is called. Otherwise, `asinhf` is called. If the argument is complex, then the macro invokes the corresponding complex function (casinhf, casinh, casinhl).

### Parameters

| arg  |   | -  |   | floating-point value representing the area of a hyperbolic sector  |

### Return value

If no errors occur, the inverse hyperbolic sine of `arg` (sinh-1
(arg), or arsinh(arg)), is returned.
如果未發生錯誤，則傳回 arg 的反雙曲正弦（ sinh -1 (arg) ，或 arsinh(arg) ）。
If a range error occurs due to underflow, the correct result (after rounding) is returned.
若因浮點下溢而發生值域錯誤，回傳正確結果（經捨入後）。

### Error handling

Errors are reported as specified in math_errhandling.
錯誤會依照 math_errhandling 的規定回報。
If the implementation supports IEEE floating-point arithmetic (IEC 60559),
若實作支援 IEEE 浮點運算（IEC 60559）：

- If the argument is ±0 or ±∞, it is returned unmodified.
如果參數為 ±0 或 ±∞，則原樣傳回。

- If the argument is NaN, NaN is returned.
若參數為 NaN，回傳 NaN。

### Notes

Although the C standard names this function "arc hyperbolic sine", the inverse functions of the hyperbolic functions are the area functions. Their argument is the area of a hyperbolic sector, not an arc. The correct name is "inverse hyperbolic sine" (used by POSIX) or "area hyperbolic sine".
儘管 C 標準將此函式命名為“arc hyperbolic sine”，但雙曲函式的反函式其實是面積函式（area functions）。它們的參數是雙曲扇形的面積，而不是弧。正確的名稱是“inverse hyperbolic sine”（POSIX 所採用）或“area hyperbolic sine”。

### Example

Run this code

```c
#include <math.h> #include <stdio.h> int main(void) {  printf("asinh(1) = %f\nasinh(-1) = %f\n", asinh(1), asinh(-1));  // special values  printf("asinh(+0) = %f\nasinh(-0) = %f\n", asinh(0.0), asinh(-0.0)); }
```

Output:

```c
asinh(1) = 0.881374 asinh(-1) = -0.881374 asinh(+0) = 0.000000 asinh(-0) = -0.000000
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.5.2 The asinh functions (p: 240-241)
7.12.5.2 asinh 函式（p: 240-241）
7.12.5.2 asinh 函式（p: 240-241）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.2.2 The asinh functions (p: 520)
F.10.2.2 asinh 函式（p: 520）
F.10.2.2 asinh 函式（p: 520）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.5.2 The asinh functions (p: 240-241)
7.12.5.2 asinh 函式（p: 240-241）
7.12.5.2 asinh 函式（p: 240-241）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.2.2 The asinh functions (p: 520)
F.10.2.2 asinh 函式（p: 520）
F.10.2.2 asinh 函式（p: 520）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.5.2 The asinh functions (p: 240-241)
7.12.5.2 asinh 函式（p: 240-241）
7.12.5.2 asinh 函式（p: 240-241）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.2.2 The asinh functions (p: 520)
F.10.2.2 asinh 函式（p: 520）
F.10.2.2 asinh 函式（p: 520）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.5.2 The asinh functions (p: 221)
7.12.5.2 asinh 函式（p: 221）
7.12.5.2 asinh 函式（p: 221）

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- F.9.2.2 The asinh functions (p: 457)
F.9.2.2 asinh 函式（p: 457）
F.9.2.2 asinh 函式（p: 457）

### See also

acoshacoshfacoshl
(C99)(C99)(C99)
|   | computes inverse hyperbolic cosine (arcoshxarcosh⁡xarcosh(x))
(function)   |

atanhatanhfatanhl
(C99)(C99)(C99)
|   | computes inverse hyperbolic tangent (artanhxartanh⁡xartanh(x))
(function)   |

sinhsinhfsinhl
(C99)(C99)
|   | computes hyperbolic sine (sinhxsinh⁡xsinh(x))
(function)   |

casinhcasinhfcasinhl
(C99)(C99)(C99)
|   | computes the complex arc hyperbolic sine
(function)   |

C++ documentation for asinh

### External links

| Weisstein, Eric W. "Inverse Hyperbolic Sine." From MathWorld — A Wolfram Web Resource.  |

---
來源頁路徑：`en.cppreference.com/c/numeric/math/asinh.html`

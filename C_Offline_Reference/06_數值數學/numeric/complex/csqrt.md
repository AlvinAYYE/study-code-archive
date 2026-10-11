# csqrtf, csqrt, csqrtl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<complex.h>`
|   |  |   |  |

```c
float complex csqrtf( float complex z );
```
|   |  (1)  |   |  (since C99)  |

```c
double complex csqrt( double complex z );
```
|   |  (2)  |   |  (since C99)  |

```c
long double complex csqrtl( long double complex z );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define sqrt( z )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Computes the complex square root of `z` with branch cut along the negative real axis.

4) Type-generic macro: If `z` has type `long double complex`, `csqrtl` is called. if `z` has type `double complex`, `csqrt` is called, if `z` has type `float complex`, `csqrtf` is called. If `z` is real or integer, then the macro invokes the corresponding real function (`sqrtf`, `sqrt`, `sqrtl`). If `z` is imaginary, the corresponding complex number version is called.

### Parameters

| z  |   | -  |   | complex argument  |

### Return value

If no errors occur, returns the square root of `z`, in the range of the right half-plane, including the imaginary axis ([0; +∞) along the real axis and (−∞; +∞) along the imaginary axis.)
若沒有發生錯誤，回傳 z 的平方根，值域為包含虛軸的右半平面（實部介於 [0, +∞)，虛部介於 (−∞, +∞)）。

### Error handling and special values
錯誤處理與特殊值

Errors are reported consistent with math_errhandling
錯誤會依照 math_errhandling 的規定回報。
If the implementation supports IEEE floating-point arithmetic,
如果實現支援 IEEE 浮點運算，

- The function is continuous onto the branch cut taking into account the sign of imaginary part
此函式在分支切割上會依虛部的符號保持連續。

- `csqrt(conj(z)) == conj(csqrt(z))`
csqrt(conj(z)) == conj(csqrt(z))

- If `z` is `±0+0i`, the result is `+0+0i`
如果 z 是 ±0+0i，結果是 +0+0i

- If `z` is `x+∞i`, the result is `+∞+∞i` even if x is NaN
如果 z 是 x+∞i，結果是 +∞+∞i，即使 x 是 NaN

- If `z` is `x+NaNi`, the result is `NaN+NaNi` (unless x is ±∞) and FE_INVALID may be raised
如果 z 是 x+NaNi，結果是 NaN+NaNi（除非 x 是 ±∞），並可能引發 FE_INVALID

- If `z` is `-∞+yi`, the result is `+0+∞i` for finite positive y
如果 z 是 -∞+yi，對於有限正值 y，結果是 +0+∞i

- If `z` is `+∞+yi`, the result is `+∞+0i)` for finite positive y
如果 z 是 +∞+yi，對於有限正值 y，結果是 +∞+0i)

- If `z` is `-∞+NaNi`, the result is `NaN±∞i` (sign of imaginary part unspecified)
如果 z 是 -∞+NaNi，結果是 NaN±∞i（虛部符號未指定）

- If `z` is `+∞+NaNi`, the result is `+∞+NaNi`
如果 z 是 +∞+NaNi，結果是 +∞+NaNi

- If `z` is `NaN+yi`, the result is `NaN+NaNi` and FE_INVALID may be raised
如果 z 是 NaN+yi，結果是 NaN+NaNi，並可能引發 FE_INVALID

- If `z` is `NaN+NaNi`, the result is `NaN+NaNi`
如果 z 是 NaN+NaNi，結果是 NaN+NaNi

### Example

Run this code

```c
#include <stdio.h> #include <complex.h> int main(void) {  double complex z1 = csqrt(-4);  printf("Square root of -4 is %.1f%+.1fi\n", creal(z1), cimag(z1));  double complex z2 = csqrt(conj(-4)); // or, in C11, CMPLX(-4, -0.0)  printf("Square root of -4-0i, the other side of the cut, is "  "%.1f%+.1fi\n", creal(z2), cimag(z2)); }
```

Output:

```c
Square root of -4 is 0.0+2.0i Square root of -4-0i, the other side of the cut, is 0.0-2.0i
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.3.8.3 The csqrt functions (p: 196)
7.3.8.3 csqrt 函式（頁：196）
7.3.8.3 csqrt 函式（頁：196）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- G.6.4.2 The csqrt functions (p: 544)
G.6.4.2 csqrt 函式（頁：544）
G.6.4.2 csqrt 函式（頁：544）

- G.7 Type-generic math <tgmath.h> (p: 545)
G.7 泛型數學 <tgmath.h>（頁：545）
G.7 泛型數學 <tgmath.h>（頁：545）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.3.8.3 The csqrt functions (p: 178)
7.3.8.3 csqrt 函式（頁：178）
7.3.8.3 csqrt 函式（頁：178）

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- G.6.4.2 The csqrt functions (p: 479)
G.6.4.2 csqrt 函式（頁：479）
G.6.4.2 csqrt 函式（頁：479）

- G.7 Type-generic math <tgmath.h> (p: 480)
G.7 泛型數學 <tgmath.h>（頁：480）
G.7 泛型數學 <tgmath.h>（頁：480）

### See also

cpowcpowfcpowl
(C99)(C99)(C99)
|   | computes the complex power function
(function)   |

sqrtsqrtfsqrtl
(C99)(C99)
|   | computes square root (√xx√x)
(function)   |

C++ documentation for sqrt

---
來源頁路徑：`en.cppreference.com/c/numeric/complex/csqrt.html`

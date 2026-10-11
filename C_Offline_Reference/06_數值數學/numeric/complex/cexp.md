# cexpf, cexp, cexpl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<complex.h>`
|   |  |   |  |

```c
float complex cexpf( float complex z );
```
|   |  (1)  |   |  (since C99)  |

```c
double complex cexp( double complex z );
```
|   |  (2)  |   |  (since C99)  |

```c
long double complex cexpl( long double complex z );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define exp( z )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Computes the complex base-*e* exponential of `z`.

4) Type-generic macro: If `z` has type `long double complex`, `cexpl` is called. if `z` has type `double complex`, `cexp` is called, if `z` has type `float complex`, `cexpf` is called. If `z` is real or integer, then the macro invokes the corresponding real function (`expf`, `exp`, `expl`). If `z` is imaginary, the corresponding complex argument version is called.

### Parameters

| z  |   | -  |   | complex argument  |

### Return value

If no errors occur, *e* raised to the power of `z`, ezezez
is returned.
若沒有發生錯誤，回傳 e 的 z 次方，也就是 e^z。

### Error handling and special values
錯誤處理與特殊值

Errors are reported consistent with math_errhandling.
錯誤會依照 math_errhandling 的規定回報。
If the implementation supports IEEE floating-point arithmetic,
如果實現支援 IEEE 浮點運算，

- `cexp(conj(z)) == conj(cexp(z))`
cexp ( conj ( z )) == conj ( cexp ( z ))

- If `z` is `±0+0i`, the result is `1+0i`
若 z 為 ±0+0i，結果為 1+0i

- If `z` is `x+∞i` (for any finite x), the result is `NaN+NaNi` and FE_INVALID is raised.
若 z 為 x+∞i（對任意有限 x），結果為 NaN+NaNi 並引發 FE_INVALID。

- If `z` is `x+NaNi` (for any finite x), the result is `NaN+NaNi` and FE_INVALID may be raised.
若 z 為 x+NaNi（對任意有限 x），結果為 NaN+NaNi，並且可能引發 FE_INVALID。

- If `z` is `+∞+0i`, the result is `+∞+0i`
如果 z 是 +∞+0i，結果是 +∞+0i

- If `z` is `-∞+yi` (for any finite y), the result is `+0cis(y)`
若 z 為 -∞+yi（對任意有限 y），結果為 +0cis(y)

- If `z` is `+∞+yi` (for any finite nonzero y), the result is `+∞cis(y)`
若 z 為 +∞+yi（對任意有限非零 y），結果為 +∞cis(y)

- If `z` is `-∞+∞i`, the result is `±0±0i` (signs are unspecified)
若 z 為 -∞+∞i，結果為 ±0±0i（符號未指定）

- If `z` is `+∞+∞i`, the result is `±∞+NaNi` and FE_INVALID is raised (the sign of the real part is unspecified)
若 z 為 +∞+∞i，結果為 ±∞+NaNi 並引發 FE_INVALID（實部的符號未指定）

- If `z` is `-∞+NaNi`, the result is `±0±0i` (signs are unspecified)
若 z 為 -∞+NaNi，結果為 ±0±0i（符號未指定）

- If `z` is `+∞+NaNi`, the result is `±∞+NaNi` (the sign of the real part is unspecified)
若 z 為 +∞+NaNi，結果為 ±∞+NaNi（實部的符號未指定）

- If `z` is `NaN+0i`, the result is `NaN+0i`
如果 z 是 NaN+0i，結果是 NaN+0i

- If `z` is `NaN+yi` (for any nonzero y), the result is `NaN+NaNi` and FE_INVALID may be raised
若 z 為 NaN+yi（對任意非零 y），結果為 NaN+NaNi，並且可能引發 FE_INVALID

- If `z` is `NaN+NaNi`, the result is `NaN+NaNi`
如果 z 是 NaN+NaNi，結果是 NaN+NaNi

where cis(y)cis(y)cis(y) is cos(y)+isin(y)cos⁡(y)+isin⁡(y)cos(y) + i sin(y)
其中 c i s ( y ) c i s ( y ) cis(y) 表示 cos ( y ) + i sin ( y ) cos ⁡ ( y ) + i sin ⁡ ( y ) cos(y) + i sin(y)

### Notes

The complex exponential function ezezez
for z=x+iyz=x+iyz = x+iy equals excis(y)excis(y)ex
cis(y), or, ex(cos(y)+isin(y))ex(cos⁡(y)+isin⁡(y))ex
(cos(y) + i sin(y))
復指數函式 e z e z e z 在 z = x + i y z = x + i y z = x+iy 時等於 e x c i s ( y ) e x c i s ( y ) e x cis(y)，或者 e x ( cos ( y ) + i sin ( y ) ) e x ( cos ⁡ ( y ) + i sin ⁡ ( y ) ) e x (cos(y) + i sin(y))
The exponential function is an *entire function* in the complex plane and has no branch cuts.
指數函式是複平面上的整函式，沒有分支切割。

### Example

Run this code

```c
#include <stdio.h> #include <math.h> #include <complex.h> int main(void) {  double PI = acos(-1);  double complex z = cexp(I * PI); // Euler's formula  printf("exp(i*pi) = %.1f%+.1fi\n", creal(z), cimag(z)); }
```

Output:

```c
exp(i*pi) = -1.0+0.0i
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.3.7.1 The cexp functions (p: 194)
7.3.7.1 cexp 函式 (p: 194)
7.3.7.1 cexp 函式 (p: 194)

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- G.6.3.1 The cexp functions (p: 543)
G.6.3.1 cexp 函式 (p: 543)
G.6.3.1 cexp 函式 (p: 543)

- G.7 Type-generic math <tgmath.h> (p: 545)
G.7 泛型數學 <tgmath.h>（頁：545）
G.7 泛型數學 <tgmath.h>（頁：545）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.3.7.1 The cexp functions (p: 176)
7.3.7.1 cexp 函式 (p: 176)
7.3.7.1 cexp 函式 (p: 176)

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- G.6.3.1 The cexp functions (p: 478)
G.6.3.1 cexp 函式 (p: 478)
G.6.3.1 cexp 函式 (p: 478)

- G.7 Type-generic math <tgmath.h> (p: 480)
G.7 泛型數學 <tgmath.h>（頁：480）
G.7 泛型數學 <tgmath.h>（頁：480）

### See also

clogclogfclogl
(C99)(C99)(C99)
|   | computes the complex natural logarithm
(function)   |

expexpfexpl
(C99)(C99)
|   | computes *e* raised to the given power (exexe)
(function)   |

C++ documentation for exp

---
來源頁路徑：`en.cppreference.com/c/numeric/complex/cexp.html`

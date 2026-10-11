# clogf, clog, clogl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<complex.h>`
|   |  |   |  |

```c
float complex clogf( float complex z );
```
|   |  (1)  |   |  (since C99)  |

```c
double complex clog( double complex z );
```
|   |  (2)  |   |  (since C99)  |

```c
long double complex clogl( long double complex z );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define log( z )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Computes the complex natural (base-*e*) logarithm of `z` with branch cut along the negative real axis.

4) Type-generic macro: If `z` has type `long double complex`, `clogl` is called. if `z` has type `double complex`, `clog` is called, if `z` has type `float complex`, `clogf` is called. If `z` is real or integer, then the macro invokes the corresponding real function (`logf`, `log`, `logl`). If `z` is imaginary, the corresponding complex number version is called.

### Parameters

| z  |   | -  |   | complex argument  |

### Return value

If no errors occur, the complex natural logarithm of `z` is returned, in the range of a strip in the interval [−iπ, +iπ] along the imaginary axis and mathematically unbounded along the real axis.
若沒有發生錯誤，回傳 z 的複數自然對數。其虛部範圍為 [−iπ, +iπ]，沿實軸則沒有界限。

### Error handling and special values
錯誤處理與特殊值

Errors are reported consistent with math_errhandling
錯誤會依照 math_errhandling 的規定回報。
If the implementation supports IEEE floating-point arithmetic,
如果實現支援 IEEE 浮點運算，

- The function is continuous onto the branch cut taking into account the sign of imaginary part
此函式在分支切割上會依虛部的符號保持連續。

- `clog(conj(z)) == conj(clog(z))`
clog(conj(z)) == conj(clog(z))

- If `z` is `-0+0i`, the result is `-∞+πi` and FE_DIVBYZERO is raised
如果 z 是 -0+0i，結果是 -∞+πi 並引發 FE_DIVBYZERO

- If `z` is `+0+0i`, the result is `-∞+0i` and FE_DIVBYZERO is raised
如果 z 是 +0+0i，結果是 -∞+0i 並引發 FE_DIVBYZERO

- If `z` is `x+∞i` (for any finite x), the result is `+∞+πi/2`
如果 z 是 x+∞i（x 為任意有限值），結果是 +∞+πi/2

- If `z` is `x+NaNi` (for any finite x), the result is `NaN+NaNi` and FE_INVALID may be raised
如果 z 是 x+NaNi（x 為任意有限值），結果是 NaN+NaNi，並可能引發 FE_INVALID

- If `z` is `-∞+yi` (for any finite positive y), the result is `+∞+πi`
如果 z 是 -∞+yi（y 為任意有限正值），結果是 +∞+πi

- If `z` is `+∞+yi` (for any finite positive y), the result is `+∞+0i`
如果 z 是 +∞+yi（y 為任意有限正值），結果是 +∞+0i

- If `z` is `-∞+∞i`, the result is `+∞+3πi/4`
如果 z 是 -∞+∞i，結果是 +∞+3πi/4

- If `z` is `+∞+∞i`, the result is `+∞+πi/4`
如果 z 是 +∞+∞i，結果是 +∞+πi/4

- If `z` is `±∞+NaNi`, the result is `+∞+NaNi`
如果 z 是 ±∞+NaNi，結果是 +∞+NaNi

- If `z` is `NaN+yi` (for any finite y), the result is `NaN+NaNi` and FE_INVALID may be raised
如果 z 是 NaN+yi（y 為任意有限值），結果是 NaN+NaNi，並可能引發 FE_INVALID

- If `z` is `NaN+∞i`, the result is `+∞+NaNi`
如果 z 是 NaN+∞i，結果是 +∞+NaNi

- If `z` is `NaN+NaNi`, the result is `NaN+NaNi`
如果 z 是 NaN+NaNi，結果是 NaN+NaNi

### Notes

The natural logarithm of a complex number z with polar coordinate components (r,θ) equals ln r + i(θ+2nπ), with the principal value ln r + iθ
極座標分量為 (r,θ) 的複數 z 的自然對數等於 ln r + i(θ+2nπ)，主值為 ln r + iθ

### Example

Run this code

```c
#include <stdio.h> #include <math.h> #include <complex.h> int main(void) {  double complex z = clog(I); // r = 1, θ = pi/2  printf("2*log(i) = %.1f%+fi\n", creal(2*z), cimag(2*z));  double complex z2 = clog(sqrt(2)/2 + sqrt(2)/2*I); // r = 1, θ = pi/4  printf("4*log(sqrt(2)/2+sqrt(2)i/2) = %.1f%+fi\n", creal(4*z2), cimag(4*z2));  double complex z3 = clog(-1); // r = 1, θ = pi  printf("log(-1+0i) = %.1f%+fi\n", creal(z3), cimag(z3));  double complex z4 = clog(conj(-1)); // or clog(CMPLX(-1, -0.0)) in C11  printf("log(-1-0i) (the other side of the cut) = %.1f%+fi\n", creal(z4), cimag(z4)); }
```

Output:

```c
2*log(i) = 0.0+3.141593i 4*log(sqrt(2)/2+sqrt(2)i/2) = 0.0+3.141593i log(-1+0i) = 0.0+3.141593i log(-1-0i) (the other side of the cut) = 0.0-3.141593i
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.3.7.2 The clog functions (p: 195)
7.3.7.2 clog 函式（頁：195）
7.3.7.2 clog 函式（頁：195）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- G.6.3.2 The clog functions (p: 543-544)
G.6.3.2 clog 函式（頁：543-544）
G.6.3.2 clog 函式（頁：543-544）

- G.7 Type-generic math <tgmath.h> (p: 545)
G.7 泛型數學 <tgmath.h>（頁：545）
G.7 泛型數學 <tgmath.h>（頁：545）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.3.7.2 The clog functions (p: 176-177)
7.3.7.2 clog 函式（頁：176-177）
7.3.7.2 clog 函式（頁：176-177）

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- G.6.3.2 The clog functions (p: 478-479)
G.6.3.2 clog 函式（頁：478-479）
G.6.3.2 clog 函式（頁：478-479）

- G.7 Type-generic math <tgmath.h> (p: 480)
G.7 泛型數學 <tgmath.h>（頁：480）
G.7 泛型數學 <tgmath.h>（頁：480）

### See also

cexpcexpfcexpl
(C99)(C99)(C99)
|   | computes the complex base-e exponential
(function)   |

loglogflogl
(C99)(C99)
|   | computes natural (base-*e*) logarithm (lnxln⁡xln(x))
(function)   |

C++ documentation for log

---
來源頁路徑：`en.cppreference.com/c/numeric/complex/clog.html`

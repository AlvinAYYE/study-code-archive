# ccoshf, ccosh, ccoshl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<complex.h>`
|   |  |   |  |

```c
float complex ccoshf( float complex z );
```
|   |  (1)  |   |  (since C99)  |

```c
double complex ccosh( double complex z );
```
|   |  (2)  |   |  (since C99)  |

```c
long double complex ccoshl( long double complex z );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define cosh( z )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Computes the complex hyperbolic cosine of `z`.

4) Type-generic macro: If `z` has type `long double complex`, `ccoshl` is called. if `z` has type `double complex`, `ccosh` is called, if `z` has type `float complex`, `ccoshf` is called. If `z` is real or integer, then the macro invokes the corresponding real function (`coshf`, `cosh`, `coshl`). If `z` is imaginary, then the macro invokes the corresponding real version of the function cos, implementing the formula cosh(iy) = cos(y), and the return type is real.

### Parameters

| z  |   | -  |   | complex argument  |

### Return value

If no errors occur, complex hyperbolic cosine of `z` is returned
若沒有發生錯誤，回傳 z 的複數雙曲餘弦。

### Error handling and special values
錯誤處理與特殊值

Errors are reported consistent with math_errhandling
錯誤會依照 math_errhandling 的規定回報。
If the implementation supports IEEE floating-point arithmetic,
若實作支援 IEEE 浮點運算：

- `ccosh(conj(z)) == conj(ccosh(z))`
ccosh(conj(z)) == conj(ccosh(z))

- `ccosh(z) == ccosh(-z)`
ccosh(z) == ccosh(-z)

- If `z` is `+0+0i`, the result is `1+0i`
如果 z 是 +0+0i，結果是 1+0i

- If `z` is `+0+∞i`, the result is `NaN±0i` (the sign of the imaginary part is unspecified) and FE_INVALID is raised
如果 z 是 +0+∞i，結果是 NaN±0i（虛部的符號未指定）並引發 FE_INVALID

- If `z` is `+0+NaNi`, the result is `NaN±0i` (the sign of the imaginary part is unspecified)
如果 z 是 +0+NaNi，結果是 NaN±0i（虛部的符號未指定）

- If `z` is `x+∞i` (for any finite non-zero x), the result is `NaN+NaNi` and FE_INVALID is raised
如果 z 是 x+∞i（x 為任意有限非零值），結果是 NaN+NaNi 並引發 FE_INVALID

- If `z` is `x+NaNi` (for any finite non-zero x), the result is `NaN+NaNi` and FE_INVALID may be raised
如果 z 是 x+NaNi（x 為任意有限非零值），結果是 NaN+NaNi，並可能引發 FE_INVALID

- If `z` is `+∞+0i`, the result is `+∞+0i`
如果 z 是 +∞+0i，結果是 +∞+0i

- If `z` is `+∞+yi` (for any finite non-zero y), the result is `+∞cis(y)`
如果 z 是 +∞+yi（y 為任意有限非零值），結果是 +∞cis(y)

- If `z` is `+∞+∞i`, the result is `±∞+NaNi` (the sign of the real part is unspecified) and FE_INVALID is raised
如果 z 是 +∞+∞i，結果是 ±∞+NaNi（實部的符號未指定）並引發 FE_INVALID

- If `z` is `+∞+NaN`, the result is `+∞+NaN`
如果 z 是 +∞+NaN，結果是 +∞+NaN

- If `z` is `NaN+0i`, the result is `NaN±0i` (the sign of the imaginary part is unspecified)
如果 z 是 NaN+0i，結果是 NaN±0i（虛部的符號未指定）

- If `z` is `NaN+yi` (for any finite non-zero y), the result is `NaN+NaNi` and FE_INVALID may be raised
如果 z 是 NaN+yi（y 為任意有限非零值），結果是 NaN+NaNi，並可能引發 FE_INVALID

- If `z` is `NaN+NaNi`, the result is `NaN+NaNi`
如果 z 是 NaN+NaNi，結果是 NaN+NaNi

where cis(y) is cos(y) + i sin(y)
其中 cis(y) = cos(y) + i sin(y)。

### Notes
Mathematical definition of hyperbolic cosine is
雙曲餘弦的數學定義如下：
cosh z =
ez
+e-z

2 |

Hyperbolic cosine is an entire function in the complex plane and has no branch cuts. It is periodic with respect to the imaginary component, with period 2πi
雙曲餘弦在複平面上是整函式，沒有分支切割；它以虛部為週期變數，週期為 2πi。

### Example

Run this code

```c
#include <stdio.h> #include <math.h> #include <complex.h> int main(void) {  double complex z = ccosh(1); // behaves like real cosh along the real line  printf("cosh(1+0i) = %f%+fi (cosh(1)=%f)\n", creal(z), cimag(z), cosh(1));  double complex z2 = ccosh(I); // behaves like real cosine along the imaginary line  printf("cosh(0+1i) = %f%+fi ( cos(1)=%f)\n", creal(z2), cimag(z2), cos(1)); }
```

Output:

```c
cosh(1+0i) = 1.543081+0.000000i (cosh(1)=1.543081) cosh(0+1i) = 0.540302+0.000000i ( cos(1)=0.540302)
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.3.6.4 The ccosh functions (p: 193)
7.3.6.4 ccosh 函式（頁：193）
7.3.6.4 ccosh 函式（頁：193）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- G.6.2.4 The ccosh functions (p: 541)
G.6.2.4 ccosh 函式（頁：541）
G.6.2.4 ccosh 函式（頁：541）

- G.7 Type-generic math <tgmath.h> (p: 545)
G.7 泛型數學 <tgmath.h>（頁：545）
G.7 泛型數學 <tgmath.h>（頁：545）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.3.6.4 The ccosh functions (p: 175)
7.3.6.4 ccosh 函式（頁：175）
7.3.6.4 ccosh 函式（頁：175）

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- G.6.2.4 The ccosh functions (p: 476)
G.6.2.4 ccosh 函式（頁：476）
G.6.2.4 ccosh 函式（頁：476）

- G.7 Type-generic math <tgmath.h> (p: 480)
G.7 泛型數學 <tgmath.h>（頁：480）
G.7 泛型數學 <tgmath.h>（頁：480）

### See also

csinhcsinhfcsinhl
(C99)(C99)(C99)
|   | computes the complex hyperbolic sine
(function)   |

ctanhctanhfctanhl
(C99)(C99)(C99)
|   | computes the complex hyperbolic tangent
(function)   |

cacoshcacoshfcacoshl
(C99)(C99)(C99)
|   | computes the complex arc hyperbolic cosine
(function)   |

coshcoshfcoshl
(C99)(C99)
|   | computes hyperbolic cosine (coshxcosh⁡xcosh(x))
(function)   |

C++ documentation for cosh

---
來源頁路徑：`en.cppreference.com/c/numeric/complex/ccosh.html`

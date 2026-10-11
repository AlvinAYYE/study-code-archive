# casinhf, casinh, casinhl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<complex.h>`
|   |  |   |  |

```c
float complex casinhf( float complex z );
```
|   |  (1)  |   |  (since C99)  |

```c
double complex casinh( double complex z );
```
|   |  (2)  |   |  (since C99)  |

```c
long double complex casinhl( long double complex z );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define asinh( z )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Computes the complex arc hyperbolic sine of `z` with branch cuts outside the interval [−i; +i] along the imaginary axis.

4) Type-generic macro: If `z` has type `long double complex`, `casinhl` is called. if `z` has type `double complex`, `casinh` is called, if `z` has type `float complex`, `casinhf` is called. If `z` is real or integer, then the macro invokes the corresponding real function (`asinhf`, `asinh`, `asinhl`). If `z` is imaginary, then the macro invokes the corresponding real version of the function asin, implementing the formula asinh(iy) = i asin(y), and the return type is imaginary.

### Parameters

| z  |   | -  |   | complex argument  |

### Return value

If no errors occur, the complex arc hyperbolic sine of `z` is returned, in the range of a strip mathematically unbounded along the real axis and in the interval [−iπ/2; +iπ/2] along the imaginary axis.
若沒有發生錯誤，回傳 z 的複數反雙曲正弦。實部沒有界限，虛部介於 [−iπ/2, +iπ/2]。

### Error handling and special values
錯誤處理與特殊值

Errors are reported consistent with math_errhandling
錯誤會依照 math_errhandling 的規定回報。
If the implementation supports IEEE floating-point arithmetic,
若實作支援 IEEE 浮點運算：

- `casinh(conj(z)) == conj(casinh(z))`
casinh(conj(z)) == conj(casinh(z))

- `casinh(-z) == -casinh(z)`
casinh(-z) == -casinh(z)

- If `z` is `+0+0i`, the result is `+0+0i`
如果 z 是 +0+0i，結果是 +0+0i

- If `z` is `x+∞i` (for any positive finite x), the result is `+∞+π/2`
如果 z 是 x+∞i（x 為任意正有限值），結果是 +∞+π/2

- If `z` is `x+NaNi` (for any finite x), the result is `NaN+NaNi` and FE_INVALID may be raised
如果 z 是 x+NaNi（x 為任意有限值），結果是 NaN+NaNi，並可能引發 FE_INVALID

- If `z` is `+∞+yi` (for any positive finite y), the result is `+∞+0i`
如果 z 是 +∞+yi（y 為任意正有限值），結果是 +∞+0i

- If `z` is `+∞+∞i`, the result is `+∞+iπ/4`
如果 z 是 +∞+∞i，結果是 +∞+iπ/4

- If `z` is `+∞+NaNi`, the result is `+∞+NaNi`
如果 z 是 +∞+NaNi，結果是 +∞+NaNi

- If `z` is `NaN+0i`, the result is `NaN+0i`
如果 z 是 NaN+0i，結果是 NaN+0i

- If `z` is `NaN+yi` (for any finite nonzero y), the result is `NaN+NaNi` and FE_INVALID may be raised
如果 z 是 NaN+yi（y 為任意有限非零值），結果是 NaN+NaNi，並可能引發 FE_INVALID

- If `z` is `NaN+∞i`, the result is `±∞+NaNi` (the sign of the real part is unspecified)
如果 z 是 NaN+∞i，結果是 ±∞+NaNi（實部的符號未指定）

- If `z` is `NaN+NaNi`, the result is `NaN+NaNi`
如果 z 是 NaN+NaNi，結果是 NaN+NaNi

### Notes

Although the C standard names this function "complex arc hyperbolic sine", the inverse functions of the hyperbolic functions are the area functions. Their argument is the area of a hyperbolic sector, not an arc. The correct name is "complex inverse hyperbolic sine", and, less common, "complex area hyperbolic sine".
C 標準雖將此函式稱為「complex arc hyperbolic sine」，但雙曲函式的反函式是面積函式：其引數代表雙曲扇形的面積，而不是弧。較正確的名稱是「complex inverse hyperbolic sine」，也有人稱為「complex area hyperbolic sine」。
Inverse hyperbolic sine is a multivalued function and requires a branch cut on the complex plane. The branch cut is conventionally placed at the line segments (-*i*∞,-*i*) and (*i*,*i*∞) of the imaginary axis.
反雙曲正弦是多值函式，因此在複平面上需要設定分支切割。通常將分支切割放在虛軸的 (-i∞, -i) 和 (i, i∞) 區間。
The mathematical definition of the principal value of the inverse hyperbolic sine is asinh z = ln(z + √1+z2
)
反雙曲正弦主值的數學定義為 asinh(z) = ln(z + √(1 + z²))。
For any z,
asinh(z) =
asin(iz) |
i |

### Example

Run this code

```c
#include <stdio.h> #include <complex.h> int main(void) {  double complex z = casinh(0+2*I);  printf("casinh(+0+2i) = %f%+fi\n", creal(z), cimag(z));  double complex z2 = casinh(-conj(2*I)); // or casinh(CMPLX(-0.0, 2)) in C11  printf("casinh(-0+2i) (the other side of the cut) = %f%+fi\n", creal(z2), cimag(z2));  // for any z, asinh(z) = asin(iz)/i  double complex z3 = casinh(1+2*I);  printf("casinh(1+2i) = %f%+fi\n", creal(z3), cimag(z3));  double complex z4 = casin((1+2*I)*I)/I;  printf("casin(i * (1+2i))/i = %f%+fi\n", creal(z4), cimag(z4)); }
```

Output:

```c
casinh(+0+2i) = 1.316958+1.570796i casinh(-0+2i) (the other side of the cut) = -1.316958+1.570796i casinh(1+2i) = 1.469352+1.063440i casin(i * (1+2i))/i = 1.469352+1.063440i
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.3.6.2 The casinh functions (p: 192-193)
7.3.6.2 casinh 函式（頁：192-193）
7.3.6.2 casinh 函式（頁：192-193）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- G.6.2.2 The casinh functions (p: 540)
G.6.2.2 casinh 函式（頁：540）
G.6.2.2 casinh 函式（頁：540）

- G.7 Type-generic math <tgmath.h> (p: 545)
G.7 泛型數學 <tgmath.h>（頁：545）
G.7 泛型數學 <tgmath.h>（頁：545）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.3.6.2 The casinh functions (p: 174-175)
7.3.6.2 casinh 函式（頁：174-175）
7.3.6.2 casinh 函式（頁：174-175）

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- G.6.2.2 The casinh functions (p: 475)
G.6.2.2 casinh 函式（頁：475）
G.6.2.2 casinh 函式（頁：475）

- G.7 Type-generic math <tgmath.h> (p: 480)
G.7 泛型數學 <tgmath.h>（頁：480）
G.7 泛型數學 <tgmath.h>（頁：480）

### See also

cacoshcacoshfcacoshl
(C99)(C99)(C99)
|   | computes the complex arc hyperbolic cosine
(function)   |

catanhcatanhfcatanhl
(C99)(C99)(C99)
|   | computes the complex arc hyperbolic tangent
(function)   |

csinhcsinhfcsinhl
(C99)(C99)(C99)
|   | computes the complex hyperbolic sine
(function)   |

asinhasinhfasinhl
(C99)(C99)(C99)
|   | computes inverse hyperbolic sine (arsinhxarsinh⁡xarsinh(x))
(function)   |

C++ documentation for asinh

---
來源頁路徑：`en.cppreference.com/c/numeric/complex/casinh.html`

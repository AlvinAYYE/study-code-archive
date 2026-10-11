# catanhf, catanh, catanhl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<complex.h>`
|   |  |   |  |

```c
float complex catanhf( float complex z );
```
|   |  (1)  |   |  (since C99)  |

```c
double complex catanh( double complex z );
```
|   |  (2)  |   |  (since C99)  |

```c
long double complex catanhl( long double complex z );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define atanh( z )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Computes the complex arc hyperbolic tangent of `z` with branch cuts outside the interval [−1; +1] along the real axis.

4) Type-generic macro: If `z` has type `long double complex`, `catanhl` is called. if `z` has type `double complex`, `catanh` is called, if `z` has type `float complex`, `catanhf` is called. If `z` is real or integer, then the macro invokes the corresponding real function (`atanhf`, `atanh`, `atanhl`). If `z` is imaginary, then the macro invokes the corresponding real version of `atan`, implementing the formula atanh(iy) = i atan(y), and the return type is imaginary.

### Parameters

| z  |   | -  |   | complex argument  |

### Return value

If no errors occur, the complex arc hyperbolic tangent of `z` is returned, in the range of a half-strip mathematically unbounded along the real axis and in the interval [−iπ/2; +iπ/2] along the imaginary axis.
若沒有發生錯誤，回傳 z 的複數反雙曲正切。實部沒有界限，虛部介於 [−iπ/2, +iπ/2]。

### Error handling and special values
錯誤處理與特殊值

Errors are reported consistent with math_errhandling
錯誤會依照 math_errhandling 的規定回報。
If the implementation supports IEEE floating-point arithmetic,
若實作支援 IEEE 浮點運算：

- `catanh(conj(z)) == conj(catanh(z))`
catanh ( conj ( z )) == conj ( catanh ( z ))

- `catanh(-z) == -catanh(z)`
catanh ( - z ) == - catanh ( z )

- If `z` is `+0+0i`, the result is `+0+0i`
如果 z 是 +0+0i，結果是 +0+0i

- If `z` is `+0+NaNi`, the result is `+0+NaNi`
若 z 為 +0+NaNi，則結果為 +0+NaNi

- If `z` is `+1+0i`, the result is `+∞+0i` and FE_DIVBYZERO is raised
若 z 為 +1+0i，則結果為 +∞+0i，並引發 FE_DIVBYZERO

- If `z` is `x+∞i` (for any finite positive x), the result is `+0+iπ/2`
若 z 為 x+∞i（對任意有限正數 x），結果為 +0+iπ/2

- If `z` is `x+NaNi` (for any finite nonzero x), the result is `NaN+NaNi` and FE_INVALID may be raised
若 z 為 x+NaNi（對任意有限非零 x），結果為 NaN+NaNi，並且可能引發 FE_INVALID

- If `z` is `+∞+yi` (for any finite positive y), the result is `+0+iπ/2`
若 z 為 +∞+yi（對任意有限正數 y），結果為 +0+iπ/2

- If `z` is `+∞+∞i`, the result is `+0+iπ/2`
若 z 為 +∞+∞i，結果為 +0+iπ/2

- If `z` is `+∞+NaNi`, the result is `+0+NaNi`
若 z 為 +∞+NaNi，結果為 +0+NaNi

- If `z` is `NaN+yi` (for any finite y), the result is `NaN+NaNi` and FE_INVALID may be raised
如果 z 是 NaN+yi（y 為任意有限值），結果是 NaN+NaNi，並可能引發 FE_INVALID

- If `z` is `NaN+∞i`, the result is `±0+iπ/2` (the sign of the real part is unspecified)
若 z 為 NaN+∞i，結果為 ±0+iπ/2（實部的符號未指定）

- If `z` is `NaN+NaNi`, the result is `NaN+NaNi`
如果 z 是 NaN+NaNi，結果是 NaN+NaNi

### Notes

Although the C standard names this function "complex arc hyperbolic tangent", the inverse functions of the hyperbolic functions are the area functions. Their argument is the area of a hyperbolic sector, not an arc. The correct name is "complex inverse hyperbolic tangent", and, less common, "complex area hyperbolic tangent".
C 標準雖將此函式稱為「complex arc hyperbolic tangent」，但雙曲函式的反函式是面積函式：其引數代表雙曲扇形的面積，而不是弧。較正確的名稱是「complex inverse hyperbolic tangent」，也有人稱為「complex area hyperbolic tangent」。
Inverse hyperbolic tangent is a multivalued function and requires a branch cut on the complex plane. The branch cut is conventionally placed at the line segmentd (-∞,-1] and [+1,+∞) of the real axis.
反雙曲正切是多值函式，因此在複平面上需要設定分支切割。通常將分支切割放在實軸的 (-∞, -1] 和 [+1, +∞) 區間。
The mathematical definition of the principal value of the inverse hyperbolic tangent is
反雙曲正切主值的數學定義如下：
atanh z =
ln(1+z)-ln(z-1) |
2 |
.

For any z,
atanh(z) =
atan(iz) |
i |

### Example

Run this code

```c
#include <stdio.h> #include <complex.h> int main(void) {  double complex z = catanh(2);  printf("catanh(+2+0i) = %f%+fi\n", creal(z), cimag(z));  double complex z2 = catanh(conj(2)); // or catanh(CMPLX(2, -0.0)) in C11  printf("catanh(+2-0i) (the other side of the cut) = %f%+fi\n", creal(z2), cimag(z2));  // for any z, atanh(z) = atan(iz)/i  double complex z3 = catanh(1+2*I);  printf("catanh(1+2i) = %f%+fi\n", creal(z3), cimag(z3));  double complex z4 = catan((1+2*I)*I)/I;  printf("catan(i * (1+2i))/i = %f%+fi\n", creal(z4), cimag(z4)); }
```

Output:

```c
catanh(+2+0i) = 0.549306+1.570796i catanh(+2-0i) (the other side of the cut) = 0.549306-1.570796i catanh(1+2i) = 0.173287+1.178097i catan(i * (1+2i))/i = 0.173287+1.178097i
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.3.6.3 The catanh functions (p: 193)
7.3.6.3 catanh 函式 (p: 193)
7.3.6.3 catanh 函式 (p: 193)

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- G.6.2.3 The catanh functions (p: 540-541)
G.6.2.3 catanh 函式 (p: 540-541)
G.6.2.3 catanh 函式 (p: 540-541)

- G.7 Type-generic math <tgmath.h> (p: 545)
G.7 泛型數學 <tgmath.h>（頁：545）
G.7 泛型數學 <tgmath.h>（頁：545）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.3.6.3 The catanh functions (p: 175)
7.3.6.3 catanh 函式 (p: 175)
7.3.6.3 catanh 函式 (p: 175)

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- G.6.2.3 The catanh functions (p: 475-476)
G.6.2.3 catanh 函式 (p: 475-476)
G.6.2.3 catanh 函式 (p: 475-476)

- G.7 Type-generic math <tgmath.h> (p: 480)
G.7 泛型數學 <tgmath.h>（頁：480）
G.7 泛型數學 <tgmath.h>（頁：480）

### See also

casinhcasinhfcasinhl
(C99)(C99)(C99)
|   | computes the complex arc hyperbolic sine
(function)   |

cacoshcacoshfcacoshl
(C99)(C99)(C99)
|   | computes the complex arc hyperbolic cosine
(function)   |

ctanhctanhfctanhl
(C99)(C99)(C99)
|   | computes the complex hyperbolic tangent
(function)   |

atanhatanhfatanhl
(C99)(C99)(C99)
|   | computes inverse hyperbolic tangent (artanhxartanh⁡xartanh(x))
(function)   |

C++ documentation for atanh

---
來源頁路徑：`en.cppreference.com/c/numeric/complex/catanh.html`

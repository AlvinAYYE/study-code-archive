# cacoshf, cacosh, cacoshl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<complex.h>`
|   |  |   |  |

```c
float complex cacoshf( float complex z );
```
|   |  (1)  |   |  (since C99)  |

```c
double complex cacosh( double complex z );
```
|   |  (2)  |   |  (since C99)  |

```c
long double complex cacoshl( long double complex z );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define acosh( z )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Computes complex arc hyperbolic cosine of a complex value `z` with branch cut at values less than 1 along the real axis.

4) Type-generic macro: If `z` has type `long double complex`, `cacoshl` is called. if `z` has type `double complex`, `cacosh` is called, if `z` has type `float complex`, `cacoshf` is called. If `z` is real or integer, then the macro invokes the corresponding real function (`acoshf`, `acosh`, `acoshl`). If `z` is imaginary, then the macro invokes the corresponding complex number version and the return type is complex.

### Parameters

| z  |   | -  |   | complex argument  |

### Return value

The complex arc hyperbolic cosine of `z` in the interval [0; ∞) along the real axis and in the interval [−iπ; +iπ] along the imaginary axis.
回傳 z 的複數反雙曲餘弦；實部介於 [0, ∞)，虛部介於 [−iπ, +iπ]。

### Error handling and special values
錯誤處理與特殊值

Errors are reported consistent with math_errhandling
錯誤會依照 math_errhandling 的規定回報。
If the implementation supports IEEE floating-point arithmetic,
若實作支援 IEEE 浮點運算：

- `cacosh(conj(z)) == conj(cacosh(z))`
cacosh ( conj ( z )) == conj ( cacosh ( z ))

- If `z` is `±0+0i`, the result is `+0+iπ/2`
若 z 為 ±0+0i，結果為 +0+iπ/2

- If `z` is `+x+∞i` (for any finite x), the result is `+∞+iπ/2`
若 z 為 +x+∞i（對任意有限 x），結果為 +∞+iπ/2

- If `z` is `+x+NaNi` (for non-zero finite x), the result is `NaN+NaNi` and FE_INVALID may be raised.
若 z 為 +x+NaNi（對非零有限 x），結果為 NaN+NaNi，並且可能引發 FE_INVALID。

- If `z` is `0+NaNi`, the result is `NaN±iπ/2`, where the sign of the imaginary part is unspecified
若 z 為 0+NaNi，結果為 NaN±iπ/2，其中虛部的符號未指定

- If `z` is `-∞+yi` (for any positive finite y), the result is `+∞+iπ`
若 z 為 -∞+yi（對任意有限正數 y），結果為 +∞+iπ

- If `z` is `+∞+yi` (for any positive finite y), the result is `+∞+0i`
如果 z 是 +∞+yi（y 為任意正有限值），結果是 +∞+0i

- If `z` is `-∞+∞i`, the result is `+∞+3iπ/4`
若 z 為 -∞+∞i，結果為 +∞+3iπ/4

- If `z` is `+∞+∞i`, the result is `+∞+iπ/4`
如果 z 是 +∞+∞i，結果是 +∞+iπ/4

- If `z` is `±∞+NaNi`, the result is `+∞+NaNi`
如果 z 是 ±∞+NaNi，結果是 +∞+NaNi

- If `z` is `NaN+yi` (for any finite y), the result is `NaN+NaNi` and FE_INVALID may be raised.
若 z 為 NaN+yi（對任意有限 y），結果為 NaN+NaNi，並且可能引發 FE_INVALID。

- If `z` is `NaN+∞i`, the result is `+∞+NaNi`
如果 z 是 NaN+∞i，結果是 +∞+NaNi

- If `z` is `NaN+NaNi`, the result is `NaN+NaNi`
如果 z 是 NaN+NaNi，結果是 NaN+NaNi

### Notes

Although the C standard names this function "complex arc hyperbolic cosine", the inverse functions of the hyperbolic functions are the area functions. Their argument is the area of a hyperbolic sector, not an arc. The correct name is "complex inverse hyperbolic cosine", and, less common, "complex area hyperbolic cosine".
C 標準雖將此函式稱為「complex arc hyperbolic cosine」，但雙曲函式的反函式是面積函式：其引數代表雙曲扇形的面積，而不是弧。較正確的名稱是「complex inverse hyperbolic cosine」，也有人稱為「complex area hyperbolic cosine」。
Inverse hyperbolic cosine is a multivalued function and requires a branch cut on the complex plane. The branch cut is conventionally placed at the line segment (-∞,+1) of the real axis.
反雙曲餘弦是多值函式，因此在複平面上需要設定分支切割。通常將分支切割放在實軸的 (-∞, +1) 區間。
The mathematical definition of the principal value of the inverse hyperbolic cosine is acosh z = ln(z + √z+1 √z-1)
反雙曲餘弦主值的數學定義為 acosh z = ln(z + √ z+1 √ z-1 )
For any z,
acosh(z) =
√z-1 |
√1-z |
acos(z)
, or simply i acos(z) in the upper half of the complex plane.
，或者在複平面的上半部分簡單地寫為 i acos(z)。
### Example

Run this code

```c
#include <stdio.h> #include <complex.h> int main(void) {  double complex z = cacosh(0.5);  printf("cacosh(+0.5+0i) = %f%+fi\n", creal(z), cimag(z));  double complex z2 = conj(0.5); // or cacosh(CMPLX(0.5, -0.0)) in C11  printf("cacosh(+0.5-0i) (the other side of the cut) = %f%+fi\n", creal(z2), cimag(z2));  // in upper half-plane, acosh(z) = i*acos(z)   double complex z3 = casinh(1+I);  printf("casinh(1+1i) = %f%+fi\n", creal(z3), cimag(z3));  double complex z4 = I*casin(1+I);  printf("I*asin(1+1i) = %f%+fi\n", creal(z4), cimag(z4)); }
```

Output:

```c
cacosh(+0.5+0i) = 0.000000-1.047198i cacosh(+0.5-0i) (the other side of the cut) = 0.500000-0.000000i casinh(1+1i) = 1.061275+0.666239i I*asin(1+1i) = -1.061275+0.666239i
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.3.6.1 The cacosh functions (p: 192)
7.3.6.1 cacosh 函式 (p: 192)
7.3.6.1 cacosh 函式 (p: 192)

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- G.6.2.1 The cacosh functions (p: 539-540)
G.6.2.1 cacosh 函式 (p: 539-540)
G.6.2.1 cacosh 函式 (p: 539-540)

- G.7 Type-generic math <tgmath.h> (p: 545)
G.7 泛型數學 <tgmath.h>（頁：545）
G.7 泛型數學 <tgmath.h>（頁：545）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.3.6.1 The cacosh functions (p: 174)
7.3.6.1 cacosh 函式 (p: 174)
7.3.6.1 cacosh 函式 (p: 174)

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- G.6.2.1 The cacosh functions (p: 474-475)
G.6.2.1 cacosh 函式 (p: 474-475)
G.6.2.1 cacosh 函式 (p: 474-475)

- G.7 Type-generic math <tgmath.h> (p: 480)
G.7 泛型數學 <tgmath.h>（頁：480）
G.7 泛型數學 <tgmath.h>（頁：480）

### See also

cacoscacosfcacosl
(C99)(C99)(C99)
|   | computes the complex arc cosine
(function)   |

casinhcasinhfcasinhl
(C99)(C99)(C99)
|   | computes the complex arc hyperbolic sine
(function)   |

catanhcatanhfcatanhl
(C99)(C99)(C99)
|   | computes the complex arc hyperbolic tangent
(function)   |

ccoshccoshfccoshl
(C99)(C99)(C99)
|   | computes the complex hyperbolic cosine
(function)   |

acoshacoshfacoshl
(C99)(C99)(C99)
|   | computes inverse hyperbolic cosine (arcoshxarcosh⁡xarcosh(x))
(function)   |

C++ documentation for acosh

---
來源頁路徑：`en.cppreference.com/c/numeric/complex/cacosh.html`

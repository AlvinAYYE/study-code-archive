# cacosf, cacos, cacosl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<complex.h>`
|   |  |   |  |

```c
float complex cacosf( float complex z );
```
|   |  (1)  |   |  (since C99)  |

```c
double complex cacos( double complex z );
```
|   |  (2)  |   |  (since C99)  |

```c
long double complex cacosl( long double complex z );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define acos( z )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Computes the complex arc cosine of `z` with branch cuts outside the interval [−1,+1] along the real axis.

4) Type-generic macro: If `z` has type `long double complex`, `cacosl` is called. if `z` has type `double complex`, `cacos` is called, if `z` has type `float complex`, `cacosf` is called. If `z` is real or integer, then the macro invokes the corresponding real function (`acosf`, `acos`, `acosl`). If `z` is imaginary, then the macro invokes the corresponding complex number version.

### Parameters

| z  |   | -  |   | complex argument  |

### Return value

If no errors occur, complex arc cosine of `z` is returned, in the range a strip unbounded along the imaginary axis and in the interval [0; π] along the real axis.
若沒有發生錯誤，回傳 z 的複數反餘弦。其實部介於 [0, π]，虛部則沒有界限。

### Error handling and special values
錯誤處理與特殊值

Errors are reported consistent with math_errhandling.
錯誤會依照 math_errhandling 的規定回報。
If the implementation supports IEEE floating-point arithmetic,
若實作支援 IEEE 浮點運算：

- `cacos(conj(z)) == conj(cacos(z))`
cacos ( conj ( z )) == conj ( cacos ( z ))

- If `z` is `±0+0i`, the result is `π/2-0i`
若 z 為 ±0+0i，結果為 π/2-0i

- If `z` is `±0+NaNi`, the result is `π/2+NaNi`
若 z 為 ±0+NaNi，結果為 π/2+NaNi

- If `z` is `x+∞i` (for any finite x), the result is `π/2-∞i`
若 z 為 x+∞i（對任意有限 x），結果為 π/2-∞i

- If `z` is `x+NaNi` (for any nonzero finite x), the result is `NaN+NaNi` and FE_INVALID may be raised.
若 z 為 x+NaNi（對任意有限非零 x），結果為 NaN+NaNi，並且可能引發 FE_INVALID。

- If `z` is `-∞+yi` (for any positive finite y), the result is `π-∞i`
若 z 為 -∞+yi（對任意有限正數 y），結果為 π-∞i

- If `z` is `+∞+yi` (for any positive finite y), the result is `+0-∞i`
若 z 為 +∞+yi（對任意有限正數 y），結果為 +0-∞i

- If `z` is `-∞+∞i`, the result is `3π/4-∞i`
若 z 為 -∞+∞i，結果為 3π/4-∞i

- If `z` is `+∞+∞i`, the result is `π/4-∞i`
若 z 為 +∞+∞i，結果為 π/4-∞i

- If `z` is `±∞+NaNi`, the result is `NaN±∞i` (the sign of the imaginary part is unspecified)
若 z 為 ±∞+NaNi，結果為 NaN±∞i（虛部的符號未指定）

- If `z` is `NaN+yi` (for any finite y), the result is `NaN+NaNi` and FE_INVALID may be raised
如果 z 是 NaN+yi（y 為任意有限值），結果是 NaN+NaNi，並可能引發 FE_INVALID

- If `z` is `NaN+∞i`, the result is `NaN-∞i`
若 z 為 NaN+∞i，結果為 NaN-∞i

- If `z` is `NaN+NaNi`, the result is `NaN+NaNi`
如果 z 是 NaN+NaNi，結果是 NaN+NaNi

### Notes

Inverse cosine (or arc cosine) is a multivalued function and requires a branch cut on the complex plane. The branch cut is conventially placed at the line segments (-∞,-1) and (1,∞) of the real axis.
反餘弦（arc cosine）是多值函式，因此在複平面上需要設定分支切割。通常將分支切割放在實軸的 (-∞, -1) 和 (1, ∞) 區間。
The mathematical definition of the principal value of arc cosine is
反餘弦主值的數學定義如下：
acos z =
1 |
2 |
π + *i*ln(*i*z + √1-z2
)
For any z, acos(z) = π - acos(-z)
對任何 z，acos(z) = π - acos(-z)。

### Example

Run this code

```c
#include <stdio.h> #include <math.h> #include <complex.h> int main(void) {  double complex z = cacos(-2);  printf("cacos(-2+0i) = %f%+fi\n", creal(z), cimag(z));  double complex z2 = cacos(conj(-2)); // or CMPLX(-2, -0.0)  printf("cacos(-2-0i) (the other side of the cut) = %f%+fi\n", creal(z2), cimag(z2));  // for any z, acos(z) = pi - acos(-z)  double pi = acos(-1);  double complex z3 = ccos(pi-z2);  printf("ccos(pi - cacos(-2-0i) = %f%+fi\n", creal(z3), cimag(z3)); }
```

Output:

```c
cacos(-2+0i) = 3.141593-1.316958i cacos(-2-0i) (the other side of the cut) = 3.141593+1.316958i ccos(pi - cacos(-2-0i) = 2.000000+0.000000i
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.3.5.1 The cacos functions (p: 190)
7.3.5.1 cacos 函式 (p: 190)
7.3.5.1 cacos 函式 (p: 190)

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- G.6.1.1 The cacos functions (p: 539)
G.6.1.1 cacos 函式 (p: 539)
G.6.1.1 cacos 函式 (p: 539)

- G.7 Type-generic math <tgmath.h> (p: 545)
G.7 泛型數學 <tgmath.h>（頁：545）
G.7 泛型數學 <tgmath.h>（頁：545）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.3.5.1 The cacos functions (p: 172)
7.3.5.1 cacos 函式 (p: 172)
7.3.5.1 cacos 函式 (p: 172)

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- G.6.1.1 The cacos functions (p: 474)
G.6.1.1 cacos 函式 (p: 474)
G.6.1.1 cacos 函式 (p: 474)

- G.7 Type-generic math <tgmath.h> (p: 480)
G.7 泛型數學 <tgmath.h>（頁：480）
G.7 泛型數學 <tgmath.h>（頁：480）

### See also

casincasinfcasinl
(C99)(C99)(C99)
|   | computes the complex arc sine
(function)   |

catancatanfcatanl
(C99)(C99)(C99)
|   | computes the complex arc tangent
(function)   |

ccosccosfccosl
(C99)(C99)(C99)
|   | computes the complex cosine
(function)   |

acosacosfacosl
(C99)(C99)
|   | computes arc cosine (arccosxarccos⁡xarccos(x))
(function)   |

C++ documentation for acos

---
來源頁路徑：`en.cppreference.com/c/numeric/complex/cacos.html`

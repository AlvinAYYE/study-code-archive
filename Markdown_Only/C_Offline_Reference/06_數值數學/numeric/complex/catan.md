# catanf, catan, catanl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<complex.h>`
|   |  |   |  |

```c
float complex catanf( float complex z );
```
|   |  (1)  |   |  (since C99)  |

```c
double complex catan( double complex z );
```
|   |  (2)  |   |  (since C99)  |

```c
long double complex catanl( long double complex z );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define atan( z )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Computes the complex arc tangent of `z` with branch cuts outside the interval [−i,+i] along the imaginary axis.

4) Type-generic macro: If `z` has type `long double complex`, `catanl` is called. if `z` has type `double complex`, `catan` is called, if `z` has type `float complex`, `catanf` is called. If `z` is real or integer, then the macro invokes the corresponding real function (`atanf`, `atan`, `atanl`). If `z` is imaginary, then the macro invokes the corresponding real version of the function atanh, implementing the formula atan(iy) = i atanh(y), and the return type of the macro is imaginary.

### Parameters

| z  |   | -  |   | complex argument  |

### Return value

If no errors occur, complex arc tangent of `z` is returned, in the range of a strip unbounded along the imaginary axis and in the interval [−π/2; +π/2] along the real axis.
若沒有發生錯誤，回傳 z 的複數反正切。實部介於 [−π/2, +π/2]，虛部則沒有界限。
Errors and special cases are handled as if the operation is implemented by `-I * catanh(I*z)`.
錯誤與特殊情況的處理方式，等同於以 -I * catanh(I * z) 實作此運算。

### Notes

Inverse tangent (or arc tangent) is a multivalued function and requires a branch cut on the complex plane. The branch cut is conventionally placed at the line segments (-∞i,-i) and (+i,+∞i) of the imaginary axis.
反正切（arc tangent）是多值函式，因此在複平面上需要設定分支切割。通常將分支切割放在虛軸的 (-∞i, -i) 和 (+i, +∞i) 區間。
The mathematical definition of the principal value of inverse tangent is
反正切主值的數學定義如下：
atan z = -
1 |
2 |
i [ln(1 - iz) - ln (1 + iz]
### Example

Run this code

```c
#include <stdio.h> #include <float.h> #include <complex.h> int main(void) {  double complex z = catan(2*I);  printf("catan(+0+2i) = %f%+fi\n", creal(z), cimag(z));  double complex z2 = catan(-conj(2*I)); // or CMPLX(-0.0, 2)  printf("catan(-0+2i) (the other side of the cut) = %f%+fi\n", creal(z2), cimag(z2));  double complex z3 = 2*catan(2*I*DBL_MAX); // or CMPLX(0, INFINITY)  printf("2*catan(+0+i*Inf) = %f%+fi\n", creal(z3), cimag(z3)); }
```

Output:

```c
catan(+0+2i) = 1.570796+0.549306i catan(-0+2i) (the other side of the cut) = -1.570796+0.549306i 2*catan(+0+i*Inf) = 3.141593+0.000000i
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.3.5.3 The catan functions (p: 191)
7.3.5.3 catan 函式（頁：191）
7.3.5.3 catan 函式（頁：191）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- G.7 Type-generic math <tgmath.h> (p: 545)
G.7 泛型數學 <tgmath.h>（頁：545）
G.7 泛型數學 <tgmath.h>（頁：545）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.3.5.3 The catan functions (p: 173)
7.3.5.3 catan 函式（頁：173）
7.3.5.3 catan 函式（頁：173）

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- G.7 Type-generic math <tgmath.h> (p: 480)
G.7 泛型數學 <tgmath.h>（頁：480）
G.7 泛型數學 <tgmath.h>（頁：480）

### See also

casincasinfcasinl
(C99)(C99)(C99)
|   | computes the complex arc sine
(function)   |

cacoscacosfcacosl
(C99)(C99)(C99)
|   | computes the complex arc cosine
(function)   |

ctanctanfctanl
(C99)(C99)(C99)
|   | computes the complex tangent
(function)   |

atanatanfatanl
(C99)(C99)
|   | computes arc tangent (arctanxarctan⁡xarctan(x))
(function)   |

C++ documentation for atan

---
來源頁路徑：`en.cppreference.com/c/numeric/complex/catan.html`

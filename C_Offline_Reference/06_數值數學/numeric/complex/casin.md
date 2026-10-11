# casinf, casin, casinl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<complex.h>`
|   |  |   |  |

```c
float complex casinf( float complex z );
```
|   |  (1)  |   |  (since C99)  |

```c
double complex casin( double complex z );
```
|   |  (2)  |   |  (since C99)  |

```c
long double complex casinl( long double complex z );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define asin( z )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Computes the complex arc sine of `z` with branch cuts outside the interval [−1,+1] along the real axis.

4) Type-generic macro: If `z` has type `long double complex`, `casinl` is called. if `z` has type `double complex`, `casin` is called, if `z` has type `float complex`, `casinf` is called. If `z` is real or integer, then the macro invokes the corresponding real function (`asinf`, `asin`, `asinl`). If `z` is imaginary, then the macro invokes the corresponding real version of the function asinh, implementing the formula arcsin(iy)=iarsinh(y)arcsin⁡(iy)=iarsinh(y)arcsin(iy) = i arsinh(y), and the return type of the macro is imaginary.

### Parameters

| z  |   | -  |   | complex argument  |

### Return value

If no errors occur, complex arc sine of `z` is returned, in the range of a strip unbounded along the imaginary axis and in the interval [−π/2; +π/2] along the real axis.
若沒有發生錯誤，回傳 z 的複數反正弦。實部介於 [−π/2, +π/2]，虛部則沒有界限。
Errors and special cases are handled as if the operation is implemented by `-I * casinh(I*z)`
錯誤與特殊情況的處理方式，等同於以 -I * casinh(I * z) 實作此運算。

### Notes

Inverse sine (or arc sine) is a multivalued function and requires a branch cut on the complex plane. The branch cut is conventionally placed at the line segments (-∞,-1) and (1,∞) of the real axis.
反正弦（arc sine）是多值函式，因此在複平面上需要設定分支切割。通常將分支切割放在實軸的 (-∞, -1) 和 (1, ∞) 區間。
The mathematical definition of the principal value of arc sine is {{mathjax-or|1=arcsinz=−iln(iz+√1−z2)arcsin⁡z=−iln⁡(iz+1−z2)|2=arcsin z = -*i*ln(*i*z + √1-z2
)}}
反正弦主值的數學定義是 {{mathjax-or|1= arcsin z = − i ln ( i z + √ 1 − z 2 ) arcsin ⁡ z = − i ln ⁡ ( i z + 1 − z 2 ) |2=arcsin z = - i ln( i z + √ 1-z 2 )}}
For any z, arcsin(z)=arccos(−z)−π2arcsin⁡(z)=arccos⁡(−z)−π2
對任何 z，arcsin(z) = arccos(−z) − π/2。
arcsin(z) = acos(-z) -
π |
2 |

### Example

Run this code

```c
#include <stdio.h> #include <math.h> #include <complex.h> int main(void) {  double complex z = casin(-2);  printf("casin(-2+0i) = %f%+fi\n", creal(z), cimag(z));  double complex z2 = casin(conj(-2)); // or CMPLX(-2, -0.0)  printf("casin(-2-0i) (the other side of the cut) = %f%+fi\n", creal(z2), cimag(z2));  // for any z, asin(z) = acos(-z) - pi/2  double pi = acos(-1);  double complex z3 = csin(cacos(conj(-2))-pi/2);  printf("csin(cacos(-2-0i)-pi/2) = %f%+fi\n", creal(z3), cimag(z3)); }
```

Output:

```c
casin(-2+0i) = -1.570796+1.316958i casin(-2-0i) (the other side of the cut) = -1.570796-1.316958i csin(cacos(-2-0i)-pi/2) = 2.000000+0.000000i
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.3.5.2 The casin functions (p: 190)
7.3.5.2 casin 函式（頁：190）
7.3.5.2 casin 函式（頁：190）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- G.7 Type-generic math <tgmath.h> (p: 545)
G.7 泛型數學 <tgmath.h>（頁：545）
G.7 泛型數學 <tgmath.h>（頁：545）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.3.5.2 The casin functions (p: 172)
7.3.5.2 casin 函式（頁：172）
7.3.5.2 casin 函式（頁：172）

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- G.7 Type-generic math <tgmath.h> (p: 480)
G.7 泛型數學 <tgmath.h>（頁：480）
G.7 泛型數學 <tgmath.h>（頁：480）

### See also

cacoscacosfcacosl
(C99)(C99)(C99)
|   | computes the complex arc cosine
(function)   |

catancatanfcatanl
(C99)(C99)(C99)
|   | computes the complex arc tangent
(function)   |

csincsinfcsinl
(C99)(C99)(C99)
|   | computes the complex sine
(function)   |

asinasinfasinl
(C99)(C99)
|   | computes arc sine (arcsinxarcsin⁡xarcsin(x))
(function)   |

C++ documentation for asin

---
來源頁路徑：`en.cppreference.com/c/numeric/complex/casin.html`

# conjf, conj, conjl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<complex.h>`
|   |  |   |  |

```c
float complex conjf( float complex z );
```
|   |  (1)  |   |  (since C99)  |

```c
double complex conj( double complex z );
```
|   |  (2)  |   |  (since C99)  |

```c
long double complex conjl( long double complex z );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define conj( z )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Computes the complex conjugate of `z` by reversing the sign of the imaginary part.

4) Type-generic macro: if `z` has type `long double complex`, `long double imaginary`, or `long double`, `conjl` is called. If `z` has type `float complex`, `float imaginary`, or `float`, `conjf` is called. If `z` has type `double complex`, `double imaginary`, `double`, or any integer type, `conj` is called.

### Parameters

| z  |   | -  |   | complex argument  |

### Return value

The complex conjugate of `z`.
z 的複共軛。

### Notes

On C99 implementations that do not implement I as _Imaginary_I, `conj` may be used to obtain complex numbers with negative zero imaginary part. In C11, the macro CMPLX is used for that purpose.
在沒有將 I 實作為 _Imaginary_I 的 C99 實作中，可以使用 conj 取得虛部為負零的複數。C11 則提供巨集 CMPLX 來達成此目的。

### Example

Run this code

```c
#include <stdio.h> #include <complex.h> int main(void) {  double complex z = 1.0 + 2.0*I;  double complex z2 = conj(z);  printf("The conjugate of %.1f%+.1fi is %.1f%+.1fi\n",  creal(z), cimag(z), creal(z2), cimag(z2));  printf("Their product is %.1f%+.1fi\n", creal(z*z2), cimag(z*z2)); }
```

Output:

```c
The conjugate of 1.0+2.0i is 1.0-2.0i Their product is 5.0+0.0i
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.3.9.4 The conj functions (p: 198)
7.3.9.4 conj 函式 (p: 198)
7.3.9.4 conj 函式 (p: 198)

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- G.7 Type-generic math <tgmath.h> (p: 545)
G.7 泛型數學 <tgmath.h>（頁：545）
G.7 泛型數學 <tgmath.h>（頁：545）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.3.9.3 The conj functions (p: 179)
7.3.9.3 conj 函式 (p: 179)
7.3.9.3 conj 函式 (p: 179)

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- G.7 Type-generic math <tgmath.h> (p: 480)
G.7 泛型數學 <tgmath.h>（頁：480）
G.7 泛型數學 <tgmath.h>（頁：480）

### See also

C++ documentation for conj

---
來源頁路徑：`en.cppreference.com/c/numeric/complex/conj.html`

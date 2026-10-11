# cabsf, cabs, cabsl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<complex.h>`
|   |  |   |  |

```c
float cabsf( float complex z );
```
|   |  (1)  |   |  (since C99)  |

```c
double cabs( double complex z );
```
|   |  (2)  |   |  (since C99)  |

```c
long double cabsl( long double complex z );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define fabs( z )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Computes the complex absolute value (also known as norm, modulus, or magnitude) of `z`.

4) Type-generic macro: if `z` has type `long double complex` or `long double imaginary`, `cabsl` is called. If `z` has type `float complex` or `float imaginary`, `cabsf` is called. If `z` has type `double complex` or `double imaginary`, `cabs` is called. For real and integer types, the corresponding version of fabs is called.

### Parameters

| z  |   | -  |   | complex argument  |

### Return value

If no errors occur, returns the absolute value (norm, magnitude) of `z`.
若沒有發生錯誤，回傳 z 的絕對值（範數或大小）。
Errors and special cases are handled as if the function is implemented as `hypot(creal(z), cimag(z))`
錯誤與特殊情況的處理方式，等同於將函式實作為 hypot(creal(z), cimag(z))。

### Example

Run this code

```c
#include <stdio.h> #include <complex.h> int main(void) {  double complex z = 1.0 + 1.0*I;  printf("%.1f%+.1fi cartesian is rho=%f theta=%f polar\n",  creal(z), cimag(z), cabs(z), carg(z)); }
```

Output:

```c
1.0+1.0i cartesian is rho=1.414214 theta=0.785398 polar
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.3.8.1 The cabs functions (p: 195)
7.3.8.1 cabs 函式（頁：195）
7.3.8.1 cabs 函式（頁：195）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- G.7 Type-generic math <tgmath.h> (p: 545)
G.7 泛型數學 <tgmath.h>（頁：545）
G.7 泛型數學 <tgmath.h>（頁：545）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.3.8.1 The cabs functions (p: 177)
7.3.8.1 cabs 函式（頁：177）
7.3.8.1 cabs 函式（頁：177）

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- G.7 Type-generic math <tgmath.h> (p: 480)
G.7 泛型數學 <tgmath.h>（頁：480）
G.7 泛型數學 <tgmath.h>（頁：480）

### See also

cargcargfcargl
(C99)(C99)(C99)
|   | computes the phase angle of a complex number
(function)   |

abslabsllabs
(C99)
|   | computes absolute value of an integral value (|x||x||x|)
(function)   |

fabsfabsffabsl
(C99)(C99)
|   | computes absolute value of a floating-point value (|x||x||x|)
(function)   |

hypothypotfhypotl
(C99)(C99)(C99)
|   | computes square root of the sum of the squares of two given numbers (√x2+y2x2+y2√x2
+y2
)
(function)   |

C++ documentation for abs

---
來源頁路徑：`en.cppreference.com/c/numeric/complex/cabs.html`

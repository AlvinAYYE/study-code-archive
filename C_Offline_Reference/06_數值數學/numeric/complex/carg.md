# cargf, carg, cargl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<complex.h>`
|   |  |   |  |

```c
float cargf( float complex z );
```
|   |  (1)  |   |  (since C99)  |

```c
double carg( double complex z );
```
|   |  (2)  |   |  (since C99)  |

```c
long double cargl( long double complex z );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define carg( z )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Computes the argument (also called phase angle) of `z`, with a branch cut along the negative real axis.

4) Type-generic macro: if `z` has type `long double complex`, `long double imaginary`, or `long double`, `cargl` is called. If `z` has type `float complex`, `float imaginary`, or `float`, `cargf` is called. If `z` has type `double complex`, `double imaginary`, `double`, or any integer type, `carg` is called.

### Parameters

| z  |   | -  |   | complex argument  |

### Return value

If no errors occur, returns the phase angle of `z` in the interval [−π; π].
若沒有發生錯誤，回傳 z 的相位角，範圍為 [−π, π]。
Errors and special cases are handled as if the function is implemented as `atan2(cimag(z), creal(z))`
錯誤與特殊情況的處理方式，等同於將函式實作為 atan2(cimag(z), creal(z))。

### Example

Run this code

```c
#include <stdio.h> #include <complex.h> int main(void)  {  double complex z1 = 1.0+0.0*I;  printf("phase angle of %.1f%+.1fi is %f\n", creal(z1), cimag(z1), carg(z1));  double complex z2 = 0.0+1.0*I;  printf("phase angle of %.1f%+.1fi is %f\n", creal(z2), cimag(z2), carg(z2));  double complex z3 = -1.0+0.0*I;  printf("phase angle of %.1f%+.1fi is %f\n", creal(z3), cimag(z3), carg(z3));  double complex z4 = conj(z3); // or CMPLX(-1, -0.0)  printf("phase angle of %.1f%+.1fi (the other side of the cut) is %f\n",  creal(z4), cimag(z4), carg(z4)); }
```

Output:

```c
phase angle of 1.0+0.0i is 0.000000 phase angle of 0.0+1.0i is 1.570796 phase angle of -1.0+0.0i is 3.141593 phase angle of -1.0-0.0i (the other side of the cut) is -3.141593
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.3.9.1 The carg functions (p: 196)
7.3.9.1 carg 函式 (p: 196)
7.3.9.1 carg 函式 (p: 196)

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- G.7 Type-generic math <tgmath.h> (p: 545)
G.7 泛型數學 <tgmath.h>（頁：545）
G.7 泛型數學 <tgmath.h>（頁：545）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.3.9.1 The carg functions (p: 178)
7.3.9.1 carg 函式 (p: 178)
7.3.9.1 carg 函式 (p: 178)

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- G.7 Type-generic math <tgmath.h> (p: 480)
G.7 泛型數學 <tgmath.h>（頁：480）
G.7 泛型數學 <tgmath.h>（頁：480）

### See also

cabscabsfcabsl
(C99)(C99)(C99)
|   | computes the magnitude of a complex number
(function)   |

atan2atan2fatan2l
(C99)(C99)
|   | computes arc tangent, using signs to determine quadrants
(function)   |

C++ documentation for arg

---
來源頁路徑：`en.cppreference.com/c/numeric/complex/carg.html`

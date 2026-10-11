# cpowf, cpow, cpowl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<complex.h>`
|   |  |   |  |

```c
float complex cpowf( float complex x, float complex y );
```
|   |  (1)  |   |  (since C99)  |

```c
double complex cpow( double complex x, double complex y );
```
|   |  (2)  |   |  (since C99)  |

```c
long double complex cpowl( long double complex x, long double complex y );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define pow( x, y )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Computes the complex power function xy
, with branch cut for the first parameter along the negative real axis.
4) Type-generic macro: If any argument has type `long double complex`, `cpowl` is called. if any argument has type `double complex`, `cpow` is called, if any argument has type `float complex`, `cpowf` is called. If the arguments are real or integer, then the macro invokes the corresponding real function (`powf`, `pow`, `powl`). If any argument is imaginary, the corresponding complex number version is called.

### Parameters

| x, y  |   | -  |   | complex argument  |

### Return value

If no errors occur, the complex power xy
, is returned.
若沒有發生錯誤，回傳複數次方 x^y。
Errors and special cases are handled as if the operation is implemented by `cexp(y*clog(x))`, except that the implementation is allowed to treat special cases more carefully.
錯誤與特殊情況的處理方式，等同於以 cexp(y * clog(x)) 實作此運算；但實作可以更謹慎地處理特殊情況。

### Example

Run this code

```c
#include <stdio.h> #include <complex.h> int main(void) {   double complex z = cpow(1.0+2.0*I, 2);  printf("(1+2i)^2 = %.1f%+.1fi\n", creal(z), cimag(z));    double complex z2 = cpow(-1, 0.5);  printf("(-1+0i)^0.5 = %.1f%+.1fi\n", creal(z2), cimag(z2));  double complex z3 = cpow(conj(-1), 0.5); // other side of the cut  printf("(-1-0i)^0.5 = %.1f%+.1fi\n", creal(z3), cimag(z3));  double complex z4 = cpow(I, I); // i^i = exp(-pi/2)  printf("i^i = %f%+fi\n", creal(z4), cimag(z4)); }
```

Output:

```c
(1+2i)^2 = -3.0+4.0i (-1+0i)^0.5 = 0.0+1.0i (-1-0i)^0.5 = 0.0-1.0i i^i = 0.207880+0.000000i
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.3.8.2 The cpow functions (p: 195-196)
7.3.8.2 cpow 函式 (p: 195-196)
7.3.8.2 cpow 函式 (p: 195-196)

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- G.6.4.1 The cpow functions (p: 544)
G.6.4.1 cpow 函式 (p: 544)
G.6.4.1 cpow 函式 (p: 544)

- G.7 Type-generic math <tgmath.h> (p: 545)
G.7 泛型數學 <tgmath.h>（頁：545）
G.7 泛型數學 <tgmath.h>（頁：545）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.3.8.2 The cpow functions (p: 177)
7.3.8.2 cpow 函式 (p: 177)
7.3.8.2 cpow 函式 (p: 177)

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- G.6.4.1 The cpow functions (p: 479)
G.6.4.1 cpow 函式 (p: 479)
G.6.4.1 cpow 函式 (p: 479)

- G.7 Type-generic math <tgmath.h> (p: 480)
G.7 泛型數學 <tgmath.h>（頁：480）
G.7 泛型數學 <tgmath.h>（頁：480）

### See also

csqrtcsqrtfcsqrtl
(C99)(C99)(C99)
|   | computes the complex square root
(function)   |

powpowfpowl
(C99)(C99)
|   | computes a number raised to the given power (xyxyx)
(function)   |

C++ documentation for pow

---
來源頁路徑：`en.cppreference.com/c/numeric/complex/cpow.html`

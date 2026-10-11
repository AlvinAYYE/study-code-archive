# ccosf, ccos, ccosl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<complex.h>`
|   |  |   |  |

```c
float complex ccosf( float complex z );
```
|   |  (1)  |   |  (since C99)  |

```c
double complex ccos( double complex z );
```
|   |  (2)  |   |  (since C99)  |

```c
long double complex ccosl( long double complex z );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define cos( z )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Computes the complex cosine of `z`.

4) Type-generic macro: If `z` has type `long double complex`, `ccosl` is called. if `z` has type `double complex`, `ccos` is called, if `z` has type `float complex`, `ccosf` is called. If `z` is real or integer, then the macro invokes the corresponding real function (`cosf`, `cos`, `cosl`). If `z` is imaginary, then the macro invokes the corresponding real version of the function cosh, implementing the formula cos(iy) = cosh(y), and the return type is real.

### Parameters

| z  |   | -  |   | complex argument  |

### Return value

If no errors occur, the complex cosine of `z` is returned.
若沒有發生錯誤，回傳 z 的複數餘弦。
Errors and special cases are handled as if the operation is implemented by `ccosh(I*z)`.
錯誤與特殊情況的處理方式，等同於以 ccosh(I * z) 實作此運算。

### Notes

The cosine is an entire function on the complex plane, and has no branch cuts.
餘弦函式在複平面上是整函式，沒有分支切割。
Mathematical definition of the cosine is
餘弦的數學定義為
cos z =
eiz
+e-iz

2 |

### Example

Run this code

```c
#include <stdio.h> #include <math.h> #include <complex.h> int main(void) {  double complex z = ccos(1); // behaves like real cosine along the real line  printf("cos(1+0i) = %f%+fi ( cos(1)=%f)\n", creal(z), cimag(z), cos(1));  double complex z2 = ccos(I); // behaves like real cosh along the imaginary line  printf("cos(0+1i) = %f%+fi (cosh(1)=%f)\n", creal(z2), cimag(z2), cosh(1)); }
```

Output:

```c
cos(1+0i) = 0.540302-0.000000i ( cos(1)=0.540302) cos(0+1i) = 1.543081-0.000000i (cosh(1)=1.543081)
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.3.5.4 The ccos functions (p: 191)
7.3.5.4 ccos 函式 (p: 191)
7.3.5.4 ccos 函式 (p: 191)

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- G.7 Type-generic math <tgmath.h> (p: 545)
G.7 泛型數學 <tgmath.h>（頁：545）
G.7 泛型數學 <tgmath.h>（頁：545）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.3.5.4 The ccos functions (p: 173)
7.3.5.4 ccos 函式 (p: 173)
7.3.5.4 ccos 函式 (p: 173)

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- G.7 Type-generic math <tgmath.h> (p: 480)
G.7 泛型數學 <tgmath.h>（頁：480）
G.7 泛型數學 <tgmath.h>（頁：480）

### See also

csincsinfcsinl
(C99)(C99)(C99)
|   | computes the complex sine
(function)   |

ctanctanfctanl
(C99)(C99)(C99)
|   | computes the complex tangent
(function)   |

cacoscacosfcacosl
(C99)(C99)(C99)
|   | computes the complex arc cosine
(function)   |

coscosfcosl
(C99)(C99)
|   | computes cosine (cosxcos⁡xcos(x))
(function)   |

C++ documentation for cos

---
來源頁路徑：`en.cppreference.com/c/numeric/complex/ccos.html`

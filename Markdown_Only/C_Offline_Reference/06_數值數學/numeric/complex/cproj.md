# cprojf, cproj, cprojl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<complex.h>`
|   |  |   |  |

```c
float complex cprojf( float complex z );
```
|   |  (1)  |   |  (since C99)  |

```c
double complex cproj( double complex z );
```
|   |  (2)  |   |  (since C99)  |

```c
long double complex cprojl( long double complex z );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define cproj( z )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Computes the projection of `z` on the Riemann sphere.

4) Type-generic macro: if `z` has type `long double complex`, `long double imaginary`, or `long double`, `cprojl` is called. If `z` has type `float complex`, `float imaginary`, or `float`, `cprojf` is called. If `z` has type `double complex`, `double imaginary`, `double`, or any integer type, `cproj` is called.

For most `z`, `cproj(z)==z`, but all complex infinities, even the numbers where one component is infinite and the other is NaN, become positive real infinity, `INFINITY+0.0*I` or `INFINITY-0.0*I`. The sign of the imaginary (zero) component is the sign of `cimag(z)`.
大多數情況下，cproj(z) == z。不過，任何分量為無窮大的複數（包括另一個分量為 NaN 的情況）都會映射為正實無窮大：INFINITY + 0.0 * I 或 INFINITY - 0.0 * I。虛部零的正負號與 cimag(z) 相同。

### Parameters

| z  |   | -  |   | complex argument  |

### Return value

The projection of `z` on the Riemann sphere.
z 在黎曼球面上的投影。
This function is fully specified for all possible inputs and is not subject to any errors described in math_errhandling
此函式對所有可能的輸入都有明確定義，不受 math_errhandling 所述錯誤狀況影響。

### Notes

The `cproj` function helps model the Riemann sphere by mapping all infinities to one (give or take the sign of the imaginary zero), and should be used just before any operation, especially comparisons, that might give spurious results for any of the other infinities.
cproj 會將所有無窮大的複數映射至同一個值（虛部零的正負號可能不同），方便以黎曼球面建模。若後續運算可能無法正確處理其他無窮大值，尤其是比較運算，應先呼叫 cproj。

### Example

Run this code

```c
#include <stdio.h> #include <complex.h> #include <math.h> int main(void) {  double complex z1 = cproj(1 + 2*I);  printf("cproj(1+2i) = %.1f%+.1fi\n", creal(z1),cimag(z1));  double complex z2 = cproj(INFINITY+2.0*I);  printf("cproj(Inf+2i) = %.1f%+.1fi\n", creal(z2),cimag(z2));  double complex z3 = cproj(INFINITY-2.0*I);  printf("cproj(Inf-2i) = %.1f%+.1fi\n", creal(z3),cimag(z3)); }
```

Output:

```c
cproj(1+2i) = 1.0+2.0i cproj(Inf+2i) = inf+0.0i cproj(Inf-2i) = inf-0.0i
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.3.9.5 The cproj functions (p: 198)
7.3.9.5 cproj 函式 (p: 198)
7.3.9.5 cproj 函式 (p: 198)

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- G.7 Type-generic math <tgmath.h> (p: 545)
G.7 泛型數學 <tgmath.h>（頁：545）
G.7 泛型數學 <tgmath.h>（頁：545）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.3.9.4 The cproj functions (p: 179)
7.3.9.4 cproj 函式 (p: 179)
7.3.9.4 cproj 函式 (p: 179)

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- G.7 Type-generic math <tgmath.h> (p: 480)
G.7 泛型數學 <tgmath.h>（頁：480）
G.7 泛型數學 <tgmath.h>（頁：480）

### See also

C++ documentation for proj

---
來源頁路徑：`en.cppreference.com/c/numeric/complex/cproj.html`

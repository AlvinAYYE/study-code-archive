# Complex number arithmetic

> 來源：cppreference C 語言參考文件（離線轉換版）。

If the macro constant `__STDC_NO_COMPLEX__` is defined by the implementation, the complex types, the header <complex.h> and all of the names listed here are not provided.
|   | (since C11) |

The C programming language, as of C99, supports complex number math with the three built-in types `double _Complex`, `float _Complex`, and `long double _Complex` (see _Complex). When the header <complex.h> is included, the three complex number types are also accessible as `double complex`, `float complex`, `long double complex`.
C 從 C99 起支援複數運算，並內建三種型別：double _Complex、float _Complex 和 long double _Complex（參見 _Complex）。包含標頭檔 <complex.h> 後，也可以分別寫成 double complex、float complex 和 long double complex。
In addition to the complex types, the three imaginary types may be supported: `double _Imaginary`, `float _Imaginary`, and `long double _Imaginary` (see _Imaginary). When the header <complex.h> is included, the three imaginary types are also accessible as `double imaginary`, `float imaginary`, and `long double imaginary`.
除了複數型別外，實作也可能支援三種虛數型別：double _Imaginary、float _Imaginary 和 long double _Imaginary（參見 _Imaginary）。包含標頭檔 <complex.h> 後，也可以分別寫成 double imaginary、float imaginary 和 long double imaginary。
Standard arithmetic operators `+`, `-`, `*`, `/` can be used with real, complex, and imaginary types in any combination.
標準算術運運算元 +、-、*、/ 可用於實數、複數和虛數型別，也可以混合使用。

A compiler that defines `__STDC_IEC_559_COMPLEX__` is recommended, but not required to support imaginary numbers. POSIX recommends checking if the macro _Imaginary_I is defined to identify imaginary number support.
|   | (since C99)
(until C11) |

Imaginary numbers are supported if `__STDC_IEC_559_COMPLEX__` or `__STDC_IEC_60559_COMPLEX__`(since C23) is defined.
|   | (since C11) |

|    |

Defined in header `<complex.h>`

#####  Types

imaginary
(C99)
|   | imaginary type macro
(keyword macro)   |

complex
(C99)
|   | complex type macro
(keyword macro)   |

#####  The imaginary constant

_Imaginary_I
(C99)
|   | the imaginary unit constant i
(macro constant)   |

_Complex_I
(C99)
|   | the complex unit constant i
(macro constant)   |

I
(C99)
|   | the complex or imaginary unit constant i
(macro constant)   |

#####  Manipulation

CMPLXCMPLXFCMPLXL
(C11)(C11)(C11)
|   | constructs a complex number from real and imaginary parts
(function macro)   |

crealcrealfcreall
(C99)(C99)(C99)
|   | computes the real part of a complex number
(function)   |

cimagcimagfcimagl
(C99)(C99)(C99)
|   | computes the imaginary part a complex number
(function)   |

cabscabsfcabsl
(C99)(C99)(C99)
|   | computes the magnitude of a complex number
(function)   |

cargcargfcargl
(C99)(C99)(C99)
|   | computes the phase angle of a complex number
(function)   |

conjconjfconjl
(C99)(C99)(C99)
|   | computes the complex conjugate
(function)   |

cprojcprojfcprojl
(C99)(C99)(C99)
|   | computes the projection on Riemann sphere
(function)   |

#####  Exponential functions

cexpcexpfcexpl
(C99)(C99)(C99)
|   | computes the complex base-e exponential
(function)   |

clogclogfclogl
(C99)(C99)(C99)
|   | computes the complex natural logarithm
(function)   |

#####  Power functions

cpowcpowfcpowl
(C99)(C99)(C99)
|   | computes the complex power function
(function)   |

csqrtcsqrtfcsqrtl
(C99)(C99)(C99)
|   | computes the complex square root
(function)   |

#####  Trigonometric functions

csincsinfcsinl
(C99)(C99)(C99)
|   | computes the complex sine
(function)   |

ccosccosfccosl
(C99)(C99)(C99)
|   | computes the complex cosine
(function)   |

ctanctanfctanl
(C99)(C99)(C99)
|   | computes the complex tangent
(function)   |

casincasinfcasinl
(C99)(C99)(C99)
|   | computes the complex arc sine
(function)   |

cacoscacosfcacosl
(C99)(C99)(C99)
|   | computes the complex arc cosine
(function)   |

catancatanfcatanl
(C99)(C99)(C99)
|   | computes the complex arc tangent
(function)   |

#####  Hyperbolic functions

csinhcsinhfcsinhl
(C99)(C99)(C99)
|   | computes the complex hyperbolic sine
(function)   |

ccoshccoshfccoshl
(C99)(C99)(C99)
|   | computes the complex hyperbolic cosine
(function)   |

ctanhctanhfctanhl
(C99)(C99)(C99)
|   | computes the complex hyperbolic tangent
(function)   |

casinhcasinhfcasinhl
(C99)(C99)(C99)
|   | computes the complex arc hyperbolic sine
(function)   |

cacoshcacoshfcacoshl
(C99)(C99)(C99)
|   | computes the complex arc hyperbolic cosine
(function)   |

catanhcatanhfcatanhl
(C99)(C99)(C99)
|   | computes the complex arc hyperbolic tangent
(function)   |

### Notes

The following function names are potentially(since C23) reserved for future addition to <complex.h> and are not available for use in the programs that include that header: cerf, cerfc, cexp2, cexpm1, clog10, clog1p, clog2, clgamma, ctgamma, csinpi, ccospi, ctanpi, casinpi, cacospi, catanpi, ccompoundn, cpown, cpowr, crootn, crsqrt, cexp10m1, cexp10, cexp2m1, clog10p1, clog2p1, clogp1(since C23), along with their -`f` and -`l` suffixed variants.
自 C23 起，下列函式名稱可能保留供未來加入 <complex.h> 使用；包含此標頭檔的程式不得使用這些名稱：cerf、cerfc、cexp2、cexpm1、clog10、clog1p、clog2、clgamma、ctgamma、csinpi、ccospi、ctanpi、casinpi、cacospi、catanpi、ccompoundn、cpown、cpowr、crootn、crsqrt、cexp10m1、cexp10、cexp2m1、clog10p1、clog2p1、clogp1，以及它們帶有 -f 或 -l 字尾的版本。
Although the C standard names the inverse hyperbolic with "complex arc hyperbolic sine" etc., the inverse functions of the hyperbolic functions are the area functions. Their argument is the area of a hyperbolic sector, not an arc. The correct names are "complex inverse hyperbolic sine" etc. Some authors use "complex area hyperbolic sine" etc.
C 標準雖以「complex arc hyperbolic sine」等名稱稱呼反雙曲函式，但雙曲函式的反函式其實是面積函式。它們的參數代表雙曲扇形的面積，而不是弧長，因此正確名稱應是「complex inverse hyperbolic sine」等。有些作者則稱為「complex area hyperbolic sine」等。
A complex or imaginary number is infinite if one of its parts is infinite, even if the other part is NaN.
複數或虛數只要有一個分量是無窮大，整個數就是無窮大，即使另一個分量是 NaN 也一樣。
A complex or imaginary number is finite if both parts are neither infinities nor NaNs.
複數或虛數的兩個分量都不是無窮大或 NaN 時，整個數就是有限值。
A complex or imaginary number is a zero if both parts are positive or negative zeroes.
複數或虛數的兩個分量都是正零或負零時，整個數就是零。
While MSVC does provide a `<complex.h>` header, it does not implement complex numbers as native types, but as `struct`s, which are incompatible with standard C complex types and do not support the `+`, `-`, `*`, `/` operators.
MSVC 雖然提供 <complex.h> 標頭檔，但複數是以 struct 實作，並非原生型別；這種型別與標準 C 複數型別不相容，也不支援 +、-、*、/ 運運算元。

### Example

Run this code

```c
#include <complex.h> #include <stdio.h> #include <tgmath.h> int main(void) {  double complex z1 = I * I; // imaginary unit squared  printf("I * I = %.1f%+.1fi\n", creal(z1), cimag(z1));  double complex z2 = pow(I, 2); // imaginary unit squared  printf("pow(I, 2) = %.1f%+.1fi\n", creal(z2), cimag(z2));  double PI = acos(-1);  double complex z3 = exp(I * PI); // Euler's formula  printf("exp(I*PI) = %.1f%+.1fi\n", creal(z3), cimag(z3));  double complex z4 = 1 + 2 * I, z5 = 1 - 2 * I; // conjugates  printf("(1+2i)*(1-2i) = %.1f%+.1fi\n", creal(z4 * z5), cimag(z4 * z5)); }
```

Output:

```c
I * I = -1.0+0.0i pow(I, 2) = -1.0+0.0i exp(I*PI) = -1.0+0.0i (1+2i)*(1-2i) = 5.0+0.0i
```

### References

| Extended content  |

- C23 standard (ISO/IEC 9899:2024):

- 6.10.8.3/1/2 `__STDC_NO_COMPLEX__` (p: TBD)

- 6.10.8.3/1/2 `__STDC_IEC_559_COMPLEX__` (p: TBD)

- 7.3 Complex arithmetic `<complex.h>` (p: TBD)

- 7.25 Type-generic math `<tgmath.h>` (p: TBD)

- 7.31.1 Complex arithmetic `<complex.h>` (p: TBD)

- Annex G (normative) IEC 60559-compatible complex arithmetic (p: TBD)

- C17 standard (ISO/IEC 9899:2018):

- 6.10.8.3/1/2 `__STDC_NO_COMPLEX__` (p: 128)

- 6.10.8.3/1/2 `__STDC_IEC_559_COMPLEX__` (p: 128)

- 7.3 Complex arithmetic `<complex.h>` (p: 136-144)

- 7.25 Type-generic math `<tgmath.h>` (p: 272-273)

- 7.31.1 Complex arithmetic `<complex.h>` (p: 391)

- Annex G (normative) IEC 60559-compatible complex arithmetic (p: 469-479)

- C11 standard (ISO/IEC 9899:2011):

- 6.10.8.3/1/2 `__STDC_NO_COMPLEX__` (p: 177)

- 6.10.8.3/1/2 `__STDC_IEC_559_COMPLEX__` (p: 177)

- 7.3 Complex arithmetic `<complex.h>` (p: 188-199)

- 7.25 Type-generic math `<tgmath.h>` (p: 373-375)

- 7.31.1 Complex arithmetic `<complex.h>` (p: 455)

- Annex G (normative) IEC 60559-compatible complex arithmetic (p: 532-545)

- C99 standard (ISO/IEC 9899:1999):

- 6.10.8/2 `__STDC_IEC_559_COMPLEX__` (p: 161)

- 7.3 Complex arithmetic `<complex.h>` (p: 170-180)

- 7.22 Type-generic math `<tgmath.h>` (p: 335-337)

- 7.26.1 Complex arithmetic `<complex.h>` (p: 401)

- Annex G (informative) IEC 60559-compatible complex arithmetic (p: 467-480)

### See also

C++ documentation for Complex number arithmetic

---
來源頁路徑：`en.cppreference.com/c/numeric/complex.html`

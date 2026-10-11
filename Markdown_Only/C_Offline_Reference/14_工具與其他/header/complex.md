# Standard library header <complex.h> (C99)

> 來源：cppreference C 語言參考文件（離線轉換版）。

This header is part of the complex number arithmetic library.
該標頭檔是複數算術庫的一部分。

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

### Synopsis

```c
#define __STDC_VERSION_COMPLEX_H__ 202311L #define complex _Complex #define imaginary /* implementation-defined */ #define _Imaginary_I /* implementation-defined */ #define _Complex_I /* implementation-defined */ #define I _Complex_I #pragma STDC CX_LIMITED_RANGE /*on-off-switch*/ double complex cacos(double complex z); float complex cacosf(float complex z); long double complex cacosl(long double complex z); double complex casin(double complex z); float complex casinf(float complex z); long double complex casinl(long double complex z); double complex catan(double complex z); float complex catanf(float complex z); long double complex catanl(long double complex z); double complex ccos(double complex z); float complex ccosf(float complex z); long double complex ccosl(long double complex z); double complex csin(double complex z); float complex csinf(float complex z); long double complex csinl(long double complex z); double complex ctan(double complex z); float complex ctanf(float complex z); long double complex ctanl(long double complex z); double complex cacosh(double complex z); float complex cacoshf(float complex z); long double complex cacoshl(long double complex z); double complex casinh(double complex z); float complex casinhf(float complex z); long double complex casinhl(long double complex z); double complex catanh(double complex z); float complex catanhf(float complex z); long double complex catanhl(long double complex z); double complex ccosh(double complex z); float complex ccoshf(float complex z); long double complex ccoshl(long double complex z); double complex csinh(double complex z); float complex csinhf(float complex z); long double complex csinhl(long double complex z); double complex ctanh(double complex z); float complex ctanhf(float complex z); long double complex ctanhl(long double complex z); double complex cexp(double complex z); float complex cexpf(float complex z); long double complex cexpl(long double complex z); double complex clog(double complex z); float complex clogf(float complex z); long double complex clogl(long double complex z); double cabs(double complex z); float cabsf(float complex z); long double cabsl(long double complex z); double complex cpow(double complex x, double complex y); float complex cpowf(float complex x, float complex y); long double complex cpowl(long double complex x, long double complex y); double complex csqrt(double complex z); float complex csqrtf(float complex z); long double complex csqrtl(long double complex z); double carg(double complex z); float cargf(float complex z); long double cargl(long double complex z); double cimag(double complex z); float cimagf(float complex z); long double cimagl(long double complex z); double complex CMPLX(double x, double y); float complex CMPLXF(float x, float y); long double complex CMPLXL(long double x, long double y); double complex conj(double complex z); float complex conjf(float complex z); long double complex conjl(long double complex z); double complex cproj(double complex z); float complex cprojf(float complex z); long double complex cprojl(long double complex z); double creal(double complex z); float crealf(float complex z); long double creall(long double complex z); // Only if the implementation defines __STDC_IEC_60559_TYPES__ and additionally the user // code defines __STDC_WANT_IEC_60559_TYPES_EXT__ before any inclusion of <complex.h>: #ifdef __STDC_WANT_IEC_60559_TYPES_EXT__ /*_FloatN*/ complex /*cacosfN*/(/*_FloatN*/ complex z); /*_FloatNx*/ complex /*cacosfNx*/(/*_FloatNx*/ complex z); /*_FloatN*/ complex /*casinfN*/(/*_FloatN*/ complex z); /*_FloatNx*/ complex /*casinfNx*/(/*_FloatNx*/ complex z); /*_FloatN*/ complex /*catanfN*/(/*_FloatN*/ complex z); /*_FloatNx*/ complex /*catanfNx*/(/*_FloatNx*/ complex z); /*_FloatN*/ complex /*ccosfN*/(/*_FloatN*/ complex z); /*_FloatNx*/ complex /*ccosfNx*/(/*_FloatNx*/ complex z); /*_FloatN*/ complex /*csinfN*/(/*_FloatN*/ complex z); /*_FloatNx*/ complex /*csinfNx*/(/*_FloatNx*/ complex z); /*_FloatN*/ complex /*ctanfN*/(/*_FloatN*/ complex z); /*_FloatNx*/ complex /*ctanfNx*/(/*_FloatNx*/ complex z); /*_FloatN*/ complex /*cacoshfN*/(/*_FloatN*/ complex z); /*_FloatNx*/ complex /*cacoshfNx*/( /*_FloatNx*/ complex z); /*_FloatN*/ complex /*casinhfN*/(/*_FloatN*/ complex z); /*_FloatNx*/ complex /*casinhfNx*/( /*_FloatNx*/ complex z); /*_FloatN*/ complex /*catanhfN*/(/*_FloatN*/ complex z); /*_FloatNx*/ complex /*catanhfNx*/( /*_FloatNx*/ complex z); /*_FloatN*/ complex /*ccoshfN*/(/*_FloatN*/ complex z); /*_FloatNx*/ complex /*ccoshfNx*/(/*_FloatNx*/ complex z); /*_FloatN*/ complex /*csinhfN*/(/*_FloatN*/ complex z); /*_FloatNx*/ complex /*csinhfNx*/(/*_FloatNx*/ complex z); /*_FloatN*/ complex /*ctanhfN*/(/*_FloatN*/ complex z); /*_FloatNx*/ complex /*ctanhfNx*/(/*_FloatNx*/ complex z); /*_FloatN*/ complex /*cexpfN*/(/*_FloatN*/ complex z); /*_FloatNx*/ complex /*cexpfNx*/(/*_FloatNx*/ complex z); /*_FloatN*/ complex /*clogfN*/(/*_FloatN*/ complex z); /*_FloatNx*/ complex /*clogfNx*/(/*_FloatNx*/ complex z); /*_FloatN*/ /*cabsfN*/(/*_FloatN*/ complex z); /*_FloatNx*/ /*cabsfNx*/(/*_FloatNx*/ complex z); /*_FloatN*/ complex /*cpowfN*/(/*_FloatN*/ complex x, /*_FloatN*/ complex y); /*_FloatNx*/ complex /*cpowfNx*/(/*_FloatNx*/ complex x, /*_FloatNx*/ complex y); /*_FloatN*/ complex /*csqrtfN*/(/*_FloatN*/ complex z); /*_FloatNx*/ complex /*csqrtfNx*/(/*_FloatNx*/ complex z); /*_FloatN*/ /*cargfN*/(/*_FloatN*/ complex z); /*_FloatNx*/ /*cargfNx*/(/*_FloatNx*/ complex z); /*_FloatN*/ /*cimagfN*/(/*_FloatN*/ complex z); /*_FloatNx*/ /*cimagfNx*/(/*_FloatNx*/ complex z); /*_FloatN*/ complex /*CMPLXFN*/(/*_FloatN*/ x, /*_FloatN*/ y); /*_FloatNx*/ complex /*CMPLXFNX*/(/*_FloatNx*/ x, /*_FloatNx*/ y); /*_FloatN*/ complex /*conjfN*/(/*_FloatN*/ complex z); /*_FloatNx*/ complex /*conjfNx*/(/*_FloatNx*/ complex z); /*_FloatN*/ complex /*cprojfN*/(/*_FloatN*/ complex z); /*_FloatNx*/ complex /*cprojfNx*/(/*_FloatNx*/ complex z); /*_FloatN*/ /*crealfN*/(/*_FloatN*/ complex z); /*_FloatNx*/ /*crealfNx*/(/*_FloatNx*/ complex z); #endif
```

---
來源頁路徑：`en.cppreference.com/c/header/complex.html`

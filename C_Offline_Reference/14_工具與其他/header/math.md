# Standard library header <math.h>

> 來源：cppreference C 語言參考文件（離線轉換版）。

This header is part of the mathematics library.
該標頭檔是數學庫的一部分。

|  | This section is incomplete
Reason: recheck add more from B.11 Mathematics <math.h>  |

### Types

float_t
(C99)
|   | most efficient floating-point type at least as wide as `float`
(typedef)   |

double_t
(C99)
|   | most efficient floating-point type at least as wide as `double`
(typedef)   |

### Constants

HUGE_VALFHUGE_VALHUGE_VALL
(C99)(C99)
|   | indicates value too big to be representable (infinity) by `float`, `double` and `long double` respectively
(macro constant)   |

INFINITY
(C99)
|   | evaluates to positive infinity (if exists)
(macro constant)   |

NAN
(C99)
|   | evaluates to a quiet NaN of type `float` (if exists)
(macro constant)   |

FP_FAST_FMAFFP_FAST_FMAFP_FAST_FMAL
(C99)(C99)(C99)
|   | indicates that the fma function generally executes about as fast as, or faster than, a multiply and an add of double operands
(macro constant)   |

FP_ILOGB0FP_ILOGBNAN
(C99)(C99)
|   | evaluates to `ilogb(x)` if x is zero or NaN, respectively
(macro constant)   |

math_errhandlingMATH_ERRNOMATH_ERREXCEPT
(C99)(C99)(C99)
|   | defines the error handling mechanism used by the common mathematical functions
(macro constant)   |

#####  Classification

FP_NORMALFP_SUBNORMALFP_ZEROFP_INFINITEFP_NAN
(C99)(C99)(C99)(C99)(C99)
|   | indicates a floating-point category
(macro constant)   |

### Functions

#####  Basic operations

fabsfabsffabsl
(C99)(C99)
|   | computes absolute value of a floating-point value (|x||x||x|)
(function)   |

fmodfmodffmodl
(C99)(C99)
|   | computes remainder of the floating-point division operation
(function)   |

remainderremainderfremainderl
(C99)(C99)(C99)
|   | computes signed remainder of the floating-point division operation
(function)   |

remquoremquofremquol
(C99)(C99)(C99)
|   | computes signed remainder as well as the three last bits of the division operation
(function)   |

fmafmaffmal
(C99)(C99)(C99)
|   | computes fused multiply-add operation
(function)   |

fmaxfmaxffmaxl
(C99)(C99)(C99)
|   | determines larger of two floating-point values
(function)   |

fminfminffminl
(C99)(C99)(C99)
|   | determines smaller of two floating-point values
(function)   |

fdimfdimffdiml
(C99)(C99)(C99)
|   | determines positive difference of two floating-point values (max(0,x−y)max(0,x−y)max(0, x-y))
(function)   |

nannanfnanl
(C99)(C99)(C99)
|   | returns a NaN (not-a-number)
(function)   |

#####  Exponential functions

expexpfexpl
(C99)(C99)
|   | computes *e* raised to the given power (exexe)
(function)   |

exp2exp2fexp2l
(C99)(C99)(C99)
|   | computes *2* raised to the given power (2x2x2)
(function)   |

expm1expm1fexpm1l
(C99)(C99)(C99)
|   | computes *e* raised to the given power, minus one (ex−1ex−1e-1)
(function)   |

loglogflogl
(C99)(C99)
|   | computes natural (base-*e*) logarithm (lnxln⁡xln(x))
(function)   |

log10log10flog10l
(C99)(C99)
|   | computes common (base-*10*) logarithm (log10xlog10⁡xlog10(x))
(function)   |

log2log2flog2l
(C99)(C99)(C99)
|   | computes base-2 logarithm (log2xlog2⁡xlog2(x))
(function)   |

log1plog1pflog1pl
(C99)(C99)(C99)
|   | computes natural (base-*e*) logarithm of 1 plus the given number (ln(1+x)ln⁡(1+x)ln(1+x))
(function)   |

#####  Power functions

powpowfpowl
(C99)(C99)
|   | computes a number raised to the given power (xyxyx)
(function)   |

sqrtsqrtfsqrtl
(C99)(C99)
|   | computes square root (√xx√x)
(function)   |

cbrtcbrtfcbrtl
(C99)(C99)(C99)
|   | computes cube root (3√xx33√x)
(function)   |

hypothypotfhypotl
(C99)(C99)(C99)
|   | computes square root of the sum of the squares of two given numbers (√x2+y2x2+y2√x2
+y2
)
(function)   |

#####  Trigonometric functions

sinsinfsinl
(C99)(C99)
|   | computes sine (sinxsin⁡xsin(x))
(function)   |

coscosfcosl
(C99)(C99)
|   | computes cosine (cosxcos⁡xcos(x))
(function)   |

tantanftanl
(C99)(C99)
|   | computes tangent (tanxtan⁡xtan(x))
(function)   |

asinasinfasinl
(C99)(C99)
|   | computes arc sine (arcsinxarcsin⁡xarcsin(x))
(function)   |

acosacosfacosl
(C99)(C99)
|   | computes arc cosine (arccosxarccos⁡xarccos(x))
(function)   |

atanatanfatanl
(C99)(C99)
|   | computes arc tangent (arctanxarctan⁡xarctan(x))
(function)   |

atan2atan2fatan2l
(C99)(C99)
|   | computes arc tangent, using signs to determine quadrants
(function)   |

#####  Hyperbolic functions

sinhsinhfsinhl
(C99)(C99)
|   | computes hyperbolic sine (sinhxsinh⁡xsinh(x))
(function)   |

coshcoshfcoshl
(C99)(C99)
|   | computes hyperbolic cosine (coshxcosh⁡xcosh(x))
(function)   |

tanhtanhftanhl
(C99)(C99)
|   | computes hyperbolic tangent (tanhxtanh⁡xtanh(x))
(function)   |

asinhasinhfasinhl
(C99)(C99)(C99)
|   | computes inverse hyperbolic sine (arsinhxarsinh⁡xarsinh(x))
(function)   |

acoshacoshfacoshl
(C99)(C99)(C99)
|   | computes inverse hyperbolic cosine (arcoshxarcosh⁡xarcosh(x))
(function)   |

atanhatanhfatanhl
(C99)(C99)(C99)
|   | computes inverse hyperbolic tangent (artanhxartanh⁡xartanh(x))
(function)   |

#####  Error and gamma functions

erferfferfl
(C99)(C99)(C99)
|   | computes error function
(function)   |

erfcerfcferfcl
(C99)(C99)(C99)
|   | computes complementary error function
(function)   |

tgammatgammaftgammal
(C99)(C99)(C99)
|   | computes gamma function
(function)   |

lgammalgammaflgammal
(C99)(C99)(C99)
|   | computes natural (base-*e*) logarithm of the gamma function
(function)   |

#####  Nearest integer floating-point operations

ceilceilfceill
(C99)(C99)
|   | computes smallest integer not less than the given value
(function)   |

floorfloorffloorl
(C99)(C99)
|   | computes largest integer not greater than the given value
(function)   |

trunctruncftruncl
(C99)(C99)(C99)
|   | rounds to nearest integer not greater in magnitude than the given value
(function)   |

roundroundfroundllroundlroundflroundlllroundllroundfllroundl
(C99)(C99)(C99)(C99)(C99)(C99)(C99)(C99)(C99)
|   | rounds to nearest integer, rounding away from zero in halfway cases
(function)   |

nearbyintnearbyintfnearbyintl
(C99)(C99)(C99)
|   | rounds to an integer using current rounding mode
(function)   |

rintrintfrintllrintlrintflrintlllrintllrintfllrintl
(C99)(C99)(C99)(C99)(C99)(C99)(C99)(C99)(C99)
|   | rounds to an integer using current rounding mode with
exception if the result differs
(function)   |

#####  Floating-point manipulation functions

frexpfrexpffrexpl
(C99)(C99)
|   | breaks a number into significand and a power of 2
(function)   |

ldexpldexpfldexpl
(C99)(C99)
|   | multiplies a number by 2 raised to a power
(function)   |

modfmodffmodfl
(C99)(C99)
|   | breaks a number into integer and fractional parts
(function)   |

scalbnscalbnfscalbnlscalblnscalblnfscalblnl
(C99)(C99)(C99)(C99)(C99)(C99)
|   | computes efficiently a number times FLT_RADIX raised to a power
(function)   |

ilogbilogbfilogbl
(C99)(C99)(C99)
|   | extracts exponent of the given number
(function)   |

logblogbflogbl
(C99)(C99)(C99)
|   | extracts exponent of the given number
(function)   |

nextafternextafterfnextafterlnexttowardnexttowardfnexttowardl
(C99)(C99)(C99)(C99)(C99)(C99)
|   | determines next representable floating-point value towards the given value
(function)   |

nextupnextupfnextuplnextdownnextdownfnextdownl
(C23)(C23)(C23)(C23)(C23)(C23)
|   | determines next representable floating-point value greater or less than the given value
(function)   |

copysigncopysignfcopysignl
(C99)(C99)(C99)
|   | produces a value with the magnitude of a given value and the sign of another given value
(function)   |

#####  Classification and comparison

fpclassify
(C99)
|   | classifies the given floating-point value
(function macro)   |

isfinite
(C99)
|   | checks if the given number has finite value
(function macro)   |

isinf
(C99)
|   | checks if the given number is infinite
(function macro)   |

isnan
(C99)
|   | checks if the given number is NaN
(function macro)   |

isnormal
(C99)
|   | checks if the given number is normal
(function macro)   |

signbit
(C99)
|   | checks if the given number is negative
(function macro)   |

isgreater
(C99)
|   | checks if the first floating-point argument is greater than the second
(function macro)   |

isgreaterequal
(C99)
|   | checks if the first floating-point argument is greater or equal than the second
(function macro)   |

isless
(C99)
|   | checks if the first floating-point argument is less than the second
(function macro)   |

islessequal
(C99)
|   | checks if the first floating-point argument is less or equal than the second
(function macro)   |

islessgreater
(C99)
|   | checks if the first floating-point argument is less or greater than the second
(function macro)   |

isunordered
(C99)
|   | checks if two floating-point values are unordered
(function macro)   |

### Synopsis

|  | This section is incomplete
Reason:
- add synopses from B.11 Mathematics <math.h>

- place obligatory and optional parts in different sections

```c
#define __STDC_VERSION_MATH_H__ 202311L // TODO: ...
```

---
來源頁路徑：`en.cppreference.com/c/header/math.html`

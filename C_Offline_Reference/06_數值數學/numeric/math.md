# Common mathematical functions

> 來源：cppreference C 語言參考文件（離線轉換版）。

### Types

Defined in header `<stdlib.h>`

div_t
|   | structure type, return of the div function
(typedef)   |

ldiv_t
|   | structure type, return of the ldiv function
(typedef)   |

lldiv_t
(C99)
|   | structure type, return of the lldiv function
(typedef)   |

Defined in header `<inttypes.h>`

imaxdiv_t
(C99)
|   | structure type, return of the imaxdiv function
(typedef)   |

Defined in header `<math.h>`

float_t
(C99)
|   | most efficient floating-point type at least as wide as `float`
(typedef)   |

double_t
(C99)
|   | most efficient floating-point type at least as wide as `double`
(typedef)   |

### Constants

Defined in header `<math.h>`

HUGE_VALFHUGE_VALHUGE_VALL
(C99)(C99)
|   | indicates value too big to be representable (infinity) by `float`, `double` and `long double` respectively
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

Defined in header `<math.h>`    (deprecated in C23)

Defined in header `<float.h>`  (since C23)

INFINITY
(C99)
|   | evaluates to positive infinity (if exists)
(macro constant)   |

NAN
(C99)
|   | evaluates to a quiet NaN of type `float` (if exists)
(macro constant)   |

Defined in header `<float.h>`

FLT_SNANDBL_SNANLDBL_SNAN
(C23)
|   | evaluates to a signaling NaN of `float`, `double` and `long double` respectively (if exists)
(macro constant)   |

#####  Classification

Defined in header `<math.h>`

FP_NORMALFP_SUBNORMALFP_ZEROFP_INFINITEFP_NAN
(C99)(C99)(C99)(C99)(C99)
|   | indicates a floating-point category
(macro constant)   |

### Functions

Defined in header `<stdlib.h>`

abslabsllabs
(C99)
|   | computes absolute value of an integral value (|x||x||x|)
(function)   |

divldivlldiv
(C99)
|   | computes quotient and remainder of integer division
(function)   |

Defined in header `<inttypes.h>`

imaxabs
(C99)
|   | computes absolute value of an integral value (|x||x||x|)
(function)   |

imaxdiv
(C99)
|   | computes quotient and remainder of integer division
(function)   |

Defined in header `<math.h>`

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

fdimfdimffdiml
(C99)(C99)(C99)
|   | determines positive difference of two floating-point values (max(0,x−y)max(0,x−y)max(0, x-y))
(function)   |

nannanfnanl
(C99)(C99)(C99)
|   | returns a NaN (not-a-number)
(function)   |

#####  Maximum/minimum operations

fmaxfmaxffmaxl
(C99)(C99)(C99)
|   | determines larger of two floating-point values
(function)   |

fminfminffminl
(C99)(C99)(C99)
|   | determines smaller of two floating-point values
(function)   |

fmaximumfmaximumffmaximuml
(C23)(C23)(C23)
|   | determines larger of two floating-point values. If either argument is NaN, returns NaN
(function)   |

fminimumfminimumffminimuml
(C23)(C23)(C23)
|   | determines smaller of two floating-point values. If either argument is NaN, returns NaN
(function)   |

fmaximum_numfmaximum_numffmaximum_numl
(C23)(C23)(C23)
|   | determines larger of two floating-point values. If one argument is NaN, returns the non-NaN argument. Returns NaN only if both arguments are NaN
(function)   |

fminimum_numfminimum_numffminimum_numl
(C23)(C23)(C23)
|   | determines smaller of two floating-point values. If one argument is NaN, returns the non-NaN argument. Returns NaN only if both arguments are NaN
(function)   |

fmaximum_magfmaximum_magffmaximum_magl
(C23)(C23)(C23)
|   | determines the floating-point value with the larger magnitude of two floating-point values. If either argument is NaN, returns NaN
(function)   |

fminimum_magfminimum_magffminimum_magl
(C23)(C23)(C23)
|   | determines the floating-point value with the smaller magnitude of two floating-point values. If either argument is NaN, returns NaN
(function)   |

fmaximum_mag_numfmaximum_mag_numffmaximum_mag_numl
(C23)(C23)(C23)
|   | determines the floating-point value with the larger magnitude of two floating-point values. If one argument is NaN, returns the non-NaN argument. Returns NaN only if both arguments are NaN
(function)   |

fminimum_mag_numfminimum_mag_numffminimum_mag_numl
(C23)(C23)(C23)
|   | determines the floating-point value with the smaller magnitude of two floating-point values. If one argument is NaN, returns the non-NaN argument. Returns NaN only if both arguments are NaN
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

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.8 Format conversion of integer types <inttypes.h> (p: TBD)
7.8 整數型別格式轉換 <inttypes.h>（p: TBD）
7.8 整數型別格式轉換 <inttypes.h>（p: TBD）

- 7.12 Mathematics <math.h> (p: TBD)
7.12 數學 <math.h>（p: TBD）
7.12 數學 <math.h>（p: TBD）

- 7.22 General utilities <stdlib.h> (p: TBD)
7.22 通用工具 <stdlib.h>（p: TBD）
7.22 通用工具 <stdlib.h>（p: TBD）

- 7.31.5 Format conversion of integer types <inttypes.h> (p: TBD)
7.31.5 整數型別格式轉換 <inttypes.h>（p: TBD）
7.31.5 整數型別格式轉換 <inttypes.h>（p: TBD）

- 7.31.12 General utilities <stdlib.h> (p: TBD)
7.31.12 通用工具 <stdlib.h> （頁碼：待定）
7.31.12 通用工具 <stdlib.h> （頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.8 Format conversion of integer types <inttypes.h> (p: 158-160)
7.8 整數型別格式轉換 <inttypes.h> （頁碼：158-160）
7.8 整數型別格式轉換 <inttypes.h> （頁碼：158-160）

- 7.12 Mathematics <math.h> (p: 169-190)
7.12 數學 <math.h> （頁碼：169-190）
7.12 數學 <math.h> （頁碼：169-190）

- 7.22 General utilities <stdlib.h> (p: 248-262)
7.22 通用工具 <stdlib.h> （頁碼：248-262）
7.22 通用工具 <stdlib.h> （頁碼：248-262）

- 7.31.5 Format conversion of integer types <inttypes.h> (p: 332)
7.31.5 整數型別格式轉換 <inttypes.h> （頁碼：332）
7.31.5 整數型別格式轉換 <inttypes.h> （頁碼：332）

- 7.31.12 General utilities <stdlib.h> (p: 333)
7.31.12 通用工具 <stdlib.h> （頁碼：333）
7.31.12 通用工具 <stdlib.h> （頁碼：333）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.8 Format conversion of integer types <inttypes.h> (p: 217-220)
7.8 整數型別格式轉換 <inttypes.h> （頁碼：198-201）
7.8 整數型別格式轉換 <inttypes.h> （頁碼：198-201）

- 7.12 Mathematics <math.h> (p: 231-261)
7.12 數學 <math.h> （頁碼：231-261）
7.12 數學 <math.h> （頁碼：231-261）

- 7.22 General utilities <stdlib.h> (p: 340-360)
7.22 通用工具 <stdlib.h> （頁碼：340-360）
7.22 通用工具 <stdlib.h> （頁碼：340-360）

- 7.31.5 Format conversion of integer types <inttypes.h> (p: 455)
7.31.5 整數型別格式轉換 <inttypes.h> （頁碼：455）
7.31.5 整數型別格式轉換 <inttypes.h> （頁碼：455）

- 7.31.12 General utilities <stdlib.h> (p: 456)
7.31.12 通用工具 <stdlib.h> （頁碼：456）
7.31.12 通用工具 <stdlib.h> （頁碼：456）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.8 Format conversion of integer types <inttypes.h> (p: 198-201)
7.8 整數型別格式轉換 <inttypes.h> （頁碼：198-201）
7.8 整數型別格式轉換 <inttypes.h> （頁碼：198-201）

- 7.12 Mathematics <math.h> (p: 212-242)
7.12 數學 <math.h> （頁碼：212-242）
7.12 數學 <math.h> （頁碼：212-242）

- 7.20 General utilities <stdlib.h> (p: 306-324)
7.20 通用工具 <stdlib.h> （頁碼：306-324）
7.20 通用工具 <stdlib.h> （頁碼：306-324）

- 7.26.4 Format conversion of integer types <inttypes.h> (p: 401)
7.26.4 整數型別格式轉換 <inttypes.h> （頁碼：401）
7.26.4 整數型別格式轉換 <inttypes.h> （頁碼：401）

- 7.26.10 General utilities <stdlib.h> (p: 402)
7.26.10 通用工具 <stdlib.h> （頁碼：402）
7.26.10 通用工具 <stdlib.h> （頁碼：402）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.5 MATHEMATICS <math.h>
4.5 數學 <math.h>
4.5 數學 <math.h>

- 4.10 GENERAL UTILITIES <stdlib.h>
4.10 通用工具 <stdlib.h>
4.10 通用工具 <stdlib.h>

- 4.13.4 Mathematics <math.h>
4.13.4 數學 <math.h>
4.13.4 數學 <math.h>

- 7.13.7 General utilities <stdlib.h>
7.13.7 通用工具 <stdlib.h>
7.13.7 通用工具 <stdlib.h>

### See also

C++ documentation for Common mathematical functions

---
來源頁路徑：`en.cppreference.com/c/numeric/math.html`

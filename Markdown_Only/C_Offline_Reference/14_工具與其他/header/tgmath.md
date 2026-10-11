# Standard library header <tgmath.h> (C99)

> 來源：cppreference C 語言參考文件（離線轉換版）。

This header is part of numeric library and provides type-generic macros that determine which real or, when applicable, complex function to call based on the types of the arguments.
這個標頭檔屬於數值函式庫，提供型別泛型巨集，會依參數型別決定要呼叫哪個實數函式；適用時也會呼叫複數函式。

### Includes

| <math.h>  |

| <complex.h>  |

|  | This section is incomplete
Reason: 7.28 Type-generic math <tgmath.h>  |

### Synopsis

|  | This section is incomplete
Reason: B.27 Type-generic math <tgmath.h>  |

```c
#include <math.h> #include <complex.h> #define __STDC_VERSION_TGMATH_H__ 202311L #define acos /* see description */ #define acosh /* see description */ #define acospi /* see description */ #define asin /* see description */ #define asinh /* see description */ #define asinpi /* see description */ #define atan /* see description */ #define atan2 /* see description */ #define atan2pi /* see description */ #define atanh /* see description */ #define atanpi /* see description */ #define cbrt /* see description */ #define ceil /* see description */ #define compoundn /* see description */ #define copysign /* see description */ #define cos /* see description */ #define cosh /* see description */ #define cospi /* see description */ #define dadd /* see description */ #define ddiv /* see description */ #define dfma /* see description */ #define dmul /* see description */ #define dsqrt /* see description */ #define dsub /* see description */ #define erf /* see description */ #define erfc /* see description */ #define exp /* see description */ #define exp10 /* see description */ #define exp10m1 /* see description */ #define exp2 /* see description */ #define exp2m1 /* see description */ #define expm1 /* see description */ #define fabs /* see description */ #define fadd /* see description */ #define fdim /* see description */ #define fdiv /* see description */ #define ffma /* see description */ #define floor /* see description */ #define fma /* see description */ #define fmax /* see description */ #define fmaximum /* see description */ #define fmaximum_mag /* see description */ #define fmaximum_mag_num /* see description */ #define fmaximum_num /* see description */ #define fmin /* see description */ #define fminimum /* see description */ #define fminimum_mag /* see description */ #define fminimum_mag_num /* see description */ #define fminimum_num /* see description */ #define fmod /* see description */ #define fmul /* see description */ #define frexp /* see description */ #define fromfp /* see description */ #define fromfpx /* see description */ #define fsqrt /* see description */ #define fsub /* see description */ #define hypot /* see description */ #define ilogb /* see description */ #define ldexp /* see description */ #define lgamma /* see description */ #define llogb /* see description */ #define llrint /* see description */ #define llround /* see description */ #define log /* see description */ #define log10 /* see description */ #define log10p1 /* see description */ #define log1p /* see description */ #define log2 /* see description */ #define log2p1 /* see description */ #define logb /* see description */ #define logp1 /* see description */ #define lrint /* see description */ #define lround /* see description */ #define nearbyint /* see description */ #define nextafter /* see description */ #define nextdown /* see description */ #define nexttoward /* see description */ #define nextup /* see description */ #define pow /* see description */ #define pown /* see description */ #define powr /* see description */ #define remainder /* see description */ #define remquo /* see description */ #define rint /* see description */ #define rootn /* see description */ #define round /* see description */ #define roundeven /* see description */ #define rsqrt /* see description */ #define scalbln /* see description */ #define scalbn /* see description */ #define sin /* see description */ #define sinh /* see description */ #define sinpi /* see description */ #define sqrt /* see description */ #define tan /* see description */ #define tanh /* see description */ #define tanpi /* see description */ #define tgamma /* see description */ #define trunc /* see description */ #define ufromfp /* see description */ #define ufromfpx /* see description */
```

Only if the implementation does not define `__STDC_NO_COMPLEX__`:
僅當實現未定義 __STDC_NO_COMPLEX__ ：

```c
#ifndef __STDC_WANT_LIB_EXT1__ #define carg /* see description */ #define cimag /* see description */ #define conj /* see description */ #define cproj /* see description */ #define creal /* see description */ #endif
```

Only if the implementation defines `__STDC_IEC_60559_DFP__`:
僅當實現定義 __STDC_IEC_60559_DFP__ ：

```c
#define d32add /* see description */ #define d32div /* see description */ #define d32fma /* see description */ #define d32mul /* see description */ #define d32sqrt /* see description */ #define d32sub /* see description */ #define d64add /* see description */ #define d64div /* see description */ #define d64fma /* see description */ #define d64mul /* see description */ #define d64sqrt /* see description */ #define d64sub /* see description */ #define llquantexp /* see description */ #define quantize /* see description */ #define quantum /* see description */ #define samequantum /* see description */
```

Only if the implementation defines `__STDC_IEC_60559_TYPES__` and additionally the user code defines `__STDC_WANT_IEC_60559_TYPES_EXT__` before any inclusion of `<tgmath.h>`:
僅當實現定義 __STDC_IEC_60559_TYPES__ ，且此外使用者程式碼 在包含 <tgmath.h> 之前的任何位置定義 __STDC_WANT_IEC_60559_TYPES_EXT__ ：

```c
#ifdef __STDC_WANT_IEC_60559_TYPES_EXT__ #define /*dMadd*/ /* see description */ #define /*dMdiv*/ /* see description */ #define /*dMfma*/ /* see description */ #define /*dMmul*/ /* see description */ #define /*dMsqrt*/ /* see description */ #define /*dMsub*/ /* see description */ #define /*dMxadd*/ /* see description */ #define /*dMxdiv*/ /* see description */ #define /*dMxfma*/ /* see description */ #define /*dMxmul*/ /* see description */ #define /*dMxsqrt*/ /* see description */ #define /*dMxsub*/ /* see description */ #define /*fMadd*/ /* see description */ #define /*fMdiv*/ /* see description */ #define /*fMfma*/ /* see description */ #define /*fMmul*/ /* see description */ #define /*fMsqrt*/ /* see description */ #define /*fMsub*/ /* see description */ #define /*fMxadd*/ /* see description */ #define /*fMxdiv*/ /* see description */ #define /*fMxfma*/ /* see description */ #define /*fMxmul*/ /* see description */ #define /*fMxsqrt*/ /* see description */ #define /*fMxsub*/ /* see description */
```

---
來源頁路徑：`en.cppreference.com/c/header/tgmath.html`

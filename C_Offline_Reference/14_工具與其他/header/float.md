# Standard library header <float.h>

> 來源：cppreference C 語言參考文件（離線轉換版）。

This header is part of the type support library, in particular its numeric limits interface.
該標頭檔是型別支援庫的一部分，特別是其數值極限介面。

### Macros

#####  Characteristics

__STDC_VERSION_FLOAT_H__
(C23)
|   | expands to `202311L`
(macro constant)   |

FLT_ROUNDS
|   | default rounding mode of floating-point arithmetic
(macro)   |

FLT_EVAL_METHOD
(C99)
|   | specifies in what precision all arithmetic operations are done
(macro constant)   |

FLT_HAS_SUBNORMDBL_HAS_SUBNORMLDBL_HAS_SUBNORM
(C11)(deprecated in C23)
|   | specifies whether the type supports subnormal (denormal) numbers:
`-1` – indeterminable, `0` – absent, `1` – present
(macro constant)   |

FLT_RADIX
|   | the radix (integer base) used by the representation of all three floating-point types
(macro constant)   |

FLT_MANT_DIGDBL_MANT_DIGLDBL_MANT_DIG
|   | number of base `FLT_RADIX` digits that can be represented without losing precision for `float`, `double` and `long double` respectively
(macro constant)   |

FLT_DECIMAL_DIGDBL_DECIMAL_DIGLDBL_DECIMAL_DIG
(C11)
|   | conversion from `float`/`double`/`long double` to decimal with at least `FLT_DECIMAL_DIG`/`DBL_DECIMAL_DIG`/`LDBL_DECIMAL_DIG` digits and back is the identity conversion: this is the decimal precision required to serialize/deserialize a floating-point value
(macro constant)   |

DECIMAL_DIG
(C99)(deprecated in C23)
|   | conversion from `long double` to decimal with at least `DECIMAL_DIG` digits and back to `long double` is the identity conversion: this is the decimal precision required to serialize/deserialize a `long double`
(macro constant)   |

CR_DECIMAL_DIG
(C23)
|   | conversions between all supported ISO/IEC 60559 binary floating-point types and character sequences with at most `CR_DECIMAL_DIG` significant decimal digits are correctly rounded
(macro constant)   |

FLT_IS_IEC_60559DBL_IS_IEC_60559LDBL_IS_IEC_60559
(C23)
|   | specifies if the type has the precision and exponent range of an ISO/IEC 60559 format
(macro constant)   |

FLT_DIGDBL_DIGLDBL_DIG
|   | number of decimal digits that are guaranteed to be preserved in text → `float`/`double`/`long double` → text roundtrip without change due to rounding or overflow
(macro constant)   |

FLT_MIN_EXPDBL_MIN_EXPLDBL_MIN_EXP
|   | minimum negative integer such that `FLT_RADIX` raised by power one less than that integer is a normalized `float`, `double` and `long double` respectively
(macro constant)   |

FLT_MIN_10_EXPDBL_MIN_10_EXPLDBL_MIN_10_EXP
|   | minimum negative integer such that `10` raised to that power is a normalized `float`, `double` and `long double` respectively
(macro constant)   |

FLT_MAX_EXPDBL_MAX_EXPLDBL_MAX_EXP
|   | maximum positive integer such that `FLT_RADIX` raised by power one less than that integer is a representable finite `float`, `double` and `long double` respectively
(macro constant)   |

FLT_MAX_10_EXPDBL_MAX_10_EXPLDBL_MAX_10_EXP
|   | maximum positive integer such that `10` raised to that power is a representable finite `float`, `double` and `long double` respectively
(macro constant)   |

FLT_MAXDBL_MAXLDBL_MAX
|   | maximum finite value of `float`, `double` and `long double` respectively
(macro constant)   |

FLT_NORM_MAXDBL_NORM_MAXLDBL_NORM_MAX
(C23)
|   | maximum normalized value of `float`, `double` and `long double` respectively
(macro constant)   |

FLT_EPSILONDBL_EPSILONLDBL_EPSILON
|   | difference between `1.0` and the next representable value for `float`, `double` and `long double` respectively
(macro constant)   |

FLT_MINDBL_MINLDBL_MIN
|   | minimum normalized positive value of `float`, `double` and `long double` respectively
(macro constant)   |

FLT_TRUE_MINDBL_TRUE_MINLDBL_TRUE_MIN
(C11)
|   | minimum positive value of `float`, `double` and `long double` respectively
(macro constant)   |

#####  Special values (since C23)

INFINITY
(C99)
|   | evaluates to positive infinity (if exists)
(macro constant)   |

NAN
(C99)
|   | evaluates to a quiet NaN of type `float` (if exists)
(macro constant)   |

FLT_SNANDBL_SNANLDBL_SNAN
(C23)
|   | evaluates to a signaling NaN of `float`, `double` and `long double` respectively (if exists)
(macro constant)   |

|  | This section is incomplete
Reason: Add macros from B.6.2, B.6.3  |

### Synopsis

```c
#define FLT_ROUNDS /* see definition */ #define FLT_EVAL_METHOD /* see definition */ #define FLT_HAS_SUBNORM /* see definition */ #define DBL_HAS_SUBNORM /* see definition */ #define LDBL_HAS_SUBNORM /* see definition */ #define FLT_RADIX /* see definition */ #define FLT_MANT_DIG /* see definition */ #define DBL_MANT_DIG /* see definition */ #define LDBL_MANT_DIG /* see definition */ #define FLT_DECIMAL_DIG /* see definition */ #define DBL_DECIMAL_DIG /* see definition */ #define LDBL_DECIMAL_DIG /* see definition */ #define DECIMAL_DIG /* see definition */ #define FLT_DIG /* see definition */ #define DBL_DIG /* see definition */ #define LDBL_DIG /* see definition */ #define FLT_MIN_EXP /* see definition */ #define DBL_MIN_EXP /* see definition */ #define LDBL_MIN_EXP /* see definition */ #define FLT_MIN_10_EXP /* see definition */ #define DBL_MIN_10_EXP /* see definition */ #define LDBL_MIN_10_EXP /* see definition */ #define FLT_MAX_EXP /* see definition */ #define DBL_MAX_EXP /* see definition */ #define LDBL_MAX_EXP /* see definition */ #define FLT_MAX_10_EXP /* see definition */ #define DBL_MAX_10_EXP /* see definition */ #define LDBL_MAX_10_EXP /* see definition */ #define FLT_MAX /* see definition */ #define DBL_MAX /* see definition */ #define LDBL_MAX /* see definition */ #define FLT_EPSILON /* see definition */ #define DBL_EPSILON /* see definition */ #define LDBL_EPSILON /* see definition */ #define FLT_MIN /* see definition */ #define DBL_MIN /* see definition */ #define LDBL_MIN /* see definition */ #define FLT_TRUE_MIN /* see definition */ #define DBL_TRUE_MIN /* see definition */ #define LDBL_TRUE_MIN /* see definition */ #define INFINITY /* see definition */ #define NAN /* see definition */ #define FLT_SNAN /* see definition */ #define DBL_SNAN /* see definition */ #define LDBL_SNAN /* see definition */
```

---
來源頁路徑：`en.cppreference.com/c/header/float.html`

# Numeric limits

> 來源：cppreference C 語言參考文件（離線轉換版）。

### Characteristics of integer types
整數型別的特性

#####  Characteristics of core language integer types

Defined in header `<limits.h>`

BOOL_WIDTH
(C23)
|   | bit width of `bool`
`bool` 的位元寬度。
(macro constant)   |

CHAR_BIT
|   | bit width of byte
一個位元組的位元數。
(macro constant)   |

MB_LEN_MAX
|   | maximum number of bytes in a multibyte character
一個多位元組字元最多會占用的位元組數。
(macro constant)   |

CHAR_WIDTH
(C23)
|   | bit width of `char`
`char` 的位元寬度。
(macro constant)   |

CHAR_MIN
|   | minimum value of `char`
`char` 可表示的最小值。
(macro constant)   |

CHAR_MAX
|   | maximum value of `char`
`char` 可表示的最大值。
(macro constant)   |

SCHAR_WIDTHSHRT_WIDTHINT_WIDTHLONG_WIDTHLLONG_WIDTH
(C23)(C23)(C23)(C23)(C23)
|   | bit width of `signed char`, `short`, `int`, `long`, and `long long` respectively
依序代表 `signed char`、`short`、`int`、`long`、`long long` 的位元寬度。
(macro constant)   |

SCHAR_MINSHRT_MININT_MINLONG_MINLLONG_MIN
(C99)
|   | minimum value of `signed char`, `short`, `int`, `long` and `long long` respectively
依序代表 `signed char`、`short`、`int`、`long`、`long long` 可表示的最小值。
(macro constant)   |

SCHAR_MAXSHRT_MAXINT_MAXLONG_MAXLLONG_MAX
(C99)
|   | maximum value of `signed char`, `short`, `int`, `long` and `long long` respectively
依序代表 `signed char`、`short`、`int`、`long`、`long long` 可表示的最大值。
(macro constant)   |

UCHAR_WIDTHUSHRT_WIDTHUINT_WIDTHULONG_WIDTHULLONG_WIDTH
(C23)(C23)(C23)(C23)(C23)
|   | bit width of `unsigned char`, `unsigned short`, `unsigned int`, `unsigned long`, and `unsigned long long` respectively
依序代表 `unsigned char`、`unsigned short`、`unsigned int`、`unsigned long`、`unsigned long long` 的位元寬度。
(macro constant)   |

UCHAR_MAXUSHRT_MAXUINT_MAXULONG_MAXULLONG_MAX
(C99)
|   | maximum value of `unsigned char`, `unsigned short`, `unsigned int`,
`unsigned long` and `unsigned long long` respectively
依序代表這些無號整數型別可表示的最大值。
(macro constant)   |

BITINT_MAXWIDTH
(C23)
|   | maximum width `N` supported by the declaration of a bit-precise integer in the type specifier `_BitInt(N)`
`_BitInt(N)` 所支援的最大位元寬度 `N`。
(macro constant)  |

#####  Characteristics of library type aliases

Defined in header `<stdint.h>`

PTRDIFF_WIDTH
(C23)
|   | bit width of ptrdiff_t
`ptrdiff_t` 的位元寬度。
(macro constant)   |

PTRDIFF_MIN
(C99)
|   | minimum value of ptrdiff_t
`ptrdiff_t` 可表示的最小值。
(macro constant)   |

PTRDIFF_MAX
(C99)
|   | maximum value of ptrdiff_t
`ptrdiff_t` 可表示的最大值。
(macro constant)   |

SIZE_WIDTH
(C23)
|   | bit width of size_t
`size_t` 的位元寬度。
(macro constant)   |

SIZE_MAX
(C99)
|   | maximum value of size_t
`size_t` 可表示的最大值。
(macro constant)   |

SIG_ATOMIC_WIDTH
(C23)
|   | bit width of sig_atomic_t
`sig_atomic_t` 的位元寬度。
(macro constant)   |

SIG_ATOMIC_MIN
(C99)
|   | minimum value of sig_atomic_t
`sig_atomic_t` 可表示的最小值。
(macro constant)   |

SIG_ATOMIC_MAX
(C99)
|   | maximum value of sig_atomic_t
`sig_atomic_t` 可表示的最大值。
(macro constant)   |

WINT_WIDTH
(C23)
|   | bit width of `wint_t`
`wint_t` 的位元寬度。
(macro constant)   |

WINT_MIN
(C99)
|   | minimum value of `wint_t`
`wint_t` 可表示的最小值。
(macro constant)   |

WINT_MAX
(C99)
|   | maximum value of `wint_t`
`wint_t` 可表示的最大值。
(macro constant)   |

Defined in header `<wchar.h>`

Defined in header `<stdint.h>`

WCHAR_WIDTH
(C23)
|   | bit width of `wchar_t`
`wchar_t` 的位元寬度。
(macro constant)   |

WCHAR_MIN
(C99)
|   | minimum value of `wchar_t`
`wchar_t` 可表示的最小值。
(macro constant)   |

WCHAR_MAX
(C99)
|   | maximum value of `wchar_t`
`wchar_t` 可表示的最大值。
(macro constant)   |

### Value requirements
取值要求

`BOOL_WIDTH` always expands to `1`.
`BOOL_WIDTH` 的值固定為 `1`。
|   | (since C23) |

Each of the `*_WIDTH` macros (other than `BOOL_WIDTH`), `BITINT_MAXWIDTH`,(since C23) `CHAR_BIT` and `MB_LEN_MAX` expands to an implementation-defined value. The allowed minimum values are listed below, where each group of macros separated by / always expand to the same value:
除了 BOOL_WIDTH、BITINT_MAXWIDTH、（自 C23 起）CHAR_BIT 和 MB_LEN_MAX 之外，每個 *_WIDTH 巨集都會展開成由實作定義的值。標準允許的最小值如下；以斜線分隔的巨集組會展開成相同的值：

- at least `1`: `MB_LEN_MAX`
至少為 1：MB_LEN_MAX

- at least `8`: `CHAR_BIT` / `CHAR_WIDTH` / `SCHAR_WIDTH` / `UCHAR_WIDTH`, `WCHAR_WIDTH`, `SIG_ATOMIC_WIDTH`
至少為 8：CHAR_BIT、CHAR_WIDTH、SCHAR_WIDTH、UCHAR_WIDTH、WCHAR_WIDTH、SIG_ATOMIC_WIDTH

- at least `16`: `SHRT_WIDTH` / `USHRT_WIDTH`, `INT_WIDTH` / `UINT_WIDTH`, `PTRDIFF_WIDTH`, `SIZE_WIDTH`, `WINT_WIDTH`
至少為 16：SHRT_WIDTH、USHRT_WIDTH、INT_WIDTH、UINT_WIDTH、PTRDIFF_WIDTH、SIZE_WIDTH、WINT_WIDTH

- at least `32`: `LONG_WIDTH` / `ULONG_WIDTH`
至少為 32：LONG_WIDTH、ULONG_WIDTH

- at least `64`: `LLONG_WIDTH` / `ULLONG_WIDTH`
至少為 64：LLONG_WIDTH、ULLONG_WIDTH

- at least `ULLONG_WIDTH`: `BITINT_MAXWIDTH`
至少等於 ULLONG_WIDTH：BITINT_MAXWIDTH

#### Notes

The types of these constants, other than the `*_WIDTH` macros, (since C23)`CHAR_BIT` and `MB_LEN_MAX`, are required to match the results of the integral promotions as applied to objects of the types they describe: `CHAR_MAX` may have type `int` or `unsigned int`, but never `char`. Similarly `USHRT_MAX` may not be of an unsigned type: its type may be `int`.
除了 *_WIDTH 巨集、（自 C23 起的）CHAR_BIT 和 MB_LEN_MAX 外，這些常數的型別會符合對應型別物件經過整數提升後的型別。例如，CHAR_MAX 的型別可能是 int 或 unsigned int，但不會是 char。類似地，USHRT_MAX 的型別也可能是 int，而非無號型別。
A freestanding implementation may lack sig_atomic_t and/or `wint_t` typedef names, in which case the `SIG_ATOMIC_*` and/or `WINT_*` macros are correspondingly absent.
獨立式實作可能不提供 sig_atomic_t 或 wint_t typedef；若是如此，SIG_ATOMIC_* 或 WINT_* 巨集也不會定義。

#### Example

Run this code

```c
#include <limits.h> #include <stdint.h> #include <stdio.h> int main(void) {  printf("CHAR_BIT = %d\n", CHAR_BIT);  printf("MB_LEN_MAX = %d\n\n", MB_LEN_MAX);    printf("CHAR_MIN = %+d\n", CHAR_MIN);  printf("CHAR_MAX = %+d\n", CHAR_MAX);  printf("SCHAR_MIN = %+d\n", SCHAR_MIN);  printf("SCHAR_MAX = %+d\n", SCHAR_MAX);  printf("UCHAR_MAX = %u\n\n", UCHAR_MAX);    printf("SHRT_MIN = %+d\n", SHRT_MIN);  printf("SHRT_MAX = %+d\n", SHRT_MAX);  printf("USHRT_MAX = %u\n\n", USHRT_MAX);    printf("INT_MIN = %+d\n", INT_MIN);  printf("INT_MAX = %+d\n", INT_MAX);  printf("UINT_MAX = %u\n\n", UINT_MAX);    printf("LONG_MIN = %+ld\n", LONG_MIN);  printf("LONG_MAX = %+ld\n", LONG_MAX);  printf("ULONG_MAX = %lu\n\n", ULONG_MAX);    printf("LLONG_MIN = %+lld\n", LLONG_MIN);  printf("LLONG_MAX = %+lld\n", LLONG_MAX);  printf("ULLONG_MAX = %llu\n\n", ULLONG_MAX);    printf("PTRDIFF_MIN = %td\n", PTRDIFF_MIN);  printf("PTRDIFF_MAX = %+td\n", PTRDIFF_MAX);  printf("SIZE_MAX = %zu\n", SIZE_MAX);  printf("SIG_ATOMIC_MIN = %+jd\n",(intmax_t)SIG_ATOMIC_MIN);  printf("SIG_ATOMIC_MAX = %+jd\n",(intmax_t)SIG_ATOMIC_MAX);  printf("WCHAR_MIN = %+jd\n",(intmax_t)WCHAR_MIN);  printf("WCHAR_MAX = %+jd\n",(intmax_t)WCHAR_MAX);  printf("WINT_MIN = %jd\n", (intmax_t)WINT_MIN);  printf("WINT_MAX = %jd\n", (intmax_t)WINT_MAX); }
```

Possible output:
可能的輸出：

```c
CHAR_BIT = 8 MB_LEN_MAX = 16 CHAR_MIN = -128 CHAR_MAX = +127 SCHAR_MIN = -128 SCHAR_MAX = +127 UCHAR_MAX = 255 SHRT_MIN = -32768 SHRT_MAX = +32767 USHRT_MAX = 65535 INT_MIN = -2147483648 INT_MAX = +2147483647 UINT_MAX = 4294967295 LONG_MIN = -9223372036854775808 LONG_MAX = +9223372036854775807 ULONG_MAX = 18446744073709551615 LLONG_MIN = -9223372036854775808 LLONG_MAX = +9223372036854775807 ULLONG_MAX = 18446744073709551615 PTRDIFF_MIN = -9223372036854775808 PTRDIFF_MAX = +9223372036854775807 SIZE_MAX = 18446744073709551615 SIG_ATOMIC_MIN = -2147483648 SIG_ATOMIC_MAX = +2147483647 WCHAR_MIN = -2147483648 WCHAR_MAX = +2147483647 WINT_MIN = 0 WINT_MAX = 4294967295
```

### Characteristics and special values of floating-point types
浮點型別的特性和特殊值

#####  Characteristics of floating-point types

Defined in header `<float.h>`

FLT_ROUNDS
|   | default rounding mode of floating-point arithmetic
浮點運算預設採用的捨入方式。
(macro)   |

FLT_EVAL_METHOD
(C99)
|   | specifies in what precision all arithmetic operations are done
指定所有浮點算術運算使用的精度。
(macro constant)   |

FLT_HAS_SUBNORMDBL_HAS_SUBNORMLDBL_HAS_SUBNORM
(C11)(deprecated in C23)
|   | specifies whether the type supports subnormal (denormal) numbers:
`-1` – indeterminable, `0` – absent, `1` – present
指出該型別是否支援次正規數：`-1` 表示無法判定，`0` 表示不支援，`1` 表示支援。
(macro constant)   |

FLT_RADIX
|   | the radix (integer base) used by the representation of all three floating-point types
三種浮點型別表示數值時使用的基數。
(macro constant)   |

FLT_MANT_DIGDBL_MANT_DIGLDBL_MANT_DIG
|   | number of base `FLT_RADIX` digits that can be represented without losing precision for `float`, `double` and `long double` respectively
依序表示 `float`、`double`、`long double` 在不損失精度時可表示的 `FLT_RADIX` 進位有效位數。
(macro constant)   |

FLT_DECIMAL_DIGDBL_DECIMAL_DIGLDBL_DECIMAL_DIG
(C11)
|   | conversion from `float`/`double`/`long double` to decimal with at least `FLT_DECIMAL_DIG`/`DBL_DECIMAL_DIG`/`LDBL_DECIMAL_DIG` digits and back is the identity conversion: this is the decimal precision required to serialize/deserialize a floating-point value
將 `float`、`double` 或 `long double` 轉成至少具有對應位數的十進位數，再轉回原型別，值不會改變。這是序列化與還原浮點值所需的十進位精度。
(macro constant)   |

DECIMAL_DIG
(C99)(deprecated in C23)
|   | conversion from `long double` to decimal with at least `DECIMAL_DIG` digits and back to `long double` is the identity conversion: this is the decimal precision required to serialize/deserialize a `long double`
`long double` 轉成至少具有 `DECIMAL_DIG` 位數的十進位數，再轉回 `long double`，值不會改變；這是序列化與還原 `long double` 所需的十進位精度。
(macro constant)   |

FLT_DIGDBL_DIGLDBL_DIG
|   | number of decimal digits that are guaranteed to be preserved in text → `float`/`double`/`long double` → text roundtrip without change due to rounding or overflow
文字轉成 `float`、`double` 或 `long double` 再轉回文字時，能保證不因捨入或溢位而改變的十進位位數。
(macro constant)   |

FLT_MIN_EXPDBL_MIN_EXPLDBL_MIN_EXP
|   | minimum negative integer such that `FLT_RADIX` raised by power one less than that integer is a normalized `float`, `double` and `long double` respectively
依序為最小整數 `n`，使 `FLT_RADIX` 的 `n-1` 次方可表示成正規化的 `float`、`double` 或 `long double`。
(macro constant)   |

FLT_MIN_10_EXPDBL_MIN_10_EXPLDBL_MIN_10_EXP
|   | minimum negative integer such that `10` raised to that power is a normalized `float`, `double` and `long double` respectively
依序為最小整數 `n`，使 `10` 的 `n` 次方可表示成正規化的 `float`、`double` 或 `long double`。
(macro constant)   |

FLT_MAX_EXPDBL_MAX_EXPLDBL_MAX_EXP
|   | maximum positive integer such that `FLT_RADIX` raised by power one less than that integer is a representable finite `float`, `double` and `long double` respectively
依序為最大整數 `n`，使 `FLT_RADIX` 的 `n-1` 次方仍是可表示的有限 `float`、`double` 或 `long double`。
(macro constant)   |

FLT_MAX_10_EXPDBL_MAX_10_EXPLDBL_MAX_10_EXP
|   | maximum positive integer such that `10` raised to that power is a representable finite `float`, `double` and `long double` respectively
依序為最大整數 `n`，使 `10` 的 `n` 次方仍是可表示的有限 `float`、`double` 或 `long double`。
(macro constant)   |

FLT_MAXDBL_MAXLDBL_MAX
|   | maximum finite value of `float`, `double` and `long double` respectively
依序代表 `float`、`double`、`long double` 可表示的最大有限值。
(macro constant)   |

FLT_EPSILONDBL_EPSILONLDBL_EPSILON
|   | difference between `1.0` and the next representable value for `float`, `double` and `long double` respectively
依序代表 `1.0` 與下一個可表示的 `float`、`double`、`long double` 數值之間的差。
(macro constant)   |

FLT_MINDBL_MINLDBL_MIN
|   | minimum normalized positive value of `float`, `double` and `long double` respectively
依序代表 `float`、`double`、`long double` 可表示的最小正規化正值。
(macro constant)   |

FLT_TRUE_MINDBL_TRUE_MINLDBL_TRUE_MIN
(C11)
|   | minimum positive value of `float`, `double` and `long double` respectively
依序代表 `float`、`double`、`long double` 可表示的最小正值。
(macro constant)   |

#####  Special values of floating-point types

Defined in header `<math.h>`    (deprecated in C23)

Defined in header `<float.h>`  (since C23)

INFINITY
(C99)
|   | evaluates to positive infinity (if exists)
若實作支援無限大，會展開為正無限大。
(macro constant)   |

NAN
(C99)
|   | evaluates to a quiet NaN of type `float` (if exists)
若實作支援，會展開為 `float` 型別的靜默 NaN（非數值）。
(macro constant)   |

Defined in header `<float.h>`

FLT_SNANDBL_SNANLDBL_SNAN
(C23)
|   | evaluates to a signaling NaN of `float`, `double` and `long double` respectively (if exists)
若實作支援，依序會展開為 `float`、`double`、`long double` 型別的訊號 NaN。
(macro constant)   |

#### Example

Run this code

```c
#include <float.h> #include <math.h> #include <stdio.h> int main(void) { printf("DECIMAL_DIG = %d\n", DECIMAL_DIG); printf("FLT_DECIMAL_DIG = %d\n", FLT_DECIMAL_DIG); printf("FLT_RADIX = %d\n", FLT_RADIX); printf("FLT_MIN = %e\n", FLT_MIN); printf("FLT_MAX = %e\n", FLT_MAX); printf("FLT_EPSILON = %e\n", FLT_EPSILON); printf("FLT_DIG = %d\n", FLT_DIG); printf("FLT_MANT_DIG = %d\n", FLT_MANT_DIG); printf("FLT_MIN_EXP = %d\n", FLT_MIN_EXP); printf("FLT_MIN_10_EXP = %d\n", FLT_MIN_10_EXP); printf("FLT_MAX_EXP = %d\n", FLT_MAX_EXP); printf("FLT_MAX_10_EXP = %d\n", FLT_MAX_10_EXP); printf("FLT_ROUNDS = %d\n", FLT_ROUNDS); printf("FLT_EVAL_METHOD = %d\n", FLT_EVAL_METHOD); printf("FLT_HAS_SUBNORM = %d\n", FLT_HAS_SUBNORM); }
```

Possible output:
可能的輸出：

```c
DECIMAL_DIG = 37 FLT_DECIMAL_DIG = 9 FLT_RADIX = 2 FLT_MIN = 1.175494e-38 FLT_MAX = 3.402823e+38 FLT_EPSILON = 1.192093e-07 FLT_DIG = 6 FLT_MANT_DIG = 24 FLT_MIN_EXP = -125 FLT_MIN_10_EXP = -37 FLT_MAX_EXP = 128 FLT_MAX_10_EXP = 38 FLT_ROUNDS = 1 FLT_EVAL_METHOD = 1 FLT_HAS_SUBNORM = 1
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 5.2.4.2 Numerical limits (p: TBD)
5.2.4.2 數值極限 (p: 待定)
5.2.4.2 數值極限 (p: 待定)

- 7.22.3 Limits of other integer types (p: TBD)
7.22.3 其他整數型別的極限 (p: 待定)
7.22.3 其他整數型別的極限 (p: 待定)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 5.2.4.2 Numerical limits (p: 20-27)
5.2.4.2 數值極限 (p: 20-27)
5.2.4.2 數值極限 (p: 20-27)

- 7.20.3 Limits of other integer types (p: 215-216)
7.20.3 其他整數型別的極限 (p: 215-216)
7.20.3 其他整數型別的極限 (p: 215-216)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 5.2.4.2 Numerical limits (p: 26-34)
5.2.4.2 數值極限 (p: 26-34)
5.2.4.2 數值極限 (p: 26-34)

- 7.20.3 Limits of other integer types (p: 293-294)
7.20.3 其他整數型別的極限 (p: 293-294)
7.20.3 其他整數型別的極限 (p: 293-294)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 5.2.4.2 Numerical limits (p: 21-28)
5.2.4.2 數值極限 (p: 21-28)
5.2.4.2 數值極限 (p: 21-28)

- 7.18.3 Limits of other integer types (p: 259-260)
7.18.3 其他整數型別的極限 (p: 259-260)
7.18.3 其他整數型別的極限 (p: 259-260)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 2.2.4.2 Numerical limits
2.2.4.2 數值極限
2.2.4.2 數值極限

### See also

C++ documentation for C numeric limits interface

---
來源頁路徑：`en.cppreference.com/c/types/limits.html`

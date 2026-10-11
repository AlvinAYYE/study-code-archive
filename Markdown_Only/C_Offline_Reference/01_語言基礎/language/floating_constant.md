# Floating constant

> 來源：cppreference C 語言參考文件（離線轉換版）。

Allows values of floating type to be used directly in expressions.
允許浮點型別的值直接用於表示式中。

### Syntax

A floating constant is a non-lvalue expression having the form:
浮點常量是一個具有以下形式的非左值表示式：

|   |

| significand exponent ﻿(optional) suffix ﻿(optional)  |   |   |   |   |

|   |

Where the significand has the form
其中有效數字具有以下形式

|   |

| whole-number ﻿(optional) `**.**`(optional) fraction ﻿(optional)  |   |   |   |   |

|   |

The exponent has the form
指數具有以下形式

|   |

| `**e**` | `**E**` exponent-sign ﻿(optional) digit-sequence  |   | (1)  |   |   |

|   |

| `**p**` | `**P**` exponent-sign ﻿(optional) digit-sequence  |   | (2)  |   | (since C99)  |

|   |

1) The exponent syntax for a decimal floating-point constant

2) The exponent syntax for hexadecimal floating-point constant

Optional single quotes (`**'**`) can be inserted between the digits as a separator, they are ignored when compiling.
|   | (since C23) |

### Explanation

If the significand begins with the character sequence `0x` or `0X`, the floating constant is a *hexadecimal floating constant*. Otherwise, it is a *decimal floating constant*.
For a *hexadecimal floating constant*, the significand is interpreted as a hexadecimal rational number, and the digit-sequence of the exponent is interpreted as the integer power of 2 to which the significand has to be scaled.

```c
double d = 0x1.2p3; // hex fraction 1.2 (decimal 1.125) scaled by 2^3, that is 9.0
```
|   | (since C99) |

For a *decimal floating constant*, the significand is interpreted as a decimal rational number, and the digit-sequence of the exponent is interpreted as the integer power of 10 to which the significand has to be scaled.
對於十進位制浮點常量，有效數字被解釋為十進位制有理數，指數的數字序列被解釋為有效數字必須縮放的 10 的整數次冪。

```c
double d = 1.2e3; // decimal fraction 1.2 scaled by 10^3, that is 1200.0
```

#### Suffixes

An unsuffixed floating constant has type `double`. If suffix is the letter `**f**` or `**F**`, the floating constant has type `float`. If suffix is the letter `**l**` or `**L**`, the floating constant has type `long double`.
無字尾的浮點常量具有 double 型別。如果字尾是字母 f 或 F，則浮點常量具有 float 型別。如果字尾是字母 l 或 L，則浮點常量具有 long double 型別。

If the implementation predefines macro `__STDC_IEC_60559_BFP__`, the following suffixes and corresponding floating constants are additionally supported:

- if suffix is `**df**` or `**DF**`, the floating constant has type `_Decimal32`;

- if suffix is `**dd**` or `**DD**`, the floating constant has type `_Decimal64`;

- if suffix is `**dl**` or `**DL**`, the floating constant has type `_Decimal128`.

Suffixes for decimal floating-point types are not allowed in hexadecimal floating constants.
|   | (since C23) |

#### Optional parts

If the exponent is present and fractional part is not used, the decimal separator may be omitted:
如果存在指數且未使用小數部分，則可以省略小數分隔符：

```c
double x = 1e0; // floating-point 1.0 (period not used)
```

For decimal floating constants, the exponent part is optional. If it is omitted, the period is not optional, and either the whole-number or the fraction must be present.
對於十進位制浮點常量，指數部分是可選的。如果省略指數，則小數點不可省略，並且整數部分或小數部分必須存在。

```c
double x = 1.; // floating-point 1.0 (fractional part optional) double y = .1; // floating-point 0.1 (whole-number part optional)
```

For hexadecimal floating constants, the exponent is not optional to avoid ambiguity resulting from an `**f**` suffix being mistaken as a hexadecimal digit.
|   | (since C99) |

#### Representable values

The result of evaluating a floating constant is either the nearest representable value or the larger or smaller representable value immediately adjacent to the nearest representable value, chosen in an implementation-defined manner (in other words, default rounding direction during translation is implementation-defined).
浮點常量求值的結果要麼是最接近的可表示值，要麼是緊鄰最接近可表示值的較大或較小的可表示值，以實現定義的方式選擇（換句話說，翻譯期間的預設舍入方向是實現定義的）。
All floating constants of the same source form convert to the same internal format with the same value. Floating constants of different source forms, e.g. `1.23` and `1.230`, need not to convert to the same internal format and value.
相同源形式的所有浮點常量以相同的值轉換為相同的內部格式。不同源形式的浮點常量，例如 1.23 和 1.230，不必轉換為相同的內部格式和值。

Floating-point constants may convert to more range and precision than is indicated by their type, if indicated by FLT_EVAL_METHOD. For example, the constant `0.1f` may act as if it were `0.1L` in an expression.
The result of evaluating a hexadecimal floating constant, if FLT_RADIX is 2, is the exact value represented by the floating constant, correctly rounded to the target type.
|   | (since C99) |

Floating constants of decimal floating-point type that have the same numerical value xxx but different quantum exponents, e.g. `1230.dd`, `1230.0dd`, and `1.23e3dd`, have distinguishable internal representations.
The quantum exponent qqq of a floating constant of a decimal floating-point type is determined in the manner that 10q10q10q
represents 1 at the place of last digit of the significand when possible. If the quantum exponent qqq and the coefficient c=x⋅10−qc=x⋅10−qc=x·10-q
determined above cannot represented exactly in the type of the floating constant, qqq is increased as needed within the limit of the type, and ccc is reduced correspondingly, with needed rounding. The rounding may result in zero or infinity. If (the possibly rounded) ccc is still out of the permitted range after qqq reaches the maximum value, the resulted floating constant has value positive infinity.
|   | (since C23) |

### Notes

Default rounding direction and precision are in effect when the floating constants are converted into internal representations, and floating-point exceptions are not raised even if  #pragma STDC FENV_ACCESS is in effect (for execution-time conversion of character strings, strtod can be used). Note that this differs from arithmetic constant expressions of floating type.
當浮點常量轉換為內部表示時，預設舍入方向和精度生效，即使 #pragma STDC FENV_ACCESS 生效也不會引發浮點異常（對於執行時的字元字串轉換，可以使用 strtod）。注意，這與浮點型別的算術常量表示式不同。
Letters in the floating constants are case-insensitive, except that uppercase and lowercase cannot be both used in suffixes for decimal floating-point types(since C23): `0x1.ep+3` and `0X1.EP+3` represent the same floating-point value `15.0`.
浮點常量中的字母不區分大小寫，但十進位制浮點型別的字尾中不能同時使用大寫和小寫（自 C23 起）：0x1.ep+3 和 0X1.EP+3 表示相同的浮點值 15.0。
The decimal point specified by setlocale has no effect on the syntax of floating constants: the decimal point character is always the period.
setlocale 指定的小數點對浮點常量的語法沒有影響：小數點字元始終是句點。
Unlike integers, not every floating value can be represented directly by decimal or even hexadecimal(since C99) constant syntax: macros NAN and INFINITY as well as functions such as nan offer ways to generate those special values(since C99). Note that `0x1.FFFFFEp128f`, which might appear to be an IEEE float NaN, in fact overflows to an infinity in that format.
與整數不同，並非每個浮點值都可以直接由十進位制甚至十六進位制（自 C99 起）常量語法表示：宏 NAN 和 INFINITY 以及如 nan 的函式提供了生成這些特殊值的方法（自 C99 起）。注意，可能看似 IEEE float NaN 的 0x1.FFFFFEp128f，實際上在該格式中會溢位為無窮大。
There are no negative floating constants; an expression such as `-1.2` is the arithmetic operator unary minus applied to the floating constant `1.2`. Note that the special value negative zero may be constructed with `-0.0`.
沒有負浮點常量；諸如 -1.2 的表示式是將算術運運算元一元減應用於浮點常量 1.2。注意，特殊值負零可以用 -0.0 構造。

### Example

Run this code

```c
#include <stdio.h> int main(void) {  printf("15.0 = %a\n", 15.0);  printf("0x1.ep+3 = %f\n", 0x1.ep+3);  // Constants outside the range of type double.  printf("+2.0e+308 --> %g\n", 2.0e+308);  printf("+1.0e-324 --> %g\n", 1.0e-324);  printf("-1.0e-324 --> %g\n", -1.0e-324);  printf("-2.0e+308 --> %g\n", -2.0e+308); }
```

Output:

```c
15.0 = 0x1.ep+3 0x1.ep+3 = 15.000000 +2.0e+308 --> inf +1.0e-324 --> 0 -1.0e-324 --> -0 -2.0e+308 --> -inf
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 6.4.4.2 Floating constants (p: TBD)
6.4.4.2 浮點常量 (p: TBD)
6.4.4.2 浮點常量 (p: TBD)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.4.4.2 Floating constants (p: 47-48)
6.4.4.2 浮點常量 (p: 47-48)
6.4.4.2 浮點常量 (p: 47-48)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.4.4.2 Floating constants (p: 65-66)
6.4.4.2 浮點常量 (p: 65-66)
6.4.4.2 浮點常量 (p: 65-66)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.4.4.2 Floating constants (p: 57-58)
6.4.4.2 浮點常量 (p: 57-58)
6.4.4.2 浮點常量 (p: 57-58)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.1.3.1 Floating constants
3.1.3.1 浮點常量
3.1.3.1 浮點常量

### See also

C++ documentation for Floating-point literal

---
來源頁路徑：`en.cppreference.com/c/language/floating_constant.html`

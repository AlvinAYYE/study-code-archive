# atof

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdlib.h>`
|   |  |   |  |

```c
double atof( const char* str );
```
|   |   |   |   |

|  |  |  |  |

Interprets a floating-point value in a byte string pointed to by `str`.
解釋由 str 指向的位元組字串中的浮點值。
Function discards any whitespace characters (as determined by isspace) until first non-whitespace character is found. Then it takes as many characters as possible to form a valid floating-point representation and converts them to a floating-point value. The valid floating-point value can be one of the following:
函式丟棄任何空白字元（由 isspace 確定），直到找到第一個非空白字元。然後取儘可能多的字元以構成有效的浮點表示，並將其轉換為浮點值。有效的浮點值可以是以下之一：

- decimal floating-point expression. It consists of the following parts:
十進位制浮點表示式。它由以下部分組成：

- (optional) plus or minus sign
（可選）正號或負號

- nonempty sequence of decimal digits optionally containing decimal-point character (as determined by the current C locale) (defines significand)
非空的十進位制數字序列，可包含小數點字元（由目前 C 本地化環境確定）（定義尾數）

- (optional) `**e**` or `**E**` followed with optional minus or plus sign and nonempty sequence of decimal digits (defines exponent to base 10)
（可選） e 或 E ，後跟可選的負號或正號和非空的十進位制數字序列（定義以 10 為底的指數）
（可選）正號或負號 非空的十進位制數字序列，可包含小數點字元（由目前 C 本地化環境確定）（定義尾數） （可選） e 或 E ，後跟可選的負號或正號和非空的十進位制數字序列（定義以 10 為底的指數）

- hexadecimal floating-point expression. It consists of the following parts:

- (optional) plus or minus sign

- `**0x**` or `**0X**`

- nonempty sequence of hexadecimal digits optionally containing a decimal-point character (as determined by the current C locale) (defines significand)

- (optional) `**p**` or `**P**` followed with optional minus or plus sign and nonempty sequence of decimal digits (defines exponent to base 2)

- infinity expression. It consists of the following parts:

- (optional) plus or minus sign

- `**INF**` or `**INFINITY**` ignoring case

- not-a-number expression. It consists of the following parts:

- (optional) plus or minus sign

- `**NAN**` or `**NAN(**`*char_sequence ﻿*`**)**` ignoring case of the `**NAN**` part. *char_sequence* can only contain digits, Latin letters, and underscores. The result is a quiet NaN floating-point value.
|   | (since C99) |

- any other expression that may be accepted by the currently installed C locale.
目前安裝的 C 本地化環境可能接受的任何其他表示式。

### Parameters

| str  |   | -  |   | pointer to the null-terminated byte string to be interpreted  |

### Return value

`double` value corresponding to the contents of `str` on success. If the converted value falls out of range of the return type, the return value is undefined. If no conversion can be performed, `0.0` is returned.
成功時傳回與 str 內容對應的 double 值。如果轉換後的值超出傳回型別的範圍，則傳回值未定義。如果無法執行轉換，則傳回 0.0 。

### Notes

The name stands for “ASCII to float”.
該名稱代表 "ASCII to float"。

### Example

Run this code

```c
#include <stdio.h> #include <stdlib.h> int main(void) {  printf("%g\n", atof(" -0.0000000123junk"));  printf("%g\n", atof("0.012"));  printf("%g\n", atof("15e16"));  printf("%g\n", atof("-0x1afp-2"));  printf("%g\n", atof("inF"));  printf("%g\n", atof("Nan"));  printf("%g\n", atof("1.0e+309")); // UB: out of range of double  printf("%g\n", atof("0.0"));  printf("%g\n", atof("junk")); // no conversion can be performed }
```

Possible output:
可能的輸出：

```c
-1.23e-08 0.012 1.5e+17 -107.75 inf nan inf 0 0
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.22.1.1 The atof function (p: TBD)
7.22.1.1 atof 函式（頁碼：待定）
7.22.1.1 atof 函式（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.22.1.1 The atof function (p: TBD)
7.22.1.1 atof 函式（頁碼：待定）
7.22.1.1 atof 函式（頁碼：待定）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.22.1.1 The atof function (p: 341)
7.22.1.1 atof 函式（頁碼：341）
7.22.1.1 atof 函式（頁碼：341）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.20.1.1 The atof function (p: 307)
7.20.1.1 atof 函式（頁碼：307）
7.20.1.1 atof 函式（頁碼：307）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.10.1.1 The atof function
4.10.1.1 atof 函式
4.10.1.1 atof 函式

### See also

strtofstrtodstrtold
(C99)(C99)
|   | converts a byte string to a floating-point value
(function)   |

C++ documentation for atof

---
來源頁路徑：`en.cppreference.com/c/string/byte/atof.html`

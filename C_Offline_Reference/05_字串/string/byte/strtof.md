# strtof, strtod, strtold

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdlib.h>`
|   |  |   |  |

```c
float strtof ( const char* restrict str, char** restrict str_end );
```
|   |  (1)  |   |  (since C99)  |

```c
double strtod ( const char* str, char** str_end );
```
|   |  (2) |   | (until C99) |

```c
double strtod ( const char* restrict str, char** restrict str_end );
```
|   |   |   | (since C99) |

```c
long double strtold( const char* restrict str, char** restrict str_end );
```
|   |  (3)  |   |  (since C99)  |

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

The functions sets the pointer pointed to by `str_end` to point to the character past the last character interpreted. If `str_end` is a null pointer, it is ignored.
這些函式將 str_end 指向的指標設定為指向最後一個被解釋字元之後的字元。如果 str_end 為空指標，則忽略它。

### Parameters

| str  |   | -  |   | pointer to the null-terminated byte string to be interpreted  |

| str_end  |   | -  |   | pointer to a pointer to character  |

### Return value

Floating-point value corresponding to the contents of `str` on success. If the converted value falls out of range of corresponding return type, range error occurs (errno is set to ERANGE) and HUGE_VAL, HUGE_VALF or HUGE_VALL is returned. If no conversion can be performed, `0` is returned.
成功時傳回與 str 內容對應的浮點值。如果轉換後的值超出相應傳回型別的範圍，則發生範圍錯誤（ errno 被設定為 ERANGE）並傳回 HUGE_VAL 、HUGE_VALF 或 HUGE_VALL。如果無法執行任何轉換，則傳回 0。

### Example

Run this code

```c
#include <errno.h> #include <stdio.h> #include <stdlib.h> int main(void) {  // parsing with error handling  const char* p = "111.11 -2.22 Nan nan(2) inF 0X1.BC70A3D70A3D7P+6 1.18973e+4932zzz";  printf("Parsing '%s':\n", p);  char* end = NULL;  for (double f = strtod(p, &end); p != end; f = strtod(p, &end))  {  printf("'%.*s' -> ", (int)(end - p), p);  p = end;  if (errno == ERANGE)  {  printf("range error, got ");  errno = 0;  }  printf("%f\n", f);  }  // parsing without error handling  printf("\" -0.0000000123junk\" --> %g\n", strtod(" -0.0000000123junk", NULL));  printf("\"junk\" --> %g\n", strtod("junk", NULL)); }
```

Possible output:
可能的輸出：

```c
Parsing '111.11 -2.22 Nan nan(2) inF 0X1.BC70A3D70A3D7P+6 1.18973e+4932zzz': '111.11' -> 111.110000 ' -2.22' -> -2.220000 ' Nan' -> nan ' nan(2)' -> nan ' inF' -> inf ' 0X1.BC70A3D70A3D7P+6' -> 111.110000 ' 1.18973e+4932' -> range error, got inf " -0.0000000123junk" --> -1.23e-08 "junk" --> 0
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.22.1.3 The strtod, strtof, and strtold functions (p: TBD)
7.22.1.3 strtod、strtof 和 strtold 函式（p: TBD）
7.22.1.3 strtod、strtof 和 strtold 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.22.1.3 The strtod, strtof, and strtold functions (p: 249-251)
7.22.1.3 strtod、strtof 和 strtold 函式（p: 249-251）
7.22.1.3 strtod、strtof 和 strtold 函式（p: 249-251）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.22.1.3 The strtod, strtof, and strtold functions (p: 342-344)
7.22.1.3 strtod、strtof 和 strtold 函式（p: 342-344）
7.22.1.3 strtod、strtof 和 strtold 函式（p: 342-344）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.20.1.3 The strtod, strtof, and strtold functions (p: 308-310)
7.20.1.3 strtod、strtof 和 strtold 函式（p: 308-310）
7.20.1.3 strtod、strtof 和 strtold 函式（p: 308-310）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.10.1.4 The strtod function
4.10.1.4 strtod 函式
4.10.1.4 strtod 函式

### See also

atof
|   | converts a byte string to a floating-point value
(function)   |

wcstofwcstodwcstold
(C99)(C95)(C99)
|   | converts a wide string to a floating-point value
(function)   |

C++ documentation for strtof, strtod, strtold

---
來源頁路徑：`en.cppreference.com/c/string/byte/strtof.html`

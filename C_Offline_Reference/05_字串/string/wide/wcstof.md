# wcstof, wcstod, wcstold

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<wchar.h>`
|   |  |   |  |

```c
float wcstof( const wchar_t* restrict str, wchar_t** restrict str_end );
```
|   |   |   |  (since C99)  |

```c
double wcstod( const wchar_t* str, wchar_t** str_end );
```
|   |   |   | (since C95)
(until C99) |

```c
double wcstod( const wchar_t* restrict str, wchar_t** restrict str_end );
```
|   |   |   | (since C99) |

```c
long double wcstold( const wchar_t* restrict str, wchar_t** restrict str_end );
```
|   |   |   |  (since C99)  |

|  |  |  |  |

Interprets a floating-point value in a wide string pointed to by `str`.
解釋由 str 指向的寬字串中的浮點值。
Function discards any whitespace characters (as determined by iswspace) until first non-whitespace character is found. Then it takes as many characters as possible to form a valid floating-point representation and converts them to a floating-point value. The valid floating-point value can be one of the following:
函式丟棄任何空白字元（由 iswspace 確定），直到找到第一個非空白字元。然後取儘可能多的字元以構成有效的浮點表示，並將其轉換為浮點值。有效的浮點值可以是以下之一：

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

The functions sets the pointer pointed to by `str_end` to point to the wide character past the last character interpreted. If `str_end` is a null pointer, it is ignored.
這些函式將 str_end 指向的指標設定為指向最後一個被解釋字元之後的寬字元。如果 str_end 為空指標，則忽略它。

### Parameters

| str  |   | -  |   | pointer to the null-terminated wide string to be interpreted  |

| str_end  |   | -  |   | pointer to a pointer to a wide character.  |

### Return value

Floating-point value corresponding to the contents of `str` on success. If the converted value falls out of range of corresponding return type, range error occurs and HUGE_VAL, HUGE_VALF or HUGE_VALL is returned. If no conversion can be performed, `0` is returned.
成功時傳回與 str 內容對應的浮點值。如果轉換後的值超出相應傳回型別的範圍，則發生範圍錯誤並傳回 HUGE_VAL 、 HUGE_VALF 或 HUGE_VALL 。如果無法執行轉換，則傳回 0 。

### Example

Run this code

```c
#include <errno.h> #include <stdio.h> #include <wchar.h> int main(void) {  const wchar_t* p = L"111.11 -2.22 0X1.BC70A3D70A3D7P+6 1.18973e+4932zzz";  printf("Parsing L\"%ls\":\n", p);  wchar_t* end;  for (double f = wcstod(p, &end); p != end; f = wcstod(p, &end))  {  printf("'%.*ls' -> ", (int)(end-p), p);  p = end;  if (errno == ERANGE){  printf("range error, got ");  errno = 0;  }  printf("%f\n", f);  } }
```

Output:

```c
Parsing L"111.11 -2.22 0X1.BC70A3D70A3D7P+6 1.18973e+4932zzz": '111.11' -> 111.110000 ' -2.22' -> -2.220000 ' 0X1.BC70A3D70A3D7P+6' -> 111.110000 ' 1.18973e+4932' -> range error, got inf
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.29.4.1.1 The wcstod, wcstof, and wcstold functions (p: TBD)
7.29.4.1.1 wcstod 、 wcstof 和 wcstold 函式（頁碼：待定）
7.29.4.1.1 wcstod 、 wcstof 和 wcstold 函式（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.29.4.1.1 The wcstod, wcstof, and wcstold functions (p: TBD)
7.29.4.1.1 wcstod 、 wcstof 和 wcstold 函式（頁碼：待定）
7.29.4.1.1 wcstod 、 wcstof 和 wcstold 函式（頁碼：待定）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.29.4.1.1 The wcstod, wcstof, and wcstold functions (p: 426-428)
7.29.4.1.1 wcstod 、 wcstof 和 wcstold 函式（頁碼：426-428）
7.29.4.1.1 wcstod 、 wcstof 和 wcstold 函式（頁碼：426-428）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.24.4.1.1 The wcstod, wcstof, and wcstold functions (p: 372-374)
7.24.4.1.1 wcstod 、 wcstof 和 wcstold 函式（頁碼：372-374）
7.24.4.1.1 wcstod 、 wcstof 和 wcstold 函式（頁碼：372-374）

### See also

strtofstrtodstrtold
(C99)(C99)
|   | converts a byte string to a floating-point value
(function)   |

C++ documentation for wcstof, wcstod, wcstold

---
來源頁路徑：`en.cppreference.com/c/string/wide/wcstof.html`

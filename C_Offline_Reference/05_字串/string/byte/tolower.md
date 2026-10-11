# tolower

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<ctype.h>`
|   |  |   |  |

```c
int tolower( int ch );
```
|   |   |   |   |

|  |  |  |  |

Converts the given character to lowercase according to the character conversion rules defined by the currently installed C locale.
根據目前安裝的 C locale 定義的字元轉換規則，將給定字元轉換為小寫。
In the default "C" locale, the following uppercase letters `ABCDEFGHIJKLMNOPQRSTUVWXYZ` are replaced with respective lowercase letters `abcdefghijklmnopqrstuvwxyz`.
在預設的 "C" locale 中，大寫字母 ABCDEFGHIJKLMNOPQRSTUVWXYZ 將被替換為對應的小寫字母 abcdefghijklmnopqrstuvwxyz。

### Parameters

| ch  |   | -  |   | character to be converted. If the value of `ch` is not representable as `unsigned char` and does not equal `EOF`, the behavior is undefined.  |

### Return value

Lowercase version of `ch` or unmodified `ch` if no lowercase version is listed in the current C locale.
ch 的小寫版本；如果目前 C locale 中未列出小寫版本，則傳回未經修改的 ch。

### Example

Run this code

```c
#include <ctype.h> #include <limits.h> #include <locale.h> #include <stdio.h> int main(void) {  // In the default locale  for (unsigned char u = 0; u < UCHAR_MAX; u++)  {  unsigned char l = tolower(u);  if (l != u)  printf("%c%c ", u, l);  }  printf("\n\n");  unsigned char c = '\xb4'; // the character Ž in ISO-8859-15  // but ´ (acute accent) in ISO-8859-1  setlocale(LC_ALL, "en_US.iso88591");  printf("in iso8859-1, tolower('0x%x') gives 0x%x\n", c, tolower(c));  setlocale(LC_ALL, "en_US.iso885915");  printf("in iso8859-15, tolower('0x%x') gives 0x%x\n", c, tolower(c)); }
```

Possible output:
可能的輸出：

```c
Aa Bb Cc Dd Ee Ff Gg Hh Ii Jj Kk Ll Mm Nn Oo Pp Qq Rr Ss Tt Uu Vv Ww Xx Yy Zz in iso8859-1, tolower('0xb4') gives 0xb4 in iso8859-15, tolower('0xb4') gives 0xb8
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.4.2.1 The tolower function (p: TBD)
7.4.2.1 tolower 函式（p: TBD）
7.4.2.1 tolower 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.4.2.1 The tolower function (p: 147)
7.4.2.1 tolower 函式（p: 147）
7.4.2.1 tolower 函式（p: 147）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.4.2.1 The tolower function (p: 203)
7.4.2.1 tolower 函式（p: 203）
7.4.2.1 tolower 函式（p: 203）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.4.2.1 The tolower function (p: 184)
7.4.2.1 tolower 函式（p: 184）
7.4.2.1 tolower 函式（p: 184）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.3.2.1 The tolower function
4.3.2.1 tolower 函式
4.3.2.1 tolower 函式

### See also

toupper
|   | converts a character to uppercase
(function)   |

towlower
(C95)
|   | converts a wide character to lowercase
(function)   |

C++ documentation for tolower

---
來源頁路徑：`en.cppreference.com/c/string/byte/tolower.html`

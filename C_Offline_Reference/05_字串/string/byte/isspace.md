# isspace

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<ctype.h>`
|   |  |   |  |

```c
int isspace( int ch );
```
|   |   |   |   |

|  |  |  |  |

Checks if the given character is either
檢查字元 ch 是否為目前 C 地區設定中的空白字元。

- A standard white-space character:
在預設的 C 地區設定中，空白字元包括：

- Space (`0x20`, `' '`),
空格（ 0x20 、 ' ' ），

- Form feed (`0x0c`, `'\f'`),
換頁（ 0x0c 、 '\f' ），

- Line feed (`0x0a`, `'\n'`),
換行（ 0x0a 、 '\n' ），

- Carriage return (`0x0d`, `'\r'`),
回車（ 0x0d 、 '\r' ），

- Horizontal tab (`0x09`, `'\t'`),
水平製表（ 0x09 、 '\t' ），

- Vertical tab (`0x0b`, `'\v'`),
垂直製表（ 0x0b 、 '\v' ），
空格（ 0x20 、 ' ' ）、換頁（ 0x0c 、 '\f' ）、換行（ 0x0a 、 '\n' ）、回車（ 0x0d 、 '\r' ）、水平製表（ 0x09 、 '\t' ）、垂直製表（ 0x0b 、 '\v' ），

- Or a locale-specific white-space character.
或特定於本地化環境的空白字元。

The behavior is undefined if the value of `ch` is not representable as `unsigned char` and is not equal to EOF.
若 ch 的值無法由 unsigned char 表示，且也不等於 EOF，行為未定義。

### Parameters

| ch  |   | -  |   | character to classify  |

### Return value

Non-zero value if the character is a whitespace character, zero otherwise.
如果字元是空白字元則傳回非零值，否則傳回零。

### Example

Run this code

```c
#include <ctype.h> #include <limits.h> #include <stdio.h>   int main(void) {  for (int ndx = 0; ndx <= UCHAR_MAX; ++ndx)  if (isspace(ndx))  printf("0x%02x ", ndx); }
```

Output:

```c
0x09 0x0a 0x0b 0x0c 0x0d 0x20
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.4.1.10 The isspace function (p: TBD)
7.4.1.10 isspace 函式（頁碼：待定）
7.4.1.10 isspace 函式（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.4.1.10 The isspace function (p: 147)
7.4.1.10 isspace 函式（頁碼：147）
7.4.1.10 isspace 函式（頁碼：147）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.4.1.10 The isspace function (p: 202-203)
7.4.1.10 isspace 函式（頁碼：202-203）
7.4.1.10 isspace 函式（頁碼：202-203）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.4.1.10 The isspace function (p: 183-184)
7.4.1.10 isspace 函式（頁碼：183-184）
7.4.1.10 isspace 函式（頁碼：183-184）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.3.1.9 The isspace function
4.3.1.9 isspace 函式
4.3.1.9 isspace 函式

### See also

iswspace
(C95)
|   | checks if a wide character is a space character
(function)   |

C++ documentation for isspace

| ASCII values  |   | characters  |   |
iscntrl
iswcntrl
|   |
isprint
iswprint
|   |
isspace
iswspace
|   |
isblank
iswblank
|   |
isgraph
iswgraph
|   |
ispunct
iswpunct
|   |
isalnum
iswalnum
|   |
isalpha
iswalpha
|   |
isupper
iswupper
|   |
islower
iswlower
|   |
isdigit
iswdigit
|   |
isxdigit
iswxdigit

| decimal  |   | hexadecimal  |   | octal  |

| 0–8  |   | `\x0`–`\x8`  |   | `\0`–`\10`  |   | control codes (`NUL`, etc.)  |   | **`≠0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |

| 9  |   | `\x9`  |   | `\11`  |   | tab (`\t`)  |   | **`≠0`**  |   | **`0`**  |   | **`≠0`**  |   | **`≠0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |

| 10–13  |   | `\xA`–`\xD`  |   | `\12`–`\15`  |   | whitespaces (`\n`, `\v`, `\f`, `\r`)  |   | **`≠0`**  |   | **`0`**  |   | **`≠0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |

| 14–31  |   | `\xE`–`\x1F`  |   | `\16`–`\37`  |   | control codes  |   | **`≠0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |

| 32  |   | `\x20`  |   | `\40`  |   | space  |   | **`0`**  |   | **`≠0`**  |   | **`≠0`**  |   | **`≠0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |

| 33–47  |   | `\x21`–`\x2F`  |   | `\41`–`\57`  |   | `!"#$%&'()*+,-./`  |   | **`0`**  |   | **`≠0`**  |   | **`0`**  |   | **`0`**  |   | **`≠0`**  |   | **`≠0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |

| 48–57  |   | `\x30`–`\x39`  |   | `\60`–`\71`  |   | `0123456789`  |   | **`0`**  |   | **`≠0`**  |   | **`0`**  |   | **`0`**  |   | **`≠0`**  |   | **`0`**  |   | **`≠0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`≠0`**  |   | **`≠0`**  |

| 58–64  |   | `\x3A`–`\x40`  |   | `\72`–`\100`  |   | `:;<=>?@`  |   | **`0`**  |   | **`≠0`**  |   | **`0`**  |   | **`0`**  |   | **`≠0`**  |   | **`≠0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |

| 65–70  |   | `\x41`–`\x46`  |   | `\101`–`\106`  |   | `ABCDEF`  |   | **`0`**  |   | **`≠0`**  |   | **`0`**  |   | **`0`**  |   | **`≠0`**  |   | **`0`**  |   | **`≠0`**  |   | **`≠0`**  |   | **`≠0`**  |   | **`0`**  |   | **`0`**  |   | **`≠0`**  |

| 71–90  |   | `\x47`–`\x5A`  |   | `\107`–`\132`  |   | `GHIJKLMNOP`
`QRSTUVWXYZ`  |   | **`0`**  |   | **`≠0`**  |   | **`0`**  |   | **`0`**  |   | **`≠0`**  |   | **`0`**  |   | **`≠0`**  |   | **`≠0`**  |   | **`≠0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |

| 91–96  |   | `\x5B`–`\x60`  |   | `\133`–`\140`  |   | `[\]^_``  |   | **`0`**  |   | **`≠0`**  |   | **`0`**  |   | **`0`**  |   | **`≠0`**  |   | **`≠0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |

| 97–102  |   | `\x61`–`\x66`  |   | `\141`–`\146`  |   | `abcdef`  |   | **`0`**  |   | **`≠0`**  |   | **`0`**  |   | **`0`**  |   | **`≠0`**  |   | **`0`**  |   | **`≠0`**  |   | **`≠0`**  |   | **`0`**  |   | **`≠0`**  |   | **`0`**  |   | **`≠0`**  |

| 103–122  |   | `\x67`–`\x7A`  |   | `\147`–`\172`  |   | `ghijklmnop`
`qrstuvwxyz`  |   | **`0`**  |   | **`≠0`**  |   | **`0`**  |   | **`0`**  |   | **`≠0`**  |   | **`0`**  |   | **`≠0`**  |   | **`≠0`**  |   | **`0`**  |   | **`≠0`**  |   | **`0`**  |   | **`0`**  |

| 123–126  |   | `\x7B`–`\x7E`  |   | `\173`–`\176`  |   | `{|}~`  |   | **`0`**  |   | **`≠0`**  |   | **`0`**  |   | **`0`**  |   | **`≠0`**  |   | **`≠0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |

| 127  |   | `\x7F`  |   | `\177`  |   | backspace character (`DEL`)  |   | **`≠0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |   | **`0`**  |

---
來源頁路徑：`en.cppreference.com/c/string/byte/isspace.html`

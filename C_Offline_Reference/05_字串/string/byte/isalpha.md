# isalpha

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<ctype.h>`
|   |  |   |  |

```c
int isalpha( int ch );
```
|   |   |   |   |

|  |  |  |  |

Checks if the given character is an alphabetic character, i.e. either an uppercase letter (`ABCDEFGHIJKLMNOPQRSTUVWXYZ`), or a lowercase letter (`abcdefghijklmnopqrstuvwxyz`).
檢查 `ch` 是否為字母。在預設的 `"C"` 地區設定中，只有英文字母 `A–Z` 和 `a–z` 符合。
In locales other than `"C"`, an alphabetic character is a character for which isupper() or islower() returns `true` or any other character considered alphabetic by the locale. In any case, iscntrl(), isdigit(), ispunct() and isspace() will return `false` for this character.
在 `"C"` 以外的地區設定中，字母還包括該地區設定認定的其他字元。`isalpha` 判定為真的字元，也會讓 `isupper` 或 `islower` 回傳非零值；`iscntrl`、`isdigit`、`ispunct` 和 `isspace` 則都會回傳 0。
The behavior is undefined if the value of `ch` is not representable as `unsigned char` and is not equal to `EOF`.
若 ch 的值無法由 unsigned char 表示，且也不等於 EOF，行為未定義。

### Parameters

| ch  |   | -  |   | character to classify  |

### Return value

Non-zero value if the character is an alphabetic character, zero otherwise.
如果字元是字母字元則傳回非零值，否則傳回零。

### Example

Demonstrates the use of `isalpha` with different locales (OS-specific).
演示 isalpha 在不同本地化環境中的用法（特定於作業系統）。
Run this code

```c
#include <ctype.h> #include <locale.h> #include <stdio.h> int main(void) {  unsigned char c = '\xdf'; // German letter ß in ISO-8859-1    printf("isalpha('\\xdf') in default C locale returned %d\n", !!isalpha(c));    setlocale(LC_CTYPE, "de_DE.iso88591");  printf("isalpha('\\xdf') in ISO-8859-1 locale returned %d\n", !!isalpha(c)); }
```

Possible output:
可能的輸出：

```c
isalpha('\xdf') in default C locale returned 0 isalpha('\xdf') in ISO-8859-1 locale returned 1
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.4.1.2 The isalpha function (p: TBD)
7.4.1.2 isalpha 函式（頁碼：待定）
7.4.1.2 isalpha 函式（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.4.1.2 The isalpha function (p: 145)
7.4.1.2 isalpha 函式（頁碼：145）
7.4.1.2 isalpha 函式（頁碼：145）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.4.1.2 The isalpha function (p: 200-201)
7.4.1.2 isalpha 函式（頁碼：200-201）
7.4.1.2 isalpha 函式（頁碼：200-201）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.4.1.2 The isalpha function (p: 181-182)
7.4.1.2 isalpha 函式（頁碼：181-182）
7.4.1.2 isalpha 函式（頁碼：181-182）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.3.1.2 The isalpha function
4.3.1.2 isalpha 函式
4.3.1.2 isalpha 函式

### See also

iswalpha
(C95)
|   | checks if a wide character is alphabetic
(function)   |

C++ documentation for isalpha

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
來源頁路徑：`en.cppreference.com/c/string/byte/isalpha.html`

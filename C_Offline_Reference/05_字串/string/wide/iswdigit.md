# iswdigit

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<wctype.h>`
|   |  |   |  |

```c
int iswdigit( wint_t ch );
```
|   |   |   |  (since C95)  |

|  |  |  |  |

Checks if the given wide character corresponds (if narrowed) to one of the ten decimal digit characters `0123456789`.
檢查給定的寬字元（如果收窄）是否對應於十個十進位制數字字元 01234567 89 之一。

### Parameters

| ch  |   | -  |   | wide character  |

### Return value

Non-zero value if the wide character is a numeric character, zero otherwise.
如果寬字元是數字字元則傳回非零值，否則傳回零。

### Notes

`iswdigit` and iswxdigit are the only standard wide character classification functions that are not affected by the currently installed C locale.
iswdigit 和 iswxdigit 是僅有的不受目前安裝的 C 本地化環境影響的標準寬字元分類函式。

### Example

Some locales offer additional character classes that detect non-ASCII digits
一些本地化環境提供額外的字元類以檢測非 ASCII 數字
Run this code

```c
#include <locale.h> #include <stdio.h> #include <wchar.h> #include <wctype.h> void test(wchar_t a3, wchar_t u3, wchar_t j3) {  printf("\t '%lc' '%lc' '%lc'\n", a3, u3, j3);  printf("iswdigit: %d %d %d\n",  !!iswdigit(a3),  !!iswdigit(u3),  !!iswdigit(j3));  printf("jdigit: %d %d %d\n",  !!iswctype(a3, wctype("jdigit")),  !!iswctype(u3, wctype("jdigit")),  !!iswctype(j3, wctype("jdigit"))); } int main(void) {  wchar_t a3 = L'3'; // the ASCII digit 3  wchar_t u3 = L'三'; // the CJK numeral 3  wchar_t j3 = L'３'; // the full-width digit 3  setlocale(LC_ALL, "en_US.utf8");  puts("In American locale:");  test(a3, u3, j3);  setlocale(LC_ALL, "ja_JP.utf8");  puts("\nIn Japanese locale:");  test(a3, u3, j3); }
```

Possible output:
可能的輸出：

```c
In American locale: '3' '三' '３' iswdigit: 1 0 0 jdigit: 0 0 0 In Japanese locale: '3' '三' '３' iswdigit: 1 0 0 jdigit: 0 0 1
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- TBD 7.30.2.1.5 The iswdigit function (p: TBD)
待定 7.30.2.1.5 iswdigit 函式（頁碼：待定）
待定 7.30.2.1.5 iswdigit 函式（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.30.2.1.5 The iswdigit function (p: 327)
7.30.2.1.5 iswdigit 函式（頁碼：327）
7.30.2.1.5 iswdigit 函式（頁碼：327）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.30.2.1.5 The iswdigit function (p: 449)
7.30.2.1.5 iswdigit 函式（頁碼：449）
7.30.2.1.5 iswdigit 函式（頁碼：449）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.25.2.1.5 The iswdigit function (p: 395)
7.25.2.1.5 iswdigit 函式（頁碼：395）
7.25.2.1.5 iswdigit 函式（頁碼：395）

### See also

isdigit
|   | checks if a character is a digit
(function)   |

C++ documentation for iswdigit

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
來源頁路徑：`en.cppreference.com/c/string/wide/iswdigit.html`

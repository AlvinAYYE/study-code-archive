# LC_ALL, LC_COLLATE, LC_CTYPE, LC_MONETARY, LC_NUMERIC, LC_TIME

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<locale.h>`
|   |  |   |  |

```c
#define LC_ALL /* implementation-defined */
```
|   |   |   |   |

```c
#define LC_COLLATE /* implementation-defined */
```
|   |   |   |   |

```c
#define LC_CTYPE /* implementation-defined */
```
|   |   |   |   |

```c
#define LC_MONETARY /* implementation-defined */
```
|   |   |   |   |

```c
#define LC_NUMERIC /* implementation-defined */
```
|   |   |   |   |

```c
#define LC_TIME /* implementation-defined */
```
|   |   |   |   |

|  |  |  |  |

Each of the above macro constants expand to integer constant expressions with distinct values that are suitable for use as the first argument of setlocale.
上面每個宏常量都展開為值互不相同的整數常量表示式，適合作為 setlocale 的第一個實參使用。

| Constant  |   | Explanation  |

| `LC_ALL`  |   | selects the entire C locale  |

| `LC_COLLATE`  |   | selects the collation category of the C locale  |

| `LC_CTYPE`  |   | selects the character classification category of the C locale  |

| `LC_MONETARY`  |   | selects the monetary formatting category of the C locale  |

| `LC_NUMERIC`  |   | selects the numeric formatting category of the C locale  |

| `LC_TIME`  |   | selects the time formatting category of the C locale  |

Additional macro constants, with names that begin with `LC_` followed by at least one uppercase letter, may be defined in `locale.h`. For example, the POSIX specification requires `LC_MESSAGES` (which controls, among other things, perror and strerror), ISO/IEC 30112:2014 (2014 draft) additionally defines `LC_IDENTIFICATION`, `LC_XLITERATE`, `LC_NAME`, `LC_ADDRESS`, `LC_TELEPHONE`, `LC_PAPER`, `LC_MEASUREMENT`, and `LC_KEYBOARD`, which are supported by the GNU C library (except for `LC_XLITERATE`).
在 locale.h 中還可以定義其他宏常量，其名稱以 LC_ 開頭，後跟至少一個大寫字母。例如，POSIX 規範要求 LC_MESSAGES（除其他內容外，它控制 perror 和 strerror），ISO/IEC 30112:2014 ( 2014 草案 ) 另外定義了 LC_IDENTIFICATION、LC_XLITERATE、LC_NAME、LC_ADDRESS、LC_TELEPHONE、LC_PAPER、LC_MEASUREMENT 和 LC_KEYBOARD，GNU C 庫支援這些宏（LC_XLITERATE 除外）。

### Example

Run this code

```c
#include <locale.h> #include <stdio.h> #include <time.h> #include <wchar.h>   int main(void) {  setlocale(LC_ALL, "en_US.UTF-8"); // the C locale will be the UTF-8 enabled English  setlocale(LC_NUMERIC, "de_DE.utf8"); // decimal dot will be German  setlocale(LC_TIME, "ja_JP.utf8"); // date/time formatting will be Japanese  wchar_t str[100];  time_t t = time(NULL);  wcsftime(str, 100, L"%A %c", localtime(&t));  wprintf(L"Number: %.2f\nDate: %Ls\n", 3.14, str); }
```

Possible output:
可能的輸出：

```c
Number: 3,14 Date: 金曜日 2023年09月15日 20時04分14秒
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.11/3 Localization <locale.h> (p: TBD)
7.11/3 本地化 <locale.h> (p: 待定)
7.11/3 本地化 <locale.h> (p: 待定)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.11/3 Localization <locale.h> (p: TBD)
7.11/3 本地化 <locale.h> (p: 待定)
7.11/3 本地化 <locale.h> (p: 待定)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.11/3 Localization <locale.h> (p: 224)
7.11/3 本地化 <locale.h> (p: 224)
7.11/3 本地化 <locale.h> (p: 224)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.11/3 Localization <locale.h> (p: 205)
7.11/3 本地化 <locale.h> (p: 205)
7.11/3 本地化 <locale.h> (p: 205)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.4 LOCALIZATION <locale.h>
4.4 本地化 <locale.h>
4.4 本地化 <locale.h>

### See also

setlocale
|   | gets and sets the current C locale
(function)   |

C++ documentation for locale categories

---
來源頁路徑：`en.cppreference.com/c/locale/LC_categories.html`

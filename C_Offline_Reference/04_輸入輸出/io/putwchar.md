# putwchar

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<wchar.h>`
|   |  |   |  |

```c
wint_t putwchar( wchar_t ch );
```
|   |   |   |  (since C95)  |

|  |  |  |  |

Writes a wide character `ch` to `stdout`.
將寬字元 ch 寫入 stdout 。

### Parameters

| ch  |   | -  |   | wide character to be written  |

### Return value

`ch` on success, WEOF on failure.
成功時為 ch ，失敗時為 WEOF。

### Example

Run this code

```c
#include <locale.h> #include <stdio.h> #include <stdlib.h> #include <wchar.h>   int main() {  setlocale(LC_ALL, "en_US.utf8");  const wchar_t data[] =  {  L'\u2200', // Unicode name: "FOR ALL"  L'∀',  L'\n',  };  for (size_t t = 0; t != (sizeof data / sizeof(wchar_t)); ++t)  {  if (putwchar(data[t]) == WEOF)  {  puts("I/O error in putwchar");  return EXIT_FAILURE;  }  }  return EXIT_SUCCESS; }
```

Possible output:
可能的輸出：

```c
∀∀
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.31.3.9 The putwchar function (p: TBD)
7.31.3.9 putwchar 函式（p: TBD）
7.31.3.9 putwchar 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.29.3.9 The putwchar function (p: 310)
7.29.3.9 putwchar 函式（p: 310）
7.29.3.9 putwchar 函式（p: 310）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.29.3.9 The putwchar function (p: 425)
7.29.3.9 putwchar 函式（p: 425）
7.29.3.9 putwchar 函式（p: 425）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.24.3.9 The putwchar function (p: 370)
7.24.3.9 putwchar 函式（p: 370）
7.24.3.9 putwchar 函式（p: 370）

### See also

putchar
|   | writes a character to stdout
(function)   |

fputwcputwc
(C95)
|   | writes a wide character to a file stream
(function)   |

C++ documentation for putwchar

---
來源頁路徑：`en.cppreference.com/c/io/putwchar.html`

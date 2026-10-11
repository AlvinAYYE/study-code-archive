# fputwc, putwc

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<wchar.h>`
|   |  |   |  |

```c
wint_t fputwc( wchar_t ch, FILE* stream );
```
|   |  (1)  |   |  (since C95)  |

```c
wint_t putwc( wchar_t ch, FILE* stream );
```
|   |  (2)  |   |  (since C95)  |

|  |  |  |  |

Writes a wide character `ch` to the given output stream `stream`.
將寬字元 ch 寫入給定的輸出流 stream 。

2) May be implemented as a macro and may evaluate `stream` more than once.

### Parameters

| ch  |   | -  |   | wide character to be written  |

| stream  |   | -  |   | the output stream  |

### Return value

Returns a copy of `ch` on success.
成功時傳回 ch 的副本。
On failure, returns WEOF and sets the *error* indicator (see ferror()) on `stream`.
失敗時，傳回 WEOF 並在 stream 上設定錯誤指示器（參見 ferror() ）。
If an encoding error occurred, additionally sets errno to EILSEQ.
如果發生編碼錯誤，還會額外將 errno 設定為 EILSEQ 。

### Example

Run this code

```c
#include <errno.h> #include <locale.h> #include <stdio.h> #include <stdlib.h> #include <wchar.h> int main(void) {  setlocale(LC_ALL, "en_US.utf8");  errno = 0;  if (fputwc(L'🍌', stdout) == WEOF)  {  if (errno == EILSEQ)  puts("Encoding error in fputwc.");  else  puts("I/O error in fputwc.");  return EXIT_FAILURE;  } }
```

Possible output:
可能的輸出：

```c
🍌
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.31.3.3 The fputwc function (p: 430)
7.31.3.3 fputwc 函式（頁碼：430）
7.31.3.3 fputwc 函式（頁碼：430）

- 7.31.3.8 The putwc function (p: 431-432)
7.31.3.8 putwc 函式（頁碼：431-432）
7.31.3.8 putwc 函式（頁碼：431-432）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.29.3.3 The fputwc function (p: 308)
7.29.3.3 fputwc 函式（頁碼：308）
7.29.3.3 fputwc 函式（頁碼：308）

- 7.29.3.8 The putwc function (p: 310)
7.29.3.8 putwc 函式（頁碼：310）
7.29.3.8 putwc 函式（頁碼：310）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.29.3.3 The fputwc function (p: 422-423)
7.29.3.3 fputwc 函式（頁碼：422-423）
7.29.3.3 fputwc 函式（頁碼：422-423）

- 7.29.3.8 The putwc function (p: 424)
7.29.3.8 putwc 函式（頁碼：424）
7.29.3.8 putwc 函式（頁碼：424）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.24.3.3 The fputwc function (p: 368)
7.24.3.3 fputwc 函式（頁碼：368）
7.24.3.3 fputwc 函式（頁碼：368）

- 7.24.3.8 The putwc function (p: 370)
7.24.3.8 putwc 函式（頁碼：370）
7.24.3.8 putwc 函式（頁碼：370）

### See also

fputcputc
|   | writes a character to a file stream
(function)   |

fputws
(C95)
|   | writes a wide string to a file stream
(function)   |

fgetwcgetwc
(C95)
|   | gets a wide character from a file stream
(function)   |

C++ documentation for fputwc

---
來源頁路徑：`en.cppreference.com/c/io/fputwc.html`

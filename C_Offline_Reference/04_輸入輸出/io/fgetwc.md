# fgetwc, getwc

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<wchar.h>`
|   |  |   |  |

```c
wint_t fgetwc( FILE* stream );
```
|   |   |   | (since C95) |

```c
wint_t getwc( FILE* stream );
```
|   |   |   | (since C95) |

|  |  |  |  |

Reads the next wide character from the given input stream. `getwc()` may be implemented as a macro and may evaluate `stream` more than once.
從給定輸入流讀取下一個寬字元。getwc() 可能被實現為宏，且可能對 stream 求值多次。

### Parameters

| stream  |   | -  |   | to read the wide character from  |

### Return value

The next wide character from the stream or `WEOF` on failure.
流中的下一個寬字元，失敗時傳回 WEOF。
If the failure has been caused by end-of-file condition, additionally sets the *eof* indicator (see feof()) on `stream`. If the failure has been caused by some other error, sets the *error* indicator (see ferror()) on `stream`.
如果失敗由檔案結束條件引起，還會在 stream 上設定 eof 指示器（參見 feof() ）。如果失敗由其他錯誤引起，則在 stream 上設定錯誤指示器（參見 ferror() ）。
If an encoding error occurred, additionally sets errno to `EILSEQ`.
如果發生編碼錯誤，還會額外將 errno 設定為 EILSEQ 。

### Example

Run this code

```c
#include <errno.h> #include <locale.h> #include <stdio.h> #include <stdlib.h> #include <wchar.h> int main(void) {  setlocale(LC_ALL, "en_US.utf8");  FILE* fp = fopen("fgetwc.dat", "w");  if(!fp)  {  perror("Can't open file for writing");  return EXIT_FAILURE;  }  fputs("кот\n", fp);  fclose(fp);  fp = fopen("fgetwc.dat", "r");  if (!fp)  {  perror("Can't open file for reading");  return EXIT_FAILURE;  }  wint_t wc;  errno = 0;  while ((wc = fgetwc(fp)) != WEOF)  putwchar(wc);  if (ferror(fp))  {  if (errno == EILSEQ)  puts("Character encoding error while reading.");  else  puts("I/O error when reading");  }  else if (feof(fp))  puts("End of file reached successfully");  fclose(fp); }
```

Possible output:
可能的輸出：

```c
кот
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.29.3.1 The fgetwc function (p: TBD)
7.29.3.1 fgetwc 函式（頁碼：待定）
7.29.3.1 fgetwc 函式（頁碼：待定）

- 7.29.3.6 The getwc function (p: TBD)
7.29.3.6 getwc 函式（頁碼：待定）
7.29.3.6 getwc 函式（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.29.3.1 The fgetwc function (p: 307-308)
7.29.3.1 fgetwc 函式（頁碼：307-308）
7.29.3.1 fgetwc 函式（頁碼：307-308）

- 7.29.3.6 The getwc function (p: 309)
7.29.3.6 getwc 函式（頁碼：309）
7.29.3.6 getwc 函式（頁碼：309）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.29.3.1 The fgetwc function (p: 421-422)
7.29.3.1 fgetwc 函式（頁碼：421-422）
7.29.3.1 fgetwc 函式（頁碼：421-422）

- 7.29.3.6 The getwc function (p: 424)
7.29.3.6 getwc 函式（頁碼：424）
7.29.3.6 getwc 函式（頁碼：424）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.24.3.1 The fgetwc function (p: 367)
7.24.3.1 fgetwc 函式（頁碼：367）
7.24.3.1 fgetwc 函式（頁碼：367）

- 7.24.3.6 The getwc function (p: 369)
7.24.3.6 getwc 函式（頁碼：369）
7.24.3.6 getwc 函式（頁碼：369）

### See also

fgetcgetc
|   | gets a character from a file stream
(function)   |

fgetws
(C95)
|   | gets a wide string from a file stream
(function)   |

fputwcputwc
(C95)
|   | writes a wide character to a file stream
(function)   |

ungetwc
(C95)
|   | puts a wide character back into a file stream
(function)   |

C++ documentation for fgetwc

---
來源頁路徑：`en.cppreference.com/c/io/fgetwc.html`

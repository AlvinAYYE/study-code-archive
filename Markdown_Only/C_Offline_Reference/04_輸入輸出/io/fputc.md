# fputc, putc

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdio.h>`
|   |  |   |  |

```c
int fputc( int ch, FILE* stream );
```
|   |   |   |  |

```c
int putc( int ch, FILE* stream );
```
|   |   |   |  |

|  |  |  |  |

Writes a character `ch` to the given output stream `stream`. `putc()` may be implemented as a macro and evaluate `stream` more than once, so the corresponding argument should never be an expression with side effects.
將字元 ch 寫入輸出串流 stream。putc() 可能以巨集實作，且可能多次求值 stream，因此傳入 putc() 的 stream 不應包含副作用。
Internally, the character is converted to `unsigned char` just before being written.
實際寫入前，ch 會先轉換成 unsigned char。

### Parameters

| ch  |   | -  |   | character to be written  |

| stream  |   | -  |   | output stream  |

### Return value

On success, returns the written character.
成功時傳回寫入的字元。
On failure, returns EOF and sets the *error* indicator (see ferror()) on `stream`.
失敗時傳回 EOF，並在 stream 設定錯誤指示器（參見 ferror()）。

### Example

Shows `putc` with error checking
展示帶錯誤檢查的 putc
Run this code

```c
#include <stdio.h> #include <stdlib.h> int main(void) {  int ret_code = 0;  for (char c = 'a'; (ret_code != EOF) && (c != 'z'); c++)  ret_code = putc(c, stdout);  // Test whether EOF was reached.  if (ret_code == EOF && ferror(stdout))  {  perror("putc()");  fprintf(stderr, "putc() failed in file %s at line # %d\n",  __FILE__, __LINE__ - 7);  exit(EXIT_FAILURE);  }  putc('\n', stdout);  return EXIT_SUCCESS; }
```

Output:

```c
abcdefghijklmnopqrstuvwxy
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.21.7.3 The fputc function (p: TBD)
7.21.7.3 fputc 函式（頁：TBD）
7.21.7.3 fputc 函式（頁：TBD）

- 7.21.7.7 The putc function (p: TBD)
7.21.7.7 putc 函式（頁：TBD）
7.21.7.7 putc 函式（頁：TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.21.7.3 The fputc function (p: TBD)
7.21.7.3 fputc 函式（頁：TBD）
7.21.7.3 fputc 函式（頁：TBD）

- 7.21.7.7 The putc function (p: TBD)
7.21.7.7 putc 函式（頁：TBD）
7.21.7.7 putc 函式（頁：TBD）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.21.7.3 The fputc function (p: 331)
7.21.7.3 fputc 函式（頁：331）
7.21.7.3 fputc 函式（頁：331）

- 7.21.7.7 The putc function (p: 333)
7.21.7.7 putc 函式（頁：333）
7.21.7.7 putc 函式（頁：333）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.19.7.3 The fputc function (p: 297)
7.19.7.3 fputc 函式（頁：297）
7.19.7.3 fputc 函式（頁：297）

- 7.19.7.8 The putc function (p: 299)
7.19.7.8 putc 函式（頁：299）
7.19.7.8 putc 函式（頁：299）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.9.7.3 The fputc function
4.9.7.3 fputc 函式
4.9.7.3 fputc 函式

- 4.9.7.8 The putc function
4.9.7.8 putc 函式
4.9.7.8 putc 函式

### See also

putchar
|   | writes a character to stdout
(function)   |

C++ documentation for fputc, putc

---
來源頁路徑：`en.cppreference.com/c/io/fputc.html`

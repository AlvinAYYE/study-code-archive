# fgetc, getc

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdio.h>`
|   |  |   |  |

```c
int fgetc( FILE* stream );
```
|   |  (1)  |   |   |

```c
int getc( FILE* stream );
```
|   |  (2)  |   |   |

|  |  |  |  |

1) Reads the next character from the given input stream.

2) Same as `fgetc`, except that if `getc` is implemented as a macro, it may evaluate stream more than once, so the corresponding argument should never be an expression with side effects.

### Parameters

| stream  |   | -  |   | to read the character from  |

### Return value

On success, returns the obtained character as an `unsigned char` converted to an `int`. On failure, returns EOF.
成功時，傳回讀取到的字元，型別為轉換成 int 的 unsigned char。 失敗時傳回 EOF。
If the failure has been caused by end-of-file condition, additionally sets the *eof* indicator (see feof()) on `stream`. If the failure has been caused by some other error, sets the *error* indicator (see ferror()) on `stream`.
若因到達檔案結尾而失敗，會在 stream 設定檔案結尾指示器（參見 feof()）；若因其他錯誤而失敗，則會設定錯誤指示器（參見 ferror()）。

### Example

Run this code

```c
#include <stdio.h> #include <stdlib.h> int main(void) {  const char* fname = "/tmp/unique_name.txt"; // or tmpnam(NULL);  int is_ok = EXIT_FAILURE;  FILE* fp = fopen(fname, "w+");  if (!fp)  {  perror("File opening failed");  return is_ok;  }  fputs("Hello, world!\n", fp);  rewind(fp);  int c; // note: int, not char, required to handle EOF  while ((c = fgetc(fp)) != EOF) // standard C I/O file reading loop  putchar(c);  if (ferror(fp))  puts("I/O error when reading");  else if (feof(fp))  {  puts("End of file is reached successfully");  is_ok = EXIT_SUCCESS;  }  fclose(fp);  remove(fname);  return is_ok; }
```

Possible output:
可能的輸出：

```c
Hello, world! End of file is reached successfully
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.21.7.1 The fgetc function (p: TBD)
7.21.7.1 fgetc 函式（頁：TBD）
7.21.7.1 fgetc 函式（頁：TBD）

- 7.21.7.5 The getc function (p: TBD)
7.21.7.5 getc 函式（頁：TBD）
7.21.7.5 getc 函式（頁：TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.21.7.1 The fgetc function (p: 240-241)
7.21.7.1 fgetc 函式（頁：240-241）
7.21.7.1 fgetc 函式（頁：240-241）

- 7.21.7.5 The getc function (p: 242)
7.21.7.5 getc 函式（頁：242）
7.21.7.5 getc 函式（頁：242）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.21.7.1 The fgetc function (p: 330)
7.21.7.1 fgetc 函式（頁：330）
7.21.7.1 fgetc 函式（頁：330）

- 7.21.7.5 The getc function (p: 332)
7.21.7.5 getc 函式（頁：332）
7.21.7.5 getc 函式（頁：332）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.19.7.1 The fgetc function (p: 296)
7.19.7.1 fgetc 函式（頁：296）
7.19.7.1 fgetc 函式（頁：296）

- 7.19.7.5 The getc function (p: 297-298)
7.19.7.5 getc 函式（頁：297-298）
7.19.7.5 getc 函式（頁：297-298）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.9.7.1 The fgetc function
4.9.7.1 fgetc 函式
4.9.7.1 fgetc 函式

- 4.9.7.5 The getc function
4.9.7.5 getc 函式
4.9.7.5 getc 函式

### See also

getchar
|   | reads a character from stdin
(function)   |

getsgets_s
(removed in C11)(C11)
|   | reads a character string from stdin
(function)   |

fputcputc
|   | writes a character to a file stream
(function)   |

ungetc
|   | puts a character back into a file stream
(function)   |

C++ documentation for fgetc, getc

---
來源頁路徑：`en.cppreference.com/c/io/fgetc.html`

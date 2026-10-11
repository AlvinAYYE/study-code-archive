# clearerr

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdio.h>`
|   |  |   |  |

```c
void clearerr( FILE *stream );
```
|   |   |   |   |

|  |  |  |  |

Resets the error flags and the `EOF` indicator for the given file stream.
重置給定檔案流的錯誤標誌和 EOF 指示器。

### Parameters

| stream  |   | -  |   | the file to reset the error flags for  |

### Return value

(none)

### Example

Run this code

```c
#include <stdio.h> #include <assert.h>   int main(void) {  FILE* tmpf = tmpfile();  fputs("cppreference.com\n", tmpf);  rewind(tmpf);  for (int ch; (ch = fgetc(tmpf)) != EOF; putchar(ch)) { }    assert(feof(tmpf)); // the loop is expected to terminate by EOF  puts("End of file reached");    clearerr(tmpf); // clear EOF  puts(feof(tmpf) ? "EOF indicator set"   : "EOF indicator cleared"); }
```

Output:

```c
cppreference.com End of file reached EOF indicator cleared
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.21.10.1 The clearerr function (p: 246)
7.21.10.1 clearerr 函式（頁碼：246）
7.21.10.1 clearerr 函式（頁碼：246）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.21.10.1 The clearerr function (p: 338)
7.21.10.1 clearerr 函式（頁碼：338）
7.21.10.1 clearerr 函式（頁碼：338）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.19.10.1 The clearerr function (p: 304)
7.19.10.1 clearerr 函式（頁碼：304）
7.19.10.1 clearerr 函式（頁碼：304）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.9.10.1 The clearerr function
4.9.10.1 clearerr 函式
4.9.10.1 clearerr 函式

### See also

feof
|   | checks for the end-of-file
(function)   |

perror
|   | displays a character string corresponding of the current error to stderr
(function)   |

ferror
|   | checks for a file error
(function)   |

C++ documentation for clearerr

---
來源頁路徑：`en.cppreference.com/c/io/clearerr.html`

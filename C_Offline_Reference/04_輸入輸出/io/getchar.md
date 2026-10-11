# getchar

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdio.h>`
|   |  |   |  |

```c
int getchar( void );
```
|   |   |   |   |

|  |  |  |  |

Reads the next character from stdin.
從 stdin 讀取下一個字元。
Equivalent to `getc(stdin)`.
等價於 getc ( stdin ) 。

### Parameters

(none)

### Return value

The obtained character on success or EOF on failure.
成功時為所獲得的字元，失敗時為 EOF。
If the failure has been caused by end-of-file condition, additionally sets the *eof* indicator (see feof()) on stdin. If the failure has been caused by some other error, sets the *error* indicator (see ferror()) on stdin.
若因遇到檔案結尾而失敗，會在 stdin 設定檔案結尾指示器（參見 feof()）；若因其他錯誤而失敗，則會設定錯誤指示器（參見 ferror()）。

### Example

Demonstrates `getchar` with error checking
演示帶錯誤檢查的 getchar
Run this code

```c
#include <stdio.h> #include <stdlib.h> int main(void) {  for (int ch; (ch = getchar()) != EOF;) // read/print "abcde" from stdin  printf("%c", ch);  // Test reason for reaching EOF.  if (feof(stdin)) // if failure caused by end-of-file condition  puts("End of file reached");  else if (ferror(stdin)) // if failure caused by some other error  {  perror("getchar()");  fprintf(stderr, "getchar() failed in file %s at line # %d\n",  __FILE__, __LINE__ - 9);  exit(EXIT_FAILURE);  }  return EXIT_SUCCESS; }
```

Possible output:
可能的輸出：

```c
abcde End of file reached
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.21.7.6 The getchar function (p: TBD)
7.21.7.6 getchar 函式（p: TBD）
7.21.7.6 getchar 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.21.7.6 The getchar function (p: TBD)
7.21.7.6 getchar 函式（p: TBD）
7.21.7.6 getchar 函式（p: TBD）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.21.7.6 The getchar function (p: 332)
7.21.7.6 getchar 函式（p: 332）
7.21.7.6 getchar 函式（p: 332）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.19.7.6 The getchar function (p: 298)
7.19.7.6 getchar 函式（p: 298）
7.19.7.6 getchar 函式（p: 298）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.9.7.6 The getchar function
4.9.7.6 getchar 函式
4.9.7.6 getchar 函式

### See also

fgetcgetc
|   | gets a character from a file stream
(function)   |

C++ documentation for getchar

---
來源頁路徑：`en.cppreference.com/c/io/getchar.html`

# putchar

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdio.h>`
|   |  |   |  |

```c
int putchar( int ch );
```
|   |   |   |   |

|  |  |  |  |

Writes a character `ch` to stdout. Internally, the character is converted to `unsigned char` just before being written.
將字元 ch 寫入 stdout。寫入前會先將它轉換為 unsigned char。
Equivalent to `putc(ch, stdout)`.
等同於 putc(ch, stdout)。

### Parameters

| ch  |   | -  |   | character to be written  |

### Return value

On success, returns the written character.
成功時，傳回寫入的字元。
On failure, returns EOF and sets the *error* indicator (see ferror()) on stdout.
若失敗，傳回 EOF，並在 stdout 設定錯誤指示器（參見 ferror()）。

### Example

Shows `putchar` with error checking
展示帶錯誤檢查的 putchar
Run this code

```c
#include <stdio.h> #include <stdlib.h> int main(void) {  int ret_code = 0;  for (char c = 'a'; (ret_code != EOF) && (c != 'z'); c++)  ret_code = putchar(c);    // Test whether EOF was reached.  if (ret_code == EOF && ferror(stdout))  {  fprintf(stderr, "putchar() failed in file %s at line # %d\n",  __FILE__, __LINE__ - 6);  perror("putchar()");  exit(EXIT_FAILURE);  }  putchar('\n');  // putchar return value is not equal to the argument  int r = 0x1070;  printf("\n0x%x\n", r);  r = putchar(r);  printf("\n0x%x\n", r); }
```

Output:

```c
abcdefghijklmnopqrstuvwxy 0x1070 p 0x70
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.21.7.8 The putchar function (p: TBD)
7.21.7.8 putchar 函式（頁：TBD）
7.21.7.8 putchar 函式（頁：TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.21.7.8 The putchar function (p: TBD)
7.21.7.8 putchar 函式（頁：TBD）
7.21.7.8 putchar 函式（頁：TBD）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.21.7.8 The putchar function (p: 333)
7.21.7.8 putchar 函式（頁：333）
7.21.7.8 putchar 函式（頁：333）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.19.7.9 The putchar function (p: 299)
7.19.7.9 putchar 函式（頁：299）
7.19.7.9 putchar 函式（頁：299）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.9.7.9 The putchar function
4.9.7.9 putchar 函式
4.9.7.9 putchar 函式

### See also

fputcputc
|   | writes a character to a file stream
(function)   |

C++ documentation for putchar

---
來源頁路徑：`en.cppreference.com/c/io/putchar.html`

# fputs

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdio.h>`
|   |  |   |  |

```c
int fputs( const char* str, FILE* stream );
```
|   |   |   | (until C99) |

```c
int fputs( const char* restrict str, FILE* restrict stream );
```
|   |   |   | (since C99) |

|  |  |  |  |

Writes every character from the null-terminated string `str` to the output stream `stream`, as if by repeatedly executing fputc.
將以空字元結尾的字串 str 寫入輸出串流 stream，效果等同於逐字元呼叫 fputc。
The terminating null character from `str` is not written.
str 中的結尾空字元不會被寫入。

### Parameters

| str  |   | -  |   | null-terminated character string to be written  |

| stream  |   | -  |   | output stream  |

### Return value

On success, returns a non-negative value.
成功時，傳回非負值。
On failure, returns EOF and sets the *error* indicator (see ferror()) on `stream`.
若失敗，傳回 EOF，並在 stream 設定錯誤指示器（參見 ferror()）。

### Notes

The related function puts appends a newline character to the output, while `fputs` writes the string unmodified.
相關函式 puts 會在輸出末尾加上換行字元；fputs 則不會額外加入換行字元。
Different implementations return different non-negative numbers: some return the last character written, some return the number of characters written (or INT_MAX if the string was longer than that), some simply return a non-negative constant such as zero.
不同的實現傳回不同的非負數：有的傳回最後寫入的字元，有的傳回寫入的字元數（如果字串比該值更長則傳回 INT_MAX），有的則簡單地傳回零這樣的非負常量。

### Example

Run this code

```c
#include <stdio.h>   int main(void) {  int rc = fputs("Hello World", stdout);  if (rc == EOF)  perror("fputs()"); // POSIX requires that errno is set }
```

Output:

```c
Hello World
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.21.7.4 The fputs function (p: TBD)
7.21.7.4 fputs 函式（p: TBD）
7.21.7.4 fputs 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.21.7.4 The fputs function (p: TBD)
7.21.7.4 fputs 函式（p: TBD）
7.21.7.4 fputs 函式（p: TBD）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.21.7.4 The fputs function (p: 331-332)
7.21.7.4 fputs 函式（p: 331-332）
7.21.7.4 fputs 函式（p: 331-332）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.19.7.4 The fputs function (p: 297)
7.19.7.4 fputs 函式（p: 297）
7.19.7.4 fputs 函式（p: 297）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.9.7.4 The fputs function
4.9.7.4 fputs 函式
4.9.7.4 fputs 函式

### See also

printffprintfsprintfsnprintfprintf_sfprintf_ssprintf_ssnprintf_s
(C99)(C11)(C11)(C11)(C11)
|   | prints formatted output to stdout, a file stream or a buffer
(function)   |

puts
|   | writes a character string to stdout
(function)   |

fgets
|   | gets a character string from a file stream
(function)   |

C++ documentation for fputs

---
來源頁路徑：`en.cppreference.com/c/io/fputs.html`

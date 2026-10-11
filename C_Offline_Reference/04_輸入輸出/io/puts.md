# puts

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdio.h>`
|   |  |   |  |

```c
int puts( const char* str );
```
|   |   |   |   |

|  |  |  |  |

Writes every character from the null-terminated string `str` and one additional newline character `'\n'` to the output stream stdout, as if by repeatedly executing fputc.
將以空字元結尾的字串 str 及額外的換行字元 '\n' 寫入 stdout，效果等同於逐字元呼叫 fputc。
The terminating null character from `str` is not written.
str 中的結尾空字元不會被寫入。

### Parameters

| str  |   | -  |   | character string to be written  |

### Return value

On success, returns a non-negative value.
成功時，傳回非負值。
On failure, returns EOF and sets the *error* indicator (see ferror()) on `stream`.
失敗時，傳回 EOF 並在 stream 上設定錯誤指示器（參見 ferror() ）。

### Notes

The `puts` function appends the newline character to the output, while fputs function does not.
puts 會在輸出末尾加上換行字元，fputs 則不會。
Different implementations return different non-negative numbers: some return the last character written, some return the number of characters written (or INT_MAX if the string was longer than that), some simply return a non-negative constant.
不同實現傳回不同的非負數：有的傳回最後寫入的字元，有的傳回寫入的字元數（如果字串更長則傳回 INT_MAX ），有的僅傳回一個非負常量。
A typical cause of failure for `puts` is running out of space on the file system, when stdout is redirected to a file.
當 stdout 被重定向到檔案時，puts 失敗的典型原因是檔案系統空間耗盡。

### Example

Run this code

```c
#include <stdio.h>   int main(void) {  int rc = puts("Hello World");  if (rc == EOF)  perror("puts()"); // POSIX requires that errno is set }
```

Output:

```c
Hello World
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.21.7.9 The puts function (p: TBD)
7.21.7.9 puts 函式（頁碼：待定）
7.21.7.9 puts 函式（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.21.7.9 The puts function (p: TBD)
7.21.7.9 puts 函式（頁碼：待定）
7.21.7.9 puts 函式（頁碼：待定）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.21.7.9 The puts function (p: 333)
7.21.7.9 puts 函式（頁碼：333）
7.21.7.9 puts 函式（頁碼：333）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.19.7.10 The puts function (p: 299)
7.19.7.10 puts 函式（頁碼：299）
7.19.7.10 puts 函式（頁碼：299）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 7.9.7.10 The puts function
7.9.7.10 puts 函式
7.9.7.10 puts 函式

### See also

fputs
|   | writes a character string to a file stream
(function)   |

printffprintfsprintfsnprintfprintf_sfprintf_ssprintf_ssnprintf_s
(C99)(C11)(C11)(C11)(C11)
|   | prints formatted output to stdout, a file stream or a buffer
(function)   |

C++ documentation for puts

---
來源頁路徑：`en.cppreference.com/c/io/puts.html`

# fputws

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<wchar.h>`
|   |  |   |  |

```c
int fputws( const wchar_t* str, FILE* stream );
```
|   |   |   | (since C95)
(until C99) |

```c
int fputws( const wchar_t* restrict str, FILE* restrict stream );
```
|   |   |   | (since C99) |

|  |  |  |  |

Writes every character from the null-terminated wide string `str` to the output stream `stream`, as if by repeatedly executing fputwc.
將以 null 結尾的寬字串 str 中的每個字元寫入輸出流 stream ，如同反覆執行 fputwc 一樣。
The terminating null wide character from `str` is not written.
str 中結尾的 null 寬字元不會被寫入。

### Parameters

| str  |   | -  |   | null-terminated wide string to be written  |

| stream  |   | -  |   | output stream  |

### Return value

On success, returns a non-negative value
成功時，傳回一個非負值
On failure, returns EOF and sets the *error* indicator (see ferror) on `stream`.
失敗時，傳回 EOF 並置位 stream 上的錯誤指示器（參見 ferror ）。

### Example

Run this code

```c
#include <locale.h> #include <stdio.h> #include <wchar.h>   int main(void) {  setlocale(LC_ALL, "en_US.utf8");  int rc = fputws(L"御休みなさい", stdout);  if (rc == EOF)  perror("fputws()"); // POSIX requires that errno is set }
```

Possible output:
可能的輸出：

```c
御休みなさい
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.29.3.4 The fputws function (p: TBD)
7.29.3.4 fputws 函式（p: TBD）
7.29.3.4 fputws 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.29.3.4 The fputws function (p: TBD)
7.29.3.4 fputws 函式（p: TBD）
7.29.3.4 fputws 函式（p: TBD）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.29.3.4 The fputws function (p: 423)
7.29.3.4 fputws 函式（p: 423）
7.29.3.4 fputws 函式（p: 423）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.24.3.4 The fputws function (p: 368)
7.24.3.4 fputws 函式（p: 368）
7.24.3.4 fputws 函式（p: 368）

### See also

fputs
|   | writes a character string to a file stream
(function)   |

wprintffwprintfswprintfwprintf_sfwprintf_sswprintf_ssnwprintf_s
(C95)(C95)(C95)(C11)(C11)(C11)(C11)
|   | prints formatted wide character output to stdout, a file stream or a buffer
(function)   |

fputws
(C95)
|   | writes a wide string to a file stream
(function)   |

fgetws
(C95)
|   | gets a wide string from a file stream
(function)   |

C++ documentation for fputws

---
來源頁路徑：`en.cppreference.com/c/io/fputws.html`

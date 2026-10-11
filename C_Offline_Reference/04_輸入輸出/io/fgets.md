# fgets

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdio.h>`
|   |  |   |  |

```c
char* fgets( char* str, int count, FILE* stream );
```
|   |   |   | (until C99) |

```c
char* fgets( char* restrict str, int count, FILE* restrict stream );
```
|   |   |   | (since C99) |

|  |  |  |  |

Reads at most `count - 1` characters from the given file stream and stores them in the character array pointed to by `str`. Parsing stops if a newline character is found (in which case `str` will contain that newline character) or if end-of-file occurs. If bytes are read and no errors occur, writes a null character at the position immediately after the last character written to `str`.
從指定的檔案串流最多讀取 count - 1 個字元，並存入 str 指向的字元陣列。遇到換行字元（會一併存入 str）或檔案結尾時停止。只要有讀到資料且未發生錯誤，就會在最後一個字元後加上空字元。

### Parameters

| str  |   | -  |   | pointer to an element of a char array  |

| count  |   | -  |   | maximum number of characters to write (typically the length of `str`)  |

| stream  |   | -  |   | file stream to read the data from  |

### Return value

`str` on success, null pointer on failure.
成功時傳回 str，失敗時傳回空指標。
If the end-of-file condition is encountered, sets the *eof* indicator on `stream` (see feof()). This is only a failure if it causes no bytes to be read, in which case a null pointer is returned and the contents of the array pointed to by `str` are not altered (i.e. the first byte is not overwritten with a null character).
遇到檔案結尾時，會在串流設定檔案結尾指示器（參見 feof()）。只有完全沒有讀取任何字元時才算失敗；此時會傳回空指標，且不會修改 str 指向的陣列內容（也不會把第一個位元組改成空字元）。
If the failure has been caused by some other error, sets the *error* indicator (see ferror()) on `stream`. The contents of the array pointed to by `str` are indeterminate (it may not even be null-terminated).
若因其他錯誤而失敗，會在串流設定錯誤指示器（參見 ferror()）。str 指向的陣列內容不確定，也可能沒有以空字元結尾。

### Notes

POSIX additionally requires that `fgets` sets errno if a read error occurs.
POSIX 還要求 fgets 在發生讀取錯誤時設定 errno。
Although the standard specification is unclear in the cases where `count <= 1`, common implementations do
雖然標準規範在 count <= 1 的情況下不明確，但常見實現會

- if `count < 1`, do nothing, report error,
如果 count < 1，什麼都不做，報告錯誤，

- if `count == 1`,
如果 count == 1，

- some implementations do nothing, report error,
某些實現不執行任何操作，報告錯誤，

- others read nothing, store zero in `str[0]`, report success.
其他實現不讀取任何內容，在 str [ 0 ] 中儲存零，並報告成功。
某些實現什麼都不做並報告錯誤，其他實現什麼都不讀取，在 str [ 0 ] 中儲存零，並報告成功。

### Example

Run this code

```c
#include <stdio.h> #include <stdlib.h>   int main(void) {  FILE* tmpf = tmpfile();  fputs("Alan Turing\n", tmpf);  fputs("John von Neumann\n", tmpf);  fputs("Alonzo Church\n", tmpf);    rewind(tmpf);    char buf[8];  while (fgets(buf, sizeof buf, tmpf) != NULL)  printf("\"%s\"\n", buf);  if (feof(tmpf))  puts("End of file reached"); }
```

Output:

```c
"Alan Tu" "ring " "John vo" "n Neuma" "nn " "Alonzo " "Church " End of file reached
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.21.7.2 The fgets function (p: TBD)
7.21.7.2 fgets 函式（p: TBD）
7.21.7.2 fgets 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.21.7.2 The fgets function (p: 241)
7.21.7.2 fgets 函式（p: 241）
7.21.7.2 fgets 函式（p: 241）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.21.7.2 The fgets function (p: 331)
7.21.7.2 fgets 函式（p: 331）
7.21.7.2 fgets 函式（p: 331）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.19.7.2 The fgets function (p: 296)
7.19.7.2 fgets 函式（p: 296）
7.19.7.2 fgets 函式（p: 296）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.9.7.2 The fgets function
4.9.7.2 fgets 函式
4.9.7.2 fgets 函式

### See also

scanffscanfsscanfscanf_sfscanf_ssscanf_s
(C11)(C11)(C11)
|   | reads formatted input from stdin, a file stream or a buffer
(function)   |

getsgets_s
(removed in C11)(C11)
|   | reads a character string from stdin
(function)   |

fputs
|   | writes a character string to a file stream
(function)   |

getlinegetwlinegetdelimgetwdelim
(dynamic memory TR)
|   | read from a stream into an automatically resized buffer until delimiter/end of line
(function)   |

C++ documentation for fgets

---
來源頁路徑：`en.cppreference.com/c/io/fgets.html`

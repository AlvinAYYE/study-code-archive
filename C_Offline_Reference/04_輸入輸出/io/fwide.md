# fwide

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<wchar.h>`
|   |  |   |  |

```c
int fwide( FILE* stream, int mode );
```
|   |   |   |  (since C95)  |

|  |  |  |  |

If `mode > 0`, attempts to make `stream` wide-oriented. If `mode < 0`, attempts to make `stream` byte-oriented. If `mode == 0`, only queries the current orientation of the stream.
如果 mode > 0 ，嘗試將 stream 設為寬導向。如果 mode < 0 ，嘗試將 stream 設為位元組導向。如果 mode == 0 ，僅查詢流的目前導向。
If the orientation of the stream has already been decided (by executing output or by an earlier call to `fwide`), this function does nothing.
如果流的導向已經確定（透過執行輸出或較早呼叫 fwide ），此函式什麼都不做。

### Parameters

| stream  |   | -  |   | pointer to the C I/O stream to modify or query  |

| mode  |   | -  |   | integer value greater than zero to set the stream wide, less than zero to set the stream narrow, or zero to query only  |

### Return value

An integer greater than zero if the stream is wide-oriented after this call, less than zero if the stream is byte-oriented after this call, and zero if the stream has no orientation.
如果呼叫後流為寬導向，則傳回大於零的整數；如果呼叫後流為位元組導向，則傳回小於零的數；如果流沒有導向，則傳回零。

### Example

The following code sets and resets the stream orientation.
以下程式碼設定和重置流導向。
Run this code

```c
#include <stdio.h> #include <stdlib.h> #include <wchar.h> void show_orientation(int n) {  n < 0 ? puts("\tnarrow orientation"):  n > 0 ? puts("\twide orientation"):  puts("\tno orientation"); } void try_read(FILE* fp) {  int c = fgetc(fp);  c == EOF  ? printf("\tnarrow character read failed\n")  : printf("\tnarrow character read '%c'\n", c);    wint_t wc = fgetwc(fp);  wc == WEOF  ? printf("\twide character read failed\n")  : printf("\twide character read '%lc'\n", wc); } int main(void) {  enum fwide_orientation { narrow = -1, query, wide };  FILE* fp = fopen("main.cpp", "r");  if (!fp)  {  perror("fopen() failed");  return EXIT_FAILURE;  }  puts("1) A newly opened stream has no orientation.");  show_orientation(fwide(fp, query));  puts("2) Establish byte orientation.");  show_orientation(fwide(fp, narrow));  try_read(fp);  puts("3) Only freopen() can reset stream orientation.");  if (freopen("main.cpp", "r", fp) == NULL)  {  perror("freopen() failed");  return EXIT_FAILURE;  }  puts("4) A reopened stream has no orientation.");  show_orientation(fwide(fp, query));  puts("5) Establish wide orientation.");  show_orientation(fwide(fp, wide));  try_read(fp);  fclose(fp); }
```

Possible output:
可能的輸出：

```c
1) A newly opened stream has no orientation. no orientation 2) Establish byte orientation. narrow orientation narrow character read '#' wide character read failed 3) Only freopen() can reset stream orientation. 4) A reopened stream has no orientation. no orientation 5) Establish wide orientation. wide orientation narrow character read failed wide character read '#'
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.29.3.5 The fwide function (p: TBD)
7.29.3.5 fwide 函式（頁碼：待定）
7.29.3.5 fwide 函式（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.29.3.5 The fwide function (p: 309)
7.29.3.5 fwide 函式（頁碼：309）
7.29.3.5 fwide 函式（頁碼：309）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.29.3.5 The fwide function (p: 423)
7.29.3.5 fwide 函式（頁碼：423）
7.29.3.5 fwide 函式（頁碼：423）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.24.3.5 The fwide function (p: 369)
7.24.3.5 fwide 函式（頁碼：369）
7.24.3.5 fwide 函式（頁碼：369）

### See also

fopenfopen_s
(C11)
|   | opens a file
(function)   |

C++ documentation for fwide

---
來源頁路徑：`en.cppreference.com/c/io/fwide.html`

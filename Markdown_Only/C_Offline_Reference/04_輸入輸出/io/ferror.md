# ferror

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdio.h>`
|   |  |   |  |

```c
int ferror( FILE *stream );
```
|   |   |   |   |

|  |  |  |  |

Checks the given stream for errors.
檢查給定流是否發生錯誤。

### Parameters

| stream  |   | -  |   | the file stream to check  |

### Return value

Nonzero value if the file stream has errors occurred, `0` otherwise
如果檔案流發生錯誤則傳回非零值，否則為 0

### Example

Run this code

```c
#include <stdio.h> #include <stdlib.h> #include <locale.h> #include <wchar.h>   int main(void) {  char* fname = tmpnam(NULL);  FILE* f = fopen(fname, "wb");  fputs("\xff\xff\n", f); // not a valid UTF-8 character sequence  fclose(f);  setlocale(LC_ALL, "en_US.utf8");  f = fopen(fname, "rb");  wint_t ch;  while ((ch=fgetwc(f)) != WEOF) // attempt to read as UTF-8 fails  printf("%#x ", ch);    if (feof(f))  puts("EOF indicator set");  if (ferror(f))  puts("Error indicator set"); }
```

Output:

```c
Error indicator set
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.21.10.3 The ferror function (p: 339)
7.21.10.3 ferror 函式（頁：339）
7.21.10.3 ferror 函式（頁：339）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.19.10.3 The ferror function (p: 305)
7.19.10.3 ferror 函式（頁：305）
7.19.10.3 ferror 函式（頁：305）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.9.10.3 The ferror function
4.9.10.3 ferror 函式
4.9.10.3 ferror 函式

### See also

clearerr
|   | clears errors
(function)   |

feof
|   | checks for the end-of-file
(function)   |

C++ documentation for ferror

---
來源頁路徑：`en.cppreference.com/c/io/ferror.html`

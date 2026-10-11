# rename

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdio.h>`
|   |  |   |  |

```c
int rename( const char* old_filename, const char* new_filename );
```
|   |   |   |   |

|  |  |  |  |

Changes the filename of a file. The file is identified by character string pointed to by `old_filename`. The new filename is identified by character string pointed to by `new_filename`.
更改檔案的檔名。檔案由 old_filename 指向的字串標識。新檔名由 new_filename 指向的字串標識。
If `new_filename` exists, the behavior is implementation-defined.
如果 new_filename 已存在，則行為由實現定義。

### Parameters

| old_filename  |   | -  |   | pointer to a null-terminated string containing the path identifying the file to rename  |

| new_filename  |   | -  |   | pointer to a null-terminated string containing the new path of the file  |

### Return value

`0` upon success or non-zero value on error.
成功時傳回 0，出錯時傳回非零值。

### Notes

POSIX specifies many additional details on the semantics of this function.
POSIX 對該函式的語意規定了許多額外細節。

### Example

Run this code

```c
#include <stdio.h> #include <stdlib.h> int main(void) {  FILE* fp = fopen("from.txt", "w"); // create file "from.txt"  if (!fp)  {  perror("from.txt");  return EXIT_FAILURE;  }  fputc('a', fp); // write to "from.txt"  fclose(fp);  int rc = rename("from.txt", "to.txt");  if (rc)  {  perror("rename");  return EXIT_FAILURE;  }  fp = fopen("to.txt", "r");  if(!fp)  {  perror("to.txt");  return EXIT_FAILURE;  }  printf("%c\n", fgetc(fp)); // read from "to.txt"  fclose(fp);  return EXIT_SUCCESS; }
```

Possible output:
可能的輸出：

```c
a
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.21.4.2 The rename function (p: TBD)
7.21.4.2 rename 函式（頁碼：待定）
7.21.4.2 rename 函式（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.21.4.2 The rename function (p: TBD)
7.21.4.2 rename 函式（頁碼：待定）
7.21.4.2 rename 函式（頁碼：待定）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.21.4.2 The rename function (p: 302-303)
7.21.4.2 rename 函式（頁碼：302-303）
7.21.4.2 rename 函式（頁碼：302-303）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.19.4.2 The rename function (p: 268-269)
7.19.4.2 rename 函式（頁碼：268-269）
7.19.4.2 rename 函式（頁碼：268-269）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.9.4.2 The rename function
4.9.4.2 rename 函式
4.9.4.2 rename 函式

### See also

remove
|   | erases a file
(function)   |

C++ documentation for rename

---
來源頁路徑：`en.cppreference.com/c/io/rename.html`

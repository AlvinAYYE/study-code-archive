# remove

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdio.h>`
|   |  |   |  |

```c
int remove( const char* pathname );
```
|   |   |   |   |

|  |  |  |  |

Deletes the file identified by the character string pointed to by `pathname`.
刪除由 pathname 指向的字元字串標識的檔案。
If the file is currently open by any process, the behavior of this function is implementation-defined. POSIX systems unlink the file name (directory entry), but the filesystem space used by the file is not reclaimed while it is open in any process and while other hard links to the file exist. Windows does not allow the file to be deleted in such cases.
如果該檔案目前正被任何程式開啟，則此函式的行為是實現定義的。POSIX 系統會取消連結檔名（目錄項），但只要該檔案在任何程式中處於開啟狀態且存在指向該檔案的其他硬連結，檔案系統所佔用的空間就不會被回收。Windows 在這種情況下不允許刪除檔案。

### Parameters

| pathname  |   | -  |   | pointer to a null-terminated string containing the path identifying the file to delete  |

### Return value

`0` upon success or non-zero value on error.
成功時傳回 0，出錯時傳回非零值。

### Notes

POSIX specifies many additional details for the behavior of this function.
POSIX 為此函式的行為指定了許多附加細節。

### Example

Run this code

```c
#include <stdio.h> #include <stdlib.h> int main(void) {  FILE* fp = fopen("file1.txt", "w"); // create file  if (!fp)  {  perror("file1.txt");  return EXIT_FAILURE;  }  puts("Created file1.txt");  fclose(fp);  int rc = remove("file1.txt");  if (rc)  {  perror("remove");  return EXIT_FAILURE;  }  puts("Removed file1.txt");  fp = fopen("file1.txt", "r"); // Failure: file does not exist  if (!fp)  perror("Opening removed file failed");  rc = remove("file1.txt"); // Failure: file does not exist  if (rc)  perror("Double-remove failed");  return EXIT_SUCCESS; }
```

Possible output:
可能的輸出：

```c
Created file1.txt Removed file1.txt Opening removed file failed: No such file or directory Double-remove failed: No such file or directory
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.21.4.1 The remove function (p: TBD)
7.21.4.1 remove 函式（頁：TBD）
7.21.4.1 remove 函式（頁：TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.21.4.1 The remove function (p: TBD)
7.21.4.1 remove 函式（頁：TBD）
7.21.4.1 remove 函式（頁：TBD）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.21.4.1 The remove function (p: 302)
7.21.4.1 remove 函式（頁：302）
7.21.4.1 remove 函式（頁：302）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.19.4.1 The remove function (p: 268)
7.19.4.1 remove 函式（頁：268）
7.19.4.1 remove 函式（頁：268）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.9.4.1 The remove function
4.9.4.1 remove 函式
4.9.4.1 remove 函式

### See also

rename
|   | renames a file
(function)   |

C++ documentation for remove

---
來源頁路徑：`en.cppreference.com/c/io/remove.html`

# tmpfile, tmpfile_s

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdio.h>`
|   |  |   |  |

```c
FILE* tmpfile( void );
```
|   |  (1)  |   |   |

```c
errno_t tmpfile_s( FILE* restrict* restrict streamptr );
```
|   |  (2)  |   |  (since C11)  |

|  |  |  |  |

1) Creates and opens a temporary file. The file is opened as binary file for update (as if by fopen with `"wb+"` mode). The filename of the file is guaranteed to be unique within the filesystem. At least TMP_MAX files may be opened during the lifetime of a program (this limit may be shared with tmpnam and may be further limited by FOPEN_MAX).

2) Same as (1), except that at least TMP_MAX_S files may be opened (the limit may be shared with tmpnam_s), and if `streamptr` is a null pointer, the currently installed constraint handler function is called.
As with all bounds-checked functions, `tmpfile_s` is only guaranteed to be available if `__STDC_LIB_EXT1__` is defined by the implementation and if the user defines `__STDC_WANT_LIB_EXT1__` to the integer constant `1` before including <stdio.h>.
與所有邊界檢查函式一樣，只有當實現定義了 __STDC_LIB_EXT1__ ，並且使用者在包含 <stdio.h> 之前將 __STDC_WANT_LIB_EXT1__ 定義為整數常量 1 時，才保證 tmpfile_s 可用。

The temporary file created by this function is closed and deleted when the program exits normally. Whether it's deleted on abnormal termination is implementation-defined.
由該函式建立的臨時檔案在程式正常退出時被關閉並刪除。在異常終止時是否刪除它由實現定義。

### Parameters

1) (none)

2) pointer to a pointer that will be updated by this function call

### Return value

1) Pointer to the file stream associated with the file or null pointer if an error has occurred.

2) Zero if the file was created and open successfully, non-zero if the file was not created or open or if `streamptr` was a null pointer. In addition, pointer to the associated file stream is stored in `*streamptr` on success, and a null pointer value is stored in `*streamptr` on error.

### Notes

On some implementations (e.g. older Linux), this function actually creates, opens, and immediately deletes the file from the file system: as long as an open file descriptor to a deleted file is held by a program, the file exists, but since it was deleted, its name does not appear in any directory, so that no other process can open it. Once the file descriptor is closed, or once the program terminates (normally or abnormally), the space occupied by the file is reclaimed by the filesystem. Newer Linux (since 3.11 or later, depending on filesystem) creates such invisible temporary files in one step, via special flag in the `open()` syscall.
在某些實現（例如較舊的 Linux）上，該函式實際上會建立檔案、開啟它，然後立即從檔案系統中刪除它：只要程式持有指向已刪除檔案的開啟檔案描述符，該檔案就仍然存在；但由於它已被刪除，其名稱不出現在任何目錄中，因此沒有其他程式能夠開啟它。一旦檔案描述符被關閉，或者程式終止（正常或異常），檔案佔用的空間就會由檔案系統回收。較新的 Linux（自 3.11 或更高版本起，具體取決於檔案系統）透過 open() 系統呼叫中的特殊標誌，一步建立此類不可見的臨時檔案。
On some implementations (e.g. Windows), elevated privileges are required as the function may create the temporary file in a system directory.
在某些實現（例如 Windows）上，該函式可能在系統目錄中建立臨時檔案，因此需要提升的許可權。

### Example

Run this code

```c
#define _POSIX_C_SOURCE 200112L #include <stdio.h> #include <unistd.h> int main(void) {  printf("TMP_MAX = %d, FOPEN_MAX = %d\n", TMP_MAX, FOPEN_MAX);  FILE* tmpf = tmpfile();  fputs("Hello, world", tmpf);  rewind(tmpf);  char buf[6];  fgets(buf, sizeof buf, tmpf);  printf("got back from the file: '%s'\n", buf);  // Linux-specific method to display the tmpfile name  char fname[FILENAME_MAX], link[FILENAME_MAX] = {0};  sprintf(fname, "/proc/self/fd/%d", fileno(tmpf));  if (readlink(fname, link, sizeof link - 1) > 0)  printf("File name: %s\n", link); }
```

Possible output:
可能的輸出：

```c
TMP_MAX = 238328, FOPEN_MAX = 16 got back from the file: 'Hello' File name: /tmp/tmpfjptPe5 (deleted)
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.21.4.3 The tmpfile function (p: TBD)
7.21.4.3 tmpfile 函式（p: TBD）
7.21.4.3 tmpfile 函式（p: TBD）

- K.3.5.1.1 The tmpfile_s function (p: TBD)
K.3.5.1.1 tmpfile_s 函式（p: TBD）
K.3.5.1.1 tmpfile_s 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.21.4.3 The tmpfile function (p: 222)
7.21.4.3 tmpfile 函式（p: 222）
7.21.4.3 tmpfile 函式（p: 222）

- K.3.5.1.1 The tmpfile_s function (p: 427)
K.3.5.1.1 tmpfile_s 函式（p: 427）
K.3.5.1.1 tmpfile_s 函式（p: 427）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.21.4.3 The tmpfile function (p: 303)
7.21.4.3 tmpfile 函式（p: 303）
7.21.4.3 tmpfile 函式（p: 303）

- K.3.5.1.1 The tmpfile_s function (p: 586-587)
K.3.5.1.1 tmpfile_s 函式（p: 586-587）
K.3.5.1.1 tmpfile_s 函式（p: 586-587）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.19.4.3 The tmpfile function (p: 269)
7.19.4.3 tmpfile 函式（p: 269）
7.19.4.3 tmpfile 函式（p: 269）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.9.4.3 The tmpfile function
4.9.4.3 tmpfile 函式
4.9.4.3 tmpfile 函式

### See also

tmpnamtmpnam_s
(C11)
|   | returns a unique filename
(function)   |

C++ documentation for tmpfile

---
來源頁路徑：`en.cppreference.com/c/io/tmpfile.html`

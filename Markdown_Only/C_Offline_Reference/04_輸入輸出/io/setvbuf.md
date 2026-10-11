# setvbuf

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdio.h>`
|   |  |   |  |

```c
int setvbuf( FILE* stream, char* buffer,  int mode, size_t size );
```
|   |   |   | (until C99) |

```c
int setvbuf( FILE* restrict stream, char* restrict buffer,  int mode, size_t size );
```
|   |   |   | (since C99) |

```c
#define _IOFBF /* unspecified */ #define _IOLBF /* unspecified */ #define _IONBF /* unspecified */
```
|   |   |   |  |

|  |  |  |  |

Changes the buffering mode of the given file stream `stream` as indicated by the argument `mode`. In addition,
根據參數 mode 指示更改給定檔案流 stream 的緩衝模式。此外，

- If `buffer` is a null pointer, resizes the internal buffer to `size`.
如果 buffer 是空指標，則將內部緩衝區大小調整為 size 。

- If `buffer` is not a null pointer, instructs the stream to use the user-provided buffer of size `size` beginning at `buffer`. The stream must be closed (with fclose) before the lifetime of the characters in `[``buffer``, ``buffer + size``)` ends. The contents of the buffer after a successful call to `setvbuf` are indeterminate and any attempt to use it is undefined behavior.
如果 buffer 不是空指標，則指示流使用從 buffer 開始、大小為 size 的使用者提供的緩衝區。流必須在 [ buffer , buffer + size ) 中字元的生命週期結束之前關閉（使用 fclose ）。成功呼叫 setvbuf 之後緩衝區的內容是不確定的，任何使用它的嘗試都是未定義行為。

### Parameters

| stream  |   | -  |   | the file stream to set the buffer to  |

| buffer  |   | -  |   | pointer to a buffer for the stream to use or null pointer to change size and mode only  |

| mode  |   | -  |   | buffering mode to use. It can be one of the following values:

| `_IOFBF`  |   | full buffering  |

| `_IOLBF`  |   | line buffering  |

| `_IONBF`  |   | no buffering  |

| size  |   | -  |   | size of the buffer  |

### Return value

`0` on success or nonzero on failure.
成功時傳回 0，失敗時傳回非零。

### Notes

This function may only be used after `stream` has been associated with an open file, but before any other operation (other than a failed call to setbuf/`setvbuf`).
此函式只能在 stream 已與開啟的檔案關聯之後、任何其他操作（setbuf / setvbuf 的失敗呼叫除外）之前使用。
Not all `size` bytes will necessarily be used for buffering: the actual buffer size is usually rounded down to a multiple of 2, a multiple of page size, etc.
並非所有 size 位元組都必然用於緩衝：實際緩衝區大小通常向下舍入為 2 的倍數、頁面大小的倍數等。
On many implementations, line buffering is only available for terminal input streams.
在許多實現中，行緩衝僅適用於終端輸入流。
A common error is setting the buffer of stdin or stdout to an array whose lifetime ends before the program terminates:
一個常見錯誤是將 stdin 或 stdout 的緩衝區設定為一個其生命期在程式終止之前結束的陣列：

```c
int main(void) {  char buf[BUFSIZ];  setbuf(stdin, buf); } // lifetime of buf ends, undefined behavior
```

The default buffer size BUFSIZ is expected to be the most efficient buffer size for file I/O on the implementation, but POSIX `fstat` often provides a better estimate.
預設緩衝區大小 BUFSIZ 預期是該實現上檔案 I/O 最高效的緩衝區大小，但 POSIX fstat 通常提供更好的估計。

### Example

One use case for changing buffer size is when a better size is known. (This example uses some POSIX function, e.g. `fileno`. See also SO: #1 and #2).
更改緩衝區大小的一個用例是已知更好的大小。（此示例使用了一些 POSIX 函式，例如 fileno。另見 SO: #1 和 #2。）
Run this code

```c
// Make some POSIX functions, such as ‘int fileno(FILE*)’, visible: #define _POSIX_SOURCE #include <stdio.h> #include <stdlib.h> #include <sys/stat.h> int main(void) {  FILE* fp = fopen("/tmp/test.txt", "w+");  if (fp == NULL)  {  perror("fopen");  return EXIT_FAILURE;  }  struct stat stats;  if (fstat(fileno(fp), &stats) == -1) // POSIX only  {  perror("fstat");  return EXIT_FAILURE;  }  printf("BUFSIZ is %d, but optimal block size is %ld\n", BUFSIZ, stats.st_blksize);  if (setvbuf(fp, NULL, _IOFBF, stats.st_blksize) != 0)  {  perror("setvbuf failed"); // POSIX version sets errno  return EXIT_FAILURE;  }  int ch;  while((ch=fgetc(fp)) != EOF); // read entire file: use truss/strace to  // observe the read(2) syscalls used  fclose(fp);  return EXIT_SUCCESS; }
```

Possible output:
可能的輸出：

```c
BUFSIZ is 8192, but optimal block size is 65536
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.23.5.6 The setvbuf function (p: 329-330)
7.23.5.6 setvbuf 函式（頁：329-330）
7.23.5.6 setvbuf 函式（頁：329-330）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.21.5.6 The setvbuf function (p: 225)
7.21.5.6 setvbuf 函式（頁：225）
7.21.5.6 setvbuf 函式（頁：225）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.21.5.6 The setvbuf function (p: 308)
7.21.5.6 setvbuf 函式（頁：308）
7.21.5.6 setvbuf 函式（頁：308）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.19.5.6 The setvbuf function (p: 273-274)
7.19.5.6 setvbuf 函式（頁：273-274）
7.19.5.6 setvbuf 函式（頁：273-274）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.9.5.6 The setvbuf function
4.9.5.6 setvbuf 函式
4.9.5.6 setvbuf 函式

### See also

setbuf
|   | sets the buffer for a file stream
(function)   |

C++ documentation for setvbuf

---
來源頁路徑：`en.cppreference.com/c/io/setvbuf.html`

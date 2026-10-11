# feof

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdio.h>`
|   |  |   |  |

```c
int feof( FILE *stream );
```
|   |   |   |   |

|  |  |  |  |

Checks if the end of the given file stream has been reached.
檢查給定檔案流是否已到達末尾。

### Parameters

| stream  |   | -  |   | the file stream to check  |

### Return value

nonzero value if the end of the stream has been reached, otherwise `0`
如果已到達流末尾則傳回非零值，否則傳回 0

### Notes

This function only reports the stream state as reported by the most recent I/O operation, it does not examine the associated data source. For example, if the most recent I/O was a fgetc, which returned the last byte of a file, `feof` returns zero. The next fgetc fails and changes the stream state to *end-of-file*. Only then `feof` returns non-zero.
此函式僅報告最近一次 I/O 操作所報告的流狀態，並不檢查關聯的資料來源。例如，如果最近的 I/O 是 fgetc 且傳回了檔案的最後一個位元組，則 feof 傳回零。下一次 fgetc 失敗並將流狀態改為檔案結束。只有那時 feof 才傳回非零。
In typical usage, input stream processing stops on any error; `feof` and ferror are then used to distinguish between different error conditions.
在典型用法中，輸入流處理在發生任何錯誤時停止；隨後使用 feof 和 ferror 區分不同的錯誤情況。

### Example

Run this code

```c
#include <stdio.h> #include <stdlib.h> int main(void) {  const char* fname = "/tmp/unique_name.txt"; // or tmpnam(NULL);  int is_ok = EXIT_FAILURE;  FILE* fp = fopen(fname, "w+");  if (!fp)  {  perror("File opening failed");  return is_ok;  }  fputs("Hello, world!\n", fp);  rewind(fp);  int c; // note: int, not char, required to handle EOF  while ((c = fgetc(fp)) != EOF) // standard C I/O file reading loop  putchar(c);  if (ferror(fp))  puts("I/O error when reading");  else if (feof(fp))  {  puts("End of file is reached successfully");  is_ok = EXIT_SUCCESS;  }  fclose(fp);  remove(fname);  return is_ok; }
```

Possible output:
可能的輸出：

```c
Hello, world! End of file is reached successfully
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.21.10.2 The feof function (p: 339)
7.21.10.2 feof 函式（頁碼：339）
7.21.10.2 feof 函式（頁碼：339）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.19.10.2 The feof function (p: 305)
7.19.10.2 feof 函式（頁碼：305）
7.19.10.2 feof 函式（頁碼：305）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.9.10.2 The feof function
4.9.10.2 feof 函式
4.9.10.2 feof 函式

### See also

clearerr
|   | clears errors
(function)   |

perror
|   | displays a character string corresponding of the current error to stderr
(function)   |

ferror
|   | checks for a file error
(function)   |

C++ documentation for feof

---
來源頁路徑：`en.cppreference.com/c/io/feof.html`

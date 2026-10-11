# fclose

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdio.h>`
|   |  |   |  |

```c
int fclose( FILE* stream );
```
|   |   |   |   |

|  |  |  |  |

Closes the given file stream. Any unwritten buffered data are flushed to the OS. Any unread buffered data are discarded.
關閉指定的檔案串流。尚未寫出的緩衝資料會送交作業系統，尚未讀取的緩衝資料則會丟棄。
Whether or not the operation succeeds, the stream is no longer associated with a file, and the buffer allocated by setbuf or setvbuf, if any, is also disassociated and deallocated if automatic allocation was used.
無論操作成功與否，串流都會解除與檔案的關聯。若 setbuf 或 setvbuf 使用了自動配置的緩衝區，也會解除關聯並釋放該緩衝區。
The behavior is undefined if the value of the pointer `stream` is used after `fclose` returns.
fclose 傳回後若再使用 stream 指標，行為未定義。

### Parameters

| stream  |   | -  |   | the file stream to close  |

### Return value

`0` on success, EOF otherwise
成功時傳回 0，否則傳回 EOF

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

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.21.5.1 The fclose function (p: TBD)
7.21.5.1 fclose 函式（頁碼：待定）
7.21.5.1 fclose 函式（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.21.5.1 The fclose function (p: TBD)
7.21.5.1 fclose 函式（頁碼：待定）
7.21.5.1 fclose 函式（頁碼：待定）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.21.5.1 The fclose function (p: 304)
7.21.5.1 fclose 函式（頁碼：304）
7.21.5.1 fclose 函式（頁碼：304）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.19.5.1 The fclose function (p: 270)
7.19.5.1 fclose 函式（頁碼：270）
7.19.5.1 fclose 函式（頁碼：270）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.9.5.1 The fclose function
4.9.5.1 fclose 函式
4.9.5.1 fclose 函式

### See also

fopenfopen_s
(C11)
|   | opens a file
(function)   |

freopenfreopen_s
(C11)
|   | open an existing stream with a different name
(function)   |

C++ documentation for fclose

---
來源頁路徑：`en.cppreference.com/c/io/fclose.html`

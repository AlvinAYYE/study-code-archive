# rewind

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdio.h>`
|   |  |   |  |

```c
void rewind( FILE *stream );
```
|   |   |   |   |

|  |  |  |  |

Moves the file position indicator to the beginning of the given file stream.
將檔案位置指示器移動到給定檔案流的起始位置。
The function is equivalent to `fseek(stream, 0, SEEK_SET);`, except that end-of-file and error indicators are cleared.
該函式等價於 fseek ( stream , 0 , SEEK_SET ); ，但會清除檔案結束指示器和錯誤指示器。
The function drops any effects from previous calls to ungetc.
該函式會丟棄先前呼叫 ungetc 所產生的任何效果。

### Parameters

| stream  |   | -  |   | file stream to modify  |

### Return value

(none)

### Example

This example shows how to read a file twice
本示例展示如何兩次讀取同一個檔案
Run this code

```c
#include <stdio.h> char str[20]; int main(void) {  FILE *f;  char ch;  f = fopen("file.txt", "w");  for (ch = '0'; ch <= '9'; ch++) {  fputc(ch, f);  }  fclose(f);  f = fopen("file.txt", "r");  fread(str, 1, 10, f);  puts(str);    rewind(f);  fread(str, 1, 10, f);  puts(str);  fclose(f);  return 0; }
```

Output:

```c
0123456789 0123456789
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.21.9.5 The rewind function (p: 338)
7.21.9.5 rewind 函式（p: 338）
7.21.9.5 rewind 函式（p: 338）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.19.9.5 The rewind function (p: 304)
7.19.9.5 rewind 函式（p: 304）
7.19.9.5 rewind 函式（p: 304）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.9.9.5 The rewind function
4.9.9.5 rewind 函式
4.9.9.5 rewind 函式

### See also

fseek
|   | moves the file position indicator to a specific location in a file
(function)   |

C++ documentation for rewind

---
來源頁路徑：`en.cppreference.com/c/io/rewind.html`

# fread

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdio.h>`
|   |  |   |  |

```c
size_t fread( void* buffer, size_t size, size_t count,  FILE* stream );
```
|   |   |   | (until C99) |

```c
size_t fread( void* restrict buffer, size_t size, size_t count,  FILE* restrict stream );
```
|   |   |   | (since C99) |

|  |  |  |  |

Reads up to `count` objects into the array `buffer` from the given input stream `stream` as if by calling fgetc `size` times for each object, and storing the results, in the order obtained, into the successive positions of `buffer`, which is reinterpreted as an array of `unsigned char`. The file position indicator for the stream is advanced by the number of characters read.
從輸入串流 stream 最多讀取 count 個物件到陣列 buffer。這相當於對每個物件呼叫 size 次 fgetc，並依讀取順序將結果存入 buffer 的連續位置；buffer 會視為 unsigned char 陣列。串流的檔案位置指示器會依讀取的字元數向前移動。
If an error occurs, the resulting value of the file position indicator for the stream is indeterminate. If a partial element is read, its value is indeterminate.
如果發生錯誤，該流的檔案位置指示器的最終值是 不確定的。如果讀取了部分元素，其值是不確定的。

### Parameters

| buffer  |   | -  |   | pointer to the array where the read objects are stored  |

| size  |   | -  |   | size of each object in bytes  |

| count  |   | -  |   | the number of the objects to be read  |

| stream  |   | -  |   | the stream to read  |

### Return value

Number of objects read successfully, which may be less than `count` if an error or end-of-file condition occurs.
傳回成功讀取的物件數。若發生錯誤或遇到檔案結尾，傳回值可能小於 count。
If `size` or `count` is zero, `fread` returns zero and performs no other action.
如果 size 或 count 為零， fread 傳回零且不執行任何其他操作。
`fread` does not distinguish between end-of-file and error, and callers must use feof and ferror to determine which occurred.
fread 不會區分檔案結尾與讀取錯誤，呼叫端必須使用 feof 和 ferror 判斷實際情況。

### Example

Run this code

```c
#include <stdio.h> enum { SIZE = 5 }; int main(void) {  const double a[SIZE] = {1.0, 2.0, 3.0, 4.0, 5.0};  printf("Array has size %ld bytes, element size: %ld\n", sizeof a, sizeof* a);  FILE* fp = fopen("test.bin", "wb"); // must use binary mode  fwrite(a, sizeof* a, SIZE, fp); // writes an array of doubles  fclose(fp);  double b[SIZE];  fp = fopen("test.bin","rb");  const size_t ret_code = fread(b, sizeof b[0], SIZE, fp); // reads an array of doubles  if (ret_code == SIZE)  {  printf("Array at %p read successfully, contents:\n", (void*)&a);  for (int n = 0; n != SIZE; ++n)  printf("%f ", b[n]);  putchar('\n');  }  else // error handling  {  if (feof(fp))  printf("Error reading test.bin: unexpected end of file\n");  else if (ferror(fp))  perror("Error reading test.bin");  }  fclose(fp); }
```

Possible output:
可能的輸出：

```c
Array has size 40 bytes, element size: 8 Array at 0x1337f00d6960 read successfully, contents: 1.000000 2.000000 3.000000 4.000000 5.000000
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.21.8.1 The fread function (p: TBD)
7.21.8.1 fread 函式（p: TBD）
7.21.8.1 fread 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.21.8.1 The fread function (p: 243-244)
7.21.8.1 fread 函式（p: 243-244）
7.21.8.1 fread 函式（p: 243-244）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.21.8.1 The fread function (p: 335)
7.21.8.1 fread 函式（p: 335）
7.21.8.1 fread 函式（p: 335）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.19.8.1 The fread function (p: 301)
7.19.8.1 fread 函式（p: 301）
7.19.8.1 fread 函式（p: 301）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.9.8.1 The fread function
4.9.8.1 fread 函式
4.9.8.1 fread 函式

### See also

scanffscanfsscanfscanf_sfscanf_ssscanf_s
(C11)(C11)(C11)
|   | reads formatted input from stdin, a file stream or a buffer
(function)   |

fgets
|   | gets a character string from a file stream
(function)   |

fwrite
|   | writes to a file
(function)   |

C++ documentation for fread

---
來源頁路徑：`en.cppreference.com/c/io/fread.html`

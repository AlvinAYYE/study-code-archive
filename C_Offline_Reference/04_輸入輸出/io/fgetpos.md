# fgetpos

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdio.h>`
|   |  |   |  |

```c
int fgetpos( FILE* stream, fpos_t* pos );
```
|   |   |   | (until C99) |

```c
int fgetpos( FILE* restrict stream, fpos_t* restrict pos );
```
|   |   |   | (since C99) |

|  |  |  |  |

Obtains the file position indicator and the current parse state (if any) for the file stream `stream` and stores them in the object pointed to by `pos`. The value stored is only meaningful as the input to fsetpos.
獲取檔案流 stream 的檔案位置指示器和目前解析狀態（如果有），並將它們儲存在 pos 指向的物件中。儲存的值僅作為 fsetpos 的輸入才有意義。

### Parameters

| stream  |   | -  |   | file stream to examine  |

| pos  |   | -  |   | pointer to a fpos_t object to store the file position indicator to  |

### Return value

`0` upon success, nonzero value otherwise.
成功時傳回 0，否則傳回非零值。

### Example

Run this code

```c
#include <assert.h> #include <stdio.h> #include <stdlib.h> int main(void) {  // prepare a file holding 4 values of type double  enum {SIZE = 4};  FILE* fp = fopen("test.bin", "wb");  assert(fp);  int rc = fwrite((double[SIZE]){1.1, 2.2, 3.3, 4.4}, sizeof(double), SIZE, fp);  assert(rc == SIZE);  fclose(fp);  // demo using fsetpos to return to the beginning of a file  fp = fopen("test.bin", "rb");  fpos_t pos;  fgetpos(fp, &pos); // store start of file in pos  double d;  rc = fread(&d, sizeof d, 1, fp); // read the first double  assert(rc == 1);  printf("First value in the file: %.1f\n", d);  fsetpos(fp,&pos); // move file position back to the start of the file  rc = fread(&d, sizeof d, 1, fp); // read the first double again  assert(rc == 1);  printf("First value in the file again: %.1f\n", d);  fclose(fp);  // demo error handling  rc = fsetpos(stdin, &pos);  if (rc)  perror("could not fsetpos stdin"); }
```

Output:

```c
First value in the file: 1.1 First value in the file again: 1.1 could not fsetpos stdin: Illegal seek
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.21.9.1 The fgetpos function (p: TBD)
7.21.9.1 fgetpos 函式（頁：TBD）
7.21.9.1 fgetpos 函式（頁：TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.21.9.1 The fgetpos function (p: TBD)
7.21.9.1 fgetpos 函式（頁：TBD）
7.21.9.1 fgetpos 函式（頁：TBD）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.21.9.1 The fgetpos function (p: 336)
7.21.9.1 fgetpos 函式（頁：336）
7.21.9.1 fgetpos 函式（頁：336）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.19.9.1 The fgetpos function (p: 302)
7.19.9.1 fgetpos 函式（頁：302）
7.19.9.1 fgetpos 函式（頁：302）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.9.9.1 The fgetpos function
4.9.9.1 fgetpos 函式
4.9.9.1 fgetpos 函式

### See also

ftell
|   | returns the current file position indicator
(function)   |

fseek
|   | moves the file position indicator to a specific location in a file
(function)   |

fsetpos
|   | moves the file position indicator to a specific location in a file
(function)   |

C++ documentation for fgetpos

---
來源頁路徑：`en.cppreference.com/c/io/fgetpos.html`

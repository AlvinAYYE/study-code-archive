# fsetpos

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdio.h>`
|   |  |   |  |

```c
int fsetpos( FILE* stream, const fpos_t* pos );
```
|   |   |   |   |

|  |  |  |  |

Sets the file position indicator and the multibyte parsing state (if any) for the file stream `stream` according to the value pointed to by `pos`.
根據 pos 所指向的值，設定檔案流 stream 的檔案位置指示器和多位元組解析狀態（如有）。
Besides establishing new parse state and position, a call to this function undoes the effects of ungetc and clears the end-of-file state, if it is set.
除了建立新的解析狀態和位置之外，呼叫該函式還會撤銷 ungetc 的效果，並在檔案結束狀態被置位時將其清除。
If a read or write error occurs, the error indicator (ferror) for the stream is set.
如果發生讀取或寫入錯誤，則會置位該流的錯誤指示器（ ferror ）。

### Parameters

| stream  |   | -  |   | file stream to modify  |

| pos  |   | -  |   | pointer to a fpos_t object to use as new value of file position indicator  |

### Return value

`0` upon success, nonzero value otherwise.
成功時傳回 0，否則傳回非零值。

### Notes

After seeking to a non-end position in a wide stream, the next call to any output function may render the remainder of the file undefined, e.g. by outputting a multibyte sequence of a different length.
在寬流中 seek 到非末尾位置之後，下一次對任何輸出函式的呼叫都可能使檔案的其餘部分未定義，例如輸出一個長度不同的多位元組序列。

### Example

`fsetpos` with error checking
帶錯誤檢查的 fsetpos
Run this code

```c
#include <stdio.h> #include <stdlib.h> int main(void) {  // Prepare an array of FP (floating-point) values.  #define SIZE 5  double A[SIZE] = {1.0, 2.0, 3.0, 4.0, 5.0};  // Write array to a file.  FILE * fp = fopen("test.bin", "wb");  fwrite(A,sizeof(double),SIZE,fp);  fclose (fp);  // Read the FP values into array B.  double B[SIZE];  fp = fopen("test.bin","rb");  fpos_t pos;  if (fgetpos(fp, &pos)) // current position: start of file  {  perror("fgetpos()");  fprintf(stderr, "fgetpos() failed in file %s at line # %d\n",  __FILE__, __LINE__ - 3);  exit(EXIT_FAILURE);  }  int ret_code = fread(B,sizeof(double),1,fp); // read one FP value  // current position: after reading one f-p value  printf("%.1f; read count = %d\n", B[0], ret_code); // print one FP value and ret_code  if (fsetpos(fp, &pos)) // reset current position to start of file  {  if (ferror(fp))  {  perror("fsetpos()");  fprintf(stderr, "fsetpos() failed in file %s at line # %d\n", __FILE__,  __LINE__ - 5);  exit(EXIT_FAILURE);  }  }  ret_code = fread(B, sizeof(double), 1, fp); // reread first FP value  printf("%.1f; read count = %d\n", B[0], ret_code); // print one FP value and ret_code  fclose(fp);  return EXIT_SUCCESS; }
```

Possible output:
可能的輸出：

```c
1.0; read count = 1 1.0; read count = 1
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.21.9.3 The fsetpos function (p: TBD)
7.21.9.3 fsetpos 函式（p: TBD）
7.21.9.3 fsetpos 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.21.9.3 The fsetpos function (p: TBD)
7.21.9.3 fsetpos 函式（p: TBD）
7.21.9.3 fsetpos 函式（p: TBD）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.21.9.3 The fsetpos function (p: 337)
7.21.9.3 fsetpos 函式（p: 337）
7.21.9.3 fsetpos 函式（p: 337）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.19.9.3 The fsetpos function (p: 303)
7.19.9.3 fsetpos 函式（p: 303）
7.19.9.3 fsetpos 函式（p: 303）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.9.9.3 The fsetpos function
4.9.9.3 fsetpos 函式
4.9.9.3 fsetpos 函式

### See also

fgetpos
|   | gets the file position indicator
(function)   |

ftell
|   | returns the current file position indicator
(function)   |

fseek
|   | moves the file position indicator to a specific location in a file
(function)   |

C++ documentation for fsetpos

---
來源頁路徑：`en.cppreference.com/c/io/fsetpos.html`

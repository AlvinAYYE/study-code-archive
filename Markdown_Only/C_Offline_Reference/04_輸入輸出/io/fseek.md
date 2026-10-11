# fseek

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdio.h>`
|   |  |   |  |

```c
int fseek( FILE* stream, long offset, int origin );
```
|   |   |   |   |

```c
#define SEEK_SET /* unspecified */ #define SEEK_CUR /* unspecified */ #define SEEK_END /* unspecified */
```
|   |   |   |   |

|  |  |  |  |

Sets the file position indicator for the file stream `stream` to the value pointed to by `offset`.
將檔案串流 stream 的檔案位置指示器移到指定位置。新位置由 offset 和 origin 共同決定。
If the `stream` is open in binary mode, the new position is exactly `offset` bytes measured from the beginning of the file if `origin` is SEEK_SET, from the current file position if `origin` is SEEK_CUR, and from the end of the file if `origin` is SEEK_END. Binary streams are not required to support SEEK_END, in particular if additional null bytes are output.
若串流以二進位模式開啟，origin 為 SEEK_SET 時，位置從檔案開頭起算 offset 個位元組；為 SEEK_CUR 時，從目前位置起算；為 SEEK_END 時，則從檔案結尾起算。二進位串流不一定支援 SEEK_END，尤其是會在檔案結尾後寫入額外空位元組的情況。
If the `stream` is open in text mode, the only supported values for `offset` are zero (which works with any `origin`) and a value returned by an earlier call to ftell on a stream associated with the same file (which only works with `origin` of SEEK_SET).
若串流以文字模式開啟，offset 只能是 0（origin 可為任意值），或先前對同一檔案串流呼叫 ftell 所傳回的值（此時 origin 必須是 SEEK_SET）。
If the `stream` is wide-oriented, the restrictions of both text and binary streams apply (result of ftell is allowed with SEEK_SET and zero offset is allowed from SEEK_SET and SEEK_CUR, but not SEEK_END).
若串流採用寬字元導向，文字串流與二進位串流的限制都適用：ftell 的結果可搭配 SEEK_SET 使用；SEEK_SET 和 SEEK_CUR 也可搭配 0 位移使用，但不支援 SEEK_END。
In addition to changing the file position indicator, `fseek` undoes the effects of ungetc and clears the end-of-file status, if applicable.
除了移動檔案位置指示器，fseek 也會取消 ungetc 的效果，並在適用時清除檔案結尾指示器。
If a read or write error occurs, the error indicator for the stream (ferror) is set and the file position is unaffected.
若讀取或寫入時發生錯誤，會設定串流的錯誤指示器（可用 ferror 查詢），檔案位置則不變。

### Parameters

| stream  |   | -  |   | file stream to modify  |

| offset  |   | -  |   | number of characters to shift the position relative to origin  |

| origin  |   | -  |   | position to which `offset` is added. It can have one of the following values: SEEK_SET, SEEK_CUR, SEEK_END  |

### Return value

`0` upon success, nonzero value otherwise.
成功時傳回 0，否則傳回非零值。

### Notes

After seeking to a non-end position in a wide stream, the next call to any output function may render the remainder of the file undefined, e.g. by outputting a multibyte sequence of a different length.
在寬字元串流中將位置移到檔案結尾以外的地方後，下一次呼叫輸出函式可能使檔案其餘內容變得未定義；例如，輸出的多位元組序列長度與原內容不同。
For text streams, the only valid values of `offset` are `0` (applicable to any `origin`) and a value returned by an earlier call to ftell (only applicable to SEEK_SET).
對文字串流而言，offset 只能是 0（origin 可為任意值），或先前呼叫 ftell 所傳回的值（此時 origin 必須是 SEEK_SET）。
POSIX allows seeking beyond the existing end of file. If an output is performed after this seek, any read from the gap will return zero bytes. Where supported by the filesystem, this creates a *sparse file*.
POSIX 允許將位置移到現有檔案結尾之後。之後若寫入資料，讀取檔案中間未寫入的空隙時會得到值為 0 的位元組；若檔案系統支援，這會形成稀疏檔案。
POSIX also requires that `fseek` first performs fflush if there are any unwritten data (but whether the shift state is restored is implementation-defined).
POSIX 也要求 fseek 在有尚未寫出的資料時先呼叫 fflush；是否還原移位狀態則由實作決定。
POSIX specifies, that `fseek` should return `-1` on error, and set errno to indicate the error.
POSIX 規定 fseek 發生錯誤時應傳回 -1，並設定 errno 指明錯誤原因。
On Windows, `_fseeki64` can be used to work with files larger than 2 GiB.
在 Windows 上，處理大於 2 GiB 的檔案時可使用 _fseeki64。

### Example

`fseek` with error checking:
帶錯誤檢查的 fseek：
Run this code

```c
#include <stdio.h> #include <stdlib.h> int main(void) {  // Prepare an array of double values.  #define SIZE 5  double A[SIZE] = {1.0, 2.0, 3.0, 4.0, 5.0};  // Write array to a file.  FILE * fp = fopen("test.bin", "wb");  fwrite(A, sizeof(double), SIZE, fp);  fclose (fp);  // Read the double values into array B.  double B[SIZE];  fp = fopen("test.bin", "rb");  // Set the file position indicator in front of third double value.  if (fseek(fp, sizeof(double) * 2L, SEEK_SET) != 0)  {  fprintf(stderr, "fseek() failed in file %s at line # %d\n",  __FILE__, __LINE__ - 2);  fclose(fp);  return EXIT_FAILURE;  }  int ret_code = fread(B, sizeof(double), 1, fp); // reads one double value  printf("ret_code == %d\n", ret_code); // prints the number of values read  printf("B[0] == %.1f\n", B[0]); // prints one value  fclose(fp);  return EXIT_SUCCESS; }
```

Possible output:
可能的輸出：

```c
ret_code == 1 B[0] == 3.0
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.23.9.2 The fseek function (p: TBD)
7.23.9.2 fseek 函式（頁碼：待定）
7.23.9.2 fseek 函式（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.21.9.2 The fseek function (p: 245)
7.21.9.2 fseek 函式（頁碼：245）
7.21.9.2 fseek 函式（頁碼：245）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.21.9.2 The fseek function (p: 336-337)
7.21.9.2 fseek 函式（頁碼：336-337）
7.21.9.2 fseek 函式（頁碼：336-337）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.19.9.2 The fseek function (p: 302-303)
7.19.9.2 fseek 函式（頁碼：302-303）
7.19.9.2 fseek 函式（頁碼：302-303）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.9.9.2 The fseek function
4.9.9.2 fseek 函式
4.9.9.2 fseek 函式

### See also

fsetpos
|   | moves the file position indicator to a specific location in a file
(function)   |

fgetpos
|   | gets the file position indicator
(function)   |

ftell
|   | returns the current file position indicator
(function)   |

rewind
|   | moves the file position indicator to the beginning in a file
(function)   |

C++ documentation for fseek

---
來源頁路徑：`en.cppreference.com/c/io/fseek.html`

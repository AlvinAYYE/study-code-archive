# fopen, fopen_s

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdio.h>`
|   |  |   |  |

```c
FILE* fopen( const char* filename, const char* mode );
```
|   |  (1) |   | (until C99) |

```c
FILE* fopen( const char* restrict filename, const char* restrict mode );
```
|   |   |   | (since C99) |

```c
errno_t fopen_s( FILE* restrict* restrict streamptr,  const char* restrict filename,  const char* restrict mode );
```
|   |  (2)  |   |  (since C11)  |

|  |  |  |  |

1) Opens a file indicated by `filename` and returns a pointer to the file stream associated with that file. `mode` is used to determine the file access mode.
1) 開啟 `filename` 指定的檔案，並傳回與該檔案關聯的串流指標。`mode` 用來指定開啟方式。

2) Same as (1), except that the pointer to the file stream is written to `streamptr` and the following errors are detected at runtime and call the currently installed constraint handler function:
2) 行為與 (1) 相同，但串流指標會寫入 `streamptr`；執行時若發現下列錯誤，會呼叫目前設定的約束處理函式：
- `streamptr` is a null pointer
streamptr 是空指標

- `filename` is a null pointer
filename 是空指標

- `mode` is a null pointer
mode 是空指標
As with all bounds-checked functions, `fopen_s` is only guaranteed to be available if `__STDC_LIB_EXT1__` is defined by the implementation and if the user defines `__STDC_WANT_LIB_EXT1__` to the integer constant `1` before including <stdio.h>.
和其他有界限檢查的函式一樣，只有實作定義了 `__STDC_LIB_EXT1__`，而且程式在引入 `<stdio.h>` 前將 `__STDC_WANT_LIB_EXT1__` 設為整數常數 `1`，才能保證可以使用 `fopen_s`。

### Parameters

| filename  |   | -  |   | file name to associate the file stream to  |

| mode  |   | -  |   | null-terminated character string determining file access mode  |

| streamptr  |   | -  |   | pointer to a pointer where the function stores the result (an out-parameter)  |

### File access flags
檔案訪問標誌

| 檔案開啟模式字串 |   | 意義 |   | 說明 |   | 檔案已存在時 |   | 檔案不存在時 |

| `"r"`  |   | 讀取 |   | 開啟檔案以供讀取 |   | 從開頭讀取 |   | 開啟失敗 |

| `"w"`  |   | 寫入 |   | 建立檔案以供寫入 |   | 清除原有內容 |   | 建立新檔 |

| `"a"`  |   | 附加 |   | 在檔案末尾追加內容 |   | 從檔案末尾寫入 |   | 建立新檔 |

| `"r+"`  |   | 讀寫 |   | 開啟檔案以供讀取和寫入 |   | 從開頭讀取 |   | 發生錯誤 |

| `"w+"`  |   | 讀寫並建立 |   | 建立檔案以供讀取和寫入 |   | 清除原有內容 |   | 建立新檔 |

| `"a+"`  |   | 讀取並附加 |   | 開啟檔案以供讀取和寫入 |   | 從檔案末尾寫入 |   | 建立新檔 |

| 可選擇加上模式旗標 `"b"`，以二進位模式開啟檔案。在 POSIX 系統上此旗標沒有作用；在 Windows 上則會停用對 `'\n'` 和 `'\x1A'` 的特殊處理。使用附加模式時，不論目前檔案位置在哪裡，資料一律寫到檔案末尾。 |

| 若 `mode` 不屬於上表列出的字串，行為未定義。有些實作（例如 Windows）也支援其他模式。 |

| 更新模式（`'+'`）可同時讀取和寫入。寫入後若要讀取，中間必須呼叫 `fflush`、`fseek`、`fsetpos` 或 `rewind`；讀取後若要寫入，中間必須呼叫 `fseek`、`fsetpos` 或 `rewind`，除非讀取時已遇到檔案結尾。更新模式下，即使指定文字模式，實作也可以採用二進位模式。 |

| C11 起，可在 `"w"` 或 `"w+"` 後加上 `"x"`。若檔案已存在，開啟就會失敗，不會覆寫檔案。 |

| 使用 `fopen_s` 或 `freopen_s` 時，以 `"w"` 或 `"a"` 建立的檔案預設會限制其他使用者存取。C11 起，可在以 `"w"` 或 `"a"` 開頭的模式字串前加上 `"u"`，改用 `fopen` 的預設檔案權限。 |

### Return value

1) If successful, returns a pointer to the new file stream. The stream is fully buffered unless `filename` refers to an interactive device. On error, returns a null pointer. POSIX requires POSIX requires] that errno be set in this case.

2) If successful, returns zero and a pointer to the new file stream is written to `*streamptr`. On error, returns a non-zero error code and writes the null pointer to `*streamptr` (unless `streamptr` is a null pointer itself).

### Notes

The format of `filename` is implementation-defined, and does not necessarily refer to a file (e.g. it may be the console or another device accessible though filesystem API). On platforms that support them, `filename` may include absolute or relative filesystem path.
filename 的格式由實作定義，不一定代表檔案，也可能是主控臺或其他可透過檔案系統 API 存取的裝置。在支援路徑的平臺上，filename 可以是絕對或相對檔案路徑。

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

- 7.21.5.3 The fopen function (p: TBD)
7.21.5.3 fopen 函式（頁碼：待定）
7.21.5.3 fopen 函式（頁碼：待定）

- K.3.5.2.1 The fopen_s function (p: TBD)
K.3.5.2.1 fopen_s 函式（頁碼：待定）
K.3.5.2.1 fopen_s 函式（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.21.5.3 The fopen function (p: 223-224)
7.21.5.3 fopen 函式（頁碼：223-224）
7.21.5.3 fopen 函式（頁碼：223-224）

- K.3.5.2.1 The fopen_s function (p: 428-429)
K.3.5.2.1 fopen_s 函式（頁碼：428-429）
K.3.5.2.1 fopen_s 函式（頁碼：428-429）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.21.5.3 The fopen function (p: 305-306)
7.21.5.3 fopen 函式（頁碼：305-306）
7.21.5.3 fopen 函式（頁碼：305-306）

- K.3.5.2.1 The fopen_s function (p: 588-590)
K.3.5.2.1 fopen_s 函式（頁碼：588-590）
K.3.5.2.1 fopen_s 函式（頁碼：588-590）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.19.5.3 The fopen function (p: 271-272)
7.19.5.3 fopen 函式（頁碼：271-272）
7.19.5.3 fopen 函式（頁碼：271-272）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.9.5.3 The fopen function
4.9.5.3 fopen 函式
4.9.5.3 fopen 函式

### See also

fclose
|   | closes a file
(function)   |

fflush
|   | synchronizes an output stream with the actual file
(function)   |

freopenfreopen_s
(C11)
|   | open an existing stream with a different name
(function)   |

C++ documentation for fopen

---
來源頁路徑：`en.cppreference.com/c/io/fopen.html`

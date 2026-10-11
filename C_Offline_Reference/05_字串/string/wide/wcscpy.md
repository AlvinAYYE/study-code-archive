# wcscpy, wcscpy_s

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<wchar.h>`
|   |  |   |  |

```c
wchar_t* wcscpy( wchar_t* dest, const wchar_t* src );
```
|   |  (1) |   | (since C95)
(until C99) |

```c
wchar_t* wcscpy( wchar_t* restrict dest, const wchar_t* restrict src );
```
|   |   |   | (since C99) |

```c
errno_t wcscpy_s( wchar_t* restrict dest, rsize_t destsz,  const wchar_t* restrict src );
```
|   |  (2)  |   |  (since C11)  |

|  |  |  |  |

1) Copies the wide string pointed to by `src` (including the terminating null wide character) to wide character array pointed to by `dest`. The behavior is undefined if the `dest` array is not large enough. The behavior is undefined if the strings overlap.

2) Same as (1), except that it may clobber the rest of the destination array with unspecified values and that the following errors are detected at runtime and call the currently installed constraint handler function:
- `src` or `dest` is a null pointer
src 或 dest 為空指標

- `destsz` is zero or greater than `RSIZE_MAX / sizeof(wchar_t)`
destsz 為零或大於 RSIZE_MAX / sizeof ( wchar_t )

- `destsz` is less or equal `wcsnlen_s(src, destsz)`, in other words, truncation would occur
destsz 小於或等於 wcsnlen_s ( src , destsz ) ，換句話說，會發生截斷

- overlap would occur between the source and the destination strings
源字串和目標字串會發生重疊
src 或 dest 為空指標 destsz 為零或大於 RSIZE_MAX / sizeof ( wchar_t ) destsz 小於或等於 wcsnlen_s ( src , destsz ) ，換句話說，會發生截斷源字串和目標字串之間會發生重疊
As with all bounds-checked functions, `wcscpy_s` is only guaranteed to be available if `__STDC_LIB_EXT1__` is defined by the implementation and if the user defines `__STDC_WANT_LIB_EXT1__` to the integer constant `1` before including <wchar.h>.
與所有邊界檢查函式一樣，僅當實現定義了 __STDC_LIB_EXT1__ 且使用者在包含 <wchar.h> 之前將 __STDC_WANT_LIB_EXT1__ 定義為整數常量 1 時，才保證 wcscpy_s 可用。

### Parameters

| dest  |   | -  |   | pointer to the wide character array to copy to  |

| src  |   | -  |   | pointer to the null-terminated wide string to copy from  |

| destsz  |   | -  |   | maximum number of characters to write, typically the size of the destination buffer  |

### Return value

1) returns a copy of `dest`

2) returns zero on success, returns non-zero on error. Also, on error, writes `L'\0'` to `dest[0]` (unless `dest` is a null pointer or `destsz` is zero or greater than `RMAX_SIZE / sizeof(wchar_t)`).

### Example

Run this code

```c
#include <locale.h> #include <stdio.h> #include <wchar.h> int main(void) {  wchar_t* src = L"犬 means dog"; // src[0] = L'狗' ; // this would be undefined behavior  wchar_t dst[wcslen(src) + 1]; // +1 for the null terminator  wcscpy(dst, src);  dst[0] = L'狗'; // OK  setlocale(LC_ALL, "en_US.utf8");  printf("src = %ls\ndst = %ls\n", src, dst); }
```

Output:

```c
src = 犬 means dog dst = 狗 means dog
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.31.4.2.1 The wcscpy function (p: 438)
7.31.4.2.1 wcscpy 函式（頁碼：438）
7.31.4.2.1 wcscpy 函式（頁碼：438）

- K.3.9.3.1.1 The wcscpy_s function (p: 663)
K.3.9.3.1.1 wcscpy_s 函式（頁碼：663）
K.3.9.3.1.1 wcscpy_s 函式（頁碼：663）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.29.4.1.2 The wcscpy function (p: TBD)
7.29.4.1.2 wcscpy 函式（頁碼：待定）
7.29.4.1.2 wcscpy 函式（頁碼：待定）

- K.3.9.2.1.1 The wcscpy_s function (p: TBD)
K.3.9.2.1.1 wcscpy_s 函式（頁碼：待定）
K.3.9.2.1.1 wcscpy_s 函式（頁碼：待定）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.29.4.1.2 The wcscpy function (p: 430)
7.29.4.1.2 wcscpy 函式（頁碼：430）
7.29.4.1.2 wcscpy 函式（頁碼：430）

- K.3.9.2.1.1 The wcscpy_s function (p: 639)
K.3.9.2.1.1 wcscpy_s 函式（頁碼：639）
K.3.9.2.1.1 wcscpy_s 函式（頁碼：639）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.24.4.1.2 The wcscpy function (p: 376)
7.24.4.1.2 wcscpy 函式（頁碼：376）
7.24.4.1.2 wcscpy 函式（頁碼：376）

### See also

wcsncpywcsncpy_s
(C95)(C11)
|   | copies a certain amount of wide characters from one string to another
(function)   |

wmemcpywmemcpy_s
(C95)(C11)
|   | copies a certain amount of wide characters between two non-overlapping arrays
(function)   |

strcpystrcpy_s
(C11)
|   | copies one string to another
(function)   |

C++ documentation for wcscpy

---
來源頁路徑：`en.cppreference.com/c/string/wide/wcscpy.html`

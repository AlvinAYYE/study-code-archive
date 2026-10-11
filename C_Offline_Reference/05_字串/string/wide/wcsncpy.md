# wcsncpy, wcsncpy_s

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<wchar.h>`
|   |  |   |  |

```c
wchar_t* wcsncpy( wchar_t* dest, const wchar_t* src, size_t count );
```
|   |  (1) |   | (since C95)
(until C99) |

```c
wchar_t* wcsncpy( wchar_t* restrict dest, const wchar_t* restrict src, size_t count );
```
|   |   |   | (since C99) |

```c
errno_t wcsncpy_s( wchar_t* restrict dest, rsize_t destsz,  const wchar_t* restrict src, rsize_t count);
```
|   |  (2)  |   |  (since C11)  |

|  |  |  |  |

1) Copies at most `count` characters of the wide string pointed to by `src` (including the terminating null wide character) to wide character array pointed to by `dest`.

If `count` is reached before the entire string `src` was copied, the resulting wide character array is not null-terminated.

If, after copying the terminating null wide character from `src`, `count` is not reached, additional null wide characters are written to `dest` until the total of `count` characters have been written.

If the strings overlap, the behavior is undefined.

2) Same as (1), except that the function does not continue writing zeroes into the destination array to pad up to `count`, it stops after writing the terminating null character (if there was no null in the source, it writes one at `dest[count]` and then stops). Also, the following errors are detected at runtime and call the currently installed constraint handler function:
- `src` or `dest` is a null pointer
src 或 dest 為空指標

- `destsz` or `count` is zero or greater than `RSIZE_MAX / sizeof(wchar_t)`
destsz 或 count 為零或大於 RSIZE_MAX / sizeof ( wchar_t )

- `count` is greater or equal `destsz`, but `destsz` is less or equal `wcsnlen_s(src, count)`, in other words, truncation would occur
count 大於或等於 destsz ，但 destsz 小於或等於 wcsnlen_s ( src , count ) ，換句話說，會發生截斷

- overlap would occur between the source and the destination strings
源字串和目標字串會發生重疊
src 或 dest 為空指標 destsz 或 count 為零或大於 RSIZE_MAX / sizeof ( wchar_t ) count 大於或等於 destsz ，但 destsz 小於或等於 wcsnlen_s ( src , count ) ，換句話說，會發生截斷源字串和目標字串之間會發生重疊
As with all bounds-checked functions, `wcsncpy_s` is only guaranteed to be available if `__STDC_LIB_EXT1__` is defined by the implementation and if the user defines `__STDC_WANT_LIB_EXT1__` to the integer constant `1` before including <wchar.h>.
與所有邊界檢查函式一樣，僅當實現定義了 __STDC_LIB_EXT1__ 且使用者在包含 <wchar.h> 之前將 __STDC_WANT_LIB_EXT1__ 定義為整數常量 1 時，才保證 wcsncpy_s 可用。

### Parameters

| dest  |   | -  |   | pointer to the wide character array to copy to  |

| src  |   | -  |   | pointer to the wide string to copy from  |

| count  |   | -  |   | maximum number of wide characters to copy  |

| destsz  |   | -  |   | the size of the destination buffer  |

### Return value

1) returns a copy of `dest`

2) returns zero on success, returns non-zero on error. Also, on error, writes `L'\0'` to `dest[0]` (unless `dest` is a null pointer or `destsz` is zero or greater than `RSIZE_MAX / sizeof(wchar_t)`) and may clobber the rest of the destination array with unspecified values.

### Notes

In typical usage, `count` is the number of elements in the destination array.
在典型用法中， count 是目標陣列中的元素數。
Although truncation to fit the destination buffer is a security risk and therefore a runtime constraints violation for `wcsncpy_s`, it is possible to get the truncating behavior by specifying `count` equal to the size of the destination array minus one: it will copy the first `count` wide characters and append the null wide terminator as always:
雖然截斷以適應目標緩衝區是一種安全風險，因此對 wcsncpy_s 而言是執行時約束違規，但可以透過指定 count 等於目標陣列大小減一來獲得截斷行為：它將複製前 count 個寬字元，並像往常一樣追加空寬終止符：

```c
size_t count = sizeof dst / sizeof *dst; wcsncpy_s(dst, count, src, count - 1);
```

### Example

Run this code

```c
#include <locale.h> #include <stdio.h> #include <wchar.h>   int main(void) {  const wchar_t src[] = L"わゐ";  wchar_t dest[6] = {L'あ', L'い', L'う', L'え', L'お'};    wcsncpy(dest, src, 4); // this will copy わゐ and repeat L'\0' two times    puts("The contents of dest are: ");  setlocale(LC_ALL, "en_US.utf8");  const long dest_size = sizeof dest / sizeof *dest;  for(wchar_t* p = dest; p - dest != dest_size; ++p) {  *p ? printf("%lc ", *p)  : printf("\\0 ");  } }
```

Possible output:
可能的輸出：

```c
The contents of dest are: わ ゐ \0 \0 お \0
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.31.4.2.2 The wcsncpy function (p: 438)
7.31.4.2.2 wcsncpy 函式（頁碼：438）
7.31.4.2.2 wcsncpy 函式（頁碼：438）

- K.3.9.3.1.2 The wcsncpy_s function (p: 663-664)
K.3.9.3.1.2 wcsncpy_s 函式（頁碼：663-664）
K.3.9.3.1.2 wcsncpy_s 函式（頁碼：663-664）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.29.4.2.2 The wcsncpy function (p: 314)
7.29.4.2.2 wcsncpy 函式（頁碼：314）
7.29.4.2.2 wcsncpy 函式（頁碼：314）

- K.3.9.2.1.2 The wcsncpy_s function (p: 464)
K.3.9.2.1.2 wcsncpy_s 函式（頁碼：464）
K.3.9.2.1.2 wcsncpy_s 函式（頁碼：464）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.29.4.2.2 The wcsncpy function (p: 431)
7.29.4.2.2 wcsncpy 函式（頁碼：431）
7.29.4.2.2 wcsncpy 函式（頁碼：431）

- K.3.9.2.1.2 The wcsncpy_s function (p: 640-641)
K.3.9.2.1.2 wcsncpy_s 函式（頁碼：640-641）
K.3.9.2.1.2 wcsncpy_s 函式（頁碼：640-641）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.24.4.2.2 The wcsncpy function (p: 377)
7.24.4.2.2 wcsncpy 函式（頁碼：377）
7.24.4.2.2 wcsncpy 函式（頁碼：377）

### See also

wcscpywcscpy_s
(C95)(C11)
|   | copies one wide string to another
(function)   |

wmemcpywmemcpy_s
(C95)(C11)
|   | copies a certain amount of wide characters between two non-overlapping arrays
(function)   |

strncpystrncpy_s
(C11)
|   | copies a certain amount of characters from one string to another
(function)   |

C++ documentation for wcsncpy

---
來源頁路徑：`en.cppreference.com/c/string/wide/wcsncpy.html`

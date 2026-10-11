# mbstowcs, mbstowcs_s

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdlib.h>`
|   |  |   |  |

```c
size_t mbstowcs( wchar_t* dst, const char* src, size_t len)
```
|   |  (1) |   | (until C99) |

```c
size_t mbstowcs( wchar_t* restrict dst, const char* restrict src, size_t len)
```
|   |   |   | (since C99) |

```c
errno_t mbstowcs_s(size_t* restrict retval, wchar_t* restrict dst,  rsize_t dstsz, const char* restrict src, rsize_t len);
```
|   |  (2)  |   |  (since C11)  |

|  |  |  |  |

1) Converts a multibyte character string from the array whose first element is pointed to by `src` to its wide character representation. Converted characters are stored in the successive elements of the array pointed to by `dst`. No more than `len` wide characters are written to the destination array.

Each character is converted as if by a call to mbtowc, except that the mbtowc conversion state is unaffected. The conversion stops if:
- The multibyte null character was converted and stored.
多位元組空字元已被轉換並儲存。

- An invalid (in the current C locale) multibyte character was encountered.
遇到了無效的（在目前 C locale 下）多位元組字元。

- The next wide character to be stored would exceed `len`.
下一個要儲存的寬字元將超出 len。

If `src` and `dst` overlap, the behavior is undefined

2) Same as (1), except that
- conversion is as-if by mbrtowc, not mbtowc
轉換等同於由 mbrtowc 完成，而非 mbtowc

- the function returns its result as an out-parameter `retval`
函式透過輸出參數 retval 傳回其結果

- if no null character was written to `dst` after `len` wide characters were written, then `L'\0'` is stored in `dst[len]`, which means len+1 total wide characters are written
如果寫入 len 個寬字元後 dst 中未寫入空字元，則將 L '\0' 儲存到 dst[len] 中，這意味著總共寫入 len+1 個寬字元

- if `dst` is a null pointer, the number of wide characters that would be produced is stored in `*retval`
如果 dst 是空指標，則將將要產生的寬字元數儲存到 * retval 中

- the function clobbers the destination array from the terminating null and until `dstsz`
函式從結束空字元開始一直覆寫目標陣列直到 dstsz

- If `src` and `dst` overlap, the behavior is unspecified.
如果 src 和 dst 重疊，則行為未指定。

- the following errors are detected at runtime and call the currently installed constraint handler function:
以下錯誤在執行時被檢測到，並呼叫目前安裝的約束處理函式：

- `retval` or `src` is a null pointer
retval 或 src 是空指標

- `dstsz` or `len` is greater than RSIZE_MAX / sizeof(wchar_t) (unless `dst` is null)
dstsz 或 len 大於 RSIZE_MAX / sizeof(wchar_t)（除非 dst 為空）

- `dstsz` is not zero (unless `dst` is null)
dstsz 不為零（除非 dst 為空）

- There is no null character in the first `dstsz` multibyte characters in the `src` array and `len` is greater than `dstsz` (unless `dst` is null)
src 陣列的前 dstsz 個多位元組字元中沒有空字元且 len 大於 dstsz（除非 dst 為空）
retval 或 src 是空指標 dstsz 或 len 大於 RSIZE_MAX / sizeof(wchar_t)（除非 dst 為空） dstsz 不為零（除非 dst 為空） src 陣列的前 dstsz 個多位元組字元中沒有空字元且 len 大於 dstsz（除非 dst 為空）
As with all bounds-checked functions, `mbstowcs_s` is only guaranteed to be available if `__STDC_LIB_EXT1__` is defined by the implementation and if the user defines `__STDC_WANT_LIB_EXT1__` to the integer constant `1` before including <stdlib.h>.
與所有邊界檢查函式一樣，只有當實現定義了 __STDC_LIB_EXT1__ 且使用者在包含 <stdlib.h> 之前將 __STDC_WANT_LIB_EXT1__ 定義為整數常量 1 時，才保證 mbstowcs_s 可用。

### Notes

In most implementations, `mbstowcs` updates a global static object of type mbstate_t as it processes through the string, and cannot be called simultaneously by two threads, mbsrtowcs should be used in such cases.
在大多數實現中，mbstowcs 在處理字串時會更新一個 mbstate_t 型別的全域性靜態物件，無法被兩個執行緒同時呼叫，此時應使用 mbsrtowcs。
POSIX specifies a common extension: if `dst` is a null pointer, this function returns the number of wide characters that would be written to `dst`, if converted. Similar behavior is standard for `mbstowcs_s` and for mbsrtowcs.
POSIX 規定了一個常見擴充套件：如果 dst 是空指標，則此函式傳回若進行轉換將寫入 dst 的寬字元數。類似行為對 mbstowcs_s 和 mbsrtowcs 而言是標準的。

### Parameters

| dst  |   | -  |   | pointer to wide character array where the wide string will be stored  |

| src  |   | -  |   | pointer to the first element of a null-terminated multibyte string to convert  |

| len  |   | -  |   | number of wide characters available in the array pointed to by dst  |

| dstsz  |   | -  |   | max number of wide characters that will be written (size of the `dst` array)  |

| retval  |   | -  |   | pointer to a size_t object where the result will be stored  |

### Return value

1) On success, returns the number of wide characters, excluding the terminating `L'\0'`, written to the destination array. On conversion error (if invalid multibyte character was encountered), returns `(size_t)-1`.

2) zero on success (in which case the number of wide characters excluding terminating zero that were, or would be written to `dst`, is stored in `*retval`), non-zero on error. In case of a runtime constraint violation, stores `(size_t)-1` in `*retval` (unless `retval` is null) and sets `dst[0]` to `L'\0'` (unless `dst` is null or `dstmax` is zero or greater than RSIZE_MAX)

### Example

Run this code

```c
#include <locale.h> #include <stdio.h> #include <stdlib.h> #include <wchar.h> int main(void) {  setlocale(LC_ALL, "en_US.utf8");  const char* mbstr = u8"z\u00df\u6c34\U0001F34C"; // or u8"zß水🍌"  wchar_t wstr[5];  mbstowcs(wstr, mbstr, 5);  wprintf(L"MB string: %s\n", mbstr);  wprintf(L"Wide string: %ls\n", wstr); }
```

Output:

```c
MB string: zß水🍌 Wide string: zß水🍌
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.22.8.1 The mbstowcs function (p: TBD)
7.22.8.1 mbstowcs 函式（p: TBD）
7.22.8.1 mbstowcs 函式（p: TBD）

- K.3.6.5.1 The mbstowcs_s function (p: TBD)
K.3.6.5.1 mbstowcs_s 函式（p: TBD）
K.3.6.5.1 mbstowcs_s 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.22.8.1 The mbstowcs function (p: TBD)
7.22.8.1 mbstowcs 函式（p: TBD）
7.22.8.1 mbstowcs 函式（p: TBD）

- K.3.6.5.1 The mbstowcs_s function (p: TBD)
K.3.6.5.1 mbstowcs_s 函式（p: TBD）
K.3.6.5.1 mbstowcs_s 函式（p: TBD）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.22.8.1 The mbstowcs function (p: 359)
7.22.8.1 mbstowcs 函式（p: 359）
7.22.8.1 mbstowcs 函式（p: 359）

- K.3.6.5.1 The mbstowcs_s function (p: 611-612)
K.3.6.5.1 mbstowcs_s 函式（p: 611-612）
K.3.6.5.1 mbstowcs_s 函式（p: 611-612）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.20.8.1 The mbstowcs function (p: 323)
7.20.8.1 mbstowcs 函式（p: 323）
7.20.8.1 mbstowcs 函式（p: 323）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.10.8.1 The mbstowcs function
4.10.8.1 mbstowcs 函式
4.10.8.1 mbstowcs 函式

### See also

mbsrtowcsmbsrtowcs_s
(C95)(C11)
|   | converts a narrow multibyte character string to wide string, given state
(function)   |

wcstombswcstombs_s
(C11)
|   | converts a wide string to narrow multibyte character string
(function)   |

C++ documentation for mbstowcs

---
來源頁路徑：`en.cppreference.com/c/string/multibyte/mbstowcs.html`

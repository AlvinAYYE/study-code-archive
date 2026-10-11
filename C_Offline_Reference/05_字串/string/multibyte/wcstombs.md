# wcstombs, wcstombs_s

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdlib.h>`
|   |  |   |  |

```c
size_t wcstombs( char* dst, const wchar_t* src, size_t len );
```
|   |  (1) |   | (until C99) |

```c
size_t wcstombs( char* restrict dst, const wchar_t* restrict src, size_t len );
```
|   |   |   | (since C99) |

```c
errno_t wcstombs_s( size_t* restrict retval, char* restrict dst, rsize_t dstsz,  const wchar_t* restrict src, rsize_t len );
```
|   |  (2)  |   |  (since C11)  |

|  |  |  |  |

1) Converts a sequence of wide characters from the array whose first element is pointed to by `src` to its narrow multibyte representation that begins in the initial shift state. Converted characters are stored in the successive elements of the char array pointed to by `dst`. No more than `len` bytes are written to the destination array.

Each character is converted as if by a call to wctomb, except that the wctomb's conversion state is unaffected. The conversion stops if:
- The null character `L'\0'` was converted and stored. The bytes stored in this case are the unshift sequence (if necessary) followed by `'\0'`,
空字元 L '\0' 已被轉換並儲存。此情況下儲存的位元組是（必要的）復位序列後跟 '\0'，

- A `wchar_t` was found that does not correspond to a valid character in the current C locale.
發現了在目前 C locale 中不對應任何有效字元的 wchar_t。

- The next multibyte character to be stored would exceed `len`.
下一個要儲存的多位元組字元將超出 len。

If `src` and `dst` overlap, the behavior is unspecified.

2) Same as (1), except that
- conversion is as-if by wcrtomb, not wctomb
轉換等同於由 wcrtomb 完成，而非 wctomb

- the function returns its result as an out-parameter `retval`
函式透過輸出參數 retval 傳回其結果

- if the conversion stops without writing a null character, the function will store `'\0'` in the next byte in `dst`, which may be `dst[len]` or `dst[dstsz]`, whichever comes first (meaning up to len+1/dstsz+1 total bytes may be written). In this case, there may be no unshift sequence written before the terminating null.
如果轉換停止時未寫入空字元，函式將在 dst 的下一個位元組中儲存 '\0'，該位元組可能是 dst[len] 或 dst[dstsz]，以先到者為準（這意味著總共最多可寫入 len+1/dstsz+1 個位元組）。在這種情況下，結束空字元之前可能沒有寫入復位序列。

- if `dst` is a null pointer, the number of bytes that would be produced is stored in `*retval`
如果 dst 是空指標，則將將要產生的位元組數儲存到 * retval 中

- the function clobbers the destination array from the terminating null and until `dstsz`
函式從結束空字元開始一直覆寫目標陣列直到 dstsz

- If `src` and `dst` overlap, the behavior is unspecified.
如果 src 和 dst 重疊，則行為未指定。

- the following errors are detected at runtime and call the currently installed constraint handler function:
以下錯誤在執行時被檢測到，並呼叫目前安裝的約束處理函式：

- `retval` or `src` is a null pointer
retval 或 src 是空指標

- `dstsz` or `len` is greater than RSIZE_MAX (unless `dst` is null)
dstsz 或 len 大於 RSIZE_MAX（除非 dst 為空）

- `dstsz` is not zero (unless `dst` is null)
dstsz 不為零（除非 dst 為空）

- `len` is greater than `dstsz` and the conversion does not encounter null or encoding error in the `src` array by the time `dstsz` is reached (unless `dst` is null)
len 大於 dstsz 且轉換在達到 dstsz 之前未在 src 陣列中遇到空字元或編碼錯誤（除非 dst 為空）
retval 或 src 是空指標 dstsz 或 len 大於 RSIZE_MAX（除非 dst 為空） dstsz 不為零（除非 dst 為空） len 大於 dstsz 且轉換在達到 dstsz 之前未在 src 陣列中遇到空字元或編碼錯誤（除非 dst 為空）
As with all bounds-checked functions, `wcstombs_s` is only guaranteed to be available if `__STDC_LIB_EXT1__` is defined by the implementation and if the user defines `__STDC_WANT_LIB_EXT1__` to the integer constant `1` before including <stdlib.h>.

### Notes

In most implementations, `wcstombs` updates a global static object of type mbstate_t as it processes through the string, and cannot be called simultaneously by two threads, wcsrtombs or `wcstombs_s` should be used in such cases.
在大多數實現中，wcstombs 在處理字串時會更新一個 mbstate_t 型別的全域性靜態物件，無法被兩個執行緒同時呼叫，此時應使用 wcsrtombs 或 wcstombs_s。
POSIX specifies a common extension: if `dst` is a null pointer, this function returns the number of bytes that would be written to `dst`, if converted. Similar behavior is standard for wcsrtombs and `wcstombs_s`.
POSIX 規定了一個常見擴充套件：如果 dst 是空指標，則此函式傳回若進行轉換將寫入 dst 的位元組數。類似行為對 wcsrtombs 和 wcstombs_s 而言是標準的。

### Parameters

| dst  |   | -  |   | pointer to narrow character array where the multibyte character will be stored  |

| src  |   | -  |   | pointer to the first element of a null-terminated wide string to convert  |

| len  |   | -  |   | number of bytes available in the array pointed to by dst  |

| dstsz  |   | -  |   | max number of bytes that will be written (size of the `dst` array)  |

| retval  |   | -  |   | pointer to a size_t object where the result will be stored  |

### Return value

1) On success, returns the number of bytes (including any shift sequences, but excluding the terminating `'\0'`) written to the character array whose first element is pointed to by `dst`. On conversion error (if invalid wide character was encountered), returns `(size_t)-1`.

2) Returns zero on success (in which case the number of bytes excluding terminating zero that were, or would be written to `dst`, is stored in `*retval`), non-zero on error. In case of a runtime constraint violation, stores `(size_t)-1` in `*retval` (unless `retval` is null) and sets `dst[0]` to `'\0'` (unless `dst` is null or `dstmax` is zero or greater than RSIZE_MAX)

### Example

Run this code

```c
#include <locale.h> #include <stdio.h> #include <stdlib.h> int main(void) {  // 4 wide characters  const wchar_t src[] = L"z\u00df\u6c34\U0001f34c";  // they occupy 10 bytes in UTF-8  char dst[11];  setlocale(LC_ALL, "en_US.utf8");  printf("wide-character string: '%ls'\n",src);  for (size_t ndx = 0; ndx < sizeof src / sizeof src[0]; ++ndx)  printf(" src[%2zu] = %#8x\n", ndx, src[ndx]);    int rtn_val = wcstombs(dst, src, sizeof dst);  printf("rtn_val = %d\n", rtn_val);  if (rtn_val > 0)  printf("multibyte string: '%s'\n",dst);  for (size_t ndx = 0; ndx < sizeof dst; ++ndx)  printf(" dst[%2zu] = %#2x\n", ndx, (unsigned char)dst[ndx]); }
```

Output:

```c
wide-character string: 'zß水🍌' src[ 0] = 0x7a src[ 1] = 0xdf src[ 2] = 0x6c34 src[ 3] = 0x1f34c src[ 4] = 0 rtn_val = 10 multibyte string: 'zß水🍌' dst[ 0] = 0x7a dst[ 1] = 0xc3 dst[ 2] = 0x9f dst[ 3] = 0xe6 dst[ 4] = 0xb0 dst[ 5] = 0xb4 dst[ 6] = 0xf0 dst[ 7] = 0x9f dst[ 8] = 0x8d dst[ 9] = 0x8c dst[10] = 0
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.22.8.2 The wcstombs function (p: TBD)
7.22.8.2 wcstombs 函式（p: TBD）
7.22.8.2 wcstombs 函式（p: TBD）

- K.3.6.5.2 The wcstombs_s function (p: TBD)
K.3.6.5.2 wcstombs_s 函式（p: TBD）
K.3.6.5.2 wcstombs_s 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.22.8.2 The wcstombs function (p: TBD)
7.22.8.2 wcstombs 函式（p: TBD）
7.22.8.2 wcstombs 函式（p: TBD）

- K.3.6.5.2 The wcstombs_s function (p: TBD)
K.3.6.5.2 wcstombs_s 函式（p: TBD）
K.3.6.5.2 wcstombs_s 函式（p: TBD）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.22.8.2 The wcstombs function (p: 360)
7.22.8.2 wcstombs 函式（p: 360）
7.22.8.2 wcstombs 函式（p: 360）

- K.3.6.5.2 The wcstombs_s function (p: 612-614)
K.3.6.5.2 wcstombs_s 函式（p: 612-614）
K.3.6.5.2 wcstombs_s 函式（p: 612-614）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.20.8.2 The wcstombs function (p: 324)
7.20.8.2 wcstombs 函式（p: 324）
7.20.8.2 wcstombs 函式（p: 324）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.10.8.2 The wcstombs function
4.10.8.2 wcstombs 函式
4.10.8.2 wcstombs 函式

### See also

wcsrtombswcsrtombs_s
(C95)(C11)
|   | converts a wide string to narrow multibyte character string, given state
(function)   |

mbstowcsmbstowcs_s
(C11)
|   | converts a narrow multibyte character string to wide string
(function)   |

C++ documentation for wcstombs

---
來源頁路徑：`en.cppreference.com/c/string/multibyte/wcstombs.html`

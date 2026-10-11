# wcsrtombs, wcsrtombs_s

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<wchar.h>`
|   |  |   |  |

```c
size_t wcsrtombs( char *dst, const wchar_t **src, size_t len, mbstate_t* ps );
```
|   |  (1) |   | (since C95)
(until C99) |

```c
size_t wcsrtombs( char *restrict dst, const wchar_t **restrict src, size_t len,  mbstate_t *restrict ps );
```
|   |   |   | (since C99) |

```c
errno_t wcsrtombs_s( size_t *restrict retval, char *restrict dst, rsize_t dstsz,  const wchar_t **restrict src, rsize_t len,  mbstate_t *restrict ps );
```
|   |  (2)  |   |  (since C11)  |

|  |  |  |  |

1) Converts a sequence of wide characters from the array whose first element is pointed to by `*src` to its narrow multibyte representation that begins in the conversion state described by `*ps`. If `dst` is not null, converted characters are stored in the successive elements of the char array pointed to by `dst`. No more than `len` bytes are written to the destination array. Each character is converted as if by a call to wcrtomb. The conversion stops if:
- The null character `L'\0'` was converted and stored. The bytes stored in this case are the unshift sequence (if necessary) followed by `'\0'`, `*src` is set to null pointer value and `*ps` represents the initial shift state.
空字元 L '\0' 已被轉換並儲存。此種情況下儲存的位元組是復原序列（如有必要）後跟 '\0' ，* src 被設定為空指標值，* ps 表示初始移位狀態。

- A `wchar_t` was found that does not correspond to a valid character in the current C locale. `*src` is set to point at the first unconverted wide character.
發現了在目前 C 區域設定中不對應有效字元的 wchar_t 。* src 被設定為指向第一個未轉換的寬字元。

- the next multibyte character to be stored would exceed `len`. `*src` is set to point at the first unconverted wide character. This condition is not checked if `dst` is a null pointer.
要儲存的下一個多位元組字元將超出 len 。* src 被設定為指向第一個未轉換的寬字元。如果 dst 是空指標，則不會檢查此條件。

2) Same as (1), except that
- the function returns its result as an out-parameter `retval`
函式透過輸出參數 retval 傳回其結果

- if the conversion stops without writing a null character, the function will store `'\0'` in the next byte in `dst`, which may be `dst[len]` or `dst[dstsz]`, whichever comes first (meaning up to len+1/dstsz+1 total bytes may be written). In this case, there may be no unshift sequence written before the terminating null.
如果轉換在未寫入空字元的情況下停止，函式將在 dst 中的下一個位元組儲存 '\0' ，該位元組可能是 dst [ len ] 或 dst [ dstsz ] （以先出現者為準）（這意味著最多可寫入 len+1/dstsz+1 個總位元組）。在這種情況下，終止空字元之前可能沒有寫入復原序列。

- the function clobbers the destination array from the terminating null and until `dstsz`
函式從結束空字元開始一直覆寫目標陣列直到 dstsz

- If `src` and `dst` overlap, the behavior is unspecified.
如果 src 和 dst 重疊，則行為未指定。

- the following errors are detected at runtime and call the currently installed constraint handler function:
以下錯誤在執行時被檢測到，並呼叫目前安裝的約束處理函式：

- `retval`, `ps`, `src`, or `*src` is a null pointer
retval 、 ps 、 src 或 * src 是空指標

- `dstsz` or `len` is greater than RSIZE_MAX (unless `dst` is null)
dstsz 或 len 大於 RSIZE_MAX（除非 dst 為空）

- `dstsz` is not zero (unless `dst` is null)
dstsz 不為零（除非 dst 為空）

- `len` is greater than `dstsz` and the conversion does not encounter null or encoding error in the `src` array by the time `dstsz` is reached (unless `dst` is null)
len 大於 dstsz 且轉換在達到 dstsz 之前未在 src 陣列中遇到空字元或編碼錯誤（除非 dst 為空）
retval 、 ps 、 src 或 * src 是空指標 dstsz 或 len 大於 RSIZE_MAX（除非 dst 為空）dstsz 不為零（除非 dst 為空）len 大於 dstsz，且轉換在到達 dstsz 之前未在 src 陣列中遇到空字元或編碼錯誤（除非 dst 為空）
As with all bounds-checked functions, `wcsrtombs_s` is only guaranteed to be available if `__STDC_LIB_EXT1__` is defined by the implementation and if the user defines `__STDC_WANT_LIB_EXT1__` to the integer constant `1` before including <wchar.h>.
與所有邊界檢查函式一樣，只有當實現定義了 __STDC_LIB_EXT1__ ，且使用者在包含 <wchar.h> 之前將 __STDC_WANT_LIB_EXT1__ 定義為整數常量 1 時，才保證 wcsrtombs_s 可用。

### Parameters

| dst  |   | -  |   | pointer to narrow character array where the multibyte characters will be stored  |

| src  |   | -  |   | pointer to pointer to the first element of a null-terminated wide string  |

| len  |   | -  |   | number of bytes available in the array pointed to by dst  |

| ps  |   | -  |   | pointer to the conversion state object  |

| dstsz  |   | -  |   | max number of bytes that will be written (size of the `dst` array)  |

| retval  |   | -  |   | pointer to a size_t object where the result will be stored  |

### Return value

1) On success, returns the number of bytes (including any shift sequences, but excluding the terminating `'\0'`) written to the character array whose first element is pointed to by `dst`. If `dst` is a null pointer, returns the number of bytes that would have been written. On conversion error (if invalid wide character was encountered), returns `(size_t)-1`, stores EILSEQ in errno, and leaves `*ps` in unspecified state.

2) Returns zero on success (in which case the number of bytes excluding terminating zero that were, or would be written to `dst`, is stored in `*retval`), non-zero on error. In case of a runtime constraint violation, stores `(size_t)-1` in `*retval` (unless `retval` is null) and sets `dst[0]` to `'\0'` (unless `dst` is null or `dstmax` is zero or greater than RSIZE_MAX)

### Example

Run this code

```c
#include <stdio.h> #include <locale.h> #include <string.h> #include <wchar.h> void print_wide(const wchar_t* wstr) {  mbstate_t state;  memset(&state, 0, sizeof state);  size_t len = 1 + wcsrtombs(NULL, &wstr, 0, &state);  char mbstr[len];  wcsrtombs(mbstr, &wstr, len, &state);  printf("Multibyte string: %s\n", mbstr);  printf("Length, including '\\0': %zu\n", len); } int main(void) {  setlocale(LC_ALL, "en_US.utf8");  print_wide(L"z\u00df\u6c34\U0001f34c"); // or L"zß水🍌" }
```

Output:

```c
Multibyte string: zß水🍌 Length, including '\0': 11
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.29.6.4.2 The wcsrtombs function (p: 324-325)
7.29.6.4.2 wcsrtombs 函式（p: 324-325）
7.29.6.4.2 wcsrtombs 函式（p: 324-325）

- K.3.9.3.2.2 The wcsrtombs_s function (p: 471-472)
K.3.9.3.2.2 wcsrtombs_s 函式（p: 471-472）
K.3.9.3.2.2 wcsrtombs_s 函式（p: 471-472）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.29.6.4.2 The wcsrtombs function (p: 446)
7.29.6.4.2 wcsrtombs 函式（p: 446）
7.29.6.4.2 wcsrtombs 函式（p: 446）

- K.3.9.3.2.2 The wcsrtombs_s function (p: 649-651)
K.3.9.3.2.2 wcsrtombs_s 函式（p: 649-651）
K.3.9.3.2.2 wcsrtombs_s 函式（p: 649-651）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.24.6.4.2 The wcsrtombs function (p: 392)
7.24.6.4.2 wcsrtombs 函式（p: 392）
7.24.6.4.2 wcsrtombs 函式（p: 392）

### See also

wcstombswcstombs_s
(C11)
|   | converts a wide string to narrow multibyte character string
(function)   |

wcrtombwcrtomb_s
(C95)(C11)
|   | converts a wide character to its multibyte representation, given state
(function)   |

mbsrtowcsmbsrtowcs_s
(C95)(C11)
|   | converts a narrow multibyte character string to wide string, given state
(function)   |

C++ documentation for wcsrtombs

---
來源頁路徑：`en.cppreference.com/c/string/multibyte/wcsrtombs.html`

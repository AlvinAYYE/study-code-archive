# mbsrtowcs, mbsrtowcs_s

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<wchar.h>`
|   |  |   |  |

```c
size_t mbsrtowcs( wchar_t* dst, const char** src, size_t len, mbstate_t* ps );
```
|   |  (1) |   | (since C95)
(until C99) |

```c
size_t mbsrtowcs( wchar_t *restrict dst, const char **restrict src, size_t len,  mbstate_t *restrict ps );
```
|   |   |   | (since C99) |

```c
errno_t mbsrtowcs_s( size_t *restrict retval,  wchar_t *restrict dst, rsize_t dstsz,  const char **restrict src, rsize_t len,  mbstate_t *restrict ps );
```
|   |  (2)  |   |  (since C11)  |

|  |  |  |  |

1) Converts a null-terminated multibyte character sequence, which begins in the conversion state described by `*ps`, from the array whose first element is pointed to by `*src` to its wide character representation. If `dst` is not null, converted characters are stored in the successive elements of the wchar_t array pointed to by `dst`. No more than `len` wide characters are written to the destination array. Each multibyte character is converted as if by a call to mbrtowc. The conversion stops if:
- The multibyte null character was converted and stored. `*src` is set to null pointer value and `*ps` represents the initial shift state.
多位元組空字元已被轉換並儲存。* src 被設定為空指標值，*ps 表示初始移位狀態。

- An invalid multibyte character (according to the current C locale) was encountered. `*src` is set to point at the beginning of the first unconverted multibyte character.
遇到了無效的多位元組字元（根據目前 C 區域設定）。* src 被設定為指向第一個未轉換多位元組字元的起始位置。

- the next wide character to be stored would exceed `len`. `*src` is set to point at the beginning of the first unconverted multibyte character. This condition is not checked if `dst` is a null pointer.
要儲存的下一個寬字元將超出 len 。* src 被設定為指向第一個未轉換多位元組字元的起始位置。如果 dst 是空指標，則不會檢查此條件。

2) Same as (1), except that
- the function returns its result as an out-parameter `retval`
函式透過輸出參數 retval 傳回其結果

- if no null character was written to `dst` after `len` wide characters were written, then `L'\0'` is stored in `dst[len]`, which means len+1 total wide characters are written
如果寫入 len 個寬字元後 dst 中未寫入空字元，則將 L '\0' 儲存到 dst[len] 中，這意味著總共寫入 len+1 個寬字元

- the function clobbers the destination array from the terminating null and until `dstsz`
函式從結束空字元開始一直覆寫目標陣列直到 dstsz

- If `src` and `dst` overlap, the behavior is unspecified.
如果 src 和 dst 重疊，則行為未指定。

- the following errors are detected at runtime and call the currently installed constraint handler function:
以下錯誤在執行時被檢測到，並呼叫目前安裝的約束處理函式：

- `retval`, `ps`, `src`, or `*src` is a null pointer
retval 、 ps 、 src 或 * src 是空指標

- `dstsz` or `len` is greater than RSIZE_MAX/sizeof(wchar_t) (unless `dst` is null)
dstsz 或 len 大於 RSIZE_MAX/sizeof(wchar_t)（除非 dst 為空）

- `dstsz` is not zero (unless `dst` is null)
dstsz 不為零（除非 dst 為空）

- There is no null character in the first `dstsz` multibyte characters in the `*src` array and `len` is greater than `dstsz` (unless `dst` is null)
* src 陣列的前 dstsz 個多位元組字元中沒有空字元且 len 大於 dstsz（除非 dst 為空）
retval 、 ps 、 src 或 * src 是空指標 dstsz 或 len 大於 RSIZE_MAX/sizeof(wchar_t)（除非 dst 為空）dstsz 不為零（除非 dst 為空）* src 陣列的前 dstsz 個多位元組字元中沒有空字元且 len 大於 dstsz（除非 dst 為空）
As with all bounds-checked functions, `mbsrtowcs_s` is only guaranteed to be available if `__STDC_LIB_EXT1__` is defined by the implementation and if the user defines `__STDC_WANT_LIB_EXT1__` to the integer constant `1` before including <wchar.h>.
與所有邊界檢查函式一樣，只有當實現定義了 __STDC_LIB_EXT1__ ，且使用者在包含 <wchar.h> 之前將 __STDC_WANT_LIB_EXT1__ 定義為整數常量 1 時，才保證 mbsrtowcs_s 可用。

### Parameters

| dst  |   | -  |   | pointer to wide character array where the results will be stored  |

| src  |   | -  |   | pointer to pointer to the first element of a null-terminated multibyte string  |

| len  |   | -  |   | number of wide characters available in the array pointed to by dst  |

| ps  |   | -  |   | pointer to the conversion state object  |

| dstsz  |   | -  |   | max number of wide characters that will be written (size of the `dst` array)  |

| retval  |   | -  |   | pointer to a size_t object where the result will be stored  |

### Return value

1) On success, returns the number of wide characters, excluding the terminating `L'\0'`, written to the character array. If `dst` is a null pointer, returns the number of wide characters that would have been written given unlimited length. On conversion error (if invalid multibyte character was encountered), returns `(size_t)-1`, stores EILSEQ in errno, and leaves `*ps` in unspecified state.

2) zero on success (in which case the number of wide characters excluding terminating zero that were, or would be written to `dst`, is stored in `*retval`), non-sero on error. In case of a runtime constraint violation, stores `(size_t)-1` in `*retval` (unless `retval` is null) and sets `dst[0]` to `L'\0'` (unless `dst` is null or `dstmax` is zero or greater than RSIZE_MAX)

### Example

Run this code

```c
#include <stdio.h> #include <locale.h> #include <wchar.h> #include <string.h> void print_as_wide(const char* mbstr) {  mbstate_t state;  memset(&state, 0, sizeof state);  size_t len = 1 + mbsrtowcs(NULL, &mbstr, 0, &state);  wchar_t wstr[len];  mbsrtowcs(&wstr[0], &mbstr, len, &state);  wprintf(L"Wide string: %ls \n", wstr);  wprintf(L"The length, including L'\\0': %zu\n", len); } int main(void) {  setlocale(LC_ALL, "en_US.utf8");  print_as_wide(u8"z\u00df\u6c34\U0001f34c"); // u8"zß水🍌" }
```

Output:

```c
Wide string: zß水🍌 The length, including L'\0': 5
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.29.6.4.1 The mbsrtowcs function (p: 445)
7.29.6.4.1 mbsrtowcs 函式（p: 445）
7.29.6.4.1 mbsrtowcs 函式（p: 445）

- K.3.9.3.2.1 The mbsrtowcs_s function (p: 648-649)
K.3.9.3.2.1 mbsrtowcs_s 函式（p: 648-649）
K.3.9.3.2.1 mbsrtowcs_s 函式（p: 648-649）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.24.6.4.1 The mbsrtowcs function (p: 391)
7.24.6.4.1 mbsrtowcs 函式（p: 391）
7.24.6.4.1 mbsrtowcs 函式（p: 391）

### See also

mbstowcsmbstowcs_s
(C11)
|   | converts a narrow multibyte character string to wide string
(function)   |

mbrtowc
(C95)
|   | converts the next multibyte character to wide character, given state
(function)   |

wcsrtombswcsrtombs_s
(C95)(C11)
|   | converts a wide string to narrow multibyte character string, given state
(function)   |

C++ documentation for mbsrtowcs

---
來源頁路徑：`en.cppreference.com/c/string/multibyte/mbsrtowcs.html`

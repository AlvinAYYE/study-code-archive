# wctomb, wctomb_s

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdlib.h>`
|   |  |   |  |

```c
int wctomb( char *s, wchar_t wc );
```
|   |  (1)  |   |   |

```c
errno_t wctomb_s( int *restrict status, char *restrict s, rsize_t ssz, wchar_t wc );
```
|   |  (2)  |   |  (since C11)  |

|  |  |  |  |

1) Converts a wide character `wc` to multibyte encoding and stores it (including any shift sequences) in the char array whose first element is pointed to by `s`. No more than `MB_CUR_MAX` characters are stored. The conversion is affected by the current locale's LC_CTYPE category.

If `wc` is the null character, the null byte is written to `s`, preceded by any shift sequences necessary to restore the initial shift state.

If `s` is a null pointer, this function resets the global conversion state and determines whether shift sequences are used.

2) Same as (1), except that the result is returned in the out-parameter `status` and the following errors are detected at runtime and call the currently installed constraint handler function:
- `ssz` is less than the number of bytes that would be written (unless `s` is null)
ssz 小於將要寫入的位元組數（除非 s 為空）

- `ssz` is greater than RSIZE_MAX (unless `s` is null)
ssz 大於 RSIZE_MAX（除非 s 為空）

- `s` is a null pointer but `ssz` is not zero
s 是空指標但 ssz 不為零
ssz 小於將要寫入的位元組數（除非 s 為空） ssz 大於 RSIZE_MAX（除非 s 為空） s 是空指標但 ssz 不為零
As with all bounds-checked functions, `wctomb_s` is only guaranteed to be available if `__STDC_LIB_EXT1__` is defined by the implementation and if the user defines `__STDC_WANT_LIB_EXT1__` to the integer constant `1` before including <stdlib.h>.
與所有邊界檢查函式一樣，只有當實現定義了 __STDC_LIB_EXT1__ 且使用者在包含 <stdlib.h> 之前將 __STDC_WANT_LIB_EXT1__ 定義為整數常量 1 時，才保證 wctomb_s 可用。

### Notes

Each call to `wctomb` updates the internal global conversion state (a static object of type mbstate_t, known only to this function). If the multibyte encoding uses shift states, this function is not reentrant. In any case, multiple threads should not call `wctomb` without synchronization: wcrtomb or `wctomb_s` may be used instead.
每次呼叫 wctomb 都會更新內部的全域性轉換狀態（一個 mbstate_t 型別的靜態物件，僅該函式知道）。如果多位元組編碼使用移位狀態，則此函式不可重入。無論哪種情況，多個執行緒都不應在沒有同步的情況下呼叫 wctomb：可改用 wcrtomb 或 wctomb_s。
Unlike most bounds-checked functions, `wctomb_s` does not null-terminate its output, because it is designed to be used in loops that process strings character-by-character.
與大多數邊界檢查函式不同，wctomb_s 不會為其輸出新增空字元結束符，因為它被設計用於逐字元處理字串的迴圈中。

### Parameters

| s  |   | -  |   | pointer to the character array for output  |

| wc  |   | -  |   | wide character to convert  |

| ssz  |   | -  |   | maximum number of bytes to write to `s` (size of the array `s`)  |

| status  |   | -  |   | pointer to an out-parameter where the result (length of the multibyte sequence or the shift sequence status) will be stored  |

### Return value

1) If `s` is not a null pointer, returns the number of bytes that are contained in the multibyte representation of `wc` or `-1` if `wc` is not a valid character.

If `s` is a null pointer, resets its internal conversion state to represent the initial shift state and returns `0` if the current multibyte encoding is not state-dependent (does not use shift sequences) or a non-zero value if the current multibyte encoding is state-dependent (uses shift sequences).

2) zero on success, in which case the multibyte representation of `wc` is stored in `s` and its length is stored in `*status`, or, if `s` is null, the shift sequence status is stored in `status`). Non-zero on encoding error or runtime constraint violation, in which case `(size_t)-1` is stored in `*status`. The value stored in `*status` never exceeds MB_CUR_MAX

### Example

Run this code

```c
#include <stdio.h> #include <stdlib.h> #include <locale.h> void demo(wchar_t wc) {  const char* dep = wctomb(NULL, wc) ? "Yes" : "No";  printf("State-dependent encoding? %s.\n", dep);  char mb[MB_CUR_MAX];  int len = wctomb(mb, wc);  printf("wide char '%lc' -> multibyte char [", wc);  for (int idx = 0; idx < len; ++idx)  printf("%s%#2x", idx ? " " : "", (unsigned char)mb[idx]);  printf("]\n"); } int main(void) {  setlocale(LC_ALL, "en_US.utf8");  printf("MB_CUR_MAX = %zu\n", MB_CUR_MAX);  demo(L'A');  demo(L'\u00df');  demo(L'\U0001d10b'); }
```

Possible output:
可能的輸出：

```c
MB_CUR_MAX = 6 State-dependent encoding? No. wide char 'A' -> multibyte char [0x41] State-dependent encoding? No. wide char 'ß' -> multibyte char [0xc3 0x9f] State-dependent encoding? No. wide char '𝄋' -> multibyte char [0xf0 0x9d 0x84 0x8b]
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.22.7.3 The wctomb function (p: 261)
7.22.7.3 wctomb 函式（p: 261）
7.22.7.3 wctomb 函式（p: 261）

- K.3.6.4.1 The wctomb_s function (p: 443)
K.3.6.4.1 wctomb_s 函式（p: 443）
K.3.6.4.1 wctomb_s 函式（p: 443）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.22.7.3 The wctomb function (p: 358-359)
7.22.7.3 wctomb 函式（p: 358-359）
7.22.7.3 wctomb 函式（p: 358-359）

- K.3.6.4.1 The wctomb_s function (p: 610-611)
K.3.6.4.1 wctomb_s 函式（p: 610-611）
K.3.6.4.1 wctomb_s 函式（p: 610-611）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.20.7.3 The wctomb function (p: 322-323)
7.20.7.3 wctomb 函式（p: 322-323）
7.20.7.3 wctomb 函式（p: 322-323）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.10.7.3 The wctomb function
4.10.7.3 wctomb 函式
4.10.7.3 wctomb 函式

### See also

mbtowc
|   | converts the next multibyte character to wide character
(function)   |

wcrtombwcrtomb_s
(C95)(C11)
|   | converts a wide character to its multibyte representation, given state
(function)   |

C++ documentation for wctomb

---
來源頁路徑：`en.cppreference.com/c/string/multibyte/wctomb.html`

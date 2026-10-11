# mbtowc

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdlib.h>`
|   |  |   |  |

```c
int mbtowc( wchar_t* pwc, const char* s, size_t n )
```
|   |   |   |  (until C99)  |

```c
int mbtowc( wchar_t* restrict pwc, const char* restrict s, size_t n )
```
|   |   |   |  (since C99)  |

|  |  |  |  |

Converts a multibyte character whose first byte is pointed to by `s` to a wide character, written to `*pwc` if `pwc` is not null.
將首位元組由 s 指向的多位元組字元轉換為寬字元，若 pwc 不為空則寫入 * pwc 。
If `s` is a null pointer, resets the global conversion state and determines whether shift sequences are used.
如果 s 是空指標，則重置全域性轉換狀態，並確定是否使用移位序列。

### Notes

Each call to `mbtowc` updates the internal global conversion state (a static object of type mbstate_t, known only to this function). If the multibyte encoding uses shift states, care must be taken to avoid backtracking or multiple scans. In any case, multiple threads should not call `mbtowc` without synchronization: mbrtowc may be used instead.
每次呼叫 mbtowc 都會更新內部全域性轉換狀態（一個型別為 mbstate_t 的靜態物件，僅本函式可知）。如果多位元組編碼使用移位狀態，則必須注意避免回溯或多次掃描。無論如何，多個執行緒不應在沒有同步的情況下呼叫 mbtowc：可改用 mbrtowc 。

### Parameters

| pwc  |   | -  |   | pointer to the wide character for output  |

| s  |   | -  |   | pointer to the multibyte character  |

| n  |   | -  |   | limit on the number of bytes in s that can be examined  |

### Return value

If `s` is not a null pointer, returns the number of bytes that are contained in the multibyte character or `-1` if the first bytes pointed to by `s` do not form a valid multibyte character or `0` if `s` is pointing at the null character `'\0'`.
如果 s 不是空指標，則傳回該多位元組字元所包含的位元組數；如果 s 指向的首位元組不構成有效的多位元組字元則傳回 -1 ；如果 s 指向空字元 '\0' 則傳回 0 。
If `s` is a null pointer, resets its internal conversion state to represent the initial shift state and returns `0` if the current multibyte encoding is not state-dependent (does not use shift sequences) or a non-zero value if the current multibyte encoding is state-dependent (uses shift sequences).
如果 s 是空指標，則將其內部轉換狀態重置為表示初始移位狀態；若目前多位元組編碼不依賴狀態（不使用移位序列）則傳回 0 ，若目前多位元組編碼依賴狀態（使用移位序列）則傳回非零值。

### Example

Run this code

```c
#include <locale.h> #include <stdio.h> #include <stdlib.h> #include <string.h> #include <wchar.h> // print multibyte string to wide-oriented stdout // equivalent to wprintf(L"%s\n", ptr); void print_mb(const char* ptr) {  mbtowc(NULL, NULL, 0); // reset the conversion state  const char* end = ptr + strlen(ptr);  int ret = 0;  for (wchar_t wc; (ret = mbtowc(&wc, ptr, end - ptr)) > 0; ptr += ret)  wprintf(L"%lc", wc);  wprintf(L"\n"); } int main(void) {  setlocale(LC_ALL, "en_US.utf8");  // UTF-8 narrow multibyte encoding  print_mb("z\u00df\u6c34\U0001F34C"); // or "zß水🍌" }
```

Output:

```c
zß水🍌
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.24.7.2 The mbtowc function (p: TBD)
7.24.7.2 mbtowc 函式（p: 待定）
7.24.7.2 mbtowc 函式（p: 待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.22.7.2 The mbtowc function (p: 260)
7.22.7.2 mbtowc 函式（p: 260）
7.22.7.2 mbtowc 函式（p: 260）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.22.7.2 The mbtowc function (p: 358)
7.22.7.2 mbtowc 函式（p: 358）
7.22.7.2 mbtowc 函式（p: 358）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.20.7.2 The mbtowc function (p: 322)
7.20.7.2 mbtowc 函式（p: 322）
7.20.7.2 mbtowc 函式（p: 322）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.10.7.2 The mbtowc function
4.10.7.2 mbtowc 函式
4.10.7.2 mbtowc 函式

### See also

mbrtowc
(C95)
|   | converts the next multibyte character to wide character, given state
(function)   |

mblen
|   | returns the number of bytes in the next multibyte character
(function)   |

C++ documentation for mbtowc

---
來源頁路徑：`en.cppreference.com/c/string/multibyte/mbtowc.html`

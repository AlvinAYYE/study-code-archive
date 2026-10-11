# wcslen, wcsnlen_s

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<wchar.h>`
|   |  |   |  |

```c
size_t wcslen( const wchar_t *str );
```
|   |  (1)  |   |  (since C95)  |

```c
size_t wcsnlen_s(const wchar_t *str, size_t strsz);
```
|   |  (2)  |   |  (since C11)  |

|  |  |  |  |

1) Returns the length of a wide string, that is the number of non-null wide characters that precede the terminating null wide character.

2) Same as (1), except that the function returns zero if `str` is a null pointer and returns `strsz` if the null wide character was not found in the first `strsz` wide characters of `src`
As with all bounds-checked functions, `wcslen_s` is only guaranteed to be available if `__STDC_LIB_EXT1__` is defined by the implementation and if the user defines `__STDC_WANT_LIB_EXT1__` to the integer constant `1` before including <stdio.h>..
與所有邊界檢查函式一樣，僅當實現定義了 __STDC_LIB_EXT1__ 且使用者在包含 <stdio.h> 之前將 __STDC_WANT_LIB_EXT1__ 定義為整數常量 1 時，才保證 wcslen_s 可用。

### Parameters

| str  |   | -  |   | pointer to the null-terminated wide string to be examined  |

| strsz  |   | -  |   | maximum number of wide characters to examine  |

### Return value

1) The length of the null-terminated wide string `str`.

2) The length of the null-terminated wide string `str` on success, zero if `str` is a null pointer, `strsz` if the null wide character was not found.

### Notes

`strnlen_s` and `wcsnlen_s` are the only bounds-checked functions that do not invoke the runtime constraints handler. They are pure utility functions used to provide limited support for non-null terminated strings.
strnlen_s 和 wcsnlen_s 是僅有的不呼叫執行時約束處理程式的邊界檢查函式。它們是純工具函式，用於為非空終止字串提供有限支援。

### Example

Run this code

```c
#include <wchar.h> #include <stdio.h> int main(void) {  wchar_t str[] = L"How many wide characters does this string contain?";  printf("without null character: %zu\n", wcslen(str));  printf("with null character: %zu\n", sizeof str / sizeof *str); }
```

Output:

```c
without null character: 50 with null character: 51
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.29.4.6.1 The wcslen function (p: 439)
7.29.4.6.1 wcslen 函式（頁碼：439）
7.29.4.6.1 wcslen 函式（頁碼：439）

- K.3.9.2.4.1 The wcsnlen_s function (p: 646-647)
K.3.9.2.4.1 wcsnlen_s 函式（頁碼：646-647）
K.3.9.2.4.1 wcsnlen_s 函式（頁碼：646-647）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.24.4.6.1 The wcslen function (p: 385)
7.24.4.6.1 wcslen 函式（頁碼：385）
7.24.4.6.1 wcslen 函式（頁碼：385）

### See also

strlenstrnlen_s
(C11)
|   | returns the length of a given string
(function)   |

C++ documentation for wcslen

---
來源頁路徑：`en.cppreference.com/c/string/wide/wcslen.html`

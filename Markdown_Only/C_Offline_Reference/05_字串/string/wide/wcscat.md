# wcscat, wcscat_s

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<wchar.h>`
|   |  |   |  |

```c
wchar_t* wcscat( wchar_t* dest, const wchar_t* src );
```
|   |  (1) |   | (since C95)
(until C99) |

```c
wchar_t* wcscat( wchar_t* restrict dest, const wchar_t* restrict src );
```
|   |   |   | (since C99) |

```c
errno_t wcscat_s( wchar_t* restrict dest, rsize_t destsz,  const wchar_t* restrict src );
```
|   |  (2)  |   |  (since C11)  |

|  |  |  |  |

1) Appends a copy of the wide string pointed to by `src` to the end of the wide string pointed to by `dest`. The wide character `src[0]` replaces the null terminator at the end of `dest`. The resulting wide string is null-terminated. The behavior is undefined if the destination array is not large enough for the contents of both `src` and `dest` and the terminating null wide character. The behavior is undefined if the strings overlap.

2) Same as (1), except that it may clobber the rest of the destination array (from the last character written to `destsz`) with unspecified values and that the following errors are detected at runtime and call the currently installed constraint handler function:
- `src` or `dest` is a null pointer
src 或 dest 為空指標

- `destsz` is zero or greater than `RSIZE_MAX / sizeof(wchar_t)`
destsz 為零或大於 RSIZE_MAX / sizeof ( wchar_t )

- there is no null terminator in the first `destsz` wide characters of `dest`
dest 的前 destsz 個寬字元中沒有空終止符

- truncation would occur (the available space at the end of `dest` would not fit every wide character, including the null terminator, of `src`)
會發生截斷（ dest 末尾的可用空間容納不下 src 的每個寬字元，包括空終止符）

- overlap would occur between the source and the destination strings
源字串和目標字串會發生重疊

As with all bounds-checked functions, `wcscat_s` is only guaranteed to be available if `__STDC_LIB_EXT1__` is defined by the implementation and if the user defines `__STDC_WANT_LIB_EXT1__` to the integer constant `1` before including <wchar.h>.

### Parameters

| dest  |   | -  |   | pointer to the null-terminated wide string to append to  |

| src  |   | -  |   | pointer to the null-terminated wide string to copy from  |

| destsz  |   | -  |   | maximum number of characters to write, typically the size of the destination buffer  |

### Return value

1) returns a copy of `dest`

2) returns zero on success, returns non-zero on error. Also, on error, writes `L'\0'` to `dest[0]` (unless `dest` is a null pointer or `destsz` is zero or greater than `RSIZE_MAX / sizeof(wchar_t)`).

### Example

Run this code

```c
#include <locale.h> #include <stdio.h> #include <wchar.h> int main(void) {  wchar_t str[50] = L"Земля, прощай.";  wcscat(str, L" ");  wcscat(str, L"В добрый путь.");  setlocale(LC_ALL, "en_US.utf8");  printf("%ls", str); }
```

Output:

```c
Земля, прощай. В добрый путь.
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.31.4.3.1 The wcscat function (p: 439)
7.31.4.3.1 wcscat 函式（頁碼：439）
7.31.4.3.1 wcscat 函式（頁碼：439）

- K.3.9.3.2.1 The wcscat_s function (p: 665-666)
K.3.9.3.2.1 wcscat_s 函式（頁碼：665-666）
K.3.9.3.2.1 wcscat_s 函式（頁碼：665-666）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.29.4.3.1 The wcscat function (p: 315)
7.29.4.3.1 wcscat 函式（頁碼：315）
7.29.4.3.1 wcscat 函式（頁碼：315）

- K.3.9.2.2.1 The wcscat_s function (p: 466)
K.3.9.2.2.1 wcscat_s 函式（頁碼：466）
K.3.9.2.2.1 wcscat_s 函式（頁碼：466）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.29.4.3.1 The wcscat function (p: 432)
7.29.4.3.1 wcscat 函式（頁碼：432）
7.29.4.3.1 wcscat 函式（頁碼：432）

- K.3.9.2.2.1 The wcscat_s function (p: 642-643)
K.3.9.2.2.1 wcscat_s 函式（頁碼：642-643）
K.3.9.2.2.1 wcscat_s 函式（頁碼：642-643）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.24.4.3.1 The wcscat function (p: 378)
7.24.4.3.1 wcscat 函式（頁碼：378）
7.24.4.3.1 wcscat 函式（頁碼：378）

### See also

wcsncatwcsncat_s
(C95)(C11)
|   | appends a certain amount of wide characters from one wide string to another
(function)   |

strcatstrcat_s
(C11)
|   | concatenates two strings
(function)   |

wcscpywcscpy_s
(C95)(C11)
|   | copies one wide string to another
(function)   |

C++ documentation for wcscat

---
來源頁路徑：`en.cppreference.com/c/string/wide/wcscat.html`

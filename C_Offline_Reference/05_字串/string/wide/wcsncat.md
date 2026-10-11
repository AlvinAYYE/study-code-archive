# wcsncat, wcsncat_s

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<wchar.h>`
|   |  |   |  |

```c
wchar_t* wcsncat( wchar_t* dest, const wchar_t* src, size_t count );
```
|   |  (1) |   | (since C95)
(until C99) |

```c
wchar_t* wcsncat( wchar_t* restrict dest,  const wchar_t* restrict src, size_t count );
```
|   |   |   | (since C99) |

```c
errno_t wcsncat_s( wchar_t* restrict dest, rsize_t destsz,  const wchar_t* restrict src, rsize_t count );
```
|   |  (2)  |   |  (since C11)  |

|  |  |  |  |

1) Appends at most `count` wide characters from the wide string pointed to by `src`, stopping if the null terminator is copied, to the end of the character string pointed to by `dest`. The wide character `src[0]` replaces the null terminator at the end of `dest`. The null terminator is always appended in the end (so the maximum number of wide characters the function may write is `count + 1`).

The behavior is undefined if the destination array is not large enough for the contents of both `src` and `dest` and the terminating null wide character.

The behavior is undefined if the strings overlap.

2) Same as (1), except that this function may clobber the remainder of the destination array (from the last wide character written to `destsz`) and that the following errors are detected at runtime and call the currently installed constraint handler function:
- `src` or `dest` is a null pointer
src 或 dest 為空指標

- `destsz` or `count` is zero or greater than `RSIZE_MAX / sizeof(wchar_t)`
destsz 或 count 為零或大於 RSIZE_MAX / sizeof ( wchar_t )

- there is no null wide character in the first `destsz` wide characters of `dest`
dest 的前 destsz 個寬字元中沒有空寬字元

- truncation would occur: `count` or the length of `src`, whichever is less, exceeds the space available between the null terminator of `dest` and `destsz`.
會發生截斷： count 或 src 的長度（取較小者）超過了 dest 的空終止符與 destsz 之間的可用空間。

- overlap would occur between the source and the destination strings
源字串和目標字串會發生重疊

As with all bounds-checked functions, `wcsncat_s` is only guaranteed to be available if `__STDC_LIB_EXT1__` is defined by the implementation and if the user defines `__STDC_WANT_LIB_EXT1__` to the integer constant `1` before including <wchar.h>.

### Parameters

| dest  |   | -  |   | pointer to the null-terminated wide string to append to  |

| src  |   | -  |   | pointer to the null-terminated wide string to copy from  |

| count  |   | -  |   | maximum number of wide characters to copy  |

| destsz  |   | -  |   | the size of the destination buffer  |

### Return value

1) returns a copy of `dest`

2) returns zero on success, returns non-zero on error. Also, on error, writes `L'\0'` to `dest[0]` (unless `dest` is a null pointer or `destsz` is zero or greater than `RSIZE_MAX / sizeof(wchar_t)`).

### Notes

Although truncation to fit the destination buffer is a security risk and therefore a runtime constraints violation for `wcsncat_s`, it is possible to get the truncating behavior by specifying `count` equal to the size of the destination array minus one: it will copy the first `count` wide characters and append the null terminator as always:
雖然截斷以適應目標緩衝區是一種安全風險，因此對 wcsncat_s 而言是執行時約束違規，但可以透過指定 count 等於目標陣列大小減一來獲得截斷行為：它將複製前 count 個寬字元，並像往常一樣追加空終止符：

```c
size_t count = sizeof dst / sizeof *dst; wcsncat_s(dst, count, src, count - wcsnlen_s(dst, count) - 1);
```

### Example

Run this code

```c
#include <locale.h> #include <stdio.h> #include <wchar.h>   int main(void) {  wchar_t str[50] = L"Земля, прощай.";  wcsncat(str, L" ", 1);  wcsncat(str, L"В добрый путь.", 8); // only append the first 8 wide chars  setlocale(LC_ALL, "en_US.utf8");  printf("%ls", str); }
```

Possible output:
可能的輸出：

```c
Земля, прощай. В добрый
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.31.4.3.2 The wcsncat function (p: 439)
7.31.4.3.2 wcsncat 函式（頁碼：439）
7.31.4.3.2 wcsncat 函式（頁碼：439）

- K.3.9.3.2.2 The wcsncat_s function (p: 666)
K.3.9.3.2.2 wcsncat_s 函式（頁碼：666）
K.3.9.3.2.2 wcsncat_s 函式（頁碼：666）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.29.4.3.2 The wcsncat function (p: 315)
7.29.4.3.2 wcsncat 函式（頁碼：315）
7.29.4.3.2 wcsncat 函式（頁碼：315）

- K.3.9.2.2.2 The wcsncat_s function (p: 466-467)
K.3.9.2.2.2 wcsncat_s 函式（頁碼：466-467）
K.3.9.2.2.2 wcsncat_s 函式（頁碼：466-467）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.29.4.3.2 The wcsncat function (p: 432-433)
7.29.4.3.2 wcsncat 函式（頁碼：432-433）
7.29.4.3.2 wcsncat 函式（頁碼：432-433）

- K.3.9.2.2.2 The wcsncat_s function (p: 643-644)
K.3.9.2.2.2 wcsncat_s 函式（頁碼：643-644）
K.3.9.2.2.2 wcsncat_s 函式（頁碼：643-644）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.24.4.3.2 The wcsncat function (p: 378-379)
7.24.4.3.2 wcsncat 函式（頁碼：378-379）
7.24.4.3.2 wcsncat 函式（頁碼：378-379）

### See also

wcscatwcscat_s
(C95)(C11)
|   | appends a copy of one wide string to another
(function)   |

strncatstrncat_s
(C11)
|   | concatenates a certain amount of characters of two strings
(function)   |

wcscpywcscpy_s
(C95)(C11)
|   | copies one wide string to another
(function)   |

C++ documentation for wcsncat

---
來源頁路徑：`en.cppreference.com/c/string/wide/wcsncat.html`

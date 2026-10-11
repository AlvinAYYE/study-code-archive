# strcpy, strcpy_s

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<string.h>`
|   |  |   |  |

```c
char* strcpy( char* dest, const char* src );
```
|   |  (1) |   | (until C99) |

```c
char* strcpy( char* restrict dest, const char* restrict src );
```
|   |   |   | (since C99) |

```c
errno_t strcpy_s( char* restrict dest, rsize_t destsz, const char* restrict src );
```
|   |  (2)  |   |  (since C11)  |

|  |  |  |  |

1) Copies the null-terminated byte string pointed to by `src`, including the null terminator, to the character array whose first element is pointed to by `dest`.

The behavior is undefined if the `dest` array is not large enough. The behavior is undefined if the strings overlap. The behavior is undefined if either `dest` is not a pointer to a character array or `src` is not a pointer to a null-terminated byte string.

2) Same as (1), except that it may clobber the rest of the destination array with unspecified values and that the following errors are detected at runtime and call the currently installed constraint handler function:
- `src` or `dest` is a null pointer
src 或 dest 為空指標

- `destsz` is zero or greater than `RSIZE_MAX`
destsz 為零或大於 RSIZE_MAX

- `destsz` is less or equal `strnlen_s(src, destsz)`; in other words, truncation would occur
destsz 小於或等於 strnlen_s ( src , destsz ) ；換句話說，會發生截斷

- overlap would occur between the source and the destination strings
源字串和目標字串會發生重疊

The behavior is undefined if the size of the character array pointed to by `dest` `<=` `strnlen_s(src, destsz)` `<` `destsz`; in other words, an erroneous value of `destsz` does not expose the impending buffer overflow.

As with all bounds-checked functions, `strcpy_s` is only guaranteed to be available if `__STDC_LIB_EXT1__` is defined by the implementation and if the user defines `__STDC_WANT_LIB_EXT1__` to the integer constant `1` before including <string.h>.

### Parameters

| dest  |   | -  |   | pointer to the character array to write to  |

| src  |   | -  |   | pointer to the null-terminated byte string to copy from  |

| destsz  |   | -  |   | maximum number of characters to write, typically the size of the destination buffer  |

### Return value

1) returns a copy of `dest`

2) returns zero on success, returns non-zero on error. Also, on error, writes zero to `dest[0]` (unless `dest` is a null pointer or `destsz` is zero or greater than `RSIZE_MAX`).

### Notes

`strcpy_s` is allowed to clobber the destination array from the last character written up to `destsz` in order to improve efficiency: it may copy in multibyte blocks and then check for null bytes.
為了提升效率，strcpy_s 可以從最後寫入的字元開始，覆寫目標陣列直到 destsz 指定的範圍；例如先以多位元組區塊複製，再檢查空字元。
The function `strcpy_s` is similar to the BSD function `strlcpy`, except that
strcpy_s 與 BSD 函式 strlcpy 類似，但有以下差異：

- `strlcpy` truncates the source string to fit in the destination (which is a security risk)
strlcpy 會截短來源字串以配合目的緩衝區大小，這可能造成安全風險。

- `strlcpy` does not perform all the runtime checks that `strcpy_s` does
strlcpy 不會執行 strcpy_s 提供的所有執行階段檢查。

- `strlcpy` does not make failures obvious by setting the destination to a null string or calling a handler if the call fails.
strlcpy 呼叫失敗時，不會將目的字串設為空字串，也不會呼叫處理常式，因此失敗不易察覺。

Although `strcpy_s` prohibits truncation due to potential security risks, it's possible to truncate a string using bounds-checked strncpy_s instead.
strcpy_s 為避免潛在的安全風險，不允許截短字串；若要截短，可改用具邊界檢查功能的 strncpy_s。

### Example

Run this code

```c
#define __STDC_WANT_LIB_EXT1__ 1 #include <stdio.h> #include <stdlib.h> #include <string.h> int main(void) {  const char* src = "Take the test."; // src[0] = 'M' ; // this would be undefined behavior  char dst[strlen(src) + 1]; // +1 to accommodate for the null terminator  strcpy(dst, src);  dst[0] = 'M'; // OK  printf("src = %s\ndst = %s\n", src, dst); #ifdef __STDC_LIB_EXT1__  set_constraint_handler_s(ignore_handler_s);  int r = strcpy_s(dst, sizeof dst, src);  printf("dst = \"%s\", r = %d\n", dst, r);  r = strcpy_s(dst, sizeof dst, "Take even more tests.");  printf("dst = \"%s\", r = %d\n", dst, r); #endif }
```

Possible output:
可能的輸出：

```c
src = Take the test. dst = Make the test. dst = "Take the test.", r = 0 dst = "", r = 22
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.24.2.3 The strcpy function (p: TBD)
7.24.2.3 strcpy 函式（頁碼：待定）
7.24.2.3 strcpy 函式（頁碼：待定）

- K.3.7.1.3 The strcpy_s function (p: TBD)
K.3.7.1.3 strcpy_s 函式（頁碼：待定）
K.3.7.1.3 strcpy_s 函式（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.24.2.3 The strcpy function (p: 264-265)
7.24.2.3 strcpy 函式（頁碼：264-265）
7.24.2.3 strcpy 函式（頁碼：264-265）

- K.3.7.1.3 The strcpy_s function (p: 447)
K.3.7.1.3 strcpy_s 函式（頁碼：447）
K.3.7.1.3 strcpy_s 函式（頁碼：447）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.24.2.3 The strcpy function (p: 363)
7.24.2.3 strcpy 函式（頁碼：363）
7.24.2.3 strcpy 函式（頁碼：363）

- K.3.7.1.3 The strcpy_s function (p: 615-616)
K.3.7.1.3 strcpy_s 函式（頁碼：615-616）
K.3.7.1.3 strcpy_s 函式（頁碼：615-616）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.21.2.3 The strcpy function (p: 326)
7.21.2.3 strcpy 函式（頁碼：326）
7.21.2.3 strcpy 函式（頁碼：326）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.11.2.3 The strcpy function
4.11.2.3 strcpy 函式
4.11.2.3 strcpy 函式

### See also

strncpystrncpy_s
(C11)
|   | copies a certain amount of characters from one string to another
(function)   |

memcpymemcpy_s
(C11)
|   | copies one buffer to another
(function)   |

wcscpywcscpy_s
(C95)(C11)
|   | copies one wide string to another
(function)   |

strdup
(dynamic memory TR)
|   | allocate a copy of a string
(function)   |

C++ documentation for strcpy

---
來源頁路徑：`en.cppreference.com/c/string/byte/strcpy.html`

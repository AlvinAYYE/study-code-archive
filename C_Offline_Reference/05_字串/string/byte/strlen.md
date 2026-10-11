# strlen, strnlen_s

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<string.h>`
|   |  |   |  |

```c
size_t strlen( const char* str );
```
|   |  (1)  |   |   |

```c
size_t strnlen_s( const char* str, size_t strsz );
```
|   |  (2)  |   |  (since C11)  |

|  |  |  |  |

1) Returns the length of the given null-terminated byte string, that is, the number of characters in a character array whose first element is pointed to by `str` up to and not including the first null character.

The behavior is undefined if `str` is not a pointer to a null-terminated byte string.

2) Same as (1), except that the function returns zero if `str` is a null pointer and returns `strsz` if the null character was not found in the first `strsz` bytes of `str`.

The behavior is undefined if `str` is not a pointer to a null-terminated byte string and `strsz` is greater than the size of that character array.
As with all bounds-checked functions, `strnlen_s` is only guaranteed to be available if `__STDC_LIB_EXT1__` is defined by the implementation and if the user defines `__STDC_WANT_LIB_EXT1__` to the integer constant `1` before including <string.h>.
和其他邊界檢查函式一樣，只有實作定義了 __STDC_LIB_EXT1__，且使用者在引入 <string.h> 前將 __STDC_WANT_LIB_EXT1__ 定義為整數常數 1，才能保證 strnlen_s 可用。

### Parameters

| str  |   | -  |   | pointer to the null-terminated byte string to be examined  |

| strsz  |   | -  |   | maximum number of characters to examine  |

### Return value

1) The length of the null-terminated byte string `str`.

2) The length of the null-terminated byte string `str` on success, zero if `str` is a null pointer, `strsz` if the null character was not found.

### Notes

`strnlen_s` and `wcsnlen_s` are the only bounds-checked functions that do not invoke the runtime constraints handler. They are pure utility functions used to provide limited support for non-null terminated strings.
strnlen_s 和 wcsnlen_s 是唯二不會呼叫執行階段限制處理常式的邊界檢查函式。這兩個輔助函式可有限度地處理未以空字元結尾的字串。

### Example

Run this code

```c
#define __STDC_WANT_LIB_EXT1__ 1 #include <stdio.h> #include <string.h> int main(void) {  const char str[] = "How many characters does this string contain?";  printf("without null character: %zu\n", strlen(str));  printf("with null character: %zu\n", sizeof str); #ifdef __STDC_LIB_EXT1__  printf("without null character: %zu\n", strnlen_s(str, sizeof str)); #endif }
```

Possible output:
可能的輸出：

```c
without null character: 45 with null character: 46 without null character: 45
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.24.6.3 The strlen function (p: TBD)
7.24.6.3 strlen 函式（p: TBD）
7.24.6.3 strlen 函式（p: TBD）

- K.3.7.4.4 The strnlen_s function (p: TBD)
K.3.7.4.4 strnlen_s 函式（p: TBD）
K.3.7.4.4 strnlen_s 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.24.6.3 The strlen function (p: TBD)
7.24.6.3 strlen 函式（p: TBD）
7.24.6.3 strlen 函式（p: TBD）

- K.3.7.4.4 The strnlen_s function (p: TBD)
K.3.7.4.4 strnlen_s 函式（p: TBD）
K.3.7.4.4 strnlen_s 函式（p: TBD）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.24.6.3 The strlen function (p: 372)
7.24.6.3 strlen 函式（p: 372）
7.24.6.3 strlen 函式（p: 372）

- K.3.7.4.4 The strnlen_s function (p: 623)
K.3.7.4.4 strnlen_s 函式（p: 623）
K.3.7.4.4 strnlen_s 函式（p: 623）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.21.6.3 The strlen function (p: 334)
7.21.6.3 strlen 函式（p: 334）
7.21.6.3 strlen 函式（p: 334）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.11.6.3 The strlen function
4.11.6.3 strlen 函式
4.11.6.3 strlen 函式

### See also

wcslenwcsnlen_s
(C95)(C11)
|   | returns the length of a wide string
(function)   |

mblen
|   | returns the number of bytes in the next multibyte character
(function)   |

C++ documentation for strlen

---
來源頁路徑：`en.cppreference.com/c/string/byte/strlen.html`

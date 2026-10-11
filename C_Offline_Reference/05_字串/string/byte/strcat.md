# strcat, strcat_s

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<string.h>`
|   |  |   |  |

```c
char* strcat( char* dest, const char* src );
```
|   |  (1) |   | (until C99) |

```c
char* strcat( char* restrict dest, const char* restrict src );
```
|   |   |   | (since C99) |

```c
errno_t strcat_s(char* restrict dest, rsize_t destsz, const char* restrict src);
```
|   |  (2)  |   |  (since C11)  |

|  |  |  |  |

1) Appends a copy of the null-terminated byte string pointed to by `src` to the end of the null-terminated byte string pointed to by `dest`. The character `src[0]` replaces the null terminator at the end of `dest`. The resulting byte string is null-terminated.

The behavior is undefined if the destination array is not large enough for the contents of both `src` and `dest` and the terminating null character. The behavior is undefined if the strings overlap. The behavior is undefined if either `dest` or `src` is not a pointer to a null-terminated byte string.

2) Same as (1), except that it may clobber the rest of the destination array (from the last character written to `destsz`) with unspecified values and that the following errors are detected at runtime and call the currently installed constraint handler function:
- `src` or `dest` is a null pointer
src 或 dest 為空指標

- `destsz` is zero or greater than RSIZE_MAX
destsz 為零或大於 RSIZE_MAX

- there is no null terminator in the first `destsz` bytes of `dest`
dest 的前 destsz 個位元組中沒有空字元結束符

- truncation would occur (the available space at the end of `dest` would not fit every character, including the null terminator, of `src`)
會發生截斷（dest 末尾的可用空間無法容納 src 的所有字元，包括空字元結束符）

- overlap would occur between the source and the destination strings
源字串和目標字串會發生重疊

The behavior is undefined if the size of the character array pointed to by `dest` < `strlen(dest)+strlen(src)+1` <= `destsz`; in other words, an erroneous value of `destsz` does not expose the impending buffer overflow.

As with all bounds-checked functions, `strcat_s` is only guaranteed to be available if `__STDC_LIB_EXT1__` is defined by the implementation and if the user defines `__STDC_WANT_LIB_EXT1__` to the integer constant `1` before including <string.h>.

### Parameters

| dest  |   | -  |   | pointer to the null-terminated byte string to append to  |

| src  |   | -  |   | pointer to the null-terminated byte string to copy from  |

| destsz  |   | -  |   | maximum number of characters to write, typically the size of the destination buffer  |

### Return value

1) returns a copy of `dest`

2) returns zero on success, returns non-zero on error. Also, on error, writes zero to `dest[0]` (unless `dest` is a null pointer or `destsz` is zero or greater than RSIZE_MAX).

### Notes

Because `strcat` needs to seek to the end of `dest` on each call, it is inefficient to concatenate many strings into one using `strcat`.
strcat 每次呼叫都要先找到 dest 的結尾，因此用它串接許多字串時效率不佳。
`strcat_s` is allowed to clobber the destination array from the last character written up to `destsz` in order to improve efficiency: it may copy in multibyte blocks and then check for null bytes.
為了提升效率，strcat_s 可能會從最後寫入的位置起，一次覆寫多個位元組，直到 destsz 指定的範圍，再檢查空字元。
The function `strcat_s` is similar to the BSD function `strlcat`, except that
strcat_s 與 BSD 函式 strlcat 類似，但有以下差異：

- `strlcat` truncates the source string to fit in the destination
strlcat 會截斷源字串以適應目標

- `strlcat` does not perform all the runtime checks that `strcat_s` does
strlcat 不會執行 strcat_s 提供的所有執行階段檢查。

- `strlcat` does not make failures obvious by setting the destination to a null string or calling a handler if the call fails.
strlcat 呼叫失敗時，不會將目的字串設為空字串，也不會呼叫處理常式，因此失敗不易察覺。

Although `strcat_s` prohibits truncation due to potential security risks, it's possible to truncate a string using bounds-checked strncat_s instead.
strcat_s 為避免潛在的安全風險，不允許截短字串；若要截短，可改用具邊界檢查功能的 strncat_s。

### Example

Run this code

```c
#define __STDC_WANT_LIB_EXT1__ 1 #include <stdio.h> #include <stdlib.h> #include <string.h> int main(void) {  char str[50] = "Hello ";  char str2[50] = "World!";  strcat(str, str2);  strcat(str, " ...");  strcat(str, " Goodbye World!");  puts(str); #ifdef __STDC_LIB_EXT1__  set_constraint_handler_s(ignore_handler_s);  int r = strcat_s(str, sizeof str, " ... ");  printf("str = \"%s\", r = %d\n", str, r);  r = strcat_s(str, sizeof str, " and this is too much");  printf("str = \"%s\", r = %d\n", str, r); #endif }
```

Possible output:
可能的輸出：

```c
Hello World! ... Goodbye World! str = "Hello World! ... Goodbye World! ... ", r = 0 str = "", r = 22
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.24.3.1 The strcat function (p: TBD)
7.24.3.1 strcat 函式（p: TBD）
7.24.3.1 strcat 函式（p: TBD）

- K.3.7.2.1 The strcat_s function (p: TBD)
K.3.7.2.1 strcat_s 函式（p: TBD）
K.3.7.2.1 strcat_s 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.24.3.1 The strcat function (p: TBD)
7.24.3.1 strcat 函式（p: TBD）
7.24.3.1 strcat 函式（p: TBD）

- K.3.7.2.1 The strcat_s function (p: TBD)
K.3.7.2.1 strcat_s 函式（p: TBD）
K.3.7.2.1 strcat_s 函式（p: TBD）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.24.3.1 The strcat function (p: 364)
7.24.3.1 strcat 函式（p: 364）
7.24.3.1 strcat 函式（p: 364）

- K.3.7.2.1 The strcat_s function (p: 617-618)
K.3.7.2.1 strcat_s 函式（p: 617-618）
K.3.7.2.1 strcat_s 函式（p: 617-618）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.21.3.1 The strcat function (p: 327)
7.21.3.1 strcat 函式（p: 327）
7.21.3.1 strcat 函式（p: 327）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.11.3.1 The strcat function
4.11.3.1 strcat 函式
4.11.3.1 strcat 函式

### See also

strncatstrncat_s
(C11)
|   | concatenates a certain amount of characters of two strings
(function)   |

strcpystrcpy_s
(C11)
|   | copies one string to another
(function)   |

memccpy
(C23)
|   | copies one buffer to another, stopping after the specified delimiter
(function)   |

C++ documentation for strcat

---
來源頁路徑：`en.cppreference.com/c/string/byte/strcat.html`

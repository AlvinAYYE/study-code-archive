# memset, memset_explicit, memset_s

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<string.h>`
|   |  |   |  |

```c
void* memset( void* dest, int ch, size_t count );
```
|   |  (1)  |   |   |

```c
void* memset_explicit( void* dest, int ch, size_t count );
```
|   |  (2)  |   |  (since C23)  |

```c
errno_t memset_s( void* dest, rsize_t destsz, int ch, rsize_t count );
```
|   |  (3)  |   |  (since C11)  |

|  |  |  |  |

1) Copies the value `(unsigned char)ch` into each of the first `count` characters of the object pointed to by `dest`.

The behavior is undefined if access occurs beyond the end of the dest array. The behavior is undefined if `dest` is a null pointer.

2) Same as (1), except that is safe for sensitive information.

3) Same as (1), except that the following errors are detected at runtime and call the currently installed constraint handler function after storing `ch` in every location of the destination range `[dest, dest + destsz)` if `dest` and `destsz` are themselves valid:
- `dest` is a null pointer
dest 為空指標

- `destsz` or `count` is greater than RSIZE_MAX
destsz 或 count 大於 RSIZE_MAX

- `count` is greater than `destsz` (buffer overflow would occur)
count 大於 destsz（會發生緩衝區溢位）
dest 為空指標 destsz 或 count 大於 RSIZE_MAX count 大於 destsz（會發生緩衝區溢位）

The behavior is undefined if the size of the character array pointed to by `dest` < `count` <= `destsz`; in other words, an erroneous value of `destsz` does not expose the impending buffer overflow.
As with all bounds-checked functions, `memset_s` is only guaranteed to be available if `__STDC_LIB_EXT1__` is defined by the implementation and if the user defines `__STDC_WANT_LIB_EXT1__` to the integer constant `1` before including <string.h>.
與所有邊界檢查函式一樣，僅當實現定義了 __STDC_LIB_EXT1__ 且使用者在包含 <string.h> 之前將 __STDC_WANT_LIB_EXT1__ 定義為整數常量 1 時，才保證 memset_s 可用。

### Parameters

| dest  |   | -  |   | pointer to the object to fill  |

| ch  |   | -  |   | fill byte  |

| count  |   | -  |   | number of bytes to fill  |

| destsz  |   | -  |   | size of the destination array  |

### Return value

1,2) A copy of `dest`

3) zero on success, non-zero on error. Also on error, if `dest` is not a null pointer and `destsz` is valid, writes `destsz` fill bytes `ch` to the destination array.

### Notes

`memset` may be optimized away (under the as-if rules) if the object modified by this function is not accessed again for the rest of its lifetime (e.g., gcc bug 8537). For that reason, this function cannot be used to scrub memory (e.g., to fill an array that stored a password with zeroes).
若程式之後不再存取 memset 修改的物件，編譯器可能依 as-if 規則省略這次呼叫（例如 gcc bug 8537）。因此，memset 不適合用來抹除記憶體，例如清除儲存密碼的陣列。
This optimization is prohibited for `memset_explicit` and `memset_s`: they are guaranteed to perform the memory write.
memset_explicit 和 memset_s 不受這項最佳化影響，標準保證它們會實際寫入記憶體。
Third-party solutions for that include FreeBSD `explicit_bzero` or Microsoft `SecureZeroMemory`.
這方面的第三方解決方案包括 FreeBSD explicit_bzero 或 Microsoft SecureZeroMemory 。

### Example

Run this code

```c
#define __STDC_WANT_LIB_EXT1__ 1 #include <stdio.h> #include <stdlib.h> #include <string.h> int main(void) {  char str[] = "ghghghghghghghghghghgh";  puts(str);  memset(str,'a',5);  puts(str); #ifdef __STDC_LIB_EXT1__  set_constraint_handler_s(ignore_handler_s);  int r = memset_s(str, sizeof str, 'b', 5);  printf("str = \"%s\", r = %d\n", str, r);  r = memset_s(str, 5, 'c', 10); // count is greater than destsz  printf("str = \"%s\", r = %d\n", str, r); #endif }
```

Possible output:
可能的輸出：

```c
ghghghghghghghghghghgh aaaaahghghghghghghghgh str = "bbbbbhghghghghghghghgh", r = 0 str = "ccccchghghghghghghghgh", r = 22
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.26.6.1 The memset function (p: 383)
7.26.6.1 memset 函式（頁碼：383）
7.26.6.1 memset 函式（頁碼：383）

- 7.26.6.2 The memset_explicit function (p: 383)
7.26.6.2 memset_explicit 函式（頁碼：383）
7.26.6.2 memset_explicit 函式（頁碼：383）

- K.3.7.5.1 The memset_s function (p: 651)
K.3.7.5.1 memset_s 函式（頁碼：651）
K.3.7.5.1 memset_s 函式（頁碼：651）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.24.6.1 The memset function (p: 270)
7.24.6.1 memset 函式（頁碼：270）
7.24.6.1 memset 函式（頁碼：270）

- K.3.7.4.1 The memset_s function (p: 451)
K.3.7.4.1 memset_s 函式（頁碼：451）
K.3.7.4.1 memset_s 函式（頁碼：451）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.24.6.1 The memset function (p: 371)
7.24.6.1 memset 函式（頁碼：371）
7.24.6.1 memset 函式（頁碼：371）

- K.3.7.4.1 The memset_s function (p: 621-622)
K.3.7.4.1 memset_s 函式（頁碼：621-622）
K.3.7.4.1 memset_s 函式（頁碼：621-622）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.21.6.1 The memset function (p: 333)
7.21.6.1 memset 函式（頁碼：333）
7.21.6.1 memset 函式（頁碼：333）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.11.6.1 The memset function
4.11.6.1 memset 函式
4.11.6.1 memset 函式

### See also

memcpymemcpy_s
(C11)
|   | copies one buffer to another
(function)   |

wmemset
(C95)
|   | copies the given wide character to every position in a wide character array
(function)   |

C++ documentation for memset

---
來源頁路徑：`en.cppreference.com/c/string/byte/memset.html`

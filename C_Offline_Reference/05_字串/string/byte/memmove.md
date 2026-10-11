# memmove, memmove_s

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<string.h>`
|   |  |   |  |

```c
void* memmove( void* dest, const void* src, size_t count );
```
|   |  (1)  |   |   |

```c
errno_t memmove_s(void* dest, rsize_t destsz, const void* src, rsize_t count);
```
|   |  (2)  |   |  (since C11)  |

|  |  |  |  |

1) Copies `count` characters from the object pointed to by `src` to the object pointed to by `dest`. Both objects are interpreted as arrays of `unsigned char`. The objects may overlap: copying takes place as if the characters were copied to a temporary character array and then the characters were copied from the array to `dest`.

The behavior is undefined if access occurs beyond the end of the dest array. The behavior is undefined if either `dest` or `src` is an invalid or null pointer.

2) Same as (1), except when detecting the following errors at runtime, it zeroes out the entire destination range `[dest, dest + destsz)` (if both `dest` and `destsz` are valid) and calls the currently installed constraint handler function:
- `dest` or `src` is a null pointer
dest 或 src 為空指標

- `destsz` or `count` is greater than RSIZE_MAX
destsz 或 count 大於 RSIZE_MAX

- `count` is greater than `destsz` (buffer overflow would occur)
count 大於 destsz（會發生緩衝區溢位）
dest 或 src 為空指標 destsz 或 count 大於 RSIZE_MAX count 大於 destsz（會發生緩衝區溢位）

The behavior is undefined if the size of the character array pointed to by `dest` < `count` <= `destsz`; in other words, an erroneous value of `destsz` does not expose the impending buffer overflow.
As with all bounds-checked functions, `memmove_s` is only guaranteed to be available if `__STDC_LIB_EXT1__` is defined by the implementation and if the user defines `__STDC_WANT_LIB_EXT1__` to the integer constant `1` before including <string.h>.
與所有邊界檢查函式一樣，僅當實現定義了 __STDC_LIB_EXT1__ 且使用者在包含 <string.h> 之前將 __STDC_WANT_LIB_EXT1__ 定義為整數常量 1 時，才保證 memmove_s 可用。

### Parameters

| dest  |   | -  |   | pointer to the object to copy to  |

| destsz  |   | -  |   | max number of bytes to modify in the destination (typically the size of the destination object)  |

| src  |   | -  |   | pointer to the object to copy from  |

| count  |   | -  |   | number of bytes to copy  |

### Return value

1) Returns a copy of `dest`

2) Returns zero on success and non-zero value on error. Also on error, if `dest` is not a null pointer and `destsz` is valid, writes `destsz` zero bytes in to the destination array.

### Notes

`memmove` may be used to set the effective type of an object obtained by an allocation function.
memmove 可用來設定透過配置函式取得之物件的有效型別。
Despite being specified "as if" a temporary buffer is used, actual implementations of this function do not incur the overhead or double copying or extra memory. A common approach (glibc and bsd libc) is to copy bytes forwards from the beginning of the buffer if the destination starts before the source, and backwards from the end otherwise, with a fall back to the more efficient memcpy when there is no overlap at all.
儘管規定為"如同"使用了臨時緩衝區，此函式的實際實現並不會產生開銷或雙重複制或額外記憶體。一種常見方法（glibc 和 bsd libc）是：如果目標在源之前開始，則從緩衝區開頭向前複製位元組，否則從末尾向後複製，當完全沒有重疊時回退到更高效的 memcpy 。
Where strict aliasing prohibits examining the same memory as values of two different types, `memmove` may be used to convert the values.
在嚴格別名規則禁止將同一記憶體作為兩種不同型別的值進行檢查的地方， memmove 可用於轉換值。

### Example

Run this code

```c
#define __STDC_WANT_LIB_EXT1__ 1 #include <inttypes.h> #include <stdint.h> #include <stdio.h> #include <stdlib.h> #include <string.h> int main(void) {  char str[] = "1234567890";  puts(str);  memmove(str + 4, str + 3, 3); // copy from [4,5,6] to [5,6,7]  puts(str);  // setting effective type of allocated memory to be int  int* p = malloc(3 * sizeof(int)); // allocated memory has no effective type  int arr[3] = {1, 2, 3};  memmove(p, arr, 3 * sizeof(int)); // allocated memory now has an effective type  // reinterpreting data  double d = 0.1;  // int64_t n = *(int64_t*)(&d); // strict aliasing violation  int64_t n;  memmove(&n, &d, sizeof d); // OK  printf("%a is %" PRIx64 " as an int64_t\n", d, n); #ifdef __STDC_LIB_EXT1__  set_constraint_handler_s(ignore_handler_s);  char src[] = "aaaaaaaaaa";  char dst[] = "xyxyxyxyxy";  int r = memmove_s(dst, sizeof dst, src, 5);  printf("dst = \"%s\", r = %d\n", dst, r);  r = memmove_s(dst, 5, src, 10); // count is greater than destsz  printf("dst = \"");  for (size_t ndx = 0; ndx < sizeof dst; ++ndx)  {  char c = dst[ndx];  c ? printf("%c", c) : printf("\\0");  }  printf("\", r = %d\n", r); #endif }
```

Possible output:
可能的輸出：

```c
1234567890 1234456890 0x1.999999999999ap-4 is 3fb999999999999a as an int64_t dst = "aaaaayxyxy", r = 0 dst = "\0\0\0\0\0yxyxy", r = 22
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.24.2.2 The memmove function (p: TBD)
7.24.2.2 memmove 函式（頁碼：待定）
7.24.2.2 memmove 函式（頁碼：待定）

- K.3.7.1.2 The memmove_s function (p: TBD)
K.3.7.1.2 memmove_s 函式（頁碼：待定）
K.3.7.1.2 memmove_s 函式（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.24.2.2 The memmove function (p: 264)
7.24.2.2 memmove 函式（頁碼：264）
7.24.2.2 memmove 函式（頁碼：264）

- K.3.7.1.2 The memmove_s function (p: 446)
K.3.7.1.2 memmove_s 函式（頁碼：446）
K.3.7.1.2 memmove_s 函式（頁碼：446）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.24.2.2 The memmove function (p: 363)
7.24.2.2 memmove 函式（頁碼：363）
7.24.2.2 memmove 函式（頁碼：363）

- K.3.7.1.2 The memmove_s function (p: 615)
K.3.7.1.2 memmove_s 函式（頁碼：615）
K.3.7.1.2 memmove_s 函式（頁碼：615）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.21.2.2 The memmove function (p: 326)
7.21.2.2 memmove 函式（頁碼：326）
7.21.2.2 memmove 函式（頁碼：326）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.11.2.2 The memmove function
4.11.2.2 memmove 函式
4.11.2.2 memmove 函式

### See also

memcpymemcpy_s
(C11)
|   | copies one buffer to another
(function)   |

wmemmovewmemmove_s
(C95)(C11)
|   | copies a certain amount of wide characters between two, possibly overlapping, arrays
(function)   |

C++ documentation for memmove

---
來源頁路徑：`en.cppreference.com/c/string/byte/memmove.html`

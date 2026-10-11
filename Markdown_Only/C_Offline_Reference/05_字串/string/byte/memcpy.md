# memcpy, memcpy_s

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<string.h>`
|   |  |   |  |

```c
void* memcpy( void* dest, const void* src, size_t count );
```
|   |  (1) |   | (until C99) |

```c
void* memcpy( void* restrict dest, const void* restrict src, size_t count );
```
|   |   |   | (since C99) |

```c
errno_t memcpy_s( void* restrict dest, rsize_t destsz,  const void* restrict src, rsize_t count );
```
|   |  (2)  |   |  (since C11)  |

|  |  |  |  |

1) Copies `count` characters from the object pointed to by `src` to the object pointed to by `dest`. Both objects are interpreted as arrays of `unsigned char`.

The behavior is undefined if access occurs beyond the end of the `dest` array. If the objects overlap (which is a violation of the restrict contract)(since C99), the behavior is undefined. The behavior is undefined if either `dest` or `src` is an invalid or null pointer.

2) Same as (1), except that the following errors are detected at runtime and cause the entire destination range `[dest, dest + destsz)` to be zeroed out (if both `dest` and `destsz` are valid), as well as call the currently installed constraint handler function:
- `dest` or `src` is a null pointer
dest 或 src 為空指標

- `destsz` or `count` is greater than RSIZE_MAX
destsz 或 count 大於 RSIZE_MAX

- `count` is greater than `destsz` (buffer overflow would occur)
count 大於 destsz（會發生緩衝區溢位）

- the source and the destination objects overlap
源物件和目標物件重疊

The behavior is undefined if the size of the character array pointed to by `dest` < `count` <= `destsz`; in other words, an erroneous value of `destsz` does not expose the impending buffer overflow.

As with all bounds-checked functions, `memcpy_s` is only guaranteed to be available if `__STDC_LIB_EXT1__` is defined by the implementation and if the user defines `__STDC_WANT_LIB_EXT1__` to the integer constant `1` before including <string.h>.

### Parameters

| dest  |   | -  |   | pointer to the object to copy to  |

| destsz  |   | -  |   | max number of bytes to modify in the destination (typically the size of the destination object)  |

| src  |   | -  |   | pointer to the object to copy from  |

| count  |   | -  |   | number of bytes to copy  |

### Return value

1) Returns a copy of `dest`

2) Returns zero on success and non-zero value on error. Also on error, if `dest` is not a null pointer and `destsz` is valid, writes `destsz` zero bytes in to the destination array.

### Notes

`memcpy` may be used to set the effective type of an object obtained by an allocation function.
memcpy 可用來設定透過配置函式取得之物件的有效型別。
`memcpy` is the fastest library routine for memory-to-memory copy. It is usually more efficient than strcpy, which must scan the data it copies or memmove, which must take precautions to handle overlapping inputs.
`memcpy` 通常是複製記憶體資料的高效方式。和 `strcpy` 不同，它不必搜尋字串結尾；和 `memmove` 不同，它也不處理來源與目的區域重疊的情況。只有在兩段記憶體不重疊時才能使用 `memcpy`。
Several C compilers transform suitable memory-copying loops to `memcpy` calls.
有些 C 編譯器會將適合的記憶體複製迴圈轉換成 memcpy 呼叫。
Where strict aliasing prohibits examining the same memory as values of two different types, `memcpy` may be used to convert the values.
嚴格別名規則不允許用不同型別的指標讀取同一筆資料時，可以用 `memcpy` 將資料複製到另一個型別的物件中；這樣不會透過不相容的指標型別存取原物件。

### Example

Run this code

```c
#define __STDC_WANT_LIB_EXT1__ 1 #include <inttypes.h> #include <stdint.h> #include <stdio.h> #include <stdlib.h> #include <string.h> int main(void) {  // simple usage  char source[] = "once upon a midnight dreary...", dest[4];  memcpy(dest, source, sizeof dest);  for (size_t n = 0; n < sizeof dest; ++n)  putchar(dest[n]);  // setting effective type of allocated memory to be int  int* p = malloc(3 * sizeof(int)); // allocated memory has no effective type  int arr[3] = {1, 2, 3};  memcpy(p, arr, 3 * sizeof(int)); // allocated memory now has an effective type  // reinterpreting data  double d = 0.1; // int64_t n = *(int64_t*)(&d); // strict aliasing violation  int64_t n;  memcpy(&n, &d, sizeof d); // OK  printf("\n%a is %" PRIx64 " as an int64_t\n", d, n); #ifdef __STDC_LIB_EXT1__  set_constraint_handler_s(ignore_handler_s);  char src[] = "aaaaaaaaaa";  char dst[] = "xyxyxyxyxy";  int r = memcpy_s(dst,sizeof dst,src,5);  printf("dst = \"%s\", r = %d\n", dst,r);  r = memcpy_s(dst,5,src,10); // count is greater than destsz  printf("dst = \"");  for (size_t ndx = 0; ndx < sizeof dst; ++ndx)  {  char c = dst[ndx];  c ? printf("%c", c) : printf("\\0");  }  printf("\", r = %d\n", r); #endif }
```

Possible output:
可能的輸出：

```c
once 0x1.999999999999ap-4 is 3fb999999999999a as an int64_t dst = "aaaaayxyxy", r = 0 dst = "\0\0\0\0\0yxyxy", r = 22
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.24.2.1 The memcpy function (p: TBD)
7.24.2.1 memcpy 函式（頁碼：待定）
7.24.2.1 memcpy 函式（頁碼：待定）

- K.3.7.1.1 The memcpy_s function (p: TBD)
K.3.7.1.1 memcpy_s 函式（頁碼：待定）
K.3.7.1.1 memcpy_s 函式（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.24.2.1 The memcpy function (p: TBD)
7.24.2.1 memcpy 函式（頁碼：待定）
7.24.2.1 memcpy 函式（頁碼：待定）

- K.3.7.1.1 The memcpy_s function (p: TBD)
K.3.7.1.1 memcpy_s 函式（頁碼：待定）
K.3.7.1.1 memcpy_s 函式（頁碼：待定）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.24.2.1 The memcpy function (p: 362)
7.24.2.1 memcpy 函式（頁碼：362）
7.24.2.1 memcpy 函式（頁碼：362）

- K.3.7.1.1 The memcpy_s function (p: 614)
K.3.7.1.1 memcpy_s 函式（p: 614）
K.3.7.1.1 memcpy_s 函式（p: 614）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.21.2.1 The memcpy function (p: 325)
7.21.2.1 memcpy 函式（p: 325）
7.21.2.1 memcpy 函式（p: 325）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.11.2.1 The memcpy function
4.11.2.1 memcpy 函式
4.11.2.1 memcpy 函式

### See also

memccpy
(C23)
|   | copies one buffer to another, stopping after the specified delimiter
(function)   |

memmovememmove_s
(C11)
|   | moves one buffer to another
(function)   |

wmemcpywmemcpy_s
(C95)(C11)
|   | copies a certain amount of wide characters between two non-overlapping arrays
(function)   |

C++ documentation for memcpy

---
來源頁路徑：`en.cppreference.com/c/string/byte/memcpy.html`

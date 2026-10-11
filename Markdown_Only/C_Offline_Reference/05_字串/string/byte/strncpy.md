# strncpy, strncpy_s

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<string.h>`
|   |  |   |  |

```c
char* strncpy( char* dest, const char* src, size_t count );
```
|   |  (1) |   | (until C99) |

```c
char* strncpy( char* restrict dest, const char* restrict src, size_t count );
```
|   |   |   | (since C99) |

```c
errno_t strncpy_s( char* restrict dest, rsize_t destsz,  const char* restrict src, rsize_t count );
```
|   |  (2)  |   |  (since C11)  |

|  |  |  |  |

1) Copies at most `count` characters of the character array pointed to by `src` (including the terminating null character, but not any of the characters that follow the null character) to character array pointed to by `dest`.

If `count` is reached before the entire array `src` was copied, the resulting character array is not null-terminated.

If, after copying the terminating null character from `src`, `count` is not reached, additional null characters are written to `dest` until the total of `count` characters have been written.

The behavior is undefined if the character arrays overlap, if either `dest` or `src` is not a pointer to a character array (including if `dest` or `src` is a null pointer), if the size of the array pointed to by `dest` is less than `count`, or if the size of the array pointed to by `src` is less than `count` and it does not contain a null character.

2) Same as (1), except that the function does not continue writing zeroes into the destination array to pad up to `count`, it stops after writing the terminating null character (if there was no null in the source, it writes one at `dest[count]` and then stops). Also, the following errors are detected at runtime and call the currently installed constraint handler function:
- `src` or `dest` is a null pointer
src 或 dest 為空指標

- `destsz` is zero or greater than RSIZE_MAX
destsz 為零或大於 RSIZE_MAX

- `count` is greater than RSIZE_MAX
count 大於 RSIZE_MAX

- `count` is greater or equal `destsz`, but `destsz` is less or equal `strnlen_s(src, count)`, in other words, truncation would occur
count 大於或等於 destsz，但 destsz 小於或等於 strnlen_s ( src , count )，換言之，會發生截斷

- overlap would occur between the source and the destination strings
源字串和目標字串會發生重疊

The behavior is undefined if the size of the character array pointed to by `dest` < `strnlen_s(src, destsz)` <= `destsz`; in other words, an erroneous value of `destsz` does not expose the impending buffer overflow. The behavior is undefined if the size of the character array pointed to by `src` < `strnlen_s(src, count)` < `destsz`; in other words, an erroneous value of `count` does not expose the impending buffer overflow.

As with all bounds-checked functions, `strncpy_s` is only guaranteed to be available if `__STDC_LIB_EXT1__` is defined by the implementation and if the user defines `__STDC_WANT_LIB_EXT1__` to the integer constant `1` before including <string.h>.

### Parameters

| dest  |   | -  |   | pointer to the character array to copy to  |

| src  |   | -  |   | pointer to the character array to copy from  |

| count  |   | -  |   | maximum number of characters to copy  |

| destsz  |   | -  |   | the size of the destination buffer  |

### Return value

1) returns a copy of `dest`

2) returns zero on success, returns non-zero on error. Also, on error, writes zero to `dest[0]` (unless `dest` is a null pointer or `destsz` is zero or greater than RSIZE_MAX) and may clobber the rest of the destination array with unspecified values.

### Notes

As corrected by the post-C11 DR 468, `strncpy_s`, unlike strcpy_s, is only allowed to clobber the remainder of the destination array if an error occurs.
依照 C11 之後的勘誤 DR 468，與 strcpy_s 不同，strncpy_s 只有發生錯誤時才可覆寫目標陣列的其餘部分。
Unlike `strncpy`, `strncpy_s` does not pad the destination array with zeroes, This is a common source of errors when converting existing code to the bounds-checked version.
strncpy_s 不像 strncpy 那樣以零填滿目標陣列；將既有程式改成使用邊界檢查版本時，常會因此出錯。
Although truncation to fit the destination buffer is a security risk and therefore a runtime constraints violation for `strncpy_s`, it is possible to get the truncating behavior by specifying `count` equal to the size of the destination array minus one: it will copy the first `count` bytes and append the null terminator as always: `strncpy_s(dst, sizeof dst, src, (sizeof dst)-1);`
為了配合目的緩衝區而截短字串可能造成安全風險，因此對 strncpy_s 而言屬於執行階段限制違規。若仍要截短，可將 count 設為目的陣列大小減一；函式會複製前 count 個位元組，並在結尾加上空字元：strncpy_s(dst, sizeof dst, src, sizeof dst - 1);

### Example

Run this code

```c
#define __STDC_WANT_LIB_EXT1__ 1 #include <errno.h> #include <stdio.h> #include <stdlib.h> #include <string.h> int main(void) {  char src[] = "hi";  char dest[6] = "abcdef"; // no null terminator  strncpy(dest, src, 5); // writes five characters 'h', 'i', '\0', '\0', '\0' to dest  printf("strncpy(dest, src, 5) to a 6-byte dest gives : ");  for (size_t n = 0; n < sizeof dest; ++n) {  char c = dest[n];  c ? printf("'%c' ", c) : printf("'\\0' ");  }  printf("\nstrncpy(dest2, src, 2) to a 2-byte dst gives : ");  char dest2[2];  strncpy(dest2, src, 2); // truncation: writes two characters 'h', 'i', to dest2  for (size_t n = 0; n < sizeof dest2; ++n) {  char c = dest2[n];  c ? printf("'%c' ", c) : printf("'\\0' ");  }  printf("\n"); #ifdef __STDC_LIB_EXT1__  set_constraint_handler_s(ignore_handler_s);  char dst1[6], src1[100] = "hello";  errno_t r1 = strncpy_s(dst1, 6, src1, 100); // writes 0 to r1, 6 characters to dst1  printf("dst1 = \"%s\", r1 = %d\n", dst1,r1); // 'h','e','l','l','o','\0' to dst1  char dst2[5], src2[7] = {'g','o','o','d','b','y','e'};  errno_t r2 = strncpy_s(dst2, 5, src2, 7); // copy overflows the destination array  printf("dst2 = \"%s\", r2 = %d\n", dst2,r2); // writes nonzero to r2,'\0' to dst2[0]  char dst3[5];  errno_t r3 = strncpy_s(dst3, 5, src2, 4); // writes 0 to r3, 5 characters to dst3  printf("dst3 = \"%s\", r3 = %d\n", dst3,r3); // 'g', 'o', 'o', 'd', '\0' to dst3 #endif }
```

Possible output:
可能的輸出：

```c
strncpy(dest, src, 5) to a 6-byte dst gives : 'h' 'i' '\0' '\0' '\0' 'f' strncpy(dest2, src, 2) to a 2-byte dst gives : 'h' 'i' dst1 = "hello", r1 = 0 dst2 = "", r2 = 22 dst3 = "good", r3 = 0
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.24.2.4 The strncpy function (p: TBD)
7.24.2.4 strncpy 函式（p: TBD）
7.24.2.4 strncpy 函式（p: TBD）

- K.3.7.1.4 The strncpy_s function (p: TBD)
K.3.7.1.4 strncpy_s 函式（p: TBD）
K.3.7.1.4 strncpy_s 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.24.2.4 The strncpy function (p: 265)
7.24.2.4 strncpy 函式（p: 265）
7.24.2.4 strncpy 函式（p: 265）

- K.3.7.1.4 The strncpy_s function (p: 447-448)
K.3.7.1.4 strncpy_s 函式（p: 447-448）
K.3.7.1.4 strncpy_s 函式（p: 447-448）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.24.2.4 The strncpy function (p: 363-364)
7.24.2.4 strncpy 函式（p: 363-364）
7.24.2.4 strncpy 函式（p: 363-364）

- K.3.7.1.4 The strncpy_s function (p: 616-617)
K.3.7.1.4 strncpy_s 函式（p: 616-617）
K.3.7.1.4 strncpy_s 函式（p: 616-617）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.21.2.4 The strncpy function (p: 326-327)
7.21.2.4 strncpy 函式（p: 326-327）
7.21.2.4 strncpy 函式（p: 326-327）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.11.2.4 The strncpy function
4.11.2.4 strncpy 函式
4.11.2.4 strncpy 函式

### See also

strcpystrcpy_s
(C11)
|   | copies one string to another
(function)   |

memcpymemcpy_s
(C11)
|   | copies one buffer to another
(function)   |

strndup
(dynamic memory TR)
|   | allocate a copy of a string up to specified size
(function)   |

C++ documentation for strncpy

---
來源頁路徑：`en.cppreference.com/c/string/byte/strncpy.html`

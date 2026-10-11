# mbrlen

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<wchar.h>`
|   |  |   |  |

```c
size_t mbrlen( const char* s, size_t n, mbstate_t* ps );
```
|   |   |   |  (since C95)
(until C99)  |

```c
size_t mbrlen( const char* restrict s, size_t n, mbstate_t* restrict ps );
```
|   |   |   |  (since C99)  |

|  |  |  |  |

Determines the size, in bytes, of the representation of a multibyte character.
確定多位元組字元表示的位元組大小。
This function is equivalent to the call `mbrtowc(NULL, s, n, ps ? ps : &internal)` for some hidden object `internal` of type mbstate_t, except that the expression `ps` is evaluated only once.
此函式等價於對某個 mbstate_t 型別的隱藏物件 internal 呼叫 mbrtowc ( NULL , s , n , ps ? ps : & internal )，區別僅在於表示式 ps 只被求值一次。

### Parameters

| s  |   | -  |   | pointer to an element of a multibyte character string  |

| n  |   | -  |   | limit on the number of bytes in s that can be examined  |

| ps  |   | -  |   | pointer to the variable holding the conversion state  |

### Return value

The first of the following that applies:
以下第一個適用的條件：

- `0` if the next `n` or fewer bytes complete the null character or if `s` is a null pointer. Both cases reset the conversion state.
如果接下來的 n 個或更少的位元組構成空字元，或如果 s 是空指標，則傳回 0。這兩種情況都會重置轉換狀態。

- the number of bytes `[1...n]` that complete a valid multibyte character
構成一個有效多位元組字元的位元組數 [ 1. .. n ]

- `(size_t)-2` if the next `n` bytes are part of a possibly valid multibyte character, which is still incomplete after examining all `n` bytes
如果接下來的 n 個位元組是某個可能有效的多位元組字元的一部分，且在檢查完全部 n 個位元組後仍不完整，則傳回 ( size_t ) -2

- `(size_t)-1` if encoding error occurs. The value of errno is EILSEQ; the conversion state is unspecified.
如果發生編碼錯誤則傳回 ( size_t ) -1。errno 的值為 EILSEQ；轉換狀態未指定。

### Example

Run this code

```c
#include <locale.h> #include <stdio.h> #include <string.h> #include <wchar.h> int main(void) {  // allow mbrlen() to work with UTF-8 multibyte encoding  setlocale(LC_ALL, "en_US.utf8");  // UTF-8 narrow multibyte encoding  const char* str = "水";  size_t sz = strlen(str);  mbstate_t mb;  memset(&mb, 0, sizeof mb);  int len1 = mbrlen(str, 1, &mb);  if (len1 == -2)  printf("The first 1 byte of %s is an incomplete multibyte char"  " (mbrlen returns -2)\n", str);  int len2 = mbrlen(str + 1, sz - 1, &mb);  printf("The remaining %zu bytes of %s hold %d bytes of the multibyte"  " character\n", sz - 1, str, len2);  printf("Attempting to call mbrlen() in the middle of %s while in initial"  " shift state returns %zd\n", str, mbrlen(str + 1, sz - 1, &mb)); }
```

Output:

```c
The first 1 byte of 水 is an incomplete multibyte char (mbrlen returns -2) The remaining 2 bytes of 水 hold 2 bytes of the multibyte character Attempting to call mbrlen() in the middle of 水 while in initial shift state returns -1
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.29.6.3.1 The mbrlen function (p: TBD)
7.29.6.3.1 mbrlen 函式（p: TBD）
7.29.6.3.1 mbrlen 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.29.6.3.1 The mbrlen function (p: TBD)
7.29.6.3.1 mbrlen 函式（p: TBD）
7.29.6.3.1 mbrlen 函式（p: TBD）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.29.6.3.1 The mbrlen function (p: 442)
7.29.6.3.1 mbrlen 函式（p: 442）
7.29.6.3.1 mbrlen 函式（p: 442）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.24.6.3.1 The mbrlen function (p: 388)
7.24.6.3.1 mbrlen 函式（p: 388）
7.24.6.3.1 mbrlen 函式（p: 388）

### See also

mbrtowc
(C95)
|   | converts the next multibyte character to wide character, given state
(function)   |

mblen
|   | returns the number of bytes in the next multibyte character
(function)   |

C++ documentation for mbrlen

---
來源頁路徑：`en.cppreference.com/c/string/multibyte/mbrlen.html`

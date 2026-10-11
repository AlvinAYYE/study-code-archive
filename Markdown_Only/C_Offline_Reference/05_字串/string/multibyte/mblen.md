# mblen

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdlib.h>`
|   |  |   |  |

```c
int mblen( const char* s, size_t n );
```
|   |   |   |   |

|  |  |  |  |

Determines the size, in bytes, of the multibyte character whose first byte is pointed to by `s`.
確定首位元組由 s 指向的多位元組字元的位元組大小。
If `s` is a null pointer, resets the global conversion state and(until C23) determined whether shift sequences are used.
如果 s 是空指標，則重置全域性轉換狀態，並（在 C23 之前）確定是否使用移位序列。
This function is equivalent to the call `mbtowc((wchar_t*)0, s, n)`, except that conversion state of mbtowc is unaffected.
此函式等價於呼叫 mbtowc (( wchar_t * ) 0 , s , n )，區別在於 mbtowc 的轉換狀態不受影響。

### Parameters

| s  |   | -  |   | pointer to the multibyte character  |

| n  |   | -  |   | limit on the number of bytes in s that can be examined  |

### Return value

If `s` is not a null pointer, returns the number of bytes that are contained in the multibyte character or `-1` if the first bytes pointed to by `s` do not form a valid multibyte character or `0` if `s` is pointing at the null charcter `'\0'`.
如果 s 不是空指標，則傳回該多位元組字元中包含的位元組數；如果 s 所指向的首位元組不構成有效的多位元組字元則傳回 -1 ；如果 s 指向空字元 '\0' 則傳回 0 。
If `s` is a null pointer, resets its internal conversion state to represent the initial shift state and(until C23) returns `0` if the current multibyte encoding is not state-dependent (does not use shift sequences) or a non-zero value if the current multibyte encoding is state-dependent (uses shift sequences).
如果 s 是空指標，則將其內部轉換狀態重置為表示初始移位狀態，並（在 C23 之前）在目前多位元組編碼不是狀態相關的（不使用移位序列）時傳回 0 ，在目前多位元組編碼是狀態相關的（使用移位序列）時傳回非零值。

### Notes

Each call to `mblen` updates the internal global conversion state (a static object of type mbstate_t, only known to this function). If the multibyte encoding uses shift states, care must be taken to avoid backtracking or multiple scans. In any case, multiple threads should not call `mblen` without synchronization: mbrlen may be used instead.
|   | (until C23) |

`mblen` is not allowed to have an internal state.
|   | (since C23) |

### Example

Run this code

```c
#include <locale.h> #include <stdio.h> #include <stdlib.h> #include <string.h> // the number of characters in a multibyte string is the sum of mblen()'s // note: the simpler approach is mbstowcs(NULL, str, sz) size_t strlen_mb(const char* ptr) {  size_t result = 0;  const char* end = ptr + strlen(ptr);  mblen(NULL, 0); // reset the conversion state  while(ptr < end) {  int next = mblen(ptr, end - ptr);  if (next == -1) {  perror("strlen_mb");  break;  }  ptr += next;  ++result;  }  return result; } void dump_bytes(const char* str) {  for (const char* end = str + strlen(str); str != end; ++str)  printf("%02X ", (unsigned char)str[0]);  printf("\n"); } int main(void) {  setlocale(LC_ALL, "en_US.utf8");  const char* str = "z\u00df\u6c34\U0001f34c";  printf("The string \"%s\" consists of %zu characters, but %zu bytes: ",  str, strlen_mb(str), strlen(str));  dump_bytes(str); }
```

Possible output:
可能的輸出：

```c
The string "zß水🍌" consists of 4 characters, but 10 bytes: 7A C3 9F E6 B0 B4 F0 9F 8D 8C
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.22.7.1 The mblen function (p: 260)
7.22.7.1 mblen 函式（p: 260）
7.22.7.1 mblen 函式（p: 260）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.22.7.1 The mblen function (p: 357)
7.22.7.1 mblen 函式（p: 357）
7.22.7.1 mblen 函式（p: 357）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.20.7.1 The mblen function (p: 321)
7.20.7.1 mblen 函式（p: 321）
7.20.7.1 mblen 函式（p: 321）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.10.7.1 The mblen function
4.10.7.1 mblen 函式
4.10.7.1 mblen 函式

### See also

mbtowc
|   | converts the next multibyte character to wide character
(function)   |

mbrlen
(C95)
|   | returns the number of bytes in the next multibyte character, given state
(function)   |

C++ documentation for mblen

---
來源頁路徑：`en.cppreference.com/c/string/multibyte/mblen.html`

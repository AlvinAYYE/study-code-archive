# strspn

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<string.h>`
|   |  |   |  |

```c
size_t strspn( const char* dest, const char* src );
```
|   |   |   |   |

|  |  |  |  |

Returns the length of the maximum initial segment (span) of the null-terminated byte string pointed to by `dest`, that consists of only the characters found in the null-terminated byte string pointed to by `src`.
傳回 dest 指向的空終止位元組字串的最大初始段（span）的長度，該段僅包含 src 指向的空終止位元組字串中的字元。
The behavior is undefined if either `dest` or `src` is not a pointer to a null-terminated byte string.
如果 dest 或 src 不是指向空終止位元組字串的指標，則行為未定義。

### Parameters

| dest  |   | -  |   | pointer to the null-terminated byte string to be analyzed  |

| src  |   | -  |   | pointer to the null-terminated byte string that contains the characters to search for  |

### Return value

The length of the maximum initial segment that contains only characters from the null-terminated byte string pointed to by `src`.
僅包含 src 指向的空終止位元組字串中的字元的最大初始段的長度。

### Example

Run this code

```c
#include <stdio.h> #include <string.h> int main(void) {  const char* string = "abcde312$#@";  const char* low_alpha = "qwertyuiopasdfghjklzxcvbnm";  size_t spnsz = strspn(string, low_alpha);  printf("After skipping initial lowercase letters from '%s'\n"  "The remainder is '%s'\n", string, string + spnsz); }
```

Output:

```c
After skipping initial lowercase letters from 'abcde312$#@' The remainder is '312$#@'
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.24.5.6 The strspn function (p: TBD)
7.24.5.6 strspn 函式（頁碼：待定）
7.24.5.6 strspn 函式（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.24.5.6 The strspn function (p: TBD)
7.24.5.6 strspn 函式（頁碼：待定）
7.24.5.6 strspn 函式（頁碼：待定）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.24.5.6 The strspn function (p: 369)
7.24.5.6 strspn 函式（頁碼：369）
7.24.5.6 strspn 函式（頁碼：369）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.21.5.6 The strspn function (p: 332)
7.21.5.6 strspn 函式（頁碼：332）
7.21.5.6 strspn 函式（頁碼：332）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.11.5.6 The strspn function
4.11.5.6 strspn 函式
4.11.5.6 strspn 函式

### See also

strcspn
|   | returns the length of the maximum initial segment that consists
of only the characters not found in another byte string
(function)   |

wcsspn
(C95)
|   | returns the length of the maximum initial segment that consists
of only the wide characters found in another wide string
(function)   |

strpbrk
|   | finds the first location of any character in one string, in another string
(function)   |

C++ documentation for strspn

---
來源頁路徑：`en.cppreference.com/c/string/byte/strspn.html`

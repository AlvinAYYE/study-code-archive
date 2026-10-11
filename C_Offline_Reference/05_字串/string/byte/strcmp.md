# strcmp

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<string.h>`
|   |  |   |  |

```c
int strcmp( const char* lhs, const char* rhs );
```
|   |   |   |   |

|  |  |  |  |

Compares two null-terminated byte strings lexicographically.
依字典序比較兩個以空字元結尾的位元組字串。
The sign of the result is the sign of the difference between the values of the first pair of characters (both interpreted as `unsigned char`) that differ in the strings being compared.
傳回值的正負號，取決於兩個字串中第一組不同字元的值之差；比較時會將字元視為 unsigned char。
The behavior is undefined if `lhs` or `rhs` are not pointers to null-terminated byte strings.
若 lhs 或 rhs 未指向以空字元結尾的位元組字串，行為未定義。

### Parameters

| lhs, rhs  |   | -  |   | pointers to the null-terminated byte strings to compare  |

### Return value

Negative value if `lhs` appears before `rhs` in lexicographical order.
若 lhs 在字典序中排在 rhs 之前，傳回負值。
Zero if `lhs` and `rhs` compare equal.
如果 lhs 和 rhs 相等，則傳回零。
Positive value if `lhs` appears after `rhs` in lexicographical order.
若 lhs 在字典序中排在 rhs 之後，傳回正值。

### Notes

This function is not locale-sensitive, unlike strcoll and strxfrm.
此函式不會依地區設定調整比較方式；strcoll 和 strxfrm 則會。

### Example

Run this code

```c
#include <stdio.h> #include <string.h> void demo(const char* lhs, const char* rhs) {  const int rc = strcmp(lhs, rhs);  const char* rel = rc < 0 ? "precedes" : rc > 0 ? "follows" : "equals";  printf("[%s] %s [%s]\n", lhs, rel, rhs); } int main(void) {  const char* string = "Hello World!";  demo(string, "Hello!");  demo(string, "Hello");  demo(string, "Hello there");  demo("Hello, everybody!" + 12, "Hello, somebody!" + 11); }
```

Output:

```c
[Hello World!] precedes [Hello!] [Hello World!] follows [Hello] [Hello World!] precedes [Hello there] [body!] equals [body!]
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.24.4.2 The strcmp function (p: TBD)
7.24.4.2 strcmp 函式（頁碼：待定）
7.24.4.2 strcmp 函式（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.24.4.2 The strcmp function (p: TBD)
7.24.4.2 strcmp 函式（頁碼：待定）
7.24.4.2 strcmp 函式（頁碼：待定）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.24.4.2 The strcmp function (p: 365-366)
7.24.4.2 strcmp 函式（頁碼：365-366）
7.24.4.2 strcmp 函式（頁碼：365-366）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.21.4.2 The strcmp function (p: 328-329)
7.21.4.2 strcmp 函式（頁碼：328-329）
7.21.4.2 strcmp 函式（頁碼：328-329）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.11.4.2 The strcmp function
4.11.4.2 strcmp 函式
4.11.4.2 strcmp 函式

### See also

strncmp
|   | compares a certain amount of characters of two strings
(function)   |

wcscmp
(C95)
|   | compares two wide strings
(function)   |

memcmp
|   | compares two buffers
(function)   |

strcoll
|   | compares two strings in accordance to the current locale
(function)   |

C++ documentation for strcmp

---
來源頁路徑：`en.cppreference.com/c/string/byte/strcmp.html`

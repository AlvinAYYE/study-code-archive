# strncmp

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<string.h>`
|   |  |   |  |

```c
int strncmp( const char* lhs, const char* rhs, size_t count );
```
|   |   |   |   |

|  |  |  |  |

Compares at most `count` characters of two possibly null-terminated arrays. The comparison is done lexicographically. Characters following the null character are not compared.
比較兩個可能空終止的陣列的至多 count 個字元。比較按字典序進行。空字元之後的字元不比較。
The sign of the result is the sign of the difference between the values of the first pair of characters (both interpreted as `unsigned char`) that differ in the arrays being compared.
結果的符號是在被比較陣列中第一對不同的字元（均解釋為 unsigned char ）值之差的符號。
The behavior is undefined when access occurs past the end of either array `lhs` or `rhs`. The behavior is undefined when either `lhs` or `rhs` is the null pointer.
當訪問超出 lhs 或 rhs 任一陣列的末尾時，行為未定義。當 lhs 或 rhs 為空指標時，行為未定義。

### Parameters

| lhs, rhs  |   | -  |   | pointers to the possibly null-terminated arrays to compare  |

| count  |   | -  |   | maximum number of characters to compare  |

### Return value

Negative value if `lhs` appears before `rhs` in lexicographical order.
如果 lhs 在字典序中出現在 rhs 之前，則傳回負值。
Zero if `lhs` and `rhs` compare equal, or if count is zero.
如果 lhs 和 rhs 相等，或 count 為零，則傳回零。
Positive value if `lhs` appears after `rhs` in lexicographical order.
如果 lhs 在字典序中出現在 rhs 之後，則傳回正值。

### Notes

This function is not locale-sensitive, unlike strcoll and strxfrm.
此函式不區分本地化環境，與 strcoll 和 strxfrm 不同。

### Example

Run this code

```c
#include <stdio.h> #include <string.h> void demo(const char* lhs, const char* rhs, int sz) {  const int rc = strncmp(lhs, rhs, sz);  if (rc < 0)  printf("First %d chars of [%s] precede [%s]\n", sz, lhs, rhs);  else if (rc > 0)  printf("First %d chars of [%s] follow [%s]\n", sz, lhs, rhs);  else  printf("First %d chars of [%s] equal [%s]\n", sz, lhs, rhs); } int main(void) {  const char* string = "Hello World!";  demo(string, "Hello!", 5);  demo(string, "Hello", 10);  demo(string, "Hello there", 10);  demo("Hello, everybody!" + 12, "Hello, somebody!" + 11, 5); }
```

Output:

```c
First 5 chars of [Hello World!] equal [Hello!] First 10 chars of [Hello World!] follow [Hello] First 10 chars of [Hello World!] precede [Hello there] First 5 chars of [body!] equal [body!]
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.24.4.4 The strncmp function (p: TBD)
7.24.4.4 strncmp 函式（頁碼：待定）
7.24.4.4 strncmp 函式（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.24.4.4 The strncmp function (p: TBD)
7.24.4.4 strncmp 函式（頁碼：待定）
7.24.4.4 strncmp 函式（頁碼：待定）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.24.4.4 The strncmp function (p: 366)
7.24.4.4 strncmp 函式（頁碼：366）
7.24.4.4 strncmp 函式（頁碼：366）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.21.4.4 The strncmp function (p: 329)
7.21.4.4 strncmp 函式（頁碼：329）
7.21.4.4 strncmp 函式（頁碼：329）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.11.4.4 The strncmp function
4.11.4.4 strncmp 函式
4.11.4.4 strncmp 函式

### See also

strcmp
|   | compares two strings
(function)   |

wcsncmp
(C95)
|   | compares a certain amount of characters from two wide strings
(function)   |

memcmp
|   | compares two buffers
(function)   |

strcoll
|   | compares two strings in accordance to the current locale
(function)   |

C++ documentation for strncmp

---
來源頁路徑：`en.cppreference.com/c/string/byte/strncmp.html`

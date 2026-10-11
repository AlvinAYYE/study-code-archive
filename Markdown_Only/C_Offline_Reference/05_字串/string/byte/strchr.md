# strchr

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<string.h>`
|   |  |   |  |

```c
char* strchr( const char* str, int ch );
```
|   |  (1)  |   |   |

```c
/*QChar*/ *strchr( /*QChar*/ *str, int ch );
```
|   |  (2)  |   |  (since C23)  |

|  |  |  |  |

1) Finds the first occurrence of `ch` (after conversion to `char` as if by `(char)ch`) in the null-terminated byte string pointed to by `str` (each character interpreted as `unsigned char`). The terminating null character is considered to be a part of the string and can be found when searching for `'\0'`.

2) Type-generic function equivalent to (1). Let `T` be an unqualified character object type.
- If `str` is of type `const T*`, the return type is `const char*`.
如果 str 的型別為 const T * ，則傳回型別為 const char * 。

- Otherwise, if `str` is of type `T*`, the return type is `char*`.
否則，如果 str 的型別為 T * ，則傳回型別為 char * 。

- Otherwise, the behavior is undefined.
否則，行為未定義。
如果 str 的型別為 const T * ，則傳回型別為 const char * 。否則，如果 str 的型別為 T * ，則傳回型別為 char * 。其他情況下，行為未定義。
If a macro definition of each of these generic functions is suppressed to access an actual function (e.g. if `(strchr)` or a function pointer is used), the actual function declaration (1) becomes visible.

The behavior is undefined if `str` is not a pointer to a null-terminated byte string.
如果 str 不是指向空終止位元組字串的指標，則行為未定義。

### Parameters

| str  |   | -  |   | pointer to the null-terminated byte string to be analyzed  |

| ch  |   | -  |   | character to search for  |

### Return value

Pointer to the found character in `str`, or null pointer if no such character is found.
若找到該字元，傳回它在 str 中首次出現位置的指標；若找不到，則傳回空指標。

### Example

Run this code

```c
#include <stdio.h> #include <string.h> int main(void) {  const char *str = "Try not. Do, or do not. There is no try.";  char target = 'T';  const char* result = str;  while((result = strchr(result, target)) != NULL)  {  printf("Found '%c' starting at '%s'\n", target, result);  ++result; // Increment result, otherwise we'll find target at the same location  } }
```

Output:

```c
Found 'T' starting at 'Try not. Do, or do not. There is no try.' Found 'T' starting at 'There is no try.'
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.24.5.2 The strchr function (p: TBD)
7.24.5.2 strchr 函式（頁碼：待定）
7.24.5.2 strchr 函式（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.24.5.2 The strchr function (p: TBD)
7.24.5.2 strchr 函式（頁碼：待定）
7.24.5.2 strchr 函式（頁碼：待定）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.24.5.2 The strchr function (p: 367-368)
7.24.5.2 strchr 函式（頁碼：367-368）
7.24.5.2 strchr 函式（頁碼：367-368）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.21.5.2 The strchr function (p: 330)
7.21.5.2 strchr 函式（頁碼：330）
7.21.5.2 strchr 函式（頁碼：330）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.11.5.2 The strchr function
4.11.5.2 strchr 函式
4.11.5.2 strchr 函式

### See also

memchr
|   | searches an array for the first occurrence of a character
(function)   |

strrchr
|   | finds the last occurrence of a character
(function)   |

strpbrk
|   | finds the first location of any character in one string, in another string
(function)   |

C++ documentation for strchr

---
來源頁路徑：`en.cppreference.com/c/string/byte/strchr.html`

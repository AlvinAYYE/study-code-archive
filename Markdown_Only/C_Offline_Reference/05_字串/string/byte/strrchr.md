# strrchr

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<string.h>`
|   |  |   |  |

```c
char* strrchr( const char* str, int ch );
```
|   |  (1)  |   |   |

```c
/*QChar*/* strrchr( /*QChar*/* str, int ch );
```
|   |  (2)  |   |  (since C23)  |

|  |  |  |  |

1) Finds the last occurrence of `ch` (after conversion to `char` as if by `(char)ch`) in the null-terminated byte string pointed to by `str` (each character interpreted as `unsigned char`). The terminating null character is considered to be a part of the string and can be found if searching for `'\0'`.

2) Type-generic function equivalent to (1). Let `T` be an unqualified character object type.
- If `str` is of type `const T*`, the return type is `const char*`.
如果 str 的型別為 const T * ，則傳回型別為 const char * 。

- Otherwise, if `str` is of type `T*`, the return type is `char*`.
否則，如果 str 的型別為 T * ，則傳回型別為 char * 。

- Otherwise, the behavior is undefined.
否則，行為未定義。
如果 str 的型別為 const T * ，則傳回型別為 const char * 。否則，如果 str 的型別為 T * ，則傳回型別為 char * 。其他情況下，行為未定義。
If a macro definition of each of these generic functions is suppressed to access an actual function (e.g. if `(strrchr)` or a function pointer is used), the actual function declaration (1) becomes visible.

The behavior is undefined if `str` is not a pointer to a null-terminated byte string.
如果 str 不是指向空終止位元組字串的指標，則行為未定義。

### Parameters

| str  |   | -  |   | pointer to the null-terminated byte string to be analyzed  |

| ch  |   | -  |   | character to search for  |

### Return value

Pointer to the found character in `str`, or null pointer if no such character is found.
指向 str 中找到的字元的指標，如果未找到這樣的字元則為空指標。

### Example

Run this code

```c
#include <stdio.h> #include <string.h> int main(void) {  char szSomeFileName[] = "foo/bar/foobar.txt";  char* pLastSlash = strrchr(szSomeFileName, '/');  char* pszBaseName = pLastSlash ? pLastSlash + 1 : szSomeFileName;  printf("Base Name: %s", pszBaseName); }
```

Output:

```c
Base Name: foobar.txt
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.24.5.5 The strrchr function (p: TBD)
7.24.5.5 strrchr 函式（p: TBD）
7.24.5.5 strrchr 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.24.5.5 The strrchr function (p: TBD)
7.24.5.5 strrchr 函式（p: TBD）
7.24.5.5 strrchr 函式（p: TBD）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.24.5.5 The strrchr function (p: 368-369)
7.24.5.5 strrchr 函式（p: 368-369）
7.24.5.5 strrchr 函式（p: 368-369）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.21.5.5 The strrchr function (p: 331)
7.21.5.5 strrchr 函式（p: 331）
7.21.5.5 strrchr 函式（p: 331）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.11.5.5 The strrchr function
4.11.5.5 strrchr 函式
4.11.5.5 strrchr 函式

### See also

strchr
|   | finds the first occurrence of a character
(function)   |

strpbrk
|   | finds the first location of any character in one string, in another string
(function)   |

C++ documentation for strrchr

---
來源頁路徑：`en.cppreference.com/c/string/byte/strrchr.html`

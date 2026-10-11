# strstr

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<string.h>`
|   |  |   |  |

```c
char* strstr( const char* str, const char* substr );
```
|   |  (1)  |   |   |

```c
/*QChar*/* strstr( /*QChar*/* str, const char* substr );
```
|   |  (2)  |   |  (since C23)  |

|  |  |  |  |

1) Finds the first occurrence of the null-terminated byte string pointed to by `substr` in the null-terminated byte string pointed to by `str`. The terminating null characters are not compared.

2) Type-generic function equivalent to (1). Let `T` be an unqualified character object type.
- If `str` is of type `const T*`, the return type is `const char*`.
如果 str 的型別為 const T * ，則傳回型別為 const char * 。

- Otherwise, if `str` is of type `T*`, the return type is `char*`.
否則，如果 str 的型別為 T * ，則傳回型別為 char * 。

- Otherwise, the behavior is undefined.
否則，行為未定義。
如果 str 的型別為 const T * ，則傳回型別為 const char * 。否則，如果 str 的型別為 T * ，則傳回型別為 char * 。其他情況下，行為未定義。
If a macro definition of each of these generic functions is suppressed to access an actual function (e.g. if `(strstr)` or a function pointer is used), the actual function declaration (1) becomes visible.

The behavior is undefined if either `str` or `substr` is not a pointer to a null-terminated byte string.
若 str 或 substr 未指向以空字元結尾的位元組字串，行為未定義。

### Parameters

| str  |   | -  |   | pointer to the null-terminated byte string to examine  |

| substr  |   | -  |   | pointer to the null-terminated byte string to search for  |

### Return value

Pointer to the first character of the found substring in `str`, or a null pointer if such substring is not found. If `substr` points to an empty string, `str` is returned.
若在 str 中找到 substr，傳回該子字串第一個字元的指標；找不到時傳回空指標。若 substr 是空字串，則傳回 str。

### Example

Run this code

```c
#include <stdio.h> #include <string.h> void find_str(char const* str, char const* substr) {  char const* pos = strstr(str, substr);  if (pos)  printf(  "Found the string [%s] in [%s] at position %td\n",  substr, str, pos - str  );  else  printf(  "The string [%s] was not found in [%s]\n",  substr, str  ); } int main(void) {  char const* str = "one two three";  find_str(str, "two");  find_str(str, "");  find_str(str, "nine");  find_str(str, "n");    return 0; }
```

Output:

```c
Found the string [two] in [one two three] at position 4 Found the string [] in [one two three] at position 0 The string [nine] was not found in [one two three] Found the string [n] in [one two three] at position 1
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.24.5.7 The strstr function (p: TBD)
7.24.5.7 strstr 函式（頁碼：待定）
7.24.5.7 strstr 函式（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.24.5.7 The strstr function (p: 269)
7.24.5.7 strstr 函式（頁碼：269）
7.24.5.7 strstr 函式（頁碼：269）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.24.5.7 The strstr function (p: 369)
7.24.5.7 strstr 函式（頁碼：369）
7.24.5.7 strstr 函式（頁碼：369）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.21.5.7 The strstr function (p: 332)
7.21.5.7 strstr 函式（頁碼：332）
7.21.5.7 strstr 函式（頁碼：332）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.11.5.7 The strstr function
4.11.5.7 strstr 函式
4.11.5.7 strstr 函式

### See also

strchr
|   | finds the first occurrence of a character
(function)   |

strrchr
|   | finds the last occurrence of a character
(function)   |

C++ documentation for strstr

---
來源頁路徑：`en.cppreference.com/c/string/byte/strstr.html`

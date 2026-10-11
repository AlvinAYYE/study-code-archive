# strpbrk

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<string.h>`
|   |  |   |  |

```c
char *strpbrk( const char *dest, const char *breakset );
```
|   |  (1)  |   |   |

```c
/*QChar*/ *strpbrk( /*QChar*/ *dest, const char *breakset );
```
|   |  (2)  |   |  (since C23)  |

|  |  |  |  |

1 ) Scans the null-terminated byte string pointed to by `dest` for any character from the null-terminated byte string pointed to by `breakset`, and returns a pointer to that character.

2) Type-generic function equivalent to (1). Let `T` be an unqualified character object type.
- If `dest` is of type `const T*`, the return type is `const char*`.
如果 dest 的型別為 const T * ，則傳回型別為 const char * 。

- Otherwise, if `dest` is of type `T*`, the return type is `char*`.
否則，如果 dest 的型別為 T * ，則傳回型別為 char * 。

- Otherwise, the behavior is undefined.
否則，行為未定義。
如果 dest 的型別為 const T * ，則傳回型別為 const char * 。否則，如果 dest 的型別為 T * ，則傳回型別為 char * 。其他情況下，行為未定義。
If a macro definition of each of these generic functions is suppressed to access an actual function (e.g. if `(strpbrk)` or a function pointer is used), the actual function declaration (1) becomes visible.

The behavior is undefined if either `dest` or `breakset` is not a pointer to a null-terminated byte string.
如果 dest 或 breakset 不是指向空終止位元組字串的指標，則行為未定義。

### Parameters

| dest  |   | -  |   | pointer to the null-terminated byte string to be analyzed  |

| breakset  |   | -  |   | pointer to the null-terminated byte string that contains the characters to search for  |

### Return value

Pointer to the first character in `dest`, that is also in `breakset`, or null pointer if no such character exists.
指向 dest 中第一個也在 breakset 中的字元的指標，如果不存在這樣的字元則為空指標。

### Notes

The name stands for "string pointer break", because it returns a pointer to the first of the separator ("break") characters.
該名稱代表 "string pointer break"，因為它傳回指向第一個分隔符（"break"）字元的指標。

### Example

Run this code

```c
#include <stdio.h> #include <string.h> int main(void) {  const char* str = "hello world, friend of mine!";  const char* sep = " ,!";  unsigned int cnt = 0;  do  {  str = strpbrk(str, sep); // find separator  if(str) str += strspn(str, sep); // skip separator  ++cnt; // increment word count  }  while(str && *str);  printf("There are %u words\n", cnt); }
```

Output:

```c
There are 5 words
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.24.5.4 The strpbrk function (p: TBD)
7.24.5.4 strpbrk 函式（頁碼：待定）
7.24.5.4 strpbrk 函式（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.24.5.4 The strpbrk function (p: TBD)
7.24.5.4 strpbrk 函式（頁碼：待定）
7.24.5.4 strpbrk 函式（頁碼：待定）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.24.5.4 The strpbrk function (p: 368)
7.24.5.4 strpbrk 函式（頁碼：368）
7.24.5.4 strpbrk 函式（頁碼：368）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.21.5.4 The strpbrk function (p: 331)
7.21.5.4 strpbrk 函式（頁碼：331）
7.21.5.4 strpbrk 函式（頁碼：331）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.11.5.4 The strpbrk function
4.11.5.4 strpbrk 函式
4.11.5.4 strpbrk 函式

### See also

strcspn
|   | returns the length of the maximum initial segment that consists
of only the characters not found in another byte string
(function)   |

strchr
|   | finds the first occurrence of a character
(function)   |

strtokstrtok_s
(C11)
|   | finds the next token in a byte string
(function)   |

C++ documentation for strpbrk

---
來源頁路徑：`en.cppreference.com/c/string/byte/strpbrk.html`

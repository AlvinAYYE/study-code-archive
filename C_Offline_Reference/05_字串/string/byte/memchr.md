# memchr

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<string.h>`
|   |  |   |  |

```c
void* memchr( const void* ptr, int ch, size_t count );
```
|   |  (1)  |   |   |

```c
/*QVoid*/ *memchr( /*QVoid*/ *ptr, int ch, size_t count );
```
|   |  (2)  |   |  (since C23)  |

|  |  |  |  |

1) Finds the first occurrence of `(unsigned char)ch` in the initial `count` bytes (each interpreted as `unsigned char`) of the object pointed to by `ptr`.

2) Type-generic function equivalent to (1). Let `T` be an unqualified object type (including `void`).
- If `ptr` is of type `const T*`, the return type is `const void*`.
如果 ptr 的型別為 const T *，則傳回型別為 const void *。

- Otherwise, if `ptr` is of type `T*`, the return type is `void*`.
否則，如果 ptr 的型別為 T *，則傳回型別為 void *。

- Otherwise, the behavior is undefined.
否則，行為未定義。
如果 ptr 的型別為 const T *，則傳回型別為 const void *。否則，如果 ptr 的型別為 T *，則傳回型別為 void *。否則，行為未定義。
If a macro definition of each of these generic functions is suppressed to access an actual function (e.g. if `(memchr)` or a function pointer is used), the actual function declaration (1) becomes visible.

The behavior is undefined if access occurs beyond the end of the array searched. The behavior is undefined if `ptr` is a null pointer.
如果訪問超出被搜尋陣列的末尾，則行為未定義。如果 ptr 為空指標，則行為未定義。

This function behaves as if it reads the bytes sequentially and stops as soon as a matching bytes is found: if the array pointed to by `ptr` is smaller than `count`, but the match is found within the array, the behavior is well-defined.
|   | (since C11) |

### Parameters

| ptr  |   | -  |   | pointer to the object to be examined  |

| ch  |   | -  |   | bytes to search for  |

| count  |   | -  |   | max number of bytes to examine  |

### Return value

Pointer to the location of the byte, or a null pointer if no such byte is found.
指向位元組位置的指標，如果未找到這樣的位元組則為空指標。

### Example

Run this code

```c
#include <stdio.h> #include <string.h> int main(void) {  const char str[] = "ABCDEFG";  const int chars[] = {'D', 'd'};  for (size_t i = 0; i < sizeof chars / (sizeof chars[0]); ++i)  {  const int c = chars[i];  const char *ps = memchr(str, c, strlen(str));  ps ? printf ("character '%c'(%i) found: %s\n", c, c, ps)  : printf ("character '%c'(%i) not found\n", c, c);  }  return 0; }
```

Possible output:
可能的輸出：

```c
character 'D'(68) found: DEFG character 'd'(100) not found
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.24.5.1 The memchr function (p: TBD)
7.24.5.1 memchr 函式（頁碼：待定）
7.24.5.1 memchr 函式（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.24.5.1 The memchr function (p: 267-268)
7.24.5.1 memchr 函式（頁碼：267-268）
7.24.5.1 memchr 函式（頁碼：267-268）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.24.5.1 The memchr function (p: 367)
7.24.5.1 memchr 函式（頁碼：367）
7.24.5.1 memchr 函式（頁碼：367）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.21.5.1 The memchr function (p: 330)
7.21.5.1 memchr 函式（頁碼：330）
7.21.5.1 memchr 函式（頁碼：330）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.11.5.1 The memchr function
4.11.5.1 memchr 函式
4.11.5.1 memchr 函式

### See also

strchr
|   | finds the first occurrence of a character
(function)   |

C++ documentation for memchr

---
來源頁路徑：`en.cppreference.com/c/string/byte/memchr.html`

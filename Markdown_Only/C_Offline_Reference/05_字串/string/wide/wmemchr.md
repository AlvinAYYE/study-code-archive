# wmemchr

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<wchar.h>`
|   |  |   |  |

```c
wchar_t *wmemchr( const wchar_t *ptr, wchar_t ch, size_t count );
```
|   |  (1)  |   |  (since C95)  |

```c
/*QWchar_t*/ *wmemchr( /*Qwchar_t*/ *ptr, wchar_t ch, size_t count );
```
|   |  (2)  |   |  (since C23)  |

|  |  |  |  |

1) Locates the first occurrence of wide character `ch` in the initial `count` wide characters of the wide character array or integer array of compatible type, pointed to by `ptr`.

2) Type-generic function equivalent to (1). Let `T` be an unqualified wide character object type.
- If `ptr` is of type `const T*`, the return type is `const wchar_t*`.
如果 ptr 的型別為 const T * ，則傳回型別為 const wchar_t * 。

- Otherwise, if `ptr` is of type `T*`, the return type is `wchar_t*`.
否則，如果 ptr 的型別為 T * ，則傳回型別為 wchar_t * 。

- Otherwise, the behavior is undefined.
否則，行為未定義。
如果 ptr 的型別為 const T * ，則傳回型別為 const wchar_t * 。否則，如果 ptr 的型別為 T * ，則傳回型別為 wchar_t * 。其他情況下，行為未定義。
If a macro definition of each of these generic functions is suppressed to access an actual function (e.g. if `(wmemchr)` or a function pointer is used), the actual function declaration (1) becomes visible.

If `count` is zero, the function returns a null pointer.
如果 count 為零，則函式傳回空指標。

### Parameters

| ptr  |   | -  |   | pointer to the wide character array to be examined  |

| ch  |   | -  |   | wide character to search for  |

| count  |   | -  |   | number of wide characters to examine  |

### Return value

Pointer to the location of the wide character, or a null pointer if no such character is found.
指向寬字元位置的指標，如果未找到這樣的字元則為空指標。

### Example

Run this code

```c
#include <locale.h> #include <stdio.h> #include <wchar.h> int main(void) {  wchar_t str[] = L"诺不轻信，故人不负我\0诺不轻许，故我不负人。";  size_t sz = sizeof str / sizeof *str;  wchar_t target = L'许';  wchar_t* result = wmemchr(str, target, sz);  if (result)  {  setlocale(LC_ALL, "en_US.utf8");  printf("Found '%lc' at position %td\n",target, result - str);  } }
```

Possible output:
可能的輸出：

```c
Found '许' at position 14
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.29.4.5.8 The wmemchr function (p: TBD)
7.29.4.5.8 wmemchr 函式（頁碼：待定）
7.29.4.5.8 wmemchr 函式（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.29.4.5.8 The wmemchr function (p: TBD)
7.29.4.5.8 wmemchr 函式（頁碼：待定）
7.29.4.5.8 wmemchr 函式（頁碼：待定）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.29.4.5.8 The wmemchr function (p: 438)
7.29.4.5.8 wmemchr 函式（頁碼：438）
7.29.4.5.8 wmemchr 函式（頁碼：438）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.24.4.5.8 The wmemchr function (p: 384)
7.24.4.5.8 wmemchr 函式（頁碼：384）
7.24.4.5.8 wmemchr 函式（頁碼：384）

### See also

memchr
|   | searches an array for the first occurrence of a character
(function)   |

wcschr
(C95)
|   | finds the first occurrence of a wide character in a wide string
(function)   |

C++ documentation for wmemchr

---
來源頁路徑：`en.cppreference.com/c/string/wide/wmemchr.html`

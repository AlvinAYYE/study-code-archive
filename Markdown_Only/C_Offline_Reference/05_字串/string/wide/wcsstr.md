# wcsstr

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<wchar.h>`
|   |  |   |  |

```c
wchar_t *wcsstr( const wchar_t *dest, const wchar_t *src );
```
|   |  (1)  |   |  (since C95)  |

```c
/*QWchar_t*/ *wcsstr( /*QWchar_t*/ *dest, const wchar_t *src );
```
|   |  (2)  |   |  (since C23)  |

|  |  |  |  |

1) Finds the first occurrence of the wide string `src` in the wide string pointed to by `dest`. The terminating null characters are not compared.

2) Type-generic function equivalent to (1). Let `T` be an unqualified wide character object type.
- If `dest` is of type `const T*`, the return type is `const wchar_t*`.
如果 dest 的型別為 const T * ，則傳回型別為 const wchar_t * 。

- Otherwise, if `dest` is of type `T*`, the return type is `wchar_t*`.
否則，如果 dest 的型別為 T * ，則傳回型別為 wchar_t * 。

- Otherwise, the behavior is undefined.
否則，行為未定義。
如果 dest 的型別為 const T * ，則傳回型別為 const wchar_t * 。否則，如果 dest 的型別為 T * ，則傳回型別為 wchar_t * 。其他情況下，行為未定義。
If a macro definition of each of these generic functions is suppressed to access an actual function (e.g. if `(wcsstr)` or a function pointer is used), the actual function declaration (1) becomes visible.

### Parameters

| dest  |   | -  |   | pointer to the null-terminated wide string to examine  |

| src  |   | -  |   | pointer to the null-terminated wide string to search for  |

### Return value

Pointer to the first character of the found substring in `dest`, or a null pointer if no such substring is found. If `src` points to an empty string, `dest` is returned.
指向 dest 中找到的子字串的第一個字元的指標，如果未找到這樣的子字串則為空指標。如果 src 指向空字串，則傳回 dest 。

### Example

Run this code

```c
#include <stdio.h> #include <locale.h> #include <wchar.h>   int main(void) {  setlocale(LC_ALL, "ru_RU.UTF-8");  wchar_t str[5][64] = {  L"Строка, где есть подстрока 'но'.",  L"Строка, где такой подстроки нет.",  L"Он здесь.",  L"Здесь он.",  L"Его нет."  };  for (size_t i = 0; i < 5; ++i) {  if (wcsstr(str[i], L"но")) {  wprintf(L"%ls\n", str[i]);  }  } }
```

Output:

```c
Строка, где есть подстрока 'но'.
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.29.4.5.6 The wcsstr function (p: 437)
7.29.4.5.6 wcsstr 函式（頁碼：437）
7.29.4.5.6 wcsstr 函式（頁碼：437）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.24.4.5.6 The wcsstr function (p: 383)
7.24.4.5.6 wcsstr 函式（頁碼：383）
7.24.4.5.6 wcsstr 函式（頁碼：383）

### See also

wcschr
(C95)
|   | finds the first occurrence of a wide character in a wide string
(function)   |

wcsrchr
(C95)
|   | finds the last occurrence of a wide character in a wide string
(function)   |

C++ documentation for wcsstr

---
來源頁路徑：`en.cppreference.com/c/string/wide/wcsstr.html`

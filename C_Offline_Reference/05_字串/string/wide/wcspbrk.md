# wcspbrk

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<wchar.h>`
|   |  |   |  |

```c
wchar_t *wcspbrk( const wchar_t *dest, const wchar_t *str );
```
|   |  (1)  |   |  (since C95)  |

```c
/*QWchar_t*/ *wcspbrk( /*QWchar_t*/ *dest, const wchar_t *str );
```
|   |  (2)  |   |  (since C23)  |

|  |  |  |  |

1) Finds the first character in wide string pointed to by `dest`, that is also in wide string pointed to by `str`.

2) Type-generic function equivalent to (1). Let `T` be an unqualified wide character object type.
- If `dest` is of type `const T*`, the return type is `const wchar_t*`.
如果 dest 的型別為 const T * ，則傳回型別為 const wchar_t * 。

- Otherwise, if `dest` is of type `T*`, the return type is `wchar_t*`.
否則，如果 dest 的型別為 T * ，則傳回型別為 wchar_t * 。

- Otherwise, the behavior is undefined.
否則，行為未定義。
如果 dest 的型別為 const T * ，則傳回型別為 const wchar_t * 。否則，如果 dest 的型別為 T * ，則傳回型別為 wchar_t * 。其他情況下，行為未定義。
If a macro definition of each of these generic functions is suppressed to access an actual function (e.g. if `(wcspbrk)` or a function pointer is used), the actual function declaration (1) becomes visible.

### Parameters

| dest  |   | -  |   | pointer to the null-terminated wide string to be analyzed  |

| src  |   | -  |   | pointer to the null-terminated wide string that contains the characters to search for  |

### Return value

Pointer to the first character in `dest`, that is also in `str`, or a null pointer if no such character exists.
指向 dest 中第一個也在 str 中的字元的指標，如果不存在這樣的字元則為空指標。

### Notes

The name stands for "wide character string pointer break", because it returns a pointer to the first of the separator ("break") characters.
該名稱代表 "wide character string pointer break"，因為它傳回指向第一個分隔符（"break"）字元的指標。

### Example

Run this code

```c
#include <stdio.h> #include <wchar.h>   int main(void) {  const wchar_t* str = L"Hello world, friend of mine!";  const wchar_t* sep = L" ,!";    unsigned int cnt = 0;  do {  str = wcspbrk(str, sep); // find separator  if (str) str += wcsspn(str, sep); // skip separator  ++cnt; // increment word count  } while (str && *str);    wprintf(L"There are %u words.\n", cnt); }
```

Output:

```c
There are 5 words.
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.29.4.5.3 The wcspbrk function (p: 436)
7.29.4.5.3 wcspbrk 函式（頁碼：436）
7.29.4.5.3 wcspbrk 函式（頁碼：436）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.24.4.5.3 The wcspbrk function (p: 382)
7.24.4.5.3 wcspbrk 函式（頁碼：382）
7.24.4.5.3 wcspbrk 函式（頁碼：382）

### See also

wcscspn
(C95)
|   | returns the length of the maximum initial segment that consists
of only the wide chars *not* found in another wide string
(function)   |

wcschr
(C95)
|   | finds the first occurrence of a wide character in a wide string
(function)   |

strpbrk
|   | finds the first location of any character in one string, in another string
(function)   |

C++ documentation for wcspbrk

---
來源頁路徑：`en.cppreference.com/c/string/wide/wcspbrk.html`

# wcschr

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<wchar.h>`
|   |  |   |  |

```c
wchar_t *wcschr( const wchar_t *str, wchar_t ch );
```
|   |  (1)  |   |  (since C95)  |

```c
/*QWchar_t*/ *wcschr( /*QWchar_t*/ *str, wchar_t ch );
```
|   |  (2)  |   |  (since C23)  |

|  |  |  |  |

1) Finds the first occurrence of the wide character `ch` in the wide string pointed to by `str`.

2) Type-generic function equivalent to (1). Let `T` be an unqualified wide character object type.
- If `str` is of type `const T*`, the return type is `const wchar_t*`.
如果 str 的型別為 const T * ，則傳回型別為 const wchar_t * 。

- Otherwise, if `str` is of type `T*`, the return type is `wchar_t*`.
否則，如果 str 的型別為 T * ，則傳回型別為 wchar_t * 。

- Otherwise, the behavior is undefined.
否則，行為未定義。
如果 str 的型別為 const T * ，則傳回型別為 const wchar_t * 。否則，如果 str 的型別為 T * ，則傳回型別為 wchar_t * 。其他情況下，行為未定義。
If a macro definition of each of these generic functions is suppressed to access an actual function (e.g. if `(wcschr)` or a function pointer is used), the actual function declaration (1) becomes visible.

### Parameters

| str  |   | -  |   | pointer to the null-terminated wide string to be analyzed  |

| ch  |   | -  |   | wide character to search for  |

### Return value

Pointer to the found character in `str`, or a null pointer if no such character is found.
指向 str 中找到的字元的指標，如果未找到這樣的字元則為空指標。

### Example

Run this code

```c
#include <wchar.h> #include <stdio.h> #include <locale.h> int main(void) {  wchar_t arr[] = L"白猫 黒猫 кошки";  wchar_t *cat = wcschr(arr, L'猫');  wchar_t *dog = wcschr(arr, L'犬');    setlocale(LC_ALL, "en_US.utf8");  if(cat)  printf("The character 猫 found at position %td\n", cat-arr);  else  puts("The character 猫 not found");    if(dog)  printf("The character 犬 found at position %td\n", dog-arr);  else  puts("The character 犬 not found"); }
```

Output:

```c
The character 猫 found at position 1 The character 犬 not found
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.29.4.5.1 The wcschr function (p: 435)
7.29.4.5.1 wcschr 函式（頁碼：435）
7.29.4.5.1 wcschr 函式（頁碼：435）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.24.4.5.1 The wcschr function (p: 381)
7.24.4.5.1 wcschr 函式（頁碼：381）
7.24.4.5.1 wcschr 函式（頁碼：381）

### See also

wcsrchr
(C95)
|   | finds the last occurrence of a wide character in a wide string
(function)   |

wcspbrk
(C95)
|   | finds the first location of any wide character in one wide string, in another wide string
(function)   |

C++ documentation for wcschr

---
來源頁路徑：`en.cppreference.com/c/string/wide/wcschr.html`

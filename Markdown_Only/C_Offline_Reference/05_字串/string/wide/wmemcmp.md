# wmemcmp

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<wchar.h>`
|   |  |   |  |

```c
int wmemcmp( const wchar_t* lhs, const wchar_t* rhs, size_t count );
```
|   |   |   |  (since C95)  |

|  |  |  |  |

Compares the first `count` wide characters of the wide character (or compatible integer type) arrays pointed to by `lhs` and `rhs`. The comparison is done lexicographically.
比較由 lhs 和 rhs 指向的寬字元（或相容整數型別）陣列的前 count 個寬字元。比較按字典序進行。
The sign of the result is the sign of the difference between the values of the first pair of wide characters that differ in the arrays being compared.
結果的符號是在被比較陣列中第一對不同的寬字元值之差的符號。
If `count` is zero, the function does nothing.
如果 count 為零，則函式不執行任何操作。

### Parameters

| lhs, rhs  |   | -  |   | pointers to the wide character arrays to compare  |

| count  |   | -  |   | number of wide characters to examine  |

### Return value

Negative value if the value of the first differing wide character in `lhs` is less than the value of the corresponding wide character in `rhs`: `lhs` precedes `rhs` in lexicographical order.
如果 lhs 中第一對不同寬字元的值小於 rhs 中對應寬字元的值，則傳回負值： lhs 在字典序中先於 rhs 。
`0` if all `count` wide characters of `lhs` and `rhs` are equal.
如果 lhs 和 rhs 的所有 count 個寬字元都相等，則傳回 0 。
Positive value if the value of the first differing wide character in `lhs` is greater than the value of the corresponding wide character in `rhs`: `rhs` precedes `lhs` in lexicographical order.
如果 lhs 中第一對不同寬字元的值大於 rhs 中對應寬字元的值，則傳回正值： rhs 在字典序中先於 lhs 。

### Notes

This function is not locale-sensitive and pays no attention to the values of the wchar_t objects it examines: nulls as well as invalid wide characters are compared too.
此函式不區分本地化環境，也不關注它檢查的 wchar_t 物件的值：空值以及無效的寬字元也會被比較。

### Example

Run this code

```c
#include <locale.h> #include <stdio.h> #include <wchar.h> void demo(const wchar_t* lhs, const wchar_t* rhs, size_t sz) {  for (size_t n = 0; n < sz; ++n)  putwchar(lhs[n]);  int rc = wmemcmp(lhs, rhs, sz);  if (rc == 0)  wprintf(L" compares equal to ");  else if(rc < 0)  wprintf(L" precedes ");  else if(rc > 0)  wprintf(L" follows ");  for (size_t n = 0; n < sz; ++n)  putwchar(rhs[n]);  wprintf(L" in lexicographical order\n"); } int main(void) {  setlocale(LC_ALL, "en_US.utf8");  wchar_t a1[] = {L'α',L'β',L'γ'};  wchar_t a2[] = {L'α',L'β',L'δ'};  size_t sz = sizeof a1 / sizeof *a1;  demo(a1, a2, sz);  demo(a2, a1, sz);  demo(a1, a1, sz); }
```

Output:

```c
αβγ precedes αβδ in lexicographical order αβδ follows αβγ in lexicographical order αβγ compares equal to αβγ in lexicographical order
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.29.4.4.5 The wmemcmp function (p: TBD)
7.29.4.4.5 wmemcmp 函式（頁碼：待定）
7.29.4.4.5 wmemcmp 函式（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.29.4.4.5 The wmemcmp function (p: TBD)
7.29.4.4.5 wmemcmp 函式（頁碼：待定）
7.29.4.4.5 wmemcmp 函式（頁碼：待定）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.29.4.4.5 The wmemcmp function (p: 435)
7.29.4.4.5 wmemcmp 函式（頁碼：435）
7.29.4.4.5 wmemcmp 函式（頁碼：435）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.24.4.4.5 The wmemcmp function (p: 381)
7.24.4.4.5 wmemcmp 函式（頁碼：381）
7.24.4.4.5 wmemcmp 函式（頁碼：381）

### See also

wcscmp
(C95)
|   | compares two wide strings
(function)   |

memcmp
|   | compares two buffers
(function)   |

wcsncmp
(C95)
|   | compares a certain amount of characters from two wide strings
(function)   |

C++ documentation for wmemcmp

---
來源頁路徑：`en.cppreference.com/c/string/wide/wmemcmp.html`

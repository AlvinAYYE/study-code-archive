# wcsncmp

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<wchar.h>`
|   |  |   |  |

```c
int wcsncmp( const wchar_t* lhs, const wchar_t* rhs, size_t count );
```
|   |   |   |  (since C95)  |

|  |  |  |  |

Compares at most `count` wide characters of two null-terminated wide strings. The comparison is done lexicographically.
比較兩個空終止寬字串的至多 count 個寬字元。比較按字典序進行。
The sign of the result is the sign of the difference between the values of the first pair of wide characters that differ in the strings being compared.
結果的符號是在被比較字串中第一對不同的寬字元值之差的符號。
The behavior is undefined if `lhs` or `rhs` are not pointers to null-terminated strings.
如果 lhs 或 rhs 不是指向空終止字串的指標，則行為未定義。

### Parameters

| lhs, rhs  |   | -  |   | pointers to the null-terminated wide strings to compare  |

| count  |   | -  |   | maximum number of characters to compare  |

### Return value

Negative value if `lhs` appears before `rhs` in lexicographical order.
如果 lhs 在字典序中出現在 rhs 之前，則傳回負值。
Zero if `lhs` and `rhs` compare equal.
如果 lhs 和 rhs 相等，則傳回零。
Positive value if `lhs` appears after `rhs` in lexicographical order.
如果 lhs 在字典序中出現在 rhs 之後，則傳回正值。

### Notes

This function is not locale-sensitive, unlike wcscoll and wcsxfrm.
此函式不區分本地化環境，與 wcscoll 和 wcsxfrm 不同。

### Example

Run this code

```c
#include <stdio.h> #include <wchar.h> #include <locale.h> void demo(const wchar_t *lhs, const wchar_t *rhs, int sz) {  int rc = wcsncmp(lhs, rhs, sz);  if(rc == 0)  printf("First %d characters of [%ls] equal [%ls]\n", sz, lhs, rhs);  else if(rc < 0)  printf("First %d characters of [%ls] precede [%ls]\n", sz, lhs, rhs);  else if(rc > 0)  printf("First %d characters of [%ls] follow [%ls]\n", sz, lhs, rhs); } int main(void) {  const wchar_t *str1 = L"안녕하세요";  const wchar_t *str2 = L"안녕히 가십시오";  setlocale(LC_ALL, "en_US.utf8");  demo(str1, str2, 5);  demo(str2, str1, 8);  demo(str1, str2, 2); }
```

Output:

```c
First 5 characters of [안녕하세요] precede [안녕히 가십시오] First 8 characters of [안녕히 가십시오] follow [안녕하세요] First 2 characters of [안녕하세요] equal [안녕히 가십시오]
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.29.4.4.3 The wcsncmp function (p: 434)
7.29.4.4.3 wcsncmp 函式（頁碼：434）
7.29.4.4.3 wcsncmp 函式（頁碼：434）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.24.4.4.3 The wcsncmp function (p: 380)
7.24.4.4.3 wcsncmp 函式（頁碼：380）
7.24.4.4.3 wcsncmp 函式（頁碼：380）

### See also

wcscmp
(C95)
|   | compares two wide strings
(function)   |

wmemcmp
(C95)
|   | compares a certain amount of wide characters from two arrays
(function)   |

wcscoll
(C95)
|   | compares two wide strings in accordance to the current locale
(function)   |

C++ documentation for wcsncmp

---
來源頁路徑：`en.cppreference.com/c/string/wide/wcsncmp.html`

# wcscmp

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<wchar.h>`
|   |  |   |  |

```c
int wcscmp( const wchar_t* lhs, const wchar_t* rhs );
```
|   |   |   |  (since C95)  |

|  |  |  |  |

Compares two null-terminated wide strings lexicographically.
按字典序比較兩個空終止寬字串。
The sign of the result is the sign of the difference between the values of the first pair of wide characters that differ in the strings being compared.
結果的符號是在被比較字串中第一對不同的寬字元值之差的符號。
The behavior is undefined if `lhs` or `rhs` are not pointers to null-terminated wide strings.
如果 lhs 或 rhs 不是指向空終止寬字串的指標，則行為未定義。

### Parameters

| lhs, rhs  |   | -  |   | pointers to the null-terminated wide strings to compare  |

### Return value

Negative value if `lhs` appears before `rhs` in lexicographical order.
如果 lhs 在字典序中出現在 rhs 之前，則傳回負值。
Zero if `lhs` and `rhs` compare equal.
如果 lhs 和 rhs 相等，則傳回零。
Positive value if `lhs` appears after `rhs` in lexicographical order.
如果 lhs 在字典序中出現在 rhs 之後，則傳回正值。

### Notes

This function is not locale-sensitive, unlike wcscoll, and the order may not be meaningful when characters from different Unicode blocks are used together or when the order of code units does not match any collation order.
此函式不區分本地化環境，與 wcscoll 不同；當來自不同 Unicode 塊的字元一起使用，或程式碼單元的順序不匹配任何排序順序時，該順序可能沒有意義。

### Example

Run this code

```c
#include <locale.h> #include <stdio.h> #include <wchar.h> void demo(const wchar_t* lhs, const wchar_t* rhs) {  int rc = wcscmp(lhs, rhs);  const char *rel = rc < 0 ? "precedes" : rc > 0 ? "follows" : "equals";  setlocale(LC_ALL, "en_US.utf8");  printf("[%ls] %s [%ls]\n", lhs, rel, rhs); } int main(void) {  const wchar_t* string = L"どうもありがとうございます";  demo(string, L"どうも");  demo(string, L"助かった");  demo(string + 9, L"ありがとうございます" + 6); }
```

Possible output:
可能的輸出：

```c
[どうもありがとうございます] follows [どうも] [どうもありがとうございます] precedes [助かった] [ざいます] equals [ざいます]
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.29.4.4.1 The wcscmp function (p: TBD)
7.29.4.4.1 wcscmp 函式（頁碼：待定）
7.29.4.4.1 wcscmp 函式（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.29.4.4.1 The wcscmp function (p: TBD)
7.29.4.4.1 wcscmp 函式（頁碼：待定）
7.29.4.4.1 wcscmp 函式（頁碼：待定）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.29.4.4.1 The wcscmp function (p: 433)
7.29.4.4.1 wcscmp 函式（頁碼：433）
7.29.4.4.1 wcscmp 函式（頁碼：433）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.24.4.4.1 The wcscmp function (p: 379)
7.24.4.4.1 wcscmp 函式（頁碼：379）
7.24.4.4.1 wcscmp 函式（頁碼：379）

### See also

wcsncmp
(C95)
|   | compares a certain amount of characters from two wide strings
(function)   |

wmemcmp
(C95)
|   | compares a certain amount of wide characters from two arrays
(function)   |

strcmp
|   | compares two strings
(function)   |

wcscoll
(C95)
|   | compares two wide strings in accordance to the current locale
(function)   |

C++ documentation for wcscmp

---
來源頁路徑：`en.cppreference.com/c/string/wide/wcscmp.html`

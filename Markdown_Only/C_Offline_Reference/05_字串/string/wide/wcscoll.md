# wcscoll

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<wchar.h>`
|   |  |   |  |

```c
int wcscoll( const wchar_t *lhs, const wchar_t *rhs );
```
|   |   |   |  (since C95)  |

|  |  |  |  |

Compares two null-terminated wide strings according to the collation order defined by the LC_COLLATE category of the currently installed locale.
根據目前安裝的本地化環境的 LC_COLLATE 類別定義的排序順序比較兩個空終止寬字串。

### Parameters

| lhs, rhs  |   | -  |   | pointers to the null-terminated wide strings to compare  |

### Return value

Negative value if `lhs` is *less than* (precedes) `rhs`.
如果 lhs 小於（先於） rhs ，則傳回負值。
`0` if `lhs` is *equal to* `rhs`.
如果 lhs 等於 rhs ，則傳回 0 。
Positive value if `lhs` is *greater than* (follows) `rhs`.
如果 lhs 大於（後於） rhs ，則傳回正值。

### Notes

Collation order is the dictionary order: the position of the letter in the national alphabet (its *equivalence class*) has higher priority than its case or variant. Within an equivalence class, lowercase characters collate before their uppercase equivalents and locale-specific order may apply to the characters with diacritics. In some locales, groups of characters compare as single *collation units*. For example, `"ch"` in Czech follows `"h"` and precedes `"i"`, and `"dzs"` in Hungarian follows `"dz"` and precedes `"g"`.
排序順序是字典序：字母在國家字母表中的位置（其等價類 ）優先於其大小寫或變體。在等價類內，小寫字元排在其大寫對應字元之前，帶有變音符號的字元可能適用特定於本地化環境的順序。在某些本地化環境中，字元組作為單個排序單元進行比較。例如，捷克語中的 "ch" 排在 "h" 之後、 "i" 之前，匈牙利語中的 "dzs" 排在 "dz" 之後、 "g" 之前。

### Example

Run this code

```c
#include <stdio.h> #include <wchar.h> #include <locale.h> void try_compare(const wchar_t* p1, const wchar_t* p2) {  if(wcscoll(p1, p2) < 0)  printf("%ls before %ls\n", p1, p2);  else  printf("%ls before %ls\n", p2, p1); } int main(void) {  setlocale(LC_ALL, "en_US.utf8");  printf("In the American locale: ");  try_compare(L"hrnec", L"chrt");  setlocale(LC_COLLATE, "cs_CZ.utf8");  printf("In the Czech locale: ");  try_compare(L"hrnec", L"chrt");  setlocale(LC_COLLATE, "en_US.utf8");  printf("In the American locale: ");  try_compare(L"år", L"ängel");  setlocale(LC_COLLATE, "sv_SE.utf8");  printf("In the Swedish locale: ");  try_compare(L"år", L"ängel"); }
```

Possible output:
可能的輸出：

```c
In the American locale: chrt before hrnec In the Czech locale: hrnec before chrt In the American locale: ängel before år In the Swedish locale: år before ängel
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.29.4.4.2 The wcscoll function (p: 433-434)
7.29.4.4.2 wcscoll 函式（頁碼：433-434）
7.29.4.4.2 wcscoll 函式（頁碼：433-434）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.24.4.4.2 The wcscoll function (p: 379-380)
7.24.4.4.2 wcscoll 函式（頁碼：379-380）
7.24.4.4.2 wcscoll 函式（頁碼：379-380）

### See also

strcoll
|   | compares two strings in accordance to the current locale
(function)   |

wcsxfrm
(C95)
|   | transform a wide string so that wcscmp would produce the same result as wcscoll
(function)   |

wcscmp
(C95)
|   | compares two wide strings
(function)   |

C++ documentation for wcscoll

---
來源頁路徑：`en.cppreference.com/c/string/wide/wcscoll.html`

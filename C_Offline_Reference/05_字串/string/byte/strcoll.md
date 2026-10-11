# strcoll

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<string.h>`
|   |  |   |  |

```c
int strcoll( const char* lhs, const char* rhs );
```
|   |   |   |   |

|  |  |  |  |

Compares two null-terminated byte strings according to the current locale as defined by the LC_COLLATE category.
根據 LC_COLLATE 類別定義的目前本地化環境比較兩個空終止位元組字串。

### Parameters

| lhs, rhs  |   | -  |   | pointers to the null-terminated byte strings to compare  |

### Return value

- Negative value if `lhs` is *less than* (precedes) `rhs`.
如果 lhs 小於（先於） rhs ，則傳回負值。

- `0` if `lhs` is *equal to* `rhs`.
如果 lhs 等於 rhs ，則傳回 0 。

- Positive value if `lhs` is *greater than* (follows) `rhs`.
如果 lhs 大於（後於） rhs ，則傳回正值。

### Notes

Collation order is the dictionary order: the position of the letter in the national alphabet (its *equivalence class*) has higher priority than its case or variant. Within an equivalence class, lowercase characters collate before their uppercase equivalents and locale-specific order may apply to the characters with diacritics. In some locales, groups of characters compare as single *collation units*. For example, `"ch"` in Czech follows `"h"` and precedes `"i"`, and `"dzs"` in Hungarian follows `"dz"` and precedes `"g"`.
排序順序是字典序：字母在國家字母表中的位置（其等價類 ）優先於其大小寫或變體。在等價類內，小寫字元排在其大寫對應字元之前，帶有變音符號的字元可能適用特定於本地化環境的順序。在某些本地化環境中，字元組作為單個排序單元進行比較。例如，捷克語中的 "ch" 排在 "h" 之後、 "i" 之前，匈牙利語中的 "dzs" 排在 "dz" 之後、 "g" 之前。

### Example

Run this code

```c
#include <locale.h> #include <stdio.h> #include <string.h> int main(void) {  setlocale(LC_COLLATE, "cs_CZ.utf8");  // Alternatively, ISO-8859-2 (a.k.a. Latin-2)  // may also work on some OS:  // setlocale(LC_COLLATE, "cs_CZ.iso88592");  const char* s1 = "hrnec";  const char* s2 = "chrt";  printf("In the Czech locale: ");  if (strcoll(s1, s2) < 0)  printf("%s before %s\n", s1, s2);  else  printf("%s before %s\n", s2, s1);  printf("In lexicographical comparison: ");  if (strcmp(s1, s2) < 0)  printf("%s before %s\n", s1, s2);  else  printf("%s before %s\n", s2, s1); }
```

Output:

```c
In the Czech locale: hrnec before chrt In lexicographical comparison: chrt before hrnec
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.24.4.3 The strcoll function (p: TBD)
7.24.4.3 strcoll 函式（頁碼：待定）
7.24.4.3 strcoll 函式（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.24.4.3 The strcoll function (p: TBD)
7.24.4.3 strcoll 函式（頁碼：待定）
7.24.4.3 strcoll 函式（頁碼：待定）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.24.4.3 The strcoll function (p: 366)
7.24.4.3 strcoll 函式（頁碼：366）
7.24.4.3 strcoll 函式（頁碼：366）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.21.4.3 The strcoll function (p: 329)
7.21.4.3 strcoll 函式（頁碼：329）
7.21.4.3 strcoll 函式（頁碼：329）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.11.4.3 The strcoll function
4.11.4.3 strcoll 函式
4.11.4.3 strcoll 函式

### See also

wcscoll
(C95)
|   | compares two wide strings in accordance to the current locale
(function)   |

strxfrm
|   | transform a string so that strcmp would produce the same result as strcoll
(function)   |

wcsxfrm
(C95)
|   | transform a wide string so that wcscmp would produce the same result as wcscoll
(function)   |

strcmp
|   | compares two strings
(function)   |

C++ documentation for strcoll

---
來源頁路徑：`en.cppreference.com/c/string/byte/strcoll.html`

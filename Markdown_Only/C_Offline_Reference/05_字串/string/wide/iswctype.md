# iswctype

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<wctype.h>`
|   |  |   |  |

```c
int iswctype( wint_t wc, wctype_t desc );
```
|   |   |   |  (since C95)  |

|  |  |  |  |

Classifies the wide character `wc` using the current C locale's LC_CTYPE category identified by `desc`.
使用由 desc 標識的目前 C 本地化環境的 LC_CTYPE 類別對寬字元 wc 進行分類。

### Parameters

| wc  |   | -  |   | the wide character to classify  |

| desc  |   | -  |   | the LC_CTYPE category, obtained from a call to wctype  |

### Return value

Non-zero if the character `wc` has the property identified by `desc` in LC_CTYPE facet of the current C locale, zero otherwise.
如果字元 wc 在目前 C 本地化環境的 LC_CTYPE 方面中具有由 desc 標識的屬性，則傳回非零，否則傳回零。

### Example

Run this code

```c
#include <locale.h> #include <stdio.h> #include <wchar.h> #include <wctype.h> const char* classify(wchar_t wc, const char* cat) {  return iswctype(wc, wctype(cat)) ? "true" : "false"; } int main(void) {  setlocale(LC_ALL, "ja_JP.UTF-8");  puts("The character \u6c34 is...");  const char* cats[] = {"digit", "alpha", "space", "cntrl", "jkanji"};  for (int n = 0; n < 5; ++n)  printf("%s?\t%s\n", cats[n], classify(L'\u6c34', cats[n])); }
```

Output:

```c
The character 水 is... digit? false alpha? true space? false cntrl? false jkanji? true
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.30.2.2.1 The iswctype function (p: TBD)
7.30.2.2.1 iswctype 函式（頁碼：待定）
7.30.2.2.1 iswctype 函式（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.30.2.2.1 The iswctype function (p: TBD)
7.30.2.2.1 iswctype 函式（頁碼：待定）
7.30.2.2.1 iswctype 函式（頁碼：待定）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.30.2.2.1 The iswctype function (p: 451-452)
7.30.2.2.1 iswctype 函式（頁碼：451-452）
7.30.2.2.1 iswctype 函式（頁碼：451-452）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.25.2.2.1 The iswctype function (p: 397-398)
7.25.2.2.1 iswctype 函式（頁碼：397-398）
7.25.2.2.1 iswctype 函式（頁碼：397-398）

### See also

wctype
(C95)
|   | looks up a character classification category in the current C locale
(function)   |

---
來源頁路徑：`en.cppreference.com/c/string/wide/iswctype.html`

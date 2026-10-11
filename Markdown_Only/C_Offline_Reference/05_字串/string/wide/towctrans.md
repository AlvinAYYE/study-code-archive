# towctrans

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<wctype.h>`
|   |  |   |  |

```c
wint_t towctrans( wint_t wc, wctrans_t desc );
```
|   |   |   |  (since C95)  |

|  |  |  |  |

Maps the wide character `wc` using the current C locale's LC_CTYPE mapping category identified by `desc`.
使用由 desc 標識的目前 C 本地化環境的 LC_CTYPE 對映類別對寬字元 wc 進行對映。

### Parameters

| wc  |   | -  |   | the wide character to map  |

| desc  |   | -  |   | the LC_CTYPE mapping, obtained from a call to wctrans  |

### Return value

The mapped value of `wc` using the mapping identified by `desc` in LC_CTYPE facet of the current C locale.
使用目前 C 本地化環境的 LC_CTYPE 方面中由 desc 標識的對映對 wc 進行對映後的值。

### Example

Run this code

```c
#include <locale.h> #include <wctype.h> #include <wchar.h> #include <stdio.h> int main(void) {  setlocale(LC_ALL, "ja_JP.UTF-8");  const wchar_t kana[] = L"ヒラガナ";  size_t sz = sizeof kana / sizeof *kana;  wchar_t hira[sz];  for (size_t n = 0; n < sz; ++n)  hira[n] = towctrans(kana[n], wctrans("tojhira"));  printf("katakana characters %ls are %ls in hiragana\n", kana, hira); }
```

Output:

```c
katakana characters ヒラガナ are ひらがな in hiragana
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.30.3.2.1 The towctrans function (p: TBD)
7.30.3.2.1 towctrans 函式（頁碼：待定）
7.30.3.2.1 towctrans 函式（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.30.3.2.1 The towctrans function (p: TBD)
7.30.3.2.1 towctrans 函式（頁碼：待定）
7.30.3.2.1 towctrans 函式（頁碼：待定）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.30.3.2.1 The towctrans function (p: 454)
7.30.3.2.1 towctrans 函式（頁碼：454）
7.30.3.2.1 towctrans 函式（頁碼：454）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.25.3.2,1 The towctrans function (p: 400)
7.25.3.2,1 towctrans 函式（頁碼：400）
7.25.3.2,1 towctrans 函式（頁碼：400）

### See also

wctrans
(C95)
|   | looks up a character mapping category in the current C locale
(function)   |

C++ documentation for towctrans

---
來源頁路徑：`en.cppreference.com/c/string/wide/towctrans.html`

# wctype

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<wctype.h>`
|   |  |   |  |

```c
wctype_t wctype( const char* str );
```
|   |   |   |  (since C95)  |

|  |  |  |  |

Constructs a value of type wctype_t that describes a LC_CTYPE category of wide character classification. It may be one of the standard classification categories, or a locale-specific category, such as `"jkanji"`.
構造一個型別為 wctype_t 的值，描述寬字元分類的 LC_CTYPE 類別。它可以是標準分類類別之一，也可以是特定於本地化環境的類別，例如 "jkanji" 。

### Parameters

| str  |   | -  |   | C string holding the name of the desired category  |

The following values of `str` are supported in all C locales:
所有 C 本地化環境支援以下 str 值：

| value of `str`  |   | effect  |

| `"alnum"`  |   | identifies the category used by iswalnum  |

| `"alpha"`  |   | identifies the category used by iswalpha  |

| `"blank"`  |   | identifies the category used by iswblank (C99)  |

| `"cntrl"`  |   | identifies the category used by iswcntrl  |

| `"digit"`  |   | identifies the category used by iswdigit  |

| `"graph"`  |   | identifies the category used by iswgraph  |

| `"lower"`  |   | identifies the category used by iswlower  |

| `"print"`  |   | identifies the category used by iswprint  |

| `"space"`  |   | identifies the category used by iswspace  |

| `"upper"`  |   | identifies the category used by iswupper  |

| `"xdigit"`  |   | identifies the category used by iswxdigit  |

### Return value

wctype_t object suitable for use with iswctype to classify wide characters according to the named category of the current C locale or zero if `str` does not name a category supported by the current C locale.
適合與 iswctype 一起使用的 wctype_t 物件，用於根據目前 C 本地化環境的命名類別對寬字元進行分類；如果 str 未命名目前 C 本地化環境支援的類別，則傳回零。

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.30.2.2.2 The wctype function (p: TBD)
7.30.2.2.2 wctype 函式（頁碼：待定）
7.30.2.2.2 wctype 函式（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.30.2.2.2 The wctype function (p: TBD)
7.30.2.2.2 wctype 函式（頁碼：待定）
7.30.2.2.2 wctype 函式（頁碼：待定）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.30.2.2.2 The wctype function (p: 452)
7.30.2.2.2 wctype 函式（頁碼：452）
7.30.2.2.2 wctype 函式（頁碼：452）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.25.2.2.2 The wctype function (p: 398)
7.25.2.2.2 wctype 函式（頁碼：398）
7.25.2.2.2 wctype 函式（頁碼：398）

### See also

iswctype
(C95)
|   | classifies a wide character according to the specified LC_CTYPE category
(function)   |

C++ documentation for wctype

---
來源頁路徑：`en.cppreference.com/c/string/wide/wctype.html`

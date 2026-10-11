# wctrans

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<wctype.h>`
|   |  |   |  |

```c
wctrans_t wctrans( const char* str );
```
|   |   |   |  (since C95)  |

|  |  |  |  |

Constructs a value of type wctrans_t that describes a LC_CTYPE category of wide character mapping. It may be one of the standard mappings, or a locale-specific mapping, such as `"tojhira"` or `"tojkata"`.
構造一個型別為 wctrans_t 的值，描述寬字元對映的 LC_CTYPE 類別。它可以是標準對映之一，也可以是特定於本地化環境的對映，例如 "tojhira" 或 "tojkata" 。

### Parameters

| str  |   | -  |   | C string holding the name of the desired mapping.
The following values of `str` are supported in all C locales:

| Value of `str`  |   | Effect  |

| `"toupper"`  |   | identifies the mapping used by towupper  |

| `"tolower"`  |   | identifies the mapping used by towlower  |

### Return value

wctrans_t object suitable for use with towctrans to map wide characters according to the named mapping of the current C locale or zero if `str` does not name a mapping supported by the current C locale.
適合與 towctrans 一起使用的 wctrans_t 物件，用於根據目前 C 本地化環境的命名對映對寬字元進行對映；如果 str 未命名目前 C 本地化環境支援的對映，則傳回零。

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.30.3.2.2 The wctrans function (p: TBD)
7.30.3.2.2 wctrans 函式（頁碼：待定）
7.30.3.2.2 wctrans 函式（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.30.3.2.2 The wctrans function (p: TBD)
7.30.3.2.2 wctrans 函式（頁碼：待定）
7.30.3.2.2 wctrans 函式（頁碼：待定）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.30.3.2.2 The wctrans function (p: 454)
7.30.3.2.2 wctrans 函式（頁碼：454）
7.30.3.2.2 wctrans 函式（頁碼：454）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.25.3.2,2 The wctrans function (p: 400)
7.25.3.2,2 wctrans 函式（頁碼：400）
7.25.3.2,2 wctrans 函式（頁碼：400）

### See also

towctrans
(C95)
|   | performs character mapping according to the specified LC_CTYPE mapping category
(function)   |

C++ documentation for wctrans

---
來源頁路徑：`en.cppreference.com/c/string/wide/wctrans.html`

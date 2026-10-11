# setlocale

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<locale.h>`
|   |  |   |  |

```c
char* setlocale( int category, const char* locale );
```
|   |   |   |   |

|  |  |  |  |

The `setlocale` function installs the specified system locale or its portion as the new C locale. The modifications remain in effect and influences the execution of all locale-sensitive C library functions until the next call to `setlocale`. If `locale` is a null pointer, `setlocale` queries the current C locale without modifying it.
setlocale 函式會將指定的系統地區設定（或其中一部分）設為新的 C 地區設定。這項設定會持續生效，並影響所有依地區設定而定的 C 標準函式庫函式，直到再次呼叫 setlocale 為止。若 locale 是空指標，setlocale 只查詢目前的 C 地區設定，不會加以變更。

### Parameters

| category  |   | -  |   | locale category identifier, one of the LC_xxx macros. May be null.  |

| locale  |   | -  |   | system-specific locale identifier. Can be `""` for the user-preferred locale or `"C"` for the minimal locale  |

### Return value

pointer to a narrow null-terminated string identifying the C locale after applying the changes, if any, or null pointer on failure.
指向某個窄字元空終止字串的指標，該字串標識應用更改（如果有）之後的 C 區域設定；失敗時傳回空指標。
A copy of the returned string along with the category used in this call to `setlocale` may be used later in the program to restore the locale back to the state at the end of this call.
可以將傳回的字串的副本與本次呼叫 setlocale 所使用的類別一起儲存，供程式稍後使用，以將區域設定恢復到本次呼叫結束時的狀態。

### Notes

During program startup, the equivalent of `setlocale(LC_ALL, "C");` is executed before any user code is run.
在程式啟動期間，等效於 setlocale ( LC_ALL , "C" ); 的呼叫會在任何使用者程式碼執行之前執行。
Although the return type is `char*`, modifying the pointed-to characters is undefined behavior.
雖然傳回型別是 char *，但修改其所指向的字元屬於未定義行為。
Because `setlocale` modifies global state which affects execution of locale-dependent functions, it is undefined behavior to call it from one thread, while another thread is executing any of the following functions: fprintf, isprint, iswdigit, localeconv, tolower, fscanf, ispunct, iswgraph, mblen, toupper, isalnum, isspace, iswlower, mbstowcs, towlower, isalpha, isupper, iswprint, mbtowc, towupper, isblank, iswalnum, iswpunct, `setlocale`, wcscoll, iscntrl, iswalpha, iswspace, strcoll, wcstod, isdigit, iswblank, iswupper, strerror, wcstombs, isgraph, iswcntrl, iswxdigit, strtod, wcsxfrm, islower, iswctype, isxdigit.
由於 setlocale 修改會影響區域設定相關函式執行的全域性狀態，因此在一個執行緒呼叫它的同時，另一個執行緒正在執行以下任何函式（fprintf , isprint , iswdigit , localeconv , tolower , fscanf , ispunct , iswgraph , mblen , toupper , isalnum , isspace , iswlower , mbstowcs , towlower , isalpha , isupper , iswprint , mbtowc , towupper , isblank , iswalnum , iswpunct , setlocale , wcscoll , iscntrl , iswalpha , iswspace , strcoll , wcstod , isdigit , iswblank , iswupper , strerror , wcstombs , isgraph , iswcntrl , iswxdigit , strtod , wcsxfrm , islower , iswctype , isxdigit）時，屬於未定義行為。
POSIX also defines a locale named "POSIX", which is always accessible and is exactly equivalent to the default minimal "C" locale.
POSIX 還定義了一個名為 "POSIX" 的區域設定，它始終可用，且完全等同於預設的最小 "C" 區域設定。
POSIX also specifies that the returned pointer, not just the contents of the pointed-to string, may be invalidated by subsequent calls to `setlocale`.
POSIX 還規定，傳回的指標（而不僅僅是其所指向字串的內容）可能會被後續的 setlocale 呼叫所失效。

### Example

Run this code

```c
#include <locale.h> #include <stdio.h> #include <time.h> #include <wchar.h>   int main(void) {  // the C locale will be UTF-8 enabled English;  // decimal dot will be German  // date and time formatting will be Japanese  setlocale(LC_ALL, "en_US.UTF-8");  setlocale(LC_NUMERIC, "de_DE.utf8");  setlocale(LC_TIME, "ja_JP.utf8");    wchar_t str[100];  time_t t = time(NULL);  wcsftime(str, 100, L"%A %c", localtime(&t));  wprintf(L"Number: %.2f\nDate: %ls\n", 3.14, str); }
```

Possible output:
可能的輸出：

```c
Number: 3,14 Date: 月曜日 2017年09月25日 13時00分15秒
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.11.1.1 The setlocale function (p: TBD)
7.11.1.1 setlocale 函式 (p: 待定)
7.11.1.1 setlocale 函式 (p: 待定)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.11.1.1 The setlocale function (p: 163-164)
7.11.1.1 setlocale 函式 (p: 163-164)
7.11.1.1 setlocale 函式 (p: 163-164)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.11.1.1 The setlocale function (p: 224-225)
7.11.1.1 setlocale 函式 (p: 224-225)
7.11.1.1 setlocale 函式 (p: 224-225)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.11.1.1 The setlocale function (p: 205-206)
7.11.1.1 setlocale 函式 (p: 205-206)
7.11.1.1 setlocale 函式 (p: 205-206)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.4.1.1 The setlocale function
4.4.1.1 setlocale 函式
4.4.1.1 setlocale 函式

### See also

LC_ALLLC_COLLATELC_CTYPELC_MONETARYLC_NUMERICLC_TIME
|   | locale categories for setlocale
(macro constant)   |

C++ documentation for setlocale

### External links

| 1.  |   | List of Windows locale names.  |

| 2.  |   | List of Linux locale names.  |

---
來源頁路徑：`en.cppreference.com/c/locale/setlocale.html`

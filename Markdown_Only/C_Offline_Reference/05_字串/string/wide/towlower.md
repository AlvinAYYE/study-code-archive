# towlower

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<wctype.h>`
|   |  |   |  |

```c
wint_t towlower( wint_t wc );
```
|   |   |   |  (since C95)  |

|  |  |  |  |

Converts the given wide character to lowercase, if possible.
如果可能，將給定的寬字元轉換為小寫。

### Parameters

| wc  |   | -  |   | wide character to be converted  |

### Return value

Lowercase version of `wc` or unmodified `wc` if no lowercase version is listed in the current C locale.
wc 的小寫版本，如果目前 C 本地化環境中未列出小寫版本，則為未修改的 wc 。

### Notes

Only 1:1 character mapping can be performed by this function, e.g. the Greek uppercase letter `'Σ'` has two lowercase forms, depending on the position in a word: `'σ'` and `'ς'`. A call to `towlower` cannot be used to obtain the correct lowercase form in this case.
此函式只能執行 1:1 字元對映，例如希臘大寫字母 'Σ' 有兩種小寫形式，取決於在單詞中的位置： 'σ' 和 'ς' 。在這種情況下，呼叫 towlower 無法獲得正確的小寫形式。
ISO 30112 specifies which pairs of Unicode characters are included in this mapping.
ISO 30112 規定了此對映中包含哪些 Unicode 字元對。

### Example

Run this code

```c
#include <locale.h> #include <stdio.h> #include <wchar.h> #include <wctype.h> int main(void) {  wchar_t wc = L'\u0190'; // Latin capital open E ('Ɛ')  printf("in the default locale, towlower(%#x) = %#x\n", wc, towlower(wc));  setlocale(LC_ALL, "en_US.utf8");  printf("in Unicode locale, towlower(%#x) = %#x\n", wc, towlower(wc)); }
```

Output:

```c
in the default locale, towlower(0x190) = 0x190 in Unicode locale, towlower(0x190) = 0x25b
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.30.3.1.1 The towlower function (p: TBD)
7.30.3.1.1 towlower 函式（頁碼：待定）
7.30.3.1.1 towlower 函式（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.30.3.1.1 The towlower function (p: TBD)
7.30.3.1.1 towlower 函式（頁碼：待定）
7.30.3.1.1 towlower 函式（頁碼：待定）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.30.3.1.1 The towlower function (p: 453)
7.30.3.1.1 towlower 函式（頁碼：453）
7.30.3.1.1 towlower 函式（頁碼：453）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.25.3.1.1 The towlower function (p: 399)
7.25.3.1.1 towlower 函式（頁碼：399）
7.25.3.1.1 towlower 函式（頁碼：399）

### See also

towupper
(C95)
|   | converts a wide character to uppercase
(function)   |

tolower
|   | converts a character to lowercase
(function)   |

C++ documentation for towlower

---
來源頁路徑：`en.cppreference.com/c/string/wide/towlower.html`

# towupper

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<wctype.h>`
|   |  |   |  |

```c
wint_t towupper( wint_t wc );
```
|   |   |   |  (since C95)  |

|  |  |  |  |

Converts the given wide character to uppercase, if possible.
如果可能，將給定的寬字元轉換為大寫。

### Parameters

| wc  |   | -  |   | wide character to be converted  |

### Return value

Uppercase version of `wc` or unmodified `wc` if no uppercase version is listed in the current C locale.
wc 的大寫版本，如果目前 C 本地化環境中未列出大寫版本，則為未修改的 wc 。

### Notes

Only 1:1 character mapping can be performed by this function, e.g. the uppercase form of 'ß' is (with some exceptions) the two-character string "SS", which cannot be obtained by `towupper`.
此函式只能執行 1:1 字元對映，例如 'ß' 的大寫形式是（在某些例外情況下）雙字元字串 "SS" ，這無法透過 towupper 獲得。
ISO 30112 specifies which pairs of Unicode characters are included in this mapping.
ISO 30112 規定了此對映中包含哪些 Unicode 字元對。

### Example

Run this code

```c
#include <stdio.h> #include <wchar.h> #include <wctype.h> #include <locale.h> int main(void) {  wchar_t wc = L'\u017f'; // Latin small letter Long S ('ſ')  printf("in the default locale, towupper(%#x) = %#x\n", wc, towupper(wc));  setlocale(LC_ALL, "en_US.utf8");  printf("in Unicode locale, towupper(%#x) = %#x\n", wc, towupper(wc)); }
```

Output:

```c
in the default locale, towupper(0x17f) = 0x17f in Unicode locale, towupper(0x17f) = 0x53
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.30.3.1.2 The towupper function (p: 453)
7.30.3.1.2 towupper 函式（頁碼：453）
7.30.3.1.2 towupper 函式（頁碼：453）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.25.3.1.2 The towupper function (p: 399)
7.25.3.1.2 towupper 函式（頁碼：399）
7.25.3.1.2 towupper 函式（頁碼：399）

### See also

towlower
(C95)
|   | converts a wide character to lowercase
(function)   |

toupper
|   | converts a character to uppercase
(function)   |

C++ documentation for towupper

---
來源頁路徑：`en.cppreference.com/c/string/wide/towupper.html`

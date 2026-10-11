# wcsxfrm

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<wchar.h>`
|   |  |   |  |

```c
size_t wcsxfrm( wchar_t* dest, const wchar_t* src, size_t count );
```
|   |   |   | (since C95)
(until C99) |

```c
size_t wcsxfrm( wchar_t* restrict dest, const wchar_t* restrict src, size_t count );
```
|   |   |   | (since C99) |

|  |  |  |  |

Transforms the null-terminated wide string pointed to by `src` into the implementation-defined form such that comparing two transformed strings with wcscmp gives the same result as comparing the original strings with wcscoll, in the current C locale.
將 src 指向的空終止寬字串轉換為實現定義的形式，使得在目前 C 本地化環境中，用 wcscmp 比較兩個轉換後的字串與用 wcscoll 比較原始字串得到相同的結果。
The first `count` characters of the transformed string are written to destination, including the terminating null character, and the length of the full transformed string is returned, excluding the terminating null character.
轉換後的字串的前 count 個字元（包括終止空字元）被寫入 destination，並傳回完整轉換後字串的長度（不包括終止空字元）。
If `count` is `0`, then `dest` is allowed to be a null pointer.
如果 count 為 0 ，則 dest 允許為空指標。

### Notes

The correct length of the buffer that can receive the entire transformed string is `1 + wcsxfrm(NULL, src, 0)`
可以接收整個轉換後字串的緩衝區的正確長度為 1 + wcsxfrm ( NULL , src , 0 )
This function is used when making multiple locale-dependent comparisons using the same wide string or set of wide strings, because it is more efficient to use `wcsxfrm` to transform all the strings just once, and subsequently compare the transformed wide strings with wcscmp.
當使用相同的寬字串或寬字串集合進行多次依賴本地化環境的比較時，會使用此函式，因為使用 wcsxfrm 僅轉換一次所有字串，然後使用 wcscmp 比較轉換後的寬字串，效率更高。

### Parameters

| dest  |   | -  |   | pointer to the first element of a wide null-terminated string to write the transformed string to  |

| src  |   | -  |   | pointer to the null-terminated wide character string to transform  |

| count  |   | -  |   | maximum number of characters to output  |

### Return value

The length of the transformed wide string, not including the terminating null-character.
轉換後的寬字串的長度，不包括終止空字元。

### Example

Run this code

```c
#include <locale.h> #include <stdio.h> #include <wchar.h> int main(void) {  setlocale(LC_ALL, "sv_SE.utf8");  const wchar_t* in1 = L"\u00e5r";  wchar_t out1[1 + wcsxfrm(NULL, in1, 0)];  wcsxfrm(out1, in1, sizeof out1/sizeof *out1);  const wchar_t* in2 = L"\u00e4ngel";  wchar_t out2[1 + wcsxfrm(NULL, in2, 0)];  wcsxfrm(out2, in2, sizeof out2 / sizeof *out2);  printf("In the Swedish locale: ");  if (wcscmp(out1, out2) < 0)  printf("%ls before %ls\n", in1, in2);  else  printf("%ls before %ls\n", in2, in1);  printf("In lexicographical comparison: ");  if (wcscmp(in1, in2) < 0)  printf("%ls before %ls\n", in1, in2);  else  printf("%ls before %ls\n", in2, in1); }
```

Output:

```c
In the Swedish locale: år before ängel In lexicographical comparison: ängel before år
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.29.4.4.4 The wcsxfrm function (p: TBD)
7.29.4.4.4 wcsxfrm 函式（頁碼：待定）
7.29.4.4.4 wcsxfrm 函式（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.29.4.4.4 The wcsxfrm function (p: TBD)
7.29.4.4.4 wcsxfrm 函式（頁碼：待定）
7.29.4.4.4 wcsxfrm 函式（頁碼：待定）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.29.4.4.4 The wcsxfrm function (p: 434-435)
7.29.4.4.4 wcsxfrm 函式（頁碼：434-435）
7.29.4.4.4 wcsxfrm 函式（頁碼：434-435）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.24.4.4.4 The wcsxfrm function (p: 380-381)
7.24.4.4.4 wcsxfrm 函式（頁碼：380-381）
7.24.4.4.4 wcsxfrm 函式（頁碼：380-381）

### See also

strcoll
|   | compares two strings in accordance to the current locale
(function)   |

wcscoll
(C95)
|   | compares two wide strings in accordance to the current locale
(function)   |

wcscmp
(C95)
|   | compares two wide strings
(function)   |

strxfrm
|   | transform a string so that strcmp would produce the same result as strcoll
(function)   |

C++ documentation for wcsxfrm

---
來源頁路徑：`en.cppreference.com/c/string/wide/wcsxfrm.html`
